#include <stdio.h>

void floyd(int n,int a[][n]);
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
	floyd(n,a);
	for(i=0;i<n;i++){
		int j;
		for(j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}	
}

void floyd(int n,int a[][n]){
	int k;
	for(k=0;k<n;k++){
		int j;
		for(j=0;j<n;j++){
			int i;
			for(i=0;i<n;i++){
				if(i!=j && j!=k && i!=j && (a[j][k]+a[k][i])<a[j][i])
						a[j][i] = a[j][k]+a[k][i];
			}
		}
	}
}
