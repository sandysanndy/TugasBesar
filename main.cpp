#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <conio2.h>

//using namespace conio;
using namespace std;

const int tinggi = 9;
const int lebar = 9;
const char Wall = '#';
const char Free = ' ';
const char SomeDude = '*';

//printf("Masukkan maksimal lebar = ");
//scanf("%i", tinggi);
char Maze[tinggi][lebar + 1] =
{
    "# #######",
    "#       #",
	"# #######",
    "# #     #",
	"# ### ###",
    "#     # #",
    "# ### # #",
    "#       #",
    "####### #",
};

class koordinat
{public:
    int X;
    int Y;
    koordinat(int x = 0, int y = 0) { X = x, Y = y; }
    koordinat(const koordinat &koordinat) { X = koordinat.X; Y = koordinat.Y; }
};

koordinat StartingPoint(1, 0);
koordinat EndingPoint(7, 8);

void cetak()
{
    for (int Y = 0; Y < tinggi; Y++)
    {
        textcolor(YELLOW);
        cout<<Maze[Y]<<endl;
    }
    cout<<endl;
}

bool Solve(int X, int Y)
{
    // Make the move (if it's wrong, we will backtrack later.
    Maze[Y][X] = SomeDude;

    // If you want progressive update, uncomment these lines...
    cetak();
    //Sleep(50);

    // Check if we have reached our goal.
    if (X == EndingPoint.X && Y == EndingPoint.Y)
    {
        return true;
    }

    // Recursively search for our goal.
    if (X > 0 && Maze[Y][X - 1] == Free && Solve(X - 1, Y))
    {
        return true;
    }
    if (X < lebar && Maze[Y][X + 1] == Free && Solve(X + 1, Y))
    {
        return true;
    }
    if (Y > 0 && Maze[Y - 1][X] == Free && Solve(X, Y - 1))
    {
        return true;
    }
    if (Y < tinggi && Maze[Y + 1][X] == Free && Solve(X, Y + 1))
    {
        return true;
    }

    // Otherwise we need to backtrack and find another solution.
    Maze[Y][X] = Free;

    // If you want progressive update, uncomment these lines...
    cetak();
    //Sleep(50);
    return false;
}

int main(int argc)
{
    
    if (Solve(StartingPoint.X, StartingPoint.Y))
    {
        cetak();
    }
    else
    {
        printf("Tidak ada solusi\n");
    }
	getch();
    return 0;
}
