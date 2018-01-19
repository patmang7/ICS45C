#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	ifstream in("rand_numbers.txt");
	vector<int> v;
	copy(istream_iterator<int>(in),istream_iterator<int>(),back_inserter(v));
	sort(begin(v),end(v),[&](int s,int p){return s < p;});
	ofstream odd("odd.txt");
	ofstream even("even.txt");
	for_each(begin(v),end(v),
	[&](int s){if(s%2==0){even<<s<<endl;}else{odd<<s<<endl;}});
	return 0;

}
