//============================================================================
// Name        : upDate-demo.cpp
// Author      : huberthuynh
// Version     :
// Copyright   : common creative - attribute
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "upDate.hpp"

using namespace std;

//This is a testing code to test the upDate class.
//Please do not change the code inside this main function
int main() {
    //test date count and constructor and insertion operator
    cout << "\n********** Test constructors and get functions***********\n";
    cout << "Date count is " << upDate::GetDateCount() << endl;
    upDate D0;
    
    if ( (D0.getMonth() != 5) || (D0.getDay() != 11) || (D0.getYear() != 1959) ) {
        cout << "Default constructor or get functions issues" << endl;
    }
    else cout << "Default constructor and get functions ok" << endl;
    
    upDate D1(12, 16, 2016);
    
    if ( (D1.getMonth() != 12) || (D1.getDay() != 16) || (D1.getYear() != 2016) ) {
        cout << "Overload constructor or get functions issues" << endl;
    }
    else cout << "Overload constructor and get functions ok" << endl;
    
    
    upDate D2(D0);
    D2.setDate(12, 16, 2016);
    if ( (D2.getMonth() != 12) || (D2.getDay() != 16) || (D2.getYear() != 2016) ) {
        cout << "Copy constructor or get functions issues" << endl;
    }
    else cout << "Copy constructor and get functions ok" << endl;
    
    //test arithmetic binary operator
    cout << "\n********** Test binary arithmetic operators and dateCount()***********\n";
    {
        upDate D3(2, 28, 2014);
        upDate D4(2, 28, 2017);
        
        upDate D5 = 365 + D3;
        upDate D6 = D5 + 366;
        
        if ( (D6.getMonth() != 2) || (D6.getDay() != 29) || (D6.getYear() != 2016) ) {
            cout << "+ binary constructor or get functions issues" << endl;
        }
        else { cout << "+ binary constructor and get functions ok" << endl; }
        
        D4 = D4 - 365;
        if ( (D4.getMonth() != 2) || (D4.getDay() != 29) || (D4.getYear() != 2016) ) {
            cout << "- binary constructor - or get functions issues" << endl;
        }
        else { cout << "- binary constructor and get functions ok" << endl; }
        
    }
    if (upDate::GetDateCount()== 3) {
        cout << "getDateCount() and destructor ok" << endl;
    }
    else {
        cout << "getDateCount() is not ok" << endl;
        cout << "Date count is " << upDate::GetDateCount() << endl;
    }
    
    //test pre and post increment and decrement
    cout << "\n**********Test pre and post decrement and increment get functions***********\n";
    if (++D2 == D2--) {
        cout << "pre ++ and post -- and == are ok" << endl;
    }
    else {
        cout << "either pre ++ and or post -- are NOT ok" << endl;
    }
    
    if (--D2 == D2++) {
        cout << "post ++ and pre -- and == are ok" << endl;
    }
    else {
        cout << "either post ++ and or pre -- and == are NOT ok" << endl;
    }
    
    // test Julian() and D3-D1 and cout << D4
    cout << "\n**********Test Julian() and D3-D1 and cout << D4***********\n";
    D1.setDate(2,28,2015);
    D2.setDate(2,29,2016);
    
    if ((D2-D1) == 366) {
        cout << "D2-D1  is ok" << endl;
    }
    else {
        cout << "D2-D1 is not ok" << endl;
    }
    
    if ((D2.julian() -D1.julian()) == 366) {
        cout << "D2-D1  is ok" << endl;
    }
    else {
        cout << "D2-D1 is not ok" << endl;
    }
    
    cout <<"\nVerifing << operator and getMonthName()\n";
    cout << D2.getMonthName() << " "<< D2.getDay() << ", "<< D2.getYear() <<endl;
    cout << D2 << endl;
    cout << "The above 2 dates should be the same, " << endl;
    
    
    // test ==, > and <
    cout << "\n********** test ==, > and < ***********\n";
    D0.setDate(2,29,2016);
    
    if ((D2==D0)) {
        cout << "==  is ok" << endl;
    }
    else {
        cout << "== is not ok" << endl;
    }
    
    if ((D2 > D1)) {
        cout << "operator>  is ok" << endl;
    }
    else {
        cout << "operator> is not ok" << endl;
    }
    
    if ((D1 < D2)) {
        cout << "operator<  is ok" << endl;
    }
    else {
        cout << "operator< is not ok" << endl;
    }
    
    string ch;
    cout << "\n\nEnter any character plus return to exit";
    cin >> ch;
    return 0;
}

