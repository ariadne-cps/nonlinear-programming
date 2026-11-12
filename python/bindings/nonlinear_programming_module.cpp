/***************************************************************************
 *            python/bindings/nonlinear_programming_module.cpp
 *
 *  Copyright  2026  Luca Geretti
 *
 ****************************************************************************/

/*
 *  This file is part of Ariadne Nonlinear Programming.
 *
 *  Ariadne Nonlinear Programming is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Ariadne Nonlinear Programming is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Ariadne Nonlinear Programming. If not, see <https://www.gnu.org/licenses/>.
 */

/** @file python/bindings/nonlinear_programming_module.cpp
 *  @brief Register the nonlinear programming Python bindings.
 */

#include "pybind11.hpp"
void nonlinear_programming_submodule(pybind11::module&);
void nonlinear_programming_module(pybind11::module& module) { nonlinear_programming_submodule(module); }
