#include <iostream>

using namespace std;

int main()
{
    int p,e,i,d;
    int m1,time(0);
    cin>>p>>e>>i>>d;
    while(!(p==-1&&e==-1&&i==-1&&d==-1))
    {
        ++time;
        p=p%23;
        e=e%28;
        i=i%33;
        m1=p;
        while(1)
        {
            m1+=23;
            if((m1%28==e)&&(m1%33==i)&&(m1!=d))
                break;
        }
        cout<<"Case "<<time<<": the next triple peak occurs in "<<m1-d<<" days."<<endl;
        cin>>p>>e>>i>>d;
    }
    return 0;
}
