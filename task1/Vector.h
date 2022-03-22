#pragma once
#include <iostream>
class Vector
{
private:
    int sz;
    int* elem;
public:
    //по умолчанию (создает массив некоторой длины по умолчанию)
    Vector();
    //по размеру (элементы инициализируются 0)
    explicit Vector(int size);
    //по размеру и числу n (элементы инициализируются числом n)
    explicit Vector(int size, int n);
    //копирования
    Vector(const Vector& a);
    //перемещения
    Vector(Vector&& v) noexcept;
    //деструктор
    ~Vector();
    //длина массива
    int size();
    //доступ к элементу (оператор [])
    int& operator[](int) const;
    //resize(newSize) – изменение размера
    void resize(int newSize);
    //оператор присваивания
    Vector& operator=(const Vector& v);
    //оператор перемещения
    Vector& operator=(Vector&& other) noexcept;
    //оператор ==
    bool operator==(const Vector& v);
    //оператор !=
    bool operator!=(const Vector& v);
    //операторы <, <=, >, >=
    bool operator<(const Vector& v);
    bool operator<=(const Vector& v);
    bool operator>(const Vector& v);
    bool operator>=(const Vector& v);
    //оператор +
    Vector operator+(const Vector& v);
    //оператор вывода
    friend std::ostream& operator<<(std::ostream& out, const Vector& v);
    //оператор ввода
    friend std::istream& operator>>(std::istream& in, Vector& v);
};