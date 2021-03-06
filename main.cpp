//intelsupi
//run with c++11 and above

#include "features/features.h"

#include "kd_lib.h"

#include <string>








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
        //^-------------------------------^
        //Add this rst_num later
        sent_rst = kst_elem_conc(kl.word_extractor(email_cont_list[i]), kl.rst_num);
        rst_list[email_cnt] = sent_rst;
    }

    iLOOP(email_cnt)
    {
        intelsup_reply(email_addr_list[email_cnt], rst_list[email_cnt]);
        log_record(email_addr_list[email_cnt], email_cont_list[email_cnt], rst_list[email_cnt]);
    }


    return 0; 
}
