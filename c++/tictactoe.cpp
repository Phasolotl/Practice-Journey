#include <iostream>
#include <ctime>

using namespace std;

void drawBoard(char *spaces);
void playerInput(char *spaces, char player);
void computerInput(char *spaces, char computer);
bool yieldResult(char *spaces, char player, char computer);
bool determineTie(char *spaces);

int main()
{

GAME:

    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);

    while(running)
    {
        playerInput(spaces, player);
        drawBoard(spaces);
        if (yieldResult(spaces, player, computer)) 
        {
            running = false;
            break;
        }
        else if(determineTie(spaces)) 
        {
            running = false;
            break;
        }

        computerInput(spaces, computer);
        drawBoard(spaces);
        if (yieldResult(spaces, player, computer)) 
        {
            running = false;
            break;
        }
        else if(determineTie(spaces)) 
        {
            running = false;
            break;
        }
    }

LOOP: // i cannot get this to work..

   /* do {
    cout << "Play Again? Y/N\n";
    cin >> choice;
    choice = toupper(choice);

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
*/
    return 0;
}

void drawBoard(char *spaces)
{
    cout << endl
         << "     |     |     \n"
         << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  \n"
         << "_____|_____|_____\n"
         << "     |     |     \n"
         << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  \n"
         << "_____|_____|_____\n"
         << "     |     |     \n"
         << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  \n" 
         << "     |     |     \n"
         << endl; // this is art <3
}
void playerInput(char *spaces, char player)
{
    int number;
    do
    {
        cout << "Place your mark (1-9)\n";
        cin >> number;
        number--;

        cin.clear();
        fflush(stdin);

        if(spaces[number] == ' ')
        {
            spaces[number] = player;
            break;
        }

    }while (~number > 0 || ~number < 8); // you can only input values between 0 to 8 (after decrements)
}
void computerInput(char *spaces, char computer)
{
    int number;
    srand(time(NULL));

    while (true)
    {
        number = rand() % 9;

        if (spaces[number] == ' ')
        {
            spaces[number] = computer;
            break;
        }

    }
}
bool yieldResult(char *spaces, char player, char computer)
{
    // horizontal conditions

    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2]))

        spaces[0] == player ? cout << "YOU WIN! GG!\n" : cout << "You lost! Skill issue!\n";

    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5]))

        spaces[3] == player ? cout << "YOU WIN! GG!\n" : cout << "You lost! Skill issue!\n";

    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8]))

        spaces[6] == player ? cout << "YOU WIN! GG!\n" : cout << "You lost! Skill issue!\n";

    // vertical conditions

    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6]))

        spaces[0] == player ? cout << "YOU WIN! GG!\n" : cout << "You lost! Skill issue!\n";

    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7]))

        spaces[1] == player ? cout << "YOU WIN! GG!\n" : cout << "You lost! Skill issue!\n";

    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8]))

        spaces[2] == player ? cout << "YOU WIN! GG!\n" : cout << "You lost! Skill issue!\n";

    // diagonal conditions
    
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8]))

        spaces[0] == player ? cout << "YOU WIN! GG!\n" : cout << "You lost! Skill issue!\n";

    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6]))

        spaces[2] == player ? cout << "YOU WIN! GG!\n" : cout << "You lost! Skill issue!\n";

    else
    {
        return false; 
    }
    // there's a better way for this right?

    return true;
}
bool determineTie(char *spaces)
{
    for (int i = 0; i < 9; i++)
    {
        if(spaces[i] == ' ');
        {
            return false;
        }
    }

    cout << "It's a tie...\n";

    return true;
}