#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

class Screen
{
    public:
        friend class X;
        Screen(const Screen&){};
        explicit Screen():num(0),price(0){};
        explicit Screen(int num_,double price_,std::string name_):num(num_),price(price_),name(name_){};
        const Screen& print() const
        {
            printtime++;
            return *this;
        }
    private:
        mutable size_t printtime;
        int num;
        double price;
        std:: string name;
};

class X
{
    public:
        X():a(0){};
        void print(){std::cout<<scr.price<<std::endl;}
    private:
        int a;
        Screen scr;
};
#endif // SCREEN_H_INCLUDED
