//
//  Act1.1.h
//  
//  ITESM QRO.
//  Israel Ivan Arroyo Parada
//  A01706190

Análisis de complejidad temporal utilizand notacion Big-O.

#suma Iterativa

El ciclo declarado hace que se itere la operacion n numero de veces
desde i =1 hasta n. Esto nos indica que la operación se hace "n" numero de veces.
Por lo tanto, pertenece a O(n).


#suma Recursiva

La funcion se llama a ella misma con cada digito de n.
La recursion de la funcion se calcula cada vez llamandose a sí misma con "(n-1)"
Hara la operacion desde "n", hasta llegar a 0. El numero de veces que se llama la 
funcion es igual a "n".
Por lo tanto, pertenece a O(n)

#suma Directa

El algoritmo utiliza la formula de las propiedades de las sumatorias:

    E =    (n ( n + 1 ))/2

       
Donde la suma comienza en i y termina en n
Por esto, cada vez que se ejecute el código, se correra una vez,
independientemente del valor de n.
Por lo tanto, pertenece a O(1).
