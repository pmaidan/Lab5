// Polina Maidanova
// Programming Fundamentals
// CS 1436
// 005
// Due Date: 09/18/2024
// Date Completed: 09/17/2024
// Date Submitted: 09/17/2024


// This program calculates the monthly payment on a loan.
#include <iostream> // Header file allowing the use of input/output objects.
#include <cmath>    // Header file allowing the use of mathematical functions.
#include <iomanip>  // Header file allowing formatting the output.
#include <cstdlib>  // Header file allowing the use of random number generation.
#include <ctime>    // Header file allowing to get and manipulate the time information.
using namespace std;    // Use standard namespace.

int main()  // Main function, starting point of the program execution.
{ 
    // Declare the variables for the loan amount, monthly and annual interest rates, amount paid back, and interest paid.
    double fLoanAmount, fAnnualRate, fMonthlyRate, fMonthlyPayment, fAmountPaidBack, fInterestPaid;

    const int MIN_LOAN = 8000, MAX_LOAN = 15000; // Initialize the minimum and maximum values for the loan.
    int iNumPayments;    // Declate the variable for the number of payments.

    unsigned seed = time(0);    // Get the system time.
    srand(seed);    // Seed the random number generator.

    // Assign a random loan amount in the range between MIN_LOAN and MAX_LOAN.
    fLoanAmount = (double)(rand() % (MAX_LOAN - MIN_LOAN + 1) + MIN_LOAN);  // Use the rand function to generate a random loan amount.

    // Request the user to enter the number of payments.
    cout << "Enter the number of payments: ";   // Display the request.
    cin >> iNumPayments; // Store the input in iNumPayments.

    // Request the user to enter the annual interest rate.
    cout << "Enter the annual interest rate: "; // Display the request.
    cin >> fAnnualRate; // Store the input in fAnnualRate.

    // Calculate the monthly interest rate.
    fMonthlyRate = fAnnualRate / 12.0;

    // If the interest rate is entered in the percentage form, convert it to a decimal form.
    if (fMonthlyRate >= 1.0)    // Check if monthly interest rate was entered in the percentage form.
    {
        fMonthlyRate = fMonthlyRate / 100.0;  // Convert the percentage form to a decimal form.
    }

    // Calculate the monthly payment.
    fMonthlyPayment = (fMonthlyRate * pow((1.0 + fMonthlyRate), (double)iNumPayments)) * fLoanAmount / (pow((1.0 + fMonthlyRate), (double)iNumPayments) - 1.0);

    // Calculate the amount paid back.
    fAmountPaidBack = fMonthlyPayment * (double)iNumPayments;

    // Calculate the interest paid.
    fInterestPaid = fAmountPaidBack - fLoanAmount;

    // Display the results.
    cout << fixed << setprecision(2);   // Display the output to 2 digits after the decimal point.
    cout << "Loan Amount: " << fLoanAmount << endl;
    cout << "Monthly Interest Rate: " << fMonthlyRate * 100.0 << "%" << endl;
    cout << "Number of Payments: " << iNumPayments << endl;
    cout << "Monthly Payment: $" << fMonthlyPayment << endl;
    cout << "Amount Paid Back: $" << fAmountPaidBack << endl;
    cout << "Interest Paid: $" << fInterestPaid << endl;

    return 0;   // Return 0 to the operating system to indicate successful completion of the program.
} 
