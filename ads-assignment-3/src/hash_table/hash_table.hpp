//
//  hash_table.hpp
//  ads-assignment-3
//
//  Created by Martin Kiesel on 14/04/16.
//  Copyright © 2016 Martin Kiesel. All rights reserved.
//

#ifndef hash_table_hpp
#define hash_table_hpp

#include "file_parser.hpp"

namespace ads_2
{
    namespace hash_table
    {
        class HashTable
        {
            parser::FileParser *parser_;
            type::KegDimension table_;
            const type::uintf table_size_;
            
            void insert(const std::string &key);

            HashTable& operator=(const HashTable&);
            HashTable(const HashTable&);
        public:
            HashTable(parser::FileParser *parser) :
                parser_(parser),
                table_size_(parser_->getLength())
            {
                table_.resize(table_size_);

                for (auto &item : table_)
                    item = new type::KegList();

                for (const auto &item : parser_->getData())
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
