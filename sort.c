#include <stdio.h>
#include <time.h>
#include <stdbool.h>
//heap sort, insertion sort
double time_elapsed(struct timespec start,struct timespec end);
void insertionSort(int* a,int n);
void heapSort(int* a,int n);
void heapify(int* a,int n);
void adjustHeap(int* a,int n);

int main(){
	int n;
	scanf("%d",&n);
	int a[n];int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int b[n+1];b[0]=0;
	for(i=1;i<=n;i++){
		b[i] = a[i-1];
	}
	struct timespec start,end,end1,end2,start1;
	clock_gettime(CLOCK_REALTIME,&start);
	insertionSort(a,n);
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	clock_gettime(CLOCK_REALTIME,&end);
	printf("Execution time insertion sort: %lf\n",time_elapsed(start,end));
	heapSort(b,n);
	for(i=1;i<=n;i++){
		printf("%d ",b[i]);
	}
	printf("\n");
	clock_gettime(CLOCK_REALTIME,&end1);
	printf("Execution time heap sort: %lf\n",time_elapsed(end,end1));
}

void insertionSort(int* a,int n){
	int i;
	for(i=1;i<n;i++){
		int j = i-1;int curr = a[i];
		while(a[j]>curr && j>=0){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = curr;
	}
}

void heapSort(int* a,int n){
	heapify(a,n);
	int i;
	for(i=n;i>=1;i--){
		int temp = a[1];
		a[1] = a[i];
		a[i] = temp;
//		printf("a[i] a[1]: %d %d\n",a[i],a[1]);int j;
		adjustHeap(a,n-(n-i+1));
	}
}
void adjustHeap(int* a,int n){
	int k=1;int v=a[k];
	bool notHeap=1;
	while(2*k<=n && notHeap){
		int j=2*k;
		if(j+1<=n)	j=a[2*k+1]>a[2*k]?2*k+1:2*k;
		if(a[j]>v){
			a[k] = a[j];
			k = j;
		}
		else notHeap=0;
	}
	a[k] = v;
}
void heapify(int* a,int n){
	int i;
	for(i=n/2;i>0;i--){
		int k=i;int v=a[k];
		bool notHeap = 1;
		while(2*k<=n && notHeap){
			int j = 2*k;
			if(j+1<=n){
				j = a[2*k+1]>a[2*k]?2*k+1:2*k;				
			}
			if(a[j]>v){
				a[k] = a[j];
				k = j;			
			}
			else notHeap=0;			
		}
		a[k] = v;
	}
}

double time_elapsed(struct timespec start,struct timespec end){
	double t;
	t = (end.tv_sec - start.tv_sec)*1000;
	t += (end.tv_nsec - start.tv_nsec)*0.000001;
	return t;
}

