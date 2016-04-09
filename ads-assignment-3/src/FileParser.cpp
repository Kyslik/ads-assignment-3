//
//  FileParser.cpp
//  ads-assignment-3
//
//  Created by Martin Kiesel on 09/04/16.
//  Copyright © 2016 Martin Kiesel. All rights reserved.
//

#include "FileParser.hpp"

#include <fstream>

namespace ads_2
{
    namespace parser
    {
        void FileParser::parse()
        {
            std::ifstream file(filename_);
            if (file.fail()) return;

            std::string str;
            std::string word;
            type::uintf probability;

            while (file >> probability >> word && data_.size() != length_)
                data_[word] = probability;
            
            is_valid_ = true;
        }
    }
}