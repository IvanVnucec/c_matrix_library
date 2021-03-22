# About: Static library Meson build configuration.
# Author: Ivan Vnucec
# License WTFPL – Do What the Fuck You Want to Public License. See LICENSE.md file for more information.

cc = meson.get_compiler('c')

m_dep = cc.find_library('m', required : false)

args = []

matrix_math = library('matrix_math', 
    sources: ['matrix_math.h', 'matrix_math.c'], 
    c_args: [args],
    dependencies: [m_dep])

matrix_math_dep = declare_dependency(include_directories: include_directories('.'), 
    link_with : matrix_math)
