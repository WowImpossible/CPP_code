#include "Test.h"

int Test::num_ = 10; //static���ε����ݳ�Ա������Ҫ����������ж�����������Ҫ��������\
                       ��֪�����Ǹ�����������ݳ�Ա�������������ǿ��Խ��г�ʼ���ġ�

Test::Test(int num):target(num)
{
	++num_;
	cout << "��ʼ��" << endl;
}

Test::~Test()
{
	--num_;
	cout << "�ͷ��ڴ�" << endl;
}

void Test::getnum()
{
	cout << num_ << endl;
}



