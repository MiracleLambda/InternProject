#include "Guest.h"

#include "Shader.h"
#include "Model.h"
#include "Camera.h"
#include "Texture.h"
#include "Application.h"

Guest::Guest()
{
}

Guest::Guest(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, GLint dish, Vector2 velocity, GLint existTime, GLint point, GLint state, int m)
	: Sprite2D(model, shader, texture), m_dish(dish), m_velocity(velocity), m_existTime(existTime), m_point(point), m_state(state), mvm(m)
{
}

Guest::~Guest()
{
}

void Guest::Init()
{
	SetCamera(Application::GetInstance()->GetCamera());
	CalculateWorldMatrix();
}

void Guest::Draw()
{
	if (m_pCamera == nullptr) return;
	glUseProgram(m_pShader->m_program);
	glBindBuffer(GL_ARRAY_BUFFER, m_pModel->GetVertexObject());
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_pModel->GetIndiceObject());

	GLuint iTempShaderVaribleGLID = -1;
	Matrix wvpMatrix;

	wvpMatrix = m_worldMatrix * m_pCamera->GetLookAtCameraMatrix();

	if (m_pTexture != nullptr)
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_pTexture->Get2DTextureAdd());
		if (m_pShader->m_iTextureLoc[0] != -1)
			glUniform1i(m_pShader->m_iTextureLoc[0], 0);
	}
	else
	{
		iTempShaderVaribleGLID = -1;
		iTempShaderVaribleGLID = m_pShader->GetUniformLocation((char*)"u_color");
		if (iTempShaderVaribleGLID != -1)
			glUniform4f(iTempShaderVaribleGLID, m_color.x, m_color.y, m_color.z, m_color.w);
	}


	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetAttribLocation((char*)"a_posL");
	if (iTempShaderVaribleGLID != -1)
	{
		glEnableVertexAttribArray(iTempShaderVaribleGLID);
		glVertexAttribPointer(iTempShaderVaribleGLID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), VETEX_POSITION);
	}

	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetAttribLocation((char*)"a_uv");
	if (iTempShaderVaribleGLID != -1)
	{
		glEnableVertexAttribArray(iTempShaderVaribleGLID);
		glVertexAttribPointer(iTempShaderVaribleGLID, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), VETEX_UV);
	}

	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetUniformLocation((char*)"u_alpha");
	if (iTempShaderVaribleGLID != -1)
		glUniform1f(iTempShaderVaribleGLID, 1.0);

	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetUniformLocation((char*)"u_wvpMatrix");
	if (iTempShaderVaribleGLID != -1)
		glUniformMatrix4fv(iTempShaderVaribleGLID, 1, GL_FALSE, wvpMatrix.m[0]);



	glDrawElements(GL_TRIANGLES, m_pModel->GetNumIndiceObject(), GL_UNSIGNED_INT, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);

}

void Guest::Update(GLfloat deltaTime)
{
	currentTime += (deltaTime * 35);
	if ((currentTime - time) > 7)
	{
		mvm = rand() % 14;
		time = currentTime;
	}
	switch (mvm)
	{
	case 0:
		this->Set2DPosition(this->GetPosition().x + deltaTime * m_velocity.x, this->GetPosition().y);
		if (this->GetPosition().y < 650) {
			this->Set2DPosition(this->GetPosition().x, this->GetPosition().y + deltaTime * m_velocity.y);
		}
		break;
	case 1:
		this->Set2DPosition(this->GetPosition().x + deltaTime * m_velocity.x, this->GetPosition().y);
		break;
	case 2:
		if (this->GetPosition().y < 650) {
			this->Set2DPosition(this->GetPosition().x, this->GetPosition().y + deltaTime * m_velocity.y);
		}
		break;
	case 3:
		if (this->GetPosition().x > 650) {
			this->Set2DPosition(this->GetPosition().x - deltaTime * m_velocity.x, this->GetPosition().y);
		}
		break;
	case 4:
		if (this->GetPosition().y > 450) {
			this->Set2DPosition(this->GetPosition().x, this->GetPosition().y - deltaTime * m_velocity.y);
		}
		break;
	case 5:
		if (this->GetPosition().x > 650) {
			this->Set2DPosition(this->GetPosition().x - deltaTime * m_velocity.x, this->GetPosition().y);
		}
		if (this->GetPosition().y < 650) {
			this->Set2DPosition(this->GetPosition().x, this->GetPosition().y + deltaTime * m_velocity.y);
		}
		break;
	case 6:
		if (this->GetPosition().x > 650) {
			this->Set2DPosition(this->GetPosition().x - deltaTime * m_velocity.x, this->GetPosition().y);
		}
		if (this->GetPosition().y > 450) {
			this->Set2DPosition(this->GetPosition().x, this->GetPosition().y - deltaTime * m_velocity.y);
		}
		break;
	case 7:
		this->Set2DPosition(this->GetPosition().x + deltaTime * m_velocity.x, this->GetPosition().y);
		if (this->GetPosition().y > 450) {
			this->Set2DPosition(this->GetPosition().x, this->GetPosition().y - deltaTime * m_velocity.y);
		}
		break;
	case 8:
		this->Set2DPosition(this->GetPosition().x + deltaTime * m_velocity.x, this->GetPosition().y);
		if (this->GetPosition().y > 450) {
			this->Set2DPosition(this->GetPosition().x, this->GetPosition().y - deltaTime * m_velocity.y);
		}
		break;
	case 9:
		this->Set2DPosition(this->GetPosition().x + deltaTime * m_velocity.x, this->GetPosition().y);
		if (this->GetPosition().y > 450) {
			this->Set2DPosition(this->GetPosition().x, this->GetPosition().y - deltaTime * m_velocity.y);
		}
		break;
	case 10:
		this->Set2DPosition(this->GetPosition().x + deltaTime * m_velocity.x, this->GetPosition().y);
		if (this->GetPosition().y < 650) {
			this->Set2DPosition(this->GetPosition().x, this->GetPosition().y + deltaTime * m_velocity.y);
		}
		break;
	case 11:
		this->Set2DPosition(this->GetPosition().x + deltaTime * m_velocity.x, this->GetPosition().y);
		if (this->GetPosition().y < 650) {
			this->Set2DPosition(this->GetPosition().x, this->GetPosition().y + deltaTime * m_velocity.y);
		}
		break;
	case 12:
		this->Set2DPosition(this->GetPosition().x + deltaTime * m_velocity.x, this->GetPosition().y);
		break;
	case 13:
		this->Set2DPosition(this->GetPosition().x + deltaTime * m_velocity.x, this->GetPosition().y);
		break;
	default:
		break;
	}
	
	if (this->GetPosition().x >= 1280)
	{
		m_state = 2;
		this->Set2DPosition(0, this->GetPosition().y);
		this->SetSize(0.0f, 0.0f);
		m_velocity.x = 0;
		m_velocity.y = 0;
	}
}

void Guest::Set2DPosition(GLint x, GLint y)
{
	m_position = Vector3((float)x, (float)y, 0.0f);
	CalculateWorldMatrix();
}

void Guest::Set2DPosition(Vector2 position)
{
	m_position = Vector3(position.x, position.y, 0.0f);
	CalculateWorldMatrix();
}

void Guest::SetSize(GLint width, GLint height)
{
	m_iWidth = width;
	m_iHeight = height;
	m_scale = Vector3((GLfloat)m_iWidth, (GLfloat)m_iHeight, 1.0f);
	CalculateWorldMatrix();
}