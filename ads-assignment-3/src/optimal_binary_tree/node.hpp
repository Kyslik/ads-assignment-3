//
//  node.hpp
//  ads-assignment-3
//
//  Created by Martin Kiesel on 09/04/16.
//  Copyright © 2016 Martin Kiesel. All rights reserved.
//

#ifndef node_h
#define node_h

namespace ads_2
{
    namespace binary_tree
    {
        struct Node
        {
            std::string key = "";
            Node *left, *right;
        };
    }
}

#endif /* node_h */