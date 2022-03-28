#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <stdlib.h>

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
        cout << name << " is sprouting!\n";
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

void addFlower(string flower, int s, int b) {
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

void loadFlowers() {
    vector<string> names = { "Violet", "Sunflower", "Rose", "Artichoke", "Lilac" };
    int rs, rb;
    for (int i = 0; i < names.size(); i++) {
        do {
            rs = rand() % 59 + 1;
            rb = rand() % 59 + 1;
        } while (rb <= rs);

        addFlower(names[i], rs, rb);
    }
}

void myFlowers() {
    cout << "How many flowers do you want to add? -> ";
    int n;
    cin >> n;

    int s, b;
    string flower;

    for (int i = 0; i < n; i++) {
        cout << "What flower do you want to add? -> ";
        cin >> flower;

        cout << "How long does " << flower << " sprout? -> ";
        cin >> s;

        cout << "How long does " << flower << " bloom? -> ";
        cin >> b;
        addFlower(flower, s, b);
    }
}

void loadMatrix() {
    cout << "T\t";

    for (int i = 0; i < flowerbase.size(); i++) {
        cout << (*flowerbase[i]).name[0] << "\t";
    }
    cout << "\n";

    for (int i = 1; i < 60; i++) {
        Sleep(1000);
        cout << i << "\t";
        for (int j = 0; j < flowerbase.size(); j++) {
            if (i == (*flowerbase[j]).sprouting_time){
                cout << "S\t";
                (*flowerbase[j]).hasSprouted = true;
            }
            if (i == (*flowerbase[j]).blooming_time){
                cout << "B\t";
                (*flowerbase[j]).hasBloomed = true;
            }
            if (i > (*flowerbase[j]).sprouting_time && i < (*flowerbase[j]).blooming_time)
                cout << "|\t";
            else if (i != (*flowerbase[j]).sprouting_time && i != (*flowerbase[j]).blooming_time)
                cout << ".\t";
        }
        cout << "\n";
    }
}

void exit() {
    for (int i = 0; i < flowerbase.size(); i++)
        delete flowerbase[i];
}

int main()
{
    srand(time(NULL));

    cout << "Do you want to precache floweras or make your own?\n1: create your own\n2: precache\n\t-> ";
    char decision;
    cin >> decision;

    switch (decision) {
    case '1': myFlowers(); break;
    case '2': loadFlowers(); break;
    default: break;
    }

    cout << "Matrix mode or text mode?\n1: matrix mode\n2: text mode\n\t-> ";
    cin >> decision;

    switch (decision) {
    case '1': loadMatrix(); break;
    case '2': grow(); break;
    default: break;
    }

    exit();
    return 0;
}
