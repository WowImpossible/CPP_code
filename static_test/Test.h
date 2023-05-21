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
	static int num_;//static数据成员是与类关联的对象，不与类对象关联。\
	                 非static数据成员，在实例化对象都是进行内存拷贝的，都是相互独立的存在。
};



#endif  //TEST_H__
