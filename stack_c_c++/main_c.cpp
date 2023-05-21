#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>

struct Link
{
	int data;//节点存入的数据
	struct Link* next;//下一个节点的地址
};

struct Stack
{
	struct Link* head;//栈的头的位置，指向的其实也是一个节点的地址，所以定义的是struct Stack*类型
	int size;//栈的大小设置
};


//栈的初始化
void StackInit(struct Stack* stack)
{
	stack->head = NULL;
	stack->size = 0;
}



//parameter:
//stack:要放数据到那个栈
//data:需要压入栈里面的数据
//注意点：需要自己创建一个节点，将需要压入栈里面的数据放到节点里面。
//        这就意味着需要手动分配空间，手动释放空间
//压栈操作：1、创建节点，把数据放起来（分配内存）
//          2、断言，查看分配的内存是否分配成功
//          3、将节点插入，栈大小改变一下。
void StackPush(struct Stack* stack, int data)
{
	//强制类型转化，因为malloc返回的是void*
	struct Link* node = (struct Link*)malloc(sizeof(struct Link));
	//查看空间是否分配成功,或者使用断言assert:assert(NULL != node),头文件<assert.h>，
	// 如果没有这个的话会出现警告c6011
	//if (NULL == node)
	//{
	//	printf("节点申请空间失败\n");
	//	exit(-1);
	//}
	assert(NULL != node);
	node->data = data;
	node->next = stack->head;
	stack->head = node;
	++stack->size;
}


//出栈：1、考虑栈里面是不是空的，如果是空的就不用弹出数据了
//      2、返回值：0表示无数据弹出，1表示弹出成功。
//      3、将弹出来的数据存起来。
//      4、弹出来数据之后，要记得将节点释放（free）
// 
//判断栈里面是否为空，返回值为0表示空，1表示非空
int StackEmpty(struct Stack* stack)
{
	return (stack->size != 0);
}

//出栈操作
int StackPop(struct Stack* stack, int* data_)
{
	//如果是空，返回0
	if (!StackEmpty(stack))
	{
		return 0;
	}
	//否则就弹出数据
	struct Link* temp = stack->head;//创建一个节点，保存要弹出节点，方便后面释放
	*data_ = temp->data;
	stack->head = stack->head->next;
	--stack->size;
	free(temp);
	return 1;
}

//将栈里面的内容全部清除
//要先给指针分配内存才可以使用指针，要不然指向谁。
void StackClearnup(struct Stack* stack)
{
	int data = 0;
	while (StackEmpty(stack))
	{
		StackPop(stack, &data);
	}
}


//struct Stack* stack要先给指针分配内存才可以使用stack里面的元素，要不然指向谁。记得手动释放free
int main()
{
	int data = 0;
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	//初始化
	StackInit(stack);
	//压栈操作
	StackPush(stack, 9);
	//看压栈是否成功，如果压栈成功，将其弹出，并将数字打印出来
	int test = StackPop(stack, &data);
	printf("%d\n", test);
	printf("%d\n", data);
	//压栈测试StackClearnup，通过看最后栈里面是否还有数据
	StackPush(stack, 10);
	StackPush(stack, 11);
	StackClearnup(stack);
	printf("%d\n", StackEmpty(stack));
	
	//释放stack空间。
	free(stack);
	return 0;
}