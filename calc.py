with open('output.txt', 'w') as f:
    numbers = list(range(1, 10000, 1))
    for num in numbers:
        f.write(str(num) + '\n')