#ifndef _RAII_H_
#define _RAII_H_

#include <malloc.h>

#define RAIID(name, destructor) name __attribute__((cleanup(destructor)))
#define RAII(name) RAIID(name, raii_free)

void raii_free(void *p)
{
	printf("free %li\n", (size_t)*((void **)p));
	free(*((void **)p));
}

void *raii_move(void *p)
{
	void **pp = (void **)p;
	void *t = *pp;
	*pp = NULL;
	return t;
}

#endif
