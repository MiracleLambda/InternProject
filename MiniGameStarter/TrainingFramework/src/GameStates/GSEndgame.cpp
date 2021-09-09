#include "GSEndgame.h"
#include "Camera.h"
using namespace std;

GSEndgame::GSEndgame() : GameStateBase(StateType::STATE_ENDGAME),
m_background(nullptr), m_listButton(std::list<std::shared_ptr<GameButton>>{})
{
}


GSEndgame::~GSEndgame()
{
}



void GSEndgame::Init()
{
	score = ScoreManager::GetInstance()->score;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_endgame.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// close button
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
	m_score = std::make_shared<Text>(shader, font, to_string(score), TextColor::RED, 3.0f);
	m_score->Set2DPosition(Vector2(780, 275));

	// record
	int record = ScoreManager::GetInstance()->CalculateHighScore(score);
	m_record = std::make_shared<Text>(shader, font, to_string(record), TextColor::RED, 3.0f);
	m_record->Set2DPosition(Vector2(780, 370));
}

void GSEndgame::Exit()
{
}


void GSEndgame::Pause()
{
}

void GSEndgame::Resume()
{
}


void GSEndgame::HandleEvents()
{
}

void GSEndgame::HandleCollisionEnter()
{
}

void GSEndgame::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSEndgame::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSEndgame::HandleMouseMoveEvents(int x, int y)
{
}

void GSEndgame::Update(float deltaTime)
{
	m_background->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSEndgame::Draw()
{
	m_background->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_score->Draw();
	m_record->Draw();
}
