#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> vct) {
    if (vct.size() == 0)
        cout << "The vector is empty!";
    else {
        cout << "\n";
        for (vector<int>::iterator it = vct.begin();
            it != vct.end();
            ++it)
        {
            cout << *it << " ";
        }
    }
}

void add_value_to_vector(vector<int> &vct) {
    cout << "What value to add? -> ";
    int v;
    cin >> v;
    vct.push_back(v);
}

void f_vectors() {
    vector<int> my_vector = {3, 5, 7, 9, 11, 13};
    int decision;
    while (true) {
        do {
            cout << "\nPress:\n\t 1: SHOW EXAMPLE VECTOR\n\t2: CLEAR VECTOR\n\t3: ADD A VALUE\n\t4: REMOVE ANY VALUE\n";
            cin >> decision;
        } while (decision < 1 || decision > 4);

        switch (decision) {
        case 1: print_vector(my_vector); break;
        case 2: my_vector = {}; break;
        case 3: add_value_to_vector(my_vector); break;
        case 4: break;
        default: break;
        }
    }
}

int main()
{
    cout << "Today we're gonna learn about STL!\n";
    int decision;

    do{
        cout << "Press:\n\t 1: VECTORS\n";
        cin >> decision;
    } while (decision != 1);

    switch (decision) {
        case 1: 
            f_vectors(); break;
        default:
            break;
    }

    return 0;
}
