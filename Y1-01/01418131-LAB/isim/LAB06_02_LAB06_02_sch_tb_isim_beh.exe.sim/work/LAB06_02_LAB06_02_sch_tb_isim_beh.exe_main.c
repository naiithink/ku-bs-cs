/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    unisims_ver_m_15469197826776211918_2316096324_init();
    unisims_ver_m_16631666276591928709_3125220529_init();
    unisims_ver_m_16176787317968387356_0970595058_init();
    unisims_ver_m_06313320939402315622_1593237687_init();
    unisims_ver_m_06312903236042698045_1759035934_init();
    work_m_06244273288012356752_0153815224_init();
    work_m_10567473267990642475_0554933656_init();
    work_m_16541823861846354283_2073120511_init();


    xsi_register_tops("work_m_10567473267990642475_0554933656");
    xsi_register_tops("work_m_16541823861846354283_2073120511");


    return xsi_run_simulation(argc, argv);

}
