//
//  FileParser.hpp
//  ads-assignment-3
//
//  Created by Martin Kiesel on 09/04/16.
//  Copyright © 2016 Martin Kiesel. All rights reserved.
//

#ifndef FileParser_hpp
#define FileParser_hpp

#include <iostream>
#include <map>

#include "ads_2_typedefs.hpp"

namespace ads_2
{
    namespace parser
    {
        class FileParser
        {
            bool is_valid_ = false;
            type::uintf length_;
            std::string filename_;
            type::Data data_;

            void parse();
        public:
            FileParser() : length_(1000), filename_("dictionary-min.txt")
            {
                parse();
            };
            FileParser(const std::string &name,
                       const type::uintf &lines) :
                                                length_(lines),
                                                filename_(name)
            {
                parse();
            };
            inline bool isValid() const {return is_valid_;}
            inline type::uintf getLength() const {return length_;}
            inline type::Data  getData() const {return data_;}

        };

    }
}

#endif /* FileParser_hpp */
