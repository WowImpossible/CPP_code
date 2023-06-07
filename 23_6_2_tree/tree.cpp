#define _CRT_SECURE_NO_WARNINGS 1


//����������
//��ַ��https://www.bilibili.com/video/BV15a4y1a7B5/?spm_id_from=333.880.my_history.page.click&vd_source=a3c8b00882a32721899e2fc37fd53bcf
#include <stdio.h>
#include <stdlib.h>

//�ڵ�Ĺ��ɣ�LChild��ڵ㣬RChild�ҽڵ�
struct TreeNode
{
	char test;
	struct TreeNode* LChild;
	struct TreeNode* RChild;
};

//���ӽڵ�
struct TreeNode* AddNode(char test)
{
	struct TreeNode* node = (TreeNode*)malloc(sizeof(struct TreeNode));
	if (node == NULL)
	{
		printf("����ռ����\n");
		exit(-1);
	}
	node->test = test;
	node->LChild = NULL;
	node->RChild = NULL;
	return node;
}

//���ڵ㽨����ϵ���������Ĺ�ϵ
void CreatTree(struct TreeNode* ParentNode, struct TreeNode* LChildNode, struct TreeNode* RChildNode)
{
	ParentNode->LChild = LChildNode;
	ParentNode->RChild = RChildNode;
}

//void���޷���ֵ�ġ�����return��ʱ���ܴ�����
//ʹ��ջ�ķ�ʽ������������ǰ�򣺸�  ��  �ҵ�˳��
void PreOrderByStack(struct TreeNode* Root)
{
	if (Root == NULL)
		return ;
	//ָ�����飬stack���ڴ��ָ��
	struct TreeNode* stack[10];
	int stackTop = -1;

	struct TreeNode* pMove = Root;
	while (stackTop != -1 || pMove)
	{
		while (pMove)
		{
			printf("%c\t", pMove->test);
			stack[++stackTop] = pMove;
			pMove = pMove->LChild;
		}
		if (stackTop != -1)
		{
			pMove = stack[stackTop];
 			stackTop--;
			pMove = pMove->RChild;
		}
	}
}

//ʹ��ջ�ķ�ʽ������������������  ��  �ҵ�˳��
void MidOrderByStack(struct TreeNode* Root)
{
	if (Root == NULL)
		return;
	//ָ�����飬stack���ڴ��ָ��
	struct TreeNode* stack[10];
	int stackTop = -1;

	struct TreeNode* pMove = Root;
	while (stackTop != -1 || pMove)
	{
		while (pMove)
		{
			stack[++stackTop] = pMove;
			pMove = pMove->LChild;
		}
		if (stackTop != -1)
		{
			pMove = stack[stackTop];
			printf("%c\t", pMove->test);
			stackTop--;
			pMove = pMove->RChild;
		}
	}
}

//ʹ��ջ�ķ�ʽ������������������  ��  ����˳��
void LastOrderByStack(struct TreeNode* Root)
{
	if (Root == NULL)
		return;
	//ָ�����飬stack���ڴ��ָ��
	struct TreeNode* stack[10];
	int stackTop = -1;

	struct TreeNode* pMove = Root;
	//����ұ��Ѿ����������Ľڵ㣬��ʱ����ֱ�Ӵ�ӡ��
	struct TreeNode* flag_point = NULL;
	//�ҵ�����ߵ�Ϊ�յ���
	while (pMove)
	{
		stack[++stackTop] = pMove;
		pMove = pMove->LChild;
	}
	while (stackTop != -1)
	{
		pMove = stack[stackTop--];
		if (pMove->RChild == NULL || pMove->RChild == flag_point)
		{
			printf("%c\t", pMove->test);
			flag_point = pMove;
		}
		else
		{
			//�ٰ�û�д�ӡ�Ľڵ�ѹ��ջ����ȥ
			stack[++stackTop] = pMove;
			pMove = pMove->RChild;
			//���ұ�������ߵ�Ҷ�ӽڵ�
			while (pMove)
			{
				stack[++stackTop] = pMove;
				pMove = pMove->LChild;
			}
		}
	}
}

//ʹ�õݹ�ķ������ʶ������ĸ���Ԫ��

//��ӡ��ǰ�ڵ������
void printCurDataPreOrder(struct TreeNode* Cur)
{
	printf("%c\t", Cur->test);
}
//ǰ��
void preOrder(struct TreeNode* Root)
{
	if (Root == NULL)
		return;
	printCurDataPreOrder(Root);
	preOrder(Root->LChild);
	preOrder(Root->RChild);
}

//����
void midOrder(struct TreeNode* Root)
{
	if (Root == NULL)
		return;
	midOrder(Root->LChild);
	printCurDataPreOrder(Root);
	midOrder(Root->RChild);
}

//����
void lastOrder(struct TreeNode* Root)
{
	if (Root == NULL)
		return;
	lastOrder(Root->LChild);
	lastOrder(Root->RChild);
	printCurDataPreOrder(Root);
}



int main(void)
{
	struct TreeNode* A = AddNode('A');
	struct TreeNode* B = AddNode('B');
	struct TreeNode* C = AddNode('C');
	struct TreeNode* D = AddNode('D');
	struct TreeNode* E = AddNode('E');
	struct TreeNode* F = AddNode('F');
	struct TreeNode* G = AddNode('G');

	CreatTree(A, B, C);
	CreatTree(B, D,NULL);
	CreatTree(D, NULL,G);
	CreatTree(C, E, F);
	
	printf("PreOrderByStack:");
	printf("\n");
	PreOrderByStack(A);
	printf("\n");
	preOrder(A);
	printf("\n");

	printf("MidOrderByStack:");
	printf("\n");
	MidOrderByStack(A);
	printf("\n");
	midOrder(A);
	printf("\n");

	printf("LastOrderByStack:");
	printf("\n");
	LastOrderByStack(A);
	printf("\n");
	lastOrder(A);
	printf("\n");

	return 0;
}

