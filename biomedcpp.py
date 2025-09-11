import ctypes, os

dll_path = os.path.abspath('sectionizer.dll')
LIB = ctypes.CDLL(dll_path)

def load():
    return LIB.load()




