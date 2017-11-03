import intlist

n1 = intlist.IntList([2, 3, 4, 5, 6, 7])

# fulllist = [n1.first].append(n1.rest)
def ithinkthishastoberecursive(n1):
    if(n1.nil == False):
        print(n1.first())
        return ithinkthishastoberecursive(n1.rest())
    else:
        return

ithinkthishastoberecursive(n1)