#pragma once
#include<iostream>
#include"vertex.hpp"
template <class T> class Octagon{
private:
    Vertex<T> Vertexs[8];
public:
    using vertex_type = Vertex<T>;
    Octagon();
    Octagon(std::istream& in);
    Vertex<T> center() const;
    double square() const;
    void read(std::istream& in);
    void print(std::ostream& os) const;
};

template<class T>
Octagon<T>::Octagon(){}

template<class T> Octagon<T>::Octagon(std::istream& in) {
    for (int i = 0; i < 8; i++)
        in >> Vertexs[i];
}
template<class T> double Octagon<T>::square() const {
    double Area = 0;
    for (int i = 0; i < 8; i++) {
        Area += (Vertexs[i].x) * (Vertexs[(i + 1) % 8].y) - (Vertexs[(i + 1) % 8].x)*(Vertexs[i].y);
    }
    Area *= 0.5;
    return abs(Area);
}

template<class T> void Octagon<T>::print(std::ostream& os) const {
    std::cout << "Octagon: ";
    for (int i = 0; i < 8; i++)
        std::cout << Vertexs[i] << ' ';
    std::cout << '\n';
}

template<class T> Vertex<T> Octagon<T>::center() const {
    Vertex<T> res = Vertex<T>();
    for (int i = 0; i < 8; i++)
        res += Vertexs[i];
    return res / 8;
}

template <class T> void Octagon<T>::read(std::istream& in) {
    Octagon<T> res = Octagon(in);
    *this = res;
}