#include <iostream>
#include <string>

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

int main()
{
    int s, b;
    string flower = "Sunflower";

    cout << "How long does " << flower << " sprout? -> ";
    cin >> s;

    cout << "How long does " << flower << " bloom? -> ";
    cin >> b;

    Flower Sunflower(flower, s, b);

    cout << Sunflower.name << ", sprouting time of " << Sunflower.sprouting_time << " and blooming time of " << Sunflower.blooming_time << " has been created!\n";
    Sunflower.Bloom();
    Sunflower.Sprout();
    Sunflower.Bloom();

}
