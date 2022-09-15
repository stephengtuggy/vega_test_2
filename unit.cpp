//
// Created by stephengt on 9/3/22.
//

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
