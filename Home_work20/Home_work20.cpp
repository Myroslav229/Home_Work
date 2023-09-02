#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <cstdio>

class LengthComparator {
public:
    bool operator()(const std::string& first,const std::string& second) {
        return first.length() > second.length();
    }
};
unsigned int countDivisibleBy(const std::vector<int>& vec, int number)
{
    return static_cast<unsigned int> (std::count_if(vec.begin(), vec.end(), [&](const int& val) {
        return (val % number == 0);
        }));

}

std::function<std::string()> makeLambda()
{
    const std::string val = "string";
    return [val] {return val; };
    //return [&val] {return val; }; returning adress of val make error because std::string calling destructor when skope end
    // ~std::string val -> val erased -> return &val -> error
}

static bool compareByLength(std::string& first, std::string& second) {

    return first.length() < second.length();
}

void write(std::vector<std::string> vec) {
    for (std::string a : vec) {
        std::cout << a << ", ";
    }
    std::cout << std::endl;
}
int main()
{
    auto bad = makeLambda();
    std::cout << bad() << std::endl;

    std::vector<int> numbers {4, 9, 7, 12, 10};
    std::cout << countDivisibleBy(numbers, 3) << std::endl;
    std::vector<std::string> stringContainer { "vehicle", "AMD", "MULTIPROGRAM", "dioxide", "Hesistation is defeat"};
    write(stringContainer);
    std::sort(stringContainer.begin(), stringContainer.end(), compareByLength);
    write(stringContainer);
    std::sort(stringContainer.begin(), stringContainer.end(), LengthComparator{});
    write(stringContainer);
    std::sort(stringContainer.begin(), stringContainer.end(), [](const std::string first,const std::string second) {
        return (first.length() < second.length());
        });
    write(stringContainer);
}