//
// Created by stephengt on 9/4/22.
//

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
    };

} // VegaTest2

#endif //VEGA_TEST_2_FLIGHTGROUP_HPP
