#include <iostream>

// Princípio da Responsabilidade Única (SRP) e Princípio Aberto/Fechado (OCP)
class Employee {
public:
    virtual ~Employee() = default;
    virtual float calculatePay() const = 0;
};

class HourlyEmployee : public Employee {
public:
    float hourlyRate;
    float hoursWorked;

    HourlyEmployee(float rate, float hours) : hourlyRate(rate), hoursWorked(hours) {}

    float calculatePay() const override {
        return hourlyRate * hoursWorked;
    }
};

class SalariedEmployee : public Employee {
public:
    float salary;

    SalariedEmployee(float s) : salary(s) {}

    float calculatePay() const override {
        return salary;
    }
};

// Princípio da Substituição de Liskov (LSP) e Princípio da Segregação de Interfaces (ISP)
class Payroll {
public:
    float calculateTotalPay(const Employee* employees[], int numEmployees) const {
        float totalPay = 0;
        for (int i = 0; i < numEmployees; ++i) {
            totalPay += employees[i]->calculatePay();
        }
        return totalPay;
    }
};

int main() {
    HourlyEmployee hourlyEmp(15, 40);
    SalariedEmployee salariedEmp(3000);

    const Employee* employees[] = { &hourlyEmp, &salariedEmp };

    Payroll payroll;
    std::cout << "Total payroll: $" << payroll.calculateTotalPay(employees, 2) << std::endl;

    return 0;
}
