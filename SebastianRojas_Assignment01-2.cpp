//Assignment 1
//Purpose of this assignment is to Generate a coin dispenser machine USING USD
//Sebastian Rojas
//09/04/23 EDITED @ 09/09/23
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
const int QUARTER_VALUE = 25;
const int DIME_VALUE = 10;
const int NICKEL_VALUE = 5;
const int PENNY_VALUE = 1;
void numeroUno() {
    // Part 1
    cout << "Enter the amount of cash you have numerically (start with $): ";
    string input;
    cin >> input;

    if (input.empty() || input[0] != '$' || input.find('.') == string::npos) {
        cout << "Wrong format. Please use the format $xx.xx. , sorry if it was not obvious enough!" << endl;
        return;
    }
    string dollarPart = input.substr(1, input.find('.') - 1);
    string centPart = input.substr(input.find('.') + 1);
    int dollars = stoi(dollarPart);
    int cents = stoi(centPart);
    if (dollars < 0 || cents < 0) {
        cout << "Negative amounts are not allowed." << endl;
        exit(1); // Abort the program ITS GONE BAD
    }
    int totalCents = dollars * 100 + cents;
    int quarters = totalCents / QUARTER_VALUE;
    totalCents %= QUARTER_VALUE;
    int dimes = totalCents / DIME_VALUE;
    totalCents %= DIME_VALUE;
    int nickels = totalCents / NICKEL_VALUE;
    totalCents %= NICKEL_VALUE;
    int pennies = totalCents;
    // Display the results
    cout << "Equivalent number of coins:" << endl;
    cout << "Quarters: " << quarters << endl;
    cout << "Dimes:    " << dimes << endl;
    cout << "Nickels:  " << nickels << endl;
    cout << "Pennies:  " << pennies << endl;
}

void numerodos() {
    // Part 2
    int quarters, dimes, nickels, pennies;
    cout << "Enter the number of quarters please!: ";
    cin >> quarters;
    cout << "Enter the number of dimes please!: ";
    cin >> dimes;
    cout << "Enter the number of nickels please!: ";
    cin >> nickels;
    cout << "Enter the number of pennies please!: ";
    cin >> pennies;
    if (quarters < 0 || dimes < 0 || nickels < 0 || pennies < 0) {
        cout << "Negative amounts are not allowed. STOP BEING A JOKESTER!" << endl;
        exit(1);
    }
    int totalCents = (quarters * QUARTER_VALUE) + (dimes * DIME_VALUE) +
        (nickels * NICKEL_VALUE) + (pennies * PENNY_VALUE);
    int dollars = totalCents / 100;
    int cents = totalCents % 100;
    cout << "The monetary value is: $" << dollars << ".";
    if (cents < 10) 
    {
        cout << "0";
    }
    cout << cents << endl;
}
int main() 
{
    int userinput;

    //Here is where the user puts in either 1 or 2, depending on which one the user picks it will then go with that.
    while (true)
    {
    cout << "Hello! Get your coins/dollars ready!" << endl;
    cout << "Would you rather..." << endl;
    cout << "1. Let me deal out coins for you" << endl;
    cout << "2. You deal those coins out for me, I'll sort the hard stuff out." << endl;
    cout << "3. Or if you are done, pick 3! " << endl;
    cout << "Pick either one (1/2/3): ";
    cin >> userinput;

    switch (userinput) //using switch since its the easiest for selection based on the value of a single value (shoutout to my programming 1 professor)
    {
    case 1:
        cin.ignore(); // IT KEPT MESSING UP THIS TOOK  SO LONG TO FIGURE OUT
        numeroUno();
        break;
    case 2:
        numerodos();
        break;
    case 3:
        cout << "See you next time!" << endl;
        return 0;
    default:
        cout << "PICK EITHER 1 OR 2 OR 3... Reopen and try again." << endl;
        break;
    }
    }
    return 0;
}
