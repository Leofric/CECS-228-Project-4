//
//  upDate.cpp
//  Project 4
//
//  Created by Alex Berthon on 10/17/16.
//  Copyright © 2016 Alex Berthon. All rights reserved.
//

#include "upDate.hpp"
#include <string>
#include <iostream>

upDate::upDate(){
    date = new int[3]{5, 11, 1959};
    dateCount++;
}

upDate::upDate(const upDate & d){
    date = new int[3];
    date[0] = d.date[0];
    date[1] = d.date[1];
    date[2] = d.date[2];
    dateCount++;
}

upDate::upDate(int m, int d, int y){
    date = new int[3]{5, 11, 1959};
    if (m<1 || m>12 || d<1 || d>31 || y<1 || y>2099 || y<1801 || d>daysInMonth(m,y)){
        date[0] = 5;
        date[1] = 11;
        date[2] = 1959;
    }
    else{
        date[0] = m;
        date[1] = d;
        date[2] = y;
    }
    dateCount++;
}

upDate::~upDate(){
    delete [] date;
    date = 0;
}

void upDate::setDate(int m, int d, int y){
    if (m<1 || m>12 || d<1 || d>31 || y<1 || y>2099 || y<1801 || d>daysInMonth(m,y)){
        date[0] = 5;
        date[1] = 11;
        date[2] = 1959;
    }
    else{
        date[0] = m;
        date[1] = d;
        date[2] = y;
    }
}

int upDate::getMonth(){
    return date[0];
}

int upDate::getDay(){
    return date[1];
}

int upDate::getYear(){
    return date[2];
}

std::string upDate::getMonthName(){
    std::string name;
    switch (date[0]) {
        case 1:
            name = "January";
            break;
        case 2:
            name = "Febuary";
            break;
        case 3:
            name = "March";
            break;
        case 4:
            name = "April";
            break;
        case 5:
            name = "May";
            break;
        case 6:
            name = "June";
            break;
        case 7:
            name = "July";
            break;
        case 8:
            name = "August";
            break;
        case 9:
            name = "September";
            break;
        case 10:
            name = "October";
            break;
        case 11:
            name = "November";
            break;
        case 12:
            name = "December";
            break;
    }
    return name;
}

int upDate::daysInMonth(int m, int y){
    switch (m) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 2:
            if(y % 4 != 0){
                return 28;
            }
            else if(y % 400 == 0){
                return 29;
            }
            else if(y % 100 == 0){
                return 28;
            }
            else return 29;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 0;
    }
}

//calculates the number of days between the given date and the current date
int upDate::daysBetween(const upDate& d){ //FIX
    double inputDate = upDate::convertToJulian(*(d.date), *(d.date+1), *(d.date+2));
    double thisDate = convertToJulian(date[0], date[1], date[2]);
    return inputDate - thisDate;
}

int upDate::julian(){
    return convertToJulian(date[0], date[1], date[2]);
}

//Overloading opperators
bool upDate::operator ==(const upDate& a)
{
    if(this->daysBetween(a)==0){
        return true;
    }
    else return false;
}

bool upDate::operator <(const upDate& a)
{
    if(this->daysBetween(a)<0){
        return true;
    }
    else return false;
}

bool upDate::operator >(const upDate& a)
{
    if(this->daysBetween(a)>0){
        return true;
    }
    else return false;
}

upDate& upDate::operator++(){
    this->date[1] += 1;
    return *this;
}

upDate upDate::operator++(int){
        upDate temp;
        operator++();
        return temp;
}

upDate& upDate::operator--(){
    date[1] = date[1]-1;
    return *this;
}

upDate upDate::operator--(int){ //bug here?
    upDate temp;
    operator--();
    return temp;
}

//used to convert Julian date to calendar date
void upDate::convertToGregorian(int *date, int x){
    int l, n, i, j, k;
    l= x+68569;
    n= 4*l/146097;
    l= l-(146097*n+3)/4;
    i= 4000*(l+1)/1461001;
    l= l-1461*i/4+31;
    j= 80*l/2447;
    k= l-2447*j/80;
    l= j/11;
    j= j+2-12*l;
    i= 100*(n-49)+i+l;
    
    date[0] = j;
    date[1] = k+1;
    date[2] = i;
}

int upDate::convertToJulian(int m, int d, int y){
    int julian = 367*y-(7*(y+(m+9)/12))/4 + (275*m)/9 + d + 1721013.5;
    return julian;
}

std::ostream& operator<<(std::ostream& os, const upDate& dt)
{
    os << dt.date[0] << '/' << dt.date[1] << '/' << dt.date[2];
    return os;
}

upDate operator+(upDate& d, const int j){
    double JD = upDate::convertToJulian(*(d.date), *(d.date+1), *(d.date+2));
    JD += j;
    int k[3];
    upDate::convertToGregorian(k, JD);
    return upDate(k[0], k[1], k[2]);
}

upDate operator+(int j, upDate& d){
    double JD = upDate::convertToJulian(*(d.date), *(d.date+1), *(d.date+2));
    JD += j;
    int k[3];
    upDate::convertToGregorian(k, JD);
    return upDate(k[0], k[1], k[2]);
}

upDate operator-(const int j, const upDate& d){
    double JD = upDate::convertToJulian(*(d.date), *(d.date+1), *(d.date+2));
    JD -= j;
    int k[3];
    upDate::convertToGregorian(k, JD);
    return upDate(k[0], k[1], k[2]);
}

upDate operator-(const upDate& d, const int j){
    double JD = upDate::convertToJulian(*(d.date), *(d.date+1), *(d.date+2));
    JD -= j;
    int k[3];
    upDate::convertToGregorian(k, JD);
    return upDate(k[0], k[1], k[2]);
}


int upDate::operator -(const upDate& d){
    return convertToJulian(*(date), *(date + 1), *(date + 2)) - convertToJulian(*(d.date), *(d.date+1), *(d.date+2));
}

void upDate::operator=(const upDate& d){
    date[0] = d.date[0];
    date[1] = d.date[1];
    date[2] = d.date[2];
}

int upDate::GetDateCount()
{
    return dateCount;
}
