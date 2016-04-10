//
//  binary_search_tree.cpp
//  ads-assignment-3
//
//  Created by Martin Kiesel on 09/04/16.
//  Copyright © 2016 Martin Kiesel. All rights reserved.
//

#include "binary_search_tree.hpp"

namespace ads_2
{
    namespace binary_tree
    {
        using type::uintf;
        using type::Pairs;

        void BinarySearchTree::compute()
        {
            const Pairs pairs = constructPairs();
            calculateOptimal(pairs);
            root_ = construct(0, matrix_size_, pairs);
        }

        const Pairs BinarySearchTree::constructPairs()
        {
            Pairs pairs(matrix_size_ + 1);
            uintf i = 1;

            for (const auto &pair : parser_->getData())
            {
                pairs[i] = pair;
                i++;
            }
            return pairs;
        }

        bool BinarySearchTree::search(const std::string &search_term)
        {
            Node *it;
            it = root_;

            while (true)
                if (it == nullptr)
                    return false;
                else if (search_term == it->key)
                    return true;
                else if (search_term < it->key)
                {
                    it = it->left;
                    continue;
                }
                else
                    it = it->right;
        }

        Node *BinarySearchTree::construct(const uintf i,
                                          const uintf j,
                                          const Pairs &pairs)
        {
            Node *node;
            if (i == j) return nullptr;

            node = new Node;
            node->key = pairs[roots_[i][j]].first;
            node->left = construct(i, roots_[i][j] - 1, pairs);
            node->right = construct(roots_[i][j], j, pairs);
            node_count_++;

            return node;
        }

        void BinarySearchTree::calculateOptimal(const Pairs &pairs)
        {
            using type::Matrix;
            using type::Dimension;

            Matrix costs(matrix_size_ + 1,
                               Dimension(matrix_size_ + 1 , 0));
            Matrix weights(matrix_size_ + 1,
                                 Dimension(matrix_size_ + 1, 0));

            for(uintf i = 0; i <= matrix_size_; i++)
                for(uintf j = i + 1; j <= matrix_size_; j++)
                    weights[i][j] = weights[i][j - 1] + pairs[j].second;

            for(uintf i = 0; i < matrix_size_; i++)
            {
                uintf j = i + 1;
                costs[i][j] = costs[i][i] + costs[j][j] + weights[i][j];
                roots_[i][j] = j;
            }

            for(uintf l = 2; l <= matrix_size_; l++)
            {
                for(uintf i = 0; i <= matrix_size_ - l; i++)
                {
                    uintf j = i + l;
                    uintf m = roots_[i][j-1];
                    uintf min = costs[i][m-1] + costs[m][j];

                    for(uintf k = m + 1; k <= roots_[i+1][j]; k++)
                    {
                        uintf x = costs[i][k-1] + costs[k][j];
                        if(x >= min) continue;
                        m = k;
                        min = x;
                    }

                    costs[i][j] = weights[i][j] + min;
                    roots_[i][j] = m;
                }
            }
        }
    }
}