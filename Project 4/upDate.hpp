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
public:
    upDate();
    upDate(int month, int day, int year);
    ~upDate();
    void setDate(int m, int d, int y);
    int getMonth();
    int getDay();
    int getYear();
    std::string getMonthName();
    int daysInMonth(int m, int y);
    int daysBetween(upDate d);
    void incrDate(int n);
    void decrDate(int n);
    void convertToGregorian(int x);
    int convertToJulian(int m, int d, int y);
    bool operator ==(const upDate& a);
    bool operator <(const upDate& a);
    bool operator >(const upDate& a);
    upDate& operator --();
    upDate operator --(int);
    upDate& operator ++();
    upDate operator ++(int);
    void julian();
    friend std::ostream& operator<<(std::ostream& os, const upDate& dt);

    upDate& operator +=(const upDate& rhs);
    
    upDate& operator -=(const upDate& rhs);
    
  //  upDate operator+(int v);
    const upDate operator+(const upDate &other) const ;
    
    //operator upDateD3=D2+5; //add5daystoD2 --> so call D3 = D2.setDays(D2 + 5);
    //operator upDateD4=5+D2;//add5daystoD2
    //operator D5 = D2 – 4; // subtract 4 days from D2
    
    //copy constructor

private:
    int *date;
};



#endif /* upDate_hpp */
