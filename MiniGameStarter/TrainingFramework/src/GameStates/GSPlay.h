#pragma once
#include "GameStateBase.h"

class Sprite2D;
class Sprite3D;
class Text;
class GameButton;
class Guest;
class MainChar;

class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

	void	Init() override;
	void	Exit() override;

	void	Pause() override;
	void	Resume() override;

	void	HandleEvents() override;
	void	HandleCollisionEnter() override;
	void	HandleKeyEvents(int key, bool bIsPressed) override;
	void	HandleTouchEvents(int x, int y, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	void	Draw() override;

	void	GenerateGuest();
	void	UpdateScore(int pnt);
	void	UpdateLife();

private:
	std::shared_ptr<Sprite2D>	m_background;
	std::shared_ptr<Sprite2D>	m_dash;
	std::shared_ptr<Text>		m_score;
	std::shared_ptr<Text>		m_lifeLabel;
	std::shared_ptr<Text>		m_lifeCount;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::vector<std::shared_ptr<Guest>>	m_listGuest;
	std::shared_ptr<MainChar>	m_main;
	int keyPressed = 0;
	int time = 0;
	int currentTime = 0;
	int score = 0;
	int life = 3;
};

