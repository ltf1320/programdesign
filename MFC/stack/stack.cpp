/*
InitStack(), 申请空间
b = a
请按任意键继续. . .
*/
#include <stdafx.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OVERFLOW -1

typedef struct node {
	char *base;
	char *top;
	int stacksize;
}SqStack;

SqStack *InitStack(){
	//构造一个空栈S
	SqStack *S = (SqStack *)malloc(sizeof(node)); // 指针也需要存储空间
	S->base = (char *)malloc(STACK_INIT_SIZE * sizeof(char));
	printf("InitStack(), 申请空间\n");
	if (!S->base) exit(OVERFLOW);//
	S->stacksize = STACK_INIT_SIZE;//存储分配失败
	S->top = S->base;
	return S;
}//InitStack

int GetTop(SqStack S,char *e){
	//若栈不空，则用e返回S的栈顶元素，并返回1，否则返回0
	if (S.top == S.base) return 0;
	*e = *(S.top - 1);
	return 1;
}//GetTop

int Push(SqStack *S,char e) {
	//插入元素e为新的栈顶元素
	if (S->top - S->base >= S->stacksize){//栈满，追加存储空间
		S->base = (char *)realloc(S->base,S->stacksize+STACKINCREMENT*sizeof(char));
		if(!S->base) exit(OVERFLOW);//存储分配失败
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return 1;
}//Push

int Pop(SqStack *S,char *e){
	//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR
	if (S->top == S->base) return 0;
	*e = *--S->top;
	return 1;
}//Pop

int main(){	
	char c,b;
	SqStack *S = InitStack();
	Push(S,'a');
	Pop(S,&b);
	printf("b = %c\n",b);
	return 0;
} 