#define _CRT_SECURE_NO_WARNINGS 1


#include <assert.h>
#include <iostream>
using namespace std;


class Stack {
	//struct Ҳ��һ��������࣬��Ҳ�ǿ����й��캯����(c++�����struct�ؼ��ֿ��Բ�д)
	//��ʹ��Ƕ�����ԭ����Ϊʹ��structĬ����public�ģ�Ƕ����Ĭ����private��
	struct Link
	{
		int data_;
		Link* next_;
	public:
		Link(int data, Link* next):data_(data),next_(next)
		{}
	};
public:
	//ջ�ĳ�ʼ��
	Stack(Link* head,int size):head_(head),size_(size)
	{}
	//���������������ͷ�ջ�����Ԫ��
	~Stack()
	{
		while (0 != head_)
		{
			int data;
			Pop(&data);
		}
		/*size_ = 0;*///�Ӳ���ûʲô�¶�����Ϊһ�����������ͻ��Զ��ͷ�
		cout << "�Ѿ�ȫ���ͷ�ջ�ڵĽڵ㣬ջ�Ĵ�СΪ" << size_ << endl;
	}
	//ѹջ����
	void Push(int data)
	{
		Link* node = new Link(data,head_);
		//���ԣ�ȷ���ڵ��������䵽���ڴ档
		assert(NULL != node);
		head_ = node;
		size_++;
		cout << "�ѽ�" << node->data_ << "ѹ��ջ��" << endl;
	}

	//�ж�ջ�Ƿ�Ϊ�գ�����true�Ļ���ʾ�ǿգ�false��ʾ��
	bool Empty()
	{
		return (size_ != 0);
	}

	//��ջ����
	bool Pop(int* data)
	{
		if (!Empty())
		{
			return false;
		}
		struct Link* temp = head_;
		*data = head_->data_;
		head_ = head_->next_;
		cout << "�ѽ�" << temp->data_ << "�Ƴ�ջ��" << endl;
		delete temp;
		--size_;
		cout << "ջ�л���" << size_ << "���ڵ�" << endl;
		return true;
	}

private:
	Link* head_;
	int size_;

};


int main(void)
{
	int data = 0;
	//�ֶ�������ڴ棬��Ҫ�ֶ��ͷţ�ֻ������delete�Ż��Զ�ʹ����������������
	Stack* stack = new Stack(0,0);
	for (int i = 0; i < 5; i++)
	{
		stack->Push(i);
	}

	for (int j = 0; j < 2; j++)
	{
		stack->Pop(&data);
	}

	delete stack;

	return 0;
}

