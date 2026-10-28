#include "pybind11.hpp"
void nonlinear_programming_submodule(pybind11::module&);
void nonlinear_programming_module(pybind11::module& module) { nonlinear_programming_submodule(module); }
