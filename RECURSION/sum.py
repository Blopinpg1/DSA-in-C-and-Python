def sum(num):
    if num == 1:
        return 1
    else:
        return num+sum(num - 1)


num = int(input("Enter the number upto which you want sum of:"))

result = sum(num)
print(f"The sum up {num} is :{result}")
