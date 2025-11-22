def factorial(x):
    if x == 1 or x == 2:
        return x
    else:
        return  x*factorial(x - 1)


x = int(input("Enter the number: "))
result = factorial(x)
print(f"The fatorial of {x} is :{result}")
