/*
InitStack(), ����ռ�
b = a
�밴���������. . .
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
	//����һ����ջS
	SqStack *S = (SqStack *)malloc(sizeof(node)); // ָ��Ҳ��Ҫ�洢�ռ�
	S->base = (char *)malloc(STACK_INIT_SIZE * sizeof(char));
	printf("InitStack(), ����ռ�\n");
	if (!S->base) exit(OVERFLOW);//
	S->stacksize = STACK_INIT_SIZE;//�洢����ʧ��
	S->top = S->base;
	return S;
}//InitStack

int GetTop(SqStack S,char *e){
	//��ջ���գ�����e����S��ջ��Ԫ�أ�������1�����򷵻�0
	if (S.top == S.base) return 0;
	*e = *(S.top - 1);
	return 1;
}//GetTop

int Push(SqStack *S,char e) {
	//����Ԫ��eΪ�µ�ջ��Ԫ��
	if (S->top - S->base >= S->stacksize){//ջ����׷�Ӵ洢�ռ�
		S->base = (char *)realloc(S->base,S->stacksize+STACKINCREMENT*sizeof(char));
		if(!S->base) exit(OVERFLOW);//�洢����ʧ��
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return 1;
}//Push

int Pop(SqStack *S,char *e){
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
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