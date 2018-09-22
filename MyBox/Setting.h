#include <list>
#ifndef SETTING_H
#define SETTING_H
using namespace std;
//数值设定类，用于计算分数和速度等
class Setting
{
public:
	static int GetSumScore() { return m_SumScore; }
	static void AddSpeed() {  m_GameSpeed -= 3; }
	static void AddScore() { m_SumScore++; }
	static int GetGameSpeed() { return m_GameSpeed; }
	static void HalfSpeed() { m_GameSpeed /= 2; }
	static void DoubleSpeed(){ m_GameSpeed *= 2; }
private:
	static int m_GameSpeed;     //游戏速度,数字越小速度越快
	static int m_SumScore;		// 分数
};
#endif

