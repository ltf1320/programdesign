#include <string.h>
#include <stdio.h>
#include <math.h>
const int maxn=500;
const int errPri=-1;
const int addPri=1;
const int subPri=1;
const int mulPri=2;
const int divPri=2;
const int powPri=3;
const int braPri=0;

int getjc(int n);//获得n的阶乘
int docalculate();
int calculate(int a,int b,char s);//做a s b
int getPri(char s);//获得运算符的优先级
int main()
{
    while(true)
        printf("%d\n",docalculate());
    return 0;
}


int docalculate()
{
    int numStack[maxn];
    int numTop=0;
    char chStack[maxn];
    int chTop=0;
    char chtmp = 0;
    int detmp,nowtmp;
    int nowPri,lastPri;
    lastPri=errPri;
    chtmp=getchar();
    while(true)
    {
        if(chtmp==' ')
        {
            chtmp=getchar();
            continue;
        }
        if(chtmp=='\n') break;
        if(chtmp>='0'&&chtmp<='9')
        {
            nowtmp=chtmp-'0';
            chtmp=getchar();
            while(chtmp>='0'&&chtmp<='9')
            {
                nowtmp=nowtmp*10+chtmp-'0';
                chtmp=getchar();
            }
            numStack[numTop++]=nowtmp;
        }
        else
        {
            if(chtmp=='(')
            {
                lastPri=getPri(chtmp);
                chStack[chTop++]=chtmp;
                chtmp=getchar();
                continue;
            }
        }
        if(chtmp=='\n') break;
        if(chtmp==' ')
        {
            chtmp=getchar();
            continue;
        }
        //括号另外处理：
        if(chtmp=='(')
        {
            chStack[chTop++]=chtmp;
            lastPri=getPri(chtmp);
            continue;
        }

        if(chtmp==')')
        {
            while(true)
            {
                chtmp=chStack[--chTop];
                if(chtmp=='(')
                    break;
                if(chTop<0)
                {
                    printf("Error 0002:Expect '('\n");
                    return 0;
                }
                if(numTop<2)
                {
                    printf("Error 0005:expretion is incorrect\n");
                    return 0;
                }
                detmp=numStack[--numTop];
                numStack[numTop-1]=calculate(numStack[numTop-1],detmp,chtmp);
            }
            while(true)
            {
                chtmp=getchar();
                if(chtmp=='\n') break;
                if(chtmp==' ') continue;
                else break;
            }
//				chStack[chTop++]=chtmp;
            if(chtmp=='\n') break;
            if(chTop>0)
                lastPri=getPri(chStack[chTop-1]);
            else lastPri=braPri;
        }
        //阶乘另外处理
        if(chtmp=='!')
        {
            numStack[numTop-1]=getjc(numStack[numTop-1]);
            chtmp=getchar();
            continue;
        }

        //对优先级进行判断，更新栈的信息
        nowPri=getPri(chtmp);
        if(nowPri<=lastPri)
        {
            while(nowPri<=lastPri)
            {
                if(chTop==0 || numTop<2)
                {
                    printf("Error 0011:expretion is incorrect\n");
                    return 0;
                }
                detmp=numStack[--numTop];
                numStack[numTop-1]=calculate(numStack[numTop-1],detmp,chStack[--chTop]);
                if(chTop==0) break;
                lastPri=getPri(chStack[chTop-1]);
            }
            lastPri=getPri(chtmp);
            chStack[chTop++]=chtmp;
        }
        else
        {
            chStack[chTop++]=chtmp;
            lastPri=nowPri;
        }
        chtmp=getchar();
    }
    //对剩下的表达式进行计算
    while(true)
    {
        if(chTop==0 && numTop==1)
        {
            return numStack[0];
        }
        if(chTop==0) {
            printf("Error 0006:expretion is incorrect\n");
            return 0;
        }
        if(numTop==1 || numTop==0)
        {
            printf("Error 0007:expretion is incorrect\n");
            return 0;
        }
        chtmp=chStack[--chTop];
        detmp=numStack[--numTop];
        numStack[numTop-1]=calculate(numStack[numTop-1],detmp,chtmp);
    }
}

int getPri(char s)
{
    switch(s)
    {
    case '+':
        return addPri;
    case '-':
        return subPri;
    case '*':
        return mulPri;
    case '/':
        return divPri;
    case '^':
        return powPri;
    case '(':
        return braPri;
    default:
        return -1;
    }
}

int calculate(int a,int b,char s)
{
    switch(s)
    {
    case '+':
        return a+b;
    case '-':
        return a-b;
    case '*':
        return a*b;
    case '/':
        return a/b;
    case '^':
        return pow(a,b);
    default:
        return 0;
    }
}

int getjc(int n)
{
   int now=1;
   for(int i=2;i<=n;i++)
        now*=i;
    return now;
}
