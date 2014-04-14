#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define  N  11+1
#define  S   (1<<12)
#define  LL  long long
LL dp[N][S];
bool a[S];
int n,Maxn,h,w;

bool Ok(int i)//��ʼ����1��״̬Ϊiʱ�Ƿ�����
{
    for(int k = 0 ; k < w; )
    {
        if(i & (1<<k))
        {
            if(k == w-1 || !(i & (1<<(k+1))))
                return false;

            k+= 2;
        }
        else k ++;
    }
    return true;
}

bool Pk(int i,int j)//�ж�i��j״̬���޳�ͻ
{
    int k;
    for(k = 0; k < w; )
    {
        if((i & (1<<k)) == 0)
        {
            if((j & (1<<k)) == 0)//�����i��Ϊ0�����j��һ����Ϊ1
                return false;
            k ++;
        }
        else
        {
            if(j & (1<<k))
                if(k == w-1 || ((i & (1<<(k+1))) && (j & (1<<(k+1)))) == 0)//�Ҿ��������ﵹ��ù
                    //k == w-1 || ((i & (1<<(k+1))) || (j & (1<<(k+1))))�������ٿ�����һ���������ѽ����ˬ����
                    return false;
                else k +=2;
            else k++;
        }
    }
    return true;
}
int main()
{
    while(scanf("%d %d",&h,&w),h && w)
    {
        int i,j,k;

        if(h < w)//��״̬��ȡС���Ż�����
            i = h ,h = w,w =i;

        Maxn = (1<<w)-1;
        memset(dp,0,sizeof(dp));

        for(i = 0 ; i <= Maxn; i++)//��ʼ����1��
        {
            if(Ok(i))
                dp[h][i] =1;
        }

        for(k = h-1 ; k >=1; k --)//ö�ٵ�k��
        {
            for(i = 0 ; i <= Maxn; i++)//��ǰ�е�״̬
            {
                for(j = 0; j <= Maxn ; j++) //ǰһ�е�״̬
                {
                    if(Pk(i,j))
                        dp[k][i] +=dp[k+1][j];
                }
            }
        }

        cout<<dp[1][Maxn]<<endl;
    }
    return 0;
}
