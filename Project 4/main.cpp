//
//  main.cpp
//  Project 4
//
//  Created by Alex Berthon on 10/17/16.
//  Copyright © 2016 Alex Berthon. All rights reserved.
//

#include <iostream>
#include "upDate.hpp"

int main(int argc, const char * argv[]) {
    upDate D1(10,27,2010);
    upDate D2;
    
    D1++;
    std::cout<<D1<<std::endl;

    ++D1;
    std::cout<<D1<<std::endl;

    --D1;
    std::cout<<D1<<std::endl;

    D1--;
    std::cout<<D1<<std::endl;

    std::cout<<D1.julian()<<std::endl;

    D1 = D1 + 1;
    std::cout<<D1<<std::endl;
    D1 = D1 - 1;
    std::cout<<D1<<std::endl;
    D1 = 1 + D1;
    std::cout<<D1<<std::endl;
    D1 = 1 - D1;
    std::cout<<D1<<std::endl;

    std::cout<<"THE END!"<<std::endl;
    std::cout<<D1-D2<<std::endl;
    std::cout<<D1.daysBetween(D2)<<std::endl;
    return 0;

}
