def add(a, b):
    return a + b


def subtract(a, b):
    return a - b


def multiply(a, b):
    return a * b


def divide(a, b):
    return a / b


print("Calculator!")
user_input = input("Input: ")
str = user_input.split(" ")
for i in range(len(str)):
    if str[i] == "+":
        str[i+1] = add(int(str[i-1]), int(str[i+1]))
    elif str[i] == "-":
        str[i+1] = subtract(int(str[i-1]), int(str[i+1]))
    elif str[i] == "*":
        str[i+1] = multiply(int(str[i-1]), int(str[i+1]))
    elif str[i] == "/":
        str[i+1] = divide(int(str[i-1]), int(str[i+1]))
    else:
        continue
print(str[len(str) - 1])
