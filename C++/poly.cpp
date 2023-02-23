#include <iostream>

using namespace std;

class Node {
public:
    int coefficient;
    int power;
    Node *next;

    Node(int coefficient, int power) {
        this->coefficient = coefficient;
        this->power = power;
        this->next = NULL;
    }
};

class Polynomial {
public:
    Node *head;
    Polynomial() {
        head = NULL;
    }

void addTerm(int coefficient, int power) {
        Node *newNode = new Node(coefficient, power);
        if (head == NULL) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

void display() {
    Node *temp = head;
        while (temp != NULL) {
            cout << temp->coefficient << "x^" << temp->power << "+";
            temp = temp->next;
        }
        cout << "0"<<endl;
    }

    
void removeDuplicates() {
        Node *temp1 = head;
        while (temp1 != NULL) {
            Node *temp2 = temp1;
            while (temp2->next != NULL) {
                if (temp1->power == temp2->next->power) {
                    temp1->coefficient += temp2->next->coefficient;
                    Node *dup = temp2->next;
                    temp2->next = temp2->next->next;
                    delete dup;
                } else {
                    temp2 = temp2->next;
                }
            }
            temp1 = temp1->next;
        }
    }

    // Method to add two polynomials
Polynomial add(Polynomial poly) {
        Polynomial result;
        Node *temp1 = head;
        Node *temp2 = poly.head;

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->power == temp2->power) {
                result.addTerm(temp1->coefficient + temp2->coefficient, temp1->power);
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else if (temp1->power > temp2->power) {
                result.addTerm(temp1->coefficient, temp1->power);
                temp1 = temp1->next;
            } else {
                result.addTerm(temp2->coefficient, temp2->power);
                temp2 = temp2->next;
            }
        }

        while (temp1 != NULL) {
            result.addTerm(temp1->coefficient, temp1->power);
            temp1 = temp1->next;
        }

        while (temp2 != NULL) {
            result.addTerm(temp2->coefficient, temp2->power);
            temp2 = temp2->next;
        }
        result.removeDuplicates();
        return result;
    }


    // Method to multiply two polynomials
Polynomial multiply(Polynomial poly) {
        Polynomial result;
        Node *temp1 = head;

        while (temp1 != NULL) {
            Node *temp2 = poly.head;
            while (temp2 != NULL) {
                int coefficient = temp1->coefficient * temp2->coefficient;
                int power = temp1->power + temp2->power;
                result.addTerm(coefficient, power);
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        result.removeDuplicates();
        return result;
    }
};

int main(){
    Polynomial poly1;
    int coeff, pow;
    char choice;
    do {
        cout << "Enter coefficient: ";
        cin >> coeff;
        cout << "Enter power: ";
        cin >> pow;
        poly1.addTerm(coeff, pow);
        cout << "Do you want to add more terms? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // ask user second polynomial
    Polynomial poly2;
    do {
        cout << "Enter coefficient 2: ";
        cin >> coeff;
        cout << "Enter power: ";
        cin >> pow;
        poly2.addTerm(coeff, pow);
        cout << "Do you want to add more terms? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    Polynomial poly3, p4;
    poly3 = poly1.add(poly2);
    p4 = poly1.multiply(poly2);



    cout << endl;
    cout << "First polynomial: ";
    poly1.display();
    cout << "Second polynomial: ";
    poly2.display();
    cout << "Sum of polynomials: ";
    poly3.display();
    cout << "Product of polynomials: ";
    p4.display();
    
    return 0;
};