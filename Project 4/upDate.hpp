//
//  upDate.hpp
//  Project 4
//
//  Created by Alex Berthon on 10/17/16.
//  Copyright © 2016 Alex Berthon. All rights reserved.
//

#ifndef upDate_hpp
#define upDate_hpp

#include <stdio.h>
#include <string>
class upDate{
    static int dateCount;
public:
    upDate();
    upDate(int month, int day, int year);
    upDate(const upDate & d);
    ~upDate();
    void setDate(int m, int d, int y);
    int getMonth();
    int getDay();
    int getYear();
    std::string getMonthName();
    int daysInMonth(int m, int y);
    int daysBetween(const upDate& d);
    static void convertToGregorian(int *date, int x);
    static int convertToJulian(int m, int d, int y);
    bool operator ==(const upDate& a);
    bool operator <(const upDate& a);
    bool operator >(const upDate& a);
    upDate& operator --();
    upDate operator --(int);
    upDate& operator ++();
    upDate operator ++(int);
    int julian();
    void operator=(const upDate& d);
    friend std::ostream& operator<<(std::ostream& os, const upDate& dt);
    friend upDate operator+(upDate& d, const int j);
    friend upDate operator+(int j, upDate& d);
    friend upDate operator-(const int j, const upDate&);
    friend upDate operator-(const upDate&, const int j);
    int operator -(const upDate& a);
    static int GetDateCount();


    //
    //niko
    //
    //carl
    
   //static method
   //Copy Constructor
    

private:
    int *date;
};
#endif /* upDate_hpp */
