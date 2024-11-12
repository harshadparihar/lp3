#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;
class NQueen
{
private:
int N;
vector<vector<int>> board;
bool isSafe(int row,int col)
{
for(int i=0;i<row;i++)
{
if(board[i][col]==1 || (col-(row-i)>=0 && board[i][col-(row-i)]==1) || (col+(row-i)<N && board[i][col+(row-i)]==1))
return false;
}
return true;
}
bool solve(int row)
{
if(row==N)
return true;
for(int col=0;col<N;col++)
{
if(isSafe(row,col))
{
board[row][col]=1;
if(solve(row+1))
return true;
board[row][col]=0;
}
}
return false;
}
public:
NQueen(int n,int frow,int fcol) : N(n),board(n,vector<int>(n,0))
{
board[frow][fcol]=1;
}
void solve()
{
if(solve(1))
printBoard();
else
cout<<"No solution";
}
void printBoard()
{
for(const auto &row:board)
{
for(int cell:row)
{
cout<<(cell?"Q ":". ");
}
cout<<endl;
}
}
};
int main()
{
int N;
cout<<"Enter the dimension of the board (nxn): ";
cin>>N;
NQueen obj(N,0,1);
obj.solve();
return 0;
}