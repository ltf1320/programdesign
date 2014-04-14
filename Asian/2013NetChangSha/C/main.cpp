#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const double err=1E-8;
struct HSV;
struct HSL;


double mod2(double a)
{
    int fl=(int)a;
    int kn=fl%2;
    double res=kn+(a-fl);
    return res;
}

bool compare(double a,double b)
{
    if(abs(a-b)<err)
        return true;
    return false;
}
/*
int round(double a)
{
    int fl=(int)a;
    double xs=a-fl;
    if(xs<0.5)
        return fl;
    else return fl+1;
}
*/
struct RGB
{
    double r,g,b;
    HSV toHSV();
    HSL toHSL();
    void read()
    {
        int nr,ng,nb;
        scanf("%d %d %d",&nr,&ng,&nb);
        r=nr;
        g=ng;
        b=nb;
    }
    void print()
    {
        printf("RGB %d %d %d\n",(int)round(r),(int)round(g),(int)round(b));
    }
};

struct HSV
{
    double h;
    double s,v;
    RGB toRGB();
    void print()
    {
        int nh=(int)round(h);
        if(nh==360) nh=0;
        printf("HSV %d %d%% %d%%\n",nh,(int)round(s*100),(int)round(v*100));
    }
    void read()
    {
        int nh,ns,nv;
        scanf("%d %d%% %d%%",&nh,&ns,&nv);
        h=nh;
        s=1.0*ns/100;
        v=1.0*nv/100;
    }
};

struct HSL
{
    double h;
    double s,l;
    void print()
    {
        int nh=(int)round(h);
        if(nh==360) nh=0;
        printf("HSL %d %d%% %d%%\n",nh,(int)round(s*100),(int)round(l*100));
    }
    void read()
    {
        int nh,ns,nl;
        scanf("%d %d%% %d%%",&nh,&ns,&nl);
        h=nh;
        s=1.0*ns/100;
        l=1.0*nl/100;
    }
    RGB toRGB();
};

RGB HSV::toRGB()
{
    RGB res;
    double hh=h/60.0;
    double c=v*s;
    double x=c*(1-abs(mod2(hh)-1));
    double m=v-c;
    switch((int)hh)
    {
        case 6:
        case 0:res.r=255*(c+m);res.g=255*(x+m);res.b=255*m;break;
        case 1:res.r=255*(x+m);res.g=255*(c+m);res.b=255*m;break;
        case 2:res.r=255*m;res.g=255*(c+m);res.b=255*(x+m);break;
        case 3:res.r=255*m;res.g=255*(x+m);res.b=255*(c+m);break;
        case 4:res.r=255*(x+m);res.g=255*m;res.b=255*(c+m);break;
        case 5:res.r=255*(c+m);res.g=255*m;res.b=255*(x+m);break;
    }
    return res;
}

RGB HSL::toRGB()
{
    RGB res;
    double c=(1-abs(2*l-1))*s;
    double hh=1.0*h/60.0;
    double x=c*(1-abs(mod2(hh)-1));
    double m=l-c/2;
    switch((int)hh)
    {
        case 6:
        case 0:res.r=255*(c+m);res.g=255*(x+m);res.b=255*m;break;
        case 1:res.r=255*(x+m);res.g=255*(c+m);res.b=255*m;break;
        case 2:res.r=255*m;res.g=255*(c+m);res.b=255*(x+m);break;
        case 3:res.r=255*m;res.g=255*(x+m);res.b=255*(c+m);break;
        case 4:res.r=255*(x+m);res.g=255*m;res.b=255*(c+m);break;
        case 5:res.r=255*(c+m);res.g=255*m;res.b=255*(x+m);break;
    }
    return res;
}

HSL RGB::toHSL()
{
    double mx=max(r,max(g,b));
    double mn=min(r,min(g,b));
    HSL res;
    if(compare(mx,mn))
        res.h=0;
    else if(compare(mx,r)&&g>=b)
        res.h=60.0*(g-b)/(mx-mn);
    else if(compare(mx,r)&&g<b)
        res.h=60.0*(g-b)/(mx-mn)+360;
    else if(compare(mx,g))
        res.h=60.0*(b-r)/(mx-mn)+120;
    else if(compare(mx,b))
        res.h=60.0*(r-g)/(mx-mn)+240;
    res.l=(1.0*mx/255+1.0*mn/255)/2;
    if(compare(mx+mn,0)||compare(mx,mn))
        res.s=0;
//    if(res.l<1.0/2+err)
    if(res.l<0.5)
        res.s=1.0*(mx-mn)/(mx+mn);
    else
        res.s=1.0*(mx-mn)/(2*255-(mx+mn));
    return res;
}

HSV RGB::toHSV()
{
    double mx=max(r,max(g,b));
    double mn=min(r,min(g,b));
    HSV res;
    if(compare(mx,mn))
        res.h=0;
    else if(compare(mx,r)&&g>=b)
        res.h=60.0*(g-b)/(mx-mn);
    else if(compare(mx,r)&&g<b)
        res.h=60.0*(g-b)/(mx-mn)+360;
    else if(compare(mx,g))
        res.h=60.0*(b-r)/(mx-mn)+120;
    else if(compare(mx,b))
        res.h=60.0*(r-g)/(mx-mn)+240;
    if(compare(mx,0))
        res.s=0;
    else res.s=1.0*(mx-mn)/mx;
    res.v=1.0*mx/255;
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    char to[10],now[10];
    RGB rgb;
    HSV hsv;
    HSL hsl;
    while(~scanf("%s",to))
    {
        scanf("%s",now);
        if(!strcmp(to,"RGB"))
        {
            if(!strcmp(now,"HSV"))
            {
                hsv.read();
                hsv.toRGB().print();
            }
            if(!strcmp(now,"HSL"))
            {
                hsl.read();
                hsl.toRGB().print();
            }
            if(!strcmp(now,"RGB"))
            {
                rgb.read();
                rgb.print();
            }
        }
        if(!strcmp(to,"HSL"))
        {
            if(!strcmp(now,"HSV"))
            {
                hsv.read();
                hsv.toRGB().toHSL().print();
            }
            if(!strcmp(now,"HSL"))
            {
                hsl.read();
                hsl.print();
            }
            if(!strcmp(now,"RGB"))
            {
                rgb.read();
                rgb.toHSL().print();
            }
        }
        if(!strcmp(to,"HSV"))
        {
            if(!strcmp(now,"HSV"))
            {
                hsv.read();
                hsv.print();
            }
            if(!strcmp(now,"HSL"))
            {
                hsl.read();
                hsl.toRGB().toHSV().print();
            }
            if(!strcmp(now,"RGB"))
            {
                rgb.read();
                rgb.toHSV().print();
            }
        }
    }
    return 0;
}
