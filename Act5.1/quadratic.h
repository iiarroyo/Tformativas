//
//  quadratic.h
//
//
//  Created by Israel Arroyo on 25/11/20.
//  A01706190

#ifndef HASH_H_
#define HASH_H_

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
  std::string toString();
  void put();
};
// impresion clase quadratic
template <class Key, class Value>
std::string Quadratic<Key, Value>::toString() const {
    std::stringstream aux;
    for (int i = 0; i < size; i++){
            if (keys[i] != initialValue){
                aux << "(" << i << " ";
              aux << keys[i] << " : " << values[i] << ") ";
            }
    }
    return aux.str();
  }
#endif /* HASH_H_ */
