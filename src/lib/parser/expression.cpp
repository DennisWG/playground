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

#include "config.hpp"
#include "expression_def.hpp"

namespace flatmessage
{
    namespace parser
    {
        BOOST_SPIRIT_INSTANTIATE(data_type, iterator_type, context_type);
        BOOST_SPIRIT_INSTANTIATE(message_type, iterator_type, context_type);
        BOOST_SPIRIT_INSTANTIATE(enumeration_type, iterator_type, context_type);
        BOOST_SPIRIT_INSTANTIATE(module_decl_type, iterator_type, context_type);
        BOOST_SPIRIT_INSTANTIATE(import_decl_type, iterator_type, context_type);
        BOOST_SPIRIT_INSTANTIATE(protocol_decl_type, iterator_type, context_type);
    }
}