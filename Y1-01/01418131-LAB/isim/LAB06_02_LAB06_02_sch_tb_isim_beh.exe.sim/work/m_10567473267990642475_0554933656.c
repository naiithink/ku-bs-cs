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
static const char *ng0 = "A = %d, B = %d, C = %d, D = %d  :  C1 = %d, S1 = %d, S0 = %d";
static const char *ng1 = "/home/naiithink/in-Sync/Files/ISE_DS/CS131-LAB/Sources/LAB06_02_VeriTest.v";
static int ng2[] = {7, 0};
static int ng3[] = {1, 0};
static int ng4[] = {4, 0};
static int ng5[] = {5, 0};
static int ng6[] = {2, 0};
static int ng7[] = {6, 0};
static int ng8[] = {0, 0};

void Monitor_77_2(char *);
static void NetReassign_42_3(char *);
static void NetReassign_43_4(char *);
static void NetReassign_44_5(char *);
static void NetReassign_45_6(char *);
static void NetReassign_49_7(char *);
static void NetReassign_54_8(char *);
static void NetReassign_59_9(char *);
static void NetReassign_64_10(char *);
void Monitor_77_2(char *);


static void Monitor_77_2_Func(char *t0)
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
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;

LAB0:    t1 = (t0 + 2248);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t0 + 1768);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 1928);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t0 + 2088);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t0 + 1208U);
    t14 = *((char **)t13);
    t13 = (t0 + 1368U);
    t15 = *((char **)t13);
    t13 = (t0 + 1048U);
    t16 = *((char **)t13);
    xsi_vlogfile_write(1, 0, 3, ng0, 8, t0, (char)118, t3, 1, (char)118, t6, 1, (char)118, t9, 1, (char)118, t12, 1, (char)118, t14, 1, (char)118, t15, 1, (char)118, t16, 1);

LAB1:    return;
}

static void Initial_34_0(char *t0)
{
    char t6[8];
    char t17[8];
    char t23[8];
    char t24[8];
    char t32[8];
    char t72[8];
    char t80[8];
    char t81[8];
    char t89[8];
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
    char *t22;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;
    char *t37;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    char *t46;
    char *t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    int t56;
    int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    char *t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    char *t70;
    char *t71;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    char *t76;
    char *t77;
    char *t78;
    char *t79;
    char *t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    char *t88;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    char *t93;
    char *t94;
    char *t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    char *t103;
    char *t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    int t113;
    int t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    char *t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    char *t127;
    char *t128;

LAB0:    t1 = (t0 + 3320U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(35, ng1);

LAB4:    xsi_set_current_line(37, ng1);

LAB5:    t2 = (t0 + 2408);
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

LAB7:    xsi_set_current_line(71, ng1);
    xsi_vlog_finish(1);

LAB1:    return;
LAB6:    xsi_set_current_line(38, ng1);

LAB8:    xsi_set_current_line(40, ng1);
    t13 = (t0 + 2408);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t16 = ((char*)((ng3)));
    memset(t17, 0, 8);
    xsi_vlog_signed_add(t17, 32, t15, 32, t16, 32);
    t18 = (t0 + 2408);
    xsi_vlogvar_assign_value(t18, t17, 0, 0, 32);
    xsi_set_current_line(42, ng1);
    t2 = (t0 + 2248);
    xsi_set_assignedflag(t2);
    t3 = (t0 + 7920);
    *((int *)t3) = 1;
    NetReassign_42_3(t0);
    xsi_set_current_line(43, ng1);
    t2 = (t0 + 1768);
    xsi_set_assignedflag(t2);
    t3 = (t0 + 7924);
    *((int *)t3) = 1;
    NetReassign_43_4(t0);
    xsi_set_current_line(44, ng1);
    t2 = (t0 + 1928);
    xsi_set_assignedflag(t2);
    t3 = (t0 + 7928);
    *((int *)t3) = 1;
    NetReassign_44_5(t0);
    xsi_set_current_line(45, ng1);
    t2 = (t0 + 2088);
    xsi_set_assignedflag(t2);
    t3 = (t0 + 7932);
    *((int *)t3) = 1;
    NetReassign_45_6(t0);
    xsi_set_current_line(47, ng1);
    t2 = (t0 + 2408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t6, 0, 8);
    xsi_vlog_signed_greatereq(t6, 32, t4, 32, t5, 32);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB9;

LAB10:
LAB11:    xsi_set_current_line(52, ng1);
    t2 = (t0 + 2408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_signed_not_equal(t6, 32, t4, 32, t5, 32);
    memset(t17, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t7) != 0)
        goto LAB15;

LAB16:    t14 = (t17 + 4);
    t19 = *((unsigned int *)t17);
    t20 = *((unsigned int *)t14);
    t21 = (t19 || t20);
    if (t21 > 0)
        goto LAB17;

LAB18:    memcpy(t32, t17, 8);

LAB19:    t64 = (t32 + 4);
    t65 = *((unsigned int *)t64);
    t66 = (~(t65));
    t67 = *((unsigned int *)t32);
    t68 = (t67 & t66);
    t69 = (t68 != 0);
    if (t69 > 0)
        goto LAB27;

LAB28:
LAB29:    xsi_set_current_line(57, ng1);
    t2 = (t0 + 2408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_signed_not_equal(t6, 32, t4, 32, t5, 32);
    memset(t17, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB31;

LAB32:    if (*((unsigned int *)t7) != 0)
        goto LAB33;

LAB34:    t14 = (t17 + 4);
    t19 = *((unsigned int *)t17);
    t20 = *((unsigned int *)t14);
    t21 = (t19 || t20);
    if (t21 > 0)
        goto LAB35;

LAB36:    memcpy(t32, t17, 8);

LAB37:    t64 = (t32 + 4);
    t65 = *((unsigned int *)t64);
    t66 = (~(t65));
    t67 = *((unsigned int *)t32);
    t68 = (t67 & t66);
    t69 = (t68 != 0);
    if (t69 > 0)
        goto LAB45;

LAB46:
LAB47:    xsi_set_current_line(62, ng1);
    t2 = (t0 + 2408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_signed_not_equal(t6, 32, t4, 32, t5, 32);
    memset(t17, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB49;

LAB50:    if (*((unsigned int *)t7) != 0)
        goto LAB51;

LAB52:    t14 = (t17 + 4);
    t19 = *((unsigned int *)t17);
    t20 = *((unsigned int *)t14);
    t21 = (t19 || t20);
    if (t21 > 0)
        goto LAB53;

LAB54:    memcpy(t32, t17, 8);

LAB55:    memset(t72, 0, 8);
    t64 = (t32 + 4);
    t65 = *((unsigned int *)t64);
    t66 = (~(t65));
    t67 = *((unsigned int *)t32);
    t68 = (t67 & t66);
    t69 = (t68 & 1U);
    if (t69 != 0)
        goto LAB63;

LAB64:    if (*((unsigned int *)t64) != 0)
        goto LAB65;

LAB66:    t71 = (t72 + 4);
    t73 = *((unsigned int *)t72);
    t74 = *((unsigned int *)t71);
    t75 = (t73 || t74);
    if (t75 > 0)
        goto LAB67;

LAB68:    memcpy(t89, t72, 8);

LAB69:    t121 = (t89 + 4);
    t122 = *((unsigned int *)t121);
    t123 = (~(t122));
    t124 = *((unsigned int *)t89);
    t125 = (t124 & t123);
    t126 = (t125 != 0);
    if (t126 > 0)
        goto LAB77;

LAB78:
LAB79:    xsi_set_current_line(67, ng1);
    t2 = (t0 + 3128);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB81;
    goto LAB1;

LAB9:    xsi_set_current_line(48, ng1);

LAB12:    xsi_set_current_line(49, ng1);
    t13 = (t0 + 2248);
    xsi_set_assignedflag(t13);
    t14 = (t0 + 7936);
    *((int *)t14) = 1;
    NetReassign_49_7(t0);
    goto LAB11;

LAB13:    *((unsigned int *)t17) = 1;
    goto LAB16;

LAB15:    t13 = (t17 + 4);
    *((unsigned int *)t17) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB16;

LAB17:    t15 = (t0 + 2408);
    t16 = (t15 + 56U);
    t18 = *((char **)t16);
    t22 = ((char*)((ng4)));
    memset(t23, 0, 8);
    xsi_vlog_signed_not_equal(t23, 32, t18, 32, t22, 32);
    memset(t24, 0, 8);
    t25 = (t23 + 4);
    t26 = *((unsigned int *)t25);
    t27 = (~(t26));
    t28 = *((unsigned int *)t23);
    t29 = (t28 & t27);
    t30 = (t29 & 1U);
    if (t30 != 0)
        goto LAB20;

LAB21:    if (*((unsigned int *)t25) != 0)
        goto LAB22;

LAB23:    t33 = *((unsigned int *)t17);
    t34 = *((unsigned int *)t24);
    t35 = (t33 & t34);
    *((unsigned int *)t32) = t35;
    t36 = (t17 + 4);
    t37 = (t24 + 4);
    t38 = (t32 + 4);
    t39 = *((unsigned int *)t36);
    t40 = *((unsigned int *)t37);
    t41 = (t39 | t40);
    *((unsigned int *)t38) = t41;
    t42 = *((unsigned int *)t38);
    t43 = (t42 != 0);
    if (t43 == 1)
        goto LAB24;

LAB25:
LAB26:    goto LAB19;

LAB20:    *((unsigned int *)t24) = 1;
    goto LAB23;

LAB22:    t31 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t31) = 1;
    goto LAB23;

LAB24:    t44 = *((unsigned int *)t32);
    t45 = *((unsigned int *)t38);
    *((unsigned int *)t32) = (t44 | t45);
    t46 = (t17 + 4);
    t47 = (t24 + 4);
    t48 = *((unsigned int *)t17);
    t49 = (~(t48));
    t50 = *((unsigned int *)t46);
    t51 = (~(t50));
    t52 = *((unsigned int *)t24);
    t53 = (~(t52));
    t54 = *((unsigned int *)t47);
    t55 = (~(t54));
    t56 = (t49 & t51);
    t57 = (t53 & t55);
    t58 = (~(t56));
    t59 = (~(t57));
    t60 = *((unsigned int *)t38);
    *((unsigned int *)t38) = (t60 & t58);
    t61 = *((unsigned int *)t38);
    *((unsigned int *)t38) = (t61 & t59);
    t62 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t62 & t58);
    t63 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t63 & t59);
    goto LAB26;

LAB27:    xsi_set_current_line(53, ng1);

LAB30:    xsi_set_current_line(54, ng1);
    t70 = (t0 + 1768);
    xsi_set_assignedflag(t70);
    t71 = (t0 + 7940);
    *((int *)t71) = 1;
    NetReassign_54_8(t0);
    goto LAB29;

LAB31:    *((unsigned int *)t17) = 1;
    goto LAB34;

LAB33:    t13 = (t17 + 4);
    *((unsigned int *)t17) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB34;

LAB35:    t15 = (t0 + 2408);
    t16 = (t15 + 56U);
    t18 = *((char **)t16);
    t22 = ((char*)((ng5)));
    memset(t23, 0, 8);
    xsi_vlog_signed_not_equal(t23, 32, t18, 32, t22, 32);
    memset(t24, 0, 8);
    t25 = (t23 + 4);
    t26 = *((unsigned int *)t25);
    t27 = (~(t26));
    t28 = *((unsigned int *)t23);
    t29 = (t28 & t27);
    t30 = (t29 & 1U);
    if (t30 != 0)
        goto LAB38;

LAB39:    if (*((unsigned int *)t25) != 0)
        goto LAB40;

LAB41:    t33 = *((unsigned int *)t17);
    t34 = *((unsigned int *)t24);
    t35 = (t33 & t34);
    *((unsigned int *)t32) = t35;
    t36 = (t17 + 4);
    t37 = (t24 + 4);
    t38 = (t32 + 4);
    t39 = *((unsigned int *)t36);
    t40 = *((unsigned int *)t37);
    t41 = (t39 | t40);
    *((unsigned int *)t38) = t41;
    t42 = *((unsigned int *)t38);
    t43 = (t42 != 0);
    if (t43 == 1)
        goto LAB42;

LAB43:
LAB44:    goto LAB37;

LAB38:    *((unsigned int *)t24) = 1;
    goto LAB41;

LAB40:    t31 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t31) = 1;
    goto LAB41;

LAB42:    t44 = *((unsigned int *)t32);
    t45 = *((unsigned int *)t38);
    *((unsigned int *)t32) = (t44 | t45);
    t46 = (t17 + 4);
    t47 = (t24 + 4);
    t48 = *((unsigned int *)t17);
    t49 = (~(t48));
    t50 = *((unsigned int *)t46);
    t51 = (~(t50));
    t52 = *((unsigned int *)t24);
    t53 = (~(t52));
    t54 = *((unsigned int *)t47);
    t55 = (~(t54));
    t56 = (t49 & t51);
    t57 = (t53 & t55);
    t58 = (~(t56));
    t59 = (~(t57));
    t60 = *((unsigned int *)t38);
    *((unsigned int *)t38) = (t60 & t58);
    t61 = *((unsigned int *)t38);
    *((unsigned int *)t38) = (t61 & t59);
    t62 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t62 & t58);
    t63 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t63 & t59);
    goto LAB44;

LAB45:    xsi_set_current_line(58, ng1);

LAB48:    xsi_set_current_line(59, ng1);
    t70 = (t0 + 1928);
    xsi_set_assignedflag(t70);
    t71 = (t0 + 7944);
    *((int *)t71) = 1;
    NetReassign_59_9(t0);
    goto LAB47;

LAB49:    *((unsigned int *)t17) = 1;
    goto LAB52;

LAB51:    t13 = (t17 + 4);
    *((unsigned int *)t17) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB52;

LAB53:    t15 = (t0 + 2408);
    t16 = (t15 + 56U);
    t18 = *((char **)t16);
    t22 = ((char*)((ng6)));
    memset(t23, 0, 8);
    xsi_vlog_signed_not_equal(t23, 32, t18, 32, t22, 32);
    memset(t24, 0, 8);
    t25 = (t23 + 4);
    t26 = *((unsigned int *)t25);
    t27 = (~(t26));
    t28 = *((unsigned int *)t23);
    t29 = (t28 & t27);
    t30 = (t29 & 1U);
    if (t30 != 0)
        goto LAB56;

LAB57:    if (*((unsigned int *)t25) != 0)
        goto LAB58;

LAB59:    t33 = *((unsigned int *)t17);
    t34 = *((unsigned int *)t24);
    t35 = (t33 & t34);
    *((unsigned int *)t32) = t35;
    t36 = (t17 + 4);
    t37 = (t24 + 4);
    t38 = (t32 + 4);
    t39 = *((unsigned int *)t36);
    t40 = *((unsigned int *)t37);
    t41 = (t39 | t40);
    *((unsigned int *)t38) = t41;
    t42 = *((unsigned int *)t38);
    t43 = (t42 != 0);
    if (t43 == 1)
        goto LAB60;

LAB61:
LAB62:    goto LAB55;

LAB56:    *((unsigned int *)t24) = 1;
    goto LAB59;

LAB58:    t31 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t31) = 1;
    goto LAB59;

LAB60:    t44 = *((unsigned int *)t32);
    t45 = *((unsigned int *)t38);
    *((unsigned int *)t32) = (t44 | t45);
    t46 = (t17 + 4);
    t47 = (t24 + 4);
    t48 = *((unsigned int *)t17);
    t49 = (~(t48));
    t50 = *((unsigned int *)t46);
    t51 = (~(t50));
    t52 = *((unsigned int *)t24);
    t53 = (~(t52));
    t54 = *((unsigned int *)t47);
    t55 = (~(t54));
    t56 = (t49 & t51);
    t57 = (t53 & t55);
    t58 = (~(t56));
    t59 = (~(t57));
    t60 = *((unsigned int *)t38);
    *((unsigned int *)t38) = (t60 & t58);
    t61 = *((unsigned int *)t38);
    *((unsigned int *)t38) = (t61 & t59);
    t62 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t62 & t58);
    t63 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t63 & t59);
    goto LAB62;

LAB63:    *((unsigned int *)t72) = 1;
    goto LAB66;

LAB65:    t70 = (t72 + 4);
    *((unsigned int *)t72) = 1;
    *((unsigned int *)t70) = 1;
    goto LAB66;

LAB67:    t76 = (t0 + 2408);
    t77 = (t76 + 56U);
    t78 = *((char **)t77);
    t79 = ((char*)((ng7)));
    memset(t80, 0, 8);
    xsi_vlog_signed_not_equal(t80, 32, t78, 32, t79, 32);
    memset(t81, 0, 8);
    t82 = (t80 + 4);
    t83 = *((unsigned int *)t82);
    t84 = (~(t83));
    t85 = *((unsigned int *)t80);
    t86 = (t85 & t84);
    t87 = (t86 & 1U);
    if (t87 != 0)
        goto LAB70;

LAB71:    if (*((unsigned int *)t82) != 0)
        goto LAB72;

LAB73:    t90 = *((unsigned int *)t72);
    t91 = *((unsigned int *)t81);
    t92 = (t90 & t91);
    *((unsigned int *)t89) = t92;
    t93 = (t72 + 4);
    t94 = (t81 + 4);
    t95 = (t89 + 4);
    t96 = *((unsigned int *)t93);
    t97 = *((unsigned int *)t94);
    t98 = (t96 | t97);
    *((unsigned int *)t95) = t98;
    t99 = *((unsigned int *)t95);
    t100 = (t99 != 0);
    if (t100 == 1)
        goto LAB74;

LAB75:
LAB76:    goto LAB69;

LAB70:    *((unsigned int *)t81) = 1;
    goto LAB73;

LAB72:    t88 = (t81 + 4);
    *((unsigned int *)t81) = 1;
    *((unsigned int *)t88) = 1;
    goto LAB73;

LAB74:    t101 = *((unsigned int *)t89);
    t102 = *((unsigned int *)t95);
    *((unsigned int *)t89) = (t101 | t102);
    t103 = (t72 + 4);
    t104 = (t81 + 4);
    t105 = *((unsigned int *)t72);
    t106 = (~(t105));
    t107 = *((unsigned int *)t103);
    t108 = (~(t107));
    t109 = *((unsigned int *)t81);
    t110 = (~(t109));
    t111 = *((unsigned int *)t104);
    t112 = (~(t111));
    t113 = (t106 & t108);
    t114 = (t110 & t112);
    t115 = (~(t113));
    t116 = (~(t114));
    t117 = *((unsigned int *)t95);
    *((unsigned int *)t95) = (t117 & t115);
    t118 = *((unsigned int *)t95);
    *((unsigned int *)t95) = (t118 & t116);
    t119 = *((unsigned int *)t89);
    *((unsigned int *)t89) = (t119 & t115);
    t120 = *((unsigned int *)t89);
    *((unsigned int *)t89) = (t120 & t116);
    goto LAB76;

LAB77:    xsi_set_current_line(63, ng1);

LAB80:    xsi_set_current_line(64, ng1);
    t127 = (t0 + 2088);
    xsi_set_assignedflag(t127);
    t128 = (t0 + 7948);
    *((int *)t128) = 1;
    NetReassign_64_10(t0);
    goto LAB79;

LAB81:    goto LAB5;

}

static void Initial_74_1(char *t0)
{

LAB0:    xsi_set_current_line(75, ng1);

LAB2:    xsi_set_current_line(77, ng1);
    Monitor_77_2(t0);

LAB1:    return;
}

static void NetReassign_42_3(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 3816U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(42, ng1);
    t3 = 0;
    t2 = ((char*)((ng8)));
    t4 = (t0 + 7920);
    if (*((int *)t4) > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    t5 = (t0 + 2248);
    xsi_vlogvar_assignassignvalue(t5, t2, 0, 0, 0, 1, ((int*)(t4)));
    t3 = 1;
    goto LAB5;

}

static void NetReassign_43_4(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 4064U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(43, ng1);
    t3 = 0;
    t2 = ((char*)((ng8)));
    t4 = (t0 + 7924);
    if (*((int *)t4) > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    t5 = (t0 + 1768);
    xsi_vlogvar_assignassignvalue(t5, t2, 0, 0, 0, 1, ((int*)(t4)));
    t3 = 1;
    goto LAB5;

}

static void NetReassign_44_5(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 4312U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(44, ng1);
    t3 = 0;
    t2 = ((char*)((ng8)));
    t4 = (t0 + 7928);
    if (*((int *)t4) > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    t5 = (t0 + 1928);
    xsi_vlogvar_assignassignvalue(t5, t2, 0, 0, 0, 1, ((int*)(t4)));
    t3 = 1;
    goto LAB5;

}

static void NetReassign_45_6(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 4560U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(45, ng1);
    t3 = 0;
    t2 = ((char*)((ng8)));
    t4 = (t0 + 7932);
    if (*((int *)t4) > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    t5 = (t0 + 2088);
    xsi_vlogvar_assignassignvalue(t5, t2, 0, 0, 0, 1, ((int*)(t4)));
    t3 = 1;
    goto LAB5;

}

static void NetReassign_49_7(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 4808U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(49, ng1);
    t3 = 0;
    t2 = ((char*)((ng3)));
    t4 = (t0 + 7936);
    if (*((int *)t4) > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    t5 = (t0 + 2248);
    xsi_vlogvar_assignassignvalue(t5, t2, 0, 0, 0, 1, ((int*)(t4)));
    t3 = 1;
    goto LAB5;

}

static void NetReassign_54_8(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 5056U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(54, ng1);
    t3 = 0;
    t2 = ((char*)((ng3)));
    t4 = (t0 + 7940);
    if (*((int *)t4) > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    t5 = (t0 + 1768);
    xsi_vlogvar_assignassignvalue(t5, t2, 0, 0, 0, 1, ((int*)(t4)));
    t3 = 1;
    goto LAB5;

}

static void NetReassign_59_9(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 5304U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(59, ng1);
    t3 = 0;
    t2 = ((char*)((ng3)));
    t4 = (t0 + 7944);
    if (*((int *)t4) > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    t5 = (t0 + 1928);
    xsi_vlogvar_assignassignvalue(t5, t2, 0, 0, 0, 1, ((int*)(t4)));
    t3 = 1;
    goto LAB5;

}

static void NetReassign_64_10(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 5552U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(64, ng1);
    t3 = 0;
    t2 = ((char*)((ng3)));
    t4 = (t0 + 7948);
    if (*((int *)t4) > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    t5 = (t0 + 2088);
    xsi_vlogvar_assignassignvalue(t5, t2, 0, 0, 0, 1, ((int*)(t4)));
    t3 = 1;
    goto LAB5;

}

void Monitor_77_2(char *t0)
{
    char *t1;
    char *t2;

LAB0:    t1 = (t0 + 5608);
    t2 = (t0 + 6120);
    xsi_vlogfile_monitor((void *)Monitor_77_2_Func, t1, t2);

LAB1:    return;
}


extern void work_m_10567473267990642475_0554933656_init()
{
	static char *pe[] = {(void *)Initial_34_0,(void *)Initial_74_1,(void *)NetReassign_42_3,(void *)NetReassign_43_4,(void *)NetReassign_44_5,(void *)NetReassign_45_6,(void *)NetReassign_49_7,(void *)NetReassign_54_8,(void *)NetReassign_59_9,(void *)NetReassign_64_10,(void *)Monitor_77_2};
	xsi_register_didat("work_m_10567473267990642475_0554933656", "isim/LAB06_02_LAB06_02_sch_tb_isim_beh.exe.sim/work/m_10567473267990642475_0554933656.didat");
	xsi_register_executes(pe);
}
