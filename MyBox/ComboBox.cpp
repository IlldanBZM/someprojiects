#include "ComboBox.h"

ComboBox::ComboBox(Point pos, Type type)
{
	m_XDis = 2;
	m_Position = pos;
	m_Type = type;
	m_Form = a;
	m_Direction = EMPTY;
}
bool ComboBox::JudgeIllegal(const bool mark[100][100])
{
	for (int i = 0; i < 4; i++)
	{
		if (mark[m_ComBox[i].GetBoxX()][m_ComBox[i].GetBoxY()] == true)//方块旋转后触碰了边界
		{
			//反旋转
			if (m_Form == a) { m_Form = d;  return false; }
			if (m_Form == b) { m_Form = a;   return false; }
			if (m_Form == c) { m_Form = b;   return false; }
			if (m_Form == d) { m_Form = c;  return false; }
		}
	}
	return true;
}
void ComboBox::Transform()
{
	//旋转皆为逆时针
	if (m_Type == A)//L形
	{
		if (m_Form == a)
		{
			m_ComBox[0] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY()), 3);
			m_ComBox[1] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY() + 1), 3);
			m_ComBox[2] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY() + 2), 3);
			m_ComBox[3] = SingleBox(Point(this->m_Position.GetX() + 1 * m_XDis, this->m_Position.GetY() + 2), 3);
		}
		if (m_Form == b)
		{
			m_ComBox[0] = SingleBox(Point(this->m_Position.GetX() - 1 * m_XDis, this->m_Position.GetY() + 1), 3);
			m_ComBox[1] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY() + 1), 3);
			m_ComBox[2] = SingleBox(Point(this->m_Position.GetX() + 1 * m_XDis, this->m_Position.GetY() + 1), 3);
			m_ComBox[3] = SingleBox(Point(this->m_Position.GetX() + 1 * m_XDis, this->m_Position.GetY()), 3);
		}
		if (m_Form == c)
		{
			m_ComBox[0] = SingleBox(Point(this->m_Position.GetX() - 1 * m_XDis, this->m_Position.GetY()), 3);
			m_ComBox[1] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY()), 3);
			m_ComBox[2] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY() + 1), 3);
			m_ComBox[3] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY() + 2), 3);
		}
		if (m_Form == d)
		{
			m_ComBox[0] = SingleBox(Point(this->m_Position.GetX() - 1 * m_XDis, this->m_Position.GetY() + 2), 3);
			m_ComBox[1] = SingleBox(Point(this->m_Position.GetX() - 1 * m_XDis, this->m_Position.GetY() + 1), 3);
			m_ComBox[2] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY() + 1), 3);
			m_ComBox[3] = SingleBox(Point(this->m_Position.GetX() + 1 * m_XDis, this->m_Position.GetY() + 1), 3);
		}
	}
	if (m_Type == B)//直线形
	{
		if (m_Form == a || m_Form == c)
		{
			m_ComBox[0] = SingleBox(Point(this->m_Position.GetX() - 1 * m_XDis, this->m_Position.GetY()), 4);
			m_ComBox[1] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY()), 4);
			m_ComBox[2] = SingleBox(Point(this->m_Position.GetX() + 1 * m_XDis, this->m_Position.GetY()), 4);
			m_ComBox[3] = SingleBox(Point(this->m_Position.GetX() + 2 * m_XDis, this->m_Position.GetY()), 4);
		}
		if (m_Form == b || m_Form == d)
		{
			m_ComBox[0] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY() - 2), 4);
			m_ComBox[1] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY() - 1), 4);
			m_ComBox[2] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY()), 4);
			m_ComBox[3] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY() + 1), 4);
		}
	}
	if (m_Type == C)//方形
	{
		m_ComBox[0] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY()), 5);
		m_ComBox[1] = SingleBox(Point(this->m_Position.GetX() + 1 * m_XDis, this->m_Position.GetY()), 5);
		m_ComBox[2] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY() + 1), 5);
		m_ComBox[3] = SingleBox(Point(this->m_Position.GetX() + 1 * m_XDis, this->m_Position.GetY() + 1), 5);
	}
	if (m_Type == D)//闪电形
	{
		if (m_Form == a || m_Form == c)
		{
			m_ComBox[0] = SingleBox(Point(this->m_Position.GetX() - 1 * m_XDis, this->m_Position.GetY()), 6);
			m_ComBox[1] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY()), 6);
			m_ComBox[2] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY() + 1), 6);
			m_ComBox[3] = SingleBox(Point(this->m_Position.GetX() + 1 * m_XDis, this->m_Position.GetY() + 1), 6);
		}
		if (m_Form == b || m_Form == d)
		{
			m_ComBox[0] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY() - 1), 6);
			m_ComBox[1] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY()), 6);
			m_ComBox[2] = SingleBox(Point(this->m_Position.GetX() - 1 * m_XDis, this->m_Position.GetY()), 6);
			m_ComBox[3] = SingleBox(Point(this->m_Position.GetX() - 1 * m_XDis, this->m_Position.GetY() + 1), 6);
		}
	}
	if (m_Type == E)//凸字形
	{
		if (m_Form == a)
		{
			m_ComBox[0] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY()), 9);
			m_ComBox[1] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY() + 1), 9);
			m_ComBox[2] = SingleBox(Point(this->m_Position.GetX() - 1 * m_XDis, this->m_Position.GetY() + 1), 9);
			m_ComBox[3] = SingleBox(Point(this->m_Position.GetX() + 1 * m_XDis, this->m_Position.GetY() + 1), 9);
		}
		if (m_Form == b)
		{
			m_ComBox[0] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY()), 9);
			m_ComBox[1] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY() + 1), 9);
			m_ComBox[2] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY() + 2), 9);
			m_ComBox[3] = SingleBox(Point(this->m_Position.GetX() - 1 * m_XDis, this->m_Position.GetY() + 1), 9);
		}
		if (m_Form == c)
		{
			m_ComBox[0] = SingleBox(Point(this->m_Position.GetX() - 1 * m_XDis, this->m_Position.GetY() + 1), 9);
			m_ComBox[1] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY() + 1), 9);
			m_ComBox[2] = SingleBox(Point(this->m_Position.GetX() + 1 * m_XDis, this->m_Position.GetY() + 1), 9);
			m_ComBox[3] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY() + 2), 9);
		}
		if (m_Form == d)
		{
			m_ComBox[0] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY()), 9);
			m_ComBox[1] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY() + 1), 9);
			m_ComBox[2] = SingleBox(Point(this->m_Position.GetX(), this->m_Position.GetY() + 2), 9);
			m_ComBox[3] = SingleBox(Point(this->m_Position.GetX() + 1 * m_XDis, this->m_Position.GetY() + 1), 9);
		}
	}
}
void ComboBox::Display()//输出方块
{
	for (int i = 0; i < 4; i++)
		m_ComBox[i].Display();
}
void ComboBox::SetDisappear()//删除方块
{
	for (int i = 0; i < 4; i++)
		m_ComBox[i].SetDisappear();
}
void ComboBox::Move()
{
	m_Position.SetY(m_Position.GetY() + 1);
	if (m_Direction == LEFT)m_Position.SetX(m_Position.GetX() - 1 * m_XDis);
	if (m_Direction == RIGHT)m_Position.SetX(m_Position.GetX() + 1 * m_XDis);
	m_Direction = EMPTY;
}
void ComboBox::Rotate()
{
	if (m_Form == a) { m_Form = b; return; }
	if (m_Form == b) { m_Form = c; return; }
	if (m_Form == c) { m_Form = d; return; }
	if (m_Form == d) { m_Form = a; return; }
}
bool ComboBox::JudgeMove(const bool mark[100][100])//
{
	if (this->m_Direction == LEFT)
	{
		if (mark[m_ComBox[0].GetBoxX() - m_XDis][m_ComBox[0].GetBoxY()] == true ||
			mark[m_ComBox[1].GetBoxX() - m_XDis][m_ComBox[1].GetBoxY()] == true ||
			mark[m_ComBox[2].GetBoxX() - m_XDis][m_ComBox[2].GetBoxY()] == true ||
			mark[m_ComBox[3].GetBoxX() - m_XDis][m_ComBox[3].GetBoxY()] == true)
			//即将碰到左边界
			m_Direction = EMPTY;
	}
	if (this->m_Direction == RIGHT)
	{
		if (mark[m_ComBox[0].GetBoxX() + m_XDis][m_ComBox[0].GetBoxY()] == true ||
			mark[m_ComBox[1].GetBoxX() + m_XDis][m_ComBox[1].GetBoxY()] == true ||
			mark[m_ComBox[2].GetBoxX() + m_XDis][m_ComBox[2].GetBoxY()] == true ||
			mark[m_ComBox[3].GetBoxX() + m_XDis][m_ComBox[3].GetBoxY()] == true)
			//即将碰到右边界
			m_Direction = EMPTY;
	}
	if (mark[m_ComBox[0].GetBoxX()][m_ComBox[0].GetBoxY() + 1] == true ||
		mark[m_ComBox[1].GetBoxX()][m_ComBox[1].GetBoxY() + 1] == true ||
		mark[m_ComBox[2].GetBoxX()][m_ComBox[2].GetBoxY() + 1] == true ||
		mark[m_ComBox[3].GetBoxX()][m_ComBox[3].GetBoxY() + 1] == true)
		//即将停止
		return false;
	else return true;
}
void ComboBox::SetMark(bool mark[100][100])
{
	for (int i = 0; i < 4; i++)
		mark[m_ComBox[i].GetBoxX()][m_ComBox[i].GetBoxY()] = true;
}
bool ComboBox::IsExit()
{
	if (m_Position.GetY() == 3)return true;
	else return false;
}
