//
//  hash_table.hpp
//  ads-assignment-3
//
//  Created by Martin Kiesel on 14/04/16.
//  Copyright © 2016 Martin Kiesel. All rights reserved.
//

#ifndef hash_table_hpp
#define hash_table_hpp

#include "dictionary_loader.hpp"

namespace ads_2
{
    namespace hash_table
    {
        class HashTable
        {
            loader::DictionaryLoader *loader_;
            type::KegDimension table_;
            const type::uintf table_size_;
            
            void insert(const std::string &key);

            HashTable& operator=(const HashTable&);
            HashTable(const HashTable&);
        public:
            HashTable(loader::DictionaryLoader *loader) :
                loader_(loader),
                table_size_(loader_->getLength())
            {
                table_.resize(table_size_);

                for (auto &item : table_)
                    item = new type::KegList();

                for (const auto &item : loader_->getData())
                    insert(item.first);
                
                sortLists();
            }

            void sortLists();
            bool search(const std::string &key) const;

            ~HashTable()
            {
                for (auto &item : table_)
                    delete item;
            }
        };
    }
}

#endif /* hash_table_hpp */
