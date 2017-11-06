
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// sequential search, bubble osrt, binary search
double time_elapsed(struct timespec start,struct timespec end);
void bubbleSort(int* a,int n);
int seqSearch(int* a,int n,int s);
int binarySearch(int* a,int n,int s);
int binSearch(int* a,int start,int end,int s);

int main(){
	int n;
	scanf("%d",&n);
	int a[n];int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	int search;
	scanf("%d",&search);
	struct timespec start,end,end1,end2,start1;
	clock_gettime(CLOCK_REALTIME,&start);
	int res = seqSearch(a,n,search);
	if(res!=-1)	printf("%d\n",res);
	else printf("NOT FOUND\n");
	clock_gettime(CLOCK_REALTIME,&end);
	printf("Execution time sequential search: %lf\n",time_elapsed(start,end));
	clock_gettime(CLOCK_REALTIME,&start1);
	bubbleSort(a,n);
	clock_gettime(CLOCK_REALTIME,&end1);
	printf("Execution time bubble sort: %lf\n",time_elapsed(start1,end1));
	int res1 = binarySearch(a,n,search);
	if(res1!=-1)	printf("%d\n",res1);
	else printf("NOT FOUND\n");
	clock_gettime(CLOCK_REALTIME,&end2);
	printf("Execution time binary search: %lf\n",time_elapsed(end1,end2));
}

int seqSearch(int* a,int n,int s){
	int i=0;
	for(i=0;i<n;i++){
		if(a[i] == s){
			printf("IN function %d",i);
			return i;
		}
	}
	return -1;
}
void bubbleSort(int* a,int n){
	int j;
	for(j=n-1;j>0;j--){
		int i = 0;
		for(i=0;i<j;i++){
			if(a[i+1]<a[i]){
				int temp = a[i+1];
				a[i+1] = a[i];
				a[i] = temp;
			}
		}
	}
	for(j=0;j<n;j++){
		printf("%d ",a[j]);
	}	
	printf("\n");
}
int binarySearch(int* a,int n,int s){
	return binSearch(a,0,n-1,s);
}

int binSearch(int* a,int start,int end,int s){
	if(start>end)	return -1;
	int mid = (start + end)/2;
	if(a[mid]==s)	return mid;
	if(a[mid]>s)	return binSearch(a,start,mid-1,s);
	return binSearch(a,mid+1,end,s);
}

double time_elapsed(struct timespec start,struct timespec end){
	double t;
	t = (end.tv_sec - start.tv_sec)*1000;
	t += (end.tv_nsec - start.tv_nsec) * 0.000001;
	return t;
}
