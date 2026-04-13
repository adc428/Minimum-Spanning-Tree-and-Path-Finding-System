# Project: Communication Network MST and Path Finder

# Description

This project implements a communication network analyzer in C.  
The program receives a graph of computers connected by bidirectional communication lines with costs, builds the network as adjacency lists, computes a Minimum Spanning Tree using Prim’s algorithm, converts that tree into a paths network, and finds the path between two requested computers.

# Components

Network Builder (`build_net`):
Receives the network input and builds an adjacency-list representation of the graph.

MST Builder (`build_prim_tree`):
Uses Prim’s algorithm to compute a Minimum Spanning Tree and stores it as a parent array.

Paths Builder (`build_paths`):
Converts the parent-array tree into a linked-list network structure.

Path Search (`find_and_print_path`):
Performs recursive traversal on the paths network and prints the route between two computers.

# Features

Adjacency-list graph representation.

Sorted insertion into linked lists.

Minimum Spanning Tree computation.

Path network generation from tree structure.

Recursive path search and printing.

# Requirements

C compiler (GCC / Visual Studio)

Standard C library
