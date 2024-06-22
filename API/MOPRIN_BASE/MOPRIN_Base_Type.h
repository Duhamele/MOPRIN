//
// Created by duhamel on 27/05/24.
//

#ifndef MOPRIN_BASE_TYPE_H
#define MOPRIN_BASE_TYPE_H

typedef char* mo_string;
/**
 * Type use by Moprin Base command bash
 */
typedef void* mo_user_data;
enum mo_b_cb_error_type {
        string_error,
        char_error,
        arg_error
};
union data_error {
        char chactare;
        mo_string string;
};
typedef struct MOPRIN_B_CB_Error_t {
        mo_b_cb_error_type type;
        data_error param;
}MOPRIN_b_CB_Error_t;
typedef void (*MOPRIN_B_CB_Action) (mo_user_data data);
typedef void (*MOPRIN_b_CB_Error) (mo_user_data data,MOPRIN_b_CB_Error_t error);

/**
 * Type use by Moprin Base TL
 */
typedef void* mo_entry_data;
typedef void* mo_ext_data;
typedef void (*MOPRIN_B_TL_Opération) (mo_entry_data donnée,mo_ext_data résultat);
typedef void* mo_tl_formula;
typedef void* mo_symbole;
#endif //MOPRIN_BASE_TYPE_H
