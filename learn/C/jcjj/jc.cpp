#include<stdio.h>
#include<math.h>
void main()
{
	int n,a,sum=0,t,i,tn=0,s,q;
	printf("������λ����");
	scanf("%d",&n);
	scanf("%d",&a);
	for(i=0;i<=n;i++)
	{
		t=pow(10,i);
		q=a*t;
     	tn=tn+q;
		sum=sum+tn;
	}
		printf("%d",sum);
}