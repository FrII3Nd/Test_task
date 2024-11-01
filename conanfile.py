from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps


class MyProjectConan(ConanFile):
    name = "Test"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"
    requires = "gtest/1.14.0"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

