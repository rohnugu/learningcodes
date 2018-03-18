#include "array_common.h"
#include <string.h>

#define FALSE 	0
#define TRUE	1

/* name of the type is humanBeing */

typedef struct  {
	char name[10];
	int age;
	float salary;
} humanBeing;

/* name of the type is humanBeing2 */

typedef struct {
	char name[10];
	int age;
	float salary;
} humanBeing2;

int humansEqual(humanBeing person1, humanBeing person2)
{
	/* return TRUE if person1 and person2 are the same human being otherwise return FALSE */

	if (strcmp(person1.name, person2.name))
		return FALSE;
	if (person1.age != person2.age)
		return FALSE;
	if (person1.salary != person2.salary)
		return FALSE;
	return TRUE;
}

typedef struct {
	enum tagField {female, male} sex;

	union {
		int children;
		int beard;
	} u;
} sexType;

typedef struct {
	int month;
	int day;
	int year;
} date;

typedef struct {
	char name[10];
	int age;
	float salary;
	date dob;
	sexType sexInfo;
} humanBeing3;


/* Note that Horowitz uses the following version,
but it SHOULD not be used for pointer. 

typedef struct list {
	char data;
	list *link;
};

or

typedef struct {
	char data;
	list *link;
} list;

The first one makes many errors since there is no typedef name before the last semicolon.

The second one does not define the name of struct { char ... }.
So it does not make error but you can see warning messages when using pointer.

struct.c:118:13: warning: assignment from incompatible pointer type [-Wincompatible-pointer-types]
  item2.link = &item3;

Therefore, you need to name the structure explicitly as follows:

*/

typedef struct tnode *TPointer;

typedef struct tnode {
	char data;
	TPointer link;
} Tnode;

void main() {

	/* name of struct variable is person */ 	
	struct {
		char name[10];
		int age;
		float salary;
	} person;

	humanBeing person1, person2;

	if (strcmp(person1.name, person2.name))
		printf("The two people do not have the same name\n");
	else
		printf("The two people have the same name\n");

	strcpy(person1.name, person2.name);
	person1.age = person2.age;
	person1.salary = person2.salary;


	strcpy(person.name, "james");
	person.age = 10;
	person.salary = 35000;

	humanBeing3 person11, person12;
	person11.sexInfo.sex = male;
	person11.sexInfo.u.beard = FALSE;

	person12.sexInfo.sex = female;
	person12.sexInfo.u.children = 4;

	/* dynamic memory allocation for a 5 by 10 2D array of integers */
	int **myArray;
	myArray = make2dArray(5,10);
	myArray[2][4] = 6;

	/* a user-specified amount of memory and initializes the allocated memory to 0 */

	int n = 10;
	int *x;
	/* x = calloc (n, sizeof(int)); */
	CALLOC(x, n, sizeof(int));

	/* Self-Referential Structure */
	Tnode item1, item2, item3;
	item1.data = 'a';
	item2.data = 'b';
	item3.data = 'c';
	item1.link = item2.link = item3.link = NULL;

	item1.link = &item2;
	item2.link = &item3;
}