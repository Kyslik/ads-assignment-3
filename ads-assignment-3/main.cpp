//
//  main.cpp
//  ads-assignment-3
//
//  Created by Martin Kiesel on 08/04/16.
//  Copyright © 2016 Martin Kiesel. All rights reserved.
//

#include <iostream>

#include "src/file_handler/dictionary_loader/dictionary_loader.hpp"
#include "src/file_handler/sample_loader/sample_loader.hpp"

#include "src/optimal_binary_tree/binary_search_tree.hpp"
#include "src/hash_table/hash_table.hpp"
#include "src/trie/trie.hpp"

const std::string DICTIONARY_FILE = "dictionary.txt";
const std::string SAMPLE_FILE = "sample100000.txt";

inline void reset(ads_2::type::uintf &i);

int main(int argc, const char * argv[])
{
    using namespace ads_2;
    using loader::DictionaryLoader;
    using loader::SampleLoader;
    using binary_tree::BinarySearchTree;
    using hash_table::HashTable;
    using trie::Trie;

    DictionaryLoader dictionary(DICTIONARY_FILE, 1000);
    SampleLoader     sample(SAMPLE_FILE);

    if (!dictionary.isValid() || !sample.isValid()) return 1;

    size_t start = 0, end = 0;
    type::uintf hit_counter = 0;

    BinarySearchTree    bst(&dictionary);
    HashTable           ht(&dictionary);
    Trie                trie(&dictionary);

    start = time(NULL);
    bst.compute();
    end = time(NULL);

    std::cout << (end - start) << std::endl;


    start = time(NULL);
    for (const auto &sample : sample.getData())
        hit_counter += bst.search(sample);
    end = time(NULL);

    std::cout << (end - start) << " " << hit_counter << std::endl;


    reset(hit_counter);
    start = time(NULL);
    for (const auto &sample : sample.getData())
        hit_counter += trie.search(sample);
    end = time(NULL);

    std::cout << (end - start) << " " << hit_counter << std::endl;


    reset(hit_counter);
    start = time(NULL);
    for (const auto &sample : sample.getData())
        hit_counter += ht.search(sample);
    end = time(NULL);

    std::cout << (end - start) << " " << hit_counter << std::endl;

    return 0;
}

inline void reset(ads_2::type::uintf &i)
{
    i ^= i;
}