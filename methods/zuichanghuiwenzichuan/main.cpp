#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    string line,l2;
    size_t change[1000],max=0;
    getline(cin,line);
    l2.resize(line.size());
    int z=0;          //���ڱ��l2�ĳ���
    for(size_t i=0;i!=line.size();++i)
        if(isalpha(line[i]))
        {
            l2[z]=line[i];
            change[z++]=i;
        }
    int i,j,x=0,y=0;
    for(i=0;i!=z;++i)
    {
        for(j=1;(i-j)>=0&&(i+j)<z;++j) //ע���еȺ�
            if(l2[i-j]!=l2[i+j])
                break;
        if((2*(j-1)+1)>max)   //ע����j-1
        {
            x=change[i-j+1];
            y=change[i+j-1];
            max=2*(j-1)+1;
        }
        for(j=1;(i-j)>=0&&((i+j)<z);++j)
            if(l2[i-j+1]!=l2[i+j])
                break;
        if((2*(j-1))>max)
        {
            x=change[i-j+2];
            y=change[i+j-1];
            max=2*(j-1);
        }
    }
    for(size_t k=x;k!=y+1;++k)
    {
        cout<<line[k];
    }
    cout<<endl;
    return 0;
}
