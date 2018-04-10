#include "queueR1.h"

/* try gcc -E queueR1_main.c to understand the preprocessor result */

void main() {
	element temp;
	createQueue(queue1, 5);

	/* This code works since C99 */
	temp = (element) { .key = 0, .value = '\0'};

	/* if you use top_queue1 instead of top(queue1) in the following line,
	the compiler will output an error. Why? */

	printf("Front: %d\n", front(queue1) );
	printf("Rear: %d\n", rear(queue1) );
	printf("Size: %d\n", sz(queue1) );
	for( int i=front(queue1) + 1; i <= rear(queue1); i++)
		printf("Index: %4d, Key: %4d, Value: %c\n", i, queue1[i].key, queue1[i].value);
	// for (int i=front(queue1) + 1; ; ) {
	// 	printf("Key: %d, Value: %c\n", stack1[i].key, stack1[i].value);
	// 	if( front(queue1) <= rear(queue1) ) {
	// 		if( i < rear(queue1) )
	// 			i++;
	// 		else
	// 			break;
	// 	} else {
	// 		if( front(queue) )
	// 	}
	// }

	printf("%d %d %d %d\n", isQueueFull(queue1), front(queue1), rear(queue1), sz(queue1) );

	addQueue(queue1, ((element) { .key = 0, .value = 'H'}) );
	addQueue(queue1, ((element) { .key = 1, .value = 'E'}) );
	addQueue(queue1, ((element) { .key = 2, .value = 'L'}) );
	addQueue(queue1, ((element) { .key = 3, .value = 'L'}) );
	addQueue(queue1, ((element) { .key = 4, .value = 'O'}) );

	printf("Front: %d\n", front(queue1) );
	printf("Rear: %d\n", rear(queue1) );
	printf("Size: %d\n", sz(queue1) );
	for( int i=front(queue1) + 1; i <= rear(queue1); i++)
		printf("Index: %4d, Key: %4d, Value: %c\n", i, queue1[i].key, queue1[i].value);

	// printf("Top: %d\n", top(stack1) );
	// for (int i=0;i< sz(stack1); i++) {
	// 	printf("Stack[%d]:\t(%d, %c)\n", i, stack1[i].key, stack1[i].value);
	// }

	// for (int i=0; i < sz(stack); i++) {
	// 	popStack(stack1, temp);
	// 	printf("POP:\t\t(%d, %c)\n", temp.key, temp.value);
	// }
}