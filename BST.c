#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
	int d;	
	struct node* left;
	struct node* right; 
}node;

node* insertIntoBST(node* root,int t);
void BFS(node* root);

int main(){
	int n;
	scanf("%d",&n);
	int i;
	node* root;
	for(i=0;i<n;i++){
		int temp;scanf("%d",&temp);
		root = insertIntoBST(root,temp);
	}
	BFS(root);
}
node* insertIntoBST(node* root,int t){
	if(!root){
		root = malloc(sizeof(node));
		root->d = t;
		return root; 
	}
	if(t>root->d)	root->right = insertIntoBST(root->right,t);	
	else root->left = insertIntoBST(root->left,t);
	return root;
}

typedef struct nodeq{
	node* p;
	struct nodeq* next;
}nodeq;
nodeq* head;
void enqueue(node* a){
	if(!head){
		head = malloc(sizeof(nodeq));
		head->p = a;
	}
	else{
		nodeq* temp = head;
		while(temp->next){
			temp = temp->next;
		}
		temp->next = malloc(sizeof(nodeq));
		temp->next->p = a;
	}
}
node* dequeue(){
	node* ans = head->p;
	head = head->next;
	return ans;
}
bool isEmpty(){
	return (bool)head;
}

void BFS(node* root){
	if(root)	enqueue(root);
	while(isEmpty()){
		node* a = dequeue();
		printf("%d\n",a->d);
		if(a->left)	enqueue(a->left);
		if(a->right)	enqueue(a->right);
	}	
}
