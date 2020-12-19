//
//  heap.h
//  
//
//  Created by Israel Arroyo on 17/10/20.
//  A01706190

#ifndef heap_h
#define heap_h

#include <stdio.h>
#include <sstream>

template <class T>
class Heap
{
private:
    unsigned int maxsize;
    unsigned int count;
    T* values;
    unsigned int parent(unsigned int) const;
    unsigned int left(unsigned int) const;
    unsigned int right(unsigned int) const;
    void heapify(unsigned int);
    void swap(unsigned int, unsigned int);
public:
    Heap(unsigned int);
    void push(int);
    void pop();
    T top();
    bool empty();
    unsigned int size();
    std::string toString() const;
    
};
template <class T>
unsigned int Heap<T>::parent(unsigned int pos) const
{
    return (unsigned int)(pos-1)/2;
}
template <class T>
unsigned int Heap<T>::left(unsigned int pos) const
{
    return (unsigned int) (pos*2) + 1;
}
template <class T>
unsigned int Heap<T>::right(unsigned int pos) const
{
    return (unsigned int) (pos*2) + 2;
}
template <class T>
void Heap<T>::heapify(unsigned int pos)
{
    unsigned int l = left(pos);
    unsigned int r = right(pos);
    unsigned int max = pos;

    if (l <= count && values[l] < values[max])
        max = l;
    if (r <= count && values[r] < values[max])
        max = r;
    if(max!=pos)
    {
        swap(pos,max);
        heapify(max);
    }
        
}
template<class T>
Heap<T>::Heap(unsigned int s)
{
    maxsize = s;
    values = new T[maxsize];
    count = 0;
}
template <class T>
void Heap<T>::push(int val)
{
    if (count >= maxsize)
        return;
    
    unsigned int pos = count;
    count++;
    while (pos > 0 && val < values[parent(pos)])
    {
        values[pos] = values[parent(pos)];
        pos = parent(pos);
    }
    values[pos] = val;

}

template <class T>
void Heap<T>::pop()
{
    if (empty())
        return;

    values[0] = values[count-1];
    count--;
    heapify(0);
}

template <class T>
T Heap<T>::top()
{
    return values[0];
}

template <class T>
bool Heap<T>::empty()
{
    return (count == 0);
}

template<class T>
unsigned int Heap<T>::size()
{
    return count;
}

template <class T>
void Heap<T>::swap(unsigned int i, unsigned int j)
{
    T aux = values[i];
    values[i] = values[j];
    values[j] = aux;
}

template <class T>
std::string Heap<T>::toString() const
{
    std::stringstream aux;
    aux << "[";    for (unsigned int i = 0; i < count; i++) {
        if (i != 0) {
            aux << " ";
        } aux << values[i];
    } aux << "]";
    return aux.str();
}

#endif /* heap_h */
