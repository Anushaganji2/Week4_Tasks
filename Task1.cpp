#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct Control {
    int id;               
    string type;    
    string state;    
    bool operator==(const Control& other) const {
        return id == other.id && type == other.type && state == other.state;
    }
};
int main() {
    vector<Control> controls = {
        {1, "button", "visible"},
        {2, "button", "invisible"},
        {3, "slider", "visible"},
        {4, "slider", "disabled"},
        {5, "button", "visible"},
        {6, "slider", "invisible"},
        {7, "button", "disabled"},
        {8, "slider", "visible"},
        {9, "button", "invisible"},
        {10, "slider", "disabled"}
    };
    cout << "All Controls:\n";
    for_each(controls.begin(), controls.end(), [](const Control& ctrl) {
        cout << "ID: " << ctrl.id << ", Type: " << ctrl.type << ", State: " << ctrl.state << "\n";
    });
    auto foundControl = find_if(controls.begin(), controls.end(), [](const Control& ctrl) {
        return ctrl.id == 3;
    });
    if (foundControl != controls.end()) {
        cout << "\nFound Control with ID 3: Type: " << foundControl->type 
                  << ", State: " << foundControl->state << "\n";
    } else {
        cout << "\nControl with ID 3 not found.\n";
    }
    auto invisibleControl = find_if(controls.begin(), controls.end(), [](const Control& ctrl) {
        return ctrl.state == "invisible";
    });
    if (invisibleControl != controls.end()) {
        cout << "\nFirst Invisible Control: ID: " << invisibleControl->id 
                  << ", Type: " << invisibleControl->type << "\n";
    } else {
        cout << "\nNo invisible controls found.\n";
    }
    auto consecutiveSameState = adjacent_find(controls.begin(), controls.end(), [](const Control& a, const Control& b) {
        return a.state == b.state;
    });
    if (consecutiveSameState != controls.end()) {
        cout << "\nFound consecutive controls with the same state:\n";
        cout << "ID1: " << consecutiveSameState->id 
                  << ", State: " << consecutiveSameState->state 
                  << "; ID2: " << (consecutiveSameState + 1)->id 
                  << ", State: " << (consecutiveSameState + 1)->state << "\n";
    } else {
        cout << "\nNo consecutive controls with the same state found.\n";
    }
    int visibleCount = count_if(controls.begin(), controls.end(), [](const Control& ctrl) {
        return ctrl.state == "visible";
    });
    cout << "\nNumber of Visible Controls: " << visibleCount << "\n";
    int disabledSlidersCount = count_if(controls.begin(), controls.end(), [](const Control& ctrl) {
        return ctrl.type == "slider" && ctrl.state == "disabled";
    });
    cout << "\nNumber of Disabled Sliders: " << disabledSlidersCount << "\n";
    bool areIdentical = equal(controls.begin(), controls.begin() + 5, controls.begin() + 5);
    if (areIdentical) {
        cout << "\nThe first five controls are identical to the next five.\n";
    } else {
        cout << "\nThe first five controls are NOT identical to the next five.\n";
    }
    return 0;
}
/*All Controls:
ID: 1, Type: button, State: visible
ID: 2, Type: button, State: invisible
ID: 3, Type: slider, State: visible
ID: 4, Type: slider, State: disabled
ID: 5, Type: button, State: visible
ID: 6, Type: slider, State: invisible
ID: 7, Type: button, State: disabled
ID: 8, Type: slider, State: visible
ID: 9, Type: button, State: invisible
ID: 10, Type: slider, State: disabled

Found Control with ID 3: Type: slider, State: visible

First Invisible Control: ID: 2, Type: button

No consecutive controls with the same state found.

Number of Visible Controls: 4

Number of Disabled Sliders: 2

The first five controls are NOT identical to the next five.
*/
