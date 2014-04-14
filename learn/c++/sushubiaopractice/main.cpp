#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    bool isn[100000]= {0};
    int pri[1000];
    int n;
    while(1)
    {
    cin>>n;
    isn[0]=isn[1]=1;
        for(int i=4; i<n; i+=2)
            isn[i]=1;
        int i,k;
        for(i=3,k=0; i<sqrt(n)+1; i+=2)
        {
            if(isn[i]==0)
            {
                pri[k++]=i;
                for(int s=2*i,j=i*i; j<n; j+=s)
                {
                    isn[j]=1;
                }
            }
        }
        for(; i<n; i+=2)
            if(isn[i]==0)
                pri[k++]=i;
        cout<<"sushu under "<<n<<" are:"<<endl;
        for(int j=0; j<k; ++j)
            cout<<pri[j]<<" ";
        cout<<endl;
    }
    return 0;
}
