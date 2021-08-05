//To compile: g++ -std=c++11 -O3 -DNDEBUG -I ~/include -L ~/lib filename.cpp -o
//filename -lsdsl -ldivsufsort -ldivsufsort64

#include <sdsl/bit_vectors.hpp>
#include <iostream>
#include<fstream>
using namespace std;
using namespace sdsl;
using namespace std::chrono;
int main()
{
auto start = high_resolution_clock::now();
 bit_vector b(156840240,0); // 156840240 chars in the given
string.
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
 rank_support_v<> b_rank(&b);
 bit_vector::select_1_type b_sel(&b);
 // cout<<b_rank(10)<<endl; // To chk if b_rank gives proper
result
 cout<<"B[34343555] is :" << b_rank(34343556)<<endl; // b[34343555]
 cout <<"888484 th A occurs at index :" << b_sel(888484) << endl;
 cout<< "size of bitvector b in MB: " << size_in_mega_bytes(b)<< endl;
 cout<< "size of succint rank in MB: " << size_in_mega_bytes(b_rank)<<
endl;
 // cout << b_sel(1) << endl; //select working properly

cout<< "size of succinct select in MB: " << size_in_mega_bytes(b_sel)<< endl;
auto stop = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop - start);
cout <<"Time Taken:"<< duration.count() << endl;
}