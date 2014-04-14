#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int maxn=100000+10;
const int inf=0x3f3f3f3f;
int h[maxn];
int sumh[maxn];

int abs(int a)
{
    return a>0?a:-a;
}


int chu(int a,int b)
{
    float c=1.0*a/b;
    int cc=floor(c);
    if(c-cc>=0.5) return cc+1;
    else return cc;
}

int main()
{
    freopen("in.txt","r",stdin);
    int C,N;
    int dh,start,end,lstart,lend;
    int cld(1);
    bool dend(0);
    int res(0);
    scanf("%d%d",&N,&C);
    sumh[0]=0;
    h[0]=h[N+1]=inf;
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&h[i]);
        sumh[i]=sumh[i-1]+h[i];
    }
    //对开头进行判断
    end=2;
    if(h[1]<=h[2])
    {
        while(true)
        {
//            dh=(2*(sumh[end-1]-sumh[0])+C)/(2*end);
            dh=chu(2*(sumh[end-1]-sumh[0])+C,2*(end-1));
            if(dh<h[end]||h[end+1]<h[end])
            {
                for(int i=1;i<end;i++)
                {
                    res+=(dh-h[i])*(dh-h[i]);
                    h[i]=dh;
                }
                break;
            }
            end++;
            cld=end;
        }
    }
    //对中间的进行处理
    for(int i=end;i<N;i++)
    {
        if(h[i]<=h[i-1]&&h[i]<=h[i+1])
        {
            start=i;
            end=i+1;
            lstart=lend=0;
            while(true)
            {
   //             dh=(sumh[end-1]-sumh[start-1]+C)/(end-start);
                dh=chu(sumh[end-1]-sumh[start-1]+C,end-start);
                if(lstart==start&&lend==end)
                {
                    if(!(dh<h[start-1]&&dh<h[end]))
                        dh=min(h[start-1],h[end]);
                    for(int j=start;j<end;j++)
                    {
                        res+=(dh-h[j])*(dh-h[j]);
                        h[j]=dh;
                    }
                    break;
                }
                lstart=start;
                lend=end;
                if(dh>=h[start-1]&&h[start]<h[start-1]&&start-1!=cld)
                    start--;
                if(dh>=h[end]&&h[end]<h[end+1]&&end!=N)
                    end++;
                if(end==N) dend=1;
            }
            i=end;
            cld=end-1;
        }
    }
    //对结尾进行判断
    if(h[N]<=h[N-1]&&!dend)
    {
        start=N;
        while(true)
        {
  //          dh=(2*(sumh[N]-sumh[start-1])+C)/(2*(N-start+1));
            dh=chu(2*(sumh[N]-sumh[start-1])+C,2*(N-start+1));
            if(dh<h[start-1]||h[start-2]<h[start-1]||start-1==cld)
            {
                if(dh>h[start-1])
                    dh=h[start-1];
                for(int i=start;i<=N;i++)
                {
                    res+=(dh-h[i])*(dh-h[i]);
                    h[i]=dh;
                }
                break;
            }
            start--;
        }
    }
    for(int i=2;i<=N;i++)
        res+=C*abs(h[i]-h[i-1]);
    printf("%d\n",res);
    return 0;
}
