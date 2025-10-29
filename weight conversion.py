# skip this line

user_weight = int(input("Type your weight: "))

print(''' 
***********************************
WELCOME TO MY WEIGHT CONVERTOR 9000
***********************************
Select which unit you wish to convert from
1) Pounds (lbs)
2) Kilograms (kg)
3) Newton (N)
Your choice:
''')

choice_from = int(input())


def pound_conversion():
    print('''
Select the unit you wish to convert to
1) Kilograms (kg)
2) Newton (N)
    ''')

    choice = int(input())

    match choice:
        case 1:
            print(user_weight * 0.45)
        case 2:
            print(user_weight * 4.44)
        case _:
            print("That's not a valid input")
    pass


def kilogram_conversion():
    print('''
Select the unit you wish to convert to
1) Pounds (lbs)
2) Newton (N)
        ''')

    choice = int(input())

    match choice:
        case 1:
            print(user_weight * 2.20)
        case 2:
            print(user_weight * 9.8)
        case _:
            print("That's not a valid input")
    pass


def newton_conversion():
    print('''
Select the unit you wish to convert to
1) Kilograms (kg)
2) Pounds (lbs)
        ''')

    choice = int(input())

    match choice:
        case 1:
            print(user_weight * 0.10)
        case 2:
            print(user_weight * 0.22)
        case _:
            print("That's not a valid input")
    pass


match choice_from:
    case 1:
        pound_conversion()
    case 2:
        kilogram_conversion()
    case 3:
        newton_conversion()
    case _:
        print("That's an invalid choice, please try again!")
