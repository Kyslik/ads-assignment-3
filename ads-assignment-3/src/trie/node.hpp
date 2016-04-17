//
//  node.hpp
//  ads-assignment-3
//
//  Created by Martin Kiesel on 15/04/16.
//  Copyright © 2016 Martin Kiesel. All rights reserved.
//

#ifndef node_hpp
#define node_hpp

#include <string>
#include <map>

namespace ads_2
{
    namespace trie
    {
        struct Node
        {
            bool is_word;
            std::map<std::string, Node> childrens; //Marek Sys can talk about childrens

            Node(bool is_word = bool() ) : is_word(is_word) {}
            Node(bool is_word,
                 std::map<std::string, Node> childrens) :
                    is_word(is_word),
                    childrens(childrens) {}
        };
    }
}

#endif /* node_hpp */
