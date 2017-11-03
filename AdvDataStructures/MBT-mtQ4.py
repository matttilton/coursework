from intlist import IntList

def convert_to_regular_list(intlist):
    """
    Converts an IntList to a regular List.
    This makes many list based operations significantly easier
    """
    intlist = str(intlist)
    intlist = intlist[1:len(intlist) - 1]
    intlist = intlist.split(", ")
    newlist = []
    for each in intlist:
        newlist.append(int(each))
    return newlist

def merge(aL: IntList, bL: IntList) -> IntList:
    """
    merges two intlists together by converting them to a regular list.
    merging that.
    then converting back into an intlist.
    """
    return IntList(sorted(convert_to_regular_list(aL) + convert_to_regular_list(bL)))

print(merge(IntList([1, 2, 3, 4, 5, 6, 7, 8, 9]), IntList([1, 3, 4, 7, 6, 44, 88])))
