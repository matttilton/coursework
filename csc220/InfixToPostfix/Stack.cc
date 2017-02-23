/****************************************************
 * <your name>
 * <the date>
 * <the file name>
 *
 * <a simple, short program/class description>
 ****************************************************/

#include <iostream>
#include "GenericList.cc"
using namespace std;

template<class s_type>
class Stack
{
	private:
		List<s_type> l;

	public:
		Stack()
		{
		}

		Stack(const Stack& s)
		{
			l = List<s_type>(s.l);
			l.First();
		}

		void operator=(const Stack& s)
		{
			l = List<s_type>(s.l);
			l.First();
		}

		s_type Peek()
		{
			return l.GetValue();
		}

		int Size()
		{
			return l.GetSize();
		}

		void Push(s_type data)
		{
			l.InsertBefore(data);
		}

		s_type Pop()
		{
			s_type t = l.GetValue();

			l.Remove();

			return t;
		}

		bool IsEmpty()
		{
			return l.IsEmpty();
		}

		bool IsFull()
		{
			return l.IsFull();
		}

		Stack operator+(const Stack& s) const
		{
			Stack<s_type> s2(*this);

			s2.l = s2.l + s.l;
			s2.l.First();

			return s2;
		}

		bool operator==(const Stack& s) const
		{
			return (*this).l == s.l;
		}

		bool operator!=(const Stack& s) const
		{
			return (*this).l != s.l;
		}

		friend ostream& operator<<(ostream& out, const Stack& s)
		{
			out << s.l;

			return out;
		}
};
