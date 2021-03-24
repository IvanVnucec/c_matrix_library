# About: Project root Meson build configuration.
# Author: Ivan Vnucec
# License WTFPL – Do What the Fuck You Want to Public License. See LICENSE.md file for more information.

project('c_matrix_library', 'c', default_options: ['c_std=c99', 'warning_level=3'], version: '1.0.0', license: 'WTFPL')

# Build library
# comment the lines below to disable checks
args = [
    '-DMTX_MATRIX_CHECK_PTRS',  # Check for NULL ptrs option
    '-DMTX_MATRIX_CHECK_DIMS'   # Check matrix dimensions option
]
add_project_arguments(args, language : 'c')
subdir('src/matrix_math')

# Build example
subdir('src')

# Test library
subdir('test')
