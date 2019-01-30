/*
** vm_fonction.h for  in /home/elodie.billiot/Corewar/CPE_2016_corewar/include
** 
** Made by Elodie Billiot
** Login   <elodie.billiot@epitech.net>
** 
** Started on  Mon Mar 13 11:14:21 2017 Elodie Billiot
** Last update Wed Mar 29 13:21:04 2017 Elodie Billiot
*/

#ifndef VM_FONCTION_H_
# define VM_FONCTION_H_

int       live_fonction(t_process *, char *, t_live *,
			t_champ *);
int       ld_fonction(t_process *, char *);
int       st_fonction(t_process *, char *);
int       add_fonction(t_process *, char *);
int       sub_fonction(t_process *, char *);
int       and_fonction(t_process *, char *);
int       or_fonction(t_process *, char *);
int       xor_fonction(t_process *, char *);
int       zjmp_fonction(t_process *, char *);
int       ldi_fonction(t_process *, char *);
int       sti_fonction(t_process *, char *);
int       fork_fonction(t_process *, char *);
int       lld_fonction(t_process *, char *);
int       lldi_fonction(t_process *, char *);
int       lfork_fonction(t_process *, char *);
int       aff_fonction(t_process *, char *);

#endif /* VM_FONCTION_H_ */
