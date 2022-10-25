#include "DrawMap.h"
#include "KeyControl.h"

int main()
{
	DrawMap dm;
	KeyControl kc;

	char key;


	dm.Init();
	dm.GridDraw(5, 5, 50, 20);
	dm.MenuDraw(10, 10);

	do
	{
	cout << "input key is " << kc.KeyInput(key);
	
	_getch();
	return 0;
}