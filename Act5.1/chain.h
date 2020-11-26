//
//  chain.h
//
//
//  Created by Israel Arroyo on 25/11/20.
//  A01706190

#ifndef CHAIN_H_
#define CHAIN_H_

#include <string>
#include <sstream>

template <class Key, class Value>
class Chain
{
private:
  unsigned int (*func) (const Key);
	unsigned int size;
	unsigned int count;

  Key *keys;
	Key initialValue;
	Value *values;

  long indexOf(const Key) const;
  
public:
  void put();
  std::string toString();

};

// impresion en la clase chain
template <class Key, class Value>
std::string Chain<Key, Value>::toString() const {
    std::stringstream aux;
    for (int i = 0; i < size; i++){
            if (!keys[i].empty()){
                aux <<"(" << i ;
                for (int j = 0; j < keys[i].size(); j ++){
                         aux << " [" << keys[i][j] << " : " << values[i][j] << "]";
                }
                aux <<") ";
            }
    }
    return aux.str();
}

#endif
