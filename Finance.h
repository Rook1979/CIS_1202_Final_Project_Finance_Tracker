#ifndef FINANCE_H
#define FINANCE_H

#include "Expense.h"

class Finance : public Expense {
private:
    std::string note;

public:
    Finance();
    Finance(std::string cat, double amt, std::string dt, std::string nt);

    void display() const override;

    std::string getNote() const;
    void setNote(std::string nt);
};

#endif
