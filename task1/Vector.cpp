#include "Vector.h"

Vector::Vector() {
    sz = 1;
    elem = new int[1]();
}

Vector::Vector(int size) {
    sz = size;
    elem = new int[size]();
}

Vector::Vector(int size, int n) {
    sz = size;
    elem = new int[size];
    for (int i = 0; i < size; i++) {
        elem[i] = n;
    }
}

Vector::Vector(const Vector& a) : sz(a.sz), elem(new int[sz]) {
    for (int i = 0; i < sz; i++)
        elem[i] = a.elem[i];
    std::cout << "copy constr" << std::endl;
}

Vector::Vector(Vector&& v) noexcept : elem(nullptr), sz(0) {
    sz = v.sz;
    elem = v.elem;
    v.elem = nullptr;
    v.sz = 0;
    std::cout << "move constr" << std::endl;
}

Vector::~Vector() {
    if (elem) {
        delete[] elem;
        elem = nullptr;
        sz = 0;
    }
}

int Vector::size() {
    return sz;
}

int& Vector::operator[](int i) const {
    if (i < 0 || i >= sz) throw std::out_of_range{ "Vector::operator[]" };
    return elem[i];
}

void Vector::resize(int newSize) {
    if (newSize < 0) throw std::runtime_error{ "resize error" };
    int* tmp = new int[newSize]();
    if (sz > newSize) {
        for (int i = 0; i < newSize; i++) {
            tmp[i] = elem[i];
        }
    }
    else {
        for (int i = 0; i < sz; i++) {
            tmp[i] = elem[i];
        }
        for (int i = sz; i < newSize; i++) {
            tmp[i] = 0;
        }
    }
    delete[] elem;
    elem = tmp;
    sz = newSize;
}

Vector& Vector::operator=(const Vector& v) {
    sz = v.sz;
    if (elem != nullptr) {
        delete[] elem;
    }
    elem = new int[v.sz];
    for (int i = 0; i < v.sz; i++) {
        elem[i] = v[i];
    }
    return *this;
}

Vector& Vector::operator=(Vector&& other) noexcept {
    if (this != &other) {
        delete[] elem;
        sz = other.sz;
        elem = other.elem;
        other.elem = nullptr;
        other.sz = 0;
    }
    return *this;
}

bool Vector::operator==(const Vector& v) {
    if (sz != v.sz)
        throw std::out_of_range("Cant check equality of vectors");
    else {
        for (int i = 0; i < size(); i++) {
            if (elem[i] != v[i])
                return false;
        }
    }
    return true;
}

bool Vector::operator!=(const Vector& v) {
    if (sz != v.sz)
        throw std::out_of_range("Cant check equality of vectors");
    else {
        for (int i = 0; i < size(); i++) {
            if (elem[i] != v[i])
                return true;
        }
    }
    return false;
}

int compare(int* arr1, int* arr2, int size1, int size2) {
    int size;
    if (size1 == size2) size = size1;
    else if (size1 < size2) size = size1;
    else size = size2;
    for (int i = 0; i < size; i++) {
        if (arr1[i] > arr2[i]) {
            return 1;
        }
        else if (arr1[i] < arr2[i]) {
            return -1;
        }
    }
    if (size1 == size2) return 0;
    else if (size1 > size2) return 1;
    else return -1;
}

bool Vector::operator<(const Vector& v) {
    return (compare(elem, v.elem, sz, v.sz) < 0);
}

bool Vector::operator<=(const Vector& v) {
    return (compare(elem, v.elem, sz, v.sz) <= 0);
}

bool Vector::operator>(const Vector& v) {
    return (compare(elem, v.elem, sz, v.sz) > 0);
}

bool Vector::operator>=(const Vector& v) {
    return (compare(elem, v.elem, sz, v.sz) >= 0);
}

Vector Vector::operator+(const Vector& other) {
    Vector newValue(sz + other.sz);
    for (int i = 0; i < sz; i++) {
        newValue[i] = elem[i];
    }
    for (int i = sz; i < sz + other.sz; i++) {
        newValue[i] = other.elem[i - sz];
    }
    return newValue;
}

std::ostream& operator<<(std::ostream & out, const Vector & v) {
    out << "Vector:\n" << "size " << v.sz << std::endl << "Elements:\n";
    for (int i = 0; i < v.sz; i++) {
        out << v[i] << ' ';
    }
    out << "\n";
    return out;
}

std::istream& operator>>(std::istream & in, Vector & v) {
    in >> v.sz;
    if (v.sz < 0) {
        throw std::out_of_range("wrong size");
    }
    for (int i = 0; i < v.sz; i++) {
        in >> v[i];
    }
    return in;
}