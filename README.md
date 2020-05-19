# TP 2 - Recolcetores y productores | Taller 7542

## Trabajo práctico 2 - Simulación de recolectores y productores usando Threads 

### Taller de programación 75.42 - FIUBA

- Alumno: Agustín Emanuel More
- Padrón: 102914
- Repositorio github: https://github.com/moreover22/tp2-taller

Contenidos
---
- [Introducción](#Introducción)
- [Conclusión](#Conclusión)
- [Referencia](#Referencia)

Introducción
---

El trabajo consiste en el desarrollo de un programa de simulación de un sistema de productores y recolectores, con la salvedad, que se trata de una ejecución en tiempo real, es decir, todos los actores estarán actuando a a la vez (salvo limitaciones de hardware, es a lo que se apunta). Esto último se logragará mediante la programación concurrente utilizando `threads` en C++.

Recolectores y productores
---

El sistema cuenta con dos tipos de actores: los _Recolectores_ (`Gatherer`) y los _Productores_ (`Producer`). Donde los primeros serán los encargados de recolectar de un mapa algún tipo de material (_Madera_, _Trigo_, _Hierro_ o _Carbón_), estos recursos serán daspachados mediante una cola bloqueante (`BloquingQueue`) y depositarán lo recolectado en un inventario (`Inventory`) compartido. A su vez, los productores, tomarán los recursos del inventario y los transformarán en puntos de beneficio que serán depositados en un contador (`ProfitPointsCounter`), donde este también es compartido.

El modelo, toma en consiración que tanto los recolectores como los productores, deberán trabajar concurrentemente, es decir, un trabajador no debe esperar a que termine otro trabajador para realizar su tarea (salvo que este último esté usando algún recurso compartido). Para lograr esto, se utilizan hilos (`Thread`) de la siguente forma:

<p align="center">
    <img src="images/dc-thread-gatherer-producer.png">
</p>

E interactuarán con los recursas compartidos:
<p align="center">
    <img src="images/dc-shared-resources.png">
</p>

Para tener en consideración en los siguientes puntos, se puede observar que tanto los productores como recolectores (más de uno, eventualmente), estarán accediendo al inventario. Además, el orden de ejeción establecerá que el inventario comienza vacio, con lo cual, los productores, deberán esperar a que el inventario contenga algún recurso antes de poder trabajar.

Archivos
---

La configuración de cantidad de trabajadores (actores), y la disposición del mapa, son obtenidas desde dos archivos. El primero, el de los trabajadores, con el siguiente formato:

```
<tipo de trabajador>=<cantidad>
```

Y el del mapa será una matriz, donde en cada posición se representa el recurso, mediante la inicial del mismo, que contiene el mapa en esa posición, por ejemplo:

```
MMHHMMHCCC
HHHMMMTTTM
```

Donde: `M` es para madera, `H` es para hierro, `C` es para carbón y `T` es para trigo.

Al ejecutar el programa, se pasará por parámetros la ruta para cada uno de estos archivos:

```
./tp <path a conf de trabajadores> <path archivo de mapa>
```

Cada archivo, tendrá una entidad asociada, encargada de parsear la información. Para el archivo de mapa, se cuenta con `MapParser` y para el de trabajadores está `WorkerParser`.

El `MapParser` adicionalmente, a medida que recorre el mapa, irá encolando los recursos en las respectivas colas bloqueantes. 

Para simplificar el uso de múltiples colas, trabajadores y accesos a inventario, se implementan dos clases contenedoras `GathererHandler` y `ProducerHandler`. Esto permite encapsular el uso de recursos asociados a cada trabajador.


<!-- 

Modelo de threading

Consideraciones de cv and mutex

Conclusion
 -->

