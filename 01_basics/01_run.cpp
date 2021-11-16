#include <iostream>
using namespace std;

int main(){
    cout << "God's wounds!\n" << endl;  // prints out "God's wounds!" on the screen

    // (1) XIII
    cout << "witamy\n"
            "na\n"
            "p\n"
            "o\n"
            "kladzie\n";

    //(1) XIV
    int inches = 56, centimeters;
    double convert = 2.54;

    //cout << "\nHow many inches? -> ";
    cin >> inches;
    centimeters = inches * convert;
    cout << inches << " in = " << centimeters << " cm";

    return 0;
}

