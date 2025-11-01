#include "utils.h"
#include <iostream>
#include <fstream>
#include <iomanip>

bool isValidDate(const std::string& date) {
    return date.length() == 10 && date[4] == '-' && date[7] == '-';
}

bool isValidAmount(double amount) {
    return amount >= 0.0;
}

void saveToFile(const std::vector<Finance>& records, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary);
    for (const auto& rec : records) {
        size_t lenCat = rec.getCategory().size();
        size_t lenDate = rec.getDate().size();
        size_t lenNote = rec.getNote().size();
        double amt = rec.getAmount();

        outFile.write((char*)&lenCat, sizeof(lenCat));
        outFile.write(rec.getCategory().c_str(), lenCat);
        outFile.write((char*)&amt, sizeof(amt));
        outFile.write((char*)&lenDate, sizeof(lenDate));
        outFile.write(rec.getDate().c_str(), lenDate);
        outFile.write((char*)&lenNote, sizeof(lenNote));
        outFile.write(rec.getNote().c_str(), lenNote);
    }
    outFile.close();
}

void loadFromFile(std::vector<Finance>& records, const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    records.clear();
    while (inFile.peek() != EOF) {
        size_t lenCat, lenDate, lenNote;
        double amt;
        std::string cat, dt, nt;

        inFile.read((char*)&lenCat, sizeof(lenCat));
        cat.resize(lenCat);
        inFile.read(&cat[0], lenCat);

        inFile.read((char*)&amt, sizeof(amt));

        inFile.read((char*)&lenDate, sizeof(lenDate));
        dt.resize(lenDate);
        inFile.read(&dt[0], lenDate);

        inFile.read((char*)&lenNote, sizeof(lenNote));
        nt.resize(lenNote);
        inFile.read(&nt[0], lenNote);

        records.emplace_back(cat, amt, dt, nt);
    }
    inFile.close();
}

void displayAll(const std::vector<Finance>& records) {
    std::cout << std::left << std::setw(15) << "Category"
              << std::setw(10) << "Amount"
              << std::setw(12) << "Date"
              << std::setw(25) << "Note" << std::endl;
    std::cout << std::string(62, '-') << std::endl;
    for (const auto& rec : records) {
        rec.display();
    }
}

double calculateTotal(const std::vector<Finance>& records) {
    double total = 0.0;
    for (const auto& rec : records) {
        total += rec.getAmount();
    }
    return total;
}

double calculateAverage(const std::vector<Finance>& records) {
    if (records.empty()) return 0.0;
    return calculateTotal(records) / records.size();
}
