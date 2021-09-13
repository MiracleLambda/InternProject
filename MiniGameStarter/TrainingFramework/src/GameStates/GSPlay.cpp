#include "GSPlay.h"

#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"
#include "Guest.h"
#include "MainChar.h"
#include <string>
#include <iostream>
using namespace std;

GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{
}

void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_play0.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);
	
	// dash
	texture = ResourceManagers::GetInstance()->GetTexture("dash.tga");
	m_dash = std::make_shared<Sprite2D>(model, shader, texture);
	m_dash->Set2DPosition(190, 625);
	m_dash->SetSize(720, 600);

	// button close
	texture = ResourceManagers::GetInstance()->GetTexture("btn_exit.tga");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(75, 75);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("BlackCloverFont.ttf");
	m_score = std::make_shared<Text>(shader, font, "Score: " + to_string(score), TextColor::BLACK, 2.0f);
	m_score->Set2DPosition(Vector2(20, 60));

	// life label
	m_lifeLabel = std::make_shared<Text>(shader, font, "Life: ", TextColor::BLACK, 2.0f);
	m_lifeLabel->Set2DPosition(Vector2(500, 60));

	// life count
	m_lifeCount = std::make_shared<Text>(shader, font, "x x x", TextColor::RED, 2.0f);
	m_lifeCount->Set2DPosition(Vector2(585, 60));

	// character
	shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	texture = ResourceManagers::GetInstance()->GetTexture("mc.tga");
	m_main = std::make_shared<MainChar>(model, shader, texture, 200, 0, 3, 10, 0.1f);
	m_main->Set2DPosition((float)Globals::screenWidth / 2, 480);
	m_main->SetSize(225, 200);
	m_main->SetScale(Vector3(225.0f, 200.0f, 10.0f));
}

void GSPlay::GenerateGuest()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_play0.tga");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	int type = rand() % 3;
	int dish, point;
	switch (type)
	{
	case 0:
		texture = ResourceManagers::GetInstance()->GetTexture("guest01.tga");
		dish = 1;
		point = 10;
		break;
	case 1:
		texture = ResourceManagers::GetInstance()->GetTexture("guest02.tga");
		dish = 2;
		point = 20;
		break;
	case 2:
		texture = ResourceManagers::GetInstance()->GetTexture("guest03.tga");
		dish = 3;
		point = 30;
		break;
	default:
		break;
	}
	int rndX = rand() % 350 + 50;
	int rndY = rand() % 200 + 50;
	int rndMvm = rand() % 14;
	std::shared_ptr<Guest> guest = std::make_shared<Guest>(model, shader, texture, dish, Vector2(rndX, rndY), 60, point, 0, rndMvm);
	int rndYPos = (rand() % 1000 + 1234) % 300 + 300;
	guest->Set2DPosition(0, rndYPos);
	guest->SetSize(91, 130);
	m_listGuest.push_back(guest);
}

void GSPlay::Exit()
{
}


void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}


void GSPlay::HandleEvents()
{
}

void GSPlay::HandleCollisionEnter()
{
	for (int i = 0; i < m_listGuest.size(); i++)
	{
		Vector3 g = m_listGuest.at(i)->GetPosition();
		Vector3 mc = m_main->GetPosition();
		float dist = sqrt(pow((g.x - mc.x), 2) + pow((g.y - mc.y), 2));

		if (dist > 0 && dist < 100)
		{
			m_listGuest.at(i)->m_state = 1;
		}
		else
		{
			m_listGuest.at(i)->m_state = 0;
		}
	}
}

void GSPlay::UpdateScore(int pnt)
{
	auto shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("BlackCloverFont.ttf");
	score += pnt;
	m_score = std::make_shared<Text>(shader, font, "Score: " + to_string(score), TextColor::BLACK, 2.0f);
	m_score->Set2DPosition(Vector2(20, 60));
}

int GSPlay::UpdateLife()
{
	for (auto it : m_listGuest)
	{
		if (it->m_state == 2)
		{
			it->m_state = 3;
			life--;
			it->SetSize(0.0f, 0.0f);
			it->Set2DPosition(0, 350);
			break;
		}
	}

	auto shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("BlackCloverFont.ttf");

	switch (life)
	{
	case 0:
		m_lifeCount = std::make_shared<Text>(shader, font, " ", TextColor::RED, 2.0f);
		break;
	case 1:
		m_lifeCount = std::make_shared<Text>(shader, font, "x", TextColor::RED, 2.0f);
		break;
	case 2:
		m_lifeCount = std::make_shared<Text>(shader, font, "x x", TextColor::RED, 2.0f);
		break;
	case 3:
		m_lifeCount = std::make_shared<Text>(shader, font, "x x x", TextColor::RED, 2.0f);
		break;
	default:
		break;
	}

	m_lifeCount->Set2DPosition(Vector2(585, 60));
}


void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed == true)
	{
		switch (key)
		{
		case 'A':
			keyPressed |= KEY_MOVE_LEFT;
			m_main->SetScale(Vector3(-225.0f, 200.0f, 10.0f));
			break;
		case 'D':
			keyPressed |= KEY_MOVE_RIGHT;
			m_main->SetScale(Vector3(225.0f, 200.0f, 10.0f));
			break;
		case 'W':
			keyPressed |= KEY_MOVE_FORWORD;
			break;
		case 'S':
			keyPressed |= KEY_MOVE_BACKWORD;
			break;
		case 'J':
			keyPressed |= KEY_J;
			break;
		case 'K':
			keyPressed |= KEY_K;
			break;
		case 'L':
			keyPressed |= KEY_L;
			break;
		default:
			break;
		}
	}
	else
	{
		switch (key)
		{
		case 'A':
			keyPressed ^= KEY_MOVE_LEFT;
			break;
		case 'D':
			keyPressed ^= KEY_MOVE_RIGHT;
			break;
		case 'W':
			keyPressed ^= KEY_MOVE_FORWORD;
			break;
		case 'S':
			keyPressed ^= KEY_MOVE_BACKWORD;
			break;
		case 'J':
			keyPressed ^= KEY_J;
			break;
		case 'K':
			keyPressed ^= KEY_K;
			break;
		case 'L':
			keyPressed ^= KEY_L;
			break;
		default:
			break;
		}
	}
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSPlay::HandleMouseMoveEvents(int x, int y)
{
}

void GSPlay::Update(float deltaTime)
{
	m_main->Update(deltaTime);

	if (keyPressed & KEY_MOVE_LEFT)
	{
		if (m_main->GetPosition().x > 0)
		{
			m_main->Set2DPosition(m_main->GetPosition().x - deltaTime * m_main->m_velocity, m_main->GetPosition().y);
		}
	}
	if (keyPressed & KEY_MOVE_RIGHT)
	{
		if (m_main->GetPosition().x < Globals::screenWidth)
		{
			m_main->Set2DPosition(m_main->GetPosition().x + deltaTime * m_main->m_velocity, m_main->GetPosition().y);
		}
	}
	if (keyPressed & KEY_MOVE_FORWORD)
	{
		if (m_main->GetPosition().y > 280)
		{
			m_main->Set2DPosition(m_main->GetPosition().x, m_main->GetPosition().y - deltaTime * m_main->m_velocity);
		}
	}
	if (keyPressed & KEY_MOVE_BACKWORD)
	{
		if (m_main->GetPosition().y < 670)
		{
			m_main->Set2DPosition(m_main->GetPosition().x, m_main->GetPosition().y + deltaTime * m_main->m_velocity);
		}
	}
	if (keyPressed & KEY_J)
	{
		if (m_main->GetPosition().x > 200)
		{
			for (auto it : m_listGuest)
			{
				if (it->m_state == 1 && it->m_dish == 1)
				{
					it->SetScale(Vector3(0.0f, 0.0f, 0.0f));
					it->Set2DPosition(0, 350);
					it->m_velocity.x = 0;
					it->m_velocity.y = 0;
					UpdateScore(it->m_point);
					it->~Guest();
					break;
				}
			}
		}
	}
	if (keyPressed & KEY_K)
	{
		if (m_main->GetPosition().x > 200)
		{
			for (auto it : m_listGuest)
			{
				if (it->m_state == 1 && it->m_dish == 2)
				{
					it->SetScale(Vector3(0.0f, 0.0f, 0.0f));
					it->Set2DPosition(0, 350);
					it->m_velocity.x = 0;
					it->m_velocity.y = 0;
					UpdateScore(it->m_point);
					it->~Guest();
					break;
				}
			}
		}
	}
	if (keyPressed & KEY_L)
	{
		if (m_main->GetPosition().x > 200)
		{
			for (auto it : m_listGuest)
			{
				if (it->m_state == 1 && it->m_dish == 3)
				{
					it->SetScale(Vector3(0.0f, 0.0f, 0.0f));
					it->Set2DPosition(0, 350);
					it->m_velocity.x = 0;
					it->m_velocity.y = 0;
					UpdateScore(it->m_point);
					
					break;
				}
			}
		}
	}

	if (life <= 0)
	{
		GameStateMachine::GetInstance()->PopState();
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_ENDGAME);
		ScoreManager::GetInstance()->score = this->score;
	}

	UpdateLife();
	HandleCollisionEnter();

	currentTime += (deltaTime * 35);
	if ((currentTime - time) > 7)
	{
		GenerateGuest();
		time = currentTime;
	}

	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}

	for (auto it : m_listGuest)
	{
		it->Update(deltaTime);
	}
}

void GSPlay::Draw()
{
	m_background->Draw();
	m_dash->Draw();
	m_score->Draw();
	m_lifeLabel->Draw();
	m_lifeCount->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	for (auto it : m_listGuest)
	{
		it->Draw();
	}
	m_main->Draw();
}