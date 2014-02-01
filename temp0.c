#include<stdio.h>

void swap(int a[], int x, int y) {
		int temp = a[x];
		a[x] = a[y];
		a[y] = temp;
		// printf("Swapping %d and %d\n",a[x],a[y]);
	}
 void max_heapify(int a[], int i, int n) {
		int l = 2 * i;
		int r = 2 * i + 1;
		int largest;

		// printf("Heaping for i= %d l=%d r=%d and n=%d\n",i,l,r,n);
		if (l <= n && a[l] > a[i])
			largest = l;
		else
			largest = i;
		if (r <= n && a[largest] < a[r])
			largest = r;

		if (largest != i) {
			swap(a, largest, i);
			// now mainting max heap property at the bottom heap of largest!
			max_heapify(a, largest, n);
		}
	}



void build_max_heap(int a[], int n) {
		int i;
		for (i = n / 2; i >= 1; i--) {
			max_heapify(a, i, n);
		}
	}


 void heap_sort(int a[], int n) {
		build_max_heap(a, n);
		int N = n,i;
		// printf("Swapping and replacing......\n");
		for (i = n; i >= 2; i--) {
			swap(a, i, 1);
			// print_arr(a, N);
			n--;// excuding the last element from the heap cuz its the highest
				// one in the available array
			max_heapify(a, 1, n);
		}
	}



	int main() {
		int count_p[1000];
		int bottles_order[1000],bottle_no;
		int milk_drunk = 0,m,n,i,j,x,z,cases;
		scanf("%d",&cases);
       while(cases>0)
       {
		scanf("%d %d",&n,&m);
		for (i = 0; i <= n; i++) {
			count_p[i]=0;
		}
		for (i = 0; i < m; i++) {
			scanf("%d",&x);
			count_p[x]++;
		}
       //for(i = 0;i<n;i++)
       //printf("%d ",count_p[i]);

		for (j = 0; j < n; j++) {

			scanf("%d",&bottle_no);

			for (z = 1; z <= bottle_no; z++) {
				scanf("%d",&bottles_order[z]);
			}

			heap_sort(bottles_order, bottle_no);
			
			 //printf("After Sorting : \n");
			 //for (z = 1; z <= bottle_no; z++) {
			 //printf("%d ",bottles_order[z]);
			 //}

			for (i = 0; i < count_p[j]; i++) {
				if ((bottle_no - i) > 0) {
					//printf("Drinking : %d\n",bottles_order[bottle_no-i]);
					milk_drunk = milk_drunk + bottles_order[bottle_no - i];
				} else
					break;
			}
		}

		printf("%d\n",milk_drunk);
		milk_drunk=0;
		cases--;
		}
		
		//getch();
		return 0;

	}
