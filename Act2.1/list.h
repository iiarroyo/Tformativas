//
//  list.h
//
//
// Created by Israel Arroyo on 23/09/20.
// A01706190

#include<iostream>
#include<sstream>
using namespace std;

template <class T> class List;
template <class T>
class Node
{
private:
    Node();
    Node(T);
    Node(T, Node<T>*);
    T value;
    Node<T>* next;
    
    friend class List<T>;
};

template <class T>
Node<T>:: Node(): value(0), next(0){}
template <class T>
Node<T>:: Node(T v): value(v), next(0){}
template <class T>
Node<T>:: Node(T v, Node* n): value(v), next(n){}



template <class T>
class List
{
public:
    List();
    void add(T);
    int find(T);
    void update(int, int);
    T remove(int);
    string toString() const;
    
private:
    Node<T>* head;
    int size;
};
template <class T>
List<T>::List():head(0), size(0){}

template <class T>
void List<T>:: add(T newVal)
{
    Node<T> *newLink, *p;
    newLink = new Node<T>(newVal);
    
    if(head == 0)
    {
//        add first
        newLink->next = head;// apunta a donde apuntaba head(o sea 0)
        head = newLink;
        size++;
        return;
    }
//    add last
    p = head;
    while(p->next != 0)
    {
        p = p->next;
    }
    newLink->next = 0;
    p->next = newLink;
    size++;
}
template <class T>
int List<T>:: find(T val)
{
    Node<T>* p;
    p = head;
    int position = 0;
    while(position<size)
    {
        
        if (val == p->value)
            return position;

        position++;
        p = p->next;
    }
    return -1;
}

template <class T>
T List<T>::remove(int index)
{
    T val;
    Node<T>* p,*q;
    if(head == 0)
        return -1;
   
    if (index == 0)
    {
//        remove first
        p = head;
        head = p->next;
        val = p->value;
        delete p;
        size--;
    }
    else
    {
//        remove en medio
        p = head;
        q = p->next;
        for(int i = 1; i < size; i++)
        {
            if(i == index)
            {
                val = q->value;
                p->next = q->next;
                delete q;
                size--;
            }
            p = p->next;
            q = q->next;
        }
    }

    
    return val;
}

template <class T>
void List<T>:: update(int index, int val)
{
    Node<T>* p;
    if(head == 0)
        return;
    p = head;
    for(int i=0;i<size && p!=0;i++)
    {
        if(i == index)
        {
            p->value = val;
            return;
        }
        p = p->next;
    }
    
}

template <class T>
string List<T>::toString() const
{
    stringstream aux;
    Node<T> *p;
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
