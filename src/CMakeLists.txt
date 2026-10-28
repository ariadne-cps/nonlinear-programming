add_library(NONLINEAR_PROGRAMMING_SRC OBJECT
    nonlinear_programming.cpp
    nonlinear_infeasible_interior_point_method.cpp
    nonlinear_interior_point_method.cpp
    nonlinear_approximate_interior_point_method.cpp
    nonlinear_interval_interior_point_method.cpp
    nonlinear_penalty_function_method.cpp
)
target_include_directories(NONLINEAR_PROGRAMMING_SRC PRIVATE "${PROJECT_SOURCE_DIR}/include/nonlinear-programming")
