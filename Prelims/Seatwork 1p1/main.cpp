#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

int main() {

    int quiz_Amount;
    vector<int> grades(quiz_Amount);
    int num = 0;
    int tot_Grade = 0;
    int avg_Grade = 0;

    cout << "Hello User!" << endl;
    
    cout << "\nHow many quizzes: " << endl;
    cin >> quiz_Amount;
    grades.resize(quiz_Amount);

    // Loops for the amount of quizzes inputted
    while (num < quiz_Amount) {
        cout << "\nInput quiz grade for quiz " << num + 1 << ": " << endl;
        cin >> grades[num];
        num++;
    }
    
    system("CLS"); // Clears the screen

    // Loop to calculate the total grade depending on the amount of quizzes encoded
    for (int i = 0; i < quiz_Amount; i++) {
        tot_Grade += grades[i];
    };
    
    avg_Grade = tot_Grade / quiz_Amount; //Calulates average grade

    cout << "The average grade is: " << avg_Grade << endl;
    cout << "The total grade is: " << tot_Grade << endl;

    return 0;
}

