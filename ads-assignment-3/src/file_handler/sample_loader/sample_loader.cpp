//
//  sample_loader.cpp
//  ads-assignment-3
//
//  Created by Martin Kiesel on 17/04/16.
//  Copyright © 2016 Martin Kiesel. All rights reserved.
//

#include "sample_loader.hpp"

#include <fstream>

namespace ads_2
{
    namespace loader
    {
        void SampleLoader::parse(const std::string &filename)
        {
            std::ifstream file(filename);
            if (file.fail()) return;

            std::string word;

            while (file >> word)
                data_.push_back(word);
            is_valid_ = true;
        }
    }
}