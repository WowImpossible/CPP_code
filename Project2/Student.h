#ifndef STUDENT_H__
#define STUDENT_H__

class Student
{
	
	class grade
	{
	public:
		grade();
		int querry_gra();
	private:
		int math;
		int chinese;
		int english;
	};
public:

	grade obj;  //不管是什么类，首先要做的就是先实例化对象
	
	void stu_name(const char* s);
	void stu_num(const char* s);
	Student();
	~Student();
	int test;


private:
	const char* name;
	const char* num;
};

#endif