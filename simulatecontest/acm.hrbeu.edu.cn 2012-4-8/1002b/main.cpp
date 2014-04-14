#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
using namespace std;

struct pp
{
    string word;
    string w;
};
bool operator<(const pp &a,const pp &b)
{
    return a.w<b.w;
}

pp words[2000];

int main()
{
 //   freopen("in.txt","r",stdin);
    string line;
    getline(cin,line);
    while(1)
    {
        if(!cin) break;
        string::iterator iter=line.begin();
        while(*iter==' ')
        {
            line.erase(iter);
            iter=line.begin();
        }
        while((iter=find(iter,line.end(),' '))!=line.end())
        {
            while(*++iter==' ')
                line.erase(iter);
        }
        stringstream in(line);
        int m=0;
        while(1)
        {
            in>>words[m++].word;
            if(!in) break;
        }
        for(int i=0; i<m; ++i)
            for(string::iterator iter=words[i].word.begin(); iter<words[i].word.end(); ++iter)
                words[i].w.push_back(toupper(*iter));
        stable_sort(words,&words[m]);
        for(int i=0; i<m-1; ++i)
            if(words[i].word!="")
                cout<<words[i].word<<" ";
        cout<<words[m-1].word<<endl;
        for(int i=0; i<m; ++i)
        {
            words[i].word.clear();
            words[i].w.clear();
        }
        getline(cin,line);
        if(!cin) break;
    }
    return 0;
}
