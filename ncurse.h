/*
** ncurse.h for ncure in /home/marcha_j//test/c/ftrace
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Thu Jun 21 22:09:39 2012 hugo marchadier
** Last update Fri Jun 22 18:01:11 2012 hugo marchadier
*/

#ifndef NCURSE_H_
# define	NCURSE_H_

# define	color(c)	printf("\033[%sm", c)

# define	SIZE_BORDER	100
# define	SIZE_MAX_Y	150

# define	REINIT		"0"
# define	HIGH_DENSITY	"1"
# define	INVERSE		"7"
# define	FLASH		"5"

	/* FOR CHARACTERE */

# define	C_BLACK		"30"
# define	C_RED		"31"
# define	C_GREEN		"32"
# define	C_YELLOW	"33"
# define	C_BLUE		"34"
# define	C_MAGENTA	"35"
# define	C_CYAN		"36"
# define	C_WHITE		"37"

	/* FOR BACKGROUND */

# define	B_BLACK		"40"
# define	B_RED		"41"
# define	B_GREEN		"42"
# define	B_YELLOW	"43"
# define	B_BLUE		"44"
# define	B_MAGENTA	"45"
# define	B_CYAN		"46"
# define	B_WHITE		"47"

void	aff_tab_sym(char *name, unsigned int addr, char *COLOR);
void	aff_tab_header(char *name, char *COLOR);
void	aff_tab_footer();
void	aff_sym(char *sym, char *COLOR, char *B_COLOR, int pos);
void	aff_ret(char *sym, char *C_COLOR, char *B_COLOR, int pos);
void	aff_legende();

#endif /* !NCURSE_H_ */
