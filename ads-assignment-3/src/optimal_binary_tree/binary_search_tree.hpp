//
//  binary_search_tree.hpp
//  ads-assignment-3
//
//  Created by Martin Kiesel on 09/04/16.
//  Copyright © 2016 Martin Kiesel. All rights reserved.
//

#ifndef binary_search_tree_hpp
#define binary_search_tree_hpp

#include "file_parser.hpp"
#include "node.hpp"

namespace ads_2
{
    namespace binary_tree
    {
        class BinarySearchTree
        {
            parser::FileParser *parser_;
            Node *root_;

            const type::uintf matrix_size_;
            type::Matrix roots_;
            type::uintf node_count_ = 0;

            const type::Pairs constructPairs();
            Node *construct(const type::uintf i,
                            const type::uintf j,
                            const type::Pairs &pairs);
            void postorder(Node* p, int indent = 0);
            void calculateOptimal(const type::Pairs &pairs);

            BinarySearchTree& operator=(const BinarySearchTree&);
            BinarySearchTree(const BinarySearchTree&);

        public:
            BinarySearchTree(parser::FileParser *parser) :
                    parser_(parser),
                    matrix_size_(parser_->getLength()),
                    roots_(matrix_size_ + 1,
                           type::Dimension(matrix_size_ + 1, 0))
            {};
            void compute();
            inline type::uintf getNodeCount() const {return node_count_;}
            bool search(const std::string &search_term);
        };
    }
}

#endif /* binary_search_tree_hpp */