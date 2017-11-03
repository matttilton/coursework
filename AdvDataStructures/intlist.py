"""
IntList Class
"""


class IntList:
    """
    List of Integers
    """

    def __init__(self, intlist=[]):
        self.intlist = intlist

    def cons(self, new_element):
        """
        concatenates the new elemtent to the list
        """
        return IntList([new_element] + self.intlist[:])

    def first(self):
        """
        returns only the first element
        """
        return self.intlist[0]

    def rest(self):
        """
        returns everything except the first element
        """
        return IntList(self.intlist[1:])

    @property
    def nil(self):
        """
        returns true if the list is empty. otherwise returns false
        """
        return len(self.intlist)==0

    def __repr__(self):
        return repr(self.intlist)

