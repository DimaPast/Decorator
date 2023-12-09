#include <iostream>
#include <string>
#include <Windows.h>


class Coffee {
public:
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
    virtual ~Coffee() = default;
};

class SimpleCoffee : public Coffee {
public:
    std::string getDescription() const override {
        return "Кава";
    }

    double cost() const override {
        return 1.0;
    }
};


class CoffeeDecorator : public Coffee {
protected:
    Coffee* coffee;

public:
    CoffeeDecorator(Coffee* baseCoffee) : coffee(baseCoffee) {}

    std::string getDescription() const override {
        return coffee->getDescription();
    }

    double cost() const override {
        return coffee->cost();
    }
};


class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* baseCoffee) : CoffeeDecorator(baseCoffee) {}

    std::string getDescription() const override {
        return coffee->getDescription() + ", з молоком";
    }

    double cost() const override {
        return coffee->cost() + 0.5;
    }
};


class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(Coffee* baseCoffee) : CoffeeDecorator(baseCoffee) {}

    std::string getDescription() const override {
        return coffee->getDescription() + ", з цукром";
    }

    double cost() const override {
        return coffee->cost() + 0.2;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
    Coffee* simpleCoffee = new SimpleCoffee();
    std::cout << "Опис: " << simpleCoffee->getDescription() << ", Вартість: $" << simpleCoffee->cost() << std::endl;

 
    Coffee* milkCoffee = new MilkDecorator(simpleCoffee);
    std::cout << "Опис: " << milkCoffee->getDescription() << ", Вартість: $" << milkCoffee->cost() << std::endl;

   
    Coffee* sugarMilkCoffee = new SugarDecorator(milkCoffee);
    std::cout << "Опис: " << sugarMilkCoffee->getDescription() << ", Вартість: $" << sugarMilkCoffee->cost() << std::endl;

  
    delete simpleCoffee;
    delete milkCoffee;
    delete sugarMilkCoffee;

    return 0;
}
