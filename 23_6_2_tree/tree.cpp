#define _CRT_SECURE_NO_WARNINGS 1


//二叉树遍历
//网址：https://www.bilibili.com/video/BV15a4y1a7B5/?spm_id_from=333.880.my_history.page.click&vd_source=a3c8b00882a32721899e2fc37fd53bcf
#include <stdio.h>
#include <stdlib.h>

//节点的构成，LChild左节点，RChild右节点
struct TreeNode
{
	char test;
	struct TreeNode* LChild;
	struct TreeNode* RChild;
};

//增加节点
struct TreeNode* AddNode(char test)
{
	struct TreeNode* node = (TreeNode*)malloc(sizeof(struct TreeNode));
	if (node == NULL)
	{
		printf("分配空间出错\n");
		exit(-1);
	}
	node->test = test;
	node->LChild = NULL;
	node->RChild = NULL;
	return node;
}

//将节点建立联系，二叉树的关系
void CreatTree(struct TreeNode* ParentNode, struct TreeNode* LChildNode, struct TreeNode* RChildNode)
{
	ParentNode->LChild = LChildNode;
	ParentNode->RChild = RChildNode;
}

//void是无返回值的。所以return的时候不能带参数
//使用栈的方式遍历二叉树，前序：根  左  右的顺序
void PreOrderByStack(struct TreeNode* Root)
{
	if (Root == NULL)
		return ;
	//指针数组，stack用于存放指针
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

//使用栈的方式遍历二叉树，中序：左  根  右的顺序
void MidOrderByStack(struct TreeNode* Root)
{
	if (Root == NULL)
		return;
	//指针数组，stack用于存放指针
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

//使用栈的方式遍历二叉树，后序：左  右  根的顺序
void LastOrderByStack(struct TreeNode* Root)
{
	if (Root == NULL)
		return;
	//指针数组，stack用于存放指针
	struct TreeNode* stack[10];
	int stackTop = -1;

	struct TreeNode* pMove = Root;
	//标记右边已经被遍历过的节点，此时可以直接打印。
	struct TreeNode* flag_point = NULL;
	//找到最左边的为空的数
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
			//再把没有打印的节点压进栈里面去
			stack[++stackTop] = pMove;
			pMove = pMove->RChild;
			//找右边最最左边的叶子节点
			while (pMove)
			{
				stack[++stackTop] = pMove;
				pMove = pMove->LChild;
			}
		}
	}
}

//使用递归的方法访问二叉树的各个元素

//打印当前节点的数据
void printCurDataPreOrder(struct TreeNode* Cur)
{
	printf("%c\t", Cur->test);
}
//前序
void preOrder(struct TreeNode* Root)
{
	if (Root == NULL)
		return;
	printCurDataPreOrder(Root);
	preOrder(Root->LChild);
	preOrder(Root->RChild);
}

//中序
void midOrder(struct TreeNode* Root)
{
	if (Root == NULL)
		return;
	midOrder(Root->LChild);
	printCurDataPreOrder(Root);
	midOrder(Root->RChild);
}

//后序
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

