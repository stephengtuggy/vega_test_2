// Copyright (c) 2022 Stephen G. Tuggy
//
// This file is part of Vega Test 2.
//
// Vega Test 2 is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Vega Test 2 is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Vega Test 2. If not, see <https://www.gnu.org/licenses/>.

#ifndef VEGA_TEST_2_FLIGHTGROUP_HPP
#define VEGA_TEST_2_FLIGHTGROUP_HPP

#include <string>
#include <boost/smart_ptr/intrusive_ptr.hpp>
//#include <boost/smart_ptr/shared_ptr.hpp>
#include "unit.hpp"
//#include "unit_collection.hpp"

namespace VegaTest2 {

    class Flightgroup {
    protected:
        std::string name_{};
        boost::container::map<std::string, boost::intrusive_ptr<Unit>> members_{};
        boost::intrusive_ptr<Unit> leader_{};
    public:
        Flightgroup();
        explicit Flightgroup(std::string name);
        Flightgroup(Flightgroup const & rhs) = delete;
        Flightgroup(Flightgroup&& rhs) noexcept;
        ~Flightgroup();
        Flightgroup& operator=(Flightgroup const& rhs) = delete;
        Flightgroup& operator=(Flightgroup && rhs) noexcept;
        std::string getName();
        void setName(std::string new_name);
        boost::intrusive_ptr<Unit> getLeader();
        void setLeader(boost::intrusive_ptr<Unit> new_leader);
        boost::container::map<std::string, boost::intrusive_ptr<Unit>> const & getMembers();
    };

} // VegaTest2

#endif //VEGA_TEST_2_FLIGHTGROUP_HPP
