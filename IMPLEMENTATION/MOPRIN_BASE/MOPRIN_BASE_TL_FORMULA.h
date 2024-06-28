//
// Created by duhamel on 28/06/24.
//

#ifndef MOPRIN_BASE_TL_FORMULA_H
#define MOPRIN_BASE_TL_FORMULA_H
#include <list>
#include <MOPRIN_Base_TL_Type.h>
#include <MOPRIN_Base_Type.h>

#include "MOPRIN_BASE_TL_Symbol.h"


class MOPRIN_BASE_TL_FORMULA {
        mo_string       name;
        MOPRIN_BASE_TL_Symbol      start_symbole;
        bool            close=false;
        MOPRIN_B_TL_Opération Operateur=nullptr;
        std::pmr::list<MOPRIN_BASE_TL_Symbol> formule={};



};



#endif //MOPRIN_BASE_TL_FORMULA_H
