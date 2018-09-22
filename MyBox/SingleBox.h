#ifndef SINGLE_BOX
#define SINGLE_BOX
#include"Object.h"
//С������
class SingleBox :Object
{
private:
	int m_color;
public:
	SingleBox() {}
	SingleBox(Point pos, int color)
	{
		m_Position = pos;
		m_color = color;
	}
	~SingleBox(){}
	void Display();//���С����
	void SetDisappear();//ɾ��С����
	int  GetBoxX() const{ return m_Position.GetX(); }
	int  GetBoxY()const{ return m_Position.GetY(); }
};
#endif
