/*
 * Copyright (C) 2013 mahkoh.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef _RAII_H_
#define _RAII_H_

#include <malloc.h>

#define RAIID(name, destructor) name __attribute__((cleanup(destructor)))
#define RAII(name) RAIID(name, raii_free)

void raii_free(void *p)
{
#ifdef DEBUG
	printf("raii_free %li\n", (size_t)*((void **)p));
#endif
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
