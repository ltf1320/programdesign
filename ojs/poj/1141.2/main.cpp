#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100+10;

char stack[maxn];
int top;
int main()
{
    char ch;
    while(true)
    {
        top=0;
        if(scanf("%c",&ch)==EOF) break;
        while(ch!='\n')
        {
            if(ch=='('||ch=='[')
            {
                stack[top++]=ch;
                putchar(ch);
            }
            else
            {
                if(ch==')')
                {
                    while(top!=0&&stack[top-1]!='(')
                    {
                        printf("]");
                        top--;
                    }
                    if(top>0)
                    {
                        putchar(')');
                        top--;
                    }
                    else  printf("()");
                }
                else
                {
                    while(top!=0&&stack[top-1]!='[')
                    {
                        printf(")");
                        top--;
                    }
                    if(top>0)
                    {
                        putchar(']');
                        top--;
                    }
                    else  printf("[]");
                }
            }
            ch=getchar();
        }
        while(top!=0)
        {
            if(stack[top-1]=='(')
                putchar(')');
            else putchar(']');
            top--;
        }
        putchar('\n');
    }
    return 0;
}
