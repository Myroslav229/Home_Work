#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <stack>

unsigned int uniqueWordsCount(const std::string& line) {
    std::string word = line;
    std::set <std::string> container;
    while (!word.empty()) {
        int p = word.find(' ');
        if (p < 0) {
            container.insert(word);
            break;
        }
        else {
            container.insert(word.substr(0, p));
            word.erase(0, p + 1);
        }
    }
    return container.size();
}

std::string mostOccuredWord(const std::string& line) {
    std::string word = line;
    std::map <std::string, int> container;
    while (!word.empty()) {
        int p = word.find(' ');
        if (p < 0) {
            container[word]++;
            break;
        }
        else {
            container[word.substr(0, p)]++;
            word.erase(0, p + 1);
        }
    }
    int max = 0;
    std::string str{container.begin()->first};
    for (auto& elem : container) {
        if (elem.second > max) {
            max = elem.second;
            str = elem.first;
        }
    }
    return str;
}

bool bracketsСheck(const std::string& line) {
    std::stack <char> s;
    std::string left{"{[("};
    std::string right{"}])"};
    bool flag = true;
    char c{};
    int p{};
    for (auto& ch : line) {
        p = left.find(ch);
        if (p >= 0) {
            s.push(ch);
        }
        p = right.find(ch);
        if (p >= 0) {
            if (s.empty()) {
                flag = false;
            }
            else {
                c = s.top();
                s.pop();
                if (p != left.find(c)) {
                    flag = false;
                }
            }
            if (!flag) { break; }
        }
    }
    if (!s.empty()) { flag = false; }
    return flag;
}
int main() {
    std::string line = "Hello Hey Hello Bye Hey Hello Hey Hey";
    std::cout << uniqueWordsCount(line) << std::endl;
    std::cout << mostOccuredWord(line) << std::endl;
    std::cout << std::boolalpha << bracketsСheck("()") << std::endl;
    std::cout << std::boolalpha << bracketsСheck("{[()][]}()") << std::endl;
    std::cout << std::boolalpha << bracketsСheck("[{]}") << std::endl;
}