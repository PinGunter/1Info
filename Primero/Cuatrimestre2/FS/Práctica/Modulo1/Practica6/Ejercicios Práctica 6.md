#### Ejercicios Práctica 6

###### Salvador Romero Cortés

---

**1.- Usa uno de los guiones que tienes y ejecútalo en background.**

Usamos el caracter `&` tras el guion para ejecutarlo en background.

```bash
nombreguion &
```

**2. Indica el número de proceso asignado.**

Cuando ejecutamos la orden anterior, bash nos avisa del número de proceso que se le asigna. Por ejemplo:

```bash
$ bash prueba &
[1] 6975  #aqui tenemos el numero de proceso y el id
```

De todas formas podríamos ejecutar la orden `jobs`

```bash
jobs
[1]+  Detenido                bash prueba
```

Si quisieramos solo el id podríamos utilizar la orden `top` o la orden `ps`.

**3. ¿Cómo matarías a dicho proceso antes de finalizar? **

De dos maneras. O bien, usando la orden `disown` , o usando la orden `kill`.

* Con `disown`

  ```bash
  disown %1
  ```

* Con `kill`

	```bash
	kill 6975
	```

**4. Muestra la información más completa de todos los procesos que se están ejecutando en el sistema (no solo los tuyos)**

Otra vez, podemos usar varias órdenes. 

* Usando la orden `ps`

  ```bash
  ps -el
  ```

  Donde `-el` son parámetros para que muestre todos los procesos y en formato largo.

* Usando la orden `top`

  ```bash
  top
  ```
