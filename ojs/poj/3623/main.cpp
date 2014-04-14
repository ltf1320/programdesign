#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=30000+100;
int N;
char ori[maxn];
char res[maxn];
int next[maxn],pre[maxn];

void work()
{
    ori[N+1]=0;
    ori[0]=0;
    for(int i=1; i<=N;)
    {
        for(int j=i+1; j<=N+1; j++)
        {
            if(ori[j]!=ori[i])
            {
                for(int k=i; k<j; k++)
                {
                    next[k]=j;
                }
                i=j;
                break;
            }
        }
    }
    for(int i=N; i>0;)
    {
        for(int j=i-1; j>=0; j--)
        {
            if(ori[j]!=ori[i])
            {
                for(int k=i; k>j; k--)
                {
                    pre[k]=j;
                }
                i=j;
                break;
            }
        }
    }

    int l=1,r=N;
    int p=0;
    int dl,dr;
    int nl,nr;
    while(r>l)
    {
        if(ori[l]>ori[r])
            res[p++]=ori[r--];
        else if(ori[r]>ori[l])
            res[p++]=ori[l++];
        else
        {
            nl=l,nr=r;
            dl=dr=0;
            while(dl==dr&&ori[nl]==ori[nr]&&nl<nr)
            {
                dl=next[nl]-nl;
                dr=nr-pre[nr];
                nl=next[nl];
                nr=pre[nr];
            }
            if(dl==dr)
            {
                if(nl>=nr) //
                {
                    res[p++]=ori[l++];
                }
                else if(ori[nl]<ori[nr])
                    res[p++]=ori[l++];
                else res[p++]=ori[r--];
            }
            else
            {
                if(dl<dr)
                {
                    if(ori[nl]<ori[next[nr]])
                        res[p++]=ori[l++];
                    else res[p++]=ori[r--];
                }
                else
                {
                    if(ori[nr]>ori[pre[nl]])
                        res[p++]=ori[l++];
                    else res[p++]=ori[r--];
                }
            }
        }
    }
    res[p++]=ori[l];
    for(int i=0; i<N; i++)
    {
        if(i&&(i%80==0))
            putchar('\n');
        putchar(res[i]);
    }
    printf("\n");
}

void input()
{
    for(int i=1; i<=N; i++)
    {
        scanf("%c",&ori[i]);
        if(ori[i]==' '||ori[i]=='\n')
        {
            i--;
            continue;
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(~scanf("%d",&N))
    {
        input();
        work();
    }
    return 0;
}
