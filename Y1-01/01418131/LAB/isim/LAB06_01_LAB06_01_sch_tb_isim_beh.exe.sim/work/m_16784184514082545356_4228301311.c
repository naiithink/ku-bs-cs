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

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "a = %d, b = %d  :  x = %d, y = %d\tcount = %2d";
static const char *ng1 = "/home/naiithink/in-Sync/Files/ISE_DS/CS131-LAB/Sources/LAB06_01_VeriTest.v";
static int ng2[] = {4, 0};
static int ng3[] = {1, 0};
static int ng4[] = {3, 0};
static int ng5[] = {2, 0};
static int ng6[] = {0, 0};

void Monitor_59_2(char *);
static void NetReassign_36_3(char *);
static void NetReassign_37_4(char *);
static void NetReassign_41_5(char *);
static void NetReassign_46_6(char *);
void Monitor_59_2(char *);


static void Monitor_59_2_Func(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;

LAB0:    t1 = (t0 + 1768);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t0 + 1608);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 1048U);
    t8 = *((char **)t7);
    t7 = (t0 + 1208U);
    t9 = *((char **)t7);
    t7 = (t0 + 1928);
    t10 = (t7 + 56U);
    t11 = *((char **)t10);
    xsi_vlogfile_write(1, 0, 3, ng0, 6, t0, (char)118, t3, 1, (char)118, t6, 1, (char)118, t8, 1, (char)118, t9, 1, (char)119, t11, 32);

LAB1:    return;
}

static void Initial_28_0(char *t0)
{
    char t6[8];
    char t17[8];
    char t24[8];
    char t25[8];
    char t33[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    char *t38;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    char *t47;
    char *t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    char *t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    char *t67;
    char *t68;

LAB0:    t1 = (t0 + 2840U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(29, ng1);

LAB4:    xsi_set_current_line(31, ng1);

LAB5:    t2 = (t0 + 1928);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_signed_less(t6, 32, t4, 32, t5, 32);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(53, ng1);
    xsi_vlog_finish(1);

LAB1:    return;
LAB6:    xsi_set_current_line(32, ng1);

LAB8:    xsi_set_current_line(34, ng1);
    t13 = (t0 + 1928);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t16 = ((char*)((ng3)));
    memset(t17, 0, 8);
    xsi_vlog_signed_add(t17, 32, t15, 32, t16, 32);
    t18 = (t0 + 1928);
    xsi_vlogvar_assign_value(t18, t17, 0, 0, 32);
    xsi_set_current_line(36, ng1);
    t2 = (t0 + 1768);
    xsi_set_assignedflag(t2);
    t3 = (t0 + 6328);
    *((int *)t3) = 1;
    NetReassign_36_3(t0);
    xsi_set_current_line(37, ng1);
    t2 = (t0 + 1608);
    xsi_set_assignedflag(t2);
    t3 = (t0 + 6332);
    *((int *)t3) = 1;
    NetReassign_37_4(t0);
    xsi_set_current_line(39, ng1);
    t2 = (t0 + 1928);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t6, 0, 8);
    xsi_vlog_signed_equal(t6, 32, t4, 32, t5, 32);
    memset(t17, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB9;

LAB10:    if (*((unsigned int *)t7) != 0)
        goto LAB11;

LAB12:    t14 = (t17 + 4);
    t19 = *((unsigned int *)t17);
    t20 = (!(t19));
    t21 = *((unsigned int *)t14);
    t22 = (t20 || t21);
    if (t22 > 0)
        goto LAB13;

LAB14:    memcpy(t33, t17, 8);

LAB15:    t61 = (t33 + 4);
    t62 = *((unsigned int *)t61);
    t63 = (~(t62));
    t64 = *((unsigned int *)t33);
    t65 = (t64 & t63);
    t66 = (t65 != 0);
    if (t66 > 0)
        goto LAB23;

LAB24:
LAB25:    xsi_set_current_line(44, ng1);
    t2 = (t0 + 1928);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng5)));
    memset(t6, 0, 8);
    xsi_vlog_signed_equal(t6, 32, t4, 32, t5, 32);
    memset(t17, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB27;

LAB28:    if (*((unsigned int *)t7) != 0)
        goto LAB29;

LAB30:    t14 = (t17 + 4);
    t19 = *((unsigned int *)t17);
    t20 = (!(t19));
    t21 = *((unsigned int *)t14);
    t22 = (t20 || t21);
    if (t22 > 0)
        goto LAB31;

LAB32:    memcpy(t33, t17, 8);

LAB33:    t61 = (t33 + 4);
    t62 = *((unsigned int *)t61);
    t63 = (~(t62));
    t64 = *((unsigned int *)t33);
    t65 = (t64 & t63);
    t66 = (t65 != 0);
    if (t66 > 0)
        goto LAB41;

LAB42:
LAB43:    xsi_set_current_line(49, ng1);
    t2 = (t0 + 2648);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB45;
    goto LAB1;

LAB9:    *((unsigned int *)t17) = 1;
    goto LAB12;

LAB11:    t13 = (t17 + 4);
    *((unsigned int *)t17) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB12;

LAB13:    t15 = (t0 + 1928);
    t16 = (t15 + 56U);
    t18 = *((char **)t16);
    t23 = ((char*)((ng2)));
    memset(t24, 0, 8);
    xsi_vlog_signed_equal(t24, 32, t18, 32, t23, 32);
    memset(t25, 0, 8);
    t26 = (t24 + 4);
    t27 = *((unsigned int *)t26);
    t28 = (~(t27));
    t29 = *((unsigned int *)t24);
    t30 = (t29 & t28);
    t31 = (t30 & 1U);
    if (t31 != 0)
        goto LAB16;

LAB17:    if (*((unsigned int *)t26) != 0)
        goto LAB18;

LAB19:    t34 = *((unsigned int *)t17);
    t35 = *((unsigned int *)t25);
    t36 = (t34 | t35);
    *((unsigned int *)t33) = t36;
    t37 = (t17 + 4);
    t38 = (t25 + 4);
    t39 = (t33 + 4);
    t40 = *((unsigned int *)t37);
    t41 = *((unsigned int *)t38);
    t42 = (t40 | t41);
    *((unsigned int *)t39) = t42;
    t43 = *((unsigned int *)t39);
    t44 = (t43 != 0);
    if (t44 == 1)
        goto LAB20;

LAB21:
LAB22:    goto LAB15;

LAB16:    *((unsigned int *)t25) = 1;
    goto LAB19;

LAB18:    t32 = (t25 + 4);
    *((unsigned int *)t25) = 1;
    *((unsigned int *)t32) = 1;
    goto LAB19;

LAB20:    t45 = *((unsigned int *)t33);
    t46 = *((unsigned int *)t39);
    *((unsigned int *)t33) = (t45 | t46);
    t47 = (t17 + 4);
    t48 = (t25 + 4);
    t49 = *((unsigned int *)t47);
    t50 = (~(t49));
    t51 = *((unsigned int *)t17);
    t52 = (t51 & t50);
    t53 = *((unsigned int *)t48);
    t54 = (~(t53));
    t55 = *((unsigned int *)t25);
    t56 = (t55 & t54);
    t57 = (~(t52));
    t58 = (~(t56));
    t59 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t59 & t57);
    t60 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t60 & t58);
    goto LAB22;

LAB23:    xsi_set_current_line(40, ng1);

LAB26:    xsi_set_current_line(41, ng1);
    t67 = (t0 + 1768);
    xsi_set_assignedflag(t67);
    t68 = (t0 + 6336);
    *((int *)t68) = 1;
    NetReassign_41_5(t0);
    goto LAB25;

LAB27:    *((unsigned int *)t17) = 1;
    goto LAB30;

LAB29:    t13 = (t17 + 4);
    *((unsigned int *)t17) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB30;

LAB31:    t15 = (t0 + 1928);
    t16 = (t15 + 56U);
    t18 = *((char **)t16);
    t23 = ((char*)((ng2)));
    memset(t24, 0, 8);
    xsi_vlog_signed_equal(t24, 32, t18, 32, t23, 32);
    memset(t25, 0, 8);
    t26 = (t24 + 4);
    t27 = *((unsigned int *)t26);
    t28 = (~(t27));
    t29 = *((unsigned int *)t24);
    t30 = (t29 & t28);
    t31 = (t30 & 1U);
    if (t31 != 0)
        goto LAB34;

LAB35:    if (*((unsigned int *)t26) != 0)
        goto LAB36;

LAB37:    t34 = *((unsigned int *)t17);
    t35 = *((unsigned int *)t25);
    t36 = (t34 | t35);
    *((unsigned int *)t33) = t36;
    t37 = (t17 + 4);
    t38 = (t25 + 4);
    t39 = (t33 + 4);
    t40 = *((unsigned int *)t37);
    t41 = *((unsigned int *)t38);
    t42 = (t40 | t41);
    *((unsigned int *)t39) = t42;
    t43 = *((unsigned int *)t39);
    t44 = (t43 != 0);
    if (t44 == 1)
        goto LAB38;

LAB39:
LAB40:    goto LAB33;

LAB34:    *((unsigned int *)t25) = 1;
    goto LAB37;

LAB36:    t32 = (t25 + 4);
    *((unsigned int *)t25) = 1;
    *((unsigned int *)t32) = 1;
    goto LAB37;

LAB38:    t45 = *((unsigned int *)t33);
    t46 = *((unsigned int *)t39);
    *((unsigned int *)t33) = (t45 | t46);
    t47 = (t17 + 4);
    t48 = (t25 + 4);
    t49 = *((unsigned int *)t47);
    t50 = (~(t49));
    t51 = *((unsigned int *)t17);
    t52 = (t51 & t50);
    t53 = *((unsigned int *)t48);
    t54 = (~(t53));
    t55 = *((unsigned int *)t25);
    t56 = (t55 & t54);
    t57 = (~(t52));
    t58 = (~(t56));
    t59 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t59 & t57);
    t60 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t60 & t58);
    goto LAB40;

LAB41:    xsi_set_current_line(45, ng1);

LAB44:    xsi_set_current_line(46, ng1);
    t67 = (t0 + 1608);
    xsi_set_assignedflag(t67);
    t68 = (t0 + 6340);
    *((int *)t68) = 1;
    NetReassign_46_6(t0);
    goto LAB43;

LAB45:    goto LAB5;

}

static void Initial_56_1(char *t0)
{

LAB0:    xsi_set_current_line(57, ng1);

LAB2:    xsi_set_current_line(59, ng1);
    Monitor_59_2(t0);

LAB1:    return;
}

static void NetReassign_36_3(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 3336U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(36, ng1);
    t3 = 0;
    t2 = ((char*)((ng6)));
    t4 = (t0 + 6328);
    if (*((int *)t4) > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    t5 = (t0 + 1768);
    xsi_vlogvar_assignassignvalue(t5, t2, 0, 0, 0, 1, ((int*)(t4)));
    t3 = 1;
    goto LAB5;

}

static void NetReassign_37_4(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 3584U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(37, ng1);
    t3 = 0;
    t2 = ((char*)((ng6)));
    t4 = (t0 + 6332);
    if (*((int *)t4) > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    t5 = (t0 + 1608);
    xsi_vlogvar_assignassignvalue(t5, t2, 0, 0, 0, 1, ((int*)(t4)));
    t3 = 1;
    goto LAB5;

}

static void NetReassign_41_5(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 3832U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(41, ng1);
    t3 = 0;
    t2 = ((char*)((ng3)));
    t4 = (t0 + 6336);
    if (*((int *)t4) > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    t5 = (t0 + 1768);
    xsi_vlogvar_assignassignvalue(t5, t2, 0, 0, 0, 1, ((int*)(t4)));
    t3 = 1;
    goto LAB5;

}

static void NetReassign_46_6(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 4080U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(46, ng1);
    t3 = 0;
    t2 = ((char*)((ng3)));
    t4 = (t0 + 6340);
    if (*((int *)t4) > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    t5 = (t0 + 1608);
    xsi_vlogvar_assignassignvalue(t5, t2, 0, 0, 0, 1, ((int*)(t4)));
    t3 = 1;
    goto LAB5;

}

void Monitor_59_2(char *t0)
{
    char *t1;
    char *t2;

LAB0:    t1 = (t0 + 4136);
    t2 = (t0 + 4648);
    xsi_vlogfile_monitor((void *)Monitor_59_2_Func, t1, t2);

LAB1:    return;
}


extern void work_m_16784184514082545356_4228301311_init()
{
	static char *pe[] = {(void *)Initial_28_0,(void *)Initial_56_1,(void *)NetReassign_36_3,(void *)NetReassign_37_4,(void *)NetReassign_41_5,(void *)NetReassign_46_6,(void *)Monitor_59_2};
	xsi_register_didat("work_m_16784184514082545356_4228301311", "isim/LAB06_01_LAB06_01_sch_tb_isim_beh.exe.sim/work/m_16784184514082545356_4228301311.didat");
	xsi_register_executes(pe);
}
