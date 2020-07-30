### Ejercicio Práctica 7

Salvador Romero Cortés

---

#### Ejercicio 1

*Considerando los ficheros proporcionados ( main2.cpp, factorial.cpp, hello.cpp, sin.cpp, cos.cpp y tan.cpp ), realiza las siguientes operaciones por pasos (no te saltes ninguno y ve mostrando cada uno de los resultados requeridos):*

  1. *Escribe en un archivo makefile las órdenes necesarias para que dé la posibilidad de* *crear el archivo compilado **hello.o.***
      	*a. Mediante el makefile, haz que se cree dicho fichero.*
  2. *Modifica el mismo archivo para se puedan compilar los archivos **tan.cpp**, **cos.cpp** y **sin.cpp** y obtener sus correspondientes archivos objeto.*
      	*a. Mediante el makefile, haz que se creen cada uno de los ficheros* independientemente.*
      *b. Mediante el makefile, haz que se creen cada uno de los ficheros de 1 sola vez.*
  3. *Seguidamente, modifica el makefile para que genere una librería llamada **libmath**.*
      	*a. Ejecuta el makefile y comprueba qué resultado ha proporcionado.*
    4. *Añade las órdenes necesarias para obtener el programa principal compilado y un **fichero ejecutable denominado **Practica7*.

**Ejercicio 1.1**

Archivo makefile

```makefile
# Archivo Makefile Ejercicio1.1
# Uso: make -f makefile1.1
hello.o: hello.cpp
	g++ -c hello.cpp
```

Captura de pantalla

![](/home/salva/Imágenes/Captura de pantalla de 2020-05-13 00-59-03.png)

Ahora usamos el archivo makefile

```bash
makefile -f makefile1.1
```

Captura de pantalla

![](/home/salva/Escritorio/ejecmakefile11.png)



**Ejercicio 1.2.a**

Archivo makefile

```makefile
# Archivo makefile Ejercicio1.2
# Uso: make -f makefile1.2 hello.o | tan.o | cos.o | sin.o

hello.o: hello.cpp
	g++ -c hello.cpp

tan.o: tan.cpp
	g++ -c tan.cpp

cos.o: cos.cpp
	g++ -c cos.cpp

sin.o: sin.cpp
	g++ -c sin.cpp
```



Captura de pantalla

![](/home/salva/Imágenes/Captura de pantalla de 2020-05-13 00-58-50.png)



Ejecución del makefile

hello.o

```bash
make -f makefile1.2 hello.o
```

tan.o

```bash
make -f makefile1.2 tan.o
```

cos.o

```bash
make -f makefile1.2 cos.o
```

sin.o

```bash
make -f makefile1.2 sin.o
```

Captura de la ejecución:

![](/home/salva/Escritorio/ejecmakefile12a.png)



**Ejercicio 1.2.b**

Archivo makefile

```makefile
# Archivo makefile Ejercicio1.2b
# Uso: make -f makefile1.2b


todos: hello.o tan.o cos.o sin.o

hello.o: hello.cpp
	g++ -c hello.cpp

tan.o: tan.cpp
	g++ -c tan.cpp

cos.o: cos.cpp
	g++ -c cos.cpp

sin.o: sin.cpp
	g++ -c sin.cpp
```

Captura:

![](/home/salva/Imágenes/Captura de pantalla de 2020-05-13 00-58-36.png)



Ejecución del makefile

```bash
make -f makefile1.2b
```

Captura:

![](/home/salva/Escritorio/ejecmakefile12b.png)



**Ejercicio 1.3**

Archivo Makefile

```makefile
# Archivo makefile Ejercicio1.3
# Uso: make -f makefile1.3


todos: hello.o factorial.o tan.o cos.o sin.o libmath.a

hello.o: hello.cpp functions.h
	g++ -c hello.cpp

factorial.o: factorial.cpp functions.h
	g++ -c factorial.cpp

tan.o: tan.cpp mates.h
	g++ -c tan.cpp 

cos.o: cos.cpp mates.h
	g++ -c cos.cpp

sin.o: sin.cpp mates.h
	g++ -c sin.cpp

libmath.a: tan.o cos.o sin.o
	ar -rvs libmath.a sin.o cos.o tan.o
```

Captura:

![](/home/salva/Imágenes/Captura de pantalla de 2020-05-13 00-58-18.png)



Ejecución del makefile

```bash
make -f makefile1.3
```

Captura:

![](/home/salva/Escritorio/ejecmakefile13.png)



**Ejercicio 1.4**

Este ya es el makefile final. Añadimos la regla de factorial necesaria para el main2.cpp. Además linkeamos la biblioteca creada anteriormente

Archivo makefile

```makefile
# Archivo makefile Ejercicio1.4 - Makefile final del ejercicio 1
# Uso: make -f makefileEjercicio1


Practica7: main2.o hello.o factorial.o libmath.a
	g++ -L./ -o Practica7 main2.o hello.o factorial.o -lmath

main2.o: main2.cpp functions.h mates.h
	g++ -c main2.cpp

hello.o: hello.cpp functions.h
	g++ -c hello.cpp

factorial.o: factorial.cpp functions.h
	g++ -c factorial.cpp

tan.o: tan.cpp mates.h
	g++ -c tan.cpp

cos.o: cos.cpp mates.h
	g++ -c cos.cpp

sin.o: sin.cpp mates.h
	g++ -c sin.cpp

libmath.a: tan.o cos.o sin.o
	ar -rvs libmath.a sin.o cos.o tan.o
```

Captura:

![](/home/salva/Imágenes/Captura de pantalla de 2020-05-13 00-57-57.png)



Ejecución del makefile:

```bash
makefile -f makefileEjercicio1
```



Captura:

![](/home/salva/Escritorio/ejecmakefile1.png)



#### Ejercicio 2

*Haciendo uso del archivo anterior, genera un nuevo makefile añadiendo al código las*
*siguientes variables:*

1. *Una variable que almacene dónde están los ficheros **include**.*
2. *Una variable que almacene el **compilador**.*
3. *Utiliza la variable en la que se guarda el **nombre del objetivo** de la regla actual para*
*no tener que repetir siempre dicha cadena.*
4. *Modifica las reglas que puedas utilizando la variable donde se almacenan las*
***dependencias*** *de la regla actual.*



**Ejercicio 2.1**

Como tenemos los archivos de cabecera en el directorio actual, el directorio include será `./` 

Archivo makefile:

```makefile
# Archivo makefile Ejercicio2.1
# Uso: make -f makefile2.1

INCLUDE_DIR=./

Practica7: main2.o hello.o factorial.o libmath.a
	g++ -L./ -o Practica7 main2.o hello.o factorial.o -lmath

main2.o: main2.cpp $(INCLUDE_DIR)functions.h $(INCLUDE_DIR)mates.h
	g++ -c main2.cpp

hello.o: hello.cpp $(INCLUDE_DIR)functions.h
	g++ -c hello.cpp

factorial.o: factorial.cpp $(INCLUDE_DIR)functions.h
	g++ -c factorial.cpp

tan.o: tan.cpp $(INCLUDE_DIR)mates.h
	g++ -c tan.cpp

cos.o: cos.cpp $(INCLUDE_DIR)mates.h
	g++ -c cos.cpp

sin.o: sin.cpp $(INCLUDE_DIR)mates.h
	g++ -c sin.cpp

libmath.a: tan.o cos.o sin.o
	ar -rvs libmath.a sin.o cos.o tan.o
```

Captura:

![](/home/salva/Imágenes/Captura de pantalla de 2020-05-13 00-56-55.png)



Ejecución del makefile

```bash
make -f makefile2.1
```

Captura:

![](/home/salva/Imágenes/Captura de pantalla de 2020-05-12 23-35-50.png)





**Ejercicio 2.2**

Ahora guardamos el compilador en la variable CC.

Archivo makefile

``` makefile
# Archivo makefile Ejercicio2.2
# Uso: make -f makefile2.2

INCLUDE_DIR=./
CC=g++

Practica7: main2.o hello.o factorial.o libmath.a
	$(CC) -L./ -o Practica7 main2.o hello.o factorial.o -lmath

main2.o: main2.cpp $(INCLUDE_DIR)functions.h $(INCLUDE_DIR)mates.h
	$(CC) -c main2.cpp

hello.o: hello.cpp $(INCLUDE_DIR)functions.h
	$(CC) -c hello.cpp

factorial.o: factorial.cpp $(INCLUDE_DIR)functions.h
	$(CC) -c factorial.cpp

tan.o: tan.cpp $(INCLUDE_DIR)mates.h
	$(CC) -c tan.cpp

cos.o: cos.cpp $(INCLUDE_DIR)mates.h
	$(CC) -c cos.cpp

sin.o: sin.cpp $(INCLUDE_DIR)mates.h
	$(CC) -c sin.cpp

libmath.a: tan.o cos.o sin.o
	ar -rvs libmath.a sin.o cos.o tan.o
```

Captura:

![](/home/salva/Imágenes/Captura de pantalla de 2020-05-13 00-56-34.png)



Ejecución:

``` bash
make -f makefile2.2
```

Captura:

![](/home/salva/Imágenes/Captura de pantalla de 2020-05-12 23-39-19.png)





**Ejercicio 2.3**

Ahora en la regla "Practica7" ponemos la variable $@ en lugar de la cadena "Practica7".

Archivo makefile:

```makefile
# Archivo makefile Ejercicio2.3
# Uso: make -f makefile2.3

INCLUDE_DIR=./
CC=g++

Practica7: main2.o hello.o factorial.o libmath.a
	$(CC) -L./ -o $@ main2.o hello.o factorial.o -lmath

main2.o: main2.cpp $(INCLUDE_DIR)functions.h $(INCLUDE_DIR)mates.h
	$(CC) -c main2.cpp

hello.o: hello.cpp $(INCLUDE_DIR)functions.h
	$(CC) -c hello.cpp

factorial.o: factorial.cpp $(INCLUDE_DIR)functions.h
	$(CC) -c factorial.cpp

tan.o: tan.cpp $(INCLUDE_DIR)mates.h
	$(CC) -c tan.cpp

cos.o: cos.cpp $(INCLUDE_DIR)mates.h
	$(CC) -c cos.cpp

sin.o: sin.cpp $(INCLUDE_DIR)mates.h
	$(CC) -c sin.cpp

libmath.a: tan.o cos.o sin.o
	ar -rvs libmath.a sin.o cos.o tan.o
```

Captura:

![](/home/salva/Imágenes/Captura de pantalla de 2020-05-13 00-56-17.png)



Ejecución:

``` bash
make -f makefile2.3
```

Captura:

![](/home/salva/Imágenes/Captura de pantalla de 2020-05-12 23-49-16.png)



**Ejercicio 2.4**

Ahora sustituimos las dependencias por la variable $^

Archivo makefile:

```makefile
# Archivo makefile Ejercicio2.4 - Makefile final del ejercicio 2
# Uso: make -f makefileEjercicio2

INCLUDE_DIR=./
CC=g++

Practica7: main2.o hello.o factorial.o libmath.a
	$(CC) -L./ -o $@ $^

main2.o: main2.cpp $(INCLUDE_DIR)functions.h $(INCLUDE_DIR)mates.h
	$(CC) -c $^

hello.o: hello.cpp $(INCLUDE_DIR)functions.h
	$(CC) -c $^

factorial.o: factorial.cpp $(INCLUDE_DIR)functions.h
	$(CC) -c $^

tan.o: tan.cpp $(INCLUDE_DIR)mates.h
	$(CC) -c $^

cos.o: cos.cpp $(INCLUDE_DIR)mates.h
	$(CC) -c $^

sin.o: sin.cpp $(INCLUDE_DIR)mates.h
	$(CC) -c $^

libmath.a: tan.o cos.o sin.o
	ar -rvs libmath.a $^
```

Captura:

![](/home/salva/Imágenes/Captura de pantalla de 2020-05-13 00-55-22.png)



Ejecución:

```bash
make -f makefileEjercicio2
```

Captura:

![](/home/salva/Imágenes/Captura de pantalla de 2020-05-13 00-04-39.png)