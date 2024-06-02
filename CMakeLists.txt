cmake_minimum_required(VERSION 3.28)
project("MOPRIN")

set(CMAKE_CXX_STANDARD 17)


set(HEADER_DIRS "API/MOPRIN_BASE")
include_directories(${HEADER_DIRS})
set(SRC_MOPRIN_BASE "IMPLEMENTATION/MOPRIN_BASE")
set(TEST "TEST")


#MOPRIN BASE
set(LIB_MOPRIN_BASE ${SRC_MOPRIN_BASE}/MOPRIN_Base_Command_bash_main.cpp)
add_library(MOPRIN_BASE STATIC ${LIB_MOPRIN_BASE})

#test MOPRIN BASE CB
add_executable(test_mo_b_cb ${TEST}/Test_Moprin_Base_Command_Bash.cpp)
target_link_libraries(test_mo_b_cb MOPRIN_BASE)
add_test(Test_Bse_Command test_mo_b_cb -h)