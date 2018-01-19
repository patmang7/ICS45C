#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template
	<typename T,typename V>
class MapArray
{
	int sz = 0;
public:	
	typedef pair<T,V> m_pair;
	struct iterator
	{
		typedef random_access_iterator_tag iterator_category;
		typedef iterator self_type;
		typedef m_pair value_type;
		typedef m_pair& reference;
		typedef m_pair* pointer;
		typedef ptrdiff_t difference_type;
		private:
			pointer ibuf;
		public:
			iterator(pointer ptr)
				:ibuf(ptr)
			{
			}
			self_type operator++()
			{
				++ibuf;
				return *this;
			}
			self_type operator++(int postfix)
			{
				self_type cpy = *this;
				++ibuf;
				return cpy;
			}
			reference operator*()
			{
				return *ibuf;
			}
			pointer operator->()
			{
				return ibuf;
			}
			bool operator==(const self_type& rhs) const
			{
				return ibuf == rhs.ibuf;
			}
			bool operator!=(const self_type& rhs) const
			{
				return ibuf != rhs.ibuf;
			}
	};
	vector<m_pair> buf;
	MapArray()
	{
	}	
	void insert(m_pair& e)
	{
		for(int i = 0;i<buf.size();i++)
		{
			if(e.first < buf[i].first)
			{
				buf.insert(buf.begin()+(i),e);
				sz++;
				return;
			}
		}	
		buf.push_back(e);
		sz++;
	}
	iterator begin()
	{
		return iterator(&buf[0]);
	}
	iterator end()
	{
		return iterator(&buf[sz-1]);
	}
	iterator find(const T& e)
	{
		for(int i = 0;i<buf.size();i++)
		{
			if(buf[i].first==e)
				return iterator(&buf[i]);
		}
		return end();
	}	
	V& operator[](const T& index)
	{
		for(int i=0;i<buf.size();i++)
		{
			if(buf[i].first==index)
				return buf[i].second;
		}
	}
	~MapArray()
	{
		buf.clear();
	}
};			
