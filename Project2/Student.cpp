#include "Student.h"
#include <iostream>

using namespace std;


void Student::stu_name(const char* s)
{
	//scanf("%s", &name);
	name = s;
	/*printf("%s\n", name);*/
	cout << name << endl;
}

void Student::stu_num(const char* s)
{
	//scanf("%s", &num);
	num = s;
	/*printf("%s\n", num);*/
	cout << num << endl;
}

Student::Student()
{
	name = "wangli";
	num = "1234567";
	test = 0;

	cout << name << endl;
	cout << num << endl;
}

Student::grade::grade()
{
	math = 80;
	chinese = 90;
	english = 100;
}

Student::~Student()
{
	cout << "delete " << name << endl;
	cout << "delete " << num << endl;
}

int Student::grade::querry_gra()
{
	cout << chinese << endl;
	cout << math << endl;
	cout << english << endl;
	//cout << test << endl;  //Error , 嵌套类是不可以访问外围类的。
	return 0;
}

