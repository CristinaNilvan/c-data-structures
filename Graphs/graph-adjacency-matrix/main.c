#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct
{
    int numberOfNodes ;
    int ** adjacencyMatrix;
} Graph;

enum {NOT_VISITED, VISITED};

FILE * validateFile(const char * fileName)
{
    FILE * file = fopen(fileName, "r");

    return file;
}

void printError()
{
    printf("Not enough memory!\n");
    exit(1);
}

void allocateMemory(Graph * graph)
{
    for (int i = 0; i < graph->numberOfNodes ; i++)
    {
        graph->adjacencyMatrix[i] = calloc(graph->numberOfNodes, sizeof(int));

        if (graph->adjacencyMatrix[i] == NULL)
            printError();
    }
}

void createGraphFromFile(FILE * file, Graph * graph)
{
    fscanf(file, "%d", &graph->numberOfNodes );

    graph->adjacencyMatrix = calloc(graph->numberOfNodes , sizeof(int *));

    if (graph->adjacencyMatrix == NULL)
        printError();

    allocateMemory(graph);

    int firstOfThePair, secondOfThePair;

    while (fscanf(file, "%d %d", &firstOfThePair, &secondOfThePair) == 2)
    {
        graph->adjacencyMatrix[firstOfThePair][secondOfThePair] = 1;
        graph->adjacencyMatrix[secondOfThePair][firstOfThePair] = 1;
    }
}

void initializeVisitedNodes(Graph * graph, int * visitedNodes)
{
    for (int i = 0; i < (*graph).numberOfNodes ; i++ )
        visitedNodes[i] = NOT_VISITED;
}

void traverseGraph(Graph * graph, int * visitedNodes, Queue * queue, int visited)
{
    while(!empty((*queue)))
    {
        visited = dequeue(queue);

        for (int toBeVisited = 0; toBeVisited < (*graph).numberOfNodes ; toBeVisited++)
            if ((*graph).adjacencyMatrix[visited][toBeVisited] == 1)
            {
                if (visitedNodes[toBeVisited] == NOT_VISITED )
                {
                    visitedNodes[toBeVisited] = VISITED;

                    printf("%d ", toBeVisited);

                    enqueue(queue, toBeVisited);
                }
            }
    }
}

void breadthFirstSearch(Graph graph, int sourceNode)
{
    int * visitedNodes = calloc(graph.numberOfNodes , sizeof(int));

    if (visitedNodes == NULL)
        printError();

    Queue queue;
    int visited = 0;

    initializeQueue(&queue);
    initializeVisitedNodes(&graph, visitedNodes);

    visitedNodes[sourceNode] = VISITED;
    printf("%d ", sourceNode);

    enqueue(&queue, sourceNode);

    traverseGraph(&graph, visitedNodes, &queue, visited);
}

void testsBreadthFirstSearch(Graph * graph)
{
    int sourceNode;

    printf("Number of nodes : %d. \nEnter the source node : ", (*graph).numberOfNodes );
    scanf("%d", &sourceNode);

    breadthFirstSearch((*graph), sourceNode);
}

int main()
{
    FILE * file = validateFile("Graph.txt");

    if (!file)
    {
        perror("Graph.txt");
        exit(1);
    }

    Graph graph;
    createGraphFromFile(file, &graph);

    testsBreadthFirstSearch(&graph);

    fclose(file);

    return 0;
}
