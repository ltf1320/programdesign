#include <iostream>
#include <cstdio>
#include <cstring>
#include <windows.h>
#include <io.h>
#include <fstream>
using namespace std;



int main()
{
    FILE *fp=NULL,*rp=NULL;
    char filepath[100]="F:\\1.bmp";
    fp=fopen(filepath,"rb");
    if(fp==NULL)
    {
        cout<<"open file error"<<endl;
        return -1;
    }
    int num1=0,num2=0,size;
    int ch;
    rp=fopen("F:\\test\\2.bmp","wb");
    cout<<fileno(fp)<<endl;

    while(true)
    {
        ch=fgetc(fp);
        if(ch==EOF)
            break;
        fputc(ch,rp);
        num1++;
    }
    fclose(rp);
    rp=NULL;
    cout<<num1<<endl;


    size=filelength(fileno(fp));
    cout<<size<<endl;

    fseek(fp,0,SEEK_SET);
    rp=fopen("F:\\test\\3.bmp","wb");
    char buf[256];
    while(true)
    {
        int kk=fread(buf,1,256,fp);
        num2+=kk;
        if(kk==0)
            break;
        fwrite(buf,1,kk,rp);
    }
    cout<<num2<<endl;
    fclose(rp);
    rp=NULL;

    HANDLE handle = CreateFile(filepath, FILE_READ_EA, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
    if (handle != INVALID_HANDLE_VALUE)
    {
        int size = GetFileSize(handle, NULL);
        cout<<size<<endl;
        CloseHandle(handle);
    }

    ifstream in;
    ofstream out;
    in.open(filepath,ios_base::binary);
    out.open("F:\\test\\4.bmp",ios_base::binary);
    int num3(0);
    while(in.read(buf,256))
    {
        num3+=256;
        out.write(buf,256);
    }
    out.write(buf,256);
    cout<<num3<<endl;
    in.close();
    out.close();
    return 0;
}
