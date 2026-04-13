#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Prim.h"

void makeEmptyCandidateList(CandidateList* lst)
{
    lst->head = lst->tail = NULL;
}

CandidateNode* createCandidateNode(Candidate c) 
{
    CandidateNode* node = (CandidateNode*)malloc(sizeof(CandidateNode));
    checkAllocation(node);
    if (!node) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    node->c = c;
    node->next = node->prev = NULL;
    return node;
}

void insertCandidate(CandidateList* lst, Candidate c, CandidateNode** location) 
{
    CandidateNode* curr = createCandidateNode(c);
    location[c.computer] = curr;
    if (lst->head == NULL) {
        lst->head = lst->tail = curr;
    }
    else {
        lst->tail->next = curr;
        curr->prev = lst->tail;
        lst->tail = curr;
    }
}

Candidate DeleteMin(CandidateList* lst)
{
    CandidateNode* v = lst->head;
    CandidateNode* min = v;
    int minVal = v->c.min;

    while (v != NULL) 
    {
        if (v->c.min < minVal)
        {
            minVal = v->c.min;
            min = v;
        }
        v = v->next;
    }

    if (min == lst->head && min == lst->tail)
    {
        lst->head = lst->tail = NULL;
    }
    else if (min == lst->head) 
    {
        lst->head = min->next;
        lst->head->prev = NULL;
    }
    else if (min == lst->tail) 
    {
        lst->tail = min->prev;
        lst->tail->next = NULL;
    }
    else 
    {
        min->prev->next = min->next;
        min->next->prev = min->prev;
    }
    Candidate result = min->c;
    free(min);
    return result;
}

void DecreaseKey(int v, CandidateNode** location, int newVal)
{
    if (location[v] != NULL) 
    {
        location[v]->c.min = newVal;
    }
    else
    {
        printf("computer %d does not exist!\n", v);
    }
}

int* build_prim_tree(EdgeList* Net, int n) 
{
    
    unsigned char* inT;
    int size = (n + 7) / 8;//the bits arr size in bytes
    inT = (unsigned char*)calloc(size, sizeof(unsigned char)); //calloc - set every bit to 0 (false) 

    int* min = (int*)malloc(n * sizeof(int));
    checkAllocation(min);
    int* Prim = (int*)malloc(n * sizeof(int));
    checkAllocation(Prim);
    CandidateNode** Location = (CandidateNode**)malloc(n * sizeof(CandidateNode*));
    checkAllocation(Location);

    CandidateList PrioriyList;
    makeEmptyCandidateList(&PrioriyList);

    for (int v = 0; v < n; v++) 
    {
        min[v] = INT_MAX;
        Prim[v] = -1;
        Candidate c;
        c.computer = v;
        c.min = min[v];
        insertCandidate(&PrioriyList, c, Location);
    }
    
    min[0] = 0;
    Prim[0] = -1;
    DecreaseKey(0, Location, 0);

    while (PrioriyList.head != NULL) {
        Candidate u = DeleteMin(&PrioriyList);
        if (min[u.computer] == INT_MAX) {
            printf("No spanning tree available.\n");
            exit(-1);
        }

        SET_BIT(inT, u.computer);
        EdgeNode* p = Net[u.computer].head;

        while (p != NULL) {
            int v = p->e.neighbor;
            int cost = p->e.cost;

            if (!GET_BIT(inT, v) && cost < min[v]) {
                min[v] = cost;
                Prim[v] = u.computer;
                DecreaseKey(v, Location, cost);
            }
            p = p->next;
        }
    }

    // שחרור זיכרון עזר
    free(min);
    free(inT);
    free(Location);
    

    return Prim;
}
