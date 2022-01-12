#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

void drinkReceipt(string drink, string type, int cost) {
    int sug;
    double money, change;
    string sugar;

    cout << "Would you like sugar with your drink?" << endl;
    cout << "(1) Yes" << endl;
    cout << "(2) No" << endl;
    cin >> sug;
    
    while (cin.fail() || sug >= 3 || sug <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Incorrect Input, Try Again:" << endl;
        cin >> sug;
    }

    if (sug == 1) {
        sugar = "Yes";
    }
    else if (sug == 2) {
        sugar = "No";
    }
    cout << endl;

    cout << "Enter the amount you would like to pay?:" << endl;
    cin >> money;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid Amount, Try Again:" << endl; 
        cin >> money;
    }

    cout << endl;
    change = money - cost;

    if (money < cost) {
        cout << "Sorry, You do not have enough money to buy your drink." << endl;
    }
    else {
        cout << endl;
        cout << endl;

        cout << "_________________________" << endl;
        cout << "________RECEIPT__________" << endl;
        cout << "Drink:      " << drink << endl;
        cout << "Drink Type: " << type << endl;
        cout << "Sugar:      " << sugar << endl;
        cout << "Cost:       " << cost << endl;
        cout << "Paid:       " << money << endl;
        cout << "Change:     " << change << endl;
        cout << endl;

        cout << "Please Wait for your order, Thank you for Purchasing!" << endl;
    }
}
void drink_CoffeeCost(int price) {
    int cost = 0, money = 1, change;
    string item, drink, type, sugar;

    if (price == 1) {
        drink = "Coffee";
        type = "Iced Coffee";
        cost = 3;
        drinkReceipt(drink, type, cost);

    }
    else if (price == 2) {
        drink = "Coffee";
        type = "Milk Coffee";
        cost = 2;
        drinkReceipt(drink, type, cost);

    }
    else if (price == 3) {
        drink = "Coffee";
        type = "Black Coffee";
        cost = 1;
        drinkReceipt(drink, type, cost);

    }
    else if (price >= 4 || price <= 0) {
        cout << "Invalid Drink Type" << endl;

    }

    cout << endl;
}

void drink_TeaCost(int price){
    int cost;
    string item, drink, type, sugar;

    if (price == 1) {
        drink = "Tea";
        type = "Ice Tea";
        cost = 3;
        drinkReceipt(drink, type, cost);

    }
    else if (price == 2) {
        drink = "Tea";
        type = "Milk Tea";
        cost = 2;
        drinkReceipt(drink, type, cost);

    }
    else if (price == 3) {
        drink = "Tea";
        type = "Black Tea";
        cost = 1;
        drinkReceipt(drink, type, cost);

    }
    else if (price >= 4 || price <= 0){
        cout << "Invalid Drink Type" << endl;

    }

    cout << endl;     
}

void drinkType(char x) {
    int type;
    switch (x) {
    case 'C':
    case 'c':
        cout << "You have picked Coffee, Please choose and enter the number what kind of coffee you like:" << endl;
        cout << "(1) Ice Coffee - 3 AED" << endl;
        cout << "(2) Milk Coffee - 2 AED" << endl;
        cout << "(3) Black Coffee - 1 AED" << endl;
        cin >> type;
        cout << endl;
        drink_CoffeeCost(type);
        break;
    case 'T':
    case 't':
        cout << "You have picked Tea, Please choose and enter the number of what kind of tea you like:" << endl;
        cout << "(1) Ice Tea - 3 AED (IT)" << endl;
        cout << "(2) Milk Tea - 2 AED (MT)" << endl;
        cout << "(3) Black Tea - 1 AED (BT)" << endl;
        cin >> type;
        cout << endl;
        drink_TeaCost(type);
        break;
    default:
        cout << "Invalid Choice" << endl;
    }
}

int main() {
    char ct;
    cout << "Welcome Customer! Here's the Menu!" << endl;
    string menu[4][4] = {
    { "||Coffee       ", "|Price (AED)  |", "|Tea       ", "|Price (AED) |"  },
    { "||Ice Coffee    ", "  3          ||", "Ice Tea", "     3          |" },
    { "||Milk Coffee   ", "  2          ||", "Milk Tea", "    2          |" },
    { "||Black Coffee  ", "  1          ||", "Black Tea", "   1          |" } };

    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            cout << menu[x][y];
        }
        cout << endl;
    }
    cout << endl;

    cout << "Lets get started with your order.\n";
    cout << "What Drink would you like, Coffee or Tea?(C/T)\n";
    cin >> ct;
    cout << endl;

    drinkType(ct);

}
