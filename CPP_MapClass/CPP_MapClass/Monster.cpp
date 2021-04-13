#include "Monster.h"

Monster::Monster()
{
}

void Monster::CreateMonster(int m_ix, int m_iy, int m_iMonsterCount)
{
	m_iCount = m_iMonsterCount;
	m_imx = m_ix + 4;
	m_imy = m_iy + 4;
}

void Monster::MoveMonster(int Start_x, int Start_y, int Width, int Height)
{
	bool check;
	MapDraw::DrawPoint(m_strMonster, m_imx, m_imy);
	int iSelect = rand() % 4;
	switch (iSelect)
	{
	case 0:
		MapDraw::ErasePoint(m_imx, m_imy);
		m_imx--;
		check = MoveCheckM(Start_x, Start_y, Width, Height);
		if (check == false)
			break;
		else
		{
			MapDraw::DrawPoint(m_strMonster, m_imx, m_imy);
			break;
		}
	case 1:
		MapDraw::ErasePoint(m_imx, m_imy);
		m_imx++;
		check = MoveCheckM(Start_x, Start_y, Width, Height);
		if (check == false)
			break;
		else
		{
			MapDraw::DrawPoint(m_strMonster, m_imx, m_imy);
			break;
		}
	case 2:
		MapDraw::ErasePoint(m_imx, m_imy);
		m_imy--;
		check = MoveCheckM(Start_x, Start_y, Width, Height);
		if (check == false)
			break;
		else
		{
			MapDraw::DrawPoint(m_strMonster, m_imx, m_imy);
			break;
		}
	case 3:
		MapDraw::ErasePoint(m_imx, m_imy);
		m_imy++;
		check = MoveCheckM(Start_x, Start_y, Width, Height);
		if (check == false)
			break;
		else
		{
			MapDraw::DrawPoint(m_strMonster, m_imx, m_imy);
			break;
		}
	}
}

bool Monster::MoveCheckM(int Start_x, int Start_y, int Width, int Height)
{
	for (int i = Start_x / 2; i < Start_x + Width; i++)
	{
		if (m_imx == i && m_imy == Start_y)
		{
			m_imy++;
			MapDraw::DrawPoint(m_strMonster, m_imx, m_imy);
			return false;
		}
		else if (m_imx == i && m_imy == Start_y + Height - 1)
		{
			m_imy--;
			MapDraw::DrawPoint(m_strMonster, m_imx, m_imy);
			return false;
		}
	}
	for (int i = Start_y; i < Start_y + Height; i++)
	{
		if (m_imx == Start_x / 2 && m_imy == i)
		{
			m_imx++;
			MapDraw::DrawPoint(m_strMonster, m_imx, m_imy);
			return false;
		}
		else if (m_imx == Start_x / 2 + Width - 2 && m_imy == i)
		{
			m_imx--;
			MapDraw::DrawPoint(m_strMonster, m_imx, m_imy);
			return false;
		}
	}
	return true;
}

bool Monster::CollisionMonster(int Player_x, int Player_y)
{
	if (Player_x == m_imx && Player_y == m_imy)
	{
		m_bDeath = true;
		return true;
	}
	else
		return false;
}

void Monster::EraseMonster()
{
	MapDraw::ErasePoint(m_imx, m_imy);
}

Monster::~Monster() {}