#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
const int maxn=1000+10;
int N;
int AN1,AN;

char str[maxn][maxn*100];
set<int> st;


void init()
{
    str[0][0]='0';
    str[0][1]=0;
    str[1002][0]='1';
    str[1002][1]=0;
    st.clear();
    st.insert(0);
    st.insert(1002);
}
char *get(const char *a,const char *b)
{
    int i=0,n1=0;
    char *res=new char[maxn*100];
    while(a[i]==b[i])
    {
        if(!a[i]) break;
        res[i]=a[i];
        if(a[i]=='1') n1++;
        i++;
    }
    if(b[i+1]==0)
    {
        res[i]='0';
        i++;
        while(a[i]&&a[i]=='1') {res[i]='1';i++;n1++;}
        res[i++]='1';
        n1++;
        res[i]=0;
    }
    else if(b[i+1]=='0')
    {
        if(a[i+1]=='0')
        {
            res[i++]='0';
            res[i++]='1';
            n1++;
            res[i]=0;
        }
        else if(a[i+1]=='1')
        {
            res[i]='0';
            res[i+1]='1';n1++;
            i+=2;
            while(true)
            {
                if(a[i]=='0')
                {
                    res[i++]='1';n1++;
                    res[i]=0;
                    break;
                }
                if(a[i]==0)
                {
                    res[i++]='1';n1++;
                    res[i]=0;
                    break;
                }
                res[i++]='1';
            }
        }
        else if(a[i+1]==0)
        {
            res[i]=a[i];i++;
            res[i++]='1';
            n1++;
            res[i]=0;
        }
    }
    else
    {

    }
    AN+=i;
    AN1+=n1;
    return res;
}

void insert(int n)
{

    char *tt;
    int l,r;
    set<int>::iterator iter=st.find(n);
    iter--;
    l=*iter;
    iter++;iter++;
    r=*iter;
    tt=get(str[l],str[r]);
    strcpy(str[n],tt);
    delete tt;
}

int main()
{
    char t1[maxn],t2[maxn];
    char *t;
    while(~scanf("%s%s",t1,t2))
    {
        t=get(t1,t2);
        printf("%s\n",t);
        delete t;
    }
    return 0;
}
