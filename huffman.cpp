#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<chrono>
using namespace std;
using namespace std::chrono;
struct Node
{
char symbol;
int freq;
Node* left;
Node* right;
Node(char symbol,int freq,Node* left=nullptr,Node* right=nullptr) : symbol(symbol),freq(freq),left(left),right(right) {}
};
struct comp
{
bool operator()(Node* a,Node* b)
{
return a->freq > b->freq;
}
};
void generateHuffman(Node* root,string code,map<char,string>& huffman)
{
if(!root)
return;
if(!root->left && !root->right)
{
huffman[root->symbol]=code;
}
generateHuffman(root->left,code+'0',huffman);
generateHuffman(root->right,code+'1',huffman);
}
int main()
{
int n;
cout<<"Enter the number of characters: ";
cin>>n;
vector<char> chars(n);
vector<int> freq(n);
cout<<"\nEnter the characters:\n";
for(int i=0;i<n;i++)
cin>>chars[i];
cout<<"\nEnter the frequencies:\n";
for(int i=0;i<n;i++)
cin>>freq[i];
map<char,string> huffman;
priority_queue<Node*,vector<Node*>,comp> minheap;
for(int i=0;i<n;i++)
minheap.push(new Node(chars[i],freq[i]));
auto start = high_resolution_clock::now();
while(minheap.size()>0)
{
Node* left = minheap.top();
minheap.pop();
Node* right = minheap.top();
minheap.pop();
minheap.push(new Node('\0',left->freq+right->freq,left,right));
}
generateHuffman(minheap.top(),"",huffman);
auto stop = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop-start);
cout<<"\nHuffman codes:\n";
for(auto kv : huffman)
{
cout<<kv.first<<" -> "<<kv.second<<endl;
}
cout<<"\nEstimated time: "<<duration.count()<<" microseconds.";
return 0;
}