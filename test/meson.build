# About: Meson build configuration for Unit tests.
# Author: Ivan Vnucec
# License: Do whatever you want with it. I don't care.

cc = meson.get_compiler('c')

inc = include_directories('./../src/')

args = [
    '-Wall',
    '-Werror'
]

m_dep  = cc.find_library('m',  required : true)      # <main.h> library
rt_dep = cc.find_library('rt', required : true)      # Library used by minunit.h test framework.

test_init = executable(
    'test_init', 
    sources:                ['test_init.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep],
    link_with:              [matrix_math_lib]
)

test_add = executable(
    'test_add', 
    sources:                ['test_add.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep],
    link_with:              [matrix_math_lib]
)

test_sub = executable(
    'test_sub', 
    sources:                ['test_sub.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep],
    link_with:              [matrix_math_lib]
)

test_scale = executable(
    'test_scale', 
    sources:                ['test_scale.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep],
    link_with:              [matrix_math_lib]
)

test_zeros = executable(
    'test_zeros', 
    sources:                ['test_zeros.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep],
    link_with:              [matrix_math_lib]
)

test_identity = executable(
    'test_identity', 
    sources:                ['test_identity.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep],
    link_with:              [matrix_math_lib]
)

test_trans = executable(
    'test_trans', 
    sources:                ['test_trans.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep],
    link_with:              [matrix_math_lib]
)

test_mult = executable(
    'test_mult', 
    sources:                ['test_mult.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep],
    link_with:              [matrix_math_lib]
)

test_setcolumn = executable(
    'test_setcolumn', 
    sources:                ['test_setcolumn.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep],
    link_with:              [matrix_math_lib]
)

test_getcolumn = executable(
    'test_getcolumn', 
    sources:                ['test_getcolumn.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep],
    link_with:              [matrix_math_lib]
)

test_copy = executable(
    'test_copy', 
    sources:                ['test_copy.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep],
    link_with:              [matrix_math_lib]
)

test_cholesky = executable(
    'test_cholesky', 
    sources:                ['test_cholesky.c'], 
    include_directories:    [inc],
    c_args:                 [args], 
    dependencies:           [m_dep, rt_dep],
    link_with:              [matrix_math_lib]
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
