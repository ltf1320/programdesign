#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<algorithm>


using namespace std;

struct node
{
    string str;
    int old,news;
}a[1010];

int p1,p2;
char s[100];
int tmp,k,p;

bool cmp(node a,node b)
{
    return a.news<b.news;
}

void inserts(int x,string keys)
{
    for(int i=0;i<p1;i++)
    {
        if(a[i].old==x)
        {
            a[i].str=keys;
            a[i].old=x;
            return;
        }
    }
    a[p1].str=keys;
    a[p1].news=0;
    a[p1++].old=x;
}

int searchs(int x)
{
    for(int i=0;i<p1;i++)
    {
        if(a[i].old==x)
        {
            if(a[i].news==0) a[i].news=p2++;
            return a[i].news;
        }
    }
    a[p1].news=p2++;
    a[p1].str="";
    a[p1++].old=x;
    return p2-1;
}

bool isBlank()
{
    k=0;
    while(s[k]!='\0')
        if(!isspace(s[k++])) return false;
    return true;

}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    p1=0,p2=1;
    while(gets(s)!=NULL)
    {
        while(isBlank())
            if(gets(s)==NULL) break;
        if(isBlank()) break;
            if(s[0]=='[')
            {
                tmp=0;
                while(s[k]!=']')
                    tmp=tmp*10+(s[k++]-'0');
                string ss=s+k+1;
                ss+="\n";
                while(gets(s)!=NULL && !isBlank())
                    ss=ss+s,ss+="\n";

                inserts(tmp,ss);
            }
            else
            {
                do
                {
                    for(int i=0;i<strlen(s);i++)
                    {
                        if(s[i]=='[')
                        {
                            tmp=0,i++;
                            while(s[i]!=']')
                                tmp=tmp*10+(s[i++]-'0');
                            p=searchs(tmp);
                            printf("[%d]",p);
                        }
                        else
                            putchar(s[i]);
                    }
                   puts("");
                }while(gets(s)!=NULL && !isBlank());
                puts("");
            }
    }
    sort(a,a+p1,cmp);
    for(int i=0;i<p1;i++)
    {
        printf("[%d]%s\n",i+1,a[i].str.c_str());
       //puts("");
    }
    //system("pause");
    return 0;
}
