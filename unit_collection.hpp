//
// Created by stephengt on 9/4/22.
//

#ifndef VEGA_TEST_2_UNIT_COLLECTION_HPP
#define VEGA_TEST_2_UNIT_COLLECTION_HPP

#include <map>
#include <string>
#include <boost/smart_ptr/intrusive_ptr.hpp>
#include "unit.hpp"

namespace VegaTest2 {

    class UnitCollection : public std::map<std::string, boost::intrusive_ptr<Unit>> {

    };

} // VegaTest2

#endif //VEGA_TEST_2_UNIT_COLLECTION_HPP
