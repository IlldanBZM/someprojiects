#ifndef COMBO_BOX
#define COMBO_BOX
#include"SingleBox.h"
enum Type { A, B, C, D, E};//һ��������Ϸ���
enum Form { a, b, c, d };//ÿ����Ϸ������������̬
enum Dir { LEFT, RIGHT ,EMPTY};
//��Ϸ�����
class ComboBox :Object
{
private:
	SingleBox m_ComBox[4];//ÿ����Ϸ������ĸ�С�������
	Type m_Type;
	Form m_Form;
	Dir m_Direction;
	int m_XDis;//ÿ���һ�����飬x��ռ�������꣨y��ֻռһ����
public:
	ComboBox(Point pos, Type);
	~ComboBox(){}
	Type GetType()const{return m_Type;}
	void SetDirection(const Dir dir) { m_Direction = dir; }
	void Display();
	void Transform();//ȷ��ÿ��С���������
	void SetDisappear();//ɾ����Ϸ���
	void Move();
	void Rotate();
	bool JudgeMove(const bool mark[100][100]);//�ж��Ƿ�����ƶ�
	bool JudgeIllegal(const bool mark[100][100]);//�жϵ�ǰλ���Ƿ�Υ��
	void SetMark(bool mark[100][100]);//��ֹͣ�ķ���λ����Mark�����м�Ϊtrue����߽��Ч
	bool IsExit();
};
#endif