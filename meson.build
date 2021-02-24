project('matrix', 'c')

src = ['src/matrix_math.c']
inc = include_directories('src')

test_src = ['test/test_add.c']
test_inc = include_directories('test')

cargs = [
    '-DMTX_MATRIX_CHECK_PTRS', 
    '-DMTX_MATRIX_CHECK_DIMS'
    ]

test_exe = executable('test_exe', sources : [src, test_src], include_directories : [inc, test_inc], c_args : cargs)
test('test_exe', test_exe)
