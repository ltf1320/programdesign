//1A不解释
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn=20;

struct Piece
{
    const static int K=5;
    const static int Q=4;
    const static int R=3;
    const static int B=2;
    const static int N=1;
    const static int P=0;
    int type,r,c;
    void print()
    {
        switch(type)
        {
            case K:putchar('K');break;
            case Q:putchar('Q');break;
            case R:putchar('R');break;
            case B:putchar('B');break;
            case N:putchar('N');break;
            case P:break;
        }
        putchar('a'+c-1);
        printf("%d",r);
    }
    void reset(char t,int r,int c)
    {
        switch(t)
        {
            case 'K':type=K;break;
            case 'Q':type=Q;break;
            case 'R':type=R;break;
            case 'B':type=B;break;
            case 'N':type=N;break;
            case 'P':type=P;break;
        }
        this->r=r;
        this->c=c;
    }
};

struct BP: public Piece
{
    bool operator<(const BP& a) const
    {
        if(type==a.type)
        {
            if(r==a.r)
            {
                return c<a.c;
            }
            else return r>a.r;
        }
        else return type>a.type;
    }
};

struct WP:public Piece
{
    bool operator<(const WP& a) const
    {
        if(type==a.type)
        {
            if(r==a.r)
            {
                return c<a.c;
            }
            else return r<a.r;
        }
        else return type>a.type;
    }
};

BP bp[maxn];
WP wp[maxn];

int bn,wn;

bool judge(char h)
{
    if(h=='|'||h=='.'||h==':') return 0;
    else return 1;
}

void DO(char h,int r,int c)
{
    if(h=='|'||h=='.'||h==':') return ;
    if(h>=97&&h<=122)
    {
        bp[bn++].reset(toupper(h),r,c);
    }
    else wp[wn++].reset(h,r,c);
}

int main()
{
    freopen("in.txt","r",stdin);
    while(getchar()!='\n');
    bn=0,wn=0;
    char tmp;
    for(int i=8;i>=1;i--)  //行
    {
        for(int j=1;j<=8;j++) //列
        {
            for(int k=0;k<4;k++)
            {
                scanf("%c",&tmp);
                DO(tmp,i,j);
            }
        }
        while(getchar()!='\n');
        while(getchar()!='\n');
    }
    sort(bp,bp+bn);
    sort(wp,wp+wn);
    printf("White: ");
    for(int i=0;i<wn-1;i++)
    {
        wp[i].print();
        putchar(',');
    }
    wp[wn-1].print();
    putchar('\n');

    printf("Black: ");
    for(int i=0;i<bn-1;i++)
    {
        bp[i].print();
        putchar(',');
    }
    bp[bn-1].print();
    putchar('\n');
    return 0;
}
