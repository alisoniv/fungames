#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
using namespace std;

//game of rock paper scissors

int main(){
    //first c++ program

    int computerScore, playerScore;
    string worthless;
    srand((unsigned) time(NULL));

    cout << "Welcome to Rock, Paper, Scissors!\n";
    cout << "Type any word to start: ";
    cin >> worthless;
    //requests input but input doesnt matter, serves as flow blocker

    while (true){
    cout << "rock\n";
    sleep(1);
    cout << "paper\n";
    sleep(1);
    cout << "scissors\n";
    sleep(1);
    
    //Determine Computer's move 
    int computerMove = rand() % 3;
    // 0 = rock, 1 = paper, 2 = scissors
    cout << "Shoot! Enter move (0 = rock, 1 = paper, 2 = scissors, 5 = exit game): ";

    //get input from user
    int input;
    cin >> input;
    int userMove = input;
    if (input == 5){break;}
    
    //display computer's move
    if (computerMove == 0) {
        cout << "\nComputer chose Rock\n";
    }else if (computerMove == 1){
        cout << "\nComputer chose Paper\n";
    }else {
        cout << "\nComputer chose Scissors\n";
    }

    if ((computerMove - userMove == 1) || (computerMove - userMove == -2)) {
        cout << "Computer Wins\n";
        computerScore ++;
    } else if ((userMove - computerMove == 1) || (userMove - computerMove == -2)){
        cout << "User Wins\n";
        playerScore++;
    } else {
        cout  << "Tie\n";
    }
    cout << "Computer Score: " << computerScore << " Your Score: " << playerScore << "\n";
        //display final score
    }

}

