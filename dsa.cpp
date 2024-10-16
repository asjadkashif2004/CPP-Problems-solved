#include <iostream>
#include <string>

struct Contact {
    std::string name;
    std::string phoneNumber;
};

struct ContactList {
    Contact* contacts;  // Pointer to an array of Contact structs
    int numberOfContacts;  // Tracks the number of contacts in the list
    int maxCapacity;  // Maximum capacity of the contact list

    // Constructor to initialize the ContactList
    ContactList(int capacity) {
        maxCapacity = capacity;
        contacts = new Contact[maxCapacity];  // Dynamically allocate memory for the array
        numberOfContacts = 0;  // Initially, there are no contacts
    }

    // Destructor to free the allocated memory
    ~ContactList() {
        delete[] contacts;  // Free the dynamically allocated array
    }

    // Function to add a new contact
    void addContact(const std::string& name, const std::string& phoneNumber) {
        if (numberOfContacts < maxCapacity) {
            contacts[numberOfContacts].name = name;
            contacts[numberOfContacts].phoneNumber = phoneNumber;
            numberOfContacts++;
        } else {
            std::cout << "Contact list is full. Cannot add more contacts." << std::endl;
        }
    }

    // Function to print all contacts
    void printContacts() const {
        if (numberOfContacts == 0) {
            std::cout << "No contacts in the list." << std::endl;
        } else {
            for (int i = 0; i < numberOfContacts; i++) {
                std::cout << "Contact " << i + 1 << ": " 
                          << contacts[i].name << " - " 
                          << contacts[i].phoneNumber << std::endl;
            }
        }
    }
};

int main() {
    // Create a contact list with a capacity of 5 contacts
    ContactList contactList(5);

    // Add a few contacts
    contactList.addContact("Alice", "123-456-7890");
    contactList.addContact("Bob", "987-654-3210");
    contactList.addContact("Charlie", "555-123-4567");

    // Print all contacts
    contactList.printContacts();

    return 0;
}

