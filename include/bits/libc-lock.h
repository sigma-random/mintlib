/* libc-internal interface for mutex locks.  Stub version.
   Copyright (C) 1996, 1997 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the GNU C Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

#ifndef _BITS_LIBC_LOCK_H
#define _BITS_LIBC_LOCK_H 1


/* Define a lock variable NAME with storage class CLASS.  The lock must be
   initialized with __libc_lock_init before it can be used (or define it
   with __libc_lock_define_initialized, below).  Use `extern' for CLASS to
   declare a lock defined in another module.  In public structure
   definitions you must use a pointer to the lock structure (i.e., NAME
   begins with a `*'), because its storage size will not be known outside
   of libc.  */
#define __libc_lock_define(CLASS,NAME)

/* Define an initialized lock variable NAME with storage class CLASS.  */
#define __libc_lock_define_initialized(CLASS,NAME)

/* Define an initialized recursive lock variable NAME with storage
   class CLASS.  */
#define __libc_lock_define_initialized_recursive(CLASS,NAME)

/* Initialize the named lock variable, leaving it in a consistent, unlocked
   state.  */
#define __libc_lock_init(NAME)

/* Same as last but this time we initialize a recursive mutex.  */
#define __libc_lock_init_recursive(NAME)

/* Finalize the named lock variable, which must be locked.  It cannot be
   used again until __libc_lock_init is called again on it.  This must be
   called on a lock variable before the containing storage is reused.  */
#define __libc_lock_fini(NAME)

/* Finalize recursive named lock.  */
#define __libc_lock_fini_recursive(NAME)

/* Lock the named lock variable.  */
#define __libc_lock_lock(NAME)

/* Lock the recursive named lock variable.  */
#define __libc_lock_lock_recursive(NAME)

/* Try to lock the named lock variable.  */
#define __libc_lock_trylock(NAME) 0

/* Try to lock the recursive named lock variable.  */
#define __libc_lock_trylock_recursive(NAME) 0

/* Unlock the named lock variable.  */
#define __libc_lock_unlock(NAME)

/* Unlock the recursive named lock variable.  */
#define __libc_lock_unlock_recursive(NAME)


/* Define once control variable.  */
#define __libc_once_define(CLASS, NAME) CLASS int NAME = 0

/* Call handler iff the first call.  */
#define __libc_once(ONCE_CONTROL, INIT_FUNCTION) \
  do {									      \
    if ((ONCE_CONTROL) == 0) {						      \
      INIT_FUNCTION ();							      \
      (ONCE_CONTROL) = 1;						      \
    }									      \
  } while (0)


/* Start critical region with cleanup.  */
#define __libc_cleanup_region_start(FCT, ARG)

/* End critical region with cleanup.  */
#define __libc_cleanup_region_end(DOIT)


/* We need portable names for some of the functions.  */
#define __libc_mutex_unlock

/* Type for key of thread specific data.  */
typedef int __libc_key_t;

/* Create key for thread specific data.  */
#define __libc_key_create(KEY,DEST) -1

/* Set thread-specific data associated with KEY to VAL.  */
#define __libc_setspecific(KEY,VAL) -1

/* Get thread-specific data associated with KEY.  */
#define __libc_getspecific(KEY) 0

#endif	/* bits/libc-lock.h */
