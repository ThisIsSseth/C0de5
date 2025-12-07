
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int ROWS, COLS, MINES;
int** board; 
bool** revealed;
bool** flagged;
const int MAX_USERS = 100; 

struct User {
    string player_username;
    string player_password;
};

User users[MAX_USERS]; 
int userCount = 0; 

struct GameState {
    string current_player;
    int rows;
    int cols;
    int bombs;
    int** board; // تغییر از char** به int**
    char** flags;
    bool** revealed;
};

GameState gameState;

void main_list();
void sign_up();
void login();
void credits();
void privacy();
void exit_game();
void user_menu();
// void resume_game();
void how_to_play();
void new_game();
void board_generator(int,int,int);
void reveal_generator(int n, int m);
void board_checker(int,int);
void board_printer(int,int);
void flag(int, int);
// void save_game();
void load_game();
bool is_game_over();
bool makeMove(int r, int c);
void autoReveal(int r, int c);
void playGame();

int main(){
    cout << "\nloading...";
    cout << "\nwelcome to our game :) \nremember : through the game you should enter the number of option you want to use...\n\n";
    main_list();
    return 0;
}

void main_list(){
    int option;
    while (true){
        cout << "\n--- MAIN MENU ---\n1)Sign up\n2)Login\n3)Credits\n4)Exit\nplease enter the number of option:";
        cin >> option; 
        switch (option){
            case 1 :
                {
                    sign_up();
                break;
                }
            case 2 :
                {
                    login();
                break;
                }
            case 3 :
                {
                    credits();
                break;
                }
            case 4 :
                {
                    exit_game();
                return;
                }    
            default:
                cout <<"\nYou entered a WRONG number. Please try again." << endl;
                break;
        }
    }
}

void sign_up(){
    if (userCount >= MAX_USERS) {
        cout << "\nUser limit reached. Cannot sign up." << endl;
        return;
    }

    User newUser;
    cout << "\nEnter username: ";
    cin >> newUser.player_username;

    for (int i = 0; i < userCount; i++) {
        if (users[i].player_username == newUser.player_username) {
            cout << "\nUsername already exists. Please choose another one." << endl;
            return;
        }
    }

    cout << "\nEnter password: ";
    cin >> newUser.player_password;

    users[userCount] = newUser;
    userCount++;
    cout << "\nSign up successful!" << endl;
}

void login(){
    string username, password;
    cout << "\nEnter username: ";
    cin >> username;

    for (int i = 0; i < userCount; i++) {
        if (users[i].player_username == username) {
            cout << "\nEnter password: ";
            cin >> password;
            gameState.current_player = username;
            if (users[i].player_password == password) {
                cout << "\nLogin successful!" << endl;

                user_menu();
                return;
            } else {
                cout << "\nIncorrect password." << endl;
                return;
            }
        }
    }

    cout << "\nUsername not found. Please sign up." << endl;
}

void credits(){
    int option;
    while(true){
        cout << "\n--- Credits ---\n1)About Us\n2)Privacy Policy\n3)Contact\n4)Back\n";
        cin >> option;
        switch (option){
            case 1 :
                cout << "\nThis game was created by Mobina Seifodin and Setayesh Ziyaee as their university project.\n";
                break;
            case 2 :
                privacy();
                break;
            case 3 :
                cout << "\nYou can contact us by this email: mobinaseif84@gmail.com\n";
                break;
            case 4 :
                main_list();
                return;    
            default:
                cout << "Invalid option.";
                break;
        }
    }
}

void privacy(){
    cout << "\nIn this game, we are committed to protecting your privacy and safeguarding your personal information."
         << "We use your data to provide and improve the Service. By using the Service, you agree to the collection"
         << " and use of information in accordance with this policy.\nWHAT INFORMATION DO WE COLLECT ABOUT YOU?\n"
         << "We collect and process the information you provide when you use the applications. This includes technical"
         << " and behavioral information about your use of the applications.\nHOW WILL WE USE THE INFORMATION ABOUT YOU?\n"
         << "We use your information to provide applications and improve them. Where it is in our legitimate interest, we use your "
         << "information to, among other things, improve and develop applications and ensure your security.\n"
         << "HOW LONG DO WE KEEP YOUR INFORMATION?\nUntil we get our score :)\n"
         << "YOUR RIGHTS\nIn certain circumstances, you have rights in relation to your information,"
         << " such as the right of removal and the right of access.\n";
}

void exit_game(){
    cout << "\nClosing the game...\nWish you played well :)\nGood Bye!";
    return;
}

void user_menu(){
    int option;
    while (true){
        cout << "\n--- USER MENU ---\n1)Continue\n2)New game\n3)How to play\n4)Language\n5)exit\nplease enter the number of option:";
        cin >> option; 
        switch (option){
            case 1 :
                // resume_game();
                break;
            case 2 :
                new_game();
                break;
            case 3 :
                how_to_play();
                break;  
            case 4 :
                cout <<"\nSorry but this game only supports the English language.\n";
                break;
            case 5 :
                cout << "\nGoing back to the main menu...\n";
                return;              
            default:
                cout <<"\nYou entered a WRONG number. Please try again." << endl;
                break;
        }
    }
}

void new_game(){
    cout << "\n--- New Game ---\nChoose one:\n1. Easy (5x5)\n2. Medium (10x10)\n3. Hard (15x15)\n4. Custom\n5. Exit\n";
    int n;
    cin >> n;
    switch (n){
        case 1:
            board_generator(5, 5, 5);
            ROWS = 5; COLS = 5; MINES = 5;
            playGame();
            break;
        case 2:
            board_generator(10, 10, 15);
            ROWS = 10; COLS = 10; MINES = 15;
            playGame();
            break;
        case 3:
            board_generator(15, 15, 60);
            ROWS = 15; COLS = 15; MINES = 60;
            playGame();
            break;
        case 4:
            cout << "\nEnter the number of rows: ";
            int row;
            cin >> row;
            cout << "\nEnter the number of columns: ";
            int clm;
            cin >> clm;
            cout << "\nEnter the number of bombs: "; 
            int bomb;
            cin >> bomb;
            board_generator(row, clm, bomb);
            playGame();
            break;
        case 5:
            exit_game();
            break;
        default:
            cout << "Invalid input...\n";
            break;
    }
}

void how_to_play(){
    cout << "\n--- How To Play ---\nThe objective of the game is to clear all the cells without hitting any mines."
         << "\nClick on a cell to open it. If it's a mine, the game is over. If it's not, it will show the number of bombs in adjacent cells."
         << "\nYou can flag suspicious cells with a right-click (or the flag command) to mark potential mines."
         << "\nThe game continues until you clear all non-mined cells or hit a mine."
         << "\nGood luck!";
}

void playGame() {
    bool gameOver = false;
    while (!gameOver) {
        cout << "1-move(r c)  2-flag(F r c)  3-save(S)  4-exit(Q)\n";
            for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1 || board[i][j] == 0) {
                cout << "X ";
            } else if (board[i][j] < -1) {
                cout << "P ";
            } else {
                cout << board[i][j] - 1 << " ";
            }
        }
        cout << endl;
    }
        char command;
        cin >> command;
        switch (command){
            case '1':
                cout <<"please enter row and column: ";
                int r, c;
                cin >> r >> c;
                gameOver = makeMove(r, c);
                if (is_game_over()) {
                    break;
                }
                break;
            case '2':
                cout << "please enter coordinates of the place you want to flag: ";
                cin >> r >> c;
                flag(r, c);
                break;
            case '3':
                // save_game();
                break;
            case '4':
                cout << "exiting...\n";
                return;       
            default:
                cout << "Invalid option.";
                break;
        }
    }
}

void board_generator(int n, int m, int bomb_num) {
    board = new int*[n];
    int i = 0;
    for (; i < n; i++) {
        board[i] = new int[m];
    }

    for (i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = 0;
        }
    }
    srand(time(NULL));
    while (bomb_num > 0) {
        int x = rand() % n;
        int y = rand() % m;
        if (board[x][y] == 0) {
            board[x][y] = -1;
            bomb_num--;
        }
    }
    reveal_generator(n, m);
}

void reveal_generator(int n, int m) {
    revealed = new bool*[n];
    flagged = new bool*[n];
    int i = 0;
    for (; i < n; i++) {
        revealed[i] = new bool[m];
        flagged[i] = new bool[m];
    }

    for (i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            revealed[i][j] = false;
            flagged[i][j] = false;
        }
    }
}

void board_printer(int n, int m){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == -1 || board[i][j] == 0) {
                cout << "X ";
            } else if (board[i][j] < -1) {
                cout << "P ";
            } else {
                cout << board[i][j] - 1 << " ";
            }
        }
        cout << endl;
    }
    cout << "\nChoose an option below (1 to Reveal, 2 to Flag, 3 to Exit):\n";
    int option;
    cin >> option;
    if (option == 1) {
        int r, c;
        cout << "\nEnter row and column (0-based): ";
        cin >> r >> c;
        if (gameState.board[r][c] == -1) {
            cout << "\nGame Over! You hit a bomb!\n";
            exit_game();
        } else {
            gameState.revealed[r][c] = true;
            board_printer(r, c);
        }
    }
    else if (option == 2) {
        int r, c;
        cout << "\nEnter row and column to flag (0-based): ";
        cin >> r >> c;
        gameState.flags[r][c] = 'F';
        board_printer(r, c);
    } 
    else if (option == 3) {
        cout << "\nExiting game...\n";
        exit_game();
    }
}

void board_checker(int n, int m) {
    cout << "Enter the row number: ";
    int row;
    cin >> row;
    cout << "Enter the column number: ";
    int clm;
    cin >> clm;
    if (board[row][clm] == -2) {
        cout << "This cell is flagged. You can't open it.\n";
        return;
    }
    if (board[row][clm] == -1) {
        cout << "Game Over\n";
    } 
    else {
        int bomb_counter = 1;
        for (int i = row - 1; i <= row + 1; i++) {
            for (int j = clm - 1; j <= clm + 1; j++) {
                if (i >= 0 && i < n && j >= 0 && j < m && board[i][j] == -1) {
                    bomb_counter++;
                }
            }
        }
        board[row][clm] = bomb_counter;
    }
}

void flag(int n, int m) {
    cout << "Enter the row number to flag: ";
    int row;
    cin >> row;
    cout << "Enter the column number to flag: ";
    int clm;
    cin >> clm;
    if (board[row][clm] == -2) {
        cout << "This cell is already flagged. Removing the flag...\n";
        board[row][clm] = 0;
    } 
    else if(board[row][clm] == -3)
    {
        cout << "This cell is already flagged. Removing the flag...\n";
        board[row][clm] = -1;
    }
    else {
        if (board[row][clm] == -1) 
        board[row][clm] = -3;
        if (board[row][clm] == 0)
        board[row][clm] = -2;
        cout << "Flag placed on the cell.\n";
    }
}

// void save_game() {
    
//     ifstream file((gameState.current_player + "_save.txt").c_str());
//     if (!file) {
//         cout << "\nError opening file for saving." << endl;
//         return;
//     }

//     file << gameState.rows << " " << gameState.cols << " " << gameState.bombs << endl;
//     int i = 0;
//     for (; i < gameState.rows; i++) {
//         for (int j = 0; j < gameState.cols; j++) {
//             file << gameState.board[i][j] << " ";
//         }
//         file << endl;
//     }

//     for (i = 0; i < gameState.rows; i++) {
//         for (int j = 0; j < gameState.cols; j++) {
//             file << gameState.flags[i][j] << " ";
//         }
//         file << endl;
//     }

//     for (i = 0; i < gameState.rows; i++) {
//         for (int j = 0; j < gameState.cols; j++) {
//             file << gameState.revealed[i][j] << " ";
//         }
//         file << endl;
//     }

//     file.close();
//     cout << "\nGame saved successfully!" << endl;
// }

void load_game() {
    ifstream file(
        (gameState.current_player + "_save.txt").c_str());
    if (!file) {
        cout << "\nError opening file for loading." << endl;
        return;
    }

    file >> gameState.rows >> gameState.cols >> gameState.bombs;
    gameState.board = new int*[gameState.rows];
    gameState.flags = new char*[gameState.rows];
    gameState.revealed = new bool*[gameState.rows];
    int i = 0;
    for (; i < gameState.rows; i++) {
        gameState.board[i] = new int[gameState.cols];
        gameState.flags[i] = new char[gameState.cols];
        gameState.revealed[i] = new bool[gameState.cols];
    }

    for (i = 0; i < gameState.rows; i++) {
        for (int j = 0; j < gameState.cols; j++) {
            file >> gameState.board[i][j];
        }
    }

    for (i = 0; i < gameState.rows; i++) {
        for (int j = 0; j < gameState.cols; j++) {
            file >> gameState.flags[i][j];
        }
    }

    for (i = 0; i < gameState.rows; i++) {
        for (int j = 0; j < gameState.cols; j++) {
            file >> gameState.revealed[i][j];
        }
    }

    file.close();
    cout << "\nGame loaded successfully!" << endl;
}

bool is_game_over() {
    load_game();
    for (int i = 0; i < gameState.rows; i++) {
        for (int j = 0; j < gameState.cols; j++) {
            if (gameState.board[i][j] != -1 && !gameState.revealed[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool makeMove(int r, int c) {
    if (r < 0 || r >= ROWS || c < 0 || c >= COLS || revealed[r][c])
        return false;

    if (flagged[r][c]) {
        cout << "this block has been flagged\n";
        return false;
    }

    revealed[r][c] = true;

    if (board[r][c] == -1) {
        cout << "lost\n";
        return true;
    }

    if (board[r][c] == 0)
        autoReveal(r, c);

    return false;
}

void autoReveal(int r, int c) {
    if (r < 0 || r >= ROWS || c < 0 || c >= COLS || revealed[r][c])
        return;

    revealed[r][c] = true;

    // if (board[r][c] == 0) {
    //     int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    //     int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
    //     for (int i = 0; i < 8; i++)
    //         autoReveal(r + dr[i], c + dc[i]);
    // }
    {
        int bomb_counter = 1;
        for (int i = r - 1; i <= r + 1; i++) {
            for (int j = c - 1; j <= c + 1; j++) {
                if (i >= 0 && i < ROWS && j >= 0 && j < COLS && board[i][j] == -1) {
                    bomb_counter++;
                }
            }
        }
        board[r][c] = bomb_counter;
    }
}