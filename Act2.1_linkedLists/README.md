# Análisis de complejidad listas ligadas
### Israel Iván Arroyo Parada 
### A01706190
## add
Corre en un tiempo de **O(n)**. Esto se debe a que la inserción de un nuevo elemento necesita que se recorra toda la lista, para así agregarlo al final. Esto sucede en todos los casos, el recorrido se siempre lleva al final de la lista, a menos que esté vacía.
## find
La comlejidad de tiempo es de **O(n)**. La búsqueda en listas ligadas simples es estrictamente lineal. Pues es necesario recorrer cada elemento para evaluar la búsqueda. En el mejor de los casos este elemento se encontraría en el primer nodo, pero en el peor podría estar al final de la lista. Por lo tanto, su recorrido es O(n).
## update
Esta función corre en un tiempo de  **O(n)**. Aunque se cuente con el índice deseado, no es posible solo acceder a un nodo. El recorrido debe comenzar desde el primer nodo, hasta llegar al indice indicado. Por lo tanto, se recorre toda la lista en el peor de los casos.
## remove
Corre en **O(n)**. La función remove es bastante parecida a "find" y "update". Se debe comenzar en el primer nodo y terminar en el indice dado. En el mejor de los casos, el índice sería 0 y la operación sería constante O(1). Pero en el peor caso, el recorrido se haría hasta el último nodo, o sea, en tiempo O(n).
