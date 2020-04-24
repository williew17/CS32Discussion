//
//  main.cpp
//  4disc
//
//  Created by Willie Wu on 1/30/20.
//  Copyright © 2020 Willie Wu. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

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

class Country {
public:
    Country(string name) {
        m_name = name;
        cout << "country constructed ";
    }
    
    string getName() {
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
    
    void displayValue() {
        cout << getValue() << endl;
    }
    
private:
    Country m_country;
};

class Bill : private Money {
public:
    Bill() : Money(100) {
        cout << "printed bill" << endl;
    }
    virtual void send_message() {
        Money::send_message();
        cout << "crinkle" << endl;
    }
    //in this case bill inherits the public membrs but they are now private in bill
};

int main()
{
    stack<int> s;
    s.push(3);
    s.push(4);
    cout << s.top();
    s.pop();
    s.pop();
    if (!s.empty())
        cout << s.size() << endl;
    
    queue<int> q;
    q.push(3);
    q.push(4);
    cout << q.front() << endl;
    q.pop();
    q.pop();
    if (q.empty())
        cout << "empty!" << endl;
    else
        cout << q.size() << endl;
    Money m;
    cout << endl;
    Coin c;
    Bill b;
}



