#include "Zfraction.h"

using namespace std;


int main()
{
    Zfraction z1(15, -4), z2(-25, 15);

    cout << z1 << " - (" << z2 << ") = " << z1-z2 << endl;

    cout << z1 << " / (" << z2 << ") = " << z1/z2 << endl;

    cout << "-(" << z1 << ") = " << -z1 << endl;

    cout << "abs(" << z1 << ") = " << abs(z1) << endl;
    
    return 0;
}