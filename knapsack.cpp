#include<iostream>
#include<vector>
#include<chrono>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
using namespace std::chrono;
struct Item
{
int value,weight;
};
class Solution
{
public:
static bool comp(Item a,Item b)
{
double r1 = static_cast<double>(a.value)/static_cast<double>(a.weight);
double r2 = static_cast<double>(b.value)/static_cast<double>(b.weight);
return r1 > r2;
}
double knapsack(int W,Item arr[],int n)
{
sort(arr,arr+n,comp);
double final_val=0;
int curr_weight=0;
for(int i=0;i<n;i++)
{
if(curr_weight + arr[i].weight <=W)
{
curr_weight+=arr[i].weight;
final_val+=arr[i].value;
}
else
{
int remain = W-curr_weight;
final_val+= (arr[i].value/static_cast<double>(arr[i].weight))*static_cast<double>(remain);
break;
}
}
return final_val;
}
};
int main()
{
int n,W;
cout<<"Enter the number of items: ";
cin>>n;
cout<<"Enter the maximum weight capacity: ";
cin>>W;
Item arr[n];
cout<<"\nEnter the vallue/weight pair:\n";
for(int i=0;i<n;i++)
{
cin>>arr[i].value>>arr[i].weight;
}
Solution obj;
auto start = high_resolution_clock::now();
double ans = obj.knapsack(W,arr,n);
auto stop = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop-start);
cout<<"\nAnswer : "<<ans;
cout<<"\nEstimated time: "<<duration.count()<<" microseconds.";
return 0;
}
