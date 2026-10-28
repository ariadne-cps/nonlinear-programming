from pyariadne import (
    NonlinearInfeasibleInteriorPointSolver,
    NonlinearInteriorPointSolver,
    NonlinearPenaltyFunctionSolver,
    IntervalNonlinearInteriorPointSolver,
    ApproximateNonlinearInteriorPointSolver,
)

def test_nonlinear_solver_exports():
    for cls in (NonlinearInfeasibleInteriorPointSolver, NonlinearInteriorPointSolver,
                NonlinearPenaltyFunctionSolver, IntervalNonlinearInteriorPointSolver,
                ApproximateNonlinearInteriorPointSolver):
        assert cls() is not None
