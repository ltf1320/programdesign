#include <iostream>

using namespace std;

int main()
{
    char arrch[100][100];
    int arr[100][100];
    int step;
    size_t nx,ny;
    size_t height,weight,inpoint;
    cin>>height>>weight>>inpoint;
    while(height||weight||inpoint)
    {
        for(size_t i=0;i!=height;++i)
            for(size_t j=0;j!=weight;++j)
                cin>>arrch[i][j];
        nx=inpoint-1;ny=0;step=0;
        for(size_t i=0;i!=height;++i)
            for(size_t j=0;j!=weight;++j)
                arr[i][j]=0;
        step=0;
        while(1)
        {
            ++step;
            arr[ny][nx]=step;
            switch(arrch[ny][nx])
            {
                case 'N':
                    ny-=1;
                    break;
                case 'S':
                    ny+=1;
                    break;
                case 'E':
                    nx+=1;
                    break;
                case 'W':
                    nx-=1;
                    break;
            }
            if(nx<0||nx>=weight||ny<0||ny>=height)
            {
                cout<<step<<" step(s) to exit"<<endl;
                break;
            }
            if(arr[ny][nx]!=0)
            {
                cout<<arr[ny][nx]-1<<" step(s) before a loop of "<<step-arr[ny][nx]+1<<" step(s)"<<endl;
                break;
            }
        }
        cin>>height>>weight>>inpoint;
    }
    return 0;
}
