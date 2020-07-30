#### REPASO DEL MÓDULO 1 DE PRÁCTICAS

##### Salvador Romero Cortés																										

###### Prácticas 1 a 4

-------------------------

**Ejercicio 1**

*A partir del directorio personal y utilizando una única orden, cree un directorio llamado **repaso**, dentro de él otros dos directorios llamados **prueba1** y **prueba2**, y dentro de prueba1 otro directorio llamado **ejercicio1**.*

```bash
mkdir repaso repaso/prueba1 repaso/prueba2 repaso/prueba1/ejercicio1
```

**Ejercicio 2**

*Situados en el directorio **ejercicio1**, con una única orden, cree cinco archivos llamados **arch1.txt**, **arch2.txt**, **arch3.txt**, **arch4.pdf** y **arch5.pdf***

```bash
cd repaso/prueba1/ejercicio1/
touch arch1.txt arch2.txt arch3.txt arch4.pdf arch5.pdf
```

**Ejercicio 3**

*Desde el directorio **ejercicio1**, redireccione al archivo **arch1.txt** elresultado de buscar la palabra “expresiones” en la ayuda (help) de la orden **let***

Si queremos sobrescribir el archivo

```bash
help let | grep expresiones > arch1.txt
```

Si queremos añadirlo al final

```bash
help let | grep expresiones >> arch1.txt
```

**Ejercicio 4**

*Desde el **directorio personal**, copie los ficheros de ejercicio1 cuya extensión tenga una x al
directorio **prueba2**.*

```bash
cd ~ 				#Nos dirigimos al directorio HOME
cp repaso/prueba1/ejercicio1/*.*x* repaso/prueba2/
```

**Ejercicio 5**

*Nuevamente desde el **directorio personal**, obtenga las 15 primeras líneas del manual de la orden
find y añádalo al final del archivo **arch1.txt** del directorio **prueba2**.*

```bash
man find | head -n 15 >> repaso/prueba2/arch1.txt
```

**Ejercicio 6**

*Exprese la siguiente operación aritmética e indique su resultado: 2+3+4+5/2 con y sin decimales.*

Con decimales

```bash
echo 2+3+4+5/2 | bc -l
11.50000000000000000000 #Salida
```

Sin decimales

```bash
echo $[2+3+4+5/2]
11						#Salida
```

**Ejercicio 7**

*En la carpeta personal, construya un guón llamado **repaso** que admita dos argumentos, el primero será un directorio y el segundo será un archivo:*

​	*`repaso <nombre_directorio><nombre_archivo>`*

*El guión deberá hacer los siguiente:*

*  *Comprobar que el número de argumentos es correcto, y si no fuera así, indicar cómo se debe ejecutar para que funcione correctamente. Esto es, una pequeña ayuda y terminar.*
* *Si el **segundo** argumento es un archivo, escribir las tres primeras líneas en otro archivo llamado **salida** y mostrar un mensaje informando de dicha acción. En caso contrario informar del error y salir.*
* *Si el **primer** argumento es un directorio, mostrar un mensaje con el número de archivos que contiene. En caso contrario crear un directorio con el nombre del primer argumento.*
* *Buscar en el directorio pasado como **primer** argumento los archivos que tienen permiso de lectura y añadir el resultado de la búsqueda al final del archivo **salida**. Además, mostrar por pantalla el siguiente mensaje: "De un total de N archivos, hay X archivos con permiso de lectura" (siendo N el número total de archivos del directorio  X los que tienen permiso de lectura).*

``` bash
#!/bin/bash
# Titulo: 	guionRepasoMod1
# Fecha:	22/03/2020 	
# Autor: 	Salvador Romero Cortés
# Versión: 	1.0
# Descripción: 	
	# Comprobar que el número de argumentos es correcto, y si no fuera así, indicar cómo se debe ejecutar para que funcione correctamente. Esto es, una pequeña ayuda y terminar.
	
	# Si el segundo argumento es un archivo, escribir las tres primeras líneas en otro archivo llamado salida y mostrar un mensaje informando de dicha acción. En caso contrario 		informar del error y salir.

	# Si el primer argumento es un directorio, mostrar un mensaje con el número de archivos que contiene. En caso contrario crear un directorio con el nombre del primer argumento
	
	# Buscar en el directorio pasado como primer argumento los archivos que tienen permiso de lectura y añadir el resultado de la búsqueda al final del archivo salida. Además, 		mostrar por pantalla el siguiente mensaje: "De un total de N archivos, hay X archivos con permiso de lectura" (siendo N el número total de archivos del directorio  X los que 		tienen permiso de lectura)
# Opciones: 	Ninguna
# Uso: 		guionRepasoMod1 <directorio> <archivo>




if [[ $# -eq 2 ]]; 
then
	if [[ -f $2 ]];
	then
		#como el enunciado no dice nada, asumo que el archivo salida se escribe en el directorio introducido como parametro
		head -n 3 $2 > $1/salida
		printf "Se han escrito las 3 primeras lineas de %s en un archivo llamado \"salida\"\n" $2

		if [ -d $1 ];
		then
			numero_archivos=`find $1 -maxdepth 1 -type f | wc -l`
			printf "En el directorio %s hay %i archivos\n" $1 $numero_archivos
			 
		else
			mkdir $1
			printf "Como no existia el directorio %s se ha creado en su lugar\n" $1
		fi
		
		find $1 -perm -a=r >> $1/salida
		n_con_permiso_l=`find $1 -maxdepth 1 -perm -a=r -type f | wc -l`
		printf "De un total de %i de archivos, hay %i archivos con permiso de lectura\n" $numero_archivos $n_con_permiso_l

	else
		printf "El segundo argumento no es un archivo valido\n"
	fi	
		
else
	printf "El numero introducido de argumentos no es válido\nEl uso de este guión es guionRepasoMod1 <directorio> <archivo>\n"
fi
```

