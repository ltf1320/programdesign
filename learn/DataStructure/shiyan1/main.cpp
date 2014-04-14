#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//定义客房链表结点结构
typedef struct HNode
	{
		char	roomN[7];	//客房名称
		float   Price;		//标准价格
		float   PriceL;	//入住价格(默认值=标准价格*80%)
		int	   Beds;		//床位数Beds
		char	   State[5];	//入住状态(值域："空闲"、"入住"、"预订"，默认值为"空闲"
		struct HNode  *next;	//指针域
	}Hotel, *HLink;


void Build(HLink &H) //输入客房名称、标准价格、床位数，将入住价格、入住状态修改为默认值，用文件操作来输入数据；
{
	FILE *file;
	file=fopen("Hotel.data","r");
	if(file==NULL)
	{
		printf("读入数据失败\n");
		return;
	}
	HLink p=(HLink)malloc(sizeof(Hotel));
	HLink now=H;
	while(fscanf(file,"%s %f %d",p->roomN,&p->Price,&p->Beds)!=EOF)
	{
		strcpy(p->State,"空闲");
		p->PriceL=p->Price*0.8;
		now->next=p;
		now=now->next;
		p=(HLink)malloc(sizeof(Hotel));
	}
	now->next=NULL;
	free(p);
	printf("已成功读入数据\n");
}

void Exp(HLink &H)  //输出所有客房的客房名称、标准价格、入住价格、床位数、入住状态；
{
	HLink p=H->next;
	printf("  房间名  标准价格  入住价格  床位数   状态\n");
	while(p)
	{
		printf("%8s %8.2f %8.2f %6d %8s\n\n",p->roomN,p->Price,p->PriceL,p->Beds,p->State);
	//	printf("%s%8.1f%8.1f%6d%8s\n",p->roomN,p->Price,p->PriceL,p->Beds,p->State);
		p=p->next;
	}
}

void updateH(HLink &H, int beds, char *state) //将床位数为beds的客房入住状态改为state
{
	HLink p=H->next;
	while(p)
	{
		if(p->Beds==beds)
			strcpy(p->State,state);
		p=p->next;
	}
}

void Add(HLink &H) //将该链表中未入住的客房入住价格均加价20%；
{
	HLink p=H->next;
	while(p)
	{
		if(!strcmp(p->State,"空闲"))
			p->PriceL*=1.2;
		p=p->next;
	}
}

void upBed(HLink &H,int beds)  //将该链表床位数不超过beds的结点都放在床位数超过beds的结点后面；
{
	HLink h1=(HLink)malloc(sizeof(Hotel)),h2=(HLink)malloc(sizeof(Hotel));
	HLink p1=h1,p2=h2;
	HLink p=H->next;
	while(p)
	{
		if(p->Beds<=beds)
		{
			p1->next=p;
			p1=p1->next;
		}
		else
		{
			p2->next=p;
			p2=p2->next;
		}
		p=p->next;
	}
	p1->next=NULL;
	p2->next=NULL;
	p=H;
	p1=h1->next;
	p2=h2->next;
	while(p1)
	{
		p->next=p1;
		p=p->next;
		p1=p1->next;
	}
	while(p2)
	{
		p->next=p2;
		p=p->next;
		p2=p2->next;
	}
	p->next=NULL;
}

HLink FirstH(HLink &H) //返回入住价格最高的客房结点指针，返回前将该结点在链表中删除
{
	HLink p=H;
	HLink Lres;
	HLink res;
	float maxp=0;
	while(p->next)
	{
		if(p->next->PriceL>maxp)
		{
			Lres=p;
			res=p->next;
			maxp=p->next->PriceL;
		}
		p=p->next;
	}
	Lres->next=Lres->next->next;
	return res;
}

void MoveK1(HLink &H, int k) //将单链表中倒数第k个结点移到第一个结点位置
{
	HLink p=H;
	HLink s=H;
	HLink t;
	int i=0;
	while(i<=k&&p)
	{
		p=p->next;
		i++;
	}
	if(i<=k)
		return;
	while(p)
	{
		p=p->next;
		s=s->next;
	}
	t=s->next;
	s->next=s->next->next;
	t->next=H->next;
	H->next=t;
}

void ReverseN2(HLink &H) //将单链表的正中间位置结点之后的全部结点倒置的功能
{
	HLink p=H;
	HLink mid=H;
	HLink k,t,g;
	while(p&&p->next)
	{
		mid=mid->next;
		p=p->next->next;
	}
	k=mid->next; //保持k->t->g的顺序，逆存链表
	t=k->next;
	if(t)
	{
		g=t->next;
		k->next=NULL;
		while(g)
		{
			t->next=k;
			k=t;
			t=g;
			g=t->next;
		}
		t->next=k;
		mid->next=t;  //把中间那个指向最后一个
	}
}


void text() //测试用
{
	HLink ss;
	HLink t;
	ss=(HLink)malloc(sizeof(Hotel));
	Build(ss);
//	Exp(ss);
//	MoveK1(ss,2);
//	ReverseN2(ss);
//	t=FirstH(ss);
//	printf("%s\n",t->roomN);
//	upBed(ss,9);
//	Add(ss);
//	updateH(ss,9,"in");
	Exp(ss);
}

void PrintChose()
{
	printf("选择功能：\n");
		printf("1.输出所有客房信息\n");
		printf("2.将床位数为beds的客房入住状态改为state\n");
		printf("3.将未入住的客房入住价格均加价20%\n");
		printf("4.将床位数不超过beds的客房都放在床位数超过beds的客房后面\n");
		printf("5.输出并删除入住价格最高的客房\n");
		printf("6.将客房中倒数第k个客房移到第一个客房的位置\n");
		printf("7.将客房的正中间位置之后的全部结点倒置\n");
		printf("0.退出程序\n\n");
}

int main()
{
//	text();
	HLink ss=(HLink)malloc(sizeof(Hotel));
	HLink t;
	char tmp[10];
	int tt;
	Build(ss);
	while(true)
	{
		PrintChose();
		scanf("%d",&tt);
		switch(tt)
		{
		case 1:Exp(ss);break;
		case 2:printf("请输入beds&state:\n");
			scanf("%d%s",&tt,tmp);
			updateH(ss,tt,tmp);
			break;
		case 3:Add(ss);break;
		case 4:printf("请输入床位数\n");
			scanf("%d",&tt);
			upBed(ss,tt);
			break;
		case 5:t=FirstH(ss);
			printf("  房间名  标准价格  入住价格  床位数   状态\n");
			printf("%8s %8.2f %8.2f %6d %8s\n\n",t->roomN,t->Price,t->PriceL,t->Beds,t->State);
			break;
		case 6:printf("请输入k\n");
			scanf("%d",&tt);
			MoveK1(ss,tt);
			break;
		case 7:ReverseN2(ss);break;
		case 0:return 0;
		}
	}
	return 0;
	
}
