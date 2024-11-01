from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps


class MyProjectConan(ConanFile):
    name = "Test"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"
    requires = "gtest/1.13.0" 
    exports_sources = "CMakeLists.txt", "src/*", "tests/*" 

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def layout(self):
        self.folders.build = "build"
        

    def package_info(self):
        self.cpp_info.libs = ["Test"]