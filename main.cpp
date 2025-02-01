#include <iostream>
#include <string>
using namespace std;

// Step 1: Define the Robot class
class Robot {
private:
    string name;
    string model;
    int batteryLife;

public:
    // Constructor

    Robot(string n, string m, int bL) : name(n), model(m), batteryLife(bL) {}

    // Getter Methods

    string getName() {return name;}

    string getModel() {return model;}

    int getBatteryLife() {return batteryLife;}

    // Setter Methods

    void setName(string n) {name = n;}

    void setModel(string m) {model = m;}

    void setBatteryLife(int bL) {batteryLife = bL;}

    // Display function
    void displayRobot() {
        cout << "Robot: " << name << " | Model: " << model << " | Battery Life: " << batteryLife << "%\n";
    }
};

// Step 2: Function to modify robot (pass by value)
void modifyRobotNameByValue(Robot robot, string name) {
    robot.setName(name);
    cout << "inside modify robot name by value" << endl;
}
void modifyRobotModelByValue(Robot robot, string model) {
    robot.setModel(model);
    cout << "inside modify robot model by value" << endl;
}
void modifyRobotBatteryLifeByValue(Robot robot, int bL) {
    robot.setBatteryLife(bL);
    cout << "inside modify robot battery life by value" << endl;
}
// Step 3: Function to modify robot (pass by reference)
void modifyRobotNameByReference(Robot& robot, string name) {
    robot.setName(name);
    cout << "inside modify robot name by reference" << endl;
}
void modifyRobotModelByReference(Robot& robot, string model) {
    robot.setModel(model);
    cout << "inside modify robot model by reference" << endl;
}
void modifyRobotBatteryLifeByReference(Robot& robot, int bL) {
    robot.setBatteryLife(bL);
    cout << "inside modify robot battery life by reference" << endl;
}

// Step 4: Template class for a Fleet that stores multiple robots
template <typename T>
class Fleet {
private:
    T* robots;
    int capacity;
    int count;

public:
    // Constructor: Allocates space for 'capacity' robots
    Fleet(int cap) {
        capacity = cap;
        count = 0;
        robots = new T[capacity];
    }

    // Add robot to fleet
    void addRobot(T robot) {
        if (count < capacity) {
            robots[count] = robot;
            count++;
        } else {
            cout << "Fleet is full!\n";
        }
    }

    // Display all robots
    void showFleet() {
        cout << "Fleet contains:\n";
        for (int i = 0; i < count; i++) {
            cout << "- " << robots[i] << "\n";
        }
    }

    // Destructor: Free allocated memory
    ~Fleet() {
        delete[] robots;
    }
};

int main() {
    // Step 5: Create a Robot object
    Robot robot1("Joey", "Robot 2405", 3);

    // Step 6: Use pointers to access Robot object
    Robot* robot1Ptr = &robot1;

    cout << "Updated Battery Life (using pointer): " << robot1Ptr->getBatteryLife() << "%\n";

    // Step 7: Pass by value (no change outside function)
    modifyRobotBatteryLifeByValue(robot1, 1);

    cout << "After modifyRobotByValue, Battery Life: " << robot1.getBatteryLife() << "%\n";

    // Step 8: Pass by reference (changes persist)

   // cout << "After modifyRobotByReference, Battery Life: " << myRobot.getBatteryLife() << "%\n";

    // Step 9: Use the Fleet template class
    Fleet<string> myFleet(3);
    myFleet.addRobot("Autobot-X");
    myFleet.addRobot("Cybertron-7");
    myFleet.addRobot("NanoDroid-3");

    myFleet.showFleet();

    return 0;
}