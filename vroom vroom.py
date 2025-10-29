import webbrowser

i = 0
user_input = ""
engine_running = False

while True:
    user_input = input("> ").upper()

    if user_input == "HELP":
        print('''List of available commands
* START - start up the engine
* DRIVE - drive the car
* STOP - stop the engine
* ??? - do not.
* EXIT - exit the car''')

    elif user_input == "START":

        if engine_running:
            print("Car has already started!")
        else:
            engine_running = not engine_running
            print("VROOOM! CAR STARTED")

    elif user_input == "DRIVE":

        if engine_running:
            for i in range (0,5):
                print("NYOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOM!!!")
        else:
            print ("Car hasn't started!!")

    elif user_input == "STOP":

        if engine_running == False:
            print("Car hasn't started!!")
        else:
            engine_running = not engine_running
            print("Vroom...! stopping engine!")

    elif user_input == "???":

        print("*CRASH*")
        webbrowser.open("https://www.youtube.com/watch?v=dQw4w9WgXcQ")
        break

    elif user_input == "QUIT":
        break

    else:
        print("I don't understand your input..")

print ("Thanks for the drive!")