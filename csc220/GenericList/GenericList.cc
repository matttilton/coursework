/****************************************************
 * <Matthew Tilton>
 * <2-8-17>
 * <GenericList.cc>
 *
 * Generic Linked list
 ****************************************************/

#include <iostream>
using namespace std;

const int MAX_SIZE = 30;

template <class T>

class List
{
	private:
		// list node definition
		struct Node
		{
			T data;
			Node *link;
		};

		Node *head;	// the head of the list
		Node *tail;	// the tail of the list
		Node *curr;	// the current position in the list
		int num_items;	// the number of items in the list

	public:
		// constructor
		// remember that an empty list has a "size" of -1 and its "position" is at -1
		List() {
			num_items = 0;
			head = NULL;
			tail = NULL;
			curr = NULL;
		}

		// copy constructor
		// clones the list l and sets the last element as the current
		List(const List& l) {
			num_items = 0;
			head = tail = curr = NULL;
			Node* p = l.head;
			while (p != NULL) {
				InsertAfter(p -> data);
				p = p -> link;
			}
		}

		// copy constructor
		// clones the list l and sets the last element as the current
		void operator=(const List& l) {
			num_items = 0;
			head = tail = curr = NULL;
			Node* p = l.head;
			while (p != NULL) {
				InsertAfter(p -> data);
				p = p -> link;
			}
		}

		//Returns the head of the list
		Node* Head() const {
			return head;
		}

		// navigates to the beginning of the list
		void First() {
			if (!IsEmpty()) {
				curr = head;
			}
		}

		// navigates to the end of the list
		// the end of the list is at the last valid item in the list
		void Last() {
			if (!IsEmpty()) {
				curr = tail;
			}
		}

		// navigates to the specified element (0-index)
		// this should not be possible for an empty list
		// this should not be possible for invalid positions
		void SetPos(int pos) {
			int counter = 0;
			if (!IsEmpty() && pos < num_items && pos >= 0) {
				curr = head;
				while (counter < pos) {
					curr = curr -> link;
					counter++;
				}
			}
		}

		// navigates to the previous element
		// this should not be possible for an empty list
		// there should be no wrap-around
		void Prev() {
			if (curr != head) {
				Node* p = head;
				while(p -> link != curr) {
					p = p -> link;
				}
				curr = p;
			}
		}

		// navigates to the next element
		// this should not be possible for an empty list
		// there should be no wrap-around
		void Next() {
			if (!IsEmpty()) {
				if (curr -> link != NULL) {
					curr = curr -> link;
				}
			}
		}

		// returns the location of the current element (or -1)
		int GetPos() const {
			if (IsEmpty()) {
				return -1;
			}	else {
				int pos = 0;
				Node* p = head;
				while (p!= curr) {
					p = p -> link;
					pos++;
				}
				return pos;
			}
		}

		// returns the value of the current element (or -1)
		T GetValue() {
			if (IsEmpty()) {
				return -1;
			}	else {
				return curr -> data;
			}
		}

		// returns the size of the list
		// size does not imply capacity
		int GetSize() const {
			return (num_items);
		}

		// inserts an item before the current element
		// the new element becomes the current
		// this should not be possible for a full list
		void InsertBefore(T data) {
			if (!IsFull()) {
				if(IsEmpty()) {
					InsertAfter(data);
				} else {
					if (curr == head) {
						curr = new Node;
						curr -> data = data;
						curr -> link = head;
						head = curr;
						num_items++;
					}	else {
						Prev();
						InsertAfter(data);
					}
				}
			}
		}

		// inserts an item after the current element
		// the new element becomes the current
		// this should not be possible for a full list
		void InsertAfter(T data) {
			if (!IsFull()) {
				if (IsEmpty()) {
					head = new Node;
					head -> data = data;
					head -> link = NULL;
					curr = head;
					tail = head;
					num_items++;
				}	else {
					if (curr == tail) {
						curr -> link = new Node;
						curr = curr -> link;
						curr -> data = data;
						curr -> link = NULL;
						tail = curr;
						num_items++;
					}	else {
						Node* p = new Node;
						p -> data = data;
						p -> link = curr -> link;
						curr -> link = p;
						curr = p;
						num_items++;
					}
				}
			}
		}

		// removes the current element (collapsing the list)
		// this should not be possible for an empty list
		void Remove() {
			if (!IsEmpty()) {
				if (curr == head) {
					head = curr -> link;
					delete curr;
					curr = head;
				} else {
					Prev();
					curr -> link = curr -> link -> link;
					Next();
					if (curr->link == NULL) {
						tail = curr;
					}
				}
				num_items--;
			}
		}

		// replaces the value of the current element with the specified value
		// this should not be possible for an empty list
		void Replace(T data) {
			if (!IsEmpty()) {
				curr -> data = data;
			}
		}

		// returns if the list is empty
		bool IsEmpty() const {
			return (num_items == 0);
		}

		// returns if the list is full
		bool IsFull() {
			return (num_items == MAX_SIZE);
		}

		// returns the concatenation of two lists
		// l should not be modified
		// l should be concatenated to the end of *this
		// the returned list should not exceed MAX_SIZE elements
		// the last element of the new list is the current
		List operator+(const List& l) const {
				List tmp;
				List val_left = (*this);
				List val_right = l;
				val_left.First();
				val_right.First();
				int counter = 0;
				while (counter < val_left.GetSize()) {
					tmp.InsertAfter(val_left.GetValue());
					val_left.Next();
					counter++;
				}
				counter = 0;
				while (counter < val_right.GetSize()) {
					tmp.InsertAfter(val_right.GetValue());
					val_right.Next();
					counter++;
				}
				return (tmp);
		}

		// returns if two lists are equal (by value)
		bool operator==(const List& l) const {
			bool flag = false;
			int counter = 0;
			int max;
			if (l.GetSize() > (*this).GetSize()) {
				max = l.GetSize();
			} else {
				max = (*this).GetSize();
			}
			if (l.GetSize() == (*this).GetSize()) {
				Node* val_left = (*this).Head();
				Node* val_right = l.Head();
				while (!flag && (counter < max)) {
					if ((val_left -> data) != (val_right -> data)) {
						flag == true;
					} else {
						counter++;
						val_left = val_left -> link;
						val_right = val_right -> link;
					}
				}
			}
		}

		// returns if two lists are not equal (by value)
		bool operator!=(const List& l) const {
			return !operator == (l);
		}

		// returns a string representation of the entire list (e.g., 1 2 3 4 5)
		// the string "NULL" should be returned for an empty list
		friend ostream& operator<<(ostream& out, const List &l) {
			if (l.num_items == 0) {
				out << "NULL";
			} else {
				Node* p = l.head;
				while (p != NULL)
				{
					out << p->data << " ";
					p = p->link;
				}
			}
			return out;
		}
};
