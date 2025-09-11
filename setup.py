from setuptools import setup, find_packages

#parse version from __init__.py
with open('build/__init__.py') as f:
    info = {}
    for line in f:

