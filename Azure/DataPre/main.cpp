#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
const int NullV=-10000;
const int Data_Size=2204;
using namespace std;


char diremu[10][20]= {"NULL","East", "West", "South", "North", "Southeast", "Northeast", "Southwest", "Northwest" };
char weaemu[10][20]= {"NULL","Snowy", "Cloudy", "Sunny", "Overcast", "Rainy", "Foggy", "Dusty" };


char ids[10][5]= {"0231","0302","0033","0003","0200","2112","3023","2131","2121"};
const char* idpre="30132212";


void getAValue(char *&ori,char *res)
{
    int i=0;
    while(*ori!=','&&*ori!='\n')
    {
        res[i++]=*ori;
        ori++;
    }
    ori++;
    res[i]=0;
}

struct MetaData
{
    char time[20];
    int AQI;
    int temp;
    int pressure;
    int humidity;
    double windSpeed;
    int windDirection;
    int weather;

    char* read(FILE *fp)
    {
        char tmp[20];
        char line[100];
        do
        {
            char* res=fgets(line,100,fp);
            if(res==NULL)
                return NULL;
        }
        while(line[0]=='\n');
        char *now=line;

        getAValue(now,time); //Date
        getAValue(now,tmp);//AQI;
        if(!strcmp(tmp,"NULL"))
            AQI=NullV;
        else sscanf(tmp,"%d",&AQI);

        getAValue(now,tmp);//temperature
        if(!strcmp(tmp,"NULL"))
            temp=NullV;
        else sscanf(tmp,"%d",&temp);

        getAValue(now,tmp);//presure;
        if(!strcmp(tmp,"NULL"))
            pressure=NullV;
        else sscanf(tmp,"%d",&pressure);

        getAValue(now,tmp);//humidity
        if(!strcmp(tmp,"NULL"))
            humidity=NullV;
        else sscanf(tmp,"%d",&humidity);

        getAValue(now,tmp);//wind speed
        if(!strcmp(tmp,"NULL"))
            windSpeed=NullV;
        else sscanf(tmp,"%lf",&windSpeed);

        getAValue(now,tmp);//wind direction
        for(int i=0; i<9; i++)
            if(!strcmp(tmp,diremu[i]))
            {
                windDirection=i;
                break;
            }

        getAValue(now,tmp);//weather
        for(int i=0; i<8; i++)
            if(!strcmp(tmp,weaemu[i]))
            {
                weather=i;
                break;
            }
        return now;
    }
    void print()
    {
        printf("AQI:%d\n",AQI);
        printf("temperatrue:%d\n",temp);
        printf("pressure:%d\n",pressure);
        printf("humidity:%d\n",humidity);
        printf("wind speed:%f\n",windSpeed);
        printf("wind direction:%d\n",windDirection);
        printf("weather:%d\n",weather);
    }
    void evaluateWindSpeed()
    {
        if(windSpeed<19)
            windSpeed=3;
        else if(windSpeed<20)
            windSpeed=3.5;
        else if(windSpeed<28)
            windSpeed=4;
        else if(windSpeed<29)
            windSpeed=4.5;
        else
            windSpeed=5;
    }
};

vector<MetaData> getData(const char *dir,const char *id)
{
    char fileName[100];
    strcpy(fileName,dir);
    strcat(fileName,idpre);
    strcat(fileName,id);
    strcat(fileName,".csv");
    FILE *fp=fopen(fileName,"r");
    vector<MetaData> res;
    MetaData tmp;
    while(tmp.read(fp)!=NULL)
    {
        res.push_back(tmp);
    }
    return res;
}

vector<MetaData> data[10];

void getAllTrainingData()
{
    for(int i=0; i<9; i++)
    {
        data[i]=getData("TrainingData\\",ids[i]);
    }
}

void getAllTestData()
{
    for(int i=0; i<9; i++)
    {
        data[i]=getData("TestData\\",ids[i]);
    }
}

bool checkNull()
{
    for(int i=0; i<9; i++)
        for(int j=0; j<(int)data[i].size(); j++)
        {
            if(data[i][j].AQI==NullV)
            {
                for(int k=0; k<9; k++)
                {
                    if(data[k][j].AQI!=NullV)
                    {
                        printf("nullStation:%d\n",i);
                        printf("notNullStation:%d\n",k);
                        printf("line:%d\n",j);
                        //           return false;
                    }
                }
            }
        }
    return true;
}

void fillNullAQI()
{
    for(int i=0; i<9; i++)
        for(int j=0; j<(int)data[i].size(); j++)
        {
            if(data[i][j].AQI==NullV)
            {
                int cnt=0;
                int sum=0;
                for(int k=0; k<9; k++)
                {
                    if(data[k][j].AQI!=NullV)
                    {
                        //     printf("nullStation:%d\n",i);
                        //     printf("notNullStation:%d\n",k);
                        //     printf("line:%d\n",j);
                        sum+=data[k][j].AQI;
                        cnt++;
                    }
                }
                if(cnt>0)
                {
                    data[i][j].AQI=sum/cnt;
                }
            }
        }
}

bool checkUseData(int start)
{
    if(start+16>Data_Size)
    {
        return false;
    }
    for(int i=0; i<4; i++) // temperature and follows are null
    {
        if(data[0][start+i].temp==NullV)
            return false;
    }
    int cnt=0;
    for(int i=4; i<16; i++) //
    {
        if(data[0][start+i].AQI==NullV)
        {
            cnt++;
        }
    }
    if(cnt>6) return false;
    return true;
}

void outputTrainingData()
{
    FILE *XFile,*YFile;
    XFile=fopen("dataX.txt","w");
    YFile=fopen("dataY.txt","w");
    for(int i=0; i<2208-4; i++)
    {
        int XCnt=0;
        if(checkUseData(i))
        {
            for(int st=0; st<9; st++)
            {
                for(int j=0; j<4; j++)
                {
                    if(data[st][i+j].AQI==NullV)
                        fprintf(XFile,"%f,",2.5);
                    else
                        fprintf(XFile,"%d,",data[st][i+j].AQI);
                    XCnt++;
                    fprintf(XFile,"%d,",data[st][i+j].temp);
                    XCnt++;
                    fprintf(XFile,"%d,",data[st][i+j].pressure);
                    XCnt++;
                    fprintf(XFile,"%d,",data[st][i+j].humidity);
                    XCnt++;
                    fprintf(XFile,"%f,",data[st][i+j].windSpeed);
                    XCnt++;
                    fprintf(XFile,"%d,",data[st][i+j].windDirection);
                    XCnt++;
                    fprintf(XFile,"%d,",data[st][i+j].weather);
                    XCnt++;
                }
            }
            int dircnt[10];
            memset(dircnt,0,sizeof(dircnt));
            int weacnt[10];
            memset(weacnt,0,sizeof(weacnt));
            for(int st=0; st<9; st++)
            {
                int n0=0,n1=0,n2=0;
                int cnt=0;
                double tsum=0,psum=0,hsum=0,wsum=0;
                for(int j=4; j<16; j++)
                {
                    if(data[st][i+j].AQI==NullV)
                        ;
                    else if(data[st][i+j].AQI<=1)
                        n0++;
                    else if(data[st][i+j].AQI==2)
                        n1++;
                    else
                        n2++;
                    if(data[st][i+j].temp!=NullV)
                    {
                        cnt++;
                        tsum+=data[st][i+j].temp;
                        psum+=data[st][i+j].pressure;
                        hsum+=data[st][i+j].humidity;
                        wsum+=data[st][i+j].windSpeed;
                    }
                    //      int t=data[st][i+j].windDirection;
                    dircnt[data[st][i+j].windDirection]++;
                    weacnt[data[st][i+j].weather]++;
                }
                int sum=n0+n1+n2;
                fprintf(YFile,"%f,%f,%f",(n0+0.0)/sum,(n1+0.0)/sum,(n2+0.0)/sum);
                if(st!=8)
                    fprintf(YFile,",");

                MetaData tmp;
                tmp.windSpeed=wsum/cnt;
                tmp.evaluateWindSpeed();
                fprintf(XFile,"%f,%f,",tsum/cnt,tmp.windSpeed);
                XCnt+=2;
                int mostDir=0,mostWea=0;
                for(int i=1; i<9; i++)
                    if(dircnt[i]>dircnt[mostDir])
                        mostDir=i;
                for(int i=1; i<8; i++)
                    if(weacnt[i]>weacnt[mostWea])
                        mostWea=i;
                fprintf(XFile,"%d,%d,",mostDir,mostWea);
                XCnt+=2;
                //              if(st!=8)
                //                  fprintf(XFile,",");
            }
            int y,m,d,h;
            sscanf(data[0][i].time,"%d-%d-%d %d",&y,&m,&d,&h);
            fprintf(XFile,"%d\n",h);
            fprintf(YFile,"\n");
        }
    }
}


void outputTrainingData_6cls()
{
    FILE *XFile,*YFile;
    XFile=fopen("dataX.txt","w");
    YFile=fopen("dataY.txt","w");
    for(int i=0; i<2208-4; i++)
    {
        int XCnt=0;
        if(checkUseData(i))
        {
            for(int st=0; st<9; st++)
            {
                for(int j=0; j<4; j++)
                {
                    if(data[st][i+j].AQI==NullV)
                        fprintf(XFile,"%f,",2.5);
                    else
                        fprintf(XFile,"%d,",data[st][i+j].AQI);
                    XCnt++;
                    fprintf(XFile,"%d,",data[st][i+j].temp);
                    XCnt++;
                    fprintf(XFile,"%d,",data[st][i+j].pressure);
                    XCnt++;
                    fprintf(XFile,"%d,",data[st][i+j].humidity);
                    XCnt++;
                    fprintf(XFile,"%f,",data[st][i+j].windSpeed);
                    XCnt++;
                    fprintf(XFile,"%d,",data[st][i+j].windDirection);
                    XCnt++;
                    fprintf(XFile,"%d,",data[st][i+j].weather);
                    XCnt++;
                }
            }
            int dircnt[10];
            memset(dircnt,0,sizeof(dircnt));
            int weacnt[10];
            memset(weacnt,0,sizeof(weacnt));
            for(int st=0; st<9; st++)
            {
                int AqiT[10];
                memset(AqiT,0,sizeof(AqiT));
                int cnt=0;
                double tsum=0,psum=0,hsum=0,wsum=0;
                for(int j=4; j<16; j++)
                {
                    if(data[st][i+j].AQI==NullV)
                        ;
                    else AqiT[data[st][i+j].AQI]++;
                    if(data[st][i+j].temp!=NullV)
                    {
                        cnt++;
                        tsum+=data[st][i+j].temp;
                        psum+=data[st][i+j].pressure;
                        hsum+=data[st][i+j].humidity;
                        wsum+=data[st][i+j].windSpeed;
                    }
                    //      int t=data[st][i+j].windDirection;
                    dircnt[data[st][i+j].windDirection]++;
                    weacnt[data[st][i+j].weather]++;
                }
       //         int sum=n0+n1+n2;
       //         fprintf(YFile,"%f,%f,%f",(n0+0.0)/sum,(n1+0.0)/sum,(n2+0.0)/sum);
                int mostA=0;
                for(int i=1;i<6;i++)
                    if(AqiT[i]>AqiT[mostA])
                        mostA=i;
                fprintf(YFile,"%d",mostA);
                if(st!=8)
                    fprintf(YFile,",");

                MetaData tmp;
                tmp.windSpeed=wsum/cnt;
                tmp.evaluateWindSpeed();
                fprintf(XFile,"%f,%f,",tsum/cnt,tmp.windSpeed);
                XCnt+=2;
                int mostDir=0,mostWea=0;
                for(int i=1; i<9; i++)
                    if(dircnt[i]>dircnt[mostDir])
                        mostDir=i;
                for(int i=1; i<8; i++)
                    if(weacnt[i]>weacnt[mostWea])
                        mostWea=i;
                fprintf(XFile,"%d,%d,",mostDir,mostWea);
                XCnt+=2;
                //              if(st!=8)
                //                  fprintf(XFile,",");
            }
            int y,m,d,h;
            sscanf(data[0][i].time,"%d-%d-%d %d",&y,&m,&d,&h);
            fprintf(XFile,"%d\n",h);
            fprintf(YFile,"\n");
        }
    }
}



void outputTestData()
{
    FILE *XFile;
    XFile=fopen("dataX_test.txt","w");
    for(int st=0; st<9; st++)
    {
        int XCnt=0;
        for(int i=0; i<(int)data[0].size(); i+=5)
        {
            for(int j=0; j<4; j++)
            {
                if(data[st][i+j].AQI==NullV)
                    fprintf(XFile,"%f,",2.5);
                else
                    fprintf(XFile,"%d,",data[st][i+j].AQI);
                XCnt++;
                fprintf(XFile,"%d,",data[st][i+j].temp);
                XCnt++;
                fprintf(XFile,"%d,",data[st][i+j].pressure);
                XCnt++;
                fprintf(XFile,"%d,",data[st][i+j].humidity);
                XCnt++;
                fprintf(XFile,"%f,",data[st][i+j].windSpeed);
                XCnt++;
                fprintf(XFile,"%d,",data[st][i+j].windDirection);
                XCnt++;
                fprintf(XFile,"%d,",data[st][i+j].weather);
                XCnt++;
            }
            fprintf(XFile,"%d,",data[st][i+4].temp);
            XCnt++;
            fprintf(XFile,"%f,",data[st][i+4].windSpeed);
            XCnt++;
            fprintf(XFile,"%d,",data[st][i+4].windDirection);
            XCnt++;
            fprintf(XFile,"%d,",data[st][i+4].weather);
            XCnt++;
            int y,m,d,h;
            sscanf(data[st][i].time,"%d-%d-%d %d",&y,&m,&d,&h);
            fprintf(XFile,"%d\n",h);
        }
    }
}

void evaluateTrainingWindSpeed()
{
    for(int st=0; st<9; st++)
        for(int i=0; i<(int)data[0].size(); i++)
        {
            data[st][i].evaluateWindSpeed();
        }
}

void evaluateTestWindSpeed()
{
    for(int st=0; st<9; st++)
        for(int i=0; i<(int)data[0].size(); i++)
        {
            if(i%5!=4)
                data[st][i].evaluateWindSpeed();
        }
}

void formatAns()
{
    FILE *AFile=fopen("result.txt","r");
    char dir[20]="result\\";
    for(int st=0; st<9; st++)
    {
        char fileName[100];
        strcpy(fileName,dir);
        strcat(fileName,idpre);
        strcat(fileName,ids[st]);
        strcat(fileName,".csv");
        FILE* fp=fopen(fileName,"w");
        for(int i=4; i<(int)data[0].size(); i+=5)
        {
            int y,m,d,h;
            sscanf(data[0][i-1].time,"%d-%d-%d %d",&y,&m,&d,&h);
            if(h==23)
            {
                d++;
                h=0;
            }
            else h++;
            double a,b,c;
            fscanf(AFile,"%lf %lf %lf",&a,&b,&c);
            fprintf(fp,"%d-%02d-%02d %02d,%.3f,%.3f,%.3f\n\n",y,m,d,h,a,b,c);
        }
    }
}


void outputResult()
{
    FILE *AFile=fopen("result.txt","r");
    char dir[20]="resultView\\";
    for(int st=0; st<9; st++)
    {
        char fileName[100];
        strcpy(fileName,dir);
        strcat(fileName,idpre);
        strcat(fileName,ids[st]);
        strcat(fileName,".csv");
        FILE* fp=fopen(fileName,"w");
        int XCnt=0;
        for(int i=4; i<(int)data[0].size(); i+=5)
        {
            for(int j=0; j<4; j++)
            {
                fprintf(fp,"%s,",data[st][i-4+j].time);
                if(data[st][i-4+j].AQI==NullV)
                    fprintf(fp,"%d,",-1);
                else
                    fprintf(fp,"%d,",data[st][i-4+j].AQI);
                XCnt++;
                fprintf(fp,"%d,",data[st][i-4+j].temp);
                XCnt++;
                fprintf(fp,"%d,",data[st][i-4+j].pressure);
                XCnt++;
                fprintf(fp,"%d,",data[st][i-4+j].humidity);
                XCnt++;
                fprintf(fp,"%f,",data[st][i-4+j].windSpeed);
                XCnt++;
                fprintf(fp,"%s,",diremu[data[st][i-4+j].windDirection]);
                XCnt++;
                fprintf(fp,"%s\n",weaemu[data[st][i-4+j].weather]);
                XCnt++;
            }
            int y,m,d,h;
            sscanf(data[0][i-1].time,"%d-%d-%d %d",&y,&m,&d,&h);
            if(h==23)
            {
                d++;
                h=0;
            }
            else h++;
            double a,b,c;
            fscanf(AFile,"%lf %lf %lf",&a,&b,&c);
            fprintf(fp,"%d-%02d-%02d %02d,%.3f,%.3f,%.3f\n\n",y,m,d,h,a,b,c);
        }
    }
}

int checkDate()
{
    int cnt=0;
    for(int st =1; st<9; st++)
    {
        if(st==2)
            continue;
        for(int i=0; i<(int)data[st].size(); i++)
        {
            if(strcmp(data[st][i].time,data[0][i].time))
            {
                //  return false;
                //           cout<<st<<" "<<i<<endl;
                //         cout<<data[st][i].time<<endl;
                //       cout<<data[0][i].time<<endl;
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{

    getAllTrainingData();
    fillNullAQI();
    //  evaluateTrainingWindSpeed();

   // outputTrainingData();

    outputTrainingData_6cls();
/*
    getAllTestData();
    //   evaluateTestWindSpeed();
    outputTestData();

        getAllTestData();
          formatAns();
        outputResult();

    //  getAllTestData();
//   cout<<checkDate()<<endl;
  */
    return 0;

}
