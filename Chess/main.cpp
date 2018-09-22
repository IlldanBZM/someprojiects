#include"GameManager.h"
#define mymanager GameManager::Instance()

int main()
{
	cout << " 菜单" << endl << endl;
	cout << "1.开始游戏" << endl;
	cout << "2.退出" << endl << endl;
	cout << "请输入选项：" << endl;
	int c(0);
	cin >> c;
	if (c == 1)
	{
		mymanager->Print();
		while (1)
		{
			if (mymanager->GetCamp() == RED)cout << "现在轮到红方" << endl;
			else cout << "现在轮到绿方" << endl;

			cout << "输入起始点和目标点：";
			int sx, sy, tx, ty;
			cin >> sx >> sy >> tx >> ty;
			if (mymanager->Move(Point(sx, sy), Point(tx, ty)))
			{
				mymanager->Print();
				if (mymanager->IsEnd())
				{
					cout << "游戏结束！获胜方为：";
					if (mymanager->GetCamp() == RED)cout << "红方" << endl;
					else cout << "绿方" << endl;
					break;
				}
				mymanager->ChangeCamp();
			}
			else cout << "输入违法，请重新输入" << endl;
		}
	}
	if (c == 2)exit(0);
	cin.get();
	return 0;
}