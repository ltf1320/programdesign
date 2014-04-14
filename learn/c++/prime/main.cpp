#include<iostream>
#include   <vector>
using namespace std;

int main()
{

    int newBF;

    int oldBF;

    int t;

    int search;

    int max;

    cout<<"输入男生人数（女生）："<<endl;
    cin>>max;

    int   *nextm=new   int[max+1];  //男生下个追求女士的号码

    int   *nextw=new   int[max+1];//女士接受的男生号

    vector<vector<int>   >   man(max,   vector<int>(max));//男生对女士的喜欢程度顺序

    vector<vector<int>   >   woman(max,   vector<int>(max+1));//女生对男生的喜欢程度顺序

    for(int i=0; i<max+1; i++)///

        nextm[i]=0;

    for(int i=0; i<max; i++)

        nextw[i]=max;//对数组初始

    for(int i=0; i<max; i++)

    {

        cout<<"第"<<i<<"位男士喜欢女生顺序为："<<endl;

        for(int j=0; j<max; j++)

            cin>>man[i][j];

    }

    for(int i=0; i<max; i++)

    {

        cout<<"第"<<i<<"位女士喜欢男生顺序为："<<endl;

        for(int j=0; j<max; j++)

            cin>>woman[i][j];

        woman[i][max]=max;
    }
    bool changeBF(vector<vector<int>   > woman,int,int,int,int);
    for(int j=0; j<max; j++)
    {
        t=man[j][nextm[j]];//要追求的女生号
        if(nextw[t]==j)
        {
            //什么也不做
        }
        else
        {
            newBF=j;
            oldBF=nextw[t];
            if(changeBF(woman,t,newBF,oldBF,max))
            {
                nextm[oldBF]++;
                nextw[t]=newBF;
                if(oldBF>j)
                {
//什么也不做
                }
                else
                {
                    j=oldBF;//前任男友被抛弃，且号码小，应让其重新最求女生
                    j--;
                }
            }
            else
            {
                nextm[j]++;//最求不成功，继续追求下一位喜欢的女生
                j--;
            }
        }
    }
    for(int  j=0; j<max; j++)
    {
        cout<<"第"<<j<<"位男士"<<"的女友是"<<man[j][nextm[j]]<<endl;
    }
}
bool changeBF(vector<vector<int>   > woman,int i,int newBF,int oldBF,int max)
{
    int temp1;
    int temp2;
    for(int j=0; j<=max; j++)
    {
        if(woman[i][j]==newBF)
        {
            temp1=j;
            break;
        }
    }

    for(int j=0; j<=max; j++)

    {

        if(woman[i][j]==oldBF)

        {

            temp2=j;
            break;

        }
    }

    return(temp1<temp2);//比较前任与现任的排序先后
}
