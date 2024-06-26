//
// Created by duhamel on 22/06/24.
//

#ifndef MOPRIN_BASE_TL_H
#define MOPRIN_BASE_TL_H
#include <MOPRIN_Base_Type.h>
#include "MOPRIN_Base_TL_Type.h"

//
//Registre Grammar
/**
 * @brief Created the registre structure of one grammar.
 * @param name (mo_string) is the name of the grammar. It is can be null.
 * @return an pointeur
 */
mo_tl_grammar MOPRIN_BASE_TL_Created_Grammar(mo_string name);
void MOPRIN_BASE_TL_Set_Grammar_Name(mo_tl_grammar grammar,mo_string name);
mo_symbole MOPRIN_BASE_TL_Get_Original_Symbol_of_the_Grammar(mo_tl_grammar);

//Action Grammar




//Registre Formale

mo_tl_formula MOPRIN_BASE_TL_Created_formula(mo_tl_grammar grammar,mo_string name_of_formula);
void MOPRIN_BASE_TL_Formula_set_start_symbol(mo_tl_formula formule,mo_symbole);
void MOPRIN_BASE_TL_Formula_add_symbol(mo_tl_formula formula,mo_symbole);
void MOPRIN_BASE_TL_Formula_add_char(mo_tl_formula,char);
void MOPRIN_BASE_TL_Formula_add_string(mo_tl_formula,mo_string);
void MOPRIN_BASE_TL_Formula_close(mo_tl_formula);
void MOPRIN_BASE_TL_Formula_set_name(mo_tl_formula,mo_string);
void MOPRIN_Base_Formula_delete(mo_tl_formula);

#endif //MOPRIN_BASE_TL_H
