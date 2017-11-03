import intlist as i

def main(intlist, value, index):
    intliststring = str(intlist)[1:len(str(intlist)) - 1]
    intlist = intliststring.split(", ")
    newlist = []
    for each in intlist:
        newlist.append(int(each))
    newlist.insert(index, value)
    return i.IntList(newlist)

print(main(i.IntList([1,2,4,5]), 2, 3))
