//
//  main.cpp
//  3disc
//
//  Created by Willie Wu on 4/16/20.
//  Copyright © 2020 Willie Wu. All rights reserved.
//

#include <iostream>
using namespace std;

class DLL
{
    struct node {
        int value;
        node *next;
        node *prev;
    };
public:
    DLL() {
        head = nullptr;
        size = 0;
    }
    
    void traverse() {
        node *p = head;
        while( p!= nullptr) {
            cout << p->value << endl;
            p = p->next;
        }
    }
      //        ^
    //head -> 0th node <-> 1st node ->
    void addNode(int pos, int v) {
        node *p = new node;
        p->value = v;
        //add to front
        if (pos == 0) {
            head->prev = p;
            p->next = head; //head points to what used to be the first node
            head = p;
            p->prev = nullptr;
            
        }
        //add to back
        else if (pos >= size) {
            node *end = head;
            
            while(end != nullptr && end->next != nullptr) {
                end = end->next;
            }
            
            p->next = nullptr;
            p->prev = end;
            if (end != nullptr)
                end->next = p; //when there was already something in the list
            else
                head = p; //insert into an empty list
        }
        //add to middle
        else {
            node *temp = head;
            for (int i = 0; i < pos - 1; i++) {
                temp = temp->next;
            }
            p->next = temp->next;
            p->prev = temp;
            temp->next->prev = p;
            temp->next = p;
        }
        size++;
    }
    
    //TODO: function deletes nodes from a given position
    void deleteNode(int pos) {
        return;
    }
    
    //TODO: function will find the first node in the LL that matches the parameters value, and return a pointer to that node.
    node* getNode(int val) {
        return head;
    }
    
    //TODO: delete all nodes by traversing through them
    ~DLL() {
        delete head;
    }
private:
    
    
    
    node *head;
    int size;
};


int main() {
    DLL links;
    //links.addNode(0, 10); //adding first node (correct)
    links.addNode(1,10); //adding first node (incorrect)
    
    links.addNode(1, 20); //adding end node (correct)

    links.addNode(4,30); //adding to end node (incorrect)

    links.addNode(0,5); //adding to beginning
    
    links.addNode(2,15); //adding to middle
    
    links.addNode(5,40); //adding to middle/end
    
    links.traverse();
    
}
