# Tarea *1*. *Complejidad Computacional*

---

##### Integrantes:
1. *Luis Daniel Roa González* - *A01021960* - *Campus Santa Fe*
2. *Katia Yareth Bellido López* - *A01023638* - *Campus Santa Fe*
3. *Constanza Gómez Sánchez* - *A01026717* - *Campus Santa Fe*
4. *Christopher Luis Miranda Vanegas* - *A01022676* - *Campus Santa Fe*
5. *Miguel Monterrubio Bandera* - *A01022153* - *Campus Santa Fe*

---
## 1. Aspectos generales

Las orientaciones de la tarea se encuentran disponibles en la plataforma **Canvas**.

Este documento es una guía sobre qué información debe entregar como parte de la tarea, qué requerimientos técnicos debe cumplir y la estructura que debe seguir para organizar su entrega.


### 1.1 Requerimientos técnicos

A continuación se mencionan los requerimientos técnicos mínimos de la tarea, favor de tenerlos presente para que cumpla con todos.

* El código debe desarrollarse en C++, cumpliendo con el último estándar [C++17](https://isocpp.org/std/the-standard).
* Toda la programación debe realizarse utilizando Programación Genérica.
* Deben utilizarse las [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md).
* Todo el código debe estar correctamente documentado, siguiendo los lineamientos que aparecen en [Documenting C++ Code](https://developer.lsst.io/cpp/api-docs.html).
* Todo el código de la tarea debe alojarse en este repositorio de GitHub.
* Debe configurar su repositorio para que utilice el sistema de Integración Continua [Travis CI](https://travis-ci.org/).

### 1.2 Estructura del repositorio

El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz del repositorio
    - README.md			# Archivo con la información general de la actividad (este archivo)
    - sources  			# Códigos fuente con la solución
    - examples			# Archivos de ejemplo que pueden utilizarse para verificar que la solución funciona.
```

## 2. Solución

Para mejorar la manera en la que construímos el código y sus funciones principales, decidimos implementar el uso de headers (__.h__) y tener las funciones que se llevarían a cabo en otros documentos de _C++_ (__.cpp__).
Para que nuestro programa funcionara de manera correcta y fuera mas flexible con los códigos introducidos, utilizamos programación genérica para que no hubiera errores.

Las funciones que consisten en el análisis del documento, ingresar las líneas individuales del código ya separadas, obtener la cantidad de operaciones elementales y el cálculo de la cuota asintótica, se están llevando a cabo en los siguientes documentos:
* [Tarea1.cpp](sources/Tarea1.cpp)
* [simplificacion.cpp](sources/simplificacion.cpp)
* [oeAnalyzer.cpp](sources/oeAnalyzer.cpp)
* [printers.cpp](sources/printers.cpp)

Para que funcione todo en conjunto, cada método esta mandando a llamar a una función correspondiente que se encuentra en el header correspondiente. Estos, llaman a los métodos dentro de sus __.cpp__ respectivo. Los headers utilizados son:
* [oeAnalyzer.h](sources/oeAnalyzer.h)
* [printers.h](sources/printers.h)
* [simplificacion.h](sources/simplificacion.h)

Además de los documentos _.cpp_, tenemos un  corren script de Python 3 que se encarga de resolver los polinomios obtenidos por los scripts de C++. El script que usamos puede ser visto en:
* [simply.py](sources/simply.py)

El código se encuentra documentado con la finalidad que cualquier persona que lo este leyendo, entienda la manera en la que los métodos están construidos. La documentación de este mismo fue hecho de acuerdo a los parámetros establecidos por el estándar de **C++17**.


### 2.1 Pasos a seguir para utilizar la aplicación

#### Requisitos:

* Contar con acceso a internet
* Contar con una terminal
	* La terminal debe tener gcc instalado
	* La terminal debe tener git instalado
	* La terminal debe poder clonar un repositorio de git (cuenta con acceso a la red)

#### Para clonar el repositorio
1. Crear una carpeta en la que se vaya a clonar el repositorio
2. Mediante la terminal, navegar a dicha carpeta
3. Correr el comando `git clone https://github.com/tec-csf/tc2017-t1-primavera-2020-equipo-1-2.git`

#### Para correr el programa
1. Mediante la terminal, navegar a la carpeta sources
2. Correr el comando: `g++ -o tarea1 Tarea1.cpp printers.cpp oeAnalyzer.cpp simplificacion.cpp -std=c++17`
3. Correr el comando: `./tarea1 -i *ruta del archivo a analizar*`
## 3. Referencias
>http://www.cplusplus.com/reference/

>https://es.cppreference.com/w/cpp/container/vector

>https://es.cppreference.com/w/cpp/container/queue

>https://docs.python.org/2/extending/extending.html

>https://scipy-lectures.org/packages/sympy.html

