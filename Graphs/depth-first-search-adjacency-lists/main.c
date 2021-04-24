#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType
{
    int key;
    struct nodeType * next;
} Node;

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

Node * createNode(int key)
{
    Node * node = (Node *)malloc(sizeof(Node));

    node->key = key;
    node->next = NULL;

    return node;
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

void depthFirstSearchVisit(Graph * graph, int visitedNode, int * time)
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
            depthFirstSearchVisit(graph, nodeToVisit, time);
        }

        currentNodeInList = currentNodeInList->next;
    }

    graph->colorOfNodes[visitedNode] = BLACK;
    *time = *time + 1;
    graph->completionTime[visitedNode] = *time;
}

void depthFirstSearchRecursive(Graph * graph)
{
    int time = 0;

    for (int i = 0; i < graph->numberOfNodes; i++)
        if (graph->colorOfNodes[i] == WHITE)
            depthFirstSearchVisit(graph, i, &time);
}

void printVector(int * vector, int number)
{
    for (int i = 0; i < number; i++)
        printf("%d ", vector[i]);

    printf("\n");
}

void testsDepthFirstSearch(Graph * graph)
{
    depthFirstSearchRecursive(graph);

    printVector((*graph).parentNodes, (*graph).numberOfNodes);
    printVector((*graph).discoverTime, (*graph).numberOfNodes);
    printVector((*graph).completionTime, (*graph).numberOfNodes);
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

    testsDepthFirstSearch(&graph);

    freeMemory(&graph);

    fclose(file);

    return 0;
}
