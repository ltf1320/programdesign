//Hash 1Aˬ..

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn=1000000;
const int pri=999983;
const double err=1E-8;


struct Snow
{
    int s[6];
    int h1,h2;
    void getHashs()
    {
        int sum=0;
        for(int i=0;i<6;i++) sum+=s[i];
        h1=sum%pri;
        double k=0;
        for(int i=0;i<6;i++) k+=1/(1.0+s[i]);
        h2=((int)(k*maxn))%pri;
    }
};

vector<Snow> sv[maxn];

bool compare(Snow &a,Snow &b)
{
    int i,j;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if(a.s[j]!=b.s[(i+j)%6]) break;
        }
        if(j==6)return true;
    }
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if(a.s[5-j]!=b.s[(i+j)%6]) break;
        }
        if(j==6)return true;
    }
    return false;
}

Snow tmp;
int n,tmpn;


bool judge()
{
    tmpn=tmp.h1;
    if(sv[tmpn].size()==0)
        sv[tmpn].push_back(tmp);
    else
    {
        for(size_t i=0;i<sv[tmpn].size();i++)
            if(sv[tmpn][i].h2==tmp.h2)
            {
                if(compare(tmp,sv[tmpn][i])) return true;
            }
    }
    return false;
}



int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    bool flag=0;
    for(int i=0;i<n;i++)
    {
        for(int i=0;i<6;i++)
            scanf("%d",&tmp.s[i]);
        tmp.getHashs();
        if(judge())
        {
            flag=1;
            break;
        }
    }
    if(flag) printf("Twin snowflakes found.\n");
    else printf("No two snowflakes are alike.\n");
    return 0;
}
