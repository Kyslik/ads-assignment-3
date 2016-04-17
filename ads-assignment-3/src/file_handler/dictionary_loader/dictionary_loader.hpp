//
//  dictionary_loader.hpp
//  ads-assignment-3
//
//  Created by Martin Kiesel on 17/04/16.
//  Copyright © 2016 Martin Kiesel. All rights reserved.
//

#ifndef dictionary_loader_hpp
#define dictionary_loader_hpp

#include "ads_2_typedefs.hpp"

namespace ads_2
{
    namespace loader
    {
        class DictionaryLoader
        {
            bool            is_valid_ = false;
            bool            is_sample_ = false;

            type::uintf     length_;
            type::Data      data_,
                            spare_data_;

            void parse(const std::string &filename);

            DictionaryLoader& operator=(const DictionaryLoader&);
            DictionaryLoader(const DictionaryLoader&);

        public:
            DictionaryLoader(const std::string &filename,
                             const type::uintf &lines) :
                                        length_(lines)
            {
                parse(filename);
            }

            inline bool         isValid()            const { return is_valid_; }
            inline type::uintf  getLength()          const { return length_; }
            inline void         freeSpareData()            { spare_data_.clear(); }

            inline const type::Data & getData()      const { return data_;}
            inline const type::Data & getSpareData() const { return spare_data_; }
        };

    }
}


#endif /* dictionary_loader_hpp */
