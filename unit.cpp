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

#include <iostream>
#include <boost/format.hpp>
#include "unit.hpp"

namespace VegaTest2 {
    bool Unit::operator<(const Unit &other) const {
        return (getFgID() < other.getFgID());
    }

    std::string Unit::getFgID() const {
        // default implementation
        return getUnitBaseFgID();
    }

    Unit::~Unit() {
        std::cout << boost::format("Destructor running for Unit %1%") % getUnitBaseFgID() << std::endl;
    }

    std::string Unit::getUnitBaseFgID() const {
        if (!custom_full_name_.empty()) {
            return custom_full_name_;
        } else {
            return (boost::format("%1$s-%2$5d") % flightgroup_name_ % flightgroup_sub_number_).str();
        }
    }
} // VegaTest2
