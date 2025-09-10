import ctypes


lib = ctypes.CDLL('library.dll')
print(lib.main)

