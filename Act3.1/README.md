# Análisis de complejidad Operaciones avanzadas en un BST
### Israel Iván Arroyo Parada 
### A01706190

## visit
Visit está funciona uniendo diferentes maneras de representar un árbol en un arreglo. Es importante revisar cada una y sus respectivas compeljidades.
### inorder, postorder y preorder
Estas tres funciones hacen un único recorrido del árbol entero, solo cambia el orden de la impresión. Por lo tanto, corren en un tiempo de **O(n)**. Este orden de impresión está dado como:
- inorder: left -> root -> right
- preorder: root -> left -> right
- postorder: left -> right -> root

### level by level
Esta última manera toma un tiempo de **O(n^2)**. Esto se debe a que la función recursiva es llamada por un loop "for" que depende de los niveles que se requieran recorrer.

## height
Calcular la altura máxima de un árbol toma tiempo de **O(n)**. Pues se debe llegar hasta el fondo del árbol recorriendo cada rama y comparar los valores sumados por la recursión. Cualquiera de estas dos operaciones puede tomar un tiempo de O(log*n) si se trata de un árbol balanceado. Por otra parte, debemos considerar el peor de los casos. Por lo tanto, el tiempo es O(n).

## ancestors
Ancestors corre con una compeljidad de **O(n)**. Esta función utiliza como esqueleto la función de find, con la diferencia de imprimir cada nodo que recorre.Y aunque pueda descartar ramas enteras, existe la posibilidad de un desbalance en el árbol. Por lo tanto, el tiempo es O(n).

## whatlevelamI
Esta función corre en un tiempo de **O(n)**. En todas las operaciones de BST debemos tomar en cuenta la posibilidad de un árbol degenerado.
What Level Am I funciona como ancestors, con la función find. En un árbol balanceado tomaría un tiempo de O(log*n). Pero en el peor de los casos corre en O(n).


