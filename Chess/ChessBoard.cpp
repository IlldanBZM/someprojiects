#include"ChessBoard.h"

ChessBoard::ChessBoard()
{
	m_isend = false;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			m_allchess[i][j] = nullptr;
		}
	}
	//四个车
	m_allchess[0][0] = new Chess(CHE, GREEN, Point(0, 0));
	m_allchess[0][8] = new Chess(CHE, GREEN, Point(0, 8));
	m_allchess[9][0] = new Chess(CHE, RED, Point(9, 0));
	m_allchess[9][8] = new Chess(CHE, RED, Point(9, 8));
	//四个马
	m_allchess[0][1] = new Chess(MA, GREEN, Point(0, 1));
	m_allchess[0][7] = new Chess(MA, GREEN, Point(0, 7));
	m_allchess[9][1] = new Chess(MA, RED, Point(9, 1));
	m_allchess[9][7] = new Chess(MA, RED, Point(9, 7));
	//四个炮
	m_allchess[2][1] = new Chess(PAO, GREEN, Point(2, 1));
	m_allchess[2][7] = new Chess(PAO, GREEN, Point(2, 7));
	m_allchess[7][1] = new Chess(PAO, RED, Point(7, 1));
	m_allchess[7][7] = new Chess(PAO, RED, Point(7, 7));
	//两个帅
	m_allchess[0][4] = new Chess(SHUAI, GREEN, Point(0, 4));
	m_allchess[9][4] = new Chess(SHUAI, RED, Point(9, 4));
	//象
	m_allchess[0][2] = new Chess(XIANG, GREEN, Point(0, 2));
	m_allchess[0][6] = new Chess(XIANG, GREEN, Point(0, 6));
	m_allchess[9][2] = new Chess(XIANG, RED, Point(9, 2));
	m_allchess[9][6] = new Chess(XIANG, RED, Point(9, 6));
	//士
	m_allchess[0][3] = new Chess(SHI, GREEN, Point(0, 3));
	m_allchess[0][5] = new Chess(SHI, GREEN, Point(0, 5));
	m_allchess[9][3] = new Chess(SHI, RED, Point(9, 3));
	m_allchess[9][5] = new Chess(SHI, RED, Point(9, 5));
	//兵
	for (int i = 0; i <= 8; i += 2)
		m_allchess[3][i] = new Chess(BING, GREEN, Point(3, i));
	for (int i = 0; i <= 8; i += 2)
		m_allchess[6][i] = new Chess(BING, RED, Point(6, i));

}

void ChessBoard::PrintBoard()
{
	for (int i = 0; i < 10; i++)
	{
		//输出上排坐标或河界
		if (i == 0 || i == 5)
		{
			cout << "  ";
			for (int j = 0; j < 9; j++)
			{
				if (i == 0)cout << j << " ";//上排坐标
				if (i == 5)cout << "一";//河界
			}
			cout << endl;
		}

		for (int j = 0; j < 9; j++)
		{
			if (j == 0) cout << i << " ";//左排坐标

			if (m_allchess[i][j] == nullptr)cout << "十";//没有棋子
			else
			{
				//根据阵营设置颜色
				if (m_allchess[i][j]->GetCamp() == GREEN)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);

				if (m_allchess[i][j]->GetCamp() == RED)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);

				if (m_allchess[i][j]->GetType() == CHE)cout << "车";
				if (m_allchess[i][j]->GetType() == MA)cout << "马";
				if (m_allchess[i][j]->GetType() == SHUAI)cout << "帅";
				if (m_allchess[i][j]->GetType() == PAO)cout << "炮";
				if (m_allchess[i][j]->GetType() == XIANG)cout << "象";
				if (m_allchess[i][j]->GetType() == SHI)cout << "士";
				if (m_allchess[i][j]->GetType() == BING)cout << "兵";

				//恢复默认颜色（白色）
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
		}
		cout << endl;
	}
}
