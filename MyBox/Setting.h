#include <list>
#ifndef SETTING_H
#define SETTING_H
using namespace std;
//��ֵ�趨�࣬���ڼ���������ٶȵ�
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
	static int m_GameSpeed;     //��Ϸ�ٶ�,����ԽС�ٶ�Խ��
	static int m_SumScore;		// ����
};
#endif

