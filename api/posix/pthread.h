// This file is a part of the IncludeOS unikernel - www.includeos.org
//
// Copyright 2015-2017 Oslo and Akershus University College of Applied Sciences
// and Alfred Bratterud
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <sched.h>

typedef unsigned int pthread_t;
typedef unsigned int pthread_key_t;
typedef struct {
  int is_initialized;
  void *stackaddr;
  int stacksize;
  int contentionscope;
  int inheritsched;
  int schedpolicy;
  sched_param schedparam;
  int  detachstate;
} pthread_attr_t;


typedef struct {} pthread_barrier_t;
typedef struct {} pthread_barrierattr_t;
typedef struct {} pthread_cond_t;
typedef struct {} pthread_condattr_t;
typedef struct {} pthread_mutex_t;
typedef struct {} pthread_mutexattr_t;
typedef struct {} pthread_rwlock_t;
typedef struct {} pthread_rwlockattr_t;
typedef struct {} pthread_spinlock_t;


int pthread_cond_broadcast(pthread_cond_t* cond);
int pthread_cond_signal(pthread_cond_t* cond);
int pthread_cond_timedwait(pthread_cond_t* cond,
                           pthread_mutex_t* mutex,
                           const struct timespec* abstime);
int pthread_cond_wait(pthread_cond_t* cond,
                      pthread_mutex_t* mutex);
int pthread_detach(pthread_t thread);
int pthread_equal(pthread_t t1, pthread_t t2);

void *pthread_getspecific(pthread_key_t key);
int pthread_setspecific(pthread_key_t key, const void *value);
int pthread_key_create(pthread_key_t *key, void (*destructor)(void*));
int pthread_mutexattr_destroy(pthread_mutexattr_t *attr);
int pthread_mutexattr_init(pthread_mutexattr_t *attr);
int pthread_mutexattr_gettype(const pthread_mutexattr_t *attr, int *type);
int pthread_mutexattr_settype(pthread_mutexattr_t *attr, int type);
int pthread_mutex_destroy(pthread_mutex_t *mutex);
int pthread_mutex_init(pthread_mutex_t* mutex,
                         const pthread_mutexattr_t* attr);
int pthread_create(pthread_t *, const pthread_attr_t *, void *(*)(void *), void *);
int pthread_join(pthread_t, void **);

