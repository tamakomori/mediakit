/* -*- coding: utf-8; tab-width: 8; indent-tabs-mode: t; -*- */

/*
 * MediaKit
 * Copyright (c) 2025, Tamako Mori. All rights reserved.
 */

/*
 * sys.h: "sys" component interface.
 */

#ifndef MEDIAKIT_SYS_H
#define MEDIAKIT_SYS_H

#include "compat.h"

/* Print a log line. */
void sys_log(const char *format, ...);

/* Print an error line. */
void sys_error(const char *format, ...);

/* Print an out-of-memory log. */
void sys_out_of_memory(void);

/* Get a millisecond time. */
uint64_t system_get_tick(void);

/* Get a two-letter language code of a system. */
const char *system_get_language(void);

#endif
