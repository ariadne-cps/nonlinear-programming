find_library(ARIADNE_NONLINEAR_PROGRAMMING_LIBRARY NAMES ariadne-nonlinear-programming)

find_package(Threads REQUIRED)

find_path(ARIADNE_NONLINEAR_PROGRAMMING_INCLUDE_DIR ariadne-nonlinear-programming.hpp PATH_SUFFIXES ariadne-nonlinear-programming)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(AriadneNonlinearProgramming DEFAULT_MSG
  ARIADNE_NONLINEAR_PROGRAMMING_LIBRARY
  ARIADNE_NONLINEAR_PROGRAMMING_INCLUDE_DIR
)

if(AriadneNonlinearProgramming_FOUND)
  get_filename_component(ARIADNE_NONLINEAR_PROGRAMMING_INCLUDE_PARENT_DIR ${ARIADNE_NONLINEAR_PROGRAMMING_INCLUDE_DIR} DIRECTORY)
  set(ARIADNE_NONLINEAR_PROGRAMMING_INCLUDE_DIRS
    ${ARIADNE_NONLINEAR_PROGRAMMING_INCLUDE_PARENT_DIR}
    ${ARIADNE_NONLINEAR_PROGRAMMING_INCLUDE_DIR}
  )
  if(NOT TARGET AriadneNonlinearProgramming::ariadne-nonlinear-programming)
    add_library(AriadneNonlinearProgramming::ariadne-nonlinear-programming UNKNOWN IMPORTED)
    set_target_properties(AriadneNonlinearProgramming::ariadne-nonlinear-programming PROPERTIES
      IMPORTED_LOCATION "${ARIADNE_NONLINEAR_PROGRAMMING_LIBRARY}"
      INTERFACE_INCLUDE_DIRECTORIES "${ARIADNE_NONLINEAR_PROGRAMMING_INCLUDE_DIRS}"
      INTERFACE_LINK_LIBRARIES "Threads::Threads"
    )
  endif()
endif()
