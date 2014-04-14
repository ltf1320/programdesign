//�״�����
//1 5 5 1 2 3 4 5
//�������û�б�ͷ��

#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int s;
	Node *next;
}Node;

void del(Node *&p) //�ͷ������ڴ�
{
	if(p==NULL) return;
	del(p->next);
	free(p);
	p=NULL;
}


void build(Node *&s) //ͨ�����빹������
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

void sort(Node *&a)  //������������򣨴�С����ð�ݣ�
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

void combine(Node *&a,Node *b) //����
{
	Node *q,*t1;
	int flag;  //����Ƿ��ҵ���ͬ��
	q=a;
	if(a->s>b->s)  //���b��С������a��С��С���ı�a�ı�ͷ
	{
		t1=a;
		a=(Node*)malloc(sizeof(Node));
		a->s=b->s;
		a->next=t1;
		b=b->next;
	}
	while(a->s==b->s)
		b=b->next; //���b��С��������a��С����������b������С����
	for(;b!=NULL;b=b->next)
	{
		flag=0;
		for(q=a;q->next!=NULL&&q->next->s<=b->s;q=q->next)
			if(q->next->s==b->s)
			{
				flag=1;
				break;
			}
		if(!flag) //���û���ҵ���ͬ�ģ������ڵ㣨��ò�Ҫֱ��ָ��lb�еĽڵ㣬��Ȼ�ᵼ��la,lb���棬����ά��������ͦ�ã���
		{
			t1=q->next;	
			q->next=(Node*)malloc(sizeof(Node));
			q->next->next=t1;
			q->next->s=b->s;
		}
	}
}

void merge(Node *a,Node *b,Node *&c) //�鲢
{
	Node *p;
	del(c);
	c=(Node*)malloc(sizeof(Node)); //����һ���µĺ��е�һ�������
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
	while(a!=NULL&&b!=NULL)   //�鲢
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
	//��ʣ�µĲ�������
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


			

void print(Node* p) //�������
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
