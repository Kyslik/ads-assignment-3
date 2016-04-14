//
//  ads_2_typedefs.hpp
//  ads-assignment-3
//
//  Created by Martin Kiesel on 09/04/16.
//  Copyright © 2016 Martin Kiesel. All rights reserved.
//

#ifndef ads_2_typedefs_h
#define ads_2_typedefs_h

#include <map>
#include <vector>
#include <list>
#include <string>

namespace ads_2
{
    namespace type
    {
        typedef uint_fast32_t uintf;
        typedef uint_fast16_t uintf16;
        
        typedef std::map<std::string, const uintf> Data;

        typedef std::pair<std::string, uintf> DataPair;
        typedef std::vector<DataPair> Pairs;

        typedef std::vector<uintf> Dimension;
        typedef std::vector<Dimension> Matrix;

        typedef std::list<std::string> KegList;
        typedef std::vector<KegList *> KegDimension;

        typedef std::vector<const std::string> SampleData;
    }
}

#endif /* ads_2_typedefs_h */
