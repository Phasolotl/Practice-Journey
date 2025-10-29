#include <iostream>
using std::cout; 
using std::cin;

void func() { 
   
    char operat;
    float num1;
    float num2;
    float result;

    cout << "Enter thy calculations: ";
    cin >> num1 >> operat >> num2;

    switch(operat) {
        case '+':
            result = num1 + num2;
            cout << "Thy result: " << result << '\n';
            break;
        case '-':
            result = num1 - num2;
            cout << "Thy result: " << result << '\n';
            break;
        case '*':
            result = num1 * num2;
            cout << "Thy result: " << result << '\n';
            break;
        case '/':
            result = num1 / num2;
            if (num2==0) {
                    cout << "ERROR: Your calculator exploded" << '\n';
                    break;
                }
            cout << "Thy result: " << result << '\n';
            break;
        default:
            cout << "ERROR: what the fuck?" << '\n';
            break;
    }

LOOP:

    char choice;
    cout << "Calculate again? Y/N" << '\n';
    cin >> choice;

    getchar();

    if(choice == 'n' || choice == 'N') {
        exit;
    }
    else if(choice == 'y' || choice == 'Y') {
        func();
    }
    else {
        cout << "That's not right, try again!";
        goto LOOP;
    }

}

int main() {

    cout << "---------- SIMPLE CALCULATOR (FUCK YOU!) ----------\n";

    func ();

    cout << "---------------------------------------------------\n";

    return 0;
}