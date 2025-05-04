def fibbonaci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibbonaci(n-1) + fibbonaci(n-2)

def fib(n):
    A = [0] * (n + 1)
    A[0] = 0
    A[1] = 1
    for i in range(2, n + 1):
        A[i] = A[i -1] + A[i - 2]
        
    return A[n]

def fib_rec_memo(n, memo = {0:0, 1:1}):
    if n in memo:
        return memo[n]
    return fib_rec_memo(n - 1, memo) + fib_rec_memo(n - 2, memo)
        