#include <iostream>
#include <map>
#include <cstdio>
#include <string>
using namespace std;
const int Haabyear=365;
const int Hollyyear=13*20;

string Haabs[19]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
map<string,int> Haab;

long long getNumOfDay(int d,string &s,int y)
{
    int res=y*Haabyear;
    res+=Haab[s]*20+d;
    return res;
}

string Hollys[20]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
struct Holly
{
    int d,y;
    string m;
    void reset(long long nd)
    {
        y=nd/Hollyyear;
        nd%=Hollyyear;
        m=Hollys[nd%20];
        d=nd%13+1;
    }
    void print()
    {
        cout<<d<<" "<<m<<" "<<y<<endl;
    }
};


int main()
{
    freopen("in.txt","r",stdin);
    for(int i=0;i<19;i++)
        Haab[Haabs[i]]=i;
    int T;
    cin>>T;
    cout<<T<<endl;
    int d,y;
    char ch;
    string m;
    Holly hd;
    while(T--)
    {
        cin>>d>>ch>>m>>y;
        hd.reset(getNumOfDay(d,m,y));
        hd.print();
    }
    return 0;
}
