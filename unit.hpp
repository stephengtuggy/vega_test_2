//
// Created by stephengt on 9/3/22.
//

#ifndef VEGA_TEST_2_UNIT_HPP
#define VEGA_TEST_2_UNIT_HPP

#include <string>
#include <cstdint>
#include <iostream>
#include <utility>
#include <boost/smart_ptr/intrusive_ref_counter.hpp>
#include <boost/smart_ptr/intrusive_ptr.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>

namespace VegaTest2 {

    class UnitCollection;
    class Flightgroup;

    class Unit : boost::intrusive_ref_counter<Unit, boost::thread_safe_counter> {
    protected:
        Flightgroup * flightgroup_{};
        std::string flightgroup_name_{};
        int32_t flightgroup_sub_number_{};
        std::string custom_full_name_{};
        boost::shared_ptr<UnitCollection> sub_units_{};
    public:
        // Default, no-args constructor
        Unit() = default;
        // Many-args constructor
        Unit(Flightgroup * flightgroup, std::string flightgroup_name, int32_t flightgroup_sub_number, std::string custom_full_name)
                : flightgroup_(flightgroup),
                flightgroup_name_(std::move(flightgroup_name)),
                flightgroup_sub_number_(flightgroup_sub_number),
                custom_full_name_(std::move(custom_full_name)) {}
        // Copy constructor
        Unit(Unit const& rhs) = default;
        // Move constructor
        Unit(Unit&& rhs) = default;
        // Destructor
        virtual ~Unit() = default;
        Unit& operator=(Unit const& rhs) = default;
        virtual bool operator<(Unit const& other) const;

        virtual std::string getFgID() const;
    };

} // VegaTest2

#endif //VEGA_TEST_2_UNIT_HPP
