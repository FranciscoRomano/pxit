// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_assert_h__
#define __core_assert_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/// log a error message to the terminal or command line application.
#define error(Format,...)\
printf("ERROR: " Format "\n",##__VA_ARGS__)

/// asserts if the condition evaluates to true, otherwise exit application.
#define assert(Condition,Format,...)\
if (!(Condition)) { error(Format,##__VA_ARGS__); exit(EXIT_FAILURE); }

// -------------------------------------------------------------------------------------------------------------------------- //

#define ASSERT_break(Condition,Format,...)\
if (!(Condition)) { printf("ERROR :: " Format "\n",##__VA_ARGS__); break; }

#define ASSERT_continue(Condition,Format,...)\
if (!(Condition)) { printf("ERROR :: " Format "\n",##__VA_ARGS__); continue; }

#define ASSERT_false(Condition,Format,...)\
if (!(Condition)) { printf("ERROR :: " Format "\n",##__VA_ARGS__); return false; }

#define ASSERT_fatal(Condition,Format,...)\
if (!(Condition)) { printf("ERROR :: " Format "\n",##__VA_ARGS__); exit(EXIT_FAILURE); }

#define ASSERT_log(Condition,Format,...)\
if (!(Condition)) { printf("ERROR :: " Format "\n",##__VA_ARGS__); }

#define ASSERT_true(Condition,Format,...)\
if (!(Condition)) { printf("ERROR :: " Format "\n",##__VA_ARGS__); return true; }

#define ASSERT(Condition,Action,Format,...)\
ASSERT_##Action(Condition,Format,##__VA_ARGS__)

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_assert_h__
// -------------------------------------------------------------------------------------------------------------------------- //