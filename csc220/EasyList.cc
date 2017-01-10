/****************************************************
 * <your name>
 * <the date>
 * <the file name>
 *
 * <a simple, short program/class description>
 * Modified by Matthew Tilton on 2016-12-23
 ****************************************************/

#include <iostream>
using namespace std;

const int MAX_SIZE = 30;

class List
{
	private:
		int end;		// the index of the last valid item in the list
		int curr;		// the index of the current item in the list
		int list[MAX_SIZE];	// the list

	public:
		// constructor
		// remember that an empty list has a "size" of -1 and its "position" is at -1
		List()
		{
			curr = -1;
		}

		// copy constructor
		// clones the list l and sets the last element as the current
		List(const List& l)
		{
			//Need to clone the list

			//Set last element to current
		}

		// copy constructor
		// clones the list l and sets the last element as the current
		void operator=(const List& l)
		{
			//Need to clone the list

			//Set last element to current
		}

		// navigates to the beginning of the list
		void First()
		{
			curr = 0;
		}

		// navigates to the end of the list
		// the end of the list is at the last valid item in the list
		// this should not be possible for an empty list (although maybe it doesn't matter?)
		void Last()
		{
			curr = (sizeof(list)/4) - 1;
		}

		// navigates to the specified element (0-index)
		// this should not be possible for an empty list
		// this should not be possible for invalid positions
		void SetPos(int pos)
		{
			curr = pos;
		}

		// navigates to the previous element
		// this should not be possible for an empty list
		// there should be no wrap-around
		void Prev()
		{
			curr = curr - 1;
		}

		// navigates to the next element
		// this should not be possible for an empty list
		// there should be no wrap-around
		void Next()
		{
			curr = curr + 1;
		}

		// returns the location of the current element (or -1)
		int GetPos()
		{
			return curr;
		}

		// returns the value of the current element (or -1)
		int GetValue()
		{
			return list[curr];
		}

		// returns the size of the list
		// size does not imply capacity
		int GetSize() const
		{
			return (sizeof(list)/4);
		}

		// inserts an item before the current element
		// the new element becomes the current
		// this should not be possible for a full list
		void InsertBefore(int data)
		{
			//This is dogshit and needs to be fixed.
			list = data + list;
		}

		// inserts an item after the current element
		// the new element becomes the current
		// this should not be possible for a full list
		void InsertAfter(int data)
		{
			//This is nothing but sudocode.
			list = list + data;
		}

		// removes the current element (collapsing the list)
		// this should not be possible for an empty list
		void Remove()
		{
			//if list is not empty.
			//split list into three lists.
			//first list contains all of the alements before element to be removed.
			//second list contains element to be removed.
			//third list contains all elements after the element to be removed.
			//concatenate first and third list.
			//clean up memory.
		}

		// replaces the value of the current element with the specified value
		// this should not be possible for an empty list
		void Replace(int data)
		{
			//if list is not empty.
			//split list into three lists.
			//first list contains all of the alements before element to be removed.
			//second list contains element to be removed.
			//third list contains all elements after the element to be removed.
			//change value of single element in second list.
			//concatenate first and third list.
			//clean up memory.
		}

		// returns if the list is empty
		bool IsEmpty() const
		{
			//if sizeof list == 0
			//return true
		}

		// returns if the list is full
		bool IsFull()
		{
			//if sizeof list == MAX_SIZE
			//return true
			//else
			//return false
		}

		// returns the concatenation of two lists
		// l should not be modified
		// l should be concatenated to the end of *this
		// the returned list should not exceed MAX_SIZE elements
		// the last element of the new list is the current
		List operator+(const List& l) const
		{
			//concatenate l and *this
		}

		// returns if two lists are equal (by value)
		bool operator==(const List& l) const
		{
			//if *this === l 
			//return true
		}

		// returns if two lists are not equal (by value)
		bool operator!=(const List& l) const
		{
			//if *this != l 
			//return true
		}

		// returns a string representation of the entire list (e.g., 1 2 3 4 5)
		// the string "NULL" should be returned for an empty list
		friend ostream& operator<<(ostream& out, const List &l)
		{
			for (int i = 0; i < l.size; i++) {
        		if (i < l.size - 1) {
            		out << l.array[i] << ", ";
        		} else {
            		out << l.array[i] << endl;
        		}
    		}

    		return out;
		}
};
