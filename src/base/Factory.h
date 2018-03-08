// Copyright (c) 2015-2018 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#ifndef __FACTORY_H__
#define __FACTORY_H__

#include <map>
#include <string>
#include <functional>

#include "Singleton.hpp"

//! Factory template class
template <typename T>
class Factory : public Singleton<Factory<T> >
{
public:
    typedef std::function<T * (void)> Creator;

    Factory()
    {
    }

    void registerObject(const std::string &name, Creator func)
    {
        m_map[name] = func;
    }

    std::shared_ptr<T> create(const std::string &name)
    {
        auto it = m_map.find(name);
        if (it == m_map.end())
            return nullptr;

        return std::shared_ptr<T>(it->second());
    }

private:
    std::map<std::string, Creator> m_map;
};

#endif
