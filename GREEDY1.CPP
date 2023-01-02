Assignment No:- 
Assignment Name:- Implementation of program for solution of Greedy Knapsack.
Name:- YOGESH PRALHAD PATIL.
Roll No:- 104.

#include<iostream.h>
#include<conio.h>

//Solution for Greedy knapsack
class GREEDY
{
	private:
		int i,n;
		float M,Cu,*P,*W,*X,*I,*R,sum;
	public:
		GREEDY(float size, int par); //size=Maximum capacity
		void READ();  //to read data from user
		void SORT();
		void KNAPSACK();
		void DISPLAY();
};
GREEDY :: GREEDY(float size,int par)
{
	M=size;
	n=par;
	sum = 0;
	I=new float[n+1]; //for items /products
	P=new float[n+1];//for profit
	W=new float[n+1];//for weight
	X=new float[n+1];//for soln vector
	R=new float[n+1];//for Ratio p/w
}
void GREEDY :: READ()
{
	for(i=1; i<=n; i++)      //profit data read by user
	{
		cout<<"Enter weight of product: ";
		cin>>W[i];
		cout<<"Enter Profit of Product: ";
		cin>>P[i];	                      
	}
}
void GREEDY :: SORT()  //sort according to P/W in form ratio and sort that ratio
{
	float temp;
	for(i=1;i<=n;i++)
	{
		R[i]=P[i]/W[i]; //  p/w ratio stored in a R array
	}
	// sorting ratio of p/w
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(R[j] < R[j+1])
			{
				temp=R[j];
				R[j]=R[j+1];
				R[j+1]=temp;

				temp=P[j];
				P[j]=P[j+1];
				P[j+1]=temp;

				temp=W[j];
				W[j]=W[j+1];
				W[j+1]=temp;
			}
		}
	}
}
void GREEDY :: KNAPSACK()
{
	X=0;
	Cu = M;   //remaining Knapsack capacity
	for(i=1;i<=n;i++)
	{
		if(W[i]> Cu)
			break;
		else
		{
			X[i] =1;
			Cu= Cu-W[i];
		}
	}
	if(i<=n)
	{
		X[i]= Cu/W[i];
	}
	for(i=1;i<=n;i++)
	{
		sum= sum + X[i]*P[i];
	}
}
void GREEDY :: DISPLAY()
{
	for(i=1;i<=n;i++)
	{
		cout<<" Weight "<<W[i]<<" "<<"Profit "<<P[i]<<" "<<" Ratio "<<R[i]<<" ";
		cout<<endl;
	}
	//Maximum profit of products
	cout<<"Max Profit is: "<<sum<<endl;
	for(i=1;i<=n;i++)
		cout<<"solution vactor is : "<<X[i]<<" "<<endl;  //solution vector
}
void main()
{
	clrscr();
	int n;
	float size;
	cout<<"Enter Capacity of Knapsack Bag: ";
	cin>>size;
	cout<<"Enter No. of Products: ";
	cin>>n;
	GREEDY gk(size,n);
	gk.READ();
	gk.SORT();
	gk.KNAPSACK();
	gk.DISPLAY();
	getch();
}
