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

	grade obj;  //������ʲô�࣬����Ҫ���ľ�����ʵ��������
	int test;
	void stu_name(const char* s);
	void stu_num(const char* s);
	Student();
	~Student();


private:
	const char* name;
	const char* num;
};

#endif