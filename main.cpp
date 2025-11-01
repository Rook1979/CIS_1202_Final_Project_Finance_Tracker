// Stephan Ulbrich
// CIS 1202 101
// 11-01-2025

#include "utils.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Finance> records;
    std::string filename = "expenses.dat";
    int choice;

    do {
        std::cout << "\nPersonal Finance Tracker\n";
        std::cout << "1. Add Expense\n2. View All\n3. Save\n4. Load\n5. Summary\n0. Exit\nChoice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string cat, dt, nt;
            double amt;

            std::cout << "Enter category: ";
            std::cin >> cat;
            std::cout << "Enter amount: ";
            std::cin >> amt;
            std::cout << "Enter date (YYYY-MM-DD): ";
            std::cin >> dt;
            std::cin.ignore();
            std::cout << "Enter note: ";
            std::getline(std::cin, nt);

            if (!isValidAmount(amt) || !isValidDate(dt)) {
                std::cout << "Invalid input. Try again.\n";
            } else {
                records.emplace_back(cat, amt, dt, nt);
                std::cout << "Expense added.\n";
            }
        } else if (choice == 2) {
            displayAll(records);
        } else if (choice == 3) {
            saveToFile(records, filename);
            std::cout << "Data saved.\n";
        } else if (choice == 4) {
            loadFromFile(records, filename);
            std::cout << "Data loaded.\n";
        } else if (choice == 5) {
            std::cout << "Total: $" << calculateTotal(records) << "\n";
            std::cout << "Average: $" << calculateAverage(records) << "\n";
        }
    } while (choice != 0);

    return 0;
}