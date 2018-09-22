#ifndef POINT_H
#define POINT_H
//×ø±êÀà
class Point
{
public:
	Point(int x = 0, int y = 0) : m_x(x), m_y(y){};
	~Point() {};
	Point& operator=(const Point &p)
	{
		m_x = p.m_x;
		m_y = p.m_y;
		return *this;
	}
	void Set(const int x,const int y) {m_x = x;m_y = y;}
	void SetX(const int x) { m_x = x; }
	void SetY(const int y) { m_y = y; }
	int GetX() const { return m_x; }
	int GetY()const { return m_y; }
private:
	int m_x;
	int m_y;
};


#endif

