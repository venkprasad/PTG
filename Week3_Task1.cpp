#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MenuItem {
public:
    string name;  
    vector<MenuItem> subMenus; 
    
    // Constructor to initialize the menu item
    MenuItem(string name) : name(name) {}

    // Add a submenu under the current menu item
    void addSubMenu(MenuItem menu) {
        subMenus.push_back(menu);
    }
};

// MenuNavigation class to manage the menu system
class MenuNavigation {
private:
    vector<MenuItem> mainMenu;  // The root level menu items
    MenuItem* currentMenu;  // Pointer to the current menu
    vector<MenuItem*> menuHistory;  // Stack to keep track of menu history 

public:
    // Constructor
    MenuNavigation() {
        currentMenu = nullptr;
    }

    // Function to initialize the menu structure
    void initializeMenu() {
        // Main menu creation
        MenuItem settings("Settings");
        settings.addSubMenu(MenuItem("Display Settings"));
        settings.addSubMenu(MenuItem("Audio Settings"));

        MenuItem media("Media");
        media.addSubMenu(MenuItem("Radio"));
        media.addSubMenu(MenuItem("Bluetooth Audio"));

        mainMenu.push_back(settings);
        mainMenu.push_back(media);

        currentMenu = &mainMenu[0];  // Set the starting menu to the first one (Settings)
    }

    // Display the current menu and its submenus
    void displayMenu() {
        cout << "\nCurrent Menu: " << currentMenu->name << endl;

        if (!currentMenu->subMenus.empty()) {
            for (int i = 0; i < currentMenu->subMenus.size(); i++) {
                cout << i + 1 << ". " << currentMenu->subMenus[i].name << endl;
            }
        } else {
            cout << "This is a leaf menu. No further options." << endl;
        }
    }

    // Navigate down to a submenu (selecting the nth option)
    void navigateDown(int option) {
        if (option >= 1 && option <= currentMenu->subMenus.size()) {
            menuHistory.push_back(currentMenu);  // Save the current menu to go back later
            currentMenu = &currentMenu->subMenus[option - 1];  // Go to the selected submenu
        } else {
            cout << "Invalid option!" << endl;
        }
    }

    // Navigate up to the previous menu
    void navigateUp() {
        if (!menuHistory.empty()) {
            currentMenu = menuHistory.back();  // Go back to the previous menu
            menuHistory.pop_back();  // Remove the last menu from the history
        } else {
            cout << "You are already at the main menu." << endl;
        }
    }

    // Enter the current menu if it has no submenus (leaf menu)
    void enterMenu() {
        if (currentMenu->subMenus.empty()) {
            cout << "Entering: " << currentMenu->name << endl;
        } else {
            cout << "This menu has submenus. Use '1' to navigate down." << endl;
        }
    }

    // Handle user input for menu navigation
    void handleUserInput() {
        int choice;
        while (true) {
            displayMenu();  // Show the current menu
            cout << "Enter your choice (1 to go down, 2 to go up, 3 to enter, 0 to exit): ";
            cin >> choice;

            // Handle the user's choice
            if (choice == 1) {
                cout << "Enter submenu number: ";
                int option;
                cin >> option;
                navigateDown(option);  // Navigate down to the selected submenu
            } else if (choice == 2) {
                navigateUp();  // Go back to the previous menu
            } else if (choice == 3) {
                enterMenu();  // Enter the current menu if it's a leaf
            } else if (choice == 0) {
                break;  // Exit the program
            } else {
                cout << "Invalid number please try again" << endl;
            }
        }
    }
};

int main() {
    MenuNavigation menuNav;
    menuNav.initializeMenu();  // Set up the menu structure
    menuNav.handleUserInput();  // Start handling user input
    return 0;
}
