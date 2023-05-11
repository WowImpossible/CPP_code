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

//注意类里面所有成员的初始化都是在构造函数里面完成的，包括类的初试化。可以用初始化列表来实现
class Container
{
public:
	Container():s(20)   //对Obj类进行初始化。不能直接在实例化时初始化，会报错
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