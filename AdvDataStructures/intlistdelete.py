# matthew tilton

# not sure how to do this recursively this is as good as i can get in the 3 minutes that i had

import intlist

def delete(x, y):
    if x.first() == y:
        return x.rest()
    else:
        return delete(x.rest(), y)