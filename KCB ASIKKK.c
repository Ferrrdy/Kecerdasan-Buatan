#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

typedef struct Node {
    int cityIndex;
    struct Node*next;
} Node;

typedef struct City {
    char name[20];
    Node* head;
} City;

City cities[MAX];
int cityCount = 0;
int visited[MAX];

int addCity(char*name) {
    for(int i = 0; i < cityCount; i++) {
        if(strcmp(cities[i].name, name) == 0) return i;
    }

    strcpy(cities[cityCount].name, name);
    cities[cityCount].head = NULL;
    return cityCount++;
}

void addRoute(char* city1, char* city2) {
    int index1 = addCity(city1);
    int index = addCity()
}