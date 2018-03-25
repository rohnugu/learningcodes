#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN(a,b) (((a)<(b))?(a):(b))

#define REPEATION_SIZE		50000000
#define MAX_STRING_SIZE		(2 * REPEATION_SIZE + 4)
#define MAX_PATTERN_SIZE	(MAX_STRING_SIZE)

char *(strstr_Plauger)(const char *s1, const char *s2);

int pmatch();
void fail();

int  failure[MAX_PATTERN_SIZE];
char string[MAX_STRING_SIZE];
char pat[MAX_PATTERN_SIZE];

int main(int argc, char* argv[]) {
	/* strcpy(string, "ababbaabaa"); */
	int n = REPEATION_SIZE;
	if(argc == 2) {
		n = MIN(n, atoi(argv[1]));
	}

	printf("Size of string: %d\n", 2*n + 3);

	for(int i=0; i<n; i++) {
		string[2*i] = 'a';
		string[2*i + 1] = 'b';
	}
	string[2*n+0] = 'a';
	string[2*n+1] = 'a';
	string[2*n+2] = 'b';
	string[2*n+3] = '\0';
	strcpy(pat, "aab");

	clock_t start, end;
	double duration;

	start = clock();
	char * sResult = strstr(string, pat);
	end = clock();
	duration = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	printf("The C Library Implementation:\t %p, %d\n", sResult, (int)(sResult - string));
	printf("Duration: %f\n", duration);

	sResult = NULL;
	start = clock();
	sResult = strstr_Plauger(string, pat);
	end = clock();
	duration = ((double) (end - start)) / CLOCKS_PER_SEC;

	printf("P. J. Plauger's Implementation:\t %p, %d\n", sResult, (int)(sResult - string));
	printf("Duration: %f\n", duration);

	start = clock();
	fail(pat);
	int pResult = pmatch(string, pat);
	end = clock();
	duration = ((double) (end - start)) / CLOCKS_PER_SEC;

	printf("KMP Algorithm in the Textbook:\t %p, %d\n", &string[pResult], pResult);
	printf("Duration: %f\n", duration);

}

/* strstr function implemented by P. J. Plauger.
   P. J. Plauger, The Standard C Library, Prentice Hall, 1992.
   Figure 14.19: strstr.c, page 405.
*/
char *(strstr_Plauger)(const char *s1, const char *s2) {
	/* find first occurence of s2[] in s1[] */
	if(*s2 == '\0')
		return ((char *)s1);
	for(; (s1 = strchr(s1, *s2)) != NULL; ++s1) {
		/* match rest of prefix */
		const char *sc1, *sc2;

		for(sc1 = s1, sc2 = s2; ; )
			if (*++sc2 == '\0')
				return ((char *)s1);
			else if (*++sc1 != *sc2)
				break;
	}
	return (NULL);
}

int pmatch(char *string, char *pat) {
	 /* Knuth, Morris, Pratt string matching algorithm */
	int i=0, j=0;
	int lenS = strlen(string);
	int lenP = strlen(pat);

	while( (i < lenS) && (j < lenP) ) {
		if(string[i] == pat[j]) {
			i++; j++;
		} else if( j == 0 )
			i++;
		  else
			j = failure[j-1] + 1;
	}

	return ( (j == lenP) ? (i - lenP) : -1);
}

void fail(char *pat) {
	/* compute the pattern's failure function */
	int n = strlen(pat);
	failure[0] = -1;

	for (int j = 1; j < n; j++) {
		int i = failure[j-1];
		while ( (pat[j] != pat[i+1]) && (i >= 0) )
			i = failure[i];
		if (pat[j] == pat[i+1])
			failure[j] = i+1;
		else
			failure[j] = -1;
	}
}
