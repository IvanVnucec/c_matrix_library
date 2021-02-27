project('matrix', 'c', default_options: 'c_std=gnu89')

cc = meson.get_compiler('c')

src = ['src/matrix_math.c']
inc = include_directories('src')

test_inc = include_directories('test')

test_cargs = [
    '-DMTX_MATRIX_CHECK_PTRS', 
    '-DMTX_MATRIX_CHECK_DIMS'
    ]

m_dep = cc.find_library('m', required : false)
rt_dep = cc.find_library('rt', required : false)

test_print_exe = executable('test_print_exe', 
    sources : [src, 'test/test_print.c'], 
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

test('test_print_exe', test_print_exe)
test('test_add_exe',   test_add_exe)
test('test_sub_exe',   test_sub_exe)
test('test_scale_exe', test_scale_exe)
test('test_zeros_exe', test_zeros_exe)
test('test_identity_exe', test_identity_exe)
test('test_trans_exe', test_trans_exe)
