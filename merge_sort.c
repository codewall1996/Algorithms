#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{
	char regNo[11];
	char name[21];
	double cgpa;
}record;

void mergeSort(record* a,int l,int r);
void merge(record* a,int l,int m,int r);
double timeElapsed(struct timespec start,struct timespec end);
void bubbleSort(record* a,int n);
int main(){
	int n;
	scanf("%d",&n);
	record* a = malloc(sizeof(record)*n);
	int i;
	for(i=0;i<n;i++){
		scanf("%s",a[i].regNo);
		scanf("%s",a[i].name);
		scanf("%lf",&(a[i].cgpa));
	}
	struct timespec start,end,end1;
	clock_gettime(CLOCK_REALTIME,&start);
	mergeSort(a,0,n-1);
	clock_gettime(CLOCK_REALTIME,&end);	
	for(i=0;i<n;i++){
		printf("%s %s %lf\n",a[i].regNo,a[i].name,a[i].cgpa);
	}
	printf("Execution time : %lf\n",timeElapsed(start,end));
	bubbleSort(a,n);
	clock_gettime(CLOCK_REALTIME,&end1);
	for(i=0;i<n;i++){
		printf("%s %s %lf\n",a[i].regNo,a[i].name,a[i].cgpa);
	}
	printf("Execution time : %lf\n",timeElapsed(end,end1));
}

void mergeSort(record* a,int l,int r){
	if(r>l){
		int m=(l+r)/2;
		mergeSort(a,l,m);
		mergeSort(a,m+1,r);
		merge(a,l,m,r);				
	}
}
void merge(record* a,int l,int m,int r){
	record* a1 = malloc(sizeof(record)*(m-l+1));
	record* a2 = malloc(sizeof(record)*(r-m));	
	int i;int p = 0;
	for(i=l;i<=m;i++){
		a1[p++] = a[i];
	}
	p = 0;
	for(i=m+1;i<=r;i++){
		a2[p++] = a[i];
	}
	int p1=0;int p2=0;
	int la=l;
	while(p1<=(m-l) && p2<(r-m)){
		a[la++] = (strcmp(a1[p1].name,a2[p2].name)>0)?a1[p1++]:a2[p2++];			
	}	
	while(p1<=(m-l))	a[la++] = a1[p1++];
	while(p2<(r-m))	a[la++] = a2[p2++];
}
double timeElapsed(struct timespec start,struct timespec end){
	double t;
	t = (end.tv_sec-start.tv_sec)*1000;
	t += (end.tv_nsec-start.tv_nsec)*0.000001;
	return t;
}
void bubbleSort(record* a,int n){
	int i=0;int j;
	for(j=n-1;j>0;j--){
		for(i=0;i<j;i++){
			if(strcmp(a[i].name,a[i+1].name)>0){
				record temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
			}
		}	
	}
}
