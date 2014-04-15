/*
** defines.h for defines in /home/l-huil_o//test/strace/tp/tp2
** 
** Made by olivier l-huillier
** Login   <l-huil_o@epitech.net>
** 
** Started on  Wed May  2 17:28:27 2012 olivier l-huillier
** Last update Fri Jun 22 17:27:59 2012 hugo marchadier
*/

#ifndef DEFINES_H_
# define DEFINES_H_

typedef enum	e_signal
  {
    NO = 0,
    YES
  }		eSIGNAL;

typedef struct	s_syscall
{
  int		nargs;
  const char	*sys_name;
  char		*token;
  eSIGNAL	is_signal;		
}		t_syscall;

#define VOID	'0'
#define NUM	'1'
#define STR	'2'
#define ADDR	'3'
#define CHAR	'4'

const t_syscall g_tab_syscall[] =
  {
    { 3,	"read", "1211", NO},			/* 0 */
    { 3,	"write", "1211", NO},			/* 1 */
    { 3,	"open", "2111", NO},			/* 2 */
    { 1,	"close", "11", NO},			/* 3 */
    { 2,	"stat", "231", NO},			/* 4 */
    { 2,	"fstat", "131", NO},			/* 5 */
    { 2,	"lstat", "213", NO},			/* 6 */
    { 3,	"poll", "3111", NO},			/* 7 */
    { 3,	"lseek", "1111", NO},	  		/* 8 */
    { 6,	"mmap", "3111113", NO},  		/* 9 */
    { 3,	"mprotect", "3111", NO},  		/* 10 */
    { 2,	"munmap", "311", NO},			/* 11 */
    { 1,	"brk", "31", NO},			/* 12 */
    { 4,	"rt_sigaction", "13331", YES},		/* 13 */
    { 4,	"rt_sigprocmask", "13331", YES},  	/* 14 */
    { 1,	"rt_sigreturn", "11", YES},		/* 15 */
    { 3,	"ioctl", "1111", NO},			/* 16 */
    { 4,	"pread"	, "12111", NO},  		/* 17 */
    { 4,	"pwrite", "12111", NO},  		/* 18 */
    { 3,	"readv"	, "1311", NO},  		/* 19 */
    { 3,	"writev", "1311", NO},  		/* 20 */
    { 2,	"access", "211", NO},			/* 21 */
    { 1,	"pipe", "31", NO},			/* 22 */
    { 5,	"select", "133331", NO},  		/* 23 */
    { 1,	"sched_yield", "01", NO},  		/* 24 */
    { 5,	"mremap", "311133", NO},  		/* 25 */
    { 3,	"msync", "3111", NO},			/* 26 */
    { 3,	"mincore", "3121", NO},  		/* 27 */
    { 3,	"madvise", "3111", NO},  		/* 28 */
    { 3,	"shmget", "1111", NO},  		/* 29 */
    { 3,	"shmat", "1313", NO},			/* 30 */
    { 3,	"shmctl", "1131", NO},	 		/* 31 */
    { 1,	"dup", "11", NO},			/* 32 */
    { 2,	"dup2", "111", NO},			/* 33 */
    { 1,	"pause", "01", NO},			/* 34 */
    { 2,	"nanosleep", "331", NO},  		/* 35 */
    { 2,	"getitimer", "131", NO},  		/* 36 */
    { 1,	"alarm", "11", NO},			/* 37 */
    { 3,	"setitimer", "1331", NO},  		/* 38 */
    { 1,	"getpid", "01", NO},			/* 39 */
    { 4,	"sendfile", "11311", NO},  		/* 40 */
    { 3,	"socket", "1111", NO},  		/* 41 */
    { 3,	"connect", "1311", NO},  		/* 42 */
    { 3,	"accept", "1331", NO},  		/* 43 */
    { 6,	"sendto", "1211311", NO},  		/* 44 */
    { 6,	"recvfrom", "1211331", NO},		/* 45 */
    { 3,	"sendmsg", "1311", NO},  		/* 46 */
    { 3,	"recvmsg", "1311", NO},  		/* 47 */
    { 2,	"shutdown", "111", NO},  		/* 48 */
    { 3,	"bind", "1311", NO},			/* 49 */
    { 2,	"listen", "111", NO},			/* 50 */
    { 3,	"getsockname", "1331", NO},		/* 51 */
    { 3,	"getpeername", "1331", NO},		/* 52 */
    { 4,	"socketpair", "11131", NO},		/* 53 */
    { 5,	"setsockopt", "111311", NO},		/* 54 */
    { 5,	"getsockopt", "111331", NO},		/* 55 */
    { 5,	"clone", "331331", NO},  		/* 56 */
    { 1,	"fork", "01", NO},			/* 57 */
    { 1,	"vfork", "01", NO},			/* 58 */
    { 3,	"execve", "2111", NO},  		/* 59 */
    { 1,	"_exit", "10", NO},			/* 60 */
    { 4,	"wait4", "13131", NO},  		/* 61 */
    { 2,	"kill", "111", YES},			/* 62 */
    { 1,	"uname", "31", NO},			/* 63 */
    { 3,	"semget", "1111", NO},  		/* 64 */
    { 3,	"semop", "1311", NO},			/* 65 */
    { 4,	"semctl", "11131", NO},  		/* 66 */
    { 1,	"shmdt", "31", NO},			/* 67 */
    { 2,	"msgget", "111", NO},			/* 68 */
    { 4,	"msgsnd", "13111", NO},  		/* 69 */
    { 5,	"msgrcv", "121111", NO},  		/* 70 */
    { 3,	"msgctl", "1131", NO},  		/* 71 */
    { 3,	"fcntl", "1131", NO},	  		/* 72 */
    { 2,	"flock", "111", NO},			/* 73 */
    { 1,	"fsync", "11", NO},			/* 74 */
    { 1,	"fdatasync", "11", NO},  		/* 75 */
    { 2,	"truncate", "211", NO},  		/* 76 */
    { 2,	"ftruncate", "111", NO},  		/* 77 */
    { 3,	"getdents", "1211", NO},  		/* 78 */
    { 2,	"getcwd", "211", NO},			/* 79 */
    { 1,	"chdir", "21", NO},			/* 80 */
    { 1,	"fchdir", "11", NO},			/* 81 */
    { 2,	"rename", "221", NO},			/* 82 */
    { 2,	"mkdir", "211", NO},			/* 83 */
    { 1,	"rmdir", "21", NO},			/* 84 */
    { 2,	"creat", "211", NO},			/* 85 */
    { 2,	"link", "221", NO},			/* 86 */
    { 1,	"unlink", "21", NO},			/* 87 */
    { 2,	"symlink", "221", NO},  		/* 88 */
    { 3,	"readlink", "2211", NO},  		/* 89 */
    { 2,	"chmod", "211", NO},			/* 90 */
    { 2,	"fchmod", "111", NO},			/* 91 */
    { 3,	"chown", "2111", NO},			/* 92 */
    { 3,	"fchown", "1111", NO},  		/* 93 */
    { 3,	"lchown", "2111", NO},  		/* 94 */
    { 1,	"umask", "11", NO},			/* 95 */
    { 2,	"gettimeofday", "331", NO},		/* 96 */
    { 2,	"getrlimit", "131", NO},  		/* 97 */
    { 2,	"getrusage", "131", NO},  		/* 98 */
    { 1,	"sysinfo", "31", NO},			/* 99 */
    { 1,	"times", "31", NO},			/* 100 */
    { 4,	"ptrace", "11331", NO},  		/* 101 */
    { 1,	"getuid", "01", NO},			/* 102 */
    { 3,	"syslog", "1211", NO},  		/* 103 */
    { 1,	"getgid", "01", NO},			/* 104 */
    { 1,	"setuid", "11", NO},			/* 105 */
    { 1,	"setgid", "11", NO},			/* 106 */
    { 1,	"geteuid", "01", NO},			/* 107 */
    { 1,	"getegid", "01", NO},			/* 108 */
    { 2,	"setpgid", "111", NO},  		/* 109 */
    { 1,	"getppid", "11", NO},			/* 110 */
    { 1,	"getpgrp", "01", NO},			/* 111 */
    { 1,	"setsid", "01", NO},			/* 112 */
    { 2,	"setreuid", "111", NO},  		/* 113 */
    { 2,	"setregid", "111", NO},  		/* 114 */
    { 2,	"getgroups", "131", NO},  		/* 115 */
    { 2,	"setgroups", "131", NO},  		/* 116 */
    { 3,	"setresuid", "1111", NO},  		/* 117 */
    { 3,	"getresuid", "3331", NO},  		/* 118 */
    { 3,	"setresgid", "1111", NO},  		/* 119 */
    { 3,	"getresgid", "3331", NO},  		/* 120 */
    { 1,	"getpgid", "11", NO},			/* 121 */
    { 1,	"setfsuid", "11", NO},  		/* 122 */
    { 1,	"setfsgid", "11", NO},  		/* 123 */
    { 1,	"getsid", "11", NO},			/* 124 */
    { 2,	"capget", "331", NO},			/* 125 */
    { 2,	"capset", "331", NO},			/* 126 */
    { 2,	"rt_sigpending", "311", YES},		/* 127 */
    { 4,	"rt_sigtimedwait", "33311", YES},  	/* 128 */
    { 3,	"rt_sigqueueinfo", "1131", YES},  	/* 129 */
    { 2,	"rt_sigsuspend", "331", YES},	  	/* 130 */
    { 2,	"sigaltstack", "331", YES},		/* 131 */
    { 2,	"utime", "231", NO},			/* 132 */
    { 3,	"mknod", "2111", NO},			/* 133 */
    { 1,	"uselib", "21", NO},			/* 134 */
    { 1,	"personality", "11", NO},  		/* 135 */
    { 2,	"ustat", "131", NO},			/* 136 */
    { 2,	"statfs", "231", NO},			/* 137 */
    { 2,	"fstatfs", "131", NO},  		/* 138 */
    { 3,	"sysfs", "1331", NO},			/* 139 */
    { 2,	"getpriority", "111", NO},		/* 140 */
    { 3,	"setpriority", "1111", NO},		/* 141 */
    { 2,	"sched_setparam", "131", NO},		/* 142 */
    { 2,	"sched_getparam", "131", NO},		/* 143 */
    { 3,	"sched_setscheduler", "1131", NO},	/* 144 */
    { 1,	"sched_getscheduler", "11", NO},  	/* 145 */
    { 1,	"sched_get_priority_max", "11", NO},	/* 146 */
    { 1,	"sched_get_priority_min", "11", NO},	/* 147 */
    { 2,	"sched_rr_get_interval", "131", NO},	/* 148 */
    { 2,	"mlock", "311", NO},			/* 149 */
    { 2,	"munlock", "311", NO},  		/* 150 */
    { 1,	"mlockall", "11", NO},  		/* 151 */
    { 1,	"munlockall", "01", NO},  		/* 152 */
    { 1,	"vhangup", "01", NO},			/* 153 */
    { 3,	"modify_ldt", "1311", NO},		/* 154 */
    { 2,	"pivot_root", "221", NO},  		/* 155 */
    { 1,	"_sysctl", "31", NO},			/* 156 */
    { 5,	"prctl", "111111", NO},  		/* 157 */
    { 2,	"arch_prctl", "131", NO},  		/* 158 */
    { 1,	"adjtimex", "31", NO},  		/* 159 */
    { 2,	"setrlimit", "131", NO},  		/* 160 */
    { 1,	"chroot", "21", NO},			/* 161 */
    { 1,	"sync", "00", NO},			/* 162 */
    { 1,	"acct", "21", NO},			/* 163 */
    { 2,	"settimeofday", "331", NO},		/* 164 */
    { 5,	"mount", "222131", NO},  		/* 165 */
    { 2,	"umount2", "211", NO},			/* 166 */
    { 2,	"swapon", "211", NO},			/* 167 */
    { 1,	"swapoff", "21", NO},			/* 168 */
    { 3,	"reboot", "1131", NO},  		/* 169 */
    { 2,	"sethostname", "211", NO},		/* 170 */
    { 2,	"setdomainname", "211", NO},		/* 171 */
    { 1,	"iopl", "11", NO},			/* 172 */
    { 3,	"ioperm", "1111", NO},  		/* 173 */
    { 2,	"create_module", "213", NO},		/* 174 */
    { 2,	"init_module", "231", NO},		/* 175 */
    { 1,	"delete_module", "21", NO},		/* 176 */
    { 1,	"get_kernel_syms", "31", NO},		/* 177 */
    { 5,	"query_module", "212131", NO},  	/* 178 */
    { 4,	"quotactl", "14131", NO},  		/* 179 */
    { 3,	"nfsservctl", "1331", NO},		/* 180 */
    { 5,	"getpmsg", NULL, NO},			/* 181 */
    { 5,	"putpmsg", NULL, NO},			/* 182 */
    { 5,	"afs_syscall", NULL, NO},  		/* 183 */
    { 3,	"tuxcall", NULL, NO},			/* 184 */
    { 3,	"security", NULL, NO},			/* 185 */
    { 1,	"gettid", "01", NO},			/* 186 */
    { 3,	"readahead", "1111", NO}, 		/* 187 */
    { 5,	"setxattr", "223111", NO}, 		/* 188 */
    { 5,	"lsetxattr", "223111", NO},		/* 189 */
    { 5,	"fsetxattr", "123111", NO},		/* 190 */
    { 4,	"getxattr", "22311", NO}, 		/* 191 */
    { 4,	"lgetxattr", "22311", NO}, 		/* 192 */
    { 4,	"fgetxattr", "12311", NO}, 		/* 193 */
    { 3,	"listxattr", "2211", NO}, 		/* 194 */
    { 3,	"llistxattr", "2211", NO}, 		/* 195 */
    { 3,	"flistxattr", "1211", NO}, 		/* 196 */
    { 2,	"removexattr", "221", NO}, 		/* 197 */
    { 2,	"lremovexattr", "221", NO},		/* 198 */
    { 2,	"fremovexattr", "121", NO},		/* 199 */
    { 2,	"tkill", "111", YES},			/* 200 */
    { 1,	"time", "33", NO},			/* 201 */
    { 6,	"futex", "3113311", NO}, 		/* 202 */
    { 3,	"sched_setaffinity", "1131", NO},	/* 203 */
    { 3,	"sched_getaffinity", "1131", NO},	/* 204 */
    { 1,	"set_thread_area", "31", NO},		/* 205 */
    { 2,	"io_setup", "131", NO}, 		/* 206 */
    { 1,	"io_destroy", "31", NO}, 		/* 207 */
    { 5,	"io_getevents", "311331", NO},		/* 208 */
    { 3,	"io_submit", "3131", NO}, 		/* 209 */
    { 3,	"io_cancel", "3331", NO}, 		/* 210 */
    { 1,	"get_thread_area", "31", NO},		/* 211 */
    { 3,	"lookup_dcookie", "1211", NO},		/* 212 */
    { 1,	"epoll_create", "11", NO}, 		/* 213 */
    { 4,	"epoll_ctl_old", NULL, NO},		/* 214 */
    { 4,	"epoll_wait_old", NULL, NO},		/* 215 */
    { 5,	"remap_file_pages", "311111", NO}, 	/* 216 */
    { 3,	"getdents64", "1311", NO}, 		/* 217 */
    { 1,	"set_tid_address", "31", NO},		/* 218 */
    { 1,	"restart_syscall", "01", NO},		/* 219 */
    { 4,	"semtimedop", "13131", NO},		/* 220 */
    { 4,	"fadvise64", "11111", NO}, 		/* 221 */
    { 3,	"timer_create", "1331", NO},		/* 222 */
    { 4,	"timer_settime", "11331", NO},		/* 223 */
    { 2,	"timer_gettime", "131", NO},		/* 224 */
    { 1,	"timer_getoverrun", "11", NO},		/* 225 */
    { 1,	"timer_delete", "11", NO}, 		/* 226 */
    { 2,	"clock_settime", "131", NO},		/* 227 */
    { 2,	"clock_gettime", "131", NO},		/* 228 */
    { 2,	"clock_getres", "131", NO},		/* 229 */
    { 4,	"clock_nanosleep", "11331", NO}, 	/* 230 */
    { 1,	"exit_group", "10", NO}, 		/* 231 */
    { 4,	"epoll_wait", "13111", NO},		/* 232 */
    { 4,	"epoll_ctl", "11131", NO}, 		/* 233 */
    { 3,	"tgkill", "1111", YES},			/* 234 */
    { 2,	"utimes", "231", NO},			/* 235 */
    { 5,	"vserver", NULL, NO},			/* 236 */
    { 6,	"mbind", "3113111", NO}, 		/* 237 */
    { 3,	"set_mempolicy", "1311", NO},		/* 238 */
    { 5,	"get_mempolicy", "331111", NO}, 	/* 239 */
    { 4,	"mq_open", "21133", NO}, 		/* 240 */
    { 1,	"mq_unlink", "21", NO}, 		/* 241 */
    { 5,	"mq_timedsend", "121331", NO},		/* 242 */
    { 5,	"mq_timedreceive", "121331", NO}, 	/* 243 */
    { 2,	"mq_notify", "131", NO}, 		/* 244 */
    { 3,	"mq_getsetattr", "1331", NO},	 	/* 245 */
    { 4,	"kexec_load", "11311", NO},	 	/* 246 */
    { 4,	"waitid", "11311", NO}, 		/* 247 */
    { 5,	"add_key", "223111", NO}, 		/* 248 */
    { 4,	"request_key", "22211", NO},		/* 249 */
    { 2,	"keyctl", "131", NO},			/* 250 */
    { 3,	"ioprio_set", "1111", NO}, 		/* 251 */
    { 2,	"ioprio_get", "111", NO}, 		/* 252 */
    { 1,	"inotify_init", "01", NO}, 		/* 253 */
    { 3,	"inotify_add_watch", "1211", NO}, 	/* 254 */
    { 2,	"inotify_rm_watch", "111", NO}, 	/* 255 */
    { 4,	"migrate_pages", "11331", NO},		/* 256 */
    { 4,	"openat", "12131", NO}, 		/* 257 */
    { 3,	"mkdirat", "1211", NO}, 		/* 258 */
    { 4,	"mknodat", "12111", NO}, 		/* 259 */
    { 5,	"fchownat", "121111", NO}, 		/* 260 */
    { 3,	"futimesat", "1231", NO}, 		/* 261 */
    { 4,	"newfstatat", NULL, NO}, 		/* 262 */
    { 3,	"unlinkat", "1211", NO}, 		/* 263 */
    { 4,	"renameat", "12121", NO}, 		/* 264 */
    { 5,	"linkat", "121211", NO}, 		/* 265 */
    { 3,	"symlinkat", "2121", NO}, 		/* 266 */
    { 4,	"readlinkat", "12211", NO},		/* 267 */
    { 4,	"fchmodat", "12111", NO}, 		/* 268 */
    { 4,	"faccessat", "12111", NO}, 		/* 269 */
    { 6,	"pselect6", "1333331", NO},		/* 270 */
    { 4,	"ppoll", "31331", NO},			/* 271 */
    { 1,	"unshare", "11", NO},			/* 272 */
    { 2,	"set_robust_list", "311", NO},		/* 273 */
    { 3,	"get_robust_list", "1331", NO}, 	/* 274 */
    { 6,	"splice", "1313111", NO}, 		/* 275 */
    { 4,	"tee", "11111", NO},			/* 276 */
    { 4,	"sync_file_range", "11111", NO}, 	/* 277 */
    { 4,	"vmsplice", "13111", NO}, 		/* 278 */
    { 6,	"move_pages", "1133311", NO},		/* 279 */
    { 4,	"utimensat", "12311", NO}, 		/* 280 */
    { 5,	"epoll_pwait", "131131", NO},		/* 281 */
    { 3,	"signalfd", "1311", NO}, 		/* 282 */
    { 2,	"timerfd_create", "111", NO},		/* 283 */
    { 2,	"eventfd", "111", NO},			/* 284 */
    { 4,	"fallocate", "11111", NO}, 		/* 285 */
    { 4,	"timerfd_settime", "11331", NO}, 	/* 286 */
    { 2,	"timerfd_gettime", "131", NO},		/* 287 */
    { 4,	"accept4", "13311", NO}, 		/* 288 */
    { 3,	"signalfd4", "1311", NO}, 		/* 289 */
    { 2,	"eventfd2", "111", NO}, 		/* 290 */
    { 1,	"epoll_create1", "11", NO},		/* 291 */
    { 3,	"dup3", "1111", NO},			/* 292 */
    { 2,	"pipe2", "311", NO},			/* 293 */
    { 1,	"inotify_init1", "11", NO},		/* 294 */
    { 4,	"preadv", "13111", NO}, 		/* 295 */
    { 4,	"pwritev", "13111", NO}, 		/* 296 */
    { 4,	"rt_tgsigqueueinfo", "11131", YES}, 	/* 297 */
    { 5,	"perf_event_open", NULL, NO},	 	/* 298 */
    { 5,	"recvmmsg", "131131", NO}, 		/* 299 */
    {-1, NULL, NULL, NO},
  };

# endif 		/* DEFINES_H_ */
