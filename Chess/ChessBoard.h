#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include<Windows.h>
#include"chess.h"

class ChessBoard
{
public:
	bool m_isend;

	ChessBoard();
	~ChessBoard() {}

	void PrintBoard();
	void ChangeChess(Point spos, Point tpos)
	{
		if (m_allchess[tpos.GetX()][tpos.GetY()] != nullptr)
		{
			if (m_allchess[tpos.GetX()][tpos.GetY()]->GetType() == SHUAI)m_isend = true;

			delete m_allchess[tpos.GetX()][tpos.GetY()];
		}
		m_allchess[tpos.GetX()][tpos.GetY()] = m_allchess[spos.GetX()][spos.GetY()];
		m_allchess[spos.GetX()][spos.GetY()] = nullptr;

	}
	Chess* GetChess(Point pos)
	{
		return m_allchess[pos.GetX()][pos.GetY()];
	}
	void Clear() {
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (m_allchess[i][j] != nullptr)
					delete m_allchess[i][j];
			}
		}
	}

private:
	Chess* m_allchess[10][9];
};



#endif 
