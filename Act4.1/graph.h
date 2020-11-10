//
//  graph.h
//
//
//  Created by Israel Arroyo on 02/11/20.
//  A01706190

#ifndef graph_hpp
#define graph_hpp

#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>

class Graph
{
private:
    int* mat;
    int n;
    int m;
    std::vector<int>* list;
public:
    Graph();
    void loadGraphList(std::string, int, int);
    void loadGraphMat(std::string, int, int);
    std::string DFS(int, int);
    void DFShelper(int,bool*, int*, std::vector<int>*);
    std::string BFS(int, int);

    std::vector<int>* readTxt(std::string);
    void addEdgeMat(std::vector<int>*);
    void addEdgeList(std::vector<int>*);
    std::string printAdjMat();
    std::string printAdjList();
};
Graph::Graph(): mat(0),n(0),m(0),list(0){}
void Graph::loadGraphMat(std::string fileName, int n_in, int m_in)
{
    //n = number of vertices
    //m = number of archs
    n=n_in;
    m=m_in;
    mat = new int[n*n];
    for(int i = 0; i<(n*n-1);i++)
    {
        mat[i]=0;
    }
    std::vector<int>* temp;
    temp = readTxt(fileName);

    addEdgeMat(temp);
}
void Graph::loadGraphList(std::string fileName, int n_in, int m_in)
{
    //n = number of vertices
    //m = number of archs
    n=n_in;
    m=m_in;
    list = new std::vector<int>[n];

    std::vector<int>* temp;
    temp = readTxt(fileName);

    addEdgeList(temp);
}
void Graph ::DFShelper(int visiting,bool* visited, int* parent, std::vector<int>* visitedList)
{
    visited[visiting] = true;
//    std::cout<<visiting<<" ";
    visitedList->push_back(visiting);

    for(int i = 0;i<n;i++)
    {
        if((mat[(visiting*n)+i])== 1 && (!visited[i]))
        {
            parent[i] = visiting;
            DFShelper(i,visited,parent,visitedList);
        }
    }
}
std::string Graph::DFS(int start, int goal)
{
    int parent[n];
    std::stringstream ans;
    std::vector<int>* visitedList = new std::vector<int>;
    bool visited[n];
    bool found = false;
    visited[start] = true;
    ans<<"visited:";
    for(int i = 0; i<n;i++)
    {
        visited[i] = false;
        parent[i] = -1;
    }
    DFShelper(start,visited,parent,visitedList);
    for(int i =0; i<visitedList->size();i++)
    {
        ans<<" "<<visitedList->at(i);
        if(visitedList->at(i) == goal)
            break;
    }
    ans<<" path:";
    int aux = goal;
    std::stack<int> path;
    path.push(aux);
    while(!found)
    {
        aux = parent[aux];
        path.push(aux);
        found = (aux == start)?true:false;
    }

    while(!path.empty())
    {
        ans<<" "<<path.top();
        path.pop();
    }
    return ans.str();
}
std::string Graph::BFS(int start, int goal)
{
    int parent[n];
    std::stringstream ans;
    std::queue<int> queue;
    bool visited[n];
    bool found = false;
    visited[start] = true;
    queue.push(start);
    ans<<"visited:";
    while(!queue.empty())
    {
        int visiting = queue.front();
        queue.pop();
        ans<<" "<<visiting;
        for(int i = 0; i < n; i++)
        {

            if((mat[(visiting*n)+i])==1 && (!visited[i])&& !found)
            {
                found = (i == goal)?true:false;
                queue.push(i);
                visited[i] = true;
                parent[i] = visiting;
            }
        }
    }

    ans<<" path:";
    int aux = goal;
    std::stack<int> path;
    path.push(aux);
    while(found)
    {
        aux = parent[aux];
        path.push(aux);
        found = (aux == start)?false:true;
    }

    while(!path.empty())
    {
        ans<<" "<<path.top();
        path.pop();
    }
    return ans.str();

}
void Graph::addEdgeMat(std::vector<int>* vec)
{
    int size = (int)vec->size();
    for(int i = 0; i<size;i+=2)
    {
//        std::cout<<"Nodo: "<<vec->at(i)<<" ";
//        std::cout<<"Arco: "<<vec->at(i+1)<<"\n";

        int row = vec->at(i);
        int column = vec->at(i+1);
        mat[row*n+column] = 1;
        mat[column*n+row] = 1;
    }
}
void Graph::addEdgeList(std::vector<int>* vec)
{
    int size = (int)vec->size();

    for(int i = 0; i<size;i+=2)
    {
//        std::cout<<"Nodo: "<<vec->at(i)<<" ";
//        std::cout<<"Arco: "<<vec->at(i+1)<<"\n";
        int node = vec->at(i);
        int arch = vec->at(i+1);
        list[node].push_back(arch);
        sort(list[node].begin(),list[node].end());
        list[arch].push_back(node);
        sort(list[arch].begin(),list[arch].end());
//        std::cout<<"  1  ";
    }

}

std::vector<int>* Graph::readTxt(std::string fileName)
{
    std::vector<int>* vec = new std::vector<int>;

    std::ifstream doc(fileName);
    if(!doc.is_open())
        return 0;

    std::string aux;
    while(getline(doc,aux))
    {
        char nodeS = aux[1];
        char archS = aux[4];
        int node = nodeS - '0';
        int arch = archS - '0';

        vec->push_back(node);
        vec->push_back(arch);
    }

    return vec;
}
std::string Graph::printAdjMat()
{
    std::stringstream aux;
    for(int i = 0; i<n*n; i++)
    {
        aux<<mat[i]<<" ";
    }
    return aux.str();
}
std::string Graph::printAdjList()
{
    std::stringstream aux;
    for(int i = 0; i<n; i++)
    {
        aux<<"vertex "<<i<<" : ";
        for(int j = 0;j<list[i].size();j++)
        {
            aux<<list[i].at(j)<<" ";
        }
    }
    return aux.str();
}

#endif /* graph_h */
