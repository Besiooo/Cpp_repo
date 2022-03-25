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
        cout << n << ", sprouting time of " << s << " and blooming time of " << b << " has been created!\n\n";
    }

    void Sprout() {
        cout << name <<" is sprouting!\n";
        hasSprouted = true;
    }

    void Bloom() {
        if (hasSprouted) {
            cout << name << " is blooming!\n";
            hasBloomed = true;
        }
        else {
            cout << name << " can't bloom if not sprouted!\n";
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

void grow() {
    for (int i = 1; i < 60; i++) {
        Sleep(1000);
        cout << "\nDay " << i << "... ";
        for (int j = 0; j < flowerbase.size(); j++) {
            if (i == (*flowerbase[j]).sprouting_time)
                (*flowerbase[j]).Sprout();
            if (i == (*flowerbase[j]).blooming_time)
                (*flowerbase[j]).Bloom();
        }       
    }
}

int main()
{
    cout << "How many flowers do you want to add? -> ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        addFlower();
    }

    grow();

    return 0;
}