# About: Meson build configuration for source directory.
# Author: Ivan Vnucec
# License: Do whatever you want with it. I don't care.

srcs = ['matrix_math.c', 'matrix_math.h']

args = [
    '-Wall',
    '-Werror',
    '-DMTX_MATRIX_CHECK_PTRS',  # Check for NULL ptrs option
    '-DMTX_MATRIX_CHECK_DIMS'   # Check matrix dimensions option
]

matrix_math_lib = static_library('matrix_math_lib', 
                        srcs, 
                        c_args: [args]) 
