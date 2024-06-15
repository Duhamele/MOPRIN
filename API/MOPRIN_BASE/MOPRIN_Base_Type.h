//
// Created by duhamel on 27/05/24.
//

#ifndef MOPRIN_BASE_TYPE_H
#define MOPRIN_BASE_TYPE_H
typedef void* mo_user_data;
typedef char* mo_string;
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
#endif //MOPRIN_BASE_TYPE_H
