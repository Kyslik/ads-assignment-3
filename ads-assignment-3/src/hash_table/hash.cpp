//
//  hash.cpp
//  ads-assignment-3
//
//  Created by Martin Kiesel on 10/04/16.
//  Copyright © 2016 Martin Kiesel. All rights reserved.
//

/* By Paul Hsieh (C) 2004, 2005.  Covered under the Paul Hsieh derivative
 license. See:
 http://www.azillionmonkeys.com/qed/weblicense.html for license details.
 http://www.azillionmonkeys.com/qed/hash.html 
 */

#include <string>
#include "ads_2_typedefs.hpp"

namespace ads_2
{
    namespace hash_table
    {
        using type::uintf;
        using type::uintf16;

        inline uintf16 get16bits (const void * p)
        {
            return *(const uintf16*)p;
        }

        uintf hash(const std::string &str)
        {
            uintf hash = 0, len = static_cast<uintf>(str.length()), tmp;
            int rem;
            if (len <= 0 || str.empty()) return 0;
            const char * data = str.c_str();

            rem = len & 3;
            len >>= 2;

            /* Main loop */
            for (;len > 0; len--)
            {
                hash  += get16bits (data);
                tmp    = (get16bits (data+2) << 11) ^ hash;
                hash   = (hash << 16) ^ tmp;
                data  += 2*sizeof (uintf16);
                hash  += hash >> 11;
            }

            /* Handle end cases */
            switch (rem)
            {
                case 3:	hash += get16bits (data);
                    hash ^= hash << 16;
                    hash ^= data[sizeof (uintf16)] << 18;
                    hash += hash >> 11;
                    break;
                case 2:	hash += get16bits (data);
                    hash ^= hash << 11;
                    hash += hash >> 17;
                    break;
                case 1: hash += *data;
                    hash ^= hash << 10;
                    hash += hash >> 1;
            }
            
            /* Force "avalanching" of final 127 bits */
            hash ^= hash << 3;
            hash += hash >> 5;
            hash ^= hash << 4;
            hash += hash >> 17;
            hash ^= hash << 25;
            hash += hash >> 6;
            
            return hash;
        }
    }
}