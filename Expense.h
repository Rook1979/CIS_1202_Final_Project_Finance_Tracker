#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

class Expense {
protected:
    std::string category;
    double amount;
    std::string date;

public:
    Expense();
    Expense(std::string cat, double amt, std::string dt);

    std::string getCategory() const;
    double getAmount() const;
    std::string getDate() const;

    void setCategory(std::string cat);
    void setAmount(double amt);
    void setDate(std::string dt);

    virtual void display() const;
};

#endif
