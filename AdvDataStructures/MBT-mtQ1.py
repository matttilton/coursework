"""
    worst-case complexity = n - 1
    average-case complexity = n - 1

    this algorithm is optimal since it only does n - 1 comparisons which is the
    minimum amount required to find the largest element in an unordered list
"""

from intlist import IntList

def findMax(gL:IntList) -> int:
    """
    finds the maximum value of an IntList
    """
    if gL is None or gL.nil:
        return None
    current_max = gL.first() #assign the current max to the first one to avoid one comparison
    gL = gL.rest() # reassign gL to be the rest of the list
    while gL.nil is False:
        if gL.first() > current_max:
            current_max = gL.first()
        gL = gL.rest()
    return current_max

print(findMax(IntList([9, 1, 2, 3, 55, 4, 5])))
