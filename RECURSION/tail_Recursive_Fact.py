def tailRecursive(num, a):
    if num == 0:
        return a
    else:
        return tailRecursive(num - 1, num * a)


num = int(input("Enter the number:"))
a = 1

result = tailRecursive(num, a)

print(f"The factorial of {num} is : {result}")
