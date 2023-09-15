/*Algoritmo de Dijkstra para encontrar el camino más corto de
nodo inicial*/

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

//Numero de vertices en el grafo
#define V 9

//Funcion para encontrar el vertice minimo de destancia
int minDistance(int dist[], bool sptSet[]){
	//inicializamos el valor
	int min = INT_MAX, min_index;
	int v;
	
	for(v = 0; v < V; v++)
		if(sptSet[v] == false && dist[v] <= min)
		min = dist[v], min_index = v;
	
	return min_index;
}

//Imprimir resultado
void printResult(int dist[]){
	int i;
	printf("Vertice \t\t Distancia desde el origen\n");
	for (i = 0; i < V; i++)
		printf("%d \t\t\t\t %d\n",  i, dist[i]);
	
}

/*Funcion del algoritmo para encontrar el camino mas corto*/

void dijkstra (int graph[V][V], int src){
	int i,count,v;
	
	int dist[V];
	//el arreglo de salida, dist[i] contendra la menor distancia de src a i

	bool sptSet[V];
	/*sptSet[i] será verdadero si el vértice i está incluido en el árbol 
	del camino más corto o la distancia más corta de src a i está finalizada*/
	
	//inicializamos las distancias como infinitas y spt como falso
	for (i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;
		
		//la distancia del nodo inicial, su distancia siempre sera 0
		dist[src] = 0;
		
		//encuentra el camino mas corto entre todos los vertices
	for (count = 0; count < V - 1; count++){
		
		
		//u siempre sera igual a src en la primera iteracion
		int u = minDistance(dist, sptSet);
		
		//marca los nodos procesados como verdaderos
		sptSet[u] = true;
		
		//actualiza el valor de los vertices adjacentes, de el nodo seleccionado
		for (v = 0; v < V; v++)
		
		/*Actualizar dist[v] sólo si no está en sptSet, hay una arista de u a v, 
		y el peso total de la ruta de src a v a través de u es menor que el valor actual de dist[v].*/
		
		if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
			 && dist[u] + graph[u][v] < dist[v])
			 dist[v] = dist[u] + graph[u][v];
	}
	printResult(dist);
}

int main(){
	//Llenamos la matriz y mandamos llamar la funcion.
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
                        
                        
    dijkstra(graph,0);
    
    return 0;
}



