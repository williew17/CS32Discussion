//
//  main.cpp
//  2disc
//
//  Created by Willie Wu on 1/16/20.
//  Copyright © 2020 Willie Wu. All rights reserved.
//

#include <iostream>
#include <string>
class Cup
{
public:
    Cup(std::string drinkName, int amount)
    {
        m_drinkName = drinkName;
        m_amount = amount;
        std::cout << "New cup of " << drinkName << std::endl;
    }
    
    Cup()
    {
        m_drinkName = "coffee";
        m_amount = 100;
        std::cout << "New cup of coffee" << std::endl;
    }
    
    void pour(int amount)
    {
        m_amount-=amount;
        std::cout << amount << " poured out" << std::endl;
    }
    
    std::string getDrink()
    {
        return m_drinkName;
    }
    
private:
    int m_amount;
    std::string m_drinkName;
};

class Table
{
public:
    Table(std::string secondCupDrink, int numCups)
    : m_secondCup(secondCupDrink, 100) //this gets run first
    {
        m_otherCups = new Cup[numCups]; //default constructor
        m_numCups = numCups;
        std::cout << "New table made" << std::endl << std::endl;
    }
    
    //What would happen if the const didn't exist?
    Table(const Table& other)
    {
        m_numCups = other.m_numCups; //integer initialization
        m_coffeeCup = other.m_coffeeCup;
        m_secondCup = other.m_secondCup;
//        m_otherCups = other.m_otherCups; //this line doesnt work
        m_otherCups = new Cup[m_numCups];
        for(int j = 0; j < m_numCups; j++)
        {
            m_otherCups[j] = other.m_otherCups[j];
        }
    }
    
    Table &operator= (const Table& other)
    {
        if (this == &other)
            return *this;
        m_numCups = other.m_numCups;
        m_coffeeCup = other.m_coffeeCup;
        m_secondCup = other.m_secondCup;
        delete [] m_otherCups;
        m_otherCups = new Cup[m_numCups];
        for(int j = 0; j < m_numCups; j++)
        {
            m_otherCups[j] = other.m_otherCups[j];
        }
        return *this;
    }
    
    ~Table()
    {
        delete [] m_otherCups; //delete all the memory associated with the array
        std::cout << "Table destroyed" << std::endl << std::endl;
        //
    }
    
    
    int getnumCups()
    {
        return m_numCups;
    }
    
    void printSecondCup()
    {
        std::cout << "Second Cup drink is " << m_secondCup.getDrink() << std::endl << std::endl;
    }
private:
    Cup *m_otherCups; // pointer
    int m_numCups;
    Cup m_coffeeCup; //this always uses the default constructor
    Cup m_secondCup;
};

int main(int argc, const char * argv[]) {
    Table tb1("orange juice", 3); // not a default constructor
    std::cout << "Copy Constructor" << std::endl;
    Table tb2 = tb1; //copy constructor
    tb2.printSecondCup();
    
    std::cout << "Assignment Operator" << std::endl;
    Table tb3("water", 1);
    tb2 = tb3;
    tb2.printSecondCup();
    
    Cup c = Cup("lemonade", 10);
    
    
    
    return 0;
}
