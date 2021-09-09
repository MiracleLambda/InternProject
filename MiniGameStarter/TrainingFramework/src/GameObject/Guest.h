#pragma once
#include "Sprite2D.h"
class Guest :
    public Sprite2D
{
public:
	GLint m_dish;
	Vector2 m_velocity;
	GLint m_existTime;
	GLint m_point;
	GLint m_state;

	int time = 0;
	int currentTime = 0;
	int mvm;

	Guest();
	Guest(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, GLint dish, Vector2 velocity, GLint existTime, GLint point, GLint state, int mvm);
	~Guest();

	void		Init() override;
	void		Draw() override;
	void		Update(GLfloat deltatime) override;

	void		Set2DPosition(GLint x, GLint y);
	void		Set2DPosition(Vector2 position);
	void		SetSize(GLint width, GLint height);
};

