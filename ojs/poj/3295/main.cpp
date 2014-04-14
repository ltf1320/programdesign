#include <cstdio>

using namespace std;

char ss[200];
int nst;
int nx;

//pqrst
bool cal(char s)
{
    bool a1,a2;
    char tmp;
    switch(ss[nx])
    {
    case 'p':
        a1=nst&1;
        break;
    case 'q':
        a1=(nst>>1)&1;
        break;
    case 'r':
        a1=(nst>>2)&1;
        break;
    case 's':
        a1=(nst>>3)&1;
        break;
    case 't':
        a1=(nst>>4)&1;
        break;
    default:
        tmp=ss[nx];
        nx++;
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
            a2=nst&1;
            break;
        case 'q':
            a2=(nst>>1)&1;
            break;
        case 'r':
            a2=(nst>>2)&1;
            break;
        case 's':
            a2=(nst>>3)&1;
            break;
        case 't':
            a2=(nst>>4)&1;
            break;
        default:
            tmp=ss[nx];
            nx++;
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
        for(nst=0; nst<=32; nst++)
        {
            nx=1;
            if(!cal(ss[0]))
            {
                T=0;
                break;
            }
        }
        if(T)  printf("tautology\n");
        else printf("not\n");
    }
    return 0;
}
