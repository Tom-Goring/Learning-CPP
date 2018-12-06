set(CMAKE_LEGACY_CYGWIN_WIN32 0) # Remove when CMake >= 2.8.4 is required
project(simple_example)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES "Hello World.cpp")
add_executable(simple_example ${SOURCE_FILES})