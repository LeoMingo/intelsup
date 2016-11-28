//intelsupi
//run with c++11 and above

#include "kd_lib.h"

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

int main(int argc, char ** argv){

    IS_DATA is_data;    //intelsup data structure
    int email_cnt = is_data.email_list_size;;

//======================initializing required lists===========================

    LIST email_list;
    list_cpy(email_list, is_data.email_list, email_cnt);
    

    LIST email_addr_list, email_cont_list;
    list_cpy(email_addr_list, email_addr_extractor(email_list), email_cnt);
    list_cpy(email_cont_list, email_cont_extractor(email_list), email_cnt);


    LIST kd_lib_list;
    list_cpy(kd_lib_list, is_data.kd_lib_list, email_cnt);

    
    KD_LIB kl(kd_lib_list);

    LIST rst_list;
    list_init(rst_list);

//=============================================================================


    LIST_ITEM sent_rst = "";
    iLOOP(email_cnt)
    {
        sent_rst = kl.word_extractor(email_cont_list[i]);
        rst_list[email_cnt] = sent_rst;
    }

    iLOOP(email_cnt)
    {
        intelsup_reply(email_addr_list[email_cnt], rst_list[email_cnt]);
        log_record(email_addr_list[email_cnt], email_cont_list[email_cnt], rst_list[email_cnt]);
    }


    return 0; 
}
