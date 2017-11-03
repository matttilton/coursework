"""
Binary Search
"""
from random import randrange

# COUNT = 0 #counter for counting number of steps

def binarysearch(data, key):
    """
        Simple recursive binary search.
        Returns the value that was searched for
    """
    # global COUNT #access count on global scope
    # COUNT = COUNT + 1 #increment count on every iteration

    if len(data) != 1:
        middle = int(len(data)/2) # divide by 2 then cast floar to int
        if key == data[middle]: # if the key is equal to the middle element return the key
            return data[middle]
        elif key > data[middle]: # if the key is bigger pass in the right side and go again
            return binarysearch(data[middle:], key)
        elif key < data[middle]: # if the key is less pass in the left side and go again
            return binarysearch(data[:middle], key)
    else:
        if data[0] == key: # if the last remaining value is equal to the key
            return data[0]
        return 'Key not found'

def main(data, key):
    """
        previously had the sort in the search algorithm but it turns out that sorting
        every time makes the program very slow. This way only sorts once and is much faster.
    """
    data.sort(key=int)
    return binarysearch(data, key)

print(main([randrange(100) for _ in range(100)], 0))
# print(COUNT)
