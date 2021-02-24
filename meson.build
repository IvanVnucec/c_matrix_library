project('matrix', 'c')

src = ['src/matrix_math.c']
inc = include_directories('src')

test_src = ['test/test_add.c']
test_inc = include_directories('test')

exe = executable('test_exec', sources : [src, test_src], include_directories : [inc, test_inc])
test('test_exec', exe)
