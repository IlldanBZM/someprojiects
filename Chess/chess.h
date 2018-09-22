#ifndef CHESS_H
#define CHESS_H

#include"Point.h"

enum ChessCamp
{
	RED,GREEN
};

enum ChessType
{
	MA,SHUAI,CHE,PAO,SHI,BING,XIANG
};

class Chess
{
public:
	Chess(ChessType type, ChessCamp camp, Point position) 
		:m_type(type),m_camp(camp),m_position(position)
	{}
	~Chess(){}

	Point GetPosition()const { return m_position; }
	void SetPosition(const Point newposition) { m_position = newposition; }
	ChessType GetType()const { return m_type; }
	ChessCamp GetCamp()const { return m_camp; }

private:
	ChessType m_type;
	ChessCamp m_camp;
	Point m_position;

};

#endif // !CHESS_H
