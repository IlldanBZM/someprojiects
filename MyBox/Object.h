#ifndef OBJECT
#define OBJECT
#include <list>
#include"Point.h"
#include<iostream>
#include<windows.h>
#include<time.h>
#include<conio.h>
using namespace std;
//�����࣬һ����Ϸ����Ļ���
class Object
{
public:
	virtual void Display() = 0;//�������
	virtual void SetDisappear() = 0;//�������
protected:
	Point m_Position;
};
#endif

