//
// Created by duhamel on 26/06/24.
//

#ifndef MOPRIN_BASE_TL_GRAMMAR_H
#define MOPRIN_BASE_TL_GRAMMAR_H
#include <list>
#include <MOPRIN_Base_TL_Type.h>
#include <MOPRIN_Base_Type.h>

#include "MOPRIN_BASE_TL_FORMULA.h"


class MOPRIN_BASE_TL_Grammar {
        mo_string name=nullptr;
        std::list<MOPRIN_BASE_TL_FORMULA> list_right={};


};



#endif //MOPRIN_BASE_TL_GRAMMAR_H
