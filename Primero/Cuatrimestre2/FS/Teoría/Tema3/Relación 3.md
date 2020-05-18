### Relación 3 

---

**4. El análisis léxico es una etapa de la compilación cuyo objetivo es:**

b) Descomponer el programa fuente en sus componentes léxicos (tokens).

**6. Para el siguiente código que aparece a la izquierda en lenguaje C++ (fichero `test.cpp`), indique el nombre de la fase en la que el compilador produce el mensaje de error que aparece a la derecha y explique la naturaleza del mismo:**

```c++
01 int main (void)
02 {
03     int i;
04     char * j;
05    
06    j = i;
07    
08    if (i == 0)
09        i += ;
10    
11    ¬;
12    
13    return 0;
14}
```

**a) test.cpp:9: error: expected primary-expression before ‘;’ token**

En la fase de análisis sintáctico. Porque según la gramática del lenguaje, después de un operador de asignación debe haber un término.

**b) test.cpp:6: error: invalid conversion from ‘int’ to ‘char*’**

En el análisis semántico, puesto que el codigo intenta asignar dos tipos distintos.

**c) test.cpp:11: error: stray ‘\302’ in program**

En el análisis léxico. Porque el carácter ¬ no es parte del alfabeto.



**8.Muestre un ejemplo a partir una sentencia de en lenguaje C++ en la que un error léxico origine un error sintáctico y semántico derivados y otro error léxico que no los derive.**

Error léxico que derive en error sintáctica y semántico:

```c++
int ejem¬plo;
ejemplo ++;
char otro;
ejemplo = otro;
```

El error léxico de la primera línea genera un error sintáctico en la linea 2 puesto y otro semántico en la linea 4.

Un error léxico que no desencadene errores

```c++
fi (valor == 3)
    cout << "Hello world";
```

Escribir mal if genera un error léxico pero nada más.



**16. ¿Todo error sintáctico origina un error semántico? En caso contrario, demuéstrelo usando algún contraejemplo. **

No, por ejemplo si nos dejamos un punto y coma se produce un error sintáctico pero no uno semántico.

```c++
int valor = 3
```

