#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int adjMatrix[MAX][MAX];
int visited[MAX];
int n; 

void createGraph() {
    int i, j;
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
}

void DFS(int v) {
    int i;
    visited[v] = 1;
    printf("City %d\n", v);
    for (i = 0; i < n; i++) {
        if (adjMatrix[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    int i, v;
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    queue[rear++] = start;
    visited[start] = 1;
    while (front < rear) {
        v = queue[front++];
        printf("City %d\n", v);
        for (i = 0; i < n; i++) {
            if (adjMatrix[v][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int start, choice;
    createGraph();
    printf("Enter the starting city (0 to %d): ", n - 1);
    scanf("%d", &start);
    printf("Choose traversal method:\n1. DFS\n2. BFS\nEnter choice: ");
    scanf("%d", &choice);
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    if (choice == 1) {
        printf("Cities reachable from city %d using DFS:\n", start);
        DFS(start);
    } else if (choice == 2) {
        printf("Cities reachable from city %d using BFS:\n", start);
        BFS(start);
    } else {
        printf("Invalid choice.\n");
    }
    return 0;
}