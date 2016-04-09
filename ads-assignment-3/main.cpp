//
//  main.cpp
//  ads-assignment-3
//
//  Created by Martin Kiesel on 08/04/16.
//  Copyright © 2016 Martin Kiesel. All rights reserved.
//

#include <iostream>

#include "src/FileParser.hpp"

int main(int argc, const char * argv[]) {
    using namespace ads_2;

    using parser::FileParser;
    FileParser parser("dictionary-small.txt", 10);


    return 0;
}