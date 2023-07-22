#include<bits/stdc++.h>
using namespace std;
#define N 9
bool isSafe(vector<vector<int>>&matrix,int val,int col,int row)
{
    for(int i = 0;i<N;i++)
    {
        if(matrix[row][i] == val)
        {
            return false;
        }
        if(matrix[i][col] == val)
        {
            return false;
        }
        if(matrix[3*(row/3)+i/3][3*(col/3)+i%3]==val)
        {
            return false;
        }
    }
    return true;
}
bool Generator(vector<vector<int>>&matrix)
{
    for(int row = 0;row<N;row++)
    {
        for(int col = 0;col<N;col++)
        {
            if(matrix[row][col] == 0)
            {
                for(int val = 1;val<=N;val++)
                {
                    if(isSafe(matrix,val,col,row))
                    {
                        matrix[row][col] = val;
                        if(Generator(matrix))
                        {
                            return true;
                        }
                        matrix[row][col] = 0;
                    }
                }   
                return false;
            }
        }
    }
    return true;

}
bool solver(vector<vector<int>>&matrix)
{
    for(int row = 0;row<N;row++)
    {
        for(int col = 0;col<N;col++)
        {
            if(matrix[row][col] == 0)
            {
                for(int val = 1;val<=N;val++)
                {
                    if(isSafe(matrix,val,col,row))
                    {
                        matrix[row][col] = val;
                        if(solver(matrix))
                        {
                            return true;
                        }
                        matrix[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void print(vector<vector<int>>matrix)
{
    for(int j =0 ;j<N-4;j++)
    {
        cout<<"-----";
    }
    cout<<endl;
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<N;j++)
        {
            if(j == 0||j%3 == 0)
            {
                cout<<"| ";
            }
            cout<<matrix[i][j]<<" ";
            if(j==N-1)
            {
                cout<<"|";
            }
        }
        cout<<endl;
        for(int j =0 ;(i+1)%3==0&&j<N-3;j++)
        {
            cout<<"----";
        }
        cout<<endl;
    }
}
int main(){
    vector<vector<int>>matrix(N,vector<int>(N,0));
    Generator(matrix);
    cout<<"ENter the no. of clues you want to solve suduko with"<<endl;
    int a;
    cin>>a;
    int remaining_element = N*N - a;
    while(remaining_element)
    {
        int row = rand()%N;
        int col = rand()%N;
        if(matrix[row][col]!=0)
        {
            matrix[row][col]=0;
            remaining_element--;
        }
    }
    print(matrix);
    cout<<"Press 's' to solve suduko"<<endl;
    char s;
    cin>>s;
    if(s =='s'||s=='S')
    {
        if(solver(matrix))
        {
            print(matrix);
        }
        else
        {
            cout<<"This soduku can't be solved"<<endl;    
        }
    }
    return 0;
}