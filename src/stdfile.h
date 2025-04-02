/* -*- coding: utf-8; tab-width: 8; indent-tabs-mode: t; -*- */

/*
 * MediaKit
 * Copyright (c) 2025, Tamako Mori. All rights reserved.
 */

/*
 * stdfile.h: The standard C implementation of the file component.
 */

#ifndef MEDIAKIT_STDFILE_H
#define MEDIAKIT_STDFILE_H

/* Initialize the stdfile module. */
bool stdfile_init(char *(*make_path_func)(const char *));

/* Cleanup the stdfile module. */
void stdfile_cleanup(void);

#endif
