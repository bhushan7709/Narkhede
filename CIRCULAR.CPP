#include<iostream.h>
#include<conio.h>
class NODE
{
	public:
		NODE *next;
		int data;
};
class LIST_31
{
	private:
		NODE *start,*end;
	public:
		LIST_31();
		void ADD_FIRST(int);
		void ADD_END(int);
		int DELETE_FIRST();
		int DELETE_END();
		//void ADD_POS(int,int);
		//int DELETE_POS(int);
		void LISTALL();
};
LIST_31::LIST_31()
{
	start=end=NULL;
}
void LIST_31::ADD_FIRST(int ele)
{
    //create New Node
    NODE *NEW =new NODE();
    //Populate New Node
    NEW->data=ele;
    NEW->next=NULL;
    //set the Links
    if(start==NULL)
    {
	start=end=NEW;
	end->next=start;
    }
    else
    {
      NEW->next=start;
      start=NEW;
      end->next=start;
    }

}
void LIST_31::ADD_END(int ele)
{
	//create New Node
	NODE *NEW = new NODE();
	//Populate New node
	NEW->data=ele;
	NEW->next=NULL;
	//Set the Links
	if (start==NULL)
	{
		start=end=NEW;
		end->next=start;
	}
	else
	{
		end->next=NEW;
		end=NEW;
		end->next=start;
	}
}
int LIST_31::DELETE_FIRST()
{
	NODE *TEMP;
	int ele;
	if(start==NULL)
	{
		cout<<"List is empty"<<endl;
		return NULL;
	}
	if(start==end)
	{
	     ele=start->data;
	     TEMP=start;
	     start=end=NULL;
	}
	else
	{
	     ele=start->data;
	     TEMP=start;
	     start=start->next;
	     end->next=start;
	}
	delete TEMP;
	return ele;
}
int LIST_31::DELETE_END()
{       int ele;
	NODE *TEMP;
	if(start==NULL)
	{
		cout<<"List is empty"<<endl;
		return NULL;
	}
	if(start==end)
	{
	     ele=start->data;
	     TEMP=start;
	     start=end=NULL;
	}
	else
	{
		NODE *ptr1=start;
		NODE *ptr2=NULL;
		while(ptr1->next!=start)
		{
			ptr2=ptr1;
			ptr1=ptr1->next;
		}
		ele=ptr1->data;
		TEMP=ptr1;
		ptr2->next=start;
		ptr2=end;
	}
	delete TEMP;
	return ele;
}
/*void LIST_31::ADD_POS(int pos,int ele)
{
	//create Node
	NODE *NEW = new NODE();
	//Populate Node
	NEW->data=ele;
	NEW->next=NULL;
	//Set Links
	if(pos==1)
	{
		NEW->next=start;
		start=NEW;
	}
	else
	{
	  NODE *ptr1=start;
	  NODE *ptr2=NULL;
	  int count=1;
	  while(count<pos)
	  {
		ptr2=ptr1;
		ptr1=ptr1->next;
		count=count+1;
	  }
	  NEW->next=ptr1;
	  ptr2->next=NEW;
	}

}
int LIST_31::DELETE_POS(int pos)
{
	NODE *TEMP;
	int ele;
	if(start==NULL)
	{
		cout<<"List is Empty"<<endl;
		return NULL;
	}
	if(pos==1)
	{
	    ele=start->data;
	    TEMP=start;
	    start=start->next;
	}
	else
	{
	    NODE *ptr1=start;
	    NODE *ptr2=NULL;
	    int count=1;
	    while(count<pos)
	    {
		ptr2=ptr1;
		ptr1=ptr1->next;
		count=count+1;
	    }
	    ele= ptr1->data;
	    TEMP=ptr1;
	    ptr2->next=ptr1->next;
	}
	delete TEMP;
	return ele;
} */
void LIST_31::LISTALL()
{
	if(start==NULL)
		cout<<"List is Empty"<<endl;
	else
	{
		NODE *ptr;
		ptr=start;
		while(ptr->next!=start)
		{
		     cout<<ptr->data<<" ";
		     ptr=ptr->next;
		}
		cout<<ptr->data<<" ";
	}
}
void MENU()
{
   int ch,ele,pos;
   LIST_31 obj;
   do
   {
	cout<<"\n1.ADD_FIRST";
	cout<<"\n2.ADD_END";
	cout<<"\n3.DELETE_FIRST";
	cout<<"\n4.DELETE_END";
	/*cout<<"\n5.ADD_POS";
	cout<<"\n6.DELETE_POS";*/
	cout<<"\n5.LISTALL";
	cout<<"\n6.Exit";
	cout<<"\nEnter your choice"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1: cout<<"Enter element"<<endl;
			cin>>ele;
			obj.ADD_FIRST(ele);
			break;
		case 2: cout<<"Enter element"<<endl;
			cin>>ele;
			obj.ADD_END(ele);
			break;
		case 3: ele=obj.DELETE_FIRST();
			if(ele!=NULL)
				cout<<ele<<" is deleted"<<endl;
			break;
		case 4: ele=obj.DELETE_END();
			if(ele!=NULL)
				cout<<ele<<" is deleted"<<endl;
			break;
		/*case 5: cout<<"Enter Position"<<endl;
			cin>>pos;
			cout<<"Enter Element"<<endl;
			cin>>ele;
			obj.ADD_POS(pos,ele);
			break;
		case 6: cout<<"Enter Position"<<endl;
			cin>>pos;
			ele=obj.DELETE_POS(pos);
			if(ele!=NULL)
				cout<<ele<<" is deleted"<<endl;
			break;*/
		case 5: obj.LISTALL();
			break;
		case 6:
			return;
		default:cout<<"Invalid Case"<<endl;
	}
   }while(1);
}
void main()
{
	clrscr();
	MENU();
	getch();
}