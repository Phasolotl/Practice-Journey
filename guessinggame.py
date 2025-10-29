import random

print("Guess my number!")

min_value = 1
max_value = 50
chance = 0

computer_guess = random.randint(min_value, (max_value + 1))

while chance < 5:
    guess = int(input("Your guess (1-50): "))
    chance += 1
    if computer_guess == guess:
        print("You found my number! Congratulation!")
        break
    elif computer_guess > guess:
        print("Too small!")
    elif computer_guess < guess:
        print("Too big!")
else:
    print(f"You didn't find my number.. My number is: {computer_guess} ")
