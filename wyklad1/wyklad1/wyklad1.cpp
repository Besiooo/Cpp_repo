#include <iostream>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

void print_vector(vector<int>& vct, int param) {
    if (vct.size() == 0)
        cout << "The vector is empty!";
    else {
        cout << "\n";
        if (param) {
            for (vector<int>::iterator it = vct.begin();
                it != vct.end();
                ++it)
            {
                cout << *it << " ";
            }
        } else {
            for (vector<int>::reverse_iterator it = vct.rbegin();
                it != vct.rend();
                ++it)
            {
                cout << *it << " ";
            }
        }
    }
}

void add_value_to_vector(vector<int> &vct) {
    cout << "What value to add? -> ";
    int v;
    cin >> v;
    vct.push_back(v);
}

void delete_from_vector(vector<int>& vct) {
    cout << "Which one? -> ";
    int index;
    cin >> index;
    vct.erase(vct.begin() + index - 1);
}

void f_vectors() {
    vector<int> my_vector = {3, 5, 7, 9, 11, 13};
    int decision;
    while (true) {
        do {
            cout << "\nPress:\n\t1: SHOW VECTOR\n\t2: CLEAR VECTOR\n\t3: ADD A VALUE\n\t4: REMOVE ANY VALUE\n\t5: SHOW REVERSED\n";
            cin >> decision;
        } while (decision < 1 || decision > 4);

        switch (decision) {
        case 1: print_vector(my_vector, 1); break;
        case 2: my_vector.clear(); break;
        case 3: add_value_to_vector(my_vector); break;
        case 4: delete_from_vector(my_vector); break;
        case 5: print_vector(my_vector, 0); break;
        default: break;
        }
    }
}

void load_map(map<int, string>& o_map) {
    for (int i = 0; i < 10; i++) {
        o_map[i] = "Billy Jean!";
    }
    cout << "\nMap has been loaded!\n";
}

void print_map(map<int, string>& o_map, int param) {
    if(o_map.size() == 0)
        cout << "No map has been loaded! (map is empty)";
    else
        if (param) 
            for (map<int, string>::iterator it = o_map.begin();
                it != o_map.end();
                ++it) 
                cout << "[" << it->first << "] -> " << it->second << "\n";     
        else 
            for(map<int, string>::reverse_iterator it = o_map.rbegin();
                it != o_map.rend();
                ++it)
                    cout << "[" << it->first << "] -> " << it->second << "\n";
}

void add_to_map(map<int, string>& o_map) {
    cout << "\nWhat index? -> ";
    int k;
    cin >> k;

    cout << "\nWhat value? -> ";
    string s;
    cin >> s;

    o_map[k] = s;
}

void f_maps(){
        map<int, string> my_map;
        int decision;
        while (true) {
            do {
                if (my_map.size())
                    cout << "Map size is " << my_map.size();
                else
                    cout << "No map! (Map is empty)";

                cout << "\nPress:\n\t1: LOAD MAP\n\t2: SHOW MAP\n\t3: ADD VALUE\n\t4: SHOW REVERSED";
                cin >> decision;
            } while (decision < 1 || decision > 4);

            switch (decision) {
            case 1: load_map(my_map); break;
            case 2: print_map(my_map, 1); break;
            case 3: add_to_map(my_map); break;
            case 4: print_map(my_map, 0); break;
            default: break;
            }
        }
    }

pair<int, int> divmod(int a, int b) {
    return make_pair(a / b, a % b);
}

void f_pairs() {
    cout << "\na/b = ?\ta = ";
    int a;
    cin >> a;
    cout << "\tb = ";
    int b;
    cin >> b;
    pair<int, int> my_pair = divmod(a, b);
    cout << "\na/b = " << my_pair.first << "\ta%b = " << my_pair.second;
}

tuple<int, int, string> divmod_tuple(int a, int b) {
    if (a % b)
        return make_tuple(a / b, a % b, "imperfect");
    else
        return make_tuple(a / b, a % b, "perfect");
}

void f_tuples() {
    cout << "\na/b = ?\ta = ";
    int a;
    cin >> a;
    cout << "\tb = ";
    int b;
    cin >> b;
    tuple<int, int, string> my_tuple = divmod_tuple(a, b);
    cout << "\n|||\ta / b\t" << get<0>(my_tuple) << "\t|||\ta % b =\t" << get<1>(my_tuple) << "\t|||\t" << get<2>(my_tuple);
}

int main()
{
    cout << "Today we're gonna learn about STL!\n";
    int decision;

    do{
        cout << "Press:\n\t 1: VECTORS\n\t 2: MAPS\n\t 3: PAIRS\n\t 4: TUPLES";
        cin >> decision;
    } while (decision != 1 && decision != 2 && decision != 3 && decision != 4);

    switch (decision) {
        case 1: 
            f_vectors(); break;
        case 2:
            f_maps(); break;
        case 3:
            f_pairs(); break;
        case 4:
            f_tuples(); break;
        default:
            break;
    }

    return 0;
}
