#ifndef TEST_H__
#define TEST_H__

#include <iostream>
using namespace std;

class Test
{
public:
	Test(int num);
	~Test();
	void getnum();
	int target;
	//static int num_;
private:
	static int num_;//static���ݳ�Ա����������Ķ��󣬲�������������\
	                 ��static���ݳ�Ա����ʵ���������ǽ����ڴ濽���ģ������໥�����Ĵ��ڡ�
};



#endif  //TEST_H__
