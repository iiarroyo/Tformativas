//
//  Act1.1.h
//  
//  ITESM QRO.
//  Israel Ivan Arroyo Parada
//  A01706190

Análisis de complejidad temporal utilizand notacion Big-O.

#suma Iterativa

El ciclo declarado hace que se itere la operacion n numero de veces
desde "i = 1" hasta "n", utilizando un acumulado que se entrega al final. Si se ejecuta el código con el número 5, la suma se hara como: 1 + 2 + 3 + 4 + 5. Donde se suma cada número y se avanza con un iterador "i". Al final se entrega el acumulado en la variable "acum". Se puede ver que los pasos se hacen "n" número de veces, la suma de la iteración y la suma del acumulado.
Por lo tanto, pertenece a O(n).


#suma Recursiva

La funcion se llama a ella misma con cada digito de "n".
La recursion de la funcion se calcula cada vez llamandose a sí misma con "(n-1)". Si se llana la funcion con el nuemro 5, la suma se hara como 5 + 4 + 2 + 1 + 0. La funcion se mueve entre los digitos restando un digito, hasta llegar a cero y empezar a regresar cada dígito de cada "nivel" de recursion.
Por lo tanto, pertenece a O(n)

#suma Directa

El algoritmo utiliza la formula de las propiedades de las sumatorias:

    E =    (n ( n + 1 ))/2

       
Donde la suma comienza en "i = 1" y termina en "n"
Por esto, cada vez que se ejecute el código, se correra una sola vez,
independientemente del valor de "n". Si se llama la funcion con el numero 5 solo se calculara como : (5 * (5 + 1))/2. Sin importar el numero "n" se hara un solo calculo.
Por lo tanto, pertenece a O(1).
