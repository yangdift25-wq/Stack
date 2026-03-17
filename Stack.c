#define _CRT_SECURE_NO_WARNINGS 
#include"Stack.h"

//栈的初始化与销毁
void STInit(ST* pst)
{
	assert(pst);
	//可开可不开
	pst->a = NULL;
	pst->top = 0;//为了让top指向栈顶元素为-1,指向栈顶的下一个位置是0
	pst->capacity = 0;
}

void STDestory(ST* pst)
{
	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}

//入栈   出栈
void STPush(ST* pst,STDataType x)
{
	assert(pst);

	//如果空间不够就扩容
	if (pst->top == pst->capacity)
	{
		//判断特殊空间
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;

		//当第一个指针为空时realloc也可以起到malloc的作用
		STDataType* tmp = realloc(pst->a, sizeof(STDataType) * newcapacity);
		if (tmp==NULL)
		{
			perror("realloc fail");
			return;
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}
	//插入
	pst->a[pst->top] = x;
	pst->top++;
}
void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);
	pst->top--;
}

//取栈顶数据
STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);

	return pst->a[pst->top - 1];
}

//判空
bool STEmpty(ST* pst)
{
	assert(pst);
	//简化写法，等于0为真，反之为假
	return pst->top == 0;
}

//栈内数据个数
int STSize(ST* pst)
{
	assert(pst);

	return pst->top;
}





/*
* 实现栈的打印
while(!STEmpty(pst))
{
	printf("%d",STTop(pst));
	STPop(pst);
}

*/