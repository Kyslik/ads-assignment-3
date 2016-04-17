//
//  trie.hpp
//  ads-assignment-3
//
//  Created by Martin Kiesel on 15/04/16.
//  Copyright © 2016 Martin Kiesel. All rights reserved.
//

#ifndef trie_hpp
#define trie_hpp

#include "file_parser.hpp"
#include "node.hpp"

namespace ads_2
{
    namespace trie
    {
        class Trie
        {
            parser::FileParser *parser_;
            Node parent;
            void construct();
            void insert(Node &node,
                        const std::string &word);
            type::uintf prefix(const std::string &prefix,
                                     const std::string &word);
            bool search(const Node &node, const std::string &word);

            Trie& operator=(const Trie&);
            Trie(const Trie&);
        public:
            Trie(parser::FileParser *parser) :
                                    parser_(parser) { construct(); };
            inline bool search(const std::string &word)
            {
                return search(parent, word);
            }

        };
    }
}

#endif /* trie_hpp */
