/*
** check_if_call.c for check_if_call in /home/marcha_j//svn/c/ftrace-2015-2014s-marcha_j
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Fri Jun 22 14:49:40 2012 hugo marchadier
** Last update Fri Jun 22 18:04:53 2012 hugo marchadier
*/

#include <stdlib.h>
#include <stdio.h>

#include <sys/user.h>
#include <sys/ptrace.h>

#include "ftrace.h"
#include "xfct.h"
#include "decode_mode_rm.h"

#define IS_CALL_E8(a)		(((a) & 0xff) == 0xe8)
#define IS_CALL_FF(a)		((((a) & 0xff) == 0xff))

static eTYPE	call_e8(struct user_regs_struct *regs,
			unsigned int *addr, t_info *info)
{
  *addr = xptrace(PTRACE_PEEKTEXT, info->pid,
		  (void*)regs->rip + 1, 0) + regs->rip + 5;
  info->size_call = SIZE_CALL_E8;
  return (eCALL);
}

static eTYPE	call_ff(struct user_regs_struct *regs,
			unsigned int *addr, t_info *info)
{
  t_prefix	mode_rm;
  eSTATUS	status_rm;
  unsigned char  *instr_tab;

  instr_tab = (unsigned char *)&(info->instr);
  mode_rm.c = instr_tab[1];
  if (mode_rm.pref.reg != 2 && mode_rm.pref.reg != 3)
    return (eNO);
  status_rm = GOOD;
  *addr = decode_mode_rm(regs, &status_rm, mode_rm, info);
  if (status_rm == ERROR || status_rm == NONE)
    return (eNO);
  return (eCALL);
}

eTYPE		check_if_call(struct user_regs_struct *regs,
			      unsigned int *addr, t_info *info)
{
  info->instr = 0;
  info->instr = xptrace(PTRACE_PEEKTEXT, info->pid, (void*)regs->rip, 0);
  if (info->status_call == ERROR)
    {
      info->status_call = GOOD;
      *addr = regs->rip;
      return (eCALL);
    }
  if (IS_CALL_E8(info->instr))
    return (call_e8(regs, addr, info));
  if (IS_CALL_FF(info->instr))
    return (call_ff(regs, addr, info));
  return (eNO);
}
