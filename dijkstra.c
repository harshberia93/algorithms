/*
Vertices are marked from 0 to n-1. We assume infinity to a high value such that no value in our graph is that big.
*/

#include<stdio.h>
#include<malloc.h>
#define Infinity 100000000
int main() {
    int n, i, j, source, unmarked;
    scanf("%d", &n); // Number of vertex
    // Making 2-d Adjacency matrix
    float **adjacency = (float **)malloc(n * sizeof(float*));
    for (i=0; i<n; i++) {
    	*(adjacency + i) = (float *)malloc((n) * sizeof(float));
    }
    // Initializing adjacency matrix
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++){
            scanf("%f", &adjacency[i][j]);
        }
    }
    scanf("%d", &source);
    int *marked_vertices = (int *)calloc(n, sizeof(int));
    marked_vertices[source] = 1;    

    float *distance = (float *)calloc(n, sizeof(float));
    // Initialize distance from source
    for (i=0; i<n; i++) {
        if (i == source) {
            distance[i] = 0;
        } else {
            if (adjacency[source][i] == 0) { // If source not connected to a vertex
                distance[i] = Infinity;
            } else {
                distance[i] = adjacency[source][i];
            }
        }
    }
    while(all_vertices_marked(marked_vertices, n) == 0){
        unmarked = minimum_unmarked(marked_vertices, distance, n); // To find out minumum unmarked vertex
        marked_vertices[unmarked] = 1; // Mark the minimum vertex
        for (i=0; i<n; i++) {
            if (marked_vertices[i] == 0) {
                if (adjacency[unmarked][i] != 0){
                    distance[i] = (distance[i] > (distance[unmarked] + adjacency[unmarked][i]))?(distance[unmarked] + adjacency[unmarked][i]) : distance[i];
                }
            }
        }
        for (i=0; i<n; i++) {
            printf("%.2f  ", distance[i]);
        }
        printf("\n");
    }

    return 0;
}

int all_vertices_marked(int *marked_vertices, int n) {
    int i;
    for (i=0; i<n; i++) {
        if (marked_vertices[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int minimum_unmarked(int *marked_vertices, float *distance, int n) {
    int minimum_vertex, i;
    float minimum_distance;
    minimum_distance = 2 * Infinity; // So that if any vertex is not connected to graph then also minimum vertex is taken
    for (i=0; i<n; i++) {
        if (marked_vertices[i] == 0) {
            if (minimum_distance > distance[i]) {
                minimum_vertex = i;
                minimum_distance = distance[i];
            }
        }
    }
    return minimum_vertex;
}