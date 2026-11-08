from setuptools import find_packages
from setuptools import setup

setup(
    name='roadwork_solution_msgs',
    version='0.1.0',
    packages=find_packages(
        include=('roadwork_solution_msgs', 'roadwork_solution_msgs.*')),
)
