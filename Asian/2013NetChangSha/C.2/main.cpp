#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const double err=1E-8;
struct HSV;
struct HSL;

int mabs(int a)
{
    return a>0?a:-a;
}

double mabs(double a)
{
    return a>0?a:-a;
}

double mod2(double a)
{
    int fl=(int)a;
    int kn=fl%2;
    double res=kn+(a-fl);
    return res;
}

bool compare(double a,double b)
{
//   if(mabs(a-b)<err)
    if(a==b)
        return true;
    return false;
}

int mround(double a)
{
    int fl=(int)a;
    double xs=a-fl;
    if(xs<0.5)
        return fl;
    else return fl+1;
}

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
        int nh=round(h);
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
        int nh=round(h);
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
    int i;
    double f, p, q, t;

    if( s == 0 )
    {
        // achromatic (grey)
        res.r = res.g = res.b = v*255;
        return res;
    }

    h /= 60; // sector 0 to 5
    i = floor( h );
    f = h - i; // factorial part of h
    p = v * ( 1 - s );
    q = v * ( 1 - s * f );
    t = v * ( 1 - s * ( 1 - f ) );

    switch( i )
    {
    case 0:
        res.r = v;
        res.g = t;
        res.b = p;
        break;
    case 1:
        res.r = q;
        res.g =v;
        res.b = p;
        break;
    case 2:
        res.r = p;
        res.g = v;
        res.b = t;
        break;
    case 3:
        res.r = p;
        res.g = q;
        res.b = v;
        break;
    case 4:
        res.r = t;
        res.g = p;
        res.b = v;
        break;
    default: // case 5:
        res.r = v;
        res.g = p;
        res.b = q;
        break;
    }
    res.r*=255;
    res.g*=255;
    res.b*=255;
    return res;
}

RGB HSL::toRGB()
{
    RGB res;
    double c=(1-mabs(2*l-1))*s;
    double hh=1.0*h/60.0;
    double x=c*(1-mabs(mod2(hh)-1));
    double m=l-c/2;
    switch((int)hh)
    {
    case 6:
    case 0:
        res.r=255*(c+m);
        res.g=255*(x+m);
        res.b=255*m;
        break;
    case 1:
        res.r=255*(x+m);
        res.g=255*(c+m);
        res.b=255*m;
        break;
    case 2:
        res.r=255*m;
        res.g=255*(c+m);
        res.b=255*(x+m);
        break;
    case 3:
        res.r=255*m;
        res.g=255*(x+m);
        res.b=255*(c+m);
        break;
    case 4:
        res.r=255*(x+m);
        res.g=255*m;
        res.b=255*(c+m);
        break;
    case 5:
        res.r=255*(c+m);
        res.g=255*m;
        res.b=255*(x+m);
        break;
    default:
        res.r=255*m;
        res.g=255*m;
        res.b=255*m;
        break;
    }
    return res;
}

HSL RGB::toHSL()
{
    double var_R = ( r / 255 );
    double var_G = ( g / 255 );
    double var_B = ( b / 255 );

    double var_Min; //Min. value of RGB
    double var_Max; //Max. value of RGB
    double del_Max; //Delta RGB value

    if (var_R > var_G)
    {
        var_Min = var_G;
        var_Max = var_R;
    }
    else
    {
        var_Min = var_R;
        var_Max = var_G;
    }

    if (var_B > var_Max) var_Max = var_B;
    if (var_B < var_Min) var_Min = var_B;

    del_Max = var_Max - var_Min;

    double H = 0, S, L;
    L = ( var_Max + var_Min ) / 2;

    if ( del_Max == 0 )
    {
        H = 0;    // gray
        S = 0;
    }
    else   //Chroma
    {
        if ( L < 0.5 )
            S = del_Max / ( var_Max + var_Min );
        else
            S = del_Max / ( 2 - var_Max - var_Min );

        double del_R = ( ( ( var_Max - var_R ) / 6 ) + ( del_Max / 2 ) ) / del_Max;
        double del_G = ( ( ( var_Max - var_G ) / 6 ) + ( del_Max / 2 ) ) / del_Max;
        double del_B = ( ( ( var_Max - var_B ) / 6 ) + ( del_Max / 2 ) ) / del_Max;

        if ( var_R == var_Max )
            H = del_B - del_G;
        else if ( var_G == var_Max )
            H = ( 1 / 3.0 ) + del_R - del_B;
        else if ( var_B == var_Max )
            H = ( 2 / 3.0 ) + del_G - del_R;
        if ( H < 0 ) H += 1;
        if ( H > 1 ) H -= 1;
    }
    HSL res;
    res.h = 360*H;
    res.s = S;
    res.l = L;
    return res;
}

HSV RGB::toHSV()
{
    r/=255;
    g/=255;
    b/=255;
    HSV res;
    double mn, mx, delta,tmp;
    tmp = min(r, g);
    mn = min( tmp, b );
    tmp = max( r, g);
    mx = max(tmp, b );
    res.v = mx; // v

    delta = mx - mn;

    if( mx != 0 )
        res.s = delta / mx; // s
    else
    {
        // r = g = b = 0 // s = 0, v is undefined
        res.s = 0;
        res.h = 0;
        return res;
    }
    if( r == mx )
        res.h = ( g - b ) / delta; // between yellow & magenta
    else if( g == mx )
        res.h = 2 + ( b - r ) / delta; // between cyan & yellow
    else
        res.h = 4 + ( r - g ) / delta; // between magenta & cyan

    res.h *= 60; // degrees
    if( res.h < 0 )
        res.h += 360;
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
