/*
 * main.cpp
 *
 *  Created on: 30/10/2020
 *      Author: clase
 */

#include <iostream>
#include <cstring>
#include <string>
#include "graph.h"

using namespace std;

int main() {

    Graph g;
    Graph star;
    Graph arbol;

    string g_ans, g_ans_2;
    string star_ans, star_ans_2;

    g.loadGraphList("g1.txt", 7, 7);
    star.loadGraphList("g2.txt", 5, 5);

    g.loadGraphMat("g1.txt", 7, 7);
    star.loadGraphMat("g2.txt", 5, 5);
//    arbol.loadGraphMat();

    //g.printAdjList()
    g_ans ="vertex 0 : 1 4 vertex 1 : 0 2 3 vertex 2 : 1 vertex 3 : 1 6 vertex 4 : 0 5 vertex 5 : 4 vertex 6 : 3 ";
    cout << " 1 " <<    (!g_ans.compare(g.printAdjList()) ? "success\n" : "fail\n");
    //star.printAdjList()
    star_ans="vertex 0 : 1 2 3 4 vertex 1 : 0 2 3 4 vertex 2 : 0 1 3 4 vertex 3 : 0 1 2 4 vertex 4 : 0 1 2 3 ";
    cout << " 2 " <<    (!star_ans.compare(star.printAdjList()) ? "success\n" : "fail\n");

    //g.printAdjMat()
    g_ans = "0 1 0 0 1 0 0 1 0 1 1 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 1 1 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 ";
    cout << " 3 " <<    (!g_ans.compare(g.printAdjMat()) ? "success\n" : "fail\n");

    //star.printAdjMat()
    star_ans ="0 1 1 1 1 1 0 1 1 1 1 1 0 1 1 1 1 1 0 1 1 1 1 1 0 ";
    cout << " 4 " <<    (!star_ans.compare(star.printAdjMat()) ? "success\n" : "fail\n");

    //g.DFS(0,3);
    g_ans = "visited: 0 4 5 1 3 path: 0 1 3";
    g_ans_2 = "visited: 0 1 2 3 path: 0 1 3";
    cout << " 5 " <<    ( (!g_ans.compare(g.DFS(0,3)) || !g_ans_2.compare(g.DFS(0,3))) ? "success\n" : "fail\n");

    //star.DFS(0,3);
    star_ans = "visited: 0 4 3 path: 0 4 3";
    star_ans_2 = "visited: 0 1 2 3 path: 0 1 2 3";
    cout << " 6 " <<    ( (!star_ans.compare(star.DFS(0,3)) || !star_ans_2.compare(star.DFS(0,3)))? "success\n" : "fail\n");


    //g.BFS(0,3);
    g_ans = "visited: 0 1 4 2 3 path: 0 1 3";
    g_ans_2 = "visited: 0 4 1 5 3 path: 0 1 3";
    cout << " 7 " <<    (( !g_ans.compare(g.BFS(0,3)) || !g_ans_2.compare(g.BFS(0,3))) ? "success\n" : "fail\n");

    //star.BFS(0,3);
    star_ans = "visited: 0 1 2 3 path: 0 3";
    star_ans_2 = "visited: 0 4 3 path: 0 3";
    cout << " 8 " <<    ((!star_ans.compare(star.BFS(0,3)) || !star_ans_2.compare(star.BFS(0,3))) ? "success\n" : "fail\n");

}
