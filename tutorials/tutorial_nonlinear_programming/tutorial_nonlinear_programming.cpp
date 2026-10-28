#include <iostream>
#include <string>
#include "ariadne-nonlinear-programming.hpp"
using namespace Ariadne;
using std::cout;
namespace {
void section(const std::string& title) { cout << "\n== " << title << " ==\n"; }
template<class T> void show(const std::string& label, const T& value) { cout << label << ": " << value << "\n"; }
}
int main() {
    section("Nonlinear constrained optimisation");

    // Minimise the squared distance from the target (5/8,3/8) over
    // [0,1]^2, while requiring x+y to stay in the non-degenerate band
    // [3/4,5/4].  The target itself is feasible and lies in the interior of
    // both the search domain and the constraint band, which is the natural
    // use case for the barrier-based interior-point implementation.
    //
    NonlinearInteriorPointSolver optimiser;
    auto q = EffectiveScalarMultivariateFunction::coordinates(2);
    EffectiveScalarMultivariateFunction objective_function =
        sqr(q[0] - 0.625_x) + sqr(q[1] - 0.375_x);
    EffectiveVectorMultivariateFunction band_constraint({
        q[0] + q[1]
    });
    ExactBoxType optimisation_domain({
        {0.0_x, 1.0_x},
        {0.0_x, 1.0_x}
    });
    ExactBoxType optimisation_codomain({
        {0.75_x, 1.25_x}
    });

    FloatDPBoundsVector optimum =
        optimiser.minimise(
            objective_function,
            optimisation_domain,
            band_constraint,
            optimisation_codomain);

    show("validated local optimum", optimum);
    show("constraint at optimum", band_constraint(optimum));


    section("Validated nonlinear feasibility");
    NonlinearInfeasibleInteriorPointSolver feasibility_solver;
    auto x = ValidatedScalarMultivariateFunction::coordinates(2);
    ValidatedVectorMultivariateFunction equality({2*x[0]-x[1]+x[0]*x[1]/8});
    ExactBoxType domain({{0.0_x,2.0_x},{0.0_x,2.0_x}});
    ExactBoxType zero({{0.0_x,0.0_x}});
    show("Certified feasible", feasibility_solver.feasible(domain,equality,zero));
    return 0;
}
