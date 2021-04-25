#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct
{
    int numberOfNodes;
    Node ** adjacencyLists;
    int * parentNodes;
    int * discoverTime;
    int * completionTime;
    int * colorOfNodes;
} Graph;

enum {WHITE, GRAY, BLACK};

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

void allocateMemoryForGraph(Graph * graph)
{
    graph->adjacencyLists = (Node **)calloc(graph->numberOfNodes , sizeof(Node *));
    graph->parentNodes = (int *)calloc(graph->numberOfNodes , sizeof(int));
    graph->discoverTime = (int *)calloc(graph->numberOfNodes , sizeof(int));
    graph->completionTime = (int *)calloc(graph->numberOfNodes , sizeof(int));
    graph->colorOfNodes = (int *)calloc(graph->numberOfNodes , sizeof(int));
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

void initializeAdjacencyLists(Graph * graph)
{
    for (int i = 0; i < graph->numberOfNodes ; i++)
        graph->adjacencyLists[i] = NULL;
}

void initializeParentNodes(Graph * graph)
{
    for (int i = 0; i < graph->numberOfNodes ; i++)
        graph->parentNodes[i] = -1;
}

void createGraphFromFile(FILE * file, Graph * graph)
{
    fscanf(file, "%d", &graph->numberOfNodes );

    allocateMemoryForGraph(graph);

    initializeAdjacencyLists(graph);
    if (graph->adjacencyLists == NULL)
        printError();

    initializeParentNodes(graph);

    int firstOfThePair, secondOfThePair;

    while (fscanf(file, "%d %d", &firstOfThePair, &secondOfThePair) == 2)
    {
        insertInAdjacencyList(graph, firstOfThePair, secondOfThePair);
        insertInAdjacencyList(graph, secondOfThePair, firstOfThePair);
    }
}

void depthFirstSearchRecursive(Graph * graph, int visitedNode, int * time)
{
    *time += 1;
    graph->discoverTime[visitedNode] = *time;
    graph->colorOfNodes[visitedNode] = GRAY;

    Node * currentNodeInList = graph->adjacencyLists[visitedNode];

    while (currentNodeInList != NULL)
    {
        int nodeToVisit = currentNodeInList->key;

        if (graph->colorOfNodes[nodeToVisit] == WHITE)
        {
            graph->parentNodes[nodeToVisit] = visitedNode;
            depthFirstSearchRecursive(graph, nodeToVisit, time);
        }

        currentNodeInList = currentNodeInList->next;
    }

    graph->colorOfNodes[visitedNode] = BLACK;
    *time = *time + 1;
    graph->completionTime[visitedNode] = *time;
}

Node * traverseNeighbours(Graph * graph, Node ** stack, int visitedNode, Node * currentNode)
{
    while (currentNode != NULL)
    {
        int nodeToVisit = currentNode->key;

        if (graph->colorOfNodes[nodeToVisit] == WHITE)
        {
            push(stack, nodeToVisit);
            graph->parentNodes[nodeToVisit] = visitedNode;
        }

        currentNode = currentNode->next;
    }
    return (*stack);
}

void depthFirstSearchIterative(Graph * graph, int startNode)
{
    Node * stack;

    initializeStack(&stack);
    push(&stack, startNode);

    while (!empty(stack))
    {
        int visitedNode = pop(&stack);

        if (graph->colorOfNodes[visitedNode] == WHITE)
        {
            graph->colorOfNodes[visitedNode] = GRAY;
            printf("%d ", visitedNode);

            Node * currentNode = graph->adjacencyLists[visitedNode];

            stack = traverseNeighbours(graph, &stack, visitedNode, currentNode);
        }
    }
}

void reinitializeGraph(Graph * graph)
{
    for (int i = 0; i < graph->numberOfNodes; i++)
    {
        graph->parentNodes[i] = -1;
        graph->discoverTime[i] = -1;
        graph->completionTime[i] = -1;
        graph->colorOfNodes[i] = WHITE;
    }
}

void printVector(int * vector, int number)
{
    for (int i = 0; i < number; i++)
        printf("%d ", vector[i]);

    printf("\n");
}

void testsDepthFirstSearchRecursive(Graph * graph)
{
    printf("Depth First Search Recursive\n");

    int time = 0;

    int startNode;
    printf("Start node :");
    scanf("%d", &startNode);

    depthFirstSearchRecursive(graph, startNode, &time);

    printVector((*graph).parentNodes, (*graph).numberOfNodes);
    printVector((*graph).discoverTime, (*graph).numberOfNodes);
    printVector((*graph).completionTime, (*graph).numberOfNodes);
}

void testsDepthFirstSearchIterative(Graph * graph)
{
    printf("Depth First Search Iterative\n");

    int startNode;
    printf("Start node : ");
    scanf("%d", &startNode);

    depthFirstSearchIterative(graph, startNode);
    printf("\n");

    printVector((*graph).parentNodes, (*graph).numberOfNodes);
}

void freeAdjacencyLists(Graph * graph)
{
    for (int i = 0; i < (*graph).numberOfNodes; i++)
        while ((*graph).adjacencyLists[i] != NULL)
        {
            Node * toBeFreed = (*graph).adjacencyLists[i];
            (*graph).adjacencyLists[i] = (*graph).adjacencyLists[i]->next;

            free(toBeFreed);
        }

    free((*graph).adjacencyLists);
}

void freeMemory(Graph * graph)
{
    free((*graph).parentNodes);
    free((*graph).discoverTime);
    free((*graph).completionTime);
    free((*graph).colorOfNodes);
    freeAdjacencyLists(graph);
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

    testsDepthFirstSearchRecursive(&graph);
    reinitializeGraph(&graph);
    testsDepthFirstSearchIterative(&graph);

    freeMemory(&graph);

    fclose(file);

    return 0;
}
