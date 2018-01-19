#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>
#include "SetList.h"
#include "MapArray.h"

using namespace std;

string toLower(string s)
{
	transform(s.begin(),s.end(),s.begin(),::tolower);
	return s;
}

int main()
{
	SetList<string> exclusion;
	ifstream in("stopwords.txt");
	for_each(istream_iterator<string>(in),istream_iterator<string>(),[&](string s){
	s=toLower(s);});
	for_each(istream_iterator<string>(in),istream_iterator<string>(),[&](string s){exclusion.insert(s);});
	ifstream in2("sample_doc.txt");
	MapArray<string,int> M;
	for_each(istream_iterator<string>(in2),istream_iterator<string>(),
	[&](string s)
	{s=toLower(s);
		if(exclusion.find(s) == exclusion.end())
		{
			if(M.find(s) == M.end())
			{
				pair<string,int> e = pair<string,int>(s,1);
				M.insert(e);
			}
			else
				M[s]++;
		}
	});
	ofstream out("frequency.txt");
	for_each(M.begin(),M.end(),[&](pair<string,int> p){out<<p.first<<": "<<p.second<<"\n";});
	return 0; 
}
