#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// Merge sort and sorting by distribution counting algo
typedef struct{
	char regNo[11];
	char name[21];
	double cgpa;
}record;

double time_elapsed(struct timespec start,struct timespec end);
//void mergeSort(record* a,int l,int r);
//void merge(record* a,int l,int m,int r);
void distributionSort(record* a,int n);

int main(){
	int n;
	scanf("%d",&n);
	record* a = malloc(sizeof(record)*n);
	record* ans = malloc(sizeof(record)*n);
	int i;
	for(i=0;i<n;i++){
		scanf("%s",a[i].regNo);
		scanf("%s",a[i].name);
		scanf("%lf",&(a[i].cgpa));
	}
/*	record* b = malloc(sizeof(record)*n);
	for(i=0;i<n;i++){
		b[i] = a[i];
	}
	struct timespec start,end,end1,end2,start1;
	clock_gettime(CLOCK_REALTIME,&start);
	mergeSort(a,0,n-1);
	for(i=0;i<n;i++){
		printf("%s %lf \n",a[i].name,a[i].cgpa);
	}*/
	struct timespec start,end,end1,end2,start1;
	clock_gettime(CLOCK_REALTIME,&end);
//	printf("Execution time merge sort: %lf\n",time_elapsed(start,end));
	distributionSort(a,n);
	for(i=0;i<n;i++){
		printf("%s %s %lf\n",a[i].regNo,a[i].name,a[i].cgpa);
	}
	clock_gettime(CLOCK_REALTIME,&end1);
	printf("Execution time heap sort: %lf\n",time_elapsed(end,end1));
}

void distributionSort(record* a,int n){
	int i;
	int b[n];
	for(i=0;i<n;i++)	b[i]=0;
	for(i=0;i<n;i++){
		int j;
		for(j=i+1;j<n;j++){
			if(a[j].cgpa<a[i].cgpa)	b[j]++;
			else b[i]++;
		}
	}
	record* c = malloc(sizeof(record)*n);
	for(i=0;i<n;i++)	c[i]=a[i];
	for(i=0;i<n;i++){
		a[b[i]] = c[i];
	}	
}

double time_elapsed(struct timespec start,struct timespec end){
	double t;
	t = (end.tv_sec - start.tv_sec)*1000;
	t += (end.tv_nsec - start.tv_nsec)*0.000001;
	return t;
}
