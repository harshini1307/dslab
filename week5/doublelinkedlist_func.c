#include <stdio.h>
#include <stdlib.h>
struct node
{
	float data;
	struct node*prev;
	struct node*next;
};
struct node*head=NULL,*tail=NULL,*cur,*t1,*t2,*temp;

void create()
{
	int n;
	printf("enter number of nodes:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cur=(struct node*)malloc(sizeof(struct node));
		printf("enter node data:");
		scanf("%f",&(cur->data));
		cur->prev=NULL;
		cur->next=NULL;
		if(head==NULL)
			head=tail=cur;
		else
		{
			tail->next=cur;
			cur->prev=tail;
			tail=cur;
		}
	}
}

void insert_at_begin()
{
	cur = (struct node*)malloc(sizeof(struct node));
	printf("Enter data to be inserted at begining:");
	scanf("%f",&(cur->data));
	cur->prev = NULL;
	cur->next = head;
	head->prev = cur;
	head = cur;
}

void insert_at_end()
{
   	cur = (struct node*)malloc(sizeof(struct node));
	printf("enter data to be inserted at end:");
	scanf("%f",&(cur->data));
   	cur->next = NULL;
   	cur->prev = tail;
	tail->next = cur;
	tail = cur;
}

void insert_at_pos()
{
	int c=1,pos;
   	cur = (struct node*)malloc(sizeof(struct node));
   	printf("Enter the values to be inserted: ");
	scanf("%f",&(cur->data));
	printf("enter position for data to be inserted:");
	scanf("%d",&pos);
	t1 = head;
	while(c<pos && t1!=NULL)
	{
		t2 = t1;
		t1 = t1->next;
		c++;
	}
	t2->next = cur;
	cur->prev = t2;
	cur->next = t1;
	t1->prev = cur;
   	printf("given node %f is inserted at %d pos\n",cur->data,pos);
}

void insert_before()
{
	float value;
	cur = (struct node*)malloc(sizeof(struct node));
   	printf("Enter the values to be inserted: ");
	scanf("%f",&(cur->data));
	printf("enter the data before which node to insert:");
	scanf("%f",&value);
	t1=head;
	while(t1 != NULL && t1->data!=value)
	{
		t2=t1;
		t1=t1->next;
	}
	t2->next=cur;
	cur->prev=t2;
	cur->next=t1;
	t1->prev=cur;
}

void insert_after()
{
	float value;
	cur = (struct node*)malloc(sizeof(struct node));
   	printf("Enter the values to be inserted: ");
	scanf("%f",&(cur->data));
	printf("enter the data after which node to insert:");
	scanf("%f",&value);
	t1=head;
	while(t1->data!=value && t1 != NULL)
		t1=t1->next;
	cur->next=t1->next;
	t1->next->prev=cur;
	t1->next=cur;
	cur->prev=t1;
}

void delete_at_begin()
{
	cur = head;
	head = cur->next;
	head->prev=NULL;
	cur->next=NULL;
	printf("Deleted element is %f \n", cur->data);
	free(cur);
}

void delete_at_end()
{
   	cur = tail;
	tail = cur->prev;
	tail->next = NULL;
	cur->prev = NULL;
	printf("Deleted element is %f \n", cur->data);
	free(cur);
}

void delete_at_pos()
{
	int pos,c=1;
	printf("enter the position of deletion:");
	scanf("%d",&pos);
	t1=head;
	while(c<pos && t1!=NULL)
	{
		t1=t1->next;
		c++;
	}
	t1->prev->next=t1->next;
	t1->next->prev=t1->prev;
	printf("Deleted data is %f",t1->data);
	t1->prev=NULL;
	t1->next=NULL;
	free(t1);
}

void delete_before()
{
	float value;
	t1 = head;
	printf("Enter data before which node has to be deleted \n");
	scanf("%f",&value);
	while(t1-> next -> data != value && t1 -> next != NULL)
	{
		t2 = t1;
		t1 = t1 -> next;
	}
	printf("Deleted element = %f",(t1 -> data));
	t2 -> next = t1 -> next;
	(t1 -> next) -> prev = t1 -> prev;
	t1 -> next =  NULL;
	t1 -> prev = NULL;
	free(t1);
}

void delete_after()
{
	float value;
	printf("Enter value after which, node has to be deleted \n");
	scanf("%f",&value);
	t1= head;
	while(t1 -> data != value && t1 != NULL) 	
	{
		t1 = t1 -> next;
	}
	t2 = t1 -> next;
	t1 -> next = t2 -> next;
	(t2 -> next) -> prev = t1;
	printf("Deleted data = %f" , t2 -> data);
	t2 -> prev = NULL;
	t2 -> next = NULL;
	free(t2);
}


void display_forward()
{
	if(head == NULL)
      		printf("\nDouble linked list is Empty\n"); 
	else
	{
		cur=head;
		printf("the elements of DLL are:\n");
    		while(cur != NULL) 
		{    
        		printf("%f<-> ", cur->data);  
        		cur = cur->next;
		}
	}
}

void display_reverse()
{
	if(head == NULL)
	{
      		printf("\nDouble linked list is Empty\n");
	}
	else
	{
		cur=tail;
		printf("the elements of DLL are:\n");
    		while(cur != NULL) 
		{    
        		printf("%f<-> ", cur->data);  
        		cur = cur->prev;
		}
	}
}

void search()
{
	int flag=0,c=0;
	float value;
	printf("Enter the value to be searched:");
	scanf("%f",&value);
	t1=head;
	while(t1!=NULL)
	{
		if(t1->data == value)
		{
			flag=1;
			break;
		}
		t1=t1->next;
		c++;
	}
	if(flag==1)
	printf("Element present in list at a position %d\n",c);
	else
	{
		printf("Element not found\n");
	}
}
void sorting()
{
	struct node *p1 , *p2,*last = NULL;
	int c,t;
	do
	{
		c=0;
		p1 = head;
		while(p1 -> next != last)
		{
			if(p1 -> data > p1->next->data)
			{
				t = p1 ->data;
				p1 -> data = p1 -> next ->data;
				p1 -> next -> data = t;	
				c = 1;			
			}
		p1 = p1-> next;	
		}
		last = p1;
	}while(c);
}

int main()
{
	int ch;
	while(1)
	{
	printf("\nprogram for double linked list\n");
	printf("1-create\n2-insert at begin\n3-insert at end\n4-insert at position\n5-insert before node");
	printf("\n6-insert after node\n7-delete at begin\n8-delete at end\n9-delete at pos\n10-delete before\n");
	printf("11-delete after\n12-display in forward\n13-display in reverse \n14-search\n15-sorting\n");
	printf("\n16-EXIT\n");
	printf("enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: create();
			break;
		case 2: insert_at_begin();
			break;
		case 3: insert_at_end();
			break;
		case 4: insert_at_pos();
			break;
		case 5: insert_before();
			break;
		case 6: insert_after();
			break;
		case 7: delete_at_begin();
			break;
		case 8: delete_at_end();
			break;
		case 9: delete_at_pos();
			break;
		case 10: delete_before();
			 break;
		case 11: delete_after();
			 break;
		case 12: display_forward();
			 break;
		case 13: display_reverse();
			 break;
		case 14: search();
			 break;
		case 15: sorting();
			break;
		case 16: exit(0);
	}
	}
}