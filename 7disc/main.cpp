//
//  main.cpp
//  6disc
//
//  Created by Willie Wu on 2/12/20.
//  Copyright © 2020 Willie Wu. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template<typename Item1, typename Item2>
class bivalue {
public:
    bivalue(Item1 i1, Item2 i2) {
        m_val1 = i1;
        m_val2 = i2;
    }
    Item1 getVal1() const { return m_val1; }
    Item2 getVal2() const { return m_val2; }
    bool operator<(const bivalue &other) const {
        return (m_val1 < other.m_val1);
    }
private:
    Item1 m_val1;
    Item2 m_val2;
};


class monovalue {
public:
    monovalue(int i) {
        m_val = i;
    }
    int getVal() const { return m_val; }
    bool operator<(const monovalue &other) const;
private:
    int m_val;
};

bool monovalue::operator<(const monovalue &other) const {
    return this->getVal() < other.getVal();
}


template<typename Item>
vector<Item> duplicate(Item &a) {
    vector<Item> v;
    v.push_back(a);
    v.push_back(a);
    return v;
}

/*
int main(int argc, const char * argv[]) {
    
    bivalue<int, string> bv1(1, "hello");
    bivalue<int, string> bv2(2, "world");
    
    //vectors
    vector<bivalue<int, string>> v;
    v.push_back(bv1);
    v.push_back(bv2);
    cout << v.front().getVal2() << endl;
    cout << v.back().getVal2() << endl;;
    cout << v.size() << endl;
    cout << v.empty() << endl;
    vector<bivalue<int, string>>::iterator it;
    for(it = v.begin(); it != v.end(); it++) {
        cout << it->getVal2() << endl;
    }
    v.pop_back();
    //lists
    list<int> li;
    li.push_front(1);
    li.push_back(2);
    li.push_front(0);
    li.pop_front();
    
    monovalue mv(5);
    vector<monovalue> v2 = duplicate(mv);
    vector<monovalue>::iterator it2;
    for(it2 = v2.begin(); it2 != v2.end(); it2++) {
        cout << it2->getVal() << endl;
    }
    
}*/
