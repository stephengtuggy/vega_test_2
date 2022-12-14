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
#include <utility>
#include "flightgroup.hpp"

namespace VegaTest2 {
    Flightgroup::Flightgroup() {
        std::cout << "Flightgroup no-args constructor called" << std::endl;
    }

    Flightgroup::Flightgroup(std::string name) : name_(std::move(name)) {
        std::cout << "Flightgroup single-arg constructor called (name)" << std::endl;
    }

    Flightgroup::Flightgroup(Flightgroup &&rhs) noexcept {
        std::cout << "Flightgroup move constructor called" << std::endl;
        name_ = std::move(rhs.name_);
        members_ = std::move(rhs.members_);
        leader_ = std::move(rhs.leader_);
    }

    Flightgroup::~Flightgroup() {
        std::cout << "Flightgroup destructor called" << std::endl;
        members_.clear();
    }

    Flightgroup &Flightgroup::operator=(Flightgroup &&rhs) noexcept {
        std::cout << "Flightgroup Move assignment operator called" << std::endl;
        name_ = std::move(rhs.name_);
        members_ = std::move(rhs.members_);
        leader_ = std::move(rhs.leader_);
        return *this;
    }

    std::string Flightgroup::getName() {
        return name_;
    }

    void Flightgroup::setName(std::string new_name) {
        name_ = std::move(new_name);
    }

    boost::intrusive_ptr<Unit> Flightgroup::getLeader() {
        return leader_;
    }

    void Flightgroup::setLeader(boost::intrusive_ptr<Unit> new_leader) {
        leader_ = std::move(new_leader);
    }

    boost::container::map<std::string, boost::intrusive_ptr<Unit>> const &Flightgroup::getMembers() {
        return members_;
    }
} // VegaTest2
