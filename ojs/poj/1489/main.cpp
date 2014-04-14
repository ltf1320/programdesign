#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=50;
char symbol[5]= {'|','n','9','8','r'};
int leftS;
int getN(char ch)
{
    switch(ch)
    {
    case '|':
        return 0;
    case 'n':
        return 1;
    case '9':
        return 2;
    case '8':
        return 3;
    case 'r':
        return 4;
    }
    return -1;
}


struct Num
{
    int n;
    int sym[5];
    int read()
    {
        n=0;
        memset(sym,0,sizeof(sym));
        char ch;
        if(scanf("%c",&ch)==EOF) return EOF;
        while(ch!='\n')
        {
            if(ch!=' ')
                sym[getN(ch)]++;
            ch=getchar();
        }
        int now=1;
        for(int i=0; i<5; i++)
        {
            n+=sym[i]*now;
            now*=10;
        }
        return 1;
    }
    void print()
    {
        bool start=0;
        for(int i=0; i<5; i++)
        {
            if(!sym[i]) continue;
            if(start)
            {
                putchar(' ');
                leftS--;
            }
            else start=1;
            for(int j=0; j<sym[i]; j++)
            {
                putchar(symbol[i]);
                leftS--;
            }
        }
    }
    void mul2()
    {
        n*=2;
        int jw=0;
        for(int i=0; i<5; i++)
        {
            sym[i]=2*sym[i]+jw;
            jw=sym[i]/10;
            sym[i]%=10;
        }
    }
    void eqt(int nn)
    {
        n=nn;
        for(int i=0;i<5;i++)
        {
            sym[i]=nn%10;
            nn/=10;
        }
    }
};

int main()
{
    freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);
    Num a,b;
    Num t,c;
    while((~b.read())&&(~a.read()))
    {
        t=b;
        memset(c.sym,0,sizeof(c.sym));
        c.n=1;
        c.sym[0]=1;
        while(c.n<=a.n)
        {
            leftS=34;
            c.print();
            if(c.n&a.n)
            {
                printf(" *");
                leftS-=2;
            }
            while(leftS--)
                putchar(' ');
            t.print();
            putchar('\n');
            c.mul2();
            t.mul2();
        }
        c.eqt(a.n*b.n);
        printf("The solution is: ");
        c.print();
        putchar('\n');
    }
    return 0;
}
