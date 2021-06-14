// Homework3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Shayla Zilinsky
// ITCS 2530
// 06/08/2021
// Description: This is a shipping calculator that:
// 1. Takes the item name
// 2. Determines if the item is fragile
// 3. Calculates the ordr total
// 4. Takes the destination of shipment


#include <iostream>
// including header file cmath to be able to round my numbers
#include <cmath>
// including header file iomanip to be able to use setrpecision
#include <iomanip>
// including header file fstream to be able to output to a txt file
#include <fstream>
// including string header file
#include <string>
// including algorithm header file
#include <algorithm>

using namespace std;

// const variables for shipping costs
const float fragileShipping = 2.00;
const float notFragile = 0.00;
// free shipping
const float freeShipping = 0.00;
// usa shipping costs
const float usaShipping1 = 6.00;
const float usaShipping2 = 9.00;
const float usaShipping3 = 12.00;
// canada shipping costs
const float canShipping1 = 8.00;
const float canShipping2 = 12.00;
const float canShipping3 = 15.00;
// australia shipping costs
const float ausShipping1 = 10.00;
const float ausShipping2 = 14.00;
const float ausShipping3 = 17.00;
// pluto shipping costs
const float plutoShipping1 = 10.00;
const float plutoShipping2 = 11.00;
const float plutoShipping3 = 12.00;


int main()
{
    // declaring variables
    string itemName;
    string fragile;
    float orderCost;
    string destination;
    float shippingCost;
    float finalCost;
    float extraShipping;
    float totalShipping;

    // writing to order file
    ofstream outFile;
    outFile.open("Order.txt");
    if (outFile.fail())
    {
        return 0;
    }

    // set precision to 2 decimal spaces
    cout << fixed << setprecision(2);

    // introduction print statement
    cout << setw(50) << setfill('*') << "" << endl;
    cout << "ITCS 2530 - Programming Assignment for week #3" << endl;
    cout << setw(50) << setfill('*') << "" << endl;

    // collect user input on the item name
    cout << "Please enter the item name (no spaces)" << setfill('.') << setw(11) << ":" << itemName;
    cin >> itemName;
    // transforming the item name to upper case
    transform(itemName.begin(), itemName.end(), itemName.begin(), toupper);

    // collect user input on fragility of the item
    cout << "Is this item fragile? (y=yes/n=no)" << setw(15) << ":" << fragile;
    cin >> fragile;
    // if statement to calculate the shipping cost
    if (fragile == "Y")
        extraShipping = fragileShipping;
    else if (fragile == "y")
        extraShipping = fragileShipping;
    else if (fragile == "N")
        extraShipping = notFragile;
    else if (fragile == "n")
        extraShipping = notFragile;
    else {
        cout << "Invalid entry, exiting" << endl;
        // returning 0 will exit the program
        return 0;
    }


    // collect the user input for the order total
    cout << "Please enter your order total" << setw(20) << ":";
    cin >> orderCost;

    // collect user input on the destination of the item
    cout << "Please enter your destination. (usa/can/aus/plu)" << setw(5) << ":" << destination;
    cin >> destination;
    // transforming destination to upper case
    transform(destination.begin(), destination.end(), destination.begin(), toupper);

    // if statement to calculate shipping cost based on destination and order total

    // shipping to usa
    if (destination == "USA")
        if (orderCost <= 50.00)
            shippingCost = usaShipping1;
        else if ((orderCost >= 50.01) && (orderCost <= 100.00))
            shippingCost = usaShipping2;
        else if ((orderCost >= 100.01) && (orderCost >= 150.00))
            shippingCost = usaShipping3;
        else
            shippingCost = freeShipping;
    // shipping to canada
    else if (destination == "CAN")
        if (orderCost <= 50.00)
            shippingCost = canShipping1;
        else if ((orderCost >= 50.01) && (orderCost <= 100.00))
            shippingCost = canShipping2;
        else if ((orderCost >= 100.01) && (orderCost >= 150.00))
            shippingCost = canShipping3;
        else
            shippingCost = freeShipping;
    // shipping to australia
    else if (destination == "AUS")
        if (orderCost <= 50.00)
            shippingCost = ausShipping1;
        else if ((orderCost >= 50.01) && (orderCost <= 100.00))
            shippingCost = ausShipping2;
        else if ((orderCost >= 100.01) && (orderCost >= 150.00))
            shippingCost = ausShipping3;
        else
            shippingCost = freeShipping;
    // shipping to pluto
    else if (destination == "PLU")
        if (orderCost <= 50.00)
            shippingCost = plutoShipping1;
        else if ((orderCost >= 50.01) && (orderCost <= 100.00))
            shippingCost = plutoShipping2;
        else if ((orderCost >= 100.01) && (orderCost >= 150.00))
            shippingCost = plutoShipping3;
        else
            shippingCost = freeShipping;
    // invalid shipping destination
    else {
        cout << "Invalid entry, exiting" << endl;
        // returning 0 will exit the program
        return 0;
    }

    // calculating total shipping cost
    totalShipping = extraShipping + shippingCost;

    // calculating the final cost
    finalCost = totalShipping + orderCost;

    cout << "" << endl;

    cout << "Your item is" << setw(30) << itemName << endl;

    cout << "Your shipping cost is" << setw(18) << totalShipping << endl;

    cout << "You are shipping to" << setw(22) << destination << endl;

    cout << "Your total shipping costs are" << setw(10) << "$" << finalCost << endl;

    // writing output to new file - Order.txt
    outFile << "Your item is" << setw(30) << itemName << endl;
    outFile << "Your shipping cost is" << setw(18) << totalShipping << endl;
    outFile << "You are shipping to" << setw(22) << destination << endl;
    outFile << "Your total shipping costs are" << setw(10) << "$" << finalCost << endl;

    // closing file
    outFile.close();

    return 0;
}
