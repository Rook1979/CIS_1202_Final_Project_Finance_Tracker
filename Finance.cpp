#include "Finance.h"
#include <iostream>
#include <iomanip>

Finance::Finance() : Expense(), note("") {}

Finance::Finance(std::string cat, double amt, std::string dt, std::string nt)
    : Expense(cat, amt, dt), note(nt) {}

void Finance::display() const {
    Expense::display();
    std::cout << std::setw(25) << note << std::endl;
}

std::string Finance::getNote() const { return note; }
void Finance::setNote(std::string nt) { note = nt; }
