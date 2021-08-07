#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

void bubbleSortTriangle(triangle* tr, double* areas,int n){
	int i,j;
	double tmp;
	triangle tmptr;

	for (j= 0; i < n; i++)
	{
		for (j = 0; j < n-1; j++)
		{
			if (areas[j]>areas[j+1])
			{
				tmp = areas[j];
				areas[j] = areas[j+1];
				areas[j+1] = tmp;

				tmptr = tr[j];
				tr[j] = tr[j+1];
				tr[j+1] = tmptr;
			}
		}
	}
}

void sort_by_area(triangle* tr, int n) {
    double *areas;
    int i=0;
    int p;
    areas = calloc(n, sizeof(double));
    for(i=0;i<n;i++){
        p=(tr[i].a+tr[i].b+tr[i].c)/2;
        areas[i] = sqrt(p*(p-tr[i].a)*(p-tr[i].b)*(p-tr[i].c));
    }
	bubbleSortTriangle(tr, areas, n);
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = (triangle*)malloc(n * sizeof(triangle));

	//for (int i = 0; i < n; i++) {
	// 	scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	// }
	// sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}