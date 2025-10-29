# gamble away for spamton..

import time
import random

def spin_slot():
    symbols = ["⭐", "❤️", "👾", "💎", "💸"]

    results = []
    for _ in range(3):
        results.append(random.choice(symbols))
    return results

def print_slot(slots):
    print("[", " | ".join(slots), "]")

def cashout(slots, bet):
    if slots[0] == slots[1] == slots[2]:

        if slots[0] == '⭐':
            return bet * 2
        elif slots[0] == '❤️':
            return bet * 3
        elif slots[0] == '👾':
            return bet * 4
        elif slots[0] == '💎':
            return bet * 5
        elif slots[0] == '💸':
            return bet * 10

    return 0


if __name__ == '__main__':
    balance = 100

    print('''
*************************
SPAMTON O' SLOTS
KROMERS: ⭐ ❤️ ️ 👾 💎 💸
*************************
GO BIG OR GO HOME! HAHA!!\n''')

    while balance > 0:
        try:
            print(f"CURRENT KROMERS: $K{balance}")

            bet = int(input("ASSERT YOUR MONEYHOLE: "))

            if bet > balance:
                print("THAT'S TOO BIG FOR YOUR [[Little Sponges]]")
                continue
            elif bet <= 0:
                print ("YOU CAN'T BET FOR FREE!!")
                continue

            balance -= bet

            slots = (spin_slot())
            print("Spinning...")
            time.sleep(1)
            print_slot(slots)

            payout = cashout(slots, bet)

            if payout > 0:
                print(f"LOOKS LIKE WE GOT A WINNER! YOU WON $K{payout}")
            else:
                print("OOPS! BETTER LUCK NEXT TIME, HEHEHAHEHAHEHA!")

            balance += payout

            play_again = input("DO YOU WANT TO HAVE MORE FUN? (Y/N) ").upper()

            match play_again:
                case 'Y': continue
                case 'N': break
                case _ :
                    print("GET OUT!")
                    exit()

        except ValueError:
            print("THAT'S NOT A VALID [[Kromers]]")
            continue

    print(f'''YOU'VE GONE [[Broke]], LOOKS LIKE THERE ISN'T ANYMORE WORTH TO PLAY WITH YOU!
YOUR FINAL KROMER: $K{balance}''')

# end of code