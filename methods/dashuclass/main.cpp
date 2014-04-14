#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

const int maxn=1000;

class bign
{
    friend bign operator+(const bign a,const bign b);
    friend ostream& operator<<(ostream& out,const bign a);
    public:
        bign():len(0){memset(num,0,sizeof(num));}
        bign(const char* chs):len(0)
        {
            memset(num,0,sizeof(num));
            int i=0;
            while(chs[i])
            {
                len++;
                num[i++]=chs[i]-'0';
            }
        }
        bign& operator=(const char* chs)
        {
            memset(num,0,sizeof(num));
            int i=0;
            while(chs[i])
            {
                len++;
                num[i++]=chs[i]-'0';
            }
            return *this;
        }
        string str() const
        {
            string tem;
            ostringstream sout;
            int i=maxn-1;
            int j=0;
            while(num[j])
                sout<<static_cast<char>(num[j++]+'0');
            tem=sout.str();
            return tem;
        }
    private:
        int num[maxn];
        int len;

};

ostream& operator<<(ostream& out,const bign a)
{
    out<<a.str();
    return out;
}

bign operator+(const bign a,const bign b)
{
    bign tem;
    int c,k;
    for(int i=0;i<max(a.len,b.len)+1;++i)
    {
        k=a.num[i]+b.num[i]+c;
        tem.num[i]=k%10;
        c=k/10;
    }
    return tem;
}
/*
bign operator*(const bign a,const bign b)
{
    bign tem;
    int c,k;
    for(int i=0;i<maxn-1;++i)
    {

    }
}
*/
int main()
{
    bign a("123"),b("234");
    bign c;
    c=a+b;
    cout<<c<<endl;
    return 0;
}
