#!/usr/bin/env python3
from pyariadne import *

def exact_box(bounds):
    return FloatDPExactBox([{exact(lo): exact(hi)} for lo, hi in bounds])

def tutorial_nonlinear_programming():
    q0 = EffectiveScalarMultivariateFunction.coordinate(2, 0)
    q1 = EffectiveScalarMultivariateFunction.coordinate(2, 1)
    objective = sqr(q0 - EffectiveNumber(Rational("5/8"))) + sqr(q1 - EffectiveNumber(Rational("3/8")))
    constraint = EffectiveVectorMultivariateFunction([q0 + q1])
    domain = exact_box([(0, 1), (0, 1)])
    codomain = exact_box([(0.75, 1.25)])
    solver = NonlinearInteriorPointSolver()
    optimum = solver.minimise(objective, domain, constraint, codomain)
    print("Validated local optimum:", optimum)
    print("Constraint image:", constraint(optimum))

if __name__ == "__main__":
    tutorial_nonlinear_programming()
