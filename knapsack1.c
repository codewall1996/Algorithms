#include <stdio.h>

int main(){
	int n;scanf("%d",&n);
	int w[n+1];w[0] = 0;
	int i;
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
	}
	int v[n+1];v[0] = 0;
	for(i=1;i<=n;i++){
		scanf("%d",&v[i]);
	}
	int W;scanf("%d",&W);
	printf("%d\n",knapsack(n,w,v,W));
}
int knapsack(int n,int* w,int* v,int W){
	int a[n+1][W+1];
	int i;
	for(i=0;i<n+1;i++){
		int j;
		for(j=0;j<W+1;j++){
			if(i==0 || j==0)	
				a[i][j] = 0;
			else{
				if(j-w[i]>=0)
					a[i][j]=a[i-1][j]>(a[i-1][j-w[i]]+v[i])?a[i-1][j]:a[i][j-w[i]]+v[i];	
				else a[i][j] = a[i-1][j];	
			}	
		}
	}
	return a[n][W];
}
