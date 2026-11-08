from setuptools import find_packages
from setuptools import setup

setup(
    name='roadwork_interfaces',
    version='0.1.0',
    packages=find_packages(
        include=('roadwork_interfaces', 'roadwork_interfaces.*')),
)
