#include <iostream>
using namespace std;

// Question 1: Simple addition and concatenation
void question1() {
    int a = 3, b = 4;
    cout << "Sum: " << a + b << endl;
    cout << "Concatenation: Hi There" << endl;
}

// Question 2: Simple string operations
void question2() {
    char input[100];
    cout << "Enter a string: ";
    cin >> input;

    int vowels = 0;
    cout << "Uppercase: ";
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'a' && input[i] <= 'z')
            input[i] -= 32;
        cout << input[i];

        if (input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U')
            vowels++;
    }
    cout << "\nNumber of vowels: " << vowels << endl;

    cout << "Reversed string: ";
    int len = 0;
    while (input[len] != '\0') len++;
    for (int i = len - 1; i >= 0; i--) {
        cout << input[i];
    }
    cout << endl;
}

// Question 3: Even numbers
void question3() {
    for (int i = 2; i <= 50; i = i + 2) {
        cout << i << " ";
    }
    cout << endl;
}

// Question 4: Square number
void question4() {
    int num;
    cout << "Enter number: ";
    cin >> num;
    cout << "Square: " << num * num << endl;
}

// Question 5: Sum digits
void question5() {
    int num, sum = 0;
    cout << "Enter number: ";
    cin >> num;
    while (num > 0) {
        sum = sum + num % 10;
        num = num / 10;
    }
    cout << "Sum of digits: " << sum << endl;
}

// Question 6: Reverse digits
void question6() {
    int num, rev = 0;
    cout << "Enter number: ";
    cin >> num;
    while (num > 0) {
        rev = rev * 10 + num % 10;
        num = num / 10;
    }
    cout << "Reversed number: " << rev << endl;
}

// Question 7: Password check
void question7() {
    char password[100];
    cout << "Enter password: ";
    cin >> password;

    int length = 0, upper = 0, lower = 0, digit = 0, special = 0;
    for (int i = 0; password[i] != '\0'; i++) {
        length++;
        if (password[i] >= 'A' && password[i] <= 'Z') upper = 1;
        else if (password[i] >= 'a' && password[i] <= 'z') lower = 1;
        else if (password[i] >= '0' && password[i] <= '9') digit = 1;
        else special = 1;
    }

    if (length >= 8 && upper && lower && digit && special)
        cout << "Strong Password" << endl;
    else {
        cout << "Weak Password" << endl;
        if (length < 8) cout << "- Must be at least 8 characters\n";
        if (!upper) cout << "- Missing uppercase letter\n";
        if (!lower) cout << "- Missing lowercase letter\n";
        if (!digit) cout << "- Missing digit\n";
        if (!special) cout << "- Missing special character\n";
    }
}

int main() {
    char repeat;
    int choice;
    do {
        cout << "Choose question (1-7): ";
        cin >> choice;

        if (choice == 1)
            question1();
        else if (choice == 2)
            question2();
        else if (choice == 3)
            question3();
        else if (choice == 4)
            question4();
        else if (choice == 5)
            question5();
        else if (choice == 6)
            question6();
        else if (choice == 7)
            question7();
        else
            cout << "Invalid choice." << endl;

        cout << "Run another? (y/n): ";
        cin >> repeat;
    } while (repeat == 'y');

    cout << "Goodbye!" << endl;
    return 0;
}

