#include "APIG24.h"

Grafo ConstruirGrafo(){
    u32 numero_de_vertices , numero_de_lados;
    scanf("p edge %u %u", &numero_de_vertices , &numero_de_lados);
    Grafo g = malloc(sizeof(struct _grafo));
    g->n = numero_de_vertices;
    g->m = numero_de_lados;
    g->vertices = malloc((g->n)*sizeof(struct _data));
    g->vecinos = malloc((g->n)*sizeof(u32));
    // ciclo para inicilizar el struct data
    // y tambien aprovecho el ciclo para crear la matriz N x N
    for (u32 i = 0; i < g->n; i+=1)
    {
        g->vertices[i * (sizeof(struct _data))].color = 0;
        g->vertices[i * (sizeof(struct _data))].grado = 0;
        g->vecinos[i] = malloc((g->n)*sizeof(u32));
    }
    
    while(1)
    {
        u32 vertice_x , vertice_y; // juntos forman el lado xy
        int is_eof = scanf("e %u %u", &vertice_x , &vertice_y);
        if(is_eof == EOF) break;
        // llenado de la matriz de vecinos en un mismo ciclo para ahorrar costo
        g->vecinos[vertice_x][(g->vertices[vertice_x].grado)] = vertice_y; // con vertice_x un numero entre 0 y n por lo tanto no se sale de la matriz
        g->vecinos[vertice_y][(g->vertices[vertice_y].grado)] = vertice_x; // con vertice_y un numero entre 0 y n por lo tanto no se sale de la matriz
        g->vertices[vertice_x].grado += 1;
        g->vertices[vertice_y].grado += 1;    
    }
}