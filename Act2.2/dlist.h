//
//  list.h
//
//
//  Created by Israel Arroyo on 28/09/20.
//  A01706190

#include<iostream>
#include<sstream>
using namespace std;

template <class T> class DList;
template <class T>
class Node
{
private:
    Node();
    Node(T);
    Node(T, Node<T>*, Node<T>*);
    T value;
    Node<T>* next;
    Node<T>* previous;
    
    friend class DList<T>;
};

template <class T>
Node<T>:: Node(): value(0), next(0), previous(0){}
template <class T>
Node<T>:: Node(T v): value(v), next(0), previous(0){}
template <class T>
Node<T>:: Node(T v, Node* n, Node* p): value(v), next(n), previous(p){}


template <class T>
class DList
{
public:
    DList();
    void add(T);
    int find(T);
    void update(int, int);
    T remove(int);
    string toStringBackward() const;
    string toStringForward() const;
    
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
};
template <class T>
DList<T>::DList():head(0),tail(0), size(0){}

template <class T>
void DList<T>:: add(T newVal)
{
    Node<T> *newLink, *p;
    newLink = new Node<T>(newVal);
    
    if(head == 0)
    {
//        add empty
        head = newLink;
        tail = newLink;
    }
    else if(head->previous)
    {
//        add first
        newLink->next=head;
        head->previous = newLink;
        head = newLink;
    }

    else
    {
//       add last
        tail->next = newLink;
        newLink->previous = tail;
        tail = newLink;
    }
   
    size++;
}
template <class T>
int DList<T>:: find(T val)
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
T DList<T>::remove(int index)
{
    T val;
    Node<T>* p,*q;
    if(head == 0)
        return -1;
    p = head;
    val = p->value;
// remove 1 elem
    if(head == tail)
    {
        head = 0;
        tail = 0;
        delete p;
        size--;
    }
    if (index == 0)
    {
//        remove first

        head = p->next;
        p->next->previous = 0;// apuntar sig elemento a p
        delete p;
        size--;
    }
    else
    {
//        remove en medio

        q = p->next;
        for(int i = 1; i < size; i++)
        {
            if(i == index)
            {
                val = q->value;
                p->next = q->next;
                q->next->previous = p;
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
void DList<T>:: update(int index, int val)
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


// Incluye estos funciones en tu dlist.h para poder imprimir tus respuestas
// en formatos compatibles con el main
template <class T>
string DList<T>::toStringForward() const {
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
template <class T>
string DList<T>::toStringBackward() const {
    stringstream aux;
    Node<T> *p;
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
