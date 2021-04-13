#pragma once
#include "Macro.h"
#include "MapDraw.h"

class Bullet
{
private:
	bool m_bEnd;
	int m_iCount;
	int m_ibx;
	int m_iby;
	string m_strBullet = "*";
public:
	void MoveBullet(int Player_x, int Player_y, int Width, int Height);
	void CreateBullet(int m_ix, int m_iy, int m_iBulletCount);
	bool MoveCheckB(int Start_x, int Start_y, int Width, int Height);
	void EraseBullet();
	inline bool GetEnd()
	{
		if (m_bEnd == true)
			return true;
		else
			return false;
	}
	inline int BulletPointx()
	{
		return m_ibx;
	}
	inline int BulletPointy()
	{
		return m_iby;
	}
	Bullet();
	~Bullet();
};

