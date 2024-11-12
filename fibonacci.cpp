#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;
class Fibonnaci
{
	public:
	void non_recursive(int n)
	{
		int n1=0,n2=1,n3;
		cout<<"0,1";
		for(int i=2;i<n;i++)
		{
			n3 = n2+n1;
			cout<<","<<n3;
			n1=n2;
			n2=n3;
		}
	}
	int n1=0,n2=1;
	void recursive(int n)
	{
		int n3;
		if(n>0)
		{
			n3=n2+n1;
			cout<<","<<n3;
			n1=n2;
			n2=n3;
			recursive(n-1);
		}
	}
};
int main()
{
	int n;
	cout<<"Enter the number of elements: ";
	cin>>n;
	Fibonnaci obj;
	cout<<"\nThe fibonnaci series using recursive method is:\n";
	auto start = high_resolution_clock::now();
	cout<<"0,1";
	obj.recursive(n-2);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop-start);
	cout<<"\nEstimated times: "<<duration.count()<<" microseconds.";
	cout<<"\nThe fibonnaci series using non-recursive method is:\n";
	obj.non_recursive(n);
	return 0;
}
