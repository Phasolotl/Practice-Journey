#include <iostream>
#include <string>

using namespace std;

int main() {

    int loop;
    cout << "Enter how much you want to pat this cat: ";
    cin >> loop;

    for(int i = loop; i >= 0; i--){
        cout << "Meow! \n";
    }

    return 0;
}