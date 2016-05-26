/* 
 * File:   main.c
 * Author: Pierre
 *
 * Created on October 24, 2013, 10:51 AM
 */    
#include "node.h"

void insert_leaf(Tree *T, int X){ //Leaf builder
    Tree new_node=NULL;
        if(!(*T)){ //Allocate Memory of new node and load the data into it
            new_node=malloc(sizeof(struct Node));
            new_node->_left=new_node->_right=NULL; //Initialize the children to nulL
            new_node->_key=X; //Load data into the node      
            *T=new_node;
            return;
        }
        if(X<(*T)->_key){ //Data to be put smaller than current node
            insert_leaf(&(*T)->_left,X); //Insert on the left of current node
        }
        if(X>(*T)->_key){ //Data to be put greater than current node
            insert_leaf(&(*T)->_right,X); //Insert on the right of current node
        }
}      
int size(Tree T){ //Size of the tree (Number of nodes in a tree)
        if(!T){ //If tree is empty then return 0
            return 0;
        }
    return 1+size(T->_right)+size(T->_left); //Get the size of left and right subtrees recursively, sum them and return it
} 
int height(Tree T){ //Height of the tree
        if(!T){
            return 0;
        }
    return 1+max(height(T->_left),height(T->_right));
}
int maximum(Tree T) { //Value of maximum leaf
    Tree current = T;
        while (current->_right != NULL) {//Loop down to find the leftmost leaf  
          current = current->_right; 
        }
    return(current->_key); 
} 
int minimum(Tree T) { //Value of minimum leaf
    Tree current = T;  
        while (current->_left != NULL) {//Loop down to find the rightmost leaf  
          current = current->_left; 
        }
    return(current->_key); 
}
Tree position_min(Tree T){ //Get minimum node
        if(T!=NULL){
            while(T->_left!=NULL)
            T=T->_left;
            }
    return T;
}
Tree position_max(Tree T){ //Get maximum node
    if(T==NULL){
        return NULL;
    }
    else if(T->_right==NULL){
        return T;
    }
    else{
        return position_max(T->_right);
    }
}
void delete_tree(Tree *T){ //Delete the entire tree
    if(*T!=NULL){
        Tree curr = *T;
        if(curr->_left != NULL){
            delete_tree(&curr->_left);
        }
        if(curr->_right != NULL){
            delete_tree(&curr->_right);
        }
        free(curr);
        *T = NULL;
    }
}
bool same_tree(Tree a, Tree b) { //Check if two tree have common paths
  // 1. both empty -> true 
  if (a==NULL && b==NULL) return(1); 
  // 2. both non-empty -> compare them 
  else if (a!=NULL && b!=NULL) { 
    return( 
      a->_key == b->_key && 
      same_tree(a->_left, b->_left) && 
      same_tree(a->_right, b->_right) 
    ); 
  } 
  // 3. one empty, one not -> false 
  else return(0); 
} 
Tree search(Tree node, int key){ //Search a leaf on the tree
    if (node == NULL){ //If tree is empty, return null
        return NULL;
    }
    else if (node->_key == key){ //If the value is present return node
        return node;
    }    
    else { //Else, keep recursively search in the tree 
         Tree left = search(node->_left, key);
         return left? left: search(node->_right, key); // "ternary operator" (if-then-else expression) ?:
    }
}
Tree delete_pos(Tree T, int X){ //Delete leaf
    Tree tmp;
    if(T==NULL);
    
    else if(X<(T->_key)){
        T->_left = delete_pos(T->_left, X);
    }
    else if(X>(T->_key)){ 
        T->_right = delete_pos(T->_right, X);
    }
    else if((T->_left)!=NULL && (T->_right)!=NULL){ 
        tmp = position_min(T->_right);
        T->_key = tmp->_key;
        T->_right = delete_pos(T->_right,T->_key);
    }
    else{ 
        tmp = T;
        if((T->_left)==NULL){
            T = T->_right;
        }
        else if((T->_right)==NULL){
        T = T->_left;
        free(tmp);
        }
    }
    return T;
}
void inorder(Tree T){ //Ascending  
    if(!T){
        return;
    }
    inorder(T->_left);
    printf("%d ",T->_key);
    inorder(T->_right);
}   
void print_dec(Tree T){ //Descending
        if(!T){
            return;
        }
        print_dec(T->_right);
        printf("%d ",T->_key);
        print_dec(T->_left);
}
void preorder(Tree T){ //Pre-order (Node, Left, Right)
 if(!T){
     return;
 }
        printf("%d ",T->_key);
        preorder(T->_left);
        preorder(T->_right); 
}
void postorder(Tree T){ //Post-order 
 if(!T){
     return;
 }
    postorder(T->_left);
    postorder(T->_right);
    printf("%d ",T->_key);
}
void display(){ 
 int choice, key;
 Tree myTree=NULL;
 Tree tmp;

 printf("----------Program For Binary Search Tree----------");
 do{
   printf("\n1.Create Randomly Fulfilled BST");
   printf("\n2.Search");
   printf("\n3.Recursive Paths");
   printf("\n4.Delete Leaf");
   printf("\n5.Delete BST");
   printf("\n6.Exit");
   printf("\nEnter your choice :");
   scanf("%d",&choice);

   switch(choice){
        case 1:
               srand(time(NULL));
               int i, dSize;
               printf("\nSize ?: ");
               scanf("%d", &dSize);
               for(i=0;i<dSize;i++){
                  int r = rand()%999;
                  insert_leaf(&myTree, r); 
               }

               printf("\nmyTree (I) - L:%d - H:%d - Max:%d - Min:%d \n",size(myTree), height(myTree), maximum(myTree), minimum(myTree));
               inorder(myTree);
               printf("\n");
               break;
         case 2:
               if(!myTree){
                   printf("\n++++++ Tree is not created ++++++\n");
                   break;
               }
               printf("\nEnter Element to be searched :");
               scanf("%d",&key);  
                   
               clock_t begin, end;
                double time_spent;
                begin = clock();    
                        tmp = search(myTree,key);
                end = clock();;
                time_spent = (double)(end - begin)/CLOCKS_PER_SEC;

               if (tmp!=NULL){
                    printf("\nNode %d is present.\n", tmp->_key);
                    printf("Search time: %f sec.\n",time_spent);
               }
               else{
                    printf("\nNode %d is not present.\n", key);
                    printf("Search time: %f sec.\n",time_spent);
               }                
            break;
       case 3:
            if(!myTree){
               printf("\n++++++ Tree is not created ++++++\n");
               break;
            }
            else{
               printf("\nThe Ascending display : "); inorder(myTree);
               printf("\nThe Descending display : "); print_dec(myTree);
               printf("\nThe Pre-order display : "); preorder(myTree);
               printf("\nThe Post-order display : "); postorder(myTree);
               printf("\n");
               }
            break;
       case 4:
           if(!myTree){
               printf("\n++++++ Tree is not created ++++++\n");
               break;
            }
           else{
               printf("\nEnter leaf to be deleted:");
               scanf("%d",&key);
               tmp = delete_pos(myTree, key);
               printf("\nmyTree (I) - L:%d - H:%d - Max:%d - Min:%d \n",size(tmp), height(tmp), maximum(tmp), minimum(tmp));
               inorder(tmp); 
           }
           break;
        case 5:
            if(!myTree){
               printf("\n++++++ Tree is not created ++++++\n");
               break;
            }
            else{
                delete_tree(&myTree);
                printf("\nBST has been deleted.\n");
            }
            break;
   }
   }while(choice!=6);
}
int main(int argc, char** argv) {
    display();
    return (EXIT_SUCCESS);
}