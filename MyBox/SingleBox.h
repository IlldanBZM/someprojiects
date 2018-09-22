#ifndef SINGLE_BOX
#define SINGLE_BOX
#include"Object.h"
//小方块类
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
	void Display();//输出小方块
	void SetDisappear();//删除小方块
	int  GetBoxX() const{ return m_Position.GetX(); }
	int  GetBoxY()const{ return m_Position.GetY(); }
};
#endif
