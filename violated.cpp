#include <iostream>

// Violando o Princípio da Responsabilidade Única e o Princípio Aberto/Fechado
class Employee {
public:
    virtual float calculatePay() = 0;
};

class HourlyEmployee : public Employee {
public:
    float hourlyRate;
    float hoursWorked;

    HourlyEmployee(float rate, float hours) : hourlyRate(rate), hoursWorked(hours) {}

    float calculatePay() override {
        return hourlyRate * hoursWorked;
    }
};

class SalariedEmployee : public Employee {
public:
    float salary;

    SalariedEmployee(float s) : salary(s) {}

    float calculatePay() override {
        return salary;
    }
};

// Violando o Princípio da Substituição de Liskov e o Princípio da Segregação de Interfaces
class Payroll {
public:
    float calculateTotalPay(Employee* employees[], int numEmployees) {
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

    Employee* employees[] = { &hourlyEmp, &salariedEmp };

    Payroll payroll;
    std::cout << "Total payroll: $" << payroll.calculateTotalPay(employees, 2) << std::endl;

    return 0;
}
