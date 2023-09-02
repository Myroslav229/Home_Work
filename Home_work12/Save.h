#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <string>
#include "Time_determination.h"





class Save {
    CurrentTime & time;
    std::fstream file;
public:
    Save(CurrentTime& time) : time{ time } {
        file.open("Save.txt", std::ios::app);
        file.close();
    }

    void save() {
        file.open("Save.txt", std::ios::out);

        file << time.getYear() << time.getDay() << std::endl;
        file.close();
    }
    bool check() {
        int x{};
        file.open("Save.txt", std::ios::in);
        file >> x;
        file.close();
        return(x == (time.getYear() * 1000 + time.getDay()));
    }
};