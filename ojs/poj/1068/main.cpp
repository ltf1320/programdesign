#include<cstdio>

using namespace std;
const int maxn=100;
int st[maxn];

int sp;

void fd()
{
    int tp=sp-1;
    int count=1;
    for(;tp>=0;tp--)
    {
        if(st[tp]==-1)
        {
            st[tp]=1;
            printf("%d",count);
            break;
        }
        else count++;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int t,n,tmp,tsp;
    scanf("%d",&t);
    while(t--)
    {
        sp=tmp=0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&tsp);
            if(tmp==tsp)
            {
                fd();
            }
            else
            {
                int dif=tsp-tmp;
                dif--;
                while(dif--)
                {
                    st[sp++]=-1;
                }
                st[sp++]=1;
                printf("1");
            }
            tmp=tsp;
            if(n) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}


