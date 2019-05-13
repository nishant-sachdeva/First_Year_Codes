#include<stdio.h>
#include<stdlib.h>

#define ll long long int
#define get(n) ll n; if(scanf("%lld", &n))
#define gets(n) char n ; if(scanf("%c", &n))
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

typedef struct node
{
	int key, sum;
	struct node* left;
	struct node* right;	
}node;

node * root = NULL;

node * make(int val)
{
	node* temp = (node*)(malloc(sizeof(node)));
	temp->key = val;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

node* insert(node * root , int val)
{
	if(!root)
		return make(val);
	if(val < root->key)
		root->left = insert(root->left, val);
	else
		root->right = insert(root->right, val);
	return root;
}

node* find_min(node * root)
{
	node* now = root;
	while(now->left)
		now = now->left;
	return now;
}

node* find_max(node * root)
{
	node * now = root;
	while(now->right)
		now = now->right;
	return now;
}

void inorder(node * root)
{
	// left, root , right
	if(root) // i.e if the root exists, go through the following procedurel
	{
		inorder(root->left);
		printf("%d %d\n", root->key, root->sum);
		inorder(root->right);
	}
	return ;
}

void preorder(node * root)
{
	// root , left, right
	if(root)
	{
		printf("%d\n",root->key);
		preorder(root->left);
		preorder(root->right);
	}
	return;
}

void postorder(node * root)
{
	//left, right, root;
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\n",root->key);
	}
	return;
}

node* delete(node * root , int val)
{
	if(!root) 
		return root;
	else if( val < root->key)
	{
		root->left = delete(root->left, val);
	}
	else if (val > root->key)
	{
		root->right = delete(root->right, val);
	}
	else if( val == root->key)
	{
		if(!(root->left))
		{
			node* temp = root->right;
			free(root);
			return temp;
		}
		else if(!(root->right))
		{
			node* temp = root->left;
			free(root);
			return temp;
		}
		// the fact that it has come till here, is showing that both the kids exist;
		// now we will follow the appropriate procedure to delete the node;
		node * temp = find_min(root->right);
		root->key = temp->key;
		root->right = delete(root->right, root->key);
	}
	return root;
}


int find_sum(node * root)
{
	if(!root)
		return 0;
	root->sum = 0;
	root->sum = root->key + find_sum(root->left) + find_sum(root->right);
	return root->sum;
}

int main()
{
	get(n);
	int arr[1000];
	for (int i = 0; i < n; ++i)
	{
		get(ni);
		arr[i] = ni;
	}
	for (int i = 0; i < n; ++i)
	{
		root = insert(root , arr[i]);
	}
	int sum = find_sum(root);
	inorder(root);
	printf("do you want to update: enter 1 or 0 accordingly\n");
	get(a);
	if( a == 1)
	{
		get(g);
		insert(root, g);
		find_sum(root);
	}
	else
		return 0;
	return 0;
}