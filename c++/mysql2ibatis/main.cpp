#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int maxn=100;
const int maxm=1000;
struct sqlField
{
    int id;
    string name;
    string Schema;
    string table;
    string Type;
    int displaySize;
    int Percision;
    int Scale;
};
sqlField fds[maxn];
int cnt=0;

void getNext(char* tmp)
{
    char tch;
    int tn=0;
    while(1)
    {
        tch=getchar();
        if(tch==','||tch=='\n')
            break;
        tmp[tn++]=tch;
    }
    tmp[tn]=0;
}

char toUpperCase(char ch)
{
    if(ch>='a'&&ch<='z')
        ch-=32;
    return ch;
}

string toUpperCase(string str)
{
    char tmp[maxm];
    int len=0;
    for(size_t i=0;i<str.length();i++)
    {
        tmp[len++]=toUpperCase(str[i]);
    }
    tmp[len]=0;
    return string(tmp);
}

//下划线改驼峰
string Xhx2TF(string str)
{
    char tmp[maxm];
    int len=0;
    for(size_t i=0;i<str.length();i++)
    {
        if(str[i]=='_')
        {
            tmp[len++]=toUpperCase(str[i+1]);
            i++;
            continue;
        }
        tmp[len++]=str[i];
    }
    tmp[len]=0;
    return string(tmp);
}



void read()
{
    sqlField tf;
    char tmp[maxm];
    while(cin>>tf.id)
    {
        getchar();
        getNext(tmp);
        tf.name=string(tmp);
        getNext(tmp);
        tf.Schema= string(tmp);
        getNext(tmp);
        tf.table= string(tmp);
        getNext(tmp);
        tf.Type= string(tmp);
        getNext(tmp);
        sscanf(tmp,"%d",&tf.displaySize);
        getNext(tmp);
        sscanf(tmp,"%d",&tf.Percision);
        getNext(tmp);
        sscanf(tmp,"%d",&tf.Scale);
        fds[cnt++]=tf;
    }
}
//生成ibatis配置文件项
void printIbatisResultMap()
{
    for(int i=0;i<cnt;i++)
    {
        cout<<"<result column=\""<<fds[i].name<<"\" property=\""<<Xhx2TF(fds[i].name)<<"\" jdbcType=\""<<fds[i].Type<<"\"/>"<<endl;
    }
}

//生成静态字段
void printConstants()
{
    for(int i=0;i<cnt;i++)
    {
        cout<<"public static final String "<<toUpperCase(fds[i].name)<<"  =  \""<<Xhx2TF(fds[i].name)<<"\";"<<endl;
    }
}

void printColumns(string prefix)
{
    for(int i=0;i<cnt;i++)
    {
        cout<<prefix<<fds[i].name;
        if(i!=cnt-1)
            cout<<',';
        cout<<endl;
    }
}

void printSelectSQL()
{
  //  cout<<"select ";
    for(int i=0;i<cnt;i++)
    {
        cout<<fds[i].name;
        if(i!=cnt-1)
            cout<<',';
    }
  //  cout<<" from "<<fds[0].table<<" where";
}

void printUpdateSQL()
{
   // cout<<"select ";
    for(int i=0;i<cnt;i++)
    {
        cout<<fds[i].name<<"=#{"<<Xhx2TF(fds[i].name)<<"}";
        if(i!=cnt-1)
            cout<<',';
    }
 //   cout<<" from "<<fds[0].table<<" where";
}

void printInsertSQL()
{
   // cout<<"select ";
    for(int i=0;i<cnt;i++)
    {
        cout<<"#{"<<Xhx2TF(fds[i].name)<<"}";
        if(i!=cnt-1)
            cout<<',';
    }
 //   cout<<" from "<<fds[0].table<<" where";
}

void printObject()
{
    for(int i=0;i<cnt;i++)
    {
        cout<<"private "<<fds[i].Type<<" "<<Xhx2TF(fds[i].name)<<";";
        if(i!=cnt-1)
            cout<<endl;
    }
}

void printWhereCondition()
{
    for(int i=0;i<cnt;i++)
    {
        cout<<"<if test=\""<<Xhx2TF(fds[i].name)<<"!=null\""<<">"<<endl;
        cout<<"AND "<<fds[i].name<<"=#{"<<Xhx2TF(fds[i].name)<<"}"<<endl;
        cout<<"</if>"<<endl;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    read();
 //   printColumns(string("settlement_ext."));
  // printIbatisResultMap();
  // cout<<endl;
  //  printSelectSQL();
      printInsertSQL();
//    printConstants();
 //   printObject();
  //  printWhereCondition();
    return 0;
}
