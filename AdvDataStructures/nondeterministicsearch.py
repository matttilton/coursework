#Matthew Tilton

from random import randint

def search(array, value):
    """
        searches through an array using random values until it
        has exahausted all valid values or has found the item
    """
    found = False
    indeces = []
    while not found and len(array) > 0:
        newrand = randint(0, len(array) - 1)
        if newrand not in indeces:
            indeces.append(newrand)
        if value == array[newrand]:
            found = True
        if len(indeces) == len(array):
            break
    return found

print(search([], '4'))
    