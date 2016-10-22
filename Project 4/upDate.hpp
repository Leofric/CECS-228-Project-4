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
    //global variable to track the number of dateCount objects in existence
    static int dateCount;
public:
    /*
     The default constructor
     */
    upDate();
    
    /*
     Overloaded constructor
        @param month 
                the month of the new date object, type int
        @param day 
                the day of the new date object, type int
        @param year 
                the year of the new date object, type int
     */
    upDate(int month, int day, int year);
    
    /*
     The copy constructor
     @param d
            the upDate object to be copied, type const upDate
     */
    upDate(const upDate & d);
    
    /*
     The destructor
     */
    ~upDate();
    
    /*
     This function sets the date of the upDate object to the user defined input
     @param m
            the new month, type int
     @param d
            the new day, type int
     @param y
            the new year, type int
     */
    void setDate(int m, int d, int y);
    
    /*
     This function returns the month of the date stored in the upDate object
     @return the month, type int
     */
    int getMonth();
    
    /*
     This function returns the day of the date stored in the upDate object
     @return the day, type int
     */
    int getDay();
    
    /*
     This function returns the year of the date stored in the upDate object
     @return the year, type int
     */
    int getYear();
    
    /*
     This function returns the name of the month of the date stored in the upDate object
     @return the name of the month, type string
     */
    std::string getMonthName();
    
    /*
     This function returns the number of days in a month for a particular year, ensures no invalid dates
     @param m
            the month, type int
     @param y
            the year, type int
     @return the number of days in the month, type int
     */
    int daysInMonth(int m, int y);
    
    /*
     This function returns the number of days between two upDate objects
     @param d
            the upDate object to be compared, type const upDate
     @return the number of days between the two objects, type int
     */
    int daysBetween(const upDate& d);
    
    /*
     This function converts a julian date into a gregorian date and stores the month, day, and year into a pointer array
     @param *date
            a pointer array to store the gregorian date information, type int
     @param x
            the julian date, type int
     */
    static void convertToGregorian(int *date, int x);
    
    /*
     This function converts a julian date into a gregorian date
     @param m
            the month, type int
     @param d
            the day, type int
     @param y 
            the year, type int
     @return the gregorian date, type int
     */
    static int convertToJulian(int m, int d, int y);
    
    /*
     This function overloads the == operator to work with upDate objects
     @param a
            the object to compare, type const upDate
     @return the outcome, type bool
     */
    bool operator ==(const upDate& a);
    
    /*
     This function overloads the < operator to work with upDate objects
     @param a
            the object to compare, type const upDate
     @return the outcome, type bool
     */
    bool operator <(const upDate& a);
    
    /*
     This function overloads the > operator to work with upDate objects
     @param a
            the object to compare, type const upDate
     @return the outcome, type bool
     */
    bool operator >(const upDate& a);
    
    /*
     This function overloads the -- operator to work with upDate objects
     */
    upDate& operator --();
    
    /*
     This function overloads the -- operator on the left side to work with upDate objects
     */
    upDate operator --(int);
    
    /*
     This function overloads the ++ operator to work with upDate objects
     */
    upDate& operator ++();
    
    /*
     This function overloads the ++ operator on the left side to work with upDate objects
     */
    upDate operator ++(int);
    
    /*
     This function returns the current julian representation of the upDate object
     @return the julian date, type int
     */
    int julian();
    
    /*
     This function overloads the = operator to work with upDate objects
     @param d
            the object to compare, type const upDate
     */
    void operator=(const upDate& d);
    
    /*
     This function overloads the << operator to work with upDate objects
     @param os
            the output stream
     @param dt
            the object to be printed, type upDate
     */
    friend std::ostream& operator<<(std::ostream& os, const upDate& dt);
    
    /*
     This function overloads the + operator to work with upDate objects
     @param d
            the object argument, type upDate
     @param j
            the numeric argument, type int
     */
    friend upDate operator+(upDate& d, const int j);
    
    /*
     This function overloads the + operator on the left to work with upDate objects
     @param j
            the numeric argument, type int
     @param d
            the object argument, type upDate
     */
    friend upDate operator+(int j, upDate& d);
    
    /*
     This function overloads the - operator to work with upDate objects
     @param j
            the numeric argument, type int
     @param d
            the object argument, type upDate
     */
    friend upDate operator-(const int j, const upDate&);
    
    /*
     This function overloads the - operator to work with upDate objects
     @param j
            the numeric argument, type int
     */
    friend upDate operator-(const upDate&, const int j);
    
    /*
     This function overloads the - operator to compare two myDate objects and calculate the days between
     @param a
            the date to be compared, type upDate
     */
    int operator -(const upDate& a);
    
    /*
     This function returns the number of upDate objects currently assigned to memory
     @return the dateCount global variable, type int
     */
    static int GetDateCount();
    
private:
    int *date;
};
#endif /* upDate_hpp */
