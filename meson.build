# About: Meson build configuration.
# Author: Ivan Vnucec
# License: Do whatever you want with it. I don't care.

project('matrix', 'c', default_options: ['c_std=c99'])

cc = meson.get_compiler('c')

src = ['src/matrix_math.c']
inc = include_directories('src')

test_inc = include_directories('test')

test_cargs = [
    '-Wall',
    '-Werror',
    '-DMTX_MATRIX_CHECK_PTRS',  # Check for NULL ptrs option
    '-DMTX_MATRIX_CHECK_DIMS'   # Check matrix dimensions option
    ]

m_dep = cc.find_library('m', required : true)      # Math library
rt_dep = cc.find_library('rt', required : true)    # Library used by minunit.h test framework.

#######################  Build test executables  #######################

test_init_exe = executable('test_init_exe', 
    sources : [src, 'test/test_init.c'], 
    include_directories : [inc, test_inc], 
    c_args : test_cargs,
    dependencies: [m_dep, rt_dep])

test_add_exe = executable('test_add_exe', 
    sources : [src, 'test/test_add.c'], 
    include_directories : [inc, test_inc], 
    c_args : test_cargs,
    dependencies: [m_dep, rt_dep])

test_sub_exe = executable('test_sub_exe', 
    sources : [src, 'test/test_sub.c'], 
    include_directories : [inc, test_inc], 
    c_args : test_cargs,
    dependencies: [m_dep, rt_dep])

test_scale_exe = executable('test_scale_exe', 
    sources : [src, 'test/test_scale.c'], 
    include_directories : [inc, test_inc], 
    c_args : test_cargs,
    dependencies: [m_dep, rt_dep])

test_zeros_exe = executable('test_zeros_exe', 
    sources : [src, 'test/test_zeros.c'], 
    include_directories : [inc, test_inc], 
    c_args : test_cargs,
    dependencies: [m_dep, rt_dep])

test_identity_exe = executable('test_identity_exe', 
    sources : [src, 'test/test_identity.c'], 
    include_directories : [inc, test_inc], 
    c_args : test_cargs,
    dependencies: [m_dep, rt_dep])

test_trans_exe = executable('test_trans_exe', 
    sources : [src, 'test/test_trans.c'], 
    include_directories : [inc, test_inc], 
    c_args : test_cargs,
    dependencies: [m_dep, rt_dep])

test_mult_exe = executable('test_mult_exe', 
    sources : [src, 'test/test_mult.c'], 
    include_directories : [inc, test_inc], 
    c_args : test_cargs,
    dependencies: [m_dep, rt_dep])

test_setcolumn_exe = executable('test_setcolumn_exe', 
    sources : [src, 'test/test_setcolumn.c'], 
    include_directories : [inc, test_inc], 
    c_args : test_cargs,
    dependencies: [m_dep, rt_dep])

test_getcolumn_exe = executable('test_getcolumn_exe', 
    sources : [src, 'test/test_getcolumn.c'], 
    include_directories : [inc, test_inc], 
    c_args : test_cargs,
    dependencies: [m_dep, rt_dep])

test_copy_exe = executable('test_copy_exe', 
    sources : [src, 'test/test_copy.c'], 
    include_directories : [inc, test_inc], 
    c_args : test_cargs,
    dependencies: [m_dep, rt_dep])

test_cholesky_exe = executable('test_cholesky_exe', 
    sources : [src, 'test/test_cholesky.c'], 
    include_directories : [inc, test_inc], 
    c_args : test_cargs,
    dependencies: [m_dep, rt_dep])
########################################################################

#######################  Run test executables  #########################
test('test_init_exe',  test_init_exe)
test('test_add_exe',   test_add_exe)
test('test_sub_exe',   test_sub_exe)
test('test_scale_exe', test_scale_exe)
test('test_zeros_exe', test_zeros_exe)
test('test_identity_exe',  test_identity_exe)
test('test_trans_exe',     test_trans_exe)
test('test_mult_exe',      test_mult_exe)
test('test_setcolumn_exe', test_setcolumn_exe)
test('test_getcolumn_exe', test_getcolumn_exe)
test('test_copy_exe',      test_copy_exe)
test('test_cholesky_exe',  test_cholesky_exe)
########################################################################
