//易错数据
//1 5 5 1 2 3 4 5
//这个链表没有表头项

#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int s;
	Node *next;
}Node;

void del(Node *&p) //释放链表内存
{
	if(p==NULL) return;
	del(p->next);
	free(p);
	p=NULL;
}


void build(Node *&s) //通过输入构造链表
{
	int n,tmp;
	Node *p;
	del(s);
	printf("input the number of data:\n");
	scanf("%d",&n);
	printf("input the data:\n");
	n--;
	scanf("%d",&tmp);
	s=(Node*)malloc(sizeof(Node));
	s->s=tmp;
	p=s;
	while(n--)
	{
		scanf("%d",&tmp);
		p->next=(Node*)malloc(sizeof(Node));
		p=p->next;
		p->s=tmp;
	}
	p->next=NULL;
}

void sort(Node *&a)  //对链表进行排序（从小到大，冒泡）
{
	Node *p=a,*end,*t;
	
	for(end=NULL;a->next!=end;end=p->next)
	{
		if(a->next->s<a->s)
		{
			t=a->next;
			a->next=a->next->next;
			t->next=a;
			a=t;
		}
		for(p=a;p->next->next!=end;p=p->next)
		{
			if(p->next->next->s<p->next->s)
			{
				t=p->next;
				p->next=p->next->next;
				t->next=p->next->next;
				p->next->next=t;
			}
		}
	}
}

void combine(Node *&a,Node *b) //并集
{
	Node *q,*t1;
	int flag;  //标记是否找到相同的
	q=a;
	if(a->s>b->s)  //如果b最小的数比a最小的小，改变a的表头
	{
		t1=a;
		a=(Node*)malloc(sizeof(Node));
		a->s=b->s;
		a->next=t1;
		b=b->next;
	}
	while(a->s==b->s)
		b=b->next; //如果b最小的数等于a最小的数，跳过b所有最小的数
	for(;b!=NULL;b=b->next)
	{
		flag=0;
		for(q=a;q->next!=NULL&&q->next->s<=b->s;q=q->next)
			if(q->next->s==b->s)
			{
				flag=1;
				break;
			}
		if(!flag) //如果没有找到相同的，便插入节点（最好不要直接指向lb中的节点，不然会导致la,lb交叉，不好维护（调了挺久））
		{
			t1=q->next;	
			q->next=(Node*)malloc(sizeof(Node));
			q->next->next=t1;
			q->next->s=b->s;
		}
	}
}

void merge(Node *a,Node *b,Node *&c) //归并
{
	Node *p;
	del(c);
	c=(Node*)malloc(sizeof(Node)); //创建一个新的含有第一项的链表
	if(a->s<=b->s)
	{
		c->s=a->s;
		a=a->next;
	}
	else 
	{
		c->s=b->s;
		b=b->next;
	}
	p=c;
	while(a!=NULL&&b!=NULL)   //归并
	{
		p->next=(Node*)malloc(sizeof(Node));
		p=p->next;
		if(a->s<=b->s)
		{
			p->s=a->s;
			a=a->next;
		}
		else 
		{
			p->s=b->s;
			b=b->next;
		}
	}
	//将剩下的插入链表
	while(a!=NULL)
	{
		p->next=(Node*)malloc(sizeof(Node));
		p=p->next;
		p->s=a->s;
		a=a->next;
	}
	while(b!=NULL)
	{
		p->next=(Node*)malloc(sizeof(Node));
		p=p->next;
		p->s=b->s;
		b=b->next;
	}
	p->next=NULL;
}


			

void print(Node* p) //输出链表
{
	while(p!=NULL)
	{
		printf("%d ",p->s);
		p=p->next;
	}
	putchar('\n');
}


void doCombine()
{
	Node *la=NULL,*lb=NULL;
	printf("input la:\n");build(la);sort(la);
	printf("input lb:\n");build(lb);sort(lb);
	combine(la,lb);
	printf("combined la and lb is:\n");
	print(la);
	del(la);
	del(lb);
}

void doMerge()
{
	Node *la=NULL,*lb=NULL,*lc=NULL;
	printf("input la:\n");build(la);sort(la);
	printf("input lb:\n");build(lb);sort(lb);
	merge(la,lb,lc);
	printf("merge la & lb into lc is\n");
	print(lc);
	del(la);
	del(lb);
	del(lc);
}


void doSort()
{
	Node *la=NULL;
	printf("input la:\n");build(la);sort(la);
	print(la);
}

int main()
{
	int n=1;
	while(n)
	{
		printf("please chose the function:\n1 for sort 2 for combine , 3 for merge , 4 for cls ,0 for exit\n");
		scanf("%d",&n);
		switch(n)
		{
		case 1:
			doSort();break;
		case 2:
			doCombine();break;
		case 3:
			doMerge();break;
		case 4:
			system("cls");break;
		}
		putchar('\n');
	}

	return 0;
}
