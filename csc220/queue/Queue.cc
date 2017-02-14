/****************************************************
 * <Matthew Tilton>
 * <2-13-17>
 * <Queue.cc>
 *
 * A queue 
 ****************************************************/
#include <iostream>
//This definitely compiles but you need to point it to the GenericList.cc that is on your computer.
#include "GenericList.cc"

using namespace std;

template <class T>

class Queue
{
  private:
    List<T> list;

  public:
    //Constructor
    Queue()
    {
        List<T> l;
        list = l;
    }

    //Copy contructor
    Queue(const Queue &q)
    {
        int size = q.Size();
        List<T> l = q.list;
        l.Last();
        for (int i = 0; i < size; i++)
        {
            Enqueue(l.GetValue());
            l.Prev();
        }
    }

    //Copy constructor
    void operator=(const Queue &q)
    {
        for (int i = 0; i < 30; i++)
        {
            list.Remove();
        }
        int size = q.Size();
        List<T> l = q.list;
        l.Last();
        for (int i = 0; i < size; i++)
        {
            Enqueue(l.GetValue());
            l.Prev();
        }
    }

    //Puts a new item at the end of the queue
    void Enqueue(T data)
    {
        if (!IsFull())
        {
            list.First();
            list.InsertBefore(data);
        }
    }

    //Removes the item at the front of the queue and returns it
    T Dequeue()
    {
        if (!IsEmpty())
        {
            list.Last();
            T tmp = list.GetValue();
            list.Remove();
            return tmp;
        }
    }

    //Shows the item at the front of the queue
    T Peek()
    {
        if (IsEmpty())
        {
            return -1;
        }
        else
        {
            list.Last();
            return list.GetValue();
        }
    }

    //Returns the size of the queue
    int Size() const
    {
        return list.GetSize();
    }

    //returns true if queue is empty
    bool IsEmpty() const
    {
        return list.IsEmpty();
    }

    //returns true if queue if full
    bool IsFull() const
    {
        return list.IsFull();
    }

    //Adds two queues together
    Queue operator+(const Queue &q) const
    {
        Queue<T> q1 = q;
        Queue<T> q2 = *this;
        Queue<T> q3;
        while (!q2.IsEmpty())
        {
            q3.Enqueue(q2.Dequeue());
        }
        while (!q1.IsEmpty())
        {
            q3.Enqueue(q1.Dequeue());
        }
        return q3;
    }

    //Determines equality of two queues
    bool operator==(const Queue &q) const
    {
        Queue<T> tmp1 = q;
        Queue<T> tmp2 = *this;
        bool flag = false;
        int i = 0;
        if (tmp1.Size() == tmp2.Size())
        {
            while (i < q.Size() && !flag)
            {

                if (tmp1.Peek() != tmp2.Peek())
                {
                    flag = true;
                }
                tmp1.Dequeue();
                tmp2.Dequeue();
                i++;
            }
            if (flag)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            return false;
        }
    }

    //Determines oposite equality of two queues
    bool operator!=(const Queue &q) const
    {
        return !(*this == q);
    }

    //outputs of stream
    friend ostream &operator<<(ostream &out, const Queue &q)
    {
        Queue<T> queue = q;
        if (q.Size() == 0)
        {
            out << "NULL";
        }
        else
        {
            for (int i = 0; i < q.Size(); i++)
            {
                out << queue.Dequeue() << " ";
            }
        }
        return out;
    }
};