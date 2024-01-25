#include <iostream>

// Абстрактний клас продукту A
class AbstractProductA {
public:
    virtual void display() = 0;
};

// Конкретний продукт A1
class ConcreteProductA1 : public AbstractProductA {
public:
    void display() override {
        std::cout << "Concrete Product A1\n";
    }
};

// Конкретний продукт A2
class ConcreteProductA2 : public AbstractProductA {
public:
    void display() override {
        std::cout << "Concrete Product A2\n";
    }
};

// Абстрактний клас продукту B
class AbstractProductB {
public:
    virtual void display() = 0;
};

// Конкретний продукт B1
class ConcreteProductB1 : public AbstractProductB {
public:
    void display() override {
        std::cout << "Concrete Product B1\n";
    }
};

// Конкретний продукт B2
class ConcreteProductB2 : public AbstractProductB {
public:
    void display() override {
        std::cout << "Concrete Product B2\n";
    }
};

// Абстрактний клас фабрики
class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
};

// Конкретна фабрика, яка створює конкретні продукти A і B
class ConcreteFactory : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA1();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB1();
    }
};

int main() {
    // Використання абстрактної фабрики
    AbstractFactory* factory = new ConcreteFactory();
    AbstractProductA* productA = factory->createProductA();
    AbstractProductB* productB = factory->createProductB();

    productA->display();
    productB->display();

    delete productA;
    delete productB;
    delete factory;

    return 0;
}
