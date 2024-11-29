#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>

using namespace std;

class ModeObserver {
public:
    virtual void update(const string& mode) = 0;
    virtual ~ModeObserver() {}
};

class Button : public ModeObserver {
public:
    void update(const string& mode) override {
        if (mode == "Night") {
            cout << "Button: Switching to Night Mode visuals." << endl;
        } else {
            cout << "Button: Switching to Day Mode visuals." << endl;
        }
    }
};

class Slider : public ModeObserver {
public:
    void update(const string& mode) override {
        if (mode == "Night") {
            cout << "Slider: Dimming for Night Mode." << endl;
        } else {
            cout << "Slider: Brightening for Day Mode." << endl;
        }
    }
};

class Switch : public ModeObserver {
public:
    void update(const string& mode) override {
        if (mode == "Night") {
            cout << "Switch: Toggling to Night Mode." << endl;
        } else {
            cout << "Switch: Toggling to Day Mode." << endl;
        }
    }
};

class HMISystem {
private:
    vector<shared_ptr<ModeObserver>> observers;
    string mode = "Day";
public:
    void attach(shared_ptr<ModeObserver> observer) {
        observers.push_back(observer);
    }
    void detach(shared_ptr<ModeObserver> observer) {
        observers.erase(
            remove(observers.begin(), observers.end(), observer),
            observers.end()
        );
    }
    void notify() {
        for (const auto& observer : observers) {
            observer->update(mode);
        }
    }
    void setMode(const string& newMode) {
        mode = newMode;
        cout << "HMISystem: Mode changed to " << mode << ". Notifying observers..." << endl;
        notify();
    }
};

int main() {
    HMISystem hmiSystem;

    auto button = make_shared<Button>();
    auto slider = make_shared<Slider>();
    auto switchObserver = make_shared<Switch>();

    hmiSystem.attach(button);
    hmiSystem.attach(slider);
    hmiSystem.attach(switchObserver);

    hmiSystem.setMode("Night");
    hmiSystem.setMode("Day");

    hmiSystem.detach(button);

    hmiSystem.setMode("Night");

    return 0;
}
/*output
HMISystem: Mode changed to Night. Notifying observers...
Button: Switching to Night Mode visuals.
Slider: Dimming for Night Mode.
Switch: Toggling to Night Mode.
HMISystem: Mode changed to Day. Notifying observers...
Button: Switching to Day Mode visuals.
Slider: Brightening for Day Mode.
Switch: Toggling to Day Mode.
HMISystem: Mode changed to Night. Notifying observers...
Slider: Dimming for Night Mode.
Switch: Toggling to Night Mode.*/
