
#ifndef PRIM_H
#define PRIM_H
#define _CRT_SECURE_NO_WARNINGS
#define SET_BIT(arr, i)    ((arr)[(i) / 8] |=  (1 << ((i) % 8)))// set a bit to 1
#define GET_BIT(arr, i)    (((arr)[(i) / 8] >> ((i) % 8)) & 1) // checks if a bit is on (1)
#include "Net.h"

typedef struct {
    int computer;
    int min;
} Candidate;

typedef struct candidate_node {
    Candidate c;
    struct candidate_node* next;
    struct candidate_node* prev;
} CandidateNode;

typedef struct {
    CandidateNode* head;
    CandidateNode* tail;
} CandidateList;

void makeEmptyCandidateList(CandidateList* lst);
CandidateNode* createCandidateNode(Candidate c);
void insertCandidate(CandidateList* lst, Candidate c, CandidateNode** location);
Candidate DeleteMin(CandidateList* lst);
void DecreaseKey(int v, CandidateNode** location, int newVal);
int* build_prim_tree(EdgeList* Net, int n);

#endif
