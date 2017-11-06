#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Sequential search, selection sort, binary search
typedef struct{
	char regNo[11];
	char name[21];
	double cgpa;
}record;

double time_elapsed(struct timespec start,struct timespec end);
void sequentialSearch(record* a,int n,char* search);
void selectionSort(record* a,int n);
int binarySearch(record* a,int l,int r,char* search);

int main(){
	int n;
	scanf("%d",&n);
	record* a = malloc(sizeof(record)*n);
	char search[21];
	int i;
	for(i=0;i<n;i++){
		scanf("%s",a[i].regNo);
		scanf("%s",a[i].name);
		scanf("%lf",&(a[i].cgpa));
	}
	scanf("%s",search);	

	struct timespec start,end,end1,end2;
	clock_gettime(CLOCK_REALTIME,&start);
	sequentialSearch(a,n,search);
	clock_gettime(CLOCK_REALTIME,&end);
	printf("Execution time sequential search: %lf\n",time_elapsed(start,end));
	selectionSort(a,n);
	for(i=0;i<n;i++){
		printf("%s %s %lf\n",a[i].regNo,a[i].name,a[i].cgpa);
	}
	printf("Execution time selection search: %lf\n",time_elapsed(end,end1));
	clock_gettime(CLOCK_REALTIME,&end1);
	int res = binarySearch(a,0,n-1,search);
	if(res==-1)	printf("NOT FOUND");
	else{
		printf("%s %s %lf\n",a[res].regNo,a[res].name,a[res].cgpa);
	}
	clock_gettime(CLOCK_REALTIME,&end2);
	printf("Execution time binarySearch: %lf\n",time_elapsed(end1,end2));

}
void selectionSort(record* a,int n){
	int j = 0;
	int i;
	for(j=n-1;j>0;j--){
		int index = 0;
		int i;
		for(i=1;i<=j;i++){
			if(strcmp(a[index].name,a[i].name)<0){
				index = i;
			//	printf("max %s %s\n",max,a[0].name);
			}
		}
//		printf("%s bef\n",a[0].name);
		record temp = a[j];
		a[j] = a[index]; 
		a[index] = temp;
		//printf("%d %s %s %saftr\n",index,a[j].name,a[index].name,a[0].name);
	}
//	int i;
}
void sequentialSearch(record* a,int n,char* search){
	int i;
	for(i=0;i<n;i++){
		if(!strcmp(search,a[i].name)){
			printf("%s ",a[i].regNo);
			printf("%s ",a[i].name);
			printf("%lf\n",a[i].cgpa);
			break;
		}	
	}
	if(i==n)
		printf("NOT FOUND\n");
}

int binarySearch(record* a,int l,int r,char* search){
	if(l>r)	return -1;
	int m = (l+r)/2;
	if(strcmp(a[m].name,search)==0)	return m;
	if(strcmp(a[m].name,search)>0)	return binarySearch(a,l,m-1,search);
	return binarySearch(a,m+1,r,search);	
}

double time_elapsed(struct timespec start,struct timespec end){
	double t;
	t = (end.tv_sec - start.tv_sec)*1000;
	t += (end.tv_nsec - start.tv_nsec) * 0.000001;
	return t;
}
