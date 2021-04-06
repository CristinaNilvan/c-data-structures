#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType
{
    int key;
    struct nodeType * left;
    struct nodeType * right;
} treeNode;

typedef struct node
{
    int key;
    struct node * next;
} listNode;

treeNode * createTreeNode(int key)
{
    treeNode * newNode = (treeNode *)malloc(sizeof(treeNode));

    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

listNode * createListNode(int key)
{
    listNode * node = (listNode *)malloc(sizeof(listNode));

    node->key = key;
    node->next = NULL;

    return node;
}

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

void initializeTrees(treeNode ** firstTreeRoot, treeNode ** secondTreeRoot)
{
    *firstTreeRoot = NULL;
    *secondTreeRoot = NULL;
}

void initializeLists(listNode ** firstListOne, listNode ** lastListOne, listNode ** firstListTwo, listNode ** lastListTwo)
{
    *firstListOne = NULL;
    *lastListOne = NULL;

    *firstListTwo = NULL;
    *lastListTwo = NULL;
}

treeNode * insertNodeInTree(treeNode * root, int key)
{
    if (root == NULL)
        return createTreeNode(key);

    if (key < root->key)
        root->left = insertNodeInTree(root->left, key);

    if (key > root->key)
        root->right = insertNodeInTree(root->right, key);

    return root;
}

void createBinarySearchTreeFromFile(FILE * file, treeNode ** root)
{
    int data;

    while (fscanf(file, "%d ", &data) == 1)
        *root = insertNodeInTree(*root, data);
}

void insertLastInList(listNode ** first, listNode ** last, int givenKey)
{
    listNode * node = createListNode(givenKey);

    *last == NULL ? (*first = node) : ((*last)->next = node);

    *last = node;
}

void convertTreeToList(treeNode * root, listNode ** first, listNode ** last)
{
    if (root != NULL)
    {
        insertLastInList(first, last, root->key);
        convertTreeToList(root->left, first, last);
        convertTreeToList(root->right, first, last);
    }
}

void concatenateLists(listNode ** lastListOne, listNode ** firstListTwo, listNode ** lastListTwo)
{
    (*lastListOne)->next = *firstListTwo;
    *lastListOne = *lastListTwo;

    *firstListTwo = NULL;
    *lastListTwo = NULL;
}

treeNode * searchTreeNode(treeNode * root, int key)
{
    if (root == NULL || root->key == key)
        return root;

    if (root->key < key)
        return searchTreeNode(root->right, key);

    return searchTreeNode(root->left, key);
}

void mergeTrees(listNode * first, treeNode ** mergedTreesRoot)
{
    while (first != NULL)
    {
        if (searchTreeNode(*mergedTreesRoot, first->key) == NULL)
            *mergedTreesRoot = insertNodeInTree(*mergedTreesRoot, first->key);

        first = first->next;
    }
}

void preOrderPrint(treeNode * root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrderPrint(root->left);
        preOrderPrint(root->right);
    }
}

void testsMerge(listNode * first, treeNode ** mergedTreeRoot)
{
    mergeTrees(first, mergedTreeRoot);

    preOrderPrint(*mergedTreeRoot);
}

void closeFiles(FILE * firstFile, FILE * secondFile)
{
    fclose(firstFile);
    fclose(secondFile);
}

void createTrees(FILE *firstFile, FILE *secondFile, treeNode ** firstTreeRoot, treeNode ** secondTreeRoot)
{
    initializeTrees(firstTreeRoot, secondTreeRoot);

    createBinarySearchTreeFromFile(firstFile, firstTreeRoot);
    createBinarySearchTreeFromFile(secondFile, secondTreeRoot);
}

int main()
{
    FILE * firstFile;
    FILE * secondFile;

    openFiles(&firstFile, &secondFile);

    if (!firstFile && !secondFile)
    {
        printf("Something went wrong with your files!");
        return -1;
    }

    treeNode *firstTreeRoot;
    treeNode *secondTreeRoot;

    createTrees(firstFile, secondFile, &firstTreeRoot, &secondTreeRoot);

    listNode *firstListOne;
    listNode *lastListOne;

    listNode *firstListTwo;
    listNode *lastListTwo;

    initializeLists(&firstListOne, &lastListOne, &firstListTwo, &lastListTwo);

    convertTreeToList(firstTreeRoot, &firstListOne, &lastListOne);
    convertTreeToList(secondTreeRoot, &firstListTwo, &lastListTwo);

    concatenateLists(&lastListOne, &firstListTwo, &lastListTwo);

    treeNode * mergedTreeRoot = NULL;
    testsMerge(firstListOne, &mergedTreeRoot);

    closeFiles(firstFile, secondFile);

    return 0;
}
