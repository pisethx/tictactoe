#include <iostream>

using namespace std;

char c;
char square[3][3]={'1','2','3','4','5','6','7','8','9'};
int num;
int draw=0, one=0, two=0;
int gamectr=1;
void board()
{
    system("cls");
    cout << "\n\n\t\t   Tic Tac Toe\n\n";
    cout << "Player X\t      "<< one << " - " << two << "\t\tPlayer O" << endl << endl;
    cout << endl;

    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << square[0][0] << "  |  " << square[0][1] << "  |  " << square[0][2] << endl;

    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;

    cout << "\t\t  " << square[1][0] << "  |  " << square[1][1] << "  |  " << square[1][2] << endl;

    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;

    cout << "\t\t  " << square[2][0] << "  |  " << square[2][1] << "  |  " << square[2][2] << endl;

    cout << "\t\t     |     |     " << endl << endl;
}

bool win(char c) {
    if (square[0][0]==square[0][1] && square[0][1]==square[0][2])
        return true;
    else if (square[0][0]==square[1][0] && square[1][0]==square[2][0])
        return true;
    else if (square[0][1]==square[1][1] && square[1][1]==square[2][1])
        return true;
    else if (square[0][2]==square[1][2] && square[1][2]==square[2][2])
        return true;
    else if (square[1][0]==square[1][1] && square[1][1]==square[1][2])
        return true;
    else if (square[2][0]==square[2][1] && square[2][1]==square[2][2])
        return true;
    else if (square[0][0]==square[1][1] && square[1][1]==square[2][2])
        return true;
    else if (square[0][2]==square[1][1] && square[1][1]==square[2][0])
        return true;
    else {
    return false;
    }
}
int main()
{
    game:
    int j,k;
    string x;
    do {
        board();
        for (int i=1; i<=9; ++i) {
        if (gamectr%2!=0){
        if (i%2 != 0)
        cout << "X's turn: ";
        else if (i%2==0)
        cout << "O's turn: ";
            cin >> c;
        if (i%2!=0) {
            for (j=0;j<3;++j){
                for (k=0;k<3;++k)
                    if (square[j][k]==c) {
                        square[j][k]='X';
                        board();
                        x="Player X";
                    }
            }
        }
        else if (i%2==0) {
            for (j=0;j<3;++j){
                for (k=0;k<3;++k)
                    if (square[j][k]==c) {
                        square[j][k]='O';
                        board();
                        x="Player O";
                    }
            }
        }
        } else if (gamectr%2==0) {
        if (i%2 != 0)
        cout << "O's turn: ";
        else if (i%2==0)
        cout << "X's turn: ";
            cin >> c;
        if (i%2!=0) {
            for (j=0;j<3;++j){
                for (k=0;k<3;++k)
                    if (square[j][k]==c) {
                        square[j][k]='O';
                        board();
                        x="Player O";
                    }
            }
        }
        else if (i%2==0) {
            for (j=0;j<3;++j){
                for (k=0;k<3;++k)
                    if (square[j][k]==c) {
                        square[j][k]='X';
                        board();
                        x="Player X";
                    }
            }
        }
        }
        if(win(c)) {
            cout << x << " wins!" << endl << endl;;
            if (x=="Player X")
                ++one;
            else if (x=="Player O")
                ++two;
            gameover :
            cout << "Press 1 to Play Again or Press 2 to Exit!" << endl;
            cin >> num;
            cout << endl;
            if (num==1) {
                ++gamectr;
                char a='1';
                for (int ii=0; ii<3;++ii) {
                    for (int jj=0;jj<3;++jj){
                        square[ii][jj]=a;
                        ++a;
                    }
                }
            goto game;
            }
            else {
            system("cls");
            cout << "\n\tTotal Games: " << one+two+draw << endl << endl;
            cout << "\tPlayer X\t" << one << "\t-\t" << two << "\tPlayer O" << endl << endl;
            if (one > two)
                cout << "\tPlayer X takes the cake!" << endl << endl;
            else if (two > one)
                cout << "\tPlayer O takes the cake!" << endl << endl;
            else cout << "\tAwww! No one could take the cake!" << endl << endl;
            cout << "\tThank you for playing!" << endl;
            break;
            }
        }
        if (i>8) {
            cout << "Its a tie!" << endl << endl;
            ++draw;
            goto gameover;
        }
        }
    } while (!win(c));
}
