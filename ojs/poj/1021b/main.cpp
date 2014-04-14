#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
using namespace std;

class SQ
{
    friend bool operator==(const SQ sq1,const SQ sq2);
public:
    SQ():n(0) {};
    void insert(int x,int y)
    {
        xvec.push_back(x);
        yvec.push_back(y);
        n++;
    }
    bool isn(int x,int y)
    {
        for(vector<int>::iterator xiter=xvec.begin(),yiter=yvec.begin(); xiter!=xvec.end(); ++xiter,++yiter)
        {
            if(((*xiter-x)<=1)&&((*yiter-y)<=1))
                return 1;
        }
        return 0;
    }
private:
    vector<int> xvec,yvec;
    int n;
};

inner bool operator==(const SQ sq1,const SQ sq2)
{
    if((sq1.n==1)&&(sq2.n==1)
       return 1;
    int kx1,ky1,kx2,ky2;
    kx1=sq1.xvec[1]-sq1.xvec[0];
    kx2=sq2.xvec[1]-sq2.xvec[0];
    ky1=sq1.yvec[1]-sq1.yvec[0];
    ky2=sq2.yvec[1]-sq2.yvec[0];
    for(int i;i<sq1.sum;++i)
    {

    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int t,W,H,n;
    string line1,line2;
    cin>>t;
    for(int i=0; i<t; ++i)
    {
        cin>>W>>H>>n;
        getline(cin,line1);
        getline(cin,line2);
        istringstream l1(line1),l2(line2);
        int x1,y1,x2,y2;
        size_t sum(1);
        SQ *p1,*p2;
        vector<SQ> SQvec1,SQvec2;
        l1>>x1>>y1;
        l2>>x2>>y2;
        p1=new SQ;
        p2=new SQ;
        p1->insert(x1,y1);
        p2->insert(x2,y2);
        SQvec1.push_back(*p1);
        SQvec2.push_back(*p2);
        int k,j;
        bool fail;
        for(j=1; j<n; ++j)
        {
            l1>>x1>>y1;
            l2>>x2>>y2;
            fail=0;
            for(k=0;k<sum;k++)
            {
                if((SQvec1[k].isn(x1,y1)==1)&&(SQvec2[k].isn(x2,y2)==1))
                {
                    SQvec1[k].insert(x1,y1);
                    SQvec2[k].insert(x2,y2);
                    break;
                }
                if(!((SQvec1[k].isn(x1,y1)==0)&&(SQvec2[k].isn(x2,y2)==0)))
                    fail=1;
            }
            if(fail==1)
                break;
            else
            {
                p1=new SQ;
                p2=new SQ;
                p1->insert(x1,y1);
                p2->insert(x2,y2);
                SQvec1.push_back(*p1);
                SQvec2.push_back(*p2);
                ++sum;
            }
        }
        if(j<n)
            cout<<"NO"<<endl;
        else
        {
            for(k=0;k<sum;++k)
                if(!(SQvec1[k]==SQvec2[k]))
                    break;
            if(k<sum)
                cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}
