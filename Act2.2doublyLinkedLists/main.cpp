/*
 * main.cpp
 *
 *  Created on: 10/08/2020
 *      Author: bvaldesa
 */

#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include "dlist.h"

/*
    // Incluye estos funciones en tu dlist.h para poder imprimir tus respuestas
    // en formatos compatibles con el main
    template <class T>
    std::string DList<T>::toStringForward() const {
        std::stringstream aux;
        DLink<T> *p;
        p = head;
        aux << "[";
        while (p != 0) {
            aux << p->value;
            if (p->next != 0) {
                aux << ", ";
            }
            p = p->next;
        }
        aux << "]";
        return aux.str();
    }
    template <class T>
    std::string DList<T>::toStringBackward() const {
        std::stringstream aux;
        DLink<T> *p;
        p = tail;
        aux << "[";
        while (p != 0) {
            aux << p->value;
            if (p->previous != 0) {
                aux << ", ";
            }
            p = p->previous;
        }
        aux << "]";
        return aux.str();
    }
*/



using namespace std;

int main(int argc, char* argv[]) {
    DList<int> b1;
    string front, back;

    b1.add(2);
    front = "[2]";
    back = "[2]";
    cout << " 1 " <<    (!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
    cout << " 1 " <<    (!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

     b1.add(3);
    b1.add(6);
    b1.add(10);
    front = "[2, 3, 6, 10]";
    back = "[10, 6, 3, 2]";
    cout << " 2 " <<    (!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
    cout << " 2 " <<    (!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

    cout << " 3 " <<    (3 == b1.find(10) ? "success\n" : "fail\n");

    cout << " 4 " <<    (-1 == b1.find(1) ? "success\n" : "fail\n");

    b1.update(1,13);
    front = "[2, 13, 6, 10]";
    back = "[10, 6, 13, 2]";
    cout << " 5 " <<    (!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
    cout << " 5 " <<    (!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

    b1.update(3,32);
    front = "[2, 13, 6, 32]";
    back = "[32, 6, 13, 2]";
    cout << " 6 " <<    (!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
    cout << " 6 " <<    (!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

    b1.remove(0);
    front = "[13, 6, 32]";
    back = "[32, 6, 13]";
    cout << " 7 " <<    (!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
    cout << " 7 " <<    (!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

    b1.remove(1);
    front = "[13, 32]";
    back = "[32, 13]";
    cout << " 8 " <<    (!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
    cout << " 8 " <<    (!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

}
