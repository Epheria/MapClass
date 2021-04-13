#pragma once
#include "Macro.h"
#include "MapDraw.h"
#include "Player.h"
#include "Monster.h"
#include "Bullet.h"

class Map
{
private:
	int m_ix;
	int m_iy;
	int m_iWidth;
	int m_iHeight;

	int m_iMonsterCount;
	int m_iBulletCount;
	int m_iKillCount = 0;
	Player P;
	vector<Monster> M;
	vector<Bullet> B;
public:
	void AddMonster();
	void MapDraw();
	void PlayerDraw();
	void MonsterDraw();
	void BulletDraw();
	void Collision();
	void CollisionBullet();
	void ShowInfo();
	void ExitGame();
	void UseBomb();
	void UseFire();

	inline int GetMosnterCount()
	{
		return M.size();
	}
	inline int GetFireCount()
	{
		return B.size();
	}
	Map();
	~Map();
};

