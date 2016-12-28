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

#include <boost/optional.hpp>

#include <string>
#include <vector>

namespace QuickMessage
{
    namespace ast
    {
        struct message
        {
            std::string name;
            std::vector<std::tuple<boost::optional<std::string>, std::string, std::string>> attributes;
        };
    }
}

BOOST_FUSION_ADAPT_STRUCT(QuickMessage::ast::message, name, attributes)