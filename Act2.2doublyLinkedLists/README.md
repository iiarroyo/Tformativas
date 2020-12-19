# Análisis de complejidad listas  doblemente ligadas
### Israel Iván Arroyo Parada 
### A01706190
## add
Corre en un tiempo de **O(1)**. Esto se debe a que la inserción de un nuevo elemento no necesita que se recorra toda la lista (como anteriormente), para así agregarlo al final. La función se dirige a la cola de la lista e inserta el elemento ahí, en el caso de estar vacío el proceso es bastante parecido. Debido a esto, la operación es la misma, independientemente de la cantidad de datos.
## find
La comlejidad de tiempo es de **O(n)**. La situación es igual a las listas ligadas simples. Pues es necesario recorrer cada elemento para evaluar la búsqueda. En el mejor de los casos este elemento se encontraría en el primer nodo, pero en el peor podría estar al final de la lista. Por lo tanto, su recorrido es O(n).
## update
Esta función corre en un tiempo de  **O(n)**. Aunque se cuente con el índice deseado, no es posible solo acceder a un nodo. Al igual que con las listas ligadas simples. El recorrido debe comenzar desde el primer nodo, hasta llegar al indice indicado. Por lo tanto, se recorre toda la lista en el peor de los casos.
## remove
Corre en **O(n)**. La función remove es bastante parecida a "find" y "update", y pasa lo mismo que con las listas ligadas simples. Se debe comenzar en el primer nodo y terminar en el indice dado. En el mejor de los casos, el índice sería 0 y la operación sería constante O(1). Pero en el peor caso, el recorrido se haría hasta el último nodo, o sea, en tiempo O(n).
