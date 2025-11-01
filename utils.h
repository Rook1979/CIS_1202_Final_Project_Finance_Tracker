#ifndef UTILS_H
#define UTILS_H

#include "Finance.h"
#include <vector>
#include <string>

bool isValidDate(const std::string& date);
bool isValidAmount(double amount);
void saveToFile(const std::vector<Finance>& records, const std::string& filename);
void loadFromFile(std::vector<Finance>& records, const std::string& filename);
void displayAll(const std::vector<Finance>& records);
double calculateTotal(const std::vector<Finance>& records);
double calculateAverage(const std::vector<Finance>& records);

#endif
