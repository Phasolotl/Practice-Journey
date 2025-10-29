# Gacha Simulator 101

import time
import random

# Item pools

five_star = ['✴️']
four_star = ['✳️']
three_star = ['⭐']

# Rarity in percentages!

rate_5 = 0.01
rate_4 = 0.20


def pull_once():
    roll = random.random()
    if roll < rate_5:
        rarity = 5
        item = random.choice(five_star)
    elif roll < rate_4 + rate_5:
        rarity = 4
        item = random.choice(four_star)
    else:
        rarity = 3
        item = random.choice(three_star)
    return {"rarity": rarity, "item": item}

def gacha_pull(wish):
    results = []
    for _ in range (wish):
        results.append(pull_once())

    if wish == 10 and not any(r["rarity"] >= 4 for r in results):
        results[-1] = {"rarity": 4, "item": random.choice(four_star)}
    return results


def result_summary(results):
    for r in results:
        print(f"{r['rarity']}* : {r['item']}")
        time.sleep(0.25)
    count_3 = sum(1 for r in results if r['rarity'] == 3)
    count_4 = sum(1 for r in results if r['rarity'] == 4)
    count_5 = sum(1 for r in results if r['rarity'] == 5)

    print(f"\nSummary: 5* x{count_5}, 4* x{count_4}, 3* x{count_3}")


if __name__ == '__main__':
    gems = 16000

    print('''
********************************
Welcome to Phi's Gacha Simulator
Current Banner:
✴️ = 1% (5*)
✳️ = 20% (4*)
⭐ = 79% (3*)
********************************
1) Single Pull (160 Gems)
2) Multi Pull (1600 Gems)''')

    while True:
        print(f"You currently have {gems} gems (If you have 0 gems, press any key to exit)")
        choice = input("> ")

        match choice:
            case '1': wish = 1
            case '2': wish = 10
            case _:
                print("Invalid choice, please try again")
                continue

        cost = wish * 160

        if gems <= 0:
            print("Thanks for playing")
            break

        elif gems < cost:
            print("Insufficient funds!")
            continue

        results = gacha_pull(wish)
        result_summary(results)

        gems -= cost

# end of code yippe!