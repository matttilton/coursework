#include <iostream>
// #ifndef __GenericList_CC_INCLUDED__
// #include "Queue.cc"
// #include "Stack.cc"
using namespace std;

const int MAX_SIZE = 1024;

//Fuck it the compiler is pissing me off. search for --- to get to the good stuff
template <class l_type>
class List
{
  private:
    // list node definition
    struct Node
    {
        l_type data;
        Node *link;
    };

    Node *head;    // the head of the list
    Node *tail;    // the tail of the list
    Node *curr;    // the current position in the list
    int num_items; // the number of items in the list

  public:
    // constructor
    // remember that an empty list has a "size" of -1 and its "position" is at -1
    List()
    {
        head = tail = curr = NULL;
        num_items = 0;
    }

    // copy constructor
    // clones the list l and sets the last element as the current
    List(const List &l)
    {
        *this = l;
    }

    // copy constructor
    // clones the list l and sets the last element as the current
    void operator=(const List &l)
    {
        Node *n = l.head;

        head = tail = curr = NULL;
        num_items = 0;

        // just loop through the list and copy each element
        while (n != NULL)
        {
            InsertAfter(n->data);
            n = n->link;
        }
    }

    // navigates to the beginning of the list
    void First()
    {
        curr = head;
    }

    // navigates to the end of the list
    // the end of the list is at the last valid item in the list
    void Last()
    {
        curr = tail;
    }

    // navigates to the specified element (0-index)
    // this should not be possible for an empty list
    // this should not be possible for invalid positions
    void SetPos(int pos)
    {
        if (!IsEmpty() && pos >= 0 && pos < num_items)
        {
            curr = head;

            // move curr to the specified position
            for (int i = 0; i < pos; i++)
                curr = curr->link;
        }
    }

    // navigates to the previous element
    // this should not be possible for an empty list
    // there should be no wrap-around
    void Prev()
    {
        if (!IsEmpty() && curr != head)
        {
            Node *n = head;

            // move n to the previous element
            while (n->link != curr)
                n = n->link;

            curr = n;
        }
    }

    // navigates to the next element
    // this should not be possible for an empty list
    // there should be no wrap-around
    void Next()
    {
        if (!IsEmpty() && curr != tail)
            curr = curr->link;
    }

    // returns the location of the current element (or -1)
    int GetPos()
    {
        if (IsEmpty())
            return -1;

        Node *n = head;
        int i = 0;

        // traverse the list to get the current position
        while (n != curr)
        {
            n = n->link;
            i++;
        }

        return i;
    }

    // returns the value of the current element (or -1)
    l_type GetValue()
    {
        return ((!IsEmpty()) ? curr->data : -1);
    }

    // returns the size of the list
    // size does not imply capacity
    int GetSize()
    {
        return num_items;
    }

    // inserts an item before the current element
    // the new element becomes the current
    // this should not be possible for a full list
    void InsertBefore(l_type data)
    {
        if (!IsFull())
        {
            // if the list is empty, just insert after
            if (IsEmpty())
                InsertAfter(data);
            else
            {
                // if we're at the beginning, just create a new head that points to the current one
                if (curr == head)
                {
                    head = new Node;
                    head->data = data;
                    head->link = curr;
                    curr = head;
                    num_items++;
                }
                // otherwise, navigate to the previous node and insert after
                else
                {
                    Prev();
                    InsertAfter(data);
                }
            }
        }
    }

    // inserts an item after the current element
    // the new element becomes the current
    // this should not be possible for a full list
    void InsertAfter(l_type data)
    {
        if (!IsFull())
        {
            Node *n = new Node;

            n->data = data;
            n->link = NULL;

            // if the list is empty, everything points to the single node
            if (IsEmpty())
                head = tail = curr = n;
            else
            {
                // if we're at the end, just tack the new node on
                if (curr == tail)
                {
                    curr->link = n;
                    curr = tail = n;
                }
                // otherwise, change the links to insert the node
                else
                {
                    n->link = curr->link;
                    curr = curr->link = n;
                }
            }

            num_items++;
        }
    }

    // removes the current element (collapsing the list)
    // this should not be possible for an empty list
    void Remove()
    {
        if (!IsEmpty())
        {
            // if we're at the beginning, reset the head
            if (curr == head)
            {
                head = curr = curr->link;

                if (head == NULL)
                    tail = NULL;
            }
            else
            {
                Prev();
                // and rearrange the pointer to remove this node
                curr->link = curr->link->link;
                // we handle removing the tail vs. other internal nodes a bit differently
                if (curr->link == NULL)
                    tail = curr;
                Next();
            }
            num_items--;
        }
    }

    // replaces the value of the current element with the specified value
    // this should not be possible for an empty list
    void Replace(l_type data)
    {
        if (!IsEmpty())
            curr->data = data;
    }

    // returns if the list is empty
    bool IsEmpty()
    {
        return (head == NULL);
    }

    // returns if the list is full
    bool IsFull()
    {
        return (num_items == MAX_SIZE);
    }

    // returns the concatenation of two lists
    // l should not be modified
    // l should be concatenated to the end of *this
    // the returned list should not exceed MAX_SIZE elements
    // the last element of the new list is the current
    List operator+(const List &l) const
    {
        // copy the first list
        List t = *this;
        Node *n = l.head;

        // iterate through the second list and copy each element to the new list
        while (n != NULL && !t.IsFull())
        {
            t.InsertAfter(n->data);
            n = n->link;
        }

        return t;
    }

    // returns if two lists are equal (by value)
    bool operator==(const List &l) const
    {
        // the lists are not equal if they're of different sizes
        if (num_items != l.num_items)
            return false;

        Node *p = head;
        Node *q = l.head;

        // iterate through each list
        while (p != NULL)
        {
            // if any pair of elements differ, the lists are not equal
            if (p->data != q->data)
                return false;
            p = p->link;
            q = q->link;
        }

        return true;
    }

    // returns if two lists are not equal (by value)
    bool operator!=(const List &l) const
    {
        return !(*this == l);
    }

    // returns a string representation of the entire list (e.g., 1 2 3 4 5)
    // the string "NULL" should be returned for an empty list
    friend ostream &operator<<(ostream &out, const List &l)
    {
        // "NULL" if the list is empty
        if (l.head == NULL)
            out << "NULL";
        else
        {
            Node *n = l.head;

            // otherwise iterate through the list and display each element separated by a space
            while (n != NULL)
            {
                out << n->data << " ";
                n = n->link;
            }
        }

        return out;
    }
};

template <class q_type>
class Queue
{
  private:
    List<q_type> l;

  public:
    Queue()
    {
    }

    Queue(const Queue &q)
    {
        l = List<q_type>(q.l);
        l.First();
    }

    void operator=(const Queue &q)
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

    Queue operator+(const Queue &q) const
    {
        Queue<q_type> q2(*this);

        q2.l = q2.l + q.l;
        q2.l.First();

        return q2;
    }

    bool operator==(const Queue &q) const
    {
        return (*this).l == q.l;
    }

    bool operator!=(const Queue &q) const
    {
        return (*this).l != q.l;
    }

    friend ostream &operator<<(ostream &out, const Queue &q)
    {
        out << q.l;

        return out;
    }
};

template <class s_type>
class Stack
{
  private:
    List<s_type> l;

  public:
    Stack()
    {
    }

    Stack(const Stack &s)
    {
        l = List<s_type>(s.l);
        l.First();
    }

    void operator=(const Stack &s)
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

    Stack operator+(const Stack &s) const
    {
        Stack<s_type> s2(*this);

        s2.l = s2.l + s.l;
        s2.l.First();

        return s2;
    }

    bool operator==(const Stack &s) const
    {
        return (*this).l == s.l;
    }

    bool operator!=(const Stack &s) const
    {
        return (*this).l != s.l;
    }

    friend ostream &operator<<(ostream &out, const Stack &s)
    {
        out << s.l;

        return out;
    }
};

bool IsOp(char ch);

int main() {
    char input[1024];
    Stack<char> s;
    Queue<char> q;
    while(cin.getline(input, 1024)) {
        for(int i = 0; i <= 1; i++){
            cout << IsOp(input[i]) << endl;
        }
    }
    return 0;

};

bool IsOp(char data) {
    return (data < '0' || data > '9');
}
