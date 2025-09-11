import ctypes, os

dll_path = os.path.abspath('sectionizer.dll')
LIB = ctypes.CDLL(dll_path)

def load(*args):
    '''
    Load a new Sectionizer object.

    Args:
        language - language of document
        max - max section length
        min - minimum section length
        slp - start line phrase
        slc - start line char
        

    '''
    return LIB.load()












