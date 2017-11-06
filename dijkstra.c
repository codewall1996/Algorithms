#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printPath(int* parent,int dst){
	if(parent[dst]==-1){
		printf("%d ",dst);
		return;
	}
	printPath(parent,parent[dst]);
	printf("%d ",dst);
}
void dijkstra(int n,int a[][n],int src,int dst){
	int parent[n];
	int d[n];
	bool taken[n];
	int i;parent[src]=-1;
	for(i=0;i<n;i++){
		taken[i]=0;
		d[i]=1000000;
	}
	d[src]=0;
	for(i=0;i<n;i++){
		int mind = mindist(d,n,taken);
		taken[mind] = 1;
		int v;
		for(v=0;v<n;v++){
			if(!taken[v] && a[mind][v] && d[mind]+a[mind][v]<d[v]){	
				d[v]=d[mind]+a[mind][v];
				parent[v] = mind;
			}
		}
	}
	printf("%d\n",d[dst]);
	printPath(parent,dst);
}
int mindist(int* d,int n,bool* taken){
	int i;int mind=1000000;int minIndex=0;
	for(i=0;i<n;i++){
		if(!taken[i] && d[i]<mind){
			mind=d[i];minIndex=i;
		}
	}
	return minIndex;
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n][n];
	int i;
	for(i=0;i<n;i++){
		int j;
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int src;scanf("%d",&src);
	int dst;scanf("%d",&dst);
	dijkstra(n,a,src,dst);
}
