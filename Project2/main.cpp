#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <iostream>

using namespace std;

//this uses for c
// 
// 
//class Student {
//
//public:
//	void stu_name(const char* s);
//	void stu_num(const char* s);
//private:
//	const char* name;
//	const char* num;
//};
//
//void Student::stu_name(const char* s)
//{
//	//scanf("%s", &name);
//	name = s;
//	printf("%s\n", name);
//}
//
//void Student::stu_num(const char* s)
//{
//	//scanf("%s", &num);
//	num = s;
//	printf("%s\n", num);
//}
//
//int main(void)
//{
//	Student s;
//	s.stu_name("wangli");
//	s.stu_num("12345678");
//
//	return 0;
//}

//c pluse pluse

class Student {

public:
	void stu_name(const char* s);
	void stu_num(const char* s);
	Student();
private:
	const char* name;
	const char* num;
};

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
	cout << name << endl;
	cout << num << endl;
}

int main(void)
{
	Student s;
	char arrna[] = "xiaozhan";
	char arrnu[] = "12345";
	s.stu_name(arrna);
	s.stu_num(arrnu);

	return 0;
}