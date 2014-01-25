#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <conio2.h>

//using namespace conio;
using namespace std;

const int tinggi = 9;
const int lebar = 9;
const char batas = '#';
const char kosong = ' ';
const char langkah = '*';

char labirin[tinggi][lebar + 1] =
{
    "# #######",
    "#       #",
	"# #######",
    "# #     #",
	"# ### ###",
    "#     # #",
    "# ### # #",
    "#       #",
    "##### ###",
};

class koordinat
{public:
    int I;
    int J;
    koordinat(int i=0, int j=0){ I = i, J = j; }
    koordinat(const koordinat &koordinat) {I = koordinat.I; J=koordinat.J;}
};

koordinat StartingPoint(1, 0);
koordinat EndingPoint(5, 8);

void cetak()
{
    for (int J = 0; J < tinggi; J++)
    {
        textcolor(YELLOW);
        cout<<labirin[J]<<endl;
    }
    cout<<endl;
}

bool solusi(int I, int J)
{
    //membuat langkah
    labirin[J][I] = langkah;

    //mencetak langkah backtracking
    cetak();
   
    if (I == EndingPoint.I && J == EndingPoint.J)
    {
        return true;
    }
    //Pencarian secara rekursif
    if (I > 0 && labirin[J][I - 1] == kosong && solusi(I - 1, J))
    {
        return true;
    }
    if (I < lebar && labirin[J][I + 1] == kosong && solusi(I + 1, J))
    {
        return true;
    }
    if (J > 0 && labirin[J - 1][I] == kosong && solusi(I, J - 1))
    {
        return true;
    }
    if (J < tinggi && labirin[J + 1][I] == kosong && solusi(I, J + 1))
    {
        return true;
    }
    //untuk backtracking
    labirin[J][I] = kosong;
    //mencetak langkah backtracking
    cetak();
    return false;
}

int main(int argc)
{
    if (solusi(StartingPoint.I, StartingPoint.J))
    {
        cetak();
    }else{ cout<<"Tidak ada solusi"<<endl;
    }
	getch();
    return 0;
}
