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
		int placeholder[MAX_SIZE];

		//Shifts list to the right by one starting at the cursor
		void SRO() {
			if (curr == -1) {
				curr = 0;
				end = 0;
			} else {
				int tmp[MAX_SIZE];
				for (int i = 0; i < MAX_SIZE; i++) {
					if (i < curr) {
						tmp[i] = list[i];
					} else if(i == curr) {
						;
					} else if(i > curr) {
						tmp[i+1] == list[i];
					}
				}
				for (int i = 0; i < MAX_SIZE; i++) {
					list[i] = tmp[i];
				}
			}
			end++;
		}

		//I dont think this is being used anywhere but removing it caused a segmentation fault so it stays
		void SROP() {
			if (curr == -1) {
				curr = 0;
				end = 0;
			}
				int tmp[MAX_SIZE];
				for (int i = 0; i < MAX_SIZE; i++) {
					if (i < curr) {
						tmp[i] = placeholder[i];
					} else if(i == curr) {
						;
					} else if(i > curr) {
						tmp[i+1] == placeholder[i];
					}
				}
				for (int i = 0; i < MAX_SIZE; i++) {
					placeholder[i] = tmp[i];
				}
			end++;
		}

	public:
		// constructor
		// remember that an empty list has a "size" of -1 and its "position" is at -1
		List()
		{
			end = -1;
			curr = -1;
		}

		// copy constructor
		// clones the list l and sets the last element as the current
		List(const List& l)
		{
			end = -1;
			curr = -1;
			for(int i = 0; i <= l.end; i++) {
				InsertAfter(l.list[i]);
			}
			curr = end;
		}

		// copy constructor
		// clones the list l and sets the last element as the current
		void operator=(const List& l)
		{
			end = -1;
			curr = -1;
			for(int i = 0; i <= l.end; i++) {
				InsertAfter(l.list[i]);
			}
			curr = end;
		}

		// navigates to the beginning of the list
		void First()
		{
			curr = 0;
		}

		// navigates to the end of the list
		// the end of the list is at the last valid item in the list
		// this should not be possible for an empty list (although maybe it doesn"t matter?)
		void Last()
		{
			curr = end;
		}

		// navigates to the specified element (0-index)
		// this should not be possible for an empty list
		// this should not be possible for invalid positions
		void SetPos(int pos)
		{
			if (pos >= 0 && pos <= MAX_SIZE && pos <= end)	{
				curr = pos;
			}
		}

		// navigates to the previous element
		// this should not be possible for an empty list
		// there should be no wrap-around
		void Prev()
		{
			if (curr != 0) {
				curr--;
			}
		}

		// navigates to the next element
		// this should not be possible for an empty list
		// there should be no wrap-around
		void Next()
		{
			if (curr != end) {
				curr++;
			}
		}

		// returns the location of the current element (or -1)
		int GetPos()
		{
			return curr;
		}

		// returns the value of the current element (or -1)
		int GetValue() const
		{
			if((end + 1) != MAX_SIZE) {
				return list[curr];
			}	else {
				return -1;
			}
		}

		// returns the size of the list
		// size does not imply capacity
		int GetSize()
		{
			return end + 1;
		}

		// inserts an item before the current element
		// the new element becomes the current
		// this should not be possible for a full list
		void InsertBefore(int data)
		{
			if((end + 1) != MAX_SIZE) {
				if(end == -1) {
					curr = 0;
				}
				int tmp[MAX_SIZE];
				end++;
				for ( int i = 0; i <= end; ++i) {
					if ( i < curr) {
						tmp[i] = list[i];
					}
					if (i==curr) {
						tmp[i] = data;
					}
					if ( i > curr) {
						tmp[i] = list[i-1];
					}
				}
				for (int i = 0; i < MAX_SIZE; i++) {
					list[i] = tmp[i];
				}

			}
		}

		// inserts an item after the current element
		// the new element becomes the current
		// this should not be possible for a full list
		void InsertAfter(int data)
		{
			if((end + 1) != MAX_SIZE) {
				curr++;
				SRO();
				list[curr] = data;
			}
		}

		// removes the current element (collapsing the list)
		// this should not be possible for an empty list
		void Remove()
		{
			if(end != -1) {
				int tmp[MAX_SIZE];
				for (int i = curr; i < end; i++) {
					list[i] = list[i + 1];
				}
				end--;
				if(curr > end) {
					curr--;
				}
			}
		}

		// replaces the value of the current element with the specified value
		// this should not be possible for an empty list
		void Replace(int data)
		{
			if(end != -1) {
				list[curr] = data;
			}
		}

		// returns if the list is empty
		bool IsEmpty() const
		{
			if(end == -1) {
				return true;
			}
		}

		// returns if the list is full
		bool IsFull()
		{
			if ((end + 1) == MAX_SIZE) {
				return true;
			} else{
				return false;
			}
		}

		// returns the concatenation of two lists
		// l should not be modified
		// l should be concatenated to the end of *this
		// the returned list should not exceed MAX_SIZE elements
		// the last element of the new list is the current
		List operator+(const List& l) const
		{
			int count = 0;
			List tmp;
			for (int i = 0; i < MAX_SIZE; i++) {
				if(i<= end) {
					tmp.InsertAfter(list[i]);
				}
				if( i > end ) {
					tmp.InsertAfter(l.list[count]);
					count++;
				}
			}
			return tmp;
		}

		// returns if two lists are equal (by value)
		bool operator==(const List& l) const
		{
			bool flag = false;
			for (int i = 0; i < MAX_SIZE; i++) {
				if (l.list[i] != list[i]) {
					flag = true;
				}
			}

			return !flag;
		}

		// returns if two lists are not equal (by value)
		bool operator!=(const List& l) const
		{
			bool flag = false;
			for (int i = 0; i < MAX_SIZE; i++) {
				if (l.list[i] != list[i]) {
					flag = true;
				}
			}

			return flag;
		}

		// returns a string representation of the entire list (e.g., 1 2 3 4 5)
		// the string "NULL" should be returned for an empty list
		friend ostream& operator<<(ostream& out, const List &l)
		{
			if(l.end == -1) {
				out << "NULL";
			}
			for(int i = 0; i <= l.end; i++) {
				out << l.list[i] << " ";
			}

			return out;
		}
};
