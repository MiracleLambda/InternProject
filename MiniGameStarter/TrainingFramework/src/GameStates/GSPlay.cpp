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

	// button close
	texture = ResourceManagers::GetInstance()->GetTexture("btn_exit.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(75, 75);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("BlackCloverFont.ttf");
	m_score = std::make_shared<Text>(shader, font, "Score: 0", TextColor::BLACK, 2.0f);
	m_score->Set2DPosition(Vector2(20, 60));

	// character
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	texture = ResourceManagers::GetInstance()->GetTexture("char_main.tga");
	m_main = std::make_shared<Sprite2D>(model, shader, texture);
	m_main->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_main->SetSize(225, 200);

	// bar
	texture = ResourceManagers::GetInstance()->GetTexture("table_bar.tga");
	m_bar = std::make_shared<Sprite2D>(model, shader, texture);
	m_bar->Set2DPosition(920, 625);
	m_bar->SetSize(740, 210);
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

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed == true) 
	{
		switch (key)
		{
		case 'A':
			keyPressed |= KEY_MOVE_LEFT;
			break;
		case 'D':
			keyPressed |= KEY_MOVE_RIGHT;
			break;
		case 'W':
			keyPressed |= KEY_MOVE_FORWORD;
			break;
		case 'S':
			keyPressed |= KEY_MOVE_BACKWORD;
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
	if (keyPressed & KEY_MOVE_LEFT)
	{
		m_main->Set2DPosition(m_main->GetPosition().x - deltaTime * 200, m_main->GetPosition().y);
	}
	if (keyPressed & KEY_MOVE_RIGHT)
	{
		m_main->Set2DPosition(m_main->GetPosition().x + deltaTime * 200, m_main->GetPosition().y);
	}
	if (keyPressed & KEY_MOVE_FORWORD)
	{
		m_main->Set2DPosition(m_main->GetPosition().x, m_main->GetPosition().y - deltaTime * 200);
	}
	if (keyPressed & KEY_MOVE_BACKWORD)
	{
		m_main->Set2DPosition(m_main->GetPosition().x, m_main->GetPosition().y + deltaTime * 200);
	}
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSPlay::Draw()
{
	m_background->Draw();
	m_score->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_main->Draw();
	m_bar->Draw();
}