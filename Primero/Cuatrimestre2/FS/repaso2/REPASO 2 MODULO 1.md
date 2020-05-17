### EJERCICIOS REPASO PRÁCTICAS 1 A 5 - MÓDULO 1

###### Salvador Romero Cortés

---

**1.- Cree tres directorios con una única orden : <u>curso_1920</u> y dentro de éste, <u>cuatrimestre_1</u> y <u>cuatrimestre_2</u>.**

```bash
mkdir curso_1920 curso_1920/cuatrimestre_1 curso_1920/cuatrimestre_2
```



**2.- <u>Cree</u> un archivo cuyo nombre sea <u>repasoMod1</u> en el directorio <u>curso_1920</u>. A continuación, <u>edítelo</u> y escriba lo siguiente:**

**DNI: *número del DNI***

**Nombre y apellidos:*nombre y apellidos***

 	**Fecha: *fecha actual (dd/mm/aaaa)***

```bash
cd curso_1920
touch repasoMod1
nano repasoMod1

##dentro de nano
DNI: 76752695Q
Nombre y Apellidos: Salvador Romero Cortés
	Fecha: 15/04/2020

# ctrl+x para guardar
```

**3.- Copie el archivo <u>repasoMod1</u> del directorio curso_1920 en el directorio <u>cuatrimestre_1</u>.**

```bash
cp repasoMod1 cuatrimestre_1
```

**4.- Redireccione el resultado de ejecutar la orden que obtiene la decha actual al fichero que ha creado en el punto 2 (en el directorio curso_1920) sin destruir su contenido**

```bash
#suponiendo desde directorio $HOME
echo `date +%d`/`date +%m`/`date +%Y` >> curso_1920/repasoMod1 

#desde el directorio "curso_1920"
echo `date +%d`/`date +%m`/`date +%Y` >> repasoMod1 
```

**5.- Indique qué es necesario hacer para crear una variable RUTA que contenga la ruta absoluta del directorio en el que nos encontramos. Compruebe con el comando correspondiente las variables locales de su sistema**

```bash
# crear variable RUTA con ruta absoluta actual
RUTA = `pwd`

# comprobar las variables locales del sistema
set
```

**6.- Obtenga las 20 últimas líneas del manual de la orden find y guárdelas en un fichero llamado <u>ayudafind</u>, dentro del directorio <u>cuatrimestre_2</u> **

```bash
man find | tail -n 20 > curso_1920/cuatrimestre_2/ayudafind
```

**7.- En la carpeta personal, construya un guión llamado <u>repaso-guion</u> que admita tres argumentos, el primero será un directorio, el segundo una letra, y el tercero una palabra:**

**`examen-guion <nombre_directorio> <letra> <palabra>`**

**El guión debe:**

* **Comprobar que se le están pasando tres argumentos, y si no fuera así, indicar cómo se debe ejecutar para que funcione correctamente. Esto es, dar una pequeña ayuda y terminar.**
* **Crear, en caso de no existir, el directorio dado como primer argumento.**
  * **Comprobar que el segundo argumento sea una `f`o una `d`. Si no fuera así, indicarlo con un mensaje de error y salir.**

* **Encontrar la palabra dada en el <u>tercer</u> argumento de forma recursiva en los archivos existente a partir del directorio indicado por el usuario (<u>primer</u> argumento), incluyendo el número de línea en donde se localiza el término. Almacenar el resultado de la consulta en un fichero llamado <u>resultado</u> dentro del directorio desde el que se ejecute el guión.**
* **Buscar en el directorio indicado por el usuario (<u>primer</u> argumento) todos los ficheros o directorios según la letra pasada como <u>segundo</u> argumento (f=fichero, d=directorio) Almacenar el <u>resultado</u> de la consulta al final del fichero resultado del apartado anterior.**

```bash
#!/bin/bash
# Título: 	repaso-guion
# Autor: 	Salvador Romero Cortés
# Fecha: 	16/04/2020
# Versión: 	1.0
# Opciones:	ninguna
# Uso:		repaso-guion <nombre_directorio> <letra> <palabra>
# Descripción:	Este guion busca el tercer argumento de manera recursiva en el directorio indicado en el primer argumento.
#		También lista los directorios/ficheros (segun el segundo argumento) del directorio indicado. 
#		Todos los resultados se guardan en un archivo llamado resultado


# funcion para mostrar la informacion de ayuda sobre el uso del guión
_ayuda(){
	printf "Uso incorrecto.\nEl uso correcto es repaso-guion <nombre_directorio> <letra> <palabra>.\nLa letra es f para archivos o d para directorios.\n"
	exit 1
}

# comprobamos los argumentos y creamos el directorio si no existe
if [ $# -ne 3 ]; then _ayuda; fi
if [ $2 != f -a $2 != d ]; then _ayuda;fi

if [ ! -d $1 ]; then
	echo "No existe el directorio $1, se crea"
	mkdir $1
fi

# encontramos de manera recursiva en el directorio dado y guardamos en un archivo las lineas y el nombre del archivo.
echo "Buscando \"$3\"..."
echo "Resultados de búsqueda" > resultado
grep -nr $3 $1 | cat >> resultado

# buscamos fichero o directorio en funcion de la entrada.
if [ $2 == f ]; then 
	echo -e "\nListado de ficheros" >> resultado 
	echo "Listando ficheros..."
else  
	echo -e "\nListado de directorios" >> resultado 
	echo "Listando directorios..."
fi 

find $1 -type $2 >> resultado
echo "Hecho, comprobar archivo \"resultado\""
```

