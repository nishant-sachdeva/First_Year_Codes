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
	ll key, height;
	struct node* left;
	struct node* right;	
}node;

// this declaration is global so that passing
// becomes easy;

ll max(ll a, ll  b)
{
	return a>b?a:b;
}

node * make(ll val)
{
	node* temp = (node*)(malloc(sizeof(node)));
	temp->key = val;
	temp->height = 1;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

ll height(node* root)
{
	if(!root)
		return 0;
	return root->height;
}

node * rightRotate(node* y)
{
	node* x = y->left;
	node* h = x->right;
	x->right = y;
	y->left = h;
	y->height = max(height(y->left) , height(y->right))+1;
	x->height = max(height(x->right) , height(x->left))+1;

	return x;
}

node* leftRotate(node* x)
{
	node* y = x->right;
	node* t = y->left;

	y->left = x;
	x->right = t;

	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	return y;
}

ll getBalance(node* root)
{
	if(!root)
		return 0;
	return height(root->left) - height(root->right);
}



node* insert(node*  root, ll key) 
{ 
	if (!root) 
		return(make(key)); 

	if (key < root->key) 
		root->left = insert(root->left, key); 
	else if (key > root->key) 
		root->right = insert(root->right, key); 
	else  
		return root; 

	root->height = 1 + max(height(root->left), 
						height(root->right)); 

	ll balance = getBalance(root); 

	if (balance > 1 && key < root->left->key) 
		return rightRotate(root); 

	if (balance < -1 && key > root->right->key) 
		return leftRotate(root); 

	if (balance > 1 && key > root->left->key) 
	{ 
		root->left = leftRotate(root->left); 
		return rightRotate(root); 
	} 

	if (balance < -1 && key < root->right->key) 
	{ 
		root->right = rightRotate(root->right); 
		return leftRotate(root); 
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
		printf("%lld ", root->key);
		inorder(root->right);
	}
	return ;
}

node* search(node* root, ll num)
{
	if(root == NULL)
		return root;
	if(root->key == num)
		return root;
	if(num < root->key)
		return search(root->left , num);
	return search(root->right ,num);
}


node* delete(node* root, ll key) 
{ 
    if (!root) 
        return root; 
    if ( key < root->key ) 
        root->left = delete(root->left, key); 
    else if( key > root->key ) 
        root->right = delete(root->right, key); 
    else
    { 
        if( !(root->left) || !(root->right) ) 
        { 
            node* temp = root->left ? root->left : root->right; 
            if (!temp) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else  
            {
            	*root = *temp;
            }
            free(temp); 
        } 
        else
        { 
            node* temp = find_min(root->right); 
            root->key = temp->key; 
            root->right = delete(root->right, temp->key); 
        } 
    } 
    if (!root) 
      return root; 
  
    root->height = 1 + max(height(root->left), height(root->right)); 
    ll balance = getBalance(root); 

    if (balance > 1 && getBalance(root->left) >= 0) 
        return rightRotate(root); 
  
    if (balance > 1 && getBalance(root->left) < 0) 
    { 
        root->left =  leftRotate(root->left); 
        return rightRotate(root); 
    } 
  
    if (balance < -1 && getBalance(root->right) <= 0) 
        return leftRotate(root); 
  
    if (balance < -1 && getBalance(root->right) > 0) 
    { 
        root->right = rightRotate(root->right); 
        return leftRotate(root); 
    } 
  
    return root; 
}


void merge(ll arr[] , ll left , ll mid , ll right)
{
	ll i, j, k;
	ll s1 = mid - left + 1;
	ll s2 = right - mid;
	ll l[s1] , r[s2];
	for(ll i=0 ; i<s1; i++) { l[i] = arr[left + i];}
	for(ll i=0 ; i<s2 ; i++ ) { r[i] = arr[mid +1+ i];}
	i=0 ; j=0 ; k = left;
	while(i < s1 && j < s2)
	{
		if(l[i] <= r[j])
		{
			arr[k++] = l[i++];
		}
		else
		{
			arr[k++] = r[j++];
		}
	}
	while(i < s1) { arr[k++] = l[i++];}
	while(j < s2) { arr[k++] = r[j++];}
}


void merge_sort(ll arr[], ll left , ll right)
{
	if(left < right)
	{
		ll mid = (left + right)/2;
		merge_sort(arr, left, mid);
		merge_sort(arr,  mid+1 , right);
		merge(arr ,left, mid, right);
	}
	return;
}

int main()
{
	get(n);
	get(t);
	get(k);
	ll arr[100005];
	node * root1 = NULL; // t-k wala tree
	node * root2 = NULL; // k wala tree
	for (ll i = 0; i < n; ++i)
	{
		get(ni);
		arr[i] = ni;
	}
	ll temp[100005];
	for (ll i = 0; i < t; ++i)
	{
		temp[i] = arr[i];
	}
	merge_sort(temp, 0, t-1);
	for(ll i = 0; i<t-k ; i++)
	{
		root1 =  insert(root1, temp[i]);
	}
	ll sum = 0;
	for (ll i = t-k; i < t ; ++i)
	{
		sum += temp[i];
		root2 = insert(root2, temp[i]);
	}
	// some elements in  t-k wala bst(root1) , the other k in k wala bst(root2)
	// for (ll i = 0; i < n; ++i)
	// {
	// 	printf("%lld ", arr[i] );
	// }
	// printf("\n");
	ll current_sum = sum;
	// printf("the current setup is\n");
	// printf("root2 : ");
	// inorder(root2);
	// printf("\n");
	// printf("root1 : ");
	// inorder(root1);
	// printf("\n");
	// printf("current = %lld and sum is %lld\n",current_sum, sum );
	
	for (ll i = t; i < n ; ++i)
	{
		
		// there is a guy going out, either it's there in root 2 or it's not;
		node * find = search(root2, arr[i-t]);
		// prllf("we are sending off %d  and ", arr[i-t]);
		// prllf("%d comes llo the mix\n", arr[i] );
		// so the windows are are all good;
		if(find) // maane root 2 mein hai,
		{
			ll b = find->key;
			root1 = insert(root1, arr[i]);
			node* ins  = find_max(root1);
			ll a = ins->key;
			root2 = insert(root2, ins->key);
			root1 = delete(root1, ins->key);
			// printf("we are planning to remove %d from the sum and add %d to it\n", b, a );
			current_sum -= b;
			current_sum += a;
			root2 = delete(root2, find->key);
		}
		else if(find == NULL)
		{
			// maane woh doosre tree mein hai;
			root1 = delete(root1, arr[i-t]);
			// doosre tree seh nikal gaya;
			node * root2kamin = find_min(root2);
			ll a = root2kamin->key;
			root1 = insert(root1, arr[i]);
			node * root1kamax = find_max(root1);
			ll b  = root1kamax->key;
			if((root1kamax->key) > (root2kamin->key))
			{
				root1 = insert(root1, root2kamin->key);
				root2 = delete(root2, root2kamin->key);
				root2 = insert(root2, root1kamax->key);
				root1 = delete(root1, root1kamax->key);
				// printf("we are planning to remove %d from the sum and add %d to it\n", a, b );
				current_sum += b;
				current_sum -= a;
			}
		}
		sum = sum>current_sum?sum:current_sum;		

		// printf("the current setup is\n");
		// printf("root2 : ");
		// inorder(root2);
		// printf("\n");
		// printf("root1 : ");
		// inorder(root1);
		// printf("\n");
		// printf("current = %lld and sum is %lld\n",current_sum, sum );
	}
	printf("%lld\n",sum );
	return 0;
}