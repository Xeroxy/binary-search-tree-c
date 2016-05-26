#ifndef NODE_H
#define NODE_H
#define N 10

#ifndef max
		#define max(a,b)(((a)>(b)))?(a):(b)) //Macro allowing us to find maximum between to integer 
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
	int _data;
	struct Node *_left;
	struct Node *_right;
}Node;
typedef struct Node* Tree;

void add_leaf(Tree *T, int data);
void print_inc(Tree T);
void print_dec(Tree T);
void print_post_order(Tree T);
Tree constains(Tree T, int data);
int number_of_leaves(Tree T);
int depth_max(Tree T);
int depth(Tree T, int data);
void delete_tree(Tree *T);

#endif