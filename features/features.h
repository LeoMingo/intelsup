#ifndef FEATURES_H
#define FEATURES_H  1



#include <string>

#define iLOOP(max) for(int i = 0; i < max; i++) 

typedef std::string LIST_ITEM;
typedef LIST_ITEM* LIST;

void list_init(LIST list, const int& init_size)
{
    list = new init_size[init_size];
    iLOOP(init_size)
    {
        list[i] = "";
    }
}

void list_cpy(LIST src, LIST dest, const int& src_size)     //make src_size read-only in function
{
    dest = new LIST_ITEM[src_size];
    iLOOP(src_size)
    {
        email_list[i] = src[i];
    }
}

LIST_ITEM list_elem_conc(LIST list, int& list_size)
{
    LIST_ITEM conc_str = "";  //Concatenated List String
    iLOOP(list_size)
    {
        conc_str += list[i];
        conc_str += "\n";
    }

    return conc_str;
}



#endif      //! FEATURES_H




