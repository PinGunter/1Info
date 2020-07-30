>Salvador Romero Cortés y Jesús García León 

# Práctica FFT 13/11/2019

### Objetivo de la práctica

Aprender a usar el osciloscopio y estudiar un circuito RC en el dominio de la frecuencia a través de la medida de los cambios en la tensión de la señal de salida debidos a las variaciones de la frecuencia de la señal de entrada. Realizar el diagrama de Bode de la función de transferencia al tomar como salida el condensador del circuito.

 ### Fundamento teórico

Esta práctica se basa en los fundamentos teóricos de diagramas de bode, corriente alterna y circuitos RC. 

Como el condensador y la resistencia están en serie la impedancia equivalente es:

$$
Z_{eq} = Zr+ Zc = R + \frac{1}{j\omega C} = \frac{j\omega RC+1}{j\omega C} = \frac{1+j\omega RC}{j\omega C}
$$
De esta forma el fasor que representa a la corriente que circula por el circuito es:
$$
i(\omega) = \frac{v_i(\omega)}{Z_{eq}} = v_i(\omega)\frac{j\omega C}{1+j\omega RC}
$$
siendo $v_i(\omega)$  el fasor que representa la tensión de la fuente de entrada. Por tanto, el fasor que representa la caída de tensión en el condensador es:
$$
i(\omega) = i(\omega)Z_c = \frac{v_i(\omega)}{1+j\omega RC}
$$

Y la función de transferencia del circuito es
$$
T(\omega)  = \frac{v_C(\omega)}{v_i(\omega)} = \frac{1}{1+j\omega RC}
$$

### Material de prácticas

En la práctica usaremos dos instrumentos principales.

* Osciloscopio 54622A de Agilent

* Generador de Señales Agilent 33220A

El osciloscopio es un instrumento análogo al multímetro o polímetro. Es decir, sirve para medir voltajes entre los polos de sus terminales llamados sondas. Podemos realizar operaciones sobre las ondas, mostrar 1 o 2 al mismo tiempo, ajustar la escala además de tomar medidas.

El generador de señales lo usaremos para generar una señal con las características deseadas. En el caso de la práctica, una señal seno de Voltaje Pico-Pico de 10V. La frecuencia la cambiaremos para el experimento.

### Desarrollo y resultados

#### Desarrollo 

La práctica consiste en medir los voltajes de entrada y salida del siguiente circuito RC para luego calcular la función de trasferencia.

![Circuito RC](C:\Users\pingu\OneDrive\Documentos\Personal\Universidad\Primero\Cuatrimestre 1\FFT\Practica 3\Anotación 2019-11-18 194231.png)

Para ello utilizaremos el material mencionado previamente. 

Seleccionaremos frecuencias de distintos ordenes de magnitud, desde 100Hz hasta $10^6$ Hz. 

#### Resultados

|         Frecuencia Teórica          |       Frecuencia Experimental       |        $\omega$ experimental         |               V~opp~                |               V~ipp~                | $H(\omega) = \frac{V_{opp}}{V_{ipp}}$      | $20log(H(\omega))$                          |
| :---------------------------------: | :---------------------------------: | :----------------------------------: | :---------------------------------: | :---------------------------------: | ------------------------------------------ | ------------------------------------------- |
|                 100                 |                 100                 |                 628                  |                10.2                 |                10.3                 | 0,990291262                                | -0,084741059                                |
|                 200                 |                 200                 |                 1256                 |                10.2                 |                10.3                 | 0,990291262                                | -0,084741059                                |
|                 300                 |                 300                 |                 1884                 |                10.2                 |                10.3                 | 0,990291262                                | -0,084741059                                |
|                 500                 |                 500                 |                 3140                 |                10.2                 |                10.3                 | 0,990291262                                | -0,084741059                                |
|                 800                 |                 800                 |                 5024                 |                10.2                 |                10.3                 | 0,990291262                                | -0,084741059                                |
|                1000                 |                1000                 |                 6280                 |                10.2                 |                10.3                 | 0,990291262                                | -0,084741059                                |
|                2000                 |                2000                 |                12560                 |                 10                  |                10.3                 | 0,970873786                                | -0,256744494                                |
|                3000                 |                3000                 |                18840                 |                 9.4                 |                10.3                 | 0,912621359                                | -0,794187422                                |
|                5000                 |                5000                 |                31400                 |                 8.3                 |                10.3                 | 0,805825243                                | -1,875182647                                |
| <span style="color:red">6400</span> | <span style="color:red">6400</span> | <span style="color:red">40192</span> | <span style="color:red">7.25</span> | <span style="color:red">10.3</span> | <span style="color:red">0,703883495</span> | <span style="color:red">-3,049984363</span> |
|                8000                 |                8000                 |                50240                 |                 6.7                 |                10.3                 | 0,650485437                                | -3,73524844                                 |
|                10000                |                10000                |                62800                 |                 5.8                 |                10.3                 | 0,563106796                                | -4,988184623                                |
|                20000                |                20000                |                125600                |                 3.4                 |                10.3                 | 0,330097087                                | -9,627166153                                |
|                30000                |                30000                |                188400                |                 2.5                 |                10.3                 | 0,242718447                                | -12,29794432                                |
|                50000                |                50000                |                314000                |                 1.7                 |                10.3                 | 0,165048544                                | -15,64776607                                |
|                80000                |                80000                |                502400                |                0.88                 |                10.3                 | 0,085436893                                | -21,36709105                                |
|               100000                |               100000                |                628000                |                0.72                 |                10.3                 | 0,069902913                                | -23,11009457                                |
|               200000                |               200000                |               1256000                |                0.34                 |                10.3                 | 0,033009709                                | -29,62716615                                |
|               300000                |               300000                |               1884000                |                0.25                 |                10.3                 | 0,024271845                                | -32,29794432                                |
|               500000                |               500000                |               3140000                |                0.16                 |                10.3                 | 0,015533981                                | -36,17434484                                |
|               800000                |               800000                |               5024000                |                0.092                |                10.3                 | 0,008932039                                | -40,98098795                                |
|               1000000               |               1000000               |                628000                |                0.075                |                10.3                 | 0,007281553                                | -42,75551923                                |

El color <span style= "color:red">rojo </span> indica la frecuencia de corte.

<strong>Representación gráfica de los datos.</strong>

![diagrama_bode](C:\Users\pingu\OneDrive\Documentos\Personal\Universidad\Primero\Cuatrimestre 1\FFT\Practica 3\diagrama.png)

