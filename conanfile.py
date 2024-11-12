from conan import ConanFile
from conan.tools.files import copy, load
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps
import os


class MyProjectConan(ConanFile):
    name = "Test"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"

    generators = "CMakeDeps"

    def requirements(self):
        if not self.conf.get("tools.build:skip_test", default=False):
            self.test_requires("cpputest/4.0")

    def layout(self):
        if not self.conf.get("tools.build:skip_test", default=False):
            cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        if not self.conf.get("tools.build:skip_test", default=False):
            cmake.test()
