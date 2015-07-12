/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#ifdef __cplusplus
extern "C" {
#endif

#define RETURN_ERRNO_AND_OUTPUT(err, output) \
   do { \
      mrb_value results = mrb_ary_new(mrb); \
      mrb_ary_push(mrb, results, mrb_fixnum_value(err)); \
      if (result == 0) \
        mrb_ary_push(mrb, results, output); \
            else \
         mrb_ary_push(mrb, results, mrb_nil_value()); \
      return results; \
      } while (0);

#if BIND_apr_allocator_alloc_FUNCTION
#define apr_allocator_alloc_REQUIRED_ARGC 2
#define apr_allocator_alloc_OPTIONAL_ARGC 0
/* apr_allocator_alloc
 *
 * Parameters:
 * - allocator: apr_allocator_t *
 * - size: int
 * Return Type: apr_memnode_t *
 */
mrb_value
mrb_APR_apr_allocator_alloc(mrb_state* mrb, mrb_value self) {
  mrb_value allocator;
  mrb_value size;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &allocator, &size);

  mruby_

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, allocator, AprAllocatorT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprAllocatorT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, size, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_allocator_t * native_allocator = (mrb_nil_p(allocator) ? NULL : mruby_unbox_apr_allocator_t(allocator));

  int native_size = mrb_fixnum(size);

  /* Invocation */
  apr_memnode_t * result = apr_allocator_alloc(native_allocator, native_size);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_memnode_t(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_allocator_create_FUNCTION
#define apr_allocator_create_REQUIRED_ARGC 1
#define apr_allocator_create_OPTIONAL_ARGC 0
/* apr_allocator_create
 *
 * Parameters:
 * - allocator: apr_allocator_t **
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_allocator_create(mrb_state* mrb, mrb_value self) {
  mrb_value allocator;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &allocator);


  /* Type checking */
  TODO_type_check_apr_allocator_t_PTR_PTR(allocator);


  /* Unbox parameters */
  apr_allocator_t ** native_allocator = TODO_mruby_unbox_apr_allocator_t_PTR_PTR(allocator);

  /* Invocation */
  apr_status_t result = apr_allocator_create(native_allocator);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_allocator_destroy_FUNCTION
#define apr_allocator_destroy_REQUIRED_ARGC 1
#define apr_allocator_destroy_OPTIONAL_ARGC 0
/* apr_allocator_destroy
 *
 * Parameters:
 * - allocator: apr_allocator_t *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_allocator_destroy(mrb_state* mrb, mrb_value self) {
  mrb_value allocator;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &allocator);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, allocator, AprAllocatorT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprAllocatorT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_allocator_t * native_allocator = (mrb_nil_p(allocator) ? NULL : mruby_unbox_apr_allocator_t(allocator));

  /* Invocation */
  apr_allocator_destroy(native_allocator);

  return mrb_nil_value();
}
#endif

#if BIND_apr_allocator_free_FUNCTION
#define apr_allocator_free_REQUIRED_ARGC 2
#define apr_allocator_free_OPTIONAL_ARGC 0
/* apr_allocator_free
 *
 * Parameters:
 * - allocator: apr_allocator_t *
 * - memnode: apr_memnode_t *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_allocator_free(mrb_state* mrb, mrb_value self) {
  mrb_value allocator;
  mrb_value memnode;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &allocator, &memnode);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, allocator, AprAllocatorT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprAllocatorT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, memnode, AprMemnodeT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprMemnodeT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_allocator_t * native_allocator = (mrb_nil_p(allocator) ? NULL : mruby_unbox_apr_allocator_t(allocator));

  apr_memnode_t * native_memnode = (mrb_nil_p(memnode) ? NULL : mruby_unbox_apr_memnode_t(memnode));

  /* Invocation */
  apr_allocator_free(native_allocator, native_memnode);

  return mrb_nil_value();
}
#endif

#if BIND_apr_allocator_max_free_set_FUNCTION
#define apr_allocator_max_free_set_REQUIRED_ARGC 2
#define apr_allocator_max_free_set_OPTIONAL_ARGC 0
/* apr_allocator_max_free_set
 *
 * Parameters:
 * - allocator: apr_allocator_t *
 * - size: int
 * Return Type: void
 */
mrb_value
mrb_APR_apr_allocator_max_free_set(mrb_state* mrb, mrb_value self) {
  mrb_value allocator;
  mrb_value size;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &allocator, &size);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, allocator, AprAllocatorT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprAllocatorT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, size, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_allocator_t * native_allocator = (mrb_nil_p(allocator) ? NULL : mruby_unbox_apr_allocator_t(allocator));

  int native_size = mrb_fixnum(size);

  /* Invocation */
  apr_allocator_max_free_set(native_allocator, native_size);

  return mrb_nil_value();
}
#endif

#if BIND_apr_allocator_mutex_get_FUNCTION
#define apr_allocator_mutex_get_REQUIRED_ARGC 1
#define apr_allocator_mutex_get_OPTIONAL_ARGC 0
/* apr_allocator_mutex_get
 *
 * Parameters:
 * - allocator: apr_allocator_t *
 * Return Type: apr_thread_mutex_t *
 */
mrb_value
mrb_APR_apr_allocator_mutex_get(mrb_state* mrb, mrb_value self) {
  mrb_value allocator;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &allocator);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, allocator, AprAllocatorT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprAllocatorT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_allocator_t * native_allocator = (mrb_nil_p(allocator) ? NULL : mruby_unbox_apr_allocator_t(allocator));

  /* Invocation */
  apr_thread_mutex_t * result = apr_allocator_mutex_get(native_allocator);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_thread_mutex_t(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_allocator_mutex_set_FUNCTION
#define apr_allocator_mutex_set_REQUIRED_ARGC 2
#define apr_allocator_mutex_set_OPTIONAL_ARGC 0
/* apr_allocator_mutex_set
 *
 * Parameters:
 * - allocator: apr_allocator_t *
 * - mutex: apr_thread_mutex_t *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_allocator_mutex_set(mrb_state* mrb, mrb_value self) {
  mrb_value allocator;
  mrb_value mutex;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &allocator, &mutex);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, allocator, AprAllocatorT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprAllocatorT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, mutex, AprThreadMutexT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadMutexT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_allocator_t * native_allocator = (mrb_nil_p(allocator) ? NULL : mruby_unbox_apr_allocator_t(allocator));

  apr_thread_mutex_t * native_mutex = (mrb_nil_p(mutex) ? NULL : mruby_unbox_apr_thread_mutex_t(mutex));

  /* Invocation */
  apr_allocator_mutex_set(native_allocator, native_mutex);

  return mrb_nil_value();
}
#endif

#if BIND_apr_allocator_owner_get_FUNCTION
#define apr_allocator_owner_get_REQUIRED_ARGC 1
#define apr_allocator_owner_get_OPTIONAL_ARGC 0
/* apr_allocator_owner_get
 *
 * Parameters:
 * - allocator: apr_allocator_t *
 * Return Type: apr_pool_t *
 */
mrb_value
mrb_APR_apr_allocator_owner_get(mrb_state* mrb, mrb_value self) {
  mrb_value allocator;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &allocator);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, allocator, AprAllocatorT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprAllocatorT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_allocator_t * native_allocator = (mrb_nil_p(allocator) ? NULL : mruby_unbox_apr_allocator_t(allocator));

  /* Invocation */
  apr_pool_t * result = apr_allocator_owner_get(native_allocator);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_pool_t(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_allocator_owner_set_FUNCTION
#define apr_allocator_owner_set_REQUIRED_ARGC 2
#define apr_allocator_owner_set_OPTIONAL_ARGC 0
/* apr_allocator_owner_set
 *
 * Parameters:
 * - allocator: apr_allocator_t *
 * - pool: apr_pool_t *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_allocator_owner_set(mrb_state* mrb, mrb_value self) {
  mrb_value allocator;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &allocator, &pool);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, allocator, AprAllocatorT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprAllocatorT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_allocator_t * native_allocator = (mrb_nil_p(allocator) ? NULL : mruby_unbox_apr_allocator_t(allocator));

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_allocator_owner_set(native_allocator, native_pool);

  return mrb_nil_value();
}
#endif

#if BIND_apr_app_initialize_FUNCTION
#define apr_app_initialize_REQUIRED_ARGC 3
#define apr_app_initialize_OPTIONAL_ARGC 0
/* apr_app_initialize
 *
 * Parameters:
 * - argc: int *
 * - argv: const char *const **
 * - env: const char *const **
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_app_initialize(mrb_state* mrb, mrb_value self) {
  mrb_value argc;
  mrb_value argv;
  mrb_value env;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &argc, &argv, &env);


  /* Type checking */
  TODO_type_check_int_PTR(argc);
  TODO_type_check_const_char_PTR_const_PTR_PTR(argv);
  TODO_type_check_const_char_PTR_const_PTR_PTR(env);


  /* Unbox parameters */
  int * native_argc = TODO_mruby_unbox_int_PTR(argc);

  const char *const ** native_argv = TODO_mruby_unbox_const_char_PTR_const_PTR_PTR(argv);

  const char *const ** native_env = TODO_mruby_unbox_const_char_PTR_const_PTR_PTR(env);

  /* Invocation */
  apr_status_t result = apr_app_initialize(native_argc, native_argv, native_env);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_array_append_FUNCTION
#define apr_array_append_REQUIRED_ARGC 3
#define apr_array_append_OPTIONAL_ARGC 0
/* apr_array_append
 *
 * Parameters:
 * - p: apr_pool_t *
 * - first: const apr_array_header_t *
 * - second: const apr_array_header_t *
 * Return Type: apr_array_header_t *
 */
mrb_value
mrb_APR_apr_array_append(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value first;
  mrb_value second;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &p, &first, &second);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, first, AprArrayHeaderT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprArrayHeaderT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, second, AprArrayHeaderT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprArrayHeaderT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const apr_array_header_t * native_first = (mrb_nil_p(first) ? NULL : mruby_unbox_const apr_array_header_t(first));

  const apr_array_header_t * native_second = (mrb_nil_p(second) ? NULL : mruby_unbox_const apr_array_header_t(second));

  /* Invocation */
  apr_array_header_t * result = apr_array_append(native_p, native_first, native_second);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_array_header_t(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_array_cat_FUNCTION
#define apr_array_cat_REQUIRED_ARGC 2
#define apr_array_cat_OPTIONAL_ARGC 0
/* apr_array_cat
 *
 * Parameters:
 * - dst: apr_array_header_t *
 * - src: const apr_array_header_t *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_array_cat(mrb_state* mrb, mrb_value self) {
  mrb_value dst;
  mrb_value src;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &dst, &src);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, dst, AprArrayHeaderT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprArrayHeaderT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, src, AprArrayHeaderT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprArrayHeaderT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_array_header_t * native_dst = (mrb_nil_p(dst) ? NULL : mruby_unbox_apr_array_header_t(dst));

  const apr_array_header_t * native_src = (mrb_nil_p(src) ? NULL : mruby_unbox_const apr_array_header_t(src));

  /* Invocation */
  apr_array_cat(native_dst, native_src);

  return mrb_nil_value();
}
#endif

#if BIND_apr_array_clear_FUNCTION
#define apr_array_clear_REQUIRED_ARGC 1
#define apr_array_clear_OPTIONAL_ARGC 0
/* apr_array_clear
 *
 * Parameters:
 * - arr: apr_array_header_t *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_array_clear(mrb_state* mrb, mrb_value self) {
  mrb_value arr;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &arr);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, arr, AprArrayHeaderT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprArrayHeaderT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_array_header_t * native_arr = (mrb_nil_p(arr) ? NULL : mruby_unbox_apr_array_header_t(arr));

  /* Invocation */
  apr_array_clear(native_arr);

  return mrb_nil_value();
}
#endif

#if BIND_apr_array_copy_FUNCTION
#define apr_array_copy_REQUIRED_ARGC 2
#define apr_array_copy_OPTIONAL_ARGC 0
/* apr_array_copy
 *
 * Parameters:
 * - p: apr_pool_t *
 * - arr: const apr_array_header_t *
 * Return Type: apr_array_header_t *
 */
mrb_value
mrb_APR_apr_array_copy(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value arr;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &p, &arr);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, arr, AprArrayHeaderT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprArrayHeaderT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const apr_array_header_t * native_arr = (mrb_nil_p(arr) ? NULL : mruby_unbox_const apr_array_header_t(arr));

  /* Invocation */
  apr_array_header_t * result = apr_array_copy(native_p, native_arr);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_array_header_t(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_array_copy_hdr_FUNCTION
#define apr_array_copy_hdr_REQUIRED_ARGC 2
#define apr_array_copy_hdr_OPTIONAL_ARGC 0
/* apr_array_copy_hdr
 *
 * Parameters:
 * - p: apr_pool_t *
 * - arr: const apr_array_header_t *
 * Return Type: apr_array_header_t *
 */
mrb_value
mrb_APR_apr_array_copy_hdr(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value arr;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &p, &arr);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, arr, AprArrayHeaderT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprArrayHeaderT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const apr_array_header_t * native_arr = (mrb_nil_p(arr) ? NULL : mruby_unbox_const apr_array_header_t(arr));

  /* Invocation */
  apr_array_header_t * result = apr_array_copy_hdr(native_p, native_arr);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_array_header_t(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_array_make_FUNCTION
#define apr_array_make_REQUIRED_ARGC 3
#define apr_array_make_OPTIONAL_ARGC 0
/* apr_array_make
 *
 * Parameters:
 * - p: apr_pool_t *
 * - nelts: int
 * - elt_size: int
 * Return Type: apr_array_header_t *
 */
mrb_value
mrb_APR_apr_array_make(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value nelts;
  mrb_value elt_size;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &p, &nelts, &elt_size);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, nelts, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, elt_size, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  int native_nelts = mrb_fixnum(nelts);

  int native_elt_size = mrb_fixnum(elt_size);

  /* Invocation */
  apr_array_header_t * result = apr_array_make(native_p, native_nelts, native_elt_size);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_array_header_t(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_array_pop_FUNCTION
#define apr_array_pop_REQUIRED_ARGC 1
#define apr_array_pop_OPTIONAL_ARGC 0
/* apr_array_pop
 *
 * Parameters:
 * - arr: apr_array_header_t *
 * Return Type: void *
 */
mrb_value
mrb_APR_apr_array_pop(mrb_state* mrb, mrb_value self) {
  mrb_value arr;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &arr);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, arr, AprArrayHeaderT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprArrayHeaderT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_array_header_t * native_arr = (mrb_nil_p(arr) ? NULL : mruby_unbox_apr_array_header_t(arr));

  /* Invocation */
  void * result = apr_array_pop(native_arr);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_array_pstrcat_FUNCTION
#define apr_array_pstrcat_REQUIRED_ARGC 3
#define apr_array_pstrcat_OPTIONAL_ARGC 0
/* apr_array_pstrcat
 *
 * Parameters:
 * - p: apr_pool_t *
 * - arr: const apr_array_header_t *
 * - sep: const char
 * Return Type: char *
 */
mrb_value
mrb_APR_apr_array_pstrcat(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value arr;
  mrb_value sep;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &p, &arr, &sep);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, arr, AprArrayHeaderT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprArrayHeaderT expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_char(sep);


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const apr_array_header_t * native_arr = (mrb_nil_p(arr) ? NULL : mruby_unbox_const apr_array_header_t(arr));

  const char native_sep = TODO_mruby_unbox_const_char(sep);

  /* Invocation */
  char * result = apr_array_pstrcat(native_p, native_arr, native_sep);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_array_push_FUNCTION
#define apr_array_push_REQUIRED_ARGC 1
#define apr_array_push_OPTIONAL_ARGC 0
/* apr_array_push
 *
 * Parameters:
 * - arr: apr_array_header_t *
 * Return Type: void *
 */
mrb_value
mrb_APR_apr_array_push(mrb_state* mrb, mrb_value self) {
  mrb_value arr;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &arr);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, arr, AprArrayHeaderT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprArrayHeaderT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_array_header_t * native_arr = (mrb_nil_p(arr) ? NULL : mruby_unbox_apr_array_header_t(arr));

  /* Invocation */
  void * result = apr_array_push(native_arr);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_atoi64_FUNCTION
#define apr_atoi64_REQUIRED_ARGC 1
#define apr_atoi64_OPTIONAL_ARGC 0
/* apr_atoi64
 *
 * Parameters:
 * - buf: const char *
 * Return Type: apr_int64_t
 */
mrb_value
mrb_APR_apr_atoi64(mrb_state* mrb, mrb_value self) {
  mrb_value buf;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &buf);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, buf, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_buf = mrb_string_value_cstr(mrb, &buf);

  /* Invocation */
  apr_int64_t result = apr_atoi64(native_buf);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_long_long(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_atomic_add32_FUNCTION
#define apr_atomic_add32_REQUIRED_ARGC 2
#define apr_atomic_add32_OPTIONAL_ARGC 0
/* apr_atomic_add32
 *
 * Parameters:
 * - mem: volatile unsigned int *
 * - val: unsigned int
 * Return Type: apr_uint32_t
 */
mrb_value
mrb_APR_apr_atomic_add32(mrb_state* mrb, mrb_value self) {
  mrb_value mem;
  mrb_value val;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &mem, &val);


  /* Type checking */
  TODO_type_check_volatile_unsigned_int_PTR(mem);
  if (!mrb_obj_is_kind_of(mrb, val, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  volatile unsigned int * native_mem = TODO_mruby_unbox_volatile_unsigned_int_PTR(mem);

  unsigned int native_val = mrb_fixnum(val);

  /* Invocation */
  apr_uint32_t result = apr_atomic_add32(native_mem, native_val);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_atomic_cas32_FUNCTION
#define apr_atomic_cas32_REQUIRED_ARGC 3
#define apr_atomic_cas32_OPTIONAL_ARGC 0
/* apr_atomic_cas32
 *
 * Parameters:
 * - mem: volatile unsigned int *
 * - with: unsigned int
 * - cmp: unsigned int
 * Return Type: apr_uint32_t
 */
mrb_value
mrb_APR_apr_atomic_cas32(mrb_state* mrb, mrb_value self) {
  mrb_value mem;
  mrb_value with;
  mrb_value cmp;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &mem, &with, &cmp);


  /* Type checking */
  TODO_type_check_volatile_unsigned_int_PTR(mem);
  if (!mrb_obj_is_kind_of(mrb, with, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, cmp, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  volatile unsigned int * native_mem = TODO_mruby_unbox_volatile_unsigned_int_PTR(mem);

  unsigned int native_with = mrb_fixnum(with);

  unsigned int native_cmp = mrb_fixnum(cmp);

  /* Invocation */
  apr_uint32_t result = apr_atomic_cas32(native_mem, native_with, native_cmp);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_atomic_casptr_FUNCTION
#define apr_atomic_casptr_REQUIRED_ARGC 3
#define apr_atomic_casptr_OPTIONAL_ARGC 0
/* apr_atomic_casptr
 *
 * Parameters:
 * - mem: volatile void **
 * - with: void *
 * - cmp: const void *
 * Return Type: void *
 */
mrb_value
mrb_APR_apr_atomic_casptr(mrb_state* mrb, mrb_value self) {
  mrb_value mem;
  mrb_value with;
  mrb_value cmp;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &mem, &with, &cmp);


  /* Type checking */
  TODO_type_check_volatile_void_PTR_PTR(mem);
  TODO_type_check_void_PTR(with);
  TODO_type_check_const_void_PTR(cmp);


  /* Unbox parameters */
  volatile void ** native_mem = TODO_mruby_unbox_volatile_void_PTR_PTR(mem);

  void * native_with = TODO_mruby_unbox_void_PTR(with);

  const void * native_cmp = TODO_mruby_unbox_const_void_PTR(cmp);

  /* Invocation */
  void * result = apr_atomic_casptr(native_mem, native_with, native_cmp);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_atomic_dec32_FUNCTION
#define apr_atomic_dec32_REQUIRED_ARGC 1
#define apr_atomic_dec32_OPTIONAL_ARGC 0
/* apr_atomic_dec32
 *
 * Parameters:
 * - mem: volatile unsigned int *
 * Return Type: int
 */
mrb_value
mrb_APR_apr_atomic_dec32(mrb_state* mrb, mrb_value self) {
  mrb_value mem;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &mem);


  /* Type checking */
  TODO_type_check_volatile_unsigned_int_PTR(mem);


  /* Unbox parameters */
  volatile unsigned int * native_mem = TODO_mruby_unbox_volatile_unsigned_int_PTR(mem);

  /* Invocation */
  int result = apr_atomic_dec32(native_mem);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_atomic_inc32_FUNCTION
#define apr_atomic_inc32_REQUIRED_ARGC 1
#define apr_atomic_inc32_OPTIONAL_ARGC 0
/* apr_atomic_inc32
 *
 * Parameters:
 * - mem: volatile unsigned int *
 * Return Type: apr_uint32_t
 */
mrb_value
mrb_APR_apr_atomic_inc32(mrb_state* mrb, mrb_value self) {
  mrb_value mem;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &mem);


  /* Type checking */
  TODO_type_check_volatile_unsigned_int_PTR(mem);


  /* Unbox parameters */
  volatile unsigned int * native_mem = TODO_mruby_unbox_volatile_unsigned_int_PTR(mem);

  /* Invocation */
  apr_uint32_t result = apr_atomic_inc32(native_mem);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_atomic_init_FUNCTION
#define apr_atomic_init_REQUIRED_ARGC 1
#define apr_atomic_init_OPTIONAL_ARGC 0
/* apr_atomic_init
 *
 * Parameters:
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_atomic_init(mrb_state* mrb, mrb_value self) {
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &p);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_atomic_init(native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_atomic_read32_FUNCTION
#define apr_atomic_read32_REQUIRED_ARGC 1
#define apr_atomic_read32_OPTIONAL_ARGC 0
/* apr_atomic_read32
 *
 * Parameters:
 * - mem: volatile unsigned int *
 * Return Type: apr_uint32_t
 */
mrb_value
mrb_APR_apr_atomic_read32(mrb_state* mrb, mrb_value self) {
  mrb_value mem;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &mem);


  /* Type checking */
  TODO_type_check_volatile_unsigned_int_PTR(mem);


  /* Unbox parameters */
  volatile unsigned int * native_mem = TODO_mruby_unbox_volatile_unsigned_int_PTR(mem);

  /* Invocation */
  apr_uint32_t result = apr_atomic_read32(native_mem);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_atomic_set32_FUNCTION
#define apr_atomic_set32_REQUIRED_ARGC 2
#define apr_atomic_set32_OPTIONAL_ARGC 0
/* apr_atomic_set32
 *
 * Parameters:
 * - mem: volatile unsigned int *
 * - val: unsigned int
 * Return Type: void
 */
mrb_value
mrb_APR_apr_atomic_set32(mrb_state* mrb, mrb_value self) {
  mrb_value mem;
  mrb_value val;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &mem, &val);


  /* Type checking */
  TODO_type_check_volatile_unsigned_int_PTR(mem);
  if (!mrb_obj_is_kind_of(mrb, val, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  volatile unsigned int * native_mem = TODO_mruby_unbox_volatile_unsigned_int_PTR(mem);

  unsigned int native_val = mrb_fixnum(val);

  /* Invocation */
  apr_atomic_set32(native_mem, native_val);

  return mrb_nil_value();
}
#endif

#if BIND_apr_atomic_sub32_FUNCTION
#define apr_atomic_sub32_REQUIRED_ARGC 2
#define apr_atomic_sub32_OPTIONAL_ARGC 0
/* apr_atomic_sub32
 *
 * Parameters:
 * - mem: volatile unsigned int *
 * - val: unsigned int
 * Return Type: void
 */
mrb_value
mrb_APR_apr_atomic_sub32(mrb_state* mrb, mrb_value self) {
  mrb_value mem;
  mrb_value val;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &mem, &val);


  /* Type checking */
  TODO_type_check_volatile_unsigned_int_PTR(mem);
  if (!mrb_obj_is_kind_of(mrb, val, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  volatile unsigned int * native_mem = TODO_mruby_unbox_volatile_unsigned_int_PTR(mem);

  unsigned int native_val = mrb_fixnum(val);

  /* Invocation */
  apr_atomic_sub32(native_mem, native_val);

  return mrb_nil_value();
}
#endif

#if BIND_apr_atomic_xchg32_FUNCTION
#define apr_atomic_xchg32_REQUIRED_ARGC 2
#define apr_atomic_xchg32_OPTIONAL_ARGC 0
/* apr_atomic_xchg32
 *
 * Parameters:
 * - mem: volatile unsigned int *
 * - val: unsigned int
 * Return Type: apr_uint32_t
 */
mrb_value
mrb_APR_apr_atomic_xchg32(mrb_state* mrb, mrb_value self) {
  mrb_value mem;
  mrb_value val;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &mem, &val);


  /* Type checking */
  TODO_type_check_volatile_unsigned_int_PTR(mem);
  if (!mrb_obj_is_kind_of(mrb, val, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  volatile unsigned int * native_mem = TODO_mruby_unbox_volatile_unsigned_int_PTR(mem);

  unsigned int native_val = mrb_fixnum(val);

  /* Invocation */
  apr_uint32_t result = apr_atomic_xchg32(native_mem, native_val);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_atomic_xchgptr_FUNCTION
#define apr_atomic_xchgptr_REQUIRED_ARGC 2
#define apr_atomic_xchgptr_OPTIONAL_ARGC 0
/* apr_atomic_xchgptr
 *
 * Parameters:
 * - mem: volatile void **
 * - with: void *
 * Return Type: void *
 */
mrb_value
mrb_APR_apr_atomic_xchgptr(mrb_state* mrb, mrb_value self) {
  mrb_value mem;
  mrb_value with;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &mem, &with);


  /* Type checking */
  TODO_type_check_volatile_void_PTR_PTR(mem);
  TODO_type_check_void_PTR(with);


  /* Unbox parameters */
  volatile void ** native_mem = TODO_mruby_unbox_volatile_void_PTR_PTR(mem);

  void * native_with = TODO_mruby_unbox_void_PTR(with);

  /* Invocation */
  void * result = apr_atomic_xchgptr(native_mem, native_with);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_collapse_spaces_FUNCTION
#define apr_collapse_spaces_REQUIRED_ARGC 2
#define apr_collapse_spaces_OPTIONAL_ARGC 0
/* apr_collapse_spaces
 *
 * Parameters:
 * - dest: char *
 * - src: const char *
 * Return Type: char *
 */
mrb_value
mrb_APR_apr_collapse_spaces(mrb_state* mrb, mrb_value self) {
  mrb_value dest;
  mrb_value src;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &dest, &src);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, dest, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, src, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_dest = strdup(mrb_string_value_cstr(mrb, &dest));

  const char * native_src = mrb_string_value_cstr(mrb, &src);

  /* Invocation */
  char * result = apr_collapse_spaces(native_dest, native_src);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_dest);
  native_dest = NULL;

  return return_value;
}
#endif

#if BIND_apr_cpystrn_FUNCTION
#define apr_cpystrn_REQUIRED_ARGC 3
#define apr_cpystrn_OPTIONAL_ARGC 0
/* apr_cpystrn
 *
 * Parameters:
 * - dst: char *
 * - src: const char *
 * - dst_size: int
 * Return Type: char *
 */
mrb_value
mrb_APR_apr_cpystrn(mrb_state* mrb, mrb_value self) {
  mrb_value dst;
  mrb_value src;
  mrb_value dst_size;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &dst, &src, &dst_size);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, dst, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, src, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, dst_size, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_dst = strdup(mrb_string_value_cstr(mrb, &dst));

  const char * native_src = mrb_string_value_cstr(mrb, &src);

  int native_dst_size = mrb_fixnum(dst_size);

  /* Invocation */
  char * result = apr_cpystrn(native_dst, native_src, native_dst_size);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_dst);
  native_dst = NULL;

  return return_value;
}
#endif

#if BIND_apr_crypto_sha256_new_FUNCTION
#define apr_crypto_sha256_new_REQUIRED_ARGC 1
#define apr_crypto_sha256_new_OPTIONAL_ARGC 0
/* apr_crypto_sha256_new
 *
 * Parameters:
 * - p: apr_pool_t *
 * Return Type: apr_crypto_hash_t *
 */
mrb_value
mrb_APR_apr_crypto_sha256_new(mrb_state* mrb, mrb_value self) {
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &p);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_crypto_hash_t * result = apr_crypto_sha256_new(native_p);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_crypto_hash_t(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_ctime_FUNCTION
#define apr_ctime_REQUIRED_ARGC 1
#define apr_ctime_OPTIONAL_ARGC 0
/* apr_ctime
 *
 * Parameters:
 * - t: AprTimeT
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_ctime(mrb_state* mrb, mrb_value self) {
  mrb_value t;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &t);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, t, AprTimeT_class(mrb))) {
    mrb_raise(mrb, AprTimeT_class(mrb), "AprTimeT expected");
    return mrb_nil_value();
  }

  /* unboxing parameters */
  apr_time_t native_t = *mruby_unbox_apr_time_t(t);

  /* Invocation */
  char * native_date_str = (char*)malloc(APR_CTIME_LEN);
  apr_status_t result = apr_ctime(native_date_str, native_t);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  mrb_value results = mrb_ary_new(mrb);
  mrb_ary_push(mrb, results, return_value);
  if (result == 0) {
     mrb_ary_push(mrb, results, mrb_str_new_cstr(mrb, native_date_str));
  }
  else {
     mrb_ary_push(mrb, results, mrb_nil_value());
  }

  free(native_date_str);
  native_date_str = NULL;

  return results;
}
#endif

#if BIND_apr_dir_close_FUNCTION
#define apr_dir_close_REQUIRED_ARGC 1
#define apr_dir_close_OPTIONAL_ARGC 0
/* apr_dir_close
 *
 * Parameters:
 * - thedir: apr_dir_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_dir_close(mrb_state* mrb, mrb_value self) {
  mrb_value thedir;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &thedir);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, thedir, AprDirT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprDirT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_dir_t * native_thedir = (mrb_nil_p(thedir) ? NULL : mruby_unbox_apr_dir_t(thedir));

  /* Invocation */
  apr_status_t result = apr_dir_close(native_thedir);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_dir_make_FUNCTION
#define apr_dir_make_REQUIRED_ARGC 3
#define apr_dir_make_OPTIONAL_ARGC 0
/* apr_dir_make
 *
 * Parameters:
 * - path: const char *
 * - perm: int
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_dir_make(mrb_state* mrb, mrb_value self) {
  mrb_value path;
  mrb_value perm;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &path, &perm, &pool);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, path, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, perm, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  const char * native_path = mrb_string_value_cstr(mrb, &path);
  int native_perm = mrb_fixnum(perm);
  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_dir_make(native_path, native_perm, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_dir_make_recursive_FUNCTION
#define apr_dir_make_recursive_REQUIRED_ARGC 3
#define apr_dir_make_recursive_OPTIONAL_ARGC 0
/* apr_dir_make_recursive
 *
 * Parameters:
 * - path: const char *
 * - perm: int
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_dir_make_recursive(mrb_state* mrb, mrb_value self) {
  mrb_value path;
  mrb_value perm;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &path, &perm, &pool);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, path, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, perm, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  const char * native_path = mrb_string_value_cstr(mrb, &path);

  int native_perm = mrb_fixnum(perm);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_dir_make_recursive(native_path, native_perm, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_dir_open_FUNCTION
#define apr_dir_open_REQUIRED_ARGC 2
#define apr_dir_open_OPTIONAL_ARGC 0
/* apr_dir_open
 *
 * Parameters:
 * - dirname: const char *
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_dir_open(mrb_state* mrb, mrb_value self) {
  mrb_value dirname;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &dirname, &pool);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, dirname, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_dirname = mrb_string_value_cstr(mrb, &dirname);
  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_dir_t * native_new_dir;
  apr_status_t result = apr_dir_open(&native_new_dir, native_dirname, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  mrb_value results = mrb_ary_new(mrb);
  mrb_ary_push(mrb, results, return_value);
  if (result == 0) {
     mrb_ary_push(mrb, results, mruby_box_apr_dir_t(mrb, native_new_dir));
  }
  else {
     mrb_ary_push(mrb, results, mrb_nil_value());
  }

  return results;
}
#endif

#if BIND_apr_dir_read_FUNCTION
#define apr_dir_read_REQUIRED_ARGC 2
#define apr_dir_read_OPTIONAL_ARGC 0
/* apr_dir_read
 *
 * Parameters:
 * - wanted: int
 * - thedir: apr_dir_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_dir_read(mrb_state* mrb, mrb_value self) {
  mrb_value wanted;
  mrb_value thedir;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &wanted, &thedir);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, wanted, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, thedir, AprDirT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprDirT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  int native_wanted = mrb_fixnum(wanted);
  apr_dir_t * native_thedir = (mrb_nil_p(thedir) ? NULL : mruby_unbox_apr_dir_t(thedir));

  /* Invocation */
  apr_finfo_t native_finfo;
  apr_status_t result = apr_dir_read(&native_finfo, native_wanted, native_thedir);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  mrb_value results = mrb_ary_new(mrb);
  mrb_ary_push(mrb, results, return_value);
  /* Even when incomplete is returned, some values are valid */
  if (result == APR_SUCCESS || result == APR_INCOMPLETE) {
     apr_finfo_t* new_finfo = (apr_finfo_t*)malloc(sizeof(apr_finfo_t));
     memcpy(new_finfo, &native_finfo, sizeof(apr_finfo_t));
     mrb_ary_push(mrb, results, mruby_giftwrap_apr_finfo_t(mrb, new_finfo));
  }
  else {
     mrb_ary_push(mrb, results, mrb_nil_value());
  }

  return results;
}
#endif

#if BIND_apr_dir_remove_FUNCTION
#define apr_dir_remove_REQUIRED_ARGC 2
#define apr_dir_remove_OPTIONAL_ARGC 0
/* apr_dir_remove
 *
 * Parameters:
 * - path: const char *
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_dir_remove(mrb_state* mrb, mrb_value self) {
  mrb_value path;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &path, &pool);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, path, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  const char * native_path = mrb_string_value_cstr(mrb, &path);
  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_dir_remove(native_path, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_dir_rewind_FUNCTION
#define apr_dir_rewind_REQUIRED_ARGC 1
#define apr_dir_rewind_OPTIONAL_ARGC 0
/* apr_dir_rewind
 *
 * Parameters:
 * - thedir: apr_dir_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_dir_rewind(mrb_state* mrb, mrb_value self) {
  mrb_value thedir;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &thedir);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, thedir, AprDirT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprDirT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_dir_t * native_thedir = (mrb_nil_p(thedir) ? NULL : mruby_unbox_apr_dir_t(thedir));

  /* Invocation */
  apr_status_t result = apr_dir_rewind(native_thedir);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_dso_error_FUNCTION
#define apr_dso_error_REQUIRED_ARGC 3
#define apr_dso_error_OPTIONAL_ARGC 0
/* apr_dso_error
 *
 * Parameters:
 * - dso: apr_dso_handle_t *
 * - buf: char *
 * - bufsize: int
 * Return Type: const char *
 */
mrb_value
mrb_APR_apr_dso_error(mrb_state* mrb, mrb_value self) {
  mrb_value dso;
  mrb_value buf;
  mrb_value bufsize;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &dso, &buf, &bufsize);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, dso, AprDsoHandleT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprDsoHandleT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, buf, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, bufsize, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_dso_handle_t * native_dso = (mrb_nil_p(dso) ? NULL : mruby_unbox_apr_dso_handle_t(dso));

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_buf = strdup(mrb_string_value_cstr(mrb, &buf));

  int native_bufsize = mrb_fixnum(bufsize);

  /* Invocation */
  const char * result = apr_dso_error(native_dso, native_buf, native_bufsize);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_buf);
  native_buf = NULL;

  return return_value;
}
#endif

#if BIND_apr_dso_load_FUNCTION
#define apr_dso_load_REQUIRED_ARGC 3
#define apr_dso_load_OPTIONAL_ARGC 0
/* apr_dso_load
 *
 * Parameters:
 * - res_handle: apr_dso_handle_t **
 * - path: const char *
 * - ctx: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_dso_load(mrb_state* mrb, mrb_value self) {
  mrb_value res_handle;
  mrb_value path;
  mrb_value ctx;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &res_handle, &path, &ctx);


  /* Type checking */
  TODO_type_check_apr_dso_handle_t_PTR_PTR(res_handle);
  if (!mrb_obj_is_kind_of(mrb, path, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, ctx, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_dso_handle_t ** native_res_handle = TODO_mruby_unbox_apr_dso_handle_t_PTR_PTR(res_handle);

  const char * native_path = mrb_string_value_cstr(mrb, &path);

  apr_pool_t * native_ctx = (mrb_nil_p(ctx) ? NULL : mruby_unbox_apr_pool_t(ctx));

  /* Invocation */
  apr_status_t result = apr_dso_load(native_res_handle, native_path, native_ctx);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_dso_sym_FUNCTION
#define apr_dso_sym_REQUIRED_ARGC 3
#define apr_dso_sym_OPTIONAL_ARGC 0
/* apr_dso_sym
 *
 * Parameters:
 * - ressym: void **
 * - handle: apr_dso_handle_t *
 * - symname: const char *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_dso_sym(mrb_state* mrb, mrb_value self) {
  mrb_value ressym;
  mrb_value handle;
  mrb_value symname;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &ressym, &handle, &symname);


  /* Type checking */
  TODO_type_check_void_PTR_PTR(ressym);
  if (!mrb_obj_is_kind_of(mrb, handle, AprDsoHandleT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprDsoHandleT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, symname, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void ** native_ressym = TODO_mruby_unbox_void_PTR_PTR(ressym);

  apr_dso_handle_t * native_handle = (mrb_nil_p(handle) ? NULL : mruby_unbox_apr_dso_handle_t(handle));

  const char * native_symname = mrb_string_value_cstr(mrb, &symname);

  /* Invocation */
  apr_status_t result = apr_dso_sym(native_ressym, native_handle, native_symname);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_dso_unload_FUNCTION
#define apr_dso_unload_REQUIRED_ARGC 1
#define apr_dso_unload_OPTIONAL_ARGC 0
/* apr_dso_unload
 *
 * Parameters:
 * - handle: apr_dso_handle_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_dso_unload(mrb_state* mrb, mrb_value self) {
  mrb_value handle;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &handle);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, handle, AprDsoHandleT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprDsoHandleT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_dso_handle_t * native_handle = (mrb_nil_p(handle) ? NULL : mruby_unbox_apr_dso_handle_t(handle));

  /* Invocation */
  apr_status_t result = apr_dso_unload(native_handle);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_env_delete_FUNCTION
#define apr_env_delete_REQUIRED_ARGC 2
#define apr_env_delete_OPTIONAL_ARGC 0
/* apr_env_delete
 *
 * Parameters:
 * - envvar: const char *
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_env_delete(mrb_state* mrb, mrb_value self) {
  mrb_value envvar;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &envvar, &pool);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, envvar, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_envvar = mrb_string_value_cstr(mrb, &envvar);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_env_delete(native_envvar, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_env_get_FUNCTION
#define apr_env_get_REQUIRED_ARGC 2
#define apr_env_get_OPTIONAL_ARGC 0
/* apr_env_get
 *
 * Parameters:
 * - value: char **
 * - envvar: const char *
 * - pool: apr_pool_t *
 * Return Type: [apr_status_t, string]
 */
mrb_value
mrb_APR_apr_env_get(mrb_state* mrb, mrb_value self) {
  mrb_value envvar;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &envvar, &pool);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, envvar, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  const char * native_envvar = mrb_string_value_cstr(mrb, &envvar);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  char * native_value;
  apr_status_t result = apr_env_get(&native_value, native_envvar, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  mrb_value results = mrb_ary_new(mrb);
  mrb_ary_push(mrb, results, return_value);
  if (result == 0){
     mrb_ary_push(mrb, results, mrb_str_new_cstr(mrb, native_value));
  }
  else {
     mrb_ary_push(mrb, results, mrb_nil_value());
  }

  return results;
}
#endif

#if BIND_apr_env_set_FUNCTION
#define apr_env_set_REQUIRED_ARGC 3
#define apr_env_set_OPTIONAL_ARGC 0
/* apr_env_set
 *
 * Parameters:
 * - envvar: const char *
 * - value: const char *
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_env_set(mrb_state* mrb, mrb_value self) {
  mrb_value envvar;
  mrb_value value;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &envvar, &value, &pool);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, envvar, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, value, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_envvar = mrb_string_value_cstr(mrb, &envvar);

  const char * native_value = mrb_string_value_cstr(mrb, &value);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_env_set(native_envvar, native_value, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_escape_echo_FUNCTION
#define apr_escape_echo_REQUIRED_ARGC 5
#define apr_escape_echo_OPTIONAL_ARGC 0
/* apr_escape_echo
 *
 * Parameters:
 * - escaped: char *
 * - str: const char *
 * - slen: int
 * - quote: int
 * - len: int *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_escape_echo(mrb_state* mrb, mrb_value self) {
  mrb_value escaped;
  mrb_value str;
  mrb_value slen;
  mrb_value quote;
  mrb_value len;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &escaped, &str, &slen, &quote, &len);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, escaped, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, str, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, slen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, quote, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(len);


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_escaped = strdup(mrb_string_value_cstr(mrb, &escaped));

  const char * native_str = mrb_string_value_cstr(mrb, &str);

  int native_slen = mrb_fixnum(slen);

  int native_quote = mrb_fixnum(quote);

  int * native_len = TODO_mruby_unbox_int_PTR(len);

  /* Invocation */
  apr_status_t result = apr_escape_echo(native_escaped, native_str, native_slen, native_quote, native_len);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_escaped);
  native_escaped = NULL;

  return return_value;
}
#endif

#if BIND_apr_escape_entity_FUNCTION
#define apr_escape_entity_REQUIRED_ARGC 5
#define apr_escape_entity_OPTIONAL_ARGC 0
/* apr_escape_entity
 *
 * Parameters:
 * - escaped: char *
 * - str: const char *
 * - slen: int
 * - toasc: int
 * - len: int *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_escape_entity(mrb_state* mrb, mrb_value self) {
  mrb_value escaped;
  mrb_value str;
  mrb_value slen;
  mrb_value toasc;
  mrb_value len;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &escaped, &str, &slen, &toasc, &len);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, escaped, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, str, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, slen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, toasc, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(len);


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_escaped = strdup(mrb_string_value_cstr(mrb, &escaped));

  const char * native_str = mrb_string_value_cstr(mrb, &str);

  int native_slen = mrb_fixnum(slen);

  int native_toasc = mrb_fixnum(toasc);

  int * native_len = TODO_mruby_unbox_int_PTR(len);

  /* Invocation */
  apr_status_t result = apr_escape_entity(native_escaped, native_str, native_slen, native_toasc, native_len);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_escaped);
  native_escaped = NULL;

  return return_value;
}
#endif

#if BIND_apr_escape_hex_FUNCTION
#define apr_escape_hex_REQUIRED_ARGC 5
#define apr_escape_hex_OPTIONAL_ARGC 0
/* apr_escape_hex
 *
 * Parameters:
 * - dest: char *
 * - src: const void *
 * - srclen: int
 * - colon: int
 * - len: int *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_escape_hex(mrb_state* mrb, mrb_value self) {
  mrb_value dest;
  mrb_value src;
  mrb_value srclen;
  mrb_value colon;
  mrb_value len;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &dest, &src, &srclen, &colon, &len);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, dest, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_void_PTR(src);
  if (!mrb_obj_is_kind_of(mrb, srclen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, colon, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(len);


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_dest = strdup(mrb_string_value_cstr(mrb, &dest));

  const void * native_src = TODO_mruby_unbox_const_void_PTR(src);

  int native_srclen = mrb_fixnum(srclen);

  int native_colon = mrb_fixnum(colon);

  int * native_len = TODO_mruby_unbox_int_PTR(len);

  /* Invocation */
  apr_status_t result = apr_escape_hex(native_dest, native_src, native_srclen, native_colon, native_len);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_dest);
  native_dest = NULL;

  return return_value;
}
#endif

#if BIND_apr_escape_path_FUNCTION
#define apr_escape_path_REQUIRED_ARGC 5
#define apr_escape_path_OPTIONAL_ARGC 0
/* apr_escape_path
 *
 * Parameters:
 * - escaped: char *
 * - path: const char *
 * - slen: int
 * - partial: int
 * - len: int *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_escape_path(mrb_state* mrb, mrb_value self) {
  mrb_value escaped;
  mrb_value path;
  mrb_value slen;
  mrb_value partial;
  mrb_value len;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &escaped, &path, &slen, &partial, &len);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, escaped, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, path, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, slen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, partial, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(len);


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_escaped = strdup(mrb_string_value_cstr(mrb, &escaped));

  const char * native_path = mrb_string_value_cstr(mrb, &path);

  int native_slen = mrb_fixnum(slen);

  int native_partial = mrb_fixnum(partial);

  int * native_len = TODO_mruby_unbox_int_PTR(len);

  /* Invocation */
  apr_status_t result = apr_escape_path(native_escaped, native_path, native_slen, native_partial, native_len);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_escaped);
  native_escaped = NULL;

  return return_value;
}
#endif

#if BIND_apr_escape_path_segment_FUNCTION
#define apr_escape_path_segment_REQUIRED_ARGC 4
#define apr_escape_path_segment_OPTIONAL_ARGC 0
/* apr_escape_path_segment
 *
 * Parameters:
 * - escaped: char *
 * - str: const char *
 * - slen: int
 * - len: int *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_escape_path_segment(mrb_state* mrb, mrb_value self) {
  mrb_value escaped;
  mrb_value str;
  mrb_value slen;
  mrb_value len;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &escaped, &str, &slen, &len);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, escaped, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, str, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, slen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(len);


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_escaped = strdup(mrb_string_value_cstr(mrb, &escaped));

  const char * native_str = mrb_string_value_cstr(mrb, &str);

  int native_slen = mrb_fixnum(slen);

  int * native_len = TODO_mruby_unbox_int_PTR(len);

  /* Invocation */
  apr_status_t result = apr_escape_path_segment(native_escaped, native_str, native_slen, native_len);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_escaped);
  native_escaped = NULL;

  return return_value;
}
#endif

#if BIND_apr_escape_shell_FUNCTION
#define apr_escape_shell_REQUIRED_ARGC 4
#define apr_escape_shell_OPTIONAL_ARGC 0
/* apr_escape_shell
 *
 * Parameters:
 * - escaped: char *
 * - str: const char *
 * - slen: int
 * - len: int *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_escape_shell(mrb_state* mrb, mrb_value self) {
  mrb_value escaped;
  mrb_value str;
  mrb_value slen;
  mrb_value len;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &escaped, &str, &slen, &len);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, escaped, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, str, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, slen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(len);


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_escaped = strdup(mrb_string_value_cstr(mrb, &escaped));

  const char * native_str = mrb_string_value_cstr(mrb, &str);

  int native_slen = mrb_fixnum(slen);

  int * native_len = TODO_mruby_unbox_int_PTR(len);

  /* Invocation */
  apr_status_t result = apr_escape_shell(native_escaped, native_str, native_slen, native_len);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_escaped);
  native_escaped = NULL;

  return return_value;
}
#endif

#if BIND_apr_escape_urlencoded_FUNCTION
#define apr_escape_urlencoded_REQUIRED_ARGC 4
#define apr_escape_urlencoded_OPTIONAL_ARGC 0
/* apr_escape_urlencoded
 *
 * Parameters:
 * - escaped: char *
 * - str: const char *
 * - slen: int
 * - len: int *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_escape_urlencoded(mrb_state* mrb, mrb_value self) {
  mrb_value escaped;
  mrb_value str;
  mrb_value slen;
  mrb_value len;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &escaped, &str, &slen, &len);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, escaped, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, str, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, slen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(len);


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_escaped = strdup(mrb_string_value_cstr(mrb, &escaped));

  const char * native_str = mrb_string_value_cstr(mrb, &str);

  int native_slen = mrb_fixnum(slen);

  int * native_len = TODO_mruby_unbox_int_PTR(len);

  /* Invocation */
  apr_status_t result = apr_escape_urlencoded(native_escaped, native_str, native_slen, native_len);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_escaped);
  native_escaped = NULL;

  return return_value;
}
#endif

#if BIND_apr_file_append_FUNCTION
#define apr_file_append_REQUIRED_ARGC 4
#define apr_file_append_OPTIONAL_ARGC 0
/* apr_file_append
 *
 * Parameters:
 * - from_path: const char *
 * - to_path: const char *
 * - perms: int
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_append(mrb_state* mrb, mrb_value self) {
  mrb_value from_path;
  mrb_value to_path;
  mrb_value perms;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &from_path, &to_path, &perms, &pool);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, from_path, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, to_path, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, perms, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  const char * native_from_path = mrb_string_value_cstr(mrb, &from_path);
  const char * native_to_path = mrb_string_value_cstr(mrb, &to_path);
  int native_perms = mrb_fixnum(perms);
  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_file_append(native_from_path, native_to_path, native_perms, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_attrs_set_FUNCTION
#define apr_file_attrs_set_REQUIRED_ARGC 4
#define apr_file_attrs_set_OPTIONAL_ARGC 0
/* apr_file_attrs_set
 *
 * Parameters:
 * - fname: String
 * - attributes: Fixnum
 * - attr_mask: Fixnum
 * - pool: AprPoolT
 * Return Type: Fixnum (errno)
 */
mrb_value
mrb_APR_apr_file_attrs_set(mrb_state* mrb, mrb_value self) {
  mrb_value fname;
  mrb_value attributes;
  mrb_value attr_mask;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &fname, &attributes, &attr_mask, &pool);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, fname, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, attributes, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, attr_mask, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  const char * native_fname = mrb_string_value_cstr(mrb, &fname);
  unsigned int native_attributes = mrb_fixnum(attributes);
  unsigned int native_attr_mask = mrb_fixnum(attr_mask);
  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_file_attrs_set(native_fname, native_attributes, native_attr_mask, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_buffer_set_FUNCTION
#define apr_file_buffer_set_REQUIRED_ARGC 3
#define apr_file_buffer_set_OPTIONAL_ARGC 0
/* apr_file_buffer_set
 *
 * Parameters:
 * - thefile: apr_file_t *
 * - buffer: char *
 * - bufsize: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_buffer_set(mrb_state* mrb, mrb_value self) {
  mrb_value thefile;
  mrb_value buffer;
  mrb_value bufsize;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &thefile, &buffer, &bufsize);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, thefile, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, buffer, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, bufsize, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_file_t * native_thefile = (mrb_nil_p(thefile) ? NULL : mruby_unbox_apr_file_t(thefile));

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_buffer = strdup(mrb_string_value_cstr(mrb, &buffer));

  int native_bufsize = mrb_fixnum(bufsize);

  /* Invocation */
  apr_status_t result = apr_file_buffer_set(native_thefile, native_buffer, native_bufsize);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_buffer);
  native_buffer = NULL;

  return return_value;
}
#endif

#if BIND_apr_file_buffer_size_get_FUNCTION
#define apr_file_buffer_size_get_REQUIRED_ARGC 1
#define apr_file_buffer_size_get_OPTIONAL_ARGC 0
/* apr_file_buffer_size_get
 *
 * Parameters:
 * - thefile: apr_file_t *
 * Return Type: apr_size_t
 */
mrb_value
mrb_APR_apr_file_buffer_size_get(mrb_state* mrb, mrb_value self) {
  mrb_value thefile;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &thefile);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, thefile, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_file_t * native_thefile = (mrb_nil_p(thefile) ? NULL : mruby_unbox_apr_file_t(thefile));

  /* Invocation */
  apr_size_t result = apr_file_buffer_size_get(native_thefile);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_close_FUNCTION
#define apr_file_close_REQUIRED_ARGC 1
#define apr_file_close_OPTIONAL_ARGC 0
/* apr_file_close
 *
 * Parameters:
 * - file: apr_file_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_close(mrb_state* mrb, mrb_value self) {
  mrb_value file;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &file);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, file, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_file_t * native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_apr_file_t(file));

  /* Invocation */
  apr_status_t result = apr_file_close(native_file);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_copy_FUNCTION
#define apr_file_copy_REQUIRED_ARGC 4
#define apr_file_copy_OPTIONAL_ARGC 0
/* apr_file_copy
 *
 * Parameters:
 * - from_path: String
 * - to_path: String
 * - perms: int
 * - pool: AprPoolType
 * Return Type: AprStatusT
 */
mrb_value
mrb_APR_apr_file_copy(mrb_state* mrb, mrb_value self) {
  mrb_value from_path;
  mrb_value to_path;
  mrb_value perms;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &from_path, &to_path, &perms, &pool);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, from_path, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, to_path, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, perms, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  const char * native_from_path = mrb_string_value_cstr(mrb, &from_path);
  const char * native_to_path = mrb_string_value_cstr(mrb, &to_path);
  apr_fileperms_t native_perms = mrb_fixnum(perms);
  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_file_copy(native_from_path, native_to_path, native_perms, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_data_get_FUNCTION
#define apr_file_data_get_REQUIRED_ARGC 3
#define apr_file_data_get_OPTIONAL_ARGC 0
/* apr_file_data_get
 *
 * Parameters:
 * - data: void **
 * - key: const char *
 * - file: apr_file_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_data_get(mrb_state* mrb, mrb_value self) {
  mrb_value data;
  mrb_value key;
  mrb_value file;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &data, &key, &file);


  /* Type checking */
  TODO_type_check_void_PTR_PTR(data);
  if (!mrb_obj_is_kind_of(mrb, key, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, file, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void ** native_data = TODO_mruby_unbox_void_PTR_PTR(data);

  const char * native_key = mrb_string_value_cstr(mrb, &key);

  apr_file_t * native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_apr_file_t(file));

  /* Invocation */
  apr_status_t result = apr_file_data_get(native_data, native_key, native_file);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_data_set_FUNCTION
#define apr_file_data_set_REQUIRED_ARGC 5
#define apr_file_data_set_OPTIONAL_ARGC 0
/* apr_file_data_set
 *
 * Parameters:
 * - file: apr_file_t *
 * - data: void *
 * - key: const char *
 * - cleanup: int (*)(void *)
 * - arg5: void *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_data_set(mrb_state* mrb, mrb_value self) {
  mrb_value file;
  mrb_value data;
  mrb_value key;
  mrb_value cleanup;
  mrb_value arg5;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &file, &data, &key, &cleanup, &arg5);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, file, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(data);
  if (!mrb_obj_is_kind_of(mrb, key, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(cleanup);
  TODO_type_check_void_PTR(arg5);


  /* Unbox parameters */
  apr_file_t * native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_apr_file_t(file));

  void * native_data = TODO_mruby_unbox_void_PTR(data);

  const char * native_key = mrb_string_value_cstr(mrb, &key);

  int (*native_cleanup)(void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(cleanup);

  void * native_arg5 = TODO_mruby_unbox_void_PTR(arg5);

  /* Invocation */
  apr_status_t result = apr_file_data_set(native_file, native_data, native_key, native_cleanup, native_arg5);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_datasync_FUNCTION
#define apr_file_datasync_REQUIRED_ARGC 1
#define apr_file_datasync_OPTIONAL_ARGC 0
/* apr_file_datasync
 *
 * Parameters:
 * - thefile: apr_file_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_datasync(mrb_state* mrb, mrb_value self) {
  mrb_value thefile;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &thefile);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, thefile, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_file_t * native_thefile = (mrb_nil_p(thefile) ? NULL : mruby_unbox_apr_file_t(thefile));

  /* Invocation */
  apr_status_t result = apr_file_datasync(native_thefile);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_dup_FUNCTION
#define apr_file_dup_REQUIRED_ARGC 3
#define apr_file_dup_OPTIONAL_ARGC 0
/* apr_file_dup
 *
 * Parameters:
 * - new_file: apr_file_t **
 * - old_file: apr_file_t *
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_dup(mrb_state* mrb, mrb_value self) {
  mrb_value new_file;
  mrb_value old_file;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &new_file, &old_file, &p);


  /* Type checking */
  TODO_type_check_apr_file_t_PTR_PTR(new_file);
  if (!mrb_obj_is_kind_of(mrb, old_file, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_file_t ** native_new_file = TODO_mruby_unbox_apr_file_t_PTR_PTR(new_file);

  apr_file_t * native_old_file = (mrb_nil_p(old_file) ? NULL : mruby_unbox_apr_file_t(old_file));

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_file_dup(native_new_file, native_old_file, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_dup2_FUNCTION
#define apr_file_dup2_REQUIRED_ARGC 3
#define apr_file_dup2_OPTIONAL_ARGC 0
/* apr_file_dup2
 *
 * Parameters:
 * - new_file: apr_file_t *
 * - old_file: apr_file_t *
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_dup2(mrb_state* mrb, mrb_value self) {
  mrb_value new_file;
  mrb_value old_file;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &new_file, &old_file, &p);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, new_file, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, old_file, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_file_t * native_new_file = (mrb_nil_p(new_file) ? NULL : mruby_unbox_apr_file_t(new_file));

  apr_file_t * native_old_file = (mrb_nil_p(old_file) ? NULL : mruby_unbox_apr_file_t(old_file));

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_file_dup2(native_new_file, native_old_file, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_eof_FUNCTION
#define apr_file_eof_REQUIRED_ARGC 1
#define apr_file_eof_OPTIONAL_ARGC 0
/* apr_file_eof
 *
 * Parameters:
 * - fptr: apr_file_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_eof(mrb_state* mrb, mrb_value self) {
  mrb_value fptr;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &fptr);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, fptr, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_file_t * native_fptr = (mrb_nil_p(fptr) ? NULL : mruby_unbox_apr_file_t(fptr));

  /* Invocation */
  apr_status_t result = apr_file_eof(native_fptr);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_flags_get_FUNCTION
#define apr_file_flags_get_REQUIRED_ARGC 1
#define apr_file_flags_get_OPTIONAL_ARGC 0
/* apr_file_flags_get
 *
 * Parameters:
 * - f: apr_file_t *
 * Return Type: apr_int32_t
 */
mrb_value
mrb_APR_apr_file_flags_get(mrb_state* mrb, mrb_value self) {
  mrb_value f;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &f);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, f, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_file_t * native_f = (mrb_nil_p(f) ? NULL : mruby_unbox_apr_file_t(f));

  /* Invocation */
  apr_int32_t result = apr_file_flags_get(native_f);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_flush_FUNCTION
#define apr_file_flush_REQUIRED_ARGC 1
#define apr_file_flush_OPTIONAL_ARGC 0
/* apr_file_flush
 *
 * Parameters:
 * - thefile: apr_file_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_flush(mrb_state* mrb, mrb_value self) {
  mrb_value thefile;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &thefile);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, thefile, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_file_t * native_thefile = (mrb_nil_p(thefile) ? NULL : mruby_unbox_apr_file_t(thefile));

  /* Invocation */
  apr_status_t result = apr_file_flush(native_thefile);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_getc_FUNCTION
#define apr_file_getc_REQUIRED_ARGC 1
#define apr_file_getc_OPTIONAL_ARGC 0
/* apr_file_getc
 *
 * Parameters:
 * - thefile: AprFileT
 * Return Type: errno: Fixnum, char: String
 */
mrb_value
mrb_APR_apr_file_getc(mrb_state* mrb, mrb_value self) {
  mrb_value thefile;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &thefile);
  if (!mrb_obj_is_kind_of(mrb, thefile, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  apr_file_t * native_thefile = (mrb_nil_p(thefile) ? NULL : mruby_unbox_apr_file_t(thefile));

  /* Invocation */
  char native_ch;
  apr_status_t result = apr_file_getc(&native_ch, native_thefile);
  if (result == APR_SUCCESS) {
    RETURN_ERRNO_AND_OUTPUT(result, mrb_str_new(mrb, &native_ch, 1));
  } else {
    RETURN_ERRNO_AND_OUTPUT(result, mrb_nil_value());
  }
}
#endif

#if BIND_apr_file_gets_FUNCTION
#define apr_file_gets_REQUIRED_ARGC 2
#define apr_file_gets_OPTIONAL_ARGC 0
/* apr_file_gets
 *
 * Parameters:
 * - len: int
 * - thefile: apr_file_t *
 * Return Type: [int, String]
 */
mrb_value
mrb_APR_apr_file_gets(mrb_state* mrb, mrb_value self) {
  mrb_value len;
  mrb_value thefile;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &len, &thefile);

  if (!mrb_obj_is_kind_of(mrb, len, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, thefile, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  int native_len = mrb_fixnum(len);
  apr_file_t * native_thefile = (mrb_nil_p(thefile) ? NULL : mruby_unbox_apr_file_t(thefile));

  /* Invocation */
  char * native_str = (char*)malloc(sizeof(char) * (native_len + 1)); /* gets adds a null terminter */
  apr_status_t result = apr_file_gets(native_str, native_len + 1, native_thefile); /* len argument is length of buffer, NOT the string, so add one for null */

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  mrb_value results = mrb_ary_new(mrb);
  mrb_ary_push(mrb, results, return_value);
  if (result == 0) {
     mrb_value ruby_str = mrb_str_new(mrb, native_str, strlen(native_str));
     mrb_ary_push(mrb, results, ruby_str);
  }
  else {
     mrb_ary_push(mrb, results, mrb_nil_value());
  }

  /* Clean up memory */
  free(native_str);
  native_str = NULL;

  return results;
}
#endif

#if BIND_apr_file_info_get_FUNCTION
#define apr_file_info_get_REQUIRED_ARGC 3
#define apr_file_info_get_OPTIONAL_ARGC 0
/* apr_file_info_get
 *
 * Parameters:
 * - finfo: apr_finfo_t *
 * - wanted: int
 * - thefile: apr_file_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_info_get(mrb_state* mrb, mrb_value self) {
  mrb_value finfo;
  mrb_value wanted;
  mrb_value thefile;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &finfo, &wanted, &thefile);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, finfo, AprFinfoT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFinfoT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, wanted, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, thefile, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_finfo_t * native_finfo = (mrb_nil_p(finfo) ? NULL : mruby_unbox_apr_finfo_t(finfo));

  int native_wanted = mrb_fixnum(wanted);

  apr_file_t * native_thefile = (mrb_nil_p(thefile) ? NULL : mruby_unbox_apr_file_t(thefile));

  /* Invocation */
  apr_status_t result = apr_file_info_get(native_finfo, native_wanted, native_thefile);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_link_FUNCTION
#define apr_file_link_REQUIRED_ARGC 2
#define apr_file_link_OPTIONAL_ARGC 0
/* apr_file_link
 *
 * Parameters:
 * - from_path: const char *
 * - to_path: const char *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_link(mrb_state* mrb, mrb_value self) {
  mrb_value from_path;
  mrb_value to_path;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &from_path, &to_path);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, from_path, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, to_path, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  const char * native_from_path = mrb_string_value_cstr(mrb, &from_path);
  const char * native_to_path = mrb_string_value_cstr(mrb, &to_path);

  /* Invocation */
  apr_status_t result = apr_file_link(native_from_path, native_to_path);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_lock_FUNCTION
#define apr_file_lock_REQUIRED_ARGC 2
#define apr_file_lock_OPTIONAL_ARGC 0
/* apr_file_lock
 *
 * Parameters:
 * - thefile: AprFileT
 * - type: Fixnum
 * Return Type: Fixnum (errno)
 */
mrb_value
mrb_APR_apr_file_lock(mrb_state* mrb, mrb_value self) {
  mrb_value thefile;
  mrb_value type;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &thefile, &type);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, thefile, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, type, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_file_t * native_thefile = (mrb_nil_p(thefile) ? NULL : mruby_unbox_apr_file_t(thefile));

  int native_type = mrb_fixnum(type);

  /* Invocation */
  apr_status_t result = apr_file_lock(native_thefile, native_type);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_mktemp_FUNCTION
#define apr_file_mktemp_REQUIRED_ARGC 4
#define apr_file_mktemp_OPTIONAL_ARGC 0
/* apr_file_mktemp
 *
 * Parameters:
 * - fp: apr_file_t **
 * - templ: char *
 * - flags: int
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_mktemp(mrb_state* mrb, mrb_value self) {
  mrb_value fp;
  mrb_value templ;
  mrb_value flags;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &fp, &templ, &flags, &p);


  /* Type checking */
  TODO_type_check_apr_file_t_PTR_PTR(fp);
  if (!mrb_obj_is_kind_of(mrb, templ, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_file_t ** native_fp = TODO_mruby_unbox_apr_file_t_PTR_PTR(fp);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_templ = strdup(mrb_string_value_cstr(mrb, &templ));

  int native_flags = mrb_fixnum(flags);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_file_mktemp(native_fp, native_templ, native_flags, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_templ);
  native_templ = NULL;

  return return_value;
}
#endif

#if BIND_apr_file_mtime_set_FUNCTION
#define apr_file_mtime_set_REQUIRED_ARGC 3
#define apr_file_mtime_set_OPTIONAL_ARGC 0
/* apr_file_mtime_set
 *
 * Parameters:
 * - fname: const char *
 * - mtime: long long
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_mtime_set(mrb_state* mrb, mrb_value self) {
  mrb_value fname;
  mrb_value mtime;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &fname, &mtime, &pool);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, fname, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_long_long(mtime);
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_fname = mrb_string_value_cstr(mrb, &fname);

  long long native_mtime = TODO_mruby_unbox_long_long(mtime);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_file_mtime_set(native_fname, native_mtime, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_name_get_FUNCTION
#define apr_file_name_get_REQUIRED_ARGC 2
#define apr_file_name_get_OPTIONAL_ARGC 0
/* apr_file_name_get
 *
 * Parameters:
 * - new_path: const char **
 * - thefile: apr_file_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_name_get(mrb_state* mrb, mrb_value self) {
  mrb_value new_path;
  mrb_value thefile;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &new_path, &thefile);


  /* Type checking */
  TODO_type_check_const_char_PTR_PTR(new_path);
  if (!mrb_obj_is_kind_of(mrb, thefile, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char ** native_new_path = TODO_mruby_unbox_const_char_PTR_PTR(new_path);

  apr_file_t * native_thefile = (mrb_nil_p(thefile) ? NULL : mruby_unbox_apr_file_t(thefile));

  /* Invocation */
  apr_status_t result = apr_file_name_get(native_new_path, native_thefile);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_namedpipe_create_FUNCTION
#define apr_file_namedpipe_create_REQUIRED_ARGC 3
#define apr_file_namedpipe_create_OPTIONAL_ARGC 0
/* apr_file_namedpipe_create
 *
 * Parameters:
 * - filename: String
 * - perm: Fixnum
 * - pool: AprPoolT
 * Return Type: Fixnum (errno)
 */
mrb_value
mrb_APR_apr_file_namedpipe_create(mrb_state* mrb, mrb_value self) {
  mrb_value filename;
  mrb_value perm;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &filename, &perm, &pool);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, filename, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, perm, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  const char * native_filename = mrb_string_value_cstr(mrb, &filename);
  int native_perm = mrb_fixnum(perm);
  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_file_namedpipe_create(native_filename, native_perm, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_open_FUNCTION
#define apr_file_open_REQUIRED_ARGC 4
#define apr_file_open_OPTIONAL_ARGC 0
/* apr_file_open
 *
 * Parameters:
 * - fname: const char *
 * - flag: int
 * - perm: int
 * - pool: apr_pool_t *
 * Return Type: [apr_status_t, apr_file_t]
 */
mrb_value
mrb_APR_apr_file_open(mrb_state* mrb, mrb_value self) {
  mrb_value fname;
  mrb_value flag;
  mrb_value perm;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &fname, &flag, &perm, &pool);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, flag, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, perm, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  const char * native_fname = mrb_string_value_cstr(mrb, &fname);
  int native_flag = mrb_fixnum(flag);
  int native_perm = mrb_fixnum(perm);
  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_file_t * native_newf;
  apr_status_t result = apr_file_open(&native_newf, native_fname, native_flag, native_perm, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  mrb_value results = mrb_ary_new(mrb);
  mrb_ary_push(mrb, results, return_value);
  if (result == 0) {
     mrb_ary_push(mrb, results, mruby_box_apr_file_t(mrb, native_newf));
  }
  else {
     mrb_ary_push(mrb, results, mrb_nil_value());
  }

  return results;
}
#endif

#if BIND_apr_file_open_flags_stderr_FUNCTION
#define apr_file_open_flags_stderr_REQUIRED_ARGC 3
#define apr_file_open_flags_stderr_OPTIONAL_ARGC 0
/* apr_file_open_flags_stderr
 *
 * Parameters:
 * - thefile: apr_file_t **
 * - flags: int
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_open_flags_stderr(mrb_state* mrb, mrb_value self) {
  mrb_value thefile;
  mrb_value flags;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &thefile, &flags, &pool);


  /* Type checking */
  TODO_type_check_apr_file_t_PTR_PTR(thefile);
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_file_t ** native_thefile = TODO_mruby_unbox_apr_file_t_PTR_PTR(thefile);

  int native_flags = mrb_fixnum(flags);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_file_open_flags_stderr(native_thefile, native_flags, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_open_flags_stdin_FUNCTION
#define apr_file_open_flags_stdin_REQUIRED_ARGC 3
#define apr_file_open_flags_stdin_OPTIONAL_ARGC 0
/* apr_file_open_flags_stdin
 *
 * Parameters:
 * - thefile: apr_file_t **
 * - flags: int
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_open_flags_stdin(mrb_state* mrb, mrb_value self) {
  mrb_value thefile;
  mrb_value flags;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &thefile, &flags, &pool);


  /* Type checking */
  TODO_type_check_apr_file_t_PTR_PTR(thefile);
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_file_t ** native_thefile = TODO_mruby_unbox_apr_file_t_PTR_PTR(thefile);

  int native_flags = mrb_fixnum(flags);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_file_open_flags_stdin(native_thefile, native_flags, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_open_flags_stdout_FUNCTION
#define apr_file_open_flags_stdout_REQUIRED_ARGC 3
#define apr_file_open_flags_stdout_OPTIONAL_ARGC 0
/* apr_file_open_flags_stdout
 *
 * Parameters:
 * - thefile: apr_file_t **
 * - flags: int
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_open_flags_stdout(mrb_state* mrb, mrb_value self) {
  mrb_value thefile;
  mrb_value flags;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &thefile, &flags, &pool);


  /* Type checking */
  TODO_type_check_apr_file_t_PTR_PTR(thefile);
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_file_t ** native_thefile = TODO_mruby_unbox_apr_file_t_PTR_PTR(thefile);

  int native_flags = mrb_fixnum(flags);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_file_open_flags_stdout(native_thefile, native_flags, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_open_stderr_FUNCTION
#define apr_file_open_stderr_REQUIRED_ARGC 1
#define apr_file_open_stderr_OPTIONAL_ARGC 0
/* apr_file_open_stderr
 *
 * Parameters:
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_open_stderr(mrb_state* mrb, mrb_value self) {
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &pool);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_file_t * native_thefile;
  apr_status_t result = apr_file_open_stderr(&native_thefile, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  mrb_value results = mrb_ary_new(mrb);
  mrb_ary_push(mrb, results, return_value);
  if (result == 0) {
     mrb_ary_push(mrb, results, mruby_box_apr_file_t(mrb, native_thefile));
  }
  else {
     mrb_ary_push(mrb, results, mrb_nil_value());
  }

  return results;
}
#endif

#if BIND_apr_file_open_stdin_FUNCTION
#define apr_file_open_stdin_REQUIRED_ARGC 1
#define apr_file_open_stdin_OPTIONAL_ARGC 0
/* apr_file_open_stdin
 *
 * Parameters:
 * - thefile: apr_file_t **
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_open_stdin(mrb_state* mrb, mrb_value self) {
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &pool);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_file_t * native_thefile;
  apr_status_t result = apr_file_open_stdin(&native_thefile, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
     mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
     return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  mrb_value results = mrb_ary_new(mrb);
  mrb_ary_push(mrb, results, return_value);
  if (result == 0) {
     mrb_ary_push(mrb, results, mruby_box_apr_file_t(mrb, native_thefile));
  }
  else {
     mrb_ary_push(mrb, results, mrb_nil_value());
  }

  return results;
}
#endif

#if BIND_apr_file_open_stdout_FUNCTION
#define apr_file_open_stdout_REQUIRED_ARGC 1
#define apr_file_open_stdout_OPTIONAL_ARGC 0
/* apr_file_open_stdout
 *
 * Parameters:
 * - thefile: apr_file_t **
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_open_stdout(mrb_state* mrb, mrb_value self) {
   mrb_value pool;

   /* Fetch the args */
   mrb_get_args(mrb, "o", &pool);

   /* Type checking */
   if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
      mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
      return mrb_nil_value();
   }

   /* Unbox parameters */
   apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

   /* Invocation */
   apr_file_t * native_thefile;
   apr_status_t result = apr_file_open_stdout(&native_thefile, native_pool);

   /* Box the return value */
   if (result > MRB_INT_MAX) {
      mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
      return mrb_nil_value();
   }
   mrb_value return_value = mrb_fixnum_value(result);

   mrb_value results = mrb_ary_new(mrb);
   mrb_ary_push(mrb, results, return_value);
   if (result == 0) {
      mrb_ary_push(mrb, results, mruby_box_apr_file_t(mrb, native_thefile));
   }
   else {
      mrb_ary_push(mrb, results, mrb_nil_value());
   }

   return results;
}
#endif

#if BIND_apr_file_perms_set_FUNCTION
#define apr_file_perms_set_REQUIRED_ARGC 2
#define apr_file_perms_set_OPTIONAL_ARGC 0
/* apr_file_perms_set
 *
 * Parameters:
 * - fname: const char *
 * - perms: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_perms_set(mrb_state* mrb, mrb_value self) {
  mrb_value fname;
  mrb_value perms;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &fname, &perms);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, fname, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, perms, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  const char * native_fname = mrb_string_value_cstr(mrb, &fname);
  int native_perms = mrb_fixnum(perms);

  /* Invocation */
  apr_status_t result = apr_file_perms_set(native_fname, native_perms);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_pipe_create_FUNCTION
#define apr_file_pipe_create_REQUIRED_ARGC 1
#define apr_file_pipe_create_OPTIONAL_ARGC 0
/* apr_file_pipe_create
 *
 * Parameters:
 * - pool: AprPoolT
 * Return Type: [errno: Fixnum, readEnd: AprFileT, writeEnd: AprFileT]
 */
mrb_value
mrb_APR_apr_file_pipe_create(mrb_state* mrb, mrb_value self) {
   mrb_value pool;

   /* Fetch the args */
   mrb_get_args(mrb, "o", &pool);

   /* Type checking */
   if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
      mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
      return mrb_nil_value();
   }

   /* Unbox parameters */
   apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

   /* Invocation */
   apr_file_t * native_in;
   apr_file_t * native_out;
   apr_status_t result = apr_file_pipe_create(&native_in, &native_out, native_pool);

   /* Box the return value */
   if (result > MRB_INT_MAX) {
      mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
      return mrb_nil_value();
   }
   mrb_value return_value = mrb_fixnum_value(result);

   mrb_value results = mrb_ary_new(mrb);
   mrb_ary_push(mrb, results, return_value);
   if (result == 0) {
      mrb_ary_push(mrb, results, mruby_box_apr_file_t(mrb, native_in));
      mrb_ary_push(mrb, results, mruby_box_apr_file_t(mrb, native_out));
   }
   else {
      mrb_ary_push(mrb, results, mrb_nil_value());
      mrb_ary_push(mrb, results, mrb_nil_value());
   }

  return results;
}
#endif

#if BIND_apr_file_pipe_create_ex_FUNCTION
#define apr_file_pipe_create_ex_REQUIRED_ARGC 4
#define apr_file_pipe_create_ex_OPTIONAL_ARGC 0
/* apr_file_pipe_create_ex
 *
 * Parameters:
 * - in: apr_file_t **
 * - out: apr_file_t **
 * - blocking: int
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_pipe_create_ex(mrb_state* mrb, mrb_value self) {
  mrb_value in;
  mrb_value out;
  mrb_value blocking;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &in, &out, &blocking, &pool);


  /* Type checking */
  TODO_type_check_apr_file_t_PTR_PTR(in);
  TODO_type_check_apr_file_t_PTR_PTR(out);
  if (!mrb_obj_is_kind_of(mrb, blocking, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_file_t ** native_in = TODO_mruby_unbox_apr_file_t_PTR_PTR(in);

  apr_file_t ** native_out = TODO_mruby_unbox_apr_file_t_PTR_PTR(out);

  int native_blocking = mrb_fixnum(blocking);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_file_pipe_create_ex(native_in, native_out, native_blocking, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_pipe_timeout_get_FUNCTION
#define apr_file_pipe_timeout_get_REQUIRED_ARGC 2
#define apr_file_pipe_timeout_get_OPTIONAL_ARGC 0
/* apr_file_pipe_timeout_get
 *
 * Parameters:
 * - thepipe: apr_file_t *
 * - timeout: long long *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_pipe_timeout_get(mrb_state* mrb, mrb_value self) {
  mrb_value thepipe;
  mrb_value timeout;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &thepipe, &timeout);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, thepipe, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  TODO_type_check_long_long_PTR(timeout);


  /* Unbox parameters */
  apr_file_t * native_thepipe = (mrb_nil_p(thepipe) ? NULL : mruby_unbox_apr_file_t(thepipe));

  long long * native_timeout = TODO_mruby_unbox_long_long_PTR(timeout);

  /* Invocation */
  apr_status_t result = apr_file_pipe_timeout_get(native_thepipe, native_timeout);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_pipe_timeout_set_FUNCTION
#define apr_file_pipe_timeout_set_REQUIRED_ARGC 2
#define apr_file_pipe_timeout_set_OPTIONAL_ARGC 0
/* apr_file_pipe_timeout_set
 *
 * Parameters:
 * - thepipe: apr_file_t *
 * - timeout: long long
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_pipe_timeout_set(mrb_state* mrb, mrb_value self) {
  mrb_value thepipe;
  mrb_value timeout;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &thepipe, &timeout);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, thepipe, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  TODO_type_check_long_long(timeout);


  /* Unbox parameters */
  apr_file_t * native_thepipe = (mrb_nil_p(thepipe) ? NULL : mruby_unbox_apr_file_t(thepipe));

  long long native_timeout = TODO_mruby_unbox_long_long(timeout);

  /* Invocation */
  apr_status_t result = apr_file_pipe_timeout_set(native_thepipe, native_timeout);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_printf_FUNCTION
#define apr_file_printf_REQUIRED_ARGC 2
#define apr_file_printf_OPTIONAL_ARGC 0
/* apr_file_printf
 *
 * Parameters:
 * - fptr: apr_file_t *
 * - format: const char *
 * Return Type: int
 */
mrb_value
mrb_APR_apr_file_printf(mrb_state* mrb, mrb_value self) {
  mrb_value fptr;
  mrb_value format;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &fptr, &format);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, fptr, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, format, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_file_t * native_fptr = (mrb_nil_p(fptr) ? NULL : mruby_unbox_apr_file_t(fptr));

  const char * native_format = mrb_string_value_cstr(mrb, &format);

  /* Invocation */
  int result = apr_file_printf(native_fptr, native_format);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_putc_FUNCTION
#define apr_file_putc_REQUIRED_ARGC 2
#define apr_file_putc_OPTIONAL_ARGC 0
/* apr_file_putc
 *
 * Parameters:
 * - ch: char
 * - thefile: apr_file_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_putc(mrb_state* mrb, mrb_value self) {
  mrb_value ch;
  mrb_value thefile;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &ch, &thefile);


  /* Type checking */
  TODO_type_check_char(ch);
  if (!mrb_obj_is_kind_of(mrb, thefile, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  char native_ch = TODO_mruby_unbox_char(ch);

  apr_file_t * native_thefile = (mrb_nil_p(thefile) ? NULL : mruby_unbox_apr_file_t(thefile));

  /* Invocation */
  apr_status_t result = apr_file_putc(native_ch, native_thefile);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_puts_FUNCTION
#define apr_file_puts_REQUIRED_ARGC 2
#define apr_file_puts_OPTIONAL_ARGC 0
/* apr_file_puts
 *
 * Parameters:
 * - str: const char *
 * - thefile: apr_file_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_puts(mrb_state* mrb, mrb_value self) {
  mrb_value str;
  mrb_value thefile;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &str, &thefile);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, str, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, thefile, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  const char * native_str = mrb_string_value_cstr(mrb, &str);

  apr_file_t * native_thefile = (mrb_nil_p(thefile) ? NULL : mruby_unbox_apr_file_t(thefile));

  /* Invocation */
  apr_status_t result = apr_file_puts(native_str, native_thefile);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_read_FUNCTION
#define apr_file_read_REQUIRED_ARGC 2
#define apr_file_read_OPTIONAL_ARGC 0
/* apr_file_read
 *
 * Parameters:
 * - thefile: AprFileT
 * - nbytes: Fixnum
 * Return Type: [int, String] (error & string of bytes read)
 */
mrb_value
mrb_APR_apr_file_read(mrb_state* mrb, mrb_value self) {
  mrb_value thefile;
  mrb_value nbytes;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &thefile, &nbytes);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, thefile, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, nbytes, mrb->fixnum_class)) {
     mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
     return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_file_t * native_thefile = (mrb_nil_p(thefile) ? NULL : mruby_unbox_apr_file_t(thefile));
  apr_size_t native_nbytes = mrb_fixnum(nbytes);

  /* Invocation */
  char * native_buf = (char*)malloc(native_nbytes); /* No null terminator will be appended */
  apr_status_t result = apr_file_read(native_thefile, native_buf, &native_nbytes);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  mrb_value ruby_buf = mrb_str_new(mrb, native_buf, native_nbytes);
  free(native_buf);
  native_buf = NULL;

  mrb_value results = mrb_ary_new(mrb);
  mrb_ary_push(mrb, results, return_value);
  mrb_ary_push(mrb, results, ruby_buf);

  return results;
}
#endif

#if BIND_apr_file_read_full_FUNCTION
#define apr_file_read_full_REQUIRED_ARGC 4
#define apr_file_read_full_OPTIONAL_ARGC 0
/* apr_file_read_full
 *
 * Parameters:
 * - thefile: apr_file_t *
 * - buf: void *
 * - nbytes: int
 * - bytes_read: int *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_read_full(mrb_state* mrb, mrb_value self) {
  mrb_value thefile;
  mrb_value buf;
  mrb_value nbytes;
  mrb_value bytes_read;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &thefile, &buf, &nbytes, &bytes_read);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, thefile, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(buf);
  if (!mrb_obj_is_kind_of(mrb, nbytes, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(bytes_read);


  /* Unbox parameters */
  apr_file_t * native_thefile = (mrb_nil_p(thefile) ? NULL : mruby_unbox_apr_file_t(thefile));

  void * native_buf = TODO_mruby_unbox_void_PTR(buf);

  int native_nbytes = mrb_fixnum(nbytes);

  int * native_bytes_read = TODO_mruby_unbox_int_PTR(bytes_read);

  /* Invocation */
  apr_status_t result = apr_file_read_full(native_thefile, native_buf, native_nbytes, native_bytes_read);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_remove_FUNCTION
#define apr_file_remove_REQUIRED_ARGC 2
#define apr_file_remove_OPTIONAL_ARGC 0
/* apr_file_remove
 *
 * Parameters:
 * - path: String
 * - pool: AprPoolT
 * Return Type: Fixnum (errno)
 */
mrb_value
mrb_APR_apr_file_remove(mrb_state* mrb, mrb_value self) {
  mrb_value path;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &path, &pool);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, path, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  const char * native_path = mrb_string_value_cstr(mrb, &path);
  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_file_remove(native_path, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_rename_FUNCTION
#define apr_file_rename_REQUIRED_ARGC 3
#define apr_file_rename_OPTIONAL_ARGC 0
/* apr_file_rename
 *
 * Parameters:
 * - from_path: String
 * - to_path: String
 * - pool: AprPoolT
 * Return Type: Fixnum (errno)
 */
mrb_value
mrb_APR_apr_file_rename(mrb_state* mrb, mrb_value self) {
  mrb_value from_path;
  mrb_value to_path;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &from_path, &to_path, &pool);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, from_path, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, to_path, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  const char * native_from_path = mrb_string_value_cstr(mrb, &from_path);
  const char * native_to_path = mrb_string_value_cstr(mrb, &to_path);
  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_file_rename(native_from_path, native_to_path, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_seek_FUNCTION
#define apr_file_seek_REQUIRED_ARGC 3
#define apr_file_seek_OPTIONAL_ARGC 0
/* apr_file_seek
 *
 * Parameters:
 * - thefile: AprFileT
 * - where: Fixnum
 * - offset: Fixnum
 * Return Type: [int, int] (errno & the actuall offset that resulted)
 */
mrb_value
mrb_APR_apr_file_seek(mrb_state* mrb, mrb_value self) {
  mrb_value thefile;
  mrb_value where;
  mrb_value offset;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &thefile, &where, &offset);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, thefile, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, where, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, offset, mrb->fixnum_class)) {
     mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
     return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_file_t * native_thefile = (mrb_nil_p(thefile) ? NULL : mruby_unbox_apr_file_t(thefile));
  apr_seek_where_t native_where = mrb_fixnum(where);
  apr_off_t native_offset = mrb_fixnum(offset);

  /* Invocation */
  apr_status_t result = apr_file_seek(native_thefile, native_where, &native_offset);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  mrb_value results = mrb_ary_new(mrb);
  mrb_ary_push(mrb, results, return_value);
  mrb_ary_push(mrb, results, mrb_fixnum_value(native_offset));

  return results;
}
#endif

#if BIND_apr_file_setaside_FUNCTION
#define apr_file_setaside_REQUIRED_ARGC 3
#define apr_file_setaside_OPTIONAL_ARGC 0
/* apr_file_setaside
 *
 * Parameters:
 * - new_file: apr_file_t **
 * - old_file: apr_file_t *
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_setaside(mrb_state* mrb, mrb_value self) {
  mrb_value new_file;
  mrb_value old_file;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &new_file, &old_file, &p);


  /* Type checking */
  TODO_type_check_apr_file_t_PTR_PTR(new_file);
  if (!mrb_obj_is_kind_of(mrb, old_file, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_file_t ** native_new_file = TODO_mruby_unbox_apr_file_t_PTR_PTR(new_file);

  apr_file_t * native_old_file = (mrb_nil_p(old_file) ? NULL : mruby_unbox_apr_file_t(old_file));

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_file_setaside(native_new_file, native_old_file, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_sync_FUNCTION
#define apr_file_sync_REQUIRED_ARGC 1
#define apr_file_sync_OPTIONAL_ARGC 0
/* apr_file_sync
 *
 * Parameters:
 * - thefile: apr_file_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_sync(mrb_state* mrb, mrb_value self) {
  mrb_value thefile;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &thefile);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, thefile, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_file_t * native_thefile = (mrb_nil_p(thefile) ? NULL : mruby_unbox_apr_file_t(thefile));

  /* Invocation */
  apr_status_t result = apr_file_sync(native_thefile);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_trunc_FUNCTION
#define apr_file_trunc_REQUIRED_ARGC 2
#define apr_file_trunc_OPTIONAL_ARGC 0
/* apr_file_trunc
 *
 * Parameters:
 * - fp: apr_file_t *
 * - offset: long long
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_trunc(mrb_state* mrb, mrb_value self) {
  mrb_value fp;
  mrb_value offset;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &fp, &offset);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, fp, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, offset, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_file_t * native_fp = (mrb_nil_p(fp) ? NULL : mruby_unbox_apr_file_t(fp));

  apr_off_t native_offset = mrb_fixnum(offset);

  /* Invocation */
  apr_status_t result = apr_file_trunc(native_fp, native_offset);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_ungetc_FUNCTION
#define apr_file_ungetc_REQUIRED_ARGC 2
#define apr_file_ungetc_OPTIONAL_ARGC 0
/* apr_file_ungetc
 *
 * Parameters:
 * - ch: char
 * - thefile: apr_file_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_ungetc(mrb_state* mrb, mrb_value self) {
  mrb_value ch;
  mrb_value thefile;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &ch, &thefile);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, ch, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, thefile, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  char native_ch = mrb_string_value_ptr(mrb, ch)[0];
  apr_file_t * native_thefile = (mrb_nil_p(thefile) ? NULL : mruby_unbox_apr_file_t(thefile));

  /* Invocation */
  apr_status_t result = apr_file_ungetc(native_ch, native_thefile);

  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_unlock_FUNCTION
#define apr_file_unlock_REQUIRED_ARGC 1
#define apr_file_unlock_OPTIONAL_ARGC 0
/* apr_file_unlock
 *
 * Parameters:
 * - thefile: AprFileT
 * Return Type: Fixnum (errno)
 */
mrb_value
mrb_APR_apr_file_unlock(mrb_state* mrb, mrb_value self) {
  mrb_value thefile;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &thefile);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, thefile, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_file_t * native_thefile = (mrb_nil_p(thefile) ? NULL : mruby_unbox_apr_file_t(thefile));

  /* Invocation */
  apr_status_t result = apr_file_unlock(native_thefile);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_write_FUNCTION
#define apr_file_write_REQUIRED_ARGC 3
#define apr_file_write_OPTIONAL_ARGC 0
/* apr_file_write
 *
 * Parameters:
 * - thefile: AprFileT
 * - buf: String
 * - nbytes: Fixnum
 * Return Type: [err, int] (error code & bytes written)
 */
mrb_value
mrb_APR_apr_file_write(mrb_state* mrb, mrb_value self) {
  mrb_value thefile;
  mrb_value buf;
  mrb_value nbytes;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &thefile, &buf, &nbytes);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, thefile, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }

  if (!mrb_obj_is_kind_of(mrb, buf, mrb->string_class)) {
     mrb_raise(mrb, E_TYPE_ERROR, "String expected");
     return mrb_nil_value();
  }

  if (!mrb_obj_is_kind_of(mrb, nbytes, mrb->fixnum_class)) {
     mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
     return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_file_t * native_thefile = (mrb_nil_p(thefile) ? NULL : mruby_unbox_apr_file_t(thefile));
  /* Just writing, no need to copy */
  char * native_buf = RSTRING_PTR(buf);
  apr_size_t native_nbytes = mrb_fixnum(nbytes);

  /* Invocation */
  apr_status_t result = apr_file_write(native_thefile, native_buf, &native_nbytes);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  mrb_value results = mrb_ary_new(mrb);
  mrb_ary_push(mrb, results, return_value);
  mrb_ary_push(mrb, results, mrb_fixnum_value(native_nbytes));

  return results;
}
#endif

#if BIND_apr_file_write_full_FUNCTION
#define apr_file_write_full_REQUIRED_ARGC 4
#define apr_file_write_full_OPTIONAL_ARGC 0
/* apr_file_write_full
 *
 * Parameters:
 * - thefile: apr_file_t *
 * - buf: const void *
 * - nbytes: int
 * - bytes_written: int *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_write_full(mrb_state* mrb, mrb_value self) {
  mrb_value thefile;
  mrb_value buf;
  mrb_value nbytes;
  mrb_value bytes_written;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &thefile, &buf, &nbytes, &bytes_written);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, thefile, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_void_PTR(buf);
  if (!mrb_obj_is_kind_of(mrb, nbytes, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(bytes_written);


  /* Unbox parameters */
  apr_file_t * native_thefile = (mrb_nil_p(thefile) ? NULL : mruby_unbox_apr_file_t(thefile));

  const void * native_buf = TODO_mruby_unbox_const_void_PTR(buf);

  int native_nbytes = mrb_fixnum(nbytes);

  int * native_bytes_written = TODO_mruby_unbox_int_PTR(bytes_written);

  /* Invocation */
  apr_status_t result = apr_file_write_full(native_thefile, native_buf, native_nbytes, native_bytes_written);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_writev_FUNCTION
#define apr_file_writev_REQUIRED_ARGC 4
#define apr_file_writev_OPTIONAL_ARGC 0
/* apr_file_writev
 *
 * Parameters:
 * - thefile: apr_file_t *
 * - vec: const iovec *
 * - nvec: int
 * - nbytes: int *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_writev(mrb_state* mrb, mrb_value self) {
  mrb_value thefile;
  mrb_value vec;
  mrb_value nvec;
  mrb_value nbytes;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &thefile, &vec, &nvec, &nbytes);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, thefile, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_iovec_PTR(vec);
  if (!mrb_obj_is_kind_of(mrb, nvec, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(nbytes);


  /* Unbox parameters */
  apr_file_t * native_thefile = (mrb_nil_p(thefile) ? NULL : mruby_unbox_apr_file_t(thefile));

  const iovec * native_vec = TODO_mruby_unbox_const_iovec_PTR(vec);

  int native_nvec = mrb_fixnum(nvec);

  int * native_nbytes = TODO_mruby_unbox_int_PTR(nbytes);

  /* Invocation */
  apr_status_t result = apr_file_writev(native_thefile, native_vec, native_nvec, native_nbytes);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_file_writev_full_FUNCTION
#define apr_file_writev_full_REQUIRED_ARGC 4
#define apr_file_writev_full_OPTIONAL_ARGC 0
/* apr_file_writev_full
 *
 * Parameters:
 * - thefile: apr_file_t *
 * - vec: const iovec *
 * - nvec: int
 * - nbytes: int *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_file_writev_full(mrb_state* mrb, mrb_value self) {
  mrb_value thefile;
  mrb_value vec;
  mrb_value nvec;
  mrb_value nbytes;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &thefile, &vec, &nvec, &nbytes);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, thefile, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_iovec_PTR(vec);
  if (!mrb_obj_is_kind_of(mrb, nvec, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(nbytes);


  /* Unbox parameters */
  apr_file_t * native_thefile = (mrb_nil_p(thefile) ? NULL : mruby_unbox_apr_file_t(thefile));

  const iovec * native_vec = TODO_mruby_unbox_const_iovec_PTR(vec);

  int native_nvec = mrb_fixnum(nvec);

  int * native_nbytes = TODO_mruby_unbox_int_PTR(nbytes);

  /* Invocation */
  apr_status_t result = apr_file_writev_full(native_thefile, native_vec, native_nvec, native_nbytes);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_filepath_encoding_FUNCTION
#define apr_filepath_encoding_REQUIRED_ARGC 2
#define apr_filepath_encoding_OPTIONAL_ARGC 0
/* apr_filepath_encoding
 *
 * Parameters:
 * - style: int *
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_filepath_encoding(mrb_state* mrb, mrb_value self) {
  mrb_value style;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &style, &p);


  /* Type checking */
  TODO_type_check_int_PTR(style);
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int * native_style = TODO_mruby_unbox_int_PTR(style);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_filepath_encoding(native_style, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_filepath_get_FUNCTION
#define apr_filepath_get_REQUIRED_ARGC 3
#define apr_filepath_get_OPTIONAL_ARGC 0
/* apr_filepath_get
 *
 * Parameters:
 * - path: char **
 * - flags: int
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_filepath_get(mrb_state* mrb, mrb_value self) {
  mrb_value path;
  mrb_value flags;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &path, &flags, &p);


  /* Type checking */
  TODO_type_check_char_PTR_PTR(path);
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  char ** native_path = TODO_mruby_unbox_char_PTR_PTR(path);

  int native_flags = mrb_fixnum(flags);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_filepath_get(native_path, native_flags, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_filepath_list_merge_FUNCTION
#define apr_filepath_list_merge_REQUIRED_ARGC 3
#define apr_filepath_list_merge_OPTIONAL_ARGC 0
/* apr_filepath_list_merge
 *
 * Parameters:
 * - liststr: char **
 * - pathelts: apr_array_header_t *
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_filepath_list_merge(mrb_state* mrb, mrb_value self) {
  mrb_value liststr;
  mrb_value pathelts;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &liststr, &pathelts, &p);


  /* Type checking */
  TODO_type_check_char_PTR_PTR(liststr);
  if (!mrb_obj_is_kind_of(mrb, pathelts, AprArrayHeaderT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprArrayHeaderT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  char ** native_liststr = TODO_mruby_unbox_char_PTR_PTR(liststr);

  apr_array_header_t * native_pathelts = (mrb_nil_p(pathelts) ? NULL : mruby_unbox_apr_array_header_t(pathelts));

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_filepath_list_merge(native_liststr, native_pathelts, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_filepath_list_split_FUNCTION
#define apr_filepath_list_split_REQUIRED_ARGC 3
#define apr_filepath_list_split_OPTIONAL_ARGC 0
/* apr_filepath_list_split
 *
 * Parameters:
 * - pathelts: apr_array_header_t **
 * - liststr: const char *
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_filepath_list_split(mrb_state* mrb, mrb_value self) {
  mrb_value pathelts;
  mrb_value liststr;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &pathelts, &liststr, &p);


  /* Type checking */
  TODO_type_check_apr_array_header_t_PTR_PTR(pathelts);
  if (!mrb_obj_is_kind_of(mrb, liststr, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_array_header_t ** native_pathelts = TODO_mruby_unbox_apr_array_header_t_PTR_PTR(pathelts);

  const char * native_liststr = mrb_string_value_cstr(mrb, &liststr);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_filepath_list_split(native_pathelts, native_liststr, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_filepath_merge_FUNCTION
#define apr_filepath_merge_REQUIRED_ARGC 5
#define apr_filepath_merge_OPTIONAL_ARGC 0
/* apr_filepath_merge
 *
 * Parameters:
 * - newpath: char **
 * - rootpath: const char *
 * - addpath: const char *
 * - flags: int
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_filepath_merge(mrb_state* mrb, mrb_value self) {
  mrb_value newpath;
  mrb_value rootpath;
  mrb_value addpath;
  mrb_value flags;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &newpath, &rootpath, &addpath, &flags, &p);


  /* Type checking */
  TODO_type_check_char_PTR_PTR(newpath);
  if (!mrb_obj_is_kind_of(mrb, rootpath, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, addpath, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  char ** native_newpath = TODO_mruby_unbox_char_PTR_PTR(newpath);

  const char * native_rootpath = mrb_string_value_cstr(mrb, &rootpath);

  const char * native_addpath = mrb_string_value_cstr(mrb, &addpath);

  int native_flags = mrb_fixnum(flags);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_filepath_merge(native_newpath, native_rootpath, native_addpath, native_flags, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_filepath_name_get_FUNCTION
#define apr_filepath_name_get_REQUIRED_ARGC 1
#define apr_filepath_name_get_OPTIONAL_ARGC 0
/* apr_filepath_name_get
 *
 * Parameters:
 * - pathname: const char *
 * Return Type: const char *
 */
mrb_value
mrb_APR_apr_filepath_name_get(mrb_state* mrb, mrb_value self) {
  mrb_value pathname;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &pathname);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pathname, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  const char * native_pathname = mrb_string_value_cstr(mrb, &pathname);

  /* Invocation */
  const char * result = apr_filepath_name_get(native_pathname);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_filepath_root_FUNCTION
#define apr_filepath_root_REQUIRED_ARGC 4
#define apr_filepath_root_OPTIONAL_ARGC 0
/* apr_filepath_root
 *
 * Parameters:
 * - rootpath: const char **
 * - filepath: const char **
 * - flags: int
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_filepath_root(mrb_state* mrb, mrb_value self) {
  mrb_value rootpath;
  mrb_value filepath;
  mrb_value flags;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &rootpath, &filepath, &flags, &p);


  /* Type checking */
  TODO_type_check_const_char_PTR_PTR(rootpath);
  TODO_type_check_const_char_PTR_PTR(filepath);
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char ** native_rootpath = TODO_mruby_unbox_const_char_PTR_PTR(rootpath);

  const char ** native_filepath = TODO_mruby_unbox_const_char_PTR_PTR(filepath);

  int native_flags = mrb_fixnum(flags);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_filepath_root(native_rootpath, native_filepath, native_flags, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_filepath_set_FUNCTION
#define apr_filepath_set_REQUIRED_ARGC 2
#define apr_filepath_set_OPTIONAL_ARGC 0
/* apr_filepath_set
 *
 * Parameters:
 * - path: const char *
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_filepath_set(mrb_state* mrb, mrb_value self) {
  mrb_value path;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &path, &p);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, path, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_path = mrb_string_value_cstr(mrb, &path);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_filepath_set(native_path, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_fnmatch_FUNCTION
#define apr_fnmatch_REQUIRED_ARGC 3
#define apr_fnmatch_OPTIONAL_ARGC 0
/* apr_fnmatch
 *
 * Parameters:
 * - pattern: const char *
 * - strings: const char *
 * - flags: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_fnmatch(mrb_state* mrb, mrb_value self) {
  mrb_value pattern;
  mrb_value strings;
  mrb_value flags;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &pattern, &strings, &flags);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pattern, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, strings, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  const char * native_pattern = mrb_string_value_cstr(mrb, &pattern);
  const char * native_strings = mrb_string_value_cstr(mrb, &strings);
  int native_flags = mrb_fixnum(flags);

  /* Invocation */
  apr_status_t result = apr_fnmatch(native_pattern, native_strings, native_flags);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_fnmatch_test_FUNCTION
#define apr_fnmatch_test_REQUIRED_ARGC 1
#define apr_fnmatch_test_OPTIONAL_ARGC 0
/* apr_fnmatch_test
 *
 * Parameters:
 * - pattern: const char *
 * Return Type: int
 */
mrb_value
mrb_APR_apr_fnmatch_test(mrb_state* mrb, mrb_value self) {
  mrb_value pattern;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &pattern);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pattern, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  const char * native_pattern = mrb_string_value_cstr(mrb, &pattern);

  /* Invocation */
  int result = apr_fnmatch_test(native_pattern);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_generate_random_bytes_FUNCTION
#define apr_generate_random_bytes_REQUIRED_ARGC 4
#define apr_generate_random_bytes_OPTIONAL_ARGC 0
/* apr_generate_random_bytes
 *
 * Parameters:
 * - buf: unsigned char *
 * - length: int
 * - arg: void *
 * - err: const char *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_generate_random_bytes(mrb_state* mrb, mrb_value self) {
  mrb_value buf;
  mrb_value length;
  mrb_value arg;
  mrb_value err;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &buf, &length, &arg, &err);


  /* Type checking */
  TODO_type_check_unsigned_char_PTR(buf);
  if (!mrb_obj_is_kind_of(mrb, length, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(arg);
  if (!mrb_obj_is_kind_of(mrb, err, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  unsigned char * native_buf = TODO_mruby_unbox_unsigned_char_PTR(buf);

  int native_length = mrb_fixnum(length);

  void * native_arg = TODO_mruby_unbox_void_PTR(arg);

  const char * native_err = mrb_string_value_cstr(mrb, &err);

  /* Invocation */
  apr_status_t result = apr_generate_random_bytes(native_buf, native_length, native_arg, native_err);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_gethostname_FUNCTION
#define apr_gethostname_REQUIRED_ARGC 3
#define apr_gethostname_OPTIONAL_ARGC 0
/* apr_gethostname
 *
 * Parameters:
 * - buf: char *
 * - len: int
 * - cont: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_gethostname(mrb_state* mrb, mrb_value self) {
  mrb_value buf;
  mrb_value len;
  mrb_value cont;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &buf, &len, &cont);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, buf, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, len, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, cont, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_buf = strdup(mrb_string_value_cstr(mrb, &buf));

  int native_len = mrb_fixnum(len);

  apr_pool_t * native_cont = (mrb_nil_p(cont) ? NULL : mruby_unbox_apr_pool_t(cont));

  /* Invocation */
  apr_status_t result = apr_gethostname(native_buf, native_len, native_cont);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_buf);
  native_buf = NULL;

  return return_value;
}
#endif

#if BIND_apr_getnameinfo_FUNCTION
#define apr_getnameinfo_REQUIRED_ARGC 3
#define apr_getnameinfo_OPTIONAL_ARGC 0
/* apr_getnameinfo
 *
 * Parameters:
 * - hostname: char **
 * - sa: apr_sockaddr_t *
 * - flags: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_getnameinfo(mrb_state* mrb, mrb_value self) {
  mrb_value hostname;
  mrb_value sa;
  mrb_value flags;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &hostname, &sa, &flags);


  /* Type checking */
  TODO_type_check_char_PTR_PTR(hostname);
  if (!mrb_obj_is_kind_of(mrb, sa, AprSockaddrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSockaddrT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  char ** native_hostname = TODO_mruby_unbox_char_PTR_PTR(hostname);

  apr_sockaddr_t * native_sa = (mrb_nil_p(sa) ? NULL : mruby_unbox_apr_sockaddr_t(sa));

  int native_flags = mrb_fixnum(flags);

  /* Invocation */
  apr_status_t result = apr_getnameinfo(native_hostname, native_sa, native_flags);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_getopt_FUNCTION
#define apr_getopt_REQUIRED_ARGC 4
#define apr_getopt_OPTIONAL_ARGC 0
/* apr_getopt
 *
 * Parameters:
 * - os: apr_getopt_t *
 * - opts: const char *
 * - option_ch: char *
 * - option_arg: const char **
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_getopt(mrb_state* mrb, mrb_value self) {
  mrb_value os;
  mrb_value opts;
  mrb_value option_ch;
  mrb_value option_arg;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &os, &opts, &option_ch, &option_arg);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, os, AprGetoptT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprGetoptT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, opts, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, option_ch, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_char_PTR_PTR(option_arg);


  /* Unbox parameters */
  apr_getopt_t * native_os = (mrb_nil_p(os) ? NULL : mruby_unbox_apr_getopt_t(os));

  const char * native_opts = mrb_string_value_cstr(mrb, &opts);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_option_ch = strdup(mrb_string_value_cstr(mrb, &option_ch));

  const char ** native_option_arg = TODO_mruby_unbox_const_char_PTR_PTR(option_arg);

  /* Invocation */
  apr_status_t result = apr_getopt(native_os, native_opts, native_option_ch, native_option_arg);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_option_ch);
  native_option_ch = NULL;

  return return_value;
}
#endif

#if BIND_apr_getopt_init_FUNCTION
#define apr_getopt_init_REQUIRED_ARGC 4
#define apr_getopt_init_OPTIONAL_ARGC 0
/* apr_getopt_init
 *
 * Parameters:
 * - os: apr_getopt_t **
 * - cont: apr_pool_t *
 * - argc: int
 * - argv: const char *const *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_getopt_init(mrb_state* mrb, mrb_value self) {
  mrb_value os;
  mrb_value cont;
  mrb_value argc;
  mrb_value argv;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &os, &cont, &argc, &argv);


  /* Type checking */
  TODO_type_check_apr_getopt_t_PTR_PTR(os);
  if (!mrb_obj_is_kind_of(mrb, cont, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, argc, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_char_PTR_const_PTR(argv);


  /* Unbox parameters */
  apr_getopt_t ** native_os = TODO_mruby_unbox_apr_getopt_t_PTR_PTR(os);

  apr_pool_t * native_cont = (mrb_nil_p(cont) ? NULL : mruby_unbox_apr_pool_t(cont));

  int native_argc = mrb_fixnum(argc);

  const char *const * native_argv = TODO_mruby_unbox_const_char_PTR_const_PTR(argv);

  /* Invocation */
  apr_status_t result = apr_getopt_init(native_os, native_cont, native_argc, native_argv);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_getopt_long_FUNCTION
#define apr_getopt_long_REQUIRED_ARGC 6
#define apr_getopt_long_OPTIONAL_ARGC 0
/* apr_getopt_long
 *
 * Parameters:
 * - os: apr_getopt_t *
 * - opts: const apr_getopt_option_t *
 * - option_ch: int *
 * - option_arg: const char **
 * - key: const char *
 * - klen: int *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_getopt_long(mrb_state* mrb, mrb_value self) {
  mrb_value os;
  mrb_value opts;
  mrb_value option_ch;
  mrb_value option_arg;
  mrb_value key;
  mrb_value klen;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooo", &os, &opts, &option_ch, &option_arg, &key, &klen);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, os, AprGetoptT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprGetoptT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, opts, AprGetoptOptionT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprGetoptOptionT expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(option_ch);
  TODO_type_check_const_char_PTR_PTR(option_arg);
  if (!mrb_obj_is_kind_of(mrb, key, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(klen);


  /* Unbox parameters */
  apr_getopt_t * native_os = (mrb_nil_p(os) ? NULL : mruby_unbox_apr_getopt_t(os));

  const apr_getopt_option_t * native_opts = (mrb_nil_p(opts) ? NULL : mruby_unbox_const apr_getopt_option_t(opts));

  int * native_option_ch = TODO_mruby_unbox_int_PTR(option_ch);

  const char ** native_option_arg = TODO_mruby_unbox_const_char_PTR_PTR(option_arg);

  const char * native_key = mrb_string_value_cstr(mrb, &key);

  int * native_klen = TODO_mruby_unbox_int_PTR(klen);

  /* Invocation */
  apr_status_t result = apr_getopt_long(native_os, native_opts, native_option_ch, native_option_arg, native_key, native_klen);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_getservbyname_FUNCTION
#define apr_getservbyname_REQUIRED_ARGC 2
#define apr_getservbyname_OPTIONAL_ARGC 0
/* apr_getservbyname
 *
 * Parameters:
 * - sockaddr: apr_sockaddr_t *
 * - servname: const char *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_getservbyname(mrb_state* mrb, mrb_value self) {
  mrb_value sockaddr;
  mrb_value servname;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sockaddr, &servname);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sockaddr, AprSockaddrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSockaddrT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, servname, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_sockaddr_t * native_sockaddr = (mrb_nil_p(sockaddr) ? NULL : mruby_unbox_apr_sockaddr_t(sockaddr));

  const char * native_servname = mrb_string_value_cstr(mrb, &servname);

  /* Invocation */
  apr_status_t result = apr_getservbyname(native_sockaddr, native_servname);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_gid_compare_FUNCTION
#define apr_gid_compare_REQUIRED_ARGC 2
#define apr_gid_compare_OPTIONAL_ARGC 0
/* apr_gid_compare
 *
 * Parameters:
 * - left: void *
 * - right: void *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_gid_compare(mrb_state* mrb, mrb_value self) {
  mrb_value left;
  mrb_value right;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &left, &right);


  /* Type checking */
  TODO_type_check_void_PTR(left);
  TODO_type_check_void_PTR(right);


  /* Unbox parameters */
  void * native_left = TODO_mruby_unbox_void_PTR(left);

  void * native_right = TODO_mruby_unbox_void_PTR(right);

  /* Invocation */
  apr_status_t result = apr_gid_compare(native_left, native_right);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_gid_get_FUNCTION
#define apr_gid_get_REQUIRED_ARGC 3
#define apr_gid_get_OPTIONAL_ARGC 0
/* apr_gid_get
 *
 * Parameters:
 * - groupid: void **
 * - groupname: const char *
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_gid_get(mrb_state* mrb, mrb_value self) {
  mrb_value groupid;
  mrb_value groupname;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &groupid, &groupname, &p);


  /* Type checking */
  TODO_type_check_void_PTR_PTR(groupid);
  if (!mrb_obj_is_kind_of(mrb, groupname, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void ** native_groupid = TODO_mruby_unbox_void_PTR_PTR(groupid);

  const char * native_groupname = mrb_string_value_cstr(mrb, &groupname);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_gid_get(native_groupid, native_groupname, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_gid_name_get_FUNCTION
#define apr_gid_name_get_REQUIRED_ARGC 3
#define apr_gid_name_get_OPTIONAL_ARGC 0
/* apr_gid_name_get
 *
 * Parameters:
 * - groupname: char **
 * - groupid: void *
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_gid_name_get(mrb_state* mrb, mrb_value self) {
  mrb_value groupname;
  mrb_value groupid;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &groupname, &groupid, &p);


  /* Type checking */
  TODO_type_check_char_PTR_PTR(groupname);
  TODO_type_check_void_PTR(groupid);
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  char ** native_groupname = TODO_mruby_unbox_char_PTR_PTR(groupname);

  void * native_groupid = TODO_mruby_unbox_void_PTR(groupid);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_gid_name_get(native_groupname, native_groupid, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_hash_clear_FUNCTION
#define apr_hash_clear_REQUIRED_ARGC 1
#define apr_hash_clear_OPTIONAL_ARGC 0
/* apr_hash_clear
 *
 * Parameters:
 * - ht: apr_hash_t *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_hash_clear(mrb_state* mrb, mrb_value self) {
  mrb_value ht;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &ht);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, ht, AprHashT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprHashT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_hash_t * native_ht = (mrb_nil_p(ht) ? NULL : mruby_unbox_apr_hash_t(ht));

  /* Invocation */
  apr_hash_clear(native_ht);

  return mrb_nil_value();
}
#endif

#if BIND_apr_hash_copy_FUNCTION
#define apr_hash_copy_REQUIRED_ARGC 2
#define apr_hash_copy_OPTIONAL_ARGC 0
/* apr_hash_copy
 *
 * Parameters:
 * - pool: apr_pool_t *
 * - h: const apr_hash_t *
 * Return Type: apr_hash_t *
 */
mrb_value
mrb_APR_apr_hash_copy(mrb_state* mrb, mrb_value self) {
  mrb_value pool;
  mrb_value h;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &pool, &h);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, h, AprHashT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprHashT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  const apr_hash_t * native_h = (mrb_nil_p(h) ? NULL : mruby_unbox_const apr_hash_t(h));

  /* Invocation */
  apr_hash_t * result = apr_hash_copy(native_pool, native_h);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_hash_t(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_hash_count_FUNCTION
#define apr_hash_count_REQUIRED_ARGC 1
#define apr_hash_count_OPTIONAL_ARGC 0
/* apr_hash_count
 *
 * Parameters:
 * - ht: apr_hash_t *
 * Return Type: unsigned int
 */
mrb_value
mrb_APR_apr_hash_count(mrb_state* mrb, mrb_value self) {
  mrb_value ht;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &ht);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, ht, AprHashT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprHashT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_hash_t * native_ht = (mrb_nil_p(ht) ? NULL : mruby_unbox_apr_hash_t(ht));

  /* Invocation */
  unsigned int result = apr_hash_count(native_ht);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_hash_do_FUNCTION
#define apr_hash_do_REQUIRED_ARGC 3
#define apr_hash_do_OPTIONAL_ARGC 0
/* apr_hash_do
 *
 * Parameters:
 * - comp: int (*)(void *, const void *, int, const void *)
 * - rec: void *
 * - ht: const apr_hash_t *
 * Return Type: int
 */
mrb_value
mrb_APR_apr_hash_do(mrb_state* mrb, mrb_value self) {
  mrb_value comp;
  mrb_value rec;
  mrb_value ht;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &comp, &rec, &ht);


  /* Type checking */
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_const_void_PTR_COMMA_intCOMMA_const_void_PTR_RPAREN(comp);
  TODO_type_check_void_PTR(rec);
  if (!mrb_obj_is_kind_of(mrb, ht, AprHashT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprHashT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int (*native_comp)(void *, const void *, int, const void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_const_void_PTR_COMMA_intCOMMA_const_void_PTR_RPAREN(comp);

  void * native_rec = TODO_mruby_unbox_void_PTR(rec);

  const apr_hash_t * native_ht = (mrb_nil_p(ht) ? NULL : mruby_unbox_const apr_hash_t(ht));

  /* Invocation */
  int result = apr_hash_do(native_comp, native_rec, native_ht);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_hash_first_FUNCTION
#define apr_hash_first_REQUIRED_ARGC 2
#define apr_hash_first_OPTIONAL_ARGC 0
/* apr_hash_first
 *
 * Parameters:
 * - p: apr_pool_t *
 * - ht: apr_hash_t *
 * Return Type: apr_hash_index_t *
 */
mrb_value
mrb_APR_apr_hash_first(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value ht;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &p, &ht);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, ht, AprHashT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprHashT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  apr_hash_t * native_ht = (mrb_nil_p(ht) ? NULL : mruby_unbox_apr_hash_t(ht));

  /* Invocation */
  apr_hash_index_t * result = apr_hash_first(native_p, native_ht);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_hash_index_t(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_hash_get_FUNCTION
#define apr_hash_get_REQUIRED_ARGC 3
#define apr_hash_get_OPTIONAL_ARGC 0
/* apr_hash_get
 *
 * Parameters:
 * - ht: apr_hash_t *
 * - key: const void *
 * - klen: int
 * Return Type: void *
 */
mrb_value
mrb_APR_apr_hash_get(mrb_state* mrb, mrb_value self) {
  mrb_value ht;
  mrb_value key;
  mrb_value klen;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &ht, &key, &klen);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, ht, AprHashT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprHashT expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_void_PTR(key);
  if (!mrb_obj_is_kind_of(mrb, klen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_hash_t * native_ht = (mrb_nil_p(ht) ? NULL : mruby_unbox_apr_hash_t(ht));

  const void * native_key = TODO_mruby_unbox_const_void_PTR(key);

  int native_klen = mrb_fixnum(klen);

  /* Invocation */
  void * result = apr_hash_get(native_ht, native_key, native_klen);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_hash_make_FUNCTION
#define apr_hash_make_REQUIRED_ARGC 1
#define apr_hash_make_OPTIONAL_ARGC 0
/* apr_hash_make
 *
 * Parameters:
 * - pool: apr_pool_t *
 * Return Type: apr_hash_t *
 */
mrb_value
mrb_APR_apr_hash_make(mrb_state* mrb, mrb_value self) {
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &pool);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_hash_t * result = apr_hash_make(native_pool);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_hash_t(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_hash_make_custom_FUNCTION
#define apr_hash_make_custom_REQUIRED_ARGC 2
#define apr_hash_make_custom_OPTIONAL_ARGC 0
/* apr_hash_make_custom
 *
 * Parameters:
 * - pool: apr_pool_t *
 * - hash_func: unsigned int (*)(const char *, int *)
 * Return Type: apr_hash_t *
 */
mrb_value
mrb_APR_apr_hash_make_custom(mrb_state* mrb, mrb_value self) {
  mrb_value pool;
  mrb_value hash_func;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &pool, &hash_func);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  TODO_type_check_unsigned_int_LPAREN_PTR_RPAREN_LPAREN_const_char_PTR_COMMA_int_PTR_RPAREN(hash_func);


  /* Unbox parameters */
  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  unsigned int (*native_hash_func)(const char *, int *) = TODO_mruby_unbox_unsigned_int_LPAREN_PTR_RPAREN_LPAREN_const_char_PTR_COMMA_int_PTR_RPAREN(hash_func);

  /* Invocation */
  apr_hash_t * result = apr_hash_make_custom(native_pool, native_hash_func);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_hash_t(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_hash_merge_FUNCTION
#define apr_hash_merge_REQUIRED_ARGC 15
#define apr_hash_merge_OPTIONAL_ARGC 0
/* apr_hash_merge
 *
 * Parameters:
 * - p: apr_pool_t *
 * - h1: const apr_hash_t *
 * - h2: const apr_hash_t *
 * - merger: void *(*)(apr_pool_t *, const void *, int, const void *, const void *, const void *)
 * - p: apr_pool_t *
 * - key: const void *
 * - klen: int
 * - h1_val: const void *
 * - h2_val: const void *
 * - data: const void *
 * - data: const void *
 * - rec: void *
 * - key: const void *
 * - klen: int
 * - value: const void *
 * Return Type: apr_hash_t *
 */
mrb_value
mrb_APR_apr_hash_merge(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value h1;
  mrb_value h2;
  mrb_value merger;
  mrb_value p;
  mrb_value key;
  mrb_value klen;
  mrb_value h1_val;
  mrb_value h2_val;
  mrb_value data;
  mrb_value data;
  mrb_value rec;
  mrb_value key;
  mrb_value klen;
  mrb_value value;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooooooooooooo", &p, &h1, &h2, &merger, &p, &key, &klen, &h1_val, &h2_val, &data, &data, &rec, &key, &klen, &value);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, h1, AprHashT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprHashT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, h2, AprHashT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprHashT expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR_LPAREN_PTR_RPAREN_LPAREN_apr_pool_t_PTR_COMMA_const_void_PTR_COMMA_intCOMMA_const_void_PTR_COMMA_const_void_PTR_COMMA_const_void_PTR_RPAREN(merger);
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_void_PTR(key);
  if (!mrb_obj_is_kind_of(mrb, klen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_void_PTR(h1_val);
  TODO_type_check_const_void_PTR(h2_val);
  TODO_type_check_const_void_PTR(data);
  TODO_type_check_const_void_PTR(data);
  TODO_type_check_void_PTR(rec);
  TODO_type_check_const_void_PTR(key);
  if (!mrb_obj_is_kind_of(mrb, klen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_void_PTR(value);


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const apr_hash_t * native_h1 = (mrb_nil_p(h1) ? NULL : mruby_unbox_const apr_hash_t(h1));

  const apr_hash_t * native_h2 = (mrb_nil_p(h2) ? NULL : mruby_unbox_const apr_hash_t(h2));

  void *(*native_merger)(apr_pool_t *, const void *, int, const void *, const void *, const void *) = TODO_mruby_unbox_void_PTR_LPAREN_PTR_RPAREN_LPAREN_apr_pool_t_PTR_COMMA_const_void_PTR_COMMA_intCOMMA_const_void_PTR_COMMA_const_void_PTR_COMMA_const_void_PTR_RPAREN(merger);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const void * native_key = TODO_mruby_unbox_const_void_PTR(key);

  int native_klen = mrb_fixnum(klen);

  const void * native_h1_val = TODO_mruby_unbox_const_void_PTR(h1_val);

  const void * native_h2_val = TODO_mruby_unbox_const_void_PTR(h2_val);

  const void * native_data = TODO_mruby_unbox_const_void_PTR(data);

  const void * native_data = TODO_mruby_unbox_const_void_PTR(data);

  void * native_rec = TODO_mruby_unbox_void_PTR(rec);

  const void * native_key = TODO_mruby_unbox_const_void_PTR(key);

  int native_klen = mrb_fixnum(klen);

  const void * native_value = TODO_mruby_unbox_const_void_PTR(value);

  /* Invocation */
  apr_hash_t * result = apr_hash_merge(native_p, native_h1, native_h2, native_merger, native_p, native_key, native_klen, native_h1_val, native_h2_val, native_data, native_data, native_rec, native_key, native_klen, native_value);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_hash_t(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_hash_next_FUNCTION
#define apr_hash_next_REQUIRED_ARGC 1
#define apr_hash_next_OPTIONAL_ARGC 0
/* apr_hash_next
 *
 * Parameters:
 * - hi: apr_hash_index_t *
 * Return Type: apr_hash_index_t *
 */
mrb_value
mrb_APR_apr_hash_next(mrb_state* mrb, mrb_value self) {
  mrb_value hi;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &hi);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, hi, AprHashIndexT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprHashIndexT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_hash_index_t * native_hi = (mrb_nil_p(hi) ? NULL : mruby_unbox_apr_hash_index_t(hi));

  /* Invocation */
  apr_hash_index_t * result = apr_hash_next(native_hi);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_hash_index_t(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_hash_overlay_FUNCTION
#define apr_hash_overlay_REQUIRED_ARGC 3
#define apr_hash_overlay_OPTIONAL_ARGC 0
/* apr_hash_overlay
 *
 * Parameters:
 * - p: apr_pool_t *
 * - overlay: const apr_hash_t *
 * - base: const apr_hash_t *
 * Return Type: apr_hash_t *
 */
mrb_value
mrb_APR_apr_hash_overlay(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value overlay;
  mrb_value base;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &p, &overlay, &base);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, overlay, AprHashT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprHashT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, base, AprHashT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprHashT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const apr_hash_t * native_overlay = (mrb_nil_p(overlay) ? NULL : mruby_unbox_const apr_hash_t(overlay));

  const apr_hash_t * native_base = (mrb_nil_p(base) ? NULL : mruby_unbox_const apr_hash_t(base));

  /* Invocation */
  apr_hash_t * result = apr_hash_overlay(native_p, native_overlay, native_base);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_hash_t(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_hash_set_FUNCTION
#define apr_hash_set_REQUIRED_ARGC 4
#define apr_hash_set_OPTIONAL_ARGC 0
/* apr_hash_set
 *
 * Parameters:
 * - ht: apr_hash_t *
 * - key: const void *
 * - klen: int
 * - val: const void *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_hash_set(mrb_state* mrb, mrb_value self) {
  mrb_value ht;
  mrb_value key;
  mrb_value klen;
  mrb_value val;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &ht, &key, &klen, &val);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, ht, AprHashT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprHashT expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_void_PTR(key);
  if (!mrb_obj_is_kind_of(mrb, klen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_void_PTR(val);


  /* Unbox parameters */
  apr_hash_t * native_ht = (mrb_nil_p(ht) ? NULL : mruby_unbox_apr_hash_t(ht));

  const void * native_key = TODO_mruby_unbox_const_void_PTR(key);

  int native_klen = mrb_fixnum(klen);

  const void * native_val = TODO_mruby_unbox_const_void_PTR(val);

  /* Invocation */
  apr_hash_set(native_ht, native_key, native_klen, native_val);

  return mrb_nil_value();
}
#endif

#if BIND_apr_hash_this_FUNCTION
#define apr_hash_this_REQUIRED_ARGC 4
#define apr_hash_this_OPTIONAL_ARGC 0
/* apr_hash_this
 *
 * Parameters:
 * - hi: apr_hash_index_t *
 * - key: const void **
 * - klen: int *
 * - val: void **
 * Return Type: void
 */
mrb_value
mrb_APR_apr_hash_this(mrb_state* mrb, mrb_value self) {
  mrb_value hi;
  mrb_value key;
  mrb_value klen;
  mrb_value val;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &hi, &key, &klen, &val);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, hi, AprHashIndexT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprHashIndexT expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_void_PTR_PTR(key);
  TODO_type_check_int_PTR(klen);
  TODO_type_check_void_PTR_PTR(val);


  /* Unbox parameters */
  apr_hash_index_t * native_hi = (mrb_nil_p(hi) ? NULL : mruby_unbox_apr_hash_index_t(hi));

  const void ** native_key = TODO_mruby_unbox_const_void_PTR_PTR(key);

  int * native_klen = TODO_mruby_unbox_int_PTR(klen);

  void ** native_val = TODO_mruby_unbox_void_PTR_PTR(val);

  /* Invocation */
  apr_hash_this(native_hi, native_key, native_klen, native_val);

  return mrb_nil_value();
}
#endif

#if BIND_apr_hash_this_key_FUNCTION
#define apr_hash_this_key_REQUIRED_ARGC 1
#define apr_hash_this_key_OPTIONAL_ARGC 0
/* apr_hash_this_key
 *
 * Parameters:
 * - hi: apr_hash_index_t *
 * Return Type: const void *
 */
mrb_value
mrb_APR_apr_hash_this_key(mrb_state* mrb, mrb_value self) {
  mrb_value hi;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &hi);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, hi, AprHashIndexT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprHashIndexT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_hash_index_t * native_hi = (mrb_nil_p(hi) ? NULL : mruby_unbox_apr_hash_index_t(hi));

  /* Invocation */
  const void * result = apr_hash_this_key(native_hi);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_const_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_hash_this_key_len_FUNCTION
#define apr_hash_this_key_len_REQUIRED_ARGC 1
#define apr_hash_this_key_len_OPTIONAL_ARGC 0
/* apr_hash_this_key_len
 *
 * Parameters:
 * - hi: apr_hash_index_t *
 * Return Type: apr_ssize_t
 */
mrb_value
mrb_APR_apr_hash_this_key_len(mrb_state* mrb, mrb_value self) {
  mrb_value hi;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &hi);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, hi, AprHashIndexT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprHashIndexT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_hash_index_t * native_hi = (mrb_nil_p(hi) ? NULL : mruby_unbox_apr_hash_index_t(hi));

  /* Invocation */
  apr_ssize_t result = apr_hash_this_key_len(native_hi);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_hash_this_val_FUNCTION
#define apr_hash_this_val_REQUIRED_ARGC 1
#define apr_hash_this_val_OPTIONAL_ARGC 0
/* apr_hash_this_val
 *
 * Parameters:
 * - hi: apr_hash_index_t *
 * Return Type: void *
 */
mrb_value
mrb_APR_apr_hash_this_val(mrb_state* mrb, mrb_value self) {
  mrb_value hi;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &hi);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, hi, AprHashIndexT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprHashIndexT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_hash_index_t * native_hi = (mrb_nil_p(hi) ? NULL : mruby_unbox_apr_hash_index_t(hi));

  /* Invocation */
  void * result = apr_hash_this_val(native_hi);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_hashfunc_default_FUNCTION
#define apr_hashfunc_default_REQUIRED_ARGC 2
#define apr_hashfunc_default_OPTIONAL_ARGC 0
/* apr_hashfunc_default
 *
 * Parameters:
 * - key: const char *
 * - klen: int *
 * Return Type: unsigned int
 */
mrb_value
mrb_APR_apr_hashfunc_default(mrb_state* mrb, mrb_value self) {
  mrb_value key;
  mrb_value klen;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &key, &klen);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, key, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(klen);


  /* Unbox parameters */
  const char * native_key = mrb_string_value_cstr(mrb, &key);

  int * native_klen = TODO_mruby_unbox_int_PTR(klen);

  /* Invocation */
  unsigned int result = apr_hashfunc_default(native_key, native_klen);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_initialize_FUNCTION
#define apr_initialize_REQUIRED_ARGC 0
#define apr_initialize_OPTIONAL_ARGC 0
/* apr_initialize
 *
 * Parameters: None
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_initialize(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  apr_status_t result = apr_initialize();

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_ipsubnet_create_FUNCTION
#define apr_ipsubnet_create_REQUIRED_ARGC 4
#define apr_ipsubnet_create_OPTIONAL_ARGC 0
/* apr_ipsubnet_create
 *
 * Parameters:
 * - ipsub: apr_ipsubnet_t **
 * - ipstr: const char *
 * - mask_or_numbits: const char *
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_ipsubnet_create(mrb_state* mrb, mrb_value self) {
  mrb_value ipsub;
  mrb_value ipstr;
  mrb_value mask_or_numbits;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &ipsub, &ipstr, &mask_or_numbits, &p);


  /* Type checking */
  TODO_type_check_apr_ipsubnet_t_PTR_PTR(ipsub);
  if (!mrb_obj_is_kind_of(mrb, ipstr, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, mask_or_numbits, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_ipsubnet_t ** native_ipsub = TODO_mruby_unbox_apr_ipsubnet_t_PTR_PTR(ipsub);

  const char * native_ipstr = mrb_string_value_cstr(mrb, &ipstr);

  const char * native_mask_or_numbits = mrb_string_value_cstr(mrb, &mask_or_numbits);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_ipsubnet_create(native_ipsub, native_ipstr, native_mask_or_numbits, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_ipsubnet_test_FUNCTION
#define apr_ipsubnet_test_REQUIRED_ARGC 2
#define apr_ipsubnet_test_OPTIONAL_ARGC 0
/* apr_ipsubnet_test
 *
 * Parameters:
 * - ipsub: apr_ipsubnet_t *
 * - sa: apr_sockaddr_t *
 * Return Type: int
 */
mrb_value
mrb_APR_apr_ipsubnet_test(mrb_state* mrb, mrb_value self) {
  mrb_value ipsub;
  mrb_value sa;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &ipsub, &sa);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, ipsub, AprIpsubnetT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprIpsubnetT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, sa, AprSockaddrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSockaddrT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_ipsubnet_t * native_ipsub = (mrb_nil_p(ipsub) ? NULL : mruby_unbox_apr_ipsubnet_t(ipsub));

  apr_sockaddr_t * native_sa = (mrb_nil_p(sa) ? NULL : mruby_unbox_apr_sockaddr_t(sa));

  /* Invocation */
  int result = apr_ipsubnet_test(native_ipsub, native_sa);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_is_empty_array_FUNCTION
#define apr_is_empty_array_REQUIRED_ARGC 1
#define apr_is_empty_array_OPTIONAL_ARGC 0
/* apr_is_empty_array
 *
 * Parameters:
 * - a: const apr_array_header_t *
 * Return Type: int
 */
mrb_value
mrb_APR_apr_is_empty_array(mrb_state* mrb, mrb_value self) {
  mrb_value a;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &a);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, a, AprArrayHeaderT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprArrayHeaderT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const apr_array_header_t * native_a = (mrb_nil_p(a) ? NULL : mruby_unbox_const apr_array_header_t(a));

  /* Invocation */
  int result = apr_is_empty_array(native_a);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_is_empty_table_FUNCTION
#define apr_is_empty_table_REQUIRED_ARGC 1
#define apr_is_empty_table_OPTIONAL_ARGC 0
/* apr_is_empty_table
 *
 * Parameters:
 * - t: const apr_table_t *
 * Return Type: int
 */
mrb_value
mrb_APR_apr_is_empty_table(mrb_state* mrb, mrb_value self) {
  mrb_value t;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &t);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, t, AprTableT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTableT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const apr_table_t * native_t = (mrb_nil_p(t) ? NULL : mruby_unbox_const apr_table_t(t));

  /* Invocation */
  int result = apr_is_empty_table(native_t);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_itoa_FUNCTION
#define apr_itoa_REQUIRED_ARGC 2
#define apr_itoa_OPTIONAL_ARGC 0
/* apr_itoa
 *
 * Parameters:
 * - p: apr_pool_t *
 * - n: int
 * Return Type: char *
 */
mrb_value
mrb_APR_apr_itoa(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value n;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &p, &n);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, n, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  int native_n = mrb_fixnum(n);

  /* Invocation */
  char * result = apr_itoa(native_p, native_n);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_ltoa_FUNCTION
#define apr_ltoa_REQUIRED_ARGC 2
#define apr_ltoa_OPTIONAL_ARGC 0
/* apr_ltoa
 *
 * Parameters:
 * - p: apr_pool_t *
 * - n: long
 * Return Type: char *
 */
mrb_value
mrb_APR_apr_ltoa(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value n;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &p, &n);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  TODO_type_check_long(n);


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  long native_n = TODO_mruby_unbox_long(n);

  /* Invocation */
  char * result = apr_ltoa(native_p, native_n);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_match_glob_FUNCTION
#define apr_match_glob_REQUIRED_ARGC 3
#define apr_match_glob_OPTIONAL_ARGC 0
/* apr_match_glob
 *
 * Parameters:
 * - dir_pattern: const char *
 * - result: apr_array_header_t **
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_match_glob(mrb_state* mrb, mrb_value self) {
  mrb_value dir_pattern;
  mrb_value result;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &dir_pattern, &result, &p);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, dir_pattern, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_apr_array_header_t_PTR_PTR(result);
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_dir_pattern = mrb_string_value_cstr(mrb, &dir_pattern);

  apr_array_header_t ** native_result = TODO_mruby_unbox_apr_array_header_t_PTR_PTR(result);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_match_glob(native_dir_pattern, native_result, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_mcast_hops_FUNCTION
#define apr_mcast_hops_REQUIRED_ARGC 2
#define apr_mcast_hops_OPTIONAL_ARGC 0
/* apr_mcast_hops
 *
 * Parameters:
 * - sock: apr_socket_t *
 * - ttl: unsigned char
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_mcast_hops(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value ttl;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sock, &ttl);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  TODO_type_check_unsigned_char(ttl);


  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));

  unsigned char native_ttl = TODO_mruby_unbox_unsigned_char(ttl);

  /* Invocation */
  apr_status_t result = apr_mcast_hops(native_sock, native_ttl);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_mcast_interface_FUNCTION
#define apr_mcast_interface_REQUIRED_ARGC 2
#define apr_mcast_interface_OPTIONAL_ARGC 0
/* apr_mcast_interface
 *
 * Parameters:
 * - sock: apr_socket_t *
 * - iface: apr_sockaddr_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_mcast_interface(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value iface;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sock, &iface);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, iface, AprSockaddrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSockaddrT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));

  apr_sockaddr_t * native_iface = (mrb_nil_p(iface) ? NULL : mruby_unbox_apr_sockaddr_t(iface));

  /* Invocation */
  apr_status_t result = apr_mcast_interface(native_sock, native_iface);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_mcast_join_FUNCTION
#define apr_mcast_join_REQUIRED_ARGC 4
#define apr_mcast_join_OPTIONAL_ARGC 0
/* apr_mcast_join
 *
 * Parameters:
 * - sock: apr_socket_t *
 * - join: apr_sockaddr_t *
 * - iface: apr_sockaddr_t *
 * - source: apr_sockaddr_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_mcast_join(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value join;
  mrb_value iface;
  mrb_value source;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &sock, &join, &iface, &source);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, join, AprSockaddrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSockaddrT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, iface, AprSockaddrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSockaddrT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, source, AprSockaddrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSockaddrT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));

  apr_sockaddr_t * native_join = (mrb_nil_p(join) ? NULL : mruby_unbox_apr_sockaddr_t(join));

  apr_sockaddr_t * native_iface = (mrb_nil_p(iface) ? NULL : mruby_unbox_apr_sockaddr_t(iface));

  apr_sockaddr_t * native_source = (mrb_nil_p(source) ? NULL : mruby_unbox_apr_sockaddr_t(source));

  /* Invocation */
  apr_status_t result = apr_mcast_join(native_sock, native_join, native_iface, native_source);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_mcast_leave_FUNCTION
#define apr_mcast_leave_REQUIRED_ARGC 4
#define apr_mcast_leave_OPTIONAL_ARGC 0
/* apr_mcast_leave
 *
 * Parameters:
 * - sock: apr_socket_t *
 * - addr: apr_sockaddr_t *
 * - iface: apr_sockaddr_t *
 * - source: apr_sockaddr_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_mcast_leave(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value addr;
  mrb_value iface;
  mrb_value source;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &sock, &addr, &iface, &source);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, addr, AprSockaddrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSockaddrT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, iface, AprSockaddrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSockaddrT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, source, AprSockaddrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSockaddrT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));

  apr_sockaddr_t * native_addr = (mrb_nil_p(addr) ? NULL : mruby_unbox_apr_sockaddr_t(addr));

  apr_sockaddr_t * native_iface = (mrb_nil_p(iface) ? NULL : mruby_unbox_apr_sockaddr_t(iface));

  apr_sockaddr_t * native_source = (mrb_nil_p(source) ? NULL : mruby_unbox_apr_sockaddr_t(source));

  /* Invocation */
  apr_status_t result = apr_mcast_leave(native_sock, native_addr, native_iface, native_source);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_mcast_loopback_FUNCTION
#define apr_mcast_loopback_REQUIRED_ARGC 2
#define apr_mcast_loopback_OPTIONAL_ARGC 0
/* apr_mcast_loopback
 *
 * Parameters:
 * - sock: apr_socket_t *
 * - opt: unsigned char
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_mcast_loopback(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value opt;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sock, &opt);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  TODO_type_check_unsigned_char(opt);


  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));

  unsigned char native_opt = TODO_mruby_unbox_unsigned_char(opt);

  /* Invocation */
  apr_status_t result = apr_mcast_loopback(native_sock, native_opt);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_mmap_create_FUNCTION
#define apr_mmap_create_REQUIRED_ARGC 6
#define apr_mmap_create_OPTIONAL_ARGC 0
/* apr_mmap_create
 *
 * Parameters:
 * - newmmap: apr_mmap_t **
 * - file: apr_file_t *
 * - offset: long long
 * - size: int
 * - flag: int
 * - cntxt: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_mmap_create(mrb_state* mrb, mrb_value self) {
  mrb_value newmmap;
  mrb_value file;
  mrb_value offset;
  mrb_value size;
  mrb_value flag;
  mrb_value cntxt;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooo", &newmmap, &file, &offset, &size, &flag, &cntxt);


  /* Type checking */
  TODO_type_check_apr_mmap_t_PTR_PTR(newmmap);
  if (!mrb_obj_is_kind_of(mrb, file, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  TODO_type_check_long_long(offset);
  if (!mrb_obj_is_kind_of(mrb, size, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flag, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, cntxt, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_mmap_t ** native_newmmap = TODO_mruby_unbox_apr_mmap_t_PTR_PTR(newmmap);

  apr_file_t * native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_apr_file_t(file));

  long long native_offset = TODO_mruby_unbox_long_long(offset);

  int native_size = mrb_fixnum(size);

  int native_flag = mrb_fixnum(flag);

  apr_pool_t * native_cntxt = (mrb_nil_p(cntxt) ? NULL : mruby_unbox_apr_pool_t(cntxt));

  /* Invocation */
  apr_status_t result = apr_mmap_create(native_newmmap, native_file, native_offset, native_size, native_flag, native_cntxt);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_mmap_delete_FUNCTION
#define apr_mmap_delete_REQUIRED_ARGC 1
#define apr_mmap_delete_OPTIONAL_ARGC 0
/* apr_mmap_delete
 *
 * Parameters:
 * - mm: apr_mmap_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_mmap_delete(mrb_state* mrb, mrb_value self) {
  mrb_value mm;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &mm);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, mm, AprMmapT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprMmapT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_mmap_t * native_mm = (mrb_nil_p(mm) ? NULL : mruby_unbox_apr_mmap_t(mm));

  /* Invocation */
  apr_status_t result = apr_mmap_delete(native_mm);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_mmap_dup_FUNCTION
#define apr_mmap_dup_REQUIRED_ARGC 3
#define apr_mmap_dup_OPTIONAL_ARGC 0
/* apr_mmap_dup
 *
 * Parameters:
 * - new_mmap: apr_mmap_t **
 * - old_mmap: apr_mmap_t *
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_mmap_dup(mrb_state* mrb, mrb_value self) {
  mrb_value new_mmap;
  mrb_value old_mmap;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &new_mmap, &old_mmap, &p);


  /* Type checking */
  TODO_type_check_apr_mmap_t_PTR_PTR(new_mmap);
  if (!mrb_obj_is_kind_of(mrb, old_mmap, AprMmapT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprMmapT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_mmap_t ** native_new_mmap = TODO_mruby_unbox_apr_mmap_t_PTR_PTR(new_mmap);

  apr_mmap_t * native_old_mmap = (mrb_nil_p(old_mmap) ? NULL : mruby_unbox_apr_mmap_t(old_mmap));

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_mmap_dup(native_new_mmap, native_old_mmap, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_mmap_offset_FUNCTION
#define apr_mmap_offset_REQUIRED_ARGC 3
#define apr_mmap_offset_OPTIONAL_ARGC 0
/* apr_mmap_offset
 *
 * Parameters:
 * - addr: void **
 * - mm: apr_mmap_t *
 * - offset: long long
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_mmap_offset(mrb_state* mrb, mrb_value self) {
  mrb_value addr;
  mrb_value mm;
  mrb_value offset;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &addr, &mm, &offset);


  /* Type checking */
  TODO_type_check_void_PTR_PTR(addr);
  if (!mrb_obj_is_kind_of(mrb, mm, AprMmapT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprMmapT expected");
    return mrb_nil_value();
  }
  TODO_type_check_long_long(offset);


  /* Unbox parameters */
  void ** native_addr = TODO_mruby_unbox_void_PTR_PTR(addr);

  apr_mmap_t * native_mm = (mrb_nil_p(mm) ? NULL : mruby_unbox_apr_mmap_t(mm));

  long long native_offset = TODO_mruby_unbox_long_long(offset);

  /* Invocation */
  apr_status_t result = apr_mmap_offset(native_addr, native_mm, native_offset);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_off_t_toa_FUNCTION
#define apr_off_t_toa_REQUIRED_ARGC 2
#define apr_off_t_toa_OPTIONAL_ARGC 0
/* apr_off_t_toa
 *
 * Parameters:
 * - p: apr_pool_t *
 * - n: long long
 * Return Type: char *
 */
mrb_value
mrb_APR_apr_off_t_toa(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value n;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &p, &n);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  TODO_type_check_long_long(n);


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  long long native_n = TODO_mruby_unbox_long_long(n);

  /* Invocation */
  char * result = apr_off_t_toa(native_p, native_n);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_os_default_encoding_FUNCTION
#define apr_os_default_encoding_REQUIRED_ARGC 1
#define apr_os_default_encoding_OPTIONAL_ARGC 0
/* apr_os_default_encoding
 *
 * Parameters:
 * - pool: apr_pool_t *
 * Return Type: const char *
 */
mrb_value
mrb_APR_apr_os_default_encoding(mrb_state* mrb, mrb_value self) {
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &pool);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  const char * result = apr_os_default_encoding(native_pool);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_os_dir_get_FUNCTION
#define apr_os_dir_get_REQUIRED_ARGC 2
#define apr_os_dir_get_OPTIONAL_ARGC 0
/* apr_os_dir_get
 *
 * Parameters:
 * - thedir: void ***
 * - dir: apr_dir_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_dir_get(mrb_state* mrb, mrb_value self) {
  mrb_value thedir;
  mrb_value dir;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &thedir, &dir);


  /* Type checking */
  TODO_type_check_void_PTR_PTR_PTR(thedir);
  if (!mrb_obj_is_kind_of(mrb, dir, AprDirT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprDirT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void *** native_thedir = TODO_mruby_unbox_void_PTR_PTR_PTR(thedir);

  apr_dir_t * native_dir = (mrb_nil_p(dir) ? NULL : mruby_unbox_apr_dir_t(dir));

  /* Invocation */
  apr_status_t result = apr_os_dir_get(native_thedir, native_dir);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_dir_put_FUNCTION
#define apr_os_dir_put_REQUIRED_ARGC 3
#define apr_os_dir_put_OPTIONAL_ARGC 0
/* apr_os_dir_put
 *
 * Parameters:
 * - dir: apr_dir_t **
 * - thedir: void **
 * - cont: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_dir_put(mrb_state* mrb, mrb_value self) {
  mrb_value dir;
  mrb_value thedir;
  mrb_value cont;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &dir, &thedir, &cont);


  /* Type checking */
  TODO_type_check_apr_dir_t_PTR_PTR(dir);
  TODO_type_check_void_PTR_PTR(thedir);
  if (!mrb_obj_is_kind_of(mrb, cont, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_dir_t ** native_dir = TODO_mruby_unbox_apr_dir_t_PTR_PTR(dir);

  void ** native_thedir = TODO_mruby_unbox_void_PTR_PTR(thedir);

  apr_pool_t * native_cont = (mrb_nil_p(cont) ? NULL : mruby_unbox_apr_pool_t(cont));

  /* Invocation */
  apr_status_t result = apr_os_dir_put(native_dir, native_thedir, native_cont);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_dso_handle_get_FUNCTION
#define apr_os_dso_handle_get_REQUIRED_ARGC 2
#define apr_os_dso_handle_get_OPTIONAL_ARGC 0
/* apr_os_dso_handle_get
 *
 * Parameters:
 * - dso: void **
 * - aprdso: apr_dso_handle_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_dso_handle_get(mrb_state* mrb, mrb_value self) {
  mrb_value dso;
  mrb_value aprdso;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &dso, &aprdso);


  /* Type checking */
  TODO_type_check_void_PTR_PTR(dso);
  if (!mrb_obj_is_kind_of(mrb, aprdso, AprDsoHandleT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprDsoHandleT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void ** native_dso = TODO_mruby_unbox_void_PTR_PTR(dso);

  apr_dso_handle_t * native_aprdso = (mrb_nil_p(aprdso) ? NULL : mruby_unbox_apr_dso_handle_t(aprdso));

  /* Invocation */
  apr_status_t result = apr_os_dso_handle_get(native_dso, native_aprdso);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_dso_handle_put_FUNCTION
#define apr_os_dso_handle_put_REQUIRED_ARGC 3
#define apr_os_dso_handle_put_OPTIONAL_ARGC 0
/* apr_os_dso_handle_put
 *
 * Parameters:
 * - dso: apr_dso_handle_t **
 * - thedso: void *
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_dso_handle_put(mrb_state* mrb, mrb_value self) {
  mrb_value dso;
  mrb_value thedso;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &dso, &thedso, &pool);


  /* Type checking */
  TODO_type_check_apr_dso_handle_t_PTR_PTR(dso);
  TODO_type_check_void_PTR(thedso);
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_dso_handle_t ** native_dso = TODO_mruby_unbox_apr_dso_handle_t_PTR_PTR(dso);

  void * native_thedso = TODO_mruby_unbox_void_PTR(thedso);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_os_dso_handle_put(native_dso, native_thedso, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_exp_time_get_FUNCTION
#define apr_os_exp_time_get_REQUIRED_ARGC 2
#define apr_os_exp_time_get_OPTIONAL_ARGC 0
/* apr_os_exp_time_get
 *
 * Parameters:
 * - ostime: _SYSTEMTIME **
 * - aprtime: apr_time_exp_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_exp_time_get(mrb_state* mrb, mrb_value self) {
  mrb_value ostime;
  mrb_value aprtime;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &ostime, &aprtime);


  /* Type checking */
  TODO_type_check__SYSTEMTIME_PTR_PTR(ostime);
  if (!mrb_obj_is_kind_of(mrb, aprtime, AprTimeExpT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTimeExpT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  _SYSTEMTIME ** native_ostime = TODO_mruby_unbox__SYSTEMTIME_PTR_PTR(ostime);

  apr_time_exp_t * native_aprtime = (mrb_nil_p(aprtime) ? NULL : mruby_unbox_apr_time_exp_t(aprtime));

  /* Invocation */
  apr_status_t result = apr_os_exp_time_get(native_ostime, native_aprtime);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_exp_time_put_FUNCTION
#define apr_os_exp_time_put_REQUIRED_ARGC 3
#define apr_os_exp_time_put_OPTIONAL_ARGC 0
/* apr_os_exp_time_put
 *
 * Parameters:
 * - aprtime: apr_time_exp_t *
 * - ostime: _SYSTEMTIME **
 * - cont: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_exp_time_put(mrb_state* mrb, mrb_value self) {
  mrb_value aprtime;
  mrb_value ostime;
  mrb_value cont;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &aprtime, &ostime, &cont);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, aprtime, AprTimeExpT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTimeExpT expected");
    return mrb_nil_value();
  }
  TODO_type_check__SYSTEMTIME_PTR_PTR(ostime);
  if (!mrb_obj_is_kind_of(mrb, cont, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_time_exp_t * native_aprtime = (mrb_nil_p(aprtime) ? NULL : mruby_unbox_apr_time_exp_t(aprtime));

  _SYSTEMTIME ** native_ostime = TODO_mruby_unbox__SYSTEMTIME_PTR_PTR(ostime);

  apr_pool_t * native_cont = (mrb_nil_p(cont) ? NULL : mruby_unbox_apr_pool_t(cont));

  /* Invocation */
  apr_status_t result = apr_os_exp_time_put(native_aprtime, native_ostime, native_cont);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_file_get_FUNCTION
#define apr_os_file_get_REQUIRED_ARGC 2
#define apr_os_file_get_OPTIONAL_ARGC 0
/* apr_os_file_get
 *
 * Parameters:
 * - thefile: void **
 * - file: apr_file_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_file_get(mrb_state* mrb, mrb_value self) {
  mrb_value thefile;
  mrb_value file;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &thefile, &file);


  /* Type checking */
  TODO_type_check_void_PTR_PTR(thefile);
  if (!mrb_obj_is_kind_of(mrb, file, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void ** native_thefile = TODO_mruby_unbox_void_PTR_PTR(thefile);

  apr_file_t * native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_apr_file_t(file));

  /* Invocation */
  apr_status_t result = apr_os_file_get(native_thefile, native_file);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_file_put_FUNCTION
#define apr_os_file_put_REQUIRED_ARGC 4
#define apr_os_file_put_OPTIONAL_ARGC 0
/* apr_os_file_put
 *
 * Parameters:
 * - file: apr_file_t **
 * - thefile: void **
 * - flags: int
 * - cont: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_file_put(mrb_state* mrb, mrb_value self) {
  mrb_value file;
  mrb_value thefile;
  mrb_value flags;
  mrb_value cont;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &file, &thefile, &flags, &cont);


  /* Type checking */
  TODO_type_check_apr_file_t_PTR_PTR(file);
  TODO_type_check_void_PTR_PTR(thefile);
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, cont, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_file_t ** native_file = TODO_mruby_unbox_apr_file_t_PTR_PTR(file);

  void ** native_thefile = TODO_mruby_unbox_void_PTR_PTR(thefile);

  int native_flags = mrb_fixnum(flags);

  apr_pool_t * native_cont = (mrb_nil_p(cont) ? NULL : mruby_unbox_apr_pool_t(cont));

  /* Invocation */
  apr_status_t result = apr_os_file_put(native_file, native_thefile, native_flags, native_cont);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_imp_time_get_FUNCTION
#define apr_os_imp_time_get_REQUIRED_ARGC 2
#define apr_os_imp_time_get_OPTIONAL_ARGC 0
/* apr_os_imp_time_get
 *
 * Parameters:
 * - ostime: _FILETIME **
 * - aprtime: long long *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_imp_time_get(mrb_state* mrb, mrb_value self) {
  mrb_value ostime;
  mrb_value aprtime;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &ostime, &aprtime);


  /* Type checking */
  TODO_type_check__FILETIME_PTR_PTR(ostime);
  TODO_type_check_long_long_PTR(aprtime);


  /* Unbox parameters */
  _FILETIME ** native_ostime = TODO_mruby_unbox__FILETIME_PTR_PTR(ostime);

  long long * native_aprtime = TODO_mruby_unbox_long_long_PTR(aprtime);

  /* Invocation */
  apr_status_t result = apr_os_imp_time_get(native_ostime, native_aprtime);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_imp_time_put_FUNCTION
#define apr_os_imp_time_put_REQUIRED_ARGC 3
#define apr_os_imp_time_put_OPTIONAL_ARGC 0
/* apr_os_imp_time_put
 *
 * Parameters:
 * - aprtime: long long *
 * - ostime: _FILETIME **
 * - cont: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_imp_time_put(mrb_state* mrb, mrb_value self) {
  mrb_value aprtime;
  mrb_value ostime;
  mrb_value cont;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &aprtime, &ostime, &cont);


  /* Type checking */
  TODO_type_check_long_long_PTR(aprtime);
  TODO_type_check__FILETIME_PTR_PTR(ostime);
  if (!mrb_obj_is_kind_of(mrb, cont, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  long long * native_aprtime = TODO_mruby_unbox_long_long_PTR(aprtime);

  _FILETIME ** native_ostime = TODO_mruby_unbox__FILETIME_PTR_PTR(ostime);

  apr_pool_t * native_cont = (mrb_nil_p(cont) ? NULL : mruby_unbox_apr_pool_t(cont));

  /* Invocation */
  apr_status_t result = apr_os_imp_time_put(native_aprtime, native_ostime, native_cont);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_locale_encoding_FUNCTION
#define apr_os_locale_encoding_REQUIRED_ARGC 1
#define apr_os_locale_encoding_OPTIONAL_ARGC 0
/* apr_os_locale_encoding
 *
 * Parameters:
 * - pool: apr_pool_t *
 * Return Type: const char *
 */
mrb_value
mrb_APR_apr_os_locale_encoding(mrb_state* mrb, mrb_value self) {
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &pool);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  const char * result = apr_os_locale_encoding(native_pool);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_os_pipe_put_FUNCTION
#define apr_os_pipe_put_REQUIRED_ARGC 3
#define apr_os_pipe_put_OPTIONAL_ARGC 0
/* apr_os_pipe_put
 *
 * Parameters:
 * - file: apr_file_t **
 * - thefile: void **
 * - cont: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_pipe_put(mrb_state* mrb, mrb_value self) {
  mrb_value file;
  mrb_value thefile;
  mrb_value cont;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &file, &thefile, &cont);


  /* Type checking */
  TODO_type_check_apr_file_t_PTR_PTR(file);
  TODO_type_check_void_PTR_PTR(thefile);
  if (!mrb_obj_is_kind_of(mrb, cont, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_file_t ** native_file = TODO_mruby_unbox_apr_file_t_PTR_PTR(file);

  void ** native_thefile = TODO_mruby_unbox_void_PTR_PTR(thefile);

  apr_pool_t * native_cont = (mrb_nil_p(cont) ? NULL : mruby_unbox_apr_pool_t(cont));

  /* Invocation */
  apr_status_t result = apr_os_pipe_put(native_file, native_thefile, native_cont);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_pipe_put_ex_FUNCTION
#define apr_os_pipe_put_ex_REQUIRED_ARGC 4
#define apr_os_pipe_put_ex_OPTIONAL_ARGC 0
/* apr_os_pipe_put_ex
 *
 * Parameters:
 * - file: apr_file_t **
 * - thefile: void **
 * - register_cleanup: int
 * - cont: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_pipe_put_ex(mrb_state* mrb, mrb_value self) {
  mrb_value file;
  mrb_value thefile;
  mrb_value register_cleanup;
  mrb_value cont;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &file, &thefile, &register_cleanup, &cont);


  /* Type checking */
  TODO_type_check_apr_file_t_PTR_PTR(file);
  TODO_type_check_void_PTR_PTR(thefile);
  if (!mrb_obj_is_kind_of(mrb, register_cleanup, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, cont, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_file_t ** native_file = TODO_mruby_unbox_apr_file_t_PTR_PTR(file);

  void ** native_thefile = TODO_mruby_unbox_void_PTR_PTR(thefile);

  int native_register_cleanup = mrb_fixnum(register_cleanup);

  apr_pool_t * native_cont = (mrb_nil_p(cont) ? NULL : mruby_unbox_apr_pool_t(cont));

  /* Invocation */
  apr_status_t result = apr_os_pipe_put_ex(native_file, native_thefile, native_register_cleanup, native_cont);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_proc_mutex_get_FUNCTION
#define apr_os_proc_mutex_get_REQUIRED_ARGC 2
#define apr_os_proc_mutex_get_OPTIONAL_ARGC 0
/* apr_os_proc_mutex_get
 *
 * Parameters:
 * - ospmutex: void **
 * - pmutex: apr_proc_mutex_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_proc_mutex_get(mrb_state* mrb, mrb_value self) {
  mrb_value ospmutex;
  mrb_value pmutex;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &ospmutex, &pmutex);


  /* Type checking */
  TODO_type_check_void_PTR_PTR(ospmutex);
  if (!mrb_obj_is_kind_of(mrb, pmutex, AprProcMutexT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcMutexT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void ** native_ospmutex = TODO_mruby_unbox_void_PTR_PTR(ospmutex);

  apr_proc_mutex_t * native_pmutex = (mrb_nil_p(pmutex) ? NULL : mruby_unbox_apr_proc_mutex_t(pmutex));

  /* Invocation */
  apr_status_t result = apr_os_proc_mutex_get(native_ospmutex, native_pmutex);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_proc_mutex_put_FUNCTION
#define apr_os_proc_mutex_put_REQUIRED_ARGC 3
#define apr_os_proc_mutex_put_OPTIONAL_ARGC 0
/* apr_os_proc_mutex_put
 *
 * Parameters:
 * - pmutex: apr_proc_mutex_t **
 * - ospmutex: void **
 * - cont: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_proc_mutex_put(mrb_state* mrb, mrb_value self) {
  mrb_value pmutex;
  mrb_value ospmutex;
  mrb_value cont;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &pmutex, &ospmutex, &cont);


  /* Type checking */
  TODO_type_check_apr_proc_mutex_t_PTR_PTR(pmutex);
  TODO_type_check_void_PTR_PTR(ospmutex);
  if (!mrb_obj_is_kind_of(mrb, cont, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_proc_mutex_t ** native_pmutex = TODO_mruby_unbox_apr_proc_mutex_t_PTR_PTR(pmutex);

  void ** native_ospmutex = TODO_mruby_unbox_void_PTR_PTR(ospmutex);

  apr_pool_t * native_cont = (mrb_nil_p(cont) ? NULL : mruby_unbox_apr_pool_t(cont));

  /* Invocation */
  apr_status_t result = apr_os_proc_mutex_put(native_pmutex, native_ospmutex, native_cont);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_shm_get_FUNCTION
#define apr_os_shm_get_REQUIRED_ARGC 2
#define apr_os_shm_get_OPTIONAL_ARGC 0
/* apr_os_shm_get
 *
 * Parameters:
 * - osshm: void **
 * - shm: apr_shm_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_shm_get(mrb_state* mrb, mrb_value self) {
  mrb_value osshm;
  mrb_value shm;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &osshm, &shm);


  /* Type checking */
  TODO_type_check_void_PTR_PTR(osshm);
  if (!mrb_obj_is_kind_of(mrb, shm, AprShmT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprShmT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void ** native_osshm = TODO_mruby_unbox_void_PTR_PTR(osshm);

  apr_shm_t * native_shm = (mrb_nil_p(shm) ? NULL : mruby_unbox_apr_shm_t(shm));

  /* Invocation */
  apr_status_t result = apr_os_shm_get(native_osshm, native_shm);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_shm_put_FUNCTION
#define apr_os_shm_put_REQUIRED_ARGC 3
#define apr_os_shm_put_OPTIONAL_ARGC 0
/* apr_os_shm_put
 *
 * Parameters:
 * - shm: apr_shm_t **
 * - osshm: void **
 * - cont: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_shm_put(mrb_state* mrb, mrb_value self) {
  mrb_value shm;
  mrb_value osshm;
  mrb_value cont;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &shm, &osshm, &cont);


  /* Type checking */
  TODO_type_check_apr_shm_t_PTR_PTR(shm);
  TODO_type_check_void_PTR_PTR(osshm);
  if (!mrb_obj_is_kind_of(mrb, cont, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_shm_t ** native_shm = TODO_mruby_unbox_apr_shm_t_PTR_PTR(shm);

  void ** native_osshm = TODO_mruby_unbox_void_PTR_PTR(osshm);

  apr_pool_t * native_cont = (mrb_nil_p(cont) ? NULL : mruby_unbox_apr_pool_t(cont));

  /* Invocation */
  apr_status_t result = apr_os_shm_put(native_shm, native_osshm, native_cont);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_sock_get_FUNCTION
#define apr_os_sock_get_REQUIRED_ARGC 2
#define apr_os_sock_get_OPTIONAL_ARGC 0
/* apr_os_sock_get
 *
 * Parameters:
 * - thesock: unsigned int *
 * - sock: apr_socket_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_sock_get(mrb_state* mrb, mrb_value self) {
  mrb_value thesock;
  mrb_value sock;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &thesock, &sock);


  /* Type checking */
  TODO_type_check_unsigned_int_PTR(thesock);
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  unsigned int * native_thesock = TODO_mruby_unbox_unsigned_int_PTR(thesock);

  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));

  /* Invocation */
  apr_status_t result = apr_os_sock_get(native_thesock, native_sock);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_sock_make_FUNCTION
#define apr_os_sock_make_REQUIRED_ARGC 3
#define apr_os_sock_make_OPTIONAL_ARGC 0
/* apr_os_sock_make
 *
 * Parameters:
 * - apr_sock: apr_socket_t **
 * - os_sock_info: apr_os_sock_info_t *
 * - cont: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_sock_make(mrb_state* mrb, mrb_value self) {
  mrb_value apr_sock;
  mrb_value os_sock_info;
  mrb_value cont;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &apr_sock, &os_sock_info, &cont);


  /* Type checking */
  TODO_type_check_apr_socket_t_PTR_PTR(apr_sock);
  if (!mrb_obj_is_kind_of(mrb, os_sock_info, AprOsSockInfoT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprOsSockInfoT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, cont, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_socket_t ** native_apr_sock = TODO_mruby_unbox_apr_socket_t_PTR_PTR(apr_sock);

  apr_os_sock_info_t * native_os_sock_info = (mrb_nil_p(os_sock_info) ? NULL : mruby_unbox_apr_os_sock_info_t(os_sock_info));

  apr_pool_t * native_cont = (mrb_nil_p(cont) ? NULL : mruby_unbox_apr_pool_t(cont));

  /* Invocation */
  apr_status_t result = apr_os_sock_make(native_apr_sock, native_os_sock_info, native_cont);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_sock_put_FUNCTION
#define apr_os_sock_put_REQUIRED_ARGC 3
#define apr_os_sock_put_OPTIONAL_ARGC 0
/* apr_os_sock_put
 *
 * Parameters:
 * - sock: apr_socket_t **
 * - thesock: unsigned int *
 * - cont: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_sock_put(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value thesock;
  mrb_value cont;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &sock, &thesock, &cont);


  /* Type checking */
  TODO_type_check_apr_socket_t_PTR_PTR(sock);
  TODO_type_check_unsigned_int_PTR(thesock);
  if (!mrb_obj_is_kind_of(mrb, cont, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_socket_t ** native_sock = TODO_mruby_unbox_apr_socket_t_PTR_PTR(sock);

  unsigned int * native_thesock = TODO_mruby_unbox_unsigned_int_PTR(thesock);

  apr_pool_t * native_cont = (mrb_nil_p(cont) ? NULL : mruby_unbox_apr_pool_t(cont));

  /* Invocation */
  apr_status_t result = apr_os_sock_put(native_sock, native_thesock, native_cont);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_thread_current_FUNCTION
#define apr_os_thread_current_REQUIRED_ARGC 0
#define apr_os_thread_current_OPTIONAL_ARGC 0
/* apr_os_thread_current
 *
 * Parameters: None
 * Return Type: apr_os_thread_t
 */
mrb_value
mrb_APR_apr_os_thread_current(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  apr_os_thread_t result = apr_os_thread_current();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_HANDLE(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_os_thread_equal_FUNCTION
#define apr_os_thread_equal_REQUIRED_ARGC 2
#define apr_os_thread_equal_OPTIONAL_ARGC 0
/* apr_os_thread_equal
 *
 * Parameters:
 * - tid1: void *
 * - tid2: void *
 * Return Type: int
 */
mrb_value
mrb_APR_apr_os_thread_equal(mrb_state* mrb, mrb_value self) {
  mrb_value tid1;
  mrb_value tid2;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &tid1, &tid2);


  /* Type checking */
  TODO_type_check_void_PTR(tid1);
  TODO_type_check_void_PTR(tid2);


  /* Unbox parameters */
  void * native_tid1 = TODO_mruby_unbox_void_PTR(tid1);

  void * native_tid2 = TODO_mruby_unbox_void_PTR(tid2);

  /* Invocation */
  int result = apr_os_thread_equal(native_tid1, native_tid2);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_thread_get_FUNCTION
#define apr_os_thread_get_REQUIRED_ARGC 2
#define apr_os_thread_get_OPTIONAL_ARGC 0
/* apr_os_thread_get
 *
 * Parameters:
 * - thethd: void ***
 * - thd: apr_thread_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_thread_get(mrb_state* mrb, mrb_value self) {
  mrb_value thethd;
  mrb_value thd;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &thethd, &thd);


  /* Type checking */
  TODO_type_check_void_PTR_PTR_PTR(thethd);
  if (!mrb_obj_is_kind_of(mrb, thd, AprThreadT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void *** native_thethd = TODO_mruby_unbox_void_PTR_PTR_PTR(thethd);

  apr_thread_t * native_thd = (mrb_nil_p(thd) ? NULL : mruby_unbox_apr_thread_t(thd));

  /* Invocation */
  apr_status_t result = apr_os_thread_get(native_thethd, native_thd);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_thread_put_FUNCTION
#define apr_os_thread_put_REQUIRED_ARGC 3
#define apr_os_thread_put_OPTIONAL_ARGC 0
/* apr_os_thread_put
 *
 * Parameters:
 * - thd: apr_thread_t **
 * - thethd: void **
 * - cont: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_thread_put(mrb_state* mrb, mrb_value self) {
  mrb_value thd;
  mrb_value thethd;
  mrb_value cont;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &thd, &thethd, &cont);


  /* Type checking */
  TODO_type_check_apr_thread_t_PTR_PTR(thd);
  TODO_type_check_void_PTR_PTR(thethd);
  if (!mrb_obj_is_kind_of(mrb, cont, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_thread_t ** native_thd = TODO_mruby_unbox_apr_thread_t_PTR_PTR(thd);

  void ** native_thethd = TODO_mruby_unbox_void_PTR_PTR(thethd);

  apr_pool_t * native_cont = (mrb_nil_p(cont) ? NULL : mruby_unbox_apr_pool_t(cont));

  /* Invocation */
  apr_status_t result = apr_os_thread_put(native_thd, native_thethd, native_cont);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_threadkey_get_FUNCTION
#define apr_os_threadkey_get_REQUIRED_ARGC 2
#define apr_os_threadkey_get_OPTIONAL_ARGC 0
/* apr_os_threadkey_get
 *
 * Parameters:
 * - thekey: unsigned long *
 * - key: apr_threadkey_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_threadkey_get(mrb_state* mrb, mrb_value self) {
  mrb_value thekey;
  mrb_value key;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &thekey, &key);


  /* Type checking */
  TODO_type_check_unsigned_long_PTR(thekey);
  if (!mrb_obj_is_kind_of(mrb, key, AprThreadkeyT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadkeyT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  unsigned long * native_thekey = TODO_mruby_unbox_unsigned_long_PTR(thekey);

  apr_threadkey_t * native_key = (mrb_nil_p(key) ? NULL : mruby_unbox_apr_threadkey_t(key));

  /* Invocation */
  apr_status_t result = apr_os_threadkey_get(native_thekey, native_key);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_threadkey_put_FUNCTION
#define apr_os_threadkey_put_REQUIRED_ARGC 3
#define apr_os_threadkey_put_OPTIONAL_ARGC 0
/* apr_os_threadkey_put
 *
 * Parameters:
 * - key: apr_threadkey_t **
 * - thekey: unsigned long *
 * - cont: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_threadkey_put(mrb_state* mrb, mrb_value self) {
  mrb_value key;
  mrb_value thekey;
  mrb_value cont;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &key, &thekey, &cont);


  /* Type checking */
  TODO_type_check_apr_threadkey_t_PTR_PTR(key);
  TODO_type_check_unsigned_long_PTR(thekey);
  if (!mrb_obj_is_kind_of(mrb, cont, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_threadkey_t ** native_key = TODO_mruby_unbox_apr_threadkey_t_PTR_PTR(key);

  unsigned long * native_thekey = TODO_mruby_unbox_unsigned_long_PTR(thekey);

  apr_pool_t * native_cont = (mrb_nil_p(cont) ? NULL : mruby_unbox_apr_pool_t(cont));

  /* Invocation */
  apr_status_t result = apr_os_threadkey_put(native_key, native_thekey, native_cont);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_os_uuid_get_FUNCTION
#define apr_os_uuid_get_REQUIRED_ARGC 1
#define apr_os_uuid_get_OPTIONAL_ARGC 0
/* apr_os_uuid_get
 *
 * Parameters:
 * - uuid_data: unsigned char *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_os_uuid_get(mrb_state* mrb, mrb_value self) {
  mrb_value uuid_data;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &uuid_data);


  /* Type checking */
  TODO_type_check_unsigned_char_PTR(uuid_data);


  /* Unbox parameters */
  unsigned char * native_uuid_data = TODO_mruby_unbox_unsigned_char_PTR(uuid_data);

  /* Invocation */
  apr_status_t result = apr_os_uuid_get(native_uuid_data);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_palloc_FUNCTION
#define apr_palloc_REQUIRED_ARGC 2
#define apr_palloc_OPTIONAL_ARGC 0
/* apr_palloc
 *
 * Parameters:
 * - p: apr_pool_t *
 * - size: int
 * Return Type: void *
 */
mrb_value
mrb_APR_apr_palloc(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value size;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &p, &size);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, size, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  int native_size = mrb_fixnum(size);

  /* Invocation */
  void * result = apr_palloc(native_p, native_size);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_palloc_debug_FUNCTION
#define apr_palloc_debug_REQUIRED_ARGC 3
#define apr_palloc_debug_OPTIONAL_ARGC 0
/* apr_palloc_debug
 *
 * Parameters:
 * - p: apr_pool_t *
 * - size: int
 * - file_line: const char *
 * Return Type: void *
 */
mrb_value
mrb_APR_apr_palloc_debug(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value size;
  mrb_value file_line;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &p, &size, &file_line);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, size, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, file_line, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  int native_size = mrb_fixnum(size);

  const char * native_file_line = mrb_string_value_cstr(mrb, &file_line);

  /* Invocation */
  void * result = apr_palloc_debug(native_p, native_size, native_file_line);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_parse_addr_port_FUNCTION
#define apr_parse_addr_port_REQUIRED_ARGC 5
#define apr_parse_addr_port_OPTIONAL_ARGC 0
/* apr_parse_addr_port
 *
 * Parameters:
 * - addr: char **
 * - scope_id: char **
 * - port: unsigned short *
 * - str: const char *
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_parse_addr_port(mrb_state* mrb, mrb_value self) {
  mrb_value addr;
  mrb_value scope_id;
  mrb_value port;
  mrb_value str;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &addr, &scope_id, &port, &str, &p);


  /* Type checking */
  TODO_type_check_char_PTR_PTR(addr);
  TODO_type_check_char_PTR_PTR(scope_id);
  TODO_type_check_unsigned_short_PTR(port);
  if (!mrb_obj_is_kind_of(mrb, str, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  char ** native_addr = TODO_mruby_unbox_char_PTR_PTR(addr);

  char ** native_scope_id = TODO_mruby_unbox_char_PTR_PTR(scope_id);

  unsigned short * native_port = TODO_mruby_unbox_unsigned_short_PTR(port);

  const char * native_str = mrb_string_value_cstr(mrb, &str);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_parse_addr_port(native_addr, native_scope_id, native_port, native_str, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_password_get_FUNCTION
#define apr_password_get_REQUIRED_ARGC 3
#define apr_password_get_OPTIONAL_ARGC 0
/* apr_password_get
 *
 * Parameters:
 * - prompt: const char *
 * - pwbuf: char *
 * - bufsize: int *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_password_get(mrb_state* mrb, mrb_value self) {
  mrb_value prompt;
  mrb_value pwbuf;
  mrb_value bufsize;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &prompt, &pwbuf, &bufsize);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, prompt, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pwbuf, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(bufsize);


  /* Unbox parameters */
  const char * native_prompt = mrb_string_value_cstr(mrb, &prompt);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_pwbuf = strdup(mrb_string_value_cstr(mrb, &pwbuf));

  int * native_bufsize = TODO_mruby_unbox_int_PTR(bufsize);

  /* Invocation */
  apr_status_t result = apr_password_get(native_prompt, native_pwbuf, native_bufsize);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_pwbuf);
  native_pwbuf = NULL;

  return return_value;
}
#endif

#if BIND_apr_pcalloc_debug_FUNCTION
#define apr_pcalloc_debug_REQUIRED_ARGC 3
#define apr_pcalloc_debug_OPTIONAL_ARGC 0
/* apr_pcalloc_debug
 *
 * Parameters:
 * - p: apr_pool_t *
 * - size: int
 * - file_line: const char *
 * Return Type: void *
 */
mrb_value
mrb_APR_apr_pcalloc_debug(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value size;
  mrb_value file_line;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &p, &size, &file_line);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, size, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, file_line, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  int native_size = mrb_fixnum(size);

  const char * native_file_line = mrb_string_value_cstr(mrb, &file_line);

  /* Invocation */
  void * result = apr_pcalloc_debug(native_p, native_size, native_file_line);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_pescape_echo_FUNCTION
#define apr_pescape_echo_REQUIRED_ARGC 3
#define apr_pescape_echo_OPTIONAL_ARGC 0
/* apr_pescape_echo
 *
 * Parameters:
 * - p: apr_pool_t *
 * - str: const char *
 * - quote: int
 * Return Type: const char *
 */
mrb_value
mrb_APR_apr_pescape_echo(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value str;
  mrb_value quote;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &p, &str, &quote);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, str, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, quote, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const char * native_str = mrb_string_value_cstr(mrb, &str);

  int native_quote = mrb_fixnum(quote);

  /* Invocation */
  const char * result = apr_pescape_echo(native_p, native_str, native_quote);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_pescape_entity_FUNCTION
#define apr_pescape_entity_REQUIRED_ARGC 3
#define apr_pescape_entity_OPTIONAL_ARGC 0
/* apr_pescape_entity
 *
 * Parameters:
 * - p: apr_pool_t *
 * - str: const char *
 * - toasc: int
 * Return Type: const char *
 */
mrb_value
mrb_APR_apr_pescape_entity(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value str;
  mrb_value toasc;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &p, &str, &toasc);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, str, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, toasc, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const char * native_str = mrb_string_value_cstr(mrb, &str);

  int native_toasc = mrb_fixnum(toasc);

  /* Invocation */
  const char * result = apr_pescape_entity(native_p, native_str, native_toasc);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_pescape_hex_FUNCTION
#define apr_pescape_hex_REQUIRED_ARGC 4
#define apr_pescape_hex_OPTIONAL_ARGC 0
/* apr_pescape_hex
 *
 * Parameters:
 * - p: apr_pool_t *
 * - src: const void *
 * - slen: int
 * - colon: int
 * Return Type: const char *
 */
mrb_value
mrb_APR_apr_pescape_hex(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value src;
  mrb_value slen;
  mrb_value colon;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &p, &src, &slen, &colon);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_void_PTR(src);
  if (!mrb_obj_is_kind_of(mrb, slen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, colon, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const void * native_src = TODO_mruby_unbox_const_void_PTR(src);

  int native_slen = mrb_fixnum(slen);

  int native_colon = mrb_fixnum(colon);

  /* Invocation */
  const char * result = apr_pescape_hex(native_p, native_src, native_slen, native_colon);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_pescape_path_FUNCTION
#define apr_pescape_path_REQUIRED_ARGC 3
#define apr_pescape_path_OPTIONAL_ARGC 0
/* apr_pescape_path
 *
 * Parameters:
 * - p: apr_pool_t *
 * - str: const char *
 * - partial: int
 * Return Type: const char *
 */
mrb_value
mrb_APR_apr_pescape_path(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value str;
  mrb_value partial;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &p, &str, &partial);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, str, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, partial, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const char * native_str = mrb_string_value_cstr(mrb, &str);

  int native_partial = mrb_fixnum(partial);

  /* Invocation */
  const char * result = apr_pescape_path(native_p, native_str, native_partial);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_pescape_path_segment_FUNCTION
#define apr_pescape_path_segment_REQUIRED_ARGC 2
#define apr_pescape_path_segment_OPTIONAL_ARGC 0
/* apr_pescape_path_segment
 *
 * Parameters:
 * - p: apr_pool_t *
 * - str: const char *
 * Return Type: const char *
 */
mrb_value
mrb_APR_apr_pescape_path_segment(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value str;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &p, &str);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, str, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const char * native_str = mrb_string_value_cstr(mrb, &str);

  /* Invocation */
  const char * result = apr_pescape_path_segment(native_p, native_str);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_pescape_shell_FUNCTION
#define apr_pescape_shell_REQUIRED_ARGC 2
#define apr_pescape_shell_OPTIONAL_ARGC 0
/* apr_pescape_shell
 *
 * Parameters:
 * - p: apr_pool_t *
 * - str: const char *
 * Return Type: const char *
 */
mrb_value
mrb_APR_apr_pescape_shell(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value str;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &p, &str);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, str, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const char * native_str = mrb_string_value_cstr(mrb, &str);

  /* Invocation */
  const char * result = apr_pescape_shell(native_p, native_str);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_pescape_urlencoded_FUNCTION
#define apr_pescape_urlencoded_REQUIRED_ARGC 2
#define apr_pescape_urlencoded_OPTIONAL_ARGC 0
/* apr_pescape_urlencoded
 *
 * Parameters:
 * - p: apr_pool_t *
 * - str: const char *
 * Return Type: const char *
 */
mrb_value
mrb_APR_apr_pescape_urlencoded(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value str;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &p, &str);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, str, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const char * native_str = mrb_string_value_cstr(mrb, &str);

  /* Invocation */
  const char * result = apr_pescape_urlencoded(native_p, native_str);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_pmemdup_FUNCTION
#define apr_pmemdup_REQUIRED_ARGC 3
#define apr_pmemdup_OPTIONAL_ARGC 0
/* apr_pmemdup
 *
 * Parameters:
 * - p: apr_pool_t *
 * - m: const void *
 * - n: int
 * Return Type: void *
 */
mrb_value
mrb_APR_apr_pmemdup(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value m;
  mrb_value n;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &p, &m, &n);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_void_PTR(m);
  if (!mrb_obj_is_kind_of(mrb, n, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const void * native_m = TODO_mruby_unbox_const_void_PTR(m);

  int native_n = mrb_fixnum(n);

  /* Invocation */
  void * result = apr_pmemdup(native_p, native_m, native_n);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_poll_FUNCTION
#define apr_poll_REQUIRED_ARGC 4
#define apr_poll_OPTIONAL_ARGC 0
/* apr_poll
 *
 * Parameters:
 * - aprset: apr_pollfd_t *
 * - numsock: int
 * - nsds: int *
 * - timeout: long long
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_poll(mrb_state* mrb, mrb_value self) {
  mrb_value aprset;
  mrb_value numsock;
  mrb_value nsds;
  mrb_value timeout;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &aprset, &numsock, &nsds, &timeout);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, aprset, AprPollfdT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPollfdT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, numsock, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(nsds);
  TODO_type_check_long_long(timeout);


  /* Unbox parameters */
  apr_pollfd_t * native_aprset = (mrb_nil_p(aprset) ? NULL : mruby_unbox_apr_pollfd_t(aprset));

  int native_numsock = mrb_fixnum(numsock);

  int * native_nsds = TODO_mruby_unbox_int_PTR(nsds);

  long long native_timeout = TODO_mruby_unbox_long_long(timeout);

  /* Invocation */
  apr_status_t result = apr_poll(native_aprset, native_numsock, native_nsds, native_timeout);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_poll_method_defname_FUNCTION
#define apr_poll_method_defname_REQUIRED_ARGC 0
#define apr_poll_method_defname_OPTIONAL_ARGC 0
/* apr_poll_method_defname
 *
 * Parameters: None
 * Return Type: const char *
 */
mrb_value
mrb_APR_apr_poll_method_defname(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  const char * result = apr_poll_method_defname();

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_pollcb_add_FUNCTION
#define apr_pollcb_add_REQUIRED_ARGC 2
#define apr_pollcb_add_OPTIONAL_ARGC 0
/* apr_pollcb_add
 *
 * Parameters:
 * - pollcb: apr_pollcb_t *
 * - descriptor: apr_pollfd_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pollcb_add(mrb_state* mrb, mrb_value self) {
  mrb_value pollcb;
  mrb_value descriptor;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &pollcb, &descriptor);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pollcb, AprPollcbT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPollcbT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, descriptor, AprPollfdT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPollfdT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pollcb_t * native_pollcb = (mrb_nil_p(pollcb) ? NULL : mruby_unbox_apr_pollcb_t(pollcb));

  apr_pollfd_t * native_descriptor = (mrb_nil_p(descriptor) ? NULL : mruby_unbox_apr_pollfd_t(descriptor));

  /* Invocation */
  apr_status_t result = apr_pollcb_add(native_pollcb, native_descriptor);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pollcb_create_FUNCTION
#define apr_pollcb_create_REQUIRED_ARGC 4
#define apr_pollcb_create_OPTIONAL_ARGC 0
/* apr_pollcb_create
 *
 * Parameters:
 * - pollcb: apr_pollcb_t **
 * - size: unsigned int
 * - p: apr_pool_t *
 * - flags: unsigned int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pollcb_create(mrb_state* mrb, mrb_value self) {
  mrb_value pollcb;
  mrb_value size;
  mrb_value p;
  mrb_value flags;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &pollcb, &size, &p, &flags);


  /* Type checking */
  TODO_type_check_apr_pollcb_t_PTR_PTR(pollcb);
  if (!mrb_obj_is_kind_of(mrb, size, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pollcb_t ** native_pollcb = TODO_mruby_unbox_apr_pollcb_t_PTR_PTR(pollcb);

  unsigned int native_size = mrb_fixnum(size);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  unsigned int native_flags = mrb_fixnum(flags);

  /* Invocation */
  apr_status_t result = apr_pollcb_create(native_pollcb, native_size, native_p, native_flags);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pollcb_create_ex_FUNCTION
#define apr_pollcb_create_ex_REQUIRED_ARGC 5
#define apr_pollcb_create_ex_OPTIONAL_ARGC 0
/* apr_pollcb_create_ex
 *
 * Parameters:
 * - pollcb: apr_pollcb_t **
 * - size: unsigned int
 * - p: apr_pool_t *
 * - flags: unsigned int
 * - method: apr_pollset_method_e
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pollcb_create_ex(mrb_state* mrb, mrb_value self) {
  mrb_value pollcb;
  mrb_value size;
  mrb_value p;
  mrb_value flags;
  mrb_value method;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &pollcb, &size, &p, &flags, &method);


  /* Type checking */
  TODO_type_check_apr_pollcb_t_PTR_PTR(pollcb);
  if (!mrb_obj_is_kind_of(mrb, size, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_apr_pollset_method_e(method);


  /* Unbox parameters */
  apr_pollcb_t ** native_pollcb = TODO_mruby_unbox_apr_pollcb_t_PTR_PTR(pollcb);

  unsigned int native_size = mrb_fixnum(size);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  unsigned int native_flags = mrb_fixnum(flags);

  apr_pollset_method_e native_method = TODO_mruby_unbox_apr_pollset_method_e(method);

  /* Invocation */
  apr_status_t result = apr_pollcb_create_ex(native_pollcb, native_size, native_p, native_flags, native_method);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pollcb_poll_FUNCTION
#define apr_pollcb_poll_REQUIRED_ARGC 5
#define apr_pollcb_poll_OPTIONAL_ARGC 0
/* apr_pollcb_poll
 *
 * Parameters:
 * - pollcb: apr_pollcb_t *
 * - timeout: long long
 * - func: int (*)(void *, apr_pollfd_t *)
 * - baton: void *
 * - retcode: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pollcb_poll(mrb_state* mrb, mrb_value self) {
  mrb_value pollcb;
  mrb_value timeout;
  mrb_value func;
  mrb_value baton;
  mrb_value retcode;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &pollcb, &timeout, &func, &baton, &retcode);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pollcb, AprPollcbT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPollcbT expected");
    return mrb_nil_value();
  }
  TODO_type_check_long_long(timeout);
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_apr_pollfd_t_PTR_RPAREN(func);
  TODO_type_check_void_PTR(baton);
  if (!mrb_obj_is_kind_of(mrb, retcode, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pollcb_t * native_pollcb = (mrb_nil_p(pollcb) ? NULL : mruby_unbox_apr_pollcb_t(pollcb));

  long long native_timeout = TODO_mruby_unbox_long_long(timeout);

  int (*native_func)(void *, apr_pollfd_t *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_apr_pollfd_t_PTR_RPAREN(func);

  void * native_baton = TODO_mruby_unbox_void_PTR(baton);

  int native_retcode = mrb_fixnum(retcode);

  /* Invocation */
  apr_status_t result = apr_pollcb_poll(native_pollcb, native_timeout, native_func, native_baton, native_retcode);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pollcb_remove_FUNCTION
#define apr_pollcb_remove_REQUIRED_ARGC 4
#define apr_pollcb_remove_OPTIONAL_ARGC 0
/* apr_pollcb_remove
 *
 * Parameters:
 * - pollcb: apr_pollcb_t *
 * - descriptor: apr_pollfd_t *
 * - baton: void *
 * - descriptor: apr_pollfd_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pollcb_remove(mrb_state* mrb, mrb_value self) {
  mrb_value pollcb;
  mrb_value descriptor;
  mrb_value baton;
  mrb_value descriptor;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &pollcb, &descriptor, &baton, &descriptor);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pollcb, AprPollcbT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPollcbT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, descriptor, AprPollfdT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPollfdT expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(baton);
  if (!mrb_obj_is_kind_of(mrb, descriptor, AprPollfdT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPollfdT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pollcb_t * native_pollcb = (mrb_nil_p(pollcb) ? NULL : mruby_unbox_apr_pollcb_t(pollcb));

  apr_pollfd_t * native_descriptor = (mrb_nil_p(descriptor) ? NULL : mruby_unbox_apr_pollfd_t(descriptor));

  void * native_baton = TODO_mruby_unbox_void_PTR(baton);

  apr_pollfd_t * native_descriptor = (mrb_nil_p(descriptor) ? NULL : mruby_unbox_apr_pollfd_t(descriptor));

  /* Invocation */
  apr_status_t result = apr_pollcb_remove(native_pollcb, native_descriptor, native_baton, native_descriptor);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pollset_add_FUNCTION
#define apr_pollset_add_REQUIRED_ARGC 2
#define apr_pollset_add_OPTIONAL_ARGC 0
/* apr_pollset_add
 *
 * Parameters:
 * - pollset: apr_pollset_t *
 * - descriptor: const apr_pollfd_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pollset_add(mrb_state* mrb, mrb_value self) {
  mrb_value pollset;
  mrb_value descriptor;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &pollset, &descriptor);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pollset, AprPollsetT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPollsetT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, descriptor, AprPollfdT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPollfdT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pollset_t * native_pollset = (mrb_nil_p(pollset) ? NULL : mruby_unbox_apr_pollset_t(pollset));

  const apr_pollfd_t * native_descriptor = (mrb_nil_p(descriptor) ? NULL : mruby_unbox_const apr_pollfd_t(descriptor));

  /* Invocation */
  apr_status_t result = apr_pollset_add(native_pollset, native_descriptor);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pollset_create_FUNCTION
#define apr_pollset_create_REQUIRED_ARGC 4
#define apr_pollset_create_OPTIONAL_ARGC 0
/* apr_pollset_create
 *
 * Parameters:
 * - pollset: apr_pollset_t **
 * - size: unsigned int
 * - p: apr_pool_t *
 * - flags: unsigned int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pollset_create(mrb_state* mrb, mrb_value self) {
  mrb_value pollset;
  mrb_value size;
  mrb_value p;
  mrb_value flags;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &pollset, &size, &p, &flags);


  /* Type checking */
  TODO_type_check_apr_pollset_t_PTR_PTR(pollset);
  if (!mrb_obj_is_kind_of(mrb, size, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pollset_t ** native_pollset = TODO_mruby_unbox_apr_pollset_t_PTR_PTR(pollset);

  unsigned int native_size = mrb_fixnum(size);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  unsigned int native_flags = mrb_fixnum(flags);

  /* Invocation */
  apr_status_t result = apr_pollset_create(native_pollset, native_size, native_p, native_flags);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pollset_create_ex_FUNCTION
#define apr_pollset_create_ex_REQUIRED_ARGC 5
#define apr_pollset_create_ex_OPTIONAL_ARGC 0
/* apr_pollset_create_ex
 *
 * Parameters:
 * - pollset: apr_pollset_t **
 * - size: unsigned int
 * - p: apr_pool_t *
 * - flags: unsigned int
 * - method: apr_pollset_method_e
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pollset_create_ex(mrb_state* mrb, mrb_value self) {
  mrb_value pollset;
  mrb_value size;
  mrb_value p;
  mrb_value flags;
  mrb_value method;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &pollset, &size, &p, &flags, &method);


  /* Type checking */
  TODO_type_check_apr_pollset_t_PTR_PTR(pollset);
  if (!mrb_obj_is_kind_of(mrb, size, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_apr_pollset_method_e(method);


  /* Unbox parameters */
  apr_pollset_t ** native_pollset = TODO_mruby_unbox_apr_pollset_t_PTR_PTR(pollset);

  unsigned int native_size = mrb_fixnum(size);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  unsigned int native_flags = mrb_fixnum(flags);

  apr_pollset_method_e native_method = TODO_mruby_unbox_apr_pollset_method_e(method);

  /* Invocation */
  apr_status_t result = apr_pollset_create_ex(native_pollset, native_size, native_p, native_flags, native_method);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pollset_destroy_FUNCTION
#define apr_pollset_destroy_REQUIRED_ARGC 1
#define apr_pollset_destroy_OPTIONAL_ARGC 0
/* apr_pollset_destroy
 *
 * Parameters:
 * - pollset: apr_pollset_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pollset_destroy(mrb_state* mrb, mrb_value self) {
  mrb_value pollset;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &pollset);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pollset, AprPollsetT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPollsetT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pollset_t * native_pollset = (mrb_nil_p(pollset) ? NULL : mruby_unbox_apr_pollset_t(pollset));

  /* Invocation */
  apr_status_t result = apr_pollset_destroy(native_pollset);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pollset_method_name_FUNCTION
#define apr_pollset_method_name_REQUIRED_ARGC 1
#define apr_pollset_method_name_OPTIONAL_ARGC 0
/* apr_pollset_method_name
 *
 * Parameters:
 * - pollset: apr_pollset_t *
 * Return Type: const char *
 */
mrb_value
mrb_APR_apr_pollset_method_name(mrb_state* mrb, mrb_value self) {
  mrb_value pollset;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &pollset);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pollset, AprPollsetT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPollsetT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pollset_t * native_pollset = (mrb_nil_p(pollset) ? NULL : mruby_unbox_apr_pollset_t(pollset));

  /* Invocation */
  const char * result = apr_pollset_method_name(native_pollset);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_pollset_poll_FUNCTION
#define apr_pollset_poll_REQUIRED_ARGC 4
#define apr_pollset_poll_OPTIONAL_ARGC 0
/* apr_pollset_poll
 *
 * Parameters:
 * - pollset: apr_pollset_t *
 * - timeout: long long
 * - num: int *
 * - descriptors: const apr_pollfd_t **
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pollset_poll(mrb_state* mrb, mrb_value self) {
  mrb_value pollset;
  mrb_value timeout;
  mrb_value num;
  mrb_value descriptors;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &pollset, &timeout, &num, &descriptors);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pollset, AprPollsetT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPollsetT expected");
    return mrb_nil_value();
  }
  TODO_type_check_long_long(timeout);
  TODO_type_check_int_PTR(num);
  TODO_type_check_const_apr_pollfd_t_PTR_PTR(descriptors);


  /* Unbox parameters */
  apr_pollset_t * native_pollset = (mrb_nil_p(pollset) ? NULL : mruby_unbox_apr_pollset_t(pollset));

  long long native_timeout = TODO_mruby_unbox_long_long(timeout);

  int * native_num = TODO_mruby_unbox_int_PTR(num);

  const apr_pollfd_t ** native_descriptors = TODO_mruby_unbox_const_apr_pollfd_t_PTR_PTR(descriptors);

  /* Invocation */
  apr_status_t result = apr_pollset_poll(native_pollset, native_timeout, native_num, native_descriptors);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pollset_remove_FUNCTION
#define apr_pollset_remove_REQUIRED_ARGC 2
#define apr_pollset_remove_OPTIONAL_ARGC 0
/* apr_pollset_remove
 *
 * Parameters:
 * - pollset: apr_pollset_t *
 * - descriptor: const apr_pollfd_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pollset_remove(mrb_state* mrb, mrb_value self) {
  mrb_value pollset;
  mrb_value descriptor;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &pollset, &descriptor);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pollset, AprPollsetT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPollsetT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, descriptor, AprPollfdT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPollfdT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pollset_t * native_pollset = (mrb_nil_p(pollset) ? NULL : mruby_unbox_apr_pollset_t(pollset));

  const apr_pollfd_t * native_descriptor = (mrb_nil_p(descriptor) ? NULL : mruby_unbox_const apr_pollfd_t(descriptor));

  /* Invocation */
  apr_status_t result = apr_pollset_remove(native_pollset, native_descriptor);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pollset_wakeup_FUNCTION
#define apr_pollset_wakeup_REQUIRED_ARGC 1
#define apr_pollset_wakeup_OPTIONAL_ARGC 0
/* apr_pollset_wakeup
 *
 * Parameters:
 * - pollset: apr_pollset_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pollset_wakeup(mrb_state* mrb, mrb_value self) {
  mrb_value pollset;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &pollset);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pollset, AprPollsetT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPollsetT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pollset_t * native_pollset = (mrb_nil_p(pollset) ? NULL : mruby_unbox_apr_pollset_t(pollset));

  /* Invocation */
  apr_status_t result = apr_pollset_wakeup(native_pollset);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pool_abort_get_FUNCTION
#define apr_pool_abort_get_REQUIRED_ARGC 1
#define apr_pool_abort_get_OPTIONAL_ARGC 0
/* apr_pool_abort_get
 *
 * Parameters:
 * - pool: apr_pool_t *
 * Return Type: apr_abortfunc_t
 */
mrb_value
mrb_APR_apr_pool_abort_get(mrb_state* mrb, mrb_value self) {
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &pool);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_abortfunc_t result = apr_pool_abort_get(native_pool);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_int_LPAREN_PTR_RPAREN_LPAREN_int_RPAREN(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_pool_abort_set_FUNCTION
#define apr_pool_abort_set_REQUIRED_ARGC 2
#define apr_pool_abort_set_OPTIONAL_ARGC 0
/* apr_pool_abort_set
 *
 * Parameters:
 * - abortfunc: int (*)(int)
 * - pool: apr_pool_t *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_pool_abort_set(mrb_state* mrb, mrb_value self) {
  mrb_value abortfunc;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &abortfunc, &pool);


  /* Type checking */
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_int_RPAREN(abortfunc);
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int (*native_abortfunc)(int) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_int_RPAREN(abortfunc);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_pool_abort_set(native_abortfunc, native_pool);

  return mrb_nil_value();
}
#endif

#if BIND_apr_pool_allocator_get_FUNCTION
#define apr_pool_allocator_get_REQUIRED_ARGC 1
#define apr_pool_allocator_get_OPTIONAL_ARGC 0
/* apr_pool_allocator_get
 *
 * Parameters:
 * - pool: apr_pool_t *
 * Return Type: apr_allocator_t *
 */
mrb_value
mrb_APR_apr_pool_allocator_get(mrb_state* mrb, mrb_value self) {
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &pool);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_allocator_t * result = apr_pool_allocator_get(native_pool);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_allocator_t(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_pool_child_cleanup_set_FUNCTION
#define apr_pool_child_cleanup_set_REQUIRED_ARGC 6
#define apr_pool_child_cleanup_set_OPTIONAL_ARGC 0
/* apr_pool_child_cleanup_set
 *
 * Parameters:
 * - p: apr_pool_t *
 * - data: const void *
 * - plain_cleanup: int (*)(void *)
 * - arg4: void *
 * - child_cleanup: int (*)(void *)
 * - arg6: void *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_pool_child_cleanup_set(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value data;
  mrb_value plain_cleanup;
  mrb_value arg4;
  mrb_value child_cleanup;
  mrb_value arg6;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooo", &p, &data, &plain_cleanup, &arg4, &child_cleanup, &arg6);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_void_PTR(data);
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(plain_cleanup);
  TODO_type_check_void_PTR(arg4);
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(child_cleanup);
  TODO_type_check_void_PTR(arg6);


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const void * native_data = TODO_mruby_unbox_const_void_PTR(data);

  int (*native_plain_cleanup)(void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(plain_cleanup);

  void * native_arg4 = TODO_mruby_unbox_void_PTR(arg4);

  int (*native_child_cleanup)(void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(child_cleanup);

  void * native_arg6 = TODO_mruby_unbox_void_PTR(arg6);

  /* Invocation */
  apr_pool_child_cleanup_set(native_p, native_data, native_plain_cleanup, native_arg4, native_child_cleanup, native_arg6);

  return mrb_nil_value();
}
#endif

#if BIND_apr_pool_cleanup_for_exec_FUNCTION
#define apr_pool_cleanup_for_exec_REQUIRED_ARGC 0
#define apr_pool_cleanup_for_exec_OPTIONAL_ARGC 0
/* apr_pool_cleanup_for_exec
 *
 * Parameters: None
 * Return Type: void
 */
mrb_value
mrb_APR_apr_pool_cleanup_for_exec(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  apr_pool_cleanup_for_exec();

  return mrb_nil_value();
}
#endif

#if BIND_apr_pool_cleanup_kill_FUNCTION
#define apr_pool_cleanup_kill_REQUIRED_ARGC 4
#define apr_pool_cleanup_kill_OPTIONAL_ARGC 0
/* apr_pool_cleanup_kill
 *
 * Parameters:
 * - p: apr_pool_t *
 * - data: const void *
 * - cleanup: int (*)(void *)
 * - arg4: void *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_pool_cleanup_kill(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value data;
  mrb_value cleanup;
  mrb_value arg4;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &p, &data, &cleanup, &arg4);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_void_PTR(data);
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(cleanup);
  TODO_type_check_void_PTR(arg4);


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const void * native_data = TODO_mruby_unbox_const_void_PTR(data);

  int (*native_cleanup)(void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(cleanup);

  void * native_arg4 = TODO_mruby_unbox_void_PTR(arg4);

  /* Invocation */
  apr_pool_cleanup_kill(native_p, native_data, native_cleanup, native_arg4);

  return mrb_nil_value();
}
#endif

#if BIND_apr_pool_cleanup_null_FUNCTION
#define apr_pool_cleanup_null_REQUIRED_ARGC 1
#define apr_pool_cleanup_null_OPTIONAL_ARGC 0
/* apr_pool_cleanup_null
 *
 * Parameters:
 * - data: void *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pool_cleanup_null(mrb_state* mrb, mrb_value self) {
  mrb_value data;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &data);


  /* Type checking */
  TODO_type_check_void_PTR(data);


  /* Unbox parameters */
  void * native_data = TODO_mruby_unbox_void_PTR(data);

  /* Invocation */
  apr_status_t result = apr_pool_cleanup_null(native_data);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pool_cleanup_register_FUNCTION
#define apr_pool_cleanup_register_REQUIRED_ARGC 6
#define apr_pool_cleanup_register_OPTIONAL_ARGC 0
/* apr_pool_cleanup_register
 *
 * Parameters:
 * - p: apr_pool_t *
 * - data: const void *
 * - plain_cleanup: int (*)(void *)
 * - arg4: void *
 * - child_cleanup: int (*)(void *)
 * - arg6: void *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_pool_cleanup_register(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value data;
  mrb_value plain_cleanup;
  mrb_value arg4;
  mrb_value child_cleanup;
  mrb_value arg6;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooo", &p, &data, &plain_cleanup, &arg4, &child_cleanup, &arg6);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_void_PTR(data);
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(plain_cleanup);
  TODO_type_check_void_PTR(arg4);
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(child_cleanup);
  TODO_type_check_void_PTR(arg6);


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const void * native_data = TODO_mruby_unbox_const_void_PTR(data);

  int (*native_plain_cleanup)(void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(plain_cleanup);

  void * native_arg4 = TODO_mruby_unbox_void_PTR(arg4);

  int (*native_child_cleanup)(void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(child_cleanup);

  void * native_arg6 = TODO_mruby_unbox_void_PTR(arg6);

  /* Invocation */
  apr_pool_cleanup_register(native_p, native_data, native_plain_cleanup, native_arg4, native_child_cleanup, native_arg6);

  return mrb_nil_value();
}
#endif

#if BIND_apr_pool_cleanup_run_FUNCTION
#define apr_pool_cleanup_run_REQUIRED_ARGC 4
#define apr_pool_cleanup_run_OPTIONAL_ARGC 0
/* apr_pool_cleanup_run
 *
 * Parameters:
 * - p: apr_pool_t *
 * - data: void *
 * - cleanup: int (*)(void *)
 * - arg4: void *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pool_cleanup_run(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value data;
  mrb_value cleanup;
  mrb_value arg4;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &p, &data, &cleanup, &arg4);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(data);
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(cleanup);
  TODO_type_check_void_PTR(arg4);


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  void * native_data = TODO_mruby_unbox_void_PTR(data);

  int (*native_cleanup)(void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(cleanup);

  void * native_arg4 = TODO_mruby_unbox_void_PTR(arg4);

  /* Invocation */
  apr_status_t result = apr_pool_cleanup_run(native_p, native_data, native_cleanup, native_arg4);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pool_clear_FUNCTION
#define apr_pool_clear_REQUIRED_ARGC 1
#define apr_pool_clear_OPTIONAL_ARGC 0
/* apr_pool_clear
 *
 * Parameters:
 * - p: apr_pool_t *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_pool_clear(mrb_state* mrb, mrb_value self) {
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &p);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_pool_clear(native_p);

  return mrb_nil_value();
}
#endif

#if BIND_apr_pool_clear_debug_FUNCTION
#define apr_pool_clear_debug_REQUIRED_ARGC 2
#define apr_pool_clear_debug_OPTIONAL_ARGC 0
/* apr_pool_clear_debug
 *
 * Parameters:
 * - p: apr_pool_t *
 * - file_line: const char *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_pool_clear_debug(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value file_line;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &p, &file_line);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, file_line, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const char * native_file_line = mrb_string_value_cstr(mrb, &file_line);

  /* Invocation */
  apr_pool_clear_debug(native_p, native_file_line);

  return mrb_nil_value();
}
#endif

#if BIND_apr_pool_create_FUNCTION
#define apr_pool_create_REQUIRED_ARGC 1
#define apr_pool_create_OPTIONAL_ARGC 0
/* apr_pool_create_core_ex
*
* Parameters:
* - parent: apr_pool_t
* Return Type: [apr_status_t, apr_pool_t]
*/
mrb_value
mrb_APR_apr_pool_create(mrb_state* mrb, mrb_value self) {
   mrb_value parent;

   /* Fetch the args */
   mrb_get_args(mrb, "o", &parent);

   /* Type checking */
   if (!mrb_nil_p(parent) && !mrb_obj_is_kind_of(mrb, parent, AprPoolT_class(mrb))) {
      mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
      return mrb_nil_value();
   }

   /* Unbox parameters */
   apr_pool_t * native_parent = (mrb_nil_p(parent) ? NULL : mruby_unbox_apr_pool_t(parent));

   /* Invocation */
   apr_pool_t * native_newpool = NULL;
   apr_status_t result = apr_pool_create_ex(&native_newpool, native_parent, NULL, NULL);

   /* Box the return value */
   if (result > MRB_INT_MAX) {
      mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
      return mrb_nil_value();
   }
   mrb_value return_value = mrb_fixnum_value(result);

   mrb_value results = mrb_ary_new(mrb);
   mrb_ary_push(mrb, results, return_value);
   if (result == 0) {
      /* Not 'giftwrappng' because we don't want the pool to be garbage collected,
       * and end up taking a bunch of other objects with it. Instead, the client
       * must explicitly call apr_pool_destroy
       */
      mrb_ary_push(mrb, results, mruby_box_apr_pool_t(mrb, native_newpool));
   }
   else {
      mrb_ary_push(mrb, results, mrb_nil_value());
   }

   return results;
}
#endif

#if BIND_apr_pool_create_core_ex_FUNCTION
#define apr_pool_create_core_ex_REQUIRED_ARGC 3
#define apr_pool_create_core_ex_OPTIONAL_ARGC 0
/* apr_pool_create_core_ex
 *
 * Parameters:
 * - newpool: apr_pool_t **
 * - abort_fn: int (*)(int)
 * - allocator: apr_allocator_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pool_create_core_ex(mrb_state* mrb, mrb_value self) {
  mrb_value newpool;
  mrb_value abort_fn;
  mrb_value allocator;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &newpool, &abort_fn, &allocator);


  /* Type checking */
  TODO_type_check_apr_pool_t_PTR_PTR(newpool);
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_int_RPAREN(abort_fn);
  if (!mrb_obj_is_kind_of(mrb, allocator, AprAllocatorT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprAllocatorT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t ** native_newpool = TODO_mruby_unbox_apr_pool_t_PTR_PTR(newpool);

  int (*native_abort_fn)(int) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_int_RPAREN(abort_fn);

  apr_allocator_t * native_allocator = (mrb_nil_p(allocator) ? NULL : mruby_unbox_apr_allocator_t(allocator));

  /* Invocation */
  apr_status_t result = apr_pool_create_core_ex(native_newpool, native_abort_fn, native_allocator);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pool_create_core_ex_debug_FUNCTION
#define apr_pool_create_core_ex_debug_REQUIRED_ARGC 4
#define apr_pool_create_core_ex_debug_OPTIONAL_ARGC 0
/* apr_pool_create_core_ex_debug
 *
 * Parameters:
 * - newpool: apr_pool_t **
 * - abort_fn: int (*)(int)
 * - allocator: apr_allocator_t *
 * - file_line: const char *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pool_create_core_ex_debug(mrb_state* mrb, mrb_value self) {
  mrb_value newpool;
  mrb_value abort_fn;
  mrb_value allocator;
  mrb_value file_line;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &newpool, &abort_fn, &allocator, &file_line);


  /* Type checking */
  TODO_type_check_apr_pool_t_PTR_PTR(newpool);
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_int_RPAREN(abort_fn);
  if (!mrb_obj_is_kind_of(mrb, allocator, AprAllocatorT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprAllocatorT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, file_line, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t ** native_newpool = TODO_mruby_unbox_apr_pool_t_PTR_PTR(newpool);

  int (*native_abort_fn)(int) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_int_RPAREN(abort_fn);

  apr_allocator_t * native_allocator = (mrb_nil_p(allocator) ? NULL : mruby_unbox_apr_allocator_t(allocator));

  const char * native_file_line = mrb_string_value_cstr(mrb, &file_line);

  /* Invocation */
  apr_status_t result = apr_pool_create_core_ex_debug(native_newpool, native_abort_fn, native_allocator, native_file_line);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pool_create_ex_FUNCTION
#define apr_pool_create_ex_REQUIRED_ARGC 4
#define apr_pool_create_ex_OPTIONAL_ARGC 0
/* apr_pool_create_ex
 *
 * Parameters:
 * - newpool: apr_pool_t **
 * - parent: apr_pool_t *
 * - abort_fn: int (*)(int)
 * - allocator: apr_allocator_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pool_create_ex(mrb_state* mrb, mrb_value self) {
  mrb_value newpool;
  mrb_value parent;
  mrb_value abort_fn;
  mrb_value allocator;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &newpool, &parent, &abort_fn, &allocator);


  /* Type checking */
  TODO_type_check_apr_pool_t_PTR_PTR(newpool);
  if (!mrb_obj_is_kind_of(mrb, parent, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_int_RPAREN(abort_fn);
  if (!mrb_obj_is_kind_of(mrb, allocator, AprAllocatorT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprAllocatorT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t ** native_newpool = TODO_mruby_unbox_apr_pool_t_PTR_PTR(newpool);

  apr_pool_t * native_parent = (mrb_nil_p(parent) ? NULL : mruby_unbox_apr_pool_t(parent));

  int (*native_abort_fn)(int) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_int_RPAREN(abort_fn);

  apr_allocator_t * native_allocator = (mrb_nil_p(allocator) ? NULL : mruby_unbox_apr_allocator_t(allocator));

  /* Invocation */
  apr_status_t result = apr_pool_create_ex(native_newpool, native_parent, native_abort_fn, native_allocator);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pool_create_ex_debug_FUNCTION
#define apr_pool_create_ex_debug_REQUIRED_ARGC 5
#define apr_pool_create_ex_debug_OPTIONAL_ARGC 0
/* apr_pool_create_ex_debug
 *
 * Parameters:
 * - newpool: apr_pool_t **
 * - parent: apr_pool_t *
 * - abort_fn: int (*)(int)
 * - allocator: apr_allocator_t *
 * - file_line: const char *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pool_create_ex_debug(mrb_state* mrb, mrb_value self) {
  mrb_value newpool;
  mrb_value parent;
  mrb_value abort_fn;
  mrb_value allocator;
  mrb_value file_line;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &newpool, &parent, &abort_fn, &allocator, &file_line);


  /* Type checking */
  TODO_type_check_apr_pool_t_PTR_PTR(newpool);
  if (!mrb_obj_is_kind_of(mrb, parent, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_int_RPAREN(abort_fn);
  if (!mrb_obj_is_kind_of(mrb, allocator, AprAllocatorT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprAllocatorT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, file_line, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t ** native_newpool = TODO_mruby_unbox_apr_pool_t_PTR_PTR(newpool);

  apr_pool_t * native_parent = (mrb_nil_p(parent) ? NULL : mruby_unbox_apr_pool_t(parent));

  int (*native_abort_fn)(int) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_int_RPAREN(abort_fn);

  apr_allocator_t * native_allocator = (mrb_nil_p(allocator) ? NULL : mruby_unbox_apr_allocator_t(allocator));

  const char * native_file_line = mrb_string_value_cstr(mrb, &file_line);

  /* Invocation */
  apr_status_t result = apr_pool_create_ex_debug(native_newpool, native_parent, native_abort_fn, native_allocator, native_file_line);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pool_create_unmanaged_ex_FUNCTION
#define apr_pool_create_unmanaged_ex_REQUIRED_ARGC 3
#define apr_pool_create_unmanaged_ex_OPTIONAL_ARGC 0
/* apr_pool_create_unmanaged_ex
 *
 * Parameters:
 * - newpool: apr_pool_t **
 * - abort_fn: int (*)(int)
 * - allocator: apr_allocator_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pool_create_unmanaged_ex(mrb_state* mrb, mrb_value self) {
  mrb_value newpool;
  mrb_value abort_fn;
  mrb_value allocator;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &newpool, &abort_fn, &allocator);


  /* Type checking */
  TODO_type_check_apr_pool_t_PTR_PTR(newpool);
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_int_RPAREN(abort_fn);
  if (!mrb_obj_is_kind_of(mrb, allocator, AprAllocatorT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprAllocatorT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t ** native_newpool = TODO_mruby_unbox_apr_pool_t_PTR_PTR(newpool);

  int (*native_abort_fn)(int) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_int_RPAREN(abort_fn);

  apr_allocator_t * native_allocator = (mrb_nil_p(allocator) ? NULL : mruby_unbox_apr_allocator_t(allocator));

  /* Invocation */
  apr_status_t result = apr_pool_create_unmanaged_ex(native_newpool, native_abort_fn, native_allocator);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pool_create_unmanaged_ex_debug_FUNCTION
#define apr_pool_create_unmanaged_ex_debug_REQUIRED_ARGC 4
#define apr_pool_create_unmanaged_ex_debug_OPTIONAL_ARGC 0
/* apr_pool_create_unmanaged_ex_debug
 *
 * Parameters:
 * - newpool: apr_pool_t **
 * - abort_fn: int (*)(int)
 * - allocator: apr_allocator_t *
 * - file_line: const char *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pool_create_unmanaged_ex_debug(mrb_state* mrb, mrb_value self) {
  mrb_value newpool;
  mrb_value abort_fn;
  mrb_value allocator;
  mrb_value file_line;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &newpool, &abort_fn, &allocator, &file_line);


  /* Type checking */
  TODO_type_check_apr_pool_t_PTR_PTR(newpool);
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_int_RPAREN(abort_fn);
  if (!mrb_obj_is_kind_of(mrb, allocator, AprAllocatorT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprAllocatorT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, file_line, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t ** native_newpool = TODO_mruby_unbox_apr_pool_t_PTR_PTR(newpool);

  int (*native_abort_fn)(int) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_int_RPAREN(abort_fn);

  apr_allocator_t * native_allocator = (mrb_nil_p(allocator) ? NULL : mruby_unbox_apr_allocator_t(allocator));

  const char * native_file_line = mrb_string_value_cstr(mrb, &file_line);

  /* Invocation */
  apr_status_t result = apr_pool_create_unmanaged_ex_debug(native_newpool, native_abort_fn, native_allocator, native_file_line);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pool_destroy_FUNCTION
#define apr_pool_destroy_REQUIRED_ARGC 1
#define apr_pool_destroy_OPTIONAL_ARGC 0
/* apr_pool_destroy
 *
 * Parameters:
 * - p: apr_pool_t *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_pool_destroy(mrb_state* mrb, mrb_value self) {
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &p);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_pool_destroy(native_p);

  return mrb_nil_value();
}
#endif

#if BIND_apr_pool_destroy_debug_FUNCTION
#define apr_pool_destroy_debug_REQUIRED_ARGC 2
#define apr_pool_destroy_debug_OPTIONAL_ARGC 0
/* apr_pool_destroy_debug
 *
 * Parameters:
 * - p: apr_pool_t *
 * - file_line: const char *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_pool_destroy_debug(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value file_line;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &p, &file_line);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, file_line, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const char * native_file_line = mrb_string_value_cstr(mrb, &file_line);

  /* Invocation */
  apr_pool_destroy_debug(native_p, native_file_line);

  return mrb_nil_value();
}
#endif

#if BIND_apr_pool_initialize_FUNCTION
#define apr_pool_initialize_REQUIRED_ARGC 0
#define apr_pool_initialize_OPTIONAL_ARGC 0
/* apr_pool_initialize
 *
 * Parameters: None
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pool_initialize(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  apr_status_t result = apr_pool_initialize();

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pool_is_ancestor_FUNCTION
#define apr_pool_is_ancestor_REQUIRED_ARGC 2
#define apr_pool_is_ancestor_OPTIONAL_ARGC 0
/* apr_pool_is_ancestor
 *
 * Parameters:
 * - a: apr_pool_t *
 * - b: apr_pool_t *
 * Return Type: int
 */
mrb_value
mrb_APR_apr_pool_is_ancestor(mrb_state* mrb, mrb_value self) {
  mrb_value a;
  mrb_value b;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &a, &b);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, a, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, b, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_a = (mrb_nil_p(a) ? NULL : mruby_unbox_apr_pool_t(a));

  apr_pool_t * native_b = (mrb_nil_p(b) ? NULL : mruby_unbox_apr_pool_t(b));

  /* Invocation */
  int result = apr_pool_is_ancestor(native_a, native_b);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pool_note_subprocess_FUNCTION
#define apr_pool_note_subprocess_REQUIRED_ARGC 3
#define apr_pool_note_subprocess_OPTIONAL_ARGC 0
/* apr_pool_note_subprocess
 *
 * Parameters:
 * - a: apr_pool_t *
 * - proc: apr_proc_t *
 * - how: apr_kill_conditions_e
 * Return Type: void
 */
mrb_value
mrb_APR_apr_pool_note_subprocess(mrb_state* mrb, mrb_value self) {
  mrb_value a;
  mrb_value proc;
  mrb_value how;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &a, &proc, &how);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, a, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, proc, AprProcT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcT expected");
    return mrb_nil_value();
  }
  TODO_type_check_apr_kill_conditions_e(how);


  /* Unbox parameters */
  apr_pool_t * native_a = (mrb_nil_p(a) ? NULL : mruby_unbox_apr_pool_t(a));

  apr_proc_t * native_proc = (mrb_nil_p(proc) ? NULL : mruby_unbox_apr_proc_t(proc));

  apr_kill_conditions_e native_how = TODO_mruby_unbox_apr_kill_conditions_e(how);

  /* Invocation */
  apr_pool_note_subprocess(native_a, native_proc, native_how);

  return mrb_nil_value();
}
#endif

#if BIND_apr_pool_parent_get_FUNCTION
#define apr_pool_parent_get_REQUIRED_ARGC 1
#define apr_pool_parent_get_OPTIONAL_ARGC 0
/* apr_pool_parent_get
 *
 * Parameters:
 * - pool: apr_pool_t *
 * Return Type: apr_pool_t *
 */
mrb_value
mrb_APR_apr_pool_parent_get(mrb_state* mrb, mrb_value self) {
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &pool);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_pool_t * result = apr_pool_parent_get(native_pool);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_pool_t(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_pool_pre_cleanup_register_FUNCTION
#define apr_pool_pre_cleanup_register_REQUIRED_ARGC 4
#define apr_pool_pre_cleanup_register_OPTIONAL_ARGC 0
/* apr_pool_pre_cleanup_register
 *
 * Parameters:
 * - p: apr_pool_t *
 * - data: const void *
 * - plain_cleanup: int (*)(void *)
 * - arg4: void *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_pool_pre_cleanup_register(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value data;
  mrb_value plain_cleanup;
  mrb_value arg4;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &p, &data, &plain_cleanup, &arg4);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_void_PTR(data);
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(plain_cleanup);
  TODO_type_check_void_PTR(arg4);


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const void * native_data = TODO_mruby_unbox_const_void_PTR(data);

  int (*native_plain_cleanup)(void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(plain_cleanup);

  void * native_arg4 = TODO_mruby_unbox_void_PTR(arg4);

  /* Invocation */
  apr_pool_pre_cleanup_register(native_p, native_data, native_plain_cleanup, native_arg4);

  return mrb_nil_value();
}
#endif

#if BIND_apr_pool_tag_FUNCTION
#define apr_pool_tag_REQUIRED_ARGC 2
#define apr_pool_tag_OPTIONAL_ARGC 0
/* apr_pool_tag
 *
 * Parameters:
 * - pool: apr_pool_t *
 * - tag: const char *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_pool_tag(mrb_state* mrb, mrb_value self) {
  mrb_value pool;
  mrb_value tag;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &pool, &tag);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, tag, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  const char * native_tag = mrb_string_value_cstr(mrb, &tag);

  /* Invocation */
  apr_pool_tag(native_pool, native_tag);

  return mrb_nil_value();
}
#endif

#if BIND_apr_pool_terminate_FUNCTION
#define apr_pool_terminate_REQUIRED_ARGC 0
#define apr_pool_terminate_OPTIONAL_ARGC 0
/* apr_pool_terminate
 *
 * Parameters: None
 * Return Type: void
 */
mrb_value
mrb_APR_apr_pool_terminate(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  apr_pool_terminate();

  return mrb_nil_value();
}
#endif

#if BIND_apr_pool_userdata_get_FUNCTION
#define apr_pool_userdata_get_REQUIRED_ARGC 3
#define apr_pool_userdata_get_OPTIONAL_ARGC 0
/* apr_pool_userdata_get
 *
 * Parameters:
 * - data: void **
 * - key: const char *
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pool_userdata_get(mrb_state* mrb, mrb_value self) {
  mrb_value data;
  mrb_value key;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &data, &key, &pool);


  /* Type checking */
  TODO_type_check_void_PTR_PTR(data);
  if (!mrb_obj_is_kind_of(mrb, key, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void ** native_data = TODO_mruby_unbox_void_PTR_PTR(data);

  const char * native_key = mrb_string_value_cstr(mrb, &key);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_pool_userdata_get(native_data, native_key, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pool_userdata_set_FUNCTION
#define apr_pool_userdata_set_REQUIRED_ARGC 5
#define apr_pool_userdata_set_OPTIONAL_ARGC 0
/* apr_pool_userdata_set
 *
 * Parameters:
 * - data: const void *
 * - key: const char *
 * - cleanup: int (*)(void *)
 * - arg4: void *
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pool_userdata_set(mrb_state* mrb, mrb_value self) {
  mrb_value data;
  mrb_value key;
  mrb_value cleanup;
  mrb_value arg4;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &data, &key, &cleanup, &arg4, &pool);


  /* Type checking */
  TODO_type_check_const_void_PTR(data);
  if (!mrb_obj_is_kind_of(mrb, key, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(cleanup);
  TODO_type_check_void_PTR(arg4);
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const void * native_data = TODO_mruby_unbox_const_void_PTR(data);

  const char * native_key = mrb_string_value_cstr(mrb, &key);

  int (*native_cleanup)(void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(cleanup);

  void * native_arg4 = TODO_mruby_unbox_void_PTR(arg4);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_pool_userdata_set(native_data, native_key, native_cleanup, native_arg4, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_pool_userdata_setn_FUNCTION
#define apr_pool_userdata_setn_REQUIRED_ARGC 5
#define apr_pool_userdata_setn_OPTIONAL_ARGC 0
/* apr_pool_userdata_setn
 *
 * Parameters:
 * - data: const void *
 * - key: const char *
 * - cleanup: int (*)(void *)
 * - arg4: void *
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_pool_userdata_setn(mrb_state* mrb, mrb_value self) {
  mrb_value data;
  mrb_value key;
  mrb_value cleanup;
  mrb_value arg4;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &data, &key, &cleanup, &arg4, &pool);


  /* Type checking */
  TODO_type_check_const_void_PTR(data);
  if (!mrb_obj_is_kind_of(mrb, key, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(cleanup);
  TODO_type_check_void_PTR(arg4);
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const void * native_data = TODO_mruby_unbox_const_void_PTR(data);

  const char * native_key = mrb_string_value_cstr(mrb, &key);

  int (*native_cleanup)(void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(cleanup);

  void * native_arg4 = TODO_mruby_unbox_void_PTR(arg4);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_pool_userdata_setn(native_data, native_key, native_cleanup, native_arg4, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_proc_create_FUNCTION
#define apr_proc_create_REQUIRED_ARGC 6
#define apr_proc_create_OPTIONAL_ARGC 0
/* apr_proc_create
 *
 * Parameters:
 * - progname: const char *
 * - args: const char *const *
 * - env: const char *const *
 * - attr: apr_procattr_t *
 * - pool: apr_pool_t *
 * Return Type: [Fixnum, AprProcT]
 */
mrb_value
mrb_APR_apr_proc_create(mrb_state* mrb, mrb_value self) {
  mrb_value progname;
  mrb_value args;
  mrb_value env;
  mrb_value attr;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &progname, &args, &env, &attr, &pool);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, progname, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, args, mrb->array_class) && !mrb_nil_p(args)) {
     mrb_raise(mrb, E_TYPE_ERROR, "Array expected");
     return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, env, mrb->array_class) && !mrb_nil_p(env)) {
     mrb_raise(mrb, E_TYPE_ERROR, "Array expected");
     return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, attr, AprProcattrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcattrT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  const char * native_progname = mrb_string_value_cstr(mrb, &progname);

  const char ** native_args;
  if (mrb_nil_p(args)) {
    native_args = NULL;
  }
  else {
     int argc = mrb_ary_len(mrb, args);
     native_args = (const char**)malloc(sizeof(char*) * (argc + 1));
     for (int i = 0; i < argc; ++i) {
        mrb_value ruby_string = mrb_ary_entry(args, i);
        native_args[i] = mrb_string_value_cstr(mrb, &ruby_string);
     }
     native_args[argc] = NULL;
  }

  const char ** native_env;
  if (mrb_nil_p(env)) {
     native_env = NULL;
  }
  else {
     int envc = mrb_ary_len(mrb, env);
     native_env = (const char**)malloc(sizeof(char*) * (envc + 1));
     for (int i = 0; i < envc; ++i) {
        mrb_value ruby_string = mrb_ary_entry(env, i);
        native_env[i] = mrb_string_value_cstr(mrb, &ruby_string);
     }
     native_env[envc] = NULL;
  }

  apr_procattr_t * native_attr = (mrb_nil_p(attr) ? NULL : mruby_unbox_apr_procattr_t(attr));
  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_proc_t* native_new_proc = (apr_proc_t*)malloc(sizeof(apr_proc_t));
  apr_status_t result = apr_proc_create(native_new_proc, native_progname, native_args, native_env, native_attr, native_pool);
  if (native_args != NULL) free(native_args);
  if (native_env != NULL) free(native_env);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  mrb_value results = mrb_ary_new(mrb);
  mrb_ary_push(mrb, results, return_value);
  if (result == 0) {
     mrb_ary_push(mrb, results, mruby_giftwrap_apr_proc_t(mrb, native_new_proc));
  }
  else {
     free(native_new_proc);
     mrb_ary_push(mrb, results, mrb_nil_value());
  }

  return results;
}
#endif

#if BIND_apr_proc_detach_FUNCTION
#define apr_proc_detach_REQUIRED_ARGC 1
#define apr_proc_detach_OPTIONAL_ARGC 0
/* apr_proc_detach
 *
 * Parameters:
 * - daemonize: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_proc_detach(mrb_state* mrb, mrb_value self) {
  mrb_value daemonize;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &daemonize);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, daemonize, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_daemonize = mrb_fixnum(daemonize);

  /* Invocation */
  apr_status_t result = apr_proc_detach(native_daemonize);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_proc_kill_FUNCTION
#define apr_proc_kill_REQUIRED_ARGC 2
#define apr_proc_kill_OPTIONAL_ARGC 0
/* apr_proc_kill
 *
 * Parameters:
 * - proc: apr_proc_t *
 * - sig: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_proc_kill(mrb_state* mrb, mrb_value self) {
  mrb_value proc;
  mrb_value sig;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &proc, &sig);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, proc, AprProcT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, sig, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_proc_t * native_proc = (mrb_nil_p(proc) ? NULL : mruby_unbox_apr_proc_t(proc));

  int native_sig = mrb_fixnum(sig);

  /* Invocation */
  apr_status_t result = apr_proc_kill(native_proc, native_sig);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_proc_mutex_child_init_FUNCTION
#define apr_proc_mutex_child_init_REQUIRED_ARGC 3
#define apr_proc_mutex_child_init_OPTIONAL_ARGC 0
/* apr_proc_mutex_child_init
 *
 * Parameters:
 * - mutex: apr_proc_mutex_t **
 * - fname: const char *
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_proc_mutex_child_init(mrb_state* mrb, mrb_value self) {
  mrb_value mutex;
  mrb_value fname;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &mutex, &fname, &pool);


  /* Type checking */
  TODO_type_check_apr_proc_mutex_t_PTR_PTR(mutex);
  if (!mrb_obj_is_kind_of(mrb, fname, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_proc_mutex_t ** native_mutex = TODO_mruby_unbox_apr_proc_mutex_t_PTR_PTR(mutex);

  const char * native_fname = mrb_string_value_cstr(mrb, &fname);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_proc_mutex_child_init(native_mutex, native_fname, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_proc_mutex_cleanup_FUNCTION
#define apr_proc_mutex_cleanup_REQUIRED_ARGC 1
#define apr_proc_mutex_cleanup_OPTIONAL_ARGC 0
/* apr_proc_mutex_cleanup
 *
 * Parameters:
 * - mutex: void *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_proc_mutex_cleanup(mrb_state* mrb, mrb_value self) {
  mrb_value mutex;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &mutex);


  /* Type checking */
  TODO_type_check_void_PTR(mutex);


  /* Unbox parameters */
  void * native_mutex = TODO_mruby_unbox_void_PTR(mutex);

  /* Invocation */
  apr_status_t result = apr_proc_mutex_cleanup(native_mutex);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_proc_mutex_create_FUNCTION
#define apr_proc_mutex_create_REQUIRED_ARGC 4
#define apr_proc_mutex_create_OPTIONAL_ARGC 0
/* apr_proc_mutex_create
 *
 * Parameters:
 * - mutex: apr_proc_mutex_t **
 * - fname: const char *
 * - mech: apr_lockmech_e
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_proc_mutex_create(mrb_state* mrb, mrb_value self) {
  mrb_value mutex;
  mrb_value fname;
  mrb_value mech;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &mutex, &fname, &mech, &pool);


  /* Type checking */
  TODO_type_check_apr_proc_mutex_t_PTR_PTR(mutex);
  if (!mrb_obj_is_kind_of(mrb, fname, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_apr_lockmech_e(mech);
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_proc_mutex_t ** native_mutex = TODO_mruby_unbox_apr_proc_mutex_t_PTR_PTR(mutex);

  const char * native_fname = mrb_string_value_cstr(mrb, &fname);

  apr_lockmech_e native_mech = TODO_mruby_unbox_apr_lockmech_e(mech);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_proc_mutex_create(native_mutex, native_fname, native_mech, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_proc_mutex_defname_FUNCTION
#define apr_proc_mutex_defname_REQUIRED_ARGC 6
#define apr_proc_mutex_defname_OPTIONAL_ARGC 0
/* apr_proc_mutex_defname
 *
 * Parameters:
 * - hash: apr_crypto_hash_t *
 * - hash: apr_crypto_hash_t *
 * - data: const void *
 * - bytes: int
 * - hash: apr_crypto_hash_t *
 * - result: unsigned char *
 * Return Type: const char *
 */
mrb_value
mrb_APR_apr_proc_mutex_defname(mrb_state* mrb, mrb_value self) {
  mrb_value hash;
  mrb_value hash;
  mrb_value data;
  mrb_value bytes;
  mrb_value hash;
  mrb_value result;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooo", &hash, &hash, &data, &bytes, &hash, &result);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, hash, AprCryptoHashT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprCryptoHashT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, hash, AprCryptoHashT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprCryptoHashT expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_void_PTR(data);
  if (!mrb_obj_is_kind_of(mrb, bytes, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, hash, AprCryptoHashT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprCryptoHashT expected");
    return mrb_nil_value();
  }
  TODO_type_check_unsigned_char_PTR(result);


  /* Unbox parameters */
  apr_crypto_hash_t * native_hash = (mrb_nil_p(hash) ? NULL : mruby_unbox_apr_crypto_hash_t(hash));

  apr_crypto_hash_t * native_hash = (mrb_nil_p(hash) ? NULL : mruby_unbox_apr_crypto_hash_t(hash));

  const void * native_data = TODO_mruby_unbox_const_void_PTR(data);

  int native_bytes = mrb_fixnum(bytes);

  apr_crypto_hash_t * native_hash = (mrb_nil_p(hash) ? NULL : mruby_unbox_apr_crypto_hash_t(hash));

  unsigned char * native_result = TODO_mruby_unbox_unsigned_char_PTR(result);

  /* Invocation */
  const char * result = apr_proc_mutex_defname(native_hash, native_hash, native_data, native_bytes, native_hash, native_result);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_proc_mutex_destroy_FUNCTION
#define apr_proc_mutex_destroy_REQUIRED_ARGC 1
#define apr_proc_mutex_destroy_OPTIONAL_ARGC 0
/* apr_proc_mutex_destroy
 *
 * Parameters:
 * - mutex: apr_proc_mutex_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_proc_mutex_destroy(mrb_state* mrb, mrb_value self) {
  mrb_value mutex;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &mutex);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, mutex, AprProcMutexT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcMutexT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_proc_mutex_t * native_mutex = (mrb_nil_p(mutex) ? NULL : mruby_unbox_apr_proc_mutex_t(mutex));

  /* Invocation */
  apr_status_t result = apr_proc_mutex_destroy(native_mutex);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_proc_mutex_lock_FUNCTION
#define apr_proc_mutex_lock_REQUIRED_ARGC 1
#define apr_proc_mutex_lock_OPTIONAL_ARGC 0
/* apr_proc_mutex_lock
 *
 * Parameters:
 * - mutex: apr_proc_mutex_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_proc_mutex_lock(mrb_state* mrb, mrb_value self) {
  mrb_value mutex;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &mutex);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, mutex, AprProcMutexT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcMutexT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_proc_mutex_t * native_mutex = (mrb_nil_p(mutex) ? NULL : mruby_unbox_apr_proc_mutex_t(mutex));

  /* Invocation */
  apr_status_t result = apr_proc_mutex_lock(native_mutex);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_proc_mutex_lockfile_FUNCTION
#define apr_proc_mutex_lockfile_REQUIRED_ARGC 1
#define apr_proc_mutex_lockfile_OPTIONAL_ARGC 0
/* apr_proc_mutex_lockfile
 *
 * Parameters:
 * - mutex: apr_proc_mutex_t *
 * Return Type: const char *
 */
mrb_value
mrb_APR_apr_proc_mutex_lockfile(mrb_state* mrb, mrb_value self) {
  mrb_value mutex;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &mutex);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, mutex, AprProcMutexT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcMutexT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_proc_mutex_t * native_mutex = (mrb_nil_p(mutex) ? NULL : mruby_unbox_apr_proc_mutex_t(mutex));

  /* Invocation */
  const char * result = apr_proc_mutex_lockfile(native_mutex);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_proc_mutex_name_FUNCTION
#define apr_proc_mutex_name_REQUIRED_ARGC 1
#define apr_proc_mutex_name_OPTIONAL_ARGC 0
/* apr_proc_mutex_name
 *
 * Parameters:
 * - mutex: apr_proc_mutex_t *
 * Return Type: const char *
 */
mrb_value
mrb_APR_apr_proc_mutex_name(mrb_state* mrb, mrb_value self) {
  mrb_value mutex;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &mutex);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, mutex, AprProcMutexT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcMutexT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_proc_mutex_t * native_mutex = (mrb_nil_p(mutex) ? NULL : mruby_unbox_apr_proc_mutex_t(mutex));

  /* Invocation */
  const char * result = apr_proc_mutex_name(native_mutex);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_proc_mutex_trylock_FUNCTION
#define apr_proc_mutex_trylock_REQUIRED_ARGC 1
#define apr_proc_mutex_trylock_OPTIONAL_ARGC 0
/* apr_proc_mutex_trylock
 *
 * Parameters:
 * - mutex: apr_proc_mutex_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_proc_mutex_trylock(mrb_state* mrb, mrb_value self) {
  mrb_value mutex;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &mutex);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, mutex, AprProcMutexT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcMutexT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_proc_mutex_t * native_mutex = (mrb_nil_p(mutex) ? NULL : mruby_unbox_apr_proc_mutex_t(mutex));

  /* Invocation */
  apr_status_t result = apr_proc_mutex_trylock(native_mutex);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_proc_mutex_unlock_FUNCTION
#define apr_proc_mutex_unlock_REQUIRED_ARGC 1
#define apr_proc_mutex_unlock_OPTIONAL_ARGC 0
/* apr_proc_mutex_unlock
 *
 * Parameters:
 * - mutex: apr_proc_mutex_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_proc_mutex_unlock(mrb_state* mrb, mrb_value self) {
  mrb_value mutex;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &mutex);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, mutex, AprProcMutexT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcMutexT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_proc_mutex_t * native_mutex = (mrb_nil_p(mutex) ? NULL : mruby_unbox_apr_proc_mutex_t(mutex));

  /* Invocation */
  apr_status_t result = apr_proc_mutex_unlock(native_mutex);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_proc_other_child_alert_FUNCTION
#define apr_proc_other_child_alert_REQUIRED_ARGC 3
#define apr_proc_other_child_alert_OPTIONAL_ARGC 0
/* apr_proc_other_child_alert
 *
 * Parameters:
 * - proc: apr_proc_t *
 * - reason: int
 * - status: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_proc_other_child_alert(mrb_state* mrb, mrb_value self) {
  mrb_value proc;
  mrb_value reason;
  mrb_value status;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &proc, &reason, &status);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, proc, AprProcT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, reason, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, status, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_proc_t * native_proc = (mrb_nil_p(proc) ? NULL : mruby_unbox_apr_proc_t(proc));

  int native_reason = mrb_fixnum(reason);

  int native_status = mrb_fixnum(status);

  /* Invocation */
  apr_status_t result = apr_proc_other_child_alert(native_proc, native_reason, native_status);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_proc_other_child_refresh_FUNCTION
#define apr_proc_other_child_refresh_REQUIRED_ARGC 2
#define apr_proc_other_child_refresh_OPTIONAL_ARGC 0
/* apr_proc_other_child_refresh
 *
 * Parameters:
 * - ocr: apr_other_child_rec_t *
 * - reason: int
 * Return Type: void
 */
mrb_value
mrb_APR_apr_proc_other_child_refresh(mrb_state* mrb, mrb_value self) {
  mrb_value ocr;
  mrb_value reason;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &ocr, &reason);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, ocr, AprOtherChildRecT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprOtherChildRecT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, reason, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_other_child_rec_t * native_ocr = (mrb_nil_p(ocr) ? NULL : mruby_unbox_apr_other_child_rec_t(ocr));

  int native_reason = mrb_fixnum(reason);

  /* Invocation */
  apr_proc_other_child_refresh(native_ocr, native_reason);

  return mrb_nil_value();
}
#endif

#if BIND_apr_proc_other_child_refresh_all_FUNCTION
#define apr_proc_other_child_refresh_all_REQUIRED_ARGC 1
#define apr_proc_other_child_refresh_all_OPTIONAL_ARGC 0
/* apr_proc_other_child_refresh_all
 *
 * Parameters:
 * - reason: int
 * Return Type: void
 */
mrb_value
mrb_APR_apr_proc_other_child_refresh_all(mrb_state* mrb, mrb_value self) {
  mrb_value reason;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &reason);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, reason, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_reason = mrb_fixnum(reason);

  /* Invocation */
  apr_proc_other_child_refresh_all(native_reason);

  return mrb_nil_value();
}
#endif

#if BIND_apr_proc_other_child_register_FUNCTION
#define apr_proc_other_child_register_REQUIRED_ARGC 8
#define apr_proc_other_child_register_OPTIONAL_ARGC 0
/* apr_proc_other_child_register
 *
 * Parameters:
 * - proc: apr_proc_t *
 * - maintenance: void (*)(int, void *, int)
 * - reason: int
 * - arg4: void *
 * - status: int
 * - data: void *
 * - write_fd: apr_file_t *
 * - p: apr_pool_t *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_proc_other_child_register(mrb_state* mrb, mrb_value self) {
  mrb_value proc;
  mrb_value maintenance;
  mrb_value reason;
  mrb_value arg4;
  mrb_value status;
  mrb_value data;
  mrb_value write_fd;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooooo", &proc, &maintenance, &reason, &arg4, &status, &data, &write_fd, &p);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, proc, AprProcT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcT expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_intCOMMA_void_PTR_COMMA_int_RPAREN(maintenance);
  if (!mrb_obj_is_kind_of(mrb, reason, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(arg4);
  if (!mrb_obj_is_kind_of(mrb, status, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(data);
  if (!mrb_obj_is_kind_of(mrb, write_fd, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_proc_t * native_proc = (mrb_nil_p(proc) ? NULL : mruby_unbox_apr_proc_t(proc));

  void (*native_maintenance)(int, void *, int) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_intCOMMA_void_PTR_COMMA_int_RPAREN(maintenance);

  int native_reason = mrb_fixnum(reason);

  void * native_arg4 = TODO_mruby_unbox_void_PTR(arg4);

  int native_status = mrb_fixnum(status);

  void * native_data = TODO_mruby_unbox_void_PTR(data);

  apr_file_t * native_write_fd = (mrb_nil_p(write_fd) ? NULL : mruby_unbox_apr_file_t(write_fd));

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_proc_other_child_register(native_proc, native_maintenance, native_reason, native_arg4, native_status, native_data, native_write_fd, native_p);

  return mrb_nil_value();
}
#endif

#if BIND_apr_proc_other_child_unregister_FUNCTION
#define apr_proc_other_child_unregister_REQUIRED_ARGC 1
#define apr_proc_other_child_unregister_OPTIONAL_ARGC 0
/* apr_proc_other_child_unregister
 *
 * Parameters:
 * - data: void *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_proc_other_child_unregister(mrb_state* mrb, mrb_value self) {
  mrb_value data;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &data);


  /* Type checking */
  TODO_type_check_void_PTR(data);


  /* Unbox parameters */
  void * native_data = TODO_mruby_unbox_void_PTR(data);

  /* Invocation */
  apr_proc_other_child_unregister(native_data);

  return mrb_nil_value();
}
#endif

#if BIND_apr_proc_wait_FUNCTION
#define apr_proc_wait_REQUIRED_ARGC 4
#define apr_proc_wait_OPTIONAL_ARGC 0
/* apr_proc_wait
 *
 * Parameters:
 * - proc: apr_proc_t *
 * - waithow: apr_wait_how_e
 * Return Type: [errno: Fixnum, exitcode: Fixnum, exitwhy: Fixnum]
 */
mrb_value
mrb_APR_apr_proc_wait(mrb_state* mrb, mrb_value self) {
  mrb_value proc;
  mrb_value waithow;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &proc, &waithow);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, proc, AprProcT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, waithow, mrb->fixnum_class)) {
     mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
     return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_proc_t * native_proc = (mrb_nil_p(proc) ? NULL : mruby_unbox_apr_proc_t(proc));
  apr_wait_how_e native_waithow = (apr_wait_how_e)mrb_fixnum(waithow);

  /* Invocation */
  int native_exitcode;
  apr_exit_why_e native_exitwhy;
  apr_status_t result = apr_proc_wait(native_proc, &native_exitcode, &native_exitwhy, native_waithow);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }

  mrb_value results = mrb_ary_new(mrb);
  mrb_ary_push(mrb, results, mrb_fixnum_value(result));
  if (result == APR_CHILD_DONE) {
     mrb_ary_push(mrb, results, mrb_fixnum_value(native_exitcode));
     mrb_ary_push(mrb, results, mrb_fixnum_value(native_exitwhy));
  }
  else {
     mrb_ary_push(mrb, results, mrb_nil_value());
     mrb_ary_push(mrb, results, mrb_nil_value());
  }

  return results;
}
#endif

#if BIND_apr_proc_wait_all_procs_FUNCTION
#define apr_proc_wait_all_procs_REQUIRED_ARGC 5
#define apr_proc_wait_all_procs_OPTIONAL_ARGC 0
/* apr_proc_wait_all_procs
 *
 * Parameters:
 * - proc: apr_proc_t *
 * - exitcode: int *
 * - exitwhy: apr_exit_why_e *
 * - waithow: apr_wait_how_e
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_proc_wait_all_procs(mrb_state* mrb, mrb_value self) {
  mrb_value proc;
  mrb_value exitcode;
  mrb_value exitwhy;
  mrb_value waithow;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &proc, &exitcode, &exitwhy, &waithow, &p);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, proc, AprProcT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcT expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(exitcode);
  TODO_type_check_apr_exit_why_e_PTR(exitwhy);
  TODO_type_check_apr_wait_how_e(waithow);
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_proc_t * native_proc = (mrb_nil_p(proc) ? NULL : mruby_unbox_apr_proc_t(proc));

  int * native_exitcode = TODO_mruby_unbox_int_PTR(exitcode);

  apr_exit_why_e * native_exitwhy = TODO_mruby_unbox_apr_exit_why_e_PTR(exitwhy);

  apr_wait_how_e native_waithow = TODO_mruby_unbox_apr_wait_how_e(waithow);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_proc_wait_all_procs(native_proc, native_exitcode, native_exitwhy, native_waithow, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

/*
 * EXTENSION
 * This function is not in libapr, it's just useful for
 * implementing some of Ruby's stdlib.
 * Ex. `spawn` returns only the PID, which we'd like to `wait` on later
 */
mrb_value
mrb_APR_apr_proc_from_pid(mrb_state* mrb, mrb_value self) {
  mrb_int pid;
   mrb_get_args(mrb, "i", &pid);

   apr_proc_t* proc = (apr_proc_t*)malloc(sizeof(apr_proc_t));
   proc->pid = pid;
#if defined(_WIN32) || defined(_WIN64)
   proc->hproc = OpenProcess(SYNCHRONIZE, false, pid);
#endif

  /* Wasn't made from an apr pool, so "giftwrap" so the ruby gc free's it */
  return mruby_giftwrap_apr_proc_t(mrb, proc);
}

#if BIND_apr_procattr_addrspace_set_FUNCTION
#define apr_procattr_addrspace_set_REQUIRED_ARGC 2
#define apr_procattr_addrspace_set_OPTIONAL_ARGC 0
/* apr_procattr_addrspace_set
 *
 * Parameters:
 * - attr: apr_procattr_t *
 * - addrspace: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_procattr_addrspace_set(mrb_state* mrb, mrb_value self) {
  mrb_value attr;
  mrb_value addrspace;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &attr, &addrspace);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, attr, AprProcattrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcattrT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, addrspace, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_procattr_t * native_attr = (mrb_nil_p(attr) ? NULL : mruby_unbox_apr_procattr_t(attr));

  int native_addrspace = mrb_fixnum(addrspace);

  /* Invocation */
  apr_status_t result = apr_procattr_addrspace_set(native_attr, native_addrspace);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_procattr_child_err_set_FUNCTION
#define apr_procattr_child_err_set_REQUIRED_ARGC 3
#define apr_procattr_child_err_set_OPTIONAL_ARGC 0
/* apr_procattr_child_err_set
 *
 * Parameters:
 * - attr: apr_procattr_t *
 * - child_err: apr_file_t *
 * - parent_err: apr_file_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_procattr_child_err_set(mrb_state* mrb, mrb_value self) {
  mrb_value attr;
  mrb_value child_err;
  mrb_value parent_err;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &attr, &child_err, &parent_err);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, attr, AprProcattrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcattrT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, child_err, AprFileT_class(mrb)) && !mrb_nil_p(child_err)) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, parent_err, AprFileT_class(mrb)) && !mrb_nil_p(parent_err)) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_procattr_t * native_attr = (mrb_nil_p(attr) ? NULL : mruby_unbox_apr_procattr_t(attr));
  apr_file_t * native_child_err = (mrb_nil_p(child_err) ? NULL : mruby_unbox_apr_file_t(child_err));
  apr_file_t * native_parent_err = (mrb_nil_p(parent_err) ? NULL : mruby_unbox_apr_file_t(parent_err));

  /* Invocation */
  apr_status_t result = apr_procattr_child_err_set(native_attr, native_child_err, native_parent_err);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_procattr_child_errfn_set_FUNCTION
#define apr_procattr_child_errfn_set_REQUIRED_ARGC 2
#define apr_procattr_child_errfn_set_OPTIONAL_ARGC 0
/* apr_procattr_child_errfn_set
 *
 * Parameters:
 * - attr: apr_procattr_t *
 * - errfn: void (*)(apr_pool_t *, int, const char *)
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_procattr_child_errfn_set(mrb_state* mrb, mrb_value self) {
  mrb_value attr;
  mrb_value errfn;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &attr, &errfn);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, attr, AprProcattrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcattrT expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_apr_pool_t_PTR_COMMA_intCOMMA_const_char_PTR_RPAREN(errfn);


  /* Unbox parameters */
  apr_procattr_t * native_attr = (mrb_nil_p(attr) ? NULL : mruby_unbox_apr_procattr_t(attr));

  void (*native_errfn)(apr_pool_t *, int, const char *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_apr_pool_t_PTR_COMMA_intCOMMA_const_char_PTR_RPAREN(errfn);

  /* Invocation */
  apr_status_t result = apr_procattr_child_errfn_set(native_attr, native_errfn);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_procattr_child_in_set_FUNCTION
#define apr_procattr_child_in_set_REQUIRED_ARGC 3
#define apr_procattr_child_in_set_OPTIONAL_ARGC 0
/* apr_procattr_child_in_set
 *
 * Parameters:
 * - attr: apr_procattr_t *
 * - child_in: apr_file_t *
 * - parent_in: apr_file_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_procattr_child_in_set(mrb_state* mrb, mrb_value self) {
  mrb_value attr;
  mrb_value child_in;
  mrb_value parent_in;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &attr, &child_in, &parent_in);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, attr, AprProcattrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcattrT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, child_in, AprFileT_class(mrb)) && !mrb_nil_p(parent_in)) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, parent_in, AprFileT_class(mrb)) && !mrb_nil_p(parent_in)) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_procattr_t * native_attr = (mrb_nil_p(attr) ? NULL : mruby_unbox_apr_procattr_t(attr));
  apr_file_t * native_child_in = (mrb_nil_p(child_in) ? NULL : mruby_unbox_apr_file_t(child_in));
  apr_file_t * native_parent_in = (mrb_nil_p(parent_in) ? NULL : mruby_unbox_apr_file_t(parent_in));

  /* Invocation */
  apr_status_t result = apr_procattr_child_in_set(native_attr, native_child_in, native_parent_in);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_procattr_child_out_set_FUNCTION
#define apr_procattr_child_out_set_REQUIRED_ARGC 3
#define apr_procattr_child_out_set_OPTIONAL_ARGC 0
/* apr_procattr_child_out_set
 *
 * Parameters:
 * - attr: apr_procattr_t *
 * - child_out: apr_file_t *
 * - parent_out: apr_file_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_procattr_child_out_set(mrb_state* mrb, mrb_value self) {
  mrb_value attr;
  mrb_value child_out;
  mrb_value parent_out;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &attr, &child_out, &parent_out);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, attr, AprProcattrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcattrT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, child_out, AprFileT_class(mrb)) && !mrb_nil_p(parent_out)) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, parent_out, AprFileT_class(mrb)) && !mrb_nil_p(parent_out)) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_procattr_t * native_attr = (mrb_nil_p(attr) ? NULL : mruby_unbox_apr_procattr_t(attr));
  apr_file_t * native_child_out = (mrb_nil_p(child_out) ? NULL : mruby_unbox_apr_file_t(child_out));
  apr_file_t * native_parent_out = (mrb_nil_p(parent_out) ? NULL : mruby_unbox_apr_file_t(parent_out));

  /* Invocation */
  apr_status_t result = apr_procattr_child_out_set(native_attr, native_child_out, native_parent_out);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_procattr_cmdtype_set_FUNCTION
#define apr_procattr_cmdtype_set_REQUIRED_ARGC 2
#define apr_procattr_cmdtype_set_OPTIONAL_ARGC 0
/* apr_procattr_cmdtype_set
 *
 * Parameters:
 * - attr: apr_procattr_t *
 * - cmd: apr_cmdtype_e
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_procattr_cmdtype_set(mrb_state* mrb, mrb_value self) {
  mrb_value attr;
  mrb_value cmd;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &attr, &cmd);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, attr, AprProcattrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcattrT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, cmd, mrb->fixnum_class)) {
     mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
     return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_procattr_t * native_attr = (mrb_nil_p(attr) ? NULL : mruby_unbox_apr_procattr_t(attr));
  apr_cmdtype_e native_cmd = (apr_cmdtype_e)mrb_fixnum(cmd);

  /* Invocation */
  apr_status_t result = apr_procattr_cmdtype_set(native_attr, native_cmd);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_procattr_create_FUNCTION
#define apr_procattr_create_REQUIRED_ARGC 1
#define apr_procattr_create_OPTIONAL_ARGC 0
/* apr_procattr_create
 *
 * Parameters:
 * - cont: AprPoolT
 * Return Type: [Fixnum, AprProcattrT]
 */
mrb_value
mrb_APR_apr_procattr_create(mrb_state* mrb, mrb_value self) {
  mrb_value cont;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &cont);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, cont, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_pool_t * native_cont = (mrb_nil_p(cont) ? NULL : mruby_unbox_apr_pool_t(cont));

  /* Invocation */
  apr_procattr_t * native_new_attr;
  apr_status_t result = apr_procattr_create(&native_new_attr, native_cont);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  mrb_value results = mrb_ary_new(mrb);
  mrb_ary_push(mrb, results, return_value);
  if (result == 0) {
     mrb_ary_push(mrb, results, mruby_box_apr_procattr_t(mrb, native_new_attr));
  }
  else {
     mrb_ary_push(mrb, results, mrb_nil_value());
  }

  return results;
}
#endif

#if BIND_apr_procattr_detach_set_FUNCTION
#define apr_procattr_detach_set_REQUIRED_ARGC 2
#define apr_procattr_detach_set_OPTIONAL_ARGC 0
/* apr_procattr_detach_set
 *
 * Parameters:
 * - attr: apr_procattr_t *
 * - detach: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_procattr_detach_set(mrb_state* mrb, mrb_value self) {
  mrb_value attr;
  mrb_value detach;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &attr, &detach);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, attr, AprProcattrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcattrT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, detach, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_procattr_t * native_attr = (mrb_nil_p(attr) ? NULL : mruby_unbox_apr_procattr_t(attr));
  int native_detach = mrb_fixnum(detach);

  /* Invocation */
  apr_status_t result = apr_procattr_detach_set(native_attr, native_detach);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_procattr_dir_set_FUNCTION
#define apr_procattr_dir_set_REQUIRED_ARGC 2
#define apr_procattr_dir_set_OPTIONAL_ARGC 0
/* apr_procattr_dir_set
 *
 * Parameters:
 * - attr: apr_procattr_t *
 * - dir: const char *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_procattr_dir_set(mrb_state* mrb, mrb_value self) {
  mrb_value attr;
  mrb_value dir;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &attr, &dir);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, attr, AprProcattrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcattrT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, dir, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_procattr_t * native_attr = (mrb_nil_p(attr) ? NULL : mruby_unbox_apr_procattr_t(attr));

  const char * native_dir = mrb_string_value_cstr(mrb, &dir);

  /* Invocation */
  apr_status_t result = apr_procattr_dir_set(native_attr, native_dir);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_procattr_error_check_set_FUNCTION
#define apr_procattr_error_check_set_REQUIRED_ARGC 2
#define apr_procattr_error_check_set_OPTIONAL_ARGC 0
/* apr_procattr_error_check_set
 *
 * Parameters:
 * - attr: apr_procattr_t *
 * - chk: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_procattr_error_check_set(mrb_state* mrb, mrb_value self) {
  mrb_value attr;
  mrb_value chk;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &attr, &chk);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, attr, AprProcattrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcattrT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, chk, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_procattr_t * native_attr = (mrb_nil_p(attr) ? NULL : mruby_unbox_apr_procattr_t(attr));

  int native_chk = mrb_fixnum(chk);

  /* Invocation */
  apr_status_t result = apr_procattr_error_check_set(native_attr, native_chk);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_procattr_group_set_FUNCTION
#define apr_procattr_group_set_REQUIRED_ARGC 2
#define apr_procattr_group_set_OPTIONAL_ARGC 0
/* apr_procattr_group_set
 *
 * Parameters:
 * - attr: apr_procattr_t *
 * - groupname: const char *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_procattr_group_set(mrb_state* mrb, mrb_value self) {
  mrb_value attr;
  mrb_value groupname;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &attr, &groupname);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, attr, AprProcattrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcattrT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, groupname, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_procattr_t * native_attr = (mrb_nil_p(attr) ? NULL : mruby_unbox_apr_procattr_t(attr));
  const char * native_groupname = mrb_string_value_cstr(mrb, &groupname);

  /* Invocation */
  apr_status_t result = apr_procattr_group_set(native_attr, native_groupname);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_procattr_io_set_FUNCTION
#define apr_procattr_io_set_REQUIRED_ARGC 4
#define apr_procattr_io_set_OPTIONAL_ARGC 0
/* apr_procattr_io_set
 *
 * Parameters:
 * - attr: apr_procattr_t *
 * - in: int
 * - out: int
 * - err: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_procattr_io_set(mrb_state* mrb, mrb_value self) {
  mrb_value attr;
  mrb_value in;
  mrb_value out;
  mrb_value err;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &attr, &in, &out, &err);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, attr, AprProcattrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcattrT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, in, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, out, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, err, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_procattr_t * native_attr = (mrb_nil_p(attr) ? NULL : mruby_unbox_apr_procattr_t(attr));
  int native_in = mrb_fixnum(in);
  int native_out = mrb_fixnum(out);
  int native_err = mrb_fixnum(err);

  /* Invocation */
  apr_status_t result = apr_procattr_io_set(native_attr, native_in, native_out, native_err);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_procattr_user_set_FUNCTION
#define apr_procattr_user_set_REQUIRED_ARGC 3
#define apr_procattr_user_set_OPTIONAL_ARGC 0
/* apr_procattr_user_set
 *
 * Parameters:
 * - attr: apr_procattr_t *
 * - username: const char *
 * - password: const char *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_procattr_user_set(mrb_state* mrb, mrb_value self) {
  mrb_value attr;
  mrb_value username;
  mrb_value password;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &attr, &username, &password);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, attr, AprProcattrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcattrT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, username, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, password, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_procattr_t * native_attr = (mrb_nil_p(attr) ? NULL : mruby_unbox_apr_procattr_t(attr));
  const char * native_username = mrb_string_value_cstr(mrb, &username);
  const char * native_password = mrb_string_value_cstr(mrb, &password);

  /* Invocation */
  apr_status_t result = apr_procattr_user_set(native_attr, native_username, native_password);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_psprintf_FUNCTION
#define apr_psprintf_REQUIRED_ARGC 2
#define apr_psprintf_OPTIONAL_ARGC 0
/* apr_psprintf
 *
 * Parameters:
 * - p: apr_pool_t *
 * - fmt: const char *
 * Return Type: char *
 */
mrb_value
mrb_APR_apr_psprintf(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value fmt;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &p, &fmt);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, fmt, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const char * native_fmt = mrb_string_value_cstr(mrb, &fmt);

  /* Invocation */
  char * result = apr_psprintf(native_p, native_fmt);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_pstrcat_FUNCTION
#define apr_pstrcat_REQUIRED_ARGC 1
#define apr_pstrcat_OPTIONAL_ARGC 0
/* apr_pstrcat
 *
 * Parameters:
 * - p: apr_pool_t *
 * Return Type: char *
 */
mrb_value
mrb_APR_apr_pstrcat(mrb_state* mrb, mrb_value self) {
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &p);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  char * result = apr_pstrcat(native_p);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_pstrcatv_FUNCTION
#define apr_pstrcatv_REQUIRED_ARGC 4
#define apr_pstrcatv_OPTIONAL_ARGC 0
/* apr_pstrcatv
 *
 * Parameters:
 * - p: apr_pool_t *
 * - vec: const iovec *
 * - nvec: int
 * - nbytes: int *
 * Return Type: char *
 */
mrb_value
mrb_APR_apr_pstrcatv(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value vec;
  mrb_value nvec;
  mrb_value nbytes;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &p, &vec, &nvec, &nbytes);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_iovec_PTR(vec);
  if (!mrb_obj_is_kind_of(mrb, nvec, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(nbytes);


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const iovec * native_vec = TODO_mruby_unbox_const_iovec_PTR(vec);

  int native_nvec = mrb_fixnum(nvec);

  int * native_nbytes = TODO_mruby_unbox_int_PTR(nbytes);

  /* Invocation */
  char * result = apr_pstrcatv(native_p, native_vec, native_nvec, native_nbytes);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_pstrdup_FUNCTION
#define apr_pstrdup_REQUIRED_ARGC 2
#define apr_pstrdup_OPTIONAL_ARGC 0
/* apr_pstrdup
 *
 * Parameters:
 * - p: apr_pool_t *
 * - s: const char *
 * Return Type: char *
 */
mrb_value
mrb_APR_apr_pstrdup(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value s;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &p, &s);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, s, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const char * native_s = mrb_string_value_cstr(mrb, &s);

  /* Invocation */
  char * result = apr_pstrdup(native_p, native_s);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_pstrmemdup_FUNCTION
#define apr_pstrmemdup_REQUIRED_ARGC 3
#define apr_pstrmemdup_OPTIONAL_ARGC 0
/* apr_pstrmemdup
 *
 * Parameters:
 * - p: apr_pool_t *
 * - s: const char *
 * - n: int
 * Return Type: char *
 */
mrb_value
mrb_APR_apr_pstrmemdup(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value s;
  mrb_value n;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &p, &s, &n);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, s, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, n, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const char * native_s = mrb_string_value_cstr(mrb, &s);

  int native_n = mrb_fixnum(n);

  /* Invocation */
  char * result = apr_pstrmemdup(native_p, native_s, native_n);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_pstrndup_FUNCTION
#define apr_pstrndup_REQUIRED_ARGC 3
#define apr_pstrndup_OPTIONAL_ARGC 0
/* apr_pstrndup
 *
 * Parameters:
 * - p: apr_pool_t *
 * - s: const char *
 * - n: int
 * Return Type: char *
 */
mrb_value
mrb_APR_apr_pstrndup(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value s;
  mrb_value n;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &p, &s, &n);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, s, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, n, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const char * native_s = mrb_string_value_cstr(mrb, &s);

  int native_n = mrb_fixnum(n);

  /* Invocation */
  char * result = apr_pstrndup(native_p, native_s, native_n);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_punescape_entity_FUNCTION
#define apr_punescape_entity_REQUIRED_ARGC 2
#define apr_punescape_entity_OPTIONAL_ARGC 0
/* apr_punescape_entity
 *
 * Parameters:
 * - p: apr_pool_t *
 * - str: const char *
 * Return Type: const char *
 */
mrb_value
mrb_APR_apr_punescape_entity(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value str;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &p, &str);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, str, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const char * native_str = mrb_string_value_cstr(mrb, &str);

  /* Invocation */
  const char * result = apr_punescape_entity(native_p, native_str);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_punescape_hex_FUNCTION
#define apr_punescape_hex_REQUIRED_ARGC 4
#define apr_punescape_hex_OPTIONAL_ARGC 0
/* apr_punescape_hex
 *
 * Parameters:
 * - p: apr_pool_t *
 * - str: const char *
 * - colon: int
 * - len: int *
 * Return Type: const void *
 */
mrb_value
mrb_APR_apr_punescape_hex(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value str;
  mrb_value colon;
  mrb_value len;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &p, &str, &colon, &len);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, str, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, colon, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(len);


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const char * native_str = mrb_string_value_cstr(mrb, &str);

  int native_colon = mrb_fixnum(colon);

  int * native_len = TODO_mruby_unbox_int_PTR(len);

  /* Invocation */
  const void * result = apr_punescape_hex(native_p, native_str, native_colon, native_len);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_const_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_punescape_url_FUNCTION
#define apr_punescape_url_REQUIRED_ARGC 5
#define apr_punescape_url_OPTIONAL_ARGC 0
/* apr_punescape_url
 *
 * Parameters:
 * - p: apr_pool_t *
 * - url: const char *
 * - forbid: const char *
 * - reserved: const char *
 * - plus: int
 * Return Type: const char *
 */
mrb_value
mrb_APR_apr_punescape_url(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value url;
  mrb_value forbid;
  mrb_value reserved;
  mrb_value plus;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &p, &url, &forbid, &reserved, &plus);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, url, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, forbid, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, reserved, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, plus, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const char * native_url = mrb_string_value_cstr(mrb, &url);

  const char * native_forbid = mrb_string_value_cstr(mrb, &forbid);

  const char * native_reserved = mrb_string_value_cstr(mrb, &reserved);

  int native_plus = mrb_fixnum(plus);

  /* Invocation */
  const char * result = apr_punescape_url(native_p, native_url, native_forbid, native_reserved, native_plus);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_pvsprintf_FUNCTION
#define apr_pvsprintf_REQUIRED_ARGC 3
#define apr_pvsprintf_OPTIONAL_ARGC 0
/* apr_pvsprintf
 *
 * Parameters:
 * - p: apr_pool_t *
 * - fmt: const char *
 * - ap: int
 * Return Type: char *
 */
mrb_value
mrb_APR_apr_pvsprintf(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value fmt;
  mrb_value ap;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &p, &fmt, &ap);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, fmt, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, ap, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const char * native_fmt = mrb_string_value_cstr(mrb, &fmt);

  int native_ap = mrb_fixnum(ap);

  /* Invocation */
  char * result = apr_pvsprintf(native_p, native_fmt, native_ap);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_random_add_entropy_FUNCTION
#define apr_random_add_entropy_REQUIRED_ARGC 3
#define apr_random_add_entropy_OPTIONAL_ARGC 0
/* apr_random_add_entropy
 *
 * Parameters:
 * - g: apr_random_t *
 * - entropy_: const void *
 * - bytes: int
 * Return Type: void
 */
mrb_value
mrb_APR_apr_random_add_entropy(mrb_state* mrb, mrb_value self) {
  mrb_value g;
  mrb_value entropy_;
  mrb_value bytes;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &g, &entropy_, &bytes);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, g, AprRandomT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprRandomT expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_void_PTR(entropy_);
  if (!mrb_obj_is_kind_of(mrb, bytes, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_random_t * native_g = (mrb_nil_p(g) ? NULL : mruby_unbox_apr_random_t(g));

  const void * native_entropy_ = TODO_mruby_unbox_const_void_PTR(entropy_);

  int native_bytes = mrb_fixnum(bytes);

  /* Invocation */
  apr_random_add_entropy(native_g, native_entropy_, native_bytes);

  return mrb_nil_value();
}
#endif

#if BIND_apr_random_after_fork_FUNCTION
#define apr_random_after_fork_REQUIRED_ARGC 1
#define apr_random_after_fork_OPTIONAL_ARGC 0
/* apr_random_after_fork
 *
 * Parameters:
 * - proc: apr_proc_t *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_random_after_fork(mrb_state* mrb, mrb_value self) {
  mrb_value proc;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &proc);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, proc, AprProcT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprProcT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_proc_t * native_proc = (mrb_nil_p(proc) ? NULL : mruby_unbox_apr_proc_t(proc));

  /* Invocation */
  apr_random_after_fork(native_proc);

  return mrb_nil_value();
}
#endif

#if BIND_apr_random_barrier_FUNCTION
#define apr_random_barrier_REQUIRED_ARGC 1
#define apr_random_barrier_OPTIONAL_ARGC 0
/* apr_random_barrier
 *
 * Parameters:
 * - g: apr_random_t *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_random_barrier(mrb_state* mrb, mrb_value self) {
  mrb_value g;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &g);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, g, AprRandomT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprRandomT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_random_t * native_g = (mrb_nil_p(g) ? NULL : mruby_unbox_apr_random_t(g));

  /* Invocation */
  apr_random_barrier(native_g);

  return mrb_nil_value();
}
#endif

#if BIND_apr_random_init_FUNCTION
#define apr_random_init_REQUIRED_ARGC 5
#define apr_random_init_OPTIONAL_ARGC 0
/* apr_random_init
 *
 * Parameters:
 * - g: apr_random_t *
 * - p: apr_pool_t *
 * - pool_hash: apr_crypto_hash_t *
 * - key_hash: apr_crypto_hash_t *
 * - prng_hash: apr_crypto_hash_t *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_random_init(mrb_state* mrb, mrb_value self) {
  mrb_value g;
  mrb_value p;
  mrb_value pool_hash;
  mrb_value key_hash;
  mrb_value prng_hash;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &g, &p, &pool_hash, &key_hash, &prng_hash);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, g, AprRandomT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprRandomT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool_hash, AprCryptoHashT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprCryptoHashT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, key_hash, AprCryptoHashT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprCryptoHashT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, prng_hash, AprCryptoHashT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprCryptoHashT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_random_t * native_g = (mrb_nil_p(g) ? NULL : mruby_unbox_apr_random_t(g));

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  apr_crypto_hash_t * native_pool_hash = (mrb_nil_p(pool_hash) ? NULL : mruby_unbox_apr_crypto_hash_t(pool_hash));

  apr_crypto_hash_t * native_key_hash = (mrb_nil_p(key_hash) ? NULL : mruby_unbox_apr_crypto_hash_t(key_hash));

  apr_crypto_hash_t * native_prng_hash = (mrb_nil_p(prng_hash) ? NULL : mruby_unbox_apr_crypto_hash_t(prng_hash));

  /* Invocation */
  apr_random_init(native_g, native_p, native_pool_hash, native_key_hash, native_prng_hash);

  return mrb_nil_value();
}
#endif

#if BIND_apr_random_insecure_bytes_FUNCTION
#define apr_random_insecure_bytes_REQUIRED_ARGC 3
#define apr_random_insecure_bytes_OPTIONAL_ARGC 0
/* apr_random_insecure_bytes
 *
 * Parameters:
 * - g: apr_random_t *
 * - random: void *
 * - bytes: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_random_insecure_bytes(mrb_state* mrb, mrb_value self) {
  mrb_value g;
  mrb_value random;
  mrb_value bytes;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &g, &random, &bytes);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, g, AprRandomT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprRandomT expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(random);
  if (!mrb_obj_is_kind_of(mrb, bytes, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_random_t * native_g = (mrb_nil_p(g) ? NULL : mruby_unbox_apr_random_t(g));

  void * native_random = TODO_mruby_unbox_void_PTR(random);

  int native_bytes = mrb_fixnum(bytes);

  /* Invocation */
  apr_status_t result = apr_random_insecure_bytes(native_g, native_random, native_bytes);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_random_insecure_ready_FUNCTION
#define apr_random_insecure_ready_REQUIRED_ARGC 1
#define apr_random_insecure_ready_OPTIONAL_ARGC 0
/* apr_random_insecure_ready
 *
 * Parameters:
 * - r: apr_random_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_random_insecure_ready(mrb_state* mrb, mrb_value self) {
  mrb_value r;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &r);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, r, AprRandomT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprRandomT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_random_t * native_r = (mrb_nil_p(r) ? NULL : mruby_unbox_apr_random_t(r));

  /* Invocation */
  apr_status_t result = apr_random_insecure_ready(native_r);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_random_secure_bytes_FUNCTION
#define apr_random_secure_bytes_REQUIRED_ARGC 3
#define apr_random_secure_bytes_OPTIONAL_ARGC 0
/* apr_random_secure_bytes
 *
 * Parameters:
 * - g: apr_random_t *
 * - random: void *
 * - bytes: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_random_secure_bytes(mrb_state* mrb, mrb_value self) {
  mrb_value g;
  mrb_value random;
  mrb_value bytes;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &g, &random, &bytes);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, g, AprRandomT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprRandomT expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(random);
  if (!mrb_obj_is_kind_of(mrb, bytes, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_random_t * native_g = (mrb_nil_p(g) ? NULL : mruby_unbox_apr_random_t(g));

  void * native_random = TODO_mruby_unbox_void_PTR(random);

  int native_bytes = mrb_fixnum(bytes);

  /* Invocation */
  apr_status_t result = apr_random_secure_bytes(native_g, native_random, native_bytes);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_random_secure_ready_FUNCTION
#define apr_random_secure_ready_REQUIRED_ARGC 1
#define apr_random_secure_ready_OPTIONAL_ARGC 0
/* apr_random_secure_ready
 *
 * Parameters:
 * - r: apr_random_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_random_secure_ready(mrb_state* mrb, mrb_value self) {
  mrb_value r;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &r);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, r, AprRandomT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprRandomT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_random_t * native_r = (mrb_nil_p(r) ? NULL : mruby_unbox_apr_random_t(r));

  /* Invocation */
  apr_status_t result = apr_random_secure_ready(native_r);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_random_standard_new_FUNCTION
#define apr_random_standard_new_REQUIRED_ARGC 1
#define apr_random_standard_new_OPTIONAL_ARGC 0
/* apr_random_standard_new
 *
 * Parameters:
 * - p: apr_pool_t *
 * Return Type: apr_random_t *
 */
mrb_value
mrb_APR_apr_random_standard_new(mrb_state* mrb, mrb_value self) {
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &p);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_random_t * result = apr_random_standard_new(native_p);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_random_t(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_rfc822_date_FUNCTION
#define apr_rfc822_date_REQUIRED_ARGC 2
#define apr_rfc822_date_OPTIONAL_ARGC 0
/* apr_rfc822_date
 *
 * Parameters:
 * - date_str: char *
 * - t: long long
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_rfc822_date(mrb_state* mrb, mrb_value self) {
  mrb_value date_str;
  mrb_value t;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &date_str, &t);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, date_str, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_long_long(t);


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_date_str = strdup(mrb_string_value_cstr(mrb, &date_str));

  long long native_t = TODO_mruby_unbox_long_long(t);

  /* Invocation */
  apr_status_t result = apr_rfc822_date(native_date_str, native_t);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_date_str);
  native_date_str = NULL;

  return return_value;
}
#endif

#if BIND_apr_shm_attach_FUNCTION
#define apr_shm_attach_REQUIRED_ARGC 3
#define apr_shm_attach_OPTIONAL_ARGC 0
/* apr_shm_attach
 *
 * Parameters:
 * - m: apr_shm_t **
 * - filename: const char *
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_shm_attach(mrb_state* mrb, mrb_value self) {
  mrb_value m;
  mrb_value filename;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &m, &filename, &pool);


  /* Type checking */
  TODO_type_check_apr_shm_t_PTR_PTR(m);
  if (!mrb_obj_is_kind_of(mrb, filename, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_shm_t ** native_m = TODO_mruby_unbox_apr_shm_t_PTR_PTR(m);

  const char * native_filename = mrb_string_value_cstr(mrb, &filename);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_shm_attach(native_m, native_filename, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_shm_attach_ex_FUNCTION
#define apr_shm_attach_ex_REQUIRED_ARGC 4
#define apr_shm_attach_ex_OPTIONAL_ARGC 0
/* apr_shm_attach_ex
 *
 * Parameters:
 * - m: apr_shm_t **
 * - filename: const char *
 * - pool: apr_pool_t *
 * - flags: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_shm_attach_ex(mrb_state* mrb, mrb_value self) {
  mrb_value m;
  mrb_value filename;
  mrb_value pool;
  mrb_value flags;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &m, &filename, &pool, &flags);


  /* Type checking */
  TODO_type_check_apr_shm_t_PTR_PTR(m);
  if (!mrb_obj_is_kind_of(mrb, filename, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_shm_t ** native_m = TODO_mruby_unbox_apr_shm_t_PTR_PTR(m);

  const char * native_filename = mrb_string_value_cstr(mrb, &filename);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  int native_flags = mrb_fixnum(flags);

  /* Invocation */
  apr_status_t result = apr_shm_attach_ex(native_m, native_filename, native_pool, native_flags);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_shm_baseaddr_get_FUNCTION
#define apr_shm_baseaddr_get_REQUIRED_ARGC 1
#define apr_shm_baseaddr_get_OPTIONAL_ARGC 0
/* apr_shm_baseaddr_get
 *
 * Parameters:
 * - m: const apr_shm_t *
 * Return Type: void *
 */
mrb_value
mrb_APR_apr_shm_baseaddr_get(mrb_state* mrb, mrb_value self) {
  mrb_value m;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &m);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, m, AprShmT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprShmT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const apr_shm_t * native_m = (mrb_nil_p(m) ? NULL : mruby_unbox_const apr_shm_t(m));

  /* Invocation */
  void * result = apr_shm_baseaddr_get(native_m);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_shm_create_FUNCTION
#define apr_shm_create_REQUIRED_ARGC 4
#define apr_shm_create_OPTIONAL_ARGC 0
/* apr_shm_create
 *
 * Parameters:
 * - m: apr_shm_t **
 * - reqsize: int
 * - filename: const char *
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_shm_create(mrb_state* mrb, mrb_value self) {
  mrb_value m;
  mrb_value reqsize;
  mrb_value filename;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &m, &reqsize, &filename, &pool);


  /* Type checking */
  TODO_type_check_apr_shm_t_PTR_PTR(m);
  if (!mrb_obj_is_kind_of(mrb, reqsize, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, filename, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_shm_t ** native_m = TODO_mruby_unbox_apr_shm_t_PTR_PTR(m);

  int native_reqsize = mrb_fixnum(reqsize);

  const char * native_filename = mrb_string_value_cstr(mrb, &filename);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_shm_create(native_m, native_reqsize, native_filename, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_shm_create_ex_FUNCTION
#define apr_shm_create_ex_REQUIRED_ARGC 5
#define apr_shm_create_ex_OPTIONAL_ARGC 0
/* apr_shm_create_ex
 *
 * Parameters:
 * - m: apr_shm_t **
 * - reqsize: int
 * - filename: const char *
 * - pool: apr_pool_t *
 * - flags: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_shm_create_ex(mrb_state* mrb, mrb_value self) {
  mrb_value m;
  mrb_value reqsize;
  mrb_value filename;
  mrb_value pool;
  mrb_value flags;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &m, &reqsize, &filename, &pool, &flags);


  /* Type checking */
  TODO_type_check_apr_shm_t_PTR_PTR(m);
  if (!mrb_obj_is_kind_of(mrb, reqsize, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, filename, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_shm_t ** native_m = TODO_mruby_unbox_apr_shm_t_PTR_PTR(m);

  int native_reqsize = mrb_fixnum(reqsize);

  const char * native_filename = mrb_string_value_cstr(mrb, &filename);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  int native_flags = mrb_fixnum(flags);

  /* Invocation */
  apr_status_t result = apr_shm_create_ex(native_m, native_reqsize, native_filename, native_pool, native_flags);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_shm_destroy_FUNCTION
#define apr_shm_destroy_REQUIRED_ARGC 1
#define apr_shm_destroy_OPTIONAL_ARGC 0
/* apr_shm_destroy
 *
 * Parameters:
 * - m: apr_shm_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_shm_destroy(mrb_state* mrb, mrb_value self) {
  mrb_value m;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &m);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, m, AprShmT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprShmT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_shm_t * native_m = (mrb_nil_p(m) ? NULL : mruby_unbox_apr_shm_t(m));

  /* Invocation */
  apr_status_t result = apr_shm_destroy(native_m);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_shm_detach_FUNCTION
#define apr_shm_detach_REQUIRED_ARGC 1
#define apr_shm_detach_OPTIONAL_ARGC 0
/* apr_shm_detach
 *
 * Parameters:
 * - m: apr_shm_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_shm_detach(mrb_state* mrb, mrb_value self) {
  mrb_value m;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &m);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, m, AprShmT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprShmT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_shm_t * native_m = (mrb_nil_p(m) ? NULL : mruby_unbox_apr_shm_t(m));

  /* Invocation */
  apr_status_t result = apr_shm_detach(native_m);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_shm_remove_FUNCTION
#define apr_shm_remove_REQUIRED_ARGC 2
#define apr_shm_remove_OPTIONAL_ARGC 0
/* apr_shm_remove
 *
 * Parameters:
 * - filename: const char *
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_shm_remove(mrb_state* mrb, mrb_value self) {
  mrb_value filename;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &filename, &pool);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, filename, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_filename = mrb_string_value_cstr(mrb, &filename);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_shm_remove(native_filename, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_shm_size_get_FUNCTION
#define apr_shm_size_get_REQUIRED_ARGC 1
#define apr_shm_size_get_OPTIONAL_ARGC 0
/* apr_shm_size_get
 *
 * Parameters:
 * - m: const apr_shm_t *
 * Return Type: apr_size_t
 */
mrb_value
mrb_APR_apr_shm_size_get(mrb_state* mrb, mrb_value self) {
  mrb_value m;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &m);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, m, AprShmT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprShmT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const apr_shm_t * native_m = (mrb_nil_p(m) ? NULL : mruby_unbox_const apr_shm_t(m));

  /* Invocation */
  apr_size_t result = apr_shm_size_get(native_m);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_signal_block_FUNCTION
#define apr_signal_block_REQUIRED_ARGC 1
#define apr_signal_block_OPTIONAL_ARGC 0
/* apr_signal_block
 *
 * Parameters:
 * - signum: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_signal_block(mrb_state* mrb, mrb_value self) {
  mrb_value signum;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &signum);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, signum, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_signum = mrb_fixnum(signum);

  /* Invocation */
  apr_status_t result = apr_signal_block(native_signum);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_signal_description_get_FUNCTION
#define apr_signal_description_get_REQUIRED_ARGC 1
#define apr_signal_description_get_OPTIONAL_ARGC 0
/* apr_signal_description_get
 *
 * Parameters:
 * - signum: int
 * Return Type: const char *
 */
mrb_value
mrb_APR_apr_signal_description_get(mrb_state* mrb, mrb_value self) {
  mrb_value signum;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &signum);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, signum, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_signum = mrb_fixnum(signum);

  /* Invocation */
  const char * result = apr_signal_description_get(native_signum);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_signal_init_FUNCTION
#define apr_signal_init_REQUIRED_ARGC 1
#define apr_signal_init_OPTIONAL_ARGC 0
/* apr_signal_init
 *
 * Parameters:
 * - pglobal: apr_pool_t *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_signal_init(mrb_state* mrb, mrb_value self) {
  mrb_value pglobal;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &pglobal);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pglobal, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_pglobal = (mrb_nil_p(pglobal) ? NULL : mruby_unbox_apr_pool_t(pglobal));

  /* Invocation */
  apr_signal_init(native_pglobal);

  return mrb_nil_value();
}
#endif

#if BIND_apr_signal_unblock_FUNCTION
#define apr_signal_unblock_REQUIRED_ARGC 4
#define apr_signal_unblock_OPTIONAL_ARGC 0
/* apr_signal_unblock
 *
 * Parameters:
 * - signum: int
 * - arg2: void *
 * - arg3: void *
 * - arg4: void *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_signal_unblock(mrb_state* mrb, mrb_value self) {
  mrb_value signum;
  mrb_value arg2;
  mrb_value arg3;
  mrb_value arg4;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &signum, &arg2, &arg3, &arg4);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, signum, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(arg2);
  TODO_type_check_void_PTR(arg3);
  TODO_type_check_void_PTR(arg4);


  /* Unbox parameters */
  int native_signum = mrb_fixnum(signum);

  void * native_arg2 = TODO_mruby_unbox_void_PTR(arg2);

  void * native_arg3 = TODO_mruby_unbox_void_PTR(arg3);

  void * native_arg4 = TODO_mruby_unbox_void_PTR(arg4);

  /* Invocation */
  apr_status_t result = apr_signal_unblock(native_signum, native_arg2, native_arg3, native_arg4);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_skiplist_add_index_FUNCTION
#define apr_skiplist_add_index_REQUIRED_ARGC 3
#define apr_skiplist_add_index_OPTIONAL_ARGC 0
/* apr_skiplist_add_index
 *
 * Parameters:
 * - sl: apr_skiplist *
 * - XXX1: int (*)(void *, void *)
 * - XXX2: int (*)(void *, void *)
 * Return Type: void
 */
mrb_value
mrb_APR_apr_skiplist_add_index(mrb_state* mrb, mrb_value self) {
  mrb_value sl;
  mrb_value XXX1;
  mrb_value XXX2;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &sl, &XXX1, &XXX2);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sl, AprSkiplist_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSkiplist expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_void_PTR_RPAREN(XXX1);
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_void_PTR_RPAREN(XXX2);


  /* Unbox parameters */
  apr_skiplist * native_sl = (mrb_nil_p(sl) ? NULL : mruby_unbox_apr_skiplist(sl));

  int (*native_XXX1)(void *, void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_void_PTR_RPAREN(XXX1);

  int (*native_XXX2)(void *, void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_void_PTR_RPAREN(XXX2);

  /* Invocation */
  apr_skiplist_add_index(native_sl, native_XXX1, native_XXX2);

  return mrb_nil_value();
}
#endif

#if BIND_apr_skiplist_alloc_FUNCTION
#define apr_skiplist_alloc_REQUIRED_ARGC 2
#define apr_skiplist_alloc_OPTIONAL_ARGC 0
/* apr_skiplist_alloc
 *
 * Parameters:
 * - sl: apr_skiplist *
 * - size: int
 * Return Type: void *
 */
mrb_value
mrb_APR_apr_skiplist_alloc(mrb_state* mrb, mrb_value self) {
  mrb_value sl;
  mrb_value size;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sl, &size);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sl, AprSkiplist_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSkiplist expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, size, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_skiplist * native_sl = (mrb_nil_p(sl) ? NULL : mruby_unbox_apr_skiplist(sl));

  int native_size = mrb_fixnum(size);

  /* Invocation */
  void * result = apr_skiplist_alloc(native_sl, native_size);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_skiplist_destroy_FUNCTION
#define apr_skiplist_destroy_REQUIRED_ARGC 2
#define apr_skiplist_destroy_OPTIONAL_ARGC 0
/* apr_skiplist_destroy
 *
 * Parameters:
 * - sl: apr_skiplist *
 * - myfree: void (*)(void *)
 * Return Type: void
 */
mrb_value
mrb_APR_apr_skiplist_destroy(mrb_state* mrb, mrb_value self) {
  mrb_value sl;
  mrb_value myfree;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sl, &myfree);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sl, AprSkiplist_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSkiplist expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(myfree);


  /* Unbox parameters */
  apr_skiplist * native_sl = (mrb_nil_p(sl) ? NULL : mruby_unbox_apr_skiplist(sl));

  void (*native_myfree)(void *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(myfree);

  /* Invocation */
  apr_skiplist_destroy(native_sl, native_myfree);

  return mrb_nil_value();
}
#endif

#if BIND_apr_skiplist_find_FUNCTION
#define apr_skiplist_find_REQUIRED_ARGC 3
#define apr_skiplist_find_OPTIONAL_ARGC 0
/* apr_skiplist_find
 *
 * Parameters:
 * - sl: apr_skiplist *
 * - data: void *
 * - iter: apr_skiplistnode **
 * Return Type: void *
 */
mrb_value
mrb_APR_apr_skiplist_find(mrb_state* mrb, mrb_value self) {
  mrb_value sl;
  mrb_value data;
  mrb_value iter;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &sl, &data, &iter);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sl, AprSkiplist_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSkiplist expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(data);
  TODO_type_check_apr_skiplistnode_PTR_PTR(iter);


  /* Unbox parameters */
  apr_skiplist * native_sl = (mrb_nil_p(sl) ? NULL : mruby_unbox_apr_skiplist(sl));

  void * native_data = TODO_mruby_unbox_void_PTR(data);

  apr_skiplistnode ** native_iter = TODO_mruby_unbox_apr_skiplistnode_PTR_PTR(iter);

  /* Invocation */
  void * result = apr_skiplist_find(native_sl, native_data, native_iter);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_skiplist_find_compare_FUNCTION
#define apr_skiplist_find_compare_REQUIRED_ARGC 4
#define apr_skiplist_find_compare_OPTIONAL_ARGC 0
/* apr_skiplist_find_compare
 *
 * Parameters:
 * - sl: apr_skiplist *
 * - data: void *
 * - iter: apr_skiplistnode **
 * - func: int (*)(void *, void *)
 * Return Type: void *
 */
mrb_value
mrb_APR_apr_skiplist_find_compare(mrb_state* mrb, mrb_value self) {
  mrb_value sl;
  mrb_value data;
  mrb_value iter;
  mrb_value func;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &sl, &data, &iter, &func);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sl, AprSkiplist_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSkiplist expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(data);
  TODO_type_check_apr_skiplistnode_PTR_PTR(iter);
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_void_PTR_RPAREN(func);


  /* Unbox parameters */
  apr_skiplist * native_sl = (mrb_nil_p(sl) ? NULL : mruby_unbox_apr_skiplist(sl));

  void * native_data = TODO_mruby_unbox_void_PTR(data);

  apr_skiplistnode ** native_iter = TODO_mruby_unbox_apr_skiplistnode_PTR_PTR(iter);

  int (*native_func)(void *, void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_void_PTR_RPAREN(func);

  /* Invocation */
  void * result = apr_skiplist_find_compare(native_sl, native_data, native_iter, native_func);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_skiplist_free_FUNCTION
#define apr_skiplist_free_REQUIRED_ARGC 2
#define apr_skiplist_free_OPTIONAL_ARGC 0
/* apr_skiplist_free
 *
 * Parameters:
 * - sl: apr_skiplist *
 * - mem: void *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_skiplist_free(mrb_state* mrb, mrb_value self) {
  mrb_value sl;
  mrb_value mem;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sl, &mem);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sl, AprSkiplist_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSkiplist expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(mem);


  /* Unbox parameters */
  apr_skiplist * native_sl = (mrb_nil_p(sl) ? NULL : mruby_unbox_apr_skiplist(sl));

  void * native_mem = TODO_mruby_unbox_void_PTR(mem);

  /* Invocation */
  apr_skiplist_free(native_sl, native_mem);

  return mrb_nil_value();
}
#endif

#if BIND_apr_skiplist_getlist_FUNCTION
#define apr_skiplist_getlist_REQUIRED_ARGC 1
#define apr_skiplist_getlist_OPTIONAL_ARGC 0
/* apr_skiplist_getlist
 *
 * Parameters:
 * - sl: apr_skiplist *
 * Return Type: apr_skiplistnode *
 */
mrb_value
mrb_APR_apr_skiplist_getlist(mrb_state* mrb, mrb_value self) {
  mrb_value sl;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &sl);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sl, AprSkiplist_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSkiplist expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_skiplist * native_sl = (mrb_nil_p(sl) ? NULL : mruby_unbox_apr_skiplist(sl));

  /* Invocation */
  apr_skiplistnode * result = apr_skiplist_getlist(native_sl);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_skiplistnode(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_skiplist_init_FUNCTION
#define apr_skiplist_init_REQUIRED_ARGC 2
#define apr_skiplist_init_OPTIONAL_ARGC 0
/* apr_skiplist_init
 *
 * Parameters:
 * - sl: apr_skiplist **
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_skiplist_init(mrb_state* mrb, mrb_value self) {
  mrb_value sl;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sl, &p);


  /* Type checking */
  TODO_type_check_apr_skiplist_PTR_PTR(sl);
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_skiplist ** native_sl = TODO_mruby_unbox_apr_skiplist_PTR_PTR(sl);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_skiplist_init(native_sl, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_skiplist_insert_FUNCTION
#define apr_skiplist_insert_REQUIRED_ARGC 2
#define apr_skiplist_insert_OPTIONAL_ARGC 0
/* apr_skiplist_insert
 *
 * Parameters:
 * - sl: apr_skiplist *
 * - data: void *
 * Return Type: apr_skiplistnode *
 */
mrb_value
mrb_APR_apr_skiplist_insert(mrb_state* mrb, mrb_value self) {
  mrb_value sl;
  mrb_value data;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sl, &data);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sl, AprSkiplist_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSkiplist expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(data);


  /* Unbox parameters */
  apr_skiplist * native_sl = (mrb_nil_p(sl) ? NULL : mruby_unbox_apr_skiplist(sl));

  void * native_data = TODO_mruby_unbox_void_PTR(data);

  /* Invocation */
  apr_skiplistnode * result = apr_skiplist_insert(native_sl, native_data);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_skiplistnode(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_skiplist_insert_compare_FUNCTION
#define apr_skiplist_insert_compare_REQUIRED_ARGC 3
#define apr_skiplist_insert_compare_OPTIONAL_ARGC 0
/* apr_skiplist_insert_compare
 *
 * Parameters:
 * - sl: apr_skiplist *
 * - data: void *
 * - comp: int (*)(void *, void *)
 * Return Type: apr_skiplistnode *
 */
mrb_value
mrb_APR_apr_skiplist_insert_compare(mrb_state* mrb, mrb_value self) {
  mrb_value sl;
  mrb_value data;
  mrb_value comp;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &sl, &data, &comp);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sl, AprSkiplist_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSkiplist expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(data);
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_void_PTR_RPAREN(comp);


  /* Unbox parameters */
  apr_skiplist * native_sl = (mrb_nil_p(sl) ? NULL : mruby_unbox_apr_skiplist(sl));

  void * native_data = TODO_mruby_unbox_void_PTR(data);

  int (*native_comp)(void *, void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_void_PTR_RPAREN(comp);

  /* Invocation */
  apr_skiplistnode * result = apr_skiplist_insert_compare(native_sl, native_data, native_comp);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_skiplistnode(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_skiplist_merge_FUNCTION
#define apr_skiplist_merge_REQUIRED_ARGC 2
#define apr_skiplist_merge_OPTIONAL_ARGC 0
/* apr_skiplist_merge
 *
 * Parameters:
 * - sl1: apr_skiplist *
 * - sl2: apr_skiplist *
 * Return Type: apr_skiplist *
 */
mrb_value
mrb_APR_apr_skiplist_merge(mrb_state* mrb, mrb_value self) {
  mrb_value sl1;
  mrb_value sl2;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sl1, &sl2);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sl1, AprSkiplist_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSkiplist expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, sl2, AprSkiplist_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSkiplist expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_skiplist * native_sl1 = (mrb_nil_p(sl1) ? NULL : mruby_unbox_apr_skiplist(sl1));

  apr_skiplist * native_sl2 = (mrb_nil_p(sl2) ? NULL : mruby_unbox_apr_skiplist(sl2));

  /* Invocation */
  apr_skiplist * result = apr_skiplist_merge(native_sl1, native_sl2);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_skiplist(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_skiplist_next_FUNCTION
#define apr_skiplist_next_REQUIRED_ARGC 2
#define apr_skiplist_next_OPTIONAL_ARGC 0
/* apr_skiplist_next
 *
 * Parameters:
 * - sl: apr_skiplist *
 * - iter: apr_skiplistnode **
 * Return Type: void *
 */
mrb_value
mrb_APR_apr_skiplist_next(mrb_state* mrb, mrb_value self) {
  mrb_value sl;
  mrb_value iter;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sl, &iter);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sl, AprSkiplist_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSkiplist expected");
    return mrb_nil_value();
  }
  TODO_type_check_apr_skiplistnode_PTR_PTR(iter);


  /* Unbox parameters */
  apr_skiplist * native_sl = (mrb_nil_p(sl) ? NULL : mruby_unbox_apr_skiplist(sl));

  apr_skiplistnode ** native_iter = TODO_mruby_unbox_apr_skiplistnode_PTR_PTR(iter);

  /* Invocation */
  void * result = apr_skiplist_next(native_sl, native_iter);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_skiplist_peek_FUNCTION
#define apr_skiplist_peek_REQUIRED_ARGC 1
#define apr_skiplist_peek_OPTIONAL_ARGC 0
/* apr_skiplist_peek
 *
 * Parameters:
 * - sl: apr_skiplist *
 * Return Type: void *
 */
mrb_value
mrb_APR_apr_skiplist_peek(mrb_state* mrb, mrb_value self) {
  mrb_value sl;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &sl);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sl, AprSkiplist_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSkiplist expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_skiplist * native_sl = (mrb_nil_p(sl) ? NULL : mruby_unbox_apr_skiplist(sl));

  /* Invocation */
  void * result = apr_skiplist_peek(native_sl);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_skiplist_pop_FUNCTION
#define apr_skiplist_pop_REQUIRED_ARGC 2
#define apr_skiplist_pop_OPTIONAL_ARGC 0
/* apr_skiplist_pop
 *
 * Parameters:
 * - sl: apr_skiplist *
 * - myfree: void (*)(void *)
 * Return Type: void *
 */
mrb_value
mrb_APR_apr_skiplist_pop(mrb_state* mrb, mrb_value self) {
  mrb_value sl;
  mrb_value myfree;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sl, &myfree);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sl, AprSkiplist_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSkiplist expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(myfree);


  /* Unbox parameters */
  apr_skiplist * native_sl = (mrb_nil_p(sl) ? NULL : mruby_unbox_apr_skiplist(sl));

  void (*native_myfree)(void *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(myfree);

  /* Invocation */
  void * result = apr_skiplist_pop(native_sl, native_myfree);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_skiplist_previous_FUNCTION
#define apr_skiplist_previous_REQUIRED_ARGC 2
#define apr_skiplist_previous_OPTIONAL_ARGC 0
/* apr_skiplist_previous
 *
 * Parameters:
 * - sl: apr_skiplist *
 * - iter: apr_skiplistnode **
 * Return Type: void *
 */
mrb_value
mrb_APR_apr_skiplist_previous(mrb_state* mrb, mrb_value self) {
  mrb_value sl;
  mrb_value iter;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sl, &iter);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sl, AprSkiplist_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSkiplist expected");
    return mrb_nil_value();
  }
  TODO_type_check_apr_skiplistnode_PTR_PTR(iter);


  /* Unbox parameters */
  apr_skiplist * native_sl = (mrb_nil_p(sl) ? NULL : mruby_unbox_apr_skiplist(sl));

  apr_skiplistnode ** native_iter = TODO_mruby_unbox_apr_skiplistnode_PTR_PTR(iter);

  /* Invocation */
  void * result = apr_skiplist_previous(native_sl, native_iter);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_skiplist_remove_FUNCTION
#define apr_skiplist_remove_REQUIRED_ARGC 3
#define apr_skiplist_remove_OPTIONAL_ARGC 0
/* apr_skiplist_remove
 *
 * Parameters:
 * - sl: apr_skiplist *
 * - data: void *
 * - myfree: void (*)(void *)
 * Return Type: int
 */
mrb_value
mrb_APR_apr_skiplist_remove(mrb_state* mrb, mrb_value self) {
  mrb_value sl;
  mrb_value data;
  mrb_value myfree;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &sl, &data, &myfree);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sl, AprSkiplist_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSkiplist expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(data);
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(myfree);


  /* Unbox parameters */
  apr_skiplist * native_sl = (mrb_nil_p(sl) ? NULL : mruby_unbox_apr_skiplist(sl));

  void * native_data = TODO_mruby_unbox_void_PTR(data);

  void (*native_myfree)(void *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(myfree);

  /* Invocation */
  int result = apr_skiplist_remove(native_sl, native_data, native_myfree);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_skiplist_remove_all_FUNCTION
#define apr_skiplist_remove_all_REQUIRED_ARGC 2
#define apr_skiplist_remove_all_OPTIONAL_ARGC 0
/* apr_skiplist_remove_all
 *
 * Parameters:
 * - sl: apr_skiplist *
 * - myfree: void (*)(void *)
 * Return Type: void
 */
mrb_value
mrb_APR_apr_skiplist_remove_all(mrb_state* mrb, mrb_value self) {
  mrb_value sl;
  mrb_value myfree;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sl, &myfree);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sl, AprSkiplist_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSkiplist expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(myfree);


  /* Unbox parameters */
  apr_skiplist * native_sl = (mrb_nil_p(sl) ? NULL : mruby_unbox_apr_skiplist(sl));

  void (*native_myfree)(void *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(myfree);

  /* Invocation */
  apr_skiplist_remove_all(native_sl, native_myfree);

  return mrb_nil_value();
}
#endif

#if BIND_apr_skiplist_remove_compare_FUNCTION
#define apr_skiplist_remove_compare_REQUIRED_ARGC 4
#define apr_skiplist_remove_compare_OPTIONAL_ARGC 0
/* apr_skiplist_remove_compare
 *
 * Parameters:
 * - sl: apr_skiplist *
 * - data: void *
 * - myfree: void (*)(void *)
 * - comp: int (*)(void *, void *)
 * Return Type: int
 */
mrb_value
mrb_APR_apr_skiplist_remove_compare(mrb_state* mrb, mrb_value self) {
  mrb_value sl;
  mrb_value data;
  mrb_value myfree;
  mrb_value comp;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &sl, &data, &myfree, &comp);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sl, AprSkiplist_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSkiplist expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(data);
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(myfree);
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_void_PTR_RPAREN(comp);


  /* Unbox parameters */
  apr_skiplist * native_sl = (mrb_nil_p(sl) ? NULL : mruby_unbox_apr_skiplist(sl));

  void * native_data = TODO_mruby_unbox_void_PTR(data);

  void (*native_myfree)(void *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(myfree);

  int (*native_comp)(void *, void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_void_PTR_RPAREN(comp);

  /* Invocation */
  int result = apr_skiplist_remove_compare(native_sl, native_data, native_myfree, native_comp);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_skiplist_set_compare_FUNCTION
#define apr_skiplist_set_compare_REQUIRED_ARGC 3
#define apr_skiplist_set_compare_OPTIONAL_ARGC 0
/* apr_skiplist_set_compare
 *
 * Parameters:
 * - sl: apr_skiplist *
 * - XXX1: int (*)(void *, void *)
 * - XXX2: int (*)(void *, void *)
 * Return Type: void
 */
mrb_value
mrb_APR_apr_skiplist_set_compare(mrb_state* mrb, mrb_value self) {
  mrb_value sl;
  mrb_value XXX1;
  mrb_value XXX2;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &sl, &XXX1, &XXX2);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sl, AprSkiplist_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSkiplist expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_void_PTR_RPAREN(XXX1);
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_void_PTR_RPAREN(XXX2);


  /* Unbox parameters */
  apr_skiplist * native_sl = (mrb_nil_p(sl) ? NULL : mruby_unbox_apr_skiplist(sl));

  int (*native_XXX1)(void *, void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_void_PTR_RPAREN(XXX1);

  int (*native_XXX2)(void *, void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_void_PTR_RPAREN(XXX2);

  /* Invocation */
  apr_skiplist_set_compare(native_sl, native_XXX1, native_XXX2);

  return mrb_nil_value();
}
#endif

#if BIND_apr_sleep_FUNCTION
#define apr_sleep_REQUIRED_ARGC 1
#define apr_sleep_OPTIONAL_ARGC 0
/* apr_sleep
 *
 * Parameters:
 * - t: long long
 * Return Type: void
 */
mrb_value
mrb_APR_apr_sleep(mrb_state* mrb, mrb_value self) {
  mrb_int t;
  mrb_get_args(mrb, "i", &t);
  apr_sleep(t);
  return mrb_nil_value();
}
#endif

#if BIND_apr_snprintf_FUNCTION
#define apr_snprintf_REQUIRED_ARGC 3
#define apr_snprintf_OPTIONAL_ARGC 0
/* apr_snprintf
 *
 * Parameters:
 * - buf: char *
 * - len: int
 * - format: const char *
 * Return Type: int
 */
mrb_value
mrb_APR_apr_snprintf(mrb_state* mrb, mrb_value self) {
  mrb_value buf;
  mrb_value len;
  mrb_value format;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &buf, &len, &format);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, buf, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, len, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, format, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_buf = strdup(mrb_string_value_cstr(mrb, &buf));

  int native_len = mrb_fixnum(len);

  const char * native_format = mrb_string_value_cstr(mrb, &format);

  /* Invocation */
  int result = apr_snprintf(native_buf, native_len, native_format);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_buf);
  native_buf = NULL;

  return return_value;
}
#endif

#if BIND_apr_sockaddr_equal_FUNCTION
#define apr_sockaddr_equal_REQUIRED_ARGC 2
#define apr_sockaddr_equal_OPTIONAL_ARGC 0
/* apr_sockaddr_equal
 *
 * Parameters:
 * - addr1: const apr_sockaddr_t *
 * - addr2: const apr_sockaddr_t *
 * Return Type: int (0 for false, non-zero otherwise)
 */
mrb_value
mrb_APR_apr_sockaddr_equal(mrb_state* mrb, mrb_value self) {
  mrb_value addr1;
  mrb_value addr2;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &addr1, &addr2);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, addr1, AprSockaddrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSockaddrT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, addr2, AprSockaddrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSockaddrT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  const apr_sockaddr_t * native_addr1 = (mrb_nil_p(addr1) ? NULL : mruby_unbox_apr_sockaddr_t(addr1));
  const apr_sockaddr_t * native_addr2 = (mrb_nil_p(addr2) ? NULL : mruby_unbox_apr_sockaddr_t(addr2));

  /* Invocation */
  int result = apr_sockaddr_equal(native_addr1, native_addr2);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_sockaddr_info_get_FUNCTION
#define apr_sockaddr_info_get_REQUIRED_ARGC 5
#define apr_sockaddr_info_get_OPTIONAL_ARGC 0
/* apr_sockaddr_info_get
 *
 * Parameters:
 * - hostname: const char *
 * - family: int
 * - port: unsigned short
 * - flags: int
 * - p: apr_pool_t *
 * Return Type: [errno, Fixnum, sock_add, AprSockaddrT]
 */
mrb_value
mrb_APR_apr_sockaddr_info_get(mrb_state* mrb, mrb_value self) {
  mrb_value hostname;
  mrb_value family;
  mrb_value port;
  mrb_value flags;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &hostname, &family, &port, &flags, &p);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, hostname, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, family, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, port, mrb->fixnum_class)) {
     mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
     return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  const char * native_hostname = mrb_string_value_cstr(mrb, &hostname);
  int native_family = mrb_fixnum(family);
  unsigned short native_port = mrb_fixnum(port);
  int native_flags = mrb_fixnum(flags);
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_sockaddr_t * native_sa;
  apr_status_t result = apr_sockaddr_info_get(&native_sa, native_hostname, native_family, native_port, native_flags, native_p);
  RETURN_ERRNO_AND_OUTPUT(result, mruby_box_apr_sockaddr_t(mrb, native_sa));
}
#endif

#if BIND_apr_sockaddr_ip_get_FUNCTION
#define apr_sockaddr_ip_get_REQUIRED_ARGC 1
#define apr_sockaddr_ip_get_OPTIONAL_ARGC 0
/* apr_sockaddr_ip_get
 *
 * Parameters:
 * - addr: char **
 * - sockaddr: apr_sockaddr_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_sockaddr_ip_get(mrb_state* mrb, mrb_value self) {
  mrb_value sockaddr;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &sockaddr);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sockaddr, AprSockaddrT_class(mrb))) {
     mrb_raise(mrb, E_TYPE_ERROR, "AprSockaddrT expected");
     return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_sockaddr_t * native_sockaddr = (mrb_nil_p(sockaddr) ? NULL : mruby_unbox_apr_sockaddr_t(sockaddr));

  /* Invocation */
  char * native_addr = NULL;
  apr_status_t result = apr_sockaddr_ip_get(&native_addr, native_sockaddr);
  RETURN_ERRNO_AND_OUTPUT(result, mrb_str_new_cstr(mrb, native_addr));
}
#endif

#if BIND_apr_sockaddr_ip_getbuf_FUNCTION
#define apr_sockaddr_ip_getbuf_REQUIRED_ARGC 3
#define apr_sockaddr_ip_getbuf_OPTIONAL_ARGC 0
/* apr_sockaddr_ip_getbuf
 *
 * Parameters:
 * - buf: char *
 * - buflen: int
 * - sockaddr: apr_sockaddr_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_sockaddr_ip_getbuf(mrb_state* mrb, mrb_value self) {
  mrb_value buf;
  mrb_value buflen;
  mrb_value sockaddr;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &buf, &buflen, &sockaddr);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, buf, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, buflen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, sockaddr, AprSockaddrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSockaddrT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_buf = strdup(mrb_string_value_cstr(mrb, &buf));

  int native_buflen = mrb_fixnum(buflen);

  apr_sockaddr_t * native_sockaddr = (mrb_nil_p(sockaddr) ? NULL : mruby_unbox_apr_sockaddr_t(sockaddr));

  /* Invocation */
  apr_status_t result = apr_sockaddr_ip_getbuf(native_buf, native_buflen, native_sockaddr);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_buf);
  native_buf = NULL;

  return return_value;
}
#endif

#if BIND_apr_sockaddr_is_wildcard_FUNCTION
#define apr_sockaddr_is_wildcard_REQUIRED_ARGC 1
#define apr_sockaddr_is_wildcard_OPTIONAL_ARGC 0
/* apr_sockaddr_is_wildcard
 *
 * Parameters:
 * - addr: const apr_sockaddr_t *
 * Return Type: Fixnum (non-zero if the address is initialize and is the wildcard)
 */
mrb_value
mrb_APR_apr_sockaddr_is_wildcard(mrb_state* mrb, mrb_value self) {
  mrb_value addr;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &addr);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, addr, AprSockaddrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSockaddrT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  const apr_sockaddr_t * native_addr = (mrb_nil_p(addr) ? NULL : mruby_unbox_apr_sockaddr_t(addr));

  /* Invocation */
  int result = apr_sockaddr_is_wildcard(native_addr);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_socket_accept_FUNCTION
#define apr_socket_accept_REQUIRED_ARGC 2
#define apr_socket_accept_OPTIONAL_ARGC 0
/* apr_socket_accept
 *
 * Parameters:
 * - sock: apr_socket_t *
 * - connection_pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_socket_accept(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value connection_pool;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sock, &connection_pool);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, connection_pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));
  apr_pool_t * native_connection_pool = (mrb_nil_p(connection_pool) ? NULL : mruby_unbox_apr_pool_t(connection_pool));

  /* Invocation */
  apr_socket_t * native_new_sock;
  apr_status_t result = apr_socket_accept(&native_new_sock, native_sock, native_connection_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);
  RETURN_ERRNO_AND_OUTPUT(result, mruby_box_apr_socket_t(mrb, native_new_sock));
}
#endif

#if BIND_apr_socket_addr_get_FUNCTION
#define apr_socket_addr_get_REQUIRED_ARGC 2
#define apr_socket_addr_get_OPTIONAL_ARGC 0
/* apr_socket_addr_get
 *
 * Parameters:
 * - which: Fixnum
 * - sock: AprSocketT
 * Return Type: [errno: Fixnum, sock_addr: AprSockaddrT]
 */
mrb_value
mrb_APR_apr_socket_addr_get(mrb_state* mrb, mrb_value self) {
  mrb_value which;
  mrb_value sock;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &which, &sock);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, which, mrb->fixnum_class)) {
     mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
     return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_interface_e native_which = (apr_interface_e)mrb_fixnum(which);
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));

  /* Invocation */
  apr_sockaddr_t * native_sa;
  apr_status_t result = apr_socket_addr_get(&native_sa, native_which, native_sock);
  RETURN_ERRNO_AND_OUTPUT(result, mruby_box_apr_sockaddr_t(mrb, native_sa));
}
#endif

#if BIND_apr_socket_atmark_FUNCTION
#define apr_socket_atmark_REQUIRED_ARGC 2
#define apr_socket_atmark_OPTIONAL_ARGC 0
/* apr_socket_atmark
 *
 * Parameters:
 * - sock: apr_socket_t *
 * - atmark: int *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_socket_atmark(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value atmark;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sock, &atmark);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(atmark);


  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));

  int * native_atmark = TODO_mruby_unbox_int_PTR(atmark);

  /* Invocation */
  apr_status_t result = apr_socket_atmark(native_sock, native_atmark);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_socket_atreadeof_FUNCTION
#define apr_socket_atreadeof_REQUIRED_ARGC 2
#define apr_socket_atreadeof_OPTIONAL_ARGC 0
/* apr_socket_atreadeof
 *
 * Parameters:
 * - sock: apr_socket_t *
 * - atreadeof: int *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_socket_atreadeof(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value atreadeof;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sock, &atreadeof);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(atreadeof);


  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));

  int * native_atreadeof = TODO_mruby_unbox_int_PTR(atreadeof);

  /* Invocation */
  apr_status_t result = apr_socket_atreadeof(native_sock, native_atreadeof);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_socket_bind_FUNCTION
#define apr_socket_bind_REQUIRED_ARGC 2
#define apr_socket_bind_OPTIONAL_ARGC 0
/* apr_socket_bind
 *
 * Parameters:
 * - sock: apr_socket_t *
 * - sa: apr_sockaddr_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_socket_bind(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value sa;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sock, &sa);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, sa, AprSockaddrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSockaddrT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));
  apr_sockaddr_t * native_sa = (mrb_nil_p(sa) ? NULL : mruby_unbox_apr_sockaddr_t(sa));

  /* Invocation */
  apr_status_t result = apr_socket_bind(native_sock, native_sa);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_socket_close_FUNCTION
#define apr_socket_close_REQUIRED_ARGC 1
#define apr_socket_close_OPTIONAL_ARGC 0
/* apr_socket_close
 *
 * Parameters:
 * - thesocket: apr_socket_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_socket_close(mrb_state* mrb, mrb_value self) {
  mrb_value thesocket;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &thesocket);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, thesocket, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_socket_t * native_thesocket = (mrb_nil_p(thesocket) ? NULL : mruby_unbox_apr_socket_t(thesocket));

  /* Invocation */
  apr_status_t result = apr_socket_close(native_thesocket);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_socket_connect_FUNCTION
#define apr_socket_connect_REQUIRED_ARGC 2
#define apr_socket_connect_OPTIONAL_ARGC 0
/* apr_socket_connect
 *
 * Parameters:
 * - sock: apr_socket_t *
 * - sa: apr_sockaddr_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_socket_connect(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value sa;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sock, &sa);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, sa, AprSockaddrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSockaddrT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));
  apr_sockaddr_t * native_sa = (mrb_nil_p(sa) ? NULL : mruby_unbox_apr_sockaddr_t(sa));

  /* Invocation */
  apr_status_t result = apr_socket_connect(native_sock, native_sa);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_socket_create_FUNCTION
#define apr_socket_create_REQUIRED_ARGC 5
#define apr_socket_create_OPTIONAL_ARGC 0
/* apr_socket_create
 *
 * Parameters:
 * - family: int
 * - type: int
 * - protocol: int
 * - cont: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_socket_create(mrb_state* mrb, mrb_value self) {
  mrb_value family;
  mrb_value type;
  mrb_value protocol;
  mrb_value cont;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &family, &type, &protocol, &cont);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, family, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, type, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, protocol, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, cont, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  int native_family = mrb_fixnum(family);
  int native_type = mrb_fixnum(type);
  int native_protocol = mrb_fixnum(protocol);
  apr_pool_t * native_cont = (mrb_nil_p(cont) ? NULL : mruby_unbox_apr_pool_t(cont));

  /* Invocation */
  apr_socket_t * native_new_sock;
  apr_status_t result = apr_socket_create(&native_new_sock, native_family, native_type, native_protocol, native_cont);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  RETURN_ERRNO_AND_OUTPUT(result, mruby_box_apr_socket_t(mrb, native_new_sock));
}
#endif

#if BIND_apr_socket_data_get_FUNCTION
#define apr_socket_data_get_REQUIRED_ARGC 3
#define apr_socket_data_get_OPTIONAL_ARGC 0
/* apr_socket_data_get
 *
 * Parameters:
 * - data: void **
 * - key: const char *
 * - sock: apr_socket_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_socket_data_get(mrb_state* mrb, mrb_value self) {
  mrb_value data;
  mrb_value key;
  mrb_value sock;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &data, &key, &sock);


  /* Type checking */
  TODO_type_check_void_PTR_PTR(data);
  if (!mrb_obj_is_kind_of(mrb, key, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void ** native_data = TODO_mruby_unbox_void_PTR_PTR(data);

  const char * native_key = mrb_string_value_cstr(mrb, &key);

  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));

  /* Invocation */
  apr_status_t result = apr_socket_data_get(native_data, native_key, native_sock);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_socket_data_set_FUNCTION
#define apr_socket_data_set_REQUIRED_ARGC 5
#define apr_socket_data_set_OPTIONAL_ARGC 0
/* apr_socket_data_set
 *
 * Parameters:
 * - sock: apr_socket_t *
 * - data: void *
 * - key: const char *
 * - cleanup: int (*)(void *)
 * - arg5: void *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_socket_data_set(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value data;
  mrb_value key;
  mrb_value cleanup;
  mrb_value arg5;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &sock, &data, &key, &cleanup, &arg5);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(data);
  if (!mrb_obj_is_kind_of(mrb, key, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(cleanup);
  TODO_type_check_void_PTR(arg5);


  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));

  void * native_data = TODO_mruby_unbox_void_PTR(data);

  const char * native_key = mrb_string_value_cstr(mrb, &key);

  int (*native_cleanup)(void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(cleanup);

  void * native_arg5 = TODO_mruby_unbox_void_PTR(arg5);

  /* Invocation */
  apr_status_t result = apr_socket_data_set(native_sock, native_data, native_key, native_cleanup, native_arg5);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_socket_listen_FUNCTION
#define apr_socket_listen_REQUIRED_ARGC 2
#define apr_socket_listen_OPTIONAL_ARGC 0
/* apr_socket_listen
 *
 * Parameters:
 * - sock: apr_socket_t *
 * - backlog: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_socket_listen(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value backlog;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sock, &backlog);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, backlog, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));
  int native_backlog = mrb_fixnum(backlog);

  /* Invocation */
  apr_status_t result = apr_socket_listen(native_sock, native_backlog);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_socket_opt_get_FUNCTION
#define apr_socket_opt_get_REQUIRED_ARGC 2
#define apr_socket_opt_get_OPTIONAL_ARGC 0
/* apr_socket_opt_get
 *
 * Parameters:
 * - sock: apr_socket_t *
 * - opt: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_socket_opt_get(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value opt;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sock, &opt);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, opt, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));
  apr_int32_t native_opt = mrb_fixnum(opt);

  /* Invocation */
  apr_int32_t native_on = 0;
  apr_status_t result = apr_socket_opt_get(native_sock, native_opt, &native_on);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  RETURN_ERRNO_AND_OUTPUT(result, mrb_fixnum_value(native_on));
}
#endif

#if BIND_apr_socket_opt_set_FUNCTION
#define apr_socket_opt_set_REQUIRED_ARGC 3
#define apr_socket_opt_set_OPTIONAL_ARGC 0
/* apr_socket_opt_set
 *
 * Parameters:
 * - sock: apr_socket_t *
 * - opt: int
 * - on: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_socket_opt_set(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value opt;
  mrb_value on;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &sock, &opt, &on);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, opt, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, on, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));
  int native_opt = mrb_fixnum(opt);
  int native_on = mrb_fixnum(on);

  /* Invocation */
  apr_status_t result = apr_socket_opt_set(native_sock, native_opt, native_on);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_socket_protocol_get_FUNCTION
#define apr_socket_protocol_get_REQUIRED_ARGC 1
#define apr_socket_protocol_get_OPTIONAL_ARGC 0
/* apr_socket_protocol_get
 *
 * Parameters:
 * - sock: apr_socket_t *
 * Return Type: [errno: Fixnum, protocol: Fixnum]
 */
mrb_value
mrb_APR_apr_socket_protocol_get(mrb_state* mrb, mrb_value self) {
  mrb_value sock;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &sock);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));

  /* Invocation */
  int native_protocol;
  apr_status_t result = apr_socket_protocol_get(native_sock, &native_protocol);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  RETURN_ERRNO_AND_OUTPUT(result, mrb_fixnum_value(native_protocol));
}
#endif

#if BIND_apr_socket_recv_FUNCTION
#define apr_socket_recv_REQUIRED_ARGC 2
#define apr_socket_recv_OPTIONAL_ARGC 0
/* apr_socket_recv
 *
 * Parameters:
 * - sock: AprSocketT
 * - len: Fixnum
 * Return Type: [errno: Fixnum, message: String]
 */
mrb_value
mrb_APR_apr_socket_recv(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value len;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sock, &len);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, len, mrb->fixnum_class)) {
     mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
     return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));
  apr_size_t native_len = mrb_fixnum(len);

  /* Invocation */
  char * native_buf = (char*)malloc(native_len);
  apr_status_t result = apr_socket_recv(native_sock, native_buf, &native_len);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }

  mrb_value result_string = mrb_str_new(mrb, native_buf, native_len);
  free(native_buf);
  native_buf = NULL;

  mrb_value results = mrb_ary_new(mrb);
  mrb_ary_push(mrb, results, mrb_fixnum_value(result));
  /* There can be an error, such as EOF, and still have bytes read, so always return this string. */
  mrb_ary_push(mrb, results, result_string);

  return results;
}
#endif

#if BIND_apr_socket_recvfrom_FUNCTION
#define apr_socket_recvfrom_REQUIRED_ARGC 3
#define apr_socket_recvfrom_OPTIONAL_ARGC 0
/* apr_socket_recvfrom
 *
 * Parameters:
 * - sock: AprSocketT
 * - flags: Fixnum
 * - len: Fixnum
 * Return Type: [errno: Fixnum, from: AprSocketT, buffer: String]
 */
mrb_value
mrb_APR_apr_socket_recvfrom(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value flags;
  mrb_value len;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &sock, &flags, &len);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, len, mrb->fixnum_class)) {
     mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
     return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));
  int native_flags = mrb_fixnum(flags);
  apr_size_t native_len = mrb_fixnum(len);

  /* Invocation */
  char * native_buf = (char*)malloc(sizeof(char)*native_len); /* to free after duplicating via mrb_str_new */
  apr_sockaddr_t * native_from = (apr_sockaddr_t*)malloc(sizeof(apr_sockaddr_t)); /* to free in mrb GC (giftwrapped pointer) */
  apr_status_t result = apr_socket_recvfrom(native_from, native_sock, native_flags, native_buf, &native_len);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  mrb_value buffer = mrb_str_new(mrb, native_buf, native_len);
  free(native_buf);
  native_buf = NULL;

  mrb_value from = mruby_giftwrap_apr_sockaddr_t(mrb, native_from);

  mrb_value results = mrb_ary_new(mrb);
  mrb_ary_push(mrb, results, return_value);
  mrb_ary_push(mrb, results, from);
  mrb_ary_push(mrb, results, buffer);

  return results;
}
#endif

#if BIND_apr_socket_send_FUNCTION
#define apr_socket_send_REQUIRED_ARGC 3
#define apr_socket_send_OPTIONAL_ARGC 0
/* apr_socket_send
 *
 * Parameters:
 * - sock: AprSocketT
 * - buf: String
 * - len: Fixnum
 * Return Type: [errno: Fixnum, bytes_sent: Fixnum]
 */
mrb_value
mrb_APR_apr_socket_send(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value buf;
  mrb_value len;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &sock, &buf, &len);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, buf, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, len, mrb->fixnum_class)) {
     mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
     return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));
  const char * native_buf = mrb_string_value_ptr(mrb, buf);
  apr_size_t native_len = mrb_fixnum(len);

  /* Invocation */
  apr_status_t result = apr_socket_send(native_sock, native_buf, &native_len);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  RETURN_ERRNO_AND_OUTPUT(result, mrb_fixnum_value(native_len));
}
#endif

#if BIND_apr_socket_sendfile_FUNCTION
#define apr_socket_sendfile_REQUIRED_ARGC 6
#define apr_socket_sendfile_OPTIONAL_ARGC 0
/* apr_socket_sendfile
 *
 * Parameters:
 * - sock: apr_socket_t *
 * - file: apr_file_t *
 * - hdtr: apr_hdtr_t *
 * - offset: long long *
 * - len: int *
 * - flags: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_socket_sendfile(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value file;
  mrb_value hdtr;
  mrb_value offset;
  mrb_value len;
  mrb_value flags;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooo", &sock, &file, &hdtr, &offset, &len, &flags);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, file, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, hdtr, AprHdtrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprHdtrT expected");
    return mrb_nil_value();
  }
  TODO_type_check_long_long_PTR(offset);
  TODO_type_check_int_PTR(len);
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));

  apr_file_t * native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_apr_file_t(file));

  apr_hdtr_t * native_hdtr = (mrb_nil_p(hdtr) ? NULL : mruby_unbox_apr_hdtr_t(hdtr));

  long long * native_offset = TODO_mruby_unbox_long_long_PTR(offset);

  int * native_len = TODO_mruby_unbox_int_PTR(len);

  int native_flags = mrb_fixnum(flags);

  /* Invocation */
  apr_status_t result = apr_socket_sendfile(native_sock, native_file, native_hdtr, native_offset, native_len, native_flags);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_socket_sendto_FUNCTION
#define apr_socket_sendto_REQUIRED_ARGC 5
#define apr_socket_sendto_OPTIONAL_ARGC 0
/* apr_socket_sendto
 *
 * Parameters:
 * - sock: apr_socket_t *
 * - where: apr_sockaddr_t *
 * - flags: int
 * - buf: const char *
 * - len: int *
 * Return Type: errno: Fixnum, bytes_written: Fixnum
 */
mrb_value
mrb_APR_apr_socket_sendto(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value where;
  mrb_value flags;
  mrb_value buf;
  mrb_value len;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &sock, &where, &flags, &buf, &len);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, where, AprSockaddrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSockaddrT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, buf, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, len, mrb->fixnum_class)) {
     mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
     return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));
  apr_sockaddr_t * native_where = (mrb_nil_p(where) ? NULL : mruby_unbox_apr_sockaddr_t(where));
  int native_flags = mrb_fixnum(flags);
  const char * native_buf = mrb_string_value_cstr(mrb, &buf);
  apr_size_t native_len = mrb_fixnum(len);

  /* Invocation */
  apr_status_t result = apr_socket_sendto(native_sock, native_where, native_flags, native_buf, &native_len);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }

  RETURN_ERRNO_AND_OUTPUT(result, mrb_fixnum_value(native_len));
}
#endif

#if BIND_apr_socket_sendv_FUNCTION
#define apr_socket_sendv_REQUIRED_ARGC 4
#define apr_socket_sendv_OPTIONAL_ARGC 0
/* apr_socket_sendv
 *
 * Parameters:
 * - sock: apr_socket_t *
 * - vec: const iovec *
 * - nvec: int
 * - len: int *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_socket_sendv(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value vec;
  mrb_value nvec;
  mrb_value len;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &sock, &vec, &nvec, &len);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_iovec_PTR(vec);
  if (!mrb_obj_is_kind_of(mrb, nvec, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(len);


  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));

  const iovec * native_vec = TODO_mruby_unbox_const_iovec_PTR(vec);

  int native_nvec = mrb_fixnum(nvec);

  int * native_len = TODO_mruby_unbox_int_PTR(len);

  /* Invocation */
  apr_status_t result = apr_socket_sendv(native_sock, native_vec, native_nvec, native_len);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_socket_shutdown_FUNCTION
#define apr_socket_shutdown_REQUIRED_ARGC 2
#define apr_socket_shutdown_OPTIONAL_ARGC 0
/* apr_socket_shutdown
 *
 * Parameters:
 * - thesocket: apr_socket_t *
 * - how: apr_shutdown_how_e
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_socket_shutdown(mrb_state* mrb, mrb_value self) {
  mrb_value thesocket;
  mrb_value how;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &thesocket, &how);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, thesocket, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, how, mrb->fixnum_class)) {
     mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
     return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_socket_t * native_thesocket = (mrb_nil_p(thesocket) ? NULL : mruby_unbox_apr_socket_t(thesocket));
  apr_shutdown_how_e native_how = (apr_shutdown_how_e)mrb_fixnum(how);

  /* Invocation */
  apr_status_t result = apr_socket_shutdown(native_thesocket, native_how);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_socket_timeout_get_FUNCTION
#define apr_socket_timeout_get_REQUIRED_ARGC 2
#define apr_socket_timeout_get_OPTIONAL_ARGC 0
/* apr_socket_timeout_get
 *
 * Parameters:
 * - sock: apr_socket_t *
 * Return Type: [errno: Fixnum, timeout: Fixnum]
 */
mrb_value
mrb_APR_apr_socket_timeout_get(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value t;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &sock);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));

  /* Invocation */
  apr_interval_time_t native_t;
  apr_status_t result = apr_socket_timeout_get(native_sock, &native_t);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  if (native_t > MRB_INT_MAX) {
     mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
     return mrb_nil_value();
  }
  RETURN_ERRNO_AND_OUTPUT(result, mrb_fixnum_value(native_t));
}
#endif

#if BIND_apr_socket_timeout_set_FUNCTION
#define apr_socket_timeout_set_REQUIRED_ARGC 2
#define apr_socket_timeout_set_OPTIONAL_ARGC 0
/* apr_socket_timeout_set
 *
 * Parameters:
 * - sock: apr_socket_t *
 * - t: long long
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_socket_timeout_set(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value t;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sock, &t);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, t, mrb->fixnum_class)) {
     mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
     return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));
  apr_interval_time_t native_t = mrb_fixnum(t);

  /* Invocation */
  apr_status_t result = apr_socket_timeout_set(native_sock, native_t);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_socket_type_get_FUNCTION
#define apr_socket_type_get_REQUIRED_ARGC 2
#define apr_socket_type_get_OPTIONAL_ARGC 0
/* apr_socket_type_get
 *
 * Parameters:
 * - sock: apr_socket_t *
 * - type: int *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_socket_type_get(mrb_state* mrb, mrb_value self) {
  mrb_value sock;
  mrb_value type;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &sock, &type);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, sock, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, type, mrb->fixnum_class)) {
     mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
     return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_socket_t * native_sock = (mrb_nil_p(sock) ? NULL : mruby_unbox_apr_socket_t(sock));
  int native_type = mrb_fixnum(type);

  /* Invocation */
  apr_status_t result = apr_socket_type_get(native_sock, &native_type);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  RETURN_ERRNO_AND_OUTPUT(result, mrb_fixnum_value(native_type));
}
#endif

#if BIND_apr_stat_FUNCTION
#define apr_stat_REQUIRED_ARGC 4
#define apr_stat_OPTIONAL_ARGC 0
/* apr_stat
 *
 * Parameters:
 * - finfo: apr_finfo_t *
 * - fname: const char *
 * - wanted: int
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_stat(mrb_state* mrb, mrb_value self) {
  mrb_value finfo;
  mrb_value fname;
  mrb_value wanted;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &finfo, &fname, &wanted, &pool);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, finfo, AprFinfoT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFinfoT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, fname, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, wanted, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_finfo_t * native_finfo = (mrb_nil_p(finfo) ? NULL : mruby_unbox_apr_finfo_t(finfo));

  const char * native_fname = mrb_string_value_cstr(mrb, &fname);

  int native_wanted = mrb_fixnum(wanted);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_stat(native_finfo, native_fname, native_wanted, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_strerror_FUNCTION
#define apr_strerror_REQUIRED_ARGC 1
#define apr_strerror_OPTIONAL_ARGC 0
/* apr_strerror
 *
 * Parameters:
 * - statcode: Fixnum
 * Return Type: String
 */
mrb_value
mrb_APR_apr_strerror(mrb_state* mrb, mrb_value self) {
  mrb_value statcode;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &statcode);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, statcode, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  int native_statcode = mrb_fixnum(statcode);

  /* Invocation */
  char*  native_buf = (char*)malloc(100);
  char * result = apr_strerror(native_statcode, native_buf, 100);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  free(native_buf);
  native_buf = NULL;

  return return_value;
}
#endif

#if BIND_apr_to_os_error_FUNCTION
#define apr_to_os_error_REQUIRED_ARGC 1
#define apr_to_os_error_OPTIONAL_ARGC 0
mrb_value
mrb_APR_apr_to_os_error(mrb_state *mrb, mrb_value self) {
  mrb_int apr_errno;
  mrb_get_args(mrb, "i", &apr_errno);
  int os_errno = APR_TO_OS_ERROR(apr_errno);
  return mrb_fixnum_value(os_errno);
}
#endif

#if BIND_apr_strfsize_FUNCTION
#define apr_strfsize_REQUIRED_ARGC 2
#define apr_strfsize_OPTIONAL_ARGC 0
/* apr_strfsize
 *
 * Parameters:
 * - size: long long
 * - buf: char *
 * Return Type: char *
 */
mrb_value
mrb_APR_apr_strfsize(mrb_state* mrb, mrb_value self) {
  mrb_value size;
  mrb_value buf;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &size, &buf);


  /* Type checking */
  TODO_type_check_long_long(size);
  if (!mrb_obj_is_kind_of(mrb, buf, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  long long native_size = TODO_mruby_unbox_long_long(size);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_buf = strdup(mrb_string_value_cstr(mrb, &buf));

  /* Invocation */
  char * result = apr_strfsize(native_size, native_buf);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_buf);
  native_buf = NULL;

  return return_value;
}
#endif

#if BIND_apr_strftime_FUNCTION
#define apr_strftime_REQUIRED_ARGC 5
#define apr_strftime_OPTIONAL_ARGC 0
/* apr_strftime
 *
 * Parameters:
 * - s: char *
 * - retsize: int *
 * - max: int
 * - format: const char *
 * - tm: apr_time_exp_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_strftime(mrb_state* mrb, mrb_value self) {
  mrb_value s;
  mrb_value retsize;
  mrb_value max;
  mrb_value format;
  mrb_value tm;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &s, &retsize, &max, &format, &tm);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(retsize);
  if (!mrb_obj_is_kind_of(mrb, max, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, format, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, tm, AprTimeExpT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTimeExpT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_s = strdup(mrb_string_value_cstr(mrb, &s));

  int * native_retsize = TODO_mruby_unbox_int_PTR(retsize);

  int native_max = mrb_fixnum(max);

  const char * native_format = mrb_string_value_cstr(mrb, &format);

  apr_time_exp_t * native_tm = (mrb_nil_p(tm) ? NULL : mruby_unbox_apr_time_exp_t(tm));

  /* Invocation */
  apr_status_t result = apr_strftime(native_s, native_retsize, native_max, native_format, native_tm);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_s);
  native_s = NULL;

  return return_value;
}
#endif

#if BIND_apr_strnatcasecmp_FUNCTION
#define apr_strnatcasecmp_REQUIRED_ARGC 2
#define apr_strnatcasecmp_OPTIONAL_ARGC 0
/* apr_strnatcasecmp
 *
 * Parameters:
 * - a: const char *
 * - b: const char *
 * Return Type: int
 */
mrb_value
mrb_APR_apr_strnatcasecmp(mrb_state* mrb, mrb_value self) {
  mrb_value a;
  mrb_value b;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &a, &b);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, a, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, b, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_a = mrb_string_value_cstr(mrb, &a);

  const char * native_b = mrb_string_value_cstr(mrb, &b);

  /* Invocation */
  int result = apr_strnatcasecmp(native_a, native_b);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_strnatcmp_FUNCTION
#define apr_strnatcmp_REQUIRED_ARGC 2
#define apr_strnatcmp_OPTIONAL_ARGC 0
/* apr_strnatcmp
 *
 * Parameters:
 * - a: const char *
 * - b: const char *
 * Return Type: int
 */
mrb_value
mrb_APR_apr_strnatcmp(mrb_state* mrb, mrb_value self) {
  mrb_value a;
  mrb_value b;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &a, &b);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, a, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, b, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_a = mrb_string_value_cstr(mrb, &a);

  const char * native_b = mrb_string_value_cstr(mrb, &b);

  /* Invocation */
  int result = apr_strnatcmp(native_a, native_b);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_strtoff_FUNCTION
#define apr_strtoff_REQUIRED_ARGC 4
#define apr_strtoff_OPTIONAL_ARGC 0
/* apr_strtoff
 *
 * Parameters:
 * - offset: long long *
 * - buf: const char *
 * - end: char **
 * - base: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_strtoff(mrb_state* mrb, mrb_value self) {
  mrb_value offset;
  mrb_value buf;
  mrb_value end;
  mrb_value base;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &offset, &buf, &end, &base);


  /* Type checking */
  TODO_type_check_long_long_PTR(offset);
  if (!mrb_obj_is_kind_of(mrb, buf, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_char_PTR_PTR(end);
  if (!mrb_obj_is_kind_of(mrb, base, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  long long * native_offset = TODO_mruby_unbox_long_long_PTR(offset);

  const char * native_buf = mrb_string_value_cstr(mrb, &buf);

  char ** native_end = TODO_mruby_unbox_char_PTR_PTR(end);

  int native_base = mrb_fixnum(base);

  /* Invocation */
  apr_status_t result = apr_strtoff(native_offset, native_buf, native_end, native_base);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_strtoi64_FUNCTION
#define apr_strtoi64_REQUIRED_ARGC 3
#define apr_strtoi64_OPTIONAL_ARGC 0
/* apr_strtoi64
 *
 * Parameters:
 * - buf: const char *
 * - end: char **
 * - base: int
 * Return Type: apr_int64_t
 */
mrb_value
mrb_APR_apr_strtoi64(mrb_state* mrb, mrb_value self) {
  mrb_value buf;
  mrb_value end;
  mrb_value base;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &buf, &end, &base);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, buf, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_char_PTR_PTR(end);
  if (!mrb_obj_is_kind_of(mrb, base, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_buf = mrb_string_value_cstr(mrb, &buf);

  char ** native_end = TODO_mruby_unbox_char_PTR_PTR(end);

  int native_base = mrb_fixnum(base);

  /* Invocation */
  apr_int64_t result = apr_strtoi64(native_buf, native_end, native_base);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_long_long(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_strtok_FUNCTION
#define apr_strtok_REQUIRED_ARGC 3
#define apr_strtok_OPTIONAL_ARGC 0
/* apr_strtok
 *
 * Parameters:
 * - str: char *
 * - sep: const char *
 * - last: char **
 * Return Type: char *
 */
mrb_value
mrb_APR_apr_strtok(mrb_state* mrb, mrb_value self) {
  mrb_value str;
  mrb_value sep;
  mrb_value last;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &str, &sep, &last);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, str, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, sep, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_char_PTR_PTR(last);


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_str = strdup(mrb_string_value_cstr(mrb, &str));

  const char * native_sep = mrb_string_value_cstr(mrb, &sep);

  char ** native_last = TODO_mruby_unbox_char_PTR_PTR(last);

  /* Invocation */
  char * result = apr_strtok(native_str, native_sep, native_last);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_str);
  native_str = NULL;

  return return_value;
}
#endif

#if BIND_apr_table_add_FUNCTION
#define apr_table_add_REQUIRED_ARGC 3
#define apr_table_add_OPTIONAL_ARGC 0
/* apr_table_add
 *
 * Parameters:
 * - t: apr_table_t *
 * - key: const char *
 * - val: const char *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_table_add(mrb_state* mrb, mrb_value self) {
  mrb_value t;
  mrb_value key;
  mrb_value val;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &t, &key, &val);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, t, AprTableT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTableT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, key, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, val, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_table_t * native_t = (mrb_nil_p(t) ? NULL : mruby_unbox_apr_table_t(t));

  const char * native_key = mrb_string_value_cstr(mrb, &key);

  const char * native_val = mrb_string_value_cstr(mrb, &val);

  /* Invocation */
  apr_table_add(native_t, native_key, native_val);

  return mrb_nil_value();
}
#endif

#if BIND_apr_table_addn_FUNCTION
#define apr_table_addn_REQUIRED_ARGC 3
#define apr_table_addn_OPTIONAL_ARGC 0
/* apr_table_addn
 *
 * Parameters:
 * - t: apr_table_t *
 * - key: const char *
 * - val: const char *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_table_addn(mrb_state* mrb, mrb_value self) {
  mrb_value t;
  mrb_value key;
  mrb_value val;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &t, &key, &val);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, t, AprTableT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTableT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, key, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, val, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_table_t * native_t = (mrb_nil_p(t) ? NULL : mruby_unbox_apr_table_t(t));

  const char * native_key = mrb_string_value_cstr(mrb, &key);

  const char * native_val = mrb_string_value_cstr(mrb, &val);

  /* Invocation */
  apr_table_addn(native_t, native_key, native_val);

  return mrb_nil_value();
}
#endif

#if BIND_apr_table_clear_FUNCTION
#define apr_table_clear_REQUIRED_ARGC 1
#define apr_table_clear_OPTIONAL_ARGC 0
/* apr_table_clear
 *
 * Parameters:
 * - t: apr_table_t *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_table_clear(mrb_state* mrb, mrb_value self) {
  mrb_value t;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &t);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, t, AprTableT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTableT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_table_t * native_t = (mrb_nil_p(t) ? NULL : mruby_unbox_apr_table_t(t));

  /* Invocation */
  apr_table_clear(native_t);

  return mrb_nil_value();
}
#endif

#if BIND_apr_table_clone_FUNCTION
#define apr_table_clone_REQUIRED_ARGC 2
#define apr_table_clone_OPTIONAL_ARGC 0
/* apr_table_clone
 *
 * Parameters:
 * - p: apr_pool_t *
 * - t: const apr_table_t *
 * Return Type: apr_table_t *
 */
mrb_value
mrb_APR_apr_table_clone(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value t;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &p, &t);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, t, AprTableT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTableT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const apr_table_t * native_t = (mrb_nil_p(t) ? NULL : mruby_unbox_const apr_table_t(t));

  /* Invocation */
  apr_table_t * result = apr_table_clone(native_p, native_t);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_table_t(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_table_compress_FUNCTION
#define apr_table_compress_REQUIRED_ARGC 2
#define apr_table_compress_OPTIONAL_ARGC 0
/* apr_table_compress
 *
 * Parameters:
 * - t: apr_table_t *
 * - flags: unsigned int
 * Return Type: void
 */
mrb_value
mrb_APR_apr_table_compress(mrb_state* mrb, mrb_value self) {
  mrb_value t;
  mrb_value flags;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &t, &flags);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, t, AprTableT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTableT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_table_t * native_t = (mrb_nil_p(t) ? NULL : mruby_unbox_apr_table_t(t));

  unsigned int native_flags = mrb_fixnum(flags);

  /* Invocation */
  apr_table_compress(native_t, native_flags);

  return mrb_nil_value();
}
#endif

#if BIND_apr_table_copy_FUNCTION
#define apr_table_copy_REQUIRED_ARGC 2
#define apr_table_copy_OPTIONAL_ARGC 0
/* apr_table_copy
 *
 * Parameters:
 * - p: apr_pool_t *
 * - t: const apr_table_t *
 * Return Type: apr_table_t *
 */
mrb_value
mrb_APR_apr_table_copy(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value t;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &p, &t);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, t, AprTableT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTableT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const apr_table_t * native_t = (mrb_nil_p(t) ? NULL : mruby_unbox_const apr_table_t(t));

  /* Invocation */
  apr_table_t * result = apr_table_copy(native_p, native_t);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_table_t(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_table_do_FUNCTION
#define apr_table_do_REQUIRED_ARGC 3
#define apr_table_do_OPTIONAL_ARGC 0
/* apr_table_do
 *
 * Parameters:
 * - comp: int (*)(void *, const char *, const char *)
 * - rec: void *
 * - t: const apr_table_t *
 * Return Type: int
 */
mrb_value
mrb_APR_apr_table_do(mrb_state* mrb, mrb_value self) {
  mrb_value comp;
  mrb_value rec;
  mrb_value t;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &comp, &rec, &t);


  /* Type checking */
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_const_char_PTR_COMMA_const_char_PTR_RPAREN(comp);
  TODO_type_check_void_PTR(rec);
  if (!mrb_obj_is_kind_of(mrb, t, AprTableT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTableT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int (*native_comp)(void *, const char *, const char *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_const_char_PTR_COMMA_const_char_PTR_RPAREN(comp);

  void * native_rec = TODO_mruby_unbox_void_PTR(rec);

  const apr_table_t * native_t = (mrb_nil_p(t) ? NULL : mruby_unbox_const apr_table_t(t));

  /* Invocation */
  int result = apr_table_do(native_comp, native_rec, native_t);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_table_elts_FUNCTION
#define apr_table_elts_REQUIRED_ARGC 1
#define apr_table_elts_OPTIONAL_ARGC 0
/* apr_table_elts
 *
 * Parameters:
 * - t: const apr_table_t *
 * Return Type: const apr_array_header_t *
 */
mrb_value
mrb_APR_apr_table_elts(mrb_state* mrb, mrb_value self) {
  mrb_value t;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &t);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, t, AprTableT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTableT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const apr_table_t * native_t = (mrb_nil_p(t) ? NULL : mruby_unbox_const apr_table_t(t));

  /* Invocation */
  const apr_array_header_t * result = apr_table_elts(native_t);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_const apr_array_header_t(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_table_get_FUNCTION
#define apr_table_get_REQUIRED_ARGC 2
#define apr_table_get_OPTIONAL_ARGC 0
/* apr_table_get
 *
 * Parameters:
 * - t: const apr_table_t *
 * - key: const char *
 * Return Type: const char *
 */
mrb_value
mrb_APR_apr_table_get(mrb_state* mrb, mrb_value self) {
  mrb_value t;
  mrb_value key;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &t, &key);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, t, AprTableT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTableT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, key, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const apr_table_t * native_t = (mrb_nil_p(t) ? NULL : mruby_unbox_const apr_table_t(t));

  const char * native_key = mrb_string_value_cstr(mrb, &key);

  /* Invocation */
  const char * result = apr_table_get(native_t, native_key);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_table_getm_FUNCTION
#define apr_table_getm_REQUIRED_ARGC 3
#define apr_table_getm_OPTIONAL_ARGC 0
/* apr_table_getm
 *
 * Parameters:
 * - p: apr_pool_t *
 * - t: const apr_table_t *
 * - key: const char *
 * Return Type: const char *
 */
mrb_value
mrb_APR_apr_table_getm(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value t;
  mrb_value key;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &p, &t, &key);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, t, AprTableT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTableT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, key, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const apr_table_t * native_t = (mrb_nil_p(t) ? NULL : mruby_unbox_const apr_table_t(t));

  const char * native_key = mrb_string_value_cstr(mrb, &key);

  /* Invocation */
  const char * result = apr_table_getm(native_p, native_t, native_key);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_table_make_FUNCTION
#define apr_table_make_REQUIRED_ARGC 2
#define apr_table_make_OPTIONAL_ARGC 0
/* apr_table_make
 *
 * Parameters:
 * - p: apr_pool_t *
 * - nelts: int
 * Return Type: apr_table_t *
 */
mrb_value
mrb_APR_apr_table_make(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value nelts;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &p, &nelts);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, nelts, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  int native_nelts = mrb_fixnum(nelts);

  /* Invocation */
  apr_table_t * result = apr_table_make(native_p, native_nelts);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_table_t(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_table_merge_FUNCTION
#define apr_table_merge_REQUIRED_ARGC 3
#define apr_table_merge_OPTIONAL_ARGC 0
/* apr_table_merge
 *
 * Parameters:
 * - t: apr_table_t *
 * - key: const char *
 * - val: const char *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_table_merge(mrb_state* mrb, mrb_value self) {
  mrb_value t;
  mrb_value key;
  mrb_value val;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &t, &key, &val);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, t, AprTableT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTableT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, key, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, val, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_table_t * native_t = (mrb_nil_p(t) ? NULL : mruby_unbox_apr_table_t(t));

  const char * native_key = mrb_string_value_cstr(mrb, &key);

  const char * native_val = mrb_string_value_cstr(mrb, &val);

  /* Invocation */
  apr_table_merge(native_t, native_key, native_val);

  return mrb_nil_value();
}
#endif

#if BIND_apr_table_mergen_FUNCTION
#define apr_table_mergen_REQUIRED_ARGC 3
#define apr_table_mergen_OPTIONAL_ARGC 0
/* apr_table_mergen
 *
 * Parameters:
 * - t: apr_table_t *
 * - key: const char *
 * - val: const char *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_table_mergen(mrb_state* mrb, mrb_value self) {
  mrb_value t;
  mrb_value key;
  mrb_value val;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &t, &key, &val);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, t, AprTableT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTableT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, key, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, val, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_table_t * native_t = (mrb_nil_p(t) ? NULL : mruby_unbox_apr_table_t(t));

  const char * native_key = mrb_string_value_cstr(mrb, &key);

  const char * native_val = mrb_string_value_cstr(mrb, &val);

  /* Invocation */
  apr_table_mergen(native_t, native_key, native_val);

  return mrb_nil_value();
}
#endif

#if BIND_apr_table_overlap_FUNCTION
#define apr_table_overlap_REQUIRED_ARGC 3
#define apr_table_overlap_OPTIONAL_ARGC 0
/* apr_table_overlap
 *
 * Parameters:
 * - a: apr_table_t *
 * - b: const apr_table_t *
 * - flags: unsigned int
 * Return Type: void
 */
mrb_value
mrb_APR_apr_table_overlap(mrb_state* mrb, mrb_value self) {
  mrb_value a;
  mrb_value b;
  mrb_value flags;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &a, &b, &flags);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, a, AprTableT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTableT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, b, AprTableT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTableT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_table_t * native_a = (mrb_nil_p(a) ? NULL : mruby_unbox_apr_table_t(a));

  const apr_table_t * native_b = (mrb_nil_p(b) ? NULL : mruby_unbox_const apr_table_t(b));

  unsigned int native_flags = mrb_fixnum(flags);

  /* Invocation */
  apr_table_overlap(native_a, native_b, native_flags);

  return mrb_nil_value();
}
#endif

#if BIND_apr_table_overlay_FUNCTION
#define apr_table_overlay_REQUIRED_ARGC 6
#define apr_table_overlay_OPTIONAL_ARGC 0
/* apr_table_overlay
 *
 * Parameters:
 * - p: apr_pool_t *
 * - overlay: const apr_table_t *
 * - base: const apr_table_t *
 * - rec: void *
 * - key: const char *
 * - value: const char *
 * Return Type: apr_table_t *
 */
mrb_value
mrb_APR_apr_table_overlay(mrb_state* mrb, mrb_value self) {
  mrb_value p;
  mrb_value overlay;
  mrb_value base;
  mrb_value rec;
  mrb_value key;
  mrb_value value;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooo", &p, &overlay, &base, &rec, &key, &value);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, overlay, AprTableT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTableT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, base, AprTableT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTableT expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(rec);
  if (!mrb_obj_is_kind_of(mrb, key, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, value, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  const apr_table_t * native_overlay = (mrb_nil_p(overlay) ? NULL : mruby_unbox_const apr_table_t(overlay));

  const apr_table_t * native_base = (mrb_nil_p(base) ? NULL : mruby_unbox_const apr_table_t(base));

  void * native_rec = TODO_mruby_unbox_void_PTR(rec);

  const char * native_key = mrb_string_value_cstr(mrb, &key);

  const char * native_value = mrb_string_value_cstr(mrb, &value);

  /* Invocation */
  apr_table_t * result = apr_table_overlay(native_p, native_overlay, native_base, native_rec, native_key, native_value);

  /* Box the return value */
  mrb_value return_value = (result == NULL ? mrb_nil_value() : mruby_box_apr_table_t(mrb, result));

  return return_value;
}
#endif

#if BIND_apr_table_set_FUNCTION
#define apr_table_set_REQUIRED_ARGC 3
#define apr_table_set_OPTIONAL_ARGC 0
/* apr_table_set
 *
 * Parameters:
 * - t: apr_table_t *
 * - key: const char *
 * - val: const char *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_table_set(mrb_state* mrb, mrb_value self) {
  mrb_value t;
  mrb_value key;
  mrb_value val;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &t, &key, &val);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, t, AprTableT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTableT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, key, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, val, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_table_t * native_t = (mrb_nil_p(t) ? NULL : mruby_unbox_apr_table_t(t));

  const char * native_key = mrb_string_value_cstr(mrb, &key);

  const char * native_val = mrb_string_value_cstr(mrb, &val);

  /* Invocation */
  apr_table_set(native_t, native_key, native_val);

  return mrb_nil_value();
}
#endif

#if BIND_apr_table_setn_FUNCTION
#define apr_table_setn_REQUIRED_ARGC 3
#define apr_table_setn_OPTIONAL_ARGC 0
/* apr_table_setn
 *
 * Parameters:
 * - t: apr_table_t *
 * - key: const char *
 * - val: const char *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_table_setn(mrb_state* mrb, mrb_value self) {
  mrb_value t;
  mrb_value key;
  mrb_value val;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &t, &key, &val);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, t, AprTableT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTableT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, key, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, val, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_table_t * native_t = (mrb_nil_p(t) ? NULL : mruby_unbox_apr_table_t(t));

  const char * native_key = mrb_string_value_cstr(mrb, &key);

  const char * native_val = mrb_string_value_cstr(mrb, &val);

  /* Invocation */
  apr_table_setn(native_t, native_key, native_val);

  return mrb_nil_value();
}
#endif

#if BIND_apr_table_unset_FUNCTION
#define apr_table_unset_REQUIRED_ARGC 2
#define apr_table_unset_OPTIONAL_ARGC 0
/* apr_table_unset
 *
 * Parameters:
 * - t: apr_table_t *
 * - key: const char *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_table_unset(mrb_state* mrb, mrb_value self) {
  mrb_value t;
  mrb_value key;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &t, &key);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, t, AprTableT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTableT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, key, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_table_t * native_t = (mrb_nil_p(t) ? NULL : mruby_unbox_apr_table_t(t));

  const char * native_key = mrb_string_value_cstr(mrb, &key);

  /* Invocation */
  apr_table_unset(native_t, native_key);

  return mrb_nil_value();
}
#endif

#if BIND_apr_table_vdo_FUNCTION
#define apr_table_vdo_REQUIRED_ARGC 4
#define apr_table_vdo_OPTIONAL_ARGC 0
/* apr_table_vdo
 *
 * Parameters:
 * - comp: int (*)(void *, const char *, const char *)
 * - rec: void *
 * - t: const apr_table_t *
 * - vp: int
 * Return Type: int
 */
mrb_value
mrb_APR_apr_table_vdo(mrb_state* mrb, mrb_value self) {
  mrb_value comp;
  mrb_value rec;
  mrb_value t;
  mrb_value vp;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &comp, &rec, &t, &vp);


  /* Type checking */
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_const_char_PTR_COMMA_const_char_PTR_RPAREN(comp);
  TODO_type_check_void_PTR(rec);
  if (!mrb_obj_is_kind_of(mrb, t, AprTableT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTableT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, vp, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int (*native_comp)(void *, const char *, const char *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_const_char_PTR_COMMA_const_char_PTR_RPAREN(comp);

  void * native_rec = TODO_mruby_unbox_void_PTR(rec);

  const apr_table_t * native_t = (mrb_nil_p(t) ? NULL : mruby_unbox_const apr_table_t(t));

  int native_vp = mrb_fixnum(vp);

  /* Invocation */
  int result = apr_table_vdo(native_comp, native_rec, native_t, native_vp);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_temp_dir_get_FUNCTION
#define apr_temp_dir_get_REQUIRED_ARGC 1
#define apr_temp_dir_get_OPTIONAL_ARGC 0
/* apr_temp_dir_get
 *
 * Parameters:
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_temp_dir_get(mrb_state* mrb, mrb_value self) {
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &p);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  const char* native_temp_dir;
  apr_status_t result = apr_temp_dir_get(&native_temp_dir, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  mrb_value results = mrb_ary_new(mrb);
  mrb_ary_push(mrb, results, return_value);
  if (result == 0) {
     mrb_ary_push(mrb, results, mrb_str_new_cstr(mrb, native_temp_dir));
  }
  else {
     mrb_ary_push(mrb, results, mrb_nil_value());
  }

  return results;
}
#endif

#if BIND_apr_terminate_FUNCTION
#define apr_terminate_REQUIRED_ARGC 0
#define apr_terminate_OPTIONAL_ARGC 0
/* apr_terminate
 *
 * Parameters: None
 * Return Type: void
 */
mrb_value
mrb_APR_apr_terminate(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  apr_terminate();

  return mrb_nil_value();
}
#endif

#if BIND_apr_terminate2_FUNCTION
#define apr_terminate2_REQUIRED_ARGC 0
#define apr_terminate2_OPTIONAL_ARGC 0
/* apr_terminate2
 *
 * Parameters: None
 * Return Type: void
 */
mrb_value
mrb_APR_apr_terminate2(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  apr_terminate2();

  return mrb_nil_value();
}
#endif

#if BIND_apr_thread_cond_broadcast_FUNCTION
#define apr_thread_cond_broadcast_REQUIRED_ARGC 1
#define apr_thread_cond_broadcast_OPTIONAL_ARGC 0
/* apr_thread_cond_broadcast
 *
 * Parameters:
 * - cond: apr_thread_cond_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_cond_broadcast(mrb_state* mrb, mrb_value self) {
  mrb_value cond;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &cond);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, cond, AprThreadCondT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadCondT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_thread_cond_t * native_cond = (mrb_nil_p(cond) ? NULL : mruby_unbox_apr_thread_cond_t(cond));

  /* Invocation */
  apr_status_t result = apr_thread_cond_broadcast(native_cond);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_cond_create_FUNCTION
#define apr_thread_cond_create_REQUIRED_ARGC 2
#define apr_thread_cond_create_OPTIONAL_ARGC 0
/* apr_thread_cond_create
 *
 * Parameters:
 * - cond: apr_thread_cond_t **
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_cond_create(mrb_state* mrb, mrb_value self) {
  mrb_value cond;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &cond, &pool);


  /* Type checking */
  TODO_type_check_apr_thread_cond_t_PTR_PTR(cond);
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_thread_cond_t ** native_cond = TODO_mruby_unbox_apr_thread_cond_t_PTR_PTR(cond);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_thread_cond_create(native_cond, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_cond_destroy_FUNCTION
#define apr_thread_cond_destroy_REQUIRED_ARGC 1
#define apr_thread_cond_destroy_OPTIONAL_ARGC 0
/* apr_thread_cond_destroy
 *
 * Parameters:
 * - cond: apr_thread_cond_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_cond_destroy(mrb_state* mrb, mrb_value self) {
  mrb_value cond;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &cond);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, cond, AprThreadCondT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadCondT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_thread_cond_t * native_cond = (mrb_nil_p(cond) ? NULL : mruby_unbox_apr_thread_cond_t(cond));

  /* Invocation */
  apr_status_t result = apr_thread_cond_destroy(native_cond);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_cond_signal_FUNCTION
#define apr_thread_cond_signal_REQUIRED_ARGC 1
#define apr_thread_cond_signal_OPTIONAL_ARGC 0
/* apr_thread_cond_signal
 *
 * Parameters:
 * - cond: apr_thread_cond_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_cond_signal(mrb_state* mrb, mrb_value self) {
  mrb_value cond;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &cond);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, cond, AprThreadCondT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadCondT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_thread_cond_t * native_cond = (mrb_nil_p(cond) ? NULL : mruby_unbox_apr_thread_cond_t(cond));

  /* Invocation */
  apr_status_t result = apr_thread_cond_signal(native_cond);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_cond_timedwait_FUNCTION
#define apr_thread_cond_timedwait_REQUIRED_ARGC 3
#define apr_thread_cond_timedwait_OPTIONAL_ARGC 0
/* apr_thread_cond_timedwait
 *
 * Parameters:
 * - cond: apr_thread_cond_t *
 * - mutex: apr_thread_mutex_t *
 * - timeout: long long
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_cond_timedwait(mrb_state* mrb, mrb_value self) {
  mrb_value cond;
  mrb_value mutex;
  mrb_value timeout;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &cond, &mutex, &timeout);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, cond, AprThreadCondT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadCondT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, mutex, AprThreadMutexT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadMutexT expected");
    return mrb_nil_value();
  }
  TODO_type_check_long_long(timeout);


  /* Unbox parameters */
  apr_thread_cond_t * native_cond = (mrb_nil_p(cond) ? NULL : mruby_unbox_apr_thread_cond_t(cond));

  apr_thread_mutex_t * native_mutex = (mrb_nil_p(mutex) ? NULL : mruby_unbox_apr_thread_mutex_t(mutex));

  long long native_timeout = TODO_mruby_unbox_long_long(timeout);

  /* Invocation */
  apr_status_t result = apr_thread_cond_timedwait(native_cond, native_mutex, native_timeout);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_cond_wait_FUNCTION
#define apr_thread_cond_wait_REQUIRED_ARGC 2
#define apr_thread_cond_wait_OPTIONAL_ARGC 0
/* apr_thread_cond_wait
 *
 * Parameters:
 * - cond: apr_thread_cond_t *
 * - mutex: apr_thread_mutex_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_cond_wait(mrb_state* mrb, mrb_value self) {
  mrb_value cond;
  mrb_value mutex;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &cond, &mutex);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, cond, AprThreadCondT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadCondT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, mutex, AprThreadMutexT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadMutexT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_thread_cond_t * native_cond = (mrb_nil_p(cond) ? NULL : mruby_unbox_apr_thread_cond_t(cond));

  apr_thread_mutex_t * native_mutex = (mrb_nil_p(mutex) ? NULL : mruby_unbox_apr_thread_mutex_t(mutex));

  /* Invocation */
  apr_status_t result = apr_thread_cond_wait(native_cond, native_mutex);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_create_FUNCTION
#define apr_thread_create_REQUIRED_ARGC 5
#define apr_thread_create_OPTIONAL_ARGC 0
/* apr_thread_create
 *
 * Parameters:
 * - new_thread: apr_thread_t **
 * - attr: apr_threadattr_t *
 * - func: void *(*)(apr_thread_t *, void *) __attribute__((stdcall))
 * - data: void *
 * - cont: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_create(mrb_state* mrb, mrb_value self) {
  mrb_value new_thread;
  mrb_value attr;
  mrb_value func;
  mrb_value data;
  mrb_value cont;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &new_thread, &attr, &func, &data, &cont);


  /* Type checking */
  TODO_type_check_apr_thread_t_PTR_PTR(new_thread);
  if (!mrb_obj_is_kind_of(mrb, attr, AprThreadattrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadattrT expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR_LPAREN_PTR_RPAREN_LPAREN_apr_thread_t_PTR_COMMA_void_PTR_RPAREN___attribute___LPAREN_LPAREN_stdcall_RPAREN_RPAREN(func);
  TODO_type_check_void_PTR(data);
  if (!mrb_obj_is_kind_of(mrb, cont, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_thread_t ** native_new_thread = TODO_mruby_unbox_apr_thread_t_PTR_PTR(new_thread);

  apr_threadattr_t * native_attr = (mrb_nil_p(attr) ? NULL : mruby_unbox_apr_threadattr_t(attr));

  void *(*native_func)(apr_thread_t *, void *) __attribute__((stdcall)) = TODO_mruby_unbox_void_PTR_LPAREN_PTR_RPAREN_LPAREN_apr_thread_t_PTR_COMMA_void_PTR_RPAREN___attribute___LPAREN_LPAREN_stdcall_RPAREN_RPAREN(func);

  void * native_data = TODO_mruby_unbox_void_PTR(data);

  apr_pool_t * native_cont = (mrb_nil_p(cont) ? NULL : mruby_unbox_apr_pool_t(cont));

  /* Invocation */
  apr_status_t result = apr_thread_create(native_new_thread, native_attr, native_func, native_data, native_cont);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_data_get_FUNCTION
#define apr_thread_data_get_REQUIRED_ARGC 3
#define apr_thread_data_get_OPTIONAL_ARGC 0
/* apr_thread_data_get
 *
 * Parameters:
 * - data: void **
 * - key: const char *
 * - thread: apr_thread_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_data_get(mrb_state* mrb, mrb_value self) {
  mrb_value data;
  mrb_value key;
  mrb_value thread;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &data, &key, &thread);


  /* Type checking */
  TODO_type_check_void_PTR_PTR(data);
  if (!mrb_obj_is_kind_of(mrb, key, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, thread, AprThreadT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void ** native_data = TODO_mruby_unbox_void_PTR_PTR(data);

  const char * native_key = mrb_string_value_cstr(mrb, &key);

  apr_thread_t * native_thread = (mrb_nil_p(thread) ? NULL : mruby_unbox_apr_thread_t(thread));

  /* Invocation */
  apr_status_t result = apr_thread_data_get(native_data, native_key, native_thread);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_data_set_FUNCTION
#define apr_thread_data_set_REQUIRED_ARGC 5
#define apr_thread_data_set_OPTIONAL_ARGC 0
/* apr_thread_data_set
 *
 * Parameters:
 * - data: void *
 * - key: const char *
 * - cleanup: int (*)(void *)
 * - arg4: void *
 * - thread: apr_thread_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_data_set(mrb_state* mrb, mrb_value self) {
  mrb_value data;
  mrb_value key;
  mrb_value cleanup;
  mrb_value arg4;
  mrb_value thread;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &data, &key, &cleanup, &arg4, &thread);


  /* Type checking */
  TODO_type_check_void_PTR(data);
  if (!mrb_obj_is_kind_of(mrb, key, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(cleanup);
  TODO_type_check_void_PTR(arg4);
  if (!mrb_obj_is_kind_of(mrb, thread, AprThreadT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void * native_data = TODO_mruby_unbox_void_PTR(data);

  const char * native_key = mrb_string_value_cstr(mrb, &key);

  int (*native_cleanup)(void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(cleanup);

  void * native_arg4 = TODO_mruby_unbox_void_PTR(arg4);

  apr_thread_t * native_thread = (mrb_nil_p(thread) ? NULL : mruby_unbox_apr_thread_t(thread));

  /* Invocation */
  apr_status_t result = apr_thread_data_set(native_data, native_key, native_cleanup, native_arg4, native_thread);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_detach_FUNCTION
#define apr_thread_detach_REQUIRED_ARGC 1
#define apr_thread_detach_OPTIONAL_ARGC 0
/* apr_thread_detach
 *
 * Parameters:
 * - thd: apr_thread_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_detach(mrb_state* mrb, mrb_value self) {
  mrb_value thd;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &thd);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, thd, AprThreadT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_thread_t * native_thd = (mrb_nil_p(thd) ? NULL : mruby_unbox_apr_thread_t(thd));

  /* Invocation */
  apr_status_t result = apr_thread_detach(native_thd);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_exit_FUNCTION
#define apr_thread_exit_REQUIRED_ARGC 2
#define apr_thread_exit_OPTIONAL_ARGC 0
/* apr_thread_exit
 *
 * Parameters:
 * - thd: apr_thread_t *
 * - retval: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_exit(mrb_state* mrb, mrb_value self) {
  mrb_value thd;
  mrb_value retval;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &thd, &retval);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, thd, AprThreadT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, retval, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_thread_t * native_thd = (mrb_nil_p(thd) ? NULL : mruby_unbox_apr_thread_t(thd));

  int native_retval = mrb_fixnum(retval);

  /* Invocation */
  apr_status_t result = apr_thread_exit(native_thd, native_retval);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_join_FUNCTION
#define apr_thread_join_REQUIRED_ARGC 2
#define apr_thread_join_OPTIONAL_ARGC 0
/* apr_thread_join
 *
 * Parameters:
 * - retval: int *
 * - thd: apr_thread_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_join(mrb_state* mrb, mrb_value self) {
  mrb_value retval;
  mrb_value thd;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &retval, &thd);


  /* Type checking */
  TODO_type_check_int_PTR(retval);
  if (!mrb_obj_is_kind_of(mrb, thd, AprThreadT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int * native_retval = TODO_mruby_unbox_int_PTR(retval);

  apr_thread_t * native_thd = (mrb_nil_p(thd) ? NULL : mruby_unbox_apr_thread_t(thd));

  /* Invocation */
  apr_status_t result = apr_thread_join(native_retval, native_thd);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_mutex_create_FUNCTION
#define apr_thread_mutex_create_REQUIRED_ARGC 3
#define apr_thread_mutex_create_OPTIONAL_ARGC 0
/* apr_thread_mutex_create
 *
 * Parameters:
 * - mutex: apr_thread_mutex_t **
 * - flags: unsigned int
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_mutex_create(mrb_state* mrb, mrb_value self) {
  mrb_value mutex;
  mrb_value flags;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &mutex, &flags, &pool);


  /* Type checking */
  TODO_type_check_apr_thread_mutex_t_PTR_PTR(mutex);
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_thread_mutex_t ** native_mutex = TODO_mruby_unbox_apr_thread_mutex_t_PTR_PTR(mutex);

  unsigned int native_flags = mrb_fixnum(flags);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_thread_mutex_create(native_mutex, native_flags, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_mutex_destroy_FUNCTION
#define apr_thread_mutex_destroy_REQUIRED_ARGC 6
#define apr_thread_mutex_destroy_OPTIONAL_ARGC 0
/* apr_thread_mutex_destroy
 *
 * Parameters:
 * - mutex: apr_thread_mutex_t *
 * - proc: apr_pool_t *
 * - err: int
 * - description: const char *
 * - arg5: apr_thread_t *
 * - arg6: void *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_mutex_destroy(mrb_state* mrb, mrb_value self) {
  mrb_value mutex;
  mrb_value proc;
  mrb_value err;
  mrb_value description;
  mrb_value arg5;
  mrb_value arg6;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooo", &mutex, &proc, &err, &description, &arg5, &arg6);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, mutex, AprThreadMutexT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadMutexT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, proc, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, err, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, description, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, arg5, AprThreadT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadT expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(arg6);


  /* Unbox parameters */
  apr_thread_mutex_t * native_mutex = (mrb_nil_p(mutex) ? NULL : mruby_unbox_apr_thread_mutex_t(mutex));

  apr_pool_t * native_proc = (mrb_nil_p(proc) ? NULL : mruby_unbox_apr_pool_t(proc));

  int native_err = mrb_fixnum(err);

  const char * native_description = mrb_string_value_cstr(mrb, &description);

  apr_thread_t * native_arg5 = (mrb_nil_p(arg5) ? NULL : mruby_unbox_apr_thread_t(arg5));

  void * native_arg6 = TODO_mruby_unbox_void_PTR(arg6);

  /* Invocation */
  apr_status_t result = apr_thread_mutex_destroy(native_mutex, native_proc, native_err, native_description, native_arg5, native_arg6);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_mutex_lock_FUNCTION
#define apr_thread_mutex_lock_REQUIRED_ARGC 1
#define apr_thread_mutex_lock_OPTIONAL_ARGC 0
/* apr_thread_mutex_lock
 *
 * Parameters:
 * - mutex: apr_thread_mutex_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_mutex_lock(mrb_state* mrb, mrb_value self) {
  mrb_value mutex;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &mutex);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, mutex, AprThreadMutexT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadMutexT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_thread_mutex_t * native_mutex = (mrb_nil_p(mutex) ? NULL : mruby_unbox_apr_thread_mutex_t(mutex));

  /* Invocation */
  apr_status_t result = apr_thread_mutex_lock(native_mutex);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_mutex_trylock_FUNCTION
#define apr_thread_mutex_trylock_REQUIRED_ARGC 1
#define apr_thread_mutex_trylock_OPTIONAL_ARGC 0
/* apr_thread_mutex_trylock
 *
 * Parameters:
 * - mutex: apr_thread_mutex_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_mutex_trylock(mrb_state* mrb, mrb_value self) {
  mrb_value mutex;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &mutex);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, mutex, AprThreadMutexT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadMutexT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_thread_mutex_t * native_mutex = (mrb_nil_p(mutex) ? NULL : mruby_unbox_apr_thread_mutex_t(mutex));

  /* Invocation */
  apr_status_t result = apr_thread_mutex_trylock(native_mutex);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_mutex_unlock_FUNCTION
#define apr_thread_mutex_unlock_REQUIRED_ARGC 1
#define apr_thread_mutex_unlock_OPTIONAL_ARGC 0
/* apr_thread_mutex_unlock
 *
 * Parameters:
 * - mutex: apr_thread_mutex_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_mutex_unlock(mrb_state* mrb, mrb_value self) {
  mrb_value mutex;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &mutex);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, mutex, AprThreadMutexT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadMutexT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_thread_mutex_t * native_mutex = (mrb_nil_p(mutex) ? NULL : mruby_unbox_apr_thread_mutex_t(mutex));

  /* Invocation */
  apr_status_t result = apr_thread_mutex_unlock(native_mutex);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_once_FUNCTION
#define apr_thread_once_REQUIRED_ARGC 2
#define apr_thread_once_OPTIONAL_ARGC 0
/* apr_thread_once
 *
 * Parameters:
 * - control: apr_thread_once_t *
 * - func: void (*)()
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_once(mrb_state* mrb, mrb_value self) {
  mrb_value control;
  mrb_value func;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &control, &func);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, control, AprThreadOnceT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadOnceT expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_RPAREN(func);


  /* Unbox parameters */
  apr_thread_once_t * native_control = (mrb_nil_p(control) ? NULL : mruby_unbox_apr_thread_once_t(control));

  void (*native_func)() = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_RPAREN(func);

  /* Invocation */
  apr_status_t result = apr_thread_once(native_control, native_func);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_once_init_FUNCTION
#define apr_thread_once_init_REQUIRED_ARGC 2
#define apr_thread_once_init_OPTIONAL_ARGC 0
/* apr_thread_once_init
 *
 * Parameters:
 * - control: apr_thread_once_t **
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_once_init(mrb_state* mrb, mrb_value self) {
  mrb_value control;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &control, &p);


  /* Type checking */
  TODO_type_check_apr_thread_once_t_PTR_PTR(control);
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_thread_once_t ** native_control = TODO_mruby_unbox_apr_thread_once_t_PTR_PTR(control);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_thread_once_init(native_control, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_rwlock_create_FUNCTION
#define apr_thread_rwlock_create_REQUIRED_ARGC 2
#define apr_thread_rwlock_create_OPTIONAL_ARGC 0
/* apr_thread_rwlock_create
 *
 * Parameters:
 * - rwlock: apr_thread_rwlock_t **
 * - pool: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_rwlock_create(mrb_state* mrb, mrb_value self) {
  mrb_value rwlock;
  mrb_value pool;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &rwlock, &pool);


  /* Type checking */
  TODO_type_check_apr_thread_rwlock_t_PTR_PTR(rwlock);
  if (!mrb_obj_is_kind_of(mrb, pool, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_thread_rwlock_t ** native_rwlock = TODO_mruby_unbox_apr_thread_rwlock_t_PTR_PTR(rwlock);

  apr_pool_t * native_pool = (mrb_nil_p(pool) ? NULL : mruby_unbox_apr_pool_t(pool));

  /* Invocation */
  apr_status_t result = apr_thread_rwlock_create(native_rwlock, native_pool);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_rwlock_destroy_FUNCTION
#define apr_thread_rwlock_destroy_REQUIRED_ARGC 1
#define apr_thread_rwlock_destroy_OPTIONAL_ARGC 0
/* apr_thread_rwlock_destroy
 *
 * Parameters:
 * - rwlock: apr_thread_rwlock_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_rwlock_destroy(mrb_state* mrb, mrb_value self) {
  mrb_value rwlock;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &rwlock);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, rwlock, AprThreadRwlockT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadRwlockT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_thread_rwlock_t * native_rwlock = (mrb_nil_p(rwlock) ? NULL : mruby_unbox_apr_thread_rwlock_t(rwlock));

  /* Invocation */
  apr_status_t result = apr_thread_rwlock_destroy(native_rwlock);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_rwlock_rdlock_FUNCTION
#define apr_thread_rwlock_rdlock_REQUIRED_ARGC 1
#define apr_thread_rwlock_rdlock_OPTIONAL_ARGC 0
/* apr_thread_rwlock_rdlock
 *
 * Parameters:
 * - rwlock: apr_thread_rwlock_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_rwlock_rdlock(mrb_state* mrb, mrb_value self) {
  mrb_value rwlock;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &rwlock);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, rwlock, AprThreadRwlockT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadRwlockT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_thread_rwlock_t * native_rwlock = (mrb_nil_p(rwlock) ? NULL : mruby_unbox_apr_thread_rwlock_t(rwlock));

  /* Invocation */
  apr_status_t result = apr_thread_rwlock_rdlock(native_rwlock);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_rwlock_tryrdlock_FUNCTION
#define apr_thread_rwlock_tryrdlock_REQUIRED_ARGC 1
#define apr_thread_rwlock_tryrdlock_OPTIONAL_ARGC 0
/* apr_thread_rwlock_tryrdlock
 *
 * Parameters:
 * - rwlock: apr_thread_rwlock_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_rwlock_tryrdlock(mrb_state* mrb, mrb_value self) {
  mrb_value rwlock;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &rwlock);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, rwlock, AprThreadRwlockT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadRwlockT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_thread_rwlock_t * native_rwlock = (mrb_nil_p(rwlock) ? NULL : mruby_unbox_apr_thread_rwlock_t(rwlock));

  /* Invocation */
  apr_status_t result = apr_thread_rwlock_tryrdlock(native_rwlock);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_rwlock_trywrlock_FUNCTION
#define apr_thread_rwlock_trywrlock_REQUIRED_ARGC 1
#define apr_thread_rwlock_trywrlock_OPTIONAL_ARGC 0
/* apr_thread_rwlock_trywrlock
 *
 * Parameters:
 * - rwlock: apr_thread_rwlock_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_rwlock_trywrlock(mrb_state* mrb, mrb_value self) {
  mrb_value rwlock;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &rwlock);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, rwlock, AprThreadRwlockT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadRwlockT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_thread_rwlock_t * native_rwlock = (mrb_nil_p(rwlock) ? NULL : mruby_unbox_apr_thread_rwlock_t(rwlock));

  /* Invocation */
  apr_status_t result = apr_thread_rwlock_trywrlock(native_rwlock);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_rwlock_unlock_FUNCTION
#define apr_thread_rwlock_unlock_REQUIRED_ARGC 1
#define apr_thread_rwlock_unlock_OPTIONAL_ARGC 0
/* apr_thread_rwlock_unlock
 *
 * Parameters:
 * - rwlock: apr_thread_rwlock_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_rwlock_unlock(mrb_state* mrb, mrb_value self) {
  mrb_value rwlock;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &rwlock);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, rwlock, AprThreadRwlockT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadRwlockT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_thread_rwlock_t * native_rwlock = (mrb_nil_p(rwlock) ? NULL : mruby_unbox_apr_thread_rwlock_t(rwlock));

  /* Invocation */
  apr_status_t result = apr_thread_rwlock_unlock(native_rwlock);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_rwlock_wrlock_FUNCTION
#define apr_thread_rwlock_wrlock_REQUIRED_ARGC 1
#define apr_thread_rwlock_wrlock_OPTIONAL_ARGC 0
/* apr_thread_rwlock_wrlock
 *
 * Parameters:
 * - rwlock: apr_thread_rwlock_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_thread_rwlock_wrlock(mrb_state* mrb, mrb_value self) {
  mrb_value rwlock;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &rwlock);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, rwlock, AprThreadRwlockT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadRwlockT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_thread_rwlock_t * native_rwlock = (mrb_nil_p(rwlock) ? NULL : mruby_unbox_apr_thread_rwlock_t(rwlock));

  /* Invocation */
  apr_status_t result = apr_thread_rwlock_wrlock(native_rwlock);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_thread_yield_FUNCTION
#define apr_thread_yield_REQUIRED_ARGC 0
#define apr_thread_yield_OPTIONAL_ARGC 0
/* apr_thread_yield
 *
 * Parameters: None
 * Return Type: void
 */
mrb_value
mrb_APR_apr_thread_yield(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  apr_thread_yield();

  return mrb_nil_value();
}
#endif

#if BIND_apr_threadattr_create_FUNCTION
#define apr_threadattr_create_REQUIRED_ARGC 2
#define apr_threadattr_create_OPTIONAL_ARGC 0
/* apr_threadattr_create
 *
 * Parameters:
 * - new_attr: apr_threadattr_t **
 * - cont: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_threadattr_create(mrb_state* mrb, mrb_value self) {
  mrb_value new_attr;
  mrb_value cont;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &new_attr, &cont);


  /* Type checking */
  TODO_type_check_apr_threadattr_t_PTR_PTR(new_attr);
  if (!mrb_obj_is_kind_of(mrb, cont, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_threadattr_t ** native_new_attr = TODO_mruby_unbox_apr_threadattr_t_PTR_PTR(new_attr);

  apr_pool_t * native_cont = (mrb_nil_p(cont) ? NULL : mruby_unbox_apr_pool_t(cont));

  /* Invocation */
  apr_status_t result = apr_threadattr_create(native_new_attr, native_cont);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_threadattr_detach_get_FUNCTION
#define apr_threadattr_detach_get_REQUIRED_ARGC 1
#define apr_threadattr_detach_get_OPTIONAL_ARGC 0
/* apr_threadattr_detach_get
 *
 * Parameters:
 * - attr: apr_threadattr_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_threadattr_detach_get(mrb_state* mrb, mrb_value self) {
  mrb_value attr;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &attr);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, attr, AprThreadattrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadattrT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_threadattr_t * native_attr = (mrb_nil_p(attr) ? NULL : mruby_unbox_apr_threadattr_t(attr));

  /* Invocation */
  apr_status_t result = apr_threadattr_detach_get(native_attr);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_threadattr_detach_set_FUNCTION
#define apr_threadattr_detach_set_REQUIRED_ARGC 2
#define apr_threadattr_detach_set_OPTIONAL_ARGC 0
/* apr_threadattr_detach_set
 *
 * Parameters:
 * - attr: apr_threadattr_t *
 * - on: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_threadattr_detach_set(mrb_state* mrb, mrb_value self) {
  mrb_value attr;
  mrb_value on;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &attr, &on);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, attr, AprThreadattrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadattrT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, on, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_threadattr_t * native_attr = (mrb_nil_p(attr) ? NULL : mruby_unbox_apr_threadattr_t(attr));

  int native_on = mrb_fixnum(on);

  /* Invocation */
  apr_status_t result = apr_threadattr_detach_set(native_attr, native_on);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_threadattr_guardsize_set_FUNCTION
#define apr_threadattr_guardsize_set_REQUIRED_ARGC 2
#define apr_threadattr_guardsize_set_OPTIONAL_ARGC 0
/* apr_threadattr_guardsize_set
 *
 * Parameters:
 * - attr: apr_threadattr_t *
 * - guardsize: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_threadattr_guardsize_set(mrb_state* mrb, mrb_value self) {
  mrb_value attr;
  mrb_value guardsize;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &attr, &guardsize);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, attr, AprThreadattrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadattrT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, guardsize, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_threadattr_t * native_attr = (mrb_nil_p(attr) ? NULL : mruby_unbox_apr_threadattr_t(attr));

  int native_guardsize = mrb_fixnum(guardsize);

  /* Invocation */
  apr_status_t result = apr_threadattr_guardsize_set(native_attr, native_guardsize);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_threadattr_stacksize_set_FUNCTION
#define apr_threadattr_stacksize_set_REQUIRED_ARGC 2
#define apr_threadattr_stacksize_set_OPTIONAL_ARGC 0
/* apr_threadattr_stacksize_set
 *
 * Parameters:
 * - attr: apr_threadattr_t *
 * - stacksize: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_threadattr_stacksize_set(mrb_state* mrb, mrb_value self) {
  mrb_value attr;
  mrb_value stacksize;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &attr, &stacksize);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, attr, AprThreadattrT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadattrT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, stacksize, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_threadattr_t * native_attr = (mrb_nil_p(attr) ? NULL : mruby_unbox_apr_threadattr_t(attr));

  int native_stacksize = mrb_fixnum(stacksize);

  /* Invocation */
  apr_status_t result = apr_threadattr_stacksize_set(native_attr, native_stacksize);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_threadkey_data_get_FUNCTION
#define apr_threadkey_data_get_REQUIRED_ARGC 3
#define apr_threadkey_data_get_OPTIONAL_ARGC 0
/* apr_threadkey_data_get
 *
 * Parameters:
 * - data: void **
 * - key: const char *
 * - threadkey: apr_threadkey_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_threadkey_data_get(mrb_state* mrb, mrb_value self) {
  mrb_value data;
  mrb_value key;
  mrb_value threadkey;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &data, &key, &threadkey);


  /* Type checking */
  TODO_type_check_void_PTR_PTR(data);
  if (!mrb_obj_is_kind_of(mrb, key, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, threadkey, AprThreadkeyT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadkeyT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void ** native_data = TODO_mruby_unbox_void_PTR_PTR(data);

  const char * native_key = mrb_string_value_cstr(mrb, &key);

  apr_threadkey_t * native_threadkey = (mrb_nil_p(threadkey) ? NULL : mruby_unbox_apr_threadkey_t(threadkey));

  /* Invocation */
  apr_status_t result = apr_threadkey_data_get(native_data, native_key, native_threadkey);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_threadkey_data_set_FUNCTION
#define apr_threadkey_data_set_REQUIRED_ARGC 5
#define apr_threadkey_data_set_OPTIONAL_ARGC 0
/* apr_threadkey_data_set
 *
 * Parameters:
 * - data: void *
 * - key: const char *
 * - cleanup: int (*)(void *)
 * - arg4: void *
 * - threadkey: apr_threadkey_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_threadkey_data_set(mrb_state* mrb, mrb_value self) {
  mrb_value data;
  mrb_value key;
  mrb_value cleanup;
  mrb_value arg4;
  mrb_value threadkey;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &data, &key, &cleanup, &arg4, &threadkey);


  /* Type checking */
  TODO_type_check_void_PTR(data);
  if (!mrb_obj_is_kind_of(mrb, key, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(cleanup);
  TODO_type_check_void_PTR(arg4);
  if (!mrb_obj_is_kind_of(mrb, threadkey, AprThreadkeyT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadkeyT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void * native_data = TODO_mruby_unbox_void_PTR(data);

  const char * native_key = mrb_string_value_cstr(mrb, &key);

  int (*native_cleanup)(void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(cleanup);

  void * native_arg4 = TODO_mruby_unbox_void_PTR(arg4);

  apr_threadkey_t * native_threadkey = (mrb_nil_p(threadkey) ? NULL : mruby_unbox_apr_threadkey_t(threadkey));

  /* Invocation */
  apr_status_t result = apr_threadkey_data_set(native_data, native_key, native_cleanup, native_arg4, native_threadkey);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_threadkey_private_create_FUNCTION
#define apr_threadkey_private_create_REQUIRED_ARGC 4
#define apr_threadkey_private_create_OPTIONAL_ARGC 0
/* apr_threadkey_private_create
 *
 * Parameters:
 * - key: apr_threadkey_t **
 * - dest: void (*)(void *)
 * - arg3: void *
 * - cont: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_threadkey_private_create(mrb_state* mrb, mrb_value self) {
  mrb_value key;
  mrb_value dest;
  mrb_value arg3;
  mrb_value cont;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &key, &dest, &arg3, &cont);


  /* Type checking */
  TODO_type_check_apr_threadkey_t_PTR_PTR(key);
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(dest);
  TODO_type_check_void_PTR(arg3);
  if (!mrb_obj_is_kind_of(mrb, cont, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_threadkey_t ** native_key = TODO_mruby_unbox_apr_threadkey_t_PTR_PTR(key);

  void (*native_dest)(void *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(dest);

  void * native_arg3 = TODO_mruby_unbox_void_PTR(arg3);

  apr_pool_t * native_cont = (mrb_nil_p(cont) ? NULL : mruby_unbox_apr_pool_t(cont));

  /* Invocation */
  apr_status_t result = apr_threadkey_private_create(native_key, native_dest, native_arg3, native_cont);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_threadkey_private_delete_FUNCTION
#define apr_threadkey_private_delete_REQUIRED_ARGC 1
#define apr_threadkey_private_delete_OPTIONAL_ARGC 0
/* apr_threadkey_private_delete
 *
 * Parameters:
 * - key: apr_threadkey_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_threadkey_private_delete(mrb_state* mrb, mrb_value self) {
  mrb_value key;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &key);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, key, AprThreadkeyT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadkeyT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_threadkey_t * native_key = (mrb_nil_p(key) ? NULL : mruby_unbox_apr_threadkey_t(key));

  /* Invocation */
  apr_status_t result = apr_threadkey_private_delete(native_key);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_threadkey_private_get_FUNCTION
#define apr_threadkey_private_get_REQUIRED_ARGC 2
#define apr_threadkey_private_get_OPTIONAL_ARGC 0
/* apr_threadkey_private_get
 *
 * Parameters:
 * - new_mem: void **
 * - key: apr_threadkey_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_threadkey_private_get(mrb_state* mrb, mrb_value self) {
  mrb_value new_mem;
  mrb_value key;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &new_mem, &key);


  /* Type checking */
  TODO_type_check_void_PTR_PTR(new_mem);
  if (!mrb_obj_is_kind_of(mrb, key, AprThreadkeyT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadkeyT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void ** native_new_mem = TODO_mruby_unbox_void_PTR_PTR(new_mem);

  apr_threadkey_t * native_key = (mrb_nil_p(key) ? NULL : mruby_unbox_apr_threadkey_t(key));

  /* Invocation */
  apr_status_t result = apr_threadkey_private_get(native_new_mem, native_key);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_threadkey_private_set_FUNCTION
#define apr_threadkey_private_set_REQUIRED_ARGC 2
#define apr_threadkey_private_set_OPTIONAL_ARGC 0
/* apr_threadkey_private_set
 *
 * Parameters:
 * - priv: void *
 * - key: apr_threadkey_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_threadkey_private_set(mrb_state* mrb, mrb_value self) {
  mrb_value priv;
  mrb_value key;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &priv, &key);


  /* Type checking */
  TODO_type_check_void_PTR(priv);
  if (!mrb_obj_is_kind_of(mrb, key, AprThreadkeyT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprThreadkeyT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void * native_priv = TODO_mruby_unbox_void_PTR(priv);

  apr_threadkey_t * native_key = (mrb_nil_p(key) ? NULL : mruby_unbox_apr_threadkey_t(key));

  /* Invocation */
  apr_status_t result = apr_threadkey_private_set(native_priv, native_key);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_time_ansi_put_FUNCTION
#define apr_time_ansi_put_REQUIRED_ARGC 2
#define apr_time_ansi_put_OPTIONAL_ARGC 0
/* apr_time_ansi_put
 *
 * Parameters:
 * - result: long long *
 * - input: long
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_time_ansi_put(mrb_state* mrb, mrb_value self) {
  mrb_value result;
  mrb_value input;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &result, &input);


  /* Type checking */
  TODO_type_check_long_long_PTR(result);
  TODO_type_check_long(input);


  /* Unbox parameters */
  long long * native_result = TODO_mruby_unbox_long_long_PTR(result);

  long native_input = TODO_mruby_unbox_long(input);

  /* Invocation */
  apr_status_t result = apr_time_ansi_put(native_result, native_input);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_time_clock_hires_FUNCTION
#define apr_time_clock_hires_REQUIRED_ARGC 1
#define apr_time_clock_hires_OPTIONAL_ARGC 0
/* apr_time_clock_hires
 *
 * Parameters:
 * - p: apr_pool_t *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_time_clock_hires(mrb_state* mrb, mrb_value self) {
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &p);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_time_clock_hires(native_p);

  return mrb_nil_value();
}
#endif

#if BIND_apr_time_exp_get_FUNCTION
#define apr_time_exp_get_REQUIRED_ARGC 2
#define apr_time_exp_get_OPTIONAL_ARGC 0
/* apr_time_exp_get
 *
 * Parameters:
 * - result: long long *
 * - input: apr_time_exp_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_time_exp_get(mrb_state* mrb, mrb_value self) {
  mrb_value result;
  mrb_value input;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &result, &input);


  /* Type checking */
  TODO_type_check_long_long_PTR(result);
  if (!mrb_obj_is_kind_of(mrb, input, AprTimeExpT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTimeExpT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  long long * native_result = TODO_mruby_unbox_long_long_PTR(result);

  apr_time_exp_t * native_input = (mrb_nil_p(input) ? NULL : mruby_unbox_apr_time_exp_t(input));

  /* Invocation */
  apr_status_t result = apr_time_exp_get(native_result, native_input);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_time_exp_gmt_FUNCTION
#define apr_time_exp_gmt_REQUIRED_ARGC 2
#define apr_time_exp_gmt_OPTIONAL_ARGC 0
/* apr_time_exp_gmt
 *
 * Parameters:
 * - result: apr_time_exp_t *
 * - input: long long
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_time_exp_gmt(mrb_state* mrb, mrb_value self) {
  mrb_value result;
  mrb_value input;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &result, &input);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, result, AprTimeExpT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTimeExpT expected");
    return mrb_nil_value();
  }
  TODO_type_check_long_long(input);


  /* Unbox parameters */
  apr_time_exp_t * native_result = (mrb_nil_p(result) ? NULL : mruby_unbox_apr_time_exp_t(result));

  long long native_input = TODO_mruby_unbox_long_long(input);

  /* Invocation */
  apr_status_t result = apr_time_exp_gmt(native_result, native_input);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_time_exp_gmt_get_FUNCTION
#define apr_time_exp_gmt_get_REQUIRED_ARGC 2
#define apr_time_exp_gmt_get_OPTIONAL_ARGC 0
/* apr_time_exp_gmt_get
 *
 * Parameters:
 * - result: long long *
 * - input: apr_time_exp_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_time_exp_gmt_get(mrb_state* mrb, mrb_value self) {
  mrb_value result;
  mrb_value input;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &result, &input);


  /* Type checking */
  TODO_type_check_long_long_PTR(result);
  if (!mrb_obj_is_kind_of(mrb, input, AprTimeExpT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTimeExpT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  long long * native_result = TODO_mruby_unbox_long_long_PTR(result);

  apr_time_exp_t * native_input = (mrb_nil_p(input) ? NULL : mruby_unbox_apr_time_exp_t(input));

  /* Invocation */
  apr_status_t result = apr_time_exp_gmt_get(native_result, native_input);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_time_exp_lt_FUNCTION
#define apr_time_exp_lt_REQUIRED_ARGC 2
#define apr_time_exp_lt_OPTIONAL_ARGC 0
/* apr_time_exp_lt
 *
 * Parameters:
 * - result: apr_time_exp_t *
 * - input: long long
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_time_exp_lt(mrb_state* mrb, mrb_value self) {
  mrb_value result;
  mrb_value input;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &result, &input);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, result, AprTimeExpT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTimeExpT expected");
    return mrb_nil_value();
  }
  TODO_type_check_long_long(input);


  /* Unbox parameters */
  apr_time_exp_t * native_result = (mrb_nil_p(result) ? NULL : mruby_unbox_apr_time_exp_t(result));

  long long native_input = TODO_mruby_unbox_long_long(input);

  /* Invocation */
  apr_status_t result = apr_time_exp_lt(native_result, native_input);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_time_exp_tz_FUNCTION
#define apr_time_exp_tz_REQUIRED_ARGC 3
#define apr_time_exp_tz_OPTIONAL_ARGC 0
/* apr_time_exp_tz
 *
 * Parameters:
 * - result: apr_time_exp_t *
 * - input: long long
 * - offs: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_time_exp_tz(mrb_state* mrb, mrb_value self) {
  mrb_value result;
  mrb_value input;
  mrb_value offs;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &result, &input, &offs);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, result, AprTimeExpT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprTimeExpT expected");
    return mrb_nil_value();
  }
  TODO_type_check_long_long(input);
  if (!mrb_obj_is_kind_of(mrb, offs, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_time_exp_t * native_result = (mrb_nil_p(result) ? NULL : mruby_unbox_apr_time_exp_t(result));

  long long native_input = TODO_mruby_unbox_long_long(input);

  int native_offs = mrb_fixnum(offs);

  /* Invocation */
  apr_status_t result = apr_time_exp_tz(native_result, native_input, native_offs);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_time_now_FUNCTION
#define apr_time_now_REQUIRED_ARGC 0
#define apr_time_now_OPTIONAL_ARGC 0
/* apr_time_now
 *
 * Parameters: None
 * Return Type: apr_time_t
 */
mrb_value
mrb_APR_apr_time_now(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  apr_time_t result = apr_time_now();

  /* Box the return value */
  apr_time_t* new_time = (apr_time_t*)malloc(sizeof(apr_time_t));
  memcpy(new_time, &result, sizeof(apr_time_t));
  mrb_value return_value = mruby_giftwrap_apr_time_t(mrb, new_time);

  return return_value;
}
#endif

#if BIND_apr_tokenize_to_argv_FUNCTION
#define apr_tokenize_to_argv_REQUIRED_ARGC 2
#define apr_tokenize_to_argv_OPTIONAL_ARGC 0
/* apr_tokenize_to_argv
 *
 * Parameters:
 * - arg_str: String
 * - token_context: AprPoolType
 * Return Type: [Fixnum, Array[String]]
 */
mrb_value
mrb_APR_apr_tokenize_to_argv(mrb_state* mrb, mrb_value self) {
  mrb_value arg_str;
  mrb_value token_context;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &arg_str, &token_context);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, arg_str, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, token_context, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }

  /* Unbox parameters */
  const char * native_arg_str = mrb_string_value_cstr(mrb, &arg_str);
  apr_pool_t * native_token_context = (mrb_nil_p(token_context) ? NULL : mruby_unbox_apr_pool_t(token_context));

  /* Invocation */
  char ** native_argv_out;
  apr_status_t result = apr_tokenize_to_argv(native_arg_str, &native_argv_out, native_token_context);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  mrb_value results = mrb_ary_new(mrb);
  mrb_ary_push(mrb, results, return_value);
  if (result == 0) {
     mrb_value argv = mrb_ary_new(mrb);
     char** current_string_ptr = native_argv_out;
     while (*current_string_ptr != NULL) {
        mrb_ary_push(mrb, argv, mrb_str_new_cstr(mrb, *current_string_ptr));
        current_string_ptr++;
     }
     mrb_ary_push(mrb, results, argv);
  }
  else {
     mrb_ary_push(mrb, results, mrb_nil_value());
  }

  return results;
}
#endif

#if BIND_apr_uid_compare_FUNCTION
#define apr_uid_compare_REQUIRED_ARGC 2
#define apr_uid_compare_OPTIONAL_ARGC 0
/* apr_uid_compare
 *
 * Parameters:
 * - left: void *
 * - right: void *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_uid_compare(mrb_state* mrb, mrb_value self) {
  mrb_value left;
  mrb_value right;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &left, &right);


  /* Type checking */
  TODO_type_check_void_PTR(left);
  TODO_type_check_void_PTR(right);


  /* Unbox parameters */
  void * native_left = TODO_mruby_unbox_void_PTR(left);

  void * native_right = TODO_mruby_unbox_void_PTR(right);

  /* Invocation */
  apr_status_t result = apr_uid_compare(native_left, native_right);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_uid_current_FUNCTION
#define apr_uid_current_REQUIRED_ARGC 3
#define apr_uid_current_OPTIONAL_ARGC 0
/* apr_uid_current
 *
 * Parameters:
 * - userid: void **
 * - groupid: void **
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_uid_current(mrb_state* mrb, mrb_value self) {
  mrb_value userid;
  mrb_value groupid;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &userid, &groupid, &p);


  /* Type checking */
  TODO_type_check_void_PTR_PTR(userid);
  TODO_type_check_void_PTR_PTR(groupid);
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void ** native_userid = TODO_mruby_unbox_void_PTR_PTR(userid);

  void ** native_groupid = TODO_mruby_unbox_void_PTR_PTR(groupid);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_uid_current(native_userid, native_groupid, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_uid_get_FUNCTION
#define apr_uid_get_REQUIRED_ARGC 4
#define apr_uid_get_OPTIONAL_ARGC 0
/* apr_uid_get
 *
 * Parameters:
 * - userid: void **
 * - groupid: void **
 * - username: const char *
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_uid_get(mrb_state* mrb, mrb_value self) {
  mrb_value userid;
  mrb_value groupid;
  mrb_value username;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &userid, &groupid, &username, &p);


  /* Type checking */
  TODO_type_check_void_PTR_PTR(userid);
  TODO_type_check_void_PTR_PTR(groupid);
  if (!mrb_obj_is_kind_of(mrb, username, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void ** native_userid = TODO_mruby_unbox_void_PTR_PTR(userid);

  void ** native_groupid = TODO_mruby_unbox_void_PTR_PTR(groupid);

  const char * native_username = mrb_string_value_cstr(mrb, &username);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_uid_get(native_userid, native_groupid, native_username, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_uid_homepath_get_FUNCTION
#define apr_uid_homepath_get_REQUIRED_ARGC 3
#define apr_uid_homepath_get_OPTIONAL_ARGC 0
/* apr_uid_homepath_get
 *
 * Parameters:
 * - dirname: char **
 * - username: const char *
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_uid_homepath_get(mrb_state* mrb, mrb_value self) {
  mrb_value dirname;
  mrb_value username;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &dirname, &username, &p);


  /* Type checking */
  TODO_type_check_char_PTR_PTR(dirname);
  if (!mrb_obj_is_kind_of(mrb, username, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  char ** native_dirname = TODO_mruby_unbox_char_PTR_PTR(dirname);

  const char * native_username = mrb_string_value_cstr(mrb, &username);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_uid_homepath_get(native_dirname, native_username, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_uid_name_get_FUNCTION
#define apr_uid_name_get_REQUIRED_ARGC 3
#define apr_uid_name_get_OPTIONAL_ARGC 0
/* apr_uid_name_get
 *
 * Parameters:
 * - username: char **
 * - userid: void *
 * - p: apr_pool_t *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_uid_name_get(mrb_state* mrb, mrb_value self) {
  mrb_value username;
  mrb_value userid;
  mrb_value p;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &username, &userid, &p);


  /* Type checking */
  TODO_type_check_char_PTR_PTR(username);
  TODO_type_check_void_PTR(userid);
  if (!mrb_obj_is_kind_of(mrb, p, AprPoolT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  char ** native_username = TODO_mruby_unbox_char_PTR_PTR(username);

  void * native_userid = TODO_mruby_unbox_void_PTR(userid);

  apr_pool_t * native_p = (mrb_nil_p(p) ? NULL : mruby_unbox_apr_pool_t(p));

  /* Invocation */
  apr_status_t result = apr_uid_name_get(native_username, native_userid, native_p);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_unescape_entity_FUNCTION
#define apr_unescape_entity_REQUIRED_ARGC 4
#define apr_unescape_entity_OPTIONAL_ARGC 0
/* apr_unescape_entity
 *
 * Parameters:
 * - unescaped: char *
 * - str: const char *
 * - slen: int
 * - len: int *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_unescape_entity(mrb_state* mrb, mrb_value self) {
  mrb_value unescaped;
  mrb_value str;
  mrb_value slen;
  mrb_value len;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &unescaped, &str, &slen, &len);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, unescaped, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, str, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, slen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(len);


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_unescaped = strdup(mrb_string_value_cstr(mrb, &unescaped));

  const char * native_str = mrb_string_value_cstr(mrb, &str);

  int native_slen = mrb_fixnum(slen);

  int * native_len = TODO_mruby_unbox_int_PTR(len);

  /* Invocation */
  apr_status_t result = apr_unescape_entity(native_unescaped, native_str, native_slen, native_len);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_unescaped);
  native_unescaped = NULL;

  return return_value;
}
#endif

#if BIND_apr_unescape_hex_FUNCTION
#define apr_unescape_hex_REQUIRED_ARGC 5
#define apr_unescape_hex_OPTIONAL_ARGC 0
/* apr_unescape_hex
 *
 * Parameters:
 * - dest: void *
 * - str: const char *
 * - slen: int
 * - colon: int
 * - len: int *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_unescape_hex(mrb_state* mrb, mrb_value self) {
  mrb_value dest;
  mrb_value str;
  mrb_value slen;
  mrb_value colon;
  mrb_value len;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &dest, &str, &slen, &colon, &len);


  /* Type checking */
  TODO_type_check_void_PTR(dest);
  if (!mrb_obj_is_kind_of(mrb, str, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, slen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, colon, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(len);


  /* Unbox parameters */
  void * native_dest = TODO_mruby_unbox_void_PTR(dest);

  const char * native_str = mrb_string_value_cstr(mrb, &str);

  int native_slen = mrb_fixnum(slen);

  int native_colon = mrb_fixnum(colon);

  int * native_len = TODO_mruby_unbox_int_PTR(len);

  /* Invocation */
  apr_status_t result = apr_unescape_hex(native_dest, native_str, native_slen, native_colon, native_len);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_unescape_url_FUNCTION
#define apr_unescape_url_REQUIRED_ARGC 7
#define apr_unescape_url_OPTIONAL_ARGC 0
/* apr_unescape_url
 *
 * Parameters:
 * - escaped: char *
 * - url: const char *
 * - slen: int
 * - forbid: const char *
 * - reserved: const char *
 * - plus: int
 * - len: int *
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_unescape_url(mrb_state* mrb, mrb_value self) {
  mrb_value escaped;
  mrb_value url;
  mrb_value slen;
  mrb_value forbid;
  mrb_value reserved;
  mrb_value plus;
  mrb_value len;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooooo", &escaped, &url, &slen, &forbid, &reserved, &plus, &len);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, escaped, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, url, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, slen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, forbid, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, reserved, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, plus, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(len);


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_escaped = strdup(mrb_string_value_cstr(mrb, &escaped));

  const char * native_url = mrb_string_value_cstr(mrb, &url);

  int native_slen = mrb_fixnum(slen);

  const char * native_forbid = mrb_string_value_cstr(mrb, &forbid);

  const char * native_reserved = mrb_string_value_cstr(mrb, &reserved);

  int native_plus = mrb_fixnum(plus);

  int * native_len = TODO_mruby_unbox_int_PTR(len);

  /* Invocation */
  apr_status_t result = apr_unescape_url(native_escaped, native_url, native_slen, native_forbid, native_reserved, native_plus, native_len);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_escaped);
  native_escaped = NULL;

  return return_value;
}
#endif

#if BIND_apr_version_FUNCTION
#define apr_version_REQUIRED_ARGC 1
#define apr_version_OPTIONAL_ARGC 0
/* apr_version
 *
 * Parameters:
 * - pvsn: apr_version_t *
 * Return Type: void
 */
mrb_value
mrb_APR_apr_version(mrb_state* mrb, mrb_value self) {
  mrb_value pvsn;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &pvsn);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, pvsn, AprVersionT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprVersionT expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_version_t * native_pvsn = (mrb_nil_p(pvsn) ? NULL : mruby_unbox_apr_version_t(pvsn));

  /* Invocation */
  apr_version(native_pvsn);

  return mrb_nil_value();
}
#endif

#if BIND_apr_version_string_FUNCTION
#define apr_version_string_REQUIRED_ARGC 0
#define apr_version_string_OPTIONAL_ARGC 0
/* apr_version_string
 *
 * Parameters: None
 * Return Type: const char *
 */
mrb_value
mrb_APR_apr_version_string(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  const char * result = apr_version_string();

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_apr_vformatter_FUNCTION
#define apr_vformatter_REQUIRED_ARGC 5
#define apr_vformatter_OPTIONAL_ARGC 0
/* apr_vformatter
 *
 * Parameters:
 * - flush_func: int (*)(apr_vformatter_buff_t *)
 * - b: apr_vformatter_buff_t *
 * - c: apr_vformatter_buff_t *
 * - fmt: const char *
 * - ap: int
 * Return Type: int
 */
mrb_value
mrb_APR_apr_vformatter(mrb_state* mrb, mrb_value self) {
  mrb_value flush_func;
  mrb_value b;
  mrb_value c;
  mrb_value fmt;
  mrb_value ap;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &flush_func, &b, &c, &fmt, &ap);


  /* Type checking */
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_apr_vformatter_buff_t_PTR_RPAREN(flush_func);
  if (!mrb_obj_is_kind_of(mrb, b, AprVformatterBuffT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprVformatterBuffT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, c, AprVformatterBuffT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprVformatterBuffT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, fmt, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, ap, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int (*native_flush_func)(apr_vformatter_buff_t *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_apr_vformatter_buff_t_PTR_RPAREN(flush_func);

  apr_vformatter_buff_t * native_b = (mrb_nil_p(b) ? NULL : mruby_unbox_apr_vformatter_buff_t(b));

  apr_vformatter_buff_t * native_c = (mrb_nil_p(c) ? NULL : mruby_unbox_apr_vformatter_buff_t(c));

  const char * native_fmt = mrb_string_value_cstr(mrb, &fmt);

  int native_ap = mrb_fixnum(ap);

  /* Invocation */
  int result = apr_vformatter(native_flush_func, native_b, native_c, native_fmt, native_ap);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_apr_vsnprintf_FUNCTION
#define apr_vsnprintf_REQUIRED_ARGC 4
#define apr_vsnprintf_OPTIONAL_ARGC 0
/* apr_vsnprintf
 *
 * Parameters:
 * - buf: char *
 * - len: int
 * - format: const char *
 * - ap: int
 * Return Type: int
 */
mrb_value
mrb_APR_apr_vsnprintf(mrb_state* mrb, mrb_value self) {
  mrb_value buf;
  mrb_value len;
  mrb_value format;
  mrb_value ap;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &buf, &len, &format, &ap);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, buf, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, len, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, format, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, ap, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_buf = strdup(mrb_string_value_cstr(mrb, &buf));

  int native_len = mrb_fixnum(len);

  const char * native_format = mrb_string_value_cstr(mrb, &format);

  int native_ap = mrb_fixnum(ap);

  /* Invocation */
  int result = apr_vsnprintf(native_buf, native_len, native_format, native_ap);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_buf);
  native_buf = NULL;

  return return_value;
}
#endif

#if BIND_apr_wait_for_io_or_timeout_FUNCTION
#define apr_wait_for_io_or_timeout_REQUIRED_ARGC 3
#define apr_wait_for_io_or_timeout_OPTIONAL_ARGC 0
/* apr_wait_for_io_or_timeout
 *
 * Parameters:
 * - f: apr_file_t *
 * - s: apr_socket_t *
 * - for_read: int
 * Return Type: apr_status_t
 */
mrb_value
mrb_APR_apr_wait_for_io_or_timeout(mrb_state* mrb, mrb_value self) {
  mrb_value f;
  mrb_value s;
  mrb_value for_read;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &f, &s, &for_read);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, f, AprFileT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, s, AprSocketT_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "AprSocketT expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, for_read, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  apr_file_t * native_f = (mrb_nil_p(f) ? NULL : mruby_unbox_apr_file_t(f));

  apr_socket_t * native_s = (mrb_nil_p(s) ? NULL : mruby_unbox_apr_socket_t(s));

  int native_for_read = mrb_fixnum(for_read);

  /* Invocation */
  apr_status_t result = apr_wait_for_io_or_timeout(native_f, native_s, native_for_read);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

void mrb_mruby_apr_gem_init(mrb_state* mrb) {
  RClass* APR_module = mrb_define_module(mrb, "APR");
  mruby_APR_define_macro_constants(mrb);

  mrb_define_class_under(mrb, APR_module, "AprTimeT", mrb->object_class);

  /*
   * Initialize class bindings
   */
#if BIND_AprAllocatorT_TYPE
  mrb_APR_AprAllocatorT_init(mrb);
#endif
#if BIND_AprArrayHeaderT_TYPE
  mrb_APR_AprArrayHeaderT_init(mrb);
#endif
#if BIND_AprCryptoHashT_TYPE
  mrb_APR_AprCryptoHashT_init(mrb);
#endif
#if BIND_AprDirT_TYPE
  mrb_APR_AprDirT_init(mrb);
#endif
#if BIND_AprDsoHandleT_TYPE
  mrb_APR_AprDsoHandleT_init(mrb);
#endif
#if BIND_AprFileT_TYPE
  mrb_APR_AprFileT_init(mrb);
#endif
#if BIND_AprFinfoT_TYPE
  mrb_APR_AprFinfoT_init(mrb);
#endif
#if BIND_AprGetoptOptionT_TYPE
  mrb_APR_AprGetoptOptionT_init(mrb);
#endif
#if BIND_AprGetoptT_TYPE
  mrb_APR_AprGetoptT_init(mrb);
#endif
#if BIND_AprHashIndexT_TYPE
  mrb_APR_AprHashIndexT_init(mrb);
#endif
#if BIND_AprHashT_TYPE
  mrb_APR_AprHashT_init(mrb);
#endif
#if BIND_AprHdtrT_TYPE
  mrb_APR_AprHdtrT_init(mrb);
#endif
#if BIND_AprIpsubnetT_TYPE
  mrb_APR_AprIpsubnetT_init(mrb);
#endif
#if BIND_AprMemnodeT_TYPE
  mrb_APR_AprMemnodeT_init(mrb);
#endif
#if BIND_AprMmapT_TYPE
  mrb_APR_AprMmapT_init(mrb);
#endif
#if BIND_AprOsSockInfoT_TYPE
  mrb_APR_AprOsSockInfoT_init(mrb);
#endif
#if BIND_AprOtherChildRecT_TYPE
  mrb_APR_AprOtherChildRecT_init(mrb);
#endif
#if BIND_AprPollcbT_TYPE
  mrb_APR_AprPollcbT_init(mrb);
#endif
#if BIND_AprPollfdT_TYPE
  mrb_APR_AprPollfdT_init(mrb);
#endif
#if BIND_AprPollsetT_TYPE
  mrb_APR_AprPollsetT_init(mrb);
#endif
#if BIND_AprPoolT_TYPE
  mrb_APR_AprPoolT_init(mrb);
#endif
#if BIND_AprProcMutexT_TYPE
  mrb_APR_AprProcMutexT_init(mrb);
#endif
#if BIND_AprProcT_TYPE
  mrb_APR_AprProcT_init(mrb);
#endif
#if BIND_AprProcattrT_TYPE
  mrb_APR_AprProcattrT_init(mrb);
#endif
#if BIND_AprRandomT_TYPE
  mrb_APR_AprRandomT_init(mrb);
#endif
#if BIND_AprShmT_TYPE
  mrb_APR_AprShmT_init(mrb);
#endif
#if BIND_AprSkiplist_TYPE
  mrb_APR_AprSkiplist_init(mrb);
#endif
#if BIND_AprSkiplistnode_TYPE
  mrb_APR_AprSkiplistnode_init(mrb);
#endif
#if BIND_AprSockaddrT_TYPE
  mrb_APR_AprSockaddrT_init(mrb);
#endif
#if BIND_AprSocketT_TYPE
  mrb_APR_AprSocketT_init(mrb);
#endif
#if BIND_AprTableEntryT_TYPE
  mrb_APR_AprTableEntryT_init(mrb);
#endif
#if BIND_AprTableT_TYPE
  mrb_APR_AprTableT_init(mrb);
#endif
#if BIND_AprThreadCondT_TYPE
  mrb_APR_AprThreadCondT_init(mrb);
#endif
#if BIND_AprThreadMutexT_TYPE
  mrb_APR_AprThreadMutexT_init(mrb);
#endif
#if BIND_AprThreadOnceT_TYPE
  mrb_APR_AprThreadOnceT_init(mrb);
#endif
#if BIND_AprThreadRwlockT_TYPE
  mrb_APR_AprThreadRwlockT_init(mrb);
#endif
#if BIND_AprThreadT_TYPE
  mrb_APR_AprThreadT_init(mrb);
#endif
#if BIND_AprThreadattrT_TYPE
  mrb_APR_AprThreadattrT_init(mrb);
#endif
#if BIND_AprThreadkeyT_TYPE
  mrb_APR_AprThreadkeyT_init(mrb);
#endif
#if BIND_AprTimeExpT_TYPE
  mrb_APR_AprTimeExpT_init(mrb);
#endif
#if BIND_AprVersionT_TYPE
  mrb_APR_AprVersionT_init(mrb);
#endif
#if BIND_AprVformatterBuffT_TYPE
  mrb_APR_AprVformatterBuffT_init(mrb);
#endif

  /*
   * Global Functions
   */
#if BIND_apr_allocator_alloc_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_allocator_alloc", mrb_APR_apr_allocator_alloc, MRB_ARGS_ARG(apr_allocator_alloc_REQUIRED_ARGC, apr_allocator_alloc_OPTIONAL_ARGC));
#endif
#if BIND_apr_allocator_create_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_allocator_create", mrb_APR_apr_allocator_create, MRB_ARGS_ARG(apr_allocator_create_REQUIRED_ARGC, apr_allocator_create_OPTIONAL_ARGC));
#endif
#if BIND_apr_allocator_destroy_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_allocator_destroy", mrb_APR_apr_allocator_destroy, MRB_ARGS_ARG(apr_allocator_destroy_REQUIRED_ARGC, apr_allocator_destroy_OPTIONAL_ARGC));
#endif
#if BIND_apr_allocator_free_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_allocator_free", mrb_APR_apr_allocator_free, MRB_ARGS_ARG(apr_allocator_free_REQUIRED_ARGC, apr_allocator_free_OPTIONAL_ARGC));
#endif
#if BIND_apr_allocator_max_free_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_allocator_max_free_set", mrb_APR_apr_allocator_max_free_set, MRB_ARGS_ARG(apr_allocator_max_free_set_REQUIRED_ARGC, apr_allocator_max_free_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_allocator_mutex_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_allocator_mutex_get", mrb_APR_apr_allocator_mutex_get, MRB_ARGS_ARG(apr_allocator_mutex_get_REQUIRED_ARGC, apr_allocator_mutex_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_allocator_mutex_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_allocator_mutex_set", mrb_APR_apr_allocator_mutex_set, MRB_ARGS_ARG(apr_allocator_mutex_set_REQUIRED_ARGC, apr_allocator_mutex_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_allocator_owner_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_allocator_owner_get", mrb_APR_apr_allocator_owner_get, MRB_ARGS_ARG(apr_allocator_owner_get_REQUIRED_ARGC, apr_allocator_owner_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_allocator_owner_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_allocator_owner_set", mrb_APR_apr_allocator_owner_set, MRB_ARGS_ARG(apr_allocator_owner_set_REQUIRED_ARGC, apr_allocator_owner_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_app_initialize_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_app_initialize", mrb_APR_apr_app_initialize, MRB_ARGS_ARG(apr_app_initialize_REQUIRED_ARGC, apr_app_initialize_OPTIONAL_ARGC));
#endif
#if BIND_apr_array_append_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_array_append", mrb_APR_apr_array_append, MRB_ARGS_ARG(apr_array_append_REQUIRED_ARGC, apr_array_append_OPTIONAL_ARGC));
#endif
#if BIND_apr_array_cat_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_array_cat", mrb_APR_apr_array_cat, MRB_ARGS_ARG(apr_array_cat_REQUIRED_ARGC, apr_array_cat_OPTIONAL_ARGC));
#endif
#if BIND_apr_array_clear_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_array_clear", mrb_APR_apr_array_clear, MRB_ARGS_ARG(apr_array_clear_REQUIRED_ARGC, apr_array_clear_OPTIONAL_ARGC));
#endif
#if BIND_apr_array_copy_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_array_copy", mrb_APR_apr_array_copy, MRB_ARGS_ARG(apr_array_copy_REQUIRED_ARGC, apr_array_copy_OPTIONAL_ARGC));
#endif
#if BIND_apr_array_copy_hdr_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_array_copy_hdr", mrb_APR_apr_array_copy_hdr, MRB_ARGS_ARG(apr_array_copy_hdr_REQUIRED_ARGC, apr_array_copy_hdr_OPTIONAL_ARGC));
#endif
#if BIND_apr_array_make_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_array_make", mrb_APR_apr_array_make, MRB_ARGS_ARG(apr_array_make_REQUIRED_ARGC, apr_array_make_OPTIONAL_ARGC));
#endif
#if BIND_apr_array_pop_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_array_pop", mrb_APR_apr_array_pop, MRB_ARGS_ARG(apr_array_pop_REQUIRED_ARGC, apr_array_pop_OPTIONAL_ARGC));
#endif
#if BIND_apr_array_pstrcat_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_array_pstrcat", mrb_APR_apr_array_pstrcat, MRB_ARGS_ARG(apr_array_pstrcat_REQUIRED_ARGC, apr_array_pstrcat_OPTIONAL_ARGC));
#endif
#if BIND_apr_array_push_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_array_push", mrb_APR_apr_array_push, MRB_ARGS_ARG(apr_array_push_REQUIRED_ARGC, apr_array_push_OPTIONAL_ARGC));
#endif
#if BIND_apr_atoi64_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_atoi64", mrb_APR_apr_atoi64, MRB_ARGS_ARG(apr_atoi64_REQUIRED_ARGC, apr_atoi64_OPTIONAL_ARGC));
#endif
#if BIND_apr_atomic_add32_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_atomic_add32", mrb_APR_apr_atomic_add32, MRB_ARGS_ARG(apr_atomic_add32_REQUIRED_ARGC, apr_atomic_add32_OPTIONAL_ARGC));
#endif
#if BIND_apr_atomic_cas32_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_atomic_cas32", mrb_APR_apr_atomic_cas32, MRB_ARGS_ARG(apr_atomic_cas32_REQUIRED_ARGC, apr_atomic_cas32_OPTIONAL_ARGC));
#endif
#if BIND_apr_atomic_casptr_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_atomic_casptr", mrb_APR_apr_atomic_casptr, MRB_ARGS_ARG(apr_atomic_casptr_REQUIRED_ARGC, apr_atomic_casptr_OPTIONAL_ARGC));
#endif
#if BIND_apr_atomic_dec32_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_atomic_dec32", mrb_APR_apr_atomic_dec32, MRB_ARGS_ARG(apr_atomic_dec32_REQUIRED_ARGC, apr_atomic_dec32_OPTIONAL_ARGC));
#endif
#if BIND_apr_atomic_inc32_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_atomic_inc32", mrb_APR_apr_atomic_inc32, MRB_ARGS_ARG(apr_atomic_inc32_REQUIRED_ARGC, apr_atomic_inc32_OPTIONAL_ARGC));
#endif
#if BIND_apr_atomic_init_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_atomic_init", mrb_APR_apr_atomic_init, MRB_ARGS_ARG(apr_atomic_init_REQUIRED_ARGC, apr_atomic_init_OPTIONAL_ARGC));
#endif
#if BIND_apr_atomic_read32_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_atomic_read32", mrb_APR_apr_atomic_read32, MRB_ARGS_ARG(apr_atomic_read32_REQUIRED_ARGC, apr_atomic_read32_OPTIONAL_ARGC));
#endif
#if BIND_apr_atomic_set32_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_atomic_set32", mrb_APR_apr_atomic_set32, MRB_ARGS_ARG(apr_atomic_set32_REQUIRED_ARGC, apr_atomic_set32_OPTIONAL_ARGC));
#endif
#if BIND_apr_atomic_sub32_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_atomic_sub32", mrb_APR_apr_atomic_sub32, MRB_ARGS_ARG(apr_atomic_sub32_REQUIRED_ARGC, apr_atomic_sub32_OPTIONAL_ARGC));
#endif
#if BIND_apr_atomic_xchg32_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_atomic_xchg32", mrb_APR_apr_atomic_xchg32, MRB_ARGS_ARG(apr_atomic_xchg32_REQUIRED_ARGC, apr_atomic_xchg32_OPTIONAL_ARGC));
#endif
#if BIND_apr_atomic_xchgptr_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_atomic_xchgptr", mrb_APR_apr_atomic_xchgptr, MRB_ARGS_ARG(apr_atomic_xchgptr_REQUIRED_ARGC, apr_atomic_xchgptr_OPTIONAL_ARGC));
#endif
#if BIND_apr_collapse_spaces_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_collapse_spaces", mrb_APR_apr_collapse_spaces, MRB_ARGS_ARG(apr_collapse_spaces_REQUIRED_ARGC, apr_collapse_spaces_OPTIONAL_ARGC));
#endif
#if BIND_apr_cpystrn_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_cpystrn", mrb_APR_apr_cpystrn, MRB_ARGS_ARG(apr_cpystrn_REQUIRED_ARGC, apr_cpystrn_OPTIONAL_ARGC));
#endif
#if BIND_apr_crypto_sha256_new_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_crypto_sha256_new", mrb_APR_apr_crypto_sha256_new, MRB_ARGS_ARG(apr_crypto_sha256_new_REQUIRED_ARGC, apr_crypto_sha256_new_OPTIONAL_ARGC));
#endif
#if BIND_apr_ctime_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_ctime", mrb_APR_apr_ctime, MRB_ARGS_ARG(apr_ctime_REQUIRED_ARGC, apr_ctime_OPTIONAL_ARGC));
#endif
#if BIND_apr_dir_close_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_dir_close", mrb_APR_apr_dir_close, MRB_ARGS_ARG(apr_dir_close_REQUIRED_ARGC, apr_dir_close_OPTIONAL_ARGC));
#endif
#if BIND_apr_dir_make_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_dir_make", mrb_APR_apr_dir_make, MRB_ARGS_ARG(apr_dir_make_REQUIRED_ARGC, apr_dir_make_OPTIONAL_ARGC));
#endif
#if BIND_apr_dir_make_recursive_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_dir_make_recursive", mrb_APR_apr_dir_make_recursive, MRB_ARGS_ARG(apr_dir_make_recursive_REQUIRED_ARGC, apr_dir_make_recursive_OPTIONAL_ARGC));
#endif
#if BIND_apr_dir_open_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_dir_open", mrb_APR_apr_dir_open, MRB_ARGS_ARG(apr_dir_open_REQUIRED_ARGC, apr_dir_open_OPTIONAL_ARGC));
#endif
#if BIND_apr_dir_read_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_dir_read", mrb_APR_apr_dir_read, MRB_ARGS_ARG(apr_dir_read_REQUIRED_ARGC, apr_dir_read_OPTIONAL_ARGC));
#endif
#if BIND_apr_dir_remove_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_dir_remove", mrb_APR_apr_dir_remove, MRB_ARGS_ARG(apr_dir_remove_REQUIRED_ARGC, apr_dir_remove_OPTIONAL_ARGC));
#endif
#if BIND_apr_dir_rewind_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_dir_rewind", mrb_APR_apr_dir_rewind, MRB_ARGS_ARG(apr_dir_rewind_REQUIRED_ARGC, apr_dir_rewind_OPTIONAL_ARGC));
#endif
#if BIND_apr_dso_error_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_dso_error", mrb_APR_apr_dso_error, MRB_ARGS_ARG(apr_dso_error_REQUIRED_ARGC, apr_dso_error_OPTIONAL_ARGC));
#endif
#if BIND_apr_dso_load_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_dso_load", mrb_APR_apr_dso_load, MRB_ARGS_ARG(apr_dso_load_REQUIRED_ARGC, apr_dso_load_OPTIONAL_ARGC));
#endif
#if BIND_apr_dso_sym_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_dso_sym", mrb_APR_apr_dso_sym, MRB_ARGS_ARG(apr_dso_sym_REQUIRED_ARGC, apr_dso_sym_OPTIONAL_ARGC));
#endif
#if BIND_apr_dso_unload_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_dso_unload", mrb_APR_apr_dso_unload, MRB_ARGS_ARG(apr_dso_unload_REQUIRED_ARGC, apr_dso_unload_OPTIONAL_ARGC));
#endif
#if BIND_apr_env_delete_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_env_delete", mrb_APR_apr_env_delete, MRB_ARGS_ARG(apr_env_delete_REQUIRED_ARGC, apr_env_delete_OPTIONAL_ARGC));
#endif
#if BIND_apr_env_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_env_get", mrb_APR_apr_env_get, MRB_ARGS_ARG(apr_env_get_REQUIRED_ARGC, apr_env_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_env_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_env_set", mrb_APR_apr_env_set, MRB_ARGS_ARG(apr_env_set_REQUIRED_ARGC, apr_env_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_escape_echo_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_escape_echo", mrb_APR_apr_escape_echo, MRB_ARGS_ARG(apr_escape_echo_REQUIRED_ARGC, apr_escape_echo_OPTIONAL_ARGC));
#endif
#if BIND_apr_escape_entity_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_escape_entity", mrb_APR_apr_escape_entity, MRB_ARGS_ARG(apr_escape_entity_REQUIRED_ARGC, apr_escape_entity_OPTIONAL_ARGC));
#endif
#if BIND_apr_escape_hex_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_escape_hex", mrb_APR_apr_escape_hex, MRB_ARGS_ARG(apr_escape_hex_REQUIRED_ARGC, apr_escape_hex_OPTIONAL_ARGC));
#endif
#if BIND_apr_escape_path_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_escape_path", mrb_APR_apr_escape_path, MRB_ARGS_ARG(apr_escape_path_REQUIRED_ARGC, apr_escape_path_OPTIONAL_ARGC));
#endif
#if BIND_apr_escape_path_segment_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_escape_path_segment", mrb_APR_apr_escape_path_segment, MRB_ARGS_ARG(apr_escape_path_segment_REQUIRED_ARGC, apr_escape_path_segment_OPTIONAL_ARGC));
#endif
#if BIND_apr_escape_shell_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_escape_shell", mrb_APR_apr_escape_shell, MRB_ARGS_ARG(apr_escape_shell_REQUIRED_ARGC, apr_escape_shell_OPTIONAL_ARGC));
#endif
#if BIND_apr_escape_urlencoded_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_escape_urlencoded", mrb_APR_apr_escape_urlencoded, MRB_ARGS_ARG(apr_escape_urlencoded_REQUIRED_ARGC, apr_escape_urlencoded_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_append_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_append", mrb_APR_apr_file_append, MRB_ARGS_ARG(apr_file_append_REQUIRED_ARGC, apr_file_append_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_attrs_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_attrs_set", mrb_APR_apr_file_attrs_set, MRB_ARGS_ARG(apr_file_attrs_set_REQUIRED_ARGC, apr_file_attrs_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_buffer_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_buffer_set", mrb_APR_apr_file_buffer_set, MRB_ARGS_ARG(apr_file_buffer_set_REQUIRED_ARGC, apr_file_buffer_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_buffer_size_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_buffer_size_get", mrb_APR_apr_file_buffer_size_get, MRB_ARGS_ARG(apr_file_buffer_size_get_REQUIRED_ARGC, apr_file_buffer_size_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_close_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_close", mrb_APR_apr_file_close, MRB_ARGS_ARG(apr_file_close_REQUIRED_ARGC, apr_file_close_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_copy_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_copy", mrb_APR_apr_file_copy, MRB_ARGS_ARG(apr_file_copy_REQUIRED_ARGC, apr_file_copy_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_data_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_data_get", mrb_APR_apr_file_data_get, MRB_ARGS_ARG(apr_file_data_get_REQUIRED_ARGC, apr_file_data_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_data_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_data_set", mrb_APR_apr_file_data_set, MRB_ARGS_ARG(apr_file_data_set_REQUIRED_ARGC, apr_file_data_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_datasync_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_datasync", mrb_APR_apr_file_datasync, MRB_ARGS_ARG(apr_file_datasync_REQUIRED_ARGC, apr_file_datasync_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_dup_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_dup", mrb_APR_apr_file_dup, MRB_ARGS_ARG(apr_file_dup_REQUIRED_ARGC, apr_file_dup_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_dup2_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_dup2", mrb_APR_apr_file_dup2, MRB_ARGS_ARG(apr_file_dup2_REQUIRED_ARGC, apr_file_dup2_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_eof_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_eof", mrb_APR_apr_file_eof, MRB_ARGS_ARG(apr_file_eof_REQUIRED_ARGC, apr_file_eof_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_flags_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_flags_get", mrb_APR_apr_file_flags_get, MRB_ARGS_ARG(apr_file_flags_get_REQUIRED_ARGC, apr_file_flags_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_flush_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_flush", mrb_APR_apr_file_flush, MRB_ARGS_ARG(apr_file_flush_REQUIRED_ARGC, apr_file_flush_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_getc_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_getc", mrb_APR_apr_file_getc, MRB_ARGS_ARG(apr_file_getc_REQUIRED_ARGC, apr_file_getc_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_gets_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_gets", mrb_APR_apr_file_gets, MRB_ARGS_ARG(apr_file_gets_REQUIRED_ARGC, apr_file_gets_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_info_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_info_get", mrb_APR_apr_file_info_get, MRB_ARGS_ARG(apr_file_info_get_REQUIRED_ARGC, apr_file_info_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_link_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_link", mrb_APR_apr_file_link, MRB_ARGS_ARG(apr_file_link_REQUIRED_ARGC, apr_file_link_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_lock_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_lock", mrb_APR_apr_file_lock, MRB_ARGS_ARG(apr_file_lock_REQUIRED_ARGC, apr_file_lock_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_mktemp_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_mktemp", mrb_APR_apr_file_mktemp, MRB_ARGS_ARG(apr_file_mktemp_REQUIRED_ARGC, apr_file_mktemp_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_mtime_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_mtime_set", mrb_APR_apr_file_mtime_set, MRB_ARGS_ARG(apr_file_mtime_set_REQUIRED_ARGC, apr_file_mtime_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_name_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_name_get", mrb_APR_apr_file_name_get, MRB_ARGS_ARG(apr_file_name_get_REQUIRED_ARGC, apr_file_name_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_namedpipe_create_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_namedpipe_create", mrb_APR_apr_file_namedpipe_create, MRB_ARGS_ARG(apr_file_namedpipe_create_REQUIRED_ARGC, apr_file_namedpipe_create_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_open_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_open", mrb_APR_apr_file_open, MRB_ARGS_ARG(apr_file_open_REQUIRED_ARGC, apr_file_open_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_open_flags_stderr_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_open_flags_stderr", mrb_APR_apr_file_open_flags_stderr, MRB_ARGS_ARG(apr_file_open_flags_stderr_REQUIRED_ARGC, apr_file_open_flags_stderr_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_open_flags_stdin_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_open_flags_stdin", mrb_APR_apr_file_open_flags_stdin, MRB_ARGS_ARG(apr_file_open_flags_stdin_REQUIRED_ARGC, apr_file_open_flags_stdin_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_open_flags_stdout_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_open_flags_stdout", mrb_APR_apr_file_open_flags_stdout, MRB_ARGS_ARG(apr_file_open_flags_stdout_REQUIRED_ARGC, apr_file_open_flags_stdout_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_open_stderr_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_open_stderr", mrb_APR_apr_file_open_stderr, MRB_ARGS_ARG(apr_file_open_stderr_REQUIRED_ARGC, apr_file_open_stderr_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_open_stdin_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_open_stdin", mrb_APR_apr_file_open_stdin, MRB_ARGS_ARG(apr_file_open_stdin_REQUIRED_ARGC, apr_file_open_stdin_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_open_stdout_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_open_stdout", mrb_APR_apr_file_open_stdout, MRB_ARGS_ARG(apr_file_open_stdout_REQUIRED_ARGC, apr_file_open_stdout_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_perms_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_perms_set", mrb_APR_apr_file_perms_set, MRB_ARGS_ARG(apr_file_perms_set_REQUIRED_ARGC, apr_file_perms_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_pipe_create_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_pipe_create", mrb_APR_apr_file_pipe_create, MRB_ARGS_ARG(apr_file_pipe_create_REQUIRED_ARGC, apr_file_pipe_create_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_pipe_create_ex_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_pipe_create_ex", mrb_APR_apr_file_pipe_create_ex, MRB_ARGS_ARG(apr_file_pipe_create_ex_REQUIRED_ARGC, apr_file_pipe_create_ex_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_pipe_timeout_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_pipe_timeout_get", mrb_APR_apr_file_pipe_timeout_get, MRB_ARGS_ARG(apr_file_pipe_timeout_get_REQUIRED_ARGC, apr_file_pipe_timeout_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_pipe_timeout_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_pipe_timeout_set", mrb_APR_apr_file_pipe_timeout_set, MRB_ARGS_ARG(apr_file_pipe_timeout_set_REQUIRED_ARGC, apr_file_pipe_timeout_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_printf_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_printf", mrb_APR_apr_file_printf, MRB_ARGS_ARG(apr_file_printf_REQUIRED_ARGC, apr_file_printf_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_putc_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_putc", mrb_APR_apr_file_putc, MRB_ARGS_ARG(apr_file_putc_REQUIRED_ARGC, apr_file_putc_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_puts_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_puts", mrb_APR_apr_file_puts, MRB_ARGS_ARG(apr_file_puts_REQUIRED_ARGC, apr_file_puts_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_read_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_read", mrb_APR_apr_file_read, MRB_ARGS_ARG(apr_file_read_REQUIRED_ARGC, apr_file_read_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_read_full_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_read_full", mrb_APR_apr_file_read_full, MRB_ARGS_ARG(apr_file_read_full_REQUIRED_ARGC, apr_file_read_full_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_remove_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_remove", mrb_APR_apr_file_remove, MRB_ARGS_ARG(apr_file_remove_REQUIRED_ARGC, apr_file_remove_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_rename_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_rename", mrb_APR_apr_file_rename, MRB_ARGS_ARG(apr_file_rename_REQUIRED_ARGC, apr_file_rename_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_seek_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_seek", mrb_APR_apr_file_seek, MRB_ARGS_ARG(apr_file_seek_REQUIRED_ARGC, apr_file_seek_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_setaside_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_setaside", mrb_APR_apr_file_setaside, MRB_ARGS_ARG(apr_file_setaside_REQUIRED_ARGC, apr_file_setaside_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_sync_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_sync", mrb_APR_apr_file_sync, MRB_ARGS_ARG(apr_file_sync_REQUIRED_ARGC, apr_file_sync_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_trunc_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_trunc", mrb_APR_apr_file_trunc, MRB_ARGS_ARG(apr_file_trunc_REQUIRED_ARGC, apr_file_trunc_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_ungetc_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_ungetc", mrb_APR_apr_file_ungetc, MRB_ARGS_ARG(apr_file_ungetc_REQUIRED_ARGC, apr_file_ungetc_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_unlock_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_unlock", mrb_APR_apr_file_unlock, MRB_ARGS_ARG(apr_file_unlock_REQUIRED_ARGC, apr_file_unlock_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_write_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_write", mrb_APR_apr_file_write, MRB_ARGS_ARG(apr_file_write_REQUIRED_ARGC, apr_file_write_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_write_full_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_write_full", mrb_APR_apr_file_write_full, MRB_ARGS_ARG(apr_file_write_full_REQUIRED_ARGC, apr_file_write_full_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_writev_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_writev", mrb_APR_apr_file_writev, MRB_ARGS_ARG(apr_file_writev_REQUIRED_ARGC, apr_file_writev_OPTIONAL_ARGC));
#endif
#if BIND_apr_file_writev_full_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_file_writev_full", mrb_APR_apr_file_writev_full, MRB_ARGS_ARG(apr_file_writev_full_REQUIRED_ARGC, apr_file_writev_full_OPTIONAL_ARGC));
#endif
#if BIND_apr_filepath_encoding_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_filepath_encoding", mrb_APR_apr_filepath_encoding, MRB_ARGS_ARG(apr_filepath_encoding_REQUIRED_ARGC, apr_filepath_encoding_OPTIONAL_ARGC));
#endif
#if BIND_apr_filepath_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_filepath_get", mrb_APR_apr_filepath_get, MRB_ARGS_ARG(apr_filepath_get_REQUIRED_ARGC, apr_filepath_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_filepath_list_merge_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_filepath_list_merge", mrb_APR_apr_filepath_list_merge, MRB_ARGS_ARG(apr_filepath_list_merge_REQUIRED_ARGC, apr_filepath_list_merge_OPTIONAL_ARGC));
#endif
#if BIND_apr_filepath_list_split_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_filepath_list_split", mrb_APR_apr_filepath_list_split, MRB_ARGS_ARG(apr_filepath_list_split_REQUIRED_ARGC, apr_filepath_list_split_OPTIONAL_ARGC));
#endif
#if BIND_apr_filepath_merge_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_filepath_merge", mrb_APR_apr_filepath_merge, MRB_ARGS_ARG(apr_filepath_merge_REQUIRED_ARGC, apr_filepath_merge_OPTIONAL_ARGC));
#endif
#if BIND_apr_filepath_name_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_filepath_name_get", mrb_APR_apr_filepath_name_get, MRB_ARGS_ARG(apr_filepath_name_get_REQUIRED_ARGC, apr_filepath_name_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_filepath_root_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_filepath_root", mrb_APR_apr_filepath_root, MRB_ARGS_ARG(apr_filepath_root_REQUIRED_ARGC, apr_filepath_root_OPTIONAL_ARGC));
#endif
#if BIND_apr_filepath_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_filepath_set", mrb_APR_apr_filepath_set, MRB_ARGS_ARG(apr_filepath_set_REQUIRED_ARGC, apr_filepath_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_fnmatch_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_fnmatch", mrb_APR_apr_fnmatch, MRB_ARGS_ARG(apr_fnmatch_REQUIRED_ARGC, apr_fnmatch_OPTIONAL_ARGC));
#endif
#if BIND_apr_fnmatch_test_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_fnmatch_test", mrb_APR_apr_fnmatch_test, MRB_ARGS_ARG(apr_fnmatch_test_REQUIRED_ARGC, apr_fnmatch_test_OPTIONAL_ARGC));
#endif
#if BIND_apr_generate_random_bytes_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_generate_random_bytes", mrb_APR_apr_generate_random_bytes, MRB_ARGS_ARG(apr_generate_random_bytes_REQUIRED_ARGC, apr_generate_random_bytes_OPTIONAL_ARGC));
#endif
#if BIND_apr_gethostname_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_gethostname", mrb_APR_apr_gethostname, MRB_ARGS_ARG(apr_gethostname_REQUIRED_ARGC, apr_gethostname_OPTIONAL_ARGC));
#endif
#if BIND_apr_getnameinfo_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_getnameinfo", mrb_APR_apr_getnameinfo, MRB_ARGS_ARG(apr_getnameinfo_REQUIRED_ARGC, apr_getnameinfo_OPTIONAL_ARGC));
#endif
#if BIND_apr_getopt_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_getopt", mrb_APR_apr_getopt, MRB_ARGS_ARG(apr_getopt_REQUIRED_ARGC, apr_getopt_OPTIONAL_ARGC));
#endif
#if BIND_apr_getopt_init_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_getopt_init", mrb_APR_apr_getopt_init, MRB_ARGS_ARG(apr_getopt_init_REQUIRED_ARGC, apr_getopt_init_OPTIONAL_ARGC));
#endif
#if BIND_apr_getopt_long_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_getopt_long", mrb_APR_apr_getopt_long, MRB_ARGS_ARG(apr_getopt_long_REQUIRED_ARGC, apr_getopt_long_OPTIONAL_ARGC));
#endif
#if BIND_apr_getservbyname_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_getservbyname", mrb_APR_apr_getservbyname, MRB_ARGS_ARG(apr_getservbyname_REQUIRED_ARGC, apr_getservbyname_OPTIONAL_ARGC));
#endif
#if BIND_apr_gid_compare_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_gid_compare", mrb_APR_apr_gid_compare, MRB_ARGS_ARG(apr_gid_compare_REQUIRED_ARGC, apr_gid_compare_OPTIONAL_ARGC));
#endif
#if BIND_apr_gid_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_gid_get", mrb_APR_apr_gid_get, MRB_ARGS_ARG(apr_gid_get_REQUIRED_ARGC, apr_gid_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_gid_name_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_gid_name_get", mrb_APR_apr_gid_name_get, MRB_ARGS_ARG(apr_gid_name_get_REQUIRED_ARGC, apr_gid_name_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_hash_clear_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_hash_clear", mrb_APR_apr_hash_clear, MRB_ARGS_ARG(apr_hash_clear_REQUIRED_ARGC, apr_hash_clear_OPTIONAL_ARGC));
#endif
#if BIND_apr_hash_copy_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_hash_copy", mrb_APR_apr_hash_copy, MRB_ARGS_ARG(apr_hash_copy_REQUIRED_ARGC, apr_hash_copy_OPTIONAL_ARGC));
#endif
#if BIND_apr_hash_count_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_hash_count", mrb_APR_apr_hash_count, MRB_ARGS_ARG(apr_hash_count_REQUIRED_ARGC, apr_hash_count_OPTIONAL_ARGC));
#endif
#if BIND_apr_hash_do_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_hash_do", mrb_APR_apr_hash_do, MRB_ARGS_ARG(apr_hash_do_REQUIRED_ARGC, apr_hash_do_OPTIONAL_ARGC));
#endif
#if BIND_apr_hash_first_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_hash_first", mrb_APR_apr_hash_first, MRB_ARGS_ARG(apr_hash_first_REQUIRED_ARGC, apr_hash_first_OPTIONAL_ARGC));
#endif
#if BIND_apr_hash_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_hash_get", mrb_APR_apr_hash_get, MRB_ARGS_ARG(apr_hash_get_REQUIRED_ARGC, apr_hash_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_hash_make_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_hash_make", mrb_APR_apr_hash_make, MRB_ARGS_ARG(apr_hash_make_REQUIRED_ARGC, apr_hash_make_OPTIONAL_ARGC));
#endif
#if BIND_apr_hash_make_custom_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_hash_make_custom", mrb_APR_apr_hash_make_custom, MRB_ARGS_ARG(apr_hash_make_custom_REQUIRED_ARGC, apr_hash_make_custom_OPTIONAL_ARGC));
#endif
#if BIND_apr_hash_merge_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_hash_merge", mrb_APR_apr_hash_merge, MRB_ARGS_ARG(apr_hash_merge_REQUIRED_ARGC, apr_hash_merge_OPTIONAL_ARGC));
#endif
#if BIND_apr_hash_next_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_hash_next", mrb_APR_apr_hash_next, MRB_ARGS_ARG(apr_hash_next_REQUIRED_ARGC, apr_hash_next_OPTIONAL_ARGC));
#endif
#if BIND_apr_hash_overlay_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_hash_overlay", mrb_APR_apr_hash_overlay, MRB_ARGS_ARG(apr_hash_overlay_REQUIRED_ARGC, apr_hash_overlay_OPTIONAL_ARGC));
#endif
#if BIND_apr_hash_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_hash_set", mrb_APR_apr_hash_set, MRB_ARGS_ARG(apr_hash_set_REQUIRED_ARGC, apr_hash_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_hash_this_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_hash_this", mrb_APR_apr_hash_this, MRB_ARGS_ARG(apr_hash_this_REQUIRED_ARGC, apr_hash_this_OPTIONAL_ARGC));
#endif
#if BIND_apr_hash_this_key_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_hash_this_key", mrb_APR_apr_hash_this_key, MRB_ARGS_ARG(apr_hash_this_key_REQUIRED_ARGC, apr_hash_this_key_OPTIONAL_ARGC));
#endif
#if BIND_apr_hash_this_key_len_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_hash_this_key_len", mrb_APR_apr_hash_this_key_len, MRB_ARGS_ARG(apr_hash_this_key_len_REQUIRED_ARGC, apr_hash_this_key_len_OPTIONAL_ARGC));
#endif
#if BIND_apr_hash_this_val_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_hash_this_val", mrb_APR_apr_hash_this_val, MRB_ARGS_ARG(apr_hash_this_val_REQUIRED_ARGC, apr_hash_this_val_OPTIONAL_ARGC));
#endif
#if BIND_apr_hashfunc_default_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_hashfunc_default", mrb_APR_apr_hashfunc_default, MRB_ARGS_ARG(apr_hashfunc_default_REQUIRED_ARGC, apr_hashfunc_default_OPTIONAL_ARGC));
#endif
#if BIND_apr_initialize_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_initialize", mrb_APR_apr_initialize, MRB_ARGS_ARG(apr_initialize_REQUIRED_ARGC, apr_initialize_OPTIONAL_ARGC));
#endif
#if BIND_apr_ipsubnet_create_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_ipsubnet_create", mrb_APR_apr_ipsubnet_create, MRB_ARGS_ARG(apr_ipsubnet_create_REQUIRED_ARGC, apr_ipsubnet_create_OPTIONAL_ARGC));
#endif
#if BIND_apr_ipsubnet_test_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_ipsubnet_test", mrb_APR_apr_ipsubnet_test, MRB_ARGS_ARG(apr_ipsubnet_test_REQUIRED_ARGC, apr_ipsubnet_test_OPTIONAL_ARGC));
#endif
#if BIND_apr_is_empty_array_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_is_empty_array", mrb_APR_apr_is_empty_array, MRB_ARGS_ARG(apr_is_empty_array_REQUIRED_ARGC, apr_is_empty_array_OPTIONAL_ARGC));
#endif
#if BIND_apr_is_empty_table_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_is_empty_table", mrb_APR_apr_is_empty_table, MRB_ARGS_ARG(apr_is_empty_table_REQUIRED_ARGC, apr_is_empty_table_OPTIONAL_ARGC));
#endif
#if BIND_apr_itoa_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_itoa", mrb_APR_apr_itoa, MRB_ARGS_ARG(apr_itoa_REQUIRED_ARGC, apr_itoa_OPTIONAL_ARGC));
#endif
#if BIND_apr_ltoa_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_ltoa", mrb_APR_apr_ltoa, MRB_ARGS_ARG(apr_ltoa_REQUIRED_ARGC, apr_ltoa_OPTIONAL_ARGC));
#endif
#if BIND_apr_match_glob_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_match_glob", mrb_APR_apr_match_glob, MRB_ARGS_ARG(apr_match_glob_REQUIRED_ARGC, apr_match_glob_OPTIONAL_ARGC));
#endif
#if BIND_apr_mcast_hops_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_mcast_hops", mrb_APR_apr_mcast_hops, MRB_ARGS_ARG(apr_mcast_hops_REQUIRED_ARGC, apr_mcast_hops_OPTIONAL_ARGC));
#endif
#if BIND_apr_mcast_interface_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_mcast_interface", mrb_APR_apr_mcast_interface, MRB_ARGS_ARG(apr_mcast_interface_REQUIRED_ARGC, apr_mcast_interface_OPTIONAL_ARGC));
#endif
#if BIND_apr_mcast_join_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_mcast_join", mrb_APR_apr_mcast_join, MRB_ARGS_ARG(apr_mcast_join_REQUIRED_ARGC, apr_mcast_join_OPTIONAL_ARGC));
#endif
#if BIND_apr_mcast_leave_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_mcast_leave", mrb_APR_apr_mcast_leave, MRB_ARGS_ARG(apr_mcast_leave_REQUIRED_ARGC, apr_mcast_leave_OPTIONAL_ARGC));
#endif
#if BIND_apr_mcast_loopback_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_mcast_loopback", mrb_APR_apr_mcast_loopback, MRB_ARGS_ARG(apr_mcast_loopback_REQUIRED_ARGC, apr_mcast_loopback_OPTIONAL_ARGC));
#endif
#if BIND_apr_mmap_create_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_mmap_create", mrb_APR_apr_mmap_create, MRB_ARGS_ARG(apr_mmap_create_REQUIRED_ARGC, apr_mmap_create_OPTIONAL_ARGC));
#endif
#if BIND_apr_mmap_delete_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_mmap_delete", mrb_APR_apr_mmap_delete, MRB_ARGS_ARG(apr_mmap_delete_REQUIRED_ARGC, apr_mmap_delete_OPTIONAL_ARGC));
#endif
#if BIND_apr_mmap_dup_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_mmap_dup", mrb_APR_apr_mmap_dup, MRB_ARGS_ARG(apr_mmap_dup_REQUIRED_ARGC, apr_mmap_dup_OPTIONAL_ARGC));
#endif
#if BIND_apr_mmap_offset_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_mmap_offset", mrb_APR_apr_mmap_offset, MRB_ARGS_ARG(apr_mmap_offset_REQUIRED_ARGC, apr_mmap_offset_OPTIONAL_ARGC));
#endif
#if BIND_apr_off_t_toa_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_off_t_toa", mrb_APR_apr_off_t_toa, MRB_ARGS_ARG(apr_off_t_toa_REQUIRED_ARGC, apr_off_t_toa_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_default_encoding_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_default_encoding", mrb_APR_apr_os_default_encoding, MRB_ARGS_ARG(apr_os_default_encoding_REQUIRED_ARGC, apr_os_default_encoding_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_dir_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_dir_get", mrb_APR_apr_os_dir_get, MRB_ARGS_ARG(apr_os_dir_get_REQUIRED_ARGC, apr_os_dir_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_dir_put_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_dir_put", mrb_APR_apr_os_dir_put, MRB_ARGS_ARG(apr_os_dir_put_REQUIRED_ARGC, apr_os_dir_put_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_dso_handle_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_dso_handle_get", mrb_APR_apr_os_dso_handle_get, MRB_ARGS_ARG(apr_os_dso_handle_get_REQUIRED_ARGC, apr_os_dso_handle_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_dso_handle_put_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_dso_handle_put", mrb_APR_apr_os_dso_handle_put, MRB_ARGS_ARG(apr_os_dso_handle_put_REQUIRED_ARGC, apr_os_dso_handle_put_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_exp_time_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_exp_time_get", mrb_APR_apr_os_exp_time_get, MRB_ARGS_ARG(apr_os_exp_time_get_REQUIRED_ARGC, apr_os_exp_time_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_exp_time_put_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_exp_time_put", mrb_APR_apr_os_exp_time_put, MRB_ARGS_ARG(apr_os_exp_time_put_REQUIRED_ARGC, apr_os_exp_time_put_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_file_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_file_get", mrb_APR_apr_os_file_get, MRB_ARGS_ARG(apr_os_file_get_REQUIRED_ARGC, apr_os_file_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_file_put_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_file_put", mrb_APR_apr_os_file_put, MRB_ARGS_ARG(apr_os_file_put_REQUIRED_ARGC, apr_os_file_put_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_imp_time_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_imp_time_get", mrb_APR_apr_os_imp_time_get, MRB_ARGS_ARG(apr_os_imp_time_get_REQUIRED_ARGC, apr_os_imp_time_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_imp_time_put_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_imp_time_put", mrb_APR_apr_os_imp_time_put, MRB_ARGS_ARG(apr_os_imp_time_put_REQUIRED_ARGC, apr_os_imp_time_put_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_locale_encoding_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_locale_encoding", mrb_APR_apr_os_locale_encoding, MRB_ARGS_ARG(apr_os_locale_encoding_REQUIRED_ARGC, apr_os_locale_encoding_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_pipe_put_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_pipe_put", mrb_APR_apr_os_pipe_put, MRB_ARGS_ARG(apr_os_pipe_put_REQUIRED_ARGC, apr_os_pipe_put_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_pipe_put_ex_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_pipe_put_ex", mrb_APR_apr_os_pipe_put_ex, MRB_ARGS_ARG(apr_os_pipe_put_ex_REQUIRED_ARGC, apr_os_pipe_put_ex_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_proc_mutex_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_proc_mutex_get", mrb_APR_apr_os_proc_mutex_get, MRB_ARGS_ARG(apr_os_proc_mutex_get_REQUIRED_ARGC, apr_os_proc_mutex_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_proc_mutex_put_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_proc_mutex_put", mrb_APR_apr_os_proc_mutex_put, MRB_ARGS_ARG(apr_os_proc_mutex_put_REQUIRED_ARGC, apr_os_proc_mutex_put_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_shm_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_shm_get", mrb_APR_apr_os_shm_get, MRB_ARGS_ARG(apr_os_shm_get_REQUIRED_ARGC, apr_os_shm_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_shm_put_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_shm_put", mrb_APR_apr_os_shm_put, MRB_ARGS_ARG(apr_os_shm_put_REQUIRED_ARGC, apr_os_shm_put_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_sock_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_sock_get", mrb_APR_apr_os_sock_get, MRB_ARGS_ARG(apr_os_sock_get_REQUIRED_ARGC, apr_os_sock_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_sock_make_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_sock_make", mrb_APR_apr_os_sock_make, MRB_ARGS_ARG(apr_os_sock_make_REQUIRED_ARGC, apr_os_sock_make_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_sock_put_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_sock_put", mrb_APR_apr_os_sock_put, MRB_ARGS_ARG(apr_os_sock_put_REQUIRED_ARGC, apr_os_sock_put_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_thread_current_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_thread_current", mrb_APR_apr_os_thread_current, MRB_ARGS_ARG(apr_os_thread_current_REQUIRED_ARGC, apr_os_thread_current_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_thread_equal_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_thread_equal", mrb_APR_apr_os_thread_equal, MRB_ARGS_ARG(apr_os_thread_equal_REQUIRED_ARGC, apr_os_thread_equal_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_thread_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_thread_get", mrb_APR_apr_os_thread_get, MRB_ARGS_ARG(apr_os_thread_get_REQUIRED_ARGC, apr_os_thread_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_thread_put_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_thread_put", mrb_APR_apr_os_thread_put, MRB_ARGS_ARG(apr_os_thread_put_REQUIRED_ARGC, apr_os_thread_put_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_threadkey_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_threadkey_get", mrb_APR_apr_os_threadkey_get, MRB_ARGS_ARG(apr_os_threadkey_get_REQUIRED_ARGC, apr_os_threadkey_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_threadkey_put_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_threadkey_put", mrb_APR_apr_os_threadkey_put, MRB_ARGS_ARG(apr_os_threadkey_put_REQUIRED_ARGC, apr_os_threadkey_put_OPTIONAL_ARGC));
#endif
#if BIND_apr_os_uuid_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_os_uuid_get", mrb_APR_apr_os_uuid_get, MRB_ARGS_ARG(apr_os_uuid_get_REQUIRED_ARGC, apr_os_uuid_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_palloc_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_palloc", mrb_APR_apr_palloc, MRB_ARGS_ARG(apr_palloc_REQUIRED_ARGC, apr_palloc_OPTIONAL_ARGC));
#endif
#if BIND_apr_palloc_debug_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_palloc_debug", mrb_APR_apr_palloc_debug, MRB_ARGS_ARG(apr_palloc_debug_REQUIRED_ARGC, apr_palloc_debug_OPTIONAL_ARGC));
#endif
#if BIND_apr_parse_addr_port_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_parse_addr_port", mrb_APR_apr_parse_addr_port, MRB_ARGS_ARG(apr_parse_addr_port_REQUIRED_ARGC, apr_parse_addr_port_OPTIONAL_ARGC));
#endif
#if BIND_apr_password_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_password_get", mrb_APR_apr_password_get, MRB_ARGS_ARG(apr_password_get_REQUIRED_ARGC, apr_password_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_pcalloc_debug_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pcalloc_debug", mrb_APR_apr_pcalloc_debug, MRB_ARGS_ARG(apr_pcalloc_debug_REQUIRED_ARGC, apr_pcalloc_debug_OPTIONAL_ARGC));
#endif
#if BIND_apr_pescape_echo_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pescape_echo", mrb_APR_apr_pescape_echo, MRB_ARGS_ARG(apr_pescape_echo_REQUIRED_ARGC, apr_pescape_echo_OPTIONAL_ARGC));
#endif
#if BIND_apr_pescape_entity_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pescape_entity", mrb_APR_apr_pescape_entity, MRB_ARGS_ARG(apr_pescape_entity_REQUIRED_ARGC, apr_pescape_entity_OPTIONAL_ARGC));
#endif
#if BIND_apr_pescape_hex_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pescape_hex", mrb_APR_apr_pescape_hex, MRB_ARGS_ARG(apr_pescape_hex_REQUIRED_ARGC, apr_pescape_hex_OPTIONAL_ARGC));
#endif
#if BIND_apr_pescape_path_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pescape_path", mrb_APR_apr_pescape_path, MRB_ARGS_ARG(apr_pescape_path_REQUIRED_ARGC, apr_pescape_path_OPTIONAL_ARGC));
#endif
#if BIND_apr_pescape_path_segment_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pescape_path_segment", mrb_APR_apr_pescape_path_segment, MRB_ARGS_ARG(apr_pescape_path_segment_REQUIRED_ARGC, apr_pescape_path_segment_OPTIONAL_ARGC));
#endif
#if BIND_apr_pescape_shell_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pescape_shell", mrb_APR_apr_pescape_shell, MRB_ARGS_ARG(apr_pescape_shell_REQUIRED_ARGC, apr_pescape_shell_OPTIONAL_ARGC));
#endif
#if BIND_apr_pescape_urlencoded_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pescape_urlencoded", mrb_APR_apr_pescape_urlencoded, MRB_ARGS_ARG(apr_pescape_urlencoded_REQUIRED_ARGC, apr_pescape_urlencoded_OPTIONAL_ARGC));
#endif
#if BIND_apr_pmemdup_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pmemdup", mrb_APR_apr_pmemdup, MRB_ARGS_ARG(apr_pmemdup_REQUIRED_ARGC, apr_pmemdup_OPTIONAL_ARGC));
#endif
#if BIND_apr_poll_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_poll", mrb_APR_apr_poll, MRB_ARGS_ARG(apr_poll_REQUIRED_ARGC, apr_poll_OPTIONAL_ARGC));
#endif
#if BIND_apr_poll_method_defname_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_poll_method_defname", mrb_APR_apr_poll_method_defname, MRB_ARGS_ARG(apr_poll_method_defname_REQUIRED_ARGC, apr_poll_method_defname_OPTIONAL_ARGC));
#endif
#if BIND_apr_pollcb_add_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pollcb_add", mrb_APR_apr_pollcb_add, MRB_ARGS_ARG(apr_pollcb_add_REQUIRED_ARGC, apr_pollcb_add_OPTIONAL_ARGC));
#endif
#if BIND_apr_pollcb_create_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pollcb_create", mrb_APR_apr_pollcb_create, MRB_ARGS_ARG(apr_pollcb_create_REQUIRED_ARGC, apr_pollcb_create_OPTIONAL_ARGC));
#endif
#if BIND_apr_pollcb_create_ex_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pollcb_create_ex", mrb_APR_apr_pollcb_create_ex, MRB_ARGS_ARG(apr_pollcb_create_ex_REQUIRED_ARGC, apr_pollcb_create_ex_OPTIONAL_ARGC));
#endif
#if BIND_apr_pollcb_poll_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pollcb_poll", mrb_APR_apr_pollcb_poll, MRB_ARGS_ARG(apr_pollcb_poll_REQUIRED_ARGC, apr_pollcb_poll_OPTIONAL_ARGC));
#endif
#if BIND_apr_pollcb_remove_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pollcb_remove", mrb_APR_apr_pollcb_remove, MRB_ARGS_ARG(apr_pollcb_remove_REQUIRED_ARGC, apr_pollcb_remove_OPTIONAL_ARGC));
#endif
#if BIND_apr_pollset_add_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pollset_add", mrb_APR_apr_pollset_add, MRB_ARGS_ARG(apr_pollset_add_REQUIRED_ARGC, apr_pollset_add_OPTIONAL_ARGC));
#endif
#if BIND_apr_pollset_create_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pollset_create", mrb_APR_apr_pollset_create, MRB_ARGS_ARG(apr_pollset_create_REQUIRED_ARGC, apr_pollset_create_OPTIONAL_ARGC));
#endif
#if BIND_apr_pollset_create_ex_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pollset_create_ex", mrb_APR_apr_pollset_create_ex, MRB_ARGS_ARG(apr_pollset_create_ex_REQUIRED_ARGC, apr_pollset_create_ex_OPTIONAL_ARGC));
#endif
#if BIND_apr_pollset_destroy_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pollset_destroy", mrb_APR_apr_pollset_destroy, MRB_ARGS_ARG(apr_pollset_destroy_REQUIRED_ARGC, apr_pollset_destroy_OPTIONAL_ARGC));
#endif
#if BIND_apr_pollset_method_name_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pollset_method_name", mrb_APR_apr_pollset_method_name, MRB_ARGS_ARG(apr_pollset_method_name_REQUIRED_ARGC, apr_pollset_method_name_OPTIONAL_ARGC));
#endif
#if BIND_apr_pollset_poll_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pollset_poll", mrb_APR_apr_pollset_poll, MRB_ARGS_ARG(apr_pollset_poll_REQUIRED_ARGC, apr_pollset_poll_OPTIONAL_ARGC));
#endif
#if BIND_apr_pollset_remove_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pollset_remove", mrb_APR_apr_pollset_remove, MRB_ARGS_ARG(apr_pollset_remove_REQUIRED_ARGC, apr_pollset_remove_OPTIONAL_ARGC));
#endif
#if BIND_apr_pollset_wakeup_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pollset_wakeup", mrb_APR_apr_pollset_wakeup, MRB_ARGS_ARG(apr_pollset_wakeup_REQUIRED_ARGC, apr_pollset_wakeup_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_abort_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_abort_get", mrb_APR_apr_pool_abort_get, MRB_ARGS_ARG(apr_pool_abort_get_REQUIRED_ARGC, apr_pool_abort_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_abort_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_abort_set", mrb_APR_apr_pool_abort_set, MRB_ARGS_ARG(apr_pool_abort_set_REQUIRED_ARGC, apr_pool_abort_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_allocator_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_allocator_get", mrb_APR_apr_pool_allocator_get, MRB_ARGS_ARG(apr_pool_allocator_get_REQUIRED_ARGC, apr_pool_allocator_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_child_cleanup_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_child_cleanup_set", mrb_APR_apr_pool_child_cleanup_set, MRB_ARGS_ARG(apr_pool_child_cleanup_set_REQUIRED_ARGC, apr_pool_child_cleanup_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_cleanup_for_exec_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_cleanup_for_exec", mrb_APR_apr_pool_cleanup_for_exec, MRB_ARGS_ARG(apr_pool_cleanup_for_exec_REQUIRED_ARGC, apr_pool_cleanup_for_exec_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_cleanup_kill_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_cleanup_kill", mrb_APR_apr_pool_cleanup_kill, MRB_ARGS_ARG(apr_pool_cleanup_kill_REQUIRED_ARGC, apr_pool_cleanup_kill_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_cleanup_null_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_cleanup_null", mrb_APR_apr_pool_cleanup_null, MRB_ARGS_ARG(apr_pool_cleanup_null_REQUIRED_ARGC, apr_pool_cleanup_null_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_cleanup_register_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_cleanup_register", mrb_APR_apr_pool_cleanup_register, MRB_ARGS_ARG(apr_pool_cleanup_register_REQUIRED_ARGC, apr_pool_cleanup_register_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_cleanup_run_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_cleanup_run", mrb_APR_apr_pool_cleanup_run, MRB_ARGS_ARG(apr_pool_cleanup_run_REQUIRED_ARGC, apr_pool_cleanup_run_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_clear_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_clear", mrb_APR_apr_pool_clear, MRB_ARGS_ARG(apr_pool_clear_REQUIRED_ARGC, apr_pool_clear_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_clear_debug_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_clear_debug", mrb_APR_apr_pool_clear_debug, MRB_ARGS_ARG(apr_pool_clear_debug_REQUIRED_ARGC, apr_pool_clear_debug_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_create_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_create", mrb_APR_apr_pool_create, MRB_ARGS_ARG(apr_pool_create_REQUIRED_ARGC, apr_pool_create_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_create_core_ex_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_create_core_ex", mrb_APR_apr_pool_create_core_ex, MRB_ARGS_ARG(apr_pool_create_core_ex_REQUIRED_ARGC, apr_pool_create_core_ex_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_create_core_ex_debug_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_create_core_ex_debug", mrb_APR_apr_pool_create_core_ex_debug, MRB_ARGS_ARG(apr_pool_create_core_ex_debug_REQUIRED_ARGC, apr_pool_create_core_ex_debug_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_create_ex_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_create_ex", mrb_APR_apr_pool_create_ex, MRB_ARGS_ARG(apr_pool_create_ex_REQUIRED_ARGC, apr_pool_create_ex_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_create_ex_debug_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_create_ex_debug", mrb_APR_apr_pool_create_ex_debug, MRB_ARGS_ARG(apr_pool_create_ex_debug_REQUIRED_ARGC, apr_pool_create_ex_debug_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_create_unmanaged_ex_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_create_unmanaged_ex", mrb_APR_apr_pool_create_unmanaged_ex, MRB_ARGS_ARG(apr_pool_create_unmanaged_ex_REQUIRED_ARGC, apr_pool_create_unmanaged_ex_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_create_unmanaged_ex_debug_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_create_unmanaged_ex_debug", mrb_APR_apr_pool_create_unmanaged_ex_debug, MRB_ARGS_ARG(apr_pool_create_unmanaged_ex_debug_REQUIRED_ARGC, apr_pool_create_unmanaged_ex_debug_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_destroy_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_destroy", mrb_APR_apr_pool_destroy, MRB_ARGS_ARG(apr_pool_destroy_REQUIRED_ARGC, apr_pool_destroy_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_destroy_debug_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_destroy_debug", mrb_APR_apr_pool_destroy_debug, MRB_ARGS_ARG(apr_pool_destroy_debug_REQUIRED_ARGC, apr_pool_destroy_debug_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_initialize_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_initialize", mrb_APR_apr_pool_initialize, MRB_ARGS_ARG(apr_pool_initialize_REQUIRED_ARGC, apr_pool_initialize_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_is_ancestor_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_is_ancestor", mrb_APR_apr_pool_is_ancestor, MRB_ARGS_ARG(apr_pool_is_ancestor_REQUIRED_ARGC, apr_pool_is_ancestor_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_note_subprocess_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_note_subprocess", mrb_APR_apr_pool_note_subprocess, MRB_ARGS_ARG(apr_pool_note_subprocess_REQUIRED_ARGC, apr_pool_note_subprocess_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_parent_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_parent_get", mrb_APR_apr_pool_parent_get, MRB_ARGS_ARG(apr_pool_parent_get_REQUIRED_ARGC, apr_pool_parent_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_pre_cleanup_register_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_pre_cleanup_register", mrb_APR_apr_pool_pre_cleanup_register, MRB_ARGS_ARG(apr_pool_pre_cleanup_register_REQUIRED_ARGC, apr_pool_pre_cleanup_register_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_tag_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_tag", mrb_APR_apr_pool_tag, MRB_ARGS_ARG(apr_pool_tag_REQUIRED_ARGC, apr_pool_tag_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_terminate_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_terminate", mrb_APR_apr_pool_terminate, MRB_ARGS_ARG(apr_pool_terminate_REQUIRED_ARGC, apr_pool_terminate_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_userdata_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_userdata_get", mrb_APR_apr_pool_userdata_get, MRB_ARGS_ARG(apr_pool_userdata_get_REQUIRED_ARGC, apr_pool_userdata_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_userdata_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_userdata_set", mrb_APR_apr_pool_userdata_set, MRB_ARGS_ARG(apr_pool_userdata_set_REQUIRED_ARGC, apr_pool_userdata_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_pool_userdata_setn_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pool_userdata_setn", mrb_APR_apr_pool_userdata_setn, MRB_ARGS_ARG(apr_pool_userdata_setn_REQUIRED_ARGC, apr_pool_userdata_setn_OPTIONAL_ARGC));
#endif
#if BIND_apr_proc_create_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_proc_create", mrb_APR_apr_proc_create, MRB_ARGS_ARG(apr_proc_create_REQUIRED_ARGC, apr_proc_create_OPTIONAL_ARGC));
#endif
#if BIND_apr_proc_detach_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_proc_detach", mrb_APR_apr_proc_detach, MRB_ARGS_ARG(apr_proc_detach_REQUIRED_ARGC, apr_proc_detach_OPTIONAL_ARGC));
#endif
#if BIND_apr_proc_kill_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_proc_kill", mrb_APR_apr_proc_kill, MRB_ARGS_ARG(apr_proc_kill_REQUIRED_ARGC, apr_proc_kill_OPTIONAL_ARGC));
#endif
#if BIND_apr_proc_mutex_child_init_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_proc_mutex_child_init", mrb_APR_apr_proc_mutex_child_init, MRB_ARGS_ARG(apr_proc_mutex_child_init_REQUIRED_ARGC, apr_proc_mutex_child_init_OPTIONAL_ARGC));
#endif
#if BIND_apr_proc_mutex_cleanup_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_proc_mutex_cleanup", mrb_APR_apr_proc_mutex_cleanup, MRB_ARGS_ARG(apr_proc_mutex_cleanup_REQUIRED_ARGC, apr_proc_mutex_cleanup_OPTIONAL_ARGC));
#endif
#if BIND_apr_proc_mutex_create_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_proc_mutex_create", mrb_APR_apr_proc_mutex_create, MRB_ARGS_ARG(apr_proc_mutex_create_REQUIRED_ARGC, apr_proc_mutex_create_OPTIONAL_ARGC));
#endif
#if BIND_apr_proc_mutex_defname_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_proc_mutex_defname", mrb_APR_apr_proc_mutex_defname, MRB_ARGS_ARG(apr_proc_mutex_defname_REQUIRED_ARGC, apr_proc_mutex_defname_OPTIONAL_ARGC));
#endif
#if BIND_apr_proc_mutex_destroy_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_proc_mutex_destroy", mrb_APR_apr_proc_mutex_destroy, MRB_ARGS_ARG(apr_proc_mutex_destroy_REQUIRED_ARGC, apr_proc_mutex_destroy_OPTIONAL_ARGC));
#endif
#if BIND_apr_proc_mutex_lock_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_proc_mutex_lock", mrb_APR_apr_proc_mutex_lock, MRB_ARGS_ARG(apr_proc_mutex_lock_REQUIRED_ARGC, apr_proc_mutex_lock_OPTIONAL_ARGC));
#endif
#if BIND_apr_proc_mutex_lockfile_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_proc_mutex_lockfile", mrb_APR_apr_proc_mutex_lockfile, MRB_ARGS_ARG(apr_proc_mutex_lockfile_REQUIRED_ARGC, apr_proc_mutex_lockfile_OPTIONAL_ARGC));
#endif
#if BIND_apr_proc_mutex_name_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_proc_mutex_name", mrb_APR_apr_proc_mutex_name, MRB_ARGS_ARG(apr_proc_mutex_name_REQUIRED_ARGC, apr_proc_mutex_name_OPTIONAL_ARGC));
#endif
#if BIND_apr_proc_mutex_trylock_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_proc_mutex_trylock", mrb_APR_apr_proc_mutex_trylock, MRB_ARGS_ARG(apr_proc_mutex_trylock_REQUIRED_ARGC, apr_proc_mutex_trylock_OPTIONAL_ARGC));
#endif
#if BIND_apr_proc_mutex_unlock_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_proc_mutex_unlock", mrb_APR_apr_proc_mutex_unlock, MRB_ARGS_ARG(apr_proc_mutex_unlock_REQUIRED_ARGC, apr_proc_mutex_unlock_OPTIONAL_ARGC));
#endif
#if BIND_apr_proc_other_child_alert_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_proc_other_child_alert", mrb_APR_apr_proc_other_child_alert, MRB_ARGS_ARG(apr_proc_other_child_alert_REQUIRED_ARGC, apr_proc_other_child_alert_OPTIONAL_ARGC));
#endif
#if BIND_apr_proc_other_child_refresh_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_proc_other_child_refresh", mrb_APR_apr_proc_other_child_refresh, MRB_ARGS_ARG(apr_proc_other_child_refresh_REQUIRED_ARGC, apr_proc_other_child_refresh_OPTIONAL_ARGC));
#endif
#if BIND_apr_proc_other_child_refresh_all_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_proc_other_child_refresh_all", mrb_APR_apr_proc_other_child_refresh_all, MRB_ARGS_ARG(apr_proc_other_child_refresh_all_REQUIRED_ARGC, apr_proc_other_child_refresh_all_OPTIONAL_ARGC));
#endif
#if BIND_apr_proc_other_child_register_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_proc_other_child_register", mrb_APR_apr_proc_other_child_register, MRB_ARGS_ARG(apr_proc_other_child_register_REQUIRED_ARGC, apr_proc_other_child_register_OPTIONAL_ARGC));
#endif
#if BIND_apr_proc_other_child_unregister_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_proc_other_child_unregister", mrb_APR_apr_proc_other_child_unregister, MRB_ARGS_ARG(apr_proc_other_child_unregister_REQUIRED_ARGC, apr_proc_other_child_unregister_OPTIONAL_ARGC));
#endif
#if BIND_apr_proc_wait_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_proc_wait", mrb_APR_apr_proc_wait, MRB_ARGS_ARG(apr_proc_wait_REQUIRED_ARGC, apr_proc_wait_OPTIONAL_ARGC));
#endif
#if BIND_apr_proc_wait_all_procs_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_proc_wait_all_procs", mrb_APR_apr_proc_wait_all_procs, MRB_ARGS_ARG(apr_proc_wait_all_procs_REQUIRED_ARGC, apr_proc_wait_all_procs_OPTIONAL_ARGC));
#endif
  mrb_define_class_method(mrb, APR_module, "apr_proc_from_pid", mrb_APR_apr_proc_from_pid, MRB_ARGS_ARG(1, 0));
#if BIND_apr_procattr_addrspace_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_procattr_addrspace_set", mrb_APR_apr_procattr_addrspace_set, MRB_ARGS_ARG(apr_procattr_addrspace_set_REQUIRED_ARGC, apr_procattr_addrspace_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_procattr_child_err_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_procattr_child_err_set", mrb_APR_apr_procattr_child_err_set, MRB_ARGS_ARG(apr_procattr_child_err_set_REQUIRED_ARGC, apr_procattr_child_err_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_procattr_child_errfn_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_procattr_child_errfn_set", mrb_APR_apr_procattr_child_errfn_set, MRB_ARGS_ARG(apr_procattr_child_errfn_set_REQUIRED_ARGC, apr_procattr_child_errfn_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_procattr_child_in_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_procattr_child_in_set", mrb_APR_apr_procattr_child_in_set, MRB_ARGS_ARG(apr_procattr_child_in_set_REQUIRED_ARGC, apr_procattr_child_in_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_procattr_child_out_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_procattr_child_out_set", mrb_APR_apr_procattr_child_out_set, MRB_ARGS_ARG(apr_procattr_child_out_set_REQUIRED_ARGC, apr_procattr_child_out_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_procattr_cmdtype_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_procattr_cmdtype_set", mrb_APR_apr_procattr_cmdtype_set, MRB_ARGS_ARG(apr_procattr_cmdtype_set_REQUIRED_ARGC, apr_procattr_cmdtype_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_procattr_create_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_procattr_create", mrb_APR_apr_procattr_create, MRB_ARGS_ARG(apr_procattr_create_REQUIRED_ARGC, apr_procattr_create_OPTIONAL_ARGC));
#endif
#if BIND_apr_procattr_detach_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_procattr_detach_set", mrb_APR_apr_procattr_detach_set, MRB_ARGS_ARG(apr_procattr_detach_set_REQUIRED_ARGC, apr_procattr_detach_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_procattr_dir_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_procattr_dir_set", mrb_APR_apr_procattr_dir_set, MRB_ARGS_ARG(apr_procattr_dir_set_REQUIRED_ARGC, apr_procattr_dir_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_procattr_error_check_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_procattr_error_check_set", mrb_APR_apr_procattr_error_check_set, MRB_ARGS_ARG(apr_procattr_error_check_set_REQUIRED_ARGC, apr_procattr_error_check_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_procattr_group_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_procattr_group_set", mrb_APR_apr_procattr_group_set, MRB_ARGS_ARG(apr_procattr_group_set_REQUIRED_ARGC, apr_procattr_group_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_procattr_io_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_procattr_io_set", mrb_APR_apr_procattr_io_set, MRB_ARGS_ARG(apr_procattr_io_set_REQUIRED_ARGC, apr_procattr_io_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_procattr_user_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_procattr_user_set", mrb_APR_apr_procattr_user_set, MRB_ARGS_ARG(apr_procattr_user_set_REQUIRED_ARGC, apr_procattr_user_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_psprintf_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_psprintf", mrb_APR_apr_psprintf, MRB_ARGS_ARG(apr_psprintf_REQUIRED_ARGC, apr_psprintf_OPTIONAL_ARGC));
#endif
#if BIND_apr_pstrcat_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pstrcat", mrb_APR_apr_pstrcat, MRB_ARGS_ARG(apr_pstrcat_REQUIRED_ARGC, apr_pstrcat_OPTIONAL_ARGC));
#endif
#if BIND_apr_pstrcatv_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pstrcatv", mrb_APR_apr_pstrcatv, MRB_ARGS_ARG(apr_pstrcatv_REQUIRED_ARGC, apr_pstrcatv_OPTIONAL_ARGC));
#endif
#if BIND_apr_pstrdup_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pstrdup", mrb_APR_apr_pstrdup, MRB_ARGS_ARG(apr_pstrdup_REQUIRED_ARGC, apr_pstrdup_OPTIONAL_ARGC));
#endif
#if BIND_apr_pstrmemdup_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pstrmemdup", mrb_APR_apr_pstrmemdup, MRB_ARGS_ARG(apr_pstrmemdup_REQUIRED_ARGC, apr_pstrmemdup_OPTIONAL_ARGC));
#endif
#if BIND_apr_pstrndup_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pstrndup", mrb_APR_apr_pstrndup, MRB_ARGS_ARG(apr_pstrndup_REQUIRED_ARGC, apr_pstrndup_OPTIONAL_ARGC));
#endif
#if BIND_apr_punescape_entity_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_punescape_entity", mrb_APR_apr_punescape_entity, MRB_ARGS_ARG(apr_punescape_entity_REQUIRED_ARGC, apr_punescape_entity_OPTIONAL_ARGC));
#endif
#if BIND_apr_punescape_hex_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_punescape_hex", mrb_APR_apr_punescape_hex, MRB_ARGS_ARG(apr_punescape_hex_REQUIRED_ARGC, apr_punescape_hex_OPTIONAL_ARGC));
#endif
#if BIND_apr_punescape_url_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_punescape_url", mrb_APR_apr_punescape_url, MRB_ARGS_ARG(apr_punescape_url_REQUIRED_ARGC, apr_punescape_url_OPTIONAL_ARGC));
#endif
#if BIND_apr_pvsprintf_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_pvsprintf", mrb_APR_apr_pvsprintf, MRB_ARGS_ARG(apr_pvsprintf_REQUIRED_ARGC, apr_pvsprintf_OPTIONAL_ARGC));
#endif
#if BIND_apr_random_add_entropy_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_random_add_entropy", mrb_APR_apr_random_add_entropy, MRB_ARGS_ARG(apr_random_add_entropy_REQUIRED_ARGC, apr_random_add_entropy_OPTIONAL_ARGC));
#endif
#if BIND_apr_random_after_fork_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_random_after_fork", mrb_APR_apr_random_after_fork, MRB_ARGS_ARG(apr_random_after_fork_REQUIRED_ARGC, apr_random_after_fork_OPTIONAL_ARGC));
#endif
#if BIND_apr_random_barrier_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_random_barrier", mrb_APR_apr_random_barrier, MRB_ARGS_ARG(apr_random_barrier_REQUIRED_ARGC, apr_random_barrier_OPTIONAL_ARGC));
#endif
#if BIND_apr_random_init_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_random_init", mrb_APR_apr_random_init, MRB_ARGS_ARG(apr_random_init_REQUIRED_ARGC, apr_random_init_OPTIONAL_ARGC));
#endif
#if BIND_apr_random_insecure_bytes_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_random_insecure_bytes", mrb_APR_apr_random_insecure_bytes, MRB_ARGS_ARG(apr_random_insecure_bytes_REQUIRED_ARGC, apr_random_insecure_bytes_OPTIONAL_ARGC));
#endif
#if BIND_apr_random_insecure_ready_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_random_insecure_ready", mrb_APR_apr_random_insecure_ready, MRB_ARGS_ARG(apr_random_insecure_ready_REQUIRED_ARGC, apr_random_insecure_ready_OPTIONAL_ARGC));
#endif
#if BIND_apr_random_secure_bytes_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_random_secure_bytes", mrb_APR_apr_random_secure_bytes, MRB_ARGS_ARG(apr_random_secure_bytes_REQUIRED_ARGC, apr_random_secure_bytes_OPTIONAL_ARGC));
#endif
#if BIND_apr_random_secure_ready_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_random_secure_ready", mrb_APR_apr_random_secure_ready, MRB_ARGS_ARG(apr_random_secure_ready_REQUIRED_ARGC, apr_random_secure_ready_OPTIONAL_ARGC));
#endif
#if BIND_apr_random_standard_new_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_random_standard_new", mrb_APR_apr_random_standard_new, MRB_ARGS_ARG(apr_random_standard_new_REQUIRED_ARGC, apr_random_standard_new_OPTIONAL_ARGC));
#endif
#if BIND_apr_rfc822_date_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_rfc822_date", mrb_APR_apr_rfc822_date, MRB_ARGS_ARG(apr_rfc822_date_REQUIRED_ARGC, apr_rfc822_date_OPTIONAL_ARGC));
#endif
#if BIND_apr_shm_attach_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_shm_attach", mrb_APR_apr_shm_attach, MRB_ARGS_ARG(apr_shm_attach_REQUIRED_ARGC, apr_shm_attach_OPTIONAL_ARGC));
#endif
#if BIND_apr_shm_attach_ex_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_shm_attach_ex", mrb_APR_apr_shm_attach_ex, MRB_ARGS_ARG(apr_shm_attach_ex_REQUIRED_ARGC, apr_shm_attach_ex_OPTIONAL_ARGC));
#endif
#if BIND_apr_shm_baseaddr_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_shm_baseaddr_get", mrb_APR_apr_shm_baseaddr_get, MRB_ARGS_ARG(apr_shm_baseaddr_get_REQUIRED_ARGC, apr_shm_baseaddr_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_shm_create_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_shm_create", mrb_APR_apr_shm_create, MRB_ARGS_ARG(apr_shm_create_REQUIRED_ARGC, apr_shm_create_OPTIONAL_ARGC));
#endif
#if BIND_apr_shm_create_ex_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_shm_create_ex", mrb_APR_apr_shm_create_ex, MRB_ARGS_ARG(apr_shm_create_ex_REQUIRED_ARGC, apr_shm_create_ex_OPTIONAL_ARGC));
#endif
#if BIND_apr_shm_destroy_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_shm_destroy", mrb_APR_apr_shm_destroy, MRB_ARGS_ARG(apr_shm_destroy_REQUIRED_ARGC, apr_shm_destroy_OPTIONAL_ARGC));
#endif
#if BIND_apr_shm_detach_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_shm_detach", mrb_APR_apr_shm_detach, MRB_ARGS_ARG(apr_shm_detach_REQUIRED_ARGC, apr_shm_detach_OPTIONAL_ARGC));
#endif
#if BIND_apr_shm_remove_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_shm_remove", mrb_APR_apr_shm_remove, MRB_ARGS_ARG(apr_shm_remove_REQUIRED_ARGC, apr_shm_remove_OPTIONAL_ARGC));
#endif
#if BIND_apr_shm_size_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_shm_size_get", mrb_APR_apr_shm_size_get, MRB_ARGS_ARG(apr_shm_size_get_REQUIRED_ARGC, apr_shm_size_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_signal_block_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_signal_block", mrb_APR_apr_signal_block, MRB_ARGS_ARG(apr_signal_block_REQUIRED_ARGC, apr_signal_block_OPTIONAL_ARGC));
#endif
#if BIND_apr_signal_description_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_signal_description_get", mrb_APR_apr_signal_description_get, MRB_ARGS_ARG(apr_signal_description_get_REQUIRED_ARGC, apr_signal_description_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_signal_init_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_signal_init", mrb_APR_apr_signal_init, MRB_ARGS_ARG(apr_signal_init_REQUIRED_ARGC, apr_signal_init_OPTIONAL_ARGC));
#endif
#if BIND_apr_signal_unblock_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_signal_unblock", mrb_APR_apr_signal_unblock, MRB_ARGS_ARG(apr_signal_unblock_REQUIRED_ARGC, apr_signal_unblock_OPTIONAL_ARGC));
#endif
#if BIND_apr_skiplist_add_index_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_skiplist_add_index", mrb_APR_apr_skiplist_add_index, MRB_ARGS_ARG(apr_skiplist_add_index_REQUIRED_ARGC, apr_skiplist_add_index_OPTIONAL_ARGC));
#endif
#if BIND_apr_skiplist_alloc_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_skiplist_alloc", mrb_APR_apr_skiplist_alloc, MRB_ARGS_ARG(apr_skiplist_alloc_REQUIRED_ARGC, apr_skiplist_alloc_OPTIONAL_ARGC));
#endif
#if BIND_apr_skiplist_destroy_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_skiplist_destroy", mrb_APR_apr_skiplist_destroy, MRB_ARGS_ARG(apr_skiplist_destroy_REQUIRED_ARGC, apr_skiplist_destroy_OPTIONAL_ARGC));
#endif
#if BIND_apr_skiplist_find_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_skiplist_find", mrb_APR_apr_skiplist_find, MRB_ARGS_ARG(apr_skiplist_find_REQUIRED_ARGC, apr_skiplist_find_OPTIONAL_ARGC));
#endif
#if BIND_apr_skiplist_find_compare_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_skiplist_find_compare", mrb_APR_apr_skiplist_find_compare, MRB_ARGS_ARG(apr_skiplist_find_compare_REQUIRED_ARGC, apr_skiplist_find_compare_OPTIONAL_ARGC));
#endif
#if BIND_apr_skiplist_free_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_skiplist_free", mrb_APR_apr_skiplist_free, MRB_ARGS_ARG(apr_skiplist_free_REQUIRED_ARGC, apr_skiplist_free_OPTIONAL_ARGC));
#endif
#if BIND_apr_skiplist_getlist_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_skiplist_getlist", mrb_APR_apr_skiplist_getlist, MRB_ARGS_ARG(apr_skiplist_getlist_REQUIRED_ARGC, apr_skiplist_getlist_OPTIONAL_ARGC));
#endif
#if BIND_apr_skiplist_init_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_skiplist_init", mrb_APR_apr_skiplist_init, MRB_ARGS_ARG(apr_skiplist_init_REQUIRED_ARGC, apr_skiplist_init_OPTIONAL_ARGC));
#endif
#if BIND_apr_skiplist_insert_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_skiplist_insert", mrb_APR_apr_skiplist_insert, MRB_ARGS_ARG(apr_skiplist_insert_REQUIRED_ARGC, apr_skiplist_insert_OPTIONAL_ARGC));
#endif
#if BIND_apr_skiplist_insert_compare_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_skiplist_insert_compare", mrb_APR_apr_skiplist_insert_compare, MRB_ARGS_ARG(apr_skiplist_insert_compare_REQUIRED_ARGC, apr_skiplist_insert_compare_OPTIONAL_ARGC));
#endif
#if BIND_apr_skiplist_merge_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_skiplist_merge", mrb_APR_apr_skiplist_merge, MRB_ARGS_ARG(apr_skiplist_merge_REQUIRED_ARGC, apr_skiplist_merge_OPTIONAL_ARGC));
#endif
#if BIND_apr_skiplist_next_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_skiplist_next", mrb_APR_apr_skiplist_next, MRB_ARGS_ARG(apr_skiplist_next_REQUIRED_ARGC, apr_skiplist_next_OPTIONAL_ARGC));
#endif
#if BIND_apr_skiplist_peek_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_skiplist_peek", mrb_APR_apr_skiplist_peek, MRB_ARGS_ARG(apr_skiplist_peek_REQUIRED_ARGC, apr_skiplist_peek_OPTIONAL_ARGC));
#endif
#if BIND_apr_skiplist_pop_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_skiplist_pop", mrb_APR_apr_skiplist_pop, MRB_ARGS_ARG(apr_skiplist_pop_REQUIRED_ARGC, apr_skiplist_pop_OPTIONAL_ARGC));
#endif
#if BIND_apr_skiplist_previous_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_skiplist_previous", mrb_APR_apr_skiplist_previous, MRB_ARGS_ARG(apr_skiplist_previous_REQUIRED_ARGC, apr_skiplist_previous_OPTIONAL_ARGC));
#endif
#if BIND_apr_skiplist_remove_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_skiplist_remove", mrb_APR_apr_skiplist_remove, MRB_ARGS_ARG(apr_skiplist_remove_REQUIRED_ARGC, apr_skiplist_remove_OPTIONAL_ARGC));
#endif
#if BIND_apr_skiplist_remove_all_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_skiplist_remove_all", mrb_APR_apr_skiplist_remove_all, MRB_ARGS_ARG(apr_skiplist_remove_all_REQUIRED_ARGC, apr_skiplist_remove_all_OPTIONAL_ARGC));
#endif
#if BIND_apr_skiplist_remove_compare_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_skiplist_remove_compare", mrb_APR_apr_skiplist_remove_compare, MRB_ARGS_ARG(apr_skiplist_remove_compare_REQUIRED_ARGC, apr_skiplist_remove_compare_OPTIONAL_ARGC));
#endif
#if BIND_apr_skiplist_set_compare_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_skiplist_set_compare", mrb_APR_apr_skiplist_set_compare, MRB_ARGS_ARG(apr_skiplist_set_compare_REQUIRED_ARGC, apr_skiplist_set_compare_OPTIONAL_ARGC));
#endif
#if BIND_apr_sleep_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_sleep", mrb_APR_apr_sleep, MRB_ARGS_ARG(apr_sleep_REQUIRED_ARGC, apr_sleep_OPTIONAL_ARGC));
#endif
#if BIND_apr_snprintf_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_snprintf", mrb_APR_apr_snprintf, MRB_ARGS_ARG(apr_snprintf_REQUIRED_ARGC, apr_snprintf_OPTIONAL_ARGC));
#endif
#if BIND_apr_sockaddr_equal_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_sockaddr_equal", mrb_APR_apr_sockaddr_equal, MRB_ARGS_ARG(apr_sockaddr_equal_REQUIRED_ARGC, apr_sockaddr_equal_OPTIONAL_ARGC));
#endif
#if BIND_apr_sockaddr_info_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_sockaddr_info_get", mrb_APR_apr_sockaddr_info_get, MRB_ARGS_ARG(apr_sockaddr_info_get_REQUIRED_ARGC, apr_sockaddr_info_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_sockaddr_ip_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_sockaddr_ip_get", mrb_APR_apr_sockaddr_ip_get, MRB_ARGS_ARG(apr_sockaddr_ip_get_REQUIRED_ARGC, apr_sockaddr_ip_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_sockaddr_ip_getbuf_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_sockaddr_ip_getbuf", mrb_APR_apr_sockaddr_ip_getbuf, MRB_ARGS_ARG(apr_sockaddr_ip_getbuf_REQUIRED_ARGC, apr_sockaddr_ip_getbuf_OPTIONAL_ARGC));
#endif
#if BIND_apr_sockaddr_is_wildcard_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_sockaddr_is_wildcard", mrb_APR_apr_sockaddr_is_wildcard, MRB_ARGS_ARG(apr_sockaddr_is_wildcard_REQUIRED_ARGC, apr_sockaddr_is_wildcard_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_accept_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_accept", mrb_APR_apr_socket_accept, MRB_ARGS_ARG(apr_socket_accept_REQUIRED_ARGC, apr_socket_accept_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_addr_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_addr_get", mrb_APR_apr_socket_addr_get, MRB_ARGS_ARG(apr_socket_addr_get_REQUIRED_ARGC, apr_socket_addr_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_atmark_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_atmark", mrb_APR_apr_socket_atmark, MRB_ARGS_ARG(apr_socket_atmark_REQUIRED_ARGC, apr_socket_atmark_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_atreadeof_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_atreadeof", mrb_APR_apr_socket_atreadeof, MRB_ARGS_ARG(apr_socket_atreadeof_REQUIRED_ARGC, apr_socket_atreadeof_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_bind_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_bind", mrb_APR_apr_socket_bind, MRB_ARGS_ARG(apr_socket_bind_REQUIRED_ARGC, apr_socket_bind_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_close_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_close", mrb_APR_apr_socket_close, MRB_ARGS_ARG(apr_socket_close_REQUIRED_ARGC, apr_socket_close_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_connect_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_connect", mrb_APR_apr_socket_connect, MRB_ARGS_ARG(apr_socket_connect_REQUIRED_ARGC, apr_socket_connect_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_create_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_create", mrb_APR_apr_socket_create, MRB_ARGS_ARG(apr_socket_create_REQUIRED_ARGC, apr_socket_create_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_data_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_data_get", mrb_APR_apr_socket_data_get, MRB_ARGS_ARG(apr_socket_data_get_REQUIRED_ARGC, apr_socket_data_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_data_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_data_set", mrb_APR_apr_socket_data_set, MRB_ARGS_ARG(apr_socket_data_set_REQUIRED_ARGC, apr_socket_data_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_listen_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_listen", mrb_APR_apr_socket_listen, MRB_ARGS_ARG(apr_socket_listen_REQUIRED_ARGC, apr_socket_listen_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_opt_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_opt_get", mrb_APR_apr_socket_opt_get, MRB_ARGS_ARG(apr_socket_opt_get_REQUIRED_ARGC, apr_socket_opt_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_opt_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_opt_set", mrb_APR_apr_socket_opt_set, MRB_ARGS_ARG(apr_socket_opt_set_REQUIRED_ARGC, apr_socket_opt_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_protocol_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_protocol_get", mrb_APR_apr_socket_protocol_get, MRB_ARGS_ARG(apr_socket_protocol_get_REQUIRED_ARGC, apr_socket_protocol_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_recv_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_recv", mrb_APR_apr_socket_recv, MRB_ARGS_ARG(apr_socket_recv_REQUIRED_ARGC, apr_socket_recv_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_recvfrom_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_recvfrom", mrb_APR_apr_socket_recvfrom, MRB_ARGS_ARG(apr_socket_recvfrom_REQUIRED_ARGC, apr_socket_recvfrom_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_send_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_send", mrb_APR_apr_socket_send, MRB_ARGS_ARG(apr_socket_send_REQUIRED_ARGC, apr_socket_send_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_sendfile_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_sendfile", mrb_APR_apr_socket_sendfile, MRB_ARGS_ARG(apr_socket_sendfile_REQUIRED_ARGC, apr_socket_sendfile_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_sendto_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_sendto", mrb_APR_apr_socket_sendto, MRB_ARGS_ARG(apr_socket_sendto_REQUIRED_ARGC, apr_socket_sendto_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_sendv_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_sendv", mrb_APR_apr_socket_sendv, MRB_ARGS_ARG(apr_socket_sendv_REQUIRED_ARGC, apr_socket_sendv_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_shutdown_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_shutdown", mrb_APR_apr_socket_shutdown, MRB_ARGS_ARG(apr_socket_shutdown_REQUIRED_ARGC, apr_socket_shutdown_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_timeout_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_timeout_get", mrb_APR_apr_socket_timeout_get, MRB_ARGS_ARG(apr_socket_timeout_get_REQUIRED_ARGC, apr_socket_timeout_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_timeout_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_timeout_set", mrb_APR_apr_socket_timeout_set, MRB_ARGS_ARG(apr_socket_timeout_set_REQUIRED_ARGC, apr_socket_timeout_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_socket_type_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_socket_type_get", mrb_APR_apr_socket_type_get, MRB_ARGS_ARG(apr_socket_type_get_REQUIRED_ARGC, apr_socket_type_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_stat_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_stat", mrb_APR_apr_stat, MRB_ARGS_ARG(apr_stat_REQUIRED_ARGC, apr_stat_OPTIONAL_ARGC));
#endif
#if BIND_apr_strerror_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_strerror", mrb_APR_apr_strerror, MRB_ARGS_ARG(apr_strerror_REQUIRED_ARGC, apr_strerror_OPTIONAL_ARGC));
#endif
#if BIND_apr_to_os_error_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_to_os_error", mrb_APR_apr_to_os_error, MRB_ARGS_ARG(apr_to_os_error_REQUIRED_ARGC, apr_to_os_error_OPTIONAL_ARGC));
#endif
#if BIND_apr_strfsize_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_strfsize", mrb_APR_apr_strfsize, MRB_ARGS_ARG(apr_strfsize_REQUIRED_ARGC, apr_strfsize_OPTIONAL_ARGC));
#endif
#if BIND_apr_strftime_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_strftime", mrb_APR_apr_strftime, MRB_ARGS_ARG(apr_strftime_REQUIRED_ARGC, apr_strftime_OPTIONAL_ARGC));
#endif
#if BIND_apr_strnatcasecmp_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_strnatcasecmp", mrb_APR_apr_strnatcasecmp, MRB_ARGS_ARG(apr_strnatcasecmp_REQUIRED_ARGC, apr_strnatcasecmp_OPTIONAL_ARGC));
#endif
#if BIND_apr_strnatcmp_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_strnatcmp", mrb_APR_apr_strnatcmp, MRB_ARGS_ARG(apr_strnatcmp_REQUIRED_ARGC, apr_strnatcmp_OPTIONAL_ARGC));
#endif
#if BIND_apr_strtoff_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_strtoff", mrb_APR_apr_strtoff, MRB_ARGS_ARG(apr_strtoff_REQUIRED_ARGC, apr_strtoff_OPTIONAL_ARGC));
#endif
#if BIND_apr_strtoi64_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_strtoi64", mrb_APR_apr_strtoi64, MRB_ARGS_ARG(apr_strtoi64_REQUIRED_ARGC, apr_strtoi64_OPTIONAL_ARGC));
#endif
#if BIND_apr_strtok_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_strtok", mrb_APR_apr_strtok, MRB_ARGS_ARG(apr_strtok_REQUIRED_ARGC, apr_strtok_OPTIONAL_ARGC));
#endif
#if BIND_apr_table_add_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_table_add", mrb_APR_apr_table_add, MRB_ARGS_ARG(apr_table_add_REQUIRED_ARGC, apr_table_add_OPTIONAL_ARGC));
#endif
#if BIND_apr_table_addn_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_table_addn", mrb_APR_apr_table_addn, MRB_ARGS_ARG(apr_table_addn_REQUIRED_ARGC, apr_table_addn_OPTIONAL_ARGC));
#endif
#if BIND_apr_table_clear_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_table_clear", mrb_APR_apr_table_clear, MRB_ARGS_ARG(apr_table_clear_REQUIRED_ARGC, apr_table_clear_OPTIONAL_ARGC));
#endif
#if BIND_apr_table_clone_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_table_clone", mrb_APR_apr_table_clone, MRB_ARGS_ARG(apr_table_clone_REQUIRED_ARGC, apr_table_clone_OPTIONAL_ARGC));
#endif
#if BIND_apr_table_compress_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_table_compress", mrb_APR_apr_table_compress, MRB_ARGS_ARG(apr_table_compress_REQUIRED_ARGC, apr_table_compress_OPTIONAL_ARGC));
#endif
#if BIND_apr_table_copy_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_table_copy", mrb_APR_apr_table_copy, MRB_ARGS_ARG(apr_table_copy_REQUIRED_ARGC, apr_table_copy_OPTIONAL_ARGC));
#endif
#if BIND_apr_table_do_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_table_do", mrb_APR_apr_table_do, MRB_ARGS_ARG(apr_table_do_REQUIRED_ARGC, apr_table_do_OPTIONAL_ARGC));
#endif
#if BIND_apr_table_elts_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_table_elts", mrb_APR_apr_table_elts, MRB_ARGS_ARG(apr_table_elts_REQUIRED_ARGC, apr_table_elts_OPTIONAL_ARGC));
#endif
#if BIND_apr_table_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_table_get", mrb_APR_apr_table_get, MRB_ARGS_ARG(apr_table_get_REQUIRED_ARGC, apr_table_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_table_getm_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_table_getm", mrb_APR_apr_table_getm, MRB_ARGS_ARG(apr_table_getm_REQUIRED_ARGC, apr_table_getm_OPTIONAL_ARGC));
#endif
#if BIND_apr_table_make_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_table_make", mrb_APR_apr_table_make, MRB_ARGS_ARG(apr_table_make_REQUIRED_ARGC, apr_table_make_OPTIONAL_ARGC));
#endif
#if BIND_apr_table_merge_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_table_merge", mrb_APR_apr_table_merge, MRB_ARGS_ARG(apr_table_merge_REQUIRED_ARGC, apr_table_merge_OPTIONAL_ARGC));
#endif
#if BIND_apr_table_mergen_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_table_mergen", mrb_APR_apr_table_mergen, MRB_ARGS_ARG(apr_table_mergen_REQUIRED_ARGC, apr_table_mergen_OPTIONAL_ARGC));
#endif
#if BIND_apr_table_overlap_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_table_overlap", mrb_APR_apr_table_overlap, MRB_ARGS_ARG(apr_table_overlap_REQUIRED_ARGC, apr_table_overlap_OPTIONAL_ARGC));
#endif
#if BIND_apr_table_overlay_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_table_overlay", mrb_APR_apr_table_overlay, MRB_ARGS_ARG(apr_table_overlay_REQUIRED_ARGC, apr_table_overlay_OPTIONAL_ARGC));
#endif
#if BIND_apr_table_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_table_set", mrb_APR_apr_table_set, MRB_ARGS_ARG(apr_table_set_REQUIRED_ARGC, apr_table_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_table_setn_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_table_setn", mrb_APR_apr_table_setn, MRB_ARGS_ARG(apr_table_setn_REQUIRED_ARGC, apr_table_setn_OPTIONAL_ARGC));
#endif
#if BIND_apr_table_unset_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_table_unset", mrb_APR_apr_table_unset, MRB_ARGS_ARG(apr_table_unset_REQUIRED_ARGC, apr_table_unset_OPTIONAL_ARGC));
#endif
#if BIND_apr_table_vdo_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_table_vdo", mrb_APR_apr_table_vdo, MRB_ARGS_ARG(apr_table_vdo_REQUIRED_ARGC, apr_table_vdo_OPTIONAL_ARGC));
#endif
#if BIND_apr_temp_dir_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_temp_dir_get", mrb_APR_apr_temp_dir_get, MRB_ARGS_ARG(apr_temp_dir_get_REQUIRED_ARGC, apr_temp_dir_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_terminate_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_terminate", mrb_APR_apr_terminate, MRB_ARGS_ARG(apr_terminate_REQUIRED_ARGC, apr_terminate_OPTIONAL_ARGC));
#endif
#if BIND_apr_terminate2_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_terminate2", mrb_APR_apr_terminate2, MRB_ARGS_ARG(apr_terminate2_REQUIRED_ARGC, apr_terminate2_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_cond_broadcast_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_cond_broadcast", mrb_APR_apr_thread_cond_broadcast, MRB_ARGS_ARG(apr_thread_cond_broadcast_REQUIRED_ARGC, apr_thread_cond_broadcast_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_cond_create_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_cond_create", mrb_APR_apr_thread_cond_create, MRB_ARGS_ARG(apr_thread_cond_create_REQUIRED_ARGC, apr_thread_cond_create_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_cond_destroy_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_cond_destroy", mrb_APR_apr_thread_cond_destroy, MRB_ARGS_ARG(apr_thread_cond_destroy_REQUIRED_ARGC, apr_thread_cond_destroy_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_cond_signal_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_cond_signal", mrb_APR_apr_thread_cond_signal, MRB_ARGS_ARG(apr_thread_cond_signal_REQUIRED_ARGC, apr_thread_cond_signal_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_cond_timedwait_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_cond_timedwait", mrb_APR_apr_thread_cond_timedwait, MRB_ARGS_ARG(apr_thread_cond_timedwait_REQUIRED_ARGC, apr_thread_cond_timedwait_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_cond_wait_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_cond_wait", mrb_APR_apr_thread_cond_wait, MRB_ARGS_ARG(apr_thread_cond_wait_REQUIRED_ARGC, apr_thread_cond_wait_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_create_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_create", mrb_APR_apr_thread_create, MRB_ARGS_ARG(apr_thread_create_REQUIRED_ARGC, apr_thread_create_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_data_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_data_get", mrb_APR_apr_thread_data_get, MRB_ARGS_ARG(apr_thread_data_get_REQUIRED_ARGC, apr_thread_data_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_data_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_data_set", mrb_APR_apr_thread_data_set, MRB_ARGS_ARG(apr_thread_data_set_REQUIRED_ARGC, apr_thread_data_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_detach_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_detach", mrb_APR_apr_thread_detach, MRB_ARGS_ARG(apr_thread_detach_REQUIRED_ARGC, apr_thread_detach_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_exit_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_exit", mrb_APR_apr_thread_exit, MRB_ARGS_ARG(apr_thread_exit_REQUIRED_ARGC, apr_thread_exit_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_join_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_join", mrb_APR_apr_thread_join, MRB_ARGS_ARG(apr_thread_join_REQUIRED_ARGC, apr_thread_join_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_mutex_create_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_mutex_create", mrb_APR_apr_thread_mutex_create, MRB_ARGS_ARG(apr_thread_mutex_create_REQUIRED_ARGC, apr_thread_mutex_create_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_mutex_destroy_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_mutex_destroy", mrb_APR_apr_thread_mutex_destroy, MRB_ARGS_ARG(apr_thread_mutex_destroy_REQUIRED_ARGC, apr_thread_mutex_destroy_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_mutex_lock_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_mutex_lock", mrb_APR_apr_thread_mutex_lock, MRB_ARGS_ARG(apr_thread_mutex_lock_REQUIRED_ARGC, apr_thread_mutex_lock_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_mutex_trylock_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_mutex_trylock", mrb_APR_apr_thread_mutex_trylock, MRB_ARGS_ARG(apr_thread_mutex_trylock_REQUIRED_ARGC, apr_thread_mutex_trylock_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_mutex_unlock_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_mutex_unlock", mrb_APR_apr_thread_mutex_unlock, MRB_ARGS_ARG(apr_thread_mutex_unlock_REQUIRED_ARGC, apr_thread_mutex_unlock_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_once_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_once", mrb_APR_apr_thread_once, MRB_ARGS_ARG(apr_thread_once_REQUIRED_ARGC, apr_thread_once_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_once_init_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_once_init", mrb_APR_apr_thread_once_init, MRB_ARGS_ARG(apr_thread_once_init_REQUIRED_ARGC, apr_thread_once_init_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_rwlock_create_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_rwlock_create", mrb_APR_apr_thread_rwlock_create, MRB_ARGS_ARG(apr_thread_rwlock_create_REQUIRED_ARGC, apr_thread_rwlock_create_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_rwlock_destroy_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_rwlock_destroy", mrb_APR_apr_thread_rwlock_destroy, MRB_ARGS_ARG(apr_thread_rwlock_destroy_REQUIRED_ARGC, apr_thread_rwlock_destroy_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_rwlock_rdlock_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_rwlock_rdlock", mrb_APR_apr_thread_rwlock_rdlock, MRB_ARGS_ARG(apr_thread_rwlock_rdlock_REQUIRED_ARGC, apr_thread_rwlock_rdlock_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_rwlock_tryrdlock_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_rwlock_tryrdlock", mrb_APR_apr_thread_rwlock_tryrdlock, MRB_ARGS_ARG(apr_thread_rwlock_tryrdlock_REQUIRED_ARGC, apr_thread_rwlock_tryrdlock_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_rwlock_trywrlock_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_rwlock_trywrlock", mrb_APR_apr_thread_rwlock_trywrlock, MRB_ARGS_ARG(apr_thread_rwlock_trywrlock_REQUIRED_ARGC, apr_thread_rwlock_trywrlock_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_rwlock_unlock_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_rwlock_unlock", mrb_APR_apr_thread_rwlock_unlock, MRB_ARGS_ARG(apr_thread_rwlock_unlock_REQUIRED_ARGC, apr_thread_rwlock_unlock_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_rwlock_wrlock_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_rwlock_wrlock", mrb_APR_apr_thread_rwlock_wrlock, MRB_ARGS_ARG(apr_thread_rwlock_wrlock_REQUIRED_ARGC, apr_thread_rwlock_wrlock_OPTIONAL_ARGC));
#endif
#if BIND_apr_thread_yield_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_thread_yield", mrb_APR_apr_thread_yield, MRB_ARGS_ARG(apr_thread_yield_REQUIRED_ARGC, apr_thread_yield_OPTIONAL_ARGC));
#endif
#if BIND_apr_threadattr_create_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_threadattr_create", mrb_APR_apr_threadattr_create, MRB_ARGS_ARG(apr_threadattr_create_REQUIRED_ARGC, apr_threadattr_create_OPTIONAL_ARGC));
#endif
#if BIND_apr_threadattr_detach_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_threadattr_detach_get", mrb_APR_apr_threadattr_detach_get, MRB_ARGS_ARG(apr_threadattr_detach_get_REQUIRED_ARGC, apr_threadattr_detach_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_threadattr_detach_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_threadattr_detach_set", mrb_APR_apr_threadattr_detach_set, MRB_ARGS_ARG(apr_threadattr_detach_set_REQUIRED_ARGC, apr_threadattr_detach_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_threadattr_guardsize_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_threadattr_guardsize_set", mrb_APR_apr_threadattr_guardsize_set, MRB_ARGS_ARG(apr_threadattr_guardsize_set_REQUIRED_ARGC, apr_threadattr_guardsize_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_threadattr_stacksize_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_threadattr_stacksize_set", mrb_APR_apr_threadattr_stacksize_set, MRB_ARGS_ARG(apr_threadattr_stacksize_set_REQUIRED_ARGC, apr_threadattr_stacksize_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_threadkey_data_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_threadkey_data_get", mrb_APR_apr_threadkey_data_get, MRB_ARGS_ARG(apr_threadkey_data_get_REQUIRED_ARGC, apr_threadkey_data_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_threadkey_data_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_threadkey_data_set", mrb_APR_apr_threadkey_data_set, MRB_ARGS_ARG(apr_threadkey_data_set_REQUIRED_ARGC, apr_threadkey_data_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_threadkey_private_create_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_threadkey_private_create", mrb_APR_apr_threadkey_private_create, MRB_ARGS_ARG(apr_threadkey_private_create_REQUIRED_ARGC, apr_threadkey_private_create_OPTIONAL_ARGC));
#endif
#if BIND_apr_threadkey_private_delete_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_threadkey_private_delete", mrb_APR_apr_threadkey_private_delete, MRB_ARGS_ARG(apr_threadkey_private_delete_REQUIRED_ARGC, apr_threadkey_private_delete_OPTIONAL_ARGC));
#endif
#if BIND_apr_threadkey_private_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_threadkey_private_get", mrb_APR_apr_threadkey_private_get, MRB_ARGS_ARG(apr_threadkey_private_get_REQUIRED_ARGC, apr_threadkey_private_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_threadkey_private_set_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_threadkey_private_set", mrb_APR_apr_threadkey_private_set, MRB_ARGS_ARG(apr_threadkey_private_set_REQUIRED_ARGC, apr_threadkey_private_set_OPTIONAL_ARGC));
#endif
#if BIND_apr_time_ansi_put_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_time_ansi_put", mrb_APR_apr_time_ansi_put, MRB_ARGS_ARG(apr_time_ansi_put_REQUIRED_ARGC, apr_time_ansi_put_OPTIONAL_ARGC));
#endif
#if BIND_apr_time_clock_hires_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_time_clock_hires", mrb_APR_apr_time_clock_hires, MRB_ARGS_ARG(apr_time_clock_hires_REQUIRED_ARGC, apr_time_clock_hires_OPTIONAL_ARGC));
#endif
#if BIND_apr_time_exp_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_time_exp_get", mrb_APR_apr_time_exp_get, MRB_ARGS_ARG(apr_time_exp_get_REQUIRED_ARGC, apr_time_exp_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_time_exp_gmt_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_time_exp_gmt", mrb_APR_apr_time_exp_gmt, MRB_ARGS_ARG(apr_time_exp_gmt_REQUIRED_ARGC, apr_time_exp_gmt_OPTIONAL_ARGC));
#endif
#if BIND_apr_time_exp_gmt_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_time_exp_gmt_get", mrb_APR_apr_time_exp_gmt_get, MRB_ARGS_ARG(apr_time_exp_gmt_get_REQUIRED_ARGC, apr_time_exp_gmt_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_time_exp_lt_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_time_exp_lt", mrb_APR_apr_time_exp_lt, MRB_ARGS_ARG(apr_time_exp_lt_REQUIRED_ARGC, apr_time_exp_lt_OPTIONAL_ARGC));
#endif
#if BIND_apr_time_exp_tz_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_time_exp_tz", mrb_APR_apr_time_exp_tz, MRB_ARGS_ARG(apr_time_exp_tz_REQUIRED_ARGC, apr_time_exp_tz_OPTIONAL_ARGC));
#endif
#if BIND_apr_time_now_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_time_now", mrb_APR_apr_time_now, MRB_ARGS_ARG(apr_time_now_REQUIRED_ARGC, apr_time_now_OPTIONAL_ARGC));
#endif
#if BIND_apr_tokenize_to_argv_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_tokenize_to_argv", mrb_APR_apr_tokenize_to_argv, MRB_ARGS_ARG(apr_tokenize_to_argv_REQUIRED_ARGC, apr_tokenize_to_argv_OPTIONAL_ARGC));
#endif
#if BIND_apr_uid_compare_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_uid_compare", mrb_APR_apr_uid_compare, MRB_ARGS_ARG(apr_uid_compare_REQUIRED_ARGC, apr_uid_compare_OPTIONAL_ARGC));
#endif
#if BIND_apr_uid_current_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_uid_current", mrb_APR_apr_uid_current, MRB_ARGS_ARG(apr_uid_current_REQUIRED_ARGC, apr_uid_current_OPTIONAL_ARGC));
#endif
#if BIND_apr_uid_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_uid_get", mrb_APR_apr_uid_get, MRB_ARGS_ARG(apr_uid_get_REQUIRED_ARGC, apr_uid_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_uid_homepath_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_uid_homepath_get", mrb_APR_apr_uid_homepath_get, MRB_ARGS_ARG(apr_uid_homepath_get_REQUIRED_ARGC, apr_uid_homepath_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_uid_name_get_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_uid_name_get", mrb_APR_apr_uid_name_get, MRB_ARGS_ARG(apr_uid_name_get_REQUIRED_ARGC, apr_uid_name_get_OPTIONAL_ARGC));
#endif
#if BIND_apr_unescape_entity_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_unescape_entity", mrb_APR_apr_unescape_entity, MRB_ARGS_ARG(apr_unescape_entity_REQUIRED_ARGC, apr_unescape_entity_OPTIONAL_ARGC));
#endif
#if BIND_apr_unescape_hex_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_unescape_hex", mrb_APR_apr_unescape_hex, MRB_ARGS_ARG(apr_unescape_hex_REQUIRED_ARGC, apr_unescape_hex_OPTIONAL_ARGC));
#endif
#if BIND_apr_unescape_url_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_unescape_url", mrb_APR_apr_unescape_url, MRB_ARGS_ARG(apr_unescape_url_REQUIRED_ARGC, apr_unescape_url_OPTIONAL_ARGC));
#endif
#if BIND_apr_version_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_version", mrb_APR_apr_version, MRB_ARGS_ARG(apr_version_REQUIRED_ARGC, apr_version_OPTIONAL_ARGC));
#endif
#if BIND_apr_version_string_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_version_string", mrb_APR_apr_version_string, MRB_ARGS_ARG(apr_version_string_REQUIRED_ARGC, apr_version_string_OPTIONAL_ARGC));
#endif
#if BIND_apr_vformatter_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_vformatter", mrb_APR_apr_vformatter, MRB_ARGS_ARG(apr_vformatter_REQUIRED_ARGC, apr_vformatter_OPTIONAL_ARGC));
#endif
#if BIND_apr_vsnprintf_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_vsnprintf", mrb_APR_apr_vsnprintf, MRB_ARGS_ARG(apr_vsnprintf_REQUIRED_ARGC, apr_vsnprintf_OPTIONAL_ARGC));
#endif
#if BIND_apr_wait_for_io_or_timeout_FUNCTION
  mrb_define_class_method(mrb, APR_module, "apr_wait_for_io_or_timeout", mrb_APR_apr_wait_for_io_or_timeout, MRB_ARGS_ARG(apr_wait_for_io_or_timeout_REQUIRED_ARGC, apr_wait_for_io_or_timeout_OPTIONAL_ARGC));
#endif

}

void mrb_mruby_apr_gem_final(mrb_state* mrb){

}

#ifdef __cplusplus
}
#endif
