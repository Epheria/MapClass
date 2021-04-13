#pragma once
#include "Macro.h"
#include "MapDraw.h"

class Monster
{
private:
	int m_iCount = 0;
	int m_imx;
	int m_imy;
	bool m_bDeath = false;
	string m_strMonster = "¢Á";
public:
	inline int MonsterPointx()
	{
		return m_imx;
	}
	inline int MonsterPointy()
	{
		return m_imy;
	}
	void CreateMonster(int m_ix, int m_iy, int m_iMonsterCount);
	void MoveMonster(int Start_x, int Start_y, int Width, int Height);
	bool CollisionMonster(int Player_x, int Player_y);
	bool MoveCheckM(int Start_x, int Start_y, int Width, int Height);
	void EraseMonster();
	Monster();
	~Monster();
};

