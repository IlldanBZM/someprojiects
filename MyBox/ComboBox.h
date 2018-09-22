#ifndef COMBO_BOX
#define COMBO_BOX
#include"SingleBox.h"
enum Type { A, B, C, D, E};//一共五种组合方块
enum Form { a, b, c, d };//每个组合方块最多四种形态
enum Dir { LEFT, RIGHT ,EMPTY};
//组合方块类
class ComboBox :Object
{
private:
	SingleBox m_ComBox[4];//每个组合方块由四个小方块组成
	Type m_Type;
	Form m_Form;
	Dir m_Direction;
	int m_XDis;//每输出一个方块，x轴占两个坐标（y轴只占一个）
public:
	ComboBox(Point pos, Type);
	~ComboBox(){}
	Type GetType()const{return m_Type;}
	void SetDirection(const Dir dir) { m_Direction = dir; }
	void Display();
	void Transform();//确定每个小方块的坐标
	void SetDisappear();//删除组合方块
	void Move();
	void Rotate();
	bool JudgeMove(const bool mark[100][100]);//判断是否可以移动
	bool JudgeIllegal(const bool mark[100][100]);//判断当前位置是否违法
	void SetMark(bool mark[100][100]);//将停止的方块位置在Mark数组中记为true，与边界等效
	bool IsExit();
};
#endif