#include <iostream>

// FUNCTION PROTOTYPING

int sumOfTwoNum(int fNum, int sNum); 
bool isGreater(int a, int b);
bool logicalOperations(bool c, bool d); 

class Triangle {
    private:
        double totalAngle, angleA, angleB, angleC;
    public:
        Triangle(double A, double B, double C);
        void setAngles(double A, double B, double C);
        const bool validateTriangle();
};

int main () {

    // ILO A #1
    std::cout << "The sum of all numbers is : " << sumOfTwoNum(8,9) << std::endl;

    // ILO A #2
    int x = 90;
    int y = 720;

   if (isGreater(x, y)) {
        std::cout << "x is greater than y" << std::endl;
    } else {
        std::cout << "x is not greater than y" << std::endl;
    }

    // ILO A #3
    bool success = logicalOperations(true, false);
    std::cout << "Function execution status: " << std::boolalpha << success << std::endl;

    // ILO B
    Triangle setl(40,50,110);
    if(setl.validateTriangle()){
        std::cout << "The shape is a valid Triangle \n.";
    }
    else{
        std::cout << "The shape is NOT a valid Triangle \n.";
    }

    return 0;
}

// ILO A #1
int sumOfTwoNum(int fNum, int sNum){

    int sum = fNum + sNum;
    return sum;
}
 // ILO A #2
bool isGreater(int a, int b){
    return a > b;
}

// ILO A #3
bool logicalOperations(bool c, bool d) {
    try {
        // Check if inputs are valid boolean values
        if ((c != 0 && c != 1) || (d != 0 && d != 1)) {
            throw std::invalid_argument("Inputs must only be 0 (false) or 1 (true).");
        }

        std::cout << std::boolalpha;

        // NOT
        std::cout << "NOT A      : " << (!c) << std::endl;
        std::cout << "NOT B      : " << (!d) << std::endl;

        // AND
        std::cout << "AND : " << (c && d) << std::endl;

        // OR
        std::cout << "OR : " << (c || d) << std::endl;

        // XOR
        std::cout << "XOR : " << (c ^ d) << std::endl;

        // NAND
        std::cout << "NAND: " << !(c && d) << std::endl;

        // NOR
        std::cout << "NOR: " << !(c || d) << std::endl;

        // XNOR
        std::cout << "XNOR: " << !(c ^ d) << std::endl;

        return true;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return false;
    }
}

// ILO B
Triangle::Triangle(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

void Triangle::setAngles(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;
}

const bool Triangle::validateTriangle(){
    return (totalAngle <= 180);
}

