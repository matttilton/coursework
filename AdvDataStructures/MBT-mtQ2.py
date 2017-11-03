def fac(n:int) -> int :
    """
    non-recursive function to find the factorial of a number
    """

    factorial = 1
    while n >= 1:
        factorial *= n
        n -= 1
    return factorial


print(fac(10))