from intlist import IntList

def insert(i:int, k:int, aL:IntList) -> IntList :
    if aL.first() == k:
        return aL.cons(i)
    return insert(i, k, aL.rest()).cons(aL.first())

print(insert(1, 5, IntList([2,3,4,5,6])));