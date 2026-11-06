#include <iostream>
#include <string>

using namespace std;

/**
 * Define a class TreasureNode to represent a node in a singly linked list.
 * The class should have the following attributes:
 * location (std::string): The location of the treasure.
 * next (TreasureNode*): A pointer to the next node in the list.
 * Implement a constructor to initialize the node's location and set next to nullptr
 */
class TreasureNode {
public:
    string location; 
    TreasureNode* next;  

    TreasureNode(string loc) : location(loc) {
        next = nullptr; 
    }
};
/**
 * Create the TreasureMap Class (Singly Linked List)
 * Define a class TreasureMap to represent a singly linked list of treasure locations.
 * The class should have the following private attribute:
 * head (TreasureNode*): A pointer to the first node in the list.
 * Implement the following public methods:
 * addLocation(std::string loc): Adds a new treasure location to the end of the list.
 * displayMap(): Displays all the treasure locations in the list.
 */
class TreasureMap {
    TreasureNode* head = nullptr;
public: 
    void addLocation(string loc) {
        TreasureNode* newLoc = new TreasureNode(loc); 
        if (head == nullptr) {
            head = newLoc; 
            return; 
        }
        TreasureNode* current = head;        
        while (current->next) {
            current = current->next; 
        }
        current->next = newLoc; 
    }
    void displayMap() {
        TreasureNode* display = head;
        while (display) {
            cout << "Location: " << display->location; 
            if (display->next) {
                cout << " -> ";
            }
            display = display->next;
        }
        cout << endl; 
    }
    ~TreasureMap() {
        cout << "Destructor called on Treasure map" << endl; 
        while (head) {
            TreasureNode* temp = head;
            head = head->next;
            delete temp; 
        }
    }
};
/**
 * Create the DoublyTreasureNode Class
 * Define a class DoublyTreasureNode to represent a node in a doubly linked list.
 * The class should have the following attributes:
 * location (std::string): The location of the treasure.
 * next (DoublyTreasureNode*): A pointer to the next node in the list.
 * prev (DoublyTreasureNode*): A pointer to the previous node in the list.
 * Implement a constructor to initialize the node's location and set next and prev to nullptr.
 */
class DoublyTreasureNode {
public: 
    string location;
    DoublyTreasureNode* next;
    DoublyTreasureNode* prev;

    DoublyTreasureNode(string loc) : location(loc) {
        prev = next = nullptr; 
    }
};
/**
 * Create the EnhancedTreasureMap Class (Doubly Linked List)
 * Define a class EnhancedTreasureMap to represent a doubly linked list of treasure locations.
 * The class should have the following private attributes:
 * head (DoublyTreasureNode*): A pointer to the first node in the list.
 * tail (DoublyTreasureNode*): A pointer to the last node in the list.
 * Implement the following public methods:
 * addLocation(std::string loc): Adds a new treasure location to the end of the list.
 * displayMapForward(): Displays all the treasure locations from head to tail. When the end is reached, display "End of Map".
 * displayMapBackward(): Displays all the treasure locations from tail to head. When the start is reached, display "Start of Map".
 */
class EnhancedTreasureMap {
    DoublyTreasureNode* head = nullptr;
    DoublyTreasureNode* tail = nullptr;
public:
    void addLocation(string loc) {
        DoublyTreasureNode* newLoc = new DoublyTreasureNode(loc);
        //1. new list, head and tail = nullptr
        if (head == nullptr && tail == nullptr) {
            head = tail = newLoc; 
        } else {
            tail->next = newLoc;
            newLoc->prev = tail;
            tail = tail->next; 
        }        
    }
    void displayMapForward() {
        DoublyTreasureNode* display = head; 
        while (display) {
            cout << "Location: " << display->location << " -> ";
            display = display->next;    
        }
        cout << " End of map" << endl; 
    }
    void displayMapBackward() {
        DoublyTreasureNode* display = tail;
        while (display) {
            cout << "Location: " << display->location << " -> ";
            display = display->prev;   
        }
        cout << " Start of map " << endl; 
    }
    ~EnhancedTreasureMap() {
        cout << "Destructor called on Enhanced Treasure Map" << endl;
        while (head) {
            DoublyTreasureNode* temp = head;
            head = head->next; 
            delete temp;
        }
    }

};
int main()
{
    /**
     * Simulate the Treasure Hunt (Using the Singly Linked List)
     * Create an instance of TreasureMap and add several treasure locations ("Beach", "Forest", "Cave", and "Mountain").
     * Use the displayMap() method to show all the locations in the map.
     */
    TreasureMap singleMap;
    singleMap.addLocation("Beach");
    singleMap.addLocation("Forest");
    singleMap.addLocation("Cave");
    singleMap.addLocation("Mountain");

    cout << "Treasure Map: " << endl;
    singleMap.displayMap(); 
    cout << endl; 

    /**
     * Simulate the Treasure Hunt (Using the Doubly Linked List)
     * Create an instance of EnhancedTreasureMap and add several treasure locations ("Beach", "Forest", "Cave", "Mountain").
     * Use the displayMapForward() method to show all the locations from start to end.
     * Use the displayMapBackward() method to show all the locations from end to start.
     */
    EnhancedTreasureMap doubleMap;
    doubleMap.addLocation("Castle");
    doubleMap.addLocation("Village");
    doubleMap.addLocation("Shire");
    doubleMap.addLocation("Tree House");

    cout << "Enhanced Treasure Map forward: " << endl;
    doubleMap.displayMapForward();
    cout << endl; 
    cout << "Enhanced Treasure Map backward: " << endl; 
    doubleMap.displayMapBackward();
    cout << endl; 
}