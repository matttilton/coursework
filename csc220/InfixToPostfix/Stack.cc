/****************************************************
 * <Matthew Tilton>
 * <2-13-17>
 * <Stack.cc>
 *
 * A stack
 ****************************************************/
#include <iostream>
//This definitely compiles but you need to point it to the GenericList.cc that is on your computer.
#include "GenericList.cc"

using namespace std;

template <class T>

class Stack
{
  private:
    List<T> list;

  public:
    //Constructor
    Stack()
    {
        List<T> l;
        list = l;
    }

    //Copy contructor
    Stack(const Stack &s)
    {
        int size = s.Size();
        List<T> l = s.list;
        l.Last();
        for (int i = 0; i < size; i++)
        {
            Push(l.GetValue());
            l.Prev();
        }
    }

    //Copy constructor
    void operator=(const Stack &s)
    {
        for (int i = 0; i < 30; i++)
        {
            list.Remove();
        }
        int size = s.Size();
        List<T> l = s.list;
        l.Last();
        for (int i = 0; i < size; i++)
        {
            Push(l.GetValue());
            l.Prev();
        }
    }

    //Puts a new item on top of the stack
    void Push(T data)
    {
        if (!IsFull())
        {
            list.First();
            list.InsertBefore(data);
        }
    }

    //Removes the item on top of the stack
    void Pop()
    {
        if (!IsEmpty())
        {
            list.First();
            list.Remove();
        }
    }

    //Shows the item on top of the stack
    T Peek()
    {
        if (IsEmpty())
        {
            return -1;
        }
        else
        {
            list.First();
            return list.GetValue();
        }
    }

    //Returns the size of the stack
    int Size() const
    {
        return list.GetSize();
    }

    //returns true if stack is empty
    bool IsEmpty() const
    {
        return list.IsEmpty();
    }

    //returns true if stack if full
    bool IsFull() const
    {
        return list.IsFull();
    }

    //Adds two stacks together
    Stack operator+(const Stack &s) const
    {
        List<T> right = s.list;
        Stack<T> s1;
        Stack<T> s2 = *this;
        List<T> left = s2.list;
        List<T> both = left + right;
        both.Last();
        while (!both.IsEmpty())
        {
            s1.Push(both.GetValue());
            both.Remove();
        }
        return s1;
    }

    //Determines equality of two stacks
    bool operator==(const Stack &s) const
    {
        Stack<T> tmp1 = s;
        Stack<T> tmp2 = *this;
        bool flag = false;
        int i = 0;
        if (tmp1.Size() == tmp2.Size())
        {
            while (i < s.Size() && !flag)
            {

                if (tmp1.Peek() != tmp2.Peek())
                {
                    flag = true;
                }
                tmp1.Pop();
                tmp2.Pop();
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

    //Determines oposite equality of two stacks
    bool operator!=(const Stack &s) const
    {
        return !(*this == s);
    }

    //outputs of stream
    friend ostream &operator<<(ostream &out, const Stack &s)
    {
        Stack<T> stack = s;
        if (s.Size() == 0)
        {
            out << "NULL";
        }
        else
        {
            for (int i = 0; i < s.Size(); i++)
            {
                out << stack.Peek() << " ";
                stack.Pop();
            }
        }
        return out;
    }
};