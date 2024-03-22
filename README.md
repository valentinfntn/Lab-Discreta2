# Lab-Discreta2

OBJETIVOS:

Los objetivos en este proyecto son:
1. Implementar un tema enseñado en clase en un lenguaje, observando las dificultades de pasar de la teoria a un
programa concreto.
2. Practicar programar funciones adhiriendose a las especificaciones de las mismas.
3. Practica de testeo de programas.
El tema concreto que usaremos este a ̃no es hacer un programa que coloree un grafo tratando de obtener un
coloreo con la menor cantidad de colores posibles, o “cerca”.
La idea NO ES presentar un programa  ́unico completo que haga esto, sino programar funciones auxiliares que
luego se pueden ensamblar en uno o mas mains que las use, de acuerdo a distintas estrategias.
El proyecto se dividira en varias etapas. Este primer documento da las especificaciones de las funciones de la
primera etapa. En esta primera etapa, simplemente especificamos funciones que permitan leer los datos del grafo
que vamos a colorear, guardarlos en alguna estructura adecuada, y otras funciones que nos permitan acceder a esos
datos, como el n ́umero de vertices y lados, los grados de cada vertice, y cuales son los vecinos de un v ́ertice.
Las etapas posteriores usaran estas funciones para hacer lo que deben hacer.
Si en las etapas posteriores uds programan sin hacer uso de estas funciones, el proyecto queda desaprobado.
Para evitar “acarreo” de errores de la primera etapa a las otras, las otras etapas las evaluaremos usando nuestras
propias funciones de la 1ra etapa.
El lenguaje es C. (C99, i.e., pueden usar comentarios // u otras cosas de C99).
Es crucial que programen las funciones de acuerdo con las especificaciones, este es uno de los objetivos de este
proyecto, y sera dificil o directamente imposible corregir las otras etapas si usan funciones que no satisfagan las
especificaciones.


RESTRICCIONES GENERALES:

1. No se puede incluir NINGUNA libreria externa que no sea una de las basicas de C. (eg, stdlib.h, stdio.h,
strings.h, stdbool.h, assert.h etc, si, pero otras no. Especificamente, glibc NO).
2. El codigo debe ser razonablemente portable, aunque no es probable que testemos sobre Apple, y en general
testearemos con Linux, quizas podamos testearlo desde Windows.
3. No pueden usar archivos llamados aux.c o aux.h
4. No pueden tener archivos tales que la unica diferencia en su nombre sea diferencia en la capitalizacion.
5. No pueden usar getline.
6. El uso de macros esta permitido pero como siempre, sean cuidadosos si los usan.
7. Pueden consultar con otros grupos, pero no pueden tener grandes fragmentos de codigo iguales, o con cambios
meramente cosm ́eticos en el codigo de otro grupo. Consultar por ideas es aceptable, copiar codigo en bloque
no.
8. Si tienen acceso a codigos de años anteriores y quieren usar ideas o fragmentos del codigo, ok, pero este
año las especificaciones son distintas. Si entregan codigo que es obviamente un codigo de a ̃nos anteriores sin
haber sido adaptado a las exigencias de este a ̃no les descontaremos puntos o directamente ser ́an desaprobados,
dependiendo que tan grande sea la caradurez.
9. Si saben como usar ChatGPT y lo usan, est ́a bien, pero deberian ser extra cuidadosos con el testeo.

COMPILACION:

Compilaremos (con mains nuestros) usando gcc, -Wall, -Wextra, -O3, -std=c99 . Tambien haremos -I al directorio
donde pondremos los .h
Esas flags seran usadas para testear la velocidad, pero para testear grafos chicos podemos agregar otras flags.
Por ejemplo, podemos usar -DNDEBUG si vemos que estan mal usando asserts.
Tambien compilaremos, para testear grafos chicos, con flags que nos permitan ver si hay buffer overflows,
shadow variables o comportamientos indefinidos, en particular con -fsanitize=address,undefined. Su programa
DEBE compilar y correr correctamente con esa flag aunque para grafos grandes lo correremos con un ejecutable
compilado sin esa flag, dado que esa flag provoca una gran demora en la ejecucion.