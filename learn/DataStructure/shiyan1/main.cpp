#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//����ͷ�������ṹ
typedef struct HNode
	{
		char	roomN[7];	//�ͷ�����
		float   Price;		//��׼�۸�
		float   PriceL;	//��ס�۸�(Ĭ��ֵ=��׼�۸�*80%)
		int	   Beds;		//��λ��Beds
		char	   State[5];	//��ס״̬(ֵ��"����"��"��ס"��"Ԥ��"��Ĭ��ֵΪ"����"
		struct HNode  *next;	//ָ����
	}Hotel, *HLink;


void Build(HLink &H) //����ͷ����ơ���׼�۸񡢴�λ��������ס�۸���ס״̬�޸�ΪĬ��ֵ�����ļ��������������ݣ�
{
	FILE *file;
	file=fopen("Hotel.data","r");
	if(file==NULL)
	{
		printf("��������ʧ��\n");
		return;
	}
	HLink p=(HLink)malloc(sizeof(Hotel));
	HLink now=H;
	while(fscanf(file,"%s %f %d",p->roomN,&p->Price,&p->Beds)!=EOF)
	{
		strcpy(p->State,"����");
		p->PriceL=p->Price*0.8;
		now->next=p;
		now=now->next;
		p=(HLink)malloc(sizeof(Hotel));
	}
	now->next=NULL;
	free(p);
	printf("�ѳɹ���������\n");
}

void Exp(HLink &H)  //������пͷ��Ŀͷ����ơ���׼�۸���ס�۸񡢴�λ������ס״̬��
{
	HLink p=H->next;
	printf("  ������  ��׼�۸�  ��ס�۸�  ��λ��   ״̬\n");
	while(p)
	{
		printf("%8s %8.2f %8.2f %6d %8s\n\n",p->roomN,p->Price,p->PriceL,p->Beds,p->State);
	//	printf("%s%8.1f%8.1f%6d%8s\n",p->roomN,p->Price,p->PriceL,p->Beds,p->State);
		p=p->next;
	}
}

void updateH(HLink &H, int beds, char *state) //����λ��Ϊbeds�Ŀͷ���ס״̬��Ϊstate
{
	HLink p=H->next;
	while(p)
	{
		if(p->Beds==beds)
			strcpy(p->State,state);
		p=p->next;
	}
}

void Add(HLink &H) //����������δ��ס�Ŀͷ���ס�۸���Ӽ�20%��
{
	HLink p=H->next;
	while(p)
	{
		if(!strcmp(p->State,"����"))
			p->PriceL*=1.2;
		p=p->next;
	}
}

void upBed(HLink &H,int beds)  //��������λ��������beds�Ľ�㶼���ڴ�λ������beds�Ľ����棻
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

HLink FirstH(HLink &H) //������ס�۸���ߵĿͷ����ָ�룬����ǰ���ý����������ɾ��
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

void MoveK1(HLink &H, int k) //���������е�����k������Ƶ���һ�����λ��
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

void ReverseN2(HLink &H) //������������м�λ�ý��֮���ȫ����㵹�õĹ���
{
	HLink p=H;
	HLink mid=H;
	HLink k,t,g;
	while(p&&p->next)
	{
		mid=mid->next;
		p=p->next->next;
	}
	k=mid->next; //����k->t->g��˳���������
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
		mid->next=t;  //���м��Ǹ�ָ�����һ��
	}
}


void text() //������
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
	printf("ѡ���ܣ�\n");
		printf("1.������пͷ���Ϣ\n");
		printf("2.����λ��Ϊbeds�Ŀͷ���ס״̬��Ϊstate\n");
		printf("3.��δ��ס�Ŀͷ���ס�۸���Ӽ�20%\n");
		printf("4.����λ��������beds�Ŀͷ������ڴ�λ������beds�Ŀͷ�����\n");
		printf("5.�����ɾ����ס�۸���ߵĿͷ�\n");
		printf("6.���ͷ��е�����k���ͷ��Ƶ���һ���ͷ���λ��\n");
		printf("7.���ͷ������м�λ��֮���ȫ����㵹��\n");
		printf("0.�˳�����\n\n");
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
		case 2:printf("������beds&state:\n");
			scanf("%d%s",&tt,tmp);
			updateH(ss,tt,tmp);
			break;
		case 3:Add(ss);break;
		case 4:printf("�����봲λ��\n");
			scanf("%d",&tt);
			upBed(ss,tt);
			break;
		case 5:t=FirstH(ss);
			printf("  ������  ��׼�۸�  ��ס�۸�  ��λ��   ״̬\n");
			printf("%8s %8.2f %8.2f %6d %8s\n\n",t->roomN,t->Price,t->PriceL,t->Beds,t->State);
			break;
		case 6:printf("������k\n");
			scanf("%d",&tt);
			MoveK1(ss,tt);
			break;
		case 7:ReverseN2(ss);break;
		case 0:return 0;
		}
	}
	return 0;
	
}
