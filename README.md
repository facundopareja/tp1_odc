# TP0 - Organizacion de Datos

### Compilacion local

Se ofrece un Makefile para compilar el programa

`make`

El programa se encontrara en **bin/autcel** junto con el archivo inicial necesario para obtener las imagenes pedidas
en el enunciado.

### Compilacion QEMU

Con la VM levantada y corriendo ejecutar

`ssh -R 5555:localhost:22 host@iphost`

Situado en tp1_odc/src en la maquina host

`scp -P 5555 -r src root@localhost:/tmp`

Abandonar la maquina host en la VM y ejecutar

```
apt-get install make
cd tmp/src
make
cd bin
```

Y el programa ya esta listo para ejecutar.


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