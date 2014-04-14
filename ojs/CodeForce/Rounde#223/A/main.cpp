#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=100000+1000;
const int mx=100000;
LL num[maxn];
LL len;
int m,n;

struct Op
{
    int type;
    int l,c;
};
Op ops[maxn];

int main()
{
  // freopen("in.txt","r",stdin);
    scanf("%d",&m);
    for(int i=0; i<m; i++)
    {
        scanf("%d",&ops[i].type);
        if(ops[i].type==1)
            scanf("%d",&ops[i].c);
        else
            scanf("%d%d",&ops[i].l,&ops[i].c);
    }
    len=0;
    scanf("%d",&n);
    int nowm=0;
    LL t;
    bool flag=0;
    for(int i=0; i<n; i++)
    {
        scanf("%I64d",&t);
        while(true)
        {
            if(ops[nowm].type==1)
            {
                if(len<mx)
                    num[++len]=ops[nowm].c;//
                else len++;
                if(len==t)
                {
                    printf("%d ",ops[nowm++].c); //
                    break;
                }
                nowm++;
            }
            else
            {
                if(len+ops[nowm].c*ops[nowm].l>=t)
                {
                    int kk=(t-len)%ops[nowm].l;
                    if(kk==0)
                        kk=ops[nowm].l;
                    printf("%I64d ",num[kk]);
                    break;
                }
                else
                {
                    if(flag)
                        len+=ops[nowm].c*ops[nowm].l;
                    else
                        for(int j=0; j<ops[nowm].c; j++)
                        {
                            for(int k=1; k<=ops[nowm].l; k++)
                            {
                                if(len<mx)
                                {
                                    num[++len]=num[k];
                                }
                                else
                                {
                                    flag=1;
                                    len+=ops[nowm].l-k+1+ops[nowm].l*(ops[nowm].c-j-1); //
                                    break;
                                }
                            }
                            if(flag) break;
                        }
                    nowm++;
                }
            }
        }
    }
    puts("");
    return 0;
}
