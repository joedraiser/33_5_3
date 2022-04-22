#include <iostream>
#include <map>

template<typename T, typename U>
class Docket
{
private:
    std::multimap<T,U> dckt;
public:
    Docket() {};

    void add(T key, U value)
    {
        dckt.template emplace(std::make_pair(T(key), U(value)));
    }

    void remove(T key)
    {
        dckt.erase(key);
    }

    void print()
    {
        for(auto i=dckt.begin();i!=dckt.end();i++)
        {
            std::cout << i->first << " " << i->second << std::endl;
        }
    }

    void find(T key)
    {
        std::cout << "Values of key " << key;
        for(auto i=dckt.begin();i!=dckt.end();i++)
        {
            if(i->first==key)
                std::cout << i->second << std::endl;
        }
    }
};

int main()
{
    Docket<int, std::string> numbers;

    numbers.add(1, "one");
    numbers.add(2,"two");
    numbers.add(3,"three");
    numbers.add(0, "zero");
    numbers.add(0, "null");

    numbers.print();

    numbers.find(0);

    numbers.remove(0);
    numbers.print();

    return 0;
}
