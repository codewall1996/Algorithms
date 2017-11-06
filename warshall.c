#include <stdio.h>

void warshall(int n,int a[][n]);
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
	warshall(n,a);
	for(i=0;i<n;i++){
		int j;
		for(j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}	
}

void warshall(int n,int a[][n]){
	int k;
	for(k=0;k<n;k++){
		int j;
		for(j=0;j<n;j++){
			int i;
			for(i=0;i<n;i++){
				if(a[j][k]==1 && a[k][i]==1)
						a[j][i] = 1;
			}
		}
	}
}
