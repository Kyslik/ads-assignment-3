//
//  dictionary_loader.cpp
//  ads-assignment-3
//
//  Created by Martin Kiesel on 17/04/16.
//  Copyright © 2016 Martin Kiesel. All rights reserved.
//

#include "dictionary_loader.hpp"

#include <fstream>

namespace ads_2
{
    namespace loader
    {
        void DictionaryLoader::parse(const std::string &filename)
        {
            std::ifstream file(filename);
            if (file.fail()) return;

            std::string word;
            type::uintf probability;

            while (data_.size() != length_ && file >> probability >> word)
                data_.insert(type::DataPair(word, probability));

            while (file >> probability >> word)
            {
                if (data_.count(word)) continue;
                spare_data_.insert(type::DataPair(word, probability));
            }

            length_ = static_cast<type::uintf>(data_.size());
            is_valid_ = true;
        }
    }
}