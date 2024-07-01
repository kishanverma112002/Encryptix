#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Structure to represent a scene in the game
struct Scene {
    string description;
    string choice1;
    string choice2;
    int outcome1;
    int outcome2;
    bool isFinalScene;
};

// Function to display the current scene
void displayScene(const Scene &scene) {
    cout << scene.description << endl;
    cout << "Do you: " << endl;
    cout << "1. " << scene.choice1 << endl;
    cout << "2. " << scene.choice2 << endl;
}

// Function to get the user's choice
int getUserChoice() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// Function to determine the outcome of the user's choice
int determineOutcome(int choice, const Scene &scene) {
    if (choice == 1) {
        return scene.outcome1;
    } else if (choice == 2) {
        return scene.outcome2;
    } else {
        cout << "Invalid choice. Please try again." << endl;
        return getUserChoice();
    }
}

int main() {
    srand(time(0)); // Seed the random number generator

    // Define the scenes in the game
    Scene scenes[14] = {
        {"You are a brave adventurer seeking fortune and glory in the land of Eldoria. You stand at the entrance of a dark and mysterious forest.", "Enter the forest", "Go back home", 1, 0, false},
        {"You are walking through the forest, and you come across a clearing. In the center of the clearing is a large stone pedestal.", "Investigate the pedestal", "Search the perimeter of the clearing", 2, 3, false},
        {"On top of the pedestal is a small, intricately carved box. It is locked, but you think you can pick the lock.", "Try to pick the lock", "Leave the box alone", 4, 5, false},
        {"You search the perimeter of the clearing and find a small, hidden door. It is slightly ajar.", "Open the door", "Go back to the pedestal", 6, 2, false},
        {"You pick the lock and open the box. Inside, you find a small, glowing crystal.", "Take the crystal", "Leave the crystal", 7, 8, false},
        {"You leave the box alone and continue on your journey.", "Continue through the forest", "Go back home", 9, 0, false},
        {"You open the door and find a small, dimly lit room. There is a figure sitting in the corner.", "Approach the figure", "Leave the room", 10, 2, false},
        {"You take the crystal and feel a surge of energy. You can sense that it has powerful magic.", "Use the crystal", "Put the crystal back", 11, 4, false},
        {"You leave the crystal and continue on your journey.", "Continue through the forest", "Go back home", 9, 0, false},
        {"The figure is an old wizard. He tells you that you have passed a test and offers to grant you a wish.", "Make a wish", "Refuse the offer", 12, 13, false},
        {"You use the crystal and feel a surge of energy. You can sense that it has powerful magic.", "Continue through the forest", "Go back home", 9, 0, false},
        {"You refuse the offer and leave the room.", "Continue through the forest", "Go back home", 9, 0, false},
        {"You make a wish and the wizard grants it. You feel a sense of satisfaction and accomplishment.", "Congratulations, you have won the game!", "", 0, 0, true},
        {"You have reached the end of the forest. You see a castle in the distance.", "Approach the castle", "Go back home", 12, 0, false},
    };

    int currentScene = 0;

    while (true) {
        displayScene(scenes[currentScene]);

        int choice = getUserChoice();
        currentScene = determineOutcome(choice, scenes[currentScene]);

        if (scenes[currentScene].isFinalScene) {
            displayScene(scenes[currentScene]);
            break;
        }
    }

    return 0;
}