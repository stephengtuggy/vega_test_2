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

#ifndef VEGA_TEST_2_UNIT_HPP
#define VEGA_TEST_2_UNIT_HPP

#include <string>
#include <cstdint>
#include <iostream>
#include <utility>
#include <boost/container/map.hpp>
#include <boost/smart_ptr/intrusive_ref_counter.hpp>
#include <boost/smart_ptr/intrusive_ptr.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>

namespace VegaTest2 {

//    class UnitCollection;
    class Flightgroup;

    class Unit : public boost::intrusive_ref_counter<Unit, boost::thread_safe_counter> {
    protected:
        Flightgroup * flightgroup_{};
        std::string flightgroup_name_{};
        int32_t flightgroup_sub_number_{};
        std::string custom_full_name_{};
        boost::container::map<std::string, boost::intrusive_ptr<Unit>> sub_units_{};
        Unit * parent_{};
    public:
        // Default, no-args constructor
        Unit() = default;
        // Many-args constructor
        Unit(Flightgroup * flightgroup, std::string flightgroup_name, int32_t flightgroup_sub_number, std::string custom_full_name)
                : flightgroup_(flightgroup),
                flightgroup_name_(std::move(flightgroup_name)),
                flightgroup_sub_number_(flightgroup_sub_number),
                custom_full_name_(std::move(custom_full_name)) {}
        // Copy constructor -- forbidden
        Unit(Unit const& rhs) = delete;
        // Move constructor
        Unit(Unit&& rhs) = default;
        // Destructor
        virtual ~Unit();    // = default;
        // copy assignment operator -- forbidden
        Unit& operator=(Unit const& rhs) = delete;
        // move assignment operator
        Unit& operator=(Unit&& rhs) = default;
        virtual bool operator<(Unit const& other) const;

        virtual std::string getFgID() const;
        std::string getUnitBaseFgID() const;
    };

} // VegaTest2

#endif //VEGA_TEST_2_UNIT_HPP
