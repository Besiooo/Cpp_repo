#include <iostream>
#include <string>

using namespace std;

class Flower {
public:
    int sprouting_time;
    int blooming_time;

    string name;

    void Sprout() {
        cout << name <<" is sprouting!";
    }

    void Bloom() {
        cout << name << " is blooming!";
    }
};

int main()
{
    Flower sunflower;
    sunflower.name = "Sunflower";

    cout << "How long does " << sunflower.name << " sprout? -> ";
    cin >> sunflower.sprouting_time;

    cout << "How long does " << sunflower.name << " bloom? -> ";
    cin >> sunflower.blooming_time;

    cout << sunflower.name << ", sprouting time of " << sunflower.sprouting_time << " and blooming time of " << sunflower.blooming_time << " has been created!";

}
