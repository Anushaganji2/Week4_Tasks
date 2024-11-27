#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
struct Control {
    int id;               // Unique ID
    std::string type;     // "button" or "slider"
    std::string state;    // "visible", "invisible", "disabled"

    // Implement the equality operator
    bool operator==(const Control& other) const {
        return id == other.id && type == other.type && state == other.state;
    }
};
int main() {
    // Step 1: Initialize a container of controls with sample data
    std::vector<Control> controls = {
        {1, "button", "visible"},
        {2, "slider", "invisible"},
        {3, "button", "disabled"},
        {4, "slider", "visible"},
        {5, "button", "visible"},
        {6, "slider", "disabled"},
        {7, "button", "invisible"},
        {8, "slider", "visible"},
        {9, "button", "visible"},
        {10, "slider", "disabled"}
    };
    std::cout << "All Controls:\n";
    std::for_each(controls.begin(), controls.end(), [](const Control& ctrl) {
        std::cout << "ID: " << ctrl.id << ", Type: " << ctrl.type << ", State: " << ctrl.state << "\n";
    });
    std::cout << "\n";
    auto it = std::find_if(controls.begin(), controls.end(), [](const Control& ctrl) { return ctrl.id == 5; });
    if (it != controls.end()) {
        std::cout << "Found control with ID 5: Type = " << it->type << ", State = " << it->state << "\n";
    } else {
        std::cout << "Control with ID 5 not found.\n";
    }
    std::cout << "\n";
    auto invisibleControl = std::find_if(controls.begin(), controls.end(), [](const Control& ctrl) {
        return ctrl.state == "invisible";
    });
    if (invisibleControl != controls.end()) {
        std::cout << "First invisible control: ID = " << invisibleControl->id << ", Type = " << invisibleControl->type << "\n";
    } else {
        std::cout << "No invisible control found.\n";
    }
    std::cout << "\n";
    auto adjacent = std::adjacent_find(controls.begin(), controls.end(), [](const Control& a, const Control& b) {
        return a.state == b.state;
    });
    if (adjacent != controls.end()) {
        std::cout << "Found adjacent controls with the same state: ID = " << adjacent->id << " and ID = " << (adjacent + 1)->id << "\n";
    } else {
        std::cout << "No adjacent controls with the same state found.\n";
    }
    std::cout << "\n";
    int visibleCount = std::count_if(controls.begin(), controls.end(), [](const Control& ctrl) {
        return ctrl.state == "visible";
    });
    std::cout << "Number of visible controls: " << visibleCount << "\n\n";
    int disabledSlidersCount = std::count_if(controls.begin(), controls.end(), [](const Control& ctrl) {
        return ctrl.type == "slider" && ctrl.state == "disabled";
    });
    std::cout << "Number of disabled sliders: " << disabledSlidersCount << "\n\n";
    std::vector<Control> controlsSubset = {
        {1, "button", "visible"},
        {2, "slider", "invisible"},
        {3, "button", "disabled"}
    };
    bool areEqual = std::equal(controls.begin(), controls.begin() + 3, controlsSubset.begin(), controlsSubset.end());
    if (areEqual) {
        std::cout << "The first 3 controls are identical to the subset.\n";
    } else {
        std::cout << "The first 3 controls are not identical to the subset.\n";
    }
    return 0;
}
/*Sample output:All Controls:
ID: 1, Type: button, State: visible
ID: 2, Type: slider, State: invisible
ID: 3, Type: button, State: disabled
ID: 4, Type: slider, State: visible
ID: 5, Type: button, State: visible
ID: 6, Type: slider, State: disabled
ID: 7, Type: button, State: invisible
ID: 8, Type: slider, State: visible
ID: 9, Type: button, State: visible
ID: 10, Type: slider, State: disabled

Found control with ID 5: Type = button, State = visible

First invisible control: ID = 2, Type = slider

Found adjacent controls with the same state: ID = 2 and ID = 3

Number of visible controls: 4

Number of disabled sliders: 3

The first 3 controls are not identical to the subset.
*/
