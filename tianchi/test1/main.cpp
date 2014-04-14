#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
using namespace std;

const int MAX_USER_NUM=2000;
const int MAX_BRAND_NUM=10000;
const int MAX_RECORD_NUM=1000000;

struct Type
{
    int id;
    string description;
    /*
    bool operator<(const Type& a)const
    {
        return id<a.id;
    }
    */
};

struct userType:public Type
{
    virtual bool judge(int id);
    virtual double mark(int userid,int brandid);
};
set<userType> userTps;
int userTpn;

struct brandType:public Type
{
    virtual bool judge(int id);
};
set<brandType> brandTps;
int brandTpn;

struct User
{
    string id;
    set<int> tps;
};
User users[MAX_USER_NUM];

struct Brand
{
    string id;
    set<int> tps;
};
Brand brds[MAX_BRAND_NUM];

map<string,int> usermp;
int usernum;

int findUser(string id)
{
    if(usermp.count(id))
        return usermp[id];
    usermp[id]=usernum;
    users[usernum].id=id;
    return usernum++;
}

map<string,int> brandmp;
int brandnum;

int findBrand(string id)
{
    if(brandmp.count(id))
        return brandmp[id];
    brandmp[id]=usernum;
    brds[usernum].id=id;
    return brandnum++;
}

struct Record
{
    static int userbox[MAX_USER_NUM];
    static int brandbox[MAX_BRAND_NUM];
    static Record rcd[MAX_RECORD_NUM];

    static int num;
    static void init() ///
    {
        num=0;
        memset(userbox,-1,sizeof(userbox));
        memset(brandbox,-1,sizeof(brandbox));
    }
    static void add(string userId,string brandId,int op)
    {
        int user=findUser(userId);
        int brand=findBrand(brandId);
        rcd[num].user=user;
        rcd[num].brand=brand;
        rcd[num].bnext=brandbox[brand];
        rcd[num].unext=userbox[user];
        rcd[num].op=op;
        brandbox[brand]=num;
        userbox[user]=num;
        num++;
    }
    int user,brand,unext,bnext;
    int op;//点击：0 购买：1 收藏：2 购物车：3
};

struct buyedUser:public userType
{
    bool judge(int id)
    {
        for(int i=Record.userbox[id];i!=-1;i=Record.rec[i].unext)
    }
};



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
