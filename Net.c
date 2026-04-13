
#include "Net.h"

void makeEmptyList(EdgeList* lst) {
    lst->head = lst->tail = NULL;
}

EdgeNode* createNewListNode(Edge data, EdgeNode* next) {
    EdgeNode* result = (EdgeNode*)malloc(sizeof(EdgeNode));
    checkAllocation(result);
    result->e = data;
    result->next = next;
    return result;
}

void insertSorted(EdgeList* lst, Edge data) {
    EdgeNode* newNode = createNewListNode(data, NULL);

    if (isEmptyList(lst)) {
        lst->head = lst->tail = newNode;
    }
    else if (data.neighbor < lst->head->e.neighbor) {
        newNode->next = lst->head;
        lst->head = newNode;
    }
    else {
        EdgeNode* curr = lst->head;
        while (curr->next != NULL && curr->next->e.neighbor < data.neighbor)
            curr = curr->next;

        newNode->next = curr->next;
        curr->next = newNode;

        if (newNode->next == NULL)
            lst->tail = newNode;
    }
}

bool isEmptyList(EdgeList* lst) {
    return lst->head == NULL;
}

void checkAllocation(void* ptr) {
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
}

EdgeList* build_net(int n)
{
    
    if (n <= 0) 
    {
        printf("Invalid input.\n");
        exit(-1);
    }
    int m;
    EdgeList* Net = malloc(n * sizeof * Net);
    checkAllocation(Net);
    for (int i = 0; i < n; i++)
        makeEmptyList(&Net[i]);

    scanf("%d", &m);
    if (n <= 0 || m < 0) {           // בדיקת תקינות בסיסית
        printf("Invalid input.\n");
        exit(-1);
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, cost;
        scanf("%d %d %d", &a, &b, &cost);
        if (a < 0 || a >= n || b < 0 || b >= n || cost < 0) {
            printf("Invalid input.\n");
            exit(-1);
        }
        insertSorted(&Net[a], (Edge) { b, cost });
        insertSorted(&Net[b], (Edge) { a, cost });
    }

    return Net;  // ← החזירו כאן, אחרי סיום הלולאה
}
void freeEdgeListArray(EdgeList* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        EdgeNode* curr = arr[i].head;
        while (curr)
        {
            EdgeNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(arr); // free the array of EdgeList itself
}

// Frees an array of EdgeList (each one is a linked list of EdgeNodes)
