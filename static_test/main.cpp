#define _CRT_SECURE_NO_WARNINGS 1
#include "Test.h"
#include <iostream>
using namespace std;


int main(void)
{
	Test t1(10);
	t1.getnum();
	Test t2(100);
	t2.getnum();
	Test* t3 = new Test(20);  //new的返回值是一个指针
	t3->getnum();
	//cout << t1.target << endl;
	//cout << Test::num_ << endl;
	return 0;
}

