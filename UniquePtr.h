#pragma once
#include <cstring>
#include <algorithm>
#include <iostream>
template <typename T>
class UniquePtr {
    using ValueType = T;
private:
    ValueType* _ptr;
public:

    // Конструктор
    UniquePtr() {
        _ptr = nullptr;
    }
    // Конструктор из указателя
    explicit UniquePtr(ValueType* ptr) {
        _ptr = ptr;
    }

    // Конструктор перемещения
    UniquePtr(UniquePtr&& o) {
        this->_ptr = o._ptr;
        o._ptr = nullptr;
        std::cout << "move construct \n";
    }

    // Конструктор копирования
    UniquePtr(const UniquePtr& o) = delete;

    // оператор присваивания через перемещение
    UniquePtr& operator=(UniquePtr&& o) {
        std::cout << "move operation \n";
        if (o._ptr == _ptr)
            return *this;
        if (_ptr != nullptr) {
            delete[] _ptr;
        }
        _ptr = nullptr;
        std::swap(_ptr, o._ptr);
        return *this;
    }
        // o == this ?

        // на этот момент тут уже что-то может быть
        // надо почистить память

    // оператор присваивания через копирование
    UniquePtr& operator=(const UniquePtr& o) = delete;

    // оператор присваивания - присвоить новый указатель
    // Не забывать про старую память
    UniquePtr& operator=(ValueType* ptr) {
        std::cout << " operator = \n";
        if (this != nullptr) {
            delete[] _ptr;
        }
        _ptr = ptr;
        return *this;
    }

    // сбрасывает _ptr в nullptr
    // не забыть почистить память память память!
    void reset() {
        reset(nullptr);
    }

    // reset + присвоение нового указателя
    void reset(ValueType* ptr) {
        std::cout << "this is empty " << static_cast<bool>(this) << std::endl;
        if (this != nullptr) {
            delete[] _ptr;
        }
        _ptr = ptr;
    }

    // "Освобождение" указателя
    // без удаления памяти
    void release() {
        _ptr = nullptr;
    }

    // возвращает, внутри nullptr или нет
    operator bool() const {
        return _ptr;
    }

    // разыменовывание
    ValueType& operator*() const {
        return *_ptr;
    }

    // оператор стрелочки
    ValueType* operator->() const {
        return get();
    }

    // возвращает указатель
    ValueType* get() const {
        return _ptr;
    }


};
