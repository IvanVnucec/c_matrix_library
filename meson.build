project('matrix', 'c')

src = ['src/matrix_math.c']
inc = include_directories('src')

test_inc = include_directories('test')

test_cargs = [
    '-DMTX_MATRIX_CHECK_PTRS', 
    '-DMTX_MATRIX_CHECK_DIMS'
    ]

test_add_exe = executable('test_add_exe', 
    sources : [src, 'test/test_add.c'], 
    include_directories : [inc, test_inc], 
    c_args : test_cargs)

test_sub_exe = executable('test_sub_exe', 
    sources : [src, 'test/test_sub.c'], 
    include_directories : [inc, test_inc], 
    c_args : test_cargs)

test('test_add_exe', test_add_exe)
test('test_sub_exe', test_sub_exe)
