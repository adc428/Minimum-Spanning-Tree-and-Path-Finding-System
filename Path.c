#include <stdio.h>
#include <stdlib.h>
#include "Path.h"

EdgeList* build_paths(int* tree, int n)
{
    EdgeList* PrimPaths = (EdgeList*)malloc(n * sizeof(EdgeList));
    checkAllocation(PrimPaths);

    for (int i = 0; i < n; i++)
        makeEmptyList(&PrimPaths[i]);

    for (int v = 0; v < n; v++)
    {
        int u = tree[v]; // ההורה של v
        if (u != -1) // כלומר v אינו השורש
        {
            Edge e1 = { u, 0 };
            Edge e2 = { v, 0 };
            insertSorted(&PrimPaths[v], e1);
            insertSorted(&PrimPaths[u], e2);
        }
    }

    return PrimPaths;
}
void find_and_print_path(EdgeList* PrimPath, int n, int first, int last)
{
    int* Color = (int*)malloc(n * sizeof(int));
    int* Parent = (int*)malloc(n * sizeof(int));
    checkAllocation(Color);
    checkAllocation(Parent);

    for (int u = 0; u < n; u++)
    {
        Color[u] = WHITE;
        Parent[u] = -1;
    }
    if (first >= n || last >= n)               // Invalid input: index out of range
    {
        printf("Invalid input.");
        exit(-1);
    }

    FindPath(first, PrimPath, Color, Parent, last);
    PrintPath(last, Parent);
    printf("\n");

    free(Color);
    free(Parent);
}

void FindPath(int u, EdgeList* PrimPaths, int* color, int* parent,int last)
{
    color[u] = GRAY;
    EdgeNode* p = PrimPaths[u].head;

    while (p != NULL)
    {
        int v = p->e.neighbor;
        if (color[v] == WHITE)
        {
            parent[v] = u;
            if (v == last)
            {
                return;
            }
            else
            {
                FindPath(v, PrimPaths, color, parent, last);
            }
        }
        p = p->next;
    }
}
void PrintPath(int v, int* parent)
{
    if (parent[v] == -1) {
        // הגענו לנקודת ההתחלה – הדפסה ראשונה
        printf("%d", v);
        return;
    }

    // קודם מדפיסים את ההורה
    PrintPath(parent[v], parent);

    // ואז מדפיסים את v (כלומר, אחרי ההורה)
    printf(" %d", v);
}

