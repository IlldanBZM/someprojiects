#ifndef GameManager_H
#define GameManager_H

#include"ChessBoard.h"


class GameManager
{
public:
	~GameManager() { m_chessboard.Clear(); }

	bool Move(Point startpos, Point targetpos);
	void ChangeCamp() 
	{
		if (m_nowcamp == RED)m_nowcamp = GREEN;
		else m_nowcamp = RED;
	}
	ChessCamp GetCamp(){ return m_nowcamp; }
	void Print(){	m_chessboard.PrintBoard();}
	bool IsEnd() { return m_chessboard.m_isend; }

	static GameManager*Instance();
private:
	ChessBoard m_chessboard;
	ChessCamp m_nowcamp;

	//单例模式 构造函数为私有的
	GameManager()
	{
		m_nowcamp = RED;
		m_chessboard= ChessBoard();
	}
	bool JudgeMoveLegel(Point startpos, Point targetpos);
	bool JudgeMoveRule(Point startpos, Point targetpos);
	int JudgeChessBetween(Point startpos, Point targetpos);

};


#endif // !GameManager_H
