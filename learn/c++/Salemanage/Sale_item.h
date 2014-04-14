#ifndef SALE_ITEM_H_INCLUDED
#define SALE_ITEM_H_INCLUDED

class Sale_item
{
    public:
        Sale_item():sold(0),revenue(0) {}
        bool input()
        {
            int price;
            if(std::cin>>isbn>>sold>>price)
            {
                revenue=price*sold;
                return 1;
            }
            else return 0;
        }
        void output()
        {
            std::cout<<isbn<<"  "<<sold<<"  "<<revenue<<std::endl;
        }
        bool issame(const Sale_item &item2)
        {
            return isbn==item2.isbn;
        }
        bool add(const Sale_item &item2)
        {
            if(issame(item2))
            {
                revenue+=item2.revenue;
                sold+=item2.sold;
                return 1;
            }
            else return 0;
        }
    private:
        std::string isbn;
        unsigned long sold;
        float revenue;
};

#endif // SALE_ITEM_H_INCLUDED
