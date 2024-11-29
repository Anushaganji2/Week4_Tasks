#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Control {
    int id;
    string type;
    string state; 

    void print() const {
        cout << "ID: " << id << ", Type: " << type << ", State: " << state << endl;
    }

    bool operator<(const Control& other) const {
        return id < other.id;
    }

    bool operator==(const Control& other) const {
        return id == other.id && type == other.type && state == other.state;
    }
};

void printControls(const string& header, const vector<Control>& controls) {
    cout << header << endl;
    for (const auto& control : controls) {
        control.print();
    }
    cout << endl;
}

void searchControlById(const vector<Control>& controls, int searchId) {
    auto it = lower_bound(controls.begin(), controls.end(), Control{searchId, "", ""});
    if (it != controls.end() && it->id == searchId) {
        cout << "Control with ID " << searchId << " found:" << endl;
        it->print();
    } else {
        cout << "Control with ID " << searchId << " not found." << endl;
    }
    cout << endl;
}

vector<Control> mergeControls(const vector<Control>& controls1, const vector<Control>& controls2) {
    vector<Control> mergedControls(controls1.size() + controls2.size());
    merge(controls1.begin(), controls1.end(), controls2.begin(), controls2.end(), mergedControls.begin());
    return mergedControls;
}

vector<Control> inPlaceMergeControls(vector<Control>& inplaceList, size_t midpoint) {
    inplace_merge(inplaceList.begin(), inplaceList.begin() + midpoint, inplaceList.end());
    return inplaceList;
}

void setOperations(const vector<Control>& controls1, const vector<Control>& controls2) {
    vector<Control> setUnion, setIntersection;

    set_union(controls1.begin(), controls1.end(), controls2.begin(), controls2.end(), back_inserter(setUnion));
    set_intersection(controls1.begin(), controls1.end(), controls2.begin(), controls2.end(), back_inserter(setIntersection));

    printControls("Set union of Controls 1 and Controls 2:", setUnion);

    cout << "Set intersection of Controls 1 and Controls 2:" << endl;
    if (setIntersection.empty()) {
        cout << "No common elements." << endl;
    } else {
        for (const auto& control : setIntersection) {
            control.print();
        }
    }
    cout << endl;
}

int main() {
    vector<Control> controls1 = { {3, "button", "visible"}, {1, "slider", "invisible"}, {5, "button", "disabled"} };
    vector<Control> controls2 = { {1, "slider", "invisible"}, {2, "button", "visible"}, {6, "slider", "disabled"} };

    sort(controls1.begin(), controls1.end());
    sort(controls2.begin(), controls2.end());

    printControls("Controls 1 after sorting:", controls1);
    printControls("Controls 2 after sorting:", controls2);

    searchControlById(controls1, 3);

    vector<Control> mergedControls = mergeControls(controls1, controls2);
    printControls("Merged controls:", mergedControls);

    vector<Control> inplaceList = {
        {1, "slider", "visible"}, {4, "button", "invisible"}, {6, "button", "disabled"}, 
        {2, "button", "visible"}, {5, "slider", "visible"}, {8, "slider", "disabled"} 
    };
    inplaceList = inPlaceMergeControls(inplaceList, 3);
    printControls("List after in-place merging:", inplaceList);

    setOperations(controls1, controls2);

    return 0;
}
/*output 
Controls 1 after sorting:
ID: 1, Type: slider, State: invisible
ID: 3, Type: button, State: visible
ID: 5, Type: button, State: disabled

Controls 2 after sorting:
ID: 1, Type: slider, State: invisible
ID: 2, Type: button, State: visible
ID: 6, Type: slider, State: disabled

Control with ID 3 found:
ID: 3, Type: button, State: visible

Merged controls:
ID: 1, Type: slider, State: invisible
ID: 1, Type: slider, State: invisible
ID: 2, Type: button, State: visible
ID: 3, Type: button, State: visible
ID: 5, Type: button, State: disabled
ID: 6, Type: slider, State: disabled

List after in-place merging:
ID: 1, Type: slider, State: visible
ID: 2, Type: button, State: visible
ID: 4, Type: button, State: invisible
ID: 5, Type: slider, State: visible
ID: 6, Type: button, State: disabled
ID: 8, Type: slider, State: disabled

Set union of Controls 1 and Controls 2:
ID: 1, Type: slider, State: invisible
ID: 2, Type: button, State: visible
ID: 3, Type: button, State: visible
ID: 5, Type: button, State: disabled
ID: 6, Type: slider, State: disabled

Set intersection of Controls 1 and Controls 2:
ID: 1, Type: slider, State: invisible*/
