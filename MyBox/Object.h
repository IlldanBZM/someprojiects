#ifndef OBJECT
#define OBJECT
#include <list>
#include"Point.h"
#include<iostream>
#include<windows.h>
#include<time.h>
#include<conio.h>
using namespace std;
//物体类，一切游戏对象的基类
class Object
{
public:
	virtual void Display() = 0;//输出画面
	virtual void SetDisappear() = 0;//清除画面
protected:
	Point m_Position;
};
#endif

