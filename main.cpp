/********************************************************************************************
 * This program replicates the game Twenty Four. First, it finds and prints a
 * range of solutions that's specified by the user. (There is a total of 3,185 solutions.)
 * Next, this program randomly selects a puzzle for the user to play. The user has to
 * enter a set of mathematical operators in order to play. The input must be three operators,
 * and the operators that could be used to play are +, -, /, and *. The program will let the
 * user know if their input of operators results in 24 or not.
 * Class: CS 141, Fall 2023
 * System: Zybook Lab
 * @author Elizabeth Ng
 * @version September 20, 2023
********************************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
 * Description: Performs a particular computation between two values, which is based on the operator that's given
 * Inputs: value1 (some value of type double), value2 (some value of type double), someOperator (an integer that corresponds to a particular operator)
 * Output: functionResult (the solution after doing some sort of math between two numbers)
 */
double compute(double value1, double value2, int someOperator) {
    double functionResult = 0.0;

    if (someOperator == 1) {
        functionResult = value1 + value2;
    }
    else if (someOperator == 2) {
        functionResult = value1 - value2;
    }
    else if (someOperator == 3) {
        functionResult = value1 / value2;
    }
    else if (someOperator == 4) {
        functionResult = value1 * value2;
    }

    return functionResult;
}

/*
 * Description: Converts an integer to the operator that it represents
 * Input: operatorNum (an integer that represents an operator)
 * Output: charResult (the operator)
 */
char numToOperatorConversion (int operatorNum) {
    char charResult;

    if (operatorNum == 1) {
        charResult = '+';
    }
    else if (operatorNum == 2) {
        charResult = '-';
    }
    else if (operatorNum == 3) {
        charResult = '/';
    }
    else if (operatorNum == 4) {
        charResult = '*';
    }

    return charResult;
}

/*
 * Description: Computes two numbers based on the character, which should represent a valid operator
 * Input: userOperator (a character that represents the operator that's used for computation), numA (some value of type double), numB (some value of type double)
 * Output: solution (the result of computing two numbers with a particular operator)
 */
double solveUsersMath (char userOperator, double numA, double numB) {
    double solution;

    if (userOperator == '+') {
        solution = numA + numB;
    }
    else if (userOperator == '-') {
        solution = numA - numB;
    }
    else if (userOperator == '/') {
        solution = numA / numB;
    }
    else if (userOperator == '*') {
        solution = numA * numB;
    }

    return solution;
}

int main()
{
    // Welcome display
    cout << "Welcome to the game of Twenty Four." << endl;
    cout << "Combine the four numbers shown below," << endl;
    cout << "in the order shown below, using the operators" << endl;
    cout << "(+,-,/,*) to yield the value 24." << endl;

    cout << "**** Begin Debug Display ****" << endl;

    // Takes the user's input, which is the beginning solution and the end solution
    double beginningSolution;
    double endSolution;
    cout << "Enter the beginning solution to be printed: ";
    cin >> beginningSolution;
    cout << "Enter the end solution to be printed: ";
    cin >> endSolution;

    // Chooses a random puzzle (integer) for the user to play
    srand(time(0));
    int randomInteger = (rand() % 3185) + 1;

    // Parts of the random puzzle, including four numbers and three operators
    double tempNum1 = 0.0;
    double tempNum2 = 0.0;
    double tempNum3 = 0.0;
    double tempNum4 = 0.0;
    char tempChar1;
    char tempChar2;
    char tempChar3;

    // This is used to index each valid solution
    int counter = 0;

    // This is used to index the solutions that the user wants to print
    int specificSol = 0;

    // Generates all possible combinations of numbers and mathematical operators

    // Generates all of the numbers
    // i is the first number, j is the second number, k is the third number, and l is the fourth number
    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j < 10; ++j) {
            for (int k = 1; k < 10; ++k) {
                for (int l = 1; l < 10; ++l) {
                    double firstNum = i;
                    double secondNum = j;
                    double thirdNum = k;
                    double fourthNum = l;

                    // This variable will constantly be updated to reflect the result of each equation
                    double result = 0.0;

                    // Generates every combination of mathematical operators
                    // m is the first operator, n is the second operator, and o is the third operator
                    for (int m = 1; m <= 4; ++m) {
                        for (int n = 1; n <= 4; ++n) {
                            for (int o = 1; o <= 4; ++o) {

                                // Computes the result between the first number and the second number
                                double tempResult1 = compute(firstNum, secondNum, m);

                                // Computes the result between the result of the first and second number's calculation with the third number.
                                double tempResult2 = compute(tempResult1, thirdNum, n);

                                // Computes the result between the result of the first, second, and third number's calculation with the fourth number.
                                result = compute(tempResult2, fourthNum, o);

                                // Prints solutions that equal 24
                                if (result == 24) {

                                    counter += 1;

                                    // Builds the parts of the randomly chosen puzzle
                                    if (counter == randomInteger) {
                                        tempNum1 = firstNum;
                                        tempNum2 = secondNum;
                                        tempNum3 = thirdNum;
                                        tempNum4 = fourthNum;

                                        tempChar1 = numToOperatorConversion(m);
                                        tempChar2 = numToOperatorConversion(n);
                                        tempChar3 = numToOperatorConversion(o);
                                    }

                                    // Marks the specific start index
                                    if (counter == beginningSolution) {
                                        specificSol = beginningSolution;
                                    }

                                    // Prints the valid solutions that are in the specified range
                                    if (specificSol >= beginningSolution && specificSol <= endSolution) {
                                        cout << counter << ":";
                                        cout << firstNum;
                                        cout << numToOperatorConversion(m);
                                        cout << secondNum;
                                        cout << numToOperatorConversion(n);
                                        cout << thirdNum;
                                        cout << numToOperatorConversion(o);
                                        cout << fourthNum << "=24" << endl;
                                    }

                                    specificSol += 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Displays the random puzzle
    cout << "Puzzle chosen is #" << randomInteger << ":" << tempNum1 << tempChar1 << tempNum2 << tempChar2 << tempNum3 << tempChar3 << tempNum4 << endl;
    cout << "**** End of the Debug Display ****" << endl;

    cout << endl;
    cout << endl;

    cout << "The numbers to use are " << tempNum1 << " " << tempNum2 << " " << tempNum3 << " " << tempNum4 << endl;
    cout << "Enter the three operators to be used (+,-,* or /):" << endl;

    string operatorSelections;

    bool check = true;
    int size = operatorSelections.size();
    int correctCharCounter = 0;

    // Error checking for length of input and for invalid input characters
    // Users are allowed to retry if their input was invalid
    while (check == true) {
        cin >> operatorSelections;
        size = operatorSelections.size();
        correctCharCounter = 0;
        if (size != 3) {
            cout << "invalid number of characters entered, please try again" << endl;
            continue;
        }

        for (int t = 0; t < size; ++t) {
            if (operatorSelections.at(t) == '+' || operatorSelections.at(t) == '-' || operatorSelections.at(t) == '/' || operatorSelections.at(t) == '*') {
                correctCharCounter += 1;
            }
        }

        if (correctCharCounter != size) {
            cout << "invalid characters entered, please try again" << endl;
        }
        else if (size == 3 && correctCharCounter == size) {
            check = false;
        }
    }

    double userSolution = 0.0;

    // Everything below prints out the work that is being done for the math, which is based on the random puzzle and the user's input
    cout << tempNum1 << " " << operatorSelections.at(0) << " " << tempNum2 << " = ";
    cout << solveUsersMath (operatorSelections.at(0), tempNum1, tempNum2) << endl;
    userSolution = solveUsersMath (operatorSelections.at(0), tempNum1, tempNum2);

    cout << userSolution << " " << operatorSelections.at(1) << " " << tempNum3 << " = ";
    cout << solveUsersMath (operatorSelections.at(1), userSolution, tempNum3) << endl;
    userSolution = solveUsersMath (operatorSelections.at(1), userSolution, tempNum3);

    cout << userSolution << " " << operatorSelections.at(2) << " " << tempNum4 << " = ";
    cout << solveUsersMath (operatorSelections.at(2), userSolution, tempNum4) << endl;
    userSolution = solveUsersMath (operatorSelections.at(2), userSolution, tempNum4);

    // Checks the final solution to see if it equals 24
    if (userSolution == 24) {
        cout << "Well done!" << endl;
    }
    else {
        cout << "incorrect: The correct answer was:" << endl;
        cout << tempNum1 << tempChar1 << tempNum2 << tempChar2 << tempNum3 << tempChar3 << tempNum4 << endl;
    }

    return 0;
}


