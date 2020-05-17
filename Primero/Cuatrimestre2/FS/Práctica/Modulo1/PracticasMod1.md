## Fundamentos de Software

### Práctica 1

<b> Ejercicio 1.1 </b>

<i>Cree el siguiente árbol de directorios a partir de un directorio desu  cuenta  de usuario.  Indique  también  cómo  sería  posible  crear  toda  esa estructura  de  directorios  mediante  una  única  orden(mire  las  opciones  de  la orden  de  creación  de  directorios  mediante man mkdir). </i>

<i>Posteriormente  realicelas siguientesacciones:
<br>a)En Ejer1 cree    los    archivos arch100.txt, filetags.txt, practFS.ext y robet201.me.</br>
<br>b)En Ejer21 cree  los  archivos robet202.me, ejer11sol.txt y blue.me.</b>
<br>c)En Ejer2 cree los archivos ejer2arch.txt, ejer2filetags.txt y readme2.pdf.</b>
<br>d)En Ejer3 cree los archivos ejer3arch.txt, ejer3filetags.txt y readme3.pdf.</b>
<br>e)¿Podrían realizarse las acciones anteriores empleando una única orden? Indique cómo. </b></i>

![1.1](/home/salva/Imágenes/1.1.png)



<i>Crear arbol de directorios</i>
`mkdir ejercicio1` 
`mkdir ejercicio1/Ejer1 ejercicio1/Ejer2 ejercicio1/Ejer3 ejercicio1/Ejer1/Ejer21`

a)

`cd Ejer1
touch arch100.txt filetags.txt practFS.ext robet201.me`
b)
`cd Ejer21
touch robet202.me ejer11sol.txt blue.me`
c)
`cd ../../Ejer2`
`touch ejer2arch.txt ejer2filetags.txt readme2.pdf`
d)
`cd ../Ejer3
touch ejer3arch.txt ejer3filetags.txt readme3.pdf`
e)
Se podría hacer indicando antes de cada fichero su directorio
<i>Ejemplo para los archivos de 21, el resto sería igual</i>
`touch Ejer1/Ejer21/robet202.me Ejer1/Ejer21/ejer11sol.txt Ejer1/Ejer21/blue.me`



**Ejercicio 1.2**

*Situados en el directorio ejercicio1 creado anteriormente, realice las siguientes acciones:*

*a) Mueva el directorio Ejer21 al directorio Ejer2.*

`mv Ejer1/Ejer21 Ejer2/`

*b) Copie los archivos de Ejer1 cuya extensión tenga una x al directorio Ejer3.*

` cp Ejer1/*.*x* Ejer3/`

*c) Si estamos situado en el directorio Ejer2y ejecutamos la orden `ls -la ../Ejer3/*arch*` , ¿qué archivo/s, en su caso, debería mostrar?*

Muestra los archivos dentro de `Ejer3` que contengan `arch`en su nombre.

```bash
salvaromero@ei142165:~/ejercicio1/Ejer2$ ls -la ../Ejer3/*arch*
-rw-r--r-- 1 salvaromero alumno 0 feb 18 18:22 ../Ejer3/arch100.txt
-rw-r--r-- 1 salvaromero alumno 0 feb 18 17:54 ../Ejer3/ejer3arch.txt
```



**Ejercicio 1.3**
*Si estamos situados en el directorio `Ejer2`, indique la orden necesaria para listar sólo los nombres de todos los archivos del directorio padre*

`ls -a ../`



**Ejercicio 2.4**

*Liste los archivos que estén en su directorio actual y fíjese en alguno que no disponga de la fecha y hora actualizada, es decir, la hora actual y el día de hoy. Ejecute la orden `touch` sobre dicho archivo y observe qué sucede sobre la fecha del citado archivo cuando se vuelva a listar.*

```bash
salvaromero@ei142165:~/ejercicio1/Ejer3$ ls -l
total 0
-rw-r--r-- 1 salvaromero alumno 0 feb 18 18:22 arch100.txt
-rw-r--r-- 1 salvaromero alumno 0 feb 18 17:54 ejer3arch.txt
-rw-r--r-- 1 salvaromero alumno 0 feb 18 17:54 ejer3filetags.txttouchsobre
-rw-r--r-- 1 salvaromero alumno 0 feb 18 18:22 filetags.txt
-rw-r--r-- 1 salvaromero alumno 0 feb 18 18:22 practFS.ext
-rw-r--r-- 1 salvaromero alumno 0 feb 18 17:54 readme3.pdf
salvaromero@ei142165:~/ejercicio1/Ejer3$ touch ejer3arch.txt 
salvaromero@ei142165:~/ejercicio1/Ejer3$ ls -l
total 0
-rw-r--r-- 1 salvaromero alumno 0 feb 18 18:22 arch100.txt
-rw-r--r-- 1 salvaromero alumno 0 feb 18 18:45 ejer3arch.txt
-rw-r--r-- 1 salvaromero alumno 0 feb 18 17:54 ejer3filetags.txt
-rw-r--r-- 1 salvaromero alumno 0 feb 18 18:22 filetags.txt
-rw-r--r-- 1 salvaromero alumno 0 feb 18 18:22 practFS.ext
-rw-r--r-- 1 salvaromero alumno 0 feb 18 17:54 readme3.pdf
```

Se actualiza la fecha del archivo



**Ejercicio 2.5**

*La  organización  del  espacio  en  directorios  es fundamental  para  poder  localizar  fácilmente  aquello que  estemos  buscando.  En  ese  sentido,  realice  las  siguientes  acciones  dentro  de  su  directorio home (es  el directorio por defecto sobre el que trabajamos al entrar en el sistema):*

*a)Obtenga en nombre de camino absoluto (pathname absoluto) de su directorio home. ¿Es el mismo que el de su compañero/a?*



```bash
salvaromero@ei142165:/home$ pwd
/home
salvaromero@ei142165:/home$ cd salvaromero/
salvaromero@ei142165:~$ pwd
/home/salvaromero
```



*b)Cree  un  directorio  para  cada  asignatura  en  la  que  se  van  a  realizar prácticas  de  laboratorio  y,  dentro  de cada directorio, nuevos directorios para cada una de las prácticas realizadas hasta el momento.*

```bash
salvaromero@ei142165:~$ mkdir MP
salvaromero@ei142165:~$ mkdir FS
salvaromero@ei142165:~$ mkdir MP/Practica_1
salvaromero@ei142165:~$ mkdir FS/Practica_1
```



*c)Dentro  del  directorio  de  la  asignatura  fundamentos  del  software  (llamado FS)  y  dentro  del  directorio creado  para  esta práctica,  copie  los  archivos `hosts` y `passwd` que  se  encuentran  dentro  del  directorio /etc.*

```bash
salvaromero@ei142165:~$ cp ../../etc/hosts FS/Practica_1
salvaromero@ei142165:~$ cp ../../etc/passwd FS/Practica_1
```

*d)Muestre el contenido de cada uno de los archivos*

Archivo hosts

```bash
salvaromero@ei142165:~/FS/Practica_1$ cat hosts 
127.0.0.1	localhost
127.0.1.1	ei142165

# The following lines are desirable for IPv6 capable hosts
::1     ip6-localhost ip6-loopback
fe00::0 ip6-localnet
ff00::0 ip6-mcastprefix
ff02::1 ip6-allnodes
ff02::2 ip6-allrouters
172.18.140.10 bacus0.ugr.es bacus0
172.18.140.11 venus0.ugr.es venus0
172.18.140.12 lepus0.ugr.es lepus0
172.18.140.13 cetus0.ugr.es cetus0
172.18.140.14 fenix0.ugr.es fenix0
172.18.140.15 sepus0.ugr.es sepus0
172.18.140.16 pirus0.ugr.es pirus0
172.18.142.10 backup-etsiit2.ugr.es backup-etsiit2
172.18.142.11 venus2.ugr.es venus2
172.18.142.12 lepus2.ugr.es lepus2
172.18.142.13 cetus2.ugr.es cetus2
172.18.142.14 fenix2.ugr.es fenix2
172.18.142.15 sepus2.ugr.es sepus2
172.18.142.16 pirus2.ugr.es pirus2
# Maquinas de los departamentos y necesarias para examen
150.214.190.179 lsi.ugr.es lsi
150.214.191.180 decsai.ugr.es decsai
#150.214.204.16 prado.ugr.es prado
#150.214.204.15 idp.ugr.es idp
```

Archivo passwd

```bash
salvaromero@ei142165:~/FS/Practica_1$ cat passwd 
root:x:0:0:root:/root:/bin/bash
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
bin:x:2:2:bin:/bin:/usr/sbin/nologin
sys:x:3:3:sys:/dev:/usr/sbin/nologin
sync:x:4:65534:sync:/bin:/bin/sync
games:x:5:60:games:/usr/games:/usr/sbin/nologin
man:x:6:12:man:/var/cache/man:/usr/sbin/nologin
lp:x:7:7:lp:/var/spool/lpd:/usr/sbin/nologin
mail:x:8:8:mail:/var/mail:/usr/sbin/nologin
news:x:9:9:news:/var/spool/news:/usr/sbin/nologin
uucp:x:10:10:uucp:/var/spool/uucp:/usr/sbin/nologin
proxy:x:13:13:proxy:/bin:/usr/sbin/nologin
www-data:x:33:33:www-data:/var/www:/usr/sbin/nologin
backup:x:34:34:backup:/var/backups:/usr/sbin/nologin
list:x:38:38:Mailing List Manager:/var/list:/usr/sbin/nologin
irc:x:39:39:ircd:/var/run/ircd:/usr/sbin/nologin
gnats:x:41:41:Gnats Bug-Reporting System (admin):/var/lib/gnats:/usr/sbin/nologin
nobody:x:65534:65534:nobody:/nonexistent:/usr/sbin/nologin
systemd-timesync:x:100:102:systemd Time Synchronization,,,:/run/systemd:/bin/false
systemd-network:x:101:103:systemd Network Management,,,:/run/systemd/netif:/bin/false
systemd-resolve:x:102:104:systemd Resolver,,,:/run/systemd/resolve:/bin/false
systemd-bus-proxy:x:103:105:systemd Bus Proxy,,,:/run/systemd:/bin/false
syslog:x:104:108::/home/syslog:/bin/false
_apt:x:105:65534::/nonexistent:/bin/false
messagebus:x:106:110::/var/run/dbus:/bin/false
uuidd:x:107:111::/run/uuidd:/bin/false
lightdm:x:108:114:Light Display Manager:/var/lib/lightdm:/bin/false
whoopsie:x:109:116::/nonexistent:/bin/false
avahi-autoipd:x:110:119:Avahi autoip daemon,,,:/var/lib/avahi-autoipd:/bin/false
avahi:x:111:120:Avahi mDNS daemon,,,:/var/run/avahi-daemon:/bin/false
dnsmasq:x:112:65534:dnsmasq,,,:/var/lib/misc:/bin/false
colord:x:113:123:colord colour management daemon,,,:/var/lib/colord:/bin/false
speech-dispatcher:x:114:29:Speech Dispatcher,,,:/var/run/speech-dispatcher:/bin/false
hplip:x:115:7:HPLIP system user,,,:/var/run/hplip:/bin/false
kernoops:x:116:65534:Kernel Oops Tracking Daemon,,,:/:/bin/false
pulse:x:117:124:PulseAudio daemon,,,:/var/run/pulse:/bin/false
rtkit:x:118:126:RealtimeKit,,,:/proc:/bin/false
saned:x:119:127::/var/lib/saned:/bin/false
usbmux:x:120:46:usbmux daemon,,,:/var/lib/usbmux:/bin/false
operador:x:1000:1000:operador,,,:/home/operador:/bin/bash
usermetrics:x:121:129:User Metrics:/var/lib/usermetrics:/bin/false
clickpkg:x:122:130::/nonexistent:/bin/false
nm-openvpn:x:123:131:NetworkManager OpenVPN,,,:/var/lib/openvpn/chroot:/bin/false
ntp:x:124:132::/home/ntp:/bin/false
lxd:x:125:65534::/var/lib/lxd/:/bin/false
mysql:x:999:50001::/home/mysql:
salvaromero:x:1472:1500:SALVADOR ROMERO CORTES:/home/salvaromero:/bin/bash
```



**Ejercicio 1.6**

*Situados en algún lugar de su directorio principal de usuario (directorio HOME), cree los directorios siguientes: `Sesion.1`, ` Sesion.10`, `Sesion.2`, `Sesion.3`,` Sesion.4`,  `Sesion.27`,` Prueba.1` y `Sintaxis.2` y realice las siguientes tareas:*

```bash
mkdir Sesion.1 Sesion.10 Sesion.2 Sesion.3 Sesion.4 Sesion.27 Prueba.1 Sintaxis.2
```



*a) Borre el directorio Sesion.4*

```bash
rmdir Sesion.4
```



*b )  Liste todos aquellos directorios que empiecen por `Sesion.` y a continuación tenga un único carácter*

```bash
ls Sesion.?

#Salida
Sesion.1:

Sesion.2:
```

*c) Liste aquellos directorios cuyos nombres terminen en `.1`*

```bash
ls *.1

#Salida
Prueba.1:

Sesion.1:
```

*d) Liste aquellos directorios cuyos nombres terminen en `.1`o `.2`*

```bash
ls *.[12]

#Salida
Prueba.1:

Sesion.1:

Sesion.2:

Sintaxis.2:
```

*e) Liste aquellos directorios cuyos nombres contengan los caracteres `si`*

```bash
ls *si*

#Salida
Sesion.1:

Sesion.10:

Sesion.2:

Sesion.27:

Sesion.3:
```

*f ) Liste aquellos directorios cuyos nombres contengan los caracteres `si` y terminen en `.2`*

```bash
#Deberia funcionar este
ls *si*.2
#Pero en las practicas el que funcionaba era este
ls *si*2*

#Salida
Sesion.2:

Sesion.27: #Este no deberia salir, este sale por el * del final. Si funcionase el original este no saldría
```



**Ejercicio 1.7**

*Desplacémonos hasta el directorio `/bin` , genere los siguientes listados de archivos (siempre de la forma más compacta y utilizando los metacaracteres apropiados)*:

a) *Todos los archivos que contengan sólo cuatro caracteres en su nombre.*

```bash
ls -a ????
```

*b) Todos los archivos que comiencen por los caracteres `d`,`f`.*

```bash
ls -a [df]*
```

*c) Todos los archivos que comiencen por las parejas de caracteres `sa`, `se`, `ad`.*

```bash
ls -a sa* se* ad*
```

*d) Todos los archivos que comiencen por `ty` acaben en  `r`.*

```bash
ls -a ty*r
```



**Ejercicio 1.8**

*Liste todos los archivos que comiencen por `tem` y terminen por `.gz` o `.zip`:*

*a) De tu directorio `HOME`.*

```bash
ls -a tem*.gz tem*.zip
```



*b) Del directorio actual.*

```bash
ls -a tem*gz tem*zip
```



*c) ¿Hay alguna diferencia en el resultado de su ejecución? Razone la respuesta.*  

En mi portátil no hay diferencia, en ambos casos no encuentra ningún fichero que cumpla las condiciones.



**Ejercicio 1.9**

*Muestre el contenido de un archivo regular que contenga texto:*

a) Las 10 primeras *líneas*.

```bash
head -n 10 archivo.txt
#El -n 10 es para indicar el numero de lineas, aunque en este caso no hace falta puesto que por defecto muestra 10 líneas.
```

b) Las 5 últimas líneas.

```bash
tail -n 5 archivo.txt
```



**Ejercicio 1.10**

*Cree un archivo empleando para ello cualquier editor de textos y escriba en el mismo varias palabras en diferentes líneas. A continuación trate de mostrar su contenido de manera ordenada empleando diversos criterios de ordenación.*

```bash
sort -n archivo.txt #ordena numericamente
sort -r archivo.txt #orden inverso
sort archivo.txt    #orden alfabetico
```



**Ejercicio 1.11**

*¿Cómo podría ver el contenido de todos los archivos del directorio actual que terminen en `.txt` o `.c`?*

```bash
ls -a *.txt *.c
```





### Práctica 2

24/02/2020

**Ejercicio 2.1**

*Se debe utilizar solamente una vez la orden chmod en cada apartado. Los cambios se harán en un*
*archivo concreto del directorio de trabajo (salvo que se indique otra cosa). Cambiaremos uno o varios permisos en*
*cada apartado (independientemente de que el archivo ya tenga o no dichos permisos) y comprobaremos que*
*funciona correctamente:*
*28*

a) Dar permiso de ejecución al “resto de usuarios”.*

```bash
touch ejercicio2.1
chmod o+x ejercicio2.1 
ls -l

#Salida
total 0
-rwxr-xr-x 1 salva salva 0 feb 24 19:57 ejercicio2.1
```

b) Dar permiso de escritura y ejecución al “grupo”.*
```bash
chmod g+rw ejercicio2.1 
ls -l

#Salida
total 0
-rwxrwxr-x 1 salva salva 0 feb 24 19:57 ejercicio2.1
```

*c) Quitar el permiso de lectura al “grupo” y al “resto de usuarios”.*

```bash
chmod og-r ejercicio2.1 
ls -l

#Salida
total 0
-rwx-wx--x 1 salva salva 0 feb 24 19:57 ejercicio2.1

```
*d) Dar permiso de ejecución al “propietario” y permiso de escritura el “resto de usuarios”.*
```bash
chmod u+x,o+r ejercicio2.1 
ls -l

#Salida
total 0
-rwx-wxr-x 1 salva salva 0 feb 24 19:57 ejercicio2.1
```
*e) Dar permiso de ejecución al “grupo” de todos los archivos cuyo nombre comience con la letra “e”. Nota: Si* *no hay más de dos archivos que cumplan esa condición, se deberán crear archivos que empiecen con “e”* *y/o modificar el nombre de archivos ya existentes para que cumplan esa condición*
```bash
touch ejemplo2
touch eeeeeeee
chmod g+x e*
ls -l

#Salida
total 0
-rw-r-xr-- 1 salva salva 0 feb 24 20:03 eeeeeeee
-rw-r-xr-- 1 salva salva 0 feb 24 20:03 ejemplo2
-rwx-wxr-x 1 salva salva 0 feb 24 19:57 ejercicio2.1
```



**Ejercicio 2.2**

*Utilizando solamente las órdenes de la práctica anterior y los metacaracteres de redirección de*
*salida:*

* *Cree un archivo llamado ej31 , que contendrá el nombre de los archivos del directorio padre del directorio*
  *de trabajo.*
```bash
ls -a ../ > ej31
```
* *Cree un archivo llamado ej32 , que contendrá las dos últimas líneas del archivo creado en el ejercicio*
  *anterior.*
```bash
tail -n 2 ej31 > ej32
```
* *Añada al final del archivo ej32 , el contenido del archivo ej31 .*

```bash
cat ej31 >> ej32
```

**Ejercicio 2.3**

*Utilizando el metacarácter de creación de cauces y sin utilizar la orden cd:*

* *Muestre por pantalla el listado (en formato largo) de los últimos 6 archivos del directorio /etc.*

```bash
ls -l /etc | tail -n 6

lrwxrwxrwx  1 root root      23 feb 22 17:21 vtrgb -> /etc/alternatives/vtrgb
-rw-r--r--  1 root root    4942 abr  8  2019 wgetrc
drwxr-xr-x  2 root root    4096 feb  3 19:26 wpa_supplicant
drwxr-xr-x 11 root root    4096 feb  3 19:27 X11
drwxr-xr-x  5 root root    4096 feb  3 19:24 xdg
-rw-r--r--  1 root root     477 mar 16  2018 zsh_command_not_found
```
* *La orden wc muestra por pantalla el número de líneas, palabras y bytes de un archivo (consulta la orden
  man para conocer más sobre ella). Utilizando dicha orden, muestre por pantalla el número de caracteres
  (sólo ese número) de los archivos del directorio de trabajo que comiencen por los caracteres “e” o “f”.*
```bash
wc -c [ef]*

  0 eeeeeeee
 91 ej31
134 ej32
  0 ejemplo2
  0 ejercicio2.1
  0 f-isima
225 total
```

**Ejercicio 2.4**

*Resuelva cada uno de los siguientes apartados.*
*a) Cree un archivo llamado ejercicio1, que contenga las 17 últimas líneas del texto que proporciona la*
*orden man para la orden chmod (se debe hacer en una única línea de órdenes y sin utilizar el metacarácter *“;” ).*

```bash
(man chmod | tail -n 17) > ejercicio1
```

*b) Al final del archivo ejercicio1, añada la ruta completa del directorio de trabajo actual.*

```bash
pwd >> ejercicio1
```

*c) Usando la combinación de órdenes mediante paréntesis, cree un archivo llamado ejercicio3 que*
*contendrá el listado de usuarios conectados al sistema (orden who) y la lista de archivos del directorio*
*actual.*

```bash
(who ; ls) > ejercicio3
```

*d) Añada, al final del archivo ejercicio3, el número de líneas, palabras y caracteres del archivo*
*ejercicio1. Asegúrese de que, por ejemplo, si no existiera ejercicio1, los mensajes de error también*
*se añadieran al final de ejercicio3.*

```bash
wc ejercicio1 &>> ejercicio3
```

*e) Con una sola orden chmod, cambie los permisos de los archivos ejercicio1 y ejercicio3, de forma*
*que se quite el permiso de lectura al “grupo” y se dé permiso de ejecución a las tres categorías de usuarios.*

```bash
chmod g-r,a+x ejercicio1 ejercicio3
```



### Práctica 3

03/03/2020

**Ejercicio 3.1**

*Escriba, al menos, cinco variables de entorno junto con el valor que tienen.*

```bash
env
```

**Ejercicio 3.2**

*Ejecute las órdenes del cuadro e indique qué ocurre y cómo puede resolver la situación para que la
variable NOMBRE se reconozca en el shell hijo*

Ocurre que el bash hijo no reconoce esa variable, aparece como valor vacío. Para solucionarlo hay que poner

```bash
export NOMBRE
```

**Ejercicio 3.3**

*Compruebe qué ocurre en las expresiones del ejemplo anterior si se quitan las comillas dobles del
final y se ponen después de los dos puntos. ¿Qué sucede si se sustituyen las comillas dobles por comillas simples?*

*Ejemplo anterior* 

```bash
$ echo “Los archivos que hay en el directorio son: $(ls -l)”
$ echo “Los archivos que hay en el directorio son: `ls -l`”
```

```bash
salva@salvaromero:~$ echo "Los archivos que hay en el directorio son:  $(ls -l)"
Los archivos que hay en el directorio son:  total 268
-rwxr-xr-x  1 salva salva  14168 feb 28 17:49 a.out
drwxr-xr-x  6 salva salva   4096 feb 24 09:49 cosas-varias
drwxr-xr-x  8 salva salva   4096 mar  2 17:49 Descargas
drwxr-xr-x  2 salva salva   4096 mar  3 18:07 Documentos
-rw-r--r--  1 salva salva   2119 feb 24 22:09 ejercicio1
drwxr-xr-x  3 salva salva   4096 feb 25 17:11 Escritorio
-rw-r--r--  1 salva salva   8980 feb 22 17:23 examples.desktop
-rw-rw-r--  1 salva salva 179957 feb 26 10:31 Firefox_wallpaper.png
drwxr-xr-x  4 salva salva   4096 mar  2 11:35 Imágenes
drwxr-xr-x  8 salva salva   4096 feb 22 17:38 jdk1.8.0_111
drwxr-xr-x  2 salva salva   4096 feb 22 17:27 Música
drwxr-xr-x 17 salva salva   4096 mar  3 16:48 netbeans-8.2
drwxr-xr-x  2 salva salva   4096 feb 22 17:27 Plantillas
-rw-rw-r--  1 salva salva    957 feb 28 17:49 prueba.cpp
drwxr-xr-x  2 salva salva   4096 feb 22 17:27 Público
drwxr-xr-x  9 salva salva   4096 mar  3 16:51 snap
drwxr-xr-x  3 salva salva   4096 feb 24 12:05 Universidad
drwxr-xr-x  2 salva salva   4096 feb 22 17:27 Vídeos
drwxrwxr-x  2 salva salva   4096 mar  2 11:06 VirtualBox VMs
salva@salvaromero:~$ echo "Los archivos que hay en el directorio son: " $(ls -l)
Los archivos que hay en el directorio son:  total 268 -rwxr-xr-x 1 salva salva 14168 feb 28 17:49 a.out drwxr-xr-x 6 salva salva 4096 feb 24 09:49 cosas-varias drwxr-xr-x 8 salva salva 4096 mar 2 17:49 Descargas drwxr-xr-x 2 salva salva 4096 mar 3 18:07 Documentos -rw-r--r-- 1 salva salva 2119 feb 24 22:09 ejercicio1 drwxr-xr-x 3 salva salva 4096 feb 25 17:11 Escritorio -rw-r--r-- 1 salva salva 8980 feb 22 17:23 examples.desktop -rw-rw-r-- 1 salva salva 179957 feb 26 10:31 Firefox_wallpaper.png drwxr-xr-x 4 salva salva 4096 mar 2 11:35 Imágenes drwxr-xr-x 8 salva salva 4096 feb 22 17:38 jdk1.8.0_111 drwxr-xr-x 2 salva salva 4096 feb 22 17:27 Música drwxr-xr-x 17 salva salva 4096 mar 3 16:48 netbeans-8.2 drwxr-xr-x 2 salva salva 4096 feb 22 17:27 Plantillas -rw-rw-r-- 1 salva salva 957 feb 28 17:49 prueba.cpp drwxr-xr-x 2 salva salva 4096 feb 22 17:27 Público drwxr-xr-x 9 salva salva 4096 mar 3 16:51 snap drwxr-xr-x 3 salva salva 4096 feb 24 12:05 Universidad drwxr-xr-x 2 salva salva 4096 feb 22 17:27 Vídeos drwxrwxr-x 2 salva salva 4096 mar 2 11:06 VirtualBox VMs
```

Lo muestra todo seguido, ignora los formatos.

Si cambiamos las comillas dobles por comillas simples:

```bash
salva@salvaromero:~$ echo 'Los archivos que hay en el directorio son:  $(ls -l)'
Los archivos que hay en el directorio son:  $(ls -l)
```

**Ejercicio 4.4**

*Pruebe la siguiente asignación*

```bash
$ numero=$numero+1
$ echo $numero
```

*¿Qué ha ocurrido?*
*Como vemos en el ejemplo anterior, todo se ha convertido en carácter, y no se ha realizado la operación*
*matemática que deseábamos. La solución a este problema viene de la mano de la orden del sistema `expr`, con la que podemos evaluar la expresión que le sigue.*

```bash
$ numero=1
$ echo $numero
1
$ numero=`expr $numero + 1`
$ echo $numero
2
```



**Ejercicio 3.5**

*Construya un guion que acepte como argumento una cadena de texto (por ejemplo, su nombre) y
que visualice en pantalla la frase Hola y el nombre dado como argumento.*

```bash
#!/bin/bash
printf "Hola $1\n"
```

**Ejercicio 3.6**

*Varíe el guion anterior para que admita una lista de nombres.*

```bash
#!/bin/bash
printf "Hola $*\n"
```

**Ejercicio 3.7**

*Cree tres variables llamadas `VAR1`, `VAR2`, `VAR3`con los siguientes valores respectivamente "hola", "adios", "14"*

```bash
salva@salvaromero:~/Universidad/Primero/Cuatrimestre2/FS/Práctica/Práctica 3$ VAR1="hola"
salva@salvaromero:~/Universidad/Primero/Cuatrimestre2/FS/Práctica/Práctica 3$ VAR2="adios"
salva@salvaromero:~/Universidad/Primero/Cuatrimestre2/FS/Práctica/Práctica 3$ VAR3="14"
```



a) *Imprima los valores de las tres variables en tres columnas con 15 caracteres de ancho*

```bash
salva@salvaromero:~/Universidad/Primero/Cuatrimestre2/FS/Práctica/Práctica 3$ printf "%15s\t%15s\t%15d\n" $VAR1 $VAR2 $VAR3
hola	adios	14
```

b) *¿Son varoables locales o globales?*

Son variables locales.

c) *Borre la variable VAR2*

```bash
unset VAR2
```

d) *Abra otra ventana de tipo terminal, ¿puede visualizar las dos variables restantes?*

No, porque son locales.

e) *Cree una variable de tipo vector con los valores iniciales de las tres variables*

```bash
salva@salvaromero:~$ variables=(hola adios 14)
```

f) *Muestre el segundo elemento del vector creado en el apartado e*

```bash
salva@salvaromero:~$ echo ${variables[1]}
adios
```

**Ejercicio 3.8**

*Cree un alias que se llame `ne`(nombrado así para indicar el número de elementos) y que devuelva el número de archivos que existen en el directorio actual. ¿Qué cambiaría si queremos que haga lo mismo pero en el directorio home correspondiente al usuario que lo ejecuta?*

```bash
salva@salvaromero:~$ alias ne='ls | wc -l'
```

Para el directorio home

```bash
salva@salvaromero:$ alias ne='ls ~ | wc -l'
```

**Ejercicio 3.9**

*Indique la línea de orden necesaria para buscar todos los archivos a partir del directorio home de
usuario ($HOME) que tengan un tamaño menor de un bloque. ¿Cómo la modificaría para que además imprima el resultado en un archivo que se cree dentro del directorio donde nos encontremos y que se llame archivosP?*

```bash
salva@salvaromero:~/Escritorio$ find ~ -size -1 
```

Para que guarde el archivo  en el directorio actual

``` bash
salva@salvaromero:~/Escritorio$ find ~ -size -1 > archivosP
#si queremos incluir los mensajes de erros ponemos &> en lugar de >
```

**Ejercicio 3.10**

*Indique cómo buscaría todos aquellos archivos del directorio actual que contengan la palabra
“ejemplo”.*

```bash
find -name "*ejemplo*"
./ejemplo3
./ejemplo2
./ejemplo1
```

**Ejercicio 3.11**

*Ejercicio 3.11. Complete la información de find y grep utilizando para ello la orden man.*

``` bash
man find
man grep
```

**Ejercicio 3.12**

*Indique cómo buscaría si un usuario dispone de una cuenta en el sistema.*

```bash
#hay dos formas
#1
grep 'salva' /etc/passwd
#2
id -u 'salva' # en este caso devuelve 1 si se encuentra o error si no
```

**Ejercicio 3.13**

*Indique cómo contabilizar el número de ficheros de la propia cuenta de usuario que no tengan*
*permiso de lectura para el resto de usuarios.*

```bash
salva@salvaromero:~/Escritorio$ find ~ ! -perm o=r | wc -l
```

**Ejercicio 3.14**

*Modifique el ejercicio 8 de forma que, en vez de un alias, sea un guion llamado numE el que*
*devuelva el número de archivos que existen en el directorio que se le pase como argumento.*

```bash
#!/bin/bash
# Título:		numE
# Fecha: 		7/3/2020
# Autor: 		Salvador Romero
# Versión: 		1.0
# Descripción: 	Devuelve el numero de archivos que existen en el directorio pasado
#				como argumento
# Opciones: 	ninguna
# Uso: 			numE directorio

ls $1 | wc -l
```



### Práctica 4

**Ejercicio 4.1**

*Utilizando una variable que contenga el valor entero 365 y otra que guarde el número del día actual*
*del año en curso, realice la misma operación del ejemplo anterior usando cada una de las diversas formas de cálculo comentadas hasta el momento, es decir, utilizando expr, $(( ... )) y $[ ... ].*

```bash
anio=365
dia=`date +%j`

#$[]
salva@salvaromero:~$ resultado="Faltan $[($anio - $dia) / 7] semanas hasta el fin de año"
salva@salvaromero:~$ echo $resultado 
Faltan 44 semanas hasta el fin de año

#$(())
salva@salvaromero:~$ resultado="Faltan $(( ($anio - $dia) / 7 )) semanas hasta el fin de año"
salva@salvaromero:~$ echo $resultado 
Faltan 44 semanas hasta el fin de año

#expr``


```

**Ejercicio 4.2**

*Realice las siguientes operaciones para conocer el funcionamiento del operador de incremento
como sufijo y como prefijo. Razone el resultado obtenido en cada una de ellas*

```bash
salva@salvaromero:~$ v=1
salva@salvaromero:~$ echo $v
1
salva@salvaromero:~$ echo $((v++)) # primero imprime luego suma
1
salva@salvaromero:~$ echo $v
2
salva@salvaromero:~$ echo $((++v)) # primero suma luego imprime
3
salva@salvaromero:~$ echo $v
3
```



**Ejercicio 4.3**

*Utilizando el operador de división, ponga un caso concreto donde se aprecie que la asignación
abreviada es equivalente a la asignación completa, es decir, que x/=y equivale a x=x/y.*

```bash
salva@salvaromero:~$ x=5
salva@salvaromero:~$ y=3
salva@salvaromero:~$ echo $x $y
5 3
salva@salvaromero:~$ let x/=y
salva@salvaromero:~$ echo $x
1
salva@salvaromero:~$ x=5
salva@salvaromero:~$ echo $x
5
salva@salvaromero:~$ let x=x/y
salva@salvaromero:~$ echo $x
1
```

**Ejercicio 4.4**

*Compruebe qué ocurre si en el ejemplo anterior utiliza comillas dobles o simples para acotar todo lo
que sigue a la orden echo. ¿Qué sucede si se acota entre comillas dobles solamente la expresión aritmética que se quiere calcular?, ¿y si se usan comillas simples?*

```bash
salva@salvaromero:~$ echo 6/5 |bc -l
1.20000000000000000000
salva@salvaromero:~$ echo "6/5 | bc -l"
6/5 | bc -l
salva@salvaromero:~$ echo '6/5 | bc -l'
6/5 | bc -l
salva@salvaromero:~$ echo '6/5' | bc -l
1.20000000000000000000
salva@salvaromero:~$ echo "6/5" | bc -l
1.20000000000000000000
```

**Ejercicio 4.5**

*Calcule con decimales el resultado de la expresión aritmética (3-2)/5. Escriba todas las expresiones que haya probado hasta dar con una respuesta válida. Utilizando una solución válida, compruebe qué sucede cuando la expresión aritmética se acota entre comillas dobles; ¿qué ocurre si se usan comillas simples?, ¿y si se ponen apóstrofos inversos?*

```bash
salva@salvaromero:~$ echo '(3-2)/5' | bc -l
.20000000000000000000
salva@salvaromero:~$ echo "(3-2)/5" | bc -l
.20000000000000000000
salva@salvaromero:~$ echo `(3-2)/5` | bc -l
bash: command substitution: línea 1: error sintáctico cerca del elemento inesperado `/5'
bash: command substitution: línea 1: `(3-2)/5'
```

**Ejercicio 4.6**

*Consulte la sintaxis completa de la orden let utilizando la orden de ayuda para las órdenes
empotradas (help let) y tome nota de su sintaxis general.*

```bash
help let
let: let arg [arg ...]
    Evalúa expresiones aritméticas.
    
    Evalúa cada ARG como una expresión aritmética.  La evaluación se hace
    con enteros de longitud fija, sin revisar desbordamientos, aunque la
    la división por 0 se captura y se marca como un error.  La siguiente
    lista de operadores está agrupada en niveles de operadores de la misma
    prioridad.  Se muestran los niveles en orden de prioridad decreciente.
    
    	id++, id--	post-incremento, post-decremento de variable
    	++id, --id	pre-incremento, pre-decremento de variable
    	-, +		menos, más unario
    	!, ~		negación lógica y basada en bits
    	**		exponenciación
    	*, /, %		multiplicación, división, residuo
    	+, -		adición, sustracción
    	<<, >>		desplazamientos de bits izquierdo y derecho
    	<=, >=, <, >	comparación
    	==, !=		equivalencia, inequivalencia
    	&		AND de bits
    	^		XOR de bits
    	|		OR de bits
    	&&		AND lógico
    	||		OR lógico
    	expr ? expr : expr
    			operador condicional
    	=, *=, /=, %=,
    	+=, -=, <<=, >>=,
    	&=, ^=, |=	asignación
    
    Se permiten las variables del intérprete como operandos.  Se reemplaza
    el nombre de la variable por su valor (coercionado a un entero
    de longitud fija) dentro de una expresión.  La variable no
    necesita tener activado su atributo integer para ser usada en
    una expresión.
    
    Los operadores se evalúan en orden de prioridad.  Primero se
    evalúan las sub-expresiones en paréntesis y pueden sobrepasar
    las reglas de prioridad anteriores.
    
    Estado de salida:
    Si el último ARGumento se evalúa como 0, let devuelve 1; de otra
    forma, let devuelve 0.

```



**Ejercicio 4.7**

*Con la orden let es posible realizar asignaciones múltiples y utilizar operadores que nosotros no hemos mencionado anteriormente. Ponga un ejemplo de asignación múltiple y, por otra parte, copie en un archivo el orden en el que se evalúan los operadores que admite. Apóyese a través de la ayuda que ofrece help let.*

```bash
let x=1 y=2
```

Orden de operadores:

>  Los operadores se evalúan en orden de prioridad.  Primero se evalúan las sub-expresiones en paréntesis y pueden sobrepasar las reglas de prioridad anteriores.



**Ejercicio 4.8**

*Probad los siguientes ejemplos y escribir los resultados obtenidos con la evaluación de expresiones*

Ejemplo 1

```bash
salva@salvaromero:~$ echo ejemplo1
ejemplo1
salva@salvaromero:~$ valor=6
salva@salvaromero:~$ if [ $valor = 3 ]; then echo si; else echo no; fi
no
salva@salvaromero:~$ echo $valor
6
```

Ejemplo 2

```bash
salva@salvaromero:~$ echo ejemplo2
ejemplo2
salva@salvaromero:~$ valor=5
salva@salvaromero:~$ if [ $valor = 3 ] && ls; then echo si; else echo no; fi
no
salva@salvaromero:~$ echo $valor
5
```

Ejemplo 3

```bash
salva@salvaromero:~$ echo ejemplo3
ejemplo3
salva@salvaromero:~$ valor=5
salva@salvaromero:~$ if [ $valor = 5 ] && ls; then echo si; else echo no; fi
 cosas-varias   Escritorio              jdk1.8.0_111   Público      'VirtualBox VMs'
 Descargas      examples.desktop        Música         snap
 divisores      Firefox_wallpaper.png   netbeans-8.2   Universidad
 Documentos     Imágenes                Plantillas     Vídeos
si

```

Ejemplo 4

```bash
salva@salvaromero:~$ echo ejemplo4
ejemplo4
salva@salvaromero:~$ valor=6
salva@salvaromero:~$ if ((valor==3)); then echo si; else echo no; fi
no
```

Ejemplo 5

```bash
echo ejemplo5
valor=5
if ((valor==5)) && ls; then echo si; else echo no; fi
echo $valor

#igual que 2
```

Ejemplo 6

```bash
echo ejemplo6
valor=5
if ((valor==5)) && ls; the echo si; else echo no; fi
echo $valor
#igual que 3
```

Ejemplo 7

```bash
salva@salvaromero:~$ echo ejemplo7
ejemplo7
salva@salvaromero:~$ echo $((3>5))
0
salva@salvaromero:~$ echo $?
0
```

Ejemplo 8

```bash
salva@salvaromero:~$ echo ejemplo8
ejemplo8
salva@salvaromero:~$ ((3>5))
salva@salvaromero:~$ echo $?
1
```

Ejemplo 9

```bash
salva@salvaromero:~$ echo ejemplo9
salva@salvaromero:~$ if ((3>5)); then echo 3 es mayor que 5; else echo 3 no es mayor que 5; fi
3 no es mayor que 5
```

**Ejercicio 4.9**

*Haciendo uso de las órdenes conocidas hasta el momento, construya un guion que admita dos parámetros, que compare por separado si el primer parámetro que se le pasa es igual al segundo, o es menor, o es mayor, y que informe tanto del valor de cada uno de los parámetros como del resultado de cada una de las evaluaciones mostrando un 0 o un 1 según corresponda.*

```bash
#!/bin/bash
#informamos de los valores de cada parametro
printf "Variables\tValores\nParámetro1\t%4i\nParámetro2\t%4i\n\n\n" $1 $2

#comparamos por separado
#parametro 1 menor que parametro 2
echo "$1 es menor que $2 --> `if [[ $1 < $2 ]]; then echo 1; else echo 0; fi`"

#parametro 1 igual que parametro 2
echo "$1 es igual que $2 --> `if [[ $1 == $2 ]]; then echo 1; else echo 0; fi`"

#parametro 1 mayor que parametro 2
echo "$1 es mayor que $2 --> `if [[ $1 > $2 ]]; then echo 1; else echo 0; fi`"
```

**Ejercicio 4.10**

*Usando test, construya un guion que admita como parámetro un nombre de archivo y realice las
siguientes acciones: asignar a una variable el resultado de comprobar si el archivo dado como parámetro es plano y tiene permiso de ejecución sobre él; asignar a otra variable el resultado de comprobar si el archivo es un enlace simbólico; mostrar el valor de las dos variables anteriores con un mensaje que aclare su significado. Pruebe el guion ejecutándolo con /bin/cat y también con /bin/rnano.*

```bash
#!/bin/bash
esplanoyejecutable=`test -f $1 -a -x $1 && echo true || echo false`
esenlacesimbolico=`test -h $1 && echo true || echo false`

if [[ $esplanoyejecutable == true ]]; then echo "El archivo $1 es plano y ejecutable"; else echo "El archivo $1 no es plano y ejecutable"; fi

if [[ $esenlacesimbolico == true ]]; then echo "El archivo $1 es un enlace simbolico"; else echo "El archivo $1 no es un enlace simbolico"; fi
```

**Ejercicio 4.11**

*Ejecute help test y anote qué otros operadores se pueden utilizar con la orden test y para
qué sirven. Ponga un ejemplo de uso de la orden test comparando dos expresiones aritméticas y otro
comparando dos cadenas de caracteres.*

```bash
help test
#salida
test: test [expresión]
    Evaluate conditional expression.
    
    Exits with a status of 0 (true) or 1 (false) depending on
    the evaluation of EXPR.  Expressions may be unary or binary.  Unary
    expressions are often used to examine the status of a file.  There
    are string operators and numeric comparison operators as well.
    
    The behavior of test depends on the number of arguments.  Read the
    bash manual page for the complete specification.
    
    File operators:
    
      -a FILE        True if file exists.
      -b FILE        True if file is block special.
      -c FILE        True if file is character special.
      -d FILE        True if file is a directory.
      -e FILE        True if file exists.
      -f FILE        True if file exists and is a regular file.
      -g FILE        True if file is set-group-id.
      -h FILE        True if file is a symbolic link.
      -L FILE        True if file is a symbolic link.
      -k FILE        True if file has its `sticky' bit set.
      -p FILE        True if file is a named pipe.
      -r FILE        True if file is readable by you.
      -s FILE        True if file exists and is not empty.
      -S FILE        True if file is a socket.
      -t FD          True if FD is opened on a terminal.
      -u FILE        True if the file is set-user-id.
      -w FILE        True if the file is writable by you.
      -x FILE        True if the file is executable by you.
      -O FILE        True if the file is effectively owned by you.
      -G FILE        True if the file is effectively owned by your group.
      -N FILE        True if the file has been modified since it was last read.
    
      FILE1 -nt FILE2  True if file1 is newer than file2 (according to
                       modification date).
    
      FILE1 -ot FILE2  True if file1 is older than file2.
    
      FILE1 -ef FILE2  True if file1 is a hard link to file2.
    
    All file operators except -h and -L are acting on the target of a symbolic
    link, not on the symlink itself, if FILE is a symbolic link.
    
    String operators:
    
      -z STRING      True if string is empty.
    
      -n STRING
         STRING      True if string is not empty.
    
      STRING1 = STRING2
                     True if the strings are equal.
      STRING1 != STRING2
                     True if the strings are not equal.
      STRING1 < STRING2
                     True if STRING1 sorts before STRING2 lexicographically.
      STRING1 > STRING2
                     True if STRING1 sorts after STRING2 lexicographically.
    
    Other operators:
    
      -o OPTION      True if the shell option OPTION is enabled.
      -v VAR         True if the shell variable VAR is set.
      -R VAR         True if the shell variable VAR is set and is a name
                     reference.
      ! EXPR         True if expr is false.
      EXPR1 -a EXPR2 True if both expr1 AND expr2 are true.
      EXPR1 -o EXPR2 True if either expr1 OR expr2 is true.
    
      arg1 OP arg2   Arithmetic tests.  OP is one of -eq, -ne,
                     -lt, -le, -gt, or -ge.
    
    Arithmetic binary operators return true if ARG1 is equal, not-equal,
    less-than, less-than-or-equal, greater-than, or greater-than-or-equal
    than ARG2.
    
    See the bash manual page bash(1) for the handling of parameters (i.e.
    missing parameters).
    
    Exit Status:
    Returns success if EXPR evaluates to true; fails if EXPR evaluates to
    false or an invalid argument is given.

### Ejemplo comparando dos strings
test string1 = string2 #true si son iguales
test string1 < string2 #true si string2 es mayor lexicograficamente que string1

### Ejemplo comparando expresiones aritmeticas
test numero1 -eq numero2 #true si son iguales
test numero1 -ge numero2 #true si numero1 >= numero2
```

**Ejercicio 4.12**

*Responda a los siguientes apartados*

*a) Razone qué hace la siguiente orden:*
`if test -f ./sesion5.pdf ; then printf “El archivo ./sesion5.pdf existe\n”; fi`

```bash
#Comprueba que exista el erchivo sesion5.pdf en el directorio actual
```

*b) Añada los cambios necesarios en la orden anterior para que también muestre un mensaje de aviso en  caso de no existir el archivo. (Recuerde que, para escribir de forma legible una orden que ocupe más de una línea, puede utilizar el carácter “\” como final de cada línea que no sea la última.)*

```bash
if test -f ./sesion5.pdf ; then printf "El archivo ./sesion5.pdf existe\n"; else printf "El archivo ./sesion5.pdf no existe\n" fi
```

*c) Sobre la solución anterior, añada un bloque elif para que, cuando no exista el archivo ./sesion5.pdf,*
*compruebe si el archivo /bin es un directorio. Ponga los mensajes adecuados para conocer el resultado*
*en cada caso posible.*

```bash
if [[ -f ./sesion5.pdf ]]; then
	printf "El archivo ./sesion5.pdf existe\n";	
elif [[ -d /bin ]];then
	printf "El archivo ./sesion5.pdf no existe, /bin es un directorio\n";
else
	printf "El archivo ./sesion5.pdf no existe y /bin no es un directorio\n";
fi
```

*d) Usando como base la solución del apartado anterior, construya un guion que sea capaz de hacer lo mismo pero admitiendo como parámetros la ruta relativa del primer archivo a buscar y la ruta absoluta del*
*segundo. Pruébelo con los dos archivos del apartado anterior.*

```bash
#!/bin/bash
# $1 ruta relativa del archivo a buscar
# $2 ruta absoluta del directorio a buscar

if [[ -f $PWD/$1 ]]; then
	printf "El archivo $1 existe\n";	
elif [[ -d $2 ]];then
	printf "El archivo $1 no existe, $2 es un directorio\n";
else
	printf "El archivo $1 no existe y $2 no es un directorio\n";
fi
```

**Ejercicio 4.13**

*Construya un guón que admita como argumento el nombre de un archivo o directorio y que permita saber si somos el propietario del archivo y si tenemos permiso de lectura sobre él*

```bash
#!/bin/bash
if [[ -O $1 ]]; then
	printf "Somos el dueño de $1\n"
else
	printf "No somos el dueño de $1\n"
fi

if [[ -r $1 ]]; then
	printf "Tenemos permiso de lectura para $1\n"
else
	printf "No tenemos permiso de lectura para $1\n"
fi
```

**Ejercicio 4.14**

*Escriba un guion que calcule si el número de días que faltan hasta fin de año es múltiplo de cinco o no, y que comunique el resultado de la evaluación. Modifique el guion anterior para que admita la opción -h de manera que, al ejecutarlo con esa opción, muestre información de para qué sirve el guion y cómo debe  ejecutarse*

```bash
#!/bin/bash
dia=`date +%j`
anio=366 #estamos en año bisiesto
restante=`expr $anio - $dia`

if [[ -z $1 ]]; then
	if (( $restante % 5 == 0));then
		printf "El numero de dias que faltan hasta año nuevo es múltiplo de 5\n"
	else
		printf "El numero de dias que faltan hasta año nuevo no es múltiplo de 5\n"
	fi
elif [[ $1 = "-h" ]]; then
	printf "Este guión indica si el número de días que quedan para que acabe el año es múltiplo de 5\nNo admite argumentos, excepto \"-h\" para mostrar este mensaje\n"
else
	printf "Uso inválido, consulte -h para ayuda\n"
fi
```

**Ejercicio 4.15**

*¿Qué pasa en el ejemplo anterior si eliminamos la redirección de la orden if?*

*Ejemplo*

```bash
#guion de ejemplo
#!/bin/bash
declare -rx SCRIPT=${0##*/}
                    		#donde SCRIPT contiene sólo el nombre del guión
                    		#${var##Patron} actúa eliminando de $var aquella parte
                    		#que cumpla de $Patron desde el principio de $var
                 	   		#En este caso: elimina todo lo que precede al
							#último slash “/".
if rm ${1} ; then
	printf "%s\n" "$SCRIPT: archivo temporal borrado"
else
	STATUS=177
	printf "%s – código de finalizacion %d\n" \
	"$SCRIPT:$LINENO no es posible borrar archivo" $STATUS
fi 2> /dev/null
```

Si quitamos la redirección se mostrará por pantalla el mensaje de error de la orden `rm` en caso de que lo hubiera.

**Ejercicio 4.16**

*Haciendo uso del mecanismo de cauces y de la orden echo, construya un guion que admita un argumento y que informe si el argumento dado es una única letra, en mayúsculas o en minúsculas, o es algo distinto de una única letra*

```bash
#!/bin/bash
echo $1 | egrep -q "\<[a-Z]{1}\>" && printf "Es una única letra en mayúsculas o minúsculas\n" || printf "Es algo distinto de una única letra\n"
```

**Ejercicio 4.17**

*Haciendo uso de expresiones regulares, escriba una orden que permita buscar en el árbol de directorios los nombres de los archivos que contengan al menos un dígito y la letra e. ¿Cómo sería la orden si quisiéramos obtener los nombres de los archivos que tengan la letra e y no contengan ni el 0 ni el 1?*

```bash
find / -regex '.*e*.*[0-9]{1,}.*e*.*'
```

```bash
find / -regex '.*e*.*[^01][2-9]{1,}.*e*.*'
```

**Ejercicio 4.18**

*Utiizando la orden grep, exprese una forma alternativa de realizar lo mismo que con wc -l*

```bash
cat <archivo>|grep –c ^ 
```





### Práctica 5

**Ejercicio 5.1**

*Escriba un guión que acepte dos argumentos. El primero será el nombre de un directorio y el segundo será un valor entero. El funcionamiento del guión será el siguiente: deberán anotarse en un archivo denomidado `archivosSinN.txt` aquellos archivos del directorio dado como argumento y que cumplan la condición de tener un tamaño menor al valor aportado en el segundo argumento. Se deben tener en cuenta las comprobaciones sobre los argumentos, es decir, debe haber dos argumentos, el primero deberá ser un directorio existente y el segundo un valor entero.*

```bash
#!/bin/bash
# $1 directorio existente
# $2 entero

if test $# -eq 2 && test -d $1 && let var=$2;then
	find $1 -maxdepth 1 -type f -size -$2 >> archivosSizN.txt
else
	echo "Argumentos invalidos"
fi

```

**Ejercicio 5.2**

*Escriba un guion que acepte el nombre de un directorio como argumento y muestre como resultado el nombre de todos y cada uno de los archivos del mismo y una leyenda que diga "Directorio", "Enlace" o "Archivo regular", según corresponda. Incluya la comprobación necesaria sobre el argumento, es decir, determine si el nombre aportado se trata de un directorio existente.*

```bash
#!/bin/bash
# $1 es un directorio existente

if [[ -d $1 ]]; then
	for i in `ls $1`;
	do
		echo "$i: "`file $1/$i --brief`
	done
else
	echo "$1 no es un directorio válido"
fi
```

**Ejercicio 5.3**

*Escriba un guion en el que, a partir de la pulsación de una tecla, detecte la zona del teclado donde* *se encuentre. Las zonas vendrán determinadas por las filas. La fila de los números 1, 2, 3, 4, ... será la fila* *1, las teclas donde se encuentra la Q, W, E, R, T, Y,... serán de la fila 2, las teclas de la A, S, D,* *F, ... serán de la fila 3 y las teclas de la Z, X, C, V, ... serán de la fila 4. La captura de la tecla se* *realizará mediante la orden read.*

```bash
#!/bin/bash

# menudo lio de opciones xd

read -p "Introduce la tecla que quiere comprobar: " tecla

case $tecla in
	º | ª | \\ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | \' | ¡ | \| | \! | \" | @ | · | \# | $ | \~ | % | \& | ¬ | \/ | \( | \) | \' | \? ) printf "$tecla está en la fila 1\n";;
	q | Q | \w | W | e | E | r | R | t | T | y | Y | u | U | i | I | o | O | p | P | \` | ^ | [ | + | \* | ] | ç | \} ) printf "$tecla está en la fila 2\n";;
	a | A | s | S | d | D | f | F | g | G | h | H | j | J | k | K | l | L | ñ | Ñ | \' | \{ ) printf "$tecla está en la fila 3\n";;
	z | Z | x | X | c | C | v | V | b | B | n | N | m | n | , | \; | \: | \. | \- | _ ) printf "$tecla está en la fila 4\n";;
esac

```

**Ejercicio 5.4**

*Escriba un guion que acepte como argumento un parámetro en el que el usuario indica el mes que quiere ver, ya sea en formato numérico o usando las tres primeras letras del nombre del mes, y muestre el nombre 
completo del mes introducido. Si el número no está comprendido entre 1 y 12 o las letras no son significativas del nombre de un mes, el guion deberá mostrar el correspondiente mensaje de error.*

```bash
#!/bin/bash
# $1 mes
case $1 in
	ene | ENE | 1 ) echo Enero;;
	feb | FEB | 2 ) echo Febrero;;
	mar | MAR | 3 ) echo Marzo;;
	abr | ABR | 4 ) echo Abril;;
	may | MAY | 5 ) echo Mayo;;
	jun | JUN | 6 ) echo Junio;;
	jul | JUL | 7 ) echo Julio;;
	ago | AGO | 8 ) echo Agosto;;
	sep | SEP | 9 ) echo Septiembre;;
	oct | OCT | 10 ) echo Octubre;;
	nov | NOV | 11 ) echo Noviembre;;
	dic | DIC | 12 ) echo Diciembre;;
	* ) echo Parámetro no válido
esac
```



**Ejercicio 5.5**

*Escriba un guion que solicite un numero hasta que su valor esté comprendido entre 1 y 10. Deberá usar la orden while y , para la captura del número, la orden read*

```bash
#!/bin/bash
while :
do
	read -p "Introduce un numero entre 1 y 10: " numero
	if test $numero -le 10 && test $numero -gr 1; then
	break
	fi
done

### otra forma
#!/bin/bash
numero=-1
while [ $numero -lt 1 -o $numero -gt 10 ];
do
	read -p "Introduce un numero entre 1 y 10: " numero
done
```



**Ejercicio 5.6**

*Copie este ejercicio y pruébelo en su sistema para ver su funcionamiento. ¿Qué podemos modificar
para que el giro se vea más rápido o más lento? ¿Qué hace la opción -e de las órdenes echo del guion?*

```bash
# para modificar la velocidad del giro
INTERVAL=n
# con un n pequeño gira más rápido, n grande para que vaya lento
```

La opción `-e`de `echo` sirve para que interprete las barras de escape. Así:

```bash
echo -e "\n"

echo "\n"
\n
```



**Ejercicio 5.7**

Escriba un guion que admita como argumento el nombre de un tipo de shell (por ejemplo, csh, sh, bash, tcsh, etc.) y nos dé un listado ordenado alfabéticamente de los usuarios que tienen dicho tipo de shell por defecto cuando abren un terminal. Dicha información del tipo de shell asignado a un usuario se puede encontrar en el archivo `/etc/passwd`, cuyo contenido está delimitado por `:`. Cada información situada entre esos delimitadores representa un campo y precisamente el campo que nos interesa se encuentra situado en primer lugar. En definitiva, para quedarnos con lo que aparece justo antes del primer  delimitador será útil la orden siguiente: 

​																	`cut -d':' -f1 /etc/passwd `

*Donde la opción` –d` indica cuál es el delimitador utilizado y la opción `–f1` representa a la secuencia de caracteres del primer campo. Realice, utilizando el mecanismo de cauces, el ejercicio pero usando la orden `cat` para mostrar el contenido de un archivo y encauzado con la orden `cut` para filtrar la información que aparece justo antes del delimitador `:` .
Realice también la comprobación de la validez del tipo de Shell que se introduce como argumento. Use para ello  la información que encontrará en el archivo `/etc/shells` donde encontrará los tipos de Shell que se pueden utilizar en el sistema.*

```bash
#!/bin/bash
read -p "Introduce el nombre de la shell: " shell
cat /etc/shells | grep -q $shell && ok=0 || ok=1
if [ $ok == 0 ];
then
	echo "Los usuarios con esta shell son: "
	cat /etc/passwd | grep $shell | cut -d ':' -f1
else 
	echo "No se ha encontrado la shell $shell"
fi
```



**Ejercicio 5.8**

*Dos órdenes frecuentes de Unix son tar y gzip. La orden tar permite almacenar/extraer varios archivos de otro archivo. Por ejemplo, podemos almacenar el contenido de un directorio en un archivo con*

​														`tar -cvf archivo.tar directorio`

*(la opción `-x`) extrae los archivos de un archivo `.tar`).*

*La orden gzip permite comprimir el contenido de un archivo para que ocupe menos espacio. Por ejemplo, gzip archivo comprime archivo y lo sustituye por otro con el mismo nombre y con la extensión .gz. La orden para descomprimir un archivo .gz o .zip es gunzip.*

*Dadas estas órdenes construya un guion, denominado cpback, que dado un directorio o lista de archivos como argumento(s) los archive y comprima en un archivo con nombre copiaYYMMDD, donde YY corresponde al año, la MM al mes y la DD al día, dentro de un directorio denominado CopiasSeguridad. El guion debe realizar las comprobaciones oportunas: los argumentos existen, el directorio de destino existe y si no, lo crea.*

```bash
#!/bin/bash
#primero comprobamos el numero de argumentos
#luego comprobamos, si $# == 1 entonces se hace con directorios, en caso contrario una lista de archivos
#comprobamos/creamos el directorio de las copias de seguridad
#si es un directorio le hacemos tar
#si es una lista de archivos, los comprobamos, los copiamos a un archivo, le hacemos tar, borramos archivo de lista
dia=`date +%d`
mes=`date +%m`
anio=`date +%g`
salida=copia$anio$mes$dia
dirsalida=CopiasSeguridad
archivos=true

_uso()
{
	echo "Uso: 5.8 <directorio> o bien 5.8 <archivo1 archivo2 ...>"
	exit 1
}
_fin()
{
	echo "Copia finalizada"
}


if [ $# -lt 1 ]; then echo "Se necesitan argumentos para este guion"; _uso;fi

test -d $1 && directorio=true || directorio=false

if [ $directorio == false -a $# -eq 1 ]; then echo "El argumento introducido no es un directorio válido"; _uso; fi

if [ ! -d $dirsalida ]; then echo "No existe el directorio de copias de seguridad, se crea."; mkdir $dirsalida; fi

if [[ $directorio == true ]];
then
	tar -cf $dirsalida/$salida $1
	_fin
else
	for archivo in $@;
	do
		echo $archivo
		test -f $archivo || archivos=false
		echo $archivo >> $dirsalida/temp.txt
	done

	if [[ $archivos = true ]]; 
	then 
	       	tar -cf $dirsalida/$salida -T $dirsalida/temp.txt
	else
		echo "Los parámetros introducidos no son correctos"; _uso;
     	fi
	rm $dirsalida/temp.txt
fi
```

**Ejercicio 5.9**

*Hacer un script en Bash denominado newdirfiles con los siguientes tres argumentos:*
*• <dirname> Nombre del directorio que, en caso de no existir, se debe crear para alojar en él los archivos*
*que se han de crear.*
*• <num_files> Número de archivos que se han de crear.*
*• <basefilename> Será una cadena de caracteres que represente el nombre base de los archivos.*

*Ese guion debe realizar lo siguiente:*
*• Comprobar que el número de argumentos es el correcto y que el segundo argumento tenga un valor*
*comprendido entre 1 y 99.*
*• Crear, en caso de no existir, el directorio dado en el primer argumento a partir del directorio donde se esté*
*situado y que posea permisos de lectura y escritura para el usuario $USER.*

**Dentro del directorio dado en el primer argumento, crear archivos cuyos contenidos estarán vacíos y cuyos*
*nombres lo formarán el nombre dado como tercer argumento y un número que irá desde 01 hasta el*
*número dado en el segundo argumento.*

```bash
#!/bin/bash
if [ $# == 3 ] && [ $2 -le 99 -a $2 -ge 1 ]; then 
	#comprobacion/creacion de directorio
	[ -d $1 ] || mkdir $1; echo "Directorio $1 creado";
	for i in `seq 1 1 $2`;
	do
		echo Archivo $1/$3$i creado
		touch $1/$3$i
	done
else
	echo "Uso incorrecto. Uso: 5.9 <directorio> <numero_archivos> <nombre_base>"
	echo "<numero_archivos> debe ser un numero entre 1 y 99"
fi
```



### Práctica 6

**Ejercicio 6.1**

*Indique cuál ha sido el error introducido en el guión anterior y cómo se corregiría*

El fallo está que en la comparación en el if, los corchetes van separados de las condiciones por espacios. Con el error está escrito así: `if ["$2" = "after" ] ; then`. Para que no falle habría que ponerlo así: 	`if [ "$2" = "after" ] ; then` .

**Ejercicio 6.2**

*Aplicar las herramientas de depuración vistas en la sección 2 para la detección de errores durante el*
*desarrollo de los guiones propuestos como ejercicios en la práctica 5.*

No. No voy a rehacer toda la práctica 5 con aseciones ni herramientas de depuración.

**Ejercicio 6.3**

*Escribir un guion que nos dé el nombre del proceso del sistema que consume más memoria.*

```bash
#! /bin/bash
ps -eo cmd --sort=-%mem | head -n 2 | tail -n 1
```

**Ejercicio 6.4**

*Escribir un guion que escriba números desde el 1 en adelante en intervalos de un segundo ¿Cómo se podría, desde otro terminal, detener la ejecución de dicho proceso, reanudarlo y terminar definitivamente su ejecución?*

```bash
# Guion para generar los numeros cada 1 segundo
#! /bin/bash
contador=1
while :
do
	echo $contador
	contador=$(($contador + 1))
	sleep 1
done
```

Primero buscamos el ppid del proceso, para ello usamos

```bash
top -b -n 1| grep nombreguion 
```

eso nos devuelve (por ejemplo)

```bash
 6647 salva     20   0   19988   3308   3056 S   0,0  0,0   0:00.01 6.4
```

donde el primer numero es el ppid. Ahora para detenerlo usamos

```bash
kill -STOP 6647
```

para reanudarlo:

```bash
kill -CONT 6647
```

para terminarlo definitivamente

```bash
kill 6647
# también podemos usar kill -9 6647 para forzarlo a terminar
```

**Ejercicio 6.5**

*¿Se puede matar un proceso que se encuentra suspendido? En su caso, ¿cómo?*

Sí, con la orden `kill`.

**Ejercicio 6.6**

*¿Qué podemos hacer a la orden `top`  para que nos muestre sólo los procesos nuestros?*

```bash
top -u usuario #si no sabemos el usuario podemos usar $UID
```

