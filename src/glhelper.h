/* -*- coding: utf-8; indent-tabs-mode: t; tab-width: 8; c-basic-offset: 8; -*- */

/*
 * MediaKit
 * Copyright (c) 2025, Tamako Mori. All rights reserved.
 */

/*
 * This header absorbs some differences in the OpenGL implementations
 * between the platforms we support. This header is included from the
 * glrender.c file only.
 *
 * GLFW and GLEW work the same way, but we don't use them to reduce
 * our dependencies.
 */

#ifndef MEDIAKIT_GLHELPER_H
#define MEDIAKIT_GLHELPER_H

#include "mediakit/compat.h"

#if defined(_MSC_VER)
#include <BaseTsd.h>
typedef SSIZE_T ssize_t;
#endif

/*
 * For Windows.
 */
#define WGL_CONTEXT_MAJOR_VERSION_ARB		0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB		0x2092
#define WGL_CONTEXT_FLAGS_ARB			0x2094
#define WGL_CONTEXT_PROFILE_MASK_ARB		0x9126
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB	0x00000001

/*
 * Define the missing macros for OpenGL 2+ and OpenGL ES 2+.
 */
#ifndef GL_CLAMP_TO_EDGE
#define GL_CLAMP_TO_EDGE			0x812F
#define GL_TEXTURE0				0x84C0
#define GL_TEXTURE1				0x84C1
#define GL_ARRAY_BUFFER				0x8892
#define GL_ELEMENT_ARRAY_BUFFER			0x8893
#define GL_STATIC_DRAW				0x88E4
#define GL_FRAGMENT_SHADER			0x8B30
#define GL_LINK_STATUS				0x8B82
#define GL_VERTEX_SHADER			0x8B31
#define GL_COMPILE_STATUS			0x8B81
#endif

/*
 * Define the missing typedefs if glext.h is not included.
 */
#ifndef __gl_glext_h_
typedef char GLchar;
typedef ssize_t GLsizeiptr;
#endif

/*
 * Declare the OpenGL 2+ API functions as pointer-to-function because:
 *  - Linux: libOpenGL.so provides pure stubs and thus we override them in linuxmain.c
 *  - Windows: opengl32.dll doesn't export OpenGL 2+ symbols and thus we define them in winmain.c
 *
 * We have to get real API pointers by the extension mechanism:
 *  - Linux: glXGetProcAddress()
 *  - Windows: wglGetProcAddress()
 */
#if defined(TARGET_LINUX) || defined(TARGET_WIN32)
extern GLuint (APIENTRY *glCreateShader)(GLenum type);
extern void (APIENTRY *glShaderSource)(GLuint shader, GLsizei count, const GLchar *const *string, const GLint *length);
extern void (APIENTRY *glCompileShader)(GLuint shader);
extern void (APIENTRY *glGetShaderiv)(GLuint shader, GLenum pname, GLint *params);
extern void (APIENTRY *glGetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
extern void (APIENTRY *glAttachShader)(GLuint program, GLuint shader);
extern void (APIENTRY *glLinkProgram)(GLuint program);
extern void (APIENTRY *glGetProgramiv)(GLuint program, GLenum pname, GLint *params);
extern void (APIENTRY *glGetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
extern GLuint (APIENTRY *glCreateProgram)(void);
extern void (APIENTRY *glUseProgram)(GLuint program);
extern void (APIENTRY *glGenVertexArrays)(GLsizei n, GLuint *arrays);
extern void (APIENTRY *glBindVertexArray)(GLuint array);
extern void (APIENTRY *glGenBuffers)(GLsizei n, GLuint *buffers);
extern void (APIENTRY *glBindBuffer)(GLenum target, GLuint buffer);
extern GLint (APIENTRY *glGetAttribLocation)(GLuint program, const GLchar *name);
extern void (APIENTRY *glVertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
extern void (APIENTRY *glEnableVertexAttribArray)(GLuint index);
extern GLint (APIENTRY *glGetUniformLocation)(GLuint program, const GLchar *name);
extern void (APIENTRY *glUniform1i)(GLint location, GLint v0);
extern void (APIENTRY *glUniform1f)(GLint location, GLfloat *v);
extern void (APIENTRY *glUniform2fv)(GLint location, GLuint, GLboolean, GLfloat *v);
extern void (APIENTRY *glUniform3fv)(GLint location, GLuint, GLboolean,  GLfloat *v);
extern void (APIENTRY *glUniform4fv)(GLint location, GLuint, GLboolean, GLfloat *v);
extern void (APIENTRY *glUniformMatrix4fv)(GLint location, GLuint, GLboolean, GLfloat *v);
extern void (APIENTRY *glBufferData)(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
extern void (APIENTRY *glDeleteShader)(GLuint shader);
extern void (APIENTRY *glDeleteProgram)(GLuint program);
extern void (APIENTRY *glDeleteVertexArrays)(GLsizei n, const GLuint *arrays);
extern void (APIENTRY *glDeleteBuffers)(GLsizei n, const GLuint *buffers);
#ifdef TARGET_WIN32
/* Note: only Windows lacks glActiveTexture(), libOpenGL.so exports one that actually works. */
extern void (APIENTRY *glActiveTexture)(GLenum texture);
#endif
#endif /* if defined(LINUX) || defined(TARGET_WIN32) */

#endif	/* GLHELPER_H */
