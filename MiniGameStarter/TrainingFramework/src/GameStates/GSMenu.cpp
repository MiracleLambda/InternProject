#include "GSMenu.h"
#include "../soloud20200207/include/soloud.h"
#include "../soloud20200207/include/soloud_wav.h"
#include "Camera.h"

using namespace SoLoud;

Soloud mnSoloud; // SoLoud engine
Wav mnWave;      // One wave file

GSMenu::GSMenu() : GameStateBase(StateType::STATE_MENU),
m_background(nullptr), m_listButton(std::list<std::shared_ptr<GameButton>>{}), m_title(nullptr)
{
}


GSMenu::~GSMenu()
{
}



void GSMenu::Init()
{
	// =========================================================================================
	mnSoloud.init(); // Initialize SoLoud
	mnWave.load("../Data/Music/retrosoul.wav"); // Load a wave
	mnWave.setLooping(1);
	mnWave.setVolume(0.3);
	mnSoloud.play(mnWave); // Play the wave
	// =========================================================================================

	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_main_menu.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// play button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_play_new.tga");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth / 2, 400);
	button->SetSize(200, 200);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY);
		});
	m_listButton.push_back(button);

	// credit button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_credit_new.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(550, 640);
	button->SetSize(70, 75);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_CREDIT);
		});
	m_listButton.push_back(button);

	// settings button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_settings_new.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(730, 640);
	button->SetSize(70, 75);
	button->SetOnClick([]() {
		
		});
	m_listButton.push_back(button);

	// exit button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_exit.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(75, 75);
	button->SetOnClick([]() {
		exit(0);
		});
	m_listButton.push_back(button);

	// game title
	// shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	// std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("BlackCloverFont.ttf");
	// m_textGameName = std::make_shared<Text>(shader, font, "Taverne da Ciel", Vector4(1.0f, 0.4f, 0.0f, 1.0f), 3.5f);
	// m_textGameName->Set2DPosition(Vector2(410, 111));
	texture = ResourceManagers::GetInstance()->GetTexture("title_new.tga");
	m_title = std::make_shared<Sprite2D>(model, shader, texture);
	m_title->Set2DPosition(Globals::screenWidth / 2, 111);
	m_title->SetSize(450, 150);
}

void GSMenu::Exit()
{
}


void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}


void GSMenu::HandleEvents()
{
}

void GSMenu::HandleCollisionEnter()
{
}

void GSMenu::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSMenu::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSMenu::HandleMouseMoveEvents(int x, int y)
{
}

void GSMenu::Update(float deltaTime)
{
	m_background->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSMenu::Draw()
{
	m_background->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_title->Draw();
}
