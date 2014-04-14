#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Student
{
    string name;
    int score;
};

bool operator<(const Student &a,const Student &b)
{
    if(a.score>b.score)
        return 1;
    if(a.score==b.score)
        if(a.name<b.name)
            return 1;
    return 0;
}

int main()
{
    freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    while(1)
    {
        if(!cin) break;
        Student s[200000];
        for(int i=0; i<n; ++i)
            cin>>s[i].name>>s[i].score;
        sort(s,&s[n]);
        for(int i=0; i<n; ++i)
            cout<<s[i].name<<" "<<s[i].score<<endl;
        cin>>n;
        if(!cin) break;
        cout<<endl<<endl;
    }
    return 0;
}
