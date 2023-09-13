// Home_work25.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>

void arrSum(std::vector<int>& vec, int thread) {
    int sum = 0;
    int step = vec.size() / thread;
    int k = 0;
    std::vector<std::thread> threads;
    
    std::mutex m;
    for (int i = 0; i < thread; ++i) {
        if (vec.size() % thread != 0 && i == thread - 1) {
            step += vec.size() - step * thread;
        }

        threads.emplace_back([&vec,i, k,step,&sum, &m] {
            
            for (int j = k; j < k + step; ++j) {
                
                m.lock();
                //std::cout << j << " ";
                sum += vec[j];
                m.unlock();
            }

        });
        k += step;

    }
    for (auto& th : threads) { th.join(); }
}

void arrFill(std::vector<int> & vec) {
    for (int & num : vec) {
        num = std::rand();
    }
}

int main()
{
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    int random_variable = std::rand();
    std::vector<int> vector (100000000);
    arrFill(vector);
    int threadCount =  1;
    std::time_t t = std::time(nullptr);
    const auto start{ std::chrono::steady_clock::now() };
    arrSum(vector, threadCount);
    const auto end{ std::chrono::steady_clock::now() };
    const std::chrono::duration<double> elapsed_seconds{end - start};
    std::cout << elapsed_seconds.count() << '\n'; // C++20's chrono::duration operator<<
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
