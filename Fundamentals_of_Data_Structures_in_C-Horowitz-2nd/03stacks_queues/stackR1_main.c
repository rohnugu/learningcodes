#include "stackR1.h"

/* try gcc -E stackR1_main.c to understand the preprocessor result */

void main() {
	element temp;
	createStack(stack1, 5);

	/* This code works since C99 */
	temp = (element) { .key = 0, .value = '\0'};

	/* if you use top_stack1 instead of top(stack1) in the following line,
	the compiler will output an error. Why? */

	printf("Top: %d\n", top(stack1) );
	printf("Size: %d\n", sz(stack1) );
	for (int i=0;i< top(stack1); i++) {
		printf("Key: %d, Value: %c\n", stack1[i].key, stack1[i].value);
	}

	printf("%d %d %d\n", isStackFull(stack1), top(stack1), sz(stack1) -1 );

	pushStack(stack1, ((element) { .key = 0, .value = 'H'}) );
	pushStack(stack1, ((element) { .key = 1, .value = 'E'}) );
	pushStack(stack1, ((element) { .key = 2, .value = 'L'}) );
	pushStack(stack1, ((element) { .key = 3, .value = 'L'}) );
	pushStack(stack1, ((element) { .key = 4, .value = 'O'}) );

	printf("Top: %d\n", top(stack1) );
	for (int i=0;i< sz(stack1); i++) {
		printf("Stack[%d]:\t(%d, %c)\n", i, stack1[i].key, stack1[i].value);
	}

	for (int i=0; i < sz(stack); i++) {
		popStack(stack1, temp);
		printf("POP:\t\t(%d, %c)\n", temp.key, temp.value);
	}
}