#include <iostream>
#include "function.h"

using namespace std;

int main() {

    loadingBar();
    system("cls");
    cout << "\n\n\t\t************** Welcome to A2 Quiz System ***********" << endl;
    int ch;
    while (true) {
        cout << "\n\t\t\t 1.ADMIN";
        cout << "\n\t\t\t 2.STUDENT";
        cout << "\n\n\t\tEnter your choice: ";
        cin >> ch;
        loadingBar();
        system("cls");

        switch (ch) {
            case 1: {
                system("cls");
                //if(m.menu3() ==1)
                {
                    menu();
                }
                break;
            }
            case 2: {
                //if(m.menu3() ==1)
                {
                    menu2();
                }
                break;
            }
            default: {
                cout << "\n\n\t\tIncorrect input. Please enter again" << endl;
                break;
            }
        }
    }
    getch();
    return 0;
}
