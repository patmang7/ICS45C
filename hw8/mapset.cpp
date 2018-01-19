#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

string toLower(string s)
{
	transform(s.begin(),s.end(),s.begin(),::tolower);
	return s;
}

int main()
{
	set<string> exclusion;
	ifstream in("stopwords.txt");
	for_each(istream_iterator<string>(in),istream_iterator<string>(),[&](string s){
	s=toLower(s);});
	copy(istream_iterator<string>(in),istream_iterator<string>(),inserter(exclusion,begin(exclusion)));
	ifstream in2("sample_doc.txt");
	map<string,int> M;
	for_each(istream_iterator<string>(in2),istream_iterator<string>(),
	[&](string s){s=toLower(s); if(exclusion.find(s) == end(exclusion))
	{M[s]++;}});
	ofstream out("frequency.txt");
	for_each(begin(M),end(M),[&](pair<string,int> s){out<<s.first<<": "<<s.second<<"\n";});
	return 0; 
}
