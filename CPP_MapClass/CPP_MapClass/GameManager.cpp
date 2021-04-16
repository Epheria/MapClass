#include "GameManager.h"

GameManager::GameManager()
{
	cout << "�� X �Է� :";
	cin >> m_ix;
	cout << "�� Y �Է� :";
	cin >> m_iy;
	cout << "�� ���� ���� �Է� :";
	cin >> m_iWidth;
	cout << "�� ���� ���� �Է� :";
	cin >> m_iHeight;
	cout << "[����]:q   [���� ����]:e   [��ź]:r" << endl;
	P.CreatePlayer(m_ix, m_iy);
}

void GameManager::Update()
{
	while (1)
	{
		AddMonster();
		PlayerDraw();
		UseFire();
		BulletDraw();
		MonsterDraw();
		Collision();
		CollisionBullet();
		ShowInfo();
		UseBomb();
		ExitGame();
		Sleep(50);
	}
}


void GameManager::AddMonster()
{
	if (P.GetCreate() == true)
	{
		if (GetMosnterCount() < MONSTER_MAX)
		{
			Monster tmp;
			tmp.CreateMonster(m_ix, m_iy, GetMosnterCount() + 1);
			M.push_back(tmp);
		}
		m_iMonsterCount = GetMosnterCount();
	}
	return;
}

void GameManager::MapDraw()
{
	MapDraw::BoxDraw(m_ix, m_iy, m_iWidth, m_iHeight);
}

void GameManager::PlayerDraw()
{
	P.MovePlayer(m_ix, m_iy, m_iWidth, m_iHeight);
}

void GameManager::MonsterDraw()
{
	if (M.empty())
	{
		return;
	}
	for (vector<Monster>::iterator iter = M.begin(); iter != M.end(); iter++)
		iter->MoveMonster(m_ix, m_iy, m_iWidth, m_iHeight);
}

void GameManager::BulletDraw()
{
	if (B.empty())
	{
		return;
	}
	for (vector<Bullet>::iterator iter = B.begin(); iter != B.end(); iter++)
		iter->MoveBullet(m_ix, m_iy, m_iWidth, m_iHeight);
}

void GameManager::Collision()
{
	bool check;
	for (vector<Monster>::iterator iter = M.begin(); iter != M.end(); iter++)
	{
		check = iter->CollisionMonster(P.PlayerPointx(), P.PlayerPointy());
		if (check == true)
		{
			M.erase(iter);
			m_iMonsterCount--;
			m_iKillCount++;
			return;
		}
	}
}

void GameManager::CollisionBullet()
{
	for (vector<Monster>::iterator iter = M.begin(); iter != M.end(); iter++)
	{
		for (vector<Bullet>::iterator iter2 = B.begin(); iter2 != B.end(); iter2++)
		{
			if (iter->MonsterPointx() == iter2->BulletPointx() &&
				iter->MonsterPointy() == iter2->BulletPointy())
			{
				M.erase(iter);
				B.erase(iter2);
				m_iMonsterCount--;
				m_iKillCount++;
				return;
			}
		}
	}
}

void GameManager::ShowInfo()
{
	MapDraw::TextDraw(m_iMonsterCount, m_iKillCount, m_iBulletCount, 0, 5);
}

void GameManager::ExitGame()
{
	if (P.GetExit() == true)
	{
		M.clear();
		B.clear();
		exit(1);
	}
}

void GameManager::UseBomb()
{
	if (P.GetBomb() == true)
	{
		for (vector<Monster>::iterator iter = M.begin(); iter != M.end(); iter++)
			iter->EraseMonster();
		for (vector<Bullet>::iterator iter = B.begin(); iter != B.end(); iter++)
			iter->EraseBullet();
		M.clear();
		B.clear();
	}
}

void GameManager::UseFire()
{
	if (P.GetFire() == true)
	{
		Bullet tmp;
		tmp.CreateBullet(P.PlayerPointx(), P.PlayerPointy(), GetFireCount() + 1);
		B.push_back(tmp);
		m_iBulletCount = GetFireCount();
	}
	return;
}

GameManager::~GameManager()
{
}
