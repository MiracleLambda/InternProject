#include "ScoreManager.h"
#include "GameObject/Shader.h"
#include "GameObject/Texture.h"
#include "GameObject/Model.h"
#include "GameObject/Camera.h"
#include "GameObject/Font.h"
#include "GameObject/Sprite2D.h"
#include "GameObject/Sprite3D.h"
#include "GameObject/Text.h"
#include <fstream> 
#include <iostream>
using namespace std;

ScoreManager::ScoreManager()
{
	std::string dataPath = "..\\Data\\Score.txt";
}

ScoreManager::~ScoreManager()
{
}

int ScoreManager::CalculateHighScore(int sc)
{
	fstream fin;
	fin.open("..\\Data\\Score.txt", ios::in);
	string data;
	getline(fin, data);
	fin.close();

	int tmp = stoi(data);
	if (sc > tmp)
	{
		fstream fout;
		fout.open("..\\Data\\Score.txt", ios::out | ios::trunc);
		fout << sc;
		fout.close();
		return sc;
	}
	else return tmp;
}


