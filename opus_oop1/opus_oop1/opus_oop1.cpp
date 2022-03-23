#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Flower {
public:
    int sprouting_time;
    int blooming_time;

    bool hasSprouted = false;
    bool hasBloomed = false;

    string name;

    Flower(string n, int s, int b) {
        this->name = n;
        this->sprouting_time = s;
        this->blooming_time = b;
        cout << n << ", sprouting time of " << s << " and blooming time of " << b << " has been created!\n";
    }

    void Sprout() {
        cout << name <<" is sprouting!";
        hasSprouted = true;
    }

    void Bloom() {
        if (hasSprouted) {
            cout << name << " is blooming!";
            hasBloomed = true;
        }
        else {
            cout << name << " can't bloom if not sprouted!";
        }
    }
};

int main()
{
    int s, b;
    string flower = "Sunflower";

    cout << "How long does " << flower << " sprout? -> ";
    cin >> s;

    cout << "How long does " << flower << " bloom? -> ";
    cin >> b;

    Flower Sunflower(flower, s, b);

    for (int i = 1; i < 60; i++) {
        Sleep(1000);
        cout << "\nDay " << i << "... ";
        if (i == Sunflower.sprouting_time)
            Sunflower.Sprout();
        if (i == Sunflower.blooming_time)
            Sunflower.Bloom();
    }

}