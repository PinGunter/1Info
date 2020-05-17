###  Ejercicio 2 Tema 2 Fundamentos del Software

###### 30/3/2020

**a) Indique el formato de la dirección virtual**

* Sabemos que las páginas son de `8KB`, o lo que es lo mismo `2¹³ bytes` -> tamaño de la pagina (muy ligado con el desplzamiento, nos podemos desplazar desde 0 hasta el tamaño de la página)

* Sabemos que la memoria virtual es de `2³² bytes`

*Direcciones virtuales: 19 bits (memoria virtual - tamaño de pagina) iniciales para indicar la PÁGINA + 13 bits restantes para indicar el DESPLAZAMIENTO  (tamaño de la pagina) dentro de la página*

Por lo tanto el formato de la dirección virtual sería un bloque de 32 bits donde los 19 bits iniciales son del número de página y los 13 siguientes del desplazamiento.

**b) Indique la dirección física correspondiente a la dirección virtual 0x0000608A**

La dirección virtual es: `0x0000608A`. 

Su equivalente en binario es  `0000 0000 0000 0000 0110 0000 1000 1010`.

Hemos dicho que los 19 bits iniciales son del número de página:

* <u>Página</u>: `0000 0000 0000 0000 011` --> página 3 (si vamos a la tabla de páginas: la página 3 está almacenada en el marco de página 14: `1110`)

* <u>Desplazamiento</u>: `0 0000 1000 1010` 

Por lo tanto la **dirección física** es : <span style='color:blue'>`0000 000`</span><span style='color:orange'>`1110`</span><span style='color:green'>`0 0000 1000 1010`</span>

Siendo el azul: relleno hasta 23 bytes, amarillo: marco de página, verde: desplazamiento

**c) ¿Cuál es el tamaño que ocupa el espacio de direcciones virtuales de este programa?**

`8KB`  *(tamaño de página)* `* 10` *(número de páginas)*

**d) Exprese en MB el tamaño de la memoria principal**

`2²³ bytes =8MB` 