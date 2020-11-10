# Análisis de Grafo: sus representaciones y sus recorridos
### Israel Iván Arroyo Parada
### A01706190
## loadGraphMat
Esta función corre en un tiempo de **O(n^2)**, pues se debe inicializar con 0 cada valor en la matriz, de tamaño N*N. Además, en el peor de los casos se debe recorrer la matriz entera si se tiene una relación con cada nodo.
## loadGraphList
La construcción de la lista tiene una complejidad de **O(n)**. A la lista inicializada se le agregan, únicamente, los arcos deseados. Por lo tanto, no depende del número de vértices y el valor de "n" está dada por los arcos.
## DFS
Tiene un tiempo de **O(n)**. Esta búsqueda funciona como un stack, con recursividad, para se visitar cada nodo una sola vez. Esto quiere decir que se hace un recorrido de todos los elementos del Grafo, hasta llegar al nodo deseado. En el peor de los casos este nodo se encontraría al final del recorrido, haciendo necesario el recorrido del Grafo entero.
## BFS
Esta búsqueda también tiene un tiempo de **O(n)**, es bastante parecido al DFS.La diferencia se encuentra en que está implementado con un queue y se hace un recorrido por niveles. A pesar de esto, permanece la restricción de visitar una sola vez cada nodo. Esto lo hace O(n).
