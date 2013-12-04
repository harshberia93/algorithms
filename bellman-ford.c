/*
Vertices are marked from 0 to n-1. We assume infinity to a high value such that no value in our graph is that big.
*/

#include<stdio.h>
#include<malloc.h>
#define Infinity 100000000
int main() {
    int n, i, j, k, source;
    float least_distance = 0;
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

    float *distance = (float *)calloc(n, sizeof(float));
    float *new_distance = (float *)calloc(n, sizeof(float));
    // Initializing operation i.e. iteration 1
    for (i=1; i<n; i++) {
        if (adjacency[source][i] != 0) {
            distance[i] = adjacency[source][i];   
        } else {
            distance[i] = Infinity;
        }
    }

    for (i=0; i<n-2; i++) {
        for (j=0; j<n; j++) { // Iterating over the n-nodes
            least_distance = distance[j]; // Least distance for node j so far
            for (k=0; k<n; k++) {
                if (adjacency[k][j] != 0) { // Nodes that point to node j
                    if ((distance[k] + adjacency[k][j]) < least_distance) {
                        least_distance = distance[k] + adjacency[k][j];
                    }
                }
            }
            new_distance[j] = least_distance;
        }
        // Assigning the new distances to the array elements
        for (k=0; k<n; k++) {
            distance[k] = new_distance[k];
        }
    }

    for (i=0; i<n; i++) { // Printing final distances
        printf("%.2f ", distance[i]);
    }
    printf("\n");
    return 0;
}
