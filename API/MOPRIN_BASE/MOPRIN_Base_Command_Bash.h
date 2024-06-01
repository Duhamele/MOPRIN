#ifndef MOPRIN_BASE_LIBRARY_H
#define MOPRIN_BASE_LIBRARY_H
#include "MOPRIN_Base_Type.h"





/**
 * @brief Init the structure of data which is used by the programm MOPRIN BASE Command Bash
 * @attention The launch of the function is obligatory for the good functioning of the programm
 * @note to see also MOPRIN_B_CB_Release()
 */
void MOPRIN_B_Command_Bash_Init();

/**
 * @brief Link one character with a function
 * @param cle the character must to be a letter
 * @param Commande the function must to be a type of MOPRIN_B_CB_Action
 * @note to see also MOPRIN_B_CB_Action
 * @note to see also MOPRIN_B_CB_Registre_Commande_string for strings
 */
void MOPRIN_B_CB_Registre_Commande_Single(char cle,MOPRIN_B_CB_Action Commande);

/**
 * @brief Link one string with a function
 * @param cle the string must be "help" for "--help", the function copies the string
 * @param Commande the function must to be a type of MOPRIN_B_CB_Action
 * @note to see also MOPRIN_B_CB_Action
 * @note to see also MOPRIN_B_CB_Registre_Commande_Single for character
 */
void MOPRIN_B_CB_Registre_Commande_string(mo_string cle,MOPRIN_B_CB_Action Commande);

/**
 * @brief Release the structure of data which is used by the programm MOPRIN BASE Command Bash
 * @note to see also MOPRIN_B_CB_Init()
 */
void MOPRIN_B_CB_Release();

/**
 *
 * @brief Launch the analyse of the command
 * @param data
 * @note to see also MOPRIN_B_Command_Bash_Init()
 */
void MOPRIN_B_CB_Run(int argc, char *argv[],mo_user_data data);

/**
 * @brief Stop the analyse of the command
 */
void MOPRIN_B_CB_Run_Stop();
void MOPRIN_B_CB_Set_Command_Default(MOPRIN_B_CB_Action Commande);

/**
 * 
 * @param number position of argument
 * @return argument
 * @note
 */
const char* MOPRIN_B_CB_Get_Argument_Command_Absolu(int number);
char* MOPRIN_B_CB_Get_Argument_Command_Relative(int number);
void MOPRIN_B_CB_Set_Command_Default_Error(MOPRIN_B_CB_Action Command);
void MOPRIN_B_CB_UP(int number);





#endif //MOPRIN_BASE_LIBRARY_H
