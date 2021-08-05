#include <iostream>
#include<vector>
#include<fstream>
using namespace std;


int main()
{
    vector<bool> b(156840240,0);
    ifstream in("input.txt");
	char c;
	int i=0;
	while(in.get(c))
	{
		if(c=='\n') continue;
		if(c=='A')
		b[i]=1;
		i++;
	}
	vector<int> b_rank(156840240,0);
	if(b[0]==1) b_rank[0]=1;
	for(int i=1;i<156840240;i++)
	{
	    if(b[i]==1)
	    b_rank[i]=b_rank[i-1]+1;
	    else
	    b_rank[i]=b_rank[i-1];
	}

}