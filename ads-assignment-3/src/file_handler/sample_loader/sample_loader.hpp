//
//  sample_loader.hpp
//  ads-assignment-3
//
//  Created by Martin Kiesel on 17/04/16.
//  Copyright © 2016 Martin Kiesel. All rights reserved.
//

#ifndef sample_loader_hpp
#define sample_loader_hpp

#include "ads_2_typedefs.hpp"

namespace ads_2
{
    namespace loader
    {
        class SampleLoader
        {
            bool                is_valid_ = false;
            type::SampleData    data_;

            void parse(const std::string &filename);

            SampleLoader& operator=(const SampleLoader&);
            SampleLoader(const SampleLoader&);

        public:
            SampleLoader(const std::string &filename)
            {
                parse(filename);
            }

            inline bool         isValid()             const { return is_valid_; }
            inline const type::SampleData & getData() const { return data_; }
        };

    }
}

#endif /* sample_loader_hpp */