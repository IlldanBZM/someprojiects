#include"GameManager.h"
#define mymanager GameManager::Instance()

int main()
{
	cout << " �˵�" << endl << endl;
	cout << "1.��ʼ��Ϸ" << endl;
	cout << "2.�˳�" << endl << endl;
	cout << "������ѡ�" << endl;
	int c(0);
	cin >> c;
	if (c == 1)
	{
		mymanager->Print();
		while (1)
		{
			if (mymanager->GetCamp() == RED)cout << "�����ֵ��췽" << endl;
			else cout << "�����ֵ��̷�" << endl;

			cout << "������ʼ���Ŀ��㣺";
			int sx, sy, tx, ty;
			cin >> sx >> sy >> tx >> ty;
			if (mymanager->Move(Point(sx, sy), Point(tx, ty)))
			{
				mymanager->Print();
				if (mymanager->IsEnd())
				{
					cout << "��Ϸ��������ʤ��Ϊ��";
					if (mymanager->GetCamp() == RED)cout << "�췽" << endl;
					else cout << "�̷�" << endl;
					break;
				}
				mymanager->ChangeCamp();
			}
			else cout << "����Υ��������������" << endl;
		}
	}
	if (c == 2)exit(0);
	cin.get();
	return 0;
}