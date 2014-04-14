
#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

std::istream& input(std::istream& in)
{
    int v;
    std::vector<int> intv;
    while(in>>v,!in.eof())
    {
        if(in.bad())
            throw std::runtime_error("input failed");
        else if(in.fail())
        {
            in.clear(std::istream::goodbit);
            in.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cerr<<"bad data"<<std::endl;
            continue;
        }
        intv.push_back(v);
    }
    for(std::vector<int>::iterator iter=intv.begin();iter!=intv.end();++iter)
        std::cout<<*iter<<" ";
    in.clear(std::istream::goodbit);
    return in;
}
#endif // INPUT_H_INCLUDED
