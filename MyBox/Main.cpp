#include"ComboBox.h"
#include"Setting.h"

const Point LeftUpPos(13, 3);
bool Mark[100][100]; // 用于标记坐标，若为true说明该坐标有方块存在
void init();//初始化框架函数
void SetColor(const int a);
void SetCOORD(const int x,const int y);
void DeleteLine();

int main() {
	srand(time(0)); // 取系统时间
	//隐藏光标
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	//创建两个方块
	ComboBox nowbox(Point(33, 3), Type(rand() % (sizeof(Type) + 1)));
	ComboBox nextbox(Point(60, 6), Type(rand() % (sizeof(Type) + 1)));
	
	init();//初始化框架

	char ch(NULL);
	while (1)//当用户按回车开始游戏
	{
		Sleep(100);
		ch = _getch();
		if (ch == 13)break;
	}
	while (1) //开始游戏
	{
		SetColor(15); SetCOORD(63, 19); cout << Setting::GetSumScore();//输出分数
		 //计算两个方块中每个小方块的坐标并输出
		nowbox.Transform();
		nextbox.Transform();
		nextbox.Display();
		nowbox.Display();
		//控制游戏速度
		Sleep(Setting::GetGameSpeed());
		//如果用户刚刚加速，现在将速度恢复
		if (ch == 's')Setting::DoubleSpeed();
		ch = NULL;
		//删除上一时刻输出的方块
		nowbox.SetDisappear();
		if (_kbhit())//响应键盘
		{
			ch = _getch();
			if (ch == 'p')//暂停
			{
				ch = _getch();
				if (ch == 'p')continue;
			}
			if (ch == 'q')exit(0);//退出
			if (ch == 's')Setting::HalfSpeed();//加速
			if (ch == 'a')nowbox.SetDirection(LEFT);//左移
			if (ch == 'd')nowbox.SetDirection(RIGHT);//右移
			if (ch == 'w')nowbox.Rotate();//旋转
		}
		nowbox.Transform();//更新坐标位置
		if (!nowbox.JudgeIllegal(Mark))nowbox.Transform();//若更新后物体位置违规，进行恢复旋转

		if (nowbox.JudgeMove(Mark))//判断是否继续移动
			nowbox.Move();

		else//若不能继续移动，则应当生成下一个方块
		{
			nowbox.Display();
			if (nowbox.IsExit())exit(0);//判断该方块是否停在出生点，若是则游戏结束
			nowbox.SetMark(Mark);//将停止移动的方块坐标在MARK数组里设置为true
			DeleteLine();//判断是否有可消除的行，有则消除
			Setting::AddSpeed();
			nowbox = ComboBox(Point(33, 3), nextbox.GetType());//新的方块
			nextbox.SetDisappear();
			nextbox = ComboBox(Point(60, 6), Type(rand() % (sizeof(Type) + 1)));
		}
	}
}
void init()
{
	SetColor(10);
	int x = LeftUpPos.GetX(), y = LeftUpPos.GetY();
	//画出大方框
	for (int i = 0; i < 30; ++i)
	{
		SetCOORD(x, 2);  Mark[x][2] = true; cout << "■";
		SetCOORD(x, 23); Mark[x][23] = true; cout << "■";
		x += 2;
	}
	for (int i = 0; i < 21; ++i)
	{
		SetCOORD(LeftUpPos.GetX(), y);
		Mark[LeftUpPos.GetX()][y] = true;
		cout << "■";
		SetCOORD(71, y);
		Mark[71][y] = true;
		cout << "■";
		SetCOORD(51, y);
		Mark[51][y] = true;
		cout << "■";
		y += 1;
	}
	//小框架内容
	for (int i = 53; i <= 69; i += 2)
	{
		SetCOORD(i, 11);
		Mark[i][11] = true;
		cout << "■";
	}
	SetColor(11);
	SetCOORD(53, 3);  cout << " Next Box : ";
	SetCOORD(54, 13); cout << "Start :  Enter ";
	SetCOORD(54, 15); cout << "Pause :   P ";
	SetCOORD(54, 17); cout << "Exit  :   Q ";
	SetCOORD(54, 19);  cout << "Score :";
}

void DeleteLine()
{
	int x = LeftUpPos.GetX() + 2, y = LeftUpPos.GetY();
	bool flag(false);
	for (int j = 0; j < 20; j++)
	{
		for (int i = 0; i < 18; i++)
		{
			if (!Mark[x][y])
			{
				flag = true;//这一行不完整，不应该删除
				break;
			}
			x += 2;
		}
		if (!flag)//这一行应该消除
		{
			for (int j = 22; j > 3; j--)
			{
				x = LeftUpPos.GetX() + 2;
				for (int i = 0; i < 18; i++)
				{
					if (j <= y) // 应该删除的行以上的所有行往下错一个位置
						Mark[x][j] = Mark[x][j - 1];
					if (Mark[x][j])
					{
						SetColor(7);
						SetCOORD(x, j);
						cout << "■";
					}
					else
					{
						SetCOORD(x, j);
						cout << " ";
					}
					x += 2;
				}
			}
			Setting::AddScore();
		}
		y++;
		x = LeftUpPos.GetX() + 2;
		flag = false;
	}
}
void SetCOORD(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void SetColor(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}