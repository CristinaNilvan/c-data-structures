#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct
{
    int numberOfNodes;
    Node ** adjacencyLists;
} Graph;

enum { NOT_VISITED, VISITED };

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

void insertInAdjacencyList(Graph * graph, int firstOfThePair, int secondOfThePair)
{
    Node * toInsert = createNode(secondOfThePair);

    if (graph->adjacencyLists[firstOfThePair] == NULL)
        graph->adjacencyLists[firstOfThePair] = toInsert;
    else
    {
        Node * currentNode = graph->adjacencyLists[firstOfThePair];

        while (currentNode->next != NULL)
            currentNode = currentNode->next;

        currentNode->next = toInsert;
    }
}

void createGraphFromFile(FILE * file, Graph * graph)
{
    fscanf(file, "%d", &graph->numberOfNodes );

    graph->adjacencyLists = calloc(graph->numberOfNodes , sizeof(int *));

    if (graph->adjacencyLists == NULL)
        printError();

    for (int i = 0; i < graph->numberOfNodes ; i++)
        graph->adjacencyLists[i] = NULL;

    int firstOfThePair, secondOfThePair;

    while (fscanf(file, "%d %d", &firstOfThePair, &secondOfThePair) == 2)
    {
        insertInAdjacencyList(graph, firstOfThePair, secondOfThePair);
        insertInAdjacencyList(graph, secondOfThePair, firstOfThePair);
    }
}

void initializeVisitedNodes(Graph * graph, int * visitedNodes)
{
    for (int i = 0; i < (*graph).numberOfNodes ; i++ )
        visitedNodes[i] = NOT_VISITED;
}

void traverseGraph(Graph * graph, int * visitedNodes, Queue * queue)
{
    int visited, toBeVisited;

    while (!empty((*queue)))
    {
        visited = dequeue(queue);
        Node * currentNode = (*graph).adjacencyLists[visited];

        while (currentNode != NULL)
        {
            toBeVisited = currentNode->key;

            if (visitedNodes[toBeVisited] == NOT_VISITED)
            {
                visitedNodes[toBeVisited] = VISITED;

                printf("%d ", toBeVisited);

                enqueue(queue, toBeVisited);
            }

            currentNode = currentNode->next;
        }
    }
}

void breadthFirstSearch(Graph graph, int sourceNode)
{
    int * visitedNodes = calloc(graph.numberOfNodes , sizeof(int));

    if (visitedNodes == NULL)
        printError();

    Queue queue;

    initializeQueue(&queue);
    initializeVisitedNodes(&graph, visitedNodes);

    visitedNodes[sourceNode] = VISITED;
    printf("%d ", sourceNode);

    enqueue(&queue, sourceNode);

    traverseGraph(&graph, visitedNodes, &queue);
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
