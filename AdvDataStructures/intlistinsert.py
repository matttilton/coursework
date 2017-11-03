import intlist as ilist

def insertinmiddle(intlist, index):
    count = 0
    firsthalf = []
    while count < index:
        firsthalf.append(intlist.first())
        intlist = intlist.rest()
        count += 1
    return [firsthalf, intlist]

def main(intlist, index, value):
    listarray = insertinmiddle(intlist, index)
    tmp = listarray[1].cons(value)
    for each in reversed(listarray[0]):
        tmp = tmp.cons(ilist.IntList(each))
    return tmp

print(str(main(ilist.IntList([1,2,4,5]), 2, 3)))
