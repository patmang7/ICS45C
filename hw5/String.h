#include <iostream>
using namespace std;
class String
{
public:
	explicit String(const char* s = "");
	String(const String& s);
	String operator = (const String& s);
	char& operator[](const int index);
	int size();
	String reverse() const;
	int indexOf(char c)const;
	bool operator == (const String& s) const;
	bool operator < (const String& s) const;
	String operator + (const String& s) const;
	String operator += (const String& s);
	void print(ostream& out) const;
	void read(istream& in);
	~String();
private:
	bool inBounds(int i)
	{
		return i>=0&&i<size();
	}
	struct ListNode
	{
		char info;
		ListNode* next;
		ListNode(char newInfo, ListNode* newNext)
			:info(newInfo),next(newNext)
		{
		}
		static ListNode* stringToList(const char* s);
		static ListNode* copy(ListNode* L);
		static ListNode* reverse(ListNode* L, ListNode* R=0);
		static ListNode* append(ListNode* L1,ListNode* L2);
		static int compare(ListNode* L1,ListNode* L2);
		static void deleteList(ListNode* L);
		static int length(ListNode* L);
	};
	ListNode* head;
};
ostream& operator<<(ostream& out, String str);
istream& operator>>(istream& in, String& str);

