#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main() {
    vector<string> dynamicWidgets = {"Speedometer", "Tachometer", "FuelGauge", "TemperatureGauge"};
    set<string> staticWidgets = {"Logo", "WarningLights", "BatteryIndicator"};
    cout << "Dynamic Widgets:\n";
    for (auto it = dynamicWidgets.begin(); it != dynamicWidgets.end(); ++it) {
        cout << *it << "\n";
    }
    auto findResult = staticWidgets.find("WarningLights");
    if (findResult != staticWidgets.end()) {
        cout << "\"WarningLights\" is found in static widgets.\n";
    } else {
        cout << "\"WarningLights\" is not found in static widgets.\n";
    }
    vector<string> combinedWidgets;
    combinedWidgets.reserve(dynamicWidgets.size() + staticWidgets.size());
    copy(dynamicWidgets.begin(), dynamicWidgets.end(), back_inserter(combinedWidgets));
    copy(staticWidgets.begin(), staticWidgets.end(), back_inserter(combinedWidgets));
    auto searchResult = find(combinedWidgets.begin(), combinedWidgets.end(), "FuelGauge");
    if (searchResult != combinedWidgets.end()) {
        cout << "\"FuelGauge\" is found in the combined widget list.\n";
    } else {
        cout << "\"FuelGauge\" is not found in the combined widget list.\n";
    }
    cout << "Combined Widget List:\n";
    for (const auto& widget : combinedWidgets) {
        cout << widget << "\n";
    }
    return 0;
}
/*output
Dynamic Widgets:
Speedometer
Tachometer
FuelGauge
TemperatureGauge
"WarningLights" is found in static widgets.
"FuelGauge" is found in the combined widget list.
Combined Widget List:
Speedometer
Tachometer
FuelGauge
TemperatureGauge
BatteryIndicator
Logo
WarningLights*/
