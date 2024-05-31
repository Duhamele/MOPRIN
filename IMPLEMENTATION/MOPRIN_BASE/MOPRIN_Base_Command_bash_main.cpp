#include "MOPRIN_Base_Command_Bash.h"

#include <cstring>

#include "MOPRIN_Base_Type.h"
#include "MOPRIN_Base_Command_BashMain_inter.h"
#include <iostream>
bool     MOPRIN_Base_run;
u_int64_t MOPRIN_Base_arg;
MOPRIN_Base_Data MOPRIN_B_CB_DATA;

void MOPRIN_B_CB_Run_Stop() {
        MOPRIN_Base_run=false;
}
void MOPRIN_B_CB_Run(int argc, char *argv[],mo_user_data data) {
        MOPRIN_Base_run=true;
        MOPRIN_Base_arg=1;
        while (MOPRIN_Base_run&&MOPRIN_Base_arg<argc) {
                if(argv[MOPRIN_Base_arg][0]=='-') {
                        //string option
                        if(argv[MOPRIN_Base_arg][1]=='-') {
                                MOPRIN_B_CB_Select_Command_string(argv[MOPRIN_Base_arg]+2,data);
                        //character option
                        }else {
                                u_int64_t number_argv=MOPRIN_Base_arg;
                                int number_i=1;
                                size_t number_max=strlen(argv[MOPRIN_Base_arg]);
                                while (number_i<number_max) {
                                        MOPRIN_B_CB_Select_Command_character(argv[number_argv][number_i],data);
                                        number_i++;
                                }
                        }
                //argument
                }else {
                        MOPRIN_B_CB_Select_Command_argument(argv[MOPRIN_Base_arg],data);
                }
                MOPRIN_Base_arg++;
        }

}

void MOPRIN_B_Command_Bash_Init() {
        MOPRIN_B_CB_DATA=(MOPRIN_Base_Data){nullptr,nullptr,MOPRIN_B_CB_Commande_Error_Default,nullptr,0,0};
        MOPRIN_Base_run=false;
}

void MOPRIN_B_CB_Registre_Commande_Single(char cle,MOPRIN_B_CB_Action Commande) {
        if(Commande!=nullptr) {
                if(MOPRIN_B_CB_DATA.action_char!=nullptr) {
                        realloc(MOPRIN_B_CB_DATA.action_char,(MOPRIN_B_CB_DATA.number_action_char+1)*sizeof(MOPRIN_Base_Command_Option_char_t));
                        MOPRIN_B_CB_DATA.action_char[MOPRIN_B_CB_DATA.number_action_char].name=cle;
                        MOPRIN_B_CB_DATA.action_char[MOPRIN_B_CB_DATA.number_action_char].action=Commande;
                        MOPRIN_B_CB_DATA.number_action_char++;
                }else {
                        MOPRIN_B_CB_DATA.action_char=(MOPRIN_Base_Command_Option_char_t*)malloc(sizeof(MOPRIN_Base_Command_Option_char_t));
                        MOPRIN_B_CB_DATA.action_char[MOPRIN_B_CB_DATA.number_action_char].name=cle;
                        MOPRIN_B_CB_DATA.action_char[MOPRIN_B_CB_DATA.number_action_char].action=Commande;
                        MOPRIN_B_CB_DATA.number_action_char++;
                }
        }
}


void MOPRIN_B_CB_Registre_Commande_string(mo_string cle,MOPRIN_B_CB_Action Commande) {
        if(Commande!=nullptr&&cle!=nullptr&&*cle!='\0') {
                if(MOPRIN_B_CB_DATA.action_string!=nullptr) {
                        realloc(MOPRIN_B_CB_DATA.action_string,(MOPRIN_B_CB_DATA.number_action_string+1)*sizeof(MOPRIN_Base_Command_Option_string_t));
                        MOPRIN_B_CB_DATA.action_string[MOPRIN_B_CB_DATA.number_action_string].action=Commande;
                        MOPRIN_B_CB_DATA.action_string[MOPRIN_B_CB_DATA.number_action_string].name=(mo_string)malloc(strlen(cle)+1);
                        strcpy(MOPRIN_B_CB_DATA.action_string[MOPRIN_B_CB_DATA.number_action_string].name,cle);
                        MOPRIN_B_CB_DATA.number_action_string++;
                }else {
                        MOPRIN_B_CB_DATA.action_string=(MOPRIN_Base_Command_Option_string_t*)malloc(sizeof(MOPRIN_Base_Command_Option_string_t));
                        MOPRIN_B_CB_DATA.action_string[MOPRIN_B_CB_DATA.number_action_string].action=Commande;
                        MOPRIN_B_CB_DATA.action_string[MOPRIN_B_CB_DATA.number_action_string].name=(mo_string)malloc(strlen(cle)+1);
                        strcpy(MOPRIN_B_CB_DATA.action_string[MOPRIN_B_CB_DATA.number_action_string].name,cle);
                        MOPRIN_B_CB_DATA.number_action_string++;
                }

        }
}

void MOPRIN_B_CB_Release() {
        free(MOPRIN_B_CB_DATA.action_char);
        for(int i=0;i<MOPRIN_B_CB_DATA.number_action_string;i++) {
                free(MOPRIN_B_CB_DATA.action_string[i].name);
        }
        free(MOPRIN_B_CB_DATA.action_string);

}

void MOPRIN_B_CB_Set_Command_Agr(MOPRIN_B_CB_Action Commande) {
        MOPRIN_B_CB_DATA.action_argument=Commande;
}
char* MOPRIN_B_CB_Get_Argument_Command_Absolu(int number){}
char* MOPRIN_B_CB_Get_Argument_Command_Relative(int number){}
int MOPRIN_B_CB_Get_Command_Number(){}
void MOPRIN_B_CB_Set_Command_Default_Error(MOPRIN_B_CB_Action Command) {
        MOPRIN_B_CB_DATA.action_error=Command;
}
void MOPRIN_B_CB_Commande_Error_Default(mo_user_data data) {
        MOPRIN_B_CB_Run_Stop();
        fprintf(stderr,"Error Command\n");


}
void MOPRIN_B_CB_Select_Command_character(char option,mo_user_data data) {
        for(int i=0;i<MOPRIN_B_CB_DATA.number_action_char;i++) {
                if(MOPRIN_B_CB_DATA.action_char[i].name==option) {
                        MOPRIN_B_CB_DATA.action_char[i].action(data);
                        return;
                }
        }
        MOPRIN_B_CB_DATA.action_error(data);
        MOPRIN_B_CB_Run_Stop();
}
void MOPRIN_B_CB_Select_Command_string(mo_string option,mo_user_data data) {
        for(int i=0;i<MOPRIN_B_CB_DATA.number_action_string;i++) {
                if(strcmp(option,MOPRIN_B_CB_DATA.action_string[i].name)==0) {
                        MOPRIN_B_CB_DATA.action_string[i].action(data);
                        return;
                }
        }
        MOPRIN_B_CB_DATA.action_error(data);
        MOPRIN_B_CB_Run_Stop();
}
void MOPRIN_B_CB_Select_Command_argument(mo_string option,mo_user_data data) {
        if(MOPRIN_B_CB_DATA.action_argument!=nullptr) {
                MOPRIN_B_CB_DATA.action_argument(data);
                return;
        }
        MOPRIN_B_CB_DATA.action_error(data);

}