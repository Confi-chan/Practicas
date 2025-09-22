
Licenciatura en Ingeniería de Software
UACM San Lorenzo Tezonco
introducción a la ingeniería en Software

Practica 1


Ariel Sofia Lopez Amaya
Matricula: 21-003-1193






Introducción
En esta práctica se desarrolla un programa en C que hace uso de arreglos bidimensionales y funciones. El objetivo principal es reforzar el manejo de matrices, la generación de números aleatorios y el uso de funciones que realicen operaciones sobre los datos almacenados.
Se busca mostrar el arreglo generado, obtener estadísticas como suma de elementos, cantidad de números pares e impares, cantidad de elementos divisibles entre 7 y calcular la matriz transpuesta.


Desarrollo
Análisis del Problema
Se requiere un arreglo bidimensional cuadrado de tamaño máximo 10 x 10, el cual será llenado con valores aleatorios entre 1 y 100. Posteriormente, se deben aplicar operaciones específicas:
1.	Mostrar el arreglo original.
2.	Calcular la suma de todos los elementos.
3.	Determinar la cantidad de números pares e impares.
4.	Determinar la cantidad de elementos divisibles entre 7.
5.	Obtener la transpuesta del arreglo y mostrarla.
Solución Propuesta
La solución se implementa en lenguaje C.
•	Se utilizará la función rand () para generar números aleatorios.
•	El arreglo se llenará con una función específica.
•	Cada operación (suma, conteo, transpuesta) será implementada en funciones separadas, para fomentar el modularidad.
•	El programa mostrará tanto el arreglo original como la transpuesta de manera tabular.




Tiempo estimado vs. real
•	Estimado: 4 días (1 día de análisis y diseño, 2 días de programación, 1 día de pruebas).
•	Real: 2 días (1/2 día de análisis, 1 día de programación, ½ día de pruebas).
Defectos encontrados y correcciones
1.	Error: al generar números aleatorios, inicialmente se usó rand () % 100, lo que incluía el 0.
o	Corrección: se cambió a rand () % 100 + 1 para restringir de 1 a 100.
2.	Error: el programa no validaba si el usuario ingresaba un tamaño inválido (mayor a 10).
o	Corrección: se añadió la validación en main.
3.	Error: impresión desalineada de la matriz.
o	Corrección: se usó printf("%3d ", valor); para alinear columnas.




Conclusiones
La práctica permitió reforzar conceptos fundamentales como el manejo de arreglos bidimensionales, modularidad en la programación mediante funciones y el uso de operaciones básicas de conteo y suma. Además, se aplicaron conocimientos sobre transposición de matrices. El uso de GitHub permitió desarrollar habilidades en control de versiones, facilitando la gestión y resguardo del código.
Se logró cumplir con los objetivos planteados y se sentaron bases sólidas para prácticas más complejas en el futuro.


