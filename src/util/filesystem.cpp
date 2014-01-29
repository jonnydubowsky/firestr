/*
 * Copyright (C) 2014  Maxim Noah Khailo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "util/filesystem.hpp"

#include "util/dbc.hpp"

#include <boost/filesystem.hpp>

namespace bf = boost::filesystem;

namespace fire
{
    namespace util
    {
            bool create_directory(const std::string& dir)
            {
                REQUIRE_FALSE(dir.empty());

                if(bf::exists(dir)) return true;

                bf::create_directories(dir);
                return bf::exists(dir);
            }

            bool delete_directory(const std::string& dir)
            {
                REQUIRE_FALSE(dir.empty());

                if(!bf::exists(dir)) return false;

                bf::remove_all(dir);
                return !bf::exists(dir);
            }
    }
}

