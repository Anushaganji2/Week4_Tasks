#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main() {
    vector<string> controlStates = {"visible", "invisible", "enabled", "disabled"};
    vector<string> backupStates(controlStates.size());
    copy(controlStates.begin(), controlStates.end(), backupStates.begin());
    cout << "Backup States: ";
    for (const auto& state : backupStates) cout << state << " ";
    cout << "\n";
    fill(controlStates.begin(), controlStates.end(), "disabled");
    cout << "After fill: ";
    for (const auto& state : controlStates) cout << state << " ";
    cout << "\n";
    auto getRandomState = []() {
        const char* states[] = {"visible", "invisible", "disabled"};
        return states[rand() % 3];
    };
    generate(controlStates.begin(), controlStates.end(), getRandomState);
    cout << "After generate: ";
    for (const auto& state : controlStates) cout << state << " ";
    cout << "\n";
    transform(controlStates.begin(), controlStates.end(), controlStates.begin(),
                   [](const string& state) { return (state == "slider") ? "invisible" : state; });
    replace(controlStates.begin(), controlStates.end(), string("disabled"), string("enabled"));
    auto newEnd = remove_if(controlStates.begin(), controlStates.end(),
                                  [](const string& state) { return state == "invisible"; });
    controlStates.erase(newEnd, controlStates.end());
    reverse(controlStates.begin(), controlStates.end());
    auto partitionPoint = partition(controlStates.begin(), controlStates.end(),
                                         [](const string& state) { return state == "visible"; });
    cout << "Final Control States: ";
    for (const auto& state : controlStates) cout << state << " ";
    return 0;
}

/*output
Backup States: visible invisible enabled disabled 
After fill: disabled disabled disabled disabled 
After generate: invisible invisible visible invisible 
Final Control States: visible*/
