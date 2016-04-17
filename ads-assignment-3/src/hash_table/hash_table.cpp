//
//  hash_table.cpp
//  ads-assignment-3
//
//  Created by Martin Kiesel on 14/04/16.
//  Copyright © 2016 Martin Kiesel. All rights reserved.
//

#include "hash_table.hpp"

#include "hash.cpp"

namespace ads_2
{
    namespace hash_table
    {
        void HashTable::insert(const std::string &key)
        {
            type::uintf hash = generateHash(key) % table_size_;
            table_[hash]->push_back(key);
        }

        bool HashTable::search(const std::string &key) const
        {
            type::uintf hash = generateHash(key) % table_size_;
            type::uintf list_size = static_cast<type::uintf>(table_[hash]->size());

            switch (list_size)
            {
                case 0:
                    return false;
                case 1:
                    return table_[hash]->front() == key;
                case 2:
                    return (table_[hash]->front() == key
                            || table_[hash]->back() == key);
                default:
                    auto end_it = table_[hash]->end();
                    return std::find(table_[hash]->begin(), end_it, key) != end_it;
            }
        }

        void HashTable::sortLists()
        {
            for (auto &list : table_)
            {
                if (list->empty() || list->size() == 1) continue;
                list->sort();
            }
        }
    }
}