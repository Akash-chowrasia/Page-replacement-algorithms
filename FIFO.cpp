#include<iostream>
using namespace std;
class queue
{
	class node
	{
		public:
			int front,rear;
			int capacity;
			int *array;
	}*Q;

	public:
		queue(int cap)
		{
		    int i;
			Q=new node;
			Q->capacity=cap;
			Q->front = Q->rear = -1;
			Q->array = new int[cap];
			for(i=0;i<cap;i++)
            {
                Q->array[i]=-2;
            }
		}
		int isinqueue(int data)
		{
		    cout << "isinqueue: " << data << endl;
			int j;
			for(j=0;j<Q->capacity;j++)
			{
				if(Q->array[j]==data)
				{
					return 1;
				}
			}
			return 0;
		}
		int enqueue(int data)
		{
		    cout << "Data: " << data << endl;
		    int i;
			Q->rear = (Q->rear+1) % (Q->capacity);
			Q->array[Q->rear] = data;
			if(Q->front==-1)
				Q->front=Q->rear;
			cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n";
			cout<<"FRAME::::  ";
			for(i=0; i < Q->capacity; i++)
			{
			    cout << Q->array[i] <<"  ";
			}
			cout<<"\n*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n";
			return 0;
		}
		int dequeue()
		{
			int data;
			Q->array[Q->front]=-2;
			if(Q->front==Q->rear)
				Q->front=Q->rear=-1;
			else
				Q->front=(Q->front+1)%Q->capacity;
			return 0;
		}
};
int main()
{
	int a,i,n,pf=0,fs,elements[20];
	cout<<"Enter the number of elements:";
	cin>>n;
	cout<<"Enter the frame size:";
	cin>>fs;
	cout<<"Enter the serise of required pages:";
	for(i=0;i<n;i++)
		cin>>elements[i];

	queue ob(fs);
	for(i=0;i<n;i++)
	{
	    cout << elements[i] << " : printed" << endl;
		if(pf<fs)
		{   if (ob.isinqueue(elements[i])!=1)
            {
                pf++;
			    ob.enqueue(elements[i]);
			    cout<<"======================================================================\n";
			    cout<<"ELEMENT::"<<elements[i]<<"          PAGE FAULT::"<<pf<<"\n";
			    cout<<"======================================================================\n";
            }
            else
            {
                cout<<"======================================================================\n";
                cout<<"ELEMENT::"<<elements[i]<<"          PAGE FAULT::"<<pf<<"\n";
                cout<<"======================================================================\n";
            }
		}
		else 
		{
			if(ob.isinqueue(elements[i])!=1)
			{
				ob.dequeue();
				a=elements[i];
				ob.enqueue(a);
				pf++;
				cout<<"======================================================================\n";
				cout<<"ELEMENT::"<<elements[i]<<"          PAGE FAULT::"<<pf<<"\n";
				cout<<"======================================================================\n";
			}
            else
            {
                cout<<"======================================================================\n";
                cout<<"ELEMENT::"<<elements[i]<<"          PAGE FAULT::"<<pf<<"\n";
                cout<<"======================================================================\n";
            }
		}
	}
	cout<<"\n\n######################################################################\n";
	cout<<"Total number of page faults: "<<pf<<"\n";
	return 0;
}
