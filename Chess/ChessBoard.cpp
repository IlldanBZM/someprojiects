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
	//�ĸ���
	m_allchess[0][0] = new Chess(CHE, GREEN, Point(0, 0));
	m_allchess[0][8] = new Chess(CHE, GREEN, Point(0, 8));
	m_allchess[9][0] = new Chess(CHE, RED, Point(9, 0));
	m_allchess[9][8] = new Chess(CHE, RED, Point(9, 8));
	//�ĸ���
	m_allchess[0][1] = new Chess(MA, GREEN, Point(0, 1));
	m_allchess[0][7] = new Chess(MA, GREEN, Point(0, 7));
	m_allchess[9][1] = new Chess(MA, RED, Point(9, 1));
	m_allchess[9][7] = new Chess(MA, RED, Point(9, 7));
	//�ĸ���
	m_allchess[2][1] = new Chess(PAO, GREEN, Point(2, 1));
	m_allchess[2][7] = new Chess(PAO, GREEN, Point(2, 7));
	m_allchess[7][1] = new Chess(PAO, RED, Point(7, 1));
	m_allchess[7][7] = new Chess(PAO, RED, Point(7, 7));
	//����˧
	m_allchess[0][4] = new Chess(SHUAI, GREEN, Point(0, 4));
	m_allchess[9][4] = new Chess(SHUAI, RED, Point(9, 4));
	//��
	m_allchess[0][2] = new Chess(XIANG, GREEN, Point(0, 2));
	m_allchess[0][6] = new Chess(XIANG, GREEN, Point(0, 6));
	m_allchess[9][2] = new Chess(XIANG, RED, Point(9, 2));
	m_allchess[9][6] = new Chess(XIANG, RED, Point(9, 6));
	//ʿ
	m_allchess[0][3] = new Chess(SHI, GREEN, Point(0, 3));
	m_allchess[0][5] = new Chess(SHI, GREEN, Point(0, 5));
	m_allchess[9][3] = new Chess(SHI, RED, Point(9, 3));
	m_allchess[9][5] = new Chess(SHI, RED, Point(9, 5));
	//��
	for (int i = 0; i <= 8; i += 2)
		m_allchess[3][i] = new Chess(BING, GREEN, Point(3, i));
	for (int i = 0; i <= 8; i += 2)
		m_allchess[6][i] = new Chess(BING, RED, Point(6, i));

}

void ChessBoard::PrintBoard()
{
	for (int i = 0; i < 10; i++)
	{
		//������������ӽ�
		if (i == 0 || i == 5)
		{
			cout << "  ";
			for (int j = 0; j < 9; j++)
			{
				if (i == 0)cout << j << " ";//��������
				if (i == 5)cout << "һ";//�ӽ�
			}
			cout << endl;
		}

		for (int j = 0; j < 9; j++)
		{
			if (j == 0) cout << i << " ";//��������

			if (m_allchess[i][j] == nullptr)cout << "ʮ";//û������
			else
			{
				//������Ӫ������ɫ
				if (m_allchess[i][j]->GetCamp() == GREEN)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);

				if (m_allchess[i][j]->GetCamp() == RED)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);

				if (m_allchess[i][j]->GetType() == CHE)cout << "��";
				if (m_allchess[i][j]->GetType() == MA)cout << "��";
				if (m_allchess[i][j]->GetType() == SHUAI)cout << "˧";
				if (m_allchess[i][j]->GetType() == PAO)cout << "��";
				if (m_allchess[i][j]->GetType() == XIANG)cout << "��";
				if (m_allchess[i][j]->GetType() == SHI)cout << "ʿ";
				if (m_allchess[i][j]->GetType() == BING)cout << "��";

				//�ָ�Ĭ����ɫ����ɫ��
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
		}
		cout << endl;
	}
}
