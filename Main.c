
#include "Net.h"
#include "Prim.h"
#include "Path.h" 
int main() {
    int n, first, last;
    scanf("%d", &n);
    EdgeList* Net = build_net(n);
    int* Prim = build_prim_tree(Net, n);
    EdgeList* PrimPath = build_paths(Prim, n); // אם קיימת
    scanf("%d%d", &first, &last);
    find_and_print_path(PrimPath, n, first, last); // אם קיימת
    freeEdgeListArray(Net, n);
    freeEdgeListArray(PrimPath, n);
    free(Prim);          
    return 0;
}


