#pragma once
#include <iostream>
class Vector
{
private:
    int sz;
    int* elem;
public:
    //�� ��������� (������� ������ ��������� ����� �� ���������)
    Vector();
    //�� ������� (�������� ���������������� 0)
    explicit Vector(int size);
    //�� ������� � ����� n (�������� ���������������� ������ n)
    explicit Vector(int size, int n);
    //�����������
    Vector(const Vector& a);
    //�����������
    Vector(Vector&& v) noexcept;
    //����������
    ~Vector();
    //����� �������
    int size();
    //������ � �������� (�������� [])
    int& operator[](int) const;
    //resize(newSize) � ��������� �������
    void resize(int newSize);
    //�������� ������������
    Vector& operator=(const Vector& v);
    //�������� �����������
    Vector& operator=(Vector&& other) noexcept;
    //�������� ==
    bool operator==(const Vector& v);
    //�������� !=
    bool operator!=(const Vector& v);
    //��������� <, <=, >, >=
    bool operator<(const Vector& v);
    bool operator<=(const Vector& v);
    bool operator>(const Vector& v);
    bool operator>=(const Vector& v);
    //�������� +
    Vector operator+(const Vector& v);
    //�������� ������
    friend std::ostream& operator<<(std::ostream& out, const Vector& v);
    //�������� �����
    friend std::istream& operator>>(std::istream& in, Vector& v);
};