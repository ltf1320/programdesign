#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
const int maxn=1000+10;
int N,M;
set<int> XY[maxn];
int X[maxn],Y[maxn],Z[maxn];
set<int> ZY[maxn];
set<int> ZX[maxn];
int res;

void init()
{
    for(int i=1; i<=N; i++)
    {
        XY[i].clear();
        ZY[i].clear();
        ZX[i].clear();
    }
    res=0;
    memset(X,0,sizeof(X));
    memset(Y,0,sizeof(Y));
    memset(Z,0,sizeof(Z));
}


int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    int a,b;
    char ca,cb,ch;
    while(T--)
    {
        scanf("%d%d",&N,&M);
        init();
        for(int i=0; i<M; i++)
        {
            ch=getchar();
            //scanf("%c=%d,%c=%d",&ca,&a,&cb,&b);
            while(ch!='Y'&&ch!='X'&&ch!='Z')
                ch=getchar();
            ca=ch;
            while(ch!='=') ch=getchar();
            scanf("%d",&a);
            while(ch!='Y'&&ch!='X'&&ch!='Z')
                ch=getchar();
            cb=ch;
            while(ch!='=') ch=getchar();
            scanf("%d",&b);

            if(a>N||a<1)continue;
            if(b>N||b<1) continue;
            if(ca=='X'&&cb=='Y')XY[a].insert(b);
            if(ca=='Y'&&cb=='X')XY[b].insert(a);
            if(ca=='X'&&cb=='Z')ZX[b].insert(a);
            if(ca=='Z'&&cb=='X')ZX[a].insert(b);
            if(ca=='Z'&&cb=='Y')ZY[a].insert(b);
            if(ca=='Y'&&cb=='Z')ZY[b].insert(a);
        }
        for(int i=1; i<=N; i++)
            for(set<int>::iterator iter=XY[i].begin(); iter!=XY[i].end(); iter++)
            {
                X[i]++;
                Y[*iter]++;
                res+=N;
            }
        for(int i=1; i<=N; i++)
            for(set<int>::iterator iter=ZX[i].begin(); iter!=ZX[i].end(); iter++)
            {
                res+=N-X[*iter];
                Z[i]++;
            }
        for(int i=1; i<=N; i++)
            for(set<int>::iterator iter=ZY[i].begin(); iter!=ZY[i].end(); iter++)
            {
                res+=N-Y[*iter]-Z[i];
            }
        for(int i=1; i<=N; i++)
            for(set<int>::iterator iter=XY[i].begin(); iter!=XY[i].end(); iter++)
            {
                for(int j=1; j<=N; j++)
                {
                    if(ZX[j].find(i)!=ZX[j].end()&&ZY[j].find(*iter)!=ZY[j].end())
                        res++;
                }
            }

        printf("%d\n",res);
    }
    return 0;
}
