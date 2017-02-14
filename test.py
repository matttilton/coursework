def recurse(x):
    if (x == 0):
        return 0
    return x + recurse(x -1)

print(recurse(-1))