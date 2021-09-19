/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

// Implementation of the Dynamic range min query which takes log(n) time for updates.

#include<bits/stdc++.h>
using namespace std;

 int min_query(int low, int high,int i, int node_low, int node_high,vector<int> &tree)  // get minimum between [low,high] in log(n) time.
{

    if(high< node_low || low>node_high) return INT_MAX;
    
    if(node_low>=low && node_high<=high)
    return tree[i];
    
    int mid = (node_low+node_high)/2;
    return min( min_query(low,high, 2*i+1, node_low,mid,tree) ,
           min_query(low,high, 2*i+2, mid+1, node_high, tree));
}

void update(vector<int> &tree,int index, int val, int n) // update in log(n) time
{
    int i= n-2+index;

    tree[i]= val;
    while(i>=1)
    {
        i=(i-1)/2;
        tree[i]= min(tree[2*i +1],tree[2*i +2]);
    }
}

int main()
{
     int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    while(__builtin_popcount(n)!=1)
    {
        a.push_back(0);
        n++;
    }
    vector<int> tree(2*n-1);

    for(int i=0;i<n;i++)
    tree[i+(n-1)]= a[i];
    
    for(int i= n-2;i>=0;i--)
    tree[i]= min(tree[2*i +1],tree[2*i +2]);
    

    while(q--)   // q queries.
    {
        int op;
        cin>>op;
        if(op==1)  // Op1 for update.
		{
		int k,u;   // Change the value at index 'k' to 'u'.
		cin >> k >> u;
        update(tree,k,u,n);
		}
        else
        {
		int low,high;
		cin>> low>>high; // Get min in the range low,high
        int ans= min_query(low-1,high-1,0,0,n-1,tree);
        cout << ans << "  " << endl;
        }
    
    }
}
