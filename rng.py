import random

print('''
!! RANDOM DICE GAME !!

Let's roll a dice!''')

# Loop program:

while True:
    try:
        i = int(input("How many dice do you want to roll?: (Enter 0 if you want to exit) "))
        if i == 0:
            print("Thanks for playing")
            break

        for i in range(1, (i + 1)):
            print("Dice number %d" % i)
            print(random.randint(1, 6))

    except ValueError:
        print("Don't do that, the system will blow up!")
        continue