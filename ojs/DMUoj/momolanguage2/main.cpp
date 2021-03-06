#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=10000+100;
typedef long long LL;
LL X,Y;
bool RE;
char tmp[1000];
int linen;
int tmp_p;
int tmp_len;
LL tnum;
char T_op;

struct OP
{
    char op;
    LL a,b;
    int sta,stb;//0 for number,1 for X,2 for Y
    int st;// 0 for null 1 for X,2 for Y
    void reset()
    {
        st=0;
        op='+';
    }
    bool usable()
    {
        if(st) return true;
        if(op=='/')
        {
            if(stb)
                return true;
            else if(b==0)
            {
                RE=1;
                return true;
            }
        }
        return false;
    }
    void go()
    {
        LL na=a,nb=b;
        if(sta==1)
            na=X;
        if(sta==2)
            na=Y;
        if(stb==1)
            nb=X;
        if(stb==2)
            nb=Y;
        if(!st) //表达式
        {
            if(op=='/'&&b==0)
            {
                if(b==0)
                {
                    printf("Runtime Error\n");
                    RE=1;
                    return ;
                }
            }
        }
        //赋值语句
        else if(st==1)
            X=cal(na,nb);
        else Y=cal(na,nb);
    }
    LL cal(LL a,LL b)
    {
        switch(op)
        {
        case '+':
            return a+b;
            break;
        case '-':
            return a-b;
            break;
        case '*':
            return a*b;
            break;
        case '/':
            if(b==0)
            {
                RE=1;
                return 0;
            }
            return a/b;
        }
        return 0;
    }
};


struct Statement
{
    virtual void go(){}
};

struct SingleOp :public Statement
{
    OP op;
    SingleOp(OP p)
    {
        op=p;
    }
    void go()
    {
        if(!RE)
            op.go();
    }
};

struct LOOPST :public Statement
{
    vector<Statement *> ops;
    LOOPST(int st,int n):lpst(st),lpn(n) {}
    LOOPST() {}
    int lpst;//0 for num 1 for X,2 for Y
    int lpn;
    ~LOOPST()
    {
        for(int i=0; i<(int)ops.size(); i++)
        {
            if(RE) return;
            delete ops[i];
        }
    }
    void go()
    {
        if(lpst==1)
            lpn=X;
        else if(lpst==2)
            lpn=Y;
        for(int p=0; p<lpn; p++)
        {
            for(int i=0; i<(int)ops.size(); i++)
            {
                if(RE) return;
                ops[i]->go();
            }
        }
    }
};

enum WType
{
    V_XY,T_Number,T_SEG,T_Operater,T_Ass,T_Loop,T_Begin,T_End,ERR,T_FileEnd
};

void getLine()
{
    tmp_len=0;
    while(tmp_len==0)
    {
        linen++;
        gets(tmp);
        tmp_p=0;
        tmp_len=strlen(tmp);
    }
}

void skip()
{
    if(tmp_p==tmp_len)
        getLine();
    while(tmp[tmp_p]==' '||tmp[tmp_p]=='\t')
    {
        tmp_p++;
        if(tmp_p==tmp_len)
            getLine();
    }
}

WType readWord(bool flag)//flag means is able to analyse number with '+' or '-'
{
    skip();
    int pp=1;
    if(tmp[tmp_p]=='-')
        pp=-1;
    if(flag&&(tmp[tmp_p]=='-'||tmp[tmp_p]=='+'))
        if(tmp[tmp_p+1]>='0'&&tmp[tmp_p+1]<='9')
            tmp_p++;
    if(tmp[tmp_p]>='0'&&tmp[tmp_p]<='9')
    {
        tnum=tmp[tmp_p]-'0';
        tmp_p++;
        while(tmp[tmp_p]>='0'&&tmp[tmp_p]<='9')
        {
            tnum*=10;
            tnum+=tmp[tmp_p]-'0';
            tmp_p++;
        }
        tnum*=pp;
        return T_Number;
    }
    switch(tmp[tmp_p])
    {
    case '#':
        return T_FileEnd;
    case 'E':
        tmp_p+=3;
        return T_End;
    case 'B':
        tmp_p+=5;
        return T_Begin;
    case 'L':
        tmp_p+=4;
        return T_Loop;
    case 'X':
        tnum=1;
        tmp_p++;
        return V_XY;
    case 'Y':
        tnum=2;
        tmp_p++;
        return V_XY;
    case '=':
        tmp_p++;
        return T_Ass;
    case ';':
        tmp_p++;
        return T_SEG;
    case '+':
    case '-':
    case '*':
    case '/':
        T_op=tmp[tmp_p];
        tmp_p++;
        return T_Operater;
    }
    printf("#001 program ERR in row %d\n",linen);
    return ERR;
}

LOOPST* readLoop(int lpst,int lpn)
{
    LOOPST* nowst=new LOOPST(lpst,lpn);
    WType type;
    int kn;
    OP now;
    while(true)
    {
        now.reset();
        type=readWord(1);
        if(type==T_End) break;
        switch(type)
        {
        case V_XY:
            kn=tnum;
            type=readWord(0);
            switch(type)
            {
            case T_SEG://
                break;
            case T_Ass://赋值语句
                now.st=kn;
                type=readWord(1);
                if(type==V_XY)
                    now.sta=tnum;
                else if(type==T_Number)
                {
                    now.sta=0;
                    now.a=tnum;
                }
                else
                {
                    printf("#009 program ERR in row %d\n",linen);
                }
                type=readWord(0);
                if(type==T_SEG)
                {
                    now.stb=0;
                    now.b=0;
                    now.op='+';
                }
                else if(type==T_Operater)
                {
                    now.op=T_op;
                    type=readWord(0);
                    if(type==V_XY)
                        now.stb=tnum;
                    else if(type==T_Number)
                    {
                        now.stb=0;
                        now.b=tnum;
                    }
                    if(readWord(0)!=T_SEG)//';'
                        printf("#003 program ERR in row %d\n",linen);
                }
                break;
            case T_Operater:
                now.st=0;
                now.sta=kn;
                now.op=T_op;
                if(type==V_XY)
                    now.stb=tnum;
                else if(type==T_Number)
                {
                    now.stb=0;
                    now.b=tnum;
                }
                else
                {
                    printf("#002 program ERR in row %d\n",linen);
                }
                if(readWord(0)!=T_SEG)//';'
                    printf("#003 program ERR in row %d\n",linen);
                break;
            default:
                printf("#004 program ERR in row %d\n",linen);
            }
            break;
        case T_Number:
            now.st=0;
            now.sta=0;
            now.a=tnum;
            type=readWord(0);
            if(type==T_SEG)
                break;
            else if(type!=T_Operater)
            {
                printf("#011 program ERR in row %d\n",linen);
            }
            now.op=T_op;
            type=readWord(0);
            if(type==V_XY)
                now.stb=tnum;
            else if(type==T_Number)
            {
                now.stb=0;
                now.b=tnum;
            }
            else
            {
                printf("#005 program ERR in row %d\n",linen);
            }
            if(readWord(0)!=T_SEG)//';'
                printf("#006 program ERR in row %d\n",linen);
            break;
        case T_Loop:
            type=readWord(1);
            if(type==V_XY)
                nowst->ops.push_back(readLoop(tnum,0));
            else if(type==T_Number)
                nowst->ops.push_back(readLoop(0,tnum));
            else printf("#007 program ERR in row %d\n",linen);
            break;
        default:
            printf("#008 program ERR in row %d\n",linen);
        }
        if(now.usable())
        {
            nowst->ops.push_back(new SingleOp(now));
        }
    }
    return nowst;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    LOOPST *final;
    WType type;
    while(true)
    {
        RE=0;
        X=Y=0;
        getLine();
        type=readWord(0);
        if(type==T_FileEnd)
            break;
        if(type!=T_Begin)
            printf("#010 program ERR in row %d\n",linen);
        final=readLoop(0,1);
        final->go();
        if(RE)
            printf("Runtime Error\n");
        else
        {
            printf("%lld %lld\n",X,Y);
        }
        delete final;
    }
    return 0;
}
