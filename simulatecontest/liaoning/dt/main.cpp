#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OVERFLOW -1
typedef struct {
	char *base;
	char *top;
	int stacksize;
}SqStack;

void InitStack(SqStack *S){
	//ｹｹﾔ・ｻｸﾕﾕｻS
	S->base=(char *)malloc(STACK_INIT_SIZE * sizeof(char));
	if (!S->base) exit(OVERFLOW);//
	S->stacksize=STACK_INIT_SIZE;//ｴ豢｢ｷﾖﾅ萍ｧｰﾜ
	S->top=S->base;
}//InitStack

int GetTop(SqStack S,char e){
	//ﾈｻｲｻｿﾕ｣ｬﾔﾃeｷｵｻﾘSｵﾄﾕｻｶ･ﾔｪﾋﾘ｣ｬｲ｢ｷｵｻﾘ1｣ｬｷｵｻﾘ0
	if (S.top==S.base) return 0;
	e=*(S.top-1);
	return 1;
}//GetTop

int Push(SqStack *S,char e){
	//ｲ衒・ｪﾋﾘeﾎｪﾐﾂｵﾄﾕｻｶ･ﾔｪﾋﾘ
	if (S->top-S->base>=S->stacksize){//ﾕｻﾂ奣ｬﾗｷｼﾓｴ豢｢ｿﾕｼ・
		S->base=(char *) realloc(S->base,S->stacksize+STACKINCREMENT*sizeof(char));
		if (!S->base) exit(OVERFLOW);//ｴ豢｢ｷﾖﾅ萍ｧｰﾜ
		S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;
	}
	*S->top++ = e;
	return 1;
}//Push

int Pop(SqStack *S,char e){
	//ﾈｻｲｻｿﾕ｣ｬﾔｾｳSｵﾄﾕｻｶ･ﾔｪﾋﾘ｣ｬﾓﾃeｷｵｻﾘﾆ葷ｵ｣ｬｲ｢ｷｵｻﾘOK｣ｬｷｵｻﾘERROR
	if (S->top==S->base) return 0;
	e=*--S->top;
	return 1;
}//Pop

int main(){
	char c;
	SqStack *S;
	InitStack(S);
	Push(S,'a');
	Pop(S,c);
	printf("%c",c);
}

