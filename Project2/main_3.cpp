#define _CRT_SECURE_NO_WARNINGS 1

#include "Student.h"
#include <stdio.h>

class Obj 
{
public:
	Obj(int num) : num_(num)
	{
		cout << "Obj()..." << endl;
		cout << num_ << endl;
	}
	~Obj()
	{
		cout << "~Obj()..." << endl;
		cout << num_ << endl;
	}
private:
	int num_;
};

//ע�����������г�Ա�ĳ�ʼ�������ڹ��캯��������ɵģ�������ĳ��Ի��������ó�ʼ���б���ʵ��
class Container
{
public:
	Container():s(20)   //��Obj����г�ʼ��������ֱ����ʵ����ʱ��ʼ�����ᱨ��
	{
		cout << "Container()..." << endl;
	}
	~Container()
	{
		cout << "~Container()..." << endl;
	}
private:
	Obj s;
};


int main(void)
{
	Container c;
	Obj s(40);
	return 0;
}