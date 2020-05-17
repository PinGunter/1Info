**1. Dado un proceso en un SO con su información de contexto, de datos y de código según se muestra en la figura y que ya ha sido atendido en un 50% y le resta la otra mitad para finalizar su ejecución. Con la idea de optimizar el espacio de memoria para que el SO pudiera disponer de un mayor número de procesos en ésta, ¿podría reducirse el espacio que ocupa en memoria en alguna de las siguientes instancias?**

| **a) La lista de procesos**                    |      |
| ---------------------------------------------- | ---- |
| **b) La información del contexto del proceso** |      |
| **c) Tamaño de los datos**                     |      |
| **d) Tamaño del código**                       |      |

La lista de procesos y la información de contexto es indispensable para que el SO administre bien los procesos. En general, como está en ejecución todos los datos son necesarios y no se puede reducir. 

**2. ¿Por qué cuando un proceso está en modo “ejecutándose” y pretende acceder a una dirección de memoria fuera del área asignada, se informa de que se ha producido un error en la ejecución? ¿Quién informa de ello? Razone la respuesta.**

Porque a pesar de estar ejecutándose, los procesos no tienen permisos  para escribir en cualquier posición de memoria puesto que podrían causar errores. Es por esto que el SO detiene el proceso e informa del error en la ejecución. El MMU es el que se encarga de informar del error.

**3. ¿Tiene sentido un modelo de 5 estados en los procesos de un SO monousuario? Razone la respuesta**

Sí tiene sentido por dos razones. La primera es que un único usuario (monousuario) puede necesitar ejecutar varios procesos al mismo tiempo y por tanto se necesita gestionar esos procesos de manera eficiente. La segunda es que el modelo de 5 estados es útil aunque sólo se encargue de un sólo proceso ya que es una buena manera de gestionar los procesos junto las llamadas al SO que pueda hacer el proceso.

**4. Dado un proceso que está en modo "ejecutándose" y pretende acceder a una dirección de memoria fuera del área asignada, lo cual sería un error en la ejecución, ¿a qué modo pasaría dicho proceso? Razone la respuesta**

| **a) Bloqueado**          |      |
| ------------------------- | ---- |
| **b) No cambia de modo.** |      |
| **c) Finalizado**         | *    |
| **d) Preparado**          |      |

Cambia a modo finalizado ya que el SO interrumpe el proceso y lo detiene, lo finaliza. 

**5. Un planificador de procesos tiene una tares concreta dentro de un SO multiprogramado. ¿Tiene sentido disponer de un planificador de procesos en un SO monoprogramado? Razone la respuesta.**

No, ya que cada proceso se ejecuta de manera secuencial, no en paralelo.

**6. Dado un SO multiprogramado, ¿bajo qué circunstancias se podría prescindir del planificador de procesos? Razone la respuesta.**

Bajo ninguna circunstancia se puede prescindir de él puesto que por la naturaleza de un sistema multiprogramado se necesita algo que gestione los recursos disponibles entre los distintos procesos que están ejecutando simultáneamente.

**7. Diga cuales de las siguientes operaciones pueden realizarse únicamente en modo supervisor, o modo kernel:**

| **a) Consultar la hora del sistema**                         |                                |
| ------------------------------------------------------------ | ------------------------------ |
| **b) Cambiar la fecha del sistema**                          | *                              |
| **c) Leer una pista/sector de un disco magnético**           | * (porque es op de bajo nivel) |
| **d) Generar una interrupción software**                     |                                |
| **e) Generar una interrupción**                              |                                |
| **f) Modificar la dirección de un vector de la tabla de vectores de interrupción** | *                              |
| **g) Deshabilitar las interrupciones**                       | *                              |

**8. En el caso de un ordenador que se vaya a usar únicamente para un único usuario, ¿qué interés puede tener la existencia de los modos de funcionamiento supervisor/usuario?**

Que los programas no accedan a direcciones de memoria fundamentales para el correcto funcionamiento del SO. En general, mantener un esquema de permisos que permita detener acciones peligrosas para la estabilidad o el funcionamiento del sistema.

También es necesario, si por ejemplo, se da un error. En este caso es necesario el modo supervisor para que produzca la interrupción y detenga el programa.

**9. Cuestiones sobre procesos, y asignación de CPU:**

| **a) ¿Es necesario que lo último que haga todo proceso antes de finalizar sea una llamada al sistema para finalizar? ¿Sigue siendo esto cierto en sistemas monoprogramados?** |
| ------------------------------------------------------------ |
| Sí, ya que es la manera de informar al SO que ha terminado, para que libere los recursos. En monoprogramados también es necesario para saber cuando debe comenzar el siguiente proceso. |
| **b) Cuando el controlador de un dispositivo produce una interrupción ¿se produce necesariamente un cambio de contexto?, ¿y cuando se produce una llamada al sistema?** |
| No es necesario en todos los casos porque hay situaciones en las que solo es necesario un cambio de modo. < -- profe.  \|\|  == >  Sí es necesario, puesto que en una interrupción el proceso se detiene y el SO ejecuta código que gestiona la interrupción, produciéndose así un cambio de contexto. En el caso de una llamada al sistema no es necesario. |
| **c) Cuando un proceso se bloquea, ¿deberá encargarse él directamente de cambiar el valor de su estado en el descriptor de proceso o PCB?** |
| El PCB se encarga de saber el estado de cada proceso, pero no lo puede modificar. Para cambiar el estado de un proceso es el SO en modo kernel el que lo cambia. |
| **d) Sea un proceso que cambia de Ejecutándose a Bloqueado, ¿puede este cambio provocar un cambio de estado en otros procesos? Si es así, ¿en qué casos?** |
| Sí, mientras está bloqueado otro proceso que esté listo puede usar los recursos que antes usaba el primer proceso. |
| **e) Idem para el cambio de estado de Bloqueado a Ejecutable** |
| Este cambio de estado en un proceso no afecta al resto, ya que es el planificador el que se encarga de controlar los estados de los procesos. Un proceso pasará a ejecutarse si hay recursos para ello y la CPU no está ocupada. Que un proceso pase de bloqueado a ejecutándose no libera recursos y por tanto el planificador no cambiará. --- En caso de que existiese un sistema de prioridades, sí podría ocurrir. Ya que si el planificador ve que un proceso prioritario esta preparado mientras que otro menos prioritario se está ejecutando. Entonces el SO bloquea al que se esta ejecutando y comienza la ejecución del prioritario. |

**10. En los primeros ordenadores, cada byte de datos leído o escrito, era manejado directamente por la CPU (es decir, no existía DMA - Acceso Directo a Memoria). ¿Qué implicaciones tenía esta organización para la multiprogramación?**

Sin DMA, se consumen muchos recursos de la CPU para realizar transferencias grandes de memoria. Esto hace que a la hora de realizar varios procesos a la vez se pueda repartir menos capacidad de procesamiento puesto que se gasta mucho en transferencias.

**11.¿Por qué no es el intérprete de órdenes (shell) parte del propio sistema operativo? ¿Qué ventajas aporta el no serlo?**

Porque no es necesario. No todos los SO necesitan una shell. Además que la shell no forme parte del SO y sea un proceso normal más implica que tendrá los permisos heredados del usuario que la haya ejecutado, aportando seguridad al sistema, ya que no cualquier usuario tienen permisos de root. Lo mismo para ejecutar órdenes en modo kernel, necesita llamar al SO.

Además haríamos un SO más pesado y complejo. También dificultaría las actualizaciones.

**12. Para cada una de las llamadas al sistema siguientes, especificar y explicar si su procesamiento por el sistema operativo implica un cambio de contexto: **

| **a) Crear un proceso. **                                    |
| ------------------------------------------------------------ |
| Si el proceso creado comienza a ejecutarse entonces sí. El mero hecho de crear un proceso no implicar cambiar de contexto. |
| **b) Abortar un proceso, es decir, terminarlo forzosamente. ** |
| Si se estaba ejecutando se produce un cambio de contexto. Si ya estaba bloqueado no. |
| **c) Suspender o bloquear un proceso. **                     |
| Sí. Produce un cambio de contexto puesto que cuando se suspenda/bloquea pasa a ejecutar otro proceso. |
| **d) Reanudar un proceso (inverso al caso anterior). **      |
| Sí. Puesto que ahora se continua la ejecución de un proceso anteriormente bloqueado. Hemos cambiado de un proceso a otro y por tanto de contexto. |
| **e) Modificar la prioridad de un proceso.**                 |
| Depende de la prioridad. Si la prioridad es alta y el proceso al que le hemos modificado la prioridad comienza a ejecutarse entonces sí se produce un cambio de contexto. |

**13. ¿Tiene sentido mantener ordenada por prioridades la cola de procesos bloqueados? Si lo tuviera ¿en qué casos sería útil hacerlo?**

Sí, ya que los procesos pueden estar bloqueados por módulos de E/S y estén esperando al mismo dispositivo. Por ejemplo, varios procesos intentan imprimir. Estos procesos están bloqueados porque están a la espera de la impresora y podría tener una prioridad. 

**14. ¿Por qué se utilizan potencias de dos para los tamaños de página, número de páginas en el espacio lógico de un proceso, y números de marcos de página?**

Para que el ordenador tenga menos problemas a acceder a ellos puesto que la memoria física se da en potencias de dos. De esta manera las direcciones lógicas tienen la misma dirección que la física. 

En general, para facilitar el direccionamiento.

**15. Sitúese en un sistema paginado, en donde la memoria real tiene un tamaño de 16 Mbytes, una dirección lógica ocupa 32 bits, de los cuales los 22 de la izquierda constituyen el número de página, y los 10 de la derecha el desplazamiento dentro de la página. Según lo anterior, **

**a) ¿Qué tamaño tiene cada página? **

Cada página tiene un tamaño de $2^{10}$ bits, lo podemos saber con el desplazamiento.

**b) ¿En cuántos marcos de página se divide la memoria física? **

​																			$\frac{2^{24}}{2^{10}} = 2^{14}$

Tenemos entonces $2^{14}$ marcos de página.

**c) ¿Qué tamaño deberá tener el campo Número de Marco de la Tabla de Páginas? **

$log_22^{14} = 14$ bits

**d) Además de dicho campo, suponga que la Tabla de Páginas tiene los siguientes campos con los siguientes valores: Protección: 1 bit (1= Sólo se permite leer; 0= Cualquier tipo de acceso). ¿Cuál es el tamaño de la Tabla de Páginas para un proceso cuyo espacio de memoria lógico es de 103K bytes?**

103 kB de memoria lógica.

$103 kB / 1 kB = 103$ páginas.

$103\:páginas · (14+1) = 1545$

El 14 es por el marco de página y el 1 por el bit de protección.

**16. Suponga que la tabla de páginas para el proceso actual se parece a la de la figura. Todos los números son decimales, la numeración comienza en todos los casos desde cero, y todas las direcciones de memoria son direcciones en bytes. El tamaño de página es de 1024 bytes.**

| Número de página virtual | Número de marco de página |
| :----------------------: | :-----------------------: |
|            0             |             4             |
|            1             |             7             |
|            2             |             1             |
|            3             |             2             |
|            4             |            10             |
|            5             |             0             |

**¿Qué direcciones físicas corresponderán con cada una de las siguientes direcciones lógicas del proceso?**

**a) 999**

**b) 2121**

**c) 5400**

**a)**

Tamaño de página = $2^{10}$ bytes.

Pasamos 999 a binario --> $999_{10} = 0011\:1110\:0111_{2}$

Los últimos 10 bits son de desplazamiento --> $11\:1110\:0111$

Así nos queda que el número de página es 00, cuyo marco es 4. Por tando la dirección física es:

<span style='color:orange'>`0100`</span><span style='color:green'>`11 1110 0111`</span> $\to$ 5095

**b)**

Pasamos 2121 a binario --> $2121_{10} = 1000\:0100\:1001_2$

Bits de desplazamiento --> $00\:0100\:1001$

Nos queda que el número de página es $10_2 = 2_{10}$ . El número de marco de página del 2 es 1. Por tanto la dirección física queda como:

<span style='color:orange'>`0001`</span><span style='color:green'>`00 0100 1001`</span> $\to$ 1097

**c)**

Pasamos 5400 a binario --> $5400_{10} = 0001\:0101\:0001\:1000_2$ 

Bits de desplazamiento --> $01\:0001\:1000$

Número de página --> $101_2 = 5_{10}$ cuyo número de marco de página es 0. La dirección física es:

<span style='color:orange'>`0000`</span><span style='color:green'>`01 0001 1000`</span> $\to$ 280



**17. ¿Qué tipo de fragmentación se produce en un sistema de gestión de memoria paginado? ¿Qué decisiones de diseño se pueden tomar para minimizar dicho problema, y cómo afectan estas decisiones al comportamiento del sistema?**

Hay dos tipos de fragmentación: externa e interna. 

* Interna: pérdida de espacio debido a que el tamaño del archivo/proceso es inferior al de la página.

* Externa: esto es cuando hay un hueco libre pero que no es suficiente para que el proceso entre, lo que obliga a usar una nueva página.

En el método de paginación de produce Fragmentación interna.

La forma de solventar en cierta medida el problema sería utilizar páginas y marcos más pequeños, luego mñas versátiles. Sin embargo, esto repercutaría deteriorando el procesador.



**19. Suponga que tenemos 3 procesos ejecutándose concurrentemente en un determinado instante. El sistema operativo utiliza un sistema de memoria con paginación. Se dispone de una memoria física de 131072 bytes (128K). Sabemos que nuestros procesos al ser ejecutados tienen los parámeros que se muestran en la tabla. **

| Proceso | Código | PIla  | Datos |
| :-----: | :----: | :---: | :---: |
|    A    | 20480  | 14288 | 10240 |
|    B    | 16384  | 8200  | 8192  |
|    C    | 18432  | 13288 | 9216  |

**Los datos indican el tamaño en bytes de cada uno de los segmentos que forman parte de la  imagen del proceso. Sabiendo que una página no puede contener partes de dos segmentos diferentes (pila, código o datos), hemos de determinar el tamaño de página que debería utilizar nuestro sistema y se barajan dos opciones: páginas de 4096 bytes (4K) o páginas de 512 bytes (1/2K). Se pide:**

**a) ¿Cuál sería la opción más apropiada, 4096 bytes o 512 bytes?. Justifica totalmente la respuesta mostrando** **todos los cálculos que has necesitado para llegar a dicha conclusión.** 

**b) ¿Cuál es el formato de cada entrada de la Tabla de Páginas con el tamaño de página elegido? Justifica el** **tamaño de los campos con direcciones. Puedes añadir los bits que consideres necesarios para el buen** **funcionamiento del sistema indicando para que van a ser utilizados.**

**c) ¿Cuántas Tablas de Páginas habrá en este sistema?¿Cuántas entradas hay en cada tabla de páginas (filas)?**

**a)**

<u>Opción de 4K.</u>

Calculamos cuántas páginas se necesitan para cada proceso

* Proceso A:  $ceil(\frac{20480}{4096}+\frac{14288}{4096}+\frac{10240}{4096}) = 12$ páginas
* Proceso B:  $ceil(\frac{16384}{4096}+\frac{8200}{4096}+\frac{8192}{4096}) = 9$ páginas
* Proceso C:  $ceil(\frac{18432}{4096}+\frac{13288}{4096}+\frac{9216}{4096}) = 12$ páginas

Por tanto necesitaremos 33 páginas * 4096 bytes = 135168 bytes. Por tanto, superamos la memoria disponible de 131072 bytes. Esta opción no la podemos usar.

<u>Opción de 512 bytes</u>

Calculamos cuántas páginas se necesitan para cada proceso

* Proceso A:  $ceil(\frac{20480}{512}+\frac{14288}{512}+\frac{10240}{512}) = 88$ páginas
* Proceso B:  $ceil(\frac{16384}{512}+\frac{8200}{512}+\frac{8192}{512}) = 65$ páginas
* Proceso C:  $ceil(\frac{18432}{512}+\frac{13288}{512}+\frac{9216}{512}) = 80$ páginas

Por tanto necesitaremos 233 páginas * 512 bytes = 119296 bytes. 

Finalmente, la única opción disponible es la de 512 bytes de tamaño de página.

**b)**

Tamaño de página $= 512 = 2^9 \to 9$ bits.

Número de página $=\frac{131072}{512} = 2^8 \to 8$ bits de número de página.

1 Bit de protección.

En total, hay 18 bits.

**c)**

Hay una tabla por cada proceso $\to$ 3 tablas.

Necesitamos una entrada por cada página. Esto es:

Proceso A $\to$ 88 entradas.

Proceso B $\to$ 65 entradas.

Proceso C $\to$ 80 entradas.

**20. En la gestión de memoria en un sistema paginado, ¿qué estructura/s de datos necesitará mantener el Sistema Operativo para administrar el espacio libre?**

El sistema operativo mantiene una tabala de páginas por cada proceso, que almacena la ubicación del marco por cada página del proceso (número de marco + modo de acceso autorizado).

**21**

**22**

**23**

