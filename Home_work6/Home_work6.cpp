#include <iostream>
#include <ctime> 

int main()
{
    std::cout << "Game start\n";
    while (true) {
        std::cout << "Ultimate quess quest\nEnter -1 for exit\nEnter -2 for Treasure hunter\nTry to guess number (0-50)\n";
        int highscore = 0;
        int score = 0;
        int ans = 0;
        int ansrow = 0, anscol = 0;
        char field[7][7];
        int row = 0, col = 0;
        while (true)
        {
            score = 0;
            std::srand(std::time(nullptr));
            const int GeneratingRange = 50;
            const double generatednum = std::rand() % (GeneratingRange - 1);
            ans = 0;
            while (true) {
                score++;
                std::cout << "Enter your answer: ";
                std::cin >> ans;
                if (ans == -1 || ans == -2) break;
                else if (ans > 50) std::cout << "Entered wrong number, number can't be higher than 50";
                else if (ans < -2) std::cout << "Entered wrong number, number can't be less than -2";
                else if (ans == generatednum) {
                    if (score == 1) std::cout << "Are you oracle?";
                    else std::cout << "You right ";
                    break;
                }
                else if (ans > generatednum && ans - generatednum < 10)
                    std::cout << "Very close, try a little less ";
                else if (ans > generatednum && ans - generatednum >= 10 && ans - generatednum < 20)
                    std::cout << "To far, try less";
                else if (ans > generatednum && ans - generatednum >= 20)
                    std::cout << "Furthest, you need much less";
                else if (ans < generatednum && generatednum - ans < 10)
                    std::cout << "Almost there, try some higher";
                else if (ans < generatednum && generatednum - ans >= 10 && generatednum - ans < 20)
                    std::cout << "Your answer is higher";
                else if (ans < generatednum && generatednum - ans >= 20)
                    std::cout << "To way less, try higher";
            }
            if (ans == -1 || ans == -2) break;

            if (highscore == 0) {
                highscore = score;
            }
            else if (score < highscore) {
                highscore = score;
            }
            std::cout << "\nHighscore: " << highscore << std::endl;
        }
        if (ans == -1) break;
        if (ans == -2) {
            score = 0;

            std::cout << "Treasure hunter\nTry to guess the coordinates of the treasure (0-7)x(0-7)\n Enter -1 -1 for exit\n Enter -1 0 for original game ";
            while (true) {
                std::srand(std::time(nullptr));
                const int GeneratingRange = 7;
                const double generatedrow = std::rand() % (GeneratingRange - 1);
                const double generatedcol = std::rand() % (GeneratingRange - 1);
                std::cout << generatedrow << ',' << generatedcol << std::endl;
                while (true) {
                    std::cin >> ansrow >> anscol;
                    if (ansrow == -1 || anscol == -1) break;
                    else if (anscol < -1 || ansrow < -1) std::cout << "Entered wrong number\n";
                    else {
                        for (row = 0; row < 7; ++row) {
                            for (col = 0; col < 7; col++) {
                                if (generatedrow == ansrow && generatedcol == anscol && ansrow == row && anscol == col)
                                    field[row][col] = { 'x' };
                                else if (ansrow == row && anscol == col && ansrow != generatedrow && anscol != generatedcol)
                                    field[row][col] = { '0' };
                                else if (ansrow == row && ansrow == generatedrow && anscol != generatedcol && anscol == col)
                                    field[row][col] = { 'r' };
                                else if (anscol == col && anscol == generatedcol && ansrow != generatedrow && ansrow == row)
                                    field[row][col] = { 'c' };
                                else field[row][col] = { '#' };
                            }
                        }

                        for (row = 0; row < 7; ++row) {
                            for (col = 0; col < 7; col++) {
                                std::cout << (char)field[row][col];
                            }
                            std::cout << std::endl;
                        }
                    }
                    score++;
                    if (ansrow != generatedrow && anscol != generatedcol) std::cout << "You miss, try again: ";
                    else if (ansrow == generatedrow && anscol != generatedcol) std::cout << "Treasure on this row, try again: ";
                    else if (anscol == generatedcol && ansrow != generatedrow) std::cout << "Treasure on this collum, try again: ";
                    else if (generatedrow == ansrow && generatedcol == anscol) {
                        std::cout << "Congratulations !!! You find a treasure\n";
                        break;
                    }
                }
                if (highscore == 0) {
                    highscore = score;
                }
                else if (score < highscore) {
                    highscore = score;
                }
                std::cout << "Highscore: " << highscore << std::endl;
                if (ansrow == -1) break;
            }
        }
        if (ansrow == -1 && anscol == -1) break;
    }
    std::cout << "See you next time!";
}
