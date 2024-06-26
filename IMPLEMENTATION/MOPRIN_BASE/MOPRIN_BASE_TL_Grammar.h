//
// Created by duhamel on 26/06/24.
//

#ifndef MOPRIN_BASE_TL_GRAMMAR_H
#define MOPRIN_BASE_TL_GRAMMAR_H
#include <list>
#include <MOPRIN_Base_TL_Type.h>
#include <MOPRIN_Base_Type.h>


class MOPRIN_BASE_TL_Grammar {
        mo_string name=nullptr;
        std::pmr::list<mo_tl_formula> formula_list={};

};



#endif //MOPRIN_BASE_TL_GRAMMAR_H
