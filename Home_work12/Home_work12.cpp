#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Save.h"
#include <map>


class WordBase {
    std::ifstream file;
public:
    std::string word(int num) {
        std::map <int, std::string> words;
        file.open("words.txt", std::ios::in);
        
        for (int i = 0; std::getline(file, words[i]); ++i);
        file.close();
        std::srand(num);
        int generatingRange = words.size();
        int generatedNum = std::rand() % (generatingRange - 1);

        return words[generatedNum];
    }
};

class Game {
    static const int wordSize = 6;
    char quess[wordSize]{};
    int counter{};
    char result[wordSize]{};
public:
    Game( ){
        
    }
    void game(std::string word) {
        while (true) {
            std::cout << "Enter: ";
            std::cin >> quess;
            for (int i = 0; i < wordSize-1; i++) {
                result[i]= '*';
                if (quess[i] == word[i]) {

                    result[i] = std::toupper(quess[i]);
                }
                else {
                    for (int j = 0; j < wordSize-1; j++) {
                        if (quess[i] == word[j]) {
                            result[i] = quess[i];
                        }
                    }
                }
            }
            std::cout << "Result: " << result << std::endl;
            counter++;
            std::cout << "Tries: " << counter << std::endl;
            if (word == quess) {
                std::cout << "Thats right ";
                break;
            }    
        }
    }
};

int main() {
    CurrentTime time;
    Save save{ time };
    WordBase w;
    while(true) {
    int input{};
    int num{};
    bool flag = false;
    std::cout << "1 - Word of the day\n2 - Random word\n0 - Exit\nEnter: ";
    std::cin >> input;
        if (input == 1) { 
            if (save.check()) {
                std::cout << "Come back tomorrow!\n";
                continue;
            }
            else { 
                num = time.getDay();
                flag = true; }
        }
        else if (input == 2) {
            num = time.getTime();
        }
        else {
            std::cout << "Good buye";
            break;
        }
        Game g;
        g.game(w.word(num));
        if (flag == true) save.save();
    }
    return 0;
}