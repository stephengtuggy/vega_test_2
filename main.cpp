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
#include <boost/smart_ptr/intrusive_ptr.hpp>
//#include <boost/smart_ptr/make_shared.hpp>
//#include <boost/smart_ptr/shared_ptr.hpp>
#include "unit.hpp"
#include "flightgroup.hpp"

boost::intrusive_ptr<VegaTest2::Unit> theTopLevelUnit() {
    static boost::intrusive_ptr<VegaTest2::Unit> kTopLevelUnit = new VegaTest2::Unit();
    return kTopLevelUnit;
}

int main() {
    std::cout << "Top Level Unit: " << theTopLevelUnit()->getFgID() << std::endl;

    VegaTest2::Flightgroup * flightgroup = new VegaTest2::Flightgroup("Shlimazel");
    flightgroup->setLeader(theTopLevelUnit());

    std::cout << "Top Level Unit after adding to Flightgroup: " << theTopLevelUnit()->getFgID() << std::endl;

    return 0;
}
