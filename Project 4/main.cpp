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
    upDate D2;
    D2++;
    ++D2;
    --D2;
    D2--;
    std::cout<<D2<<std::endl;
    std::cout<<D2.julian();
    upDate D1(10,27,2010);
    D1 = D1+5;
    D1 = 5 + D1;
 //   upDate D3 = D2+5;
//std::cout<<D3<<std::endl;
  //  int x = D3-D2;
  //  upDate D4 = 5+D2;
    return 0;
}
