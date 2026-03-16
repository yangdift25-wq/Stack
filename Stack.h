#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

//栈的初始化与销毁
void STInit(ST* pst);
void STDestory(ST* pst);
//入栈   出栈
void STPush(ST* pst,STDataType x);
void STPop(ST* pst);
//去栈内数据
STDataType STTop(ST* pst);
//判空
bool STEmpty(ST* pst);
//栈内数据个数
int STSize(ST* pst);