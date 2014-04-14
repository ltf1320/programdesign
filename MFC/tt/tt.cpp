# include<stdio.h>
# include<stdlib.h>
# define LIST_INIT_SIZE  100
# define LISTINCREMENT   10
typedef struct
{
    int *elem;
    int  length;
    int listsize;
} SqList;

SqList build(SqList L,int n) //构造一个线性表L
{
    L.elem=(int*)malloc(LIST_INIT_SIZE*sizeof(int));
    if(!L.elem)exit(0);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    printf("请输入线性表的%d个元素：\n",n);
    while(L.length<n)
    {
        scanf("%d",&L.elem[L.length]);
        L.length++;
    }
    return L;
}
void GetElem(SqList L,int i,int *&e) //返回线性表中第i个元素
{
    int n=0;
    while(n<i-1) n++;
    * e=L.elem[n];
}

int LocateElem(SqList L,int e) // 返回线性表中第一个与e相等的元素的位序
{
    int i=1;
    int *p;
    p=L.elem;
    while(i<=L.length&&!(*(p++)==e)) ++i;
    if(i<=L.length) return i;
    else return 0;
}

int  ListInsert(SqList &L,int i,int e) //在线性表的第i个位置插入新元素
{
    int* newbase;
    if(i<1||i>L.length+1) return 0;
    if(L.length>=L.listsize)
    {
        newbase = (int*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(int));
        if(!newbase)exit(0);
        L.elem=newbase;
        L.listsize+=LISTINCREMENT;
    }
    int *q;
    int *p;
    q=&(L.elem[i-1]);
    for (p=&(L.elem[L.length-1]); p>=q; --p) *(p+1)=*p;
    *q=e;
    ++L.length;	
    return 1;
}

void output(SqList l)
{
    int i=0;
    printf("\n线性表的元素如下：\n");
    printf("-------------------------\n");
    while(i<l.length)
    {

        printf("%d\t",l.elem[i]);
        i++;
    }
}

void unite(SqList La,SqList Lb)
{
    int i;
    int* e=(int*)malloc(sizeof(int));
    for(i=1; i<=Lb.length; i++)
    {
        GetElem(Lb,i,e);
        if(!LocateElem(La,*e)) ListInsert(La,La.length+1,*e);
    }
    output(La);
}
void MergeList(SqList La,SqList Lb,SqList Lc)
{
    int i,j,k;
    i=j=1;
    k=0;
    int *p=(int*)malloc(sizeof(int)),*q=(int*)malloc(sizeof(int));
	Lc.elem=(int*)malloc(LISTINCREMENT*sizeof(int));
	Lc.length=0;
	Lc.listsize=LISTINCREMENT;
    while((i<=La.length)&&(j<=Lb.length))
    {
        GetElem(La,i,p);
        GetElem(Lb,j,q);
        if(*p<*q)
        {
            ListInsert(Lc,++k,*p);
            ++i;
        }
        else
        {
            ListInsert(Lc,++k,*q);
            ++j;
        }
    }
    while(i<=La.length)
    {
        GetElem(La,i++,p);
        ListInsert(Lc,++k,*p);
    }
    while(j<=Lb.length)
    {
        GetElem(Lb,j++,q);
        ListInsert(Lc,++k,*q);
    }
    output(Lc);
}

int main()
{
    SqList la,lb,lc;
    la=build(la,4);
    lb=build(lb,7);
    output(la);
    output(lb);
	unite(la,lb);
	MergeList(la,lb,lc);

}


