#include <iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<map>
#include<vector>
using namespace std;
const int N=1000000;
int prime[801];//����1000���ڵ�����
int num;//1000���������ĸ���
int isprime[1000001];
int flag[1000001];//flag[i]��ʾi�Ƿ��뵱ǰm����
void getprime()//ɸ������
{
	for(int i=2;i<=1000000;i++)if(isprime[i]==0)
	{
		prime[num++]=i;
		for(int j=1;j*i<=1000000;j++)
		isprime[j*i]=1;
	}
}
int euler(int n)//���n��ŷ����������ɸ���������以�ʵ���flag[i]==0��ʾn��i������
{
	int nn=n;
	int res=n;
	for(int i=0;i<num&&prime[i]*prime[i]<=n;i++)
	{
		if(n%prime[i]==0)
		{
			res=res/prime[i]*(prime[i]-1);
			while(n%prime[i]==0)
			{
				n/=prime[i];
			}
			for(int j=prime[i];j<=nn;j=j+prime[i])//����prime[i]�ı����϶���n������
			{
				flag[j]=1;
			}
		}
	}
	if(n>1)
	{
		res=res/n*(n-1);
		for(int j=n;j<=nn;j+=n)
		{
			flag[j]=1;
		}
	}
	return res;
}
int solve(int key)
{
	int cnt=0;
	for(int i=1;i<=1000001;i++)
	{
		if(flag[i]==0)
		cnt++;
		if(cnt==key)
		return i;
	}
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int m,k;
	getprime();
	while(scanf("%d%d",&m,&k)!=EOF)
	{
		memset(flag,0,sizeof(flag));
		if(m==1)
		{printf("%d\n",k);continue;}
		int f=euler(m);
		int key=(k-1)%f+1;
		printf("%I64d\n",(__int64)((k-1)/(f)*m+solve(key)));

	}
}
