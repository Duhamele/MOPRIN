//
// Created by duhamel on 01/06/24.
//
#include <cstdio>
#include <cstdlib>

#include "MOPRIN_Base_Type.h"
#include "MOPRIN_Base_Command_Bash.h"

void help(mo_user_data data) {
        printf("Aide:\n");
        MOPRIN_B_CB_Run_Stop();
}










int main(int argc,char* argv[]) {
        MOPRIN_B_Command_Bash_Init();
        MOPRIN_B_CB_Registre_Commande_string("help",help);
        MOPRIN_B_CB_Registre_Commande_Single('h',help);

        MOPRIN_B_CB_Run(argc,argv,nullptr);
        MOPRIN_B_CB_Release();
        exit(0);
}