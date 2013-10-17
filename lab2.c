#include <stdio.h>

void heapify(int *tab, int n, int k) {
	int v = tab[k];
	int j;
	while (k <= (n/2)-1) {
		j = 2*k + 1;
		if (j < n - 1 && tab[j] < tab[j+1]) {
			j += 1;
		}

		if (v >= tab[j]) {
		  break;
		}

		tab[k] = tab[j];
		k = j;
	}
	tab[k] = v;
}

void construct (int *tab, int n) {
  int i;
  for (i=(n/2)-1; i >= 0; i--) {
    heapify(tab, n, i);
  }
}

int deletemax(int *tab, int *n) {
  int first = tab[0];
  tab[0] = tab[*n-1];
  *n -= 1;
  heapify(tab, *n, 0);
  return first;
}

void heapsort (int *tab, int n) {
  int m = n;
  construct (tab, n);
  int i;
  for (i = m-1; i >= 1; i--) {
    tab[i] = deletemax(tab, &n);
  }
  n=m;
}


int main(int argc, char const *argv[])
{
	int n = 8;
	int tab[8] = {8, 7, 6, 5, 4, 3, 2, 1};
	//int tab[6] = {15,16,13,11,19,-5};
	heapsort(tab, 8);
	int i = 0;
	for (i = 0; i<n; i++)
	  printf("%d ", tab[i]);
	printf("\n");
	return 0;
}
