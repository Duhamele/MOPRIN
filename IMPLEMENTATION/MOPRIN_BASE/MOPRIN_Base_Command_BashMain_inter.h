//
// Created by duhamel on 29/05/24.
//

#ifndef MOPRIN_BASE_HEADS_H
#define MOPRIN_BASE_HEADS_H
#include <sys/types.h>
#include "MOPRIN_Base_Type.h"
typedef struct MOPRIN_Base_Command_Option_char {
 char name;
 MOPRIN_B_CB_Action action;
}MOPRIN_Base_Command_Option_char_t;

typedef struct MOPRIN_Base_Command_Option_string {
 mo_string name;
 MOPRIN_B_CB_Action action;
}MOPRIN_Base_Command_Option_string_t;

typedef struct MOPRIN_Base_Data {
 MOPRIN_Base_Command_Option_char_t* action_char;
 MOPRIN_Base_Command_Option_string_t* action_string;
 MOPRIN_b_CB_Error action_error;
 MOPRIN_B_CB_Action action_argument;
 size_t number_action_char;
 size_t number_action_string;
}MOPRIN_Base_Data;
/**
 * @brief If the command analyse work
 * @note type of bool
 */
extern bool     MOPRIN_Base_run;
extern u_int64_t MOPRIN_Base_arg;
extern MOPRIN_Base_Data MOPRIN_B_CB_DATA;
void MOPRIN_B_CB_Commande_Error_Default(mo_user_data data,MOPRIN_b_CB_Error_t Error);
void MOPRIN_B_CB_Select_Command_character(char option,mo_user_data data);
void MOPRIN_B_CB_Select_Command_string(mo_string option,mo_user_data data);
void MOPRIN_B_CB_Select_Command_argument(mo_string option,mo_user_data data);


#endif //MOPRIN_BASE_HEADS_H
