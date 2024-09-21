# TP0 - Organizacion de Datos

### Compilacion

Se ofrece un Makefile para compilar el programa

`make`

El programa se encontrara en **bin/autcel**

### Ejecucion

```
Uso:
    autcel -h
    autcel -V
    autcel R N inputfile [-o outputprefix]
Opciones:
    -h, --help Imprime este mensaje.
    -V, --version Da la versión del programa.
    -o Prefijo de los archivos de salida.
Ejemplos:
    autcel 30 80 inicial -o evolucion
    Calcula la evolución del autómata "Regla 30",
    en un mundo unidimensional de 80 celdas, por 80 iteraciones.
    El archivo de salida se llamará evolucion.pbm.
    Si no se da un prefijo para los archivos de salida,
    el prefijo será el nombre del archivo de entrada.
```