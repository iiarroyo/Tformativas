# Análisis de Grafo: sus representaciones y sus recorridos
### Israel Iván Arroyo Parada
### A01706190
## loadGraphMat
Esta función corre en un tiempo de **O(n^2)**, pues se debe inicializar con 0 cada valor en la matriz, de tamaño N*N. Después de esto, se debe llenar con las relaciones deseadas. Esta operación también puede ser O(n^2), en el peor de los casos se debe recorrer la matriz entera si se tiene una relación con cada nodo. Podría caer en O(2*n^2) = O(n^2).
## loadGraphList
La construcción de la lista tiene una complejidad de **O(n)**. A la lista inicializada se le agregan, únicamente, los arcos deseados. Concretamente, la operación sería O (V + E), donde V representa los vértices y E los arcos, porque se llega al índice deseado y se insertan las relaciones. Al final del recorrido se ha visitado toda la lista (V) y se ha insertado cada arco(E). Esto sigue cayendo en O(n).
## DFS
Tiene un tiempo de **O(n)**, en general. Esta búsqueda funciona (DFShelper) como un stack, con recursividad, para poder visitar cada nodo una sola vez. Esto quiere decir que se hace un solo recorrido de todos los elementos del Grafo, hasta llegar al nodo deseado. En el peor de los casos este nodo se encontraría al final del recorrido, haciendo necesario el recorrido del Grafo entero. Esta función integra otros recorridos de lostas con tamaño V (número de vértices), pero sigue cayendo en O(n).
## BFS
Esta búsqueda también tiene un tiempo de **O(n)**, es bastante parecido al DFS. La diferencia se encuentra en que está implementado con un queue y se hace un recorrido por niveles. Detalladamente el recorrido se haría en función al número de vértices y arcos, es decir, que la n está compuesta por V y E. A pesar de esto, permanece la restricción de visitar una sola vez cada nodo. Esto lo hace O(n). También incluye recorridos de O(V), pero permanece el O(n).

