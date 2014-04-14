#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+10;
const int maxStrLen=110;
const int maxNameLen=40;
const int maxLineLen=300;
const int nextN=70;
int N;
char row[maxLineLen];
int row_len;
int p;
char now_str[maxn];
int now_num;

bool ERR,ENDED;

char strs[maxn][maxStrLen];
int strn;

int getN(char ch)
{
    if(ch>='0'&&ch<='9')
        return ch-'0';
    if(ch>='a'&&ch<='z')
        return ch-'a'+10;
    if(ch>='A'&&ch<='Z')
        return ch-'A'+37;
    return 65;
}

struct Node
{
    Node *next[nextN];
    bool type;
    int num;
    bool end;
    Node()
    {
        end=0;
        memset(next,0,sizeof(next));
    }
    void reset()
    {
        for(int i=0;i<nextN;i++)
        {
            if(next[i])
            {
                next[i]->reset();
                delete next[i];
                next[i]=0;
            }
        }
    }
};
Node var,con;

void insert(bool tp,char *s) //var:tp=0,con:tp=1
{
    int now;
    Node *rt;
    if(var) rt=&var;
    else rt=&con;
    for(int i=0;s[i];i++)
    {
        now=getN(s[i]);
        if(!rt.next[now])
            rt.next=new Node();
        rt=rt->next[now];
    }
    if(rt->end)
    {

    }
}

enum Type
{
    Var,Con,Eql,Str,Num,Err,Print,Dump,Panic,END
};

Type analyse()
{

}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
