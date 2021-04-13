#include"Mecro.h"
#include"MapDraw.h"
#include"Map.h"

void main()
{
	Map map;
	map.MapDraw();

	while (1)
	{
		map.AddMonster();
		map.PlayerDraw();
		map.UseFire();
		map.BulletDraw();
		map.MonsterDraw();
		map.Collision();
		map.CollisionBullet();
		map.ShowInfo();
		map.UseBomb();
		map.ExitGame();
		Sleep(50);
	}
}