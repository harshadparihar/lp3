#include<iostream>
#include<chrono>
#include<vector>
#include<queue>
using namespace std;
using namespace std::chrono;
int knapsackDP(int W,const vector<int>& values,const vector<int>& weights)
{
vector<int> dp(W + 1,0);
for(int i=0;i<values.size();i++)
{
for(int w=W;w>=weights[i];--w)
{
dp[w] = max(dp[w],values[i]+dp[w-weights[i]]);
}
}
return dp[W];
}
struct Node
{
int level,profit,weight;
double bound;
bool operator<(const Node &other) const
{
return bound < other.bound;
}
};
double calculateBound(int level,int profit,int weight,int W,const vector<int>& values,const vector<int>& weights)
{
double bound = profit;
int n=values.size(),totweight=weight;
while(level<n && totweight+weights[level]<=W)
{
totweight+=weights[level];
bound+=values[level++];
}
if(level<n)
bound+=(W-totweight)*(static_cast<double>(values[level])/static_cast<double>(weights[level]));
return bound;
}
int knapsackBB(int W,const vector<int>& values,const vector<int>& weights)
{
int max_profit=0;
priority_queue<Node> pq;
pq.push({-1,0,0,calculateBound(0,0,0,W,values,weights)});
while(!pq.empty())
{
Node u = pq.top();
pq.pop();
if(u.level == int(values.size())-1)
continue;
Node v = {u.level+1,u.profit+values[u.level+1],u.weight+weights[u.level+1]};
if(v.weight<=W && v.profit>max_profit)
{
max_profit=v.profit;
}
v.bound = calculateBound(v.level+1,v.profit,v.weight,W,values,weights);
if(v.bound>max_profit)
pq.push(v);
v.profit=u.profit;
v.weight=u.weight;
v.bound = calculateBound(v.level+1,v.profit,v.weight,W,values,weights);
if(v.bound>max_profit)
pq.push(v);
}
return max_profit;
}
int main()
{
int n,W;
cout<<"Enter the number of items: ";
cin>>n;
cout<<"Enter the maximum weight capacity: ";
cin>>W;
vector<int> values(n);
vector<int> weights(n);
cout<<"Enter the value/weight pair:\n";
for(int i=0;i<n;i++)
cin>>values[i]>>weights[i];
auto start = high_resolution_clock::now();
int ansDP = knapsackDP(W,values,weights);
auto stop = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop-start);
cout<<"\nSolution using Dynamic Programming: "<<ansDP<<endl;
cout<<"Estimated time: "<<duration.count()<<" microseconds."<<endl;

auto st = high_resolution_clock::now();
int ansBB = knapsackBB(W,values,weights);
auto end = high_resolution_clock::now();
auto dur = duration_cast<microseconds>(end-st);
cout<<"\nSolution using Branch N Bound: "<<ansBB<<endl;
cout<<"Estimated time: "<<dur.count()<<" microseconds."<<endl;
return 0;
}