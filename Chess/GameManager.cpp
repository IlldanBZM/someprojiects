#include"GameManager.h"

//����ģʽ
GameManager * GameManager::Instance()
{
	static GameManager instance;
	return &instance;
}

bool GameManager::JudgeMoveLegel(Point startpos, Point targetpos)
{
	//��Ŀ��λ�ú���ʼλ����ͬ������
	if (startpos == targetpos)return false;
	//�����ʼѡ��λ��û�����ӣ���������Ӫ�뵱ǰ��Ҳ�һ�£�����
	if (m_chessboard.GetChess(startpos) == nullptr||
		m_chessboard.GetChess(startpos)->GetCamp()!=m_nowcamp)
		return false;
	//���Ŀ��λ��Խ�磬����
	if (targetpos.GetX() < 0 || targetpos.GetX() > 9 || 
		targetpos.GetY() < 0 || targetpos.GetY() > 8)
		return false;


	return true;
}

bool GameManager::JudgeMoveRule(Point startpos, Point targetpos)
{
	//���ǳ�
	if (m_chessboard.GetChess(startpos)->GetType() == CHE) 
	{
		
		if (startpos.GetX() == targetpos.GetX() || startpos.GetY() == targetpos.GetY())//Ŀ�����ʼ��һ��ֱ����
			if (!JudgeChessBetween(startpos, targetpos))//�м�û������
			{
				if (m_chessboard.GetChess(targetpos) != nullptr)//��Ҫ���� 
				{
					//����Ҫ��Ӫ��ͬ
					if (m_chessboard.GetChess(startpos)->GetCamp() != m_chessboard.GetChess(targetpos)->GetCamp())
						return true;
				}
				//�����ó��ӣ�ֱ���� 
				else if(m_chessboard.GetChess(targetpos) == nullptr)
					return true;
			}
	}
	//������
	else if (m_chessboard.GetChess(startpos)->GetType() == PAO)
	{
		if (m_chessboard.GetChess(targetpos) == nullptr)//�����ó���
		{
			if (startpos.GetX() == targetpos.GetX() || startpos.GetY() == targetpos.GetY())
				if (!JudgeChessBetween(startpos, targetpos))return true;
		}
		else//��Ҫ����
		{
		if (m_chessboard.GetChess(startpos)->GetCamp() != m_chessboard.GetChess(targetpos)->GetCamp())
			if (startpos.GetX() == targetpos.GetX() || startpos.GetY() == targetpos.GetY())
				if (JudgeChessBetween(startpos, targetpos)==1)return true;
		}
	}
	//������
	else if (m_chessboard.GetChess(startpos)->GetType() == MA)
	{ 
		//�����ó��ӣ���Ҫ��������Ӫ��ͬ
		if (m_chessboard.GetChess(targetpos) == nullptr ||
			(m_chessboard.GetChess(targetpos) != nullptr &&m_chessboard.GetChess(startpos)->GetCamp() != m_chessboard.GetChess(targetpos)->GetCamp()))
		{
			//���γ�����
			if (abs(targetpos.GetY() - startpos.GetY()) == 2 && abs(targetpos.GetX() - startpos.GetX()) == 1
				|| abs(targetpos.GetY() - startpos.GetY()) == 1 && abs(targetpos.GetX() - startpos.GetX()) == 2)
			{
				//��û��������
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

//�ж���ֱ���ϵ�������ж�������
int GameManager::JudgeChessBetween(Point startpos, Point targetpos)
{
	int num = 0;
	//������x�����
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
	//������y�����
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
