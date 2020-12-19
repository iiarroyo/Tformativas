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
#include "bst.h"

using namespace std;

int main(int argc, char* argv[]) {
    BST<int> bst;
    string  ans;

    bst.add(10);

    ans =    "[10]\n[10]\n[10]\n[10]";
    cout << " 1 " <<    (!ans.compare(bst.visit()) ? "success\n" : "fail\n");

    cout << " 2 " <<    (1 == bst.height() ? "success\n" : "fail\n");

    bst.add(12);
    bst.add(8);
    bst.add(110);
    bst.add(112);
    bst.add(18);

    ans = "[10 8 12 110 18 112]\n[8 10 12 18 110 112]\n[8 18 112 110 12 10]\n[10 8 12 110 18 112]";
    cout << " 3 " <<    (!ans.compare(bst.visit()) ? "success\n" : "fail\n");
   
    cout << " 4 " <<    (4 == bst.height() ? "success\n" : "fail\n");

    ans = "[10 12 110]";
    cout << " 5 " <<    (!ans.compare(bst.ancestors(112)) ? "success\n" : "fail\n");

    ans = "[]";
    cout << " 6 " <<    (!ans.compare(bst.ancestors(1000)) ? "success\n" : "fail\n");

    cout << " 7 " <<    (4 == bst.whatlevelamI(18) ? "success\n" : "fail\n");

    cout << " 8 " <<    (2 == bst.whatlevelamI(8) ? "success\n" : "fail\n");

}
