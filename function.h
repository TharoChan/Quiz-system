//************************************************************************//
//			      HEADER FILES USED IN PROJECT          		          //
//************************************************************************//

#include <iostream>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>

using namespace std;
///================Login Program=============///
class Manager {
    private:
        char userName[30];
        char password[30];
    public:
        void getData();
        void Signup();
        int menu3();
        bool IsLoggedIn();
        friend void displayGrade();
}m;
void loadingBar();

void Manager::getData() {
    cout << "\t\tEnter Username : ";
    cin >> userName;
    cout << "\t\tEnter Password : ";
    cin >> password;
}

void Manager::Signup() {
    cout << "\n\n\t\tPlease Register...\n\n";
    getData();
    system("cls");

    ofstream fout;
    fout.open("Register.txt", ios::out | ios::app);
    fout << userName << endl;
    fout << password << endl;
    fout.close();
    loadingBar();

    cout << "\n\n\t\tSuccessfully Registered You can login now.\n\n";
}

bool Manager::IsLoggedIn() {
    char un[30], pw[30];

    ifstream fin("Register.txt", ios::in | ios::binary);
    cout << "\n\n\n\t\t\tPlease login\n\n";
    getData();
    loadingBar();
    system("cls");

    int flag = 0;
    while (!flag) {
        fin >> un;
        fin >> pw;

        int result1 = strncmp(un, m.userName, 30);
        int result2 = strncmp(pw, m.password, 30);

        if (result1 == 0 && result2 == 0) {
            return true;
            flag = 1;
        } else {
            return false;
        }
    }
    fin.close();
}

int Manager::menu3() {
    int ch;
    int flag = 'n';
    while (flag) {
        cout << "\n\n\t\t ******************  LOGIN  *****************\n\n";
        cout << "\t\t\t 1.Login";
        cout << "\n\t\t\t 2.Register";
        cout << "\n\t\t\t 0.Exit\n\n\t\t";
        cout << "Enter Your Choice : ";
        cin >> ch;
        system("cls");

        switch (ch) {
            case 1: {
                int status = m.IsLoggedIn();

                if (!status) {
                    cout << "\n\n\t\tLogin Failed. Please Register First! \n\n";
                }
                else {
                    cout << "\n\n\t\t\tWelcome " << m.userName << endl;
                    flag = 'y';
                    return 1;
                }
            }
            break;
            case 2: {
                m.Signup();
            }
                break;
            case 0: {
                exit(0);
            }
            default: {
                cout << "\n\t\tIncorrect input, Please enter again" << endl;
            }
                break;
        }
    }
}
///=====================END OF REGISTRATION======================///
///==============================================================///

///=======================ADMIN CLASS==========================///
///==============================================================///
class Admin {
    public: char question[100];
    char answer[100];
    int mark;
    int qNumber;

    void getData();
    void display();
}t;
///====================STUDENT CLASS=======================
///==============================================================
class Student: public Admin {
    public:
        char sAns[100];
        int scordMark;

    void getData();
    int takeExam();
    void displayQus();
}s;

void option2();
void menu2();
void displayGrade();

void menu2() {
    int c;
    option2();
    cin >> c;
    system("cls");
    while (c) {
        switch (c) {
        case 1:
            s.takeExam();
            break;
        case 2:
            displayGrade();
            break;
        case 0:
            exit(1);
        default:
            cout << "\n\t\tPlease enter the correct choice\n";
            break;
        }

        getch();
        system("cls");
        option2();
        cin >> c;
        system("cls");

    }
}

void Student::displayQus() {
    cout << "\n\n   _______________________________________________________________\n";
    cout << "\n\tQuestion no." << t.qNumber << " : " << t.question << " (point: " << t.mark << ")\n";
}

void Student::getData() {
    cout << "\n\tEnter your answer : ";
    cin.ignore();
    cin.get(sAns, 100);
}

void option2() {
    cout << "\n\n\t\t\t1.Take Exam";
    cout << "\n\t\t\t2.Grade";
    cout << "\n\t\t\t0.Exit";
    cout << "\n\n\t\t\tEnter your choice: ";
}

int Student::takeExam() {
    ///Count the time start to finish the exam
    cout << "\n\n\t\t************* EXAM ************";
    clock_t start;
    double duration;
    start = clock();

    fstream fin("q.txt", ios::in | ios::out | ios::binary);
    while (fin.read((char * ) & t, sizeof(t))) {
        displayQus();
        getData();

        int a = strncmp(t.answer, s.sAns, 100); //compeering two strings
        if (a == 0) {
            scordMark = scordMark + t.mark;
            cout << "\n\t\tCorrect" << endl;
        } else {
            cout << "\n\t\tIncorrect" << endl;
        }
    }
    fin.close();

    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    cout << "\n\n\t\tYou Took : " << duration << " seconds" << endl;
}

void disBar();
void disBar(int n) {
    int a = 177, b = 219;
    printf("\t\t");
    for (int i = 1; i < 20; i++) {
        printf("%c", a);
    }
    printf("\r");
    printf("\t\t");
    for (int i = 1; i < n; i++) {
        printf("%c", b);
        Sleep(50);
    }
}

void displayGrade() {
    ///display the grade using percentage and bar
    float mul;
    float per;
    float totalMark = 0;

    fstream fin("q.txt", ios::in | ios::out | ios::binary);
    while (fin.read((char * ) & t, sizeof(t))) {
        totalMark = totalMark + t.mark;
    }
    fin.close();

    mul = s.scordMark * 100;
    per = (float)(mul / totalMark);

    cout << "\n\n\t\t\tGRADE";
    cout << "\n\n\t***************************************************";
    cout << "\n\n\t\tNAME : " << m.userName;

    cout << "\n\n\t\tPercentage " << per << "%" << endl; //display the grade by percentage
    if (per > 0 && per < 20) //display the grade by bar
    {
        disBar(4);
        cout << "\n\n\t\tGRADE : F \n\n\t\tFailed";
    } else if (per >= 20 && per < 40) {
        disBar(8);
        cout << "\n\n\t\tGRADE : D \n\n\t\tFair";
    } else if (per >= 40 && per < 60) {
        disBar(12);
        cout << "\n\n\t\tGRADE : C \n\n\t\tGOOD!";
    } else if (per >= 60 && per < 80) {
        disBar(16);
        cout << "\n\n\t\tGRADE : B \n\n\t\tVERY GOOD!";
    } else if (per >= 80 && per <= 100) {
        disBar(20);
        cout << "\n\n\t\tGRADE : A \n\n\t\tEXELENT!";
    }
    cout << "\n\n\t***************************************************\n\n";
    system("pause");
}

///===================================================================///
///==========================END OF STUDENT CLASS=====================///
///===================================================================///

void menu();
void options();
void Search();
void add();
void displayAll();
void modify();
void Delete();
void Trash();

void menu() {
    int ch;
    options();
    cin >> ch;
    system("cls");
    while (ch) {
        switch (ch) {
        case 1:
            add();
            break;
        case 2:
            Search();
            break;
        case 3:
            displayAll();
            break;
        case 4:
            modify();
            break;
        case 5:
            Delete();
            break;
        case 6:
            Trash();
            break;
        case 0:
            exit(1);
        default:
            cout << "\t\tWrong Input please enter the correct value...";
        }
        system("pause");
        system("cls");
        options();
        cin >> ch;
        system("cls");
    }
}

void Admin::getData() {
    cout << "\n\n\t\tEnter the question no : ";
    cin >> qNumber;
    cout << "\n\t\tEnter the Question : ";
    cin.ignore();
    cin.get(question, 100);

    cout << "\n\t\tEnter the answer : ";
    cin.ignore();
    cin.get(answer, 100);
    cout << "\n\t\tEnter the mark : ";
    cin >> mark;
}

void Admin::display() {
    cout << "\n   _______________________________________________________________";
    cout << "\n\tQuestion no." << qNumber << " : " << question << " (point: " << mark << ")";
    cout << "\n\tAnswer        : " << answer << "\n\n\n";
}

void options() {
    cout << "\n\t\t\t***** MENU OF PROGRAM *****";
    cout << "\n\n\t\t\t 1. Add the Question...";
    cout << "\n\t\t\t 2. Search the Question...";
    cout << "\n\t\t\t 3. Display all Questions...";
    cout << "\n\t\t\t 4. Modify the Question...";
    cout << "\n\t\t\t 5. Delete the Question...";
    cout << "\n\t\t\t 6. View Deleted Questions...";
    cout << "\n\t\t\t 0. EXIT....";
    cout << "\n\n\t\t\tEnter Your Choice  : ";
}

void add() {
    char ch = 'y';
    ofstream fout("q.txt", ios::out | ios::app | ios::binary);

    while (ch == 'y') {
        t.getData();
        fout.write((char * ) & t, sizeof(t));
        cout << "\n\t\tDo you want to add more (y/n) : ";
        cin >> ch;
    }
    fout.close();
}

void Search() {
    ifstream fin("q.txt", ios::in | ios::binary);
    int qNo;

    cout << "\n\n\t\tEnter the question no to search : ";
    cin >> qNo;
    loadingBar();
    system("cls");

    char found = 'n';
    while (fin.read((char * ) & t, sizeof(t))) {
        if (t.qNumber == qNo) {
            t.display();
            found = 'y';
        }
    }
    if (found == 'n') cout << "\n\n\t\tQuestion No." << qNo << " is not in the file...\n";
    fin.close();
}

void displayAll() {
    loadingBar();
    system("cls");
    cout << "\n\n\t\t********* ALL QUESTIONS AND ANSWERS *********\n\n";
    ifstream fin("q.txt", ios::in | ios::binary);
    while (fin.read((char * ) & t, sizeof(t))) {
        t.display();
    }
    fin.close();
}

void modify() {
    int qNo;
    fstream fio("q.txt", ios::in | ios::out | ios::binary | ios::ate);
    fio.seekg(0);

    cout << "\n\n\t\tEnter the question number to be modified : ";
    cin >> qNo;
    loadingBar();
    system("cls");

    char found = 'n';
    while (fio) {
        int loc = fio.tellg();
        fio.read((char * ) & t, sizeof(t));
        if (t.qNumber == qNo) {
            t.getData();
            found = 'y';
            fio.seekg(loc);
            fio.write((char * ) & t, sizeof(t));
            cout << "\n\n\t\tYour record of question No." << qNo << " has been updated...\n";

        }
    }
    if (found == 'n') cout << "\n\n\t\tQuestion No." << qNo << " is not in the file...\n";
    fio.close();
}

void Delete() {
    int qN;
    char found = 'n';
    fstream fio("q.txt", ios::in | ios::out | ios::binary);
    ofstream fout("temp.txt", ios::out | ios::binary | ios::app);
    ofstream out("trash.txt", ios::out | ios::binary | ios::app);

    cout << "\n\n\t\tEnter the Question number to be deleted : ";
    cin >> qN;
    loadingBar();
    system("cls");

    while (fio.read((char * ) & t, sizeof(t))) {
        if (t.qNumber == qN) {
            out.write((char * ) & t, sizeof(t));
            found = 'y';
        } else {
            fout.write((char * ) & t, sizeof(t));
        }
    }
    if (found == 'n') cout << "\n\n\t\tQuestion No." << qN << " is not in the file...\n ";
    fio.close();
    fout.close();
    remove("q.txt");
    rename("temp.txt", "q.txt");
}

void Trash() {
    ifstream out("trash.txt", ios::in | ios::binary);
    while (out.read((char * ) & t, sizeof(t))) {
        t.display();
    }
    out.close();
}

///===================================================================///
///========================== Loading Screen =========================///
///===================================================================///

void loadingBar() {
    char a = 177, b = 219;

    printf("\n\n\t\t\t    Loading...\n\n");
    printf("\t\t\t");

    for (int i = 0; i < 18; i++)
        printf("%c", a);

    printf("\r");
    printf("\t\t\t");

    for (int i = 0; i < 18; i++) {
        printf("%c", b);

        Sleep(30);
    }
}
