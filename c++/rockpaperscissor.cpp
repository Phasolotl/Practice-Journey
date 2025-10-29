#include <iostream>
#include <ctime>

using namespace std;

char player_input();
void show_choice(char choice);
char computer_input();
void game_result(char player, char computer);

int main()
{
    char player;
    char computer;
    char choice;

GAME:

    player = player_input();
    cout << "Your choice: ";
    show_choice (player);

    computer = computer_input();
    cout << "Your opponent's choice: ";
    show_choice (computer);

    game_result(player, computer);

LOOP:

    do 
    {
    cout << "Play Again? Y/N" << endl;
    cin >> choice;

    cin.clear();
    fflush(stdin);

    if (choice == 'Y')
        {
        goto GAME;
        }
    else if (choice == 'N')
        {
        cout << "Thanks for playing!\n";
        }
    else
        {
        cout << "Wrong input, please input the correct choice!\n";
        goto LOOP;
        }
    } 
    while (choice != 'N');

    return 0;
}

char player_input()
{
    char player;
    cout << "****** ROCK PAPER SCISSOR ******\n";
    
    do{
        cout << "Pick your choice:\n"
             << "'R' = Rock\n"
             << "'P' = Paper\n"
             << "'S' = Scissor\n"
             << "Input: ";
    cin >> player;

    cin.clear();
    fflush(stdin);

    }while(player != 'R' && player != 'P' && player != 'S');

    return player;
}

char computer_input()
{
    short max_value = 3;
    short min_value = 1;
    
    srand(time(NULL));
    int num = rand() % max_value + min_value;

    switch(num)
    {
        case 1: return 'R';
        case 2: return 'P';
        case 3: return 'S';
    }
}

void show_choice(char choice)
{
    switch(choice)
    {
        case 'R': cout << "Rock\n";
            break;
        case 'P': cout << "Paper\n";
            break;
        case 'S': cout << "Scissor\n";
            break;
    }
}

void game_result(char player, char computer)
{
    switch(player)
    {
        case 'R': if (computer == 'R')
                {
                cout << "It's a tie!\n";
                }
                  else if (computer == 'P')
                {
                cout << "You lost...\n";
                }
                  else
                {
                cout << "YOU WON!!!!!\n";
                }
            break;
        case 'P': if (computer == 'R')
                {
                cout << "YOU WON!!!!!\n";
                }
                  else if (computer == 'P')
                {
                cout << "It's a tie!\n";
                }
                  else
                {
                cout << "You lost...\n";
                }
            break;
        case 'S': if (computer == 'R')
                {
                cout << "You lost...!\n";
                }
                  else if (computer == 'P')
                {
                cout << "YOU WON!!!!!!\n";
                }
                  else
                {
                cout << "It's a tie!\n";
                }
            break;
    }
}