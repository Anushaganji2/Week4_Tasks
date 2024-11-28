#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<string> controls = {"visible", "invisible", "disabled", "visible", "disabled"};
    vector<string> controls_backup(controls.size());
    copy(controls.begin(), controls.end(), controls_backup.begin());
    fill(controls.begin(), controls.end(), "disabled");
    srand(time(0));
    vector<string> states = {"visible", "invisible", "disabled"};
    generate(controls.begin(), controls.end(), [&]() {
        return states[rand() % states.size()];
    });
    for (const auto &state : controls) cout << state << " ";
    cout << endl;
    transform(controls.begin(), controls.end(), controls.begin(), [](const string &state) {
        return (state == "visible") ? "invisible" : state;
    });
    for (const auto &state : controls) cout << state << " ";
    cout << endl;
    replace(controls.begin(), controls.end(), string("disabled"), string("enabled"));
    for (const auto &state : controls) cout << state << " ";
    cout << endl;
    auto it = remove_if(controls.begin(), controls.end(), [](const string &state) {
        return state == "invisible";
    });
    controls.erase(it, controls.end());
    for (const auto &state : controls) cout << state << " ";
    cout << endl;
    reverse(controls.begin(), controls.end());
    for (const auto &state : controls) cout << state << " ";
    cout << endl;
    partition(controls.begin(), controls.end(), [](const string &state) {
        return state == "visible";
    });
    for (const auto &state : controls) cout << state << " ";
    cout << endl;
    return 0;
}


/*output
invisible disabled visible disabled visible 
invisible disabled invisible disabled invisible 
invisible enabled invisible enabled invisible 
enabled enabled 
enabled enabled 
enabled enabled */
