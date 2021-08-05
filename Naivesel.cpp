#include <iostream>
#include<vector>
#include <chrono> 
#include<fstream>
using namespace std;
using namespace std::chrono; 


int b_sel[156840242]={0};

int main()
{
auto start = high_resolution_clock::now();
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
	
	int j=1;
	for(int i=0;i<156840240;i++)
	{
	    if(b[i]==1)
	    b_sel[j++]=i;
	}

cout <<"888484th A is at position: "<< b_sel[888484] << endl;
cout << "Size of b_rank in MBs: "<< sizeof(b_sel)/1048576 << endl;
auto stop = high_resolution_clock::now(); 
auto duration = duration_cast<microseconds>(stop - start);
cout <<"Time Taken:"<< duration.count() << endl;


}
