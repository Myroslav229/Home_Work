#include <iostream>

const char vowels[] = "aeiouAEIOU";
const char constonants[] = "abcdefghijklmnopqrstuvwxyzBCDFGHJKLMNPQRSTVWXYZ";

void translateArray(int numbers[], int size) {
    for (int i = 0; i < size; ++i) {
        if (numbers[i] > 0) numbers[i] *= 2;
        else numbers[i] = 0;
    }
}
void toUppercase(char str[]) {
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] > 96 && str[i] < 123)
        {
            str[i] -= 32;
        }

    }
}
bool isPalindrom(const char str[]) {
    for (int i = 0; i < strlen(str) - 1; ++i) {
        if (str[i] != str[strlen(str) - 1 - i])
        {
            return false;
        }
        else return true;
    }
}
void parseStringLetters(const char str[], int& vowelsCount, int& constonantsCount) {
    for (int i = 0; i < strlen(str); ++i) {
        for (int j = 0; j < strlen(vowels); j++) {
            if (str[i] == vowels[j])
            {
                vowelsCount++;
            }
        }
        for (int j = 0; j < strlen(constonants); j++) {
            if (str[i] == constonants[j])
            {
                constonantsCount++;
            }
        }
    }
}
bool isEqual(const char str1[], const char str2[]) {
    for (int i = 0; i < strlen(str1); ++i) {
        if (str1[i] != str2[i])
        {
            return false;
        }
        else return true;
    }
}


int main() {
    const int N = 10;
    int array[N]{};
    std::cout << "Enter 10 element of array: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> array[i];
    }
    std::cout << "Result:\n";
    translateArray(array, N);
    std::cout << "\nTranslated array: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;

    char str1[256]{};
    std::cout << "Enter word to up letters: ";
    std::cin >> str1;
    toUppercase(str1);
    std::cout << "\nChanged word: " << str1 << std::endl;

    char str2[256]{};
    std::cout << "Enter word for examination for palindrome: ";
    std::cin >> str2;
    std::cout << "This word is palindrome is " << std::boolalpha << isPalindrom(str2) << std::endl;
    char str3[256]{};
    int vowelCount = 0, constonantCount = 0;
    std::cout << "Enter word for ";
    std::cin >> str3;
    parseStringLetters(str3, vowelCount, constonantCount);
    std::cout << "Number of vowels: " << vowelCount << std::endl << "Number of constonants: " << constonantCount << std::endl;

    char str4[256]{};
    std::cout << "Enter first word: ";
    std::cin >> str4;
    char str5[256]{};
    std::cout << "\nEnter second word: ";
    std::cin >> str5;
    std::cout << "\nThis words is equal is " << std::boolalpha << isEqual(str4, str5);
}