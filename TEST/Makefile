#GCC

TEMP=Temp/
INC_DIR=../API/MOPRIN_BASE ../IMPLEMENTATION/MOPRIN_BASE
CCFLAGS= $(addprefix -I,$(INC_DIR))
GCC=g++ -Wall -Wextra ${CCFLAGS}
MOPRIN_BASE=../IMPLEMENTATION/MOPRIN_BASE/
clean:
	rm -f Temp/*

Test_cb:Test_Moprin_Base_Command_Bash.o MOPRIN_Base_Command_bash_main.o
	${GCC} ${TEMP}Test_Moprin_Base_Command_Bash.o ${TEMP}MOPRIN_Base_Command_bash_main.o -o ${TEMP}Test_CB

Test_Moprin_Base_Command_Bash.o:
	${GCC} -c Test_Moprin_Base_Command_Bash.cpp -o ${TEMP}Test_Moprin_Base_Command_Bash.o
MOPRIN_Base_Command_bash_main.o:
	${GCC} -c ${MOPRIN_BASE}MOPRIN_Base_Command_bash_main.cpp -o ${TEMP}MOPRIN_Base_Command_bash_main.o
Test:Test_cb
	echo "Test Morpin CB\n"
	./${TEMP}Test_CB --help
	./${TEMP}Test_CB -h
	./${TEMP}Test_CB -ph af
	./${TEMP}Test_CB -p af -h
