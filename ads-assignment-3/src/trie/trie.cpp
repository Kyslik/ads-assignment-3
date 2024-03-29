//
//  trie.cpp
//  ads-assignment-3
//
//  Created by Martin Kiesel on 15/04/16.
//  Copyright © 2016 Martin Kiesel. All rights reserved.
//

#include "trie.hpp"

namespace ads_2
{
    namespace trie
    {
        void Trie::construct()
        {
            for(const auto &word : loader_->getData())
                insert(parent, word.first);
        }

        type::uintf Trie::prefix(const std::string &prefix,
                                 const std::string &word)
        {
            auto res = std::mismatch(prefix.begin(), prefix.end(), word.begin());
            return static_cast<type::uintf>((res.first - prefix.begin()) % word.length());
        }

        void Trie::insert(Node &node, const std::string &word)
        {
            for (auto &kid : node.childrens)
            {
                if (kid.first == word)
                {
                    kid.second.is_word = true;
                    return;
                }

                if (kid.first.size() == word.size())
                {
                    type::uintf pos = prefix(kid.first, word);
                    if (pos == 0) continue;

                    std::string pre_word = word.substr(0, pos);
                    std::string sub_word = word.substr(pos);
                    std::string sub_kid = kid.first.substr(pos);

                    insert(node.childrens[pre_word], sub_word);
                    node.childrens[pre_word].childrens[sub_kid] = Node(kid.second.is_word, node.childrens[kid.first].childrens);
                    node.childrens[pre_word].is_word = false;
                    node.childrens.erase(kid.first);
                    return;
                }

                if (kid.first.size() < word.size())
                {
                    // kid may be prefix of word
                    type::uintf pos = prefix(kid.first, word);
                    if (pos != 0)
                    {
                        std::string sub_word = word.substr(pos);
                        if (pos == kid.first.size())
                            insert(kid.second, sub_word);
                        else
                        {
                            std::string pre_word = word.substr(0, pos);
                            std::string sub_kid = kid.first.substr(pos);

                            insert(node.childrens[pre_word], sub_word);
                            node.childrens[pre_word].childrens[sub_kid] = Node(kid.second.is_word, node.childrens[kid.first].childrens);
                            node.childrens[pre_word].is_word = false;
                            node.childrens.erase(kid.first);
                        }
                        return;
                    }
                    continue;
                }

                if (kid.first.size() > word.size())
                {
                    type::uintf pos = prefix(word, kid.first);
                    if (pos != 0)
                    {
                        std::string sub_kid = kid.first.substr(pos);
                        if (pos == word.size())
                        {
                            insert(node.childrens[word], sub_kid);
                            node.childrens[word].childrens[sub_kid] = Node(kid.second.is_word, node.childrens[kid.first].childrens);
                            node.childrens[word].is_word = false;
                            node.childrens.erase(kid.first);
                        }
                        else
                        {
                            std::string pre_kid = kid.first.substr(0, pos);
                            std::string sub_word = word.substr(pos);

                            insert(node.childrens[pre_kid], sub_word);
                            node.childrens[pre_kid].childrens[sub_kid] = Node(kid.second.is_word, node.childrens[kid.first].childrens);
                            node.childrens[pre_kid].is_word = false;
                            node.childrens.erase(kid.first);
                        }
                        return;
                    }
                    continue;
                }
            }
            node.childrens[word] = Node(true);
        }

        bool Trie::search(const Node &node, const std::string &word)
        {
            for (const auto &kid : node.childrens)
            {
                if (kid.first == word)
                    return kid.second.is_word;

                if (kid.first.size() == word.size())
                {
                    type::uintf pos = prefix(kid.first, word);
                    if (pos != 0 && pos == kid.first.size())
                        return search(kid.second, word.substr(pos));
                    continue;
                }

                if (kid.first.size() < word.size())
                {
                    type::uintf pos = prefix(kid.first, word);
                    if (pos != 0 && pos == kid.first.size())
                        return search(kid.second, word.substr(pos));
                    continue;
                }

                if (kid.first.size() > word.size())
                {
                    type::uintf pos = prefix(word, kid.first);
                    if (pos != 0)
                        return search(kid.second, kid.first.substr(pos));
                    continue;
                }
            }
            return false;
        }
    }
}