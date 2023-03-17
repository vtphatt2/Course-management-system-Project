#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct ClassNode {
    string className;
    ClassNode* next;
};
void readClassesFromFile(string fileName) {
    ifstream inFile(fileName);
    if (!inFile) {
        cout << "Error opening file " << endl;
        return;
    }

    // read classes into linked list
    ClassNode* pHead = nullptr;
    string line;
    while (getline(inFile, line)) {
        ClassNode* newNode = new ClassNode;
        newNode->className = line;
        newNode->next = nullptr;
        if (pHead == nullptr) {
            pHead = newNode;
        } else {
            ClassNode* currentNode = pHead;
            while (currentNode->next != nullptr) {
                currentNode = currentNode->next;
            }
            currentNode->next = newNode;
        }
    }

    // display classes to user
    cout << "List of classes:" << endl;
    for (ClassNode* curr = pHead; curr != nullptr; curr = curr->next) {
        cout << curr->className << endl;
    }

    // free memory
    while (pHead != nullptr) {
        ClassNode* temp = pHead;
        pHead = pHead->next;
        delete temp;
    }
}
