### Módulo 2 de prácticas

**Ejercicio 7.1**

*Pruebe a comentar en el archivo fuente main.cpp la directiva de procesamiento “#include ”functions.h”. La línea quedaría así: //#include ”functions.h”. Pruebe a generar ahora el módulo objeto con la orden de compilación mostrada anteriormente. ¿Qué ha ocurrido?*

Da error de compilación puesto que estamos haciendo a referencias externas no declaradas ni definidas.

```bash
# El mensaje de error es el siguiente:
main.cpp: In function ‘int main()’:
main.cpp:7:5: error: ‘print_hello’ was not declared in this scope
    7 |     print_hello();
      |     ^~~~~~~~~~~
main.cpp:9:41: error: ‘factorial’ was not declared in this scope
    9 |     cout << "The factorial of 7 is " << factorial(7) << endl;
      |           
```

**Ejercicio 7.2**

*Explique por qué el enlazador no ha podido generar el programa archivo ejecutable programa2 del
ejemplo anterior y, sin embargo, ¿por qué sí hemos podido generar el módulo main2.o?*

Porque lo que ha hecho ha sido generar un módulo objeto, que no resuelve las referencias externas.

**Ejercicio 7.3** 

*Explique por qué la orden g++ previa ha fallado. Explique los tipos de errores que ha encontrado.*

Ha fallado porque el compilador no encuentra el archivo "funciones.h" ya que lo hemos movido del mismo directorio que donde están los .cpp. El error es:

```bash
functions.h: No existe el archivo o el directorio
```

**Ejercicio 7.4** 

*Copie el contenido del makefile previo a un archivo llamado makefileE ubicado en el mismo directorio en el que están los archivos de código fuente .cpp. Pruebe a modificar distintos archivos .cpp (puede hacerlo  usando la orden touch sobre uno o varios de esos archivos) y compruebe la secuencia de instrucciones que se muestra en el terminal al ejecutarse la orden make. ¿Se genera siempre la misma secuencia de órdenes cuando los archivos han sido modificados que cuando no? ¿A qué cree puede deberse tal comportamiento?*

No se genera la misma secuencia. Sin cambiar nada se genera:

```bash
make -f makefileE
ar -rvs libmates.a sin.o cos.o tan.o
r - sin.o
r - cos.o
r - tan.o
g++ -L./ -o programa2 main2.o factorial.o hello.o -lmates
```

Si cambiamos el hello.cpp la secuencia queda como:

```bash
make -f makefileE
g++ -I./includes -c main2.cpp
g++ -I./includes -c factorial.cpp
g++ -I./includes -c hello.cpp
g++ -I./includes -c sin.cpp
g++ -I./includes -c cos.cpp
g++ -I./includes -c tan.cpp
ar -rvs libmates.a sin.o cos.o tan.o
r - sin.o
r - cos.o
r - tan.o
g++ -L./ -o programa2 main2.o factorial.o hello.o -lmates
```

Se vuelve a compilar todo lo que depende de hello.cpp

**Ejercicio 7.5**

*Obtener un nuevo makefileF a partir del makefile del ejercicio anterior que incluya además las dependencias sobre los archivos de cabecera. Pruebe a modificar cualqueir archivo de cabecera (usando la orden `touch`) y compruebe la secuencia de instrucciones que se muestra en el terminal al ejecutarse la orden `make`.*