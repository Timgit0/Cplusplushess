#include <iostream>
#include <vector>
#include <string>
//#include <io.h>
#include <fcntl.h>


int max(int a, int b)
{
    if (a > b) return a;
    return b;
}

class Piece
{
public:
    std :: string name;
    std :: string color;
    std :: vector<std :: vector<char>> picture;
    bool enPassant;

    Piece()
    {
        name = "nothing";
        color = "";
        enPassant = false;

        std :: vector<char> piece0;
        std :: vector<char> piece1;
        std :: vector<char> piece2;
        std :: vector<char> piece3;

        piece0.push_back(' ');
        piece0.push_back(' ');
        piece0.push_back(' ');

        piece1.push_back(' ');
        piece1.push_back(' ');
        piece1.push_back(' ');

        piece2.push_back(' ');
        piece2.push_back(' ');
        piece2.push_back(' ');

        piece3.push_back(' ');
        piece3.push_back(' ');
        piece3.push_back(' ');

        picture.push_back(piece0);
        picture.push_back(piece1);
        picture.push_back(piece2);
        picture.push_back(piece3);


    }
    Piece(std :: string _name, std :: string _color)
    {
        name = _name;
        color = _color;
        enPassant = false;
        std :: vector<char> piece0;
        std :: vector<char> piece1;
        std :: vector<char> piece2;
        std :: vector<char> piece3;
        if (name == "pawn")
        {
            /*
            /¯\
            \ /
            / \
            ¯¯¯
            */
            piece0.push_back('/');
            piece0.push_back('_');
            piece0.push_back('\\');

            piece1.push_back('\\');
            piece1.push_back(' ');
            piece1.push_back('/');

            piece2.push_back('/');
            if (color == "white") piece2.push_back('w');
            else if (color == "black") piece2.push_back('b');
            piece2.push_back('\\');

            piece3.push_back('-');
            piece3.push_back('-');
            piece3.push_back('-');
        }
        else if (name == "knight")
        {
            /*
            /¯|
            \ |
            / |
            ¯¯¯
            */
            piece0.push_back('/');
            piece0.push_back('-');
            piece0.push_back('|');

            piece1.push_back('\\');
            piece1.push_back(' ');
            piece1.push_back('|');

            piece2.push_back('/');
            if (color == "white") piece2.push_back('w');
            else if (color == "black") piece2.push_back('b');
            piece2.push_back('|');

            piece3.push_back('-');
            piece3.push_back('-');
            piece3.push_back('-');
        }
        else if (name == "bishop")
        {
            /*
            /*\
            \¯/
            / \
            ¯¯¯
            */
            piece0.push_back('/');
            piece0.push_back('*');
            piece0.push_back('\\');

            piece1.push_back('\\');
            piece1.push_back('-');
            piece1.push_back('/');

            piece2.push_back('/');
            if (color == "white") piece2.push_back('w');
            else if (color == "black") piece2.push_back('b');
            piece2.push_back('\\');

            piece3.push_back('-');
            piece3.push_back('-');
            piece3.push_back('-');
        }
        else if (name == "rook")
        {
            /*
            |V|
            | |
            / \
            ¯¯¯
            */
            piece0.push_back('|');
            piece0.push_back('V');
            piece0.push_back('|');

            piece1.push_back('|');
            piece1.push_back(' ');
            piece1.push_back('|');

            piece2.push_back('/');
            if (color == "white") piece2.push_back('w');
            else if (color == "black") piece2.push_back('b');
            piece2.push_back('\\');

            piece3.push_back('-');
            piece3.push_back('-');
            piece3.push_back('-');
        }
        else if (name == "king")
        {
            /*
            /+\
            \ /
            / \
            ¯¯¯
            */
            piece0.push_back('/');
            piece0.push_back('+');
            piece0.push_back('\\');

            piece1.push_back('\\');
            piece1.push_back(' ');
            piece1.push_back('/');

            piece2.push_back('/');
            if (color == "white") piece2.push_back('w');
            else if (color == "black") piece2.push_back('b');
            piece2.push_back('\\');

            piece3.push_back('-');
            piece3.push_back('-');
            piece3.push_back('-');
        }
        else if (name == "queen")
        {
            /*
            \|/
            |¯|
            / \
            ¯¯¯
            */
            piece0.push_back('\\');
            piece0.push_back('|');
            piece0.push_back('/');

            piece1.push_back('|');
            piece1.push_back('-');
            piece1.push_back('|');

            piece2.push_back('/');
            if (color == "white") piece2.push_back('w');
            else if (color == "black") piece2.push_back('b');
            piece2.push_back('\\');

            piece3.push_back('-');
            piece3.push_back('-');
            piece3.push_back('-');

        }

        picture.push_back(piece0);
        picture.push_back(piece1);
        picture.push_back(piece2);
        picture.push_back(piece3);
    }
    bool CanMoveTo(std :: vector<int> coords, bool attack, std :: vector<std :: vector<Piece>> _board, std :: string _colorToMove)
    {
        int x0, y0, x1, y1;
        x0 = coords[0];
        y0 = coords[1];
        x1 = coords[2];
        y1 = coords[3];
        if (_colorToMove != color) return false;
        if (_board[x1][y1].color == color) return false;
        if (name == "pawn")
        {
            if (color == "black")
            {
                if ((y0 == y1 && x1 == x0+1 && !attack) || (y0 == y1 && x1 == 3 && x0 == 1 && !attack) || ((abs(y1 - y0) == 1) && x1 == x0+1 && attack)) return true;
            }
            else
            {
                if ((y0 == y1 && x1 == x0-1 && !attack) || (y0 == y1 && x1 == 4 && x0 == 6 && !attack) || ((abs(y1 - y0) == 1) && x1 == x0-1 && attack)) return true;
            }
        }
        else if (name == "knight")
        {
            if (((abs(x1 - x0) == 1) && (abs(y1 - y0) == 2)) || ((abs(x1 - x0) == 2) && (abs(y1 - y0) == 1))) return true;
        }
        else if (name == "bishop")
        {
            if (abs(x1 - x0) == abs(y1 - y0))
            {
                for (int i = 1; i < abs(x1-x0); i++)
                {
                    if (_board[x0+i*((x1-x0)/max(abs(x1-x0),abs(y1-y0)))][y0+i*((y1-y0)/max(abs(x1-x0),abs(y1-y0)))].name != "nothing") return false;
                }
                return true;
            }
        }
        else if (name == "rook")
        {
            if (x1 == x0 || y1 == y0)
            {
                for (int i = 1; i < max(abs(x1-x0),abs(y1-y0)); i++)
                {
                    if (_board[x0+i*((x1-x0)/max(abs(x1-x0),abs(y1-y0)))][y0+i*((y1-y0)/max(abs(x1-x0),abs(y1-y0)))].name != "nothing") return false;
                }
                return true;
            }
        }
        else if (name == "queen")
        {
            if (abs(x1 - x0) == abs(y1 - y0))
            {
                for (int i = 1; i < abs(x1-x0); i++)
                {
                    if (_board[x0+i*((x1-x0)/max(abs(x1-x0),abs(y1-y0)))][y0+i*((y1-y0)/max(abs(x1-x0),abs(y1-y0)))].name != "nothing") return false;
                }
                return true;
            }
            else if (x1 == x0 || y1 == y0)
            {
                for (int i = 1; i < max(abs(x1-x0),abs(y1-y0)); i++)
                {
                    if (_board[x0+i*((x1-x0)/max(abs(x1-x0),abs(y1-y0)))][y0+i*((y1-y0)/max(abs(x1-x0),abs(y1-y0)))].name != "nothing") return false;
                }
                return true;
            }
        }
        else if (name == "king")
        {
            if (abs(x1 - x0) <= 1 && abs(y1 - y0) <= 1) return true;
        }
        return false;
    }

};


std :: vector<std :: vector<Piece>> CreateStartingBoard()
{
    std :: vector<std :: vector<Piece>> _board;

    std :: vector<Piece> row0;
    std :: vector<Piece> row1;
    std :: vector<Piece> row2to5;
    std :: vector<Piece> row6;
    std :: vector<Piece> row7;

    row0.push_back(Piece("rook", "black"));
    row0.push_back(Piece("knight", "black"));
    row0.push_back(Piece("bishop", "black"));
    row0.push_back(Piece("queen", "black"));
    row0.push_back(Piece("king", "black"));
    row0.push_back(Piece("bishop", "black"));
    row0.push_back(Piece("knight", "black"));
    row0.push_back(Piece("rook", "black"));

    for (int i = 0; i < 8; i++)
    {
        row1.push_back(Piece("pawn", "black"));
        row6.push_back(Piece("pawn", "white"));
        row2to5.push_back(Piece());
    }


    row7.push_back(Piece("rook", "white"));
    row7.push_back(Piece("knight", "white"));
    row7.push_back(Piece("bishop", "white"));
    row7.push_back(Piece("queen", "white"));
    row7.push_back(Piece("king", "white"));
    row7.push_back(Piece("bishop", "white"));
    row7.push_back(Piece("knight", "white"));
    row7.push_back(Piece("rook", "white"));

    _board.push_back(row0);
    _board.push_back(row1);
    for (int i = 0; i < 4; i++)
    {
        _board.push_back(row2to5);
    }
    _board.push_back(row6);
    _board.push_back(row7);
    return _board;
}


void PrintBoard(std :: vector<std :: vector<Piece>> _board)
{
    system("clear");
    for (int y = 0; y < 8*4; y++)
    {
        if (y%4 == 0)
        {
            for (int x = 0; x < 8*3; x++)
            {
                if (x == 0) std :: cout << '+' << '-';
                else if (x%3 == 0) std :: cout << '-' << '+' << '-';
                std :: cout << '-';
            }
            std :: cout << '-' << '+';
            std :: cout << '\n';
        }
        for (int x = 0; x < 8*3; x++)
        {
            if (x == 0) std :: cout << '|' << ' ';
            else if (x%3 == 0) std :: cout << ' ' << '|' << ' ';
            std :: cout << _board[y/4][x/3].picture[y%4][x%3];
        }
        std :: cout << ' ' << '|' << ' ';
        std :: cout << '\n';
    }
    for (int x = 0; x < 8*3-1; x++)
    {
        if (x == 0) std :: cout << '+' << '-';
        std :: cout << '-';
        if (x == 8*3-2) std :: cout << '-';
        if (x%3 == 2 && x != 0) std :: cout << '-' << '+' << '-';
    }
    std :: cout << '-' << '+';
    std :: cout << '\n';
}


std :: vector<int> TheirNotationToOurs(char x0, int y0, char x1, int y1)
{
    // (0 1) is a black knight and so is b8
    std :: vector<int> ans;
    ans.push_back(8 - y0);
    if (x0 == 'a' || x0 == 'A' || x0 == '1') ans.push_back(0);
    if (x0 == 'b' || x0 == 'B' || x0 == '2') ans.push_back(1);
    if (x0 == 'c' || x0 == 'C' || x0 == '3') ans.push_back(2);
    if (x0 == 'd' || x0 == 'D' || x0 == '4') ans.push_back(3);
    if (x0 == 'e' || x0 == 'E' || x0 == '5') ans.push_back(4);
    if (x0 == 'f' || x0 == 'F' || x0 == '6') ans.push_back(5);
    if (x0 == 'g' || x0 == 'G' || x0 == '7') ans.push_back(6);
    if (x0 == 'h' || x0 == 'H' || x0 == '8') ans.push_back(7);

    ans.push_back(8 - y1);
    if (x1 == 'a' || x1 == 'A' || x1 == '1') ans.push_back(0);
    if (x1 == 'b' || x1 == 'B' || x1 == '2') ans.push_back(1);
    if (x1 == 'c' || x1 == 'C' || x1 == '3') ans.push_back(2);
    if (x1 == 'd' || x1 == 'D' || x1 == '4') ans.push_back(3);
    if (x1 == 'e' || x1 == 'E' || x1 == '5') ans.push_back(4);
    if (x1 == 'f' || x1 == 'F' || x1 == '6') ans.push_back(5);
    if (x1 == 'g' || x1 == 'G' || x1 == '7') ans.push_back(6);
    if (x1 == 'h' || x1 == 'H' || x1 == '8') ans.push_back(7);

    return ans;
}

std :: vector<std :: vector<Piece>> MakeMove(std :: vector<std :: vector<Piece>> _board, std :: string _colorToMove)
{
    char _x0, _x1;
    int _y0, _y1;
    std :: cin >> _x0 >> _y0 >> _x1 >> _y1;
    int x0, y0, x1, y1;
    x0 = TheirNotationToOurs(_x0, _y0, _x1, _y1)[0];
    y0 = TheirNotationToOurs(_x0, _y0, _x1, _y1)[1];
    x1 = TheirNotationToOurs(_x0, _y0, _x1, _y1)[2];
    y1 = TheirNotationToOurs(_x0, _y0, _x1, _y1)[3];

    //std :: cout << x0 << y0 << x1 << y1;
    //std :: cout << _board[x0][y0].CanMoveTo(TheirNotationToOurs(_x0, _y0, _x1, _y1), _board[x1][y1].name != "nothing", _board, _colorToMove);
    //std :: cout << _board[3][3].enPassant;
    if (_board[x0][y0].CanMoveTo(TheirNotationToOurs(_x0, _y0, _x1, _y1), (_board[x1][y1].name != "nothing"), _board, _colorToMove))
    {
        if (x1 == 0 && _board[x0][y0].name == "pawn" && _board[x0][y0].color == "white") _board[x1][y1] = Piece("queen", "white");
        else if (x1 == 8 && _board[x0][y0].name == "pawn" && _board[x0][y0].color == "black") _board[x1][y1] = Piece("queen", "black");
        else _board[x1][y1] = _board[x0][y0];
        _board[x0][y0] = Piece();
    }
    else
    {
        std :: cout << "impossible move!\n";
        return MakeMove(_board, _colorToMove);
    }
    if ((_board[x0][y0].name == "pawn")&&(_board[x0][y1].enPassant))
    {
        _board[x1][y1] = _board[x0][y0];
        _board[x0][y0] = Piece();
        _board[x0][y1] = Piece();
    }
    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            if (_board[x][y].enPassant) _board[x][y].enPassant = false;
        }
    }
    if (abs(x1-x0) == 2 && _board[x1][y1].name == "pawn") _board[x1][y1].enPassant = true;
    return _board;
}

bool CheckKings(std :: vector<std :: vector<Piece>> _board)
{
    bool whiteKing = false;
    bool blackKing = false;
    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            if (_board[x][y].name == "king" && _board[x][y].color == "white") whiteKing = true;
            else if (_board[x][y].name == "king" && _board[x][y].color == "black") blackKing = true;
        }
    }
    if (whiteKing && blackKing) return true;
    if (whiteKing) std :: cout << "white won!!!\n";
    if (blackKing) std :: cout << "b won!!!\n";
    return false;

}

int main()
{
//    _setmode(_fileno(stdout), _O_U16TEXT);

    std :: vector<std :: vector<Piece>> board;

    std :: string colorToMove = "white";

    board = CreateStartingBoard();

    PrintBoard(board);

    while(CheckKings(board))
    {
        board = MakeMove(board, colorToMove);
        if (colorToMove == "white") colorToMove = "black";
        else colorToMove = "white";

        PrintBoard(board);
    }

    return 0;
}
