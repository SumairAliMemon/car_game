//// 22i-2709-DataProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
#include <iostream>
#include <conio.h>
#include <windows.h>
#include"Header.h"
using namespace std;

void playSound() {
    Beep(500, 150);  // Frequency: 1000 Hz, Duration: 200 milliseconds
}


// Define gotoxy for Windows console
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Define setColor for Windows console
void setColor(int attributes) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attributes);
}

void drawMenu(int selectedOption, GridGraph& grid) {
    // Get the size of the console window
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    // Calculate the center position for the title and menu
    int centerX = consoleWidth / 2;
    int centerY = consoleHeight / 2;

    // Display "Car game" above the menu
    gotoxy(centerX - 4, centerY - 3);  // Centered position for "Car game"
    setColor(FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    cout << " MEMO CARS";
    setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);

    // Display menu options
    for (int i = 1; i <= 4; ++i) {
        gotoxy(centerX - 8, centerY - 2 + i);  // Centered position for menu options

        if (i == selectedOption) {
            setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
            std::cout << "> ";
        }
        else {
            setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
            std::cout << "  ";
        }

        switch (i) {
        case 1:
            cout << "1. Manual Game";
            break;
        case 2:
            cout << "2. Automatic Game";
            break;
        case 3:
            cout << "3. Exit";
            break;
        case 4:
            cout << "4. Leader_Board";
            break;
        }
    }
}


void displayMainpage() {
    cout << "\n\n\n\n";
    cout << "\t\t\t----------------------------------------------------------------------" << endl;
    cout << "\n\n";
    cout << CYAN << "\t\t\t\t\t\tWELCOME THE MEMO CAR " << RESET << endl;
    cout << "\n\n";
    cout << "\t\t\t----------------------------------------------------------------------" << endl;
    int a = 0;
    cin >> a;
    system("cls");
}
int main() {

    int selectedOption = 1; 
    displayMainpage();
          GridGraph graph;
          graph.importScore();


    while (true) {
        drawMenu(selectedOption, graph);
           
        char key = _getch();
        switch (key) {
        case 72:

            playSound();
            selectedOption = (selectedOption > 1) ? selectedOption - 1 : 4;
            break;
        case 80:
                playSound();
            selectedOption = (selectedOption < 4) ? selectedOption + 1 : 1;
            break;
        case 0x0D:  
      
                playSound(); 
            switch (selectedOption) {
            case 1:
                   graph.GamePlay();

                break;
            case 2:

                graph.AutomaticGame();
        

                break;
            case 3:
                //graph.Imp
                graph.Export();
                return 1 ;
                break;
                
            case 4:
                system("cls");
                cout << "\t\t\t\t\t\t\t LEADER BOARD \n\n\n\n";

                graph.scoreStored->display(graph.scoreStored->root);
                int a = 0;
                cin >> a;

                break;
            }
            break;
        }

        system("cls");  // Clear the console screen
    }
   
    
    return 0;
}
