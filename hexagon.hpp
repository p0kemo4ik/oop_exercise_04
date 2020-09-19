#pragma once
#include<iostream>
#include"vertex.hpp"
template <class T> class Hexagon{
private:
    Vertex<T> Vertexs[6];
public:
    using vertex_type = Vertex<T>;
    Hexagon();
    Hexagon(std::istream& in);
    Vertex<T> center() const;
    double square() const;
    void read(std::istream& in);
    void print(std::ostream& os) const;
};

template<class T>
Hexagon<T>::Hexagon() {}

template<class T> Hexagon<T>::Hexagon(std::istream& in) {
    for (int i = 0; i < 6; i++)
        in >> Vertexs[i];
}
template<class T> double Hexagon<T>::square() const {
    double Area = 0;
    for (int i = 0; i < 6; i++) {
        Area += (Vertexs[i].x) * (Vertexs[(i + 1) % 6].y) - (Vertexs[(i + 1) % 6].x)*(Vertexs[i].y);
    }
    Area *= 0.5;
    return abs(Area);
}

template<class T> void Hexagon<T>::print(std::ostream& os) const {
    std::cout << "Hexagon: ";
    for (int i = 0; i < 6; i++)
        std::cout << Vertexs[i] << ' ';
    std::cout << '\n';
}

template<class T> Vertex<T> Hexagon<T>::center() const {
    Vertex<T> res = Vertex<T>();
    for (int i = 0; i < 6; i++)
        res += Vertexs[i];
    return res / 6;
}

template <class T> void Hexagon<T>::read(std::istream& in) {
    Hexagon<T> res = Hexagon(in);
    *this = res;
}