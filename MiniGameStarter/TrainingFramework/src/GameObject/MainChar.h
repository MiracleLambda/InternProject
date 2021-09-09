#pragma once
#include "Sprite2D.h"
class MainChar :
    public Sprite2D
{
public:
    MainChar();
    MainChar(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture,
        GLint velocity, GLint point, GLint life, int numFrames, float frameTime);
    ~MainChar();

    void		Init() override;
    void		Draw() override;
    void		Update(GLfloat deltatime) override;

    void		Set2DPosition(GLint x, GLint y);
    void		Set2DPosition(Vector2 position);
    void		SetSize(GLint width, GLint height);

    int m_numFrames;
    int m_currentFrame;
    float m_frameTime;
    float m_currentFrameTime;

    GLint m_velocity;
    GLint m_point;
    GLint m_life;
};

