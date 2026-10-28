#include "pybind11.hpp"
#include "numeric/numeric.hpp"
#include "algebra/vector.hpp"
#include "algebra/matrix.hpp"
#include "geometry/box.hpp"
#include "function/function.hpp"
#include "nonlinear-programming/nonlinear_programming.hpp"
#include "nonlinear-programming/nonlinear_interior_point_method.hpp"
#include "nonlinear-programming/nonlinear_penalty_function_method.hpp"
using namespace Ariadne;

Void export_optimiser_interface(pybind11::module& module)
{
    typedef NonlinearProgrammingSolverInterface::ValidatedNumericType ValidatedNumericType;
    typedef NonlinearProgrammingSolverInterface::ExactVectorType ExactVectorType;

    pybind11::class_<NonlinearProgrammingSolverInterface> optimiser_interface_class(module,"NonlinearProgrammingSolverInterface");
    optimiser_interface_class.def("minimise", (Vector<ValidatedNumericType>(NonlinearProgrammingSolverInterface::*)(ValidatedScalarMultivariateFunction, ExactBoxType, ValidatedVectorMultivariateFunction, ExactBoxType)const) &NonlinearProgrammingSolverInterface::minimise);
    optimiser_interface_class.def("minimise", (Vector<ValidatedNumericType>(NonlinearProgrammingSolverInterface::*)(ValidatedScalarMultivariateFunction, ExactBoxType, ValidatedVectorMultivariateFunction, ValidatedVectorMultivariateFunction)const) &NonlinearProgrammingSolverInterface::minimise);
    optimiser_interface_class.def("feasible", (ValidatedKleenean(NonlinearProgrammingSolverInterface::*)(ExactBoxType, ValidatedVectorMultivariateFunction, ExactBoxType)const) &NonlinearProgrammingSolverInterface::feasible);
    optimiser_interface_class.def("feasible", (ValidatedKleenean(NonlinearProgrammingSolverInterface::*)(ExactBoxType, ValidatedVectorMultivariateFunction, ValidatedVectorMultivariateFunction)const) &NonlinearProgrammingSolverInterface::feasible);
    optimiser_interface_class.def("almost_feasible_point", (Bool(NonlinearProgrammingSolverInterface::*)(ExactBoxType, ValidatedVectorMultivariateFunction, ExactBoxType,FloatDPApproximationVector, FloatDPApproximation)const) &NonlinearProgrammingSolverInterface::almost_feasible_point);
    optimiser_interface_class.def("is_feasible_point", (Bool(NonlinearProgrammingSolverInterface::*)(ExactBoxType, ValidatedVectorMultivariateFunction, ExactBoxType,FloatDPVector)const) &NonlinearProgrammingSolverInterface::is_feasible_point);
    optimiser_interface_class.def("validate_feasibility", (Bool(NonlinearProgrammingSolverInterface::*)(ExactBoxType, ValidatedVectorMultivariateFunction, ExactBoxType,ExactVectorType)const) &NonlinearProgrammingSolverInterface::validate_feasibility);
    optimiser_interface_class.def("validate_feasibility", (Bool(NonlinearProgrammingSolverInterface::*)(ExactBoxType, ValidatedVectorMultivariateFunction, ExactBoxType,ExactVectorType,ExactVectorType)const) &NonlinearProgrammingSolverInterface::validate_feasibility);
    optimiser_interface_class.def("validate_infeasibility", (Bool(NonlinearProgrammingSolverInterface::*)(ExactBoxType, ValidatedVectorMultivariateFunction, ExactBoxType,ExactVectorType,ExactVectorType)const) &NonlinearProgrammingSolverInterface::validate_infeasibility);
    optimiser_interface_class.def("contains_feasible_point", (ValidatedKleenean(NonlinearProgrammingSolverInterface::*)(ExactBoxType, ValidatedVectorMultivariateFunction, ExactBoxType,FloatDPBoundsVector)const) &NonlinearProgrammingSolverInterface::contains_feasible_point);
    optimiser_interface_class.def("is_infeasibility_certificate", (Bool(NonlinearProgrammingSolverInterface::*)(ExactBoxType, ValidatedVectorMultivariateFunction, ExactBoxType,ExactVectorType)const) &NonlinearProgrammingSolverInterface::is_infeasibility_certificate);
    //NOTE: Not in C++ API
    //optimiser_interface_class.def("__str__", &__cstr__<NonlinearProgrammingSolverInterface>);
}

Void export_interior_point_solvers(pybind11::module& module)
{
    pybind11::class_<NonlinearInfeasibleInteriorPointSolver,NonlinearProgrammingSolverInterface> nonlinear_infeasible_interior_point_solver_class(module,"NonlinearInfeasibleInteriorPointSolver");
    nonlinear_infeasible_interior_point_solver_class.def(pybind11::init<>());

    pybind11::class_<NonlinearInteriorPointSolver,NonlinearProgrammingSolverInterface> nonlinear_interior_point_solver_class(module,"NonlinearInteriorPointSolver");
    nonlinear_interior_point_solver_class.def(pybind11::init<>());
}


void nonlinear_programming_submodule(pybind11::module& module) {
    export_optimiser_interface(module);
    export_interior_point_solvers(module);
    pybind11::class_<NonlinearPenaltyFunctionSolver,NonlinearProgrammingSolverInterface>(module,"NonlinearPenaltyFunctionSolver").def(pybind11::init<>());
    pybind11::class_<IntervalNonlinearInteriorPointSolver,NonlinearInteriorPointSolver>(module,"IntervalNonlinearInteriorPointSolver").def(pybind11::init<>());
    pybind11::class_<ApproximateNonlinearInteriorPointSolver,NonlinearInteriorPointSolver>(module,"ApproximateNonlinearInteriorPointSolver").def(pybind11::init<>());
}
