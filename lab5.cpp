// Polina Maidanova
// Programming Fundamentals
// CS 1436
// 005
// Due Date: 09/18/2024
// Date Completed: 09/12/2024
// Date Submitted: 09/12/2024


// This program calculates the monthly payment on a loan.
#include <iostream> // Header file allowing the use of input/output objects.
#include <cmath>    // Header file allowing the use of mathematical functions.
#include <iomanip>  // Header file allowing formatting the output.
#include <cstdlib>  // Headerfile allowing the use of random number generation.
#include <ctime>    // Header file allowing to get and manipulate the time information.
using namespace std;    // Use standard namespace.

int main()  // Main function, starting point of the program execution.
{   // Beginning of main function's body.
    // Declare the variables for the loan amount, monthly and annual interest rates, amount paid back, and interest paid.
    double loanAmount, intRateAnnual, intRateMonthly, monthlyPayment, amountPaidBack, interestPaid;

    const int  MIN = 8000, MAX = 15000; // Declare the minimum and maximum values for the loan.
    int numPayments;    // Declate the variable for the number of payments.

    unsigned seed = time(0);    // Get the system time.
    srand(seed);    // Seed the random number generator.

    // Assign a random loan amount in the range between MIN and MAX.
    loanAmount = (rand() % (MAX - MIN + 1) + MIN);

    // Request the user to enter the number of payments.
    cout << "Enter the number of payments: ";
    cin >> numPayments;

    // Request the user to enter the annual interest rate.
    cout << "Enter the annual interest rate: ";
    cin >> intRateAnnual;

    // Calculate the monthly interest rate.
    intRateMonthly = intRateAnnual / 12;

    // If the interest rate is entered in the percentage form, convert it to a decimal form.
    if (intRateMonthly >= 1)    // Check if monthly interest rate was entered in the percentage form.
    {
        intRateMonthly = intRateMonthly / 100;  // Convert the percentage form to a decimal form.
    }

    // Calculate the monthly payment.
    monthlyPayment = (intRateMonthly * pow((1 + intRateMonthly), numPayments)) * loanAmount / (pow((1 + intRateMonthly), numPayments) - 1);

    // Calculate the amount paid back.
    amountPaidBack = monthlyPayment * numPayments;

    // Calculate the interest paid.
    interestPaid = amountPaidBack - loanAmount;

    // Display the results.
    cout << fixed << setprecision(2);
    cout << "Loan Amount: " << loanAmount << endl;
    cout << "Monthly Interest Rate: " << intRateMonthly * 100 << "%" << endl;
    cout << "Number of Payments: " << numPayments << endl;
    cout << "Monthly Payment: $" << monthlyPayment << endl;
    cout << "Amount Paid Back: $" << amountPaidBack << endl;
    cout << "Interest Paid: $" << interestPaid << endl;

    return 0;   // Return 0 to the operating system to indicate successful completion of the program.
} 
