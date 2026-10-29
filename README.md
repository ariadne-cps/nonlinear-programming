# Ariadne Nonlinear Programming

[![macOS Status](https://github.com/ariadne-cps/nonlinear-programming/actions/workflows/macos.yml/badge.svg)](https://github.com/ariadne-cps/nonlinear-programming/actions/workflows/macos.yml)
[![Ubuntu Status](https://github.com/ariadne-cps/nonlinear-programming/actions/workflows/ubuntu.yml/badge.svg)](https://github.com/ariadne-cps/nonlinear-programming/actions/workflows/ubuntu.yml)
[![Windows Status](https://github.com/ariadne-cps/nonlinear-programming/actions/workflows/win.yml/badge.svg)](https://github.com/ariadne-cps/nonlinear-programming/actions/workflows/win.yml)
[![Sanitizers Status](https://github.com/ariadne-cps/nonlinear-programming/actions/workflows/sanitizers.yml/badge.svg)](https://github.com/ariadne-cps/nonlinear-programming/actions/workflows/sanitizers.yml)
[![Coverage Status](https://github.com/ariadne-cps/nonlinear-programming/actions/workflows/coverage.yml/badge.svg)](https://github.com/ariadne-cps/nonlinear-programming/actions/workflows/coverage.yml)
[![codecov](https://codecov.io/gh/ariadne-cps/nonlinear-programming/branch/main/graph/badge.svg)](https://codecov.io/gh/ariadne-cps/nonlinear-programming)

Ariadne Nonlinear Programming provides C++20 nonlinear minimisation and validated feasibility methods, including interior-point and penalty-function solvers.

## Layout

Public headers live in `include/nonlinear-programming`, implementation files in `src`, tests in `tests`, Python bindings, tests and tutorial in `python`, and the standalone C++ tutorial in `tutorials`. The umbrella header is `include/ariadne-nonlinear-programming.hpp`.

## Dependencies

- [ariadne-cps/function](https://github.com/ariadne-cps/function), included as a Git submodule.
- [ariadne-cps/configuration](https://github.com/ariadne-cps/configuration), providing the shared build configuration.

## Build

```sh
git clone --recurse-submodules https://github.com/ariadne-cps/nonlinear-programming.git
cd nonlinear-programming
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel --target tests
ctest --test-dir build --output-on-failure
```

## Python bindings

With a compatible Python 3.11+ development environment the standalone build produces the `pyariadne` extension, including the nonlinear programming solver bindings.

## Tutorials

- C++: `tutorials/tutorial_nonlinear_programming/tutorial_nonlinear_programming.cpp`.
- Python: `python/tutorials/tutorial_nonlinear_programming.py`.

## License

GNU General Public License v3.0.
