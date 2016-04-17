//
//  file_parser.hpp
//  ads-assignment-3
//
//  Created by Martin Kiesel on 09/04/16.
//  Copyright © 2016 Martin Kiesel. All rights reserved.
//

#ifndef file_parser_hpp
#define file_parser_hpp

#include <iostream>
#include <map>

#include "ads_2_typedefs.hpp"

namespace ads_2
{
    namespace parser
    {
        class FileParser
        {
            bool                is_valid_ = false;
            bool                is_sample_ = false;
            
            type::uintf         length_;
            type::Data          data_,
                                spare_data_;
            type::SampleData    sample_data_;

            void parse(const std::string &filename);

            FileParser& operator=(const FileParser&);
            FileParser(const FileParser&);

        public:
            FileParser(const std::string &filename = "dictionary-min.txt") :
                                                            length_(1000)
            {
                parse(filename);
            }
            FileParser(const std::string &filename, const type::uintf &lines) :
                                                            length_(lines)
            {
                parse(filename);
            }
            FileParser(const std::string &filename, bool is_sample) :
                                                            is_sample_(is_sample)
            {
                parse(filename);
            }
            
            inline bool         isValid()            const {return is_valid_;}
            inline type::uintf getLength()           const {return length_;}
            inline void         freeSpareData()            {spare_data_.clear();}
            
            inline const type::Data & getData()      const {return data_;}
            inline const type::Data & getSpareData() const {return spare_data_;}
            inline const type::SampleData & getSampleData() const {return sample_data_;}
        };

    }
}

#endif /* file_parser_hpp */
