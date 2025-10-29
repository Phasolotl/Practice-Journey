#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void func() 
{
    int min_value = 1;
    int max_value = 6;

    srand (time(0));
        int dice_number_one = (rand() % (max_value - min_value + 1)) + min_value;
        int dice_number_two = (rand() % (max_value - min_value + 1)) + min_value;
        int dice_number_three = (rand() % (max_value - min_value + 1)) + min_value;
    
    cout << "Your dice rolled: " << endl
         << dice_number_one << endl
         << dice_number_two << endl
         << dice_number_three << endl;

    short luck = (dice_number_one + dice_number_two + dice_number_three) / 3;

    if (luck > 3) {
        cout << "Your Lucky!" << endl;
    }

    else if (luck < 3) {
        cout << "Your not lucky.." << endl;
    }

    else if (luck == 3) {
        cout << "Your neutral lucky." << endl;
    }
    
}

int main() 
{

    cout << "Welcome to Gambling! \n \n";

    func();

    char choice;

    do {
    cout << "Roll again? Y/N" << endl;
    cin >> choice;

    if (choice == 'Y'){
        func();
        }
    else if (choice == 'N'){
        cout << "Thanks for participating!\n";
        }
    }while (choice != 'N');

    return 0;
}


