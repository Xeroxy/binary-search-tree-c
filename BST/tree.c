#include"node.h"

void add_leaf(Tree *T, int data){ //Leaf builder
	Tree new_leaf=NULL;				
	if(!(*T)){//If tree is empty
		new_leaf=malloc(sizeof(struct Node));// Allocate memory of new leaf
		new_leaf->_left=new_leaf->_right=NULL;//Initialize the children to null
		new_leaf->_data=data;//Load data into the leaf
		*T=new_leaf;
		return;
	}
	if(data<(*T)->_data){//Data to be put smaller than the current node
		add_leaf(&(*T)->_left,data);//Insert on the left of the current node
	}
	if(data>(*T)->_data){//Data to be put greater than the current node
		add_leaf(&(*T)->_right,data);//Insert on the right of the current node
	}
}
void print_inc(Tree T){ //Inorder printing
	if(!T){ //If tree is empty retun...
		return;
	}
	print_inc(T->_left); //Start on left: smaller values
	printf("%d ",T->_data); //Print data
	print_inc(T->_right); //Keep recursively exploring the right subtrees: greater values
}
void print_dec(Tree T){ //Descending order printing
	if(!T){ //If tree is empty retun...
		return;
	}
	print_dec(T->_right); //Start on right: greater values
	printf("%d ",T->_data); //Print data
	print_dec(T->_left); //Keep recursively exploring the left subtrees: smaller values
}
void print_post_order(Tree T){ //Post-order printing (Left, Right, Node)
	if(!T){ //If tree is empty retun...
		return;
	}
	print_post_order(T->_left); //Left child recursive call
	print_post_order(T->_right);//Right child recursive call
	printf("%d ",T->_data); //Print data
}
void delete_tree(Tree *T){ //Delete the entire tree
	if(*T!=NULL){ //Until tree has no leaves
		Tree current=*T;
		if(current->_left!=NULL){ //Until left subtrees has no leaves
			delete_tree(&current->_left);
		}
		else if(current->_right!=NULL){ //Until right subtrees has no leaves
			delete_tree(&current->_right);
		}
	free(current); //Free current node
	*T=NULL; //Initialize tree to null
	}
}
Tree constains(Tree T, int data){ //Search leaf on the tree
	if(!T){ //If tree is empty, return null
		return NULL;
	}
	else if ((T->_data)==data){ // If the value is present return its node
		return T;
	}
	else{ //Else, keep recursively searching in the tree
		Tree left=constains(T->_left, data); //Search on left subtree and keep result in left
		return (left? left: constains(T->_right, data)); //"Ternary operator" (if-then-else expression) ?: return left or right data
	}
}
int number_of_leaves(Tree T){ //Size of the tree (Number of leaves present in the tree)
	if(!T){
		return 0;
	}
	return 1+number_of_leaves(T->_right)+number_of_leaves(T->_left); //Get the size of left and right subtrees recursively, sum them and return it
}
int depth_max(Tree T){ //Maximum height (depth) of the tree
	if(!T){
		return 0;
	}
	return 1+max(depth_max(T->_right),depth_max(T->_left)); //Get the max path between left and right subtrees recursively and return it
}
int depth(Tree T, int data){ //Get the depth of one node
	if(!T){
		return 0;
	}
	return 1+max(depth(T->_right, data),depth(T->_left, data)); //Get recursively the max path between left and right subtrees to the data and return it
}
