#include<iostream>
using namespace std;
class optimal
{
	int *FRAME;
	int capacity;
	public:
		optimal(int cap)
		{
			FRAME=new int[cap];
			capacity=cap;
		}
		void insert_into_frame(int a,int data)
		{
			FRAME[a]=data;
		}
		int in_frame(int data)
		{
			int i;
			for(i=0;i<capacity;i++)
			{
				if(FRAME[i]==data)
					return 1;
			}
			return 0;
		}
		int future(int a,int arr[],int n)
		{
			int count=0,temp,index=0,i,j,p;
			p=FRAME[0];
			for(i=0;i<capacity;i++)
			{
				p=FRAME[i];
				for(j=a+1;j<n;j++)
				{
					if(p==arr[j])
					{
						count=j;
						break;
					}
				}
				if(count>temp)
				{
					temp=count;
					index=i;
				}					
			}
			return index;
		}
};
int main()
{
	int elements[20],fs,pf=0,n,i,index;
	cout<<"Enter the number of elements:";
	cin>>n;
	cout<<"Enter the frame size:";
	cin>>fs;
	optimal ob(fs);
	cout<<"Enter the elements:";
	for(i=0;i<n;i++)
	{
		cin>>elements[i];
	}
	for(i=0;i<n;i++)
	{
		if(pf<fs)
		{
			if(ob.in_frame(elements[i])!=1)
			{
				ob.insert_into_frame(i,elements[i]);
				pf++;
			}
		}
		else
		{
			if(ob.in_frame(elements[i])==1)
			{
			}
			else
			{
				index=ob.future(i,elements,n);
				ob.insert_into_frame(index,elements[i]);
				pf++;
			}
		}
	}
	cout<<"The number of page faults:"<<pf<<"\n";
	return 0;
}
