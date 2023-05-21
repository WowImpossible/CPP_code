#include "Test.h"

int Test::num_ = 10; //static修饰的数据成员，还需要在类体外进行定义行声明。要带类名，\
                       才知道是那个类里面的数据成员。定义性声明是可以进行初始化的。

Test::Test(int num):target(num)
{
	++num_;
	cout << "初始化" << endl;
}

Test::~Test()
{
	--num_;
	cout << "释放内存" << endl;
}

void Test::getnum()
{
	cout << num_ << endl;
}



