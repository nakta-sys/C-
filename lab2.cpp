#include <iostream>
#include <cstring>
using namespace std;

// Exercise 2: Swapping methods
void swapNoPointersOrRefs(float a, float b) {
    float temp = a; a = b; b = temp;
    cout << "After swap (no pointers/refs): a=" << a << ", b=" << b << endl;
}
void swapUsingPointers(float *a, float *b) {
    float temp = *a; *a = *b; *b = temp;
}
void swapUsingReferences(float &a, float &b) {
    float temp = a; a = b; b = temp;
}

// Exercise 3: Simple calculator
void calculator() {
    double num1, num2; char op;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter operator (+ - * /): ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> num2;

    switch(op) {
        case '+': cout << "Result: " << num1 + num2 << endl; break;
        case '-': cout << "Result: " << num1 - num2 << endl; break;
        case '*': cout << "Result: " << num1 * num2 << endl; break;
        case '/':
            if(num2 != 0) cout << "Result: " << num1 / num2 << endl;
            else cout << "Error: Division by zero!" << endl;
            break;
        default: cout << "Invalid operator" << endl;
    }
}

// Exercise 4: Continuous numbers
void continuousNumbers() {
    int num;
    while(true) {
        cout << "Enter a number (negative to stop, zero to skip): "; cin >> num;
        if(num < 0) break;
        if(num == 0) continue;
        cout << "Square: " << num*num << endl;
    }
}

// Exercise 5: Array reverse
void reverseArray() {
    int arr[] = {1,4,7,10,15}, reversed[5], size=5;
    int *ptr = arr + size - 1;
    for(int i = 0; i < size; i++) reversed[i] = *ptr--;
    cout << "Reversed array: ";
    for(int n : reversed) cout << n << " ";
    cout << endl;
}

// Exercise 6: Student records
struct Student { char name[50]; int id; float grade; } students[100];
int count = 0;
void manageStudents() {
    int choice;
    do {
        cout << "1.Add 2.Display 3.Search 4.Exit: "; cin >> choice;
        if(choice==1) {
            cout << "Name: "; cin >> students[count].name;
            cout << "ID: "; cin >> students[count].id;
            cout << "Grade: "; cin >> students[count].grade; count++;
        } else if(choice==2) {
            for(int i=0; i<count; i++)
                cout << students[i].name << " " << students[i].id << " " << students[i].grade << endl;
        } else if(choice==3) {
            int sid; cout << "Search ID: "; cin >> sid;
            bool found = false;
            for(int i=0; i<count; i++)
                if(students[i].id==sid) {
                    cout << students[i].name << " " << students[i].grade << endl;
                    found=true;
                }
            if(!found) cout << "Not found!" << endl;
        }
    } while(choice!=4);
}

// Exercise 7: Pointers shallow copy
void shallowCopyDemo() {
    int x=100; int *p1=&x, *p2=p1;
    *p1 = 200; cout << "Pointer 2 sees: " << *p2 << endl;
}

// Exercise 8: References
void referenceDemo() {
    int a=100; int &refA=a; refA=30;
    cout << "Value of a: " << a << endl;
}

int main() {
    int task;
    do {
        cout << "\nWhich exercise (2-8) to execute? (0 to exit): ";
        cin >> task;
        switch(task) {
            case 2: {
                float x, y;
                cout << "Enter two floating values: "; cin >> x >> y;
                swapNoPointersOrRefs(x,y);
                swapUsingPointers(&x,&y); cout<<"Pointers swap: "<<x<<" "<<y<<endl;
                swapUsingReferences(x,y); cout<<"References swap: "<<x<<" "<<y<<endl; break;
            }
            case 3: calculator(); break;
            case 4: continuousNumbers(); break;
            case 5: reverseArray(); break;
            case 6: manageStudents(); break;
            case 7: shallowCopyDemo(); break;
            case 8: referenceDemo(); break;
            case 0: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while(task != 0);

    return 0;
}
