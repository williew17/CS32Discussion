//
//  main.cpp
//  5disc
//
//  Created by Willie Wu on 1/30/20.
//  Copyright © 2020 Willie Wu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
//virtual keyword is necessary in base class if you are going to redefine it.
//not strictly necessary in derived classes but you should
//no virtual constructors
//always have virtual destructors
class Money {
public:
    Money(int val = 25) {
        cout << "making money... ";
        m_value = val;
    }
    virtual ~Money() {
        cout << "destroyed!" << endl;
    }
    virtual void send_message() {
        cout << "cha-ching!" << endl;
    }
protected:
    int getValue() {
        return m_value;
    }
private:
    int m_value;
};

//ABC
class Place {
public:
    virtual ~Place() { }
    virtual string getName() = 0;
};

class Country: public Place {
public:
    Country(string name) {
        m_name = name;
        cout << "country constructed... ";
    }
    
    virtual string getName() {
        return m_name;
    }
    
private:
    string m_name;
};

class Coin : public Money {
public:
    Coin() : m_country("USA") {
        cout << "minted coin" << endl;
    }
    void clink() {
        cout << "clink!" << endl;
    }
    
    virtual void send_message() {
        cout << "coins!" << endl;
    }
    
    void displayValue() {
        cout << Money::getValue() << endl;
    }
    
private:
    Country m_country;
};

class Bill : private Money {
public:
    Bill() : Money(100) {
        cout << "printed bill" << endl;
    }
    
    virtual ~Bill() {
        cout << "Bill shredded...";
    }
    
    virtual void send_message() {
        Money::send_message();
        cout << "crinkle" << endl;
    }
    //in this case bill inherits the public members but they are now private in bill
};

void polymorphicSend(Money* m) {
    m->send_message();
}

/*int main()
{
    Money m;
    cout << endl;
    Coin c;
    c.clink();
    Bill b;
    b.send_message();
    cout << "Polymorphic Function:" << endl;
    polymorphicSend(&m);
    polymorphicSend(&c);
    //polymorphicSend(&b);
}*/




