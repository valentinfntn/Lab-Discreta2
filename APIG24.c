#include "APIG24.h"
#include "EstructuraGrafo24.h"
#include <limits.h>

Grafo ConstruirGrafo()
{
    u32 numero_de_vertices , numero_de_lados;
    int error_code = scanf("p edge %u %u", &numero_de_vertices , &numero_de_lados);
    if(error_code != 2) exit(EXIT_FAILURE);
    Grafo g = malloc(sizeof(struct _grafo));
    g->n = numero_de_vertices;
    g->m = numero_de_lados;
    g->delta = 0u;
    g->vertices = malloc((g->n)*sizeof(struct _data));
    g->vecinos = malloc((g->n)*sizeof(u32*));
    // ciclo para inicilizar el struct data
    // y tambien aprovecho el ciclo para crear la matriz N x N
    for (u32 i = 0; i < g->n; ++i)
    {
        g->vertices[i].color = 0;
        g->vertices[i].grado = 0;
        g->vecinos[i] = malloc((g->n)*sizeof(u32));
    }
    for (u32 i = 0u; i < g->m; ++i)
    {
        u32 vertice_x , vertice_y; // juntos forman el lado xy
        int error_code = scanf("\ne %u %u", &vertice_x , &vertice_y);
        if(error_code != 2) exit(EXIT_FAILURE);
        // llenado de la matriz de vecinos en un mismo ciclo para ahorrar costo
        g->vecinos[vertice_x][(g->vertices[vertice_x].grado)] = vertice_y; // con vertice_x un numero entre 0 y n por lo tanto no se sale de la matriz
        g->vecinos[vertice_y][(g->vertices[vertice_y].grado)] = vertice_x; // con vertice_y un numero entre 0 y n por lo tanto no se sale de la matriz
        g->vertices[vertice_x].grado += 1;
        g->vertices[vertice_y].grado += 1;
    }
    // calculo delta
    for (u32 i = 0u; i < g->n; ++i)
    {
        if(g->delta < g->vertices[i].grado){
            g->delta = g->vertices[i].grado;
        }
    }
    
    return g;
}

void DestruirGrafo(Grafo g)
{
    for (u32 i = 0; i < g->n; ++i)
    {
        free(g->vecinos[i]);
    }
    free(g->vecinos);
    free(g->vertices);
    free(g);
    g = NULL;
}

u32 NumeroDeVertices(Grafo g)
{
    return g->n;
}

u32 NumeroDeLados(Grafo g)
{
    return g->m;
}

u32 Delta(Grafo g)
{
    return g->delta;
}

u32 Grado(u32 i,Grafo g)
{
    if(i < g->n)
    {
        return g->vertices[i].grado;
    }
    else
    {
        return 0;
    }
}

color Color(u32 i,Grafo g)
{
    if(i < g->n)
    {
        return g->vertices[i].color;
    }
    else
    {
        return INT_MAX;
    }
}

u32 Vecino(u32 j,u32 i,Grafo g)
{
    if(i < g->n && j < g->vertices[i].grado)
    {
        return g->vecinos[i][j];
    }
    else
    {
        return INT_MAX;
    }
}

void AsignarColor(color x,u32 i,Grafo  g)
{
    if(i<g->n)
    {
        g->vertices[i].color = x;
    }
}

void ExtraerColores(Grafo g,color* c)
{
    for (u32 i = 0; i < g->n; ++i)
    {
        c[i] = g->vertices[i].color;
    }
}

void ImportarColores(color* c,Grafo  g)
{
    for (u32 i = 0; i < g->n; ++i)
    {
        g->vertices[i].color = c[i];
    }
    
}
