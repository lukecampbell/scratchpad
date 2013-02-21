_realthread = None

def get_realthread():
    global _realthread

    if _realthread:
        return _realthread

    import imp
    fp, pathname, description = imp.find_module('thread')
    try:
        _realthread = imp.load_module('realthread',fp,pathname,description)
    finally:
        if fp:
            fp.close()
    return _realthread

