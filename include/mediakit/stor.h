/* -*- coding: utf-8; tab-width: 8; indent-tabs-mode: t; -*- */

/*
 * MediaKit
 * Copyright (c) 2025, Tamako Mori. All rights reserved.
 */

/*
 * stor.h: "stor" component interface.
 */

#ifndef MEDIAKIT_STOR_H
#define MEDIAKIT_STOR_H

#include "config.h"

struct stor;

/* Open a storage. */
bool stor_open(const char *file_name, struct stor **s);

/* Put an data item. */
bool stor_put(struct stor *s, const char *key, const char *value);

/* Get an data item. */
bool stor_get(struct stor *s, const char *key, const char **value);

/* Remove an data item. */
bool stor_remove(struct stor *s, const char *key);

/* Remove all data items. */
bool stor_remove_all(struct stor *s);

/* Close a storage. */
bool stor_close(struct stor *s);

#endif
