#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+100;
const int maxk=30;
int N,M,K;
int lev[maxn];

int pp[maxk]; //ƥ�����
int pnum[maxk]; //ƥ��ĸ���

int dp[maxn];
int pi[maxn]; //kmpԤ��������
int a[maxn]; //a����

void kmp() //kmpԤ����
{
    int p,k;
    k=-1;
    pi[0]=-1;
    for(p=1; p<=M; p++)
    {
        while(k!=-1&&a[k+1]!=a[p])
            k=pi[k];
        if(a[k+1]==a[p])
            k=k+1;
        pi[p]=k;
    }
}
int p;

bool judge() //�ж�ƥ���Ƿ���ϴ�С��ϵ
{
    bool flag=1;
    int w=1;
    while(pnum[w]==0) w++; //
    for(int j=w+1; j<=K; j++)
    {
        if(pnum[j])
        {
            if(pp[j]<=pp[w])
            {
                flag=0;
                break;
            }
            w=j;
        }
    }
    return flag;
}

void work()
{
    kmp();
    p=-1;
    for(int i=0; i<N; i++)
    {
        dp[i+1]=max(dp[i+1],dp[i]);
        while(true)
        {
            bool de=0; //����Ƿ��¼���ƥ��
            if(a[p+1]&&!pnum[a[p+1]])
            {
                pp[a[p+1]]=lev[i];
                pnum[a[p+1]]=1;
                de=1;
            }
            if(a[p+1]&&pp[a[p+1]]==lev[i]&&judge())
            {
                if(!de)
                    pnum[a[p+1]]++;
                break;
            }
            if(de)
                pnum[a[p+1]]--;
            if(p==-1)
                break;
//���ƥ��ʧ�ܣ���i-p-1��ʼ����ƥ��
/*
10 5 10
2 4 2 4 2 1 7 1 7 1
1 2 1 2 1
*/
            if(pi[p]==-1)
            {
                i=i-p-1;
                p=-1;
                memset(pp,0,sizeof(pp));
                memset(pnum,0,sizeof(pnum));
                break;
            }
            //���Ѿ��Ѿ��޷�ƥ���ȥ��
            for(int j=pi[p]+1; j<=p; j++)
            {
                pnum[a[j]]--;
            }
            p=pi[p];
        }
        if(pp[a[p+1]]==lev[i])
            p++;
        if(p==M-1)
        {
            dp[i+1]=max(dp[i+1],dp[i+1-M]+1);
        }
    }
    printf("%d\n",dp[N]);
}

void input()
{
    for(int i=0; i<N; i++)
        scanf("%d",&lev[i]);
    for(int i=0; i<M; i++)
        scanf("%d",&a[i]);
}

void init()
{
    memset(dp,0,sizeof(dp));
    memset(pp,0,sizeof(pp));
    memset(pnum,0,sizeof(pnum));
    memset(a,0,sizeof(a));
    memset(pi,0,sizeof(pi));
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&N,&M,&K))
    {
        init();
        input();
        work();
    }
    return 0;
}
