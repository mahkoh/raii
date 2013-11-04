#include <malloc.h>
#include <string.h>

#define DEBUG
#include "raii.h"

int fill_string(char *c)
{
	strcpy(c, "Hello World\n");
	//return 0;
	return 1;
}

char *example(void)
{
	RAII(char *test) = malloc(128);
	printf("malloc %li\n", (size_t)test);

	if (test == NULL)
		return NULL;

	if (!fill_string(test))
		return NULL;

	return raii_move(&test);
}

int main(void)
{
	//char *c = example();
	RAII(char *c) = example();
	if (c)
		printf("%s", c);
}
