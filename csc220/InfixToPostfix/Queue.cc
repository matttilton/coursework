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

template<class q_type>
class Queue
{
	private:
		List<q_type> l;

	public:
		Queue()
		{
		}

		Queue(const Queue& q)
		{
			l = List<q_type>(q.l);
			l.First();
		}

		void operator=(const Queue& q)
		{
			l = List<q_type>(q.l);
			l.First();
		}

		q_type Peek()
		{
			q_type t;

			l.First();
			t = l.GetValue();
			l.Last();

			return t;
		}

		int Size()
		{
			return l.GetSize();
		}

		void Enqueue(q_type data)
		{
			l.InsertAfter(data);
		}

		q_type Dequeue()
		{
			q_type t;
			
			l.First();
			t = l.GetValue();
			l.Remove();
			l.Last();

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

		Queue operator+(const Queue& q) const
		{
			Queue<q_type> q2(*this);

			q2.l = q2.l + q.l;
			q2.l.First();

			return q2;
		}

		bool operator==(const Queue& q) const
		{
			return (*this).l == q.l;
		}

		bool operator!=(const Queue& q) const
		{
			return (*this).l != q.l;
		}

		friend ostream& operator<<(ostream& out, const Queue& q)
		{
			out << q.l;

			return out;
		}
};
