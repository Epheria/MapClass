#pragma once
#include "Macro.h"
#include "MapDraw.h"

class Player
{
private:
	bool m_bFire;
	bool m_bCreate;
	bool m_bBomb;
	bool m_bExit;
	int m_ipx;
	int m_ipy;
	string m_strPlayer = "¢»";
public:
	inline int PlayerPointx()
	{
		return m_ipx;
	}
	inline int PlayerPointy()
	{
		return m_ipy;
	}
	void CreatePlayer(int m_ix, int m_iy);
	void MovePlayer(int Start_x, int Start_y, int Width, int Height);
	bool MoveCheckP(int Start_x, int Start_y, int Width, int Height);
	inline bool GetExit()
	{
		if (m_bExit == true)
			return true;
		else
			return false;
	}
	inline char GetBomb()
	{
		if (m_bBomb == true)
			return true;
		else
			return false;
	}
	inline char GetCreate()
	{
		if (m_bCreate == true)
			return true;
		else
			return false;
	}
	inline char GetFire()
	{
		if (m_bFire == true)
			return true;
		else
			return false;
	}
	Player();
	~Player();
};