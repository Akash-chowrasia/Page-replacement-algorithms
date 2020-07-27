#include<iostream>
using namespace std;
class LRU
{
	int *FRAME;
	int capacity;
	public:
		LRU(int cap)
		{
			FRAME=new int[cap];
			capacity=cap;
			int i;
			for(i=0;i<cap;i++)
            {
                FRAME[i]=-2;
            }
		}
		void insert_into_frame(int i,int data)
		{
			FRAME[i]=data;
			int j;
			cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n";
			cout<<"FRAME:::: ";
			for(j=0;j<capacity;j++)
            {
                cout<<FRAME[j]<<"    ";
            }
            cout<<"\n*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n";
		}
		int inframe(int data)
		{
			int i;
			for(i=0;i<capacity;i++)
			{
				if(FRAME[i]==data)
					return 1;
			}
			return 0;
		}
		int past(int a,int arr[])
		{
			int i,item,j;
			for(i=a-1;i>=0;i--)
			{
				for(j=0;j<capacity;j++)
				{
					if(arr[i]==FRAME[j])
					{
						item=j;
					}	
				}
			}
			return item;
		}
};
int main()
{
	int elements[20],i,pf=0,n,fs,index;
	cout<<"Enter the number of elements: ";
	cin>>n;
	cout<<"Enter frame size: ";
	cin>>fs;
	cout<<"Enter the elements: ";
	for(i=0;i<n;i++)
	{
		cin>>elements[i];
	}
	LRU ob(fs);
	for(i=0;i<n;i++)
	{
		if(pf<fs)
		{
			if(ob.inframe(elements[i])!=1)
			{
				ob.insert_into_frame(i,elements[i]);
				pf++;
				cout<<"======================================================================\n";
				cout<<"ELEMENT::"<<elements[i]<<"          PAGE FAULT::"<<pf;
				cout<<"\n======================================================================\n";
			}
            else
            {
                cout<<"======================================================================\n";
                cout<<"ELEMENT::"<<elements[i]<<"          PAGE FAULT::"<<pf<<endl;
                cout<<"======================================================================\n";
            }
		}
		else
		{
			if(ob.inframe(elements[i]!=1))
			{
				index=ob.past(i,elements);
				ob.insert_into_frame(index,elements[i]);
				pf++;
				cout<<"======================================================================\n";
				cout<<"ELEMENT::"<<elements[i]<<"          PAGE FAULT::"<<pf<<endl;
				cout<<"======================================================================\n";
			}
            else
            {
                cout<<"======================================================================\n";
                cout<<"ELEMENT::"<<elements[i]<<"          PAGE FAULT::"<<pf<<endl;
                cout<<"======================================================================\n";
            }
		}
	}
	cout<<"\n\n######################################################################\n";
	cout<<"The total page fault: "<<pf<<"\n";
	return 0;
}
