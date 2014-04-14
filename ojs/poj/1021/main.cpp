#include <iostream>

using namespace std;

class Grid
{
public:
    grid(int W_,int H_,int n):W(W_),H(H_)
    {
        for(int i=0; i<H; i++)
            for(int j=0; j<W; j++)
                gir[i][j]=0;
        int xi,yi;
        for(int i=0; i<n; i++)
        {
            cin>>yi>>xi;
            gir[yi][xi]=i;
        }
    };

private:
    int gir[100][100];
    int W,H;
};

int main()
{
    int t,W,H,n;
    cin>>t
    for(i=0; i<t; i++)
    {
        cin>>W>>H>>n;
        Grid grid1(W,H,n);
        Grid grid2(W,H,n);

    }
    return 0;
}
