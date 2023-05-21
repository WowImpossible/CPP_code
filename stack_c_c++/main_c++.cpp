#define _CRT_SECURE_NO_WARNINGS 1


#include <assert.h>
#include <iostream>
using namespace std;


class Stack {
	//struct 也是一个特殊的类，它也是可以有构造函数的(c++里面的struct关键字可以不写)
	//不使用嵌套类的原因：因为使用struct默认是public的，嵌套类默认是private的
	struct Link
	{
		int data_;
		Link* next_;
	public:
		Link(int data, Link* next):data_(data),next_(next)
		{}
	};
public:
	//栈的初始化
	Stack(Link* head,int size):head_(head),size_(size)
	{}
	//析构函数，用于释放栈里面的元素
	~Stack()
	{
		while (0 != head_)
		{
			int data;
			Pop(&data);
		}
		/*size_ = 0;*///加不加没什么事儿，因为一般程序结束，就会自动释放
		cout << "已经全部释放栈内的节点，栈的大小为" << size_ << endl;
	}
	//压栈操作
	void Push(int data)
	{
		Link* node = new Link(data,head_);
		//断言，确保节点正常分配到了内存。
		assert(NULL != node);
		head_ = node;
		size_++;
		cout << "已将" << node->data_ << "压入栈中" << endl;
	}

	//判断栈是否为空，返回true的话表示非空，false表示空
	bool Empty()
	{
		return (size_ != 0);
	}

	//出栈操作
	bool Pop(int* data)
	{
		if (!Empty())
		{
			return false;
		}
		struct Link* temp = head_;
		*data = head_->data_;
		head_ = head_->next_;
		cout << "已将" << temp->data_ << "移除栈中" << endl;
		delete temp;
		--size_;
		cout << "栈中还有" << size_ << "个节点" << endl;
		return true;
	}

private:
	Link* head_;
	int size_;

};


int main(void)
{
	int data = 0;
	//手动分配的内存，需要手动释放，只有用了delete才会自动使用析构函数！！！
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

