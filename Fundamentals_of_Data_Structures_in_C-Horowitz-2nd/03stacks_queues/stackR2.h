#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MALLOC(p,s) \
	if ( !( (p) = malloc(s) ) ) { \
		fprintf(stderr, "Insufficient memory"); \
		exit(EXIT_FAILURE); \
	}

#define CALLOC(p,n,s) \
	if ( !( (p) = calloc(n,s) ) ) { \
		fprintf(stderr, "Insufficient memory"); \
		exit(EXIT_FAILURE); \
	}

#define REALLOC(p,s) \
	if ( !( (p) = realloc(p,s) ) ) { \
		fprintf(stderr, "Insufficient memory"); \
		exit(EXIT_FAILURE); \
	}


typedef struct _element {
	int key;
	char value; /* other fields */
} element;

typedef element* stack;

extern int __capacity;
extern int __top;

/* Own Series */
#define createOwnStack(stack,defaultSize) 	createStack(stack, defaultSize); \
											stack__capacity = 1; \
											stack__top = -1;

#define isOwnEmpty(stack)	( stack__top < 0 )
#define isOwnFull(stack)	( (stack__top) >= (stack_capacity - 1) )
#define pushOwnStack(stack,item)	printf("Not Defined yet.\n");
#define popOwnStack(stack,item)		printf("Not Defined yet.\n");


/* Textbook Series */
#define top(stack)	__top
#define sz(stack)	__capacity


void createStack(stack *_stack, int defaultSize);

bool isEmpty();
bool isFull();
void stackFull(stack *_stack);
void pushStack(stack *_stack, element item);
void popStack(stack _stack, element* item);