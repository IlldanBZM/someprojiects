#include"ComboBox.h"
#include"Setting.h"

const Point LeftUpPos(13, 3);
bool Mark[100][100]; // ���ڱ�����꣬��Ϊtrue˵���������з������
void init();//��ʼ����ܺ���
void SetColor(const int a);
void SetCOORD(const int x,const int y);
void DeleteLine();

int main() {
	srand(time(0)); // ȡϵͳʱ��
	//���ع��
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	//������������
	ComboBox nowbox(Point(33, 3), Type(rand() % (sizeof(Type) + 1)));
	ComboBox nextbox(Point(60, 6), Type(rand() % (sizeof(Type) + 1)));
	
	init();//��ʼ�����

	char ch(NULL);
	while (1)//���û����س���ʼ��Ϸ
	{
		Sleep(100);
		ch = _getch();
		if (ch == 13)break;
	}
	while (1) //��ʼ��Ϸ
	{
		SetColor(15); SetCOORD(63, 19); cout << Setting::GetSumScore();//�������
		 //��������������ÿ��С��������겢���
		nowbox.Transform();
		nextbox.Transform();
		nextbox.Display();
		nowbox.Display();
		//������Ϸ�ٶ�
		Sleep(Setting::GetGameSpeed());
		//����û��ոռ��٣����ڽ��ٶȻָ�
		if (ch == 's')Setting::DoubleSpeed();
		ch = NULL;
		//ɾ����һʱ������ķ���
		nowbox.SetDisappear();
		if (_kbhit())//��Ӧ����
		{
			ch = _getch();
			if (ch == 'p')//��ͣ
			{
				ch = _getch();
				if (ch == 'p')continue;
			}
			if (ch == 'q')exit(0);//�˳�
			if (ch == 's')Setting::HalfSpeed();//����
			if (ch == 'a')nowbox.SetDirection(LEFT);//����
			if (ch == 'd')nowbox.SetDirection(RIGHT);//����
			if (ch == 'w')nowbox.Rotate();//��ת
		}
		nowbox.Transform();//��������λ��
		if (!nowbox.JudgeIllegal(Mark))nowbox.Transform();//�����º�����λ��Υ�棬���лָ���ת

		if (nowbox.JudgeMove(Mark))//�ж��Ƿ�����ƶ�
			nowbox.Move();

		else//�����ܼ����ƶ�����Ӧ��������һ������
		{
			nowbox.Display();
			if (nowbox.IsExit())exit(0);//�жϸ÷����Ƿ�ͣ�ڳ����㣬��������Ϸ����
			nowbox.SetMark(Mark);//��ֹͣ�ƶ��ķ���������MARK����������Ϊtrue
			DeleteLine();//�ж��Ƿ��п��������У���������
			Setting::AddSpeed();
			nowbox = ComboBox(Point(33, 3), nextbox.GetType());//�µķ���
			nextbox.SetDisappear();
			nextbox = ComboBox(Point(60, 6), Type(rand() % (sizeof(Type) + 1)));
		}
	}
}
void init()
{
	SetColor(10);
	int x = LeftUpPos.GetX(), y = LeftUpPos.GetY();
	//�����󷽿�
	for (int i = 0; i < 30; ++i)
	{
		SetCOORD(x, 2);  Mark[x][2] = true; cout << "��";
		SetCOORD(x, 23); Mark[x][23] = true; cout << "��";
		x += 2;
	}
	for (int i = 0; i < 21; ++i)
	{
		SetCOORD(LeftUpPos.GetX(), y);
		Mark[LeftUpPos.GetX()][y] = true;
		cout << "��";
		SetCOORD(71, y);
		Mark[71][y] = true;
		cout << "��";
		SetCOORD(51, y);
		Mark[51][y] = true;
		cout << "��";
		y += 1;
	}
	//С�������
	for (int i = 53; i <= 69; i += 2)
	{
		SetCOORD(i, 11);
		Mark[i][11] = true;
		cout << "��";
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
				flag = true;//��һ�в���������Ӧ��ɾ��
				break;
			}
			x += 2;
		}
		if (!flag)//��һ��Ӧ������
		{
			for (int j = 22; j > 3; j--)
			{
				x = LeftUpPos.GetX() + 2;
				for (int i = 0; i < 18; i++)
				{
					if (j <= y) // Ӧ��ɾ���������ϵ����������´�һ��λ��
						Mark[x][j] = Mark[x][j - 1];
					if (Mark[x][j])
					{
						SetColor(7);
						SetCOORD(x, j);
						cout << "��";
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