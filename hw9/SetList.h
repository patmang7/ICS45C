#include <iterator>
#include <iostream>
using namespace std;

template
	<typename T>
class SetList
{
	template
		<typename Type>
	struct ListNode
	{
		Type info;
		ListNode* next;
		ListNode(Type i,ListNode* n)
			:info(i),next(n)
		{
		}
	};
	
	struct iterator
	{
		typedef forward_iterator_tag iterator_category;
		typedef iterator self_type;
		typedef T value_type;
		typedef ListNode<T>& reference;
		typedef ListNode<T>* pointer;
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
				ibuf = ibuf->next;
				return *this;
			}
			self_type operator++(int postfix)
			{
				self_type cpy = *this;
				ibuf = ibuf->next;
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
	struct const_iterator
	{
		typedef forward_iterator_tag iterator_category;
		typedef const_iterator self_type;
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef ptrdiff_t difference_type;
		private:
			pointer buf;
		public:
			const_iterator(pointer ptr)
				:buf(ptr)
			{
			}
			self_type operator++()
			{
				buf = buf->next;
				return *this;
			}
			self_type operator++(int postfix)
			{
				self_type cpy = *this;
				buf = buf->next;
				return cpy;
			}

			const reference operator*()
			{
				return *buf;
			}
			const pointer operator->()
			{
				return buf;
			}
			bool operator==(const self_type& rhs) const
			{
				return buf == rhs.buf;
			}
			bool operator!=(const self_type& rhs) const
			{
				return buf != rhs.buf;
			}		
	};
	ListNode<T>* head;
public:	
	SetList()
		:head(nullptr)
	{
	}
	void insert(T s)
	{
		head = new ListNode<T>(s,head);
	}
	iterator find(const T& e)
	{
		ListNode<T>* temp = head;
		while(temp != nullptr)
		{
			if(temp->info == e)
				return iterator(temp);
			temp = temp->next;
		}
		return iterator(nullptr);
	}
	iterator begin()
	{
		return iterator(head);
	}
	iterator end()
	{
		return iterator(nullptr);
	}
	const_iterator begin() const
	{
		return const_iterator(head);
	}
	const_iterator end() const
	{
		return const_iterator(nullptr);
	}
	~SetList()
	{
		ListNode<T>* temp;
		for(ListNode<T>* p = head;p!=nullptr;)
		{
			temp = p;
			p = p->next;
			delete temp;
		}
	}

};



