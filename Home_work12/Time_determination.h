#pragma once
#define _CRT_SECURE_NO_WARNINGS


#include <ctime>
class CurrentTime {
    int day{};
    int year{};
    std::time_t t;
    const int days_before_month[13] { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
public:

    CurrentTime() {
        t = std::time(nullptr);
        std::tm* now = std::localtime(&t);
        year = now->tm_year+1900;
        day = now->tm_mday + days_before_month[now->tm_mon + 1];
    }
    int getDay() {
        return day;
    }
    int getYear() {
        return year;
    }
    int getTime() {
        return static_cast<int>(t);
    }
};