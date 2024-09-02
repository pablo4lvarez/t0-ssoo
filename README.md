# t0-ssoo

Tarea 0 SSOO y Redes 2024-2.

Este repositorio contiene la implementación de una shell personalizada en C, como parte de una tarea para la asignatura de Sistemas Operativos.

## Descripción

La shell, llamada `lrsh`, es capaz de ejecutar varios comandos personalizados que incluyen:

- `lrexec`: Ejecuta un comando específico.
- `hello`: Muestra un saludo por pantalla.
- `sum`: Calcula la suma de dos números.
- `is prime`: Determina si un número es primo.
- `lrlist`: Lista los archivos del directorio actual.
- `lrexit`: Cierra la shell.

## Estructura del Repositorio

El repositorio contiene los siguientes archivos:

- `lrsh.c`: Código fuente de la shell.
- `lrexec.c`: Implementación del comando `lrexec`.
- `hello.c`: Implementación del comando `hello`.
- `sum.c`: Implementación del comando `sum`.
- `is_prime.c`: Implementación del comando `is prime`.
- `lrlist.c`: Implementación del comando `lrlist`.
- `lrexit`: Implementación del comando `lrexit`.
- `Makefile`: Script de construcción para compilar todos los archivos.

## Requisitos

- **Compilador GCC**: Necesario para compilar los archivos de C.
- **Sistema Operativo Linux**: Este proyecto está diseñado para ejecutarse en entornos basados en Unix.

## Detalles

- El comando `lrlist` incluye a todos los procesos que han sido llamados desde inició la shell.
- En caso de que el comando `lrexec` falla por alguna razón, este se muestra en la lista de `lrlist`, con el exit code -1.
