#include "APIG24.h"

int main(){
    Grafo g = ConstruirGrafo();
    printf("%d: Numero de vertices\n" ,NumeroDeVertices(g));
    printf("%d: Numero de lados\n",NumeroDeLados(g));
    printf("%d: Delta\n",Delta(g));
    DestruirGrafo(g);
    return 0;
}

