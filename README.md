ESTRUCTURAS DE DATOS LINEALES

PRÁCTICA 4

ALGORITMOS DE ORDENAMIENTO

Brandon Gabriel Aguirre Franco/ 2203025381

UAM-C


OBJETIVO:
Verificar de forma experimental el tiempo de ejecución de algunos algoritmos de ordenamiento.

RESUMEN DE RESULTADOS.
De acuerdo a las instrcciones de la p´ractica el programa se encarga de ir guardando los tiempos de cada iteración registrandolos en un archivo de texto como se muestra a continuación.
algoritmo 1 = merge_sort, algoritmo 2 = quick_sort, algoritmo 3 = bubble_sort, algoritmo 4 = insertion_sort, algoritmo 5 = select_sort
Tiempo de ejecución por cada repetición
Repetición 1:
	Algoritmo 1: 5.352e-06 segundos
	Algoritmo 2: 4.37e-07 segundos
	Algoritmo 3: 4.1e-07 segundos
	Algoritmo 4: 1.97e-07 segundos
	Algoritmo 5: 3.18e-07 segundos

Repetición 2:
	Algoritmo 1: 9.75e-07 segundos
	Algoritmo 2: 2.54e-07 segundos
	Algoritmo 3: 3.63e-07 segundos
	Algoritmo 4: 2.69e-07 segundos
	Algoritmo 5: 2.87e-07 segundos

Repetición 3:
	Algoritmo 1: 1.283e-06 segundos
	Algoritmo 2: 3.43e-07 segundos
	Algoritmo 3: 3.34e-07 segundos
	Algoritmo 4: 2.02e-07 segundos
	Algoritmo 5: 3.18e-07 segundos

..............."LAS PRIMERAS 3 REPETICIONES"

 A su vez todos estos tiempos registrados quedaron almacenados en un arreglo para posteriormente calcular el tiempo promedio de ejecución de cada algoritmo y la desviación estándar. 
Una vez calculadas estas dos operaciones se realizó la siguiente tabla junto con su gráfica empezando desde  5 repeticiones hasta 500000 “debido a la gran demora en la ejecución del programa sobre todo en los algoritmos iterativos”.



![image](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-B7AGUI/assets/151887010/83db9ba8-41ea-43a5-b703-4910d9a3504a)


Para empezar con el promedio obtenemos una medida que ayude a entender el rendimiento de cada algoritmo para cada arreglo, con la desviación estándar veremos una variación en los tiempos de ejecución promedio de cada algoritmo con lo que si obtenemos una desviación estándar pequeña indicara que los tiempos de ejecución de cada algoritmo están cercanos al promedio, mientras que una desviación estándar grande nos indica que hay un gran margen de variabilidad.

Los algoritmos iterativos  son de orden (n^2) representando el peor caso de tiempo de ejecución ya que si el tamaño del arreglo ordenar aumenta el tiempo de ejecución crece cuadráticamente con este tamaño viéndolo al realizar la práctica Bubblesort es el algoritmo menos eficiente y con el que se produce la mayor demora de todos al intentar el arreglo con arreglos de 5*10^2 el tiempo estimado al menos de una repetición fue de 10 minutos, en otra incluso fueron cerca de 20 por lo que esto dispara el valor en la desviación estándar y comparado con los otros métodos iterativos este resultó ser el que peor tiempos de ejecución maneja. 

Por el contrario con los métodos recursivos Merge-Sort y Q-Sort obtenemos tiempos muchos menores resultando ser los más óptimos cuando se trata de arreglos con tamaños realmente grandes, debido a que crece de manera logarítmica con respecto al tamaño de la entrada, lo cual es más eficiente que una complejidad cuadrática.
En la gráfica incluso ni se alcanza a apreciar la fluctuación en los tiempos entre merge-sort y quick-sort ya que son algoritmos muy rápidos y el que una sea mejor que la otra en cuanto al tiempo dependerá mucho del arreglo a ordenar sin embargo merge tiende a ser más estable y rápido en cuánto a los tiempos comparado con Q-sort incluso en el peor caso. Una prueba de ésto fue al correr el programa para un arreglo de tamaño de 10,000,000, dándo la siguiente salida 
Iniciando ordenamiento con MERGE SORT...        Ordenado.       Tiempo: 21.899s
Iniciando ordenamiento con QUICKSORT...         Ordenado.       Tiempo: 147.54s . 
Algunas otros datos quedaron registrados en la siguiente tabla y gráfica.

![image](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-B7AGUI/assets/151887010/2f083371-18d9-4a58-b182-433149283e07)
