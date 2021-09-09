#pragma once
#include <map>
#include "GameManager/Singleton.h"
#include "GameConfig.h"
#include "GameObject/Shader.h"
#include "GameObject/Texture.h"
#include "GameObject/Model.h"
#include "GameObject/Font.h"
#include "GameObject/Camera.h"
#include "GameObject/Sprite2D.h"
#include "GameObject/Sprite3D.h"
#include "GameObject/Text.h"

class ScoreManager : public CSingleton<ScoreManager>
{
public:
	ScoreManager();
	~ScoreManager();
	int CalculateHighScore(int sc);
	int score;
};
