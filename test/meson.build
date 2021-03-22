# About: Meson build configuration for Unit tests.
# Author: Ivan Vnucec
# License WTFPL – Do What the Fuck You Want to Public License. See LICENSE.md file for more information.

cc = meson.get_compiler('c')

inc = []
args = []

m_dep  = cc.find_library('m',  required : false)
rt_dep = cc.find_library('rt', required : false)

test_init = executable(
    'test_init', 
    sources:                ['test_init.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep, matrix_math_dep]
)

test_add = executable(
    'test_add', 
    sources:                ['test_add.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep, matrix_math_dep]
)

test_sub = executable(
    'test_sub', 
    sources:                ['test_sub.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep, matrix_math_dep]
)

test_scale = executable(
    'test_scale', 
    sources:                ['test_scale.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep, matrix_math_dep]
)

test_zeros = executable(
    'test_zeros', 
    sources:                ['test_zeros.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep, matrix_math_dep]
)

test_identity = executable(
    'test_identity', 
    sources:                ['test_identity.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep, matrix_math_dep]
)

test_trans = executable(
    'test_trans', 
    sources:                ['test_trans.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep, matrix_math_dep]
)

test_mult = executable(
    'test_mult', 
    sources:                ['test_mult.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep, matrix_math_dep]
)

test_setcolumn = executable(
    'test_setcolumn', 
    sources:                ['test_setcolumn.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep, matrix_math_dep]
)

test_getcolumn = executable(
    'test_getcolumn', 
    sources:                ['test_getcolumn.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep, matrix_math_dep]
)

test_copy = executable(
    'test_copy', 
    sources:                ['test_copy.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep, matrix_math_dep]
)

test_cholesky = executable(
    'test_cholesky', 
    sources:                ['test_cholesky.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep, matrix_math_dep]
)

test_trace = executable(
    'test_trace', 
    sources:                ['test_trace.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep, matrix_math_dep]
)

test('test_init',       test_init)
test('test_add',        test_add)
test('test_sub',        test_sub)
test('test_scale',      test_scale)
test('test_zeros',      test_zeros)
test('test_identity',   test_identity)
test('test_trans',      test_trans)
test('test_mult',       test_mult)
test('test_setcolumn',  test_setcolumn)
test('test_getcolumn',  test_getcolumn)
test('test_copy',       test_copy)
test('test_cholesky',   test_cholesky)
test('test_trace',      test_trace)
