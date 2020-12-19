# Análisis de complejidad algoritmos de ordenamiento
### Israel Iván Arroyo Parada 
### A01706190

## ordenaSeleccion
Este algoritmo corre en un tiempo de **O(n^2)**. En la mayoría de los casos se debe hacer más de un
recorrido al arreglo. El primer recorrido se hace cuando se asigna el menor o mayor elemento a cada lugar
"i" en el arreglo (de 0 hasta n). El segundo se hace cuando se debe encontrar dicho elemento para después
hacer un swap de "i"con "j"(de i hasta n). Un recorrido de O(n) que corre dentro de otro O(n) es O(n)*O(n).
Por lo tanto, la complejidad es O(n^2).

## ordenaBurbuja
Este algoritmo corre, de igual manera, en tiempo **O(n^2)**. Pues se procesan dos "for loops". El primer for
loop recorre el arreglo para asignar un lugar a cada elemento que se ordene. El segundo loop va hacendo
swaps entre cada elemento contiguo, solo si el hay un elemento menor, hasta llegar al elemento "i". Aunque
parece hace  menos trabajo que el algoritmo anterior, pues en cada iteración del segundo "for loop" hace
varios swaps, cae en la categoría de O(n^2).

## ordenaMerge
El "Merge Sort" tiene un tiempo de **O(n*logn)**. La funcion de ordenaMerge utiliza dos funciones
auxiliares; split y mergeArray. "split" corre en un tiempo O(n), pues se divide todo hasta llegar a arreglos de
un solo elemento. La operación "mergeArray" debe comparar los elementos de dos arreglos y decidir cuál
es menor. Esto está hecho en tiempo O(n), pero la operacion se hace con menos frecuencia en cada
llamada iterativa. Este comportamiento es de O(logn) se divide el trabajo a la mitad mientras se mueve
hacia arriba en los niveles del árbol recursivo. Por lo tanto, el tiempo es O(n*logn), el tiempo de "split" se
descarta.

## busqSecuencial
La búsqueda secuencial corre en **O(n)**. Aunque se parta del supesto de un arreglo ordenado, en el peor
de los casos se recorren todos los elementos hasta encontrar uno en particular. Consta de un solo "for
loop"que recorre el arreglo. Por lo tanto, es O(n).

## busqBinaria
La búsqueda binaria corre en tiempo**O(logn)**. No debe recorrer todo el arreglo para encontrar un
elemento. Con cada iteración se divide el trabajo a la mitad en cada iteración, haciendo una especie de
árbol binario. Solo recorre cierta rama, ignorando las demás ramas. Por lo tanto, el tiempo es O(logn).
