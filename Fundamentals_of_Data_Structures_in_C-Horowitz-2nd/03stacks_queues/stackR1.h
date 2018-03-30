#include <stdlib.h>
#include <stdio.h>

typedef struct _element {
	int key;
	char value; /* other fields */
} element;

#define top(stack)	(top_stack)
#define sz(stack)	(sz_stack)

#define createStack(stack,maxStackSize)	element stack[maxStackSize]; \
										int top_stack = -1; \
										int sz_stack = maxStackSize;
										/* note: if you declare sz_stack as unsigned int, 
										isStackFull will do a strange behavior. Why? */

#define isStackEmpty(stack)	( top_stack < 0)

#define isStackFull(stack) ( top_stack >= sz_stack - 1)

#define pushStack(stack,item)	if( isStackFull(stack) ) { \
									printf("Stack full\n"); \
									exit(-1); \
								} else { \
									stack[++top_stack] = item; \
									printf("PUSH:\t\t(%d, %c)\n", stack[top_stack].key, stack[top_stack].value); \
								}

#define popStack(stack,item) if(!(isStackEmpty(stack))) { \
								item = stack[top_stack--]; \
							}

