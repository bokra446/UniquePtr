#include "UniquePtr.h"
#include <utility>
#include <crtdbg.h>
#include <iostream>
int main() {
        //int* data = new int[256];
        //ValueType* h = new ValueType[3];
        //UniquePtr ff(h);
        /*{
            UniquePtr ptr(std::move(ff));
        }*/

        UniquePtr<char> p1;
        //UniquePtr p2(p1); // копирование, нельзя!
        UniquePtr<char> p2(std::move(p1));
        p2 = std::move(p1);

    p2 = nullptr;
    //p2 = p2; // копирование, не заработает
    p2 = UniquePtr<char>(nullptr); // перемещение
    p2 = std::move(p2);
    if (p2) {
        std::cout << p2.get() << std::endl;
    }
    else {
        std::cout << "pip" << std::endl;
    }
    //delete[] h;
    //_CrtDumpMemoryLeaks();
    // 1. Проверить, что освобождает память после деструктора
    // 2. Проверить приведение к bool
    // 3. Проверить перемещение
    // 4. Проверить копирование (не должно работать)
    // 5. Проверить перемещение в самого себя
}