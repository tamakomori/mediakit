/* -*- coding: utf-8; tab-width: 8; indent-tabs-mode: t; -*- */

/*
 * MediaKit
 * Copyright (c) 2025, Tamako Mori. All rights reserved.
 */

/*
 * stdstor.h: The standard C implementation for stor component.
 */

#ifndef MEDIAKIT_STDSTOR_H
#define MEDIAKIT_STDSTOR_H

#include "mediakit/compat.h"

/* Initialize the stdstor module. */
bool stdstor_init(void);

/* Cleanup the stdstor module. */
void stdstor_cleanup(void);

#endif
