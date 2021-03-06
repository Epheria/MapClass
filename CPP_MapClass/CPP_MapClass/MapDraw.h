#pragma once
#include"Macro.h"

class MapDraw
{
public:
	static void BoxDraw(int Start_x, int Start_y, int Width, int Height)
	{
		for (int y = 0; y < Height; y++)
		{
			gotoxy(Start_x, Start_y + y);
			if (y == 0)
			{
				cout << "┌";
				for (int x = 1; x < Width - 1; x++)
					cout << "──";
				cout << "┐";
			}
			else if (y == Height - 1)
			{
				cout << "└";
				for (int x = 1; x < Width - 1; x++)
					cout << "──";
				cout << "┘";
			}
			else
			{
				cout << "│";
				for (int x = 1; x < Width - 1; x++)
					cout << "  ";
				cout << "│";
			}
		}
		return;
	}
	static void DrawPoint(string str, int x, int y)
	{
		gotoxy(x * 2, y);
		cout << str;
		gotoxy(-1, -1);
		return;
	}
	static void DrawMidText(string str, int x, int y)
	{
		if (x > str.size() / 2)
			x -= str.size() / 2;
		gotoxy(x, y);
		cout << str;
		return;
	}
	static void TextDraw(int iMonsterCount, int iKillCount, int iBulletCount, int x, int y)
	{
		gotoxy(x, y);
		cout << "현재 몬스터 수 : " << iMonsterCount << "마리 생존" << endl;
		cout << "현재 킬 수 : " << iKillCount << "마리" << endl;
		cout << "발사한 총알 수 : " << iBulletCount << "발" << endl;
	}
	static void ErasePoint(int x, int y)
	{
		gotoxy(x * 2, y);
		cout << "  ";
		gotoxy(-1, -1);
		return;
	}
	MapDraw() {}
	static inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	~MapDraw() {}
};

