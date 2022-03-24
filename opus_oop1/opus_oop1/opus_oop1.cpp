#include <iostream>
#include <string>
#include <windows.h>
#include <vector>

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

vector<Flower*> flowerbase;

void addFlower() {
    int s, b;
    string flower;
    
    cout << "What flower do you want to add? -> ";
    cin >> flower;

    cout << "How long does " << flower << " sprout? -> ";
    cin >> s;

    cout << "How long does " << flower << " bloom? -> ";
    cin >> b;

    Flower* obj = new Flower(flower, s, b);
    flowerbase.push_back(obj);
}

void grow(Flower flower) {
    for (int i = 1; i < 60; i++) {
        Sleep(1000);
        cout << "\nDay " << i << "... ";
        if (i == flower.sprouting_time)
            flower.Sprout();
        if (i == flower.blooming_time)
            flower.Bloom();
    }
}

int main()
{
    addFlower();
    cout <<  (*flowerbase[0]).name;
    grow(*flowerbase[0]);

    return 0;
}