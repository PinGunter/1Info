### Ejercicio Práctica 8

Salvador Romero Cortés

---

#### Ejercicio 1

*Utilizando los archivos disponibles en la carpeta de la sesión 8 (main.cpp, factorial.cpp y hello.cpp). Ejecuta la siguiente orden*

```bash
g++ main.cpp factorial.cpp hello.cpp -o ejecutable
```

*Una vez compilado el código, utiliza la herramienta **gdb** para ver el código del programa principal. Describe qué sucede al intentar ver las líneas del código del <u>main</u> y cómo harías para ver el código por medio del depurador. Indica cómo se puede salir del depurador.*

Ejecución de la línea

![](/home/salvaromero/Imágenes/Captura de pantalla de 2020-05-23 18-33-32.png)

Ejecutamos gdb

![](/home/salvaromero/Imágenes/Captura de pantalla de 2020-05-23 18-34-11.png)

Intentamos ver las líneas del código de <u>main</u>

![](/home/salvaromero/Imágenes/Captura de pantalla de 2020-05-23 18-34-50.png)

Da error, porque al compilar no hemos incluido información de depuración con el parámetro `-g`.

Para poder ver las líneas, volvemos a compilar el programa con el parámetro `-g`. Quedaría así la orden:

```bash
g++ -g main.cpp factorial.cpp hello.cpp -o ejecutable
```

![](/home/salvaromero/Imágenes/Captura de pantalla de 2020-05-23 18-37-13.png)

Como podemos ver, ahora no da error.

Para ver el código de main usamos la orden sentencia `list`.

```bash
list main
```

![](/home/salvaromero/Imágenes/Captura de pantalla de 2020-05-23 18-38-38.png)

Ahí podemos ver las 10 primeras líneas de la función main, podemos ver más lineas si añadimos al final de la orden list un rango de líneas. Por ejemplo:

```bash
list 1,11
```

![](/home/salvaromero/Imágenes/Captura de pantalla de 2020-05-23 18-40-54.png)

Para cerrar el depurador gdb, escribimos la orden `quit` (también podemos usar `q`)

![](/home/salvaromero/Imágenes/Captura de pantalla de 2020-05-23 18-41-38.png)

#### Ejercicio 2

*¿Cómo harías para ejecutar la función factorial del ejercicio anterior? Muestra una captura de pantalla indicando el resultado y cómo has llegado a él.*

Para ejecutar la función factorial podemos poner un breakpoint en su llamada. Para ello usamos la orden `break`.  Podemos usar el nombre de la función o la línea.

```bash
break factorial
```

A continuación ejecutamos el programa con la orden `run`. Y podemos ejecutar la función factorial paso a paso usando la orden `next`.

![](/home/salvaromero/Imágenes/Captura de pantalla de 2020-05-23 19-25-31.png)

Aquí vemos como se ejecuta la función factorial. Al haber usado `break factorial`, aparecen paso a paso todas las llamadas a factorial. Si quisieramos aun más pasos podríamos haber utlizado la orden `step`en lugar de `next`.



#### Ejercicio 3.
Compila el código del siguiente programa y haz todas las configuraciones necesarias con **gdb** para mostrar el valor de la variable **final2** justo antes de que se le asigne ningún valor dentro del bucle for . Describe todos los pasos que has seguido e incluye una captura de pantalla de los mismos.

Compilamos el programa

```bash
g++ -g ejercicio3.cpp -o ejercicio3
```

![](/home/salvaromero/Imágenes/Captura de pantalla de 2020-05-23 19-37-50.png)

Ejecutamos gdb

```bash
gdb ejercicio3
```

![](/home/salvaromero/Imágenes/Captura de pantalla de 2020-05-23 19-39-49.png)

Para ello ponemos un punto de ruptura donde aparece la variable **final2**. Lo podemos ver con list.

```bash
list 1,34
```

![](/home/salvaromero/Imágenes/Captura de pantalla de 2020-05-23 19-45-12.png)

Vemos que es en la línea 29, ponemos un punto de ruptura ahí.

```bash
break 29
```

![](/home/salvaromero/Imágenes/Captura de pantalla de 2020-05-23 19-40-20.png)

Ahora ejecutamos el programa y cuando se detenga en el punto de ruptura mostramos el valor de la variable. Usamos las órdenes `run` para ejecutar el programa y la orden 

```bash
display final2
```

para mostrar la variable.

Ejecutamos el programa y se detiene en el punto de ruptura:

![](/home/salvaromero/Imágenes/Captura de pantalla de 2020-05-23 19-41-31.png)

Ahora usamos `display`

![](/home/salvaromero/Imágenes/Captura de pantalla de 2020-05-23 19-42-19.png)

Por tanto, podemos ver que la variable **final2** tiene el valor 0 antes de ser asignado otro por el bucle for.



#### Ejercicio 4

Usamos un punto de ruptura condicional que detenga el programa cuando la variable i valga 50.

```bash
break 29 if i==50
```

Una vez creado el punto de ruptura, ejecutamos con la orden `run` y vemos los valores de las variables con la orden `display`.

![](/home/salvaromero/Imágenes/Captura de pantalla de 2020-05-23 19-49-02.png)

Sin embargo, la variable final2 puede tener dos valores cuando i vale 50. Puede tener el valor antes de la asignación del bucle for (mostrado en la captura anterior). O el valor tras la asignación del bucle for. En ambos casos la variable i vale 50. Para ver el segundo caso usamos la orden `next`.

![](/home/salvaromero/Imágenes/Captura de pantalla de 2020-05-23 19-54-23.png)

Como vemos, en el segundo caso la variable final2 vale 52 mientras que la i sigue valiendo 50.



#### Ejercicio 5

*Con el mismo código del ejercicio anterior no aparece que la variable **final2** pueda ser mayor de 101. Utilizando el depurador **gdb** haz, que <u>sin tocar la variable **final2**</u>, esta variable tenga un valor por encima de 1000 al final del programa. Describe todos los pasos que has seguido para conseguirlo e incluye la captura de pantalla correspondiente.*

Hay varias maneras de hacerlo, yo lo voy a hacer modificando el valor de retorno de la función `cuenta(int)` cuando la i valga 99 (última iteración). Para ello debemos hacer lo siguiente:

* 1. Iniciar el depurador **gdb**

     ![](/home/salvaromero/Imágenes/Captura de pantalla de 2020-05-23 20-07-18.png)

* 2. Establecemos un punto de ruptura condicional en la línea 29 (donde se llama a la función cuenta) que se active cuando i valga 99 (última iteración).

     ![](/home/salvaromero/Imágenes/Captura de pantalla de 2020-05-23 20-08-09.png)

* 3. Establecemos otro punto de ruptura al final del programa, donde observaremos el valor de la variable final2.

     ![](/home/salvaromero/Imágenes/Captura de pantalla de 2020-05-23 20-09-07.png)

* 4. Ejecutamos el programa con la orden `run` y luego utilizamos la orden `step` hasta llegar al valor de retorno de la función

     ![](/home/salvaromero/Imágenes/Captura de pantalla de 2020-05-23 20-10-27.png)

* 5. Ahora modificamos el valor de `tmp` antes de que lo devuelva. Usamos la orden `set variable`

     ![](/home/salvaromero/Imágenes/Captura de pantalla de 2020-05-23 20-11-10.png)

* 6. Continuamos con la ejecución del programa hasta llegar al final, donde habíamos puesto el segundo punto de ruptura

     ![](/home/salvaromero/Imágenes/Captura de pantalla de 2020-05-23 20-11-48.png)

* 7. Y ahora usamos la orden `display` para ver cuanto vale **final2**

     ![](/home/salvaromero/Imágenes/Captura de pantalla de 2020-05-23 20-12-43.png)

Conseguimos de esta manera que la variable valga 1001 al final del programa.