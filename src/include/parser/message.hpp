/*
Copyright (c) 2016 Dennis Werner Garske (DWG)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#pragma once

#include <boost/config/warning_disable.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/include/io.hpp>
#include <boost/fusion/include/std_pair.hpp>
#include <boost/fusion/include/std_tuple.hpp>

#include <string>
#include <vector>

#include "../ast/message.hpp"
#include "common.hpp"

namespace QuickMessage
{
    namespace parser
    {
        namespace x3 = boost::spirit::x3;
        namespace ascii = boost::spirit::x3::ascii;

        using x3::lit;
        using x3::lexeme;
        using x3::omit;
        using ascii::char_;
        using ascii::space;
        using x3::string;

        // A set of rules for an attribute
        // TODO: give this one a better name than "rule"
        auto const rules = x3::rule<class rules, std::string>() = string("optional") | string("repeated");

        // An optional rule, followed by a name, followed by a name, followed by a semicolon
        // Valid example: optional Color eyeColor;
        // Invalid example: optional eyeColor;
        auto const attribute
            = x3::rule<class attribute, std::tuple<boost::optional<std::string>, std::string, std::string>>()
            = lexeme[-(rules >> omit[+space]) >> name >> omit[+space] >> name >> ';'];

        // The structure of a message.
        // Example: message Ping { int64 time; int32 latency; }
        auto const message = x3::rule<class message, ast::message>()
            = lit("message") >> name >> '{' >> +attribute >> '}';

        BOOST_SPIRIT_DEFINE(message);
    }
}