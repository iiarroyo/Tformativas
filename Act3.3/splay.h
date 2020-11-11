//
//  splay.h
//  Act3.3
//
//  Created by Israel Arroyo on 25/10/20.
//

#ifndef splay_h
#define splay_h
#include <sstream>
#include <vector>
template <class T> class SplayTree;

template <class T>
class Node
{
public:
    Node(T);
    Node<T>* add(T);
    Node<T>* find(T);
    Node<T>* remove(T);
    void removeChilds();
    void inorder(std::vector<T>&) const;
    
    void print_tree(std::stringstream&) const;
    void preorder(std::vector<T>&) const;
    Node<T>* predecesor();
    
private:
    T value;
    Node* left;
    Node* right;
    Node* parent;
    
    friend class SplayTree<T>;
};


template <class T>
Node<T>::Node(T val): left(0), right(0), parent(0), value(val){}

template <class T>
Node<T>* Node<T>::add(T val)
{
    if (val < value)
    {
        if (left != 0)
        {
            return left->add(val);
        }
        else
        {
            left = new Node<T>(val);
            if (left)

                left->parent = this;
            
            return left;
        }
    }
    else
    {
        if (right != 0)
        {
            return right->add(val);
        }
        else
        {
            right = new Node<T>(val);
            if(right)

                right->parent = this;
            
            return right;
        }
    }
    return 0;
    
}

template <class T>
void Node<T>::print_tree(std::stringstream &aux) const {
    if (parent != 0){
        aux << "\n node " << value;
        aux << " parent " << parent->value;
    }else
        aux << "\n root " << value;
    if (left != 0)
        aux << " left " << left->value;
    if (right != 0)
        aux << " right " << right->value;
    aux << "\n";
    if (left != 0) {
        left->print_tree(aux);
    }
    if (right != 0) {
        right->print_tree(aux);
    }
}

template <class T>
void Node<T>::preorder(std::vector<T>& vec) const
{
    
//    root->left->right
    
    vec.push_back(value);
    
    if (left != 0)
        left->preorder(vec);
    
    if (right != 0)
        right->preorder(vec);
    
}
template <class T>
void Node<T>::inorder(std::vector<T>& vec) const
{
//    left->root->right
    
    if (left != 0)
        left->inorder(vec);
    
    vec.push_back(value);
    
    if (right != 0)
        right->inorder(vec);
   
}

template <class T>
Node<T>* Node<T>::find(T val)
{
 
    if(val == value)
    {
        return this;
    }
    else if (val<value)
    {
        if(left!=0)
            return left->find(val);
        else
            return this;
    }
    else if (val>value)
    {
        if(right!=0)
            return right->find(val);
        else
            return this;
    }
    return 0;
}

template <class T>
Node<T>* Node<T>::predecesor()
{
    Node<T> *le, *ri;

    le = left;
    ri = right;

    if (left == 0)
    {
        if (right != 0)
            right = 0;
        return ri;
    }

    if (left->right == 0)
    {
        left = left->left;
        le->left = 0;
        return le;
    }

    Node<T> *parent, *child;
    parent = left;
    child = left->right;
    while (child->right != 0)
    {
        parent = child;
        child = child->right;
    }
    parent->right = child->left;
    child->left = 0;
    return child;
}

template <class T>
Node<T>* Node<T>::remove(T val)
{
    Node<T> * succ, *old;

    if (val < value)
    {
        if (left != 0)
        {
            if (left->value == val)
            {
                old = left;
                succ = left->predecesor();
                if (succ != 0)
                {
                    succ->left = old->left;
                    succ->right = old->right;
                    succ->parent = old->parent;
                    if(succ->left)
                        succ->left->parent=succ;
                    if(succ->right)
                        succ->right->parent=succ;
                }
                left = succ;
                delete old;
                return this;
            }
            else
            {
                return left->remove(val);
            }
        }
    }

    else if (val > value)
    {
        if (right != 0)
        {
            if (right->value == val)
            {
                old = right;
                succ = right->predecesor();
                if (succ != 0)
                {
                    succ->left = old->left;
                    succ->right = old->right;
                    succ->parent=old->parent;
                    if(succ->left)
                        succ->left->parent=succ;
                    if(succ->right)
                        succ->right->parent=succ;
                }
                right = succ;
                delete old;
                return this;
            }
            else
            {
                return right->remove(val);
            }
        }
    }
    return 0;
}



template <class T>
void Node<T>::removeChilds()
{
    if (left != 0)
    {
        left->removeChilds();
        delete left;
        left = 0;
    }
    if (right != 0)
    {
        right->removeChilds();
        delete right;
        right = 0;
    }
}


template <class T>
class SplayTree
{
public:
    SplayTree();
    void Splay(Node<T>*);
    void rightRot(Node<T>*);
    void leftRot(Node<T>*);
    bool find(T);
    void remove(T);
    
    void add(T);
    std::string inorder() const;
    std::string preorder() const;
    
private:
    Node<T>* root;
};
template <class T>
SplayTree<T>::SplayTree(): root(0){}

template <class T>
void SplayTree<T>::Splay(Node<T>* source)
{
    if(!root)
        return;
    
    while(source->parent)
    {
        Node<T>* grandparent = source->parent->parent;
        if(grandparent == 0)
        {
            if(source == source->parent->left)
                rightRot(source->parent);
            else
                leftRot(source->parent);
        }
        else if(source == source->parent->left &&source->parent == grandparent->left )
        {
//            o
//           /
//          o
//         /
//        o
            rightRot(grandparent);
            rightRot(source->parent);
        }
        else if(source == source->parent->right &&source->parent == grandparent->right )
        {
//            o
//             \
//              o
//               \
//                o
            leftRot(grandparent);
            leftRot(source->parent);
        }
        else if(source == source->parent->left && source->parent == grandparent->right )
        {
//            o
//             \
//              o
//             /
//            o
            rightRot(source->parent);
            leftRot(source->parent);
        }
        else
        {
//            o
//           /
//          o
//           \
//            o
            leftRot(source->parent);
            rightRot(source->parent);
        }
    }
}
template<class T>
void SplayTree<T>::leftRot(Node<T>* source)
{
    Node<T>* p;
    p = source->right;
    source -> right = source -> right -> left;
    if(p -> left!= 0)
        p->left->parent = source;
    
    p -> parent = source -> parent;
    p->left = source;
    source->parent = p;
    
    if(p->parent==0)
        this->root = p;
    else if(source == p->parent->left)
        p->parent->left = p;
    else
        p->parent->right = p;
    
    
    
}
template<class T>
void SplayTree<T>::rightRot(Node<T>* source)
{
    
    Node<T>* p;
    p = source->left;
    source -> left = p -> right;
    if(p -> right)
        p->right->parent = source;
    
    p -> parent = source -> parent;
    p->right = source;
    source->parent = p;
    
    if(p->parent == 0)
        this->root = p;
    else if(source == p->parent->right)
        p->parent->right = p;
    else
        p->parent->left = p;
    
    
   
}

template<class T>
void SplayTree<T>::add(T val)
{
    if (root)
    {
        Node<T>* aux = root->add(val);
        Splay(aux);
    }
    else
        root = new Node<T>(val);
    
}
template <class T>
bool SplayTree<T>::find(T val)
{
    
    if (root)
    {
        Node<T>* aux = root->find(val);
        Splay(aux);
        if(aux)
            return true;
        else
            return false;
    }
    return false;
}

template <class T>
std::string SplayTree<T>::inorder() const
{
    std::vector<T> vec;

    if (root!= 0)
        root->inorder(vec);
    
    std::stringstream aux;
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
std::string SplayTree<T>::preorder() const
{
    std::vector<T> vec;
    if (root!= 0)
        root->preorder(vec);
    
    std::stringstream aux;
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
void SplayTree<T>::remove(T val)
{
    if (root)
    {
        if (val == root->value)
        {
            Node<T> *succ = root->predecesor();
            if (succ != 0)
            {
                succ->left = root->left;
                succ->right = root->right;
                succ->parent=0;
                if(succ->left)
                    succ->left->parent=succ;
                if(succ->right)
                    succ->right->parent=succ;
            }
            delete root;
            root = succ;
        }
        else
        {
            Node<T>*p = root->remove(val);
            if (p != 0)
                Splay(p);
        }
    }

}


#endif /* splay_h */
