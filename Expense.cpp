#include "Expense.h"
#include <iostream>
#include <iomanip>

Expense::Expense() : category(""), amount(0.0), date("") {}

Expense::Expense(std::string cat, double amt, std::string dt)
    : category(cat), amount(amt), date(dt) {}

std::string Expense::getCategory() const { return category; }
double Expense::getAmount() const { return amount; }
std::string Expense::getDate() const { return date; }

void Expense::setCategory(std::string cat) { category = cat; }
void Expense::setAmount(double amt) { amount = amt; }
void Expense::setDate(std::string dt) { date = dt; }

void Expense::display() const {
    std::cout << std::left << std::setw(15) << category
              << std::setw(10) << amount
              << std::setw(12) << date;
}