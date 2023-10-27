//SECTION 3 GROUP 1
//EZAMIRUL SYAKIR BIN SHEKH ABDUL HALIM
//AA221947
//MUHAMMAD QAID UQAIL BIN KHAIRUL ANUAR
//AA221626
//HAZMAN IRFAN BIN AHSAN
//AA221623
//NUR ALMAS SHAZIRENE FASHALIN BINTI MUHAMMAD MUZAFAR
//AA222155
//JUITA EIYSAH BINTI SUHAINI
//AA220239
//AFRINA FARZANA BINTI AZARUDDIN
//AA221505
#include<iostream>
#include<iomanip>
#include<string>
#include<ctime>
using namespace std;

//Global Variables
int category[2] = { 0,0 }, subCategoryFood[2] = { 0,0 }, subCategoryDrinks[2] = { 0,0 }, subCategoryBurger[3] = { 0,0,0 }, burgerbeef[10] = { 0,0,0,0,0,0,0,0,0,0 }, 
burgerchicken[8] = { 0,0,0,0,0,0,0,0 }, burgervege[2] = { 0,0 }, addons[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 }, setmealF[4] = { 0,0,0,0 },
setmealBev[4] = { 0,0,0,0 }, sidesItems[11] = { 0,0,0,0,0,0,0,0,0,0,0 }, drinks[8] = { 0,0,0,0,0,0,0,0 }, drinksM[3] = { 0,0,0 }, maxsetmeal;
string categoryN[2] = { "Food", "Drinks" }, subCategoryFoodN[2] = { "Burger","Sides " }, subCategoryDrinksN[2] = { "Others    ","Milkshakes" }, 
subCategoryBurgerN[3] = { "Burger Beef      ", "Burger Chicken   ","Burger Vegetarian" },
burgerbeefN[10] = { "The Shack [Beef]              ", "Animal Style                  ", "Double Animal                 ", "KGB Spiked                    ", "Tornado [Beef]                ", "Bash                          ",
"Bella Bomb Tower              ", "Sacre Bleu!                   ", "Truffle & Swish Mushroom      ", "Bobcat [Beef]                 " },
burgerchickenN[8] = { "The Shack [Chicken]           ", "Tornado [Chicken]             ","Bella Bomb                    ","Bobcat [Chicken]              ", "Klub                          ", "Seoul                         ",
"Hot Mess                      ", "Kickin'                       " },
burgervegeN[2] = { "Sunshine Bella                ", "Vegan Belia Bomb              " },
addonsN[13] = { "Egg                           ", "Chicken Ham                   ", "Caramelized Onion             ", "Sliced Cheese                 ", "Avocado                       ", "Bun                           ",
"Blue Cheese                   ",
"Beef Bacon                    ", "Bacon Jam Relish              ", "Portobello Mushroom           ", "Grilled Chicken               ", "Fried Chicken                 ", "Smashed Beef                  " },
setmealFN[4] = { "Salt & Pepper Fries", "Herbed Fries       ", "Spicy Cajun Fries  ", "Malt Vinegar Fries " }, setmealBevN[4] = { "Lemonade     ", "Ice Mango Tea", "Honey Lemon  ", "Ice Lemon Tea" },
sidesItemsN[11] = { "Onion Rings (Buttermilk Fried)", "Chicken Bites with Dips       ", "Potato Wedges with Dips       ", "Salt & Pepper Fries           ", "Herbed Fries                  ",
"Spicy Cajun Fries             ","Malt Vinegar Fries            ", "Truffle'd fries               ", "Kimchi fries with Bulgogi Beef","Kimchi Fries Fully Loaded     ", "Texas Jalapeno Cheese Fries   " },
drinksN[8] = { "Lemonade                      ", "Ice Mango Tea                 ", "Honey Lemon                   ", "Ice Lemon Tea                 ", "Ice Lavender Tea              ", "Strawberry Lemonade           ",
"Root Beer Float               ", "Coke Float                    " },
drinksNM[3] = { "Nutella S'mores               ", "Strawberry Season             ", "Salted Caramel Pralines       " },
setmealFries[999], setmealBeverages[999], setmealB[999];
double priceItemsBeef[10] = { 12.90, 14.90, 19.90, 15.90, 15.90, 18.90, 21.90, 18.90, 20.90, 15.90 }, priceItemsChicken[8] = { 12.90, 15.90, 21.90, 15.90, 18.90, 15.90, 18.90, 15.90 }, priceItemsVege[2] = { 14.90, 15.90 }, 
priceItemsAddOns[13] = { 2.00,2.00,2.50,2.50,3.00,3.00,3.00,3.50,3.50,4.00,6.00,6.50,7.00 },
priceItemsSides[11] = { 6.90,7.90,7.90,7.90,7.90,7.90,7.90,10.90,13.90,16.90,14.90 }, priceItemsDrinks[11] = { 5.90,5.90,5.90,5.90,6.90,6.90,6.90,6.90,11.90,11.90,11.90 }, setmealprice[100];
int quantitybeef[10], quantitychicken[8],
quantityvege[2],
quantityaddons[13],
quantitysides[11],
quantitydrinksO[8],
quantitydrinksM[3];


//Define Module Function
int inputValidation(string ask, int maxValue, int lower, string error);
int inputValidationQ(string ask);
double inputValidationPayment(double currenttotalPrice);
string staffName(double hour);
void receiptTemplate(double currenttotalPrice, double hour, double minute, string time, int month, int year, string staff, double totalpriceItems, int day, double payment);
void receiptCalculate(int maxValue, string itemsN[], double price[], int quantity[]);
void rankingSummarys(int maxValue, int itemsQ[], string itemsN[], string itemsRanking);
void categoryFoodChoice(double& totalpriceItems);
void categoryDrinksChoice(double& totalpriceItems);
double burgerBeef(int& value);
double burgerChicken(int& value);
double burgerVegetarian(int& value);
void addOns(double& totalpriceItems, int quantityburger, double priceItems);
void setmeal(double& totalpriceItems, double priceItems);
double setmealburgerBeef(double priceItems);
double setmealburgerChicken(double priceItems);
double setmealburgerVege(double priceItems);
void summaryValue(int maxValue, int itemsQ[], string itemsN[], string itemsRanking);

//MAIN FUNCTION
int main() {

#pragma warning(disable: 4996)
    //current time
    time_t now = time(0);
    tm* localTime = localtime(&now);
    int hour = localTime->tm_hour;
    int minute = localTime->tm_min;
    int year = localTime->tm_year;
    int day = localTime->tm_mday;
    int month = localTime->tm_mon;
    string time;
    if (hour > 11.59)
    {
        time = "PM";
    }
    else
    {
        time = "AM";
    }
    string staff = staffName(hour);
    int value = 0;
    double summaryTotalSales = 0;
    bool loopMenu = true;

    while (loopMenu == true) {

        cout << "\n\n\nMAIN MENU " << endl;
        cout << "1. Receive order from the customer \n2. Generate reports\n3. Exit the program\n" << endl;
        value = inputValidation("Enter Choice ", 3, 1, "Choice");

        if (value == 1) {
            for (int i = 0; i < 13; i++)
            {
                if (i < 2)
                {
                    quantityvege[i] = 0;
                }if (i < 3) {
                    quantitydrinksM[i] = 0;
                }
                if (i < 8){
                    quantitychicken[i] = 0;
                    quantitydrinksO[i] = 0;
                }
                if (i < 10){
                    quantitybeef[i] = 0;
                }
                if (i < 11)
                {
                    quantitysides[i] = 0;
                }
                if (i < 13)
                {
                    quantityaddons[i] = 0;
                }
            }

            double totalpriceItems = 0, payment, currenttotalPrice = 0;
            maxsetmeal = 0;
            int order = 1;


            while (order == 1)
            {
#pragma warning(disable:6385)
                cout << "\n\n\nWELCOME TO KGB" << "\nMy name is " << staff << endl;
                cout << "__________________________________________________________________________________________" << endl;
                cout << "Category\n" << endl;
                cout << "1. Food\n2. Drinks" << endl;
                value = inputValidation("Insert category code (1-2): ", 2, 1, "category");
                if (value == 1)
                {
                    categoryFoodChoice(totalpriceItems);
                }
                else if (value == 2) {

                    categoryDrinksChoice(totalpriceItems);
                }
                value = value - 1;
                category[value] += 1;
                order = inputValidation("Add more order? (Yes-1/No-2)", 2, 1, "choice");
                if (order == 1) {
                }
                else {
                    currenttotalPrice = totalpriceItems + totalpriceItems * 0.06;
                    payment = inputValidationPayment(currenttotalPrice);
                    receiptTemplate(currenttotalPrice, hour, minute, time, month, year, staff, totalpriceItems, day, payment);
                    summaryTotalSales += currenttotalPrice;
                }
            }

        }
        else if (value == 2)
        {
            bool loopQ = true;
            while (loopQ == true)
            {
                cout << "\n\n\nGENERATE REPORTS" << endl;
                cout << "\n\n\n1. Quantity sold for each product for the day\n2. Total sales for the day\n3. Ranking of the most ordered product for the day\n4. Return to Main Menu" << endl;
                value = inputValidation("Enter Choice ", 4, 1, "Choice");
                if (value == 1)
                {
                    cout << "\nSUMMARY\n____________" << endl;
                    summaryValue(2, category, categoryN, "CATEGORY");
                    summaryValue(2, subCategoryFood, subCategoryFoodN, "FOOD");
                    summaryValue(2, subCategoryDrinks, subCategoryDrinksN, "DRINKS");
                    summaryValue(3, subCategoryBurger, subCategoryBurgerN, "BURGER");
                    summaryValue(10, burgerbeef, burgerbeefN, "BEEF BURGER");
                    summaryValue(8, burgerchicken, burgerchickenN, "CHICKEN BURGER");
                    summaryValue(2, burgervege, burgervegeN, "VEGETARIAN BURGER");
                    summaryValue(13, addons, addonsN, "ADD-ONS");
                    summaryValue(4, setmealF, setmealFN, "SET MEAL FRIES");
                    summaryValue(4, setmealBev, setmealBevN, "SET MEAL BEVERAGES");
                    summaryValue(11, sidesItems, sidesItemsN, "SIDES");
                    summaryValue(8, drinks, drinksN, "OTHER DRINKS");
                    summaryValue(3, drinks, drinksNM, "MILKSHAKES");
                    cout << "\n\n\n";
                }
                else if (value == 2)
                {
                    cout << "\nTotal Summary Sales : RM" << fixed << setprecision(2) << summaryTotalSales;
                }
                else if (value == 3)
                {

                    int categoryR[2], subCategoryFoodR[2], subCategoryDrinksR[2], subCategoryBurgerR[3], burgerbeefR[10],
                        burgerchickenR[8], burgervegeR[2], addonsR[13], setmealFR[4],
                        setmealBevR[4], sidesItemsR[11], drinksR[8], drinksMR[3];
                    string categoryNR[2], subCategoryFoodNR[2] , subCategoryDrinksNR[2] , subCategoryBurgerNR[3],
                        burgerbeefNR[10],
                        burgerchickenNR[8],
                        burgervegeNR[2],
                        addonsNR[13],
                        setmealFNR[4], setmealBevNR[4],
                        sidesItemsNR[11],
                        drinksNR[8],
                        drinksNMR[3];


                    for (int i = 0; i < 13; i++)
                    {
                        if (i < 2)
                        {
                            categoryR[i] = category[i];
                            categoryNR[i] = categoryN[i];
                            subCategoryFoodR[i] = subCategoryFood[i];
                            subCategoryFoodNR[i] = subCategoryFoodN[i];
                            subCategoryDrinksR[i] = subCategoryDrinks[i];
                            subCategoryDrinksNR[i] = subCategoryDrinksN[i];
                            burgervegeR[i] = burgervege[i];
                            burgervegeNR[i] = burgervegeN[i];
                        }
                    
                        if (i < 3)
                        {
                            subCategoryBurgerR[i] = subCategoryBurger[i];
                            subCategoryBurgerNR[i] = subCategoryBurgerN[i];
                            drinksMR[i] = drinksM[i];
                            drinksNMR[i] = drinksNM[i];
                        }
                        if (i < 4)
                        {
                            setmealFR[i] = setmealF[i];
                            setmealFNR[i] = setmealFN[i];
                            setmealBevR[i] = setmealBev[i];
                            setmealBevNR[i] = setmealBevN[i];
                        }
                        if (i < 8)
                        {
                            burgerchickenR[i] = burgerchicken[i];
                            burgerchickenNR[i] = burgerchickenN[i];
                            drinksR[i] = drinks[i];
                            drinksNR[i] = drinksN[i];
                        }
                        if (i < 10)
                        {
                            burgerbeefR[i] = burgerbeef[i];
                            burgerbeefNR[i] = burgerbeefN[i];
                        }
                        if (i < 11)
                        {
                            sidesItemsR[i] = sidesItems[i];
                            sidesItemsNR[i] = sidesItemsN[i];
                        }
                        if (i < 13)
                        {
                            addonsR[i] = addons[i];
                            addonsNR[i] = addonsN[i];
                        }
                    }
                    cout << "\nRANKING\n____________" << endl;
                    rankingSummarys(2, categoryR, categoryNR, "CATEGORY");
                    rankingSummarys(2, subCategoryFoodR, subCategoryFoodNR, "FOOD");
                    rankingSummarys(2, subCategoryDrinksR, subCategoryDrinksNR, "DRINKS");
                    rankingSummarys(3, subCategoryBurgerR, subCategoryBurgerNR, "BURGER");
                    rankingSummarys(10, burgerbeefR, burgerbeefNR, "BEEF BURGER");
                    rankingSummarys(8, burgerchickenR, burgerchickenNR, "CHICKEN BURGER");
                    rankingSummarys(2, burgervegeR, burgervegeNR, "VEGETARIAN BURGER");
                    rankingSummarys(13, addonsR, addonsNR, "ADD-ONS");
                    rankingSummarys(4, setmealFR, setmealFNR, "SET MEAL FRIES");
                    rankingSummarys(4, setmealBevR, setmealBevNR, "SET MEAL BEVERAGES");
                    rankingSummarys(11, sidesItemsR, sidesItemsNR, "SIDES");
                    rankingSummarys(8, drinksR, drinksNR, "OTHER DRINKS");
                    rankingSummarys(3, drinksMR, drinksNMR, "MILKSHAKES");
                    cout << "\n\n\n";
                }
                else
                {
                    loopQ = false;
                }
            }
        }
        else
        {
           loopMenu = false;
        }
    }
}

//Modules Function
int inputValidation(string ask, int maxValue, int lower, string error)
{
    int value;
    bool inputV = false;
    do
    {
        cout << endl << ask << endl;
        cin >> value;
        cout << "\033[2J\033[1;1H";
        if (cin.fail() || value<lower || value>maxValue)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid " << error << ".Please enter 1 to " << maxValue << " only.";
        }
        else
        {
            string remainingInput;
            getline(cin, remainingInput);
            if (remainingInput.empty()) {
                break;  // Input is a valid integer
                inputV = true;
            }
            else {
                cout << "Invalid input. Please enter an integer value." << endl;
                inputV = false;
            }
        }

    } while (cin.fail() || value<lower || value>maxValue || not inputV);

    return value;
}
int inputValidationQ(string ask)
{
    int value;
    do
    {
        cout << endl << ask << endl;
        cin >> value;
        cout << "\033[2J\033[1;1H";
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid quantity.Please enter number for quantity";
        }
        else if (value < 1)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid quantity.Please enter at least 1";
        }
        else {}
    } while (cin.fail());
    return value;
}
double inputValidationPayment(double currenttotalPrice) {
    double payment;
    cout << "Total price : RM" << fixed << setprecision(2) << currenttotalPrice;
    do
    {
        cout << ".\nEnter payment : RM";
        cin >> payment;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid Amount.Please Pay RM" << currenttotalPrice;
        }
        else if (payment < currenttotalPrice)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInsufficient Amount.Please Pay RM" << currenttotalPrice;
        }

    } while (cin.fail() || payment < currenttotalPrice);
    return payment;
}
string staffName(double hour) {
    string staff;

    if (hour >= 0 && hour <= 3.59)
    {
        staff = "Ezamirul Syakir";
    }
    else if (hour >= 4 && hour <= 7.59)
    {
        staff = "Hazman Irfan";
    }
    else if (hour >= 8 && hour <= 11.59)
    {
        staff = "Nur Almas";
    }
    else if (hour >= 12 && hour <= 15.59)
    {
        staff = "Qaid Uqail";
    }
    else if (hour >= 16 && hour <= 19.59)
    {
        staff = "Juita Eiysah";
    }
    else
    {
        staff = "Afrina Farzana";
    }
    return staff;
}
void categoryFoodChoice(double& totalpriceItems)
{
    cout << "________________________________" << endl;
    cout << "                                                                                                              " << endl;
    cout << "Food" << endl;
    cout << "                                              " << endl;
    cout << "1. Burger     " << endl;
    cout << "2. Sides        " << endl;
    cout << "                                              " << endl;
    int value = inputValidation("Enter food code(1-2): ", 2, 1, "food code");
    int choice = value;
    if (value == 1)
    {
        double priceItems = 0;
        value = inputValidation("Make it a set meal? (1-Yes, 2-No) ", 2, 1, "choice");
        if (value == 1)
        {
            setmeal(totalpriceItems, priceItems);
        }
        else
        {
            cout << "________________________________" << endl;
            cout << "                                                                                                              " << endl;
            cout << "Burger " << endl;
            cout << "                                               " << endl;
            cout << "1. Beef             " << endl;
            cout << "2. Chicken       " << endl;
            cout << "3. Vegetarian  " << endl;
            cout << "                                               " << endl;
            value = inputValidation("Insert burger code(1-3): ", 3, 1, "burger's category code");
            cout << "________________________________" << endl << endl;
            int choice = value - 1;
            subCategoryBurger[choice] += 1;

            if (value == 1)
            {
                priceItems = burgerBeef(value);
            }
            else if (value == 2)
            {
                priceItems = burgerChicken(value);
            }
            else
            {
                priceItems = burgerVegetarian(value);
            }
            totalpriceItems = totalpriceItems + priceItems * value;
            int quantityburger = value;
            value = inputValidation("Add-Ons to burger?(Yes - 1/No - 2)", 2, 1, "choice");
            if (value == 1)
            {
                addOns(totalpriceItems, quantityburger, priceItems);
            }
            else {};
        }
        choice = choice - 1;
        subCategoryFood[choice] += 1;
    }
    else {
        cout << "________________________________" << endl;
        cout << "                                                                                                              " << endl;
        cout << "Sides Items" << endl;
        cout << "                                                  " << endl;
        cout << "1.  Onion Rings (Buttermilk Fried)              RM6.90" << endl;
        cout << "2.  Chicken Bites with Dips                     RM7.90" << endl;
        cout << "3.  Potato Wedges with Dips                     RM7.90" << endl;
        cout << "4.  Salt & Pepper Fries                         RM7.90" << endl;
        cout << "5.  Herbed Fries                                RM7.90" << endl;
        cout << "6.  Spicy Cajun Fries                           RM7.90" << endl;
        cout << "7.  Malt Vinegar Fries                          RM7.90" << endl;
        cout << "8.  Truffled fries                             RM10.90" << endl;
        cout << "9.  Kimchi fries with Bulgogi Beef              RM13.90" << endl;
        cout << "10. Kimchi Fries Fully Loaded                   RM16.90" << endl;
        cout << "11. Texas Jalapeno Cheese Fries                 RM14.90" << endl;
        value = inputValidation("Enter sides code(1-11):", 11, 1, "sides code");
        int choice = value;
        double priceItems;
        if (choice == 1)
        {
            priceItems = 6.9;
        }
        else if (choice <= 7)
        {
            priceItems = 7.9;
        }
        else if (choice == 8)
        {
            priceItems = 10.9;
        }
        else if (choice == 9)
        {
            priceItems = 13.9;
        }
        else if (choice == 10)
        {
            priceItems = 16.9;
        }
        else
        {
            priceItems = 14.9;
        }
        value = inputValidationQ("Enter the quantity");
        totalpriceItems = totalpriceItems + priceItems * value;
        choice = choice - 1;
        quantitysides[choice] += value;
        sidesItems[choice] += value;
    }
}
void categoryDrinksChoice(double& totalpriceItems)
{

    cout << "________________________________" << endl;
    cout << "                                                                                                              " << endl;
    cout << "Drinks" << endl;   cout << "                                                  " << endl;
    cout << "1. Others" << endl;
    cout << "2. Milkshakes" << endl;
    cout << "________________________________" << endl << endl;
    int value = inputValidation("Enter drinks code(1-2):", 2, 1, "drinks code");
    subCategoryDrinks[value] += 1;

    if (value == 1)
    {
        cout << "Other drinks" << endl;
        cout << "" << endl;
        cout << "Item                                                     Price(RM)" << endl;
        cout << "" << endl;
        cout << "1. Lemonade                                           5.90" << endl;
        cout << "2. Ice mango tea                                      5.90" << endl;
        cout << "3. Honey lemon                                        5.90" << endl;
        cout << "4. Ice lemon tea                                      5.90" << endl;
        cout << "5. Ice lavender tea                                   6.90" << endl;
        cout << "6. Stawberry lemonade                                 6.90" << endl;
        cout << "7. Root beer float                                    6.90" << endl;
        cout << "8. Coke float                                         6.90" << endl;
        value = inputValidation("Enter the drink's code(1-8): ", 8, 1, "drinks code");
        int choice = value;
        double priceItems;
        if (choice <= 4)
        {
            priceItems = 5.9;
        }
        else
        {
            priceItems = 6.9;
        }
        value = inputValidationQ("Enter quantity");
        totalpriceItems = totalpriceItems + priceItems * value;
        choice = choice - 1;
        quantitydrinksO[choice] += value;
        drinks[choice] += value;
    }
    else
    {
        cout << "Milkshakes" << endl;
        cout << "" << endl;
        cout << "Item                                                     Price(RM)" << endl;
        cout << "" << endl;
        cout << "1. Nutella S' mores                                 11.90" << endl;
        cout << "2. Stawberry season                                 11.90" << endl;
        cout << "3. Salted Caramel Pralines                          11.90" << endl;
        value = inputValidation("Enter milkshake code(1-3): ", 3, 1, "milkshake code");
        int choice = value;
        value = inputValidationQ("Enter quantity");
        totalpriceItems = totalpriceItems + 11.9 * value;
        choice = choice - 1;
        quantitydrinksM[choice] += value;
        drinks[choice] += value;
    }

}
double burgerBeef(int& value)
{
    cout << "Beef burger" << endl;
    cout << "                                                             " << endl;
    cout << "Item                                                 Price(RM)" << endl;
    cout << "                                                             " << endl;
    cout << "1. The Shack                                           12.90" << endl;
    cout << "2. Animal Style                                        14.90" << endl;
    cout << "3. Double Animal                                       19.90" << endl;
    cout << "4. KGB Spiked                                          15.90" << endl;
    cout << "5. Tornado                                             15.90" << endl;
    cout << "6. Bash                                                18.90" << endl;
    cout << "7. Bella Bomb Tower                                    21.90" << endl;
    cout << "8. Sacre Bleu!                                         18.90" << endl;
    cout << "9. Truffle & Swish Mushroom                            20.90" << endl;
    cout << "10. Bobcat                                             15.90" << endl;
    value = inputValidation("Enter Beef burger code (1-10): ", 10, 1, "beef burger code");
    int choice = value;
    double priceItems;
    if (choice == 1)
    {
        priceItems = 12.9;
    }
    else if (choice == 2)
    {
        priceItems = 14.9;
    }
    else if (choice == 3)
    {
        priceItems = 19.9;
    }
    else if (choice == 4 || choice == 10 || choice == 5)
    {
        priceItems = 15.9;
    }
    else if (choice == 6 || choice == 8)
    {
        priceItems = 18.9;
    }
    else if (choice == 7)
    {
        priceItems = 21.9;
    }
    else
    {
        priceItems = 20.9;
    }

    value = inputValidationQ("Enter quantity");
    choice = choice - 1;
    quantitybeef[choice] += value;
    burgerbeef[choice] += value;


    return priceItems;
}
double burgerChicken(int& value)
{
    cout << "Chicken burger" << endl;
    cout << "                                                         " << endl;
    cout << "Item                                                     Price(RM)" << endl;
    cout << "" << endl;
    cout << "1. The Shack                                               12.90" << endl;
    cout << "2. Tornado                                                 15.90" << endl;
    cout << "3. Bella Bomb                                              21.90" << endl;
    cout << "4. Bobcat                                                  15.90" << endl;
    cout << "5. Klub                                                    18.90" << endl;
    cout << "6. Seoul                                                   15.90" << endl;
    cout << "7. Hot Mess                                                18.90" << endl;
    cout << "8. Kickin                                                  15.90" << endl;
    value = inputValidation("Enter Chicken burger code (1-8): ", 8, 1, "chicken burger code");
    int choice = value;
    double priceItems;
    if (choice == 1)
    {
        priceItems = 12.9;
    }
    else if (choice == 2 || choice == 4 || choice == 6 || choice == 8)
        {
            priceItems = 15.9;
        }
        else if (choice == 5 || choice == 7)
            {
                priceItems = 18.9;
            }
            else
            {
                priceItems = 21.9;
            }
    value = inputValidationQ("Enter quantity");
    choice = choice - 1;
    quantitychicken[choice] += value;
    burgerchicken[choice] += value;

    return priceItems;
}
double burgerVegetarian(int& value)
{
    cout << "Vegetarian burger" << endl;
    cout << "                                                                  " << endl;
    cout << "Item                                                     Price(RM)" << endl;
    cout << "                                                                  " << endl;
    cout << "1. Sunshine Bella                                          14.90" << endl;
    cout << "2. Vegan Belia Bomb                                        15.90" << endl;
    value = inputValidation("Enter Vegetarian Burger code (1-2): ", 2, 1, " vegetarian burger code");
    int choice = value;
    double priceItems;
    if (choice == 1)
    {
        priceItems = 14.9;
    }
    else
    {
        priceItems = 15.9;
    }
    value = inputValidationQ("Enter quantity");
    choice = choice - 1;
    quantityvege[choice] += value;
    burgervege[choice] += value;
    return priceItems;
}
void addOns(double& totalpriceItems, int quantityburger, double priceItems)
{
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    cout << "Adds - Ons\n";
    cout << "1.  Egg                           RM2.00\n";
    cout << "2.  Chicken Ham                   RM2.00\n";
    cout << "3.  Caramelized onion             RM2.50\n";
    cout << "4.  Sliced cheese                 RM2.50\n";
    cout << "5.  Avocado                       RM3.00\n";
    cout << "6.  Bun                           RM3.00\n";
    cout << "7.  Blue cheese                   RM3.00\n";
    cout << "8.  Beef bacon                    RM3.50\n";
    cout << "9.  Bacon jam relish              RM3.50\n";
    cout << "10. Portobello mushroom           RM4.00\n";
    cout << "11. Grilled chicken               RM6.00\n";
    cout << "12. Fried chicken                 RM6.50\n";
    cout << "13. Smashed beef                  RM7.00\n";

    int count = 1;
    do {
        int choiceAO[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
        int countAO = 0;
        int choice{};
        int value = inputValidation("Add-Ons for Burger " + to_string(count) + "?(1-Yes/2-No)", 2, 1, "choice");
        do {
            if (value == 1)
            {
                value = inputValidation("Enter Add-Ons code between 1-13", 13, 1, "Add-Ons code");
                choice = value;
                if (choice == 1 || choice == 2) {
                    priceItems = 2.00;
                }
                else if (choice == 3 || choice == 4) {
                    priceItems = 2.50;
                }
                else if (choice == 5 || choice == 6 || choice == 7) {
                    priceItems = 3.00;
                }
                else if (choice == 8 || choice == 9) {
                    priceItems = 3.50;
                }
                else if (choice == 10) {
                    priceItems = 4.00;
                }
                else if (choice == 11) {
                    priceItems = 6.00;
                }
                else if (choice == 12) {
                    priceItems = 6.50;
                }
                else {
                    priceItems = 7.00;
                }
                totalpriceItems += priceItems;
                choice = choice - 1;
                quantityaddons[choice] += 1;
                addons[choice] += 1;
                value = inputValidation("Add more add-ons for burger " + to_string(count) + "? (1-Yes/2-No)", 2, 1, "choice");
            }
            else
            {
            }
            countAO++;
            choiceAO[countAO] = choice;
        } while (value == 1);
        count++;
    } while (count <= quantityburger);
}
void receiptTemplate(double currenttotalPrice, double hour, double minute, string time, int month, int year, string staff, double totalpriceitems, int day, double payment)

{
    cout << "\n\n ";
    cout << "                                                       KGB" << endl;
    cout << "                                                KGB Holding Sdh Bhd" << endl;
    cout << "                                                    1092679-U" << endl;
    cout << "                                             The Courtyard by KGB" << endl;
    cout << "                                         GP1-03 Level 3 , Tamarind Square," << endl;
    cout << "                                           Persiaran Multimedia , Cyberjaya ," << endl;
    cout << "                                                    63000,Selangor" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                                         INVOICE" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << setprecision(0) << endl;
    cout << "Date        : " << day << "/" << month << "/" << year << "   " << hour << ":" << minute << " " << time << endl;
    cout << "Staff: " << staff << endl;
    cout << "Order ID: " << rand() << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Item                                                             Qty           Unit P. (RM)          Price(RM)" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << setprecision(2) << endl;

    for (int count = 1; count <= maxsetmeal; count++)
    {
        cout << "Set Meal" << endl;
        cout << setmealB[count] + "                                                    1                                " << setmealprice[count] << endl;
        cout << setmealFries[count] << endl;
        cout << setmealBeverages[count] << endl;
        cout << "                                                                       " << endl;
    }

    receiptCalculate(10, burgerbeefN, priceItemsBeef, quantitybeef);
    receiptCalculate(8, burgerchickenN, priceItemsChicken, quantitychicken);
    receiptCalculate(2, burgervegeN, priceItemsVege, quantityvege);
    receiptCalculate(13, addonsN, priceItemsAddOns, quantityaddons);
    receiptCalculate(11, sidesItemsN, priceItemsSides, quantitysides);
    receiptCalculate(8, drinksN, priceItemsDrinks, quantitydrinksO);
    receiptCalculate(3, drinksNM, priceItemsDrinks, quantitydrinksM);

    cout << fixed << setprecision(2) << "---------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                                                              Subtotal                           " << totalpriceitems << endl;
    cout << "                                                                              6% Service Tax                     " << totalpriceitems * 0.06 << endl;
    cout << "                                                                              Total                              " << currenttotalPrice << endl;
    cout << "                                                                              CASH                               " << payment << endl;
    cout << "                                                                              Change                             " << payment - currenttotalPrice << endl;
}
void setmeal(double& totalpriceItems, double priceItems) {
    maxsetmeal++;
    cout << "________________________________" << endl;
    cout << "                                                                                                              " << endl;
    cout << "Burger " << endl;
    cout << "                                               " << endl;
    cout << "1. Beef             " << endl;
    cout << "2. Chicken       " << endl;
    cout << "3. Vegetarian  " << endl;
    cout << "                                               " << endl;
    cout << "________________________________" << endl << endl;
    int value = inputValidation("Insert burger code (1-3): ", 3, 1, "category burger");
    if (value == 1)
    {
        priceItems = setmealburgerBeef(priceItems);
    }
    else if (value == 2)
    {
        priceItems = setmealburgerChicken(priceItems);
    }
    else
    {
        priceItems = setmealburgerVege(priceItems);
    }
    value = value - 1;
    subCategoryBurger[value] += 1;
    setmealprice[maxsetmeal] = priceItems + 5.90;
    totalpriceItems += priceItems + 5.90;
    cout << "________________________________" << endl;
    cout << "                                                                                                              " << endl;
    cout << "Set Meal Fries  " << endl;
    cout << "                                               " << endl;
    cout << "1. Salt & Pepper Fries  " << endl;
    cout << "2. Herbed Fries             " << endl;
    cout << "3. Spicy Cajun Fries      " << endl;
    cout << "4. Malt Vinegar Fries    " << endl;
    value = inputValidation("Enter fries code (1-4): ", 4, 1, "fries code");
    if (value == 1)
    {
        setmealFries[maxsetmeal] = "Salt & Pepper Fries";
    }
    else if (value == 2)
    {
        setmealFries[maxsetmeal] = "Herbed Fries";
    }
    else if (value == 3)
    {
        setmealFries[maxsetmeal] = "Spicy Cajun Fries";
    }
    else
    {
        setmealFries[maxsetmeal] = "Malt Vinegar Fries";
    }
    value = value - 1;
    setmealF[value] += 1;
    cout << "________________________________" << endl;
    cout << "                                                                                                              " << endl;
    cout << "Set Meal Beverages  " << endl;
    cout << "                                               " << endl;
    cout << "1. Lemonade          " << endl;
    cout << "2. Ice Mango Tea   " << endl;
    cout << "3. Honey Lemon    " << endl;
    cout << "4. Ice Lemon Tea   " << endl;
    value = inputValidation("Enter beverage code (1-4): ", 4, 1, "beverage code");
    if (value == 1)
    {
        setmealBeverages[maxsetmeal] = "Lemonade";
    }
    else if (value == 2)
    {
        setmealBeverages[maxsetmeal] = "Ice Mango Tea";
    }
    else if (value == 3)
    {
        setmealBeverages[maxsetmeal] = "Honey Lemon";
    }
    else
    {
        setmealBeverages[maxsetmeal] = "Ice Lemon Tea";
    }
    value = value - 1;
    setmealBev[value] += 1;
}
double setmealburgerBeef(double priceItems) {
    cout << "________________________________" << endl;
    cout << "                                                                                                              " << endl;
    cout << "Beef burger" << endl;
    cout << "" << endl;
    cout << "Item                                                     Price(RM)" << endl;
    cout << "" << endl;
    cout << "1. The Shack                                           12.90" << endl;
    cout << "2. Animal Style                                        14.90" << endl;
    cout << "3. Double Animal                                       19.90" << endl;
    cout << "4. KGB Spiked                                          15.90" << endl;
    cout << "5. Tornado                                             15.90" << endl;
    cout << "6. Bash                                                18.90" << endl;
    cout << "7. Bella Bomb Tower                                    21.90" << endl;
    cout << "8. Sacre Bleu!                                         18.90" << endl;
    cout << "9. Truffle & Swish Mushroom                            20.90" << endl;
    cout << "10. Bobcat                                             15.90" << endl;

    int value = inputValidation("Enter Beef burger code (1-10): ", 10, 1, "beef burger code");
    if (value == 1)
    {
        priceItems = 12.9;
        setmealB[maxsetmeal] = "The Shack [Beef]";
    }
    else if (value == 2)
    {
        priceItems = 14.9;
        setmealB[maxsetmeal] = "Animal Style";
    }
    else if (value == 3)
    {
        priceItems = 19.9;
        setmealB[maxsetmeal] = "Double Animal";
    }
    else if (value == 4)
    {
        priceItems = 15.9;
        setmealB[maxsetmeal] = "KGB Spiked";
    }
    else if (value == 5)
    {
        priceItems = 15.9;
        setmealB[maxsetmeal] = "Tornado [beef]";
    }
    else if (value == 6)
    {
        priceItems = 18.9;
        setmealB[maxsetmeal] = "Bash";
    }
    else if (value == 7)
    {
        priceItems = 21.9;
        setmealB[maxsetmeal] = "Bella Bomb Tower";
    }
    else if (value == 8)
    {
        priceItems = 18.9;
        setmealB[maxsetmeal] = "Sacre Bleu!";
    }
    else if (value == 9)
    {
        priceItems = 20.9;
        setmealB[maxsetmeal] = "Truffle and Swish Mushroom";
    }
    else
    {
        priceItems = 15.9;
        setmealB[maxsetmeal] = "Bobcat [Beef]";
    }
    value = value - 1;
    burgerbeef[value] += 1;
    return priceItems;
}
double setmealburgerChicken(double priceItems)
{
    cout << "________________________________" << endl;
    cout << "                                                                                                              " << endl;
    cout << "Chicken burger" << endl;
    cout << "" << endl;
    cout << "Item                                                     Price(RM)" << endl;
    cout << "" << endl;
    cout << "1. The Shack                                               12.90" << endl;
    cout << "2. Tornado                                                 15.90" << endl;
    cout << "3. Bella Bomb                                              21.90" << endl;
    cout << "4. Bobcat                                                  15.90" << endl;
    cout << "5. Klub                                                    18.90" << endl;
    cout << "6. Seoul                                                   15.90" << endl;
    cout << "7. Hot Mess                                                18.90" << endl;
    cout << "8. Kickin                                                  15.90" << endl;
    int value = inputValidation("Enter Chicken burger code (1-8): ", 8, 1, "chicken burger code");
    if (value == 1)
    {
        priceItems = 12.9;
        setmealB[maxsetmeal] = "The Shack [Chicken]";
    }
    else if (value == 2)
    {
        priceItems = 15.9;
        setmealB[maxsetmeal] = "Tornado [Chicken]";
    }
    else if (value == 3)
    {
        priceItems = 21.9;
        setmealB[maxsetmeal] = "Bella Bomb";
    }
    else if (value == 4)
    {
        priceItems = 15.9;
        setmealB[maxsetmeal] = "Bobcat [Chicken]";
    }
    else if (value == 5)
    {
        priceItems = 18.9;
        setmealB[maxsetmeal] = "Klub";
    }
    else if (value == 6)
    {
        priceItems = 15.9;
        setmealB[maxsetmeal] = "Seoul";
    }
    else if (value == 7)
    {
        priceItems = 18.9;
        setmealB[maxsetmeal] = "Hot Mess";
    }
    else
    {
        priceItems = 15.9;
        setmealB[maxsetmeal] = "Kickin'";
    }
    value = value - 1;
    burgerchicken[value] += 1;
    return priceItems;
}
double setmealburgerVege(double priceItems)
{
    cout << "________________________________" << endl;
    cout << "                                                                                                              " << endl;
    cout << "Vegetarian Burger" << endl;
    cout << "                                                                                                              " << endl;
    cout << "Item                                                     Price(RM)" << endl;
    cout << "" << endl;
    cout << "1. Sunshine Bella                                          14.90" << endl;
    cout << "2. Vegan Belia Bomb                                        15.90" << endl;
    int value = inputValidation("Enter Vegetarian Burger code (1-2): ", 2, 1, "vegetarian burger code");
    if (value == 1)
    {
        priceItems = 14.9;
        setmealB[maxsetmeal] = "Sunshine Bella";
    }
    else
    {
        priceItems = 15.9;
        setmealB[maxsetmeal] = "Vegan Belia Bomb";
    }
    value = value - 1;
    burgervege[value] += 1;
    return priceItems;
}
void receiptCalculate(int maxValue, string itemsN[], double price[], int quantity[])
{
    int count = 0;
    while (count < maxValue)
    {
        if (quantity[count] == 0)
        {
        }
        else
        {
            cout << itemsN[count] << "                                    " << quantity[count] << "                 " << price[count] << "               " << quantity[count] * price[count] << endl;
        }
        count++;
    }
}
void rankingSummarys(int maxValue, int itemsQ[], string itemsN[], string itemsRanking)
{
    int outer = 0;
    while (outer < maxValue)
    {
        int inner = outer + 1;
        while (inner < maxValue)
        {
            if (itemsQ[inner] > itemsQ[outer])
            {
                int temporary = itemsQ[inner];
                itemsQ[inner] = itemsQ[outer];
                itemsQ[outer] = temporary;
                string temporaryN = itemsN[inner];
                itemsN[inner] = itemsN[outer];
                itemsN[outer] = temporaryN;
            }
            else
            {
            }
            inner++;
        }
        outer++;
    }

    int index = 1;
    cout << "                          " << endl;
    cout << itemsRanking << endl;
    cout << "---------------------------------------------------" << endl;
    for (int index = 0; index < maxValue; index++)
    {
        cout << itemsN[index] << "          " << itemsQ[index] << endl;
    }
}
void summaryValue(int maxValue, int itemsQ[], string itemsN[], string itemsRanking)
{

    cout << "                          " << endl;
    cout << itemsRanking << endl;
    cout << "---------------------------------------------------" << endl;
    for (int index = 0; index < maxValue; index++)
    {
        cout << itemsN[index] << "          " << itemsQ[index] << endl;
    }
}