#include <iostream>

using namespace std;

struct Queue
{
public:
    Queue(int n=0)
    {
        num=n;
		nc=n;
		head=end=front=back=NULL;
        reset(nc);
    }
    Queue(int a,int n):num(0),nc(0)
    {
        head=end=front=back=NULL;
        for(int i=0;i<n;++i)
            push(a);
    }
    bool push(int n)
    {
        if(back!=end)
        {
            *back=n;
			++back;
            ++num;
        }
        else
        {
            if(nc!=0)
                reset(nc*2);
            else reset(2);
            push(n);
        }
        return 1;
    }
    int get_front()
    {
        return *front;
    }
    int get_back()
    {
        return *(back-1);
    }
    int* begin()
    {
        return front;
    }
    int* last()
    {
        return back;
    }
	int size()
	{return num;}
    bool pop()
    {
        if(num>0)
        {
            front++;
            return 1;
        }
        else return 0;
    }
    int operator[](int i)
    {
        if(i<num)
            return *(head+i);
        else return NULL;
    }
    bool reset(int n)
    {
        int *k=new int[n];
        head=k;
        end=k+nc;
        int *f=front;
        front=k;
        back=front+num;
        int *p=front;
        for(int i=0;i<num;++i)
            *p++=*f++;
        delete [] f;
		nc=n;
        return 1;
    }
private:
    int num,nc;
    int *front;
    int *back;
    int *head;
    int *end;
};

int main()
{
    Queue queue(20,20);
    queue.push(5);
    queue.push(6);
    queue.push(7);
    for(int *i=queue.begin();i!=queue.last();++i)
        cout<<*i<<" ";
    return 0;
}
