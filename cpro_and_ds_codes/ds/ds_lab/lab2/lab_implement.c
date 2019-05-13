#include<stdio.h>
#include<stdlib.h>


#define ll long long int
#define get(n) ll n; if(scanf("%lld", &n))
#define gets(n) char n ; if(scanf("%c", &n))
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

typedef struct linked
{
	int item;
	struct linked *link;
}linked;
//the pointer p seems to be moving with the latest, so if we add an element
//p will be that new pointer and will point to the previous
struct linked *p;
struct linked *head;
void add(int item)
{
	struct linked *q;
	q=(struct linked*) malloc(sizeof(struct linked));
	q->item=item;
	q->link=NULL;
	if(p==NULL)
	{
		p=q;
		head = p;
	}
	else
	{
		q->link=p;
		p=q;
	}
	printf("Added %d\n",item);
}



void display()
{	
	printf("Links\n");
	struct linked *q=p;
	int i=0;
	while(q != NULL)
	{
		i++;
		printf("Item %d and %d number\n",i,q->item);
		q=q->link;
	}
	printf("\n");
}

void delete(int item)
{
	if(p==NULL)
		return;
	struct linked *q1=p->link;
	//printf("%d --is \n",p->link);
	struct linked *q2=p;
	if(q2->item == item)
	{
		p=q1;
		free(q2);
	}
	else
	{
		while(q1!=NULL)
		{
			if(q1->item==item)
			{
				q2->link=q1->link;
				free(q1);
				break;
			}
			else
			{
				q1=q1->link;q2=q2->link;
			}
		}
	}
	printf("Deleted %d\n",item);
}

void delete_from_front()
{
	linked * a = head;
	head = head->link;	
	free(a);
}

void push(int key)
{
	add(key);
	return;
}

int pop()
{
	linked*q = p;
	p = p->link;
	free(q);
	return p->item;
}

int top()
{
	return p->item;
}

void enqueue(int num)
{
	add(num);
	return ;
}

int dequeue()
{
	linked * a = head;
	head = head->link;	
	int n = a->item;
	free(a);
	return n;
}

int main()
{
	// I am making a stack c;
	

	return 0;
}