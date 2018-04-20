#define __SYSCALL_LL_E(x) (x)
#define __SYSCALL_LL_O(x) (x)

#define __asm_syscall(...) do { \
        __asm__ __volatile__ ( "svc 0" \
        : "=r"(x0) : __VA_ARGS__ : "memory", "cc"); \
        return x0; \
        } while (0)

static inline long __syscall0(long n)
{
        register long x8 __asm__("x8") = n;
        register long x0 __asm__("x0");
        __asm_syscall("r"(x8));
}

static inline long __syscall1(long n, long a)
{
        register long x8 __asm__("x8") = n;
        register long x0 __asm__("x0") = a;
        __asm_syscall("r"(x8), "0"(x0));
}

static inline long __syscall2(long n, long a, long b)
{
        register long x8 __asm__("x8") = n;
        register long x0 __asm__("x0") = a;
        register long x1 __asm__("x1") = b;
        __asm_syscall("r"(x8), "0"(x0), "r"(x1));
}

static inline long __syscall3(long n, long a, long b, long c)
{
        register long x8 __asm__("x8") = n;
        register long x0 __asm__("x0") = a;
        register long x1 __asm__("x1") = b;
        register long x2 __asm__("x2") = c;
        __asm_syscall("r"(x8), "0"(x0), "r"(x1), "r"(x2));
}

static inline long __syscall4(long n, long a, long b, long c, long d)
{
        register long x8 __asm__("x8") = n;
        register long x0 __asm__("x0") = a;
        register long x1 __asm__("x1") = b;
        register long x2 __asm__("x2") = c;
        register long x3 __asm__("x3") = d;
        __asm_syscall("r"(x8), "0"(x0), "r"(x1), "r"(x2), "r"(x3));
}

static inline long __syscall5(long n, long a, long b, long c, long d, long e)
{
        register long x8 __asm__("x8") = n;
        register long x0 __asm__("x0") = a;
        register long x1 __asm__("x1") = b;
        register long x2 __asm__("x2") = c;
        register long x3 __asm__("x3") = d;
        register long x4 __asm__("x4") = e;
        __asm_syscall("r"(x8), "0"(x0), "r"(x1), "r"(x2), "r"(x3), "r"(x4));
}

static inline long __syscall6(long n, long a, long b, long c, long d, long e, long f)
{
        register long x8 __asm__("x8") = n;
        register long x0 __asm__("x0") = a;
        register long x1 __asm__("x1") = b;
        register long x2 __asm__("x2") = c;
        register long x3 __asm__("x3") = d;
        register long x4 __asm__("x4") = e;
        register long x5 __asm__("x5") = f;
        __asm_syscall("r"(x8), "0"(x0), "r"(x1), "r"(x2), "r"(x3), "r"(x4), "r"(x5));
}

#define VDSO_USEFUL
#define VDSO_CGT_SYM "__kernel_clock_gettime"
#define VDSO_CGT_VER "LINUX_2.6.39"

/*
#define __SYSCALL_LL_E(x) \
((union { long long ll; long l[2]; }){ .ll = x }).l[0], \
((union { long long ll; long l[2]; }){ .ll = x }).l[1]
#define __SYSCALL_LL_O(x) 0, __SYSCALL_LL_E((x))

long (__syscall)(long, ...);

static inline long __syscall0(long n)
{
	return (__syscall)(n, 0, 0, 0, 0, 0, 0);
}

static inline long __syscall1(long n, long a)
{
	return (__syscall)(n, a, 0, 0, 0, 0, 0);
}

static inline long __syscall2(long n, long a, long b)
{
	return (__syscall)(n, a, b, 0, 0, 0, 0);
}

static inline long __syscall3(long n, long a, long b, long c)
{
	return (__syscall)(n, a, b, c, 0, 0, 0);
}

static inline long __syscall4(long n, long a, long b, long c, long d)
{
	return (__syscall)(n, a, b, c, d, 0, 0);
}

static inline long __syscall5(long n, long a, long b, long c, long d, long e)
{
	return (__syscall)(n, a, b, c, d, e, 0);
}

static inline long __syscall6(long n, long a, long b, long c, long d, long e, long f)
{
	return (__syscall)(n, a, b, c, d, e, f);
}
*/
#define __socketcall(nm,a,b,c,d,e,f) syscall(SYS_##nm, a, b, c, d, e, f)
#define __socketcall_cp(nm,a,b,c,d,e,f) syscall_cp(SYS_##nm, a, b, c, d, e, f)

#define __NR_restart_syscall	0
#define __NR_exit	1
#define __NR_fork	2
#define __NR_read	3
#define __NR_write	4
#define __NR_open	5
#define __NR_close	6
#define __NR_creat	8
#define __NR_link	9
#define __NR_unlink	10
#define __NR_execve	11
#define __NR_chdir	12
#define __NR_time	13
#define __NR_mknod	14
#define __NR_chmod	15
#define __NR_lchown	16
#define __NR_lseek	19
#define __NR_getpid	20
#define __NR_mount	21
#define __NR_umount	22
#define __NR_setuid	23
#define __NR_getuid	24
#define __NR_stime	25
#define __NR_ptrace	26
#define __NR_alarm	27
#define __NR_pause	29
#define __NR_utime	30
#define __NR_access	33
#define __NR_nice	34
#define __NR_sync	36
#define __NR_kill	37
#define __NR_rename	38
#define __NR_mkdir	39
#define __NR_rmdir	40
#define __NR_dup	41
#define __NR_pipe	42
#define __NR_times	43
#define __NR_brk	45
#define __NR_setgid	46
#define __NR_getgid	47
#define __NR_geteuid	49
#define __NR_getegid	50
#define __NR_acct	51
#define __NR_umount2	52
#define __NR_ioctl	54
#define __NR_fcntl	55
#define __NR_setpgid	57
#define __NR_umask	60
#define __NR_chroot	61
#define __NR_ustat	62
#define __NR_dup2	63
#define __NR_getppid	64
#define __NR_getpgrp	65
#define __NR_setsid	66
#define __NR_sigaction	67
#define __NR_setreuid	70
#define __NR_setregid	71
#define __NR_sigsuspend	72
#define __NR_sigpending	73
#define __NR_sethostname	74
#define __NR_setrlimit	75
#define __NR_getrusage	77
#define __NR_gettimeofday	78
#define __NR_settimeofday	79
#define __NR_getgroups	80
#define __NR_setgroups	81
#define __NR_select	82
#define __NR_symlink	83
#define __NR_readlink	85
#define __NR_uselib	86
#define __NR_swapon	87
#define __NR_reboot	88
#define __NR_readdir	89
#define __NR_mmap	90
#define __NR_munmap	91
#define __NR_truncate	92
#define __NR_ftruncate	93
#define __NR_fchmod	94
#define __NR_fchown	95
#define __NR_getpriority	96
#define __NR_setpriority	97
#define __NR_statfs	99
#define __NR_fstatfs	100
#define __NR_socketcall	102
#define __NR_syslog	103
#define __NR_setitimer	104
#define __NR_getitimer	105
#define __NR_stat	106
#define __NR_lstat	107
#define __NR_fstat	108
#define __NR_vhangup	111
#define __NR_syscall	113
#define __NR_wait4	114
#define __NR_swapoff	115
#define __NR_sysinfo	116
#define __NR_ipc	117
#define __NR_fsync	118
#define __NR_sigreturn	119
#define __NR_clone	120
#define __NR_setdomainname	121
#define __NR_uname	122
#define __NR_adjtimex	124
#define __NR_mprotect	125
#define __NR_sigprocmask	126
#define __NR_init_module	128
#define __NR_delete_module	129
#define __NR_quotactl	131
#define __NR_getpgid	132
#define __NR_fchdir	133
#define __NR_bdflush	134
#define __NR_sysfs	135
#define __NR_personality	136
#define __NR_setfsuid	138
#define __NR_setfsgid	139
#define __NR__llseek	140
#define __NR_getdents	141
#define __NR__newselect	142
#define __NR_flock	143
#define __NR_msync	144
#define __NR_readv	145
#define __NR_writev	146
#define __NR_getsid	147
#define __NR_fdatasync	148
#define __NR__sysctl	149
#define __NR_mlock	150
#define __NR_munlock	151
#define __NR_mlockall	152
#define __NR_munlockall	153
#define __NR_sched_setparam	154
#define __NR_sched_getparam	155
#define __NR_sched_setscheduler	156
#define __NR_sched_getscheduler	157
#define __NR_sched_yield	158
#define __NR_sched_get_priority_max	159
#define __NR_sched_get_priority_min	160
#define __NR_sched_rr_get_interval	161
#define __NR_nanosleep	162
#define __NR_mremap	163
#define __NR_setresuid	164
#define __NR_getresuid	165
#define __NR_poll	168
#define __NR_nfsservctl	169
#define __NR_setresgid	170
#define __NR_getresgid	171
#define __NR_prctl	172
#define __NR_rt_sigreturn	173
#define __NR_rt_sigaction	174
#define __NR_rt_sigprocmask	175
#define __NR_rt_sigpending	176
#define __NR_rt_sigtimedwait	177
#define __NR_rt_sigqueueinfo	178
#define __NR_rt_sigsuspend	179
#define __NR_pread64	180
#define __NR_pwrite64	181
#define __NR_chown	182
#define __NR_getcwd	183
#define __NR_capget	184
#define __NR_capset	185
#define __NR_sigaltstack	186
#define __NR_sendfile	187
#define __NR_vfork	190
#define __NR_ugetrlimit	191
#define __NR_mmap2	192
#define __NR_truncate64	193
#define __NR_ftruncate64	194
#define __NR_stat64	195
#define __NR_lstat64	196
#define __NR_fstat64	197
#define __NR_lchown32	198
#define __NR_getuid32	199
#define __NR_getgid32	200
#define __NR_geteuid32	201
#define __NR_getegid32	202
#define __NR_setreuid32	203
#define __NR_setregid32	204
#define __NR_getgroups32	205
#define __NR_setgroups32	206
#define __NR_fchown32	207
#define __NR_setresuid32	208
#define __NR_getresuid32	209
#define __NR_setresgid32	210
#define __NR_getresgid32	211
#define __NR_chown32	212
#define __NR_setuid32	213
#define __NR_setgid32	214
#define __NR_setfsuid32	215
#define __NR_setfsgid32	216
#define __NR_getdents64	217
#define __NR_pivot_root	218
#define __NR_mincore	219
#define __NR_madvise	220
#define __NR_fcntl64	221
#define __NR_gettid	224
#define __NR_readahead	225
#define __NR_setxattr	226
#define __NR_lsetxattr	227
#define __NR_fsetxattr	228
#define __NR_getxattr	229
#define __NR_lgetxattr	230
#define __NR_fgetxattr	231
#define __NR_listxattr	232
#define __NR_llistxattr	233
#define __NR_flistxattr	234
#define __NR_removexattr	235
#define __NR_lremovexattr	236
#define __NR_fremovexattr	237
#define __NR_tkill	238
#define __NR_sendfile64	239
#define __NR_futex	240
#define __NR_sched_setaffinity	241
#define __NR_sched_getaffinity	242
#define __NR_io_setup	243
#define __NR_io_destroy	244
#define __NR_io_getevents	245
#define __NR_io_submit	246
#define __NR_io_cancel	247
#define __NR_exit_group	248
#define __NR_lookup_dcookie	249
#define __NR_epoll_create	250
#define __NR_epoll_ctl	251
#define __NR_epoll_wait	252
#define __NR_remap_file_pages	253
#define __NR_set_tid_address	256
#define __NR_timer_create	257
#define __NR_timer_settime	258
#define __NR_timer_gettime	259
#define __NR_timer_getoverrun	260
#define __NR_timer_delete	261
#define __NR_clock_settime	262
#define __NR_clock_gettime	263
#define __NR_clock_getres	264
#define __NR_clock_nanosleep	265
#define __NR_statfs64	266
#define __NR_fstatfs64	267
#define __NR_tgkill	268
#define __NR_utimes	269
#define __NR_fadvise64_64	270
#define __NR_pciconfig_iobase	271
#define __NR_pciconfig_read	272
#define __NR_pciconfig_write	273
#define __NR_mq_open	274
#define __NR_mq_unlink	275
#define __NR_mq_timedsend	276
#define __NR_mq_timedreceive	277
#define __NR_mq_notify	278
#define __NR_mq_getsetattr	279
#define __NR_waitid	280
#define __NR_socket	281
#define __NR_bind	282
#define __NR_connect	283
#define __NR_listen	284
#define __NR_accept	285
#define __NR_getsockname	286
#define __NR_getpeername	287
#define __NR_socketpair	288
#define __NR_send	289
#define __NR_sendto	290
#define __NR_recv	291
#define __NR_recvfrom	292
#define __NR_shutdown	293
#define __NR_setsockopt	294
#define __NR_getsockopt	295
#define __NR_sendmsg	296
#define __NR_recvmsg	297
#define __NR_semop	298
#define __NR_semget	299
#define __NR_semctl	300
#define __NR_msgsnd	301
#define __NR_msgrcv	302
#define __NR_msgget	303
#define __NR_msgctl	304
#define __NR_shmat	305
#define __NR_shmdt	306
#define __NR_shmget	307
#define __NR_shmctl	308
#define __NR_add_key	309
#define __NR_request_key	310
#define __NR_keyctl	311
#define __NR_semtimedop	312
#define __NR_vserver	313
#define __NR_ioprio_set	314
#define __NR_ioprio_get	315
#define __NR_inotify_init	316
#define __NR_inotify_add_watch	317
#define __NR_inotify_rm_watch	318
#define __NR_mbind	319
#define __NR_get_mempolicy	320
#define __NR_set_mempolicy	321
#define __NR_openat	322
#define __NR_mkdirat	323
#define __NR_mknodat	324
#define __NR_fchownat	325
#define __NR_futimesat	326
#define __NR_fstatat64	327
#define __NR_unlinkat	328
#define __NR_renameat	329
#define __NR_linkat	330
#define __NR_symlinkat	331
#define __NR_readlinkat	332
#define __NR_fchmodat	333
#define __NR_faccessat	334
#define __NR_pselect6	335
#define __NR_ppoll	336
#define __NR_unshare	337
#define __NR_set_robust_list	338
#define __NR_get_robust_list	339
#define __NR_splice	340
#define __NR_sync_file_range2	341
#define __NR_tee	342
#define __NR_vmsplice	343
#define __NR_move_pages	344
#define __NR_getcpu	345
#define __NR_epoll_pwait	346
#define __NR_kexec_load	347
#define __NR_utimensat	348
#define __NR_signalfd	349
#define __NR_timerfd_create	350
#define __NR_eventfd	351
#define __NR_fallocate	352
#define __NR_timerfd_settime	353
#define __NR_timerfd_gettime	354
#define __NR_signalfd4	355
#define __NR_eventfd2	356
#define __NR_epoll_create1	357
#define __NR_dup3	358
#define __NR_pipe2	359
#define __NR_inotify_init1	360
#define __NR_preadv	361
#define __NR_pwritev	362
#define __NR_rt_tgsigqueueinfo	363
#define __NR_perf_event_open	364
#define __NR_recvmmsg	365
#define __NR_accept4	366
#define __NR_fanotify_init	367
#define __NR_fanotify_mark	368
#define __NR_prlimit64	369
#define __NR_name_to_handle_at	370
#define __NR_open_by_handle_at	371
#define __NR_clock_adjtime	372
#define __NR_syncfs	373
#define __NR_sendmmsg	374
#define __NR_setns	375

/* fixup legacy 16-bit junk */
#undef __NR_lchown
#undef __NR_getuid
#undef __NR_getgid
#undef __NR_geteuid
#undef __NR_getegid
#undef __NR_setreuid
#undef __NR_setregid
#undef __NR_getgroups
#undef __NR_setgroups
#undef __NR_fchown
#undef __NR_setresuid
#undef __NR_getresuid
#undef __NR_setresgid
#undef __NR_getresgid
#undef __NR_chown
#undef __NR_setuid
#undef __NR_setgid
#undef __NR_setfsuid
#undef __NR_setfsgid
#define __NR_lchown __NR_lchown32
#define __NR_getuid __NR_getuid32
#define __NR_getgid __NR_getgid32
#define __NR_geteuid __NR_geteuid32
#define __NR_getegid __NR_getegid32
#define __NR_setreuid __NR_setreuid32
#define __NR_setregid __NR_setregid32
#define __NR_getgroups __NR_getgroups32
#define __NR_setgroups __NR_setgroups32
#define __NR_fchown __NR_fchown32
#define __NR_setresuid __NR_setresuid32
#define __NR_getresuid __NR_getresuid32
#define __NR_setresgid __NR_setresgid32
#define __NR_getresgid __NR_getresgid32
#define __NR_chown __NR_chown32
#define __NR_setuid __NR_setuid32
#define __NR_setgid __NR_setgid32
#define __NR_setfsuid __NR_setfsuid32
#define __NR_setfsgid __NR_setfsgid32


/* fixup legacy 32-bit-vs-lfs64 junk */
#undef __NR_fcntl
#undef __NR_getdents
#undef __NR_ftruncate
#undef __NR_truncate
#undef __NR_stat
#undef __NR_fstat
#undef __NR_lstat
#undef __NR_statfs
#undef __NR_fstatfs
#define __NR_fcntl __NR_fcntl64
#define __NR_getdents __NR_getdents64
#define __NR_ftruncate __NR_ftruncate64
#define __NR_truncate __NR_truncate64
#define __NR_stat __NR_stat64
#define __NR_fstat __NR_fstat64
#define __NR_lstat __NR_lstat64
#define __NR_statfs __NR_statfs64
#define __NR_fstatfs __NR_fstatfs64
#define __NR_fstatat __NR_fstatat64
#define __NR_pread __NR_pread64
#define __NR_pwrite __NR_pwrite64

#define __NR_fadvise __NR_fadvise64_64

#undef __NR_getrlimit
#define __NR_getrlimit __NR_ugetrlimit

#undef __NR_select
#define __NR_select __NR__newselect


/* Repeated with SYS_ prefix */

#define SYS_restart_syscall	0
#define SYS_exit	1
#define SYS_fork	2
#define SYS_read	3
#define SYS_write	4
#define SYS_open	5
#define SYS_close	6
#define SYS_creat	8
#define SYS_link	9
#define SYS_unlink	10
#define SYS_execve	11
#define SYS_chdir	12
#define SYS_time	13
#define SYS_mknod	14
#define SYS_chmod	15
#define SYS_lchown	16
#define SYS_lseek	19
#define SYS_getpid	20
#define SYS_mount	21
#define SYS_umount	22
#define SYS_setuid	23
#define SYS_getuid	24
#define SYS_stime	25
#define SYS_ptrace	26
#define SYS_alarm	27
#define SYS_pause	29
#define SYS_utime	30
#define SYS_access	33
#define SYS_nice	34
#define SYS_sync	36
#define SYS_kill	37
#define SYS_rename	38
#define SYS_mkdir	39
#define SYS_rmdir	40
#define SYS_dup	41
#define SYS_pipe	42
#define SYS_times	43
#define SYS_brk	45
#define SYS_setgid	46
#define SYS_getgid	47
#define SYS_geteuid	49
#define SYS_getegid	50
#define SYS_acct	51
#define SYS_umount2	52
#define SYS_ioctl	54
#define SYS_fcntl	55
#define SYS_setpgid	57
#define SYS_umask	60
#define SYS_chroot	61
#define SYS_ustat	62
#define SYS_dup2	63
#define SYS_getppid	64
#define SYS_getpgrp	65
#define SYS_setsid	66
#define SYS_sigaction	67
#define SYS_setreuid	70
#define SYS_setregid	71
#define SYS_sigsuspend	72
#define SYS_sigpending	73
#define SYS_sethostname	74
#define SYS_setrlimit	75
#define SYS_getrusage	77
#define SYS_gettimeofday	78
#define SYS_settimeofday	79
#define SYS_getgroups	80
#define SYS_setgroups	81
#define SYS_select	82
#define SYS_symlink	83
#define SYS_readlink	85
#define SYS_uselib	86
#define SYS_swapon	87
#define SYS_reboot	88
#define SYS_readdir	89
#define SYS_mmap	90
#define SYS_munmap	91
#define SYS_truncate	92
#define SYS_ftruncate	93
#define SYS_fchmod	94
#define SYS_fchown	95
#define SYS_getpriority	96
#define SYS_setpriority	97
#define SYS_statfs	99
#define SYS_fstatfs	100
#define SYS_socketcall	102
#define SYS_syslog	103
#define SYS_setitimer	104
#define SYS_getitimer	105
#define SYS_stat	106
#define SYS_lstat	107
#define SYS_fstat	108
#define SYS_vhangup	111
#define SYS_syscall	113
#define SYS_wait4	114
#define SYS_swapoff	115
#define SYS_sysinfo	116
#define SYS_ipc	117
#define SYS_fsync	118
#define SYS_sigreturn	119
#define SYS_clone	120
#define SYS_setdomainname	121
#define SYS_uname	122
#define SYS_adjtimex	124
#define SYS_mprotect	125
#define SYS_sigprocmask	126
#define SYS_init_module	128
#define SYS_delete_module	129
#define SYS_quotactl	131
#define SYS_getpgid	132
#define SYS_fchdir	133
#define SYS_bdflush	134
#define SYS_sysfs	135
#define SYS_personality	136
#define SYS_setfsuid	138
#define SYS_setfsgid	139
#define SYS__llseek	140
#define SYS_getdents	141
#define SYS__newselect	142
#define SYS_flock	143
#define SYS_msync	144
#define SYS_readv	145
#define SYS_writev	146
#define SYS_getsid	147
#define SYS_fdatasync	148
#define SYS__sysctl	149
#define SYS_mlock	150
#define SYS_munlock	151
#define SYS_mlockall	152
#define SYS_munlockall	153
#define SYS_sched_setparam	154
#define SYS_sched_getparam	155
#define SYS_sched_setscheduler	156
#define SYS_sched_getscheduler	157
#define SYS_sched_yield	158
#define SYS_sched_get_priority_max	159
#define SYS_sched_get_priority_min	160
#define SYS_sched_rr_get_interval	161
#define SYS_nanosleep	162
#define SYS_mremap	163
#define SYS_setresuid	164
#define SYS_getresuid	165
#define SYS_poll	168
#define SYS_nfsservctl	169
#define SYS_setresgid	170
#define SYS_getresgid	171
#define SYS_prctl	172
#define SYS_rt_sigreturn	173
#define SYS_rt_sigaction	174
#define SYS_rt_sigprocmask	175
#define SYS_rt_sigpending	176
#define SYS_rt_sigtimedwait	177
#define SYS_rt_sigqueueinfo	178
#define SYS_rt_sigsuspend	179
#define SYS_pread64	180
#define SYS_pwrite64	181
#define SYS_chown	182
#define SYS_getcwd	183
#define SYS_capget	184
#define SYS_capset	185
#define SYS_sigaltstack	186
#define SYS_sendfile	187
#define SYS_vfork	190
#define SYS_ugetrlimit	191
#define SYS_mmap2	192
#define SYS_truncate64	193
#define SYS_ftruncate64	194
#define SYS_stat64	195
#define SYS_lstat64	196
#define SYS_fstat64	197
#define SYS_lchown32	198
#define SYS_getuid32	199
#define SYS_getgid32	200
#define SYS_geteuid32	201
#define SYS_getegid32	202
#define SYS_setreuid32	203
#define SYS_setregid32	204
#define SYS_getgroups32	205
#define SYS_setgroups32	206
#define SYS_fchown32	207
#define SYS_setresuid32	208
#define SYS_getresuid32	209
#define SYS_setresgid32	210
#define SYS_getresgid32	211
#define SYS_chown32	212
#define SYS_setuid32	213
#define SYS_setgid32	214
#define SYS_setfsuid32	215
#define SYS_setfsgid32	216
#define SYS_getdents64	217
#define SYS_pivot_root	218
#define SYS_mincore	219
#define SYS_madvise	220
#define SYS_fcntl64	221
#define SYS_gettid	224
#define SYS_readahead	225
#define SYS_setxattr	226
#define SYS_lsetxattr	227
#define SYS_fsetxattr	228
#define SYS_getxattr	229
#define SYS_lgetxattr	230
#define SYS_fgetxattr	231
#define SYS_listxattr	232
#define SYS_llistxattr	233
#define SYS_flistxattr	234
#define SYS_removexattr	235
#define SYS_lremovexattr	236
#define SYS_fremovexattr	237
#define SYS_tkill	238
#define SYS_sendfile64	239
#define SYS_futex	240
#define SYS_sched_setaffinity	241
#define SYS_sched_getaffinity	242
#define SYS_io_setup	243
#define SYS_io_destroy	244
#define SYS_io_getevents	245
#define SYS_io_submit	246
#define SYS_io_cancel	247
#define SYS_exit_group	248
#define SYS_lookup_dcookie	249
#define SYS_epoll_create	250
#define SYS_epoll_ctl	251
#define SYS_epoll_wait	252
#define SYS_remap_file_pages	253
#define SYS_set_tid_address	256
#define SYS_timer_create	257
#define SYS_timer_settime	258
#define SYS_timer_gettime	259
#define SYS_timer_getoverrun	260
#define SYS_timer_delete	261
#define SYS_clock_settime	262
#define SYS_clock_gettime	263
#define SYS_clock_getres	264
#define SYS_clock_nanosleep	265
#define SYS_statfs64	266
#define SYS_fstatfs64	267
#define SYS_tgkill	268
#define SYS_utimes	269
#define SYS_fadvise64_64	270
#define SYS_pciconfig_iobase	271
#define SYS_pciconfig_read	272
#define SYS_pciconfig_write	273
#define SYS_mq_open	274
#define SYS_mq_unlink	275
#define SYS_mq_timedsend	276
#define SYS_mq_timedreceive	277
#define SYS_mq_notify	278
#define SYS_mq_getsetattr	279
#define SYS_waitid	280
#define SYS_socket	281
#define SYS_bind	282
#define SYS_connect	283
#define SYS_listen	284
#define SYS_accept	285
#define SYS_getsockname	286
#define SYS_getpeername	287
#define SYS_socketpair	288
#define SYS_send	289
#define SYS_sendto	290
#define SYS_recv	291
#define SYS_recvfrom	292
#define SYS_shutdown	293
#define SYS_setsockopt	294
#define SYS_getsockopt	295
#define SYS_sendmsg	296
#define SYS_recvmsg	297
#define SYS_semop	298
#define SYS_semget	299
#define SYS_semctl	300
#define SYS_msgsnd	301
#define SYS_msgrcv	302
#define SYS_msgget	303
#define SYS_msgctl	304
#define SYS_shmat	305
#define SYS_shmdt	306
#define SYS_shmget	307
#define SYS_shmctl	308
#define SYS_add_key	309
#define SYS_request_key	310
#define SYS_keyctl	311
#define SYS_semtimedop	312
#define SYS_vserver	313
#define SYS_ioprio_set	314
#define SYS_ioprio_get	315
#define SYS_inotify_init	316
#define SYS_inotify_add_watch	317
#define SYS_inotify_rm_watch	318
#define SYS_mbind	319
#define SYS_get_mempolicy	320
#define SYS_set_mempolicy	321
#define SYS_openat	322
#define SYS_mkdirat	323
#define SYS_mknodat	324
#define SYS_fchownat	325
#define SYS_futimesat	326
#define SYS_fstatat64	327
#define SYS_unlinkat	328
#define SYS_renameat	329
#define SYS_linkat	330
#define SYS_symlinkat	331
#define SYS_readlinkat	332
#define SYS_fchmodat	333
#define SYS_faccessat	334
#define SYS_pselect6	335
#define SYS_ppoll	336
#define SYS_unshare	337
#define SYS_set_robust_list	338
#define SYS_get_robust_list	339
#define SYS_splice	340
#define SYS_sync_file_range2	341
#define SYS_tee	342
#define SYS_vmsplice	343
#define SYS_move_pages	344
#define SYS_getcpu	345
#define SYS_epoll_pwait	346
#define SYS_kexec_load	347
#define SYS_utimensat	348
#define SYS_signalfd	349
#define SYS_timerfd_create	350
#define SYS_eventfd	351
#define SYS_fallocate	352
#define SYS_timerfd_settime	353
#define SYS_timerfd_gettime	354
#define SYS_signalfd4	355
#define SYS_eventfd2	356
#define SYS_epoll_create1	357
#define SYS_dup3	358
#define SYS_pipe2	359
#define SYS_inotify_init1	360
#define SYS_preadv	361
#define SYS_pwritev	362
#define SYS_rt_tgsigqueueinfo	363
#define SYS_perf_event_open	364
#define SYS_recvmmsg	365
#define SYS_accept4	366
#define SYS_fanotify_init	367
#define SYS_fanotify_mark	368
#define SYS_prlimit64	369
#define SYS_name_to_handle_at	370
#define SYS_open_by_handle_at	371
#define SYS_clock_adjtime	372
#define SYS_syncfs	373
#define SYS_sendmmsg	374
#define SYS_setns	375

/* fixup legacy 16-bit junk */
#undef SYS_lchown
#undef SYS_getuid
#undef SYS_getgid
#undef SYS_geteuid
#undef SYS_getegid
#undef SYS_setreuid
#undef SYS_setregid
#undef SYS_getgroups
#undef SYS_setgroups
#undef SYS_fchown
#undef SYS_setresuid
#undef SYS_getresuid
#undef SYS_setresgid
#undef SYS_getresgid
#undef SYS_chown
#undef SYS_setuid
#undef SYS_setgid
#undef SYS_setfsuid
#undef SYS_setfsgid
#define SYS_lchown SYS_lchown32
#define SYS_getuid SYS_getuid32
#define SYS_getgid SYS_getgid32
#define SYS_geteuid SYS_geteuid32
#define SYS_getegid SYS_getegid32
#define SYS_setreuid SYS_setreuid32
#define SYS_setregid SYS_setregid32
#define SYS_getgroups SYS_getgroups32
#define SYS_setgroups SYS_setgroups32
#define SYS_fchown SYS_fchown32
#define SYS_setresuid SYS_setresuid32
#define SYS_getresuid SYS_getresuid32
#define SYS_setresgid SYS_setresgid32
#define SYS_getresgid SYS_getresgid32
#define SYS_chown SYS_chown32
#define SYS_setuid SYS_setuid32
#define SYS_setgid SYS_setgid32
#define SYS_setfsuid SYS_setfsuid32
#define SYS_setfsgid SYS_setfsgid32


/* fixup legacy 32-bit-vs-lfs64 junk */
#undef SYS_fcntl
#undef SYS_getdents
#undef SYS_ftruncate
#undef SYS_truncate
#undef SYS_stat
#undef SYS_fstat
#undef SYS_lstat
#undef SYS_statfs
#undef SYS_fstatfs
#define SYS_fcntl SYS_fcntl64
#define SYS_getdents SYS_getdents64
#define SYS_ftruncate SYS_ftruncate64
#define SYS_truncate SYS_truncate64
#define SYS_stat SYS_stat64
#define SYS_fstat SYS_fstat64
#define SYS_lstat SYS_lstat64
#define SYS_statfs SYS_statfs64
#define SYS_fstatfs SYS_fstatfs64
#define SYS_fstatat SYS_fstatat64
#define SYS_pread SYS_pread64
#define SYS_pwrite SYS_pwrite64

#define SYS_fadvise SYS_fadvise64_64

#undef SYS_getrlimit
#define SYS_getrlimit SYS_ugetrlimit

#undef SYS_select
#define SYS_select SYS__newselect
