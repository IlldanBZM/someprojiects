#include"SingleBox.h"
void SingleBox:: Display()
{
	COORD pos;
	pos.X = m_Position.GetX();
	pos.Y = m_Position.GetY();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), m_color);
	cout << "¡ö";
}
void SingleBox::SetDisappear()
{
	COORD pos;
	pos.X = m_Position.GetX();
	pos.Y = m_Position.GetY();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	cout << " ";
}