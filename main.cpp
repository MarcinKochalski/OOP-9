#include <iostream>
#include <fstream>
// Only works for (a,b) format
// Converts fractions into double numbers for determinant calculations
// not sure if we had to keep the numbers in fractions, keeping them in fractions would be so much work
using namespace std;
struct Numbers
        {
    double A, B, C, D, E, F, G, H, I, J, K, L;
};

void read(string filename, Numbers& numbers1)
{
    ifstream infile(filename);
    if (!infile.is_open())
    {
        cout << "Could not open file " << filename << endl;
        return;
    }
    char openParen, closeParen, comma;
    infile >> openParen >> numbers1.A >> comma >> numbers1.B >> closeParen
           >> openParen >> numbers1.C >> comma >> numbers1.D >> closeParen
           >> openParen >> numbers1.E >> comma >> numbers1.F >> closeParen
           >> openParen >> numbers1.G >> comma >> numbers1.H >> closeParen
           >> openParen >> numbers1.I >> comma >> numbers1.J >> closeParen
           >> openParen >> numbers1.K >> comma >> numbers1.L >> closeParen;
    infile.close();
    cout << "Numbers from the txt file are: " << numbers1.A << "/" << numbers1.B << " " << numbers1.C << "/" << numbers1.D << " "
         << numbers1.E << "/" << numbers1.F << " " << numbers1.G << "/" << numbers1.H << " "
         << numbers1.I << "/" << numbers1.J << " " << numbers1.K << "/" << numbers1.L << ", so the equations are: " <<endl;
    cout << numbers1.A << "/" << numbers1.B <<"x";
    cout <<" + ";
    cout << numbers1.C << "/" << numbers1.D<<"y";
    cout <<" = ";
    cout << numbers1.E << "/" << numbers1.F<<endl;
    cout << numbers1.G << "/" << numbers1.H<<"x";
    cout <<" + ";
    cout << numbers1.I << "/" << numbers1.J<<"y";
    cout <<" = ";
    cout << numbers1.K << "/" << numbers1.L<<endl;
    cout << "So, the coefficients are: "<<endl;
}

void solveEquations(Numbers& numbers1)
{
double detAll, detForX, detForY, x1,x2,y1,y2,r1,r2,x,y;
x1=numbers1.A/numbers1.B;
x2=numbers1.G/numbers1.H;
y1=numbers1.C/numbers1.D;
y2=numbers1.I/numbers1.J;
r1=numbers1.E/numbers1.F;
r2=numbers1.K/numbers1.L;
cout <<endl;
cout << "x1 = " << x1 <<endl;
cout << "x2 = " << x2 <<endl;
cout << "y1 = " << y1 <<endl;
cout << "y2 = " << y2 <<endl;
cout << "r1 = " << r1 <<endl;
cout << "r2 = " << r2 <<endl;
detAll=(x1*y2-y1*x2);
detForX=(r1*y2-y1*r2);
detForY=(x1*r2-r1*x2);
cout << "Det from x and y matrix = " << detAll <<endl;
cout << "Det from x and r matrix = " << detForX <<endl;
cout << "Det from y and r matrix = " << detForY <<endl;
if (detAll==0)
{
    cout << "Det = 0! No solutions or infinite solutions." << endl;
    return;
}
    x=detForX/detAll;
    y=detForY/detAll;
    cout << "Finished! x = "<< x <<" y = " << y <<endl;
    cout << "Stopping.";
return;
}

int main() {
    Numbers numbers1;
    read("numbers.txt", numbers1);
    solveEquations(numbers1);

    return 0;
}