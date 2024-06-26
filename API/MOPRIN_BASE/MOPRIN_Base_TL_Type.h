//
// Created by duhamel on 26/06/24.
//

#ifndef MOPRIN_BASE_TL_TYPE_H
#define MOPRIN_BASE_TL_TYPE_H
typedef void* mo_entry_data;
typedef void* mo_ext_data;
typedef void (*MOPRIN_B_TL_Opération) (mo_entry_data donnée,mo_ext_data résultat);
typedef void* mo_tl_formula;
typedef void* mo_symbole;
typedef void* mo_tl_grammar;
#endif //MOPRIN_BASE_TL_TYPE_H
