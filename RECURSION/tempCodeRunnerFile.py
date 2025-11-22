table = {}


def fibo(n):
    if n <= 0:
        raise ValueError("Fibonacci is not defined for non-positive integers.")
    if n == 1 or n == 2:
        return 1
    if n not in table:
        # Store result only if not already computed
        table[n] = fibo(n - 1) + fibo(n - 2)
    return table[n]



n = int(input("Enter number: "))
print("FIBONACCI number is:", fibo(n))

