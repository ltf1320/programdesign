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
int prime[801];//保存1000以内的素数
int num;//1000以内素数的个数
int isprime[1000001];
int flag[1000001];//flag[i]表示i是否与当前m互质
void getprime()//筛出素数
{
	for(int i=2;i<=1000000;i++)if(isprime[i]==0)
	{
		prime[num++]=i;
		for(int j=1;j*i<=1000000;j++)
		isprime[j*i]=1;
	}
}
int euler(int n)//求出n的欧拉函数并且筛出所有与其互质的数flag[i]==0表示n与i不互质
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
			for(int j=prime[i];j<=nn;j=j+prime[i])//所有prime[i]的倍数肯定与n不互质
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
