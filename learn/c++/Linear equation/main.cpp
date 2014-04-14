#include <iostream>
using namespace std;

int main()
{
    double arr[100][100];
    size_t n;
    cout<<"please input the n"<<std::endl;
    cin>>n;
    cout<<"please input the arr "<<endl;
    for(size_t i=0;i!=n;++i)            //input
        for(size_t j=0;j!=n+1;++j)
        {
            std::cin>>arr[i][j];
        }
    for(size_t i=0;i!=n;++i)            //变成上三角
        for(size_t j=i+1;j!=n;++j)
        {
            double ki=arr[j][i]/arr[i][i];
            for(size_t k=i;k!=n+1;++k)
                arr[j][k]-=arr[i][k]*ki;
        }
//    arr[n-1][n]/=arr[n-1][n-1];
    for(int i=n-1;i!=-1;--i)         //计算，将结果储存在arr[i][n]
    {
        for(size_t j=n-1;j!=static_cast<size_t>(i);--j)
        {
            arr[i][j]*=arr[j][n];
            arr[i][n]-=arr[i][j];
        }
        arr[i][n]/=arr[i][i];
    }
    for(size_t i=0;i!=n;i++)        //output
        cout<<arr[i][n]<<endl;
    return 0;
}
