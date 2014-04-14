#include <cstdio>

using namespace std;

char ss[1000];
int nx;
int p,q,r,s,t;
//pqrst
int cal(char s)
{
    int a1,a2;
    char tmp;
    nx++;
    switch(ss[nx])
    {
    case 'p':
        a1=p;
        break;
    case 'q':
        a1=q;
        break;
    case 'r':
        a1=r;
        break;
    case 's':
        a1=s;
        break;
    case 't':
        a1=t;
        break;
    default:
        tmp=ss[nx];
        a1=cal(tmp);
        break;
    }
    if(s=='N') return !a1;
    else
    {
        nx++;
        switch(ss[nx])
        {
        case 'p':
            a2=p;
            break;
        case 'q':
            a2=q;
            break;
        case 'r':
            a2=r;
            break;
        case 's':
            a2=s;
            break;
        case 't':
            a2=t;
            break;
        default:
            tmp=ss[nx];
            a2=cal(tmp);
            break;
        }
    }
    switch(s)
    {
    case 'K':
        return a1&&a2;
    case 'A':
        return a1||a2;
    case 'C':
        return (!a1)||a2;
    case 'E':
        return a1==a2;
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
        for(q=0;q<2;q++)
            for(p=0;p<2;p++)
                for(r=0;r<2;r++)
                    for(s=0;s<2;s++)
                        for(t=0;t<2;t++)
                        {
                            nx=0;
                            if(!cal(ss[0])) {T=0;break;}
                        }
        if(T)  printf("tautology\n");
        else printf("not\n");
    }
    return 0;
}
