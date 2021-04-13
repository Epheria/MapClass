#include "Bullet.h"

Bullet::Bullet()
{

}

void Bullet::CreateBullet(int m_ix, int m_iy, int m_iBulletCount)
{
	m_iCount = m_iBulletCount;
	m_ibx = m_ix;
	m_iby = m_iy;
}

void Bullet::MoveBullet(int Start_x, int Start_y, int Width, int Height)
{
	bool check;
	m_bEnd = false;
	MapDraw::ErasePoint(m_ibx, m_iby);
	m_iby--;
	check = MoveCheckB(Start_x, Start_y, Width, Height);
	if (check == false)
	{
		MapDraw::ErasePoint(m_ibx, m_iby);
		m_bEnd = true;
		return;
	}
	else
		MapDraw::DrawPoint(m_strBullet, m_ibx, m_iby);
}

bool Bullet::MoveCheckB(int Start_x, int Start_y, int Width, int Height)
{
	for (int i = Start_x / 2; i < Start_x + Width; i++)
	{
		if (m_ibx == i && m_iby == Start_y)
		{
			m_iby++;
			return false;
		}
	}
	return true;
}

void Bullet::EraseBullet()
{
	MapDraw::ErasePoint(m_ibx, m_iby);
}

Bullet::~Bullet()
{

}