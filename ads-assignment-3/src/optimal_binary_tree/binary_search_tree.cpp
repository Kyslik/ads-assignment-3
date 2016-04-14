//
//  binary_search_tree.cpp
//  ads-assignment-3
//
//  Created by Martin Kiesel on 09/04/16.
//  Copyright © 2016 Martin Kiesel. All rights reserved.
//

#include "binary_search_tree.hpp"
#include <queue>

namespace ads_2
{
    namespace binary_tree
    {
        using type::uintf;
        using type::Pairs;
        using type::Dimension;

        void BinarySearchTree::compute()
        {
            const Pairs pairs = constructPairs();
            const Dimension improbabilities = constructImprobabilities();
            parser_->freeSpareData();
            calculateOptimal(pairs, improbabilities);
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

        const Dimension BinarySearchTree::constructImprobabilities()
        {
            const uintf length = parser_->getLength();
            Dimension improbabilities(length + 1, 0);

            for (const auto &spare : parser_->getSpareData())
            {
                if (spare.first < parser_->getData().begin()->first)
                    improbabilities[0] += spare.second;
                else
                    break;
            }
            
            for(auto it = parser_->getSpareData().rbegin();
                it != parser_->getSpareData().rend();
                it++)
            {

                if (it->first > parser_->getData().rbegin()->first)
                    improbabilities[length] += it->second;
                else
                    break;
            }

            {
                uintf i = 1;
                auto previous_it = parser_->getData().begin();
                auto previous_spare = parser_->getSpareData().begin();

                for (auto it = std::next(previous_it);
                     it != parser_->getData().end();
                     it++)
                {
//                    for (const auto &spare : parser_->getSpareData())
//                    {
//                        if (previous_it->first > spare.first) continue;
//                        if (previous_it->first < spare.first && spare.first < it->first)
//                            improbabilities[i] += spare.second;
//                        if (spare.first > it->first) break;
//                    }

                    for (auto it_s = previous_spare;
                         it_s != parser_->getSpareData().end();
                         it_s++)
                    {
                        if (previous_it->first < it_s->first && it_s->first < it->first) {
                            improbabilities[i] += it_s->second;
                            previous_spare = it_s;
                        }
                        if (it_s->first > it->first) break;
                    }

                    i++;
                    previous_it = it;
                }
            }

            return improbabilities;
        }

        uintf BinarySearchTree::countNodes() const
        {
            if (root_ == nullptr) return 0;
            std::queue<Node*> q;
            type::uintf count = 1;
            q.push(root_);

            while (!q.empty())
            {
                Node* n = q.front();
                q.pop();
                count++;
                if (n->left != nullptr)
                    q.push(n->left);
                if (n->right != nullptr)
                    q.push(n->right);
            }

            return count;
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

        void BinarySearchTree::calculateOptimal(const Pairs &pairs,
                                                const Dimension &improbabilities)
        {
            using type::Matrix;

            Matrix costs(matrix_size_ + 1,
                               Dimension(matrix_size_ + 1 , 0));
            Matrix weights(matrix_size_ + 1,
                                 Dimension(matrix_size_ + 1, 0));

            for(uintf i = 0; i <= matrix_size_; i++)
            {
                weights[i][i] = improbabilities[i];
                for(uintf j = i + 1; j <= matrix_size_; j++)
                    weights[i][j] = weights[i][j - 1] +
                                    pairs[j].second +
                                    improbabilities[j];
            }

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
    }
}