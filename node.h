/* 
 * File:   node.h
 * Author: Pierre
 *
 * Created on October 24, 2013, 10:51 AM
 */

#ifndef LIST_H
#define	LIST_H

#ifndef max
	#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
#endif
#ifndef min
	#define min( a, b ) ( ((a) < (b)) ? (a) : (b) )
#endif
#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
    
typedef struct Node{
        int _key;
        struct Node *_left; 
        struct Node *_right;
}Node;

typedef struct Node* Tree;

#ifdef	__cplusplus
}
#endif

#endif	/* LIST_H */

