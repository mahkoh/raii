### C++11 move pattern in C with cleanup attribute

Variables declared with the `RAII` macro are automatically freed when the function exits:

```c
void func(void)
{
    RAII(char *test) = malloc(55);
    if (!condition)
        return; /* free(test) is called */
    /* free(test) is called */
}
```

A custom destructor can be declared with the `RAIID` macro:

```c
void destruct(struct mystruct *p);
void construct(struct mystruct *p);

void func(void)
{
    RAIID(struct mystruct test, destruct);
    construct(&test);
    if (!condition)
        return; /* destruct(&test) is called */
    /* destruct(&test) is called */
}
```

`RAII` declared variables can be returned with the `raii_move` function:

```c
char *func(void)
{
    RAII(char *test) = malloc(11);
    if (!condition)
        return NULL; /* free(test) is called */
    strcpy(test, "Hello");
    return raii_move(&test); /* test isn't freed */
}
```
