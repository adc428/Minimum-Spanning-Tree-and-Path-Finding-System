#ifndef PATH_H
#define PATH_H
#define _CRT_SECURE_NO_WARNINGS
#define WHITE 0
#define GRAY 1
#define BLACK 2
#include "Net.h"

EdgeList* build_paths(int* tree, int n);
void FindPath(int u, EdgeList* PrimPaths, int* color, int* parent, int last);
void PrintPath(int v, int* parent);
void find_and_print_path(EdgeList* PrimPath, int n, int first, int last);

#endif
