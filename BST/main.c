#include "node.h"

void main(){
	//srand(time(NULL)); //Avoid repetition in random generation, does not work with visual...
	//int tab[N]={3,1,9,7,5,4,8,10,2,6}; //Static fulfilled tab for previous questions

	int i, input, random; //Create used integer
	Tree myTree=NULL; //Create & initialize a tree call myTree to null
	Tree tmp; //Create temporary tree (use for search if cases)

	for(i=0;i<N;i++){ //Loop until desire size (here N=10)
		random=(rand()%100)+1; //Random int generation from 0 to 100. If we do it like asked: from 0 to 10 -> only 7 values are added on the tree... We don't know why ??
		add_leaf(&myTree,random); //Call leaf builder
	}

	//Recursive paths printing
	printf("Increasing display:  ");
	print_inc(myTree); 
	printf("\n");
	printf("Decreasing display:  ");
	print_dec(myTree);
	printf("\n");
	printf("Post-order display:  ");
	print_post_order(myTree);
	printf("\n\n");

	//Recursive search on the tree
	printf("Value to find: "); //Ask user value to find...
	scanf("%d", &input);
	tmp = constains(myTree, input);
		if(tmp!=NULL){ //If data is found
			printf("\n1: Leaf %d exist\n", tmp->_data);
			printf("Depth of leaf %d: %d", tmp->_data, depth(tmp, input)); //Display its depth
		}
		else{ //If data is not found
			printf("\n0: Leaf %d does not exist\n", input);
		}
	
	printf("\nNumber of leaves of the tree: %d\n",number_of_leaves(myTree)); //Display number of leaves present in the tree
	printf("Maximal height: %d\n",depth_max(myTree)); //Display max depth of the tree
	delete_tree(&myTree); //Delete the tree to free allocated memory
	printf("\nTree has been deleted.\n\n");

system("pause"); 
}
