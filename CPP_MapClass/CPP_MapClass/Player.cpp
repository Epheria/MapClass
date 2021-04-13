#include "Player.h"

Player::Player()
{
}

void Player::CreatePlayer(int m_ix, int m_iy)
{
	m_ipx = m_ix * 2;
	m_ipy = m_iy * 2;
}

void Player::MovePlayer(int Start_x, int Start_y, int Width, int Height)
{
	m_bBomb = false;
	m_bCreate = false;
	m_bFire = false;
	MapDraw::DrawPoint(m_strPlayer, m_ipx, m_ipy);
	char ch;
	bool check;
	if (_kbhit())
	{
		ch = _getch();
		switch (ch)
		{
		case LEFT:
			MapDraw::ErasePoint(m_ipx, m_ipy);
			m_ipx--;
			check = MoveCheckP(Start_x, Start_y, Width, Height);
			if (check == false)
				break;
			else
			{
				MapDraw::DrawPoint(m_strPlayer, m_ipx, m_ipy);
				break;
			}
		case RIGHT:
			MapDraw::ErasePoint(m_ipx, m_ipy);
			m_ipx++;
			check = MoveCheckP(Start_x, Start_y, Width, Height);
			if (check == false)
				break;
			else
			{
				MapDraw::DrawPoint(m_strPlayer, m_ipx, m_ipy);
				break;
			}
		case UP:
			MapDraw::ErasePoint(m_ipx, m_ipy);
			m_ipy--;
			check = MoveCheckP(Start_x, Start_y, Width, Height);
			if (check == false)
				break;
			else
			{
				MapDraw::DrawPoint(m_strPlayer, m_ipx, m_ipy);
				break;
			}
		case DOWN:
			MapDraw::ErasePoint(m_ipx, m_ipy);
			m_ipy++;
			check = MoveCheckP(Start_x, Start_y, Width, Height);
			if (check == false)
				break;
			else
			{
				MapDraw::DrawPoint(m_strPlayer, m_ipx, m_ipy);
				break;
			}
		case FIRE:
			m_bFire = true;
			break;
		case BOMB:
			m_bBomb = true;
			break;
		case CREATE:
			m_bCreate = true;
			break;
		case EXIT:
			m_bExit = true;
			break;
		}
	}
}

bool Player::MoveCheckP(int Start_x, int Start_y, int Width, int Height)
{
	for (int i = Start_x / 2; i < Start_x + Width; i++)
	{
		if (m_ipx == i && m_ipy == Start_y)
		{
			m_ipy++;
			MapDraw::DrawPoint(m_strPlayer, m_ipx, m_ipy);
			return false;
		}
		else if (m_ipx == i && m_ipy == Start_y + Height - 1)
		{
			m_ipy--;
			MapDraw::DrawPoint(m_strPlayer, m_ipx, m_ipy);
			return false;
		}
	}
	for (int i = Start_y; i < Start_y + Height; i++)
	{
		if (m_ipx == Start_x / 2 && m_ipy == i)
		{
			m_ipx++;
			MapDraw::DrawPoint(m_strPlayer, m_ipx, m_ipy);
			return false;
		}
		else if (m_ipx == Start_x / 2 + Width - 2 && m_ipy == i)
		{
			m_ipx--;
			MapDraw::DrawPoint(m_strPlayer, m_ipx, m_ipy);
			return false;
		}
	}
	return true;
}

Player::~Player() {}