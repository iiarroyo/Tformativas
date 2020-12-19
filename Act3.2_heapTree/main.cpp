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
#include "heap.h"

using namespace std;

/* Agregue en tu heap.h el metodo to string
template <class T>
std::string Heap<T>::toString() const {
    std::stringstream aux;
    aux << "[";    for (unsigned int i = 0; i < count; i++) {
        if (i != 0) {
            aux << " ";
        } aux << data[i];
    } aux << "]";
    return aux.str();
}
*/

int main(int argc, char* argv[]) {
    Heap<int> heap(20);
    string ans;
    heap.push(8);
    cout<<heap.toString();

  ans =    "[8]";
    cout << " 1 " <<    (!ans.compare(heap.toString()) ? "success\n" : "fail\n");

    heap.push(20);
//    cout<<heap.toString();
    heap.push(31);
//    cout<<heap.toString();
    heap.push(5);
//    cout<<heap.toString();
    heap.push(87);
//    cout<<heap.toString();
    ans ="[5 8 31 20 87]";
    cout << " 2 " <<    (!ans.compare(heap.toString()) ? "success\n" : "fail\n");
//    cout<<heap.toString();
    heap.pop();
    ans ="[8 20 31 87]";
    cout << " 3 " <<    (!ans.compare(heap.toString()) ? "success\n" : "fail\n");
//    cout<<heap.toString();
    cout << " 4 " <<    ((4 == heap.size()) ? "success\n" : "fail\n");

    heap.pop();
    ans ="[20 87 31]";
    cout << " 5 " <<    (!ans.compare(heap.toString()) ? "success\n" : "fail\n");

    cout << " 6 " <<    ((3 == heap.size()) ? "success\n" : "fail\n");

    cout << " 7 " <<    ((20 == heap.top()) ? "success\n" : "fail\n");

    cout << " 8 " <<    ((0 == heap.empty()) ? "success\n" : "fail\n");

    heap.pop();

    cout << " 9 " <<    ((31 == heap.top()) ? "success\n" : "fail\n");

    heap.pop();

    cout << " 10 " <<    ((0 == heap.empty()) ? "success\n" : "fail\n");

}
