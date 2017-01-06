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

#include "ast.hpp"

#include <boost/fusion/include/adapt_struct.hpp>

BOOST_FUSION_ADAPT_STRUCT(flatmessage::ast::message,
    (std::string, name)
    (std::vector<flatmessage::ast::attribute>, attributes)
)

BOOST_FUSION_ADAPT_STRUCT(flatmessage::ast::attribute,
    (boost::optional<std::string>, specifier)
    (std::string, type)(std::string, name)
)

BOOST_FUSION_ADAPT_STRUCT(flatmessage::ast::enumeration,
    (std::string, name)
    (std::string, alignment)
    (std::vector<flatmessage::ast::enum_value>, values)
)

BOOST_FUSION_ADAPT_STRUCT(flatmessage::ast::enum_value,
    (std::string, name)
    (int, value)
)