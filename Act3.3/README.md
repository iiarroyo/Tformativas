# Análisis de un árbol Desplegado: Implementando un Splay Tree
### Israel Iván Arroyo Parada 
### A01706190

De acuerdo con (Geeks for Geeks, 2019), cualquier operacion de un Splay tree tiene un tiempo de **O(logn)**. Pero es importante aclarar que se puede llegar a un caso **O(n)**, si las inserciones llevan a un árbol degenerado. En este caso, se tomará un caso común con un árbol balanceado con complejidad promedio de O(logn).

Geeks for Geeks. (2019). Splay Tree | Set 1 (Search). 1 de nov. 2020, de NA Sitio web: https://www.geeksforgeeks.org/splay-tree-set-1-insert/

## add
Esta función está dada en un tiempo de **O(log*n)** por tratarse de un BST balanceado. El dato a insertar no debe ser evaluado por cada elemento del árbol. Esto, sin tomar en cuenta la operación Splay.
## remove
También corre en **O(log*n)**. Pues la búsqueda del elemento a eliminar se hace en dicho tiempo. Aquí no se toma en cuenta la operación Splay, que se hace después.
## find
Al tratarse de un árbol balanceado, la operación es **O(log*n)**. Lo que deriva en un recorrido de un nodo a la vez, por cada nivel del árbol. Con cada nivel se reduce la cantidad de nodos a una razón de O(log*n).
## inorder
Este recorrido del árbol toma un tiempo de **O(n)**. Para imprimir cada nodo, se debe recorrer cada elemento del árbol una vez. Por lo tanto pertenece a una operación lineal O(n).
## size
Por la implentación hecha, corre en **O(1)**. La clase Splay tiene una variable size, que aumenta y disminuye con cada inserción y eliminación de nodos. La función regresa dicho valor.

## splay
Tiene una complejidad **O(logn)**. Esto se debe al recorrido que se debe hacer para llevar un nodo a la raíz. En el peor de los casos se haría un Splay en una hoja y se tendría que hacer un recorrido por cada nivel, resultando en un tiempo de O(logn).
