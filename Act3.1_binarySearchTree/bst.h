//
//  main.cpp
//  Act3.1
//
//  Created by Israel Arroyo on 12/10/20.
//

#ifndef BST_H_
#define BST_H_
#include <sstream>
#include <vector>
using namespace std;
template <class T> class BST;
template <class T>
class Node {
private:
    T value;
    Node *left, *right;
    Node<T>* predecesor();

public:
    Node(T);
    Node(T, Node<T>*, Node<T>*);
    void add(T);
    bool find(T);
    void remove(T);
    void removeChilds();
    void inorder(vector<T>&) const;
    void preorder(vector<T>&) const;
    void postorder(vector<T>&) const;
    void stringLevelOrder(vector<T>&) const;
    void stringGivenLevel(vector<T>&, int) const;
    int height() const;
    bool ancestors(vector<T>&,T);
    int whatlevelamI(T);

    friend class BST<T>;
};
template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0) {}

template <class T>
void Node<T>::add(T val)
{
    if (val < value)
    {
        if (left != 0)
            left->add(val);
        else
            left = new Node<T>(val);
    }
    else
    {
        if (right != 0)
            right->add(val);
        else
            right = new Node<T>(val);
    }
}
template <class T>
int Node<T>::height() const
{
    int downLeft = 0;
    int downRight = 0;
    
    if (left != 0)
    {
        downLeft = left->height()+1;
    }
    if (right != 0)
    {
        downRight = right->height()+1;
    }
    if (downLeft == 0 && downRight == 0)
        return 1;
    
    return downLeft>downRight? downLeft:downRight;
    
}
template <class T>
void Node<T>::inorder(vector<T>& vec) const
{
//    left->root->right
    
    if (left != 0)
        left->inorder(vec);
    
    vec.push_back(value);
    
    if (right != 0)
        right->inorder(vec);
   
}

template <class T>
void Node<T>::preorder(vector<T>& vec) const
{
    
//    root->left->right
    vec.push_back(value);
    if (left != 0)
    {
        left->preorder(vec);
    }
    if (right != 0)
    {
        right->preorder(vec);
    }
    
}
template<class T>
void Node<T>:: postorder(vector<T>& vec) const
{
//    left->right->root
    if(left !=0)
    {
        left->postorder(vec);
    }
    if (right!=0)
    {
        right->postorder(vec);
    }
    vec.push_back(value);
}
template<class T>
void Node<T>:: stringLevelOrder(vector<T>& vec) const
{
    int h = height();
    for(int level = 1; level <= h;level++)
    {
        stringGivenLevel(vec,level);
    }
}
template<class T>
void Node<T>:: stringGivenLevel(vector<T>& vec, int level) const
{
        if (level == 1)
            vec.push_back(value);
        else if (level > 1)
        {
            if(left!=0)
                left->stringGivenLevel(vec, level-1);
            if(right!=0)
                right->stringGivenLevel(vec, level-1);
        }
}
template <class T>
bool Node<T>::ancestors(vector<T>& vec,T val)
{
    if (val == value)
        return true;
    else if (val < value)
    {
        vec.push_back(value);
        return (left != 0 && left->ancestors(vec,val));
    }
    else if (val > value)
    {
        vec.push_back(value);
        return (right != 0 && right->ancestors(vec,val));
    }
    return false;
}

template <class T>
int Node<T>::whatlevelamI(T val)
{
    if (val == value)
        return 1;
    
    else if (val < value)
    {
        if(left != 0)
            return left->whatlevelamI(val) + 1;
        
    }
    else if (val > value)
    {
        if (right != 0)
            return right->whatlevelamI(val) + 1;
    }
    return -1;
}

template <class T>
bool Node<T>::find(T val)
{
    if (val == value)
        return true;
    
    else if (val < value)
        return (left != 0 && left->find(val));
    else if (val > value)
        return (right != 0 && right->find(val));
    return false;
}
//------------------------------------------------
//------------------------------------------------

template <class T>
class BST {
private:
    Node<T> *root;

public:
    BST();
    
    string visit();
    string ancestors(T);
    int whatlevelamI(T);
    string inorder() const;
    string preorder() const;
    string postorder() const;
    string levelbylevel() const;
    int height() const;
    
    void add(T);
    bool find(T) const;
    
};
template <class T>
BST<T>::BST() : root(0) {}
template <class T>
string BST<T>::visit()
{
    stringstream aux;
    
    if (root!= 0)
    {
        aux<<preorder()<<"\n";
        aux<<inorder()<<"\n";
        aux<<postorder()<<"\n";
        aux<<levelbylevel();
    }
    return aux.str();
}

template <class T>
string BST<T>::inorder() const
{
    vector<T> vec;

    if (root!= 0)
        root->inorder(vec);
    
    stringstream aux;
    aux<<"[";
    for(int i = 0; i<vec.size();i++)
    {
        if(i!=vec.size()-1)
            aux<<vec[i]<<" ";
        else
            aux<<vec[i];
    }
    aux<<"]";
    return aux.str();
}
template <class T>
string BST<T>::preorder() const
{
    vector<T> vec;
    if (root!= 0)
        root->preorder(vec);
    
    stringstream aux;
    aux<<"[";
    for(int i = 0; i<vec.size();i++)
    {
        if(i!=vec.size()-1)
            aux<<vec[i]<<" ";
        else{aux<<vec[i];}
    }
    aux<<"]";
    return aux.str();
}

template <class T>
string BST<T>::postorder() const
{
    vector<T> vec;
    if (root!= 0)
        root->postorder(vec);
    
    stringstream aux;
    aux<<"[";
    for(int i = 0; i<vec.size();i++)
    {
        if(i!=vec.size()-1)
            aux<<vec[i]<<" ";
        else{aux<<vec[i];}
    }
    aux<<"]";
    return aux.str();
}
template <class T>
string BST<T>::levelbylevel() const
{
    //    basado en
    //https://www.geeksforgeeks.org/level-order-tree-traversal/
    vector<T> vec;
    if (root!= 0)
    {
        root->stringLevelOrder(vec);
    }
   
    stringstream aux;
    aux<<"[";
    for(int i = 0; i<vec.size();i++)
    {
        if(i!=vec.size()-1)
            aux<<vec[i]<<" ";
        else{aux<<vec[i];}
    }
    aux<<"]";
    return aux.str();
}
template<class T>
int BST<T>::height() const
{
    return root->height();
}

template <class T>
string BST<T>::ancestors(T val)
{
    if(root ==0)
        return"[]";
    bool flag = true;
    vector<T> vec;
    flag = root->ancestors(vec, val);
    stringstream aux;
    aux<<"[";
    for(int i = 0; flag &&i<vec.size();i++)
    {
        if(i!=vec.size()-1)
            aux<<vec[i]<<" ";
        else{aux<<vec[i];}
    }
    aux<<"]";
    return aux.str();
}

template <class T>
int BST<T>::whatlevelamI(T val)
{
    int temp;
    if (root != 0)
    {
        temp = root->whatlevelamI(val);
        if(temp < 0)
            return -1;
        return temp;
    }
    return -1;
}

template<class T>
void BST<T>::add(T val) {
    if (root != 0) {
        if (!root->find(val)) {
            root->add(val);
        }
    } else {
        root = new Node<T>(val);
    }
}

template <class T>
bool BST<T>::find(T val) const
{
    if (root != 0)
        return root->find(val);
    else
        return false;
}
#endif /* BST_H_ */


