#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int N;
enum Weather
{
    SUNNY=0,
    CLOUDY,
    RAINY
};

enum Wetness
{
    DRY=0,
    DRYISH,
    DAMP,
    SOGGY
};

const double Weather2Wetness[5][5]=
{
    {0.6,0.2,0.15,0.05},
    {0.25,0.3,0.2,0.25},
    {0.05,0.10,0.35,0.5}
};

const double Weather2Weather[5][5]=
{
    {0.5,0.375,0.125},
    {0.25,0.125,0.625},
    {0.25,0.375,0.375}
};



int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    char we[100];
    for(int cas=1; cas<=T; cas++)
    {
        printf("Case #%d:\n",cas);
        scanf("%d",&N);
        double ps=0.63,pc=0.17,pr=0.2;//³õÊ¼
        for(int i=0; i<N; i++)
        {
            scanf("%s",we);
            Wetness wet;
            if(!strcmp(we,"Dry"))
                wet=DRY;
            else if(!strcmp(we,"Dryish"))
                wet=DRYISH;
            else if(!strcmp(we,"Damp"))
                wet=DAMP;
            else if(!strcmp(we,"Soggy"))
                wet=SOGGY;
            double pwet;
    //        if(i)
            {
                double nps,npc,npr;
                nps=ps*Weather2Weather[SUNNY][SUNNY]+pc*Weather2Weather[CLOUDY][SUNNY]+pr*Weather2Weather[RAINY][SUNNY];
                npc=ps*Weather2Weather[SUNNY][CLOUDY]+pc*Weather2Weather[CLOUDY][CLOUDY]+pr*Weather2Weather[RAINY][CLOUDY];
                npr=ps*Weather2Weather[SUNNY][RAINY]+pc*Weather2Weather[CLOUDY][RAINY]+pr*Weather2Weather[RAINY][RAINY];
                ps=nps;
                pc=npc;
                pr=npr;

            }
      //      if(i)
            {
         //       ps=0.5,pc=0.5,pr=0;
          //      wet=DRYISH;
                pwet=ps*Weather2Wetness[SUNNY][wet]+pc*Weather2Wetness[CLOUDY][wet]+pr*Weather2Wetness[RAINY][wet];
                ps=ps/pwet*Weather2Wetness[SUNNY][wet];
                pc=pc/pwet*Weather2Wetness[CLOUDY][wet];
                pr=pr/pwet*Weather2Wetness[RAINY][wet];
      //          cout<<pwet<<endl;
      //          cout<<ps<<" "<<pc<<" "<<pr<<endl<<endl;
            }
            //         cout<<wet<<endl;
            cout<<pwet<<endl;
            cout<<ps<<" "<<pc<<" "<<pr<<endl<<endl;
            if(ps>pc&&ps>pr)
                printf("Sunny\n");
            else if(pc>ps&&pc>pr)
                printf("Cloudy\n");
            else printf("Rainy\n");

        }
    }
    return 0;
}
