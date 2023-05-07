#define _CRT_SECURE_NO_WARNINGS 1

#include "Student.h"
#include <stdio.h>

int main(void)
{
	/*Student s;*/
	//s.stu_name("nihao");
	//s.stu_num("123456789");

	Student* s1 = new Student;

	s1->obj.querry_gra();

	delete s1;

	return 0;
}