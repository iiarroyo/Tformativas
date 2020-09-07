//
//  sorts.h
//  
//
//  Israel Arroyo A01706190
//
//Algoritmos de ordenamiento y de busqueda

#ifndef sorts_h
#define sorts_h

#include <vector>
#include <iostream>
#include <list>

using namespace std;

template < class T >
class Sorts
{
private:
    void swap(vector<T>& , int , int );
    void mergeSplit(vector<T>& , vector<T>& , int , int );
    void copyArray(vector<T>& , vector<T>& , int , int );
    void mergeArray(vector<T>& A, vector<T>& B, int i, int j, int k);
 
public:
    void ordenaSeleccion(vector<T>& v);
    void ordenaBurbuja(vector<T>& v);
    void ordenaMerge(vector<T>& v);
    int busqSecuencial(vector<T>& v, int val);
    int busqBinaria(vector<T>& v, int val);
    
};
template <class T>
void Sorts<T>::swap(vector<T>& v, int i, int j)
{
    int aux = v[i];
    v[i]=v[j];
    v[j]= aux;
}
template <class T>
void Sorts<T>::ordenaSeleccion(vector<T>& v)
{
    int n = v.size()-1;
    for(int i = 0; i < n; i++)
    {
        int pos = i;
        for (int j = i; j <= n; j++ )
        {
            if (v[j]<v[pos])
                pos = j;
        }
        if(pos!=i)
            swap(v,i,pos);
        
    }
}
template <class T>
void Sorts<T>::ordenaBurbuja(vector<T>& v)
{
    int n = v.size() - 1;
    for (int i = 0; i < n; i++)
    {
        for(int j = n ; j > i; j--)
        {
            if(v[j] < v[j-1])
            {
                swap(v,j,j-1);
            }
        }
    }
}

template <class T>
void Sorts<T>::ordenaMerge(vector<T>& v)
{
    vector<T> aux(v.size());
    mergeSplit(v,aux,0,v.size()-1);
}

template <class T>
void Sorts<T>::mergeSplit(vector<T>& A, vector<T>& B, int first, int last)
{
//    first = principio de arreglo
//    last = final de arreglo
 
    if(first < last)
    {
        int mid = (first + last) / 2;
        
        mergeSplit(A, B, first, mid);
        mergeSplit(A, B, mid + 1, last);
        mergeArray(A, B, first, last,mid);
        copyArray(A, B, first, last);
    }
    
}

template <class T>
void Sorts<T>::mergeArray(vector<T>& A, vector<T>& B, int first, int last, int mid)
{
    int i = first;
    int j = mid +1;
    int posB = first;

    //    i = principio de 1er arreglo
    //    j = principio de 2o arreglo
    //    mid = final de 1er arreglo
    
    
    while(i <= mid && j <= last)
    {
        if(A[i] < A[j])
        {
            B[posB] = A[i];
            i++;
        }
        else
        {
            B[posB] = A[j];
            j++;
        }
        posB++;
     }
    
    while(i <= mid)
    {
        B[posB] = A[i];
        posB++;
        i++;
    }
    while(j <= last)
    {
        B[posB] = A[j];
        posB++;
        j++;
    }

     
}

template <class T>
void Sorts<T>::copyArray(vector<T>& A, vector<T>& B, int first, int last)
{

    for (int x = first; x <= last; x++) {
        A[x] = B[x];
    }
}

template <class T>
int Sorts<T>::busqBinaria(vector<T>& v, int val)
{
    int last = v.size() - 1;
    int first = 0;
    int mid;
    bool found = false;
    bool more = (first <= last);
    
    while (!found && more)
    {
        mid = (first + last) /2;
        if(val < v[mid])
        {
            last = mid - 1;
            more = first <= last;
        }
        
        else if(val > v[mid])
        {
            first = mid + 1;
            more = first <= last;
        }
            
        else if (v[mid] == val)
            found = true;
    }
    
    return mid;
}

template <class T>
int Sorts<T>::busqSecuencial(vector<T>& v, int val)
{
    int size = v.size();
    bool found = true;
    for(int i = 0; i<size && found; i++)
    {
        if (val == v[i])
            return i;
        else if(v[i]>val)
            found = false;
    }
    return -1;
}

#endif /* sorts_h */
