project(py_ext_lib)

pybind11_add_module(py_ext_lib THIN_LTO src/cpp/py_ext_lib.cpp)
