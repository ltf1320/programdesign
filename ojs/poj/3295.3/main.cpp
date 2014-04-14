#include<cstdio>
using namespace std;
const int maxn=300;
char ss[maxn];
int nx;
int p,q,r,s,t;

bool cal()
{
    nx++;
    switch(ss[nx])
    {
    case 'p':return p;
    case 'q':return q;
    case 'r':return r;
    case 's':return s;
    case 't':return t;
    case 'K':return cal()&cal(); //不能用&& 和||，因为可能跳过一段代码
    case 'A':return cal()|cal();
    case 'N':return !cal();
    case 'C':return !cal()|cal();
    case 'E':return cal()==cal();
    }
    return 0;
}


int main()
{
    freopen("in.txt","r",stdin);
    bool T;
    while(~scanf("%s",ss))
    {
        if(ss[0]=='0') break;
        T=1;
        for(p=0;p<=1;p++)
            for(q=0;q<=1;q++)
                for(r=0;r<=1;r++)
                    for(s=0;s<=1;s++)
                        for(t=0;t<=1;t++)
                        {
                            nx=-1;
                            if(!cal())
                            {
                                T=0;
                                break;
                            }
                        }
        if(T) printf("tautology\n");
        else printf("not\n");
    }
    return 0;
}
