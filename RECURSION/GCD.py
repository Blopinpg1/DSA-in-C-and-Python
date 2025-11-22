def GCD(a, b):
    if b == 0:
        return a
    else:
        return GCD(b, a % b)


a, b = map(int, input("Enter two numbers separated by spaces: ").split())
result = GCD(a, b)
print(f"The greatest common divisor between {a} and {b} is {result}")
