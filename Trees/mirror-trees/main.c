#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodeType
{
    int key;
    struct nodeType * left;
    struct nodeType * right;
} Node;

FILE * validateFile(const char * fileName)
{
    FILE * file = fopen(fileName, "r");
    return file;
}

void openFiles(FILE ** firstFile, FILE ** secondFile)
{
    *firstFile = validateFile("FirstTree.txt");
    *secondFile = validateFile("SecondTree.txt");
}

Node * createBinaryTreeFromFile(FILE * file)
{
    Node * newNode;
    int key;

    fscanf(file, "%d", &key);

    if (key == 0)
        return NULL;

    newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("We don't have memory in createBinTree!");
        exit(5);
    }

    newNode->key = key;
    newNode->left = createBinaryTreeFromFile(file);
    newNode->right = createBinaryTreeFromFile(file);

    return newNode;
}

void createTrees(FILE * firstFile, FILE * secondFile, Node ** firstTreeRoot, Node ** secondTreeRoot)
{
    *firstTreeRoot = createBinaryTreeFromFile(firstFile);
    *secondTreeRoot = createBinaryTreeFromFile(secondFile);
}

bool areMirror(Node * firstTreeRoot, Node * secondTreeRoot)
{
    if (firstTreeRoot == NULL && secondTreeRoot == NULL)
        return true;

    if (firstTreeRoot == NULL || secondTreeRoot == NULL)
        return false;

    return (firstTreeRoot->key == secondTreeRoot->key) && areMirror(firstTreeRoot->left, secondTreeRoot->right) &&
            areMirror(firstTreeRoot->right, secondTreeRoot->left);
}

void testsIfTreesAreMirror(Node * firstTreeRoot, Node * secondTreeRoot)
{
    printf("Are the given trees mirror of each other? \n");

    areMirror(firstTreeRoot, secondTreeRoot) ? printf("Yes") : printf("No");
}

void closeFiles(FILE * firstFile, FILE * secondFile)
{
    fclose(firstFile);
    fclose(secondFile);
}

int main()
{
    FILE * firstFile;
    FILE * secondFile;

    openFiles(&firstFile, &secondFile);

    if (!firstFile && !secondFile)
    {
        printf("Something went wrong!");
        return -1;
    }

    Node * firstTreeRoot;
    Node * secondTreeRoot;

    createTrees(firstFile, secondFile, &firstTreeRoot, &secondTreeRoot);

    testsIfTreesAreMirror(firstTreeRoot, secondTreeRoot);

    closeFiles(firstFile, secondFile);

    return 0;
}
