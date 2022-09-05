#include <iostream>
#include <boost/smart_ptr/intrusive_ptr.hpp>
#include <boost/smart_ptr/make_shared.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include "unit.hpp"

boost::shared_ptr<VegaTest2::Unit> theTopLevelUnit() {
    static boost::shared_ptr<VegaTest2::Unit> kTopLevelUnit = boost::make_shared<VegaTest2::Unit>();
    return kTopLevelUnit;
}

int main() {
    std::cout << "Top Level Unit: " << theTopLevelUnit()->getFgID() << std::endl;

    return 0;
}
