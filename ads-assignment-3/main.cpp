//
//  main.cpp
//  ads-assignment-3
//
//  Created by Martin Kiesel on 08/04/16.
//  Copyright © 2016 Martin Kiesel. All rights reserved.
//

#include <iostream>


//#include "src/file_parser.hpp"
#include "src/optimal_binary_tree/binary_search_tree.hpp"

int main(int argc, const char * argv[])
{
    using namespace ads_2;
    using parser::FileParser;
    using binary_tree::BinarySearchTree;

    FileParser parser("dictionary-min.txt", 1000);
    if (!parser.isValid()) return 1;

    BinarySearchTree bst(&parser);
    size_t start = time(NULL);
    bst.compute();
    size_t end = time(NULL);
    std::cout << end - start << std::endl;
    std::cout << bst.getNodeCount() << std::endl;

    std::string word;
    while (std::cin >> word)
    {
        if (word == "abc") break;
        std::cout << word << ": " << bst.search(word) << std::endl;
    }
    return 0;
}