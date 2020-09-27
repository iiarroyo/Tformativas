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
#include "list.h"

using namespace std;


/* Agregar un metodo toString a su clase.h
template <class T>
std::string List<T>::toString() const {
    std::stringstream aux;
    Link<T> *p;
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
*/

int main(int argc, char* argv[]) {
    List<int> b1;
    string ans;

    b1.add(2);
    ans = "[2]";
    cout << " 1 " <<    (!ans.compare(b1.toString()) ? "success\n" : "fail\n");

    b1.add(3);
    b1.add(6);
    b1.add(10);
    ans = "[2, 3, 6, 10]";
    cout << " 2 " <<    (!ans.compare(b1.toString()) ? "success\n" : "fail\n");

    cout << " 3 " <<    (3 == b1.find(10) ? "success\n" : "fail\n");

    cout << " 4 " <<    (-1 == b1.find(1) ? "success\n" : "fail\n");

    b1.update(1,13);
    ans = "[2, 13, 6, 10]";
    cout << " 5 " <<    (!ans.compare(b1.toString()) ? "success\n" : "fail\n");

    b1.update(3,32);
    ans ="[2, 13, 6, 32]";
    cout << " 6 " <<    (!ans.compare(b1.toString()) ? "success\n" : "fail\n");

    b1.remove(0);
    ans = "[13, 6, 32]";
    cout << " 7 " <<    (!ans.compare(b1.toString()) ? "success\n" : "fail\n");

    b1.remove(1);
    ans = "[13, 32]";
    cout << " 8 " <<    (!ans.compare(b1.toString()) ? "success\n" : "fail\n");

}
