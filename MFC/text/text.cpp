# include<stdio.h>
# include<stdlib.h>
typedef struct LNode
    {int data; 
      struct LNode *next;
    }LNode, *LinkList;

void build(LinkList &head) {
	LinkList pf, p;  
    head=(LinkList)malloc(sizeof(LNode)); 
	head->next=NULL;
	pf=head;
	int i;
	printf("please input the value of list(0 the end):");
	scanf("%d",&i);
   while(i!=0) 
   {  p=(LNode*)malloc(sizeof(LNode)); //为新结点开新空间
     p->data=i;      
     p->next=pf->next;    pf->next=p; //插入到表尾
     pf=p; //移动pf指针到下一位置
    printf("please input the value of list(0 the end):");
	scanf("%d",&i);
   }
}
void output (LinkList l){
	l=l->next;
	printf("链表的元素为：\n");
	while(l){
		printf("\t%d",l->data);
		l=l->next;
	}
	printf("\n");
}

int length(LinkList l){
	int length=0;
	while(l){
		l=l->next;
		length++;
	}
	return length;
}


LinkList arrange(LinkList L){
	LinkList pre_x=NULL;
	LinkList pre_y=NULL;
	LNode *temp=NULL;
	int i,j,t;
	t=length(L);
	for(pre_x=L,i=0;i<t;pre_x=pre_x->next)
		for(pre_y=L,j=0;j<t-i;pre_y=pre_y->next)
			if(pre_y->data>pre_y->data)
			{
			temp=pre_y->next;
			pre_y->next=pre_y->next->next;
			temp->next=pre_y->next->next;
			pre_y->next->next=temp;
			}
	
		
	
		return L;
}

void main(){
	LinkList  La;
	LinkList  Lb=NULL;
	build(La);
	output(La);
	Lb=arrange(La);
	output(Lb);
}

