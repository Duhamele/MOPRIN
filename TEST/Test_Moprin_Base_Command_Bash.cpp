//
// Created by duhamel on 01/06/24.
//
#include "MOPRIN_Base_Type.h"
#include "MOPRIN_Base_Command_Bash.h"












int main(int argc,char* argv[]) {
        MOPRIN_B_Command_Bash_Init();


        MOPRIN_B_CB_Run(argc,argv,nullptr);
        MOPRIN_B_CB_Release();
}