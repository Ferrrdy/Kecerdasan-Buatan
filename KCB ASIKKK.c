#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20 

typedef struct Node {
    int cityIndex;
    struct Node* next;
} Node;

typedef struct {
    char name[20];
    Node* head;
} City;

City cities[MAX];
int cityCount = 0;
int visited[MAX];

int addCity(char* name) {
    for (int i = 0; i < cityCount; i++) {
        if (strcmp(cities[i].name, name) == 0) return i;
    }
    strcpy(cities[cityCount].name, name);
    cities[cityCount].head = NULL;
    return cityCount++;
}

void addRoute(char* city1, char* city2) {
    int index1 = addCity(city1);
    int index2 = addCity(city2);

    Node* newNode1 = (Node*)malloc(sizeof(Node));
    newNode1->cityIndex = index2;
    newNode1->next = cities[index1].head;
    cities[index1].head = newNode1;

    Node* newNode2 = (Node*)malloc(sizeof(Node));
    newNode2->cityIndex = index1;
    newNode2->next = cities[index2].head;
    cities[index2].head = newNode2;
}

int dfs(int current, int destination, int path[], int pathIndex) {
    visited[current] = 1;
    path[pathIndex] = current;

    if (current == destination) {
        printf("Rute ditemukan: ");
        for (int i = 0; i <= pathIndex; i++) {
            printf("%s ", cities[path[i]].name);
            if (i != pathIndex) printf("-> ");
        }
        printf("\n");
        return 1;
    }

    Node* temp = cities[current].head;
    while (temp) {
        if (!visited[temp->cityIndex]) {
            if (dfs(temp->cityIndex, destination, path, pathIndex + 1)) {
                return 1;
            }
        }
        temp = temp->next;
    }

    return 0;
}

void findRouteDFS(char* start, char* end) {
    int startIndex = -1, endIndex = -1;
    
    for (int i = 0; i < cityCount; i++) {
        if (strcmp(cities[i].name, start) == 0) startIndex = i;
        if (strcmp(cities[i].name, end) == 0) endIndex = i;
    }

    if (startIndex == -1 || endIndex == -1) {
        printf("Kota tidak ditemukan!\n");
        return;
    }

    memset(visited, 0, sizeof(visited));
    int path[MAX];

    if (!dfs(startIndex, endIndex, path, 0)) {
        printf("Tidak ada rute dari %s ke %s\n", start, end);
    }
}

int main() {
    addRoute("Arad", "Zerind");
    addRoute("Arad", "Timisoara");
    addRoute("Arad", "Sibiu");
    addRoute("Zerind", "Oradea");
    addRoute("Oradea", "Sibiu");
    addRoute("Timisoara", "Lugoj");
    addRoute("Lugoj", "Mehadia");
    addRoute("Mehadia", "Dobreta");
    addRoute("Dobreta", "Craiova");
    addRoute("Craiova", "Pitesti");
    addRoute("Craiova", "Rimnicu Vilcea");
    addRoute("Pitesti", "Bucharest");
    addRoute("Sibiu", "Fagaras");
    addRoute("Fagaras", "Bucharest");
    addRoute("Sibiu", "Rimnicu Vilcea");
    addRoute("Rimnicu Vilcea", "Pitesti");
    addRoute("Bucharest", "Giurgiu");
    addRoute("Bucharest", "Urziceni");
    addRoute("Urziceni", "Vaslui");
    addRoute("Urziceni", "Hirsova");
    addRoute("Hirsova", "Eforie");
    addRoute("Vaslui", "Lasi");
    addRoute("Lasi", "Neamt");

    char start[20], end[20];
    printf("Masukkan kota asal: ");
    scanf("%s", start);
    printf("Masukkan kota tujuan: ");
    scanf("%s", end);

    findRouteDFS(start, end);

    return 0;
}
