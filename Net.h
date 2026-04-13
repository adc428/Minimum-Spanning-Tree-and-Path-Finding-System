
#ifndef NET_H
#define NET_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int neighbor;
    int cost;
} Edge;

typedef struct edge_node {
    Edge e;
    struct edge_node* next;
} EdgeNode;

typedef struct {
    EdgeNode* head;
    EdgeNode* tail;
} EdgeList;

void makeEmptyList(EdgeList* lst);
EdgeNode* createNewListNode(Edge data, EdgeNode* next);
void insertSorted(EdgeList* lst, Edge data);
bool isEmptyList(EdgeList* lst);
void checkAllocation(void* ptr);
EdgeList* build_net(int n);
void freeEdgeListArray(EdgeList* arr, int n);

#endif
