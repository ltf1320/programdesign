#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Big
{
    static const int maxn=1009,BIT=10000;
    int s[maxn],l;
    Big();
    Big(int b);
    Big(char *str);

    template <typename T>
    void operator=(T b);

    bool operator<(const Big &b);
    bool operator==(const Big &b);
    bool operator>(const Big &b);
    bool operator<=(const Big &b);
    bool operator>=(const Big &b);

    Big operator+(const Big &b);
    Big operator*(const Big &b);
    Big operator-(const Big &b);
    Big operator/(const int &b);
    void out();
};
Big::Big()
{
    memset(s,0,sizeof(s)),l=1;
}
Big::Big(int b)
{
    memset(s,0,sizeof(s)),l=0;
    while(b) s[l++]=b%BIT,b/=BIT;
    l=(!l)?1:l;
}
Big::Big(char *str)
{
    memset(s,0,sizeof(s)),l=0;
    int i,j,p;
    for(i=strlen(str)-1;i>=0;i-=4)
    {
        for(p=0,j=max(i-3,0);j<=i;p=p*10+str[j]-'0',++j);
        s[l++]=p;
    }
    while(!s[l-1] && l-1) l--;
}
template <typename T>
void Big::operator=(T b)
{
    Big tmp(b);
    (*this)=tmp;
}
bool Big::operator<(const Big &b)
{
    if(l!=b.l) return l<b.l;
    for(int i=l-1;i>=0;i--) if(s[i]!=b.s[i]) return s[i]<b.s[i];
    return 0;
}
bool Big::operator==(const Big &b)
{
    if(l!=b.l) return 0;
    for(int i=l-1;i>=0;i--) if(s[i]!=b.s[i]) return 0;
    return 1;
}
bool Big::operator>(const Big &b)
{
    return !((*this)<b || (*this)==b);
}
bool Big::operator<=(const Big &b)
{
    return (*this)<b || (*this)==b;
}
bool Big::operator>=(const Big &b)
{
    return (*this)>b || (*this)==b;
}
Big Big::operator+(const Big &b)
{
    Big c;
    c.l=max(l,b.l);
    for(int i=0;i<c.l;++i)
c.s[i]+=s[i]+b.s[i],c.s[i+1]+=c.s[i]/BIT,c.s[i]%=BIT;
    while(c.s[c.l]) c.s[c.l+1]+=c.s[c.l]/BIT,c.s[c.l++]%=BIT;
    return c;
}
Big Big::operator*(const Big &b)
{
    Big c;
    for(int i=0;i<l;i++)  for(int j=0;j<b.l;j++)
    c.s[i+j]+=s[i]*b.s[j],c.s[i+j+1]+=c.s[i+j]/BIT,c.s[i+j]%=BIT;
    c.l=l+b.l;
    while(!c.s[c.l-1] && c.l-1) c.l--;
    return c;
}
Big Big::operator-(const Big &b)
{
    Big c=(*this);
    for(int i=0;i<c.l;i++)  if((c.s[i]-=b.s[i])<0) c.s[i+1]--,c.s[i]+=BIT;
    while(c.l-1 && !c.s[c.l-1]) c.l--;
    return c;
}
Big Big::operator/(const int &b)
{
    Big c;
    for(int i=l-1,x=0;i>=0;i--) x=x*BIT+s[i],c.s[i]=x/b,x%=b;
    c.l=l;
    while(c.l-1 && !c.s[c.l-1]) c.l--;
    return c;
}

void Big::out()
{
    printf("%d",s[l-1]);
    for(int i=l-2;i>=0;i--) printf("%04d",s[i]);
    puts("");
}


int main()
{
    Big a=100,b=10;
    Big c=a/b;
    c.out();
    return 0;
}
