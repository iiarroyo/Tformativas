/*
 * main.cpp
 *
 *  Created on: 29/10/2020
 *      Author: clase
 */

#include <iostream>
#include <cstring>
#include <string>
#include "quadratic.h"
#include "chain.h"


using namespace std;

/* // impresion clase quadratic
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
*/

/* // impresion en la clase chain
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
*/

unsigned int myHash(const string s) {
    unsigned int acum = 0;
    for (unsigned int i = 0; i < s.size(); i++) {
        acum += (int) s[i];
    }
    return acum;
}

int main(int argc, char* argv[]) {

        Chain <string, int> chain_hash(10, myHash);
        Quadratic <string, int> quad_hash(10, string("empty"), myHash);

        string c_ans, q_ans;

            quad_hash.put(string("tecnica"), 11);
            quad_hash.put(string("casa"), 12);
            quad_hash.put(string("caza"), 13);
            quad_hash.put(string("amos"), 15);
            quad_hash.put(string("magneto"), 17);
            quad_hash.put(string("operador"), 18);
            quad_hash.put(string("taza"), 18);

            chain_hash.put(string("tecnica"), 11);
            chain_hash.put(string("casa"), 12);
            chain_hash.put(string("caza"), 13);
            chain_hash.put(string("amos"), 15);
            chain_hash.put(string("magneto"), 17);
            chain_hash.put(string("operador"), 18);
            chain_hash.put(string("taza"), 18);

            c_ans = "(0 [operador : 18]) (2 [amos : 15] [taza : 18]) (5 [caza : 13]) (7 [tecnica : 11] [magneto : 17]) (8 [casa : 12]) ";
            q_ans = "(0 operador : 18) (1 magneto : 17) (2 amos : 15) (3 taza : 18) (5 caza : 13) (7 tecnica : 11) (8 casa : 12) ";

        cout << " 1 " <<    ( (!c_ans.compare(chain_hash.toString().c_str())) ? "success\n" : "fail\n");

            cout << " 2 " <<    ( (!q_ans.compare(quad_hash.toString().c_str())) ? "success\n" : "fail\n");

            quad_hash.put(string("max"), 99);
            quad_hash.put(string("cocacola"), 188);

            chain_hash.put(string("max"), 99);
            chain_hash.put(string("cocacola"), 188);

            c_ans = "(0 [operador : 18]) (1 [cocacola : 188]) (2 [amos : 15] [taza : 18]) (5 [caza : 13]) (6 [max : 99]) (7 [tecnica : 11] [magneto : 17]) (8 [casa : 12]) ";
            q_ans = "(0 operador : 18) (1 magneto : 17) (2 amos : 15) (3 taza : 18) (5 caza : 13) (6 max : 99) (7 tecnica : 11) (8 casa : 12) ";

            cout << " 3 " <<    ( (!c_ans.compare(chain_hash.toString().c_str())) ? "success\n" : "fail\n");

            cout << " 4 " <<    ( (!q_ans.compare(quad_hash.toString().c_str())) ? "success\n" : "fail\n");

            return 0;
}
