import ctypes, os

dll_path = os.path.abspath('sectionizer.dll')
LIB = ctypes.CDLL(dll_path)

<<<<<<< HEAD:biomedcpp.py
def load():
    return LIB.load()
=======
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








>>>>>>> 3b961bc1fcfce60c75e17fa2fd1fd44d48b177fc:engine.py




