typedef struct Node
{
	int data;
	struct Node *ptr;
}NODE;

NODE *createNode()
{
	NODE *n = (NODE*)malloc(sizeof(NODE));
	n->data = NULL;
	n->ptr = NULL;

	return n;
}

NODE *insertfirst(NODE *head, int val)
{
	NODE *n = createNode();
	n->data = val;
	n->ptr = head;
	head = n;
	printf("\n %d is Inserted \n",val);

	return head;
}


NODE *insertlast(NODE *head, int val)
{
	NODE *tr = head;
	NODE *n = createNode();
	n->data = val;
	if(head==NULL)
	{
		head=n;
	}
	else
	{
		while(tr->ptr!=NULL)
		{
			tr=tr->ptr;

		}
		tr->ptr=n;
	}
	printf("\n %d is Inserted \n",val);
	return head;
}

void display(NODE *head)
{
	NODE *tr=head;
	if(tr==NULL)
	{
		printf("\n Link List is EMPTY");
	}
	else
	{
		while(tr!=NULL)
		{
			printf("%d_",tr->data);
			tr = tr->ptr;
		}
		printf("\n");
	}
}

NODE *insertpos(NODE *head,int pos, int val)
{
	int i=0,j=1;
	NODE *n = createNode();
	n->data = val;
    NODE *tr = head;
    if (pos == 1)
	{
        	n->ptr = head;
	        head = n;
	}
	else
	{
		while (j < (pos-1) && tr != NULL)
	        {
			tr = tr->ptr;
        		j++;
        	}
	        if(tr == NULL)
        	{
        		printf("INVALID POSITION/n");
        	}
	        else
        	{
        		n->ptr = tr->ptr;
				tr->ptr = n;
        	}
        	printf("\n %d is Inserted \n",val);
	}
	return head;
}

NODE *insertbefore(NODE *head, int eval, int nval)
{
	NODE *tr = head, *pre=NULL;
	NODE *n = createNode();
	n->data = nval;

	if(head->data == eval)
	{
		n->ptr = head;
		head = n;
	}
	else
	{
		while(tr != NULL && tr->data != eval)
		{
			pre = tr;
			tr = tr->ptr;
		}
		if(tr == NULL)
		{
			printf("\n It's value is not inserted \n");
			free(n);
		}
		else
		{
			n->ptr = tr;
			pre -> ptr = n;
		}
		printf("\n %d is Inserted \n",nval);
		return head;
	}
}

NODE *insertafter(NODE *head, int eval, int nval)
{
	NODE *tr = head, *post=NULL;
	NODE *n = createNode();
	n->data = nval;

	if(head->data == eval)
	{
		n->ptr = head;
		head = n;
	}
	else
	{
		while(tr != NULL && tr->data != eval)
		{
			tr = tr->ptr;
		}
		if(tr == NULL)
		{
			printf("\n It's value is not in Link-List \n");
			free(n);
		}
		else
		{
			n->ptr = tr->ptr ;
			tr -> ptr = n;
			printf("\n %d is Inserted \n",nval);
		}
		//printf("\n %d is Inserted \n",nval);
		return head;
	}
}

NODE *deletefirst(NODE *head)
{
	NODE *tr = head;
	int val=NULL;
	if(head==NULL)
	{
		printf("\n Link List is Already EMPTY");
	}
	else
	{
		NODE *first = head;
		head = head->ptr;
		printf("\n %d is Deleted \n",tr->data);
		free(first);
	}
	return head;
}

NODE *deletelast(NODE *head)
{
	NODE *tr = head, *last=NULL;
	if(head == NULL)
	{
		printf("\n Link List is Already EMPTY");
	}
	if(head->ptr==NULL)
	{
		head=NULL;
	}
	else
	{
		while(tr->ptr != NULL)
		{
			last = tr;
			tr = tr->ptr;
		}
		printf("\n %d is Deleted \n",tr->data);
		last->ptr=NULL;
		free(tr);
	}

	return head;
}

NODE *deleteatpos(NODE *head, int pos)
{
	int con = 1;
	NODE *tr = head, *pre = NULL;

	if(head == NULL)
	{
		printf("\n Link List is Already EMPTY");
	}
	if(pos == 1)
	{
		head = head->ptr;
		free(tr);
	}
	else
	{
		while(con < pos && tr != NULL)
		{
			pre = tr;
			tr = tr->ptr;
			con++;
		}
		if(tr == NULL)
		{
			printf("\n Value is not found \n");
		}
		else
		{
			pre -> ptr = tr -> ptr;
			printf("\n %d is Deleted \n",tr->data);
			free(tr);
		}
	}
	return head;
}

void deleteAfter(NODE *head,int val)
{
	NODE *del=NULL;
	NODE *tr=head;
	if(head==NULL)
	{
		printf("\n Link List is Already EMPTY");
	}
	else
	{
		while(tr!=NULL && tr->data!=val)
		{
			tr=tr->ptr;
		}
		if(tr==NULL)
		{
			printf("\nValue not found \n");
		}
		else if(tr->ptr==NULL)
		{
			printf("\nNode does not exist to delete \n");
		}
		else
		{
			del=tr->ptr;
			tr->ptr=del->ptr;
			printf("\n %d is Deleted \n",del->data);
			free(del);
		}
	}
}

NODE* deleteBefore(NODE* head,int val)
{
	NODE *pre=NULL,*pre2=NULL;
	NODE *tr=head;
	if(head==NULL)
	{
		printf("\n Link List is Already EMPTY");
	}
	else if(head->data==val)
	{
		printf("\nNode does not exist to delete\n");
	}
	/*else if((head->ptr)->data==val)
	{
		head=head->ptr;
		printf("\n %d is Deleted \n",tr->data);
		free(tr);
	}*/
	else
	{
		while(tr!=NULL && tr->data!=val)
		{
			pre2=pre;
			pre=tr;
			tr=tr->ptr;
		}
		if(tr==NULL)
		{
			printf("\nValue not found\n");
		}
		else if(pre==head)
		{
			head=head->ptr;
			printf("\n %d is Deleted \n",pre->data);
			free(pre);
		}
		else
		{
			pre2->ptr=tr;
			printf("\n %d is Deleted \n",pre->data);
			free(pre);
		}
	}
	return head;
}

NODE* deleteFirstOcc(NODE *head,int val)
{
	NODE *pre=NULL;
	NODE *tr=head;
	if(head==NULL)
	{
		printf("\n Link List is Already EMPTY");
	}
	if(head->data==val)
	{
		head=head->ptr;
		printf("\n First %d is Deleted \n",tr->data);
		free(tr);
	}
	else
	{
		while (tr!=NULL && tr->data!=val)
		{
			pre=tr;
			tr=tr->ptr;
		}
		if(tr==NULL)
		{
			printf("\nValue not found\n");
		}
		else
		{
			pre->ptr=tr->ptr;
			printf("\n First %d is Deleted \n",tr->data);
			free(tr);
		}
	}
	return head;
}

NODE* deleteAllOcc(NODE *head,int val)
{
	int flg=0,i=0;
	NODE *pre=NULL,*del=NULL;
	NODE *tr=head;
	if(head==NULL)
	{
		printf("\n Link List is Already EMPTY");
	}
	else
	{
		while(tr!=NULL)
		{
			if(tr->data==val)
			{
				del=tr;
				if(tr==head)
				{
					head=head->ptr;
					tr=head;
				}
				else
				{
					pre->ptr=tr->ptr;
					tr=pre->ptr;
				}
				i++;
				//free(del);
				flg=1;

			}
			else
			{
				pre=tr;
				tr=tr->ptr;
			}
		}
		if(flg==0)
			printf("\nValue not found\n");
	}
	printf("\n %d time %d is Deleted \n",i,del->data);
	free(del);
	return head;
}
