#include <stdlib.h>

typedef struct
{
	char* arr;
	size_t len;
	size_t size;
	int (*cmp) (const void *, const void *);
} qsort_t;

static char *element(qsort_t *qs, size_t i)
{
	return &qs->arr[qs->size * i];
}

static void swap(qsort_t *qs, size_t A, size_t B)
{
	char *a = element(qs, A);
	char *b = element(qs, B);
	size_t i = 0;
	char tmp;

	for( ; i < qs->size ; ++i )
	{
		tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	}
}

void qsort(void *base, size_t nmemb, size_t size, int (*compar) (const void *, const void *))
{
	qsort_t qs;

	qs.arr = base;
	qs.len = nmemb;
	qs.size = size;
	qs.cmp = compar;
}
