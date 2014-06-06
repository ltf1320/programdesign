#include<stdio.h>
#include<string.h>
#include<cstdlib>
#include<time.h>
char base64EncodeChars[80] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
int base64DecodeChars[128] = {
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1, 63,
52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, 64, -1, -1,
-1,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1,
-1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1};
char str_buf[1000000];
int value_base64[4];
int value_str[4];
bool str2base64(void);
bool base642str(void);
int main()
{
    freopen("in.txt","r",stdin);
    int testcase=1;
    char cmd[8];
    char desc[256],infile[256], outfile[256];
        //freopen("data/1in.in","r",stdin);
    //freopen("data/out.out","w",stdout);
    //freopen("io.ini","r",stdin);
    //gets(desc);
    //gets(infile);
    //gets(desc);
    //gets(outfile);
    //freopen(infile, "r", stdin);
    //freopen(outfile, "w", stdout);
    while(1)
    {
        //printf("input cmd:");
        gets(cmd);
        //printf("input code:");
        if (strcmp(cmd,"#exit#")==0)break;
        printf("Case #%d\n", testcase++);

            if(strcmp(cmd,"#b2s#")==0)
            base642str();
            //printf("#############b2s\n");
            else if(strcmp(cmd,"#s2b#")==0)
            str2base64();
            //printf("#############s2b\n");

    }
    return 0;
}
bool str2base64(void)
{
    int pos,len,fillcnt;

    while(true)
    {
        gets(str_buf);
        if(!strcmp(str_buf,"#CaseEnd#"))break;
        len=strlen(str_buf);
        if((len%3)!=0)
        {
            if((len%3)==1)
            {
                strcat(str_buf,"**");
                str_buf[len]=0;
                str_buf[len+1]=0;
                len+=2;
            }
            else
            {
                strcat(str_buf,"*");
                str_buf[len]=0;
                len++;
            }
    }
    pos=0;
    while(pos<len)
    {
        if(pos!=0&&pos%57==0)printf("\n");

        value_str[0] = str_buf[pos++];
        value_str[1] = str_buf[pos++];
        value_str[2] = str_buf[pos++];

        value_base64[0] = (value_str[0] & 0xfc) >> 2;
        value_base64[1] = ((value_str[0] & 0x03) << 4) ^ ((value_str[1] & 0xf0) >> 4);

        if (value_str[1]!=0)
            value_base64[2] = ((value_str[1] & 0x0f) << 2) ^ ((value_str[2] & 0xc0) >> 6);
        else
            value_base64[2] = 64;

        if (value_str[2]!=0)
            value_base64[3] = (value_str[2] & 0x3f);
        else
            value_base64[3] = 64;

        //printf("%d, %d, %d, %d\n", value_base64[0], value_base64[1], value_base64[2], value_base64[3]);
        printf("%c",base64EncodeChars[value_base64[0]]);
        printf("%c",base64EncodeChars[value_base64[1]]);
        printf("%c",base64EncodeChars[value_base64[2]]);
        printf("%c",base64EncodeChars[value_base64[3]]);
    }
}
    //gets(str_buf);
    printf("\n");
    return true;
}
bool base642str(void)
{
    int pos,len;

    while(true)
    {
        gets(str_buf);
        if(str_buf[0]=='#')break;
        len=strlen(str_buf);
        if((len%4)!=0)return false;
        pos=0;
        while(pos<len)
        {
            value_base64[0] = base64DecodeChars[str_buf[pos++]];
            value_base64[1] = base64DecodeChars[str_buf[pos++]];
            value_base64[2] = base64DecodeChars[str_buf[pos++]];
            value_base64[3] = base64DecodeChars[str_buf[pos++]];
            //pos+=4;

            value_str[0] = ((value_base64[0] & 0x3f) << 2) ^ ((value_base64[1] & 0x30) >> 4);
            if (value_base64[2] != 64)
            {
                value_str[1] = ((value_base64[1] & 0x0f) << 4) ^ ((value_base64[2] & 0x3c) >> 2);
            }else
            {
                value_str[1] = 0;
            }
            if (value_base64[3] != 64)
            {
                value_str[2] = ((value_base64[2] & 0x03) << 6) ^ ((value_base64[3] & 0x3f));
            }else
            {
                value_str[2] = 0;
            }
            //printf("%d %d %d\n",value_str[0],value_str[1],value_str[2]);
            printf("%c",value_str[0]);
            if(value_str[1]!=0)printf("%c",value_str[1]);
            if(value_str[2]!=0)printf("%c",value_str[2]);
        }
    }
    printf("\n");
    //printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
    return true;
}
