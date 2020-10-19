# Análisis de un árbol Heap: Implementando una fila priorizada
### Israel Iván Arroyo Parada 
### A01706190
## push
Esta función corre en un tiempo de **O(logn)** pues se debe realizar una revisión de la condición dada. Esto es, cuando se inserta un número, se revisa si es menor que su padre, si es así, se hace un swap. Este proceso puede llegar a hacerse a todos los niveles, que están dados por logn.
## pop
Por sí sola, tiene una complejidad constante de **O(1)**. Esto se debe a que esta operación elimina siempre el primer elemento del heap, en este caso el menor. Por esto la operación se mantendrá igual a pesar de la longitud del heap. Es importante notar que se manda a llamar a heapify al final de la instrucción, que corre en un tiempo diferente.
## top
Top funciona de la misma manera que pop. Corre en un tiempo de **O(1)**, por ser solo una consulta del primer elemento del arreglo.
## empty
Tiene un tiempo de **O(1)**. Esta función es muy sencilla, solo se verifica que la cantidad de elemntos almacenados sea diferente de 0. Siempre se hace esta misa operación.
## size
De la misma forma que empty y top, tiene un tiempo de **O(1)**. Pues solo se consulta un valor de la clase Heap. Este valor indica la cantidad de valores almacenados.
## Funciones adicionales importantes
### heapify y swap
Heapify es muy importante, contiene la condición necesaria para ordenar el árbol heap. Este proceso de verificar que los hijos sean mayores al padre toma un tiempo de **O(nlogn)**.  Heapify puede ser llamado para todos los nodos del árbol, cuando es llamado desde la raíz, esto corre en O(n). Después se hace un swap, que es llamado en un tiempo de O(logn), solo se hace un cambio si el hijo es menor al padre. Y esto se reduce con cada nivel que se recorre.

