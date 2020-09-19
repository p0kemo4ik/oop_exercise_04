#include <iostream>
#include <tuple>

#include "vertex.hpp"
#include "hexagon.hpp"
#include "octagon.hpp"
#include "pentagon.hpp"
#include "templates.hpp"

template<class T>
void process() {
    T object;
    read(std::cin, object);
    print(std::cout, object);
    std::cout << square(object) << std::endl;
    std::cout << center(object) << std::endl;
}

int main() {
    std::cout << "How you want to declare your figure: " << std::endl;
    std::cout << "1. Tuple" << std::endl;
    std::cout << "2. Class" << std::endl;
    int menu, angles, figure;
    std::cin >> menu;
    std::cout << "How many angles (5, 6, 8): " << std::endl;
    std::cin >> angles;
    switch (menu) {
        case 1 :
            switch (angles) {
                case 5:
                    process<std::tuple<Vertex<int>, Vertex<int>, Vertex<int>, Vertex<int>, Vertex<int>>>();
                    break;
                case 6:
                    process<std::tuple<Vertex<int>, Vertex<int>, Vertex<int>, Vertex<int>, Vertex<int>, Vertex<int>>>();
                    break;
                case 8:
                    process<std::tuple<Vertex<int>, Vertex<int>, Vertex<int>, Vertex<int>, Vertex<int>, Vertex<int>, Vertex<int>, Vertex<int>>>();
                    break;
            }
            break;
        case 2:
            switch (angles) {
                case 5:
                    process<Pentagon<int>>();
                    break;
                case 6:
                    process<Hexagon<int>>();
                    break;
                case 8:
                    process<Hexagon<int>>();
                    break;
            }
            break;
    }
    return 0;
}