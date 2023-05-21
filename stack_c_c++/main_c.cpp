#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>

struct Link
{
	int data;//�ڵ���������
	struct Link* next;//��һ���ڵ�ĵ�ַ
};

struct Stack
{
	struct Link* head;//ջ��ͷ��λ�ã�ָ�����ʵҲ��һ���ڵ�ĵ�ַ�����Զ������struct Stack*����
	int size;//ջ�Ĵ�С����
};


//ջ�ĳ�ʼ��
void StackInit(struct Stack* stack)
{
	stack->head = NULL;
	stack->size = 0;
}



//parameter:
//stack:Ҫ�����ݵ��Ǹ�ջ
//data:��Ҫѹ��ջ���������
//ע��㣺��Ҫ�Լ�����һ���ڵ㣬����Ҫѹ��ջ��������ݷŵ��ڵ����档
//        �����ζ����Ҫ�ֶ�����ռ䣬�ֶ��ͷſռ�
//ѹջ������1�������ڵ㣬�����ݷ������������ڴ棩
//          2�����ԣ��鿴������ڴ��Ƿ����ɹ�
//          3�����ڵ���룬ջ��С�ı�һ�¡�
void StackPush(struct Stack* stack, int data)
{
	//ǿ������ת������Ϊmalloc���ص���void*
	struct Link* node = (struct Link*)malloc(sizeof(struct Link));
	//�鿴�ռ��Ƿ����ɹ�,����ʹ�ö���assert:assert(NULL != node),ͷ�ļ�<assert.h>��
	// ���û������Ļ�����־���c6011
	//if (NULL == node)
	//{
	//	printf("�ڵ�����ռ�ʧ��\n");
	//	exit(-1);
	//}
	assert(NULL != node);
	node->data = data;
	node->next = stack->head;
	stack->head = node;
	++stack->size;
}


//��ջ��1������ջ�����ǲ��ǿյģ�����ǿյľͲ��õ���������
//      2������ֵ��0��ʾ�����ݵ�����1��ʾ�����ɹ���
//      3���������������ݴ�������
//      4������������֮��Ҫ�ǵý��ڵ��ͷţ�free��
// 
//�ж�ջ�����Ƿ�Ϊ�գ�����ֵΪ0��ʾ�գ�1��ʾ�ǿ�
int StackEmpty(struct Stack* stack)
{
	return (stack->size != 0);
}

//��ջ����
int StackPop(struct Stack* stack, int* data_)
{
	//����ǿգ�����0
	if (!StackEmpty(stack))
	{
		return 0;
	}
	//����͵�������
	struct Link* temp = stack->head;//����һ���ڵ㣬����Ҫ�����ڵ㣬��������ͷ�
	*data_ = temp->data;
	stack->head = stack->head->next;
	--stack->size;
	free(temp);
	return 1;
}

//��ջ���������ȫ�����
//Ҫ�ȸ�ָ������ڴ�ſ���ʹ��ָ�룬Ҫ��Ȼָ��˭��
void StackClearnup(struct Stack* stack)
{
	int data = 0;
	while (StackEmpty(stack))
	{
		StackPop(stack, &data);
	}
}


//struct Stack* stackҪ�ȸ�ָ������ڴ�ſ���ʹ��stack�����Ԫ�أ�Ҫ��Ȼָ��˭���ǵ��ֶ��ͷ�free
int main()
{
	int data = 0;
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	//��ʼ��
	StackInit(stack);
	//ѹջ����
	StackPush(stack, 9);
	//��ѹջ�Ƿ�ɹ������ѹջ�ɹ������䵯�����������ִ�ӡ����
	int test = StackPop(stack, &data);
	printf("%d\n", test);
	printf("%d\n", data);
	//ѹջ����StackClearnup��ͨ�������ջ�����Ƿ�������
	StackPush(stack, 10);
	StackPush(stack, 11);
	StackClearnup(stack);
	printf("%d\n", StackEmpty(stack));
	
	//�ͷ�stack�ռ䡣
	free(stack);
	return 0;
}