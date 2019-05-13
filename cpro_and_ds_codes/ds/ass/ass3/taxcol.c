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
	ll key;
	struct node * left;
	struct node * right;
	ll left_sum;
	ll right_sum;	
}node;

node * make(int val)
{
	node* temp = (node*) malloc(sizeof(node));
	temp->left = NULL;
	temp->right = NULL;
	temp->left_sum = 0;
	temp->right_sum = 0;
	temp->key = val;
	return temp;
}


node* insert(node* root, int num)
{
	if(!root)
	{
		return make(num);
	}
	// now this means we are in the main part of the code
	if(num < root->key)
	{
		root->left_sum += num;
		root->left = insert(root->left, num);
	}
	else if(num >= root->key)
	{
		root->right_sum += num;
		root->right = insert(root->right, num);
	}
	return root;
}

node* find_min(node * root)
{
	node* now = root;
	while(now->left)
		now = now->left;
	return now;

}

node* delete(node* root, int num)
{
	if(!root)
		return root;
	// now we know that we are in the main part of the tree;
	if(num < root->key)
	{
		root->left_sum -= num;
		root->left = delete(root->left, num);
	}
	else if(num > root->key)
	{
		root->right_sum -= num;
		root->right = delete(root->right, num);
	}
	else if(num == root->key)
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
			// find the successor, replace the current element and the right sum of the current element;
			node * temp = find_min(root->right);
			// root->right_sum -= root->key;
			root->right_sum -= temp->key;
			root->key = temp->key;
			root->right = delete(root->right, root->key);
	}
	return root;
}

ll ans = 0;
// ans will keep  track of the  last guy that satidfeie

void find(node* root, ll req)
{
	// the fact that we are here says that there is gonna be an answer
	if(!root)
		return;
	ll tax = root->left_sum/10 + (root->key + root->right_sum)/2;
	if(tax >= req)
	{
		// we  will go further right;
		ans = root->key; // ans is the latest guy that contains  hte last guy that satisfies;
		find(root->right, req  - (root->left_sum + root->key)/10 );
		return ;
	}
	else
	{
		// we go to left;
		find(root->left, req - (root->right_sum + root->key)/2  );
		return ;
	}
	return;
}

void inorder(node* root)
{
	if(root)
	{
		inorder(root->left);
		printf("%lld ",root->key );
		inorder(root->right);
	}
	return;
}

int main()
{
	get(a);
	ll num_of_a = 0;
	node* root = NULL;
	ll sum = 0;
	while(1)
	{
		if(num_of_a == a)
			break;
		char inp;
		scanf("%c", &inp);
		if(inp == 'A')
		{
			num_of_a++;
			get(req);
			// check fi max is possiblel
			if(sum/10 >= req)
			{
				// eman all geos
				ans = 1e9;
				printf("%lld\n", ans );
			}
			else if(sum/2  < req)
			{
				// maane never ahpp
				printf("Alert!\n");
			}
			else{
			// yhaan  tak aaya mean ans possible hai
				find(root, req);
				printf("%lld\n", ans );
			}
		}
		else if(inp == 'H')
		{
			get(salary);
			sum += salary;
			root = insert(root, salary);
			// inorder(root);
			// printf("\n");
		}
		else if(inp == 'F')
		{
			get(salary);
			sum -= salary;
			root = delete(root, salary);
			// inorder(root);
			// printf("\n");
		}
	}
	// you have successfully reached the end of your code, hope you had a nice time;
	return 0;
}