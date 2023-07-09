#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//return 0 for valid move, 1 for incorrect move
int checkinputforErrors(int dummyvalues[9][9],int num, int row, int column){
    int error;
    for (int i=0; i < 9; i++) {
            //check horizontal
            if (dummyvalues[i][column] == num){
                error++;
            }
            //check vertical
            if (dummyvalues[row][i] == num ){
                error++;
            }
    }
    
    //check 3x3 box
    if (error > 0){
        return 0;
    } else {
        return 1;
    }
    
}

//pass in array of correct numbers on board to this function
void updateBoard(int ugamevalues[9][9], string ugameboard){
    //prints board to terminal
    int x = 0;
    for (int r = 0; r < 9; r++){
        x+=41;
        for (int c = 0; c < 9; c++) {
            if (x < 80){
            ugameboard[x] = ugamevalues[r][c] + 48;}
            else {
            ugameboard[x-1] = ugamevalues[r][c] + 48;}
            x+=4;
        }
    }
    cout << ugameboard;
}

//return 0 for valid board, 1 for incorrect board
int checkCompleteBoardforErrors(int dummyvalues[9][9]){
    //iterate through game board array to check correct input

    //after checks, should be 0 if no error
    int error;

    for (int i=0; i < 9; i++) {
        for (int j = 0; j < 9; j++ ) {
            for (int x = 0; x < 9; x++) {
                //check vertical
                if ((dummyvalues[i][j] == dummyvalues[i][x]) && (x!=j)){
                    error++;
                    cout << error;
                }

                //check horizontal
                if ((dummyvalues[j][i] == dummyvalues[x][i] ) && (x!=j)){
                    error++;
                    cout << error;
                }
            }
        } 
    }
    cout << "\nLast: " << error;
/*
//check 3x3 boxes
for (int m = 0; m < 3; m+=3){
    for (int w = 0; w < 3; w+=3){
        int checker[9];
        //for each box, put all values into temp array, then check each num for uniqueness
        int x = 0;
            for (int y = 0; y < 3; y++){
                for (int n = 0; n < 3; n++){
                checker[x] = dummyvalues[m+y][w+n];
                x++;
                }
            }
        for (int b = 0; b < 9; b++){
            for (int a = 0; a < 9; a++){
            if (checker[b] == checker[a]){
                error++;
                }
            }
        }
    }
}*/

    if (error > 0){ return 1;
    } else {return 0;}

}

int main(){

    //game loop
    string gameBoard = "\n-------------------------------------\n|   |   |   |   |   |   |   |   |   |\n-------------------------------------\n|   |   |   |   |   |   |   |   |   |\n------------------------------------- \n|   |   |   |   |   |   |   |   |   |\n------------------------------------- \n|   |   |   |   |   |   |   |   |   |\n------------------------------------- \n|   |   |   |   |   |   |   |   |   |\n------------------------------------- \n|   |   |   |   |   |   |   |   |   |\n------------------------------------- \n|   |   |   |   |   |   |   |   |   |\n------------------------------------- \n|   |   |   |   |   |   |   |   |   |\n------------------------------------- \n|   |   |   |   |   |   |   |   |   |\n------------------------------------- ";
    int gamevalues[9][9];
    int gamechoice;
    int lives = 3;
    cout << "Welcome to Sudoku. Choose your starting game board \n Easy 1, Medium 2, Hard 3: ";
    cin >> gamechoice;

    // intialize gamevalues into gameBoard
    //can create a function to randomly generate this
    if (gamechoice == 1 ){

        //dummy board for testing
        gamevalues[0][1] = 7;
        gamevalues[0][4] = 2;
        gamevalues[0][7] = 4;
        gamevalues[0][8] = 6;
        gamevalues[1][1] = 6;
        gamevalues[1][6] = 8;
        gamevalues[1][7] = 9;
        gamevalues[2][0] = 2;
        gamevalues[2][3] = 8;
        gamevalues[2][6] = 7;
        gamevalues[2][7] = 1;
        gamevalues[2][8] = 5;
        gamevalues[3][1] = 8;
        gamevalues[3][3] = 4;
        gamevalues[3][4] = 9;
        gamevalues[3][5] = 7;
        gamevalues[4][0] = 7;
        gamevalues[4][1] = 1;
        gamevalues[4][7] = 5;
        gamevalues[5][3] = 1;
        gamevalues[5][4] = 3;
        gamevalues[5][6] = 4;
        gamevalues[5][7] = 8;
        gamevalues[6][0] = 6;
        gamevalues[6][1] = 9;
        gamevalues[6][2] = 7;
        gamevalues[6][5] = 2;
        gamevalues[6][8] = 8;
        gamevalues[7][1] = 5;
        gamevalues[7][2] = 8;
        gamevalues[7][7] = 6;
        gamevalues[8][0] = 4;
        gamevalues[8][1] = 3;
        gamevalues[8][4] = 8;
        gamevalues[8][7] = 7;
    }

    while (true) {
        updateBoard(gamevalues, gameBoard);
        //welcome to sudoku
        int number;
        cout << "\nEnter number: ";
        cin >> number;
        
        int row, column;
        cout << "\nEnter the row (0-9) ";
        cin >> row;
        cout << "\nEnter the column number (0-9): ";
        cin >> column;
        int tempvalues[9][9];
        
        for (int x; x < 9; x++) {
            for (int y; y < 9; y++) {
                tempvalues[x][y] = gamevalues[x][y];
            }
        }
        tempvalues[row][column] = number;
        
        
        if (checkinputforErrors(tempvalues) == 0){
            cout << "\nCorrect move";
        }else {
            cout << "\nIllegal move, try again";
            lives--;
        }
        
        if (lives <= 0){
            cout << "\nAll lives lost. Game over.";
            break;
        }
        
    }

    return 0;
}












