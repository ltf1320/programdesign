#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
const int n=4;
int used[1500];
int usednum=0;
int main()
{
    string num;
    ostringstream out;
    istringstream in;
    cin>>num;
    cout<<num;
    int num1,num2;
    char ch;
    while(1)
    {
        for(int i=0;i<n;++i)
            for(int j=i+1;j<n;++j)
                if(num[i]<num[j])
                {
                    ch=num[j];
                    num[j]=num[i];
                    num[i]=ch;
                }
        in.clear();
		in.str("");  //,clear() 只设置流的状态，不清空缓存
        in.str(num);
        in>>num1;
        for(int i=0;i<n/2;++i)
        {
            ch=num[i];
            num[i]=num[n-i-1];
            num[n-i-1]=ch;
        }
        in.clear();
		in.str("");
        in.str(num);
        in>>num2;
/*        cout<<num2<<endl;
        system("pause");
*/

        num1-=num2;

/*        cout<<num1<<" "<<num2<<endl;
        system("pause");
*/
        bool end=0;
        for(int i=0;i<usednum;++i)
            if(used[i]==num1)
            {
                end=1;
                break;
            }
        if(end) break;
        used[usednum++]=num1;
        out.clear();
		out.str("");
        out<<num1;
        num=out.str();
        cout<<"->"<<num1;
    }
    return 0;
}
