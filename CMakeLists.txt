cmake_minimum_required(VERSION 3.28)
project("MOPRIN")

set(CMAKE_CXX_STANDARD 17)


set(HEADER_DIRS "API/MOPRIN_BASE")
include_directories(${HEADER_DIRS})
set(SRC_MOPRIN_BASE "IMPLEMENTATION/MOPRIN_BASE")
set(TEST "TEST")


#MOPRIN BASE CB
set(LIB_MOPRIN_BASE ${SRC_MOPRIN_BASE}/MOPRIN_Base_Command_bash_main.cpp)
add_library(MOPRIN_BASE_CB STATIC ${LIB_MOPRIN_BASE})

#test MOPRIN BASE CB
add_executable(test_mo_b_cb ${TEST}/Test_Moprin_Base_Command_Bash.cpp)
target_link_libraries(test_mo_b_cb MOPRIN_BASE_CB)
add_test(Test_Bse_Command test_mo_b_cb -h --help)

#MOPRIN BASE TL
set(LIB_MOPRIN_B_TL ${SRC_MOPRIN_BASE}/MOPRIN_Base_TL_int.cpp
        IMPLEMENTATION/MOPRIN_BASE/MOPRIN_BASE_TL_Grammar.cpp
        IMPLEMENTATION/MOPRIN_BASE/MOPRIN_BASE_TL_Grammar.h)
add_library(MOPRIN_BASE_TL STATIC ${LIB_MOPRIN_B_TL})
