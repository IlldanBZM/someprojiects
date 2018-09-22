#include"GameManager.h"

//单例模式
GameManager * GameManager::Instance()
{
	static GameManager instance;
	return &instance;
}

bool GameManager::JudgeMoveLegel(Point startpos, Point targetpos)
{
	//若目标位置和起始位置相同，错误
	if (startpos == targetpos)return false;
	//如果起始选定位置没有棋子，或棋子阵营与当前玩家不一致，错误
	if (m_chessboard.GetChess(startpos) == nullptr||
		m_chessboard.GetChess(startpos)->GetCamp()!=m_nowcamp)
		return false;
	//如果目标位置越界，错误
	if (targetpos.GetX() < 0 || targetpos.GetX() > 9 || 
		targetpos.GetY() < 0 || targetpos.GetY() > 8)
		return false;


	return true;
}

bool GameManager::JudgeMoveRule(Point startpos, Point targetpos)
{
	//若是车
	if (m_chessboard.GetChess(startpos)->GetType() == CHE) 
	{
		
		if (startpos.GetX() == targetpos.GetX() || startpos.GetY() == targetpos.GetY())//目标和起始在一条直线上
			if (!JudgeChessBetween(startpos, targetpos))//中间没有棋子
			{
				if (m_chessboard.GetChess(targetpos) != nullptr)//若要吃子 
				{
					//必须要阵营不同
					if (m_chessboard.GetChess(startpos)->GetCamp() != m_chessboard.GetChess(targetpos)->GetCamp())
						return true;
				}
				//若不用吃子，直接走 
				else if(m_chessboard.GetChess(targetpos) == nullptr)
					return true;
			}
	}
	//若是炮
	else if (m_chessboard.GetChess(startpos)->GetType() == PAO)
	{
		if (m_chessboard.GetChess(targetpos) == nullptr)//若不用吃子
		{
			if (startpos.GetX() == targetpos.GetX() || startpos.GetY() == targetpos.GetY())
				if (!JudgeChessBetween(startpos, targetpos))return true;
		}
		else//若要吃子
		{
		if (m_chessboard.GetChess(startpos)->GetCamp() != m_chessboard.GetChess(targetpos)->GetCamp())
			if (startpos.GetX() == targetpos.GetX() || startpos.GetY() == targetpos.GetY())
				if (JudgeChessBetween(startpos, targetpos)==1)return true;
		}
	}
	//若是马
	else if (m_chessboard.GetChess(startpos)->GetType() == MA)
	{ 
		//若不用吃子，或要吃子且阵营不同
		if (m_chessboard.GetChess(targetpos) == nullptr ||
			(m_chessboard.GetChess(targetpos) != nullptr &&m_chessboard.GetChess(startpos)->GetCamp() != m_chessboard.GetChess(targetpos)->GetCamp()))
		{
			//若形成日字
			if (abs(targetpos.GetY() - startpos.GetY()) == 2 && abs(targetpos.GetX() - startpos.GetX()) == 1
				|| abs(targetpos.GetY() - startpos.GetY()) == 1 && abs(targetpos.GetX() - startpos.GetX()) == 2)
			{
				//若没有蹩马腿
				if (targetpos.GetY() - startpos.GetY() == 2 && m_chessboard.GetChess(Point(startpos.GetX(), startpos.GetY() + 1)) == nullptr ||
					targetpos.GetY() - startpos.GetY() == -2 && m_chessboard.GetChess(Point(startpos.GetX(), startpos.GetY() - 1)) == nullptr ||
					targetpos.GetX() - startpos.GetX() == 2 && m_chessboard.GetChess(Point(startpos.GetX() + 1, startpos.GetY())) == nullptr ||
					targetpos.GetX() - startpos.GetX() == -2 && m_chessboard.GetChess(Point(startpos.GetX() - 1, startpos.GetY())) == nullptr)
					return true;
			}
		}
	}

	return false;
}

bool GameManager::Move(Point startpos, Point targetpos)
{
	if (JudgeMoveLegel(startpos, targetpos) && JudgeMoveRule(startpos, targetpos))
	{
		m_chessboard.ChangeChess(startpos, targetpos);
			return true;
	}
	else return false;
}

//判断在直线上的两点间有多少棋子
int GameManager::JudgeChessBetween(Point startpos, Point targetpos)
{
	int num = 0;
	//若两点x轴相等
	if (startpos.GetX() == targetpos.GetX())
	{
		int x = startpos.GetX();
		if (startpos.GetY() > targetpos.GetY())
		{
			for (int i = targetpos.GetY()+1; i < startpos.GetY();i++) 
			{
				if (m_chessboard.GetChess(Point(x, i)) != nullptr)num++;
			}
		}
		else
		{
			for (int i = startpos.GetY() + 1; i < targetpos.GetY(); i++)
			{
				if (m_chessboard.GetChess(Point(x, i)) != nullptr)num++;
			}
		}
	}
	//若两点y轴相等
	else if (startpos.GetY() == targetpos.GetY())
	{
		int y = startpos.GetY();
		if (startpos.GetX() > targetpos.GetX())
		{
			for (int i = targetpos.GetX() + 1; i < startpos.GetX(); i++)
			{
				if (m_chessboard.GetChess(Point(i, y)) != nullptr)num++;
			}
		}
		else
		{
			for (int i = startpos.GetX() + 1; i < targetpos.GetX(); i++)
			{
				if (m_chessboard.GetChess(Point(i, y)) != nullptr)num++;
			}
		}
	}
	return num;
}
