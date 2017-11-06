#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{
	char regNo[11];
	char name[21];
	double cgpa;
}record;

double timeElapsed(struct timespec start,struct timespec end);
void quickSort(record* a,int l,int r);
int partition(record* a,int l,int r);
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
	quickSort(a,0,n-1);
	clock_gettime(CLOCK_REALTIME,&end);	
	for(i=0;i<n;i++){
		printf("%s %s %lf\n",a[i].regNo,a[i].name,a[i].cgpa);
	}
	printf("Execution time : %lf\n",timeElapsed(start,end));
}

void quickSort(record* a,int l,int r){
	if(l<r){
		int s = partition(a,l,r);
		quickSort(a,l,s-1);
		quickSort(a,s+1,r);
	}
}
int partition(record* a,int l,int r){
	int lh=l+1;int rh=r;
	while(lh<rh){
		while(strcmp(a[lh].regNo,a[l].regNo)<0 && lh<=r)	lh++;
		while(strcmp(a[rh].regNo,a[l].regNo)>0 && rh>=0)	rh--;
		if(lh<rh){
			record temp = a[lh];
			a[lh] = a[rh];
			a[rh] = temp;
		}	
	}	
	if(strcmp(a[rh].regNo,a[l].regNo)<0){
		record temp = a[l];
		a[l] = a[rh];
		a[rh] = temp;
	}	
	return rh;
}
double timeElapsed(struct timespec start,struct timespec end){
	double t;
	t = (end.tv_sec - start.tv_sec)*1000;
	t += (end.tv_nsec - start.tv_nsec)*0.000001;
	return t;
}

