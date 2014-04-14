#include <iostream>
#include <stdexcept>
using namespace std;

class examclass
{
    public:
        friend examclass& operator+=(const examclass cl1,const examclass cl2);
        examclass(int val_=0,int* begin_=0,int* end_=0):val(val_),beg(begin_),arr(begin_),end(end_) {};
        examclass& operator++()
        {
            if(arr==end)
                throw runtime_error("ou of range");
            ++arr;
            return *this;
        }
        examclass operator++(int)
        {
            examclass tem(*this);
            ++*this;
            return tem;
        }
        int operator[](int i) {return beg[i];}
        void operator()(int i,int val){beg[i]=val;}
        bool operator==(const examclass cl){return cl.val==val;}
        int get_arr_val(){return *arr;}
        int* begin(){return beg;}
    private:
        examclass& operator=(const examclass cl){};
        int val;
        int *arr;
        int *beg;
        int *end;
};

examclass& operator+=(examclass cl1,const examclass cl2)
{
    cl1.val+=cl2.val;
    return cl1;
}

examclass operator+(const examclass cl1,const examclass cl2)
{
    examclass tem(cl1);
    cl1+=cl2;
    return tem;
}

int main()
{
    int a[100];
    for(int i=0;i<100;i++)
        a[i]=i;
    examclass cl(10,a,a+99);
    cl++;
    cout<<cl.get_arr_val()<<endl;
    ++cl;
    cout<<cl.get_arr_val()<<endl;
    cout<<cl[5]<<endl;
    cl(0,9);
    cout<<cl[0]<<endl;
    return 0;
}
