from distutils.core import setup, Extension

balloon_hash_module = Extension('balloon_hash',
                                 sources = ['balloonmodule.c',
                                            'balloon.c'],
                                 include_dirs = ['.'],
                                 libraries=['ssl', 'crypto'])

setup (name = 'balloon_hash',
       version = '1.0',
       description = 'Balloon hashing module',
       ext_modules = [balloon_hash_module])
