#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct linked
{
	int item;
	struct linked *link;
};
struct linked *p;
void add(int item)
{
	struct linked *q;
	q=(struct linked*) malloc(sizeof(struct linked));
	q->item=item;
	q->link=NULL;
	if(p==NULL)
		p=q;
	else
	{
		q->link=p;
		p=q;
	}
	printf("Added%d\n",item);
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
int main()
{
	p=NULL;
	add(10);
	add(20);
	add(30);
	display();
	add(40);
	add(50);
	display();
	delete(10);
	display();
	delete(30);
	display();
	return 0;
}
