//
//  main.cpp
//  ads-assignment-3
//
//  Created by Martin Kiesel on 08/04/16.
//  Copyright © 2016 Martin Kiesel. All rights reserved.
//

#include <iostream>
#include <ctime>

#include "src/file_parser.hpp"
#include "src/optimal_binary_tree/binary_search_tree.hpp"
#include "src/hash_table/hash_table.hpp"

int main(int argc, const char * argv[])
{
    using namespace ads_2;
    using parser::FileParser;
    using binary_tree::BinarySearchTree;
    using hash_table::HashTable;


    FileParser parser("dictionary.txt", static_cast<type::uintf>(1000));
    FileParser sample("sample100000.txt", true);
    if (!parser.isValid() || !sample.isValid()) return 1;
//
//    BinarySearchTree bst(&parser);

//    bst.compute();
    HashTable ht(&parser);
    ht.sortLists();

    type::uintf hit_counter = 0;
    size_t start = clock();
    for (const auto &sample : sample.getSampleData())
        hit_counter = hit_counter + ht.search(sample);

    size_t end = clock();
    std::cout << (end - start)/double(CLOCKS_PER_SEC)*1000 << std::endl;
    std::cout << hit_counter << std::endl;





//    std::string word;
//    while (std::cin >> word)
//    {
//        if (word == "abc") break;
//        std::cout << "ht.search(" << word << "): " << ht.search(word) << std::endl;
//
//    }

    return 0;
}