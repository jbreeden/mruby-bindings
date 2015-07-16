/*
 * TODO: INCLUDES
 */

#include "mruby_NSPR.h"

#ifdef __cplusplus
extern "C" {
#endif

#if BIND_LL_MaxInt_FUNCTION
#define LL_MaxInt_REQUIRED_ARGC 0
#define LL_MaxInt_OPTIONAL_ARGC 0
/* LL_MaxInt
 *
 * Parameters: None
 * Return Type: PRInt64
 */
mrb_value
mrb_NSPR_LL_MaxInt(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRInt64 result = LL_MaxInt();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_long_long(mrb, result);

  return return_value;
}
#endif

#if BIND_LL_MaxUint_FUNCTION
#define LL_MaxUint_REQUIRED_ARGC 0
#define LL_MaxUint_OPTIONAL_ARGC 0
/* LL_MaxUint
 *
 * Parameters: None
 * Return Type: PRUint64
 */
mrb_value
mrb_NSPR_LL_MaxUint(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRUint64 result = LL_MaxUint();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_unsigned_long_long(mrb, result);

  return return_value;
}
#endif

#if BIND_LL_MinInt_FUNCTION
#define LL_MinInt_REQUIRED_ARGC 0
#define LL_MinInt_OPTIONAL_ARGC 0
/* LL_MinInt
 *
 * Parameters: None
 * Return Type: PRInt64
 */
mrb_value
mrb_NSPR_LL_MinInt(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRInt64 result = LL_MinInt();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_long_long(mrb, result);

  return return_value;
}
#endif

#if BIND_LL_Zero_FUNCTION
#define LL_Zero_REQUIRED_ARGC 0
#define LL_Zero_OPTIONAL_ARGC 0
/* LL_Zero
 *
 * Parameters: None
 * Return Type: PRInt64
 */
mrb_value
mrb_NSPR_LL_Zero(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRInt64 result = LL_Zero();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_long_long(mrb, result);

  return return_value;
}
#endif

#if BIND_nspr_InitializePRErrorTable_FUNCTION
#define nspr_InitializePRErrorTable_REQUIRED_ARGC 0
#define nspr_InitializePRErrorTable_OPTIONAL_ARGC 0
/* nspr_InitializePRErrorTable
 *
 * Parameters: None
 * Return Type: void
 */
mrb_value
mrb_NSPR_nspr_InitializePRErrorTable(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  nspr_InitializePRErrorTable();

  return mrb_nil_value();
}
#endif

#if BIND_PL_Base64Decode_FUNCTION
#define PL_Base64Decode_REQUIRED_ARGC 3
#define PL_Base64Decode_OPTIONAL_ARGC 0
/* PL_Base64Decode
 *
 * Parameters:
 * - src: const char *
 * - srclen: unsigned int
 * - dest: char *
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_Base64Decode(mrb_state* mrb, mrb_value self) {
  mrb_value src;
  mrb_value srclen;
  mrb_value dest;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &src, &srclen, &dest);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, src, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, srclen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, dest, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_src = mrb_string_value_cstr(mrb, &src);

  unsigned int native_srclen = mrb_fixnum(srclen);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_dest = strdup(mrb_string_value_cstr(mrb, &dest));

  /* Invocation */
  char * result = PL_Base64Decode(native_src, native_srclen, native_dest);

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

#if BIND_PL_Base64Encode_FUNCTION
#define PL_Base64Encode_REQUIRED_ARGC 3
#define PL_Base64Encode_OPTIONAL_ARGC 0
/* PL_Base64Encode
 *
 * Parameters:
 * - src: const char *
 * - srclen: unsigned int
 * - dest: char *
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_Base64Encode(mrb_state* mrb, mrb_value self) {
  mrb_value src;
  mrb_value srclen;
  mrb_value dest;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &src, &srclen, &dest);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, src, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, srclen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, dest, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_src = mrb_string_value_cstr(mrb, &src);

  unsigned int native_srclen = mrb_fixnum(srclen);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_dest = strdup(mrb_string_value_cstr(mrb, &dest));

  /* Invocation */
  char * result = PL_Base64Encode(native_src, native_srclen, native_dest);

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

#if BIND_PL_CompareStrings_FUNCTION
#define PL_CompareStrings_REQUIRED_ARGC 2
#define PL_CompareStrings_OPTIONAL_ARGC 0
/* PL_CompareStrings
 *
 * Parameters:
 * - v1: const void *
 * - v2: const void *
 * Return Type: PRIntn
 */
mrb_value
mrb_NSPR_PL_CompareStrings(mrb_state* mrb, mrb_value self) {
  mrb_value v1;
  mrb_value v2;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &v1, &v2);


  /* Type checking */
  TODO_type_check_const_void_PTR(v1);
  TODO_type_check_const_void_PTR(v2);


  /* Unbox parameters */
  const void * native_v1 = TODO_mruby_unbox_const_void_PTR(v1);

  const void * native_v2 = TODO_mruby_unbox_const_void_PTR(v2);

  /* Invocation */
  PRIntn result = PL_CompareStrings(native_v1, native_v2);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PL_CompareValues_FUNCTION
#define PL_CompareValues_REQUIRED_ARGC 2
#define PL_CompareValues_OPTIONAL_ARGC 0
/* PL_CompareValues
 *
 * Parameters:
 * - v1: const void *
 * - v2: const void *
 * Return Type: PRIntn
 */
mrb_value
mrb_NSPR_PL_CompareValues(mrb_state* mrb, mrb_value self) {
  mrb_value v1;
  mrb_value v2;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &v1, &v2);


  /* Type checking */
  TODO_type_check_const_void_PTR(v1);
  TODO_type_check_const_void_PTR(v2);


  /* Unbox parameters */
  const void * native_v1 = TODO_mruby_unbox_const_void_PTR(v1);

  const void * native_v2 = TODO_mruby_unbox_const_void_PTR(v2);

  /* Invocation */
  PRIntn result = PL_CompareValues(native_v1, native_v2);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PL_CreateLongOptState_FUNCTION
#define PL_CreateLongOptState_REQUIRED_ARGC 4
#define PL_CreateLongOptState_OPTIONAL_ARGC 0
/* PL_CreateLongOptState
 *
 * Parameters:
 * - argc: int
 * - argv: char **
 * - options: const char *
 * - longOpts: const struct PLLongOpt *
 * Return Type: PLOptState *
 */
mrb_value
mrb_NSPR_PL_CreateLongOptState(mrb_state* mrb, mrb_value self) {
  mrb_value argc;
  mrb_value argv;
  mrb_value options;
  mrb_value longOpts;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &argc, &argv, &options, &longOpts);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, argc, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_char_PTR_PTR(argv);
  if (!mrb_obj_is_kind_of(mrb, options, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_struct_PLLongOpt_PTR(longOpts);


  /* Unbox parameters */
  int native_argc = mrb_fixnum(argc);

  char ** native_argv = TODO_mruby_unbox_char_PTR_PTR(argv);

  const char * native_options = mrb_string_value_cstr(mrb, &options);

  const struct PLLongOpt * native_longOpts = TODO_mruby_unbox_const_struct_PLLongOpt_PTR(longOpts);

  /* Invocation */
  PLOptState * result = PL_CreateLongOptState(native_argc, native_argv, native_options, native_longOpts);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PLOptState_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_CreateOptState_FUNCTION
#define PL_CreateOptState_REQUIRED_ARGC 3
#define PL_CreateOptState_OPTIONAL_ARGC 0
/* PL_CreateOptState
 *
 * Parameters:
 * - argc: int
 * - argv: char **
 * - options: const char *
 * Return Type: PLOptState *
 */
mrb_value
mrb_NSPR_PL_CreateOptState(mrb_state* mrb, mrb_value self) {
  mrb_value argc;
  mrb_value argv;
  mrb_value options;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &argc, &argv, &options);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, argc, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_char_PTR_PTR(argv);
  if (!mrb_obj_is_kind_of(mrb, options, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_argc = mrb_fixnum(argc);

  char ** native_argv = TODO_mruby_unbox_char_PTR_PTR(argv);

  const char * native_options = mrb_string_value_cstr(mrb, &options);

  /* Invocation */
  PLOptState * result = PL_CreateOptState(native_argc, native_argv, native_options);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PLOptState_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_DestroyOptState_FUNCTION
#define PL_DestroyOptState_REQUIRED_ARGC 1
#define PL_DestroyOptState_OPTIONAL_ARGC 0
/* PL_DestroyOptState
 *
 * Parameters:
 * - opt: struct PLOptState *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PL_DestroyOptState(mrb_state* mrb, mrb_value self) {
  mrb_value opt;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &opt);


  /* Type checking */
  TODO_type_check_struct_PLOptState_PTR(opt);


  /* Unbox parameters */
  struct PLOptState * native_opt = TODO_mruby_unbox_struct_PLOptState_PTR(opt);

  /* Invocation */
  PL_DestroyOptState(native_opt);

  return mrb_nil_value();
}
#endif

#if BIND_PL_FPrintError_FUNCTION
#define PL_FPrintError_REQUIRED_ARGC 2
#define PL_FPrintError_OPTIONAL_ARGC 0
/* PL_FPrintError
 *
 * Parameters:
 * - output: struct PRFileDesc *
 * - msg: const char *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PL_FPrintError(mrb_state* mrb, mrb_value self) {
  mrb_value output;
  mrb_value msg;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &output, &msg);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(output);
  if (!mrb_obj_is_kind_of(mrb, msg, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRFileDesc * native_output = TODO_mruby_unbox_struct_PRFileDesc_PTR(output);

  const char * native_msg = mrb_string_value_cstr(mrb, &msg);

  /* Invocation */
  PL_FPrintError(native_output, native_msg);

  return mrb_nil_value();
}
#endif

#if BIND_PL_GetNextOpt_FUNCTION
#define PL_GetNextOpt_REQUIRED_ARGC 16
#define PL_GetNextOpt_OPTIONAL_ARGC 0
/* PL_GetNextOpt
 *
 * Parameters:
 * - opt: struct PLOptState *
 * - key: const void *
 * - v1: const void *
 * - v2: const void *
 * - he: struct PLHashEntry *
 * - i: int
 * - arg: void *
 * - pool: void *
 * - size: unsigned long
 * - pool: void *
 * - item: void *
 * - pool: void *
 * - key: const void *
 * - pool: void *
 * - he: struct PLHashEntry *
 * - flag: unsigned int
 * Return Type: PLOptStatus
 */
mrb_value
mrb_NSPR_PL_GetNextOpt(mrb_state* mrb, mrb_value self) {
  mrb_value opt;
  mrb_value key;
  mrb_value v1;
  mrb_value v2;
  mrb_value he;
  mrb_value i;
  mrb_value arg;
  mrb_value pool;
  mrb_value size;
  mrb_value pool;
  mrb_value item;
  mrb_value pool;
  mrb_value key;
  mrb_value pool;
  mrb_value he;
  mrb_value flag;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooooooooooooo", &opt, &key, &v1, &v2, &he, &i, &arg, &pool, &size, &pool, &item, &pool, &key, &pool, &he, &flag);


  /* Type checking */
  TODO_type_check_struct_PLOptState_PTR(opt);
  TODO_type_check_const_void_PTR(key);
  TODO_type_check_const_void_PTR(v1);
  TODO_type_check_const_void_PTR(v2);
  TODO_type_check_struct_PLHashEntry_PTR(he);
  if (!mrb_obj_is_kind_of(mrb, i, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(arg);
  TODO_type_check_void_PTR(pool);
  TODO_type_check_unsigned_long(size);
  TODO_type_check_void_PTR(pool);
  TODO_type_check_void_PTR(item);
  TODO_type_check_void_PTR(pool);
  TODO_type_check_const_void_PTR(key);
  TODO_type_check_void_PTR(pool);
  TODO_type_check_struct_PLHashEntry_PTR(he);
  if (!mrb_obj_is_kind_of(mrb, flag, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PLOptState * native_opt = TODO_mruby_unbox_struct_PLOptState_PTR(opt);

  const void * native_key = TODO_mruby_unbox_const_void_PTR(key);

  const void * native_v1 = TODO_mruby_unbox_const_void_PTR(v1);

  const void * native_v2 = TODO_mruby_unbox_const_void_PTR(v2);

  struct PLHashEntry * native_he = TODO_mruby_unbox_struct_PLHashEntry_PTR(he);

  int native_i = mrb_fixnum(i);

  void * native_arg = TODO_mruby_unbox_void_PTR(arg);

  void * native_pool = TODO_mruby_unbox_void_PTR(pool);

  unsigned long native_size = TODO_mruby_unbox_unsigned_long(size);

  void * native_pool = TODO_mruby_unbox_void_PTR(pool);

  void * native_item = TODO_mruby_unbox_void_PTR(item);

  void * native_pool = TODO_mruby_unbox_void_PTR(pool);

  const void * native_key = TODO_mruby_unbox_const_void_PTR(key);

  void * native_pool = TODO_mruby_unbox_void_PTR(pool);

  struct PLHashEntry * native_he = TODO_mruby_unbox_struct_PLHashEntry_PTR(he);

  unsigned int native_flag = mrb_fixnum(flag);

  /* Invocation */
  PLOptStatus result = PL_GetNextOpt(native_opt, native_key, native_v1, native_v2, native_he, native_i, native_arg, native_pool, native_size, native_pool, native_item, native_pool, native_key, native_pool, native_he, native_flag);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PLOptStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_HashString_FUNCTION
#define PL_HashString_REQUIRED_ARGC 1
#define PL_HashString_OPTIONAL_ARGC 0
/* PL_HashString
 *
 * Parameters:
 * - key: const void *
 * Return Type: PLHashNumber
 */
mrb_value
mrb_NSPR_PL_HashString(mrb_state* mrb, mrb_value self) {
  mrb_value key;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &key);


  /* Type checking */
  TODO_type_check_const_void_PTR(key);


  /* Unbox parameters */
  const void * native_key = TODO_mruby_unbox_const_void_PTR(key);

  /* Invocation */
  PLHashNumber result = PL_HashString(native_key);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PLHashNumber(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_HashTableAdd_FUNCTION
#define PL_HashTableAdd_REQUIRED_ARGC 3
#define PL_HashTableAdd_OPTIONAL_ARGC 0
/* PL_HashTableAdd
 *
 * Parameters:
 * - ht: struct PLHashTable *
 * - key: const void *
 * - value: void *
 * Return Type: PLHashEntry *
 */
mrb_value
mrb_NSPR_PL_HashTableAdd(mrb_state* mrb, mrb_value self) {
  mrb_value ht;
  mrb_value key;
  mrb_value value;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &ht, &key, &value);


  /* Type checking */
  TODO_type_check_struct_PLHashTable_PTR(ht);
  TODO_type_check_const_void_PTR(key);
  TODO_type_check_void_PTR(value);


  /* Unbox parameters */
  struct PLHashTable * native_ht = TODO_mruby_unbox_struct_PLHashTable_PTR(ht);

  const void * native_key = TODO_mruby_unbox_const_void_PTR(key);

  void * native_value = TODO_mruby_unbox_void_PTR(value);

  /* Invocation */
  PLHashEntry * result = PL_HashTableAdd(native_ht, native_key, native_value);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PLHashEntry_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_HashTableDestroy_FUNCTION
#define PL_HashTableDestroy_REQUIRED_ARGC 1
#define PL_HashTableDestroy_OPTIONAL_ARGC 0
/* PL_HashTableDestroy
 *
 * Parameters:
 * - ht: struct PLHashTable *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PL_HashTableDestroy(mrb_state* mrb, mrb_value self) {
  mrb_value ht;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &ht);


  /* Type checking */
  TODO_type_check_struct_PLHashTable_PTR(ht);


  /* Unbox parameters */
  struct PLHashTable * native_ht = TODO_mruby_unbox_struct_PLHashTable_PTR(ht);

  /* Invocation */
  PL_HashTableDestroy(native_ht);

  return mrb_nil_value();
}
#endif

#if BIND_PL_HashTableDump_FUNCTION
#define PL_HashTableDump_REQUIRED_ARGC 3
#define PL_HashTableDump_OPTIONAL_ARGC 0
/* PL_HashTableDump
 *
 * Parameters:
 * - ht: struct PLHashTable *
 * - dump: int (*)(struct PLHashEntry *, int, void *)
 * - fp: struct __sFILE *
 * Return Type: PRIntn
 */
mrb_value
mrb_NSPR_PL_HashTableDump(mrb_state* mrb, mrb_value self) {
  mrb_value ht;
  mrb_value dump;
  mrb_value fp;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &ht, &dump, &fp);


  /* Type checking */
  TODO_type_check_struct_PLHashTable_PTR(ht);
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_struct_PLHashEntry_PTR_COMMA_intCOMMA_void_PTR_RPAREN(dump);
  TODO_type_check_struct___sFILE_PTR(fp);


  /* Unbox parameters */
  struct PLHashTable * native_ht = TODO_mruby_unbox_struct_PLHashTable_PTR(ht);

  int (*native_dump)(struct PLHashEntry *, int, void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_struct_PLHashEntry_PTR_COMMA_intCOMMA_void_PTR_RPAREN(dump);

  struct __sFILE * native_fp = TODO_mruby_unbox_struct___sFILE_PTR(fp);

  /* Invocation */
  PRIntn result = PL_HashTableDump(native_ht, native_dump, native_fp);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PL_HashTableEnumerateEntries_FUNCTION
#define PL_HashTableEnumerateEntries_REQUIRED_ARGC 3
#define PL_HashTableEnumerateEntries_OPTIONAL_ARGC 0
/* PL_HashTableEnumerateEntries
 *
 * Parameters:
 * - ht: struct PLHashTable *
 * - f: int (*)(struct PLHashEntry *, int, void *)
 * - arg: void *
 * Return Type: PRIntn
 */
mrb_value
mrb_NSPR_PL_HashTableEnumerateEntries(mrb_state* mrb, mrb_value self) {
  mrb_value ht;
  mrb_value f;
  mrb_value arg;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &ht, &f, &arg);


  /* Type checking */
  TODO_type_check_struct_PLHashTable_PTR(ht);
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_struct_PLHashEntry_PTR_COMMA_intCOMMA_void_PTR_RPAREN(f);
  TODO_type_check_void_PTR(arg);


  /* Unbox parameters */
  struct PLHashTable * native_ht = TODO_mruby_unbox_struct_PLHashTable_PTR(ht);

  int (*native_f)(struct PLHashEntry *, int, void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_struct_PLHashEntry_PTR_COMMA_intCOMMA_void_PTR_RPAREN(f);

  void * native_arg = TODO_mruby_unbox_void_PTR(arg);

  /* Invocation */
  PRIntn result = PL_HashTableEnumerateEntries(native_ht, native_f, native_arg);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PL_HashTableLookup_FUNCTION
#define PL_HashTableLookup_REQUIRED_ARGC 2
#define PL_HashTableLookup_OPTIONAL_ARGC 0
/* PL_HashTableLookup
 *
 * Parameters:
 * - ht: struct PLHashTable *
 * - key: const void *
 * Return Type: void *
 */
mrb_value
mrb_NSPR_PL_HashTableLookup(mrb_state* mrb, mrb_value self) {
  mrb_value ht;
  mrb_value key;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &ht, &key);


  /* Type checking */
  TODO_type_check_struct_PLHashTable_PTR(ht);
  TODO_type_check_const_void_PTR(key);


  /* Unbox parameters */
  struct PLHashTable * native_ht = TODO_mruby_unbox_struct_PLHashTable_PTR(ht);

  const void * native_key = TODO_mruby_unbox_const_void_PTR(key);

  /* Invocation */
  void * result = PL_HashTableLookup(native_ht, native_key);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_HashTableLookupConst_FUNCTION
#define PL_HashTableLookupConst_REQUIRED_ARGC 2
#define PL_HashTableLookupConst_OPTIONAL_ARGC 0
/* PL_HashTableLookupConst
 *
 * Parameters:
 * - ht: struct PLHashTable *
 * - key: const void *
 * Return Type: void *
 */
mrb_value
mrb_NSPR_PL_HashTableLookupConst(mrb_state* mrb, mrb_value self) {
  mrb_value ht;
  mrb_value key;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &ht, &key);


  /* Type checking */
  TODO_type_check_struct_PLHashTable_PTR(ht);
  TODO_type_check_const_void_PTR(key);


  /* Unbox parameters */
  struct PLHashTable * native_ht = TODO_mruby_unbox_struct_PLHashTable_PTR(ht);

  const void * native_key = TODO_mruby_unbox_const_void_PTR(key);

  /* Invocation */
  void * result = PL_HashTableLookupConst(native_ht, native_key);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_HashTableRawAdd_FUNCTION
#define PL_HashTableRawAdd_REQUIRED_ARGC 5
#define PL_HashTableRawAdd_OPTIONAL_ARGC 0
/* PL_HashTableRawAdd
 *
 * Parameters:
 * - ht: struct PLHashTable *
 * - hep: struct PLHashEntry **
 * - keyHash: unsigned int
 * - key: const void *
 * - value: void *
 * Return Type: PLHashEntry *
 */
mrb_value
mrb_NSPR_PL_HashTableRawAdd(mrb_state* mrb, mrb_value self) {
  mrb_value ht;
  mrb_value hep;
  mrb_value keyHash;
  mrb_value key;
  mrb_value value;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &ht, &hep, &keyHash, &key, &value);


  /* Type checking */
  TODO_type_check_struct_PLHashTable_PTR(ht);
  TODO_type_check_struct_PLHashEntry_PTR_PTR(hep);
  if (!mrb_obj_is_kind_of(mrb, keyHash, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_void_PTR(key);
  TODO_type_check_void_PTR(value);


  /* Unbox parameters */
  struct PLHashTable * native_ht = TODO_mruby_unbox_struct_PLHashTable_PTR(ht);

  struct PLHashEntry ** native_hep = TODO_mruby_unbox_struct_PLHashEntry_PTR_PTR(hep);

  unsigned int native_keyHash = mrb_fixnum(keyHash);

  const void * native_key = TODO_mruby_unbox_const_void_PTR(key);

  void * native_value = TODO_mruby_unbox_void_PTR(value);

  /* Invocation */
  PLHashEntry * result = PL_HashTableRawAdd(native_ht, native_hep, native_keyHash, native_key, native_value);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PLHashEntry_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_HashTableRawLookup_FUNCTION
#define PL_HashTableRawLookup_REQUIRED_ARGC 3
#define PL_HashTableRawLookup_OPTIONAL_ARGC 0
/* PL_HashTableRawLookup
 *
 * Parameters:
 * - ht: struct PLHashTable *
 * - keyHash: unsigned int
 * - key: const void *
 * Return Type: PLHashEntry **
 */
mrb_value
mrb_NSPR_PL_HashTableRawLookup(mrb_state* mrb, mrb_value self) {
  mrb_value ht;
  mrb_value keyHash;
  mrb_value key;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &ht, &keyHash, &key);


  /* Type checking */
  TODO_type_check_struct_PLHashTable_PTR(ht);
  if (!mrb_obj_is_kind_of(mrb, keyHash, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_void_PTR(key);


  /* Unbox parameters */
  struct PLHashTable * native_ht = TODO_mruby_unbox_struct_PLHashTable_PTR(ht);

  unsigned int native_keyHash = mrb_fixnum(keyHash);

  const void * native_key = TODO_mruby_unbox_const_void_PTR(key);

  /* Invocation */
  PLHashEntry ** result = PL_HashTableRawLookup(native_ht, native_keyHash, native_key);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PLHashEntry_PTR_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_HashTableRawLookupConst_FUNCTION
#define PL_HashTableRawLookupConst_REQUIRED_ARGC 3
#define PL_HashTableRawLookupConst_OPTIONAL_ARGC 0
/* PL_HashTableRawLookupConst
 *
 * Parameters:
 * - ht: struct PLHashTable *
 * - keyHash: unsigned int
 * - key: const void *
 * Return Type: PLHashEntry **
 */
mrb_value
mrb_NSPR_PL_HashTableRawLookupConst(mrb_state* mrb, mrb_value self) {
  mrb_value ht;
  mrb_value keyHash;
  mrb_value key;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &ht, &keyHash, &key);


  /* Type checking */
  TODO_type_check_struct_PLHashTable_PTR(ht);
  if (!mrb_obj_is_kind_of(mrb, keyHash, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_void_PTR(key);


  /* Unbox parameters */
  struct PLHashTable * native_ht = TODO_mruby_unbox_struct_PLHashTable_PTR(ht);

  unsigned int native_keyHash = mrb_fixnum(keyHash);

  const void * native_key = TODO_mruby_unbox_const_void_PTR(key);

  /* Invocation */
  PLHashEntry ** result = PL_HashTableRawLookupConst(native_ht, native_keyHash, native_key);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PLHashEntry_PTR_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_HashTableRawRemove_FUNCTION
#define PL_HashTableRawRemove_REQUIRED_ARGC 3
#define PL_HashTableRawRemove_OPTIONAL_ARGC 0
/* PL_HashTableRawRemove
 *
 * Parameters:
 * - ht: struct PLHashTable *
 * - hep: struct PLHashEntry **
 * - he: struct PLHashEntry *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PL_HashTableRawRemove(mrb_state* mrb, mrb_value self) {
  mrb_value ht;
  mrb_value hep;
  mrb_value he;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &ht, &hep, &he);


  /* Type checking */
  TODO_type_check_struct_PLHashTable_PTR(ht);
  TODO_type_check_struct_PLHashEntry_PTR_PTR(hep);
  TODO_type_check_struct_PLHashEntry_PTR(he);


  /* Unbox parameters */
  struct PLHashTable * native_ht = TODO_mruby_unbox_struct_PLHashTable_PTR(ht);

  struct PLHashEntry ** native_hep = TODO_mruby_unbox_struct_PLHashEntry_PTR_PTR(hep);

  struct PLHashEntry * native_he = TODO_mruby_unbox_struct_PLHashEntry_PTR(he);

  /* Invocation */
  PL_HashTableRawRemove(native_ht, native_hep, native_he);

  return mrb_nil_value();
}
#endif

#if BIND_PL_HashTableRemove_FUNCTION
#define PL_HashTableRemove_REQUIRED_ARGC 2
#define PL_HashTableRemove_OPTIONAL_ARGC 0
/* PL_HashTableRemove
 *
 * Parameters:
 * - ht: struct PLHashTable *
 * - key: const void *
 * Return Type: PRBool
 */
mrb_value
mrb_NSPR_PL_HashTableRemove(mrb_state* mrb, mrb_value self) {
  mrb_value ht;
  mrb_value key;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &ht, &key);


  /* Type checking */
  TODO_type_check_struct_PLHashTable_PTR(ht);
  TODO_type_check_const_void_PTR(key);


  /* Unbox parameters */
  struct PLHashTable * native_ht = TODO_mruby_unbox_struct_PLHashTable_PTR(ht);

  const void * native_key = TODO_mruby_unbox_const_void_PTR(key);

  /* Invocation */
  PRBool result = PL_HashTableRemove(native_ht, native_key);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRBool(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_NewHashTable_FUNCTION
#define PL_NewHashTable_REQUIRED_ARGC 6
#define PL_NewHashTable_OPTIONAL_ARGC 0
/* PL_NewHashTable
 *
 * Parameters:
 * - numBuckets: unsigned int
 * - keyHash: unsigned int (*)(const void *)
 * - keyCompare: int (*)(const void *, const void *)
 * - valueCompare: int (*)(const void *, const void *)
 * - allocOps: const struct PLHashAllocOps *
 * - allocPriv: void *
 * Return Type: PLHashTable *
 */
mrb_value
mrb_NSPR_PL_NewHashTable(mrb_state* mrb, mrb_value self) {
  mrb_value numBuckets;
  mrb_value keyHash;
  mrb_value keyCompare;
  mrb_value valueCompare;
  mrb_value allocOps;
  mrb_value allocPriv;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooo", &numBuckets, &keyHash, &keyCompare, &valueCompare, &allocOps, &allocPriv);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, numBuckets, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_unsigned_int_LPAREN_PTR_RPAREN_LPAREN_const_void_PTR_RPAREN(keyHash);
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_const_void_PTR_COMMA_const_void_PTR_RPAREN(keyCompare);
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_const_void_PTR_COMMA_const_void_PTR_RPAREN(valueCompare);
  TODO_type_check_const_struct_PLHashAllocOps_PTR(allocOps);
  TODO_type_check_void_PTR(allocPriv);


  /* Unbox parameters */
  unsigned int native_numBuckets = mrb_fixnum(numBuckets);

  unsigned int (*native_keyHash)(const void *) = TODO_mruby_unbox_unsigned_int_LPAREN_PTR_RPAREN_LPAREN_const_void_PTR_RPAREN(keyHash);

  int (*native_keyCompare)(const void *, const void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_const_void_PTR_COMMA_const_void_PTR_RPAREN(keyCompare);

  int (*native_valueCompare)(const void *, const void *) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_const_void_PTR_COMMA_const_void_PTR_RPAREN(valueCompare);

  const struct PLHashAllocOps * native_allocOps = TODO_mruby_unbox_const_struct_PLHashAllocOps_PTR(allocOps);

  void * native_allocPriv = TODO_mruby_unbox_void_PTR(allocPriv);

  /* Invocation */
  PLHashTable * result = PL_NewHashTable(native_numBuckets, native_keyHash, native_keyCompare, native_valueCompare, native_allocOps, native_allocPriv);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PLHashTable_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_PrintError_FUNCTION
#define PL_PrintError_REQUIRED_ARGC 1
#define PL_PrintError_OPTIONAL_ARGC 0
/* PL_PrintError
 *
 * Parameters:
 * - msg: const char *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PL_PrintError(mrb_state* mrb, mrb_value self) {
  mrb_value msg;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &msg);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, msg, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_msg = mrb_string_value_cstr(mrb, &msg);

  /* Invocation */
  PL_PrintError(native_msg);

  return mrb_nil_value();
}
#endif

#if BIND_PL_strcasecmp_FUNCTION
#define PL_strcasecmp_REQUIRED_ARGC 2
#define PL_strcasecmp_OPTIONAL_ARGC 0
/* PL_strcasecmp
 *
 * Parameters:
 * - a: const char *
 * - b: const char *
 * Return Type: PRIntn
 */
mrb_value
mrb_NSPR_PL_strcasecmp(mrb_state* mrb, mrb_value self) {
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
  PRIntn result = PL_strcasecmp(native_a, native_b);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PL_strcaserstr_FUNCTION
#define PL_strcaserstr_REQUIRED_ARGC 2
#define PL_strcaserstr_OPTIONAL_ARGC 0
/* PL_strcaserstr
 *
 * Parameters:
 * - big: const char *
 * - little: const char *
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strcaserstr(mrb_state* mrb, mrb_value self) {
  mrb_value big;
  mrb_value little;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &big, &little);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, big, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, little, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_big = mrb_string_value_cstr(mrb, &big);

  const char * native_little = mrb_string_value_cstr(mrb, &little);

  /* Invocation */
  char * result = PL_strcaserstr(native_big, native_little);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_strcasestr_FUNCTION
#define PL_strcasestr_REQUIRED_ARGC 2
#define PL_strcasestr_OPTIONAL_ARGC 0
/* PL_strcasestr
 *
 * Parameters:
 * - big: const char *
 * - little: const char *
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strcasestr(mrb_state* mrb, mrb_value self) {
  mrb_value big;
  mrb_value little;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &big, &little);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, big, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, little, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_big = mrb_string_value_cstr(mrb, &big);

  const char * native_little = mrb_string_value_cstr(mrb, &little);

  /* Invocation */
  char * result = PL_strcasestr(native_big, native_little);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_strcat_FUNCTION
#define PL_strcat_REQUIRED_ARGC 2
#define PL_strcat_OPTIONAL_ARGC 0
/* PL_strcat
 *
 * Parameters:
 * - dst: char *
 * - src: const char *
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strcat(mrb_state* mrb, mrb_value self) {
  mrb_value dst;
  mrb_value src;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &dst, &src);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, dst, mrb->string_class)) {
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
  char * native_dst = strdup(mrb_string_value_cstr(mrb, &dst));

  const char * native_src = mrb_string_value_cstr(mrb, &src);

  /* Invocation */
  char * result = PL_strcat(native_dst, native_src);

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

#if BIND_PL_strcatn_FUNCTION
#define PL_strcatn_REQUIRED_ARGC 3
#define PL_strcatn_OPTIONAL_ARGC 0
/* PL_strcatn
 *
 * Parameters:
 * - dst: char *
 * - max: unsigned int
 * - src: const char *
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strcatn(mrb_state* mrb, mrb_value self) {
  mrb_value dst;
  mrb_value max;
  mrb_value src;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &dst, &max, &src);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, dst, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, max, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
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
  char * native_dst = strdup(mrb_string_value_cstr(mrb, &dst));

  unsigned int native_max = mrb_fixnum(max);

  const char * native_src = mrb_string_value_cstr(mrb, &src);

  /* Invocation */
  char * result = PL_strcatn(native_dst, native_max, native_src);

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

#if BIND_PL_strchr_FUNCTION
#define PL_strchr_REQUIRED_ARGC 2
#define PL_strchr_OPTIONAL_ARGC 0
/* PL_strchr
 *
 * Parameters:
 * - s: const char *
 * - c: char
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strchr(mrb_state* mrb, mrb_value self) {
  mrb_value s;
  mrb_value c;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &s, &c);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_char(c);


  /* Unbox parameters */
  const char * native_s = mrb_string_value_cstr(mrb, &s);

  char native_c = TODO_mruby_unbox_char(c);

  /* Invocation */
  char * result = PL_strchr(native_s, native_c);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_strcmp_FUNCTION
#define PL_strcmp_REQUIRED_ARGC 2
#define PL_strcmp_OPTIONAL_ARGC 0
/* PL_strcmp
 *
 * Parameters:
 * - a: const char *
 * - b: const char *
 * Return Type: PRIntn
 */
mrb_value
mrb_NSPR_PL_strcmp(mrb_state* mrb, mrb_value self) {
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
  PRIntn result = PL_strcmp(native_a, native_b);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PL_strcpy_FUNCTION
#define PL_strcpy_REQUIRED_ARGC 2
#define PL_strcpy_OPTIONAL_ARGC 0
/* PL_strcpy
 *
 * Parameters:
 * - dest: char *
 * - src: const char *
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strcpy(mrb_state* mrb, mrb_value self) {
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
  char * result = PL_strcpy(native_dest, native_src);

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

#if BIND_PL_strdup_FUNCTION
#define PL_strdup_REQUIRED_ARGC 1
#define PL_strdup_OPTIONAL_ARGC 0
/* PL_strdup
 *
 * Parameters:
 * - s: const char *
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strdup(mrb_state* mrb, mrb_value self) {
  mrb_value s;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &s);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_s = mrb_string_value_cstr(mrb, &s);

  /* Invocation */
  char * result = PL_strdup(native_s);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_strfree_FUNCTION
#define PL_strfree_REQUIRED_ARGC 1
#define PL_strfree_OPTIONAL_ARGC 0
/* PL_strfree
 *
 * Parameters:
 * - s: char *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PL_strfree(mrb_state* mrb, mrb_value self) {
  mrb_value s;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &s);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_s = strdup(mrb_string_value_cstr(mrb, &s));

  /* Invocation */
  PL_strfree(native_s);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_s);
  native_s = NULL;

  return mrb_nil_value();
}
#endif

#if BIND_PL_strlen_FUNCTION
#define PL_strlen_REQUIRED_ARGC 1
#define PL_strlen_OPTIONAL_ARGC 0
/* PL_strlen
 *
 * Parameters:
 * - str: const char *
 * Return Type: PRUint32
 */
mrb_value
mrb_NSPR_PL_strlen(mrb_state* mrb, mrb_value self) {
  mrb_value str;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &str);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, str, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_str = mrb_string_value_cstr(mrb, &str);

  /* Invocation */
  PRUint32 result = PL_strlen(native_str);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PL_strncasecmp_FUNCTION
#define PL_strncasecmp_REQUIRED_ARGC 3
#define PL_strncasecmp_OPTIONAL_ARGC 0
/* PL_strncasecmp
 *
 * Parameters:
 * - a: const char *
 * - b: const char *
 * - max: unsigned int
 * Return Type: PRIntn
 */
mrb_value
mrb_NSPR_PL_strncasecmp(mrb_state* mrb, mrb_value self) {
  mrb_value a;
  mrb_value b;
  mrb_value max;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &a, &b, &max);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, a, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, b, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, max, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_a = mrb_string_value_cstr(mrb, &a);

  const char * native_b = mrb_string_value_cstr(mrb, &b);

  unsigned int native_max = mrb_fixnum(max);

  /* Invocation */
  PRIntn result = PL_strncasecmp(native_a, native_b, native_max);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PL_strncaserstr_FUNCTION
#define PL_strncaserstr_REQUIRED_ARGC 3
#define PL_strncaserstr_OPTIONAL_ARGC 0
/* PL_strncaserstr
 *
 * Parameters:
 * - big: const char *
 * - little: const char *
 * - max: unsigned int
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strncaserstr(mrb_state* mrb, mrb_value self) {
  mrb_value big;
  mrb_value little;
  mrb_value max;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &big, &little, &max);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, big, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, little, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, max, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_big = mrb_string_value_cstr(mrb, &big);

  const char * native_little = mrb_string_value_cstr(mrb, &little);

  unsigned int native_max = mrb_fixnum(max);

  /* Invocation */
  char * result = PL_strncaserstr(native_big, native_little, native_max);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_strncasestr_FUNCTION
#define PL_strncasestr_REQUIRED_ARGC 3
#define PL_strncasestr_OPTIONAL_ARGC 0
/* PL_strncasestr
 *
 * Parameters:
 * - big: const char *
 * - little: const char *
 * - max: unsigned int
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strncasestr(mrb_state* mrb, mrb_value self) {
  mrb_value big;
  mrb_value little;
  mrb_value max;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &big, &little, &max);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, big, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, little, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, max, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_big = mrb_string_value_cstr(mrb, &big);

  const char * native_little = mrb_string_value_cstr(mrb, &little);

  unsigned int native_max = mrb_fixnum(max);

  /* Invocation */
  char * result = PL_strncasestr(native_big, native_little, native_max);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_strncat_FUNCTION
#define PL_strncat_REQUIRED_ARGC 3
#define PL_strncat_OPTIONAL_ARGC 0
/* PL_strncat
 *
 * Parameters:
 * - dst: char *
 * - src: const char *
 * - max: unsigned int
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strncat(mrb_state* mrb, mrb_value self) {
  mrb_value dst;
  mrb_value src;
  mrb_value max;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &dst, &src, &max);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, dst, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, src, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, max, mrb->fixnum_class)) {
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

  unsigned int native_max = mrb_fixnum(max);

  /* Invocation */
  char * result = PL_strncat(native_dst, native_src, native_max);

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

#if BIND_PL_strnchr_FUNCTION
#define PL_strnchr_REQUIRED_ARGC 3
#define PL_strnchr_OPTIONAL_ARGC 0
/* PL_strnchr
 *
 * Parameters:
 * - s: const char *
 * - c: char
 * - n: unsigned int
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strnchr(mrb_state* mrb, mrb_value self) {
  mrb_value s;
  mrb_value c;
  mrb_value n;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &s, &c, &n);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_char(c);
  if (!mrb_obj_is_kind_of(mrb, n, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_s = mrb_string_value_cstr(mrb, &s);

  char native_c = TODO_mruby_unbox_char(c);

  unsigned int native_n = mrb_fixnum(n);

  /* Invocation */
  char * result = PL_strnchr(native_s, native_c, native_n);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_strncmp_FUNCTION
#define PL_strncmp_REQUIRED_ARGC 3
#define PL_strncmp_OPTIONAL_ARGC 0
/* PL_strncmp
 *
 * Parameters:
 * - a: const char *
 * - b: const char *
 * - max: unsigned int
 * Return Type: PRIntn
 */
mrb_value
mrb_NSPR_PL_strncmp(mrb_state* mrb, mrb_value self) {
  mrb_value a;
  mrb_value b;
  mrb_value max;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &a, &b, &max);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, a, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, b, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, max, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_a = mrb_string_value_cstr(mrb, &a);

  const char * native_b = mrb_string_value_cstr(mrb, &b);

  unsigned int native_max = mrb_fixnum(max);

  /* Invocation */
  PRIntn result = PL_strncmp(native_a, native_b, native_max);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PL_strncpy_FUNCTION
#define PL_strncpy_REQUIRED_ARGC 3
#define PL_strncpy_OPTIONAL_ARGC 0
/* PL_strncpy
 *
 * Parameters:
 * - dest: char *
 * - src: const char *
 * - max: unsigned int
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strncpy(mrb_state* mrb, mrb_value self) {
  mrb_value dest;
  mrb_value src;
  mrb_value max;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &dest, &src, &max);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, dest, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, src, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, max, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
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

  unsigned int native_max = mrb_fixnum(max);

  /* Invocation */
  char * result = PL_strncpy(native_dest, native_src, native_max);

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

#if BIND_PL_strncpyz_FUNCTION
#define PL_strncpyz_REQUIRED_ARGC 3
#define PL_strncpyz_OPTIONAL_ARGC 0
/* PL_strncpyz
 *
 * Parameters:
 * - dest: char *
 * - src: const char *
 * - max: unsigned int
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strncpyz(mrb_state* mrb, mrb_value self) {
  mrb_value dest;
  mrb_value src;
  mrb_value max;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &dest, &src, &max);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, dest, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, src, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, max, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
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

  unsigned int native_max = mrb_fixnum(max);

  /* Invocation */
  char * result = PL_strncpyz(native_dest, native_src, native_max);

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

#if BIND_PL_strndup_FUNCTION
#define PL_strndup_REQUIRED_ARGC 2
#define PL_strndup_OPTIONAL_ARGC 0
/* PL_strndup
 *
 * Parameters:
 * - s: const char *
 * - max: unsigned int
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strndup(mrb_state* mrb, mrb_value self) {
  mrb_value s;
  mrb_value max;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &s, &max);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, max, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_s = mrb_string_value_cstr(mrb, &s);

  unsigned int native_max = mrb_fixnum(max);

  /* Invocation */
  char * result = PL_strndup(native_s, native_max);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_strnlen_FUNCTION
#define PL_strnlen_REQUIRED_ARGC 2
#define PL_strnlen_OPTIONAL_ARGC 0
/* PL_strnlen
 *
 * Parameters:
 * - str: const char *
 * - max: unsigned int
 * Return Type: PRUint32
 */
mrb_value
mrb_NSPR_PL_strnlen(mrb_state* mrb, mrb_value self) {
  mrb_value str;
  mrb_value max;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &str, &max);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, str, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, max, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_str = mrb_string_value_cstr(mrb, &str);

  unsigned int native_max = mrb_fixnum(max);

  /* Invocation */
  PRUint32 result = PL_strnlen(native_str, native_max);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PL_strnpbrk_FUNCTION
#define PL_strnpbrk_REQUIRED_ARGC 3
#define PL_strnpbrk_OPTIONAL_ARGC 0
/* PL_strnpbrk
 *
 * Parameters:
 * - s: const char *
 * - list: const char *
 * - n: unsigned int
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strnpbrk(mrb_state* mrb, mrb_value self) {
  mrb_value s;
  mrb_value list;
  mrb_value n;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &s, &list, &n);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, list, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, n, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_s = mrb_string_value_cstr(mrb, &s);

  const char * native_list = mrb_string_value_cstr(mrb, &list);

  unsigned int native_n = mrb_fixnum(n);

  /* Invocation */
  char * result = PL_strnpbrk(native_s, native_list, native_n);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_strnprbrk_FUNCTION
#define PL_strnprbrk_REQUIRED_ARGC 3
#define PL_strnprbrk_OPTIONAL_ARGC 0
/* PL_strnprbrk
 *
 * Parameters:
 * - s: const char *
 * - list: const char *
 * - n: unsigned int
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strnprbrk(mrb_state* mrb, mrb_value self) {
  mrb_value s;
  mrb_value list;
  mrb_value n;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &s, &list, &n);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, list, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, n, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_s = mrb_string_value_cstr(mrb, &s);

  const char * native_list = mrb_string_value_cstr(mrb, &list);

  unsigned int native_n = mrb_fixnum(n);

  /* Invocation */
  char * result = PL_strnprbrk(native_s, native_list, native_n);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_strnrchr_FUNCTION
#define PL_strnrchr_REQUIRED_ARGC 3
#define PL_strnrchr_OPTIONAL_ARGC 0
/* PL_strnrchr
 *
 * Parameters:
 * - s: const char *
 * - c: char
 * - n: unsigned int
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strnrchr(mrb_state* mrb, mrb_value self) {
  mrb_value s;
  mrb_value c;
  mrb_value n;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &s, &c, &n);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_char(c);
  if (!mrb_obj_is_kind_of(mrb, n, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_s = mrb_string_value_cstr(mrb, &s);

  char native_c = TODO_mruby_unbox_char(c);

  unsigned int native_n = mrb_fixnum(n);

  /* Invocation */
  char * result = PL_strnrchr(native_s, native_c, native_n);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_strnrstr_FUNCTION
#define PL_strnrstr_REQUIRED_ARGC 3
#define PL_strnrstr_OPTIONAL_ARGC 0
/* PL_strnrstr
 *
 * Parameters:
 * - big: const char *
 * - little: const char *
 * - max: unsigned int
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strnrstr(mrb_state* mrb, mrb_value self) {
  mrb_value big;
  mrb_value little;
  mrb_value max;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &big, &little, &max);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, big, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, little, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, max, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_big = mrb_string_value_cstr(mrb, &big);

  const char * native_little = mrb_string_value_cstr(mrb, &little);

  unsigned int native_max = mrb_fixnum(max);

  /* Invocation */
  char * result = PL_strnrstr(native_big, native_little, native_max);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_strnstr_FUNCTION
#define PL_strnstr_REQUIRED_ARGC 3
#define PL_strnstr_OPTIONAL_ARGC 0
/* PL_strnstr
 *
 * Parameters:
 * - big: const char *
 * - little: const char *
 * - n: unsigned int
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strnstr(mrb_state* mrb, mrb_value self) {
  mrb_value big;
  mrb_value little;
  mrb_value n;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &big, &little, &n);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, big, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, little, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, n, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_big = mrb_string_value_cstr(mrb, &big);

  const char * native_little = mrb_string_value_cstr(mrb, &little);

  unsigned int native_n = mrb_fixnum(n);

  /* Invocation */
  char * result = PL_strnstr(native_big, native_little, native_n);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_strpbrk_FUNCTION
#define PL_strpbrk_REQUIRED_ARGC 2
#define PL_strpbrk_OPTIONAL_ARGC 0
/* PL_strpbrk
 *
 * Parameters:
 * - s: const char *
 * - list: const char *
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strpbrk(mrb_state* mrb, mrb_value self) {
  mrb_value s;
  mrb_value list;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &s, &list);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, list, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_s = mrb_string_value_cstr(mrb, &s);

  const char * native_list = mrb_string_value_cstr(mrb, &list);

  /* Invocation */
  char * result = PL_strpbrk(native_s, native_list);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_strprbrk_FUNCTION
#define PL_strprbrk_REQUIRED_ARGC 2
#define PL_strprbrk_OPTIONAL_ARGC 0
/* PL_strprbrk
 *
 * Parameters:
 * - s: const char *
 * - list: const char *
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strprbrk(mrb_state* mrb, mrb_value self) {
  mrb_value s;
  mrb_value list;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &s, &list);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, list, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_s = mrb_string_value_cstr(mrb, &s);

  const char * native_list = mrb_string_value_cstr(mrb, &list);

  /* Invocation */
  char * result = PL_strprbrk(native_s, native_list);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_strrchr_FUNCTION
#define PL_strrchr_REQUIRED_ARGC 2
#define PL_strrchr_OPTIONAL_ARGC 0
/* PL_strrchr
 *
 * Parameters:
 * - s: const char *
 * - c: char
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strrchr(mrb_state* mrb, mrb_value self) {
  mrb_value s;
  mrb_value c;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &s, &c);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_char(c);


  /* Unbox parameters */
  const char * native_s = mrb_string_value_cstr(mrb, &s);

  char native_c = TODO_mruby_unbox_char(c);

  /* Invocation */
  char * result = PL_strrchr(native_s, native_c);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_strrstr_FUNCTION
#define PL_strrstr_REQUIRED_ARGC 2
#define PL_strrstr_OPTIONAL_ARGC 0
/* PL_strrstr
 *
 * Parameters:
 * - big: const char *
 * - little: const char *
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strrstr(mrb_state* mrb, mrb_value self) {
  mrb_value big;
  mrb_value little;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &big, &little);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, big, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, little, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_big = mrb_string_value_cstr(mrb, &big);

  const char * native_little = mrb_string_value_cstr(mrb, &little);

  /* Invocation */
  char * result = PL_strrstr(native_big, native_little);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_strstr_FUNCTION
#define PL_strstr_REQUIRED_ARGC 2
#define PL_strstr_OPTIONAL_ARGC 0
/* PL_strstr
 *
 * Parameters:
 * - big: const char *
 * - little: const char *
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strstr(mrb_state* mrb, mrb_value self) {
  mrb_value big;
  mrb_value little;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &big, &little);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, big, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, little, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_big = mrb_string_value_cstr(mrb, &big);

  const char * native_little = mrb_string_value_cstr(mrb, &little);

  /* Invocation */
  char * result = PL_strstr(native_big, native_little);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PL_strtok_r_FUNCTION
#define PL_strtok_r_REQUIRED_ARGC 3
#define PL_strtok_r_OPTIONAL_ARGC 0
/* PL_strtok_r
 *
 * Parameters:
 * - s1: char *
 * - s2: const char *
 * - lasts: char **
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PL_strtok_r(mrb_state* mrb, mrb_value self) {
  mrb_value s1;
  mrb_value s2;
  mrb_value lasts;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &s1, &s2, &lasts);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s1, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, s2, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_char_PTR_PTR(lasts);


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_s1 = strdup(mrb_string_value_cstr(mrb, &s1));

  const char * native_s2 = mrb_string_value_cstr(mrb, &s2);

  char ** native_lasts = TODO_mruby_unbox_char_PTR_PTR(lasts);

  /* Invocation */
  char * result = PL_strtok_r(native_s1, native_s2, native_lasts);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_s1);
  native_s1 = NULL;

  return return_value;
}
#endif

#if BIND_PR_Abort_FUNCTION
#define PR_Abort_REQUIRED_ARGC 1
#define PR_Abort_OPTIONAL_ARGC 0
/* PR_Abort
 *
 * Parameters:
 * - arg: void *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_Abort(mrb_state* mrb, mrb_value self) {
  mrb_value arg;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &arg);


  /* Type checking */
  TODO_type_check_void_PTR(arg);


  /* Unbox parameters */
  void * native_arg = TODO_mruby_unbox_void_PTR(arg);

  /* Invocation */
  PR_Abort(native_arg);

  return mrb_nil_value();
}
#endif

#if BIND_PR_Accept_FUNCTION
#define PR_Accept_REQUIRED_ARGC 3
#define PR_Accept_OPTIONAL_ARGC 0
/* PR_Accept
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - addr: union PRNetAddr *
 * - timeout: unsigned int
 * Return Type: PRFileDesc *
 */
mrb_value
mrb_NSPR_PR_Accept(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value addr;
  mrb_value timeout;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &fd, &addr, &timeout);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_union_PRNetAddr_PTR(addr);
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  union PRNetAddr * native_addr = TODO_mruby_unbox_union_PRNetAddr_PTR(addr);

  unsigned int native_timeout = mrb_fixnum(timeout);

  /* Invocation */
  PRFileDesc * result = PR_Accept(native_fd, native_addr, native_timeout);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRFileDesc_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_AcceptRead_FUNCTION
#define PR_AcceptRead_REQUIRED_ARGC 6
#define PR_AcceptRead_OPTIONAL_ARGC 0
/* PR_AcceptRead
 *
 * Parameters:
 * - listenSock: struct PRFileDesc *
 * - acceptedSock: struct PRFileDesc **
 * - peerAddr: union PRNetAddr **
 * - buf: void *
 * - amount: int
 * - timeout: unsigned int
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_AcceptRead(mrb_state* mrb, mrb_value self) {
  mrb_value listenSock;
  mrb_value acceptedSock;
  mrb_value peerAddr;
  mrb_value buf;
  mrb_value amount;
  mrb_value timeout;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooo", &listenSock, &acceptedSock, &peerAddr, &buf, &amount, &timeout);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(listenSock);
  TODO_type_check_struct_PRFileDesc_PTR_PTR(acceptedSock);
  TODO_type_check_union_PRNetAddr_PTR_PTR(peerAddr);
  TODO_type_check_void_PTR(buf);
  if (!mrb_obj_is_kind_of(mrb, amount, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRFileDesc * native_listenSock = TODO_mruby_unbox_struct_PRFileDesc_PTR(listenSock);

  struct PRFileDesc ** native_acceptedSock = TODO_mruby_unbox_struct_PRFileDesc_PTR_PTR(acceptedSock);

  union PRNetAddr ** native_peerAddr = TODO_mruby_unbox_union_PRNetAddr_PTR_PTR(peerAddr);

  void * native_buf = TODO_mruby_unbox_void_PTR(buf);

  int native_amount = mrb_fixnum(amount);

  unsigned int native_timeout = mrb_fixnum(timeout);

  /* Invocation */
  PRInt32 result = PR_AcceptRead(native_listenSock, native_acceptedSock, native_peerAddr, native_buf, native_amount, native_timeout);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_Access_FUNCTION
#define PR_Access_REQUIRED_ARGC 2
#define PR_Access_OPTIONAL_ARGC 0
/* PR_Access
 *
 * Parameters:
 * - name: const char *
 * - how: enum PRAccessHow
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_Access(mrb_state* mrb, mrb_value self) {
  mrb_value name;
  mrb_value how;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &name, &how);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_enum_PRAccessHow(how);


  /* Unbox parameters */
  const char * native_name = mrb_string_value_cstr(mrb, &name);

  enum PRAccessHow native_how = TODO_mruby_unbox_enum_PRAccessHow(how);

  /* Invocation */
  PRStatus result = PR_Access(native_name, native_how);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_AddToCounter_FUNCTION
#define PR_AddToCounter_REQUIRED_ARGC 2
#define PR_AddToCounter_OPTIONAL_ARGC 0
/* PR_AddToCounter
 *
 * Parameters:
 * - handle: void *
 * - value: unsigned int
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_AddToCounter(mrb_state* mrb, mrb_value self) {
  mrb_value handle;
  mrb_value value;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &handle, &value);


  /* Type checking */
  TODO_type_check_void_PTR(handle);
  if (!mrb_obj_is_kind_of(mrb, value, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void * native_handle = TODO_mruby_unbox_void_PTR(handle);

  unsigned int native_value = mrb_fixnum(value);

  /* Invocation */
  PR_AddToCounter(native_handle, native_value);

  return mrb_nil_value();
}
#endif

#if BIND_PR_AddWaitFileDesc_FUNCTION
#define PR_AddWaitFileDesc_REQUIRED_ARGC 2
#define PR_AddWaitFileDesc_OPTIONAL_ARGC 0
/* PR_AddWaitFileDesc
 *
 * Parameters:
 * - group: struct PRWaitGroup *
 * - desc: struct PRRecvWait *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_AddWaitFileDesc(mrb_state* mrb, mrb_value self) {
  mrb_value group;
  mrb_value desc;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &group, &desc);


  /* Type checking */
  TODO_type_check_struct_PRWaitGroup_PTR(group);
  TODO_type_check_struct_PRRecvWait_PTR(desc);


  /* Unbox parameters */
  struct PRWaitGroup * native_group = TODO_mruby_unbox_struct_PRWaitGroup_PTR(group);

  struct PRRecvWait * native_desc = TODO_mruby_unbox_struct_PRRecvWait_PTR(desc);

  /* Invocation */
  PRStatus result = PR_AddWaitFileDesc(native_group, native_desc);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_Assert_FUNCTION
#define PR_Assert_REQUIRED_ARGC 3
#define PR_Assert_OPTIONAL_ARGC 0
/* PR_Assert
 *
 * Parameters:
 * - s: const char *
 * - file: const char *
 * - ln: int
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_Assert(mrb_state* mrb, mrb_value self) {
  mrb_value s;
  mrb_value file;
  mrb_value ln;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &s, &file, &ln);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, file, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, ln, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_s = mrb_string_value_cstr(mrb, &s);

  const char * native_file = mrb_string_value_cstr(mrb, &file);

  int native_ln = mrb_fixnum(ln);

  /* Invocation */
  PR_Assert(native_s, native_file, native_ln);

  return mrb_nil_value();
}
#endif

#if BIND_PR_AssertCurrentThreadInMonitor_FUNCTION
#define PR_AssertCurrentThreadInMonitor_REQUIRED_ARGC 1
#define PR_AssertCurrentThreadInMonitor_OPTIONAL_ARGC 0
/* PR_AssertCurrentThreadInMonitor
 *
 * Parameters:
 * - mon: struct PRMonitor *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_AssertCurrentThreadInMonitor(mrb_state* mrb, mrb_value self) {
  mrb_value mon;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &mon);


  /* Type checking */
  TODO_type_check_struct_PRMonitor_PTR(mon);


  /* Unbox parameters */
  struct PRMonitor * native_mon = TODO_mruby_unbox_struct_PRMonitor_PTR(mon);

  /* Invocation */
  PR_AssertCurrentThreadInMonitor(native_mon);

  return mrb_nil_value();
}
#endif

#if BIND_PR_AssertCurrentThreadOwnsLock_FUNCTION
#define PR_AssertCurrentThreadOwnsLock_REQUIRED_ARGC 1
#define PR_AssertCurrentThreadOwnsLock_OPTIONAL_ARGC 0
/* PR_AssertCurrentThreadOwnsLock
 *
 * Parameters:
 * - lock: struct PRLock *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_AssertCurrentThreadOwnsLock(mrb_state* mrb, mrb_value self) {
  mrb_value lock;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &lock);


  /* Type checking */
  TODO_type_check_struct_PRLock_PTR(lock);


  /* Unbox parameters */
  struct PRLock * native_lock = TODO_mruby_unbox_struct_PRLock_PTR(lock);

  /* Invocation */
  PR_AssertCurrentThreadOwnsLock(native_lock);

  return mrb_nil_value();
}
#endif

#if BIND_PR_AtomicAdd_FUNCTION
#define PR_AtomicAdd_REQUIRED_ARGC 2
#define PR_AtomicAdd_OPTIONAL_ARGC 0
/* PR_AtomicAdd
 *
 * Parameters:
 * - ptr: int *
 * - val: int
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_AtomicAdd(mrb_state* mrb, mrb_value self) {
  mrb_value ptr;
  mrb_value val;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &ptr, &val);


  /* Type checking */
  TODO_type_check_int_PTR(ptr);
  if (!mrb_obj_is_kind_of(mrb, val, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int * native_ptr = TODO_mruby_unbox_int_PTR(ptr);

  int native_val = mrb_fixnum(val);

  /* Invocation */
  PRInt32 result = PR_AtomicAdd(native_ptr, native_val);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_AtomicDecrement_FUNCTION
#define PR_AtomicDecrement_REQUIRED_ARGC 1
#define PR_AtomicDecrement_OPTIONAL_ARGC 0
/* PR_AtomicDecrement
 *
 * Parameters:
 * - val: int *
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_AtomicDecrement(mrb_state* mrb, mrb_value self) {
  mrb_value val;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &val);


  /* Type checking */
  TODO_type_check_int_PTR(val);


  /* Unbox parameters */
  int * native_val = TODO_mruby_unbox_int_PTR(val);

  /* Invocation */
  PRInt32 result = PR_AtomicDecrement(native_val);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_AtomicIncrement_FUNCTION
#define PR_AtomicIncrement_REQUIRED_ARGC 1
#define PR_AtomicIncrement_OPTIONAL_ARGC 0
/* PR_AtomicIncrement
 *
 * Parameters:
 * - val: int *
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_AtomicIncrement(mrb_state* mrb, mrb_value self) {
  mrb_value val;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &val);


  /* Type checking */
  TODO_type_check_int_PTR(val);


  /* Unbox parameters */
  int * native_val = TODO_mruby_unbox_int_PTR(val);

  /* Invocation */
  PRInt32 result = PR_AtomicIncrement(native_val);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_AtomicSet_FUNCTION
#define PR_AtomicSet_REQUIRED_ARGC 2
#define PR_AtomicSet_OPTIONAL_ARGC 0
/* PR_AtomicSet
 *
 * Parameters:
 * - val: int *
 * - newval: int
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_AtomicSet(mrb_state* mrb, mrb_value self) {
  mrb_value val;
  mrb_value newval;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &val, &newval);


  /* Type checking */
  TODO_type_check_int_PTR(val);
  if (!mrb_obj_is_kind_of(mrb, newval, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int * native_val = TODO_mruby_unbox_int_PTR(val);

  int native_newval = mrb_fixnum(newval);

  /* Invocation */
  PRInt32 result = PR_AtomicSet(native_val, native_newval);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_AttachSharedMemory_FUNCTION
#define PR_AttachSharedMemory_REQUIRED_ARGC 2
#define PR_AttachSharedMemory_OPTIONAL_ARGC 0
/* PR_AttachSharedMemory
 *
 * Parameters:
 * - shm: struct PRSharedMemory *
 * - flags: int
 * Return Type: void *
 */
mrb_value
mrb_NSPR_PR_AttachSharedMemory(mrb_state* mrb, mrb_value self) {
  mrb_value shm;
  mrb_value flags;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &shm, &flags);


  /* Type checking */
  TODO_type_check_struct_PRSharedMemory_PTR(shm);
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRSharedMemory * native_shm = TODO_mruby_unbox_struct_PRSharedMemory_PTR(shm);

  int native_flags = mrb_fixnum(flags);

  /* Invocation */
  void * result = PR_AttachSharedMemory(native_shm, native_flags);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_Available_FUNCTION
#define PR_Available_REQUIRED_ARGC 1
#define PR_Available_OPTIONAL_ARGC 0
/* PR_Available
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_Available(mrb_state* mrb, mrb_value self) {
  mrb_value fd;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &fd);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  /* Invocation */
  PRInt32 result = PR_Available(native_fd);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_Available64_FUNCTION
#define PR_Available64_REQUIRED_ARGC 1
#define PR_Available64_OPTIONAL_ARGC 0
/* PR_Available64
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * Return Type: PRInt64
 */
mrb_value
mrb_NSPR_PR_Available64(mrb_state* mrb, mrb_value self) {
  mrb_value fd;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &fd);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  /* Invocation */
  PRInt64 result = PR_Available64(native_fd);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_long_long(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_Bind_FUNCTION
#define PR_Bind_REQUIRED_ARGC 2
#define PR_Bind_OPTIONAL_ARGC 0
/* PR_Bind
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - addr: const union PRNetAddr *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_Bind(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value addr;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &fd, &addr);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_const_union_PRNetAddr_PTR(addr);


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  const union PRNetAddr * native_addr = TODO_mruby_unbox_const_union_PRNetAddr_PTR(addr);

  /* Invocation */
  PRStatus result = PR_Bind(native_fd, native_addr);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_BlockClockInterrupts_FUNCTION
#define PR_BlockClockInterrupts_REQUIRED_ARGC 0
#define PR_BlockClockInterrupts_OPTIONAL_ARGC 0
/* PR_BlockClockInterrupts
 *
 * Parameters: None
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_BlockClockInterrupts(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PR_BlockClockInterrupts();

  return mrb_nil_value();
}
#endif

#if BIND_PR_BlockInterrupt_FUNCTION
#define PR_BlockInterrupt_REQUIRED_ARGC 0
#define PR_BlockInterrupt_OPTIONAL_ARGC 0
/* PR_BlockInterrupt
 *
 * Parameters: None
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_BlockInterrupt(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PR_BlockInterrupt();

  return mrb_nil_value();
}
#endif

#if BIND_PR_Calloc_FUNCTION
#define PR_Calloc_REQUIRED_ARGC 2
#define PR_Calloc_OPTIONAL_ARGC 0
/* PR_Calloc
 *
 * Parameters:
 * - nelem: unsigned int
 * - elsize: unsigned int
 * Return Type: void *
 */
mrb_value
mrb_NSPR_PR_Calloc(mrb_state* mrb, mrb_value self) {
  mrb_value nelem;
  mrb_value elsize;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &nelem, &elsize);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, nelem, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, elsize, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  unsigned int native_nelem = mrb_fixnum(nelem);

  unsigned int native_elsize = mrb_fixnum(elsize);

  /* Invocation */
  void * result = PR_Calloc(native_nelem, native_elsize);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CallOnce_FUNCTION
#define PR_CallOnce_REQUIRED_ARGC 2
#define PR_CallOnce_OPTIONAL_ARGC 0
/* PR_CallOnce
 *
 * Parameters:
 * - once: struct PRCallOnceType *
 * - func: PRStatus (*)(void)
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_CallOnce(mrb_state* mrb, mrb_value self) {
  mrb_value once;
  mrb_value func;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &once, &func);


  /* Type checking */
  TODO_type_check_struct_PRCallOnceType_PTR(once);
  TODO_type_check_PRStatus_LPAREN_PTR_RPAREN_LPAREN_void_RPAREN(func);


  /* Unbox parameters */
  struct PRCallOnceType * native_once = TODO_mruby_unbox_struct_PRCallOnceType_PTR(once);

  PRStatus (*native_func)(void) = TODO_mruby_unbox_PRStatus_LPAREN_PTR_RPAREN_LPAREN_void_RPAREN(func);

  /* Invocation */
  PRStatus result = PR_CallOnce(native_once, native_func);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CallOnceWithArg_FUNCTION
#define PR_CallOnceWithArg_REQUIRED_ARGC 3
#define PR_CallOnceWithArg_OPTIONAL_ARGC 0
/* PR_CallOnceWithArg
 *
 * Parameters:
 * - once: struct PRCallOnceType *
 * - func: PRStatus (*)(void *)
 * - arg: void *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_CallOnceWithArg(mrb_state* mrb, mrb_value self) {
  mrb_value once;
  mrb_value func;
  mrb_value arg;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &once, &func, &arg);


  /* Type checking */
  TODO_type_check_struct_PRCallOnceType_PTR(once);
  TODO_type_check_PRStatus_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(func);
  TODO_type_check_void_PTR(arg);


  /* Unbox parameters */
  struct PRCallOnceType * native_once = TODO_mruby_unbox_struct_PRCallOnceType_PTR(once);

  PRStatus (*native_func)(void *) = TODO_mruby_unbox_PRStatus_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(func);

  void * native_arg = TODO_mruby_unbox_void_PTR(arg);

  /* Invocation */
  PRStatus result = PR_CallOnceWithArg(native_once, native_func, native_arg);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CancelJob_FUNCTION
#define PR_CancelJob_REQUIRED_ARGC 1
#define PR_CancelJob_OPTIONAL_ARGC 0
/* PR_CancelJob
 *
 * Parameters:
 * - job: struct PRJob *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_CancelJob(mrb_state* mrb, mrb_value self) {
  mrb_value job;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &job);


  /* Type checking */
  TODO_type_check_struct_PRJob_PTR(job);


  /* Unbox parameters */
  struct PRJob * native_job = TODO_mruby_unbox_struct_PRJob_PTR(job);

  /* Invocation */
  PRStatus result = PR_CancelJob(native_job);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CancelWaitFileDesc_FUNCTION
#define PR_CancelWaitFileDesc_REQUIRED_ARGC 2
#define PR_CancelWaitFileDesc_OPTIONAL_ARGC 0
/* PR_CancelWaitFileDesc
 *
 * Parameters:
 * - group: struct PRWaitGroup *
 * - desc: struct PRRecvWait *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_CancelWaitFileDesc(mrb_state* mrb, mrb_value self) {
  mrb_value group;
  mrb_value desc;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &group, &desc);


  /* Type checking */
  TODO_type_check_struct_PRWaitGroup_PTR(group);
  TODO_type_check_struct_PRRecvWait_PTR(desc);


  /* Unbox parameters */
  struct PRWaitGroup * native_group = TODO_mruby_unbox_struct_PRWaitGroup_PTR(group);

  struct PRRecvWait * native_desc = TODO_mruby_unbox_struct_PRRecvWait_PTR(desc);

  /* Invocation */
  PRStatus result = PR_CancelWaitFileDesc(native_group, native_desc);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CancelWaitGroup_FUNCTION
#define PR_CancelWaitGroup_REQUIRED_ARGC 1
#define PR_CancelWaitGroup_OPTIONAL_ARGC 0
/* PR_CancelWaitGroup
 *
 * Parameters:
 * - group: struct PRWaitGroup *
 * Return Type: PRRecvWait *
 */
mrb_value
mrb_NSPR_PR_CancelWaitGroup(mrb_state* mrb, mrb_value self) {
  mrb_value group;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &group);


  /* Type checking */
  TODO_type_check_struct_PRWaitGroup_PTR(group);


  /* Unbox parameters */
  struct PRWaitGroup * native_group = TODO_mruby_unbox_struct_PRWaitGroup_PTR(group);

  /* Invocation */
  PRRecvWait * result = PR_CancelWaitGroup(native_group);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRRecvWait_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CeilingLog2_FUNCTION
#define PR_CeilingLog2_REQUIRED_ARGC 1
#define PR_CeilingLog2_OPTIONAL_ARGC 0
/* PR_CeilingLog2
 *
 * Parameters:
 * - i: unsigned int
 * Return Type: PRIntn
 */
mrb_value
mrb_NSPR_PR_CeilingLog2(mrb_state* mrb, mrb_value self) {
  mrb_value i;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &i);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, i, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  unsigned int native_i = mrb_fixnum(i);

  /* Invocation */
  PRIntn result = PR_CeilingLog2(native_i);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_CEnterMonitor_FUNCTION
#define PR_CEnterMonitor_REQUIRED_ARGC 1
#define PR_CEnterMonitor_OPTIONAL_ARGC 0
/* PR_CEnterMonitor
 *
 * Parameters:
 * - address: void *
 * Return Type: PRMonitor *
 */
mrb_value
mrb_NSPR_PR_CEnterMonitor(mrb_state* mrb, mrb_value self) {
  mrb_value address;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &address);


  /* Type checking */
  TODO_type_check_void_PTR(address);


  /* Unbox parameters */
  void * native_address = TODO_mruby_unbox_void_PTR(address);

  /* Invocation */
  PRMonitor * result = PR_CEnterMonitor(native_address);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRMonitor_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CExitMonitor_FUNCTION
#define PR_CExitMonitor_REQUIRED_ARGC 1
#define PR_CExitMonitor_OPTIONAL_ARGC 0
/* PR_CExitMonitor
 *
 * Parameters:
 * - address: void *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_CExitMonitor(mrb_state* mrb, mrb_value self) {
  mrb_value address;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &address);


  /* Type checking */
  TODO_type_check_void_PTR(address);


  /* Unbox parameters */
  void * native_address = TODO_mruby_unbox_void_PTR(address);

  /* Invocation */
  PRStatus result = PR_CExitMonitor(native_address);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_Cleanup_FUNCTION
#define PR_Cleanup_REQUIRED_ARGC 0
#define PR_Cleanup_OPTIONAL_ARGC 0
/* PR_Cleanup
 *
 * Parameters: None
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_Cleanup(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRStatus result = PR_Cleanup();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_ClearInterrupt_FUNCTION
#define PR_ClearInterrupt_REQUIRED_ARGC 0
#define PR_ClearInterrupt_OPTIONAL_ARGC 0
/* PR_ClearInterrupt
 *
 * Parameters: None
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_ClearInterrupt(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PR_ClearInterrupt();

  return mrb_nil_value();
}
#endif

#if BIND_PR_Close_FUNCTION
#define PR_Close_REQUIRED_ARGC 1
#define PR_Close_OPTIONAL_ARGC 0
/* PR_Close
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_Close(mrb_state* mrb, mrb_value self) {
  mrb_value fd;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &fd);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  /* Invocation */
  PRStatus result = PR_Close(native_fd);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CloseDir_FUNCTION
#define PR_CloseDir_REQUIRED_ARGC 1
#define PR_CloseDir_OPTIONAL_ARGC 0
/* PR_CloseDir
 *
 * Parameters:
 * - dir: struct PRDir *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_CloseDir(mrb_state* mrb, mrb_value self) {
  mrb_value dir;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &dir);


  /* Type checking */
  TODO_type_check_struct_PRDir_PTR(dir);


  /* Unbox parameters */
  struct PRDir * native_dir = TODO_mruby_unbox_struct_PRDir_PTR(dir);

  /* Invocation */
  PRStatus result = PR_CloseDir(native_dir);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CloseFileMap_FUNCTION
#define PR_CloseFileMap_REQUIRED_ARGC 1
#define PR_CloseFileMap_OPTIONAL_ARGC 0
/* PR_CloseFileMap
 *
 * Parameters:
 * - fmap: struct PRFileMap *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_CloseFileMap(mrb_state* mrb, mrb_value self) {
  mrb_value fmap;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &fmap);


  /* Type checking */
  TODO_type_check_struct_PRFileMap_PTR(fmap);


  /* Unbox parameters */
  struct PRFileMap * native_fmap = TODO_mruby_unbox_struct_PRFileMap_PTR(fmap);

  /* Invocation */
  PRStatus result = PR_CloseFileMap(native_fmap);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CloseSemaphore_FUNCTION
#define PR_CloseSemaphore_REQUIRED_ARGC 1
#define PR_CloseSemaphore_OPTIONAL_ARGC 0
/* PR_CloseSemaphore
 *
 * Parameters:
 * - sem: struct PRSem *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_CloseSemaphore(mrb_state* mrb, mrb_value self) {
  mrb_value sem;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &sem);


  /* Type checking */
  TODO_type_check_struct_PRSem_PTR(sem);


  /* Unbox parameters */
  struct PRSem * native_sem = TODO_mruby_unbox_struct_PRSem_PTR(sem);

  /* Invocation */
  PRStatus result = PR_CloseSemaphore(native_sem);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CloseSharedMemory_FUNCTION
#define PR_CloseSharedMemory_REQUIRED_ARGC 1
#define PR_CloseSharedMemory_OPTIONAL_ARGC 0
/* PR_CloseSharedMemory
 *
 * Parameters:
 * - shm: struct PRSharedMemory *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_CloseSharedMemory(mrb_state* mrb, mrb_value self) {
  mrb_value shm;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &shm);


  /* Type checking */
  TODO_type_check_struct_PRSharedMemory_PTR(shm);


  /* Unbox parameters */
  struct PRSharedMemory * native_shm = TODO_mruby_unbox_struct_PRSharedMemory_PTR(shm);

  /* Invocation */
  PRStatus result = PR_CloseSharedMemory(native_shm);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CNotify_FUNCTION
#define PR_CNotify_REQUIRED_ARGC 1
#define PR_CNotify_OPTIONAL_ARGC 0
/* PR_CNotify
 *
 * Parameters:
 * - address: void *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_CNotify(mrb_state* mrb, mrb_value self) {
  mrb_value address;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &address);


  /* Type checking */
  TODO_type_check_void_PTR(address);


  /* Unbox parameters */
  void * native_address = TODO_mruby_unbox_void_PTR(address);

  /* Invocation */
  PRStatus result = PR_CNotify(native_address);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CNotifyAll_FUNCTION
#define PR_CNotifyAll_REQUIRED_ARGC 1
#define PR_CNotifyAll_OPTIONAL_ARGC 0
/* PR_CNotifyAll
 *
 * Parameters:
 * - address: void *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_CNotifyAll(mrb_state* mrb, mrb_value self) {
  mrb_value address;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &address);


  /* Type checking */
  TODO_type_check_void_PTR(address);


  /* Unbox parameters */
  void * native_address = TODO_mruby_unbox_void_PTR(address);

  /* Invocation */
  PRStatus result = PR_CNotifyAll(native_address);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_cnvtf_FUNCTION
#define PR_cnvtf_REQUIRED_ARGC 4
#define PR_cnvtf_OPTIONAL_ARGC 0
/* PR_cnvtf
 *
 * Parameters:
 * - buf: char *
 * - bufsz: int
 * - prcsn: int
 * - fval: double
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_cnvtf(mrb_state* mrb, mrb_value self) {
  mrb_value buf;
  mrb_value bufsz;
  mrb_value prcsn;
  mrb_value fval;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &buf, &bufsz, &prcsn, &fval);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, buf, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, bufsz, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, prcsn, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, fval, mrb->float_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Float expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_buf = strdup(mrb_string_value_cstr(mrb, &buf));

  int native_bufsz = mrb_fixnum(bufsz);

  int native_prcsn = mrb_fixnum(prcsn);

  double native_fval = mrb_float(fval);

  /* Invocation */
  PR_cnvtf(native_buf, native_bufsz, native_prcsn, native_fval);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_buf);
  native_buf = NULL;

  return mrb_nil_value();
}
#endif

#if BIND_PR_Connect_FUNCTION
#define PR_Connect_REQUIRED_ARGC 3
#define PR_Connect_OPTIONAL_ARGC 0
/* PR_Connect
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - addr: const union PRNetAddr *
 * - timeout: unsigned int
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_Connect(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value addr;
  mrb_value timeout;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &fd, &addr, &timeout);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_const_union_PRNetAddr_PTR(addr);
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  const union PRNetAddr * native_addr = TODO_mruby_unbox_const_union_PRNetAddr_PTR(addr);

  unsigned int native_timeout = mrb_fixnum(timeout);

  /* Invocation */
  PRStatus result = PR_Connect(native_fd, native_addr, native_timeout);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_ConnectContinue_FUNCTION
#define PR_ConnectContinue_REQUIRED_ARGC 2
#define PR_ConnectContinue_OPTIONAL_ARGC 0
/* PR_ConnectContinue
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - out_flags: short
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_ConnectContinue(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value out_flags;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &fd, &out_flags);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_short(out_flags);


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  short native_out_flags = TODO_mruby_unbox_short(out_flags);

  /* Invocation */
  PRStatus result = PR_ConnectContinue(native_fd, native_out_flags);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_ConvertIPv4AddrToIPv6_FUNCTION
#define PR_ConvertIPv4AddrToIPv6_REQUIRED_ARGC 2
#define PR_ConvertIPv4AddrToIPv6_OPTIONAL_ARGC 0
/* PR_ConvertIPv4AddrToIPv6
 *
 * Parameters:
 * - v4addr: unsigned int
 * - v6addr: struct PRIPv6Addr *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_ConvertIPv4AddrToIPv6(mrb_state* mrb, mrb_value self) {
  mrb_value v4addr;
  mrb_value v6addr;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &v4addr, &v6addr);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, v4addr, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct_PRIPv6Addr_PTR(v6addr);


  /* Unbox parameters */
  unsigned int native_v4addr = mrb_fixnum(v4addr);

  struct PRIPv6Addr * native_v6addr = TODO_mruby_unbox_struct_PRIPv6Addr_PTR(v6addr);

  /* Invocation */
  PR_ConvertIPv4AddrToIPv6(native_v4addr, native_v6addr);

  return mrb_nil_value();
}
#endif

#if BIND_PR_CreateCounter_FUNCTION
#define PR_CreateCounter_REQUIRED_ARGC 3
#define PR_CreateCounter_OPTIONAL_ARGC 0
/* PR_CreateCounter
 *
 * Parameters:
 * - qName: const char *
 * - rName: const char *
 * - description: const char *
 * Return Type: PRCounterHandle
 */
mrb_value
mrb_NSPR_PR_CreateCounter(mrb_state* mrb, mrb_value self) {
  mrb_value qName;
  mrb_value rName;
  mrb_value description;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &qName, &rName, &description);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, qName, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, rName, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, description, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_qName = mrb_string_value_cstr(mrb, &qName);

  const char * native_rName = mrb_string_value_cstr(mrb, &rName);

  const char * native_description = mrb_string_value_cstr(mrb, &description);

  /* Invocation */
  PRCounterHandle result = PR_CreateCounter(native_qName, native_rName, native_description);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CreateFileMap_FUNCTION
#define PR_CreateFileMap_REQUIRED_ARGC 3
#define PR_CreateFileMap_OPTIONAL_ARGC 0
/* PR_CreateFileMap
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - size: long long
 * - prot: enum PRFileMapProtect
 * Return Type: PRFileMap *
 */
mrb_value
mrb_NSPR_PR_CreateFileMap(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value size;
  mrb_value prot;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &fd, &size, &prot);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_long_long(size);
  TODO_type_check_enum_PRFileMapProtect(prot);


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  long long native_size = TODO_mruby_unbox_long_long(size);

  enum PRFileMapProtect native_prot = TODO_mruby_unbox_enum_PRFileMapProtect(prot);

  /* Invocation */
  PRFileMap * result = PR_CreateFileMap(native_fd, native_size, native_prot);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRFileMap_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CreateIOLayer_FUNCTION
#define PR_CreateIOLayer_REQUIRED_ARGC 1
#define PR_CreateIOLayer_OPTIONAL_ARGC 0
/* PR_CreateIOLayer
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * Return Type: PRFileDesc *
 */
mrb_value
mrb_NSPR_PR_CreateIOLayer(mrb_state* mrb, mrb_value self) {
  mrb_value fd;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &fd);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  /* Invocation */
  PRFileDesc * result = PR_CreateIOLayer(native_fd);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRFileDesc_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CreateIOLayerStub_FUNCTION
#define PR_CreateIOLayerStub_REQUIRED_ARGC 2
#define PR_CreateIOLayerStub_OPTIONAL_ARGC 0
/* PR_CreateIOLayerStub
 *
 * Parameters:
 * - ident: int
 * - methods: const struct PRIOMethods *
 * Return Type: PRFileDesc *
 */
mrb_value
mrb_NSPR_PR_CreateIOLayerStub(mrb_state* mrb, mrb_value self) {
  mrb_value ident;
  mrb_value methods;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &ident, &methods);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, ident, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_struct_PRIOMethods_PTR(methods);


  /* Unbox parameters */
  int native_ident = mrb_fixnum(ident);

  const struct PRIOMethods * native_methods = TODO_mruby_unbox_const_struct_PRIOMethods_PTR(methods);

  /* Invocation */
  PRFileDesc * result = PR_CreateIOLayerStub(native_ident, native_methods);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRFileDesc_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CreateMWaitEnumerator_FUNCTION
#define PR_CreateMWaitEnumerator_REQUIRED_ARGC 1
#define PR_CreateMWaitEnumerator_OPTIONAL_ARGC 0
/* PR_CreateMWaitEnumerator
 *
 * Parameters:
 * - group: struct PRWaitGroup *
 * Return Type: PRMWaitEnumerator *
 */
mrb_value
mrb_NSPR_PR_CreateMWaitEnumerator(mrb_state* mrb, mrb_value self) {
  mrb_value group;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &group);


  /* Type checking */
  TODO_type_check_struct_PRWaitGroup_PTR(group);


  /* Unbox parameters */
  struct PRWaitGroup * native_group = TODO_mruby_unbox_struct_PRWaitGroup_PTR(group);

  /* Invocation */
  PRMWaitEnumerator * result = PR_CreateMWaitEnumerator(native_group);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRMWaitEnumerator_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CreateOrderedLock_FUNCTION
#define PR_CreateOrderedLock_REQUIRED_ARGC 2
#define PR_CreateOrderedLock_OPTIONAL_ARGC 0
/* PR_CreateOrderedLock
 *
 * Parameters:
 * - order: int
 * - name: const char *
 * Return Type: PROrderedLock *
 */
mrb_value
mrb_NSPR_PR_CreateOrderedLock(mrb_state* mrb, mrb_value self) {
  mrb_value order;
  mrb_value name;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &order, &name);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, order, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_order = mrb_fixnum(order);

  const char * native_name = mrb_string_value_cstr(mrb, &name);

  /* Invocation */
  PROrderedLock * result = PR_CreateOrderedLock(native_order, native_name);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PROrderedLock_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CreatePipe_FUNCTION
#define PR_CreatePipe_REQUIRED_ARGC 2
#define PR_CreatePipe_OPTIONAL_ARGC 0
/* PR_CreatePipe
 *
 * Parameters:
 * - readPipe: struct PRFileDesc **
 * - writePipe: struct PRFileDesc **
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_CreatePipe(mrb_state* mrb, mrb_value self) {
  mrb_value readPipe;
  mrb_value writePipe;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &readPipe, &writePipe);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR_PTR(readPipe);
  TODO_type_check_struct_PRFileDesc_PTR_PTR(writePipe);


  /* Unbox parameters */
  struct PRFileDesc ** native_readPipe = TODO_mruby_unbox_struct_PRFileDesc_PTR_PTR(readPipe);

  struct PRFileDesc ** native_writePipe = TODO_mruby_unbox_struct_PRFileDesc_PTR_PTR(writePipe);

  /* Invocation */
  PRStatus result = PR_CreatePipe(native_readPipe, native_writePipe);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CreateProcess_FUNCTION
#define PR_CreateProcess_REQUIRED_ARGC 4
#define PR_CreateProcess_OPTIONAL_ARGC 0
/* PR_CreateProcess
 *
 * Parameters:
 * - path: const char *
 * - argv: char *const *
 * - envp: char *const *
 * - attr: const struct PRProcessAttr *
 * Return Type: PRProcess *
 */
mrb_value
mrb_NSPR_PR_CreateProcess(mrb_state* mrb, mrb_value self) {
  mrb_value path;
  mrb_value argv;
  mrb_value envp;
  mrb_value attr;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &path, &argv, &envp, &attr);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, path, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_char_PTR_const_PTR(argv);
  TODO_type_check_char_PTR_const_PTR(envp);
  TODO_type_check_const_struct_PRProcessAttr_PTR(attr);


  /* Unbox parameters */
  const char * native_path = mrb_string_value_cstr(mrb, &path);

  char *const * native_argv = TODO_mruby_unbox_char_PTR_const_PTR(argv);

  char *const * native_envp = TODO_mruby_unbox_char_PTR_const_PTR(envp);

  const struct PRProcessAttr * native_attr = TODO_mruby_unbox_const_struct_PRProcessAttr_PTR(attr);

  /* Invocation */
  PRProcess * result = PR_CreateProcess(native_path, native_argv, native_envp, native_attr);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRProcess_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CreateProcessDetached_FUNCTION
#define PR_CreateProcessDetached_REQUIRED_ARGC 4
#define PR_CreateProcessDetached_OPTIONAL_ARGC 0
/* PR_CreateProcessDetached
 *
 * Parameters:
 * - path: const char *
 * - argv: char *const *
 * - envp: char *const *
 * - attr: const struct PRProcessAttr *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_CreateProcessDetached(mrb_state* mrb, mrb_value self) {
  mrb_value path;
  mrb_value argv;
  mrb_value envp;
  mrb_value attr;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &path, &argv, &envp, &attr);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, path, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_char_PTR_const_PTR(argv);
  TODO_type_check_char_PTR_const_PTR(envp);
  TODO_type_check_const_struct_PRProcessAttr_PTR(attr);


  /* Unbox parameters */
  const char * native_path = mrb_string_value_cstr(mrb, &path);

  char *const * native_argv = TODO_mruby_unbox_char_PTR_const_PTR(argv);

  char *const * native_envp = TODO_mruby_unbox_char_PTR_const_PTR(envp);

  const struct PRProcessAttr * native_attr = TODO_mruby_unbox_const_struct_PRProcessAttr_PTR(attr);

  /* Invocation */
  PRStatus result = PR_CreateProcessDetached(native_path, native_argv, native_envp, native_attr);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CreateStack_FUNCTION
#define PR_CreateStack_REQUIRED_ARGC 1
#define PR_CreateStack_OPTIONAL_ARGC 0
/* PR_CreateStack
 *
 * Parameters:
 * - stack_name: const char *
 * Return Type: PRStack *
 */
mrb_value
mrb_NSPR_PR_CreateStack(mrb_state* mrb, mrb_value self) {
  mrb_value stack_name;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &stack_name);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, stack_name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_stack_name = mrb_string_value_cstr(mrb, &stack_name);

  /* Invocation */
  PRStack * result = PR_CreateStack(native_stack_name);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStack_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CreateThread_FUNCTION
#define PR_CreateThread_REQUIRED_ARGC 8
#define PR_CreateThread_OPTIONAL_ARGC 0
/* PR_CreateThread
 *
 * Parameters:
 * - type: enum PRThreadType
 * - start: void (*)(void *)
 * - arg: void *
 * - arg: void *
 * - priority: enum PRThreadPriority
 * - scope: enum PRThreadScope
 * - state: enum PRThreadState
 * - stackSize: unsigned int
 * Return Type: PRThread *
 */
mrb_value
mrb_NSPR_PR_CreateThread(mrb_state* mrb, mrb_value self) {
  mrb_value type;
  mrb_value start;
  mrb_value arg;
  mrb_value arg;
  mrb_value priority;
  mrb_value scope;
  mrb_value state;
  mrb_value stackSize;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooooo", &type, &start, &arg, &arg, &priority, &scope, &state, &stackSize);


  /* Type checking */
  TODO_type_check_enum_PRThreadType(type);
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(start);
  TODO_type_check_void_PTR(arg);
  TODO_type_check_void_PTR(arg);
  TODO_type_check_enum_PRThreadPriority(priority);
  TODO_type_check_enum_PRThreadScope(scope);
  TODO_type_check_enum_PRThreadState(state);
  if (!mrb_obj_is_kind_of(mrb, stackSize, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  enum PRThreadType native_type = TODO_mruby_unbox_enum_PRThreadType(type);

  void (*native_start)(void *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(start);

  void * native_arg = TODO_mruby_unbox_void_PTR(arg);

  void * native_arg = TODO_mruby_unbox_void_PTR(arg);

  enum PRThreadPriority native_priority = TODO_mruby_unbox_enum_PRThreadPriority(priority);

  enum PRThreadScope native_scope = TODO_mruby_unbox_enum_PRThreadScope(scope);

  enum PRThreadState native_state = TODO_mruby_unbox_enum_PRThreadState(state);

  unsigned int native_stackSize = mrb_fixnum(stackSize);

  /* Invocation */
  PRThread * result = PR_CreateThread(native_type, native_start, native_arg, native_arg, native_priority, native_scope, native_state, native_stackSize);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRThread_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CreateThreadPool_FUNCTION
#define PR_CreateThreadPool_REQUIRED_ARGC 3
#define PR_CreateThreadPool_OPTIONAL_ARGC 0
/* PR_CreateThreadPool
 *
 * Parameters:
 * - initial_threads: int
 * - max_threads: int
 * - stacksize: unsigned int
 * Return Type: PRThreadPool *
 */
mrb_value
mrb_NSPR_PR_CreateThreadPool(mrb_state* mrb, mrb_value self) {
  mrb_value initial_threads;
  mrb_value max_threads;
  mrb_value stacksize;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &initial_threads, &max_threads, &stacksize);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, initial_threads, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, max_threads, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, stacksize, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_initial_threads = mrb_fixnum(initial_threads);

  int native_max_threads = mrb_fixnum(max_threads);

  unsigned int native_stacksize = mrb_fixnum(stacksize);

  /* Invocation */
  PRThreadPool * result = PR_CreateThreadPool(native_initial_threads, native_max_threads, native_stacksize);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRThreadPool_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CreateTrace_FUNCTION
#define PR_CreateTrace_REQUIRED_ARGC 3
#define PR_CreateTrace_OPTIONAL_ARGC 0
/* PR_CreateTrace
 *
 * Parameters:
 * - qName: const char *
 * - rName: const char *
 * - description: const char *
 * Return Type: PRTraceHandle
 */
mrb_value
mrb_NSPR_PR_CreateTrace(mrb_state* mrb, mrb_value self) {
  mrb_value qName;
  mrb_value rName;
  mrb_value description;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &qName, &rName, &description);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, qName, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, rName, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, description, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_qName = mrb_string_value_cstr(mrb, &qName);

  const char * native_rName = mrb_string_value_cstr(mrb, &rName);

  const char * native_description = mrb_string_value_cstr(mrb, &description);

  /* Invocation */
  PRTraceHandle result = PR_CreateTrace(native_qName, native_rName, native_description);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CreateWaitGroup_FUNCTION
#define PR_CreateWaitGroup_REQUIRED_ARGC 1
#define PR_CreateWaitGroup_OPTIONAL_ARGC 0
/* PR_CreateWaitGroup
 *
 * Parameters:
 * - size: int
 * Return Type: PRWaitGroup *
 */
mrb_value
mrb_NSPR_PR_CreateWaitGroup(mrb_state* mrb, mrb_value self) {
  mrb_value size;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &size);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, size, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_size = mrb_fixnum(size);

  /* Invocation */
  PRWaitGroup * result = PR_CreateWaitGroup(native_size);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRWaitGroup_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_CSetOnMonitorRecycle_FUNCTION
#define PR_CSetOnMonitorRecycle_REQUIRED_ARGC 2
#define PR_CSetOnMonitorRecycle_OPTIONAL_ARGC 0
/* PR_CSetOnMonitorRecycle
 *
 * Parameters:
 * - callback: void (*)(void *)
 * - address: void *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_CSetOnMonitorRecycle(mrb_state* mrb, mrb_value self) {
  mrb_value callback;
  mrb_value address;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &callback, &address);


  /* Type checking */
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(callback);
  TODO_type_check_void_PTR(address);


  /* Unbox parameters */
  void (*native_callback)(void *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(callback);

  void * native_address = TODO_mruby_unbox_void_PTR(address);

  /* Invocation */
  PR_CSetOnMonitorRecycle(native_callback, native_address);

  return mrb_nil_value();
}
#endif

#if BIND_PR_CWait_FUNCTION
#define PR_CWait_REQUIRED_ARGC 2
#define PR_CWait_OPTIONAL_ARGC 0
/* PR_CWait
 *
 * Parameters:
 * - address: void *
 * - timeout: unsigned int
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_CWait(mrb_state* mrb, mrb_value self) {
  mrb_value address;
  mrb_value timeout;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &address, &timeout);


  /* Type checking */
  TODO_type_check_void_PTR(address);
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void * native_address = TODO_mruby_unbox_void_PTR(address);

  unsigned int native_timeout = mrb_fixnum(timeout);

  /* Invocation */
  PRStatus result = PR_CWait(native_address, native_timeout);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_DecrementCounter_FUNCTION
#define PR_DecrementCounter_REQUIRED_ARGC 1
#define PR_DecrementCounter_OPTIONAL_ARGC 0
/* PR_DecrementCounter
 *
 * Parameters:
 * - handle: void *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_DecrementCounter(mrb_state* mrb, mrb_value self) {
  mrb_value handle;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &handle);


  /* Type checking */
  TODO_type_check_void_PTR(handle);


  /* Unbox parameters */
  void * native_handle = TODO_mruby_unbox_void_PTR(handle);

  /* Invocation */
  PR_DecrementCounter(native_handle);

  return mrb_nil_value();
}
#endif

#if BIND_PR_Delete_FUNCTION
#define PR_Delete_REQUIRED_ARGC 1
#define PR_Delete_OPTIONAL_ARGC 0
/* PR_Delete
 *
 * Parameters:
 * - name: const char *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_Delete(mrb_state* mrb, mrb_value self) {
  mrb_value name;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &name);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_name = mrb_string_value_cstr(mrb, &name);

  /* Invocation */
  PRStatus result = PR_Delete(native_name);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_DeleteSemaphore_FUNCTION
#define PR_DeleteSemaphore_REQUIRED_ARGC 1
#define PR_DeleteSemaphore_OPTIONAL_ARGC 0
/* PR_DeleteSemaphore
 *
 * Parameters:
 * - name: const char *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_DeleteSemaphore(mrb_state* mrb, mrb_value self) {
  mrb_value name;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &name);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_name = mrb_string_value_cstr(mrb, &name);

  /* Invocation */
  PRStatus result = PR_DeleteSemaphore(native_name);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_DeleteSharedMemory_FUNCTION
#define PR_DeleteSharedMemory_REQUIRED_ARGC 1
#define PR_DeleteSharedMemory_OPTIONAL_ARGC 0
/* PR_DeleteSharedMemory
 *
 * Parameters:
 * - name: const char *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_DeleteSharedMemory(mrb_state* mrb, mrb_value self) {
  mrb_value name;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &name);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_name = mrb_string_value_cstr(mrb, &name);

  /* Invocation */
  PRStatus result = PR_DeleteSharedMemory(native_name);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_DestroyCondVar_FUNCTION
#define PR_DestroyCondVar_REQUIRED_ARGC 1
#define PR_DestroyCondVar_OPTIONAL_ARGC 0
/* PR_DestroyCondVar
 *
 * Parameters:
 * - cvar: struct PRCondVar *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_DestroyCondVar(mrb_state* mrb, mrb_value self) {
  mrb_value cvar;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &cvar);


  /* Type checking */
  TODO_type_check_struct_PRCondVar_PTR(cvar);


  /* Unbox parameters */
  struct PRCondVar * native_cvar = TODO_mruby_unbox_struct_PRCondVar_PTR(cvar);

  /* Invocation */
  PR_DestroyCondVar(native_cvar);

  return mrb_nil_value();
}
#endif

#if BIND_PR_DestroyCounter_FUNCTION
#define PR_DestroyCounter_REQUIRED_ARGC 1
#define PR_DestroyCounter_OPTIONAL_ARGC 0
/* PR_DestroyCounter
 *
 * Parameters:
 * - handle: void *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_DestroyCounter(mrb_state* mrb, mrb_value self) {
  mrb_value handle;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &handle);


  /* Type checking */
  TODO_type_check_void_PTR(handle);


  /* Unbox parameters */
  void * native_handle = TODO_mruby_unbox_void_PTR(handle);

  /* Invocation */
  PR_DestroyCounter(native_handle);

  return mrb_nil_value();
}
#endif

#if BIND_PR_DestroyLock_FUNCTION
#define PR_DestroyLock_REQUIRED_ARGC 1
#define PR_DestroyLock_OPTIONAL_ARGC 0
/* PR_DestroyLock
 *
 * Parameters:
 * - lock: struct PRLock *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_DestroyLock(mrb_state* mrb, mrb_value self) {
  mrb_value lock;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &lock);


  /* Type checking */
  TODO_type_check_struct_PRLock_PTR(lock);


  /* Unbox parameters */
  struct PRLock * native_lock = TODO_mruby_unbox_struct_PRLock_PTR(lock);

  /* Invocation */
  PR_DestroyLock(native_lock);

  return mrb_nil_value();
}
#endif

#if BIND_PR_DestroyMonitor_FUNCTION
#define PR_DestroyMonitor_REQUIRED_ARGC 1
#define PR_DestroyMonitor_OPTIONAL_ARGC 0
/* PR_DestroyMonitor
 *
 * Parameters:
 * - mon: struct PRMonitor *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_DestroyMonitor(mrb_state* mrb, mrb_value self) {
  mrb_value mon;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &mon);


  /* Type checking */
  TODO_type_check_struct_PRMonitor_PTR(mon);


  /* Unbox parameters */
  struct PRMonitor * native_mon = TODO_mruby_unbox_struct_PRMonitor_PTR(mon);

  /* Invocation */
  PR_DestroyMonitor(native_mon);

  return mrb_nil_value();
}
#endif

#if BIND_PR_DestroyMWaitEnumerator_FUNCTION
#define PR_DestroyMWaitEnumerator_REQUIRED_ARGC 1
#define PR_DestroyMWaitEnumerator_OPTIONAL_ARGC 0
/* PR_DestroyMWaitEnumerator
 *
 * Parameters:
 * - enumerator: struct PRMWaitEnumerator *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_DestroyMWaitEnumerator(mrb_state* mrb, mrb_value self) {
  mrb_value enumerator;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &enumerator);


  /* Type checking */
  TODO_type_check_struct_PRMWaitEnumerator_PTR(enumerator);


  /* Unbox parameters */
  struct PRMWaitEnumerator * native_enumerator = TODO_mruby_unbox_struct_PRMWaitEnumerator_PTR(enumerator);

  /* Invocation */
  PRStatus result = PR_DestroyMWaitEnumerator(native_enumerator);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_DestroyOrderedLock_FUNCTION
#define PR_DestroyOrderedLock_REQUIRED_ARGC 1
#define PR_DestroyOrderedLock_OPTIONAL_ARGC 0
/* PR_DestroyOrderedLock
 *
 * Parameters:
 * - lock: struct PRLock *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_DestroyOrderedLock(mrb_state* mrb, mrb_value self) {
  mrb_value lock;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &lock);


  /* Type checking */
  TODO_type_check_struct_PRLock_PTR(lock);


  /* Unbox parameters */
  struct PRLock * native_lock = TODO_mruby_unbox_struct_PRLock_PTR(lock);

  /* Invocation */
  PR_DestroyOrderedLock(native_lock);

  return mrb_nil_value();
}
#endif

#if BIND_PR_DestroyPollableEvent_FUNCTION
#define PR_DestroyPollableEvent_REQUIRED_ARGC 1
#define PR_DestroyPollableEvent_OPTIONAL_ARGC 0
/* PR_DestroyPollableEvent
 *
 * Parameters:
 * - event: struct PRFileDesc *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_DestroyPollableEvent(mrb_state* mrb, mrb_value self) {
  mrb_value event;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &event);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(event);


  /* Unbox parameters */
  struct PRFileDesc * native_event = TODO_mruby_unbox_struct_PRFileDesc_PTR(event);

  /* Invocation */
  PRStatus result = PR_DestroyPollableEvent(native_event);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_DestroyProcessAttr_FUNCTION
#define PR_DestroyProcessAttr_REQUIRED_ARGC 1
#define PR_DestroyProcessAttr_OPTIONAL_ARGC 0
/* PR_DestroyProcessAttr
 *
 * Parameters:
 * - attr: struct PRProcessAttr *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_DestroyProcessAttr(mrb_state* mrb, mrb_value self) {
  mrb_value attr;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &attr);


  /* Type checking */
  TODO_type_check_struct_PRProcessAttr_PTR(attr);


  /* Unbox parameters */
  struct PRProcessAttr * native_attr = TODO_mruby_unbox_struct_PRProcessAttr_PTR(attr);

  /* Invocation */
  PR_DestroyProcessAttr(native_attr);

  return mrb_nil_value();
}
#endif

#if BIND_PR_DestroyRWLock_FUNCTION
#define PR_DestroyRWLock_REQUIRED_ARGC 1
#define PR_DestroyRWLock_OPTIONAL_ARGC 0
/* PR_DestroyRWLock
 *
 * Parameters:
 * - lock: struct PRRWLock *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_DestroyRWLock(mrb_state* mrb, mrb_value self) {
  mrb_value lock;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &lock);


  /* Type checking */
  TODO_type_check_struct_PRRWLock_PTR(lock);


  /* Unbox parameters */
  struct PRRWLock * native_lock = TODO_mruby_unbox_struct_PRRWLock_PTR(lock);

  /* Invocation */
  PR_DestroyRWLock(native_lock);

  return mrb_nil_value();
}
#endif

#if BIND_PR_DestroyStack_FUNCTION
#define PR_DestroyStack_REQUIRED_ARGC 1
#define PR_DestroyStack_OPTIONAL_ARGC 0
/* PR_DestroyStack
 *
 * Parameters:
 * - stack: struct PRStackStr *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_DestroyStack(mrb_state* mrb, mrb_value self) {
  mrb_value stack;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &stack);


  /* Type checking */
  TODO_type_check_struct_PRStackStr_PTR(stack);


  /* Unbox parameters */
  struct PRStackStr * native_stack = TODO_mruby_unbox_struct_PRStackStr_PTR(stack);

  /* Invocation */
  PRStatus result = PR_DestroyStack(native_stack);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_DestroyTrace_FUNCTION
#define PR_DestroyTrace_REQUIRED_ARGC 1
#define PR_DestroyTrace_OPTIONAL_ARGC 0
/* PR_DestroyTrace
 *
 * Parameters:
 * - handle: void *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_DestroyTrace(mrb_state* mrb, mrb_value self) {
  mrb_value handle;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &handle);


  /* Type checking */
  TODO_type_check_void_PTR(handle);


  /* Unbox parameters */
  void * native_handle = TODO_mruby_unbox_void_PTR(handle);

  /* Invocation */
  PR_DestroyTrace(native_handle);

  return mrb_nil_value();
}
#endif

#if BIND_PR_DestroyWaitGroup_FUNCTION
#define PR_DestroyWaitGroup_REQUIRED_ARGC 1
#define PR_DestroyWaitGroup_OPTIONAL_ARGC 0
/* PR_DestroyWaitGroup
 *
 * Parameters:
 * - group: struct PRWaitGroup *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_DestroyWaitGroup(mrb_state* mrb, mrb_value self) {
  mrb_value group;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &group);


  /* Type checking */
  TODO_type_check_struct_PRWaitGroup_PTR(group);


  /* Unbox parameters */
  struct PRWaitGroup * native_group = TODO_mruby_unbox_struct_PRWaitGroup_PTR(group);

  /* Invocation */
  PRStatus result = PR_DestroyWaitGroup(native_group);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_DetachProcess_FUNCTION
#define PR_DetachProcess_REQUIRED_ARGC 1
#define PR_DetachProcess_OPTIONAL_ARGC 0
/* PR_DetachProcess
 *
 * Parameters:
 * - process: struct PRProcess *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_DetachProcess(mrb_state* mrb, mrb_value self) {
  mrb_value process;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &process);


  /* Type checking */
  TODO_type_check_struct_PRProcess_PTR(process);


  /* Unbox parameters */
  struct PRProcess * native_process = TODO_mruby_unbox_struct_PRProcess_PTR(process);

  /* Invocation */
  PRStatus result = PR_DetachProcess(native_process);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_DetachSharedMemory_FUNCTION
#define PR_DetachSharedMemory_REQUIRED_ARGC 2
#define PR_DetachSharedMemory_OPTIONAL_ARGC 0
/* PR_DetachSharedMemory
 *
 * Parameters:
 * - shm: struct PRSharedMemory *
 * - addr: void *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_DetachSharedMemory(mrb_state* mrb, mrb_value self) {
  mrb_value shm;
  mrb_value addr;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &shm, &addr);


  /* Type checking */
  TODO_type_check_struct_PRSharedMemory_PTR(shm);
  TODO_type_check_void_PTR(addr);


  /* Unbox parameters */
  struct PRSharedMemory * native_shm = TODO_mruby_unbox_struct_PRSharedMemory_PTR(shm);

  void * native_addr = TODO_mruby_unbox_void_PTR(addr);

  /* Invocation */
  PRStatus result = PR_DetachSharedMemory(native_shm, native_addr);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_DisableClockInterrupts_FUNCTION
#define PR_DisableClockInterrupts_REQUIRED_ARGC 0
#define PR_DisableClockInterrupts_OPTIONAL_ARGC 0
/* PR_DisableClockInterrupts
 *
 * Parameters: None
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_DisableClockInterrupts(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PR_DisableClockInterrupts();

  return mrb_nil_value();
}
#endif

#if BIND_PR_dtoa_FUNCTION
#define PR_dtoa_REQUIRED_ARGC 8
#define PR_dtoa_OPTIONAL_ARGC 0
/* PR_dtoa
 *
 * Parameters:
 * - d: double
 * - mode: int
 * - ndigits: int
 * - decpt: int *
 * - sign: int *
 * - rve: char **
 * - buf: char *
 * - bufsize: unsigned long
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_dtoa(mrb_state* mrb, mrb_value self) {
  mrb_value d;
  mrb_value mode;
  mrb_value ndigits;
  mrb_value decpt;
  mrb_value sign;
  mrb_value rve;
  mrb_value buf;
  mrb_value bufsize;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooooo", &d, &mode, &ndigits, &decpt, &sign, &rve, &buf, &bufsize);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, d, mrb->float_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Float expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, mode, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, ndigits, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(decpt);
  TODO_type_check_int_PTR(sign);
  TODO_type_check_char_PTR_PTR(rve);
  if (!mrb_obj_is_kind_of(mrb, buf, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_unsigned_long(bufsize);


  /* Unbox parameters */
  double native_d = mrb_float(d);

  int native_mode = mrb_fixnum(mode);

  int native_ndigits = mrb_fixnum(ndigits);

  int * native_decpt = TODO_mruby_unbox_int_PTR(decpt);

  int * native_sign = TODO_mruby_unbox_int_PTR(sign);

  char ** native_rve = TODO_mruby_unbox_char_PTR_PTR(rve);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_buf = strdup(mrb_string_value_cstr(mrb, &buf));

  unsigned long native_bufsize = TODO_mruby_unbox_unsigned_long(bufsize);

  /* Invocation */
  PRStatus result = PR_dtoa(native_d, native_mode, native_ndigits, native_decpt, native_sign, native_rve, native_buf, native_bufsize);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

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

#if BIND_PR_EnableClockInterrupts_FUNCTION
#define PR_EnableClockInterrupts_REQUIRED_ARGC 0
#define PR_EnableClockInterrupts_OPTIONAL_ARGC 0
/* PR_EnableClockInterrupts
 *
 * Parameters: None
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_EnableClockInterrupts(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PR_EnableClockInterrupts();

  return mrb_nil_value();
}
#endif

#if BIND_PR_EnterMonitor_FUNCTION
#define PR_EnterMonitor_REQUIRED_ARGC 1
#define PR_EnterMonitor_OPTIONAL_ARGC 0
/* PR_EnterMonitor
 *
 * Parameters:
 * - mon: struct PRMonitor *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_EnterMonitor(mrb_state* mrb, mrb_value self) {
  mrb_value mon;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &mon);


  /* Type checking */
  TODO_type_check_struct_PRMonitor_PTR(mon);


  /* Unbox parameters */
  struct PRMonitor * native_mon = TODO_mruby_unbox_struct_PRMonitor_PTR(mon);

  /* Invocation */
  PR_EnterMonitor(native_mon);

  return mrb_nil_value();
}
#endif

#if BIND_PR_EnumerateAddrInfo_FUNCTION
#define PR_EnumerateAddrInfo_REQUIRED_ARGC 4
#define PR_EnumerateAddrInfo_OPTIONAL_ARGC 0
/* PR_EnumerateAddrInfo
 *
 * Parameters:
 * - enumPtr: void *
 * - addrInfo: const struct PRAddrInfo *
 * - port: unsigned short
 * - result: union PRNetAddr *
 * Return Type: void *
 */
mrb_value
mrb_NSPR_PR_EnumerateAddrInfo(mrb_state* mrb, mrb_value self) {
  mrb_value enumPtr;
  mrb_value addrInfo;
  mrb_value port;
  mrb_value result;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &enumPtr, &addrInfo, &port, &result);


  /* Type checking */
  TODO_type_check_void_PTR(enumPtr);
  TODO_type_check_const_struct_PRAddrInfo_PTR(addrInfo);
  TODO_type_check_unsigned_short(port);
  TODO_type_check_union_PRNetAddr_PTR(result);


  /* Unbox parameters */
  void * native_enumPtr = TODO_mruby_unbox_void_PTR(enumPtr);

  const struct PRAddrInfo * native_addrInfo = TODO_mruby_unbox_const_struct_PRAddrInfo_PTR(addrInfo);

  unsigned short native_port = TODO_mruby_unbox_unsigned_short(port);

  union PRNetAddr * native_result = TODO_mruby_unbox_union_PRNetAddr_PTR(result);

  /* Invocation */
  void * result = PR_EnumerateAddrInfo(native_enumPtr, native_addrInfo, native_port, native_result);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_EnumerateHostEnt_FUNCTION
#define PR_EnumerateHostEnt_REQUIRED_ARGC 4
#define PR_EnumerateHostEnt_OPTIONAL_ARGC 0
/* PR_EnumerateHostEnt
 *
 * Parameters:
 * - enumIndex: int
 * - hostEnt: const struct PRHostEnt *
 * - port: unsigned short
 * - address: union PRNetAddr *
 * Return Type: PRIntn
 */
mrb_value
mrb_NSPR_PR_EnumerateHostEnt(mrb_state* mrb, mrb_value self) {
  mrb_value enumIndex;
  mrb_value hostEnt;
  mrb_value port;
  mrb_value address;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &enumIndex, &hostEnt, &port, &address);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, enumIndex, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_struct_PRHostEnt_PTR(hostEnt);
  TODO_type_check_unsigned_short(port);
  TODO_type_check_union_PRNetAddr_PTR(address);


  /* Unbox parameters */
  int native_enumIndex = mrb_fixnum(enumIndex);

  const struct PRHostEnt * native_hostEnt = TODO_mruby_unbox_const_struct_PRHostEnt_PTR(hostEnt);

  unsigned short native_port = TODO_mruby_unbox_unsigned_short(port);

  union PRNetAddr * native_address = TODO_mruby_unbox_union_PRNetAddr_PTR(address);

  /* Invocation */
  PRIntn result = PR_EnumerateHostEnt(native_enumIndex, native_hostEnt, native_port, native_address);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_EnumerateWaitGroup_FUNCTION
#define PR_EnumerateWaitGroup_REQUIRED_ARGC 2
#define PR_EnumerateWaitGroup_OPTIONAL_ARGC 0
/* PR_EnumerateWaitGroup
 *
 * Parameters:
 * - enumerator: struct PRMWaitEnumerator *
 * - previous: const struct PRRecvWait *
 * Return Type: PRRecvWait *
 */
mrb_value
mrb_NSPR_PR_EnumerateWaitGroup(mrb_state* mrb, mrb_value self) {
  mrb_value enumerator;
  mrb_value previous;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &enumerator, &previous);


  /* Type checking */
  TODO_type_check_struct_PRMWaitEnumerator_PTR(enumerator);
  TODO_type_check_const_struct_PRRecvWait_PTR(previous);


  /* Unbox parameters */
  struct PRMWaitEnumerator * native_enumerator = TODO_mruby_unbox_struct_PRMWaitEnumerator_PTR(enumerator);

  const struct PRRecvWait * native_previous = TODO_mruby_unbox_const_struct_PRRecvWait_PTR(previous);

  /* Invocation */
  PRRecvWait * result = PR_EnumerateWaitGroup(native_enumerator, native_previous);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRRecvWait_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_ErrorInstallCallback_FUNCTION
#define PR_ErrorInstallCallback_REQUIRED_ARGC 5
#define PR_ErrorInstallCallback_OPTIONAL_ARGC 0
/* PR_ErrorInstallCallback
 *
 * Parameters:
 * - languages: const char *const *
 * - lookup: const char *(*)(int, unsigned int, const struct PRErrorTable *, struct PRErrorCallbackPrivate *, struct PRErrorCallbackTablePrivate *)
 * - newtable: struct PRErrorCallbackTablePrivate *(*)(const struct PRErrorTable *, struct PRErrorCallbackPrivate *)
 * - cb_private: struct PRErrorCallbackPrivate *
 * - arg5: const char *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_ErrorInstallCallback(mrb_state* mrb, mrb_value self) {
  mrb_value languages;
  mrb_value lookup;
  mrb_value newtable;
  mrb_value cb_private;
  mrb_value arg5;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &languages, &lookup, &newtable, &cb_private, &arg5);


  /* Type checking */
  TODO_type_check_const_char_PTR_const_PTR(languages);
  TODO_type_check_const_char_PTR_LPAREN_PTR_RPAREN_LPAREN_intCOMMA_unsigned_intCOMMA_const_struct_PRErrorTable_PTR_COMMA_struct_PRErrorCallbackPrivate_PTR_COMMA_struct_PRErrorCallbackTablePrivate_PTR_RPAREN(lookup);
  TODO_type_check_struct_PRErrorCallbackTablePrivate_PTR_LPAREN_PTR_RPAREN_LPAREN_const_struct_PRErrorTable_PTR_COMMA_struct_PRErrorCallbackPrivate_PTR_RPAREN(newtable);
  TODO_type_check_struct_PRErrorCallbackPrivate_PTR(cb_private);
  if (!mrb_obj_is_kind_of(mrb, arg5, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char *const * native_languages = TODO_mruby_unbox_const_char_PTR_const_PTR(languages);

  const char *(*native_lookup)(int, unsigned int, const struct PRErrorTable *, struct PRErrorCallbackPrivate *, struct PRErrorCallbackTablePrivate *) = TODO_mruby_unbox_const_char_PTR_LPAREN_PTR_RPAREN_LPAREN_intCOMMA_unsigned_intCOMMA_const_struct_PRErrorTable_PTR_COMMA_struct_PRErrorCallbackPrivate_PTR_COMMA_struct_PRErrorCallbackTablePrivate_PTR_RPAREN(lookup);

  struct PRErrorCallbackTablePrivate *(*native_newtable)(const struct PRErrorTable *, struct PRErrorCallbackPrivate *) = TODO_mruby_unbox_struct_PRErrorCallbackTablePrivate_PTR_LPAREN_PTR_RPAREN_LPAREN_const_struct_PRErrorTable_PTR_COMMA_struct_PRErrorCallbackPrivate_PTR_RPAREN(newtable);

  struct PRErrorCallbackPrivate * native_cb_private = TODO_mruby_unbox_struct_PRErrorCallbackPrivate_PTR(cb_private);

  const char * native_arg5 = mrb_string_value_cstr(mrb, &arg5);

  /* Invocation */
  PR_ErrorInstallCallback(native_languages, native_lookup, native_newtable, native_cb_private, native_arg5);

  return mrb_nil_value();
}
#endif

#if BIND_PR_ErrorInstallTable_FUNCTION
#define PR_ErrorInstallTable_REQUIRED_ARGC 1
#define PR_ErrorInstallTable_OPTIONAL_ARGC 0
/* PR_ErrorInstallTable
 *
 * Parameters:
 * - table: const struct PRErrorTable *
 * Return Type: PRErrorCode
 */
mrb_value
mrb_NSPR_PR_ErrorInstallTable(mrb_state* mrb, mrb_value self) {
  mrb_value table;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &table);


  /* Type checking */
  TODO_type_check_const_struct_PRErrorTable_PTR(table);


  /* Unbox parameters */
  const struct PRErrorTable * native_table = TODO_mruby_unbox_const_struct_PRErrorTable_PTR(table);

  /* Invocation */
  PRErrorCode result = PR_ErrorInstallTable(native_table);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRErrorCode(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_ErrorLanguages_FUNCTION
#define PR_ErrorLanguages_REQUIRED_ARGC 0
#define PR_ErrorLanguages_OPTIONAL_ARGC 0
/* PR_ErrorLanguages
 *
 * Parameters: None
 * Return Type: const char *const *
 */
mrb_value
mrb_NSPR_PR_ErrorLanguages(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  const char *const * result = PR_ErrorLanguages();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_const_char_PTR_const_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_ErrorToName_FUNCTION
#define PR_ErrorToName_REQUIRED_ARGC 1
#define PR_ErrorToName_OPTIONAL_ARGC 0
/* PR_ErrorToName
 *
 * Parameters:
 * - code: int
 * Return Type: const char *
 */
mrb_value
mrb_NSPR_PR_ErrorToName(mrb_state* mrb, mrb_value self) {
  mrb_value code;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &code);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, code, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_code = mrb_fixnum(code);

  /* Invocation */
  const char * result = PR_ErrorToName(native_code);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_ErrorToString_FUNCTION
#define PR_ErrorToString_REQUIRED_ARGC 2
#define PR_ErrorToString_OPTIONAL_ARGC 0
/* PR_ErrorToString
 *
 * Parameters:
 * - code: int
 * - language: unsigned int
 * Return Type: const char *
 */
mrb_value
mrb_NSPR_PR_ErrorToString(mrb_state* mrb, mrb_value self) {
  mrb_value code;
  mrb_value language;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &code, &language);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, code, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, language, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_code = mrb_fixnum(code);

  unsigned int native_language = mrb_fixnum(language);

  /* Invocation */
  const char * result = PR_ErrorToString(native_code, native_language);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_ExitMonitor_FUNCTION
#define PR_ExitMonitor_REQUIRED_ARGC 1
#define PR_ExitMonitor_OPTIONAL_ARGC 0
/* PR_ExitMonitor
 *
 * Parameters:
 * - mon: struct PRMonitor *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_ExitMonitor(mrb_state* mrb, mrb_value self) {
  mrb_value mon;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &mon);


  /* Type checking */
  TODO_type_check_struct_PRMonitor_PTR(mon);


  /* Unbox parameters */
  struct PRMonitor * native_mon = TODO_mruby_unbox_struct_PRMonitor_PTR(mon);

  /* Invocation */
  PRStatus result = PR_ExitMonitor(native_mon);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_ExplodeTime_FUNCTION
#define PR_ExplodeTime_REQUIRED_ARGC 3
#define PR_ExplodeTime_OPTIONAL_ARGC 0
/* PR_ExplodeTime
 *
 * Parameters:
 * - usecs: long long
 * - params: struct PRTimeParameters (*)(const struct PRExplodedTime *)
 * - exploded: struct PRExplodedTime *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_ExplodeTime(mrb_state* mrb, mrb_value self) {
  mrb_value usecs;
  mrb_value params;
  mrb_value exploded;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &usecs, &params, &exploded);


  /* Type checking */
  TODO_type_check_long_long(usecs);
  TODO_type_check_struct_PRTimeParameters_LPAREN_PTR_RPAREN_LPAREN_const_struct_PRExplodedTime_PTR_RPAREN(params);
  TODO_type_check_struct_PRExplodedTime_PTR(exploded);


  /* Unbox parameters */
  long long native_usecs = TODO_mruby_unbox_long_long(usecs);

  struct PRTimeParameters (*native_params)(const struct PRExplodedTime *) = TODO_mruby_unbox_struct_PRTimeParameters_LPAREN_PTR_RPAREN_LPAREN_const_struct_PRExplodedTime_PTR_RPAREN(params);

  struct PRExplodedTime * native_exploded = TODO_mruby_unbox_struct_PRExplodedTime_PTR(exploded);

  /* Invocation */
  PR_ExplodeTime(native_usecs, native_params, native_exploded);

  return mrb_nil_value();
}
#endif

#if BIND_PR_ExportFileMapAsString_FUNCTION
#define PR_ExportFileMapAsString_REQUIRED_ARGC 3
#define PR_ExportFileMapAsString_OPTIONAL_ARGC 0
/* PR_ExportFileMapAsString
 *
 * Parameters:
 * - fm: struct PRFileMap *
 * - bufsize: unsigned long
 * - buf: char *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_ExportFileMapAsString(mrb_state* mrb, mrb_value self) {
  mrb_value fm;
  mrb_value bufsize;
  mrb_value buf;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &fm, &bufsize, &buf);


  /* Type checking */
  TODO_type_check_struct_PRFileMap_PTR(fm);
  TODO_type_check_unsigned_long(bufsize);
  if (!mrb_obj_is_kind_of(mrb, buf, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRFileMap * native_fm = TODO_mruby_unbox_struct_PRFileMap_PTR(fm);

  unsigned long native_bufsize = TODO_mruby_unbox_unsigned_long(bufsize);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_buf = strdup(mrb_string_value_cstr(mrb, &buf));

  /* Invocation */
  PRStatus result = PR_ExportFileMapAsString(native_fm, native_bufsize, native_buf);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

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

#if BIND_PR_FindFunctionSymbol_FUNCTION
#define PR_FindFunctionSymbol_REQUIRED_ARGC 2
#define PR_FindFunctionSymbol_OPTIONAL_ARGC 0
/* PR_FindFunctionSymbol
 *
 * Parameters:
 * - lib: struct PRLibrary *
 * - name: const char *
 * Return Type: PRFuncPtr
 */
mrb_value
mrb_NSPR_PR_FindFunctionSymbol(mrb_state* mrb, mrb_value self) {
  mrb_value lib;
  mrb_value name;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &lib, &name);


  /* Type checking */
  TODO_type_check_struct_PRLibrary_PTR(lib);
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRLibrary * native_lib = TODO_mruby_unbox_struct_PRLibrary_PTR(lib);

  const char * native_name = mrb_string_value_cstr(mrb, &name);

  /* Invocation */
  PRFuncPtr result = PR_FindFunctionSymbol(native_lib, native_name);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_LPAREN_PTR_RPAREN_LPAREN_void_RPAREN(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_FindFunctionSymbolAndLibrary_FUNCTION
#define PR_FindFunctionSymbolAndLibrary_REQUIRED_ARGC 2
#define PR_FindFunctionSymbolAndLibrary_OPTIONAL_ARGC 0
/* PR_FindFunctionSymbolAndLibrary
 *
 * Parameters:
 * - name: const char *
 * - lib: struct PRLibrary **
 * Return Type: PRFuncPtr
 */
mrb_value
mrb_NSPR_PR_FindFunctionSymbolAndLibrary(mrb_state* mrb, mrb_value self) {
  mrb_value name;
  mrb_value lib;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &name, &lib);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct_PRLibrary_PTR_PTR(lib);


  /* Unbox parameters */
  const char * native_name = mrb_string_value_cstr(mrb, &name);

  struct PRLibrary ** native_lib = TODO_mruby_unbox_struct_PRLibrary_PTR_PTR(lib);

  /* Invocation */
  PRFuncPtr result = PR_FindFunctionSymbolAndLibrary(native_name, native_lib);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_LPAREN_PTR_RPAREN_LPAREN_void_RPAREN(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_FindNextCounterQname_FUNCTION
#define PR_FindNextCounterQname_REQUIRED_ARGC 1
#define PR_FindNextCounterQname_OPTIONAL_ARGC 0
/* PR_FindNextCounterQname
 *
 * Parameters:
 * - handle: void *
 * Return Type: PRCounterHandle
 */
mrb_value
mrb_NSPR_PR_FindNextCounterQname(mrb_state* mrb, mrb_value self) {
  mrb_value handle;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &handle);


  /* Type checking */
  TODO_type_check_void_PTR(handle);


  /* Unbox parameters */
  void * native_handle = TODO_mruby_unbox_void_PTR(handle);

  /* Invocation */
  PRCounterHandle result = PR_FindNextCounterQname(native_handle);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_FindNextCounterRname_FUNCTION
#define PR_FindNextCounterRname_REQUIRED_ARGC 2
#define PR_FindNextCounterRname_OPTIONAL_ARGC 0
/* PR_FindNextCounterRname
 *
 * Parameters:
 * - rhandle: void *
 * - qhandle: void *
 * Return Type: PRCounterHandle
 */
mrb_value
mrb_NSPR_PR_FindNextCounterRname(mrb_state* mrb, mrb_value self) {
  mrb_value rhandle;
  mrb_value qhandle;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &rhandle, &qhandle);


  /* Type checking */
  TODO_type_check_void_PTR(rhandle);
  TODO_type_check_void_PTR(qhandle);


  /* Unbox parameters */
  void * native_rhandle = TODO_mruby_unbox_void_PTR(rhandle);

  void * native_qhandle = TODO_mruby_unbox_void_PTR(qhandle);

  /* Invocation */
  PRCounterHandle result = PR_FindNextCounterRname(native_rhandle, native_qhandle);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_FindNextTraceQname_FUNCTION
#define PR_FindNextTraceQname_REQUIRED_ARGC 1
#define PR_FindNextTraceQname_OPTIONAL_ARGC 0
/* PR_FindNextTraceQname
 *
 * Parameters:
 * - handle: void *
 * Return Type: PRTraceHandle
 */
mrb_value
mrb_NSPR_PR_FindNextTraceQname(mrb_state* mrb, mrb_value self) {
  mrb_value handle;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &handle);


  /* Type checking */
  TODO_type_check_void_PTR(handle);


  /* Unbox parameters */
  void * native_handle = TODO_mruby_unbox_void_PTR(handle);

  /* Invocation */
  PRTraceHandle result = PR_FindNextTraceQname(native_handle);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_FindNextTraceRname_FUNCTION
#define PR_FindNextTraceRname_REQUIRED_ARGC 2
#define PR_FindNextTraceRname_OPTIONAL_ARGC 0
/* PR_FindNextTraceRname
 *
 * Parameters:
 * - rhandle: void *
 * - qhandle: void *
 * Return Type: PRTraceHandle
 */
mrb_value
mrb_NSPR_PR_FindNextTraceRname(mrb_state* mrb, mrb_value self) {
  mrb_value rhandle;
  mrb_value qhandle;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &rhandle, &qhandle);


  /* Type checking */
  TODO_type_check_void_PTR(rhandle);
  TODO_type_check_void_PTR(qhandle);


  /* Unbox parameters */
  void * native_rhandle = TODO_mruby_unbox_void_PTR(rhandle);

  void * native_qhandle = TODO_mruby_unbox_void_PTR(qhandle);

  /* Invocation */
  PRTraceHandle result = PR_FindNextTraceRname(native_rhandle, native_qhandle);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_FindSymbol_FUNCTION
#define PR_FindSymbol_REQUIRED_ARGC 2
#define PR_FindSymbol_OPTIONAL_ARGC 0
/* PR_FindSymbol
 *
 * Parameters:
 * - lib: struct PRLibrary *
 * - name: const char *
 * Return Type: void *
 */
mrb_value
mrb_NSPR_PR_FindSymbol(mrb_state* mrb, mrb_value self) {
  mrb_value lib;
  mrb_value name;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &lib, &name);


  /* Type checking */
  TODO_type_check_struct_PRLibrary_PTR(lib);
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRLibrary * native_lib = TODO_mruby_unbox_struct_PRLibrary_PTR(lib);

  const char * native_name = mrb_string_value_cstr(mrb, &name);

  /* Invocation */
  void * result = PR_FindSymbol(native_lib, native_name);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_FindSymbolAndLibrary_FUNCTION
#define PR_FindSymbolAndLibrary_REQUIRED_ARGC 2
#define PR_FindSymbolAndLibrary_OPTIONAL_ARGC 0
/* PR_FindSymbolAndLibrary
 *
 * Parameters:
 * - name: const char *
 * - lib: struct PRLibrary **
 * Return Type: void *
 */
mrb_value
mrb_NSPR_PR_FindSymbolAndLibrary(mrb_state* mrb, mrb_value self) {
  mrb_value name;
  mrb_value lib;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &name, &lib);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct_PRLibrary_PTR_PTR(lib);


  /* Unbox parameters */
  const char * native_name = mrb_string_value_cstr(mrb, &name);

  struct PRLibrary ** native_lib = TODO_mruby_unbox_struct_PRLibrary_PTR_PTR(lib);

  /* Invocation */
  void * result = PR_FindSymbolAndLibrary(native_name, native_lib);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_FloorLog2_FUNCTION
#define PR_FloorLog2_REQUIRED_ARGC 1
#define PR_FloorLog2_OPTIONAL_ARGC 0
/* PR_FloorLog2
 *
 * Parameters:
 * - i: unsigned int
 * Return Type: PRIntn
 */
mrb_value
mrb_NSPR_PR_FloorLog2(mrb_state* mrb, mrb_value self) {
  mrb_value i;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &i);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, i, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  unsigned int native_i = mrb_fixnum(i);

  /* Invocation */
  PRIntn result = PR_FloorLog2(native_i);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_FormatTime_FUNCTION
#define PR_FormatTime_REQUIRED_ARGC 4
#define PR_FormatTime_OPTIONAL_ARGC 0
/* PR_FormatTime
 *
 * Parameters:
 * - buf: char *
 * - buflen: int
 * - fmt: const char *
 * - tm: const struct PRExplodedTime *
 * Return Type: PRUint32
 */
mrb_value
mrb_NSPR_PR_FormatTime(mrb_state* mrb, mrb_value self) {
  mrb_value buf;
  mrb_value buflen;
  mrb_value fmt;
  mrb_value tm;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &buf, &buflen, &fmt, &tm);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, buf, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, buflen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, fmt, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_struct_PRExplodedTime_PTR(tm);


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_buf = strdup(mrb_string_value_cstr(mrb, &buf));

  int native_buflen = mrb_fixnum(buflen);

  const char * native_fmt = mrb_string_value_cstr(mrb, &fmt);

  const struct PRExplodedTime * native_tm = TODO_mruby_unbox_const_struct_PRExplodedTime_PTR(tm);

  /* Invocation */
  PRUint32 result = PR_FormatTime(native_buf, native_buflen, native_fmt, native_tm);

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

#if BIND_PR_FormatTimeUSEnglish_FUNCTION
#define PR_FormatTimeUSEnglish_REQUIRED_ARGC 5
#define PR_FormatTimeUSEnglish_OPTIONAL_ARGC 0
/* PR_FormatTimeUSEnglish
 *
 * Parameters:
 * - buf: char *
 * - bufSize: unsigned int
 * - format: const char *
 * - tm: const struct PRExplodedTime *
 * - arg: void *
 * Return Type: PRUint32
 */
mrb_value
mrb_NSPR_PR_FormatTimeUSEnglish(mrb_state* mrb, mrb_value self) {
  mrb_value buf;
  mrb_value bufSize;
  mrb_value format;
  mrb_value tm;
  mrb_value arg;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &buf, &bufSize, &format, &tm, &arg);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, buf, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, bufSize, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, format, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_struct_PRExplodedTime_PTR(tm);
  TODO_type_check_void_PTR(arg);


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_buf = strdup(mrb_string_value_cstr(mrb, &buf));

  unsigned int native_bufSize = mrb_fixnum(bufSize);

  const char * native_format = mrb_string_value_cstr(mrb, &format);

  const struct PRExplodedTime * native_tm = TODO_mruby_unbox_const_struct_PRExplodedTime_PTR(tm);

  void * native_arg = TODO_mruby_unbox_void_PTR(arg);

  /* Invocation */
  PRUint32 result = PR_FormatTimeUSEnglish(native_buf, native_bufSize, native_format, native_tm, native_arg);

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

#if BIND_PR_fprintf_FUNCTION
#define PR_fprintf_REQUIRED_ARGC 2
#define PR_fprintf_OPTIONAL_ARGC 0
/* PR_fprintf
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - fmt: const char *
 * Return Type: PRUint32
 */
mrb_value
mrb_NSPR_PR_fprintf(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value fmt;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &fd, &fmt);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  if (!mrb_obj_is_kind_of(mrb, fmt, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  const char * native_fmt = mrb_string_value_cstr(mrb, &fmt);

  /* Invocation */
  PRUint32 result = PR_fprintf(native_fd, native_fmt);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_Free_FUNCTION
#define PR_Free_REQUIRED_ARGC 1
#define PR_Free_OPTIONAL_ARGC 0
/* PR_Free
 *
 * Parameters:
 * - ptr: void *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_Free(mrb_state* mrb, mrb_value self) {
  mrb_value ptr;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &ptr);


  /* Type checking */
  TODO_type_check_void_PTR(ptr);


  /* Unbox parameters */
  void * native_ptr = TODO_mruby_unbox_void_PTR(ptr);

  /* Invocation */
  PR_Free(native_ptr);

  return mrb_nil_value();
}
#endif

#if BIND_PR_FreeAddrInfo_FUNCTION
#define PR_FreeAddrInfo_REQUIRED_ARGC 1
#define PR_FreeAddrInfo_OPTIONAL_ARGC 0
/* PR_FreeAddrInfo
 *
 * Parameters:
 * - addrInfo: struct PRAddrInfo *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_FreeAddrInfo(mrb_state* mrb, mrb_value self) {
  mrb_value addrInfo;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &addrInfo);


  /* Type checking */
  TODO_type_check_struct_PRAddrInfo_PTR(addrInfo);


  /* Unbox parameters */
  struct PRAddrInfo * native_addrInfo = TODO_mruby_unbox_struct_PRAddrInfo_PTR(addrInfo);

  /* Invocation */
  PR_FreeAddrInfo(native_addrInfo);

  return mrb_nil_value();
}
#endif

#if BIND_PR_FreeLibraryName_FUNCTION
#define PR_FreeLibraryName_REQUIRED_ARGC 1
#define PR_FreeLibraryName_OPTIONAL_ARGC 0
/* PR_FreeLibraryName
 *
 * Parameters:
 * - mem: char *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_FreeLibraryName(mrb_state* mrb, mrb_value self) {
  mrb_value mem;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &mem);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, mem, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_mem = strdup(mrb_string_value_cstr(mrb, &mem));

  /* Invocation */
  PR_FreeLibraryName(native_mem);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_mem);
  native_mem = NULL;

  return mrb_nil_value();
}
#endif

#if BIND_PR_GetAddrInfoByName_FUNCTION
#define PR_GetAddrInfoByName_REQUIRED_ARGC 3
#define PR_GetAddrInfoByName_OPTIONAL_ARGC 0
/* PR_GetAddrInfoByName
 *
 * Parameters:
 * - hostname: const char *
 * - af: unsigned short
 * - flags: int
 * Return Type: PRAddrInfo *
 */
mrb_value
mrb_NSPR_PR_GetAddrInfoByName(mrb_state* mrb, mrb_value self) {
  mrb_value hostname;
  mrb_value af;
  mrb_value flags;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &hostname, &af, &flags);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, hostname, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_unsigned_short(af);
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_hostname = mrb_string_value_cstr(mrb, &hostname);

  unsigned short native_af = TODO_mruby_unbox_unsigned_short(af);

  int native_flags = mrb_fixnum(flags);

  /* Invocation */
  PRAddrInfo * result = PR_GetAddrInfoByName(native_hostname, native_af, native_flags);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRAddrInfo_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetCanonNameFromAddrInfo_FUNCTION
#define PR_GetCanonNameFromAddrInfo_REQUIRED_ARGC 1
#define PR_GetCanonNameFromAddrInfo_OPTIONAL_ARGC 0
/* PR_GetCanonNameFromAddrInfo
 *
 * Parameters:
 * - addrInfo: const struct PRAddrInfo *
 * Return Type: const char *
 */
mrb_value
mrb_NSPR_PR_GetCanonNameFromAddrInfo(mrb_state* mrb, mrb_value self) {
  mrb_value addrInfo;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &addrInfo);


  /* Type checking */
  TODO_type_check_const_struct_PRAddrInfo_PTR(addrInfo);


  /* Unbox parameters */
  const struct PRAddrInfo * native_addrInfo = TODO_mruby_unbox_const_struct_PRAddrInfo_PTR(addrInfo);

  /* Invocation */
  const char * result = PR_GetCanonNameFromAddrInfo(native_addrInfo);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetConnectStatus_FUNCTION
#define PR_GetConnectStatus_REQUIRED_ARGC 1
#define PR_GetConnectStatus_OPTIONAL_ARGC 0
/* PR_GetConnectStatus
 *
 * Parameters:
 * - pd: const struct PRPollDesc *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_GetConnectStatus(mrb_state* mrb, mrb_value self) {
  mrb_value pd;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &pd);


  /* Type checking */
  TODO_type_check_const_struct_PRPollDesc_PTR(pd);


  /* Unbox parameters */
  const struct PRPollDesc * native_pd = TODO_mruby_unbox_const_struct_PRPollDesc_PTR(pd);

  /* Invocation */
  PRStatus result = PR_GetConnectStatus(native_pd);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetCounter_FUNCTION
#define PR_GetCounter_REQUIRED_ARGC 1
#define PR_GetCounter_OPTIONAL_ARGC 0
/* PR_GetCounter
 *
 * Parameters:
 * - handle: void *
 * Return Type: PRUint32
 */
mrb_value
mrb_NSPR_PR_GetCounter(mrb_state* mrb, mrb_value self) {
  mrb_value handle;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &handle);


  /* Type checking */
  TODO_type_check_void_PTR(handle);


  /* Unbox parameters */
  void * native_handle = TODO_mruby_unbox_void_PTR(handle);

  /* Invocation */
  PRUint32 result = PR_GetCounter(native_handle);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_GetCounterHandleFromName_FUNCTION
#define PR_GetCounterHandleFromName_REQUIRED_ARGC 2
#define PR_GetCounterHandleFromName_OPTIONAL_ARGC 0
/* PR_GetCounterHandleFromName
 *
 * Parameters:
 * - qName: const char *
 * - rName: const char *
 * Return Type: PRCounterHandle
 */
mrb_value
mrb_NSPR_PR_GetCounterHandleFromName(mrb_state* mrb, mrb_value self) {
  mrb_value qName;
  mrb_value rName;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &qName, &rName);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, qName, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, rName, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_qName = mrb_string_value_cstr(mrb, &qName);

  const char * native_rName = mrb_string_value_cstr(mrb, &rName);

  /* Invocation */
  PRCounterHandle result = PR_GetCounterHandleFromName(native_qName, native_rName);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetCounterNameFromHandle_FUNCTION
#define PR_GetCounterNameFromHandle_REQUIRED_ARGC 4
#define PR_GetCounterNameFromHandle_OPTIONAL_ARGC 0
/* PR_GetCounterNameFromHandle
 *
 * Parameters:
 * - handle: void *
 * - qName: const char **
 * - rName: const char **
 * - description: const char **
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_GetCounterNameFromHandle(mrb_state* mrb, mrb_value self) {
  mrb_value handle;
  mrb_value qName;
  mrb_value rName;
  mrb_value description;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &handle, &qName, &rName, &description);


  /* Type checking */
  TODO_type_check_void_PTR(handle);
  TODO_type_check_const_char_PTR_PTR(qName);
  TODO_type_check_const_char_PTR_PTR(rName);
  TODO_type_check_const_char_PTR_PTR(description);


  /* Unbox parameters */
  void * native_handle = TODO_mruby_unbox_void_PTR(handle);

  const char ** native_qName = TODO_mruby_unbox_const_char_PTR_PTR(qName);

  const char ** native_rName = TODO_mruby_unbox_const_char_PTR_PTR(rName);

  const char ** native_description = TODO_mruby_unbox_const_char_PTR_PTR(description);

  /* Invocation */
  PR_GetCounterNameFromHandle(native_handle, native_qName, native_rName, native_description);

  return mrb_nil_value();
}
#endif

#if BIND_PR_GetCurrentThread_FUNCTION
#define PR_GetCurrentThread_REQUIRED_ARGC 0
#define PR_GetCurrentThread_OPTIONAL_ARGC 0
/* PR_GetCurrentThread
 *
 * Parameters: None
 * Return Type: PRThread *
 */
mrb_value
mrb_NSPR_PR_GetCurrentThread(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRThread * result = PR_GetCurrentThread();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRThread_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetDefaultIOMethods_FUNCTION
#define PR_GetDefaultIOMethods_REQUIRED_ARGC 0
#define PR_GetDefaultIOMethods_OPTIONAL_ARGC 0
/* PR_GetDefaultIOMethods
 *
 * Parameters: None
 * Return Type: const PRIOMethods *
 */
mrb_value
mrb_NSPR_PR_GetDefaultIOMethods(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  const PRIOMethods * result = PR_GetDefaultIOMethods();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_const_PRIOMethods_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetDescType_FUNCTION
#define PR_GetDescType_REQUIRED_ARGC 89
#define PR_GetDescType_OPTIONAL_ARGC 0
/* PR_GetDescType
 *
 * Parameters:
 * - file: struct PRFileDesc *
 * - fd: struct PRFileDesc *
 * - fd: struct PRFileDesc *
 * - buf: void *
 * - amount: int
 * - fd: struct PRFileDesc *
 * - buf: const void *
 * - amount: int
 * - fd: struct PRFileDesc *
 * - fd: struct PRFileDesc *
 * - fd: struct PRFileDesc *
 * - fd: struct PRFileDesc *
 * - offset: int
 * - how: enum PRSeekWhence
 * - fd: struct PRFileDesc *
 * - offset: long long
 * - how: enum PRSeekWhence
 * - fd: struct PRFileDesc *
 * - info: struct PRFileInfo *
 * - fd: struct PRFileDesc *
 * - info: struct PRFileInfo64 *
 * - fd: struct PRFileDesc *
 * - iov: const struct PRIOVec *
 * - iov_size: int
 * - timeout: unsigned int
 * - fd: struct PRFileDesc *
 * - addr: const union PRNetAddr *
 * - timeout: unsigned int
 * - fd: struct PRFileDesc *
 * - addr: union PRNetAddr *
 * - timeout: unsigned int
 * - fd: struct PRFileDesc *
 * - addr: const union PRNetAddr *
 * - fd: struct PRFileDesc *
 * - backlog: int
 * - fd: struct PRFileDesc *
 * - how: int
 * - fd: struct PRFileDesc *
 * - buf: void *
 * - amount: int
 * - flags: int
 * - timeout: unsigned int
 * - fd: struct PRFileDesc *
 * - buf: const void *
 * - amount: int
 * - flags: int
 * - timeout: unsigned int
 * - fd: struct PRFileDesc *
 * - buf: void *
 * - amount: int
 * - flags: int
 * - addr: union PRNetAddr *
 * - timeout: unsigned int
 * - fd: struct PRFileDesc *
 * - buf: const void *
 * - amount: int
 * - flags: int
 * - addr: const union PRNetAddr *
 * - timeout: unsigned int
 * - fd: struct PRFileDesc *
 * - in_flags: short
 * - out_flags: short *
 * - sd: struct PRFileDesc *
 * - nd: struct PRFileDesc **
 * - raddr: union PRNetAddr **
 * - buf: void *
 * - amount: int
 * - t: unsigned int
 * - sd: struct PRFileDesc *
 * - fd: struct PRFileDesc *
 * - headers: const void *
 * - hlen: int
 * - flags: enum PRTransmitFileFlags
 * - t: unsigned int
 * - fd: struct PRFileDesc *
 * - addr: union PRNetAddr *
 * - fd: struct PRFileDesc *
 * - addr: union PRNetAddr *
 * - fd: struct PRFileDesc *
 * - data: struct PRSocketOptionData *
 * - fd: struct PRFileDesc *
 * - data: const struct PRSocketOptionData *
 * - networkSocket: struct PRFileDesc *
 * - sendData: struct PRSendFileData *
 * - flags: enum PRTransmitFileFlags
 * - timeout: unsigned int
 * - fd: struct PRFileDesc *
 * - out_flags: short
 * - fd: struct PRFileDesc *
 * Return Type: PRDescType
 */
mrb_value
mrb_NSPR_PR_GetDescType(mrb_state* mrb, mrb_value self) {
  mrb_value file;
  mrb_value fd;
  mrb_value fd;
  mrb_value buf;
  mrb_value amount;
  mrb_value fd;
  mrb_value buf;
  mrb_value amount;
  mrb_value fd;
  mrb_value fd;
  mrb_value fd;
  mrb_value fd;
  mrb_value offset;
  mrb_value how;
  mrb_value fd;
  mrb_value offset;
  mrb_value how;
  mrb_value fd;
  mrb_value info;
  mrb_value fd;
  mrb_value info;
  mrb_value fd;
  mrb_value iov;
  mrb_value iov_size;
  mrb_value timeout;
  mrb_value fd;
  mrb_value addr;
  mrb_value timeout;
  mrb_value fd;
  mrb_value addr;
  mrb_value timeout;
  mrb_value fd;
  mrb_value addr;
  mrb_value fd;
  mrb_value backlog;
  mrb_value fd;
  mrb_value how;
  mrb_value fd;
  mrb_value buf;
  mrb_value amount;
  mrb_value flags;
  mrb_value timeout;
  mrb_value fd;
  mrb_value buf;
  mrb_value amount;
  mrb_value flags;
  mrb_value timeout;
  mrb_value fd;
  mrb_value buf;
  mrb_value amount;
  mrb_value flags;
  mrb_value addr;
  mrb_value timeout;
  mrb_value fd;
  mrb_value buf;
  mrb_value amount;
  mrb_value flags;
  mrb_value addr;
  mrb_value timeout;
  mrb_value fd;
  mrb_value in_flags;
  mrb_value out_flags;
  mrb_value sd;
  mrb_value nd;
  mrb_value raddr;
  mrb_value buf;
  mrb_value amount;
  mrb_value t;
  mrb_value sd;
  mrb_value fd;
  mrb_value headers;
  mrb_value hlen;
  mrb_value flags;
  mrb_value t;
  mrb_value fd;
  mrb_value addr;
  mrb_value fd;
  mrb_value addr;
  mrb_value fd;
  mrb_value data;
  mrb_value fd;
  mrb_value data;
  mrb_value networkSocket;
  mrb_value sendData;
  mrb_value flags;
  mrb_value timeout;
  mrb_value fd;
  mrb_value out_flags;
  mrb_value fd;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo", &file, &fd, &fd, &buf, &amount, &fd, &buf, &amount, &fd, &fd, &fd, &fd, &offset, &how, &fd, &offset, &how, &fd, &info, &fd, &info, &fd, &iov, &iov_size, &timeout, &fd, &addr, &timeout, &fd, &addr, &timeout, &fd, &addr, &fd, &backlog, &fd, &how, &fd, &buf, &amount, &flags, &timeout, &fd, &buf, &amount, &flags, &timeout, &fd, &buf, &amount, &flags, &addr, &timeout, &fd, &buf, &amount, &flags, &addr, &timeout, &fd, &in_flags, &out_flags, &sd, &nd, &raddr, &buf, &amount, &t, &sd, &fd, &headers, &hlen, &flags, &t, &fd, &addr, &fd, &addr, &fd, &data, &fd, &data, &networkSocket, &sendData, &flags, &timeout, &fd, &out_flags, &fd);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(file);
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_void_PTR(buf);
  if (!mrb_obj_is_kind_of(mrb, amount, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_const_void_PTR(buf);
  if (!mrb_obj_is_kind_of(mrb, amount, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  if (!mrb_obj_is_kind_of(mrb, offset, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_enum_PRSeekWhence(how);
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_long_long(offset);
  TODO_type_check_enum_PRSeekWhence(how);
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_struct_PRFileInfo_PTR(info);
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_struct_PRFileInfo64_PTR(info);
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_const_struct_PRIOVec_PTR(iov);
  if (!mrb_obj_is_kind_of(mrb, iov_size, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_const_union_PRNetAddr_PTR(addr);
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_union_PRNetAddr_PTR(addr);
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_const_union_PRNetAddr_PTR(addr);
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  if (!mrb_obj_is_kind_of(mrb, backlog, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  if (!mrb_obj_is_kind_of(mrb, how, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_void_PTR(buf);
  if (!mrb_obj_is_kind_of(mrb, amount, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_const_void_PTR(buf);
  if (!mrb_obj_is_kind_of(mrb, amount, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_void_PTR(buf);
  if (!mrb_obj_is_kind_of(mrb, amount, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_union_PRNetAddr_PTR(addr);
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_const_void_PTR(buf);
  if (!mrb_obj_is_kind_of(mrb, amount, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_union_PRNetAddr_PTR(addr);
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_short(in_flags);
  TODO_type_check_short_PTR(out_flags);
  TODO_type_check_struct_PRFileDesc_PTR(sd);
  TODO_type_check_struct_PRFileDesc_PTR_PTR(nd);
  TODO_type_check_union_PRNetAddr_PTR_PTR(raddr);
  TODO_type_check_void_PTR(buf);
  if (!mrb_obj_is_kind_of(mrb, amount, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, t, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct_PRFileDesc_PTR(sd);
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_const_void_PTR(headers);
  if (!mrb_obj_is_kind_of(mrb, hlen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_enum_PRTransmitFileFlags(flags);
  if (!mrb_obj_is_kind_of(mrb, t, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_union_PRNetAddr_PTR(addr);
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_union_PRNetAddr_PTR(addr);
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_struct_PRSocketOptionData_PTR(data);
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_const_struct_PRSocketOptionData_PTR(data);
  TODO_type_check_struct_PRFileDesc_PTR(networkSocket);
  TODO_type_check_struct_PRSendFileData_PTR(sendData);
  TODO_type_check_enum_PRTransmitFileFlags(flags);
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_short(out_flags);
  TODO_type_check_struct_PRFileDesc_PTR(fd);


  /* Unbox parameters */
  struct PRFileDesc * native_file = TODO_mruby_unbox_struct_PRFileDesc_PTR(file);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  void * native_buf = TODO_mruby_unbox_void_PTR(buf);

  int native_amount = mrb_fixnum(amount);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  const void * native_buf = TODO_mruby_unbox_const_void_PTR(buf);

  int native_amount = mrb_fixnum(amount);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  int native_offset = mrb_fixnum(offset);

  enum PRSeekWhence native_how = TODO_mruby_unbox_enum_PRSeekWhence(how);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  long long native_offset = TODO_mruby_unbox_long_long(offset);

  enum PRSeekWhence native_how = TODO_mruby_unbox_enum_PRSeekWhence(how);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  struct PRFileInfo * native_info = TODO_mruby_unbox_struct_PRFileInfo_PTR(info);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  struct PRFileInfo64 * native_info = TODO_mruby_unbox_struct_PRFileInfo64_PTR(info);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  const struct PRIOVec * native_iov = TODO_mruby_unbox_const_struct_PRIOVec_PTR(iov);

  int native_iov_size = mrb_fixnum(iov_size);

  unsigned int native_timeout = mrb_fixnum(timeout);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  const union PRNetAddr * native_addr = TODO_mruby_unbox_const_union_PRNetAddr_PTR(addr);

  unsigned int native_timeout = mrb_fixnum(timeout);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  union PRNetAddr * native_addr = TODO_mruby_unbox_union_PRNetAddr_PTR(addr);

  unsigned int native_timeout = mrb_fixnum(timeout);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  const union PRNetAddr * native_addr = TODO_mruby_unbox_const_union_PRNetAddr_PTR(addr);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  int native_backlog = mrb_fixnum(backlog);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  int native_how = mrb_fixnum(how);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  void * native_buf = TODO_mruby_unbox_void_PTR(buf);

  int native_amount = mrb_fixnum(amount);

  int native_flags = mrb_fixnum(flags);

  unsigned int native_timeout = mrb_fixnum(timeout);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  const void * native_buf = TODO_mruby_unbox_const_void_PTR(buf);

  int native_amount = mrb_fixnum(amount);

  int native_flags = mrb_fixnum(flags);

  unsigned int native_timeout = mrb_fixnum(timeout);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  void * native_buf = TODO_mruby_unbox_void_PTR(buf);

  int native_amount = mrb_fixnum(amount);

  int native_flags = mrb_fixnum(flags);

  union PRNetAddr * native_addr = TODO_mruby_unbox_union_PRNetAddr_PTR(addr);

  unsigned int native_timeout = mrb_fixnum(timeout);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  const void * native_buf = TODO_mruby_unbox_const_void_PTR(buf);

  int native_amount = mrb_fixnum(amount);

  int native_flags = mrb_fixnum(flags);

  const union PRNetAddr * native_addr = TODO_mruby_unbox_const_union_PRNetAddr_PTR(addr);

  unsigned int native_timeout = mrb_fixnum(timeout);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  short native_in_flags = TODO_mruby_unbox_short(in_flags);

  short * native_out_flags = TODO_mruby_unbox_short_PTR(out_flags);

  struct PRFileDesc * native_sd = TODO_mruby_unbox_struct_PRFileDesc_PTR(sd);

  struct PRFileDesc ** native_nd = TODO_mruby_unbox_struct_PRFileDesc_PTR_PTR(nd);

  union PRNetAddr ** native_raddr = TODO_mruby_unbox_union_PRNetAddr_PTR_PTR(raddr);

  void * native_buf = TODO_mruby_unbox_void_PTR(buf);

  int native_amount = mrb_fixnum(amount);

  unsigned int native_t = mrb_fixnum(t);

  struct PRFileDesc * native_sd = TODO_mruby_unbox_struct_PRFileDesc_PTR(sd);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  const void * native_headers = TODO_mruby_unbox_const_void_PTR(headers);

  int native_hlen = mrb_fixnum(hlen);

  enum PRTransmitFileFlags native_flags = TODO_mruby_unbox_enum_PRTransmitFileFlags(flags);

  unsigned int native_t = mrb_fixnum(t);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  union PRNetAddr * native_addr = TODO_mruby_unbox_union_PRNetAddr_PTR(addr);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  union PRNetAddr * native_addr = TODO_mruby_unbox_union_PRNetAddr_PTR(addr);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  struct PRSocketOptionData * native_data = TODO_mruby_unbox_struct_PRSocketOptionData_PTR(data);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  const struct PRSocketOptionData * native_data = TODO_mruby_unbox_const_struct_PRSocketOptionData_PTR(data);

  struct PRFileDesc * native_networkSocket = TODO_mruby_unbox_struct_PRFileDesc_PTR(networkSocket);

  struct PRSendFileData * native_sendData = TODO_mruby_unbox_struct_PRSendFileData_PTR(sendData);

  enum PRTransmitFileFlags native_flags = TODO_mruby_unbox_enum_PRTransmitFileFlags(flags);

  unsigned int native_timeout = mrb_fixnum(timeout);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  short native_out_flags = TODO_mruby_unbox_short(out_flags);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  /* Invocation */
  PRDescType result = PR_GetDescType(native_file, native_fd, native_fd, native_buf, native_amount, native_fd, native_buf, native_amount, native_fd, native_fd, native_fd, native_fd, native_offset, native_how, native_fd, native_offset, native_how, native_fd, native_info, native_fd, native_info, native_fd, native_iov, native_iov_size, native_timeout, native_fd, native_addr, native_timeout, native_fd, native_addr, native_timeout, native_fd, native_addr, native_fd, native_backlog, native_fd, native_how, native_fd, native_buf, native_amount, native_flags, native_timeout, native_fd, native_buf, native_amount, native_flags, native_timeout, native_fd, native_buf, native_amount, native_flags, native_addr, native_timeout, native_fd, native_buf, native_amount, native_flags, native_addr, native_timeout, native_fd, native_in_flags, native_out_flags, native_sd, native_nd, native_raddr, native_buf, native_amount, native_t, native_sd, native_fd, native_headers, native_hlen, native_flags, native_t, native_fd, native_addr, native_fd, native_addr, native_fd, native_data, native_fd, native_data, native_networkSocket, native_sendData, native_flags, native_timeout, native_fd, native_out_flags, native_fd);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRDescType(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetDirectorySeparator_FUNCTION
#define PR_GetDirectorySeparator_REQUIRED_ARGC 0
#define PR_GetDirectorySeparator_OPTIONAL_ARGC 0
/* PR_GetDirectorySeparator
 *
 * Parameters: None
 * Return Type: char
 */
mrb_value
mrb_NSPR_PR_GetDirectorySeparator(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  char result = PR_GetDirectorySeparator();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_char(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetDirectorySepartor_FUNCTION
#define PR_GetDirectorySepartor_REQUIRED_ARGC 0
#define PR_GetDirectorySepartor_OPTIONAL_ARGC 0
/* PR_GetDirectorySepartor
 *
 * Parameters: None
 * Return Type: char
 */
mrb_value
mrb_NSPR_PR_GetDirectorySepartor(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  char result = PR_GetDirectorySepartor();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_char(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetEnv_FUNCTION
#define PR_GetEnv_REQUIRED_ARGC 1
#define PR_GetEnv_OPTIONAL_ARGC 0
/* PR_GetEnv
 *
 * Parameters:
 * - var: const char *
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PR_GetEnv(mrb_state* mrb, mrb_value self) {
  mrb_value var;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &var);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, var, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_var = mrb_string_value_cstr(mrb, &var);

  /* Invocation */
  char * result = PR_GetEnv(native_var);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetError_FUNCTION
#define PR_GetError_REQUIRED_ARGC 0
#define PR_GetError_OPTIONAL_ARGC 0
/* PR_GetError
 *
 * Parameters: None
 * Return Type: PRErrorCode
 */
mrb_value
mrb_NSPR_PR_GetError(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRErrorCode result = PR_GetError();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRErrorCode(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetErrorText_FUNCTION
#define PR_GetErrorText_REQUIRED_ARGC 8
#define PR_GetErrorText_OPTIONAL_ARGC 0
/* PR_GetErrorText
 *
 * Parameters:
 * - text: char *
 * - code: int
 * - language: unsigned int
 * - table: const struct PRErrorTable *
 * - cb_private: struct PRErrorCallbackPrivate *
 * - table_private: struct PRErrorCallbackTablePrivate *
 * - table: const struct PRErrorTable *
 * - cb_private: struct PRErrorCallbackPrivate *
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_GetErrorText(mrb_state* mrb, mrb_value self) {
  mrb_value text;
  mrb_value code;
  mrb_value language;
  mrb_value table;
  mrb_value cb_private;
  mrb_value table_private;
  mrb_value table;
  mrb_value cb_private;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooooo", &text, &code, &language, &table, &cb_private, &table_private, &table, &cb_private);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, text, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, code, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, language, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_struct_PRErrorTable_PTR(table);
  TODO_type_check_struct_PRErrorCallbackPrivate_PTR(cb_private);
  TODO_type_check_struct_PRErrorCallbackTablePrivate_PTR(table_private);
  TODO_type_check_const_struct_PRErrorTable_PTR(table);
  TODO_type_check_struct_PRErrorCallbackPrivate_PTR(cb_private);


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_text = strdup(mrb_string_value_cstr(mrb, &text));

  int native_code = mrb_fixnum(code);

  unsigned int native_language = mrb_fixnum(language);

  const struct PRErrorTable * native_table = TODO_mruby_unbox_const_struct_PRErrorTable_PTR(table);

  struct PRErrorCallbackPrivate * native_cb_private = TODO_mruby_unbox_struct_PRErrorCallbackPrivate_PTR(cb_private);

  struct PRErrorCallbackTablePrivate * native_table_private = TODO_mruby_unbox_struct_PRErrorCallbackTablePrivate_PTR(table_private);

  const struct PRErrorTable * native_table = TODO_mruby_unbox_const_struct_PRErrorTable_PTR(table);

  struct PRErrorCallbackPrivate * native_cb_private = TODO_mruby_unbox_struct_PRErrorCallbackPrivate_PTR(cb_private);

  /* Invocation */
  PRInt32 result = PR_GetErrorText(native_text, native_code, native_language, native_table, native_cb_private, native_table_private, native_table, native_cb_private);

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
  free(native_text);
  native_text = NULL;

  return return_value;
}
#endif

#if BIND_PR_GetErrorTextLength_FUNCTION
#define PR_GetErrorTextLength_REQUIRED_ARGC 0
#define PR_GetErrorTextLength_OPTIONAL_ARGC 0
/* PR_GetErrorTextLength
 *
 * Parameters: None
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_GetErrorTextLength(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRInt32 result = PR_GetErrorTextLength();

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_GetFileInfo_FUNCTION
#define PR_GetFileInfo_REQUIRED_ARGC 2
#define PR_GetFileInfo_OPTIONAL_ARGC 0
/* PR_GetFileInfo
 *
 * Parameters:
 * - fn: const char *
 * - info: struct PRFileInfo *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_GetFileInfo(mrb_state* mrb, mrb_value self) {
  mrb_value fn;
  mrb_value info;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &fn, &info);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, fn, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct_PRFileInfo_PTR(info);


  /* Unbox parameters */
  const char * native_fn = mrb_string_value_cstr(mrb, &fn);

  struct PRFileInfo * native_info = TODO_mruby_unbox_struct_PRFileInfo_PTR(info);

  /* Invocation */
  PRStatus result = PR_GetFileInfo(native_fn, native_info);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetFileInfo64_FUNCTION
#define PR_GetFileInfo64_REQUIRED_ARGC 2
#define PR_GetFileInfo64_OPTIONAL_ARGC 0
/* PR_GetFileInfo64
 *
 * Parameters:
 * - fn: const char *
 * - info: struct PRFileInfo64 *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_GetFileInfo64(mrb_state* mrb, mrb_value self) {
  mrb_value fn;
  mrb_value info;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &fn, &info);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, fn, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct_PRFileInfo64_PTR(info);


  /* Unbox parameters */
  const char * native_fn = mrb_string_value_cstr(mrb, &fn);

  struct PRFileInfo64 * native_info = TODO_mruby_unbox_struct_PRFileInfo64_PTR(info);

  /* Invocation */
  PRStatus result = PR_GetFileInfo64(native_fn, native_info);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetHostByAddr_FUNCTION
#define PR_GetHostByAddr_REQUIRED_ARGC 4
#define PR_GetHostByAddr_OPTIONAL_ARGC 0
/* PR_GetHostByAddr
 *
 * Parameters:
 * - hostaddr: const union PRNetAddr *
 * - buf: char *
 * - bufsize: int
 * - hostentry: struct PRHostEnt *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_GetHostByAddr(mrb_state* mrb, mrb_value self) {
  mrb_value hostaddr;
  mrb_value buf;
  mrb_value bufsize;
  mrb_value hostentry;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &hostaddr, &buf, &bufsize, &hostentry);


  /* Type checking */
  TODO_type_check_const_union_PRNetAddr_PTR(hostaddr);
  if (!mrb_obj_is_kind_of(mrb, buf, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, bufsize, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct_PRHostEnt_PTR(hostentry);


  /* Unbox parameters */
  const union PRNetAddr * native_hostaddr = TODO_mruby_unbox_const_union_PRNetAddr_PTR(hostaddr);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_buf = strdup(mrb_string_value_cstr(mrb, &buf));

  int native_bufsize = mrb_fixnum(bufsize);

  struct PRHostEnt * native_hostentry = TODO_mruby_unbox_struct_PRHostEnt_PTR(hostentry);

  /* Invocation */
  PRStatus result = PR_GetHostByAddr(native_hostaddr, native_buf, native_bufsize, native_hostentry);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

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

#if BIND_PR_GetHostByName_FUNCTION
#define PR_GetHostByName_REQUIRED_ARGC 4
#define PR_GetHostByName_OPTIONAL_ARGC 0
/* PR_GetHostByName
 *
 * Parameters:
 * - hostname: const char *
 * - buf: char *
 * - bufsize: int
 * - hostentry: struct PRHostEnt *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_GetHostByName(mrb_state* mrb, mrb_value self) {
  mrb_value hostname;
  mrb_value buf;
  mrb_value bufsize;
  mrb_value hostentry;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &hostname, &buf, &bufsize, &hostentry);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, hostname, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
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
  TODO_type_check_struct_PRHostEnt_PTR(hostentry);


  /* Unbox parameters */
  const char * native_hostname = mrb_string_value_cstr(mrb, &hostname);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_buf = strdup(mrb_string_value_cstr(mrb, &buf));

  int native_bufsize = mrb_fixnum(bufsize);

  struct PRHostEnt * native_hostentry = TODO_mruby_unbox_struct_PRHostEnt_PTR(hostentry);

  /* Invocation */
  PRStatus result = PR_GetHostByName(native_hostname, native_buf, native_bufsize, native_hostentry);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

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

#if BIND_PR_GetIdentitiesLayer_FUNCTION
#define PR_GetIdentitiesLayer_REQUIRED_ARGC 2
#define PR_GetIdentitiesLayer_OPTIONAL_ARGC 0
/* PR_GetIdentitiesLayer
 *
 * Parameters:
 * - fd_stack: struct PRFileDesc *
 * - id: int
 * Return Type: PRFileDesc *
 */
mrb_value
mrb_NSPR_PR_GetIdentitiesLayer(mrb_state* mrb, mrb_value self) {
  mrb_value fd_stack;
  mrb_value id;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &fd_stack, &id);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd_stack);
  if (!mrb_obj_is_kind_of(mrb, id, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRFileDesc * native_fd_stack = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd_stack);

  int native_id = mrb_fixnum(id);

  /* Invocation */
  PRFileDesc * result = PR_GetIdentitiesLayer(native_fd_stack, native_id);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRFileDesc_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetInheritedFD_FUNCTION
#define PR_GetInheritedFD_REQUIRED_ARGC 1
#define PR_GetInheritedFD_OPTIONAL_ARGC 0
/* PR_GetInheritedFD
 *
 * Parameters:
 * - name: const char *
 * Return Type: PRFileDesc *
 */
mrb_value
mrb_NSPR_PR_GetInheritedFD(mrb_state* mrb, mrb_value self) {
  mrb_value name;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &name);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_name = mrb_string_value_cstr(mrb, &name);

  /* Invocation */
  PRFileDesc * result = PR_GetInheritedFD(native_name);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRFileDesc_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetInheritedFileMap_FUNCTION
#define PR_GetInheritedFileMap_REQUIRED_ARGC 1
#define PR_GetInheritedFileMap_OPTIONAL_ARGC 0
/* PR_GetInheritedFileMap
 *
 * Parameters:
 * - shmname: const char *
 * Return Type: PRFileMap *
 */
mrb_value
mrb_NSPR_PR_GetInheritedFileMap(mrb_state* mrb, mrb_value self) {
  mrb_value shmname;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &shmname);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, shmname, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_shmname = mrb_string_value_cstr(mrb, &shmname);

  /* Invocation */
  PRFileMap * result = PR_GetInheritedFileMap(native_shmname);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRFileMap_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetIPNodeByName_FUNCTION
#define PR_GetIPNodeByName_REQUIRED_ARGC 6
#define PR_GetIPNodeByName_OPTIONAL_ARGC 0
/* PR_GetIPNodeByName
 *
 * Parameters:
 * - hostname: const char *
 * - af: unsigned short
 * - flags: int
 * - buf: char *
 * - bufsize: int
 * - hostentry: struct PRHostEnt *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_GetIPNodeByName(mrb_state* mrb, mrb_value self) {
  mrb_value hostname;
  mrb_value af;
  mrb_value flags;
  mrb_value buf;
  mrb_value bufsize;
  mrb_value hostentry;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooo", &hostname, &af, &flags, &buf, &bufsize, &hostentry);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, hostname, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_unsigned_short(af);
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
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
  TODO_type_check_struct_PRHostEnt_PTR(hostentry);


  /* Unbox parameters */
  const char * native_hostname = mrb_string_value_cstr(mrb, &hostname);

  unsigned short native_af = TODO_mruby_unbox_unsigned_short(af);

  int native_flags = mrb_fixnum(flags);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_buf = strdup(mrb_string_value_cstr(mrb, &buf));

  int native_bufsize = mrb_fixnum(bufsize);

  struct PRHostEnt * native_hostentry = TODO_mruby_unbox_struct_PRHostEnt_PTR(hostentry);

  /* Invocation */
  PRStatus result = PR_GetIPNodeByName(native_hostname, native_af, native_flags, native_buf, native_bufsize, native_hostentry);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

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

#if BIND_PR_GetLayersIdentity_FUNCTION
#define PR_GetLayersIdentity_REQUIRED_ARGC 1
#define PR_GetLayersIdentity_OPTIONAL_ARGC 0
/* PR_GetLayersIdentity
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * Return Type: PRDescIdentity
 */
mrb_value
mrb_NSPR_PR_GetLayersIdentity(mrb_state* mrb, mrb_value self) {
  mrb_value fd;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &fd);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  /* Invocation */
  PRDescIdentity result = PR_GetLayersIdentity(native_fd);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRDescIdentity(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetLibraryFilePathname_FUNCTION
#define PR_GetLibraryFilePathname_REQUIRED_ARGC 2
#define PR_GetLibraryFilePathname_OPTIONAL_ARGC 0
/* PR_GetLibraryFilePathname
 *
 * Parameters:
 * - name: const char *
 * - addr: void (*)(void)
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PR_GetLibraryFilePathname(mrb_state* mrb, mrb_value self) {
  mrb_value name;
  mrb_value addr;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &name, &addr);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_void_RPAREN(addr);


  /* Unbox parameters */
  const char * native_name = mrb_string_value_cstr(mrb, &name);

  void (*native_addr)(void) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_void_RPAREN(addr);

  /* Invocation */
  char * result = PR_GetLibraryFilePathname(native_name, native_addr);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetLibraryName_FUNCTION
#define PR_GetLibraryName_REQUIRED_ARGC 2
#define PR_GetLibraryName_OPTIONAL_ARGC 0
/* PR_GetLibraryName
 *
 * Parameters:
 * - dir: const char *
 * - lib: const char *
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PR_GetLibraryName(mrb_state* mrb, mrb_value self) {
  mrb_value dir;
  mrb_value lib;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &dir, &lib);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, dir, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, lib, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_dir = mrb_string_value_cstr(mrb, &dir);

  const char * native_lib = mrb_string_value_cstr(mrb, &lib);

  /* Invocation */
  char * result = PR_GetLibraryName(native_dir, native_lib);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetLibraryPath_FUNCTION
#define PR_GetLibraryPath_REQUIRED_ARGC 0
#define PR_GetLibraryPath_OPTIONAL_ARGC 0
/* PR_GetLibraryPath
 *
 * Parameters: None
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PR_GetLibraryPath(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  char * result = PR_GetLibraryPath();

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetMemMapAlignment_FUNCTION
#define PR_GetMemMapAlignment_REQUIRED_ARGC 0
#define PR_GetMemMapAlignment_OPTIONAL_ARGC 0
/* PR_GetMemMapAlignment
 *
 * Parameters: None
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_GetMemMapAlignment(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRInt32 result = PR_GetMemMapAlignment();

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_GetNameForIdentity_FUNCTION
#define PR_GetNameForIdentity_REQUIRED_ARGC 1
#define PR_GetNameForIdentity_OPTIONAL_ARGC 0
/* PR_GetNameForIdentity
 *
 * Parameters:
 * - ident: int
 * Return Type: const char *
 */
mrb_value
mrb_NSPR_PR_GetNameForIdentity(mrb_state* mrb, mrb_value self) {
  mrb_value ident;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &ident);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, ident, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_ident = mrb_fixnum(ident);

  /* Invocation */
  const char * result = PR_GetNameForIdentity(native_ident);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetNumberOfProcessors_FUNCTION
#define PR_GetNumberOfProcessors_REQUIRED_ARGC 0
#define PR_GetNumberOfProcessors_OPTIONAL_ARGC 0
/* PR_GetNumberOfProcessors
 *
 * Parameters: None
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_GetNumberOfProcessors(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRInt32 result = PR_GetNumberOfProcessors();

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_GetOpenFileInfo_FUNCTION
#define PR_GetOpenFileInfo_REQUIRED_ARGC 2
#define PR_GetOpenFileInfo_OPTIONAL_ARGC 0
/* PR_GetOpenFileInfo
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - info: struct PRFileInfo *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_GetOpenFileInfo(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value info;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &fd, &info);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_struct_PRFileInfo_PTR(info);


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  struct PRFileInfo * native_info = TODO_mruby_unbox_struct_PRFileInfo_PTR(info);

  /* Invocation */
  PRStatus result = PR_GetOpenFileInfo(native_fd, native_info);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetOpenFileInfo64_FUNCTION
#define PR_GetOpenFileInfo64_REQUIRED_ARGC 2
#define PR_GetOpenFileInfo64_OPTIONAL_ARGC 0
/* PR_GetOpenFileInfo64
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - info: struct PRFileInfo64 *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_GetOpenFileInfo64(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value info;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &fd, &info);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_struct_PRFileInfo64_PTR(info);


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  struct PRFileInfo64 * native_info = TODO_mruby_unbox_struct_PRFileInfo64_PTR(info);

  /* Invocation */
  PRStatus result = PR_GetOpenFileInfo64(native_fd, native_info);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetOSError_FUNCTION
#define PR_GetOSError_REQUIRED_ARGC 0
#define PR_GetOSError_OPTIONAL_ARGC 0
/* PR_GetOSError
 *
 * Parameters: None
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_GetOSError(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRInt32 result = PR_GetOSError();

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_GetPageShift_FUNCTION
#define PR_GetPageShift_REQUIRED_ARGC 0
#define PR_GetPageShift_OPTIONAL_ARGC 0
/* PR_GetPageShift
 *
 * Parameters: None
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_GetPageShift(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRInt32 result = PR_GetPageShift();

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_GetPageSize_FUNCTION
#define PR_GetPageSize_REQUIRED_ARGC 0
#define PR_GetPageSize_OPTIONAL_ARGC 0
/* PR_GetPageSize
 *
 * Parameters: None
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_GetPageSize(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRInt32 result = PR_GetPageSize();

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_GetPathSeparator_FUNCTION
#define PR_GetPathSeparator_REQUIRED_ARGC 0
#define PR_GetPathSeparator_OPTIONAL_ARGC 0
/* PR_GetPathSeparator
 *
 * Parameters: None
 * Return Type: char
 */
mrb_value
mrb_NSPR_PR_GetPathSeparator(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  char result = PR_GetPathSeparator();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_char(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetPeerName_FUNCTION
#define PR_GetPeerName_REQUIRED_ARGC 2
#define PR_GetPeerName_OPTIONAL_ARGC 0
/* PR_GetPeerName
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - addr: union PRNetAddr *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_GetPeerName(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value addr;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &fd, &addr);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_union_PRNetAddr_PTR(addr);


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  union PRNetAddr * native_addr = TODO_mruby_unbox_union_PRNetAddr_PTR(addr);

  /* Invocation */
  PRStatus result = PR_GetPeerName(native_fd, native_addr);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetPhysicalMemorySize_FUNCTION
#define PR_GetPhysicalMemorySize_REQUIRED_ARGC 0
#define PR_GetPhysicalMemorySize_OPTIONAL_ARGC 0
/* PR_GetPhysicalMemorySize
 *
 * Parameters: None
 * Return Type: PRUint64
 */
mrb_value
mrb_NSPR_PR_GetPhysicalMemorySize(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRUint64 result = PR_GetPhysicalMemorySize();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_unsigned_long_long(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetProtoByName_FUNCTION
#define PR_GetProtoByName_REQUIRED_ARGC 4
#define PR_GetProtoByName_OPTIONAL_ARGC 0
/* PR_GetProtoByName
 *
 * Parameters:
 * - protocolname: const char *
 * - buffer: char *
 * - bufsize: int
 * - result: struct PRProtoEnt *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_GetProtoByName(mrb_state* mrb, mrb_value self) {
  mrb_value protocolname;
  mrb_value buffer;
  mrb_value bufsize;
  mrb_value result;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &protocolname, &buffer, &bufsize, &result);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, protocolname, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
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
  TODO_type_check_struct_PRProtoEnt_PTR(result);


  /* Unbox parameters */
  const char * native_protocolname = mrb_string_value_cstr(mrb, &protocolname);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_buffer = strdup(mrb_string_value_cstr(mrb, &buffer));

  int native_bufsize = mrb_fixnum(bufsize);

  struct PRProtoEnt * native_result = TODO_mruby_unbox_struct_PRProtoEnt_PTR(result);

  /* Invocation */
  PRStatus result = PR_GetProtoByName(native_protocolname, native_buffer, native_bufsize, native_result);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

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

#if BIND_PR_GetProtoByNumber_FUNCTION
#define PR_GetProtoByNumber_REQUIRED_ARGC 4
#define PR_GetProtoByNumber_OPTIONAL_ARGC 0
/* PR_GetProtoByNumber
 *
 * Parameters:
 * - protocolnumber: int
 * - buffer: char *
 * - bufsize: int
 * - result: struct PRProtoEnt *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_GetProtoByNumber(mrb_state* mrb, mrb_value self) {
  mrb_value protocolnumber;
  mrb_value buffer;
  mrb_value bufsize;
  mrb_value result;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &protocolnumber, &buffer, &bufsize, &result);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, protocolnumber, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
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
  TODO_type_check_struct_PRProtoEnt_PTR(result);


  /* Unbox parameters */
  int native_protocolnumber = mrb_fixnum(protocolnumber);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_buffer = strdup(mrb_string_value_cstr(mrb, &buffer));

  int native_bufsize = mrb_fixnum(bufsize);

  struct PRProtoEnt * native_result = TODO_mruby_unbox_struct_PRProtoEnt_PTR(result);

  /* Invocation */
  PRStatus result = PR_GetProtoByNumber(native_protocolnumber, native_buffer, native_bufsize, native_result);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

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

#if BIND_PR_GetRandomNoise_FUNCTION
#define PR_GetRandomNoise_REQUIRED_ARGC 2
#define PR_GetRandomNoise_OPTIONAL_ARGC 0
/* PR_GetRandomNoise
 *
 * Parameters:
 * - buf: void *
 * - size: unsigned long
 * Return Type: PRSize
 */
mrb_value
mrb_NSPR_PR_GetRandomNoise(mrb_state* mrb, mrb_value self) {
  mrb_value buf;
  mrb_value size;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &buf, &size);


  /* Type checking */
  TODO_type_check_void_PTR(buf);
  TODO_type_check_unsigned_long(size);


  /* Unbox parameters */
  void * native_buf = TODO_mruby_unbox_void_PTR(buf);

  unsigned long native_size = TODO_mruby_unbox_unsigned_long(size);

  /* Invocation */
  PRSize result = PR_GetRandomNoise(native_buf, native_size);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRSize(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetSocketOption_FUNCTION
#define PR_GetSocketOption_REQUIRED_ARGC 2
#define PR_GetSocketOption_OPTIONAL_ARGC 0
/* PR_GetSocketOption
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - data: struct PRSocketOptionData *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_GetSocketOption(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value data;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &fd, &data);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_struct_PRSocketOptionData_PTR(data);


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  struct PRSocketOptionData * native_data = TODO_mruby_unbox_struct_PRSocketOptionData_PTR(data);

  /* Invocation */
  PRStatus result = PR_GetSocketOption(native_fd, native_data);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetSockName_FUNCTION
#define PR_GetSockName_REQUIRED_ARGC 2
#define PR_GetSockName_OPTIONAL_ARGC 0
/* PR_GetSockName
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - addr: union PRNetAddr *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_GetSockName(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value addr;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &fd, &addr);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_union_PRNetAddr_PTR(addr);


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  union PRNetAddr * native_addr = TODO_mruby_unbox_union_PRNetAddr_PTR(addr);

  /* Invocation */
  PRStatus result = PR_GetSockName(native_fd, native_addr);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetSpecialFD_FUNCTION
#define PR_GetSpecialFD_REQUIRED_ARGC 1
#define PR_GetSpecialFD_OPTIONAL_ARGC 0
/* PR_GetSpecialFD
 *
 * Parameters:
 * - id: enum PRSpecialFD
 * Return Type: PRFileDesc *
 */
mrb_value
mrb_NSPR_PR_GetSpecialFD(mrb_state* mrb, mrb_value self) {
  mrb_value id;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &id);


  /* Type checking */
  TODO_type_check_enum_PRSpecialFD(id);


  /* Unbox parameters */
  enum PRSpecialFD native_id = TODO_mruby_unbox_enum_PRSpecialFD(id);

  /* Invocation */
  PRFileDesc * result = PR_GetSpecialFD(native_id);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRFileDesc_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetSystemInfo_FUNCTION
#define PR_GetSystemInfo_REQUIRED_ARGC 3
#define PR_GetSystemInfo_OPTIONAL_ARGC 0
/* PR_GetSystemInfo
 *
 * Parameters:
 * - cmd: PRSysInfo
 * - buf: char *
 * - buflen: unsigned int
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_GetSystemInfo(mrb_state* mrb, mrb_value self) {
  mrb_value cmd;
  mrb_value buf;
  mrb_value buflen;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &cmd, &buf, &buflen);


  /* Type checking */
  TODO_type_check_PRSysInfo(cmd);
  if (!mrb_obj_is_kind_of(mrb, buf, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, buflen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  PRSysInfo native_cmd = TODO_mruby_unbox_PRSysInfo(cmd);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_buf = strdup(mrb_string_value_cstr(mrb, &buf));

  unsigned int native_buflen = mrb_fixnum(buflen);

  /* Invocation */
  PRStatus result = PR_GetSystemInfo(native_cmd, native_buf, native_buflen);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

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

#if BIND_PR_GetThreadName_FUNCTION
#define PR_GetThreadName_REQUIRED_ARGC 2
#define PR_GetThreadName_OPTIONAL_ARGC 0
/* PR_GetThreadName
 *
 * Parameters:
 * - thread: const struct PRThread *
 * - priv: void *
 * Return Type: const char *
 */
mrb_value
mrb_NSPR_PR_GetThreadName(mrb_state* mrb, mrb_value self) {
  mrb_value thread;
  mrb_value priv;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &thread, &priv);


  /* Type checking */
  TODO_type_check_const_struct_PRThread_PTR(thread);
  TODO_type_check_void_PTR(priv);


  /* Unbox parameters */
  const struct PRThread * native_thread = TODO_mruby_unbox_const_struct_PRThread_PTR(thread);

  void * native_priv = TODO_mruby_unbox_void_PTR(priv);

  /* Invocation */
  const char * result = PR_GetThreadName(native_thread, native_priv);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetThreadPriority_FUNCTION
#define PR_GetThreadPriority_REQUIRED_ARGC 1
#define PR_GetThreadPriority_OPTIONAL_ARGC 0
/* PR_GetThreadPriority
 *
 * Parameters:
 * - thread: const struct PRThread *
 * Return Type: PRThreadPriority
 */
mrb_value
mrb_NSPR_PR_GetThreadPriority(mrb_state* mrb, mrb_value self) {
  mrb_value thread;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &thread);


  /* Type checking */
  TODO_type_check_const_struct_PRThread_PTR(thread);


  /* Unbox parameters */
  const struct PRThread * native_thread = TODO_mruby_unbox_const_struct_PRThread_PTR(thread);

  /* Invocation */
  PRThreadPriority result = PR_GetThreadPriority(native_thread);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_enum_PRThreadPriority(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetThreadPrivate_FUNCTION
#define PR_GetThreadPrivate_REQUIRED_ARGC 1
#define PR_GetThreadPrivate_OPTIONAL_ARGC 0
/* PR_GetThreadPrivate
 *
 * Parameters:
 * - tpdIndex: unsigned int
 * Return Type: void *
 */
mrb_value
mrb_NSPR_PR_GetThreadPrivate(mrb_state* mrb, mrb_value self) {
  mrb_value tpdIndex;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &tpdIndex);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, tpdIndex, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  unsigned int native_tpdIndex = mrb_fixnum(tpdIndex);

  /* Invocation */
  void * result = PR_GetThreadPrivate(native_tpdIndex);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetThreadScope_FUNCTION
#define PR_GetThreadScope_REQUIRED_ARGC 1
#define PR_GetThreadScope_OPTIONAL_ARGC 0
/* PR_GetThreadScope
 *
 * Parameters:
 * - thread: const struct PRThread *
 * Return Type: PRThreadScope
 */
mrb_value
mrb_NSPR_PR_GetThreadScope(mrb_state* mrb, mrb_value self) {
  mrb_value thread;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &thread);


  /* Type checking */
  TODO_type_check_const_struct_PRThread_PTR(thread);


  /* Unbox parameters */
  const struct PRThread * native_thread = TODO_mruby_unbox_const_struct_PRThread_PTR(thread);

  /* Invocation */
  PRThreadScope result = PR_GetThreadScope(native_thread);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_enum_PRThreadScope(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetThreadState_FUNCTION
#define PR_GetThreadState_REQUIRED_ARGC 2
#define PR_GetThreadState_OPTIONAL_ARGC 0
/* PR_GetThreadState
 *
 * Parameters:
 * - thread: const struct PRThread *
 * - gmt: const struct PRExplodedTime *
 * Return Type: PRThreadState
 */
mrb_value
mrb_NSPR_PR_GetThreadState(mrb_state* mrb, mrb_value self) {
  mrb_value thread;
  mrb_value gmt;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &thread, &gmt);


  /* Type checking */
  TODO_type_check_const_struct_PRThread_PTR(thread);
  TODO_type_check_const_struct_PRExplodedTime_PTR(gmt);


  /* Unbox parameters */
  const struct PRThread * native_thread = TODO_mruby_unbox_const_struct_PRThread_PTR(thread);

  const struct PRExplodedTime * native_gmt = TODO_mruby_unbox_const_struct_PRExplodedTime_PTR(gmt);

  /* Invocation */
  PRThreadState result = PR_GetThreadState(native_thread, native_gmt);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_enum_PRThreadState(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetThreadType_FUNCTION
#define PR_GetThreadType_REQUIRED_ARGC 1
#define PR_GetThreadType_OPTIONAL_ARGC 0
/* PR_GetThreadType
 *
 * Parameters:
 * - thread: const struct PRThread *
 * Return Type: PRThreadType
 */
mrb_value
mrb_NSPR_PR_GetThreadType(mrb_state* mrb, mrb_value self) {
  mrb_value thread;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &thread);


  /* Type checking */
  TODO_type_check_const_struct_PRThread_PTR(thread);


  /* Unbox parameters */
  const struct PRThread * native_thread = TODO_mruby_unbox_const_struct_PRThread_PTR(thread);

  /* Invocation */
  PRThreadType result = PR_GetThreadType(native_thread);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_enum_PRThreadType(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetTraceEntries_FUNCTION
#define PR_GetTraceEntries_REQUIRED_ARGC 3
#define PR_GetTraceEntries_OPTIONAL_ARGC 0
/* PR_GetTraceEntries
 *
 * Parameters:
 * - buffer: struct PRTraceEntry *
 * - count: int
 * - found: int *
 * Return Type: PRIntn
 */
mrb_value
mrb_NSPR_PR_GetTraceEntries(mrb_state* mrb, mrb_value self) {
  mrb_value buffer;
  mrb_value count;
  mrb_value found;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &buffer, &count, &found);


  /* Type checking */
  TODO_type_check_struct_PRTraceEntry_PTR(buffer);
  if (!mrb_obj_is_kind_of(mrb, count, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_int_PTR(found);


  /* Unbox parameters */
  struct PRTraceEntry * native_buffer = TODO_mruby_unbox_struct_PRTraceEntry_PTR(buffer);

  int native_count = mrb_fixnum(count);

  int * native_found = TODO_mruby_unbox_int_PTR(found);

  /* Invocation */
  PRIntn result = PR_GetTraceEntries(native_buffer, native_count, native_found);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_GetTraceHandleFromName_FUNCTION
#define PR_GetTraceHandleFromName_REQUIRED_ARGC 2
#define PR_GetTraceHandleFromName_OPTIONAL_ARGC 0
/* PR_GetTraceHandleFromName
 *
 * Parameters:
 * - qName: const char *
 * - rName: const char *
 * Return Type: PRTraceHandle
 */
mrb_value
mrb_NSPR_PR_GetTraceHandleFromName(mrb_state* mrb, mrb_value self) {
  mrb_value qName;
  mrb_value rName;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &qName, &rName);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, qName, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, rName, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_qName = mrb_string_value_cstr(mrb, &qName);

  const char * native_rName = mrb_string_value_cstr(mrb, &rName);

  /* Invocation */
  PRTraceHandle result = PR_GetTraceHandleFromName(native_qName, native_rName);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetTraceNameFromHandle_FUNCTION
#define PR_GetTraceNameFromHandle_REQUIRED_ARGC 4
#define PR_GetTraceNameFromHandle_OPTIONAL_ARGC 0
/* PR_GetTraceNameFromHandle
 *
 * Parameters:
 * - handle: void *
 * - qName: const char **
 * - rName: const char **
 * - description: const char **
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_GetTraceNameFromHandle(mrb_state* mrb, mrb_value self) {
  mrb_value handle;
  mrb_value qName;
  mrb_value rName;
  mrb_value description;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &handle, &qName, &rName, &description);


  /* Type checking */
  TODO_type_check_void_PTR(handle);
  TODO_type_check_const_char_PTR_PTR(qName);
  TODO_type_check_const_char_PTR_PTR(rName);
  TODO_type_check_const_char_PTR_PTR(description);


  /* Unbox parameters */
  void * native_handle = TODO_mruby_unbox_void_PTR(handle);

  const char ** native_qName = TODO_mruby_unbox_const_char_PTR_PTR(qName);

  const char ** native_rName = TODO_mruby_unbox_const_char_PTR_PTR(rName);

  const char ** native_description = TODO_mruby_unbox_const_char_PTR_PTR(description);

  /* Invocation */
  PR_GetTraceNameFromHandle(native_handle, native_qName, native_rName, native_description);

  return mrb_nil_value();
}
#endif

#if BIND_PR_GetTraceOption_FUNCTION
#define PR_GetTraceOption_REQUIRED_ARGC 2
#define PR_GetTraceOption_OPTIONAL_ARGC 0
/* PR_GetTraceOption
 *
 * Parameters:
 * - command: enum PRTraceOption
 * - value: void *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_GetTraceOption(mrb_state* mrb, mrb_value self) {
  mrb_value command;
  mrb_value value;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &command, &value);


  /* Type checking */
  TODO_type_check_enum_PRTraceOption(command);
  TODO_type_check_void_PTR(value);


  /* Unbox parameters */
  enum PRTraceOption native_command = TODO_mruby_unbox_enum_PRTraceOption(command);

  void * native_value = TODO_mruby_unbox_void_PTR(value);

  /* Invocation */
  PR_GetTraceOption(native_command, native_value);

  return mrb_nil_value();
}
#endif

#if BIND_PR_GetUniqueIdentity_FUNCTION
#define PR_GetUniqueIdentity_REQUIRED_ARGC 1
#define PR_GetUniqueIdentity_OPTIONAL_ARGC 0
/* PR_GetUniqueIdentity
 *
 * Parameters:
 * - layer_name: const char *
 * Return Type: PRDescIdentity
 */
mrb_value
mrb_NSPR_PR_GetUniqueIdentity(mrb_state* mrb, mrb_value self) {
  mrb_value layer_name;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &layer_name);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, layer_name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_layer_name = mrb_string_value_cstr(mrb, &layer_name);

  /* Invocation */
  PRDescIdentity result = PR_GetUniqueIdentity(native_layer_name);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRDescIdentity(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GetVersion_FUNCTION
#define PR_GetVersion_REQUIRED_ARGC 0
#define PR_GetVersion_OPTIONAL_ARGC 0
/* PR_GetVersion
 *
 * Parameters: None
 * Return Type: const char *
 */
mrb_value
mrb_NSPR_PR_GetVersion(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  const char * result = PR_GetVersion();

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_GMTParameters_FUNCTION
#define PR_GMTParameters_REQUIRED_ARGC 1
#define PR_GMTParameters_OPTIONAL_ARGC 0
/* PR_GMTParameters
 *
 * Parameters:
 * - gmt: const struct PRExplodedTime *
 * Return Type: PRTimeParameters
 */
mrb_value
mrb_NSPR_PR_GMTParameters(mrb_state* mrb, mrb_value self) {
  mrb_value gmt;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &gmt);


  /* Type checking */
  TODO_type_check_const_struct_PRExplodedTime_PTR(gmt);


  /* Unbox parameters */
  const struct PRExplodedTime * native_gmt = TODO_mruby_unbox_const_struct_PRExplodedTime_PTR(gmt);

  /* Invocation */
  PRTimeParameters result = PR_GMTParameters(native_gmt);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRTimeParameters(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_htonl_FUNCTION
#define PR_htonl_REQUIRED_ARGC 1
#define PR_htonl_OPTIONAL_ARGC 0
/* PR_htonl
 *
 * Parameters:
 * - arg1: unsigned int
 * Return Type: PRUint32
 */
mrb_value
mrb_NSPR_PR_htonl(mrb_state* mrb, mrb_value self) {
  mrb_value arg1;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &arg1);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, arg1, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  unsigned int native_arg1 = mrb_fixnum(arg1);

  /* Invocation */
  PRUint32 result = PR_htonl(native_arg1);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_htonll_FUNCTION
#define PR_htonll_REQUIRED_ARGC 1
#define PR_htonll_OPTIONAL_ARGC 0
/* PR_htonll
 *
 * Parameters:
 * - arg1: unsigned long long
 * Return Type: PRUint64
 */
mrb_value
mrb_NSPR_PR_htonll(mrb_state* mrb, mrb_value self) {
  mrb_value arg1;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &arg1);


  /* Type checking */
  TODO_type_check_unsigned_long_long(arg1);


  /* Unbox parameters */
  unsigned long long native_arg1 = TODO_mruby_unbox_unsigned_long_long(arg1);

  /* Invocation */
  PRUint64 result = PR_htonll(native_arg1);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_unsigned_long_long(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_htons_FUNCTION
#define PR_htons_REQUIRED_ARGC 1
#define PR_htons_OPTIONAL_ARGC 0
/* PR_htons
 *
 * Parameters:
 * - arg1: unsigned short
 * Return Type: PRUint16
 */
mrb_value
mrb_NSPR_PR_htons(mrb_state* mrb, mrb_value self) {
  mrb_value arg1;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &arg1);


  /* Type checking */
  TODO_type_check_unsigned_short(arg1);


  /* Unbox parameters */
  unsigned short native_arg1 = TODO_mruby_unbox_unsigned_short(arg1);

  /* Invocation */
  PRUint16 result = PR_htons(native_arg1);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_unsigned_short(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_ImplodeTime_FUNCTION
#define PR_ImplodeTime_REQUIRED_ARGC 1
#define PR_ImplodeTime_OPTIONAL_ARGC 0
/* PR_ImplodeTime
 *
 * Parameters:
 * - exploded: const struct PRExplodedTime *
 * Return Type: PRTime
 */
mrb_value
mrb_NSPR_PR_ImplodeTime(mrb_state* mrb, mrb_value self) {
  mrb_value exploded;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &exploded);


  /* Type checking */
  TODO_type_check_const_struct_PRExplodedTime_PTR(exploded);


  /* Unbox parameters */
  const struct PRExplodedTime * native_exploded = TODO_mruby_unbox_const_struct_PRExplodedTime_PTR(exploded);

  /* Invocation */
  PRTime result = PR_ImplodeTime(native_exploded);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_long_long(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_ImportFileMapFromString_FUNCTION
#define PR_ImportFileMapFromString_REQUIRED_ARGC 1
#define PR_ImportFileMapFromString_OPTIONAL_ARGC 0
/* PR_ImportFileMapFromString
 *
 * Parameters:
 * - fmstring: const char *
 * Return Type: PRFileMap *
 */
mrb_value
mrb_NSPR_PR_ImportFileMapFromString(mrb_state* mrb, mrb_value self) {
  mrb_value fmstring;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &fmstring);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, fmstring, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_fmstring = mrb_string_value_cstr(mrb, &fmstring);

  /* Invocation */
  PRFileMap * result = PR_ImportFileMapFromString(native_fmstring);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRFileMap_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_IncrementCounter_FUNCTION
#define PR_IncrementCounter_REQUIRED_ARGC 1
#define PR_IncrementCounter_OPTIONAL_ARGC 0
/* PR_IncrementCounter
 *
 * Parameters:
 * - handle: void *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_IncrementCounter(mrb_state* mrb, mrb_value self) {
  mrb_value handle;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &handle);


  /* Type checking */
  TODO_type_check_void_PTR(handle);


  /* Unbox parameters */
  void * native_handle = TODO_mruby_unbox_void_PTR(handle);

  /* Invocation */
  PR_IncrementCounter(native_handle);

  return mrb_nil_value();
}
#endif

#if BIND_PR_Init_FUNCTION
#define PR_Init_REQUIRED_ARGC 5
#define PR_Init_OPTIONAL_ARGC 0
/* PR_Init
 *
 * Parameters:
 * - type: enum PRThreadType
 * - priority: enum PRThreadPriority
 * - maxPTDs: unsigned int
 * - argc: int
 * - argv: char **
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_Init(mrb_state* mrb, mrb_value self) {
  mrb_value type;
  mrb_value priority;
  mrb_value maxPTDs;
  mrb_value argc;
  mrb_value argv;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &type, &priority, &maxPTDs, &argc, &argv);


  /* Type checking */
  TODO_type_check_enum_PRThreadType(type);
  TODO_type_check_enum_PRThreadPriority(priority);
  if (!mrb_obj_is_kind_of(mrb, maxPTDs, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, argc, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_char_PTR_PTR(argv);


  /* Unbox parameters */
  enum PRThreadType native_type = TODO_mruby_unbox_enum_PRThreadType(type);

  enum PRThreadPriority native_priority = TODO_mruby_unbox_enum_PRThreadPriority(priority);

  unsigned int native_maxPTDs = mrb_fixnum(maxPTDs);

  int native_argc = mrb_fixnum(argc);

  char ** native_argv = TODO_mruby_unbox_char_PTR_PTR(argv);

  /* Invocation */
  PR_Init(native_type, native_priority, native_maxPTDs, native_argc, native_argv);

  return mrb_nil_value();
}
#endif

#if BIND_PR_Initialize_FUNCTION
#define PR_Initialize_REQUIRED_ARGC 4
#define PR_Initialize_OPTIONAL_ARGC 0
/* PR_Initialize
 *
 * Parameters:
 * - prmain: int (*)(int, char **)
 * - argc: int
 * - argv: char **
 * - maxPTDs: unsigned int
 * Return Type: PRIntn
 */
mrb_value
mrb_NSPR_PR_Initialize(mrb_state* mrb, mrb_value self) {
  mrb_value prmain;
  mrb_value argc;
  mrb_value argv;
  mrb_value maxPTDs;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &prmain, &argc, &argv, &maxPTDs);


  /* Type checking */
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_intCOMMA_char_PTR_PTR_RPAREN(prmain);
  if (!mrb_obj_is_kind_of(mrb, argc, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_char_PTR_PTR(argv);
  if (!mrb_obj_is_kind_of(mrb, maxPTDs, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int (*native_prmain)(int, char **) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_intCOMMA_char_PTR_PTR_RPAREN(prmain);

  int native_argc = mrb_fixnum(argc);

  char ** native_argv = TODO_mruby_unbox_char_PTR_PTR(argv);

  unsigned int native_maxPTDs = mrb_fixnum(maxPTDs);

  /* Invocation */
  PRIntn result = PR_Initialize(native_prmain, native_argc, native_argv, native_maxPTDs);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_Initialized_FUNCTION
#define PR_Initialized_REQUIRED_ARGC 0
#define PR_Initialized_OPTIONAL_ARGC 0
/* PR_Initialized
 *
 * Parameters: None
 * Return Type: PRBool
 */
mrb_value
mrb_NSPR_PR_Initialized(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRBool result = PR_Initialized();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRBool(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_InitializeNetAddr_FUNCTION
#define PR_InitializeNetAddr_REQUIRED_ARGC 3
#define PR_InitializeNetAddr_OPTIONAL_ARGC 0
/* PR_InitializeNetAddr
 *
 * Parameters:
 * - val: enum PRNetAddrValue
 * - port: unsigned short
 * - addr: union PRNetAddr *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_InitializeNetAddr(mrb_state* mrb, mrb_value self) {
  mrb_value val;
  mrb_value port;
  mrb_value addr;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &val, &port, &addr);


  /* Type checking */
  TODO_type_check_enum_PRNetAddrValue(val);
  TODO_type_check_unsigned_short(port);
  TODO_type_check_union_PRNetAddr_PTR(addr);


  /* Unbox parameters */
  enum PRNetAddrValue native_val = TODO_mruby_unbox_enum_PRNetAddrValue(val);

  unsigned short native_port = TODO_mruby_unbox_unsigned_short(port);

  union PRNetAddr * native_addr = TODO_mruby_unbox_union_PRNetAddr_PTR(addr);

  /* Invocation */
  PRStatus result = PR_InitializeNetAddr(native_val, native_port, native_addr);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_Interrupt_FUNCTION
#define PR_Interrupt_REQUIRED_ARGC 1
#define PR_Interrupt_OPTIONAL_ARGC 0
/* PR_Interrupt
 *
 * Parameters:
 * - thread: struct PRThread *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_Interrupt(mrb_state* mrb, mrb_value self) {
  mrb_value thread;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &thread);


  /* Type checking */
  TODO_type_check_struct_PRThread_PTR(thread);


  /* Unbox parameters */
  struct PRThread * native_thread = TODO_mruby_unbox_struct_PRThread_PTR(thread);

  /* Invocation */
  PRStatus result = PR_Interrupt(native_thread);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_IntervalNow_FUNCTION
#define PR_IntervalNow_REQUIRED_ARGC 0
#define PR_IntervalNow_OPTIONAL_ARGC 0
/* PR_IntervalNow
 *
 * Parameters: None
 * Return Type: PRIntervalTime
 */
mrb_value
mrb_NSPR_PR_IntervalNow(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRIntervalTime result = PR_IntervalNow();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRIntervalTime(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_IntervalToMicroseconds_FUNCTION
#define PR_IntervalToMicroseconds_REQUIRED_ARGC 2
#define PR_IntervalToMicroseconds_OPTIONAL_ARGC 0
/* PR_IntervalToMicroseconds
 *
 * Parameters:
 * - ticks: unsigned int
 * - fd: struct PRFileDesc *
 * Return Type: PRUint32
 */
mrb_value
mrb_NSPR_PR_IntervalToMicroseconds(mrb_state* mrb, mrb_value self) {
  mrb_value ticks;
  mrb_value fd;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &ticks, &fd);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, ticks, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct_PRFileDesc_PTR(fd);


  /* Unbox parameters */
  unsigned int native_ticks = mrb_fixnum(ticks);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  /* Invocation */
  PRUint32 result = PR_IntervalToMicroseconds(native_ticks, native_fd);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_IntervalToMilliseconds_FUNCTION
#define PR_IntervalToMilliseconds_REQUIRED_ARGC 1
#define PR_IntervalToMilliseconds_OPTIONAL_ARGC 0
/* PR_IntervalToMilliseconds
 *
 * Parameters:
 * - ticks: unsigned int
 * Return Type: PRUint32
 */
mrb_value
mrb_NSPR_PR_IntervalToMilliseconds(mrb_state* mrb, mrb_value self) {
  mrb_value ticks;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &ticks);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, ticks, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  unsigned int native_ticks = mrb_fixnum(ticks);

  /* Invocation */
  PRUint32 result = PR_IntervalToMilliseconds(native_ticks);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_IntervalToSeconds_FUNCTION
#define PR_IntervalToSeconds_REQUIRED_ARGC 1
#define PR_IntervalToSeconds_OPTIONAL_ARGC 0
/* PR_IntervalToSeconds
 *
 * Parameters:
 * - ticks: unsigned int
 * Return Type: PRUint32
 */
mrb_value
mrb_NSPR_PR_IntervalToSeconds(mrb_state* mrb, mrb_value self) {
  mrb_value ticks;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &ticks);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, ticks, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  unsigned int native_ticks = mrb_fixnum(ticks);

  /* Invocation */
  PRUint32 result = PR_IntervalToSeconds(native_ticks);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_IsNetAddrType_FUNCTION
#define PR_IsNetAddrType_REQUIRED_ARGC 2
#define PR_IsNetAddrType_OPTIONAL_ARGC 0
/* PR_IsNetAddrType
 *
 * Parameters:
 * - addr: const union PRNetAddr *
 * - val: enum PRNetAddrValue
 * Return Type: PRBool
 */
mrb_value
mrb_NSPR_PR_IsNetAddrType(mrb_state* mrb, mrb_value self) {
  mrb_value addr;
  mrb_value val;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &addr, &val);


  /* Type checking */
  TODO_type_check_const_union_PRNetAddr_PTR(addr);
  TODO_type_check_enum_PRNetAddrValue(val);


  /* Unbox parameters */
  const union PRNetAddr * native_addr = TODO_mruby_unbox_const_union_PRNetAddr_PTR(addr);

  enum PRNetAddrValue native_val = TODO_mruby_unbox_enum_PRNetAddrValue(val);

  /* Invocation */
  PRBool result = PR_IsNetAddrType(native_addr, native_val);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRBool(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_JoinJob_FUNCTION
#define PR_JoinJob_REQUIRED_ARGC 1
#define PR_JoinJob_OPTIONAL_ARGC 0
/* PR_JoinJob
 *
 * Parameters:
 * - job: struct PRJob *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_JoinJob(mrb_state* mrb, mrb_value self) {
  mrb_value job;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &job);


  /* Type checking */
  TODO_type_check_struct_PRJob_PTR(job);


  /* Unbox parameters */
  struct PRJob * native_job = TODO_mruby_unbox_struct_PRJob_PTR(job);

  /* Invocation */
  PRStatus result = PR_JoinJob(native_job);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_JoinThread_FUNCTION
#define PR_JoinThread_REQUIRED_ARGC 1
#define PR_JoinThread_OPTIONAL_ARGC 0
/* PR_JoinThread
 *
 * Parameters:
 * - thread: struct PRThread *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_JoinThread(mrb_state* mrb, mrb_value self) {
  mrb_value thread;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &thread);


  /* Type checking */
  TODO_type_check_struct_PRThread_PTR(thread);


  /* Unbox parameters */
  struct PRThread * native_thread = TODO_mruby_unbox_struct_PRThread_PTR(thread);

  /* Invocation */
  PRStatus result = PR_JoinThread(native_thread);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_JoinThreadPool_FUNCTION
#define PR_JoinThreadPool_REQUIRED_ARGC 1
#define PR_JoinThreadPool_OPTIONAL_ARGC 0
/* PR_JoinThreadPool
 *
 * Parameters:
 * - tpool: struct PRThreadPool *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_JoinThreadPool(mrb_state* mrb, mrb_value self) {
  mrb_value tpool;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &tpool);


  /* Type checking */
  TODO_type_check_struct_PRThreadPool_PTR(tpool);


  /* Unbox parameters */
  struct PRThreadPool * native_tpool = TODO_mruby_unbox_struct_PRThreadPool_PTR(tpool);

  /* Invocation */
  PRStatus result = PR_JoinThreadPool(native_tpool);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_KillProcess_FUNCTION
#define PR_KillProcess_REQUIRED_ARGC 1
#define PR_KillProcess_OPTIONAL_ARGC 0
/* PR_KillProcess
 *
 * Parameters:
 * - process: struct PRProcess *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_KillProcess(mrb_state* mrb, mrb_value self) {
  mrb_value process;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &process);


  /* Type checking */
  TODO_type_check_struct_PRProcess_PTR(process);


  /* Unbox parameters */
  struct PRProcess * native_process = TODO_mruby_unbox_struct_PRProcess_PTR(process);

  /* Invocation */
  PRStatus result = PR_KillProcess(native_process);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_Listen_FUNCTION
#define PR_Listen_REQUIRED_ARGC 2
#define PR_Listen_OPTIONAL_ARGC 0
/* PR_Listen
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - backlog: int
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_Listen(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value backlog;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &fd, &backlog);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  if (!mrb_obj_is_kind_of(mrb, backlog, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  int native_backlog = mrb_fixnum(backlog);

  /* Invocation */
  PRStatus result = PR_Listen(native_fd, native_backlog);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_LoadLibrary_FUNCTION
#define PR_LoadLibrary_REQUIRED_ARGC 1
#define PR_LoadLibrary_OPTIONAL_ARGC 0
/* PR_LoadLibrary
 *
 * Parameters:
 * - name: const char *
 * Return Type: PRLibrary *
 */
mrb_value
mrb_NSPR_PR_LoadLibrary(mrb_state* mrb, mrb_value self) {
  mrb_value name;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &name);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_name = mrb_string_value_cstr(mrb, &name);

  /* Invocation */
  PRLibrary * result = PR_LoadLibrary(native_name);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRLibrary_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_LoadLibraryWithFlags_FUNCTION
#define PR_LoadLibraryWithFlags_REQUIRED_ARGC 2
#define PR_LoadLibraryWithFlags_OPTIONAL_ARGC 0
/* PR_LoadLibraryWithFlags
 *
 * Parameters:
 * - libSpec: struct PRLibSpec
 * - flags: int
 * Return Type: PRLibrary *
 */
mrb_value
mrb_NSPR_PR_LoadLibraryWithFlags(mrb_state* mrb, mrb_value self) {
  mrb_value libSpec;
  mrb_value flags;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &libSpec, &flags);


  /* Type checking */
  TODO_type_check_struct_PRLibSpec(libSpec);
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRLibSpec native_libSpec = TODO_mruby_unbox_struct_PRLibSpec(libSpec);

  int native_flags = mrb_fixnum(flags);

  /* Invocation */
  PRLibrary * result = PR_LoadLibraryWithFlags(native_libSpec, native_flags);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRLibrary_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_LoadStaticLibrary_FUNCTION
#define PR_LoadStaticLibrary_REQUIRED_ARGC 2
#define PR_LoadStaticLibrary_OPTIONAL_ARGC 0
/* PR_LoadStaticLibrary
 *
 * Parameters:
 * - name: const char *
 * - table: const struct PRStaticLinkTable *
 * Return Type: PRLibrary *
 */
mrb_value
mrb_NSPR_PR_LoadStaticLibrary(mrb_state* mrb, mrb_value self) {
  mrb_value name;
  mrb_value table;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &name, &table);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_struct_PRStaticLinkTable_PTR(table);


  /* Unbox parameters */
  const char * native_name = mrb_string_value_cstr(mrb, &name);

  const struct PRStaticLinkTable * native_table = TODO_mruby_unbox_const_struct_PRStaticLinkTable_PTR(table);

  /* Invocation */
  PRLibrary * result = PR_LoadStaticLibrary(native_name, native_table);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRLibrary_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_LocalTimeParameters_FUNCTION
#define PR_LocalTimeParameters_REQUIRED_ARGC 1
#define PR_LocalTimeParameters_OPTIONAL_ARGC 0
/* PR_LocalTimeParameters
 *
 * Parameters:
 * - gmt: const struct PRExplodedTime *
 * Return Type: PRTimeParameters
 */
mrb_value
mrb_NSPR_PR_LocalTimeParameters(mrb_state* mrb, mrb_value self) {
  mrb_value gmt;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &gmt);


  /* Type checking */
  TODO_type_check_const_struct_PRExplodedTime_PTR(gmt);


  /* Unbox parameters */
  const struct PRExplodedTime * native_gmt = TODO_mruby_unbox_const_struct_PRExplodedTime_PTR(gmt);

  /* Invocation */
  PRTimeParameters result = PR_LocalTimeParameters(native_gmt);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRTimeParameters(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_Lock_FUNCTION
#define PR_Lock_REQUIRED_ARGC 1
#define PR_Lock_OPTIONAL_ARGC 0
/* PR_Lock
 *
 * Parameters:
 * - lock: struct PRLock *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_Lock(mrb_state* mrb, mrb_value self) {
  mrb_value lock;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &lock);


  /* Type checking */
  TODO_type_check_struct_PRLock_PTR(lock);


  /* Unbox parameters */
  struct PRLock * native_lock = TODO_mruby_unbox_struct_PRLock_PTR(lock);

  /* Invocation */
  PR_Lock(native_lock);

  return mrb_nil_value();
}
#endif

#if BIND_PR_LockOrderedLock_FUNCTION
#define PR_LockOrderedLock_REQUIRED_ARGC 1
#define PR_LockOrderedLock_OPTIONAL_ARGC 0
/* PR_LockOrderedLock
 *
 * Parameters:
 * - lock: struct PRLock *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_LockOrderedLock(mrb_state* mrb, mrb_value self) {
  mrb_value lock;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &lock);


  /* Type checking */
  TODO_type_check_struct_PRLock_PTR(lock);


  /* Unbox parameters */
  struct PRLock * native_lock = TODO_mruby_unbox_struct_PRLock_PTR(lock);

  /* Invocation */
  PR_LockOrderedLock(native_lock);

  return mrb_nil_value();
}
#endif

#if BIND_PR_LogFlush_FUNCTION
#define PR_LogFlush_REQUIRED_ARGC 0
#define PR_LogFlush_OPTIONAL_ARGC 0
/* PR_LogFlush
 *
 * Parameters: None
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_LogFlush(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PR_LogFlush();

  return mrb_nil_value();
}
#endif

#if BIND_PR_LogPrint_FUNCTION
#define PR_LogPrint_REQUIRED_ARGC 1
#define PR_LogPrint_OPTIONAL_ARGC 0
/* PR_LogPrint
 *
 * Parameters:
 * - fmt: const char *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_LogPrint(mrb_state* mrb, mrb_value self) {
  mrb_value fmt;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &fmt);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, fmt, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_fmt = mrb_string_value_cstr(mrb, &fmt);

  /* Invocation */
  PR_LogPrint(native_fmt);

  return mrb_nil_value();
}
#endif

#if BIND_PR_MakeDir_FUNCTION
#define PR_MakeDir_REQUIRED_ARGC 2
#define PR_MakeDir_OPTIONAL_ARGC 0
/* PR_MakeDir
 *
 * Parameters:
 * - name: const char *
 * - mode: int
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_MakeDir(mrb_state* mrb, mrb_value self) {
  mrb_value name;
  mrb_value mode;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &name, &mode);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, mode, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_name = mrb_string_value_cstr(mrb, &name);

  int native_mode = mrb_fixnum(mode);

  /* Invocation */
  PRStatus result = PR_MakeDir(native_name, native_mode);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_Malloc_FUNCTION
#define PR_Malloc_REQUIRED_ARGC 1
#define PR_Malloc_OPTIONAL_ARGC 0
/* PR_Malloc
 *
 * Parameters:
 * - size: unsigned int
 * Return Type: void *
 */
mrb_value
mrb_NSPR_PR_Malloc(mrb_state* mrb, mrb_value self) {
  mrb_value size;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &size);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, size, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  unsigned int native_size = mrb_fixnum(size);

  /* Invocation */
  void * result = PR_Malloc(native_size);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_MemMap_FUNCTION
#define PR_MemMap_REQUIRED_ARGC 3
#define PR_MemMap_OPTIONAL_ARGC 0
/* PR_MemMap
 *
 * Parameters:
 * - fmap: struct PRFileMap *
 * - offset: long long
 * - len: unsigned int
 * Return Type: void *
 */
mrb_value
mrb_NSPR_PR_MemMap(mrb_state* mrb, mrb_value self) {
  mrb_value fmap;
  mrb_value offset;
  mrb_value len;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &fmap, &offset, &len);


  /* Type checking */
  TODO_type_check_struct_PRFileMap_PTR(fmap);
  TODO_type_check_long_long(offset);
  if (!mrb_obj_is_kind_of(mrb, len, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRFileMap * native_fmap = TODO_mruby_unbox_struct_PRFileMap_PTR(fmap);

  long long native_offset = TODO_mruby_unbox_long_long(offset);

  unsigned int native_len = mrb_fixnum(len);

  /* Invocation */
  void * result = PR_MemMap(native_fmap, native_offset, native_len);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_MemUnmap_FUNCTION
#define PR_MemUnmap_REQUIRED_ARGC 2
#define PR_MemUnmap_OPTIONAL_ARGC 0
/* PR_MemUnmap
 *
 * Parameters:
 * - addr: void *
 * - len: unsigned int
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_MemUnmap(mrb_state* mrb, mrb_value self) {
  mrb_value addr;
  mrb_value len;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &addr, &len);


  /* Type checking */
  TODO_type_check_void_PTR(addr);
  if (!mrb_obj_is_kind_of(mrb, len, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void * native_addr = TODO_mruby_unbox_void_PTR(addr);

  unsigned int native_len = mrb_fixnum(len);

  /* Invocation */
  PRStatus result = PR_MemUnmap(native_addr, native_len);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_MicrosecondsToInterval_FUNCTION
#define PR_MicrosecondsToInterval_REQUIRED_ARGC 1
#define PR_MicrosecondsToInterval_OPTIONAL_ARGC 0
/* PR_MicrosecondsToInterval
 *
 * Parameters:
 * - micro: unsigned int
 * Return Type: PRIntervalTime
 */
mrb_value
mrb_NSPR_PR_MicrosecondsToInterval(mrb_state* mrb, mrb_value self) {
  mrb_value micro;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &micro);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, micro, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  unsigned int native_micro = mrb_fixnum(micro);

  /* Invocation */
  PRIntervalTime result = PR_MicrosecondsToInterval(native_micro);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRIntervalTime(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_MillisecondsToInterval_FUNCTION
#define PR_MillisecondsToInterval_REQUIRED_ARGC 1
#define PR_MillisecondsToInterval_OPTIONAL_ARGC 0
/* PR_MillisecondsToInterval
 *
 * Parameters:
 * - milli: unsigned int
 * Return Type: PRIntervalTime
 */
mrb_value
mrb_NSPR_PR_MillisecondsToInterval(mrb_state* mrb, mrb_value self) {
  mrb_value milli;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &milli);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, milli, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  unsigned int native_milli = mrb_fixnum(milli);

  /* Invocation */
  PRIntervalTime result = PR_MillisecondsToInterval(native_milli);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRIntervalTime(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_MkDir_FUNCTION
#define PR_MkDir_REQUIRED_ARGC 2
#define PR_MkDir_OPTIONAL_ARGC 0
/* PR_MkDir
 *
 * Parameters:
 * - name: const char *
 * - mode: int
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_MkDir(mrb_state* mrb, mrb_value self) {
  mrb_value name;
  mrb_value mode;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &name, &mode);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, mode, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_name = mrb_string_value_cstr(mrb, &name);

  int native_mode = mrb_fixnum(mode);

  /* Invocation */
  PRStatus result = PR_MkDir(native_name, native_mode);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_NetAddrToString_FUNCTION
#define PR_NetAddrToString_REQUIRED_ARGC 3
#define PR_NetAddrToString_OPTIONAL_ARGC 0
/* PR_NetAddrToString
 *
 * Parameters:
 * - addr: const union PRNetAddr *
 * - string: char *
 * - size: unsigned int
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_NetAddrToString(mrb_state* mrb, mrb_value self) {
  mrb_value addr;
  mrb_value string;
  mrb_value size;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &addr, &string, &size);


  /* Type checking */
  TODO_type_check_const_union_PRNetAddr_PTR(addr);
  if (!mrb_obj_is_kind_of(mrb, string, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, size, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const union PRNetAddr * native_addr = TODO_mruby_unbox_const_union_PRNetAddr_PTR(addr);

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_string = strdup(mrb_string_value_cstr(mrb, &string));

  unsigned int native_size = mrb_fixnum(size);

  /* Invocation */
  PRStatus result = PR_NetAddrToString(native_addr, native_string, native_size);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_string);
  native_string = NULL;

  return return_value;
}
#endif

#if BIND_PR_NewCondVar_FUNCTION
#define PR_NewCondVar_REQUIRED_ARGC 1
#define PR_NewCondVar_OPTIONAL_ARGC 0
/* PR_NewCondVar
 *
 * Parameters:
 * - lock: struct PRLock *
 * Return Type: PRCondVar *
 */
mrb_value
mrb_NSPR_PR_NewCondVar(mrb_state* mrb, mrb_value self) {
  mrb_value lock;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &lock);


  /* Type checking */
  TODO_type_check_struct_PRLock_PTR(lock);


  /* Unbox parameters */
  struct PRLock * native_lock = TODO_mruby_unbox_struct_PRLock_PTR(lock);

  /* Invocation */
  PRCondVar * result = PR_NewCondVar(native_lock);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRCondVar_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_NewLock_FUNCTION
#define PR_NewLock_REQUIRED_ARGC 0
#define PR_NewLock_OPTIONAL_ARGC 0
/* PR_NewLock
 *
 * Parameters: None
 * Return Type: PRLock *
 */
mrb_value
mrb_NSPR_PR_NewLock(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRLock * result = PR_NewLock();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRLock_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_NewLogModule_FUNCTION
#define PR_NewLogModule_REQUIRED_ARGC 1
#define PR_NewLogModule_OPTIONAL_ARGC 0
/* PR_NewLogModule
 *
 * Parameters:
 * - name: const char *
 * Return Type: PRLogModuleInfo *
 */
mrb_value
mrb_NSPR_PR_NewLogModule(mrb_state* mrb, mrb_value self) {
  mrb_value name;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &name);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_name = mrb_string_value_cstr(mrb, &name);

  /* Invocation */
  PRLogModuleInfo * result = PR_NewLogModule(native_name);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRLogModuleInfo_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_NewMonitor_FUNCTION
#define PR_NewMonitor_REQUIRED_ARGC 0
#define PR_NewMonitor_OPTIONAL_ARGC 0
/* PR_NewMonitor
 *
 * Parameters: None
 * Return Type: PRMonitor *
 */
mrb_value
mrb_NSPR_PR_NewMonitor(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRMonitor * result = PR_NewMonitor();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRMonitor_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_NewPollableEvent_FUNCTION
#define PR_NewPollableEvent_REQUIRED_ARGC 0
#define PR_NewPollableEvent_OPTIONAL_ARGC 0
/* PR_NewPollableEvent
 *
 * Parameters: None
 * Return Type: PRFileDesc *
 */
mrb_value
mrb_NSPR_PR_NewPollableEvent(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRFileDesc * result = PR_NewPollableEvent();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRFileDesc_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_NewProcessAttr_FUNCTION
#define PR_NewProcessAttr_REQUIRED_ARGC 0
#define PR_NewProcessAttr_OPTIONAL_ARGC 0
/* PR_NewProcessAttr
 *
 * Parameters: None
 * Return Type: PRProcessAttr *
 */
mrb_value
mrb_NSPR_PR_NewProcessAttr(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRProcessAttr * result = PR_NewProcessAttr();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRProcessAttr_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_NewRWLock_FUNCTION
#define PR_NewRWLock_REQUIRED_ARGC 2
#define PR_NewRWLock_OPTIONAL_ARGC 0
/* PR_NewRWLock
 *
 * Parameters:
 * - lock_rank: unsigned int
 * - lock_name: const char *
 * Return Type: PRRWLock *
 */
mrb_value
mrb_NSPR_PR_NewRWLock(mrb_state* mrb, mrb_value self) {
  mrb_value lock_rank;
  mrb_value lock_name;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &lock_rank, &lock_name);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, lock_rank, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, lock_name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  unsigned int native_lock_rank = mrb_fixnum(lock_rank);

  const char * native_lock_name = mrb_string_value_cstr(mrb, &lock_name);

  /* Invocation */
  PRRWLock * result = PR_NewRWLock(native_lock_rank, native_lock_name);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRRWLock_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_NewTCPSocket_FUNCTION
#define PR_NewTCPSocket_REQUIRED_ARGC 0
#define PR_NewTCPSocket_OPTIONAL_ARGC 0
/* PR_NewTCPSocket
 *
 * Parameters: None
 * Return Type: PRFileDesc *
 */
mrb_value
mrb_NSPR_PR_NewTCPSocket(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRFileDesc * result = PR_NewTCPSocket();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRFileDesc_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_NewTCPSocketPair_FUNCTION
#define PR_NewTCPSocketPair_REQUIRED_ARGC 1
#define PR_NewTCPSocketPair_OPTIONAL_ARGC 0
/* PR_NewTCPSocketPair
 *
 * Parameters:
 * - fds: struct PRFileDesc *[2]
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_NewTCPSocketPair(mrb_state* mrb, mrb_value self) {
  mrb_value fds;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &fds);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR_[2](fds);


  /* Unbox parameters */
  struct PRFileDesc *[2] native_fds = TODO_mruby_unbox_struct_PRFileDesc_PTR_[2](fds);

  /* Invocation */
  PRStatus result = PR_NewTCPSocketPair(native_fds);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_NewThreadPrivateIndex_FUNCTION
#define PR_NewThreadPrivateIndex_REQUIRED_ARGC 2
#define PR_NewThreadPrivateIndex_OPTIONAL_ARGC 0
/* PR_NewThreadPrivateIndex
 *
 * Parameters:
 * - newIndex: unsigned int *
 * - destructor: void (*)(void *)
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_NewThreadPrivateIndex(mrb_state* mrb, mrb_value self) {
  mrb_value newIndex;
  mrb_value destructor;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &newIndex, &destructor);


  /* Type checking */
  TODO_type_check_unsigned_int_PTR(newIndex);
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(destructor);


  /* Unbox parameters */
  unsigned int * native_newIndex = TODO_mruby_unbox_unsigned_int_PTR(newIndex);

  void (*native_destructor)(void *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(destructor);

  /* Invocation */
  PRStatus result = PR_NewThreadPrivateIndex(native_newIndex, native_destructor);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_NewUDPSocket_FUNCTION
#define PR_NewUDPSocket_REQUIRED_ARGC 0
#define PR_NewUDPSocket_OPTIONAL_ARGC 0
/* PR_NewUDPSocket
 *
 * Parameters: None
 * Return Type: PRFileDesc *
 */
mrb_value
mrb_NSPR_PR_NewUDPSocket(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRFileDesc * result = PR_NewUDPSocket();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRFileDesc_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_NormalizeTime_FUNCTION
#define PR_NormalizeTime_REQUIRED_ARGC 2
#define PR_NormalizeTime_OPTIONAL_ARGC 0
/* PR_NormalizeTime
 *
 * Parameters:
 * - exploded: struct PRExplodedTime *
 * - params: struct PRTimeParameters (*)(const struct PRExplodedTime *)
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_NormalizeTime(mrb_state* mrb, mrb_value self) {
  mrb_value exploded;
  mrb_value params;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &exploded, &params);


  /* Type checking */
  TODO_type_check_struct_PRExplodedTime_PTR(exploded);
  TODO_type_check_struct_PRTimeParameters_LPAREN_PTR_RPAREN_LPAREN_const_struct_PRExplodedTime_PTR_RPAREN(params);


  /* Unbox parameters */
  struct PRExplodedTime * native_exploded = TODO_mruby_unbox_struct_PRExplodedTime_PTR(exploded);

  struct PRTimeParameters (*native_params)(const struct PRExplodedTime *) = TODO_mruby_unbox_struct_PRTimeParameters_LPAREN_PTR_RPAREN_LPAREN_const_struct_PRExplodedTime_PTR_RPAREN(params);

  /* Invocation */
  PR_NormalizeTime(native_exploded, native_params);

  return mrb_nil_value();
}
#endif

#if BIND_PR_Notify_FUNCTION
#define PR_Notify_REQUIRED_ARGC 1
#define PR_Notify_OPTIONAL_ARGC 0
/* PR_Notify
 *
 * Parameters:
 * - mon: struct PRMonitor *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_Notify(mrb_state* mrb, mrb_value self) {
  mrb_value mon;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &mon);


  /* Type checking */
  TODO_type_check_struct_PRMonitor_PTR(mon);


  /* Unbox parameters */
  struct PRMonitor * native_mon = TODO_mruby_unbox_struct_PRMonitor_PTR(mon);

  /* Invocation */
  PRStatus result = PR_Notify(native_mon);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_NotifyAll_FUNCTION
#define PR_NotifyAll_REQUIRED_ARGC 1
#define PR_NotifyAll_OPTIONAL_ARGC 0
/* PR_NotifyAll
 *
 * Parameters:
 * - mon: struct PRMonitor *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_NotifyAll(mrb_state* mrb, mrb_value self) {
  mrb_value mon;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &mon);


  /* Type checking */
  TODO_type_check_struct_PRMonitor_PTR(mon);


  /* Unbox parameters */
  struct PRMonitor * native_mon = TODO_mruby_unbox_struct_PRMonitor_PTR(mon);

  /* Invocation */
  PRStatus result = PR_NotifyAll(native_mon);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_NotifyAllCondVar_FUNCTION
#define PR_NotifyAllCondVar_REQUIRED_ARGC 1
#define PR_NotifyAllCondVar_OPTIONAL_ARGC 0
/* PR_NotifyAllCondVar
 *
 * Parameters:
 * - cvar: struct PRCondVar *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_NotifyAllCondVar(mrb_state* mrb, mrb_value self) {
  mrb_value cvar;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &cvar);


  /* Type checking */
  TODO_type_check_struct_PRCondVar_PTR(cvar);


  /* Unbox parameters */
  struct PRCondVar * native_cvar = TODO_mruby_unbox_struct_PRCondVar_PTR(cvar);

  /* Invocation */
  PRStatus result = PR_NotifyAllCondVar(native_cvar);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_NotifyCondVar_FUNCTION
#define PR_NotifyCondVar_REQUIRED_ARGC 1
#define PR_NotifyCondVar_OPTIONAL_ARGC 0
/* PR_NotifyCondVar
 *
 * Parameters:
 * - cvar: struct PRCondVar *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_NotifyCondVar(mrb_state* mrb, mrb_value self) {
  mrb_value cvar;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &cvar);


  /* Type checking */
  TODO_type_check_struct_PRCondVar_PTR(cvar);


  /* Unbox parameters */
  struct PRCondVar * native_cvar = TODO_mruby_unbox_struct_PRCondVar_PTR(cvar);

  /* Invocation */
  PRStatus result = PR_NotifyCondVar(native_cvar);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_Now_FUNCTION
#define PR_Now_REQUIRED_ARGC 0
#define PR_Now_OPTIONAL_ARGC 0
/* PR_Now
 *
 * Parameters: None
 * Return Type: PRTime
 */
mrb_value
mrb_NSPR_PR_Now(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRTime result = PR_Now();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_long_long(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_ntohl_FUNCTION
#define PR_ntohl_REQUIRED_ARGC 1
#define PR_ntohl_OPTIONAL_ARGC 0
/* PR_ntohl
 *
 * Parameters:
 * - arg1: unsigned int
 * Return Type: PRUint32
 */
mrb_value
mrb_NSPR_PR_ntohl(mrb_state* mrb, mrb_value self) {
  mrb_value arg1;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &arg1);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, arg1, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  unsigned int native_arg1 = mrb_fixnum(arg1);

  /* Invocation */
  PRUint32 result = PR_ntohl(native_arg1);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_ntohll_FUNCTION
#define PR_ntohll_REQUIRED_ARGC 1
#define PR_ntohll_OPTIONAL_ARGC 0
/* PR_ntohll
 *
 * Parameters:
 * - arg1: unsigned long long
 * Return Type: PRUint64
 */
mrb_value
mrb_NSPR_PR_ntohll(mrb_state* mrb, mrb_value self) {
  mrb_value arg1;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &arg1);


  /* Type checking */
  TODO_type_check_unsigned_long_long(arg1);


  /* Unbox parameters */
  unsigned long long native_arg1 = TODO_mruby_unbox_unsigned_long_long(arg1);

  /* Invocation */
  PRUint64 result = PR_ntohll(native_arg1);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_unsigned_long_long(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_ntohs_FUNCTION
#define PR_ntohs_REQUIRED_ARGC 1
#define PR_ntohs_OPTIONAL_ARGC 0
/* PR_ntohs
 *
 * Parameters:
 * - arg1: unsigned short
 * Return Type: PRUint16
 */
mrb_value
mrb_NSPR_PR_ntohs(mrb_state* mrb, mrb_value self) {
  mrb_value arg1;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &arg1);


  /* Type checking */
  TODO_type_check_unsigned_short(arg1);


  /* Unbox parameters */
  unsigned short native_arg1 = TODO_mruby_unbox_unsigned_short(arg1);

  /* Invocation */
  PRUint16 result = PR_ntohs(native_arg1);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_unsigned_short(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_Open_FUNCTION
#define PR_Open_REQUIRED_ARGC 3
#define PR_Open_OPTIONAL_ARGC 0
/* PR_Open
 *
 * Parameters:
 * - name: const char *
 * - flags: int
 * - mode: int
 * Return Type: PRFileDesc *
 */
mrb_value
mrb_NSPR_PR_Open(mrb_state* mrb, mrb_value self) {
  mrb_value name;
  mrb_value flags;
  mrb_value mode;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &name, &flags, &mode);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, mode, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_name = mrb_string_value_cstr(mrb, &name);

  int native_flags = mrb_fixnum(flags);

  int native_mode = mrb_fixnum(mode);

  /* Invocation */
  PRFileDesc * result = PR_Open(native_name, native_flags, native_mode);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRFileDesc_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_OpenAnonFileMap_FUNCTION
#define PR_OpenAnonFileMap_REQUIRED_ARGC 3
#define PR_OpenAnonFileMap_OPTIONAL_ARGC 0
/* PR_OpenAnonFileMap
 *
 * Parameters:
 * - dirName: const char *
 * - size: unsigned long
 * - prot: enum PRFileMapProtect
 * Return Type: PRFileMap *
 */
mrb_value
mrb_NSPR_PR_OpenAnonFileMap(mrb_state* mrb, mrb_value self) {
  mrb_value dirName;
  mrb_value size;
  mrb_value prot;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &dirName, &size, &prot);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, dirName, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_unsigned_long(size);
  TODO_type_check_enum_PRFileMapProtect(prot);


  /* Unbox parameters */
  const char * native_dirName = mrb_string_value_cstr(mrb, &dirName);

  unsigned long native_size = TODO_mruby_unbox_unsigned_long(size);

  enum PRFileMapProtect native_prot = TODO_mruby_unbox_enum_PRFileMapProtect(prot);

  /* Invocation */
  PRFileMap * result = PR_OpenAnonFileMap(native_dirName, native_size, native_prot);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRFileMap_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_OpenDir_FUNCTION
#define PR_OpenDir_REQUIRED_ARGC 1
#define PR_OpenDir_OPTIONAL_ARGC 0
/* PR_OpenDir
 *
 * Parameters:
 * - name: const char *
 * Return Type: PRDir *
 */
mrb_value
mrb_NSPR_PR_OpenDir(mrb_state* mrb, mrb_value self) {
  mrb_value name;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &name);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_name = mrb_string_value_cstr(mrb, &name);

  /* Invocation */
  PRDir * result = PR_OpenDir(native_name);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRDir_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_OpenFile_FUNCTION
#define PR_OpenFile_REQUIRED_ARGC 3
#define PR_OpenFile_OPTIONAL_ARGC 0
/* PR_OpenFile
 *
 * Parameters:
 * - name: const char *
 * - flags: int
 * - mode: int
 * Return Type: PRFileDesc *
 */
mrb_value
mrb_NSPR_PR_OpenFile(mrb_state* mrb, mrb_value self) {
  mrb_value name;
  mrb_value flags;
  mrb_value mode;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &name, &flags, &mode);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, mode, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_name = mrb_string_value_cstr(mrb, &name);

  int native_flags = mrb_fixnum(flags);

  int native_mode = mrb_fixnum(mode);

  /* Invocation */
  PRFileDesc * result = PR_OpenFile(native_name, native_flags, native_mode);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRFileDesc_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_OpenSemaphore_FUNCTION
#define PR_OpenSemaphore_REQUIRED_ARGC 4
#define PR_OpenSemaphore_OPTIONAL_ARGC 0
/* PR_OpenSemaphore
 *
 * Parameters:
 * - name: const char *
 * - flags: int
 * - mode: int
 * - value: unsigned int
 * Return Type: PRSem *
 */
mrb_value
mrb_NSPR_PR_OpenSemaphore(mrb_state* mrb, mrb_value self) {
  mrb_value name;
  mrb_value flags;
  mrb_value mode;
  mrb_value value;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &name, &flags, &mode, &value);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, mode, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, value, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_name = mrb_string_value_cstr(mrb, &name);

  int native_flags = mrb_fixnum(flags);

  int native_mode = mrb_fixnum(mode);

  unsigned int native_value = mrb_fixnum(value);

  /* Invocation */
  PRSem * result = PR_OpenSemaphore(native_name, native_flags, native_mode, native_value);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRSem_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_OpenSharedMemory_FUNCTION
#define PR_OpenSharedMemory_REQUIRED_ARGC 4
#define PR_OpenSharedMemory_OPTIONAL_ARGC 0
/* PR_OpenSharedMemory
 *
 * Parameters:
 * - name: const char *
 * - size: unsigned long
 * - flags: int
 * - mode: int
 * Return Type: PRSharedMemory *
 */
mrb_value
mrb_NSPR_PR_OpenSharedMemory(mrb_state* mrb, mrb_value self) {
  mrb_value name;
  mrb_value size;
  mrb_value flags;
  mrb_value mode;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &name, &size, &flags, &mode);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_unsigned_long(size);
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, mode, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_name = mrb_string_value_cstr(mrb, &name);

  unsigned long native_size = TODO_mruby_unbox_unsigned_long(size);

  int native_flags = mrb_fixnum(flags);

  int native_mode = mrb_fixnum(mode);

  /* Invocation */
  PRSharedMemory * result = PR_OpenSharedMemory(native_name, native_size, native_flags, native_mode);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRSharedMemory_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_OpenTCPSocket_FUNCTION
#define PR_OpenTCPSocket_REQUIRED_ARGC 1
#define PR_OpenTCPSocket_OPTIONAL_ARGC 0
/* PR_OpenTCPSocket
 *
 * Parameters:
 * - af: int
 * Return Type: PRFileDesc *
 */
mrb_value
mrb_NSPR_PR_OpenTCPSocket(mrb_state* mrb, mrb_value self) {
  mrb_value af;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &af);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, af, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_af = mrb_fixnum(af);

  /* Invocation */
  PRFileDesc * result = PR_OpenTCPSocket(native_af);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRFileDesc_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_OpenUDPSocket_FUNCTION
#define PR_OpenUDPSocket_REQUIRED_ARGC 1
#define PR_OpenUDPSocket_OPTIONAL_ARGC 0
/* PR_OpenUDPSocket
 *
 * Parameters:
 * - af: int
 * Return Type: PRFileDesc *
 */
mrb_value
mrb_NSPR_PR_OpenUDPSocket(mrb_state* mrb, mrb_value self) {
  mrb_value af;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &af);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, af, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_af = mrb_fixnum(af);

  /* Invocation */
  PRFileDesc * result = PR_OpenUDPSocket(native_af);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRFileDesc_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_ParseTimeString_FUNCTION
#define PR_ParseTimeString_REQUIRED_ARGC 3
#define PR_ParseTimeString_OPTIONAL_ARGC 0
/* PR_ParseTimeString
 *
 * Parameters:
 * - string: const char *
 * - default_to_gmt: int
 * - result: long long *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_ParseTimeString(mrb_state* mrb, mrb_value self) {
  mrb_value string;
  mrb_value default_to_gmt;
  mrb_value result;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &string, &default_to_gmt, &result);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, string, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, default_to_gmt, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_long_long_PTR(result);


  /* Unbox parameters */
  const char * native_string = mrb_string_value_cstr(mrb, &string);

  int native_default_to_gmt = mrb_fixnum(default_to_gmt);

  long long * native_result = TODO_mruby_unbox_long_long_PTR(result);

  /* Invocation */
  PRStatus result = PR_ParseTimeString(native_string, native_default_to_gmt, native_result);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_ParseTimeStringToExplodedTime_FUNCTION
#define PR_ParseTimeStringToExplodedTime_REQUIRED_ARGC 3
#define PR_ParseTimeStringToExplodedTime_OPTIONAL_ARGC 0
/* PR_ParseTimeStringToExplodedTime
 *
 * Parameters:
 * - string: const char *
 * - default_to_gmt: int
 * - result: struct PRExplodedTime *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_ParseTimeStringToExplodedTime(mrb_state* mrb, mrb_value self) {
  mrb_value string;
  mrb_value default_to_gmt;
  mrb_value result;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &string, &default_to_gmt, &result);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, string, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, default_to_gmt, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct_PRExplodedTime_PTR(result);


  /* Unbox parameters */
  const char * native_string = mrb_string_value_cstr(mrb, &string);

  int native_default_to_gmt = mrb_fixnum(default_to_gmt);

  struct PRExplodedTime * native_result = TODO_mruby_unbox_struct_PRExplodedTime_PTR(result);

  /* Invocation */
  PRStatus result = PR_ParseTimeStringToExplodedTime(native_string, native_default_to_gmt, native_result);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_Poll_FUNCTION
#define PR_Poll_REQUIRED_ARGC 3
#define PR_Poll_OPTIONAL_ARGC 0
/* PR_Poll
 *
 * Parameters:
 * - pds: struct PRPollDesc *
 * - npds: int
 * - timeout: unsigned int
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_Poll(mrb_state* mrb, mrb_value self) {
  mrb_value pds;
  mrb_value npds;
  mrb_value timeout;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &pds, &npds, &timeout);


  /* Type checking */
  TODO_type_check_struct_PRPollDesc_PTR(pds);
  if (!mrb_obj_is_kind_of(mrb, npds, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRPollDesc * native_pds = TODO_mruby_unbox_struct_PRPollDesc_PTR(pds);

  int native_npds = mrb_fixnum(npds);

  unsigned int native_timeout = mrb_fixnum(timeout);

  /* Invocation */
  PRInt32 result = PR_Poll(native_pds, native_npds, native_timeout);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_PopIOLayer_FUNCTION
#define PR_PopIOLayer_REQUIRED_ARGC 2
#define PR_PopIOLayer_OPTIONAL_ARGC 0
/* PR_PopIOLayer
 *
 * Parameters:
 * - fd_stack: struct PRFileDesc *
 * - id: int
 * Return Type: PRFileDesc *
 */
mrb_value
mrb_NSPR_PR_PopIOLayer(mrb_state* mrb, mrb_value self) {
  mrb_value fd_stack;
  mrb_value id;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &fd_stack, &id);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd_stack);
  if (!mrb_obj_is_kind_of(mrb, id, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRFileDesc * native_fd_stack = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd_stack);

  int native_id = mrb_fixnum(id);

  /* Invocation */
  PRFileDesc * result = PR_PopIOLayer(native_fd_stack, native_id);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRFileDesc_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_PostSemaphore_FUNCTION
#define PR_PostSemaphore_REQUIRED_ARGC 1
#define PR_PostSemaphore_OPTIONAL_ARGC 0
/* PR_PostSemaphore
 *
 * Parameters:
 * - sem: struct PRSem *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_PostSemaphore(mrb_state* mrb, mrb_value self) {
  mrb_value sem;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &sem);


  /* Type checking */
  TODO_type_check_struct_PRSem_PTR(sem);


  /* Unbox parameters */
  struct PRSem * native_sem = TODO_mruby_unbox_struct_PRSem_PTR(sem);

  /* Invocation */
  PRStatus result = PR_PostSemaphore(native_sem);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_ProcessAttrSetCurrentDirectory_FUNCTION
#define PR_ProcessAttrSetCurrentDirectory_REQUIRED_ARGC 2
#define PR_ProcessAttrSetCurrentDirectory_OPTIONAL_ARGC 0
/* PR_ProcessAttrSetCurrentDirectory
 *
 * Parameters:
 * - attr: struct PRProcessAttr *
 * - dir: const char *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_ProcessAttrSetCurrentDirectory(mrb_state* mrb, mrb_value self) {
  mrb_value attr;
  mrb_value dir;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &attr, &dir);


  /* Type checking */
  TODO_type_check_struct_PRProcessAttr_PTR(attr);
  if (!mrb_obj_is_kind_of(mrb, dir, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRProcessAttr * native_attr = TODO_mruby_unbox_struct_PRProcessAttr_PTR(attr);

  const char * native_dir = mrb_string_value_cstr(mrb, &dir);

  /* Invocation */
  PRStatus result = PR_ProcessAttrSetCurrentDirectory(native_attr, native_dir);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_ProcessAttrSetInheritableFD_FUNCTION
#define PR_ProcessAttrSetInheritableFD_REQUIRED_ARGC 3
#define PR_ProcessAttrSetInheritableFD_OPTIONAL_ARGC 0
/* PR_ProcessAttrSetInheritableFD
 *
 * Parameters:
 * - attr: struct PRProcessAttr *
 * - fd: struct PRFileDesc *
 * - name: const char *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_ProcessAttrSetInheritableFD(mrb_state* mrb, mrb_value self) {
  mrb_value attr;
  mrb_value fd;
  mrb_value name;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &attr, &fd, &name);


  /* Type checking */
  TODO_type_check_struct_PRProcessAttr_PTR(attr);
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRProcessAttr * native_attr = TODO_mruby_unbox_struct_PRProcessAttr_PTR(attr);

  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  const char * native_name = mrb_string_value_cstr(mrb, &name);

  /* Invocation */
  PRStatus result = PR_ProcessAttrSetInheritableFD(native_attr, native_fd, native_name);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_ProcessAttrSetInheritableFileMap_FUNCTION
#define PR_ProcessAttrSetInheritableFileMap_REQUIRED_ARGC 3
#define PR_ProcessAttrSetInheritableFileMap_OPTIONAL_ARGC 0
/* PR_ProcessAttrSetInheritableFileMap
 *
 * Parameters:
 * - attr: struct PRProcessAttr *
 * - fm: struct PRFileMap *
 * - shmname: const char *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_ProcessAttrSetInheritableFileMap(mrb_state* mrb, mrb_value self) {
  mrb_value attr;
  mrb_value fm;
  mrb_value shmname;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &attr, &fm, &shmname);


  /* Type checking */
  TODO_type_check_struct_PRProcessAttr_PTR(attr);
  TODO_type_check_struct_PRFileMap_PTR(fm);
  if (!mrb_obj_is_kind_of(mrb, shmname, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRProcessAttr * native_attr = TODO_mruby_unbox_struct_PRProcessAttr_PTR(attr);

  struct PRFileMap * native_fm = TODO_mruby_unbox_struct_PRFileMap_PTR(fm);

  const char * native_shmname = mrb_string_value_cstr(mrb, &shmname);

  /* Invocation */
  PRStatus result = PR_ProcessAttrSetInheritableFileMap(native_attr, native_fm, native_shmname);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_ProcessAttrSetStdioRedirect_FUNCTION
#define PR_ProcessAttrSetStdioRedirect_REQUIRED_ARGC 3
#define PR_ProcessAttrSetStdioRedirect_OPTIONAL_ARGC 0
/* PR_ProcessAttrSetStdioRedirect
 *
 * Parameters:
 * - attr: struct PRProcessAttr *
 * - stdioFd: enum PRSpecialFD
 * - redirectFd: struct PRFileDesc *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_ProcessAttrSetStdioRedirect(mrb_state* mrb, mrb_value self) {
  mrb_value attr;
  mrb_value stdioFd;
  mrb_value redirectFd;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &attr, &stdioFd, &redirectFd);


  /* Type checking */
  TODO_type_check_struct_PRProcessAttr_PTR(attr);
  TODO_type_check_enum_PRSpecialFD(stdioFd);
  TODO_type_check_struct_PRFileDesc_PTR(redirectFd);


  /* Unbox parameters */
  struct PRProcessAttr * native_attr = TODO_mruby_unbox_struct_PRProcessAttr_PTR(attr);

  enum PRSpecialFD native_stdioFd = TODO_mruby_unbox_enum_PRSpecialFD(stdioFd);

  struct PRFileDesc * native_redirectFd = TODO_mruby_unbox_struct_PRFileDesc_PTR(redirectFd);

  /* Invocation */
  PR_ProcessAttrSetStdioRedirect(native_attr, native_stdioFd, native_redirectFd);

  return mrb_nil_value();
}
#endif

#if BIND_PR_ProcessExit_FUNCTION
#define PR_ProcessExit_REQUIRED_ARGC 1
#define PR_ProcessExit_OPTIONAL_ARGC 0
/* PR_ProcessExit
 *
 * Parameters:
 * - status: int
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_ProcessExit(mrb_state* mrb, mrb_value self) {
  mrb_value status;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &status);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, status, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_status = mrb_fixnum(status);

  /* Invocation */
  PR_ProcessExit(native_status);

  return mrb_nil_value();
}
#endif

#if BIND_PR_PushIOLayer_FUNCTION
#define PR_PushIOLayer_REQUIRED_ARGC 3
#define PR_PushIOLayer_OPTIONAL_ARGC 0
/* PR_PushIOLayer
 *
 * Parameters:
 * - fd_stack: struct PRFileDesc *
 * - id: int
 * - layer: struct PRFileDesc *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_PushIOLayer(mrb_state* mrb, mrb_value self) {
  mrb_value fd_stack;
  mrb_value id;
  mrb_value layer;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &fd_stack, &id, &layer);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd_stack);
  if (!mrb_obj_is_kind_of(mrb, id, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct_PRFileDesc_PTR(layer);


  /* Unbox parameters */
  struct PRFileDesc * native_fd_stack = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd_stack);

  int native_id = mrb_fixnum(id);

  struct PRFileDesc * native_layer = TODO_mruby_unbox_struct_PRFileDesc_PTR(layer);

  /* Invocation */
  PRStatus result = PR_PushIOLayer(native_fd_stack, native_id, native_layer);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_QueueJob_FUNCTION
#define PR_QueueJob_REQUIRED_ARGC 4
#define PR_QueueJob_OPTIONAL_ARGC 0
/* PR_QueueJob
 *
 * Parameters:
 * - tpool: struct PRThreadPool *
 * - fn: void (*)(void *)
 * - arg: void *
 * - joinable: int
 * Return Type: PRJob *
 */
mrb_value
mrb_NSPR_PR_QueueJob(mrb_state* mrb, mrb_value self) {
  mrb_value tpool;
  mrb_value fn;
  mrb_value arg;
  mrb_value joinable;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &tpool, &fn, &arg, &joinable);


  /* Type checking */
  TODO_type_check_struct_PRThreadPool_PTR(tpool);
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(fn);
  TODO_type_check_void_PTR(arg);
  if (!mrb_obj_is_kind_of(mrb, joinable, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRThreadPool * native_tpool = TODO_mruby_unbox_struct_PRThreadPool_PTR(tpool);

  void (*native_fn)(void *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(fn);

  void * native_arg = TODO_mruby_unbox_void_PTR(arg);

  int native_joinable = mrb_fixnum(joinable);

  /* Invocation */
  PRJob * result = PR_QueueJob(native_tpool, native_fn, native_arg, native_joinable);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRJob_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_QueueJob_Accept_FUNCTION
#define PR_QueueJob_Accept_REQUIRED_ARGC 5
#define PR_QueueJob_Accept_OPTIONAL_ARGC 0
/* PR_QueueJob_Accept
 *
 * Parameters:
 * - tpool: struct PRThreadPool *
 * - iod: struct PRJobIoDesc *
 * - fn: void (*)(void *)
 * - arg: void *
 * - joinable: int
 * Return Type: PRJob *
 */
mrb_value
mrb_NSPR_PR_QueueJob_Accept(mrb_state* mrb, mrb_value self) {
  mrb_value tpool;
  mrb_value iod;
  mrb_value fn;
  mrb_value arg;
  mrb_value joinable;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &tpool, &iod, &fn, &arg, &joinable);


  /* Type checking */
  TODO_type_check_struct_PRThreadPool_PTR(tpool);
  TODO_type_check_struct_PRJobIoDesc_PTR(iod);
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(fn);
  TODO_type_check_void_PTR(arg);
  if (!mrb_obj_is_kind_of(mrb, joinable, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRThreadPool * native_tpool = TODO_mruby_unbox_struct_PRThreadPool_PTR(tpool);

  struct PRJobIoDesc * native_iod = TODO_mruby_unbox_struct_PRJobIoDesc_PTR(iod);

  void (*native_fn)(void *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(fn);

  void * native_arg = TODO_mruby_unbox_void_PTR(arg);

  int native_joinable = mrb_fixnum(joinable);

  /* Invocation */
  PRJob * result = PR_QueueJob_Accept(native_tpool, native_iod, native_fn, native_arg, native_joinable);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRJob_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_QueueJob_Connect_FUNCTION
#define PR_QueueJob_Connect_REQUIRED_ARGC 6
#define PR_QueueJob_Connect_OPTIONAL_ARGC 0
/* PR_QueueJob_Connect
 *
 * Parameters:
 * - tpool: struct PRThreadPool *
 * - iod: struct PRJobIoDesc *
 * - addr: const union PRNetAddr *
 * - fn: void (*)(void *)
 * - arg: void *
 * - joinable: int
 * Return Type: PRJob *
 */
mrb_value
mrb_NSPR_PR_QueueJob_Connect(mrb_state* mrb, mrb_value self) {
  mrb_value tpool;
  mrb_value iod;
  mrb_value addr;
  mrb_value fn;
  mrb_value arg;
  mrb_value joinable;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooo", &tpool, &iod, &addr, &fn, &arg, &joinable);


  /* Type checking */
  TODO_type_check_struct_PRThreadPool_PTR(tpool);
  TODO_type_check_struct_PRJobIoDesc_PTR(iod);
  TODO_type_check_const_union_PRNetAddr_PTR(addr);
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(fn);
  TODO_type_check_void_PTR(arg);
  if (!mrb_obj_is_kind_of(mrb, joinable, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRThreadPool * native_tpool = TODO_mruby_unbox_struct_PRThreadPool_PTR(tpool);

  struct PRJobIoDesc * native_iod = TODO_mruby_unbox_struct_PRJobIoDesc_PTR(iod);

  const union PRNetAddr * native_addr = TODO_mruby_unbox_const_union_PRNetAddr_PTR(addr);

  void (*native_fn)(void *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(fn);

  void * native_arg = TODO_mruby_unbox_void_PTR(arg);

  int native_joinable = mrb_fixnum(joinable);

  /* Invocation */
  PRJob * result = PR_QueueJob_Connect(native_tpool, native_iod, native_addr, native_fn, native_arg, native_joinable);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRJob_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_QueueJob_Read_FUNCTION
#define PR_QueueJob_Read_REQUIRED_ARGC 5
#define PR_QueueJob_Read_OPTIONAL_ARGC 0
/* PR_QueueJob_Read
 *
 * Parameters:
 * - tpool: struct PRThreadPool *
 * - iod: struct PRJobIoDesc *
 * - fn: void (*)(void *)
 * - arg: void *
 * - joinable: int
 * Return Type: PRJob *
 */
mrb_value
mrb_NSPR_PR_QueueJob_Read(mrb_state* mrb, mrb_value self) {
  mrb_value tpool;
  mrb_value iod;
  mrb_value fn;
  mrb_value arg;
  mrb_value joinable;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &tpool, &iod, &fn, &arg, &joinable);


  /* Type checking */
  TODO_type_check_struct_PRThreadPool_PTR(tpool);
  TODO_type_check_struct_PRJobIoDesc_PTR(iod);
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(fn);
  TODO_type_check_void_PTR(arg);
  if (!mrb_obj_is_kind_of(mrb, joinable, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRThreadPool * native_tpool = TODO_mruby_unbox_struct_PRThreadPool_PTR(tpool);

  struct PRJobIoDesc * native_iod = TODO_mruby_unbox_struct_PRJobIoDesc_PTR(iod);

  void (*native_fn)(void *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(fn);

  void * native_arg = TODO_mruby_unbox_void_PTR(arg);

  int native_joinable = mrb_fixnum(joinable);

  /* Invocation */
  PRJob * result = PR_QueueJob_Read(native_tpool, native_iod, native_fn, native_arg, native_joinable);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRJob_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_QueueJob_Timer_FUNCTION
#define PR_QueueJob_Timer_REQUIRED_ARGC 5
#define PR_QueueJob_Timer_OPTIONAL_ARGC 0
/* PR_QueueJob_Timer
 *
 * Parameters:
 * - tpool: struct PRThreadPool *
 * - timeout: unsigned int
 * - fn: void (*)(void *)
 * - arg: void *
 * - joinable: int
 * Return Type: PRJob *
 */
mrb_value
mrb_NSPR_PR_QueueJob_Timer(mrb_state* mrb, mrb_value self) {
  mrb_value tpool;
  mrb_value timeout;
  mrb_value fn;
  mrb_value arg;
  mrb_value joinable;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &tpool, &timeout, &fn, &arg, &joinable);


  /* Type checking */
  TODO_type_check_struct_PRThreadPool_PTR(tpool);
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(fn);
  TODO_type_check_void_PTR(arg);
  if (!mrb_obj_is_kind_of(mrb, joinable, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRThreadPool * native_tpool = TODO_mruby_unbox_struct_PRThreadPool_PTR(tpool);

  unsigned int native_timeout = mrb_fixnum(timeout);

  void (*native_fn)(void *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(fn);

  void * native_arg = TODO_mruby_unbox_void_PTR(arg);

  int native_joinable = mrb_fixnum(joinable);

  /* Invocation */
  PRJob * result = PR_QueueJob_Timer(native_tpool, native_timeout, native_fn, native_arg, native_joinable);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRJob_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_QueueJob_Write_FUNCTION
#define PR_QueueJob_Write_REQUIRED_ARGC 5
#define PR_QueueJob_Write_OPTIONAL_ARGC 0
/* PR_QueueJob_Write
 *
 * Parameters:
 * - tpool: struct PRThreadPool *
 * - iod: struct PRJobIoDesc *
 * - fn: void (*)(void *)
 * - arg: void *
 * - joinable: int
 * Return Type: PRJob *
 */
mrb_value
mrb_NSPR_PR_QueueJob_Write(mrb_state* mrb, mrb_value self) {
  mrb_value tpool;
  mrb_value iod;
  mrb_value fn;
  mrb_value arg;
  mrb_value joinable;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &tpool, &iod, &fn, &arg, &joinable);


  /* Type checking */
  TODO_type_check_struct_PRThreadPool_PTR(tpool);
  TODO_type_check_struct_PRJobIoDesc_PTR(iod);
  TODO_type_check_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(fn);
  TODO_type_check_void_PTR(arg);
  if (!mrb_obj_is_kind_of(mrb, joinable, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRThreadPool * native_tpool = TODO_mruby_unbox_struct_PRThreadPool_PTR(tpool);

  struct PRJobIoDesc * native_iod = TODO_mruby_unbox_struct_PRJobIoDesc_PTR(iod);

  void (*native_fn)(void *) = TODO_mruby_unbox_void_LPAREN_PTR_RPAREN_LPAREN_void_PTR_RPAREN(fn);

  void * native_arg = TODO_mruby_unbox_void_PTR(arg);

  int native_joinable = mrb_fixnum(joinable);

  /* Invocation */
  PRJob * result = PR_QueueJob_Write(native_tpool, native_iod, native_fn, native_arg, native_joinable);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRJob_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_Read_FUNCTION
#define PR_Read_REQUIRED_ARGC 3
#define PR_Read_OPTIONAL_ARGC 0
/* PR_Read
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - buf: void *
 * - amount: int
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_Read(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value buf;
  mrb_value amount;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &fd, &buf, &amount);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_void_PTR(buf);
  if (!mrb_obj_is_kind_of(mrb, amount, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  void * native_buf = TODO_mruby_unbox_void_PTR(buf);

  int native_amount = mrb_fixnum(amount);

  /* Invocation */
  PRInt32 result = PR_Read(native_fd, native_buf, native_amount);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_ReadDir_FUNCTION
#define PR_ReadDir_REQUIRED_ARGC 2
#define PR_ReadDir_OPTIONAL_ARGC 0
/* PR_ReadDir
 *
 * Parameters:
 * - dir: struct PRDir *
 * - flags: enum PRDirFlags
 * Return Type: PRDirEntry *
 */
mrb_value
mrb_NSPR_PR_ReadDir(mrb_state* mrb, mrb_value self) {
  mrb_value dir;
  mrb_value flags;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &dir, &flags);


  /* Type checking */
  TODO_type_check_struct_PRDir_PTR(dir);
  TODO_type_check_enum_PRDirFlags(flags);


  /* Unbox parameters */
  struct PRDir * native_dir = TODO_mruby_unbox_struct_PRDir_PTR(dir);

  enum PRDirFlags native_flags = TODO_mruby_unbox_enum_PRDirFlags(flags);

  /* Invocation */
  PRDirEntry * result = PR_ReadDir(native_dir, native_flags);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRDirEntry_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_Realloc_FUNCTION
#define PR_Realloc_REQUIRED_ARGC 2
#define PR_Realloc_OPTIONAL_ARGC 0
/* PR_Realloc
 *
 * Parameters:
 * - ptr: void *
 * - size: unsigned int
 * Return Type: void *
 */
mrb_value
mrb_NSPR_PR_Realloc(mrb_state* mrb, mrb_value self) {
  mrb_value ptr;
  mrb_value size;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &ptr, &size);


  /* Type checking */
  TODO_type_check_void_PTR(ptr);
  if (!mrb_obj_is_kind_of(mrb, size, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void * native_ptr = TODO_mruby_unbox_void_PTR(ptr);

  unsigned int native_size = mrb_fixnum(size);

  /* Invocation */
  void * result = PR_Realloc(native_ptr, native_size);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_void_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_RecordTraceEntries_FUNCTION
#define PR_RecordTraceEntries_REQUIRED_ARGC 0
#define PR_RecordTraceEntries_OPTIONAL_ARGC 0
/* PR_RecordTraceEntries
 *
 * Parameters: None
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_RecordTraceEntries(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PR_RecordTraceEntries();

  return mrb_nil_value();
}
#endif

#if BIND_PR_Recv_FUNCTION
#define PR_Recv_REQUIRED_ARGC 5
#define PR_Recv_OPTIONAL_ARGC 0
/* PR_Recv
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - buf: void *
 * - amount: int
 * - flags: int
 * - timeout: unsigned int
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_Recv(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value buf;
  mrb_value amount;
  mrb_value flags;
  mrb_value timeout;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &fd, &buf, &amount, &flags, &timeout);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_void_PTR(buf);
  if (!mrb_obj_is_kind_of(mrb, amount, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  void * native_buf = TODO_mruby_unbox_void_PTR(buf);

  int native_amount = mrb_fixnum(amount);

  int native_flags = mrb_fixnum(flags);

  unsigned int native_timeout = mrb_fixnum(timeout);

  /* Invocation */
  PRInt32 result = PR_Recv(native_fd, native_buf, native_amount, native_flags, native_timeout);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_RecvFrom_FUNCTION
#define PR_RecvFrom_REQUIRED_ARGC 6
#define PR_RecvFrom_OPTIONAL_ARGC 0
/* PR_RecvFrom
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - buf: void *
 * - amount: int
 * - flags: int
 * - addr: union PRNetAddr *
 * - timeout: unsigned int
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_RecvFrom(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value buf;
  mrb_value amount;
  mrb_value flags;
  mrb_value addr;
  mrb_value timeout;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooo", &fd, &buf, &amount, &flags, &addr, &timeout);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_void_PTR(buf);
  if (!mrb_obj_is_kind_of(mrb, amount, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_union_PRNetAddr_PTR(addr);
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  void * native_buf = TODO_mruby_unbox_void_PTR(buf);

  int native_amount = mrb_fixnum(amount);

  int native_flags = mrb_fixnum(flags);

  union PRNetAddr * native_addr = TODO_mruby_unbox_union_PRNetAddr_PTR(addr);

  unsigned int native_timeout = mrb_fixnum(timeout);

  /* Invocation */
  PRInt32 result = PR_RecvFrom(native_fd, native_buf, native_amount, native_flags, native_addr, native_timeout);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_Rename_FUNCTION
#define PR_Rename_REQUIRED_ARGC 2
#define PR_Rename_OPTIONAL_ARGC 0
/* PR_Rename
 *
 * Parameters:
 * - from: const char *
 * - to: const char *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_Rename(mrb_state* mrb, mrb_value self) {
  mrb_value from;
  mrb_value to;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &from, &to);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, from, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, to, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_from = mrb_string_value_cstr(mrb, &from);

  const char * native_to = mrb_string_value_cstr(mrb, &to);

  /* Invocation */
  PRStatus result = PR_Rename(native_from, native_to);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_ResetProcessAttr_FUNCTION
#define PR_ResetProcessAttr_REQUIRED_ARGC 1
#define PR_ResetProcessAttr_OPTIONAL_ARGC 0
/* PR_ResetProcessAttr
 *
 * Parameters:
 * - attr: struct PRProcessAttr *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_ResetProcessAttr(mrb_state* mrb, mrb_value self) {
  mrb_value attr;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &attr);


  /* Type checking */
  TODO_type_check_struct_PRProcessAttr_PTR(attr);


  /* Unbox parameters */
  struct PRProcessAttr * native_attr = TODO_mruby_unbox_struct_PRProcessAttr_PTR(attr);

  /* Invocation */
  PR_ResetProcessAttr(native_attr);

  return mrb_nil_value();
}
#endif

#if BIND_PR_RmDir_FUNCTION
#define PR_RmDir_REQUIRED_ARGC 1
#define PR_RmDir_OPTIONAL_ARGC 0
/* PR_RmDir
 *
 * Parameters:
 * - name: const char *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_RmDir(mrb_state* mrb, mrb_value self) {
  mrb_value name;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &name);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_name = mrb_string_value_cstr(mrb, &name);

  /* Invocation */
  PRStatus result = PR_RmDir(native_name);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_RWLock_Rlock_FUNCTION
#define PR_RWLock_Rlock_REQUIRED_ARGC 1
#define PR_RWLock_Rlock_OPTIONAL_ARGC 0
/* PR_RWLock_Rlock
 *
 * Parameters:
 * - lock: struct PRRWLock *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_RWLock_Rlock(mrb_state* mrb, mrb_value self) {
  mrb_value lock;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &lock);


  /* Type checking */
  TODO_type_check_struct_PRRWLock_PTR(lock);


  /* Unbox parameters */
  struct PRRWLock * native_lock = TODO_mruby_unbox_struct_PRRWLock_PTR(lock);

  /* Invocation */
  PR_RWLock_Rlock(native_lock);

  return mrb_nil_value();
}
#endif

#if BIND_PR_RWLock_Unlock_FUNCTION
#define PR_RWLock_Unlock_REQUIRED_ARGC 1
#define PR_RWLock_Unlock_OPTIONAL_ARGC 0
/* PR_RWLock_Unlock
 *
 * Parameters:
 * - lock: struct PRRWLock *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_RWLock_Unlock(mrb_state* mrb, mrb_value self) {
  mrb_value lock;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &lock);


  /* Type checking */
  TODO_type_check_struct_PRRWLock_PTR(lock);


  /* Unbox parameters */
  struct PRRWLock * native_lock = TODO_mruby_unbox_struct_PRRWLock_PTR(lock);

  /* Invocation */
  PR_RWLock_Unlock(native_lock);

  return mrb_nil_value();
}
#endif

#if BIND_PR_RWLock_Wlock_FUNCTION
#define PR_RWLock_Wlock_REQUIRED_ARGC 1
#define PR_RWLock_Wlock_OPTIONAL_ARGC 0
/* PR_RWLock_Wlock
 *
 * Parameters:
 * - lock: struct PRRWLock *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_RWLock_Wlock(mrb_state* mrb, mrb_value self) {
  mrb_value lock;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &lock);


  /* Type checking */
  TODO_type_check_struct_PRRWLock_PTR(lock);


  /* Unbox parameters */
  struct PRRWLock * native_lock = TODO_mruby_unbox_struct_PRRWLock_PTR(lock);

  /* Invocation */
  PR_RWLock_Wlock(native_lock);

  return mrb_nil_value();
}
#endif

#if BIND_PR_SecondsToInterval_FUNCTION
#define PR_SecondsToInterval_REQUIRED_ARGC 1
#define PR_SecondsToInterval_OPTIONAL_ARGC 0
/* PR_SecondsToInterval
 *
 * Parameters:
 * - seconds: unsigned int
 * Return Type: PRIntervalTime
 */
mrb_value
mrb_NSPR_PR_SecondsToInterval(mrb_state* mrb, mrb_value self) {
  mrb_value seconds;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &seconds);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, seconds, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  unsigned int native_seconds = mrb_fixnum(seconds);

  /* Invocation */
  PRIntervalTime result = PR_SecondsToInterval(native_seconds);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRIntervalTime(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_Seek_FUNCTION
#define PR_Seek_REQUIRED_ARGC 3
#define PR_Seek_OPTIONAL_ARGC 0
/* PR_Seek
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - offset: int
 * - whence: enum PRSeekWhence
 * Return Type: PROffset32
 */
mrb_value
mrb_NSPR_PR_Seek(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value offset;
  mrb_value whence;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &fd, &offset, &whence);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  if (!mrb_obj_is_kind_of(mrb, offset, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_enum_PRSeekWhence(whence);


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  int native_offset = mrb_fixnum(offset);

  enum PRSeekWhence native_whence = TODO_mruby_unbox_enum_PRSeekWhence(whence);

  /* Invocation */
  PROffset32 result = PR_Seek(native_fd, native_offset, native_whence);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PROffset32(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_Seek64_FUNCTION
#define PR_Seek64_REQUIRED_ARGC 3
#define PR_Seek64_OPTIONAL_ARGC 0
/* PR_Seek64
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - offset: long long
 * - whence: enum PRSeekWhence
 * Return Type: PROffset64
 */
mrb_value
mrb_NSPR_PR_Seek64(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value offset;
  mrb_value whence;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &fd, &offset, &whence);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_long_long(offset);
  TODO_type_check_enum_PRSeekWhence(whence);


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  long long native_offset = TODO_mruby_unbox_long_long(offset);

  enum PRSeekWhence native_whence = TODO_mruby_unbox_enum_PRSeekWhence(whence);

  /* Invocation */
  PROffset64 result = PR_Seek64(native_fd, native_offset, native_whence);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_long_long(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_Send_FUNCTION
#define PR_Send_REQUIRED_ARGC 5
#define PR_Send_OPTIONAL_ARGC 0
/* PR_Send
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - buf: const void *
 * - amount: int
 * - flags: int
 * - timeout: unsigned int
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_Send(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value buf;
  mrb_value amount;
  mrb_value flags;
  mrb_value timeout;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &fd, &buf, &amount, &flags, &timeout);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_const_void_PTR(buf);
  if (!mrb_obj_is_kind_of(mrb, amount, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  const void * native_buf = TODO_mruby_unbox_const_void_PTR(buf);

  int native_amount = mrb_fixnum(amount);

  int native_flags = mrb_fixnum(flags);

  unsigned int native_timeout = mrb_fixnum(timeout);

  /* Invocation */
  PRInt32 result = PR_Send(native_fd, native_buf, native_amount, native_flags, native_timeout);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_SendFile_FUNCTION
#define PR_SendFile_REQUIRED_ARGC 4
#define PR_SendFile_OPTIONAL_ARGC 0
/* PR_SendFile
 *
 * Parameters:
 * - networkSocket: struct PRFileDesc *
 * - sendData: struct PRSendFileData *
 * - flags: enum PRTransmitFileFlags
 * - timeout: unsigned int
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_SendFile(mrb_state* mrb, mrb_value self) {
  mrb_value networkSocket;
  mrb_value sendData;
  mrb_value flags;
  mrb_value timeout;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &networkSocket, &sendData, &flags, &timeout);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(networkSocket);
  TODO_type_check_struct_PRSendFileData_PTR(sendData);
  TODO_type_check_enum_PRTransmitFileFlags(flags);
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRFileDesc * native_networkSocket = TODO_mruby_unbox_struct_PRFileDesc_PTR(networkSocket);

  struct PRSendFileData * native_sendData = TODO_mruby_unbox_struct_PRSendFileData_PTR(sendData);

  enum PRTransmitFileFlags native_flags = TODO_mruby_unbox_enum_PRTransmitFileFlags(flags);

  unsigned int native_timeout = mrb_fixnum(timeout);

  /* Invocation */
  PRInt32 result = PR_SendFile(native_networkSocket, native_sendData, native_flags, native_timeout);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_SendTo_FUNCTION
#define PR_SendTo_REQUIRED_ARGC 6
#define PR_SendTo_OPTIONAL_ARGC 0
/* PR_SendTo
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - buf: const void *
 * - amount: int
 * - flags: int
 * - addr: const union PRNetAddr *
 * - timeout: unsigned int
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_SendTo(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value buf;
  mrb_value amount;
  mrb_value flags;
  mrb_value addr;
  mrb_value timeout;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooo", &fd, &buf, &amount, &flags, &addr, &timeout);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_const_void_PTR(buf);
  if (!mrb_obj_is_kind_of(mrb, amount, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, flags, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_const_union_PRNetAddr_PTR(addr);
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  const void * native_buf = TODO_mruby_unbox_const_void_PTR(buf);

  int native_amount = mrb_fixnum(amount);

  int native_flags = mrb_fixnum(flags);

  const union PRNetAddr * native_addr = TODO_mruby_unbox_const_union_PRNetAddr_PTR(addr);

  unsigned int native_timeout = mrb_fixnum(timeout);

  /* Invocation */
  PRInt32 result = PR_SendTo(native_fd, native_buf, native_amount, native_flags, native_addr, native_timeout);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_SetConcurrency_FUNCTION
#define PR_SetConcurrency_REQUIRED_ARGC 1
#define PR_SetConcurrency_OPTIONAL_ARGC 0
/* PR_SetConcurrency
 *
 * Parameters:
 * - numCPUs: unsigned int
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_SetConcurrency(mrb_state* mrb, mrb_value self) {
  mrb_value numCPUs;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &numCPUs);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, numCPUs, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  unsigned int native_numCPUs = mrb_fixnum(numCPUs);

  /* Invocation */
  PR_SetConcurrency(native_numCPUs);

  return mrb_nil_value();
}
#endif

#if BIND_PR_SetCounter_FUNCTION
#define PR_SetCounter_REQUIRED_ARGC 2
#define PR_SetCounter_OPTIONAL_ARGC 0
/* PR_SetCounter
 *
 * Parameters:
 * - handle: void *
 * - value: unsigned int
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_SetCounter(mrb_state* mrb, mrb_value self) {
  mrb_value handle;
  mrb_value value;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &handle, &value);


  /* Type checking */
  TODO_type_check_void_PTR(handle);
  if (!mrb_obj_is_kind_of(mrb, value, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void * native_handle = TODO_mruby_unbox_void_PTR(handle);

  unsigned int native_value = mrb_fixnum(value);

  /* Invocation */
  PR_SetCounter(native_handle, native_value);

  return mrb_nil_value();
}
#endif

#if BIND_PR_SetCurrentThreadName_FUNCTION
#define PR_SetCurrentThreadName_REQUIRED_ARGC 1
#define PR_SetCurrentThreadName_OPTIONAL_ARGC 0
/* PR_SetCurrentThreadName
 *
 * Parameters:
 * - name: const char *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_SetCurrentThreadName(mrb_state* mrb, mrb_value self) {
  mrb_value name;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &name);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_name = mrb_string_value_cstr(mrb, &name);

  /* Invocation */
  PRStatus result = PR_SetCurrentThreadName(native_name);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_SetEnv_FUNCTION
#define PR_SetEnv_REQUIRED_ARGC 1
#define PR_SetEnv_OPTIONAL_ARGC 0
/* PR_SetEnv
 *
 * Parameters:
 * - string: const char *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_SetEnv(mrb_state* mrb, mrb_value self) {
  mrb_value string;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &string);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, string, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_string = mrb_string_value_cstr(mrb, &string);

  /* Invocation */
  PRStatus result = PR_SetEnv(native_string);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_SetError_FUNCTION
#define PR_SetError_REQUIRED_ARGC 2
#define PR_SetError_OPTIONAL_ARGC 0
/* PR_SetError
 *
 * Parameters:
 * - errorCode: int
 * - oserr: int
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_SetError(mrb_state* mrb, mrb_value self) {
  mrb_value errorCode;
  mrb_value oserr;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &errorCode, &oserr);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, errorCode, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, oserr, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_errorCode = mrb_fixnum(errorCode);

  int native_oserr = mrb_fixnum(oserr);

  /* Invocation */
  PR_SetError(native_errorCode, native_oserr);

  return mrb_nil_value();
}
#endif

#if BIND_PR_SetErrorText_FUNCTION
#define PR_SetErrorText_REQUIRED_ARGC 2
#define PR_SetErrorText_OPTIONAL_ARGC 0
/* PR_SetErrorText
 *
 * Parameters:
 * - textLength: int
 * - text: const char *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_SetErrorText(mrb_state* mrb, mrb_value self) {
  mrb_value textLength;
  mrb_value text;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &textLength, &text);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, textLength, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, text, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_textLength = mrb_fixnum(textLength);

  const char * native_text = mrb_string_value_cstr(mrb, &text);

  /* Invocation */
  PR_SetErrorText(native_textLength, native_text);

  return mrb_nil_value();
}
#endif

#if BIND_PR_SetFDCacheSize_FUNCTION
#define PR_SetFDCacheSize_REQUIRED_ARGC 2
#define PR_SetFDCacheSize_OPTIONAL_ARGC 0
/* PR_SetFDCacheSize
 *
 * Parameters:
 * - low: int
 * - high: int
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_SetFDCacheSize(mrb_state* mrb, mrb_value self) {
  mrb_value low;
  mrb_value high;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &low, &high);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, low, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, high, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_low = mrb_fixnum(low);

  int native_high = mrb_fixnum(high);

  /* Invocation */
  PRStatus result = PR_SetFDCacheSize(native_low, native_high);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_SetFDInheritable_FUNCTION
#define PR_SetFDInheritable_REQUIRED_ARGC 2
#define PR_SetFDInheritable_OPTIONAL_ARGC 0
/* PR_SetFDInheritable
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - inheritable: int
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_SetFDInheritable(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value inheritable;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &fd, &inheritable);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  if (!mrb_obj_is_kind_of(mrb, inheritable, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  int native_inheritable = mrb_fixnum(inheritable);

  /* Invocation */
  PRStatus result = PR_SetFDInheritable(native_fd, native_inheritable);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_SetLibraryPath_FUNCTION
#define PR_SetLibraryPath_REQUIRED_ARGC 1
#define PR_SetLibraryPath_OPTIONAL_ARGC 0
/* PR_SetLibraryPath
 *
 * Parameters:
 * - path: const char *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_SetLibraryPath(mrb_state* mrb, mrb_value self) {
  mrb_value path;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &path);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, path, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_path = mrb_string_value_cstr(mrb, &path);

  /* Invocation */
  PRStatus result = PR_SetLibraryPath(native_path);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_SetLogBuffering_FUNCTION
#define PR_SetLogBuffering_REQUIRED_ARGC 1
#define PR_SetLogBuffering_OPTIONAL_ARGC 0
/* PR_SetLogBuffering
 *
 * Parameters:
 * - buffer_size: int
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_SetLogBuffering(mrb_state* mrb, mrb_value self) {
  mrb_value buffer_size;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &buffer_size);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, buffer_size, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int native_buffer_size = mrb_fixnum(buffer_size);

  /* Invocation */
  PR_SetLogBuffering(native_buffer_size);

  return mrb_nil_value();
}
#endif

#if BIND_PR_SetLogFile_FUNCTION
#define PR_SetLogFile_REQUIRED_ARGC 1
#define PR_SetLogFile_OPTIONAL_ARGC 0
/* PR_SetLogFile
 *
 * Parameters:
 * - name: const char *
 * Return Type: PRBool
 */
mrb_value
mrb_NSPR_PR_SetLogFile(mrb_state* mrb, mrb_value self) {
  mrb_value name;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &name);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, name, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_name = mrb_string_value_cstr(mrb, &name);

  /* Invocation */
  PRBool result = PR_SetLogFile(native_name);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRBool(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_SetNetAddr_FUNCTION
#define PR_SetNetAddr_REQUIRED_ARGC 4
#define PR_SetNetAddr_OPTIONAL_ARGC 0
/* PR_SetNetAddr
 *
 * Parameters:
 * - val: enum PRNetAddrValue
 * - af: unsigned short
 * - port: unsigned short
 * - addr: union PRNetAddr *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_SetNetAddr(mrb_state* mrb, mrb_value self) {
  mrb_value val;
  mrb_value af;
  mrb_value port;
  mrb_value addr;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &val, &af, &port, &addr);


  /* Type checking */
  TODO_type_check_enum_PRNetAddrValue(val);
  TODO_type_check_unsigned_short(af);
  TODO_type_check_unsigned_short(port);
  TODO_type_check_union_PRNetAddr_PTR(addr);


  /* Unbox parameters */
  enum PRNetAddrValue native_val = TODO_mruby_unbox_enum_PRNetAddrValue(val);

  unsigned short native_af = TODO_mruby_unbox_unsigned_short(af);

  unsigned short native_port = TODO_mruby_unbox_unsigned_short(port);

  union PRNetAddr * native_addr = TODO_mruby_unbox_union_PRNetAddr_PTR(addr);

  /* Invocation */
  PRStatus result = PR_SetNetAddr(native_val, native_af, native_port, native_addr);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_SetPollableEvent_FUNCTION
#define PR_SetPollableEvent_REQUIRED_ARGC 1
#define PR_SetPollableEvent_OPTIONAL_ARGC 0
/* PR_SetPollableEvent
 *
 * Parameters:
 * - event: struct PRFileDesc *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_SetPollableEvent(mrb_state* mrb, mrb_value self) {
  mrb_value event;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &event);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(event);


  /* Unbox parameters */
  struct PRFileDesc * native_event = TODO_mruby_unbox_struct_PRFileDesc_PTR(event);

  /* Invocation */
  PRStatus result = PR_SetPollableEvent(native_event);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_SetSocketOption_FUNCTION
#define PR_SetSocketOption_REQUIRED_ARGC 2
#define PR_SetSocketOption_OPTIONAL_ARGC 0
/* PR_SetSocketOption
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - data: const struct PRSocketOptionData *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_SetSocketOption(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value data;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &fd, &data);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_const_struct_PRSocketOptionData_PTR(data);


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  const struct PRSocketOptionData * native_data = TODO_mruby_unbox_const_struct_PRSocketOptionData_PTR(data);

  /* Invocation */
  PRStatus result = PR_SetSocketOption(native_fd, native_data);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_SetStdioRedirect_FUNCTION
#define PR_SetStdioRedirect_REQUIRED_ARGC 3
#define PR_SetStdioRedirect_OPTIONAL_ARGC 0
/* PR_SetStdioRedirect
 *
 * Parameters:
 * - attr: struct PRProcessAttr *
 * - stdioFd: enum PRSpecialFD
 * - redirectFd: struct PRFileDesc *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_SetStdioRedirect(mrb_state* mrb, mrb_value self) {
  mrb_value attr;
  mrb_value stdioFd;
  mrb_value redirectFd;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &attr, &stdioFd, &redirectFd);


  /* Type checking */
  TODO_type_check_struct_PRProcessAttr_PTR(attr);
  TODO_type_check_enum_PRSpecialFD(stdioFd);
  TODO_type_check_struct_PRFileDesc_PTR(redirectFd);


  /* Unbox parameters */
  struct PRProcessAttr * native_attr = TODO_mruby_unbox_struct_PRProcessAttr_PTR(attr);

  enum PRSpecialFD native_stdioFd = TODO_mruby_unbox_enum_PRSpecialFD(stdioFd);

  struct PRFileDesc * native_redirectFd = TODO_mruby_unbox_struct_PRFileDesc_PTR(redirectFd);

  /* Invocation */
  PR_SetStdioRedirect(native_attr, native_stdioFd, native_redirectFd);

  return mrb_nil_value();
}
#endif

#if BIND_PR_SetThreadPriority_FUNCTION
#define PR_SetThreadPriority_REQUIRED_ARGC 2
#define PR_SetThreadPriority_OPTIONAL_ARGC 0
/* PR_SetThreadPriority
 *
 * Parameters:
 * - thread: struct PRThread *
 * - priority: enum PRThreadPriority
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_SetThreadPriority(mrb_state* mrb, mrb_value self) {
  mrb_value thread;
  mrb_value priority;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &thread, &priority);


  /* Type checking */
  TODO_type_check_struct_PRThread_PTR(thread);
  TODO_type_check_enum_PRThreadPriority(priority);


  /* Unbox parameters */
  struct PRThread * native_thread = TODO_mruby_unbox_struct_PRThread_PTR(thread);

  enum PRThreadPriority native_priority = TODO_mruby_unbox_enum_PRThreadPriority(priority);

  /* Invocation */
  PR_SetThreadPriority(native_thread, native_priority);

  return mrb_nil_value();
}
#endif

#if BIND_PR_SetThreadPrivate_FUNCTION
#define PR_SetThreadPrivate_REQUIRED_ARGC 2
#define PR_SetThreadPrivate_OPTIONAL_ARGC 0
/* PR_SetThreadPrivate
 *
 * Parameters:
 * - tpdIndex: unsigned int
 * - priv: void *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_SetThreadPrivate(mrb_state* mrb, mrb_value self) {
  mrb_value tpdIndex;
  mrb_value priv;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &tpdIndex, &priv);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, tpdIndex, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(priv);


  /* Unbox parameters */
  unsigned int native_tpdIndex = mrb_fixnum(tpdIndex);

  void * native_priv = TODO_mruby_unbox_void_PTR(priv);

  /* Invocation */
  PRStatus result = PR_SetThreadPrivate(native_tpdIndex, native_priv);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_SetTraceOption_FUNCTION
#define PR_SetTraceOption_REQUIRED_ARGC 2
#define PR_SetTraceOption_OPTIONAL_ARGC 0
/* PR_SetTraceOption
 *
 * Parameters:
 * - command: enum PRTraceOption
 * - value: void *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_SetTraceOption(mrb_state* mrb, mrb_value self) {
  mrb_value command;
  mrb_value value;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &command, &value);


  /* Type checking */
  TODO_type_check_enum_PRTraceOption(command);
  TODO_type_check_void_PTR(value);


  /* Unbox parameters */
  enum PRTraceOption native_command = TODO_mruby_unbox_enum_PRTraceOption(command);

  void * native_value = TODO_mruby_unbox_void_PTR(value);

  /* Invocation */
  PR_SetTraceOption(native_command, native_value);

  return mrb_nil_value();
}
#endif

#if BIND_PR_Shutdown_FUNCTION
#define PR_Shutdown_REQUIRED_ARGC 2
#define PR_Shutdown_OPTIONAL_ARGC 0
/* PR_Shutdown
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - how: enum PRShutdownHow
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_Shutdown(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value how;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &fd, &how);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_enum_PRShutdownHow(how);


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  enum PRShutdownHow native_how = TODO_mruby_unbox_enum_PRShutdownHow(how);

  /* Invocation */
  PRStatus result = PR_Shutdown(native_fd, native_how);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_ShutdownThreadPool_FUNCTION
#define PR_ShutdownThreadPool_REQUIRED_ARGC 1
#define PR_ShutdownThreadPool_OPTIONAL_ARGC 0
/* PR_ShutdownThreadPool
 *
 * Parameters:
 * - tpool: struct PRThreadPool *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_ShutdownThreadPool(mrb_state* mrb, mrb_value self) {
  mrb_value tpool;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &tpool);


  /* Type checking */
  TODO_type_check_struct_PRThreadPool_PTR(tpool);


  /* Unbox parameters */
  struct PRThreadPool * native_tpool = TODO_mruby_unbox_struct_PRThreadPool_PTR(tpool);

  /* Invocation */
  PRStatus result = PR_ShutdownThreadPool(native_tpool);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_Sleep_FUNCTION
#define PR_Sleep_REQUIRED_ARGC 1
#define PR_Sleep_OPTIONAL_ARGC 0
/* PR_Sleep
 *
 * Parameters:
 * - ticks: unsigned int
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_Sleep(mrb_state* mrb, mrb_value self) {
  mrb_value ticks;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &ticks);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, ticks, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  unsigned int native_ticks = mrb_fixnum(ticks);

  /* Invocation */
  PRStatus result = PR_Sleep(native_ticks);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_smprintf_FUNCTION
#define PR_smprintf_REQUIRED_ARGC 1
#define PR_smprintf_OPTIONAL_ARGC 0
/* PR_smprintf
 *
 * Parameters:
 * - fmt: const char *
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PR_smprintf(mrb_state* mrb, mrb_value self) {
  mrb_value fmt;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &fmt);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, fmt, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_fmt = mrb_string_value_cstr(mrb, &fmt);

  /* Invocation */
  char * result = PR_smprintf(native_fmt);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_smprintf_free_FUNCTION
#define PR_smprintf_free_REQUIRED_ARGC 1
#define PR_smprintf_free_OPTIONAL_ARGC 0
/* PR_smprintf_free
 *
 * Parameters:
 * - mem: char *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_smprintf_free(mrb_state* mrb, mrb_value self) {
  mrb_value mem;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &mem);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, mem, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_mem = strdup(mrb_string_value_cstr(mrb, &mem));

  /* Invocation */
  PR_smprintf_free(native_mem);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_mem);
  native_mem = NULL;

  return mrb_nil_value();
}
#endif

#if BIND_PR_snprintf_FUNCTION
#define PR_snprintf_REQUIRED_ARGC 3
#define PR_snprintf_OPTIONAL_ARGC 0
/* PR_snprintf
 *
 * Parameters:
 * - out: char *
 * - outlen: unsigned int
 * - fmt: const char *
 * Return Type: PRUint32
 */
mrb_value
mrb_NSPR_PR_snprintf(mrb_state* mrb, mrb_value self) {
  mrb_value out;
  mrb_value outlen;
  mrb_value fmt;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &out, &outlen, &fmt);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, out, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, outlen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, fmt, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_out = strdup(mrb_string_value_cstr(mrb, &out));

  unsigned int native_outlen = mrb_fixnum(outlen);

  const char * native_fmt = mrb_string_value_cstr(mrb, &fmt);

  /* Invocation */
  PRUint32 result = PR_snprintf(native_out, native_outlen, native_fmt);

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
  free(native_out);
  native_out = NULL;

  return return_value;
}
#endif

#if BIND_PR_sprintf_append_FUNCTION
#define PR_sprintf_append_REQUIRED_ARGC 5
#define PR_sprintf_append_OPTIONAL_ARGC 0
/* PR_sprintf_append
 *
 * Parameters:
 * - last: char *
 * - fmt: const char *
 * - arg: void *
 * - s: const char *
 * - slen: unsigned int
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PR_sprintf_append(mrb_state* mrb, mrb_value self) {
  mrb_value last;
  mrb_value fmt;
  mrb_value arg;
  mrb_value s;
  mrb_value slen;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &last, &fmt, &arg, &s, &slen);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, last, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, fmt, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_void_PTR(arg);
  if (!mrb_obj_is_kind_of(mrb, s, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, slen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_last = strdup(mrb_string_value_cstr(mrb, &last));

  const char * native_fmt = mrb_string_value_cstr(mrb, &fmt);

  void * native_arg = TODO_mruby_unbox_void_PTR(arg);

  const char * native_s = mrb_string_value_cstr(mrb, &s);

  unsigned int native_slen = mrb_fixnum(slen);

  /* Invocation */
  char * result = PR_sprintf_append(native_last, native_fmt, native_arg, native_s, native_slen);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_last);
  native_last = NULL;

  return return_value;
}
#endif

#if BIND_PR_sscanf_FUNCTION
#define PR_sscanf_REQUIRED_ARGC 2
#define PR_sscanf_OPTIONAL_ARGC 0
/* PR_sscanf
 *
 * Parameters:
 * - buf: const char *
 * - fmt: const char *
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_sscanf(mrb_state* mrb, mrb_value self) {
  mrb_value buf;
  mrb_value fmt;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &buf, &fmt);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, buf, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, fmt, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_buf = mrb_string_value_cstr(mrb, &buf);

  const char * native_fmt = mrb_string_value_cstr(mrb, &fmt);

  /* Invocation */
  PRInt32 result = PR_sscanf(native_buf, native_fmt);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_StackPop_FUNCTION
#define PR_StackPop_REQUIRED_ARGC 1
#define PR_StackPop_OPTIONAL_ARGC 0
/* PR_StackPop
 *
 * Parameters:
 * - stack: struct PRStackStr *
 * Return Type: PRStackElem *
 */
mrb_value
mrb_NSPR_PR_StackPop(mrb_state* mrb, mrb_value self) {
  mrb_value stack;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &stack);


  /* Type checking */
  TODO_type_check_struct_PRStackStr_PTR(stack);


  /* Unbox parameters */
  struct PRStackStr * native_stack = TODO_mruby_unbox_struct_PRStackStr_PTR(stack);

  /* Invocation */
  PRStackElem * result = PR_StackPop(native_stack);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStackElem_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_StackPush_FUNCTION
#define PR_StackPush_REQUIRED_ARGC 2
#define PR_StackPush_OPTIONAL_ARGC 0
/* PR_StackPush
 *
 * Parameters:
 * - stack: struct PRStackStr *
 * - stack_elem: struct PRStackElemStr *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_StackPush(mrb_state* mrb, mrb_value self) {
  mrb_value stack;
  mrb_value stack_elem;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &stack, &stack_elem);


  /* Type checking */
  TODO_type_check_struct_PRStackStr_PTR(stack);
  TODO_type_check_struct_PRStackElemStr_PTR(stack_elem);


  /* Unbox parameters */
  struct PRStackStr * native_stack = TODO_mruby_unbox_struct_PRStackStr_PTR(stack);

  struct PRStackElemStr * native_stack_elem = TODO_mruby_unbox_struct_PRStackElemStr_PTR(stack_elem);

  /* Invocation */
  PR_StackPush(native_stack, native_stack_elem);

  return mrb_nil_value();
}
#endif

#if BIND_PR_StringToNetAddr_FUNCTION
#define PR_StringToNetAddr_REQUIRED_ARGC 2
#define PR_StringToNetAddr_OPTIONAL_ARGC 0
/* PR_StringToNetAddr
 *
 * Parameters:
 * - string: const char *
 * - addr: union PRNetAddr *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_StringToNetAddr(mrb_state* mrb, mrb_value self) {
  mrb_value string;
  mrb_value addr;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &string, &addr);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, string, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_union_PRNetAddr_PTR(addr);


  /* Unbox parameters */
  const char * native_string = mrb_string_value_cstr(mrb, &string);

  union PRNetAddr * native_addr = TODO_mruby_unbox_union_PRNetAddr_PTR(addr);

  /* Invocation */
  PRStatus result = PR_StringToNetAddr(native_string, native_addr);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_strtod_FUNCTION
#define PR_strtod_REQUIRED_ARGC 2
#define PR_strtod_OPTIONAL_ARGC 0
/* PR_strtod
 *
 * Parameters:
 * - s00: const char *
 * - se: char **
 * Return Type: PRFloat64
 */
mrb_value
mrb_NSPR_PR_strtod(mrb_state* mrb, mrb_value self) {
  mrb_value s00;
  mrb_value se;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &s00, &se);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, s00, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_char_PTR_PTR(se);


  /* Unbox parameters */
  const char * native_s00 = mrb_string_value_cstr(mrb, &s00);

  char ** native_se = TODO_mruby_unbox_char_PTR_PTR(se);

  /* Invocation */
  PRFloat64 result = PR_strtod(native_s00, native_se);

  /* Box the return value */
  mrb_value return_value = mrb_float_value(result);

  return return_value;
}
#endif

#if BIND_PR_SubtractFromCounter_FUNCTION
#define PR_SubtractFromCounter_REQUIRED_ARGC 2
#define PR_SubtractFromCounter_OPTIONAL_ARGC 0
/* PR_SubtractFromCounter
 *
 * Parameters:
 * - handle: void *
 * - value: unsigned int
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_SubtractFromCounter(mrb_state* mrb, mrb_value self) {
  mrb_value handle;
  mrb_value value;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &handle, &value);


  /* Type checking */
  TODO_type_check_void_PTR(handle);
  if (!mrb_obj_is_kind_of(mrb, value, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void * native_handle = TODO_mruby_unbox_void_PTR(handle);

  unsigned int native_value = mrb_fixnum(value);

  /* Invocation */
  PR_SubtractFromCounter(native_handle, native_value);

  return mrb_nil_value();
}
#endif

#if BIND_PR_sxprintf_FUNCTION
#define PR_sxprintf_REQUIRED_ARGC 3
#define PR_sxprintf_OPTIONAL_ARGC 0
/* PR_sxprintf
 *
 * Parameters:
 * - f: int (*)(void *, const char *, unsigned int)
 * - arg: void *
 * - fmt: const char *
 * Return Type: PRUint32
 */
mrb_value
mrb_NSPR_PR_sxprintf(mrb_state* mrb, mrb_value self) {
  mrb_value f;
  mrb_value arg;
  mrb_value fmt;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &f, &arg, &fmt);


  /* Type checking */
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_const_char_PTR_COMMA_unsigned_int_RPAREN(f);
  TODO_type_check_void_PTR(arg);
  if (!mrb_obj_is_kind_of(mrb, fmt, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  int (*native_f)(void *, const char *, unsigned int) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_const_char_PTR_COMMA_unsigned_int_RPAREN(f);

  void * native_arg = TODO_mruby_unbox_void_PTR(arg);

  const char * native_fmt = mrb_string_value_cstr(mrb, &fmt);

  /* Invocation */
  PRUint32 result = PR_sxprintf(native_f, native_arg, native_fmt);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_Sync_FUNCTION
#define PR_Sync_REQUIRED_ARGC 1
#define PR_Sync_OPTIONAL_ARGC 0
/* PR_Sync
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_Sync(mrb_state* mrb, mrb_value self) {
  mrb_value fd;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &fd);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  /* Invocation */
  PRStatus result = PR_Sync(native_fd);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_SyncMemMap_FUNCTION
#define PR_SyncMemMap_REQUIRED_ARGC 3
#define PR_SyncMemMap_OPTIONAL_ARGC 0
/* PR_SyncMemMap
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - addr: void *
 * - len: unsigned int
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_SyncMemMap(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value addr;
  mrb_value len;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &fd, &addr, &len);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_void_PTR(addr);
  if (!mrb_obj_is_kind_of(mrb, len, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  void * native_addr = TODO_mruby_unbox_void_PTR(addr);

  unsigned int native_len = mrb_fixnum(len);

  /* Invocation */
  PRStatus result = PR_SyncMemMap(native_fd, native_addr, native_len);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_TicksPerSecond_FUNCTION
#define PR_TicksPerSecond_REQUIRED_ARGC 0
#define PR_TicksPerSecond_OPTIONAL_ARGC 0
/* PR_TicksPerSecond
 *
 * Parameters: None
 * Return Type: PRUint32
 */
mrb_value
mrb_NSPR_PR_TicksPerSecond(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRUint32 result = PR_TicksPerSecond();

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_Trace_FUNCTION
#define PR_Trace_REQUIRED_ARGC 9
#define PR_Trace_OPTIONAL_ARGC 0
/* PR_Trace
 *
 * Parameters:
 * - handle: void *
 * - userData0: unsigned int
 * - userData1: unsigned int
 * - userData2: unsigned int
 * - userData3: unsigned int
 * - userData4: unsigned int
 * - userData5: unsigned int
 * - userData6: unsigned int
 * - userData7: unsigned int
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_Trace(mrb_state* mrb, mrb_value self) {
  mrb_value handle;
  mrb_value userData0;
  mrb_value userData1;
  mrb_value userData2;
  mrb_value userData3;
  mrb_value userData4;
  mrb_value userData5;
  mrb_value userData6;
  mrb_value userData7;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooooooo", &handle, &userData0, &userData1, &userData2, &userData3, &userData4, &userData5, &userData6, &userData7);


  /* Type checking */
  TODO_type_check_void_PTR(handle);
  if (!mrb_obj_is_kind_of(mrb, userData0, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, userData1, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, userData2, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, userData3, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, userData4, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, userData5, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, userData6, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, userData7, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  void * native_handle = TODO_mruby_unbox_void_PTR(handle);

  unsigned int native_userData0 = mrb_fixnum(userData0);

  unsigned int native_userData1 = mrb_fixnum(userData1);

  unsigned int native_userData2 = mrb_fixnum(userData2);

  unsigned int native_userData3 = mrb_fixnum(userData3);

  unsigned int native_userData4 = mrb_fixnum(userData4);

  unsigned int native_userData5 = mrb_fixnum(userData5);

  unsigned int native_userData6 = mrb_fixnum(userData6);

  unsigned int native_userData7 = mrb_fixnum(userData7);

  /* Invocation */
  PR_Trace(native_handle, native_userData0, native_userData1, native_userData2, native_userData3, native_userData4, native_userData5, native_userData6, native_userData7);

  return mrb_nil_value();
}
#endif

#if BIND_PR_TransmitFile_FUNCTION
#define PR_TransmitFile_REQUIRED_ARGC 6
#define PR_TransmitFile_OPTIONAL_ARGC 0
/* PR_TransmitFile
 *
 * Parameters:
 * - networkSocket: struct PRFileDesc *
 * - sourceFile: struct PRFileDesc *
 * - headers: const void *
 * - hlen: int
 * - flags: enum PRTransmitFileFlags
 * - timeout: unsigned int
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_TransmitFile(mrb_state* mrb, mrb_value self) {
  mrb_value networkSocket;
  mrb_value sourceFile;
  mrb_value headers;
  mrb_value hlen;
  mrb_value flags;
  mrb_value timeout;

  /* Fetch the args */
  mrb_get_args(mrb, "oooooo", &networkSocket, &sourceFile, &headers, &hlen, &flags, &timeout);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(networkSocket);
  TODO_type_check_struct_PRFileDesc_PTR(sourceFile);
  TODO_type_check_const_void_PTR(headers);
  if (!mrb_obj_is_kind_of(mrb, hlen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  TODO_type_check_enum_PRTransmitFileFlags(flags);
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRFileDesc * native_networkSocket = TODO_mruby_unbox_struct_PRFileDesc_PTR(networkSocket);

  struct PRFileDesc * native_sourceFile = TODO_mruby_unbox_struct_PRFileDesc_PTR(sourceFile);

  const void * native_headers = TODO_mruby_unbox_const_void_PTR(headers);

  int native_hlen = mrb_fixnum(hlen);

  enum PRTransmitFileFlags native_flags = TODO_mruby_unbox_enum_PRTransmitFileFlags(flags);

  unsigned int native_timeout = mrb_fixnum(timeout);

  /* Invocation */
  PRInt32 result = PR_TransmitFile(native_networkSocket, native_sourceFile, native_headers, native_hlen, native_flags, native_timeout);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_UnblockClockInterrupts_FUNCTION
#define PR_UnblockClockInterrupts_REQUIRED_ARGC 0
#define PR_UnblockClockInterrupts_OPTIONAL_ARGC 0
/* PR_UnblockClockInterrupts
 *
 * Parameters: None
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_UnblockClockInterrupts(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PR_UnblockClockInterrupts();

  return mrb_nil_value();
}
#endif

#if BIND_PR_UnblockInterrupt_FUNCTION
#define PR_UnblockInterrupt_REQUIRED_ARGC 0
#define PR_UnblockInterrupt_OPTIONAL_ARGC 0
/* PR_UnblockInterrupt
 *
 * Parameters: None
 * Return Type: void
 */
mrb_value
mrb_NSPR_PR_UnblockInterrupt(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PR_UnblockInterrupt();

  return mrb_nil_value();
}
#endif

#if BIND_PR_UnloadLibrary_FUNCTION
#define PR_UnloadLibrary_REQUIRED_ARGC 1
#define PR_UnloadLibrary_OPTIONAL_ARGC 0
/* PR_UnloadLibrary
 *
 * Parameters:
 * - lib: struct PRLibrary *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_UnloadLibrary(mrb_state* mrb, mrb_value self) {
  mrb_value lib;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &lib);


  /* Type checking */
  TODO_type_check_struct_PRLibrary_PTR(lib);


  /* Unbox parameters */
  struct PRLibrary * native_lib = TODO_mruby_unbox_struct_PRLibrary_PTR(lib);

  /* Invocation */
  PRStatus result = PR_UnloadLibrary(native_lib);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_Unlock_FUNCTION
#define PR_Unlock_REQUIRED_ARGC 1
#define PR_Unlock_OPTIONAL_ARGC 0
/* PR_Unlock
 *
 * Parameters:
 * - lock: struct PRLock *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_Unlock(mrb_state* mrb, mrb_value self) {
  mrb_value lock;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &lock);


  /* Type checking */
  TODO_type_check_struct_PRLock_PTR(lock);


  /* Unbox parameters */
  struct PRLock * native_lock = TODO_mruby_unbox_struct_PRLock_PTR(lock);

  /* Invocation */
  PRStatus result = PR_Unlock(native_lock);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_UnlockOrderedLock_FUNCTION
#define PR_UnlockOrderedLock_REQUIRED_ARGC 1
#define PR_UnlockOrderedLock_OPTIONAL_ARGC 0
/* PR_UnlockOrderedLock
 *
 * Parameters:
 * - lock: struct PRLock *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_UnlockOrderedLock(mrb_state* mrb, mrb_value self) {
  mrb_value lock;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &lock);


  /* Type checking */
  TODO_type_check_struct_PRLock_PTR(lock);


  /* Unbox parameters */
  struct PRLock * native_lock = TODO_mruby_unbox_struct_PRLock_PTR(lock);

  /* Invocation */
  PRStatus result = PR_UnlockOrderedLock(native_lock);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_USPacificTimeParameters_FUNCTION
#define PR_USPacificTimeParameters_REQUIRED_ARGC 1
#define PR_USPacificTimeParameters_OPTIONAL_ARGC 0
/* PR_USPacificTimeParameters
 *
 * Parameters:
 * - gmt: const struct PRExplodedTime *
 * Return Type: PRTimeParameters
 */
mrb_value
mrb_NSPR_PR_USPacificTimeParameters(mrb_state* mrb, mrb_value self) {
  mrb_value gmt;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &gmt);


  /* Type checking */
  TODO_type_check_const_struct_PRExplodedTime_PTR(gmt);


  /* Unbox parameters */
  const struct PRExplodedTime * native_gmt = TODO_mruby_unbox_const_struct_PRExplodedTime_PTR(gmt);

  /* Invocation */
  PRTimeParameters result = PR_USPacificTimeParameters(native_gmt);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRTimeParameters(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_VersionCheck_FUNCTION
#define PR_VersionCheck_REQUIRED_ARGC 1
#define PR_VersionCheck_OPTIONAL_ARGC 0
/* PR_VersionCheck
 *
 * Parameters:
 * - importedVersion: const char *
 * Return Type: PRBool
 */
mrb_value
mrb_NSPR_PR_VersionCheck(mrb_state* mrb, mrb_value self) {
  mrb_value importedVersion;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &importedVersion);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, importedVersion, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  const char * native_importedVersion = mrb_string_value_cstr(mrb, &importedVersion);

  /* Invocation */
  PRBool result = PR_VersionCheck(native_importedVersion);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRBool(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_vfprintf_FUNCTION
#define PR_vfprintf_REQUIRED_ARGC 3
#define PR_vfprintf_OPTIONAL_ARGC 0
/* PR_vfprintf
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - fmt: const char *
 * - ap: struct __va_list_tag [1]
 * Return Type: PRUint32
 */
mrb_value
mrb_NSPR_PR_vfprintf(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value fmt;
  mrb_value ap;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &fd, &fmt, &ap);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  if (!mrb_obj_is_kind_of(mrb, fmt, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct___va_list_tag_[1](ap);


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  const char * native_fmt = mrb_string_value_cstr(mrb, &fmt);

  struct __va_list_tag [1] native_ap = TODO_mruby_unbox_struct___va_list_tag_[1](ap);

  /* Invocation */
  PRUint32 result = PR_vfprintf(native_fd, native_fmt, native_ap);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_vsmprintf_FUNCTION
#define PR_vsmprintf_REQUIRED_ARGC 2
#define PR_vsmprintf_OPTIONAL_ARGC 0
/* PR_vsmprintf
 *
 * Parameters:
 * - fmt: const char *
 * - ap: struct __va_list_tag [1]
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PR_vsmprintf(mrb_state* mrb, mrb_value self) {
  mrb_value fmt;
  mrb_value ap;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &fmt, &ap);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, fmt, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct___va_list_tag_[1](ap);


  /* Unbox parameters */
  const char * native_fmt = mrb_string_value_cstr(mrb, &fmt);

  struct __va_list_tag [1] native_ap = TODO_mruby_unbox_struct___va_list_tag_[1](ap);

  /* Invocation */
  char * result = PR_vsmprintf(native_fmt, native_ap);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_vsnprintf_FUNCTION
#define PR_vsnprintf_REQUIRED_ARGC 4
#define PR_vsnprintf_OPTIONAL_ARGC 0
/* PR_vsnprintf
 *
 * Parameters:
 * - out: char *
 * - outlen: unsigned int
 * - fmt: const char *
 * - ap: struct __va_list_tag [1]
 * Return Type: PRUint32
 */
mrb_value
mrb_NSPR_PR_vsnprintf(mrb_state* mrb, mrb_value self) {
  mrb_value out;
  mrb_value outlen;
  mrb_value fmt;
  mrb_value ap;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &out, &outlen, &fmt, &ap);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, out, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, outlen, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, fmt, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct___va_list_tag_[1](ap);


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_out = strdup(mrb_string_value_cstr(mrb, &out));

  unsigned int native_outlen = mrb_fixnum(outlen);

  const char * native_fmt = mrb_string_value_cstr(mrb, &fmt);

  struct __va_list_tag [1] native_ap = TODO_mruby_unbox_struct___va_list_tag_[1](ap);

  /* Invocation */
  PRUint32 result = PR_vsnprintf(native_out, native_outlen, native_fmt, native_ap);

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
  free(native_out);
  native_out = NULL;

  return return_value;
}
#endif

#if BIND_PR_vsprintf_append_FUNCTION
#define PR_vsprintf_append_REQUIRED_ARGC 3
#define PR_vsprintf_append_OPTIONAL_ARGC 0
/* PR_vsprintf_append
 *
 * Parameters:
 * - last: char *
 * - fmt: const char *
 * - ap: struct __va_list_tag [1]
 * Return Type: char *
 */
mrb_value
mrb_NSPR_PR_vsprintf_append(mrb_state* mrb, mrb_value self) {
  mrb_value last;
  mrb_value fmt;
  mrb_value ap;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &last, &fmt, &ap);


  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, last, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, fmt, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct___va_list_tag_[1](ap);


  /* Unbox parameters */
  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_last = strdup(mrb_string_value_cstr(mrb, &last));

  const char * native_fmt = mrb_string_value_cstr(mrb, &fmt);

  struct __va_list_tag [1] native_ap = TODO_mruby_unbox_struct___va_list_tag_[1](ap);

  /* Invocation */
  char * result = PR_vsprintf_append(native_last, native_fmt, native_ap);

  /* Box the return value */
  mrb_value return_value = mrb_str_new_cstr(mrb, result);

  /* WARNING: Assuming that the new string can be deallocated after the function call.
   *          Please verify that this is correct (the function does not save this parameter).
   *
   *          Has this been verified? [No]
   */
  free(native_last);
  native_last = NULL;

  return return_value;
}
#endif

#if BIND_PR_vsxprintf_FUNCTION
#define PR_vsxprintf_REQUIRED_ARGC 4
#define PR_vsxprintf_OPTIONAL_ARGC 0
/* PR_vsxprintf
 *
 * Parameters:
 * - f: int (*)(void *, const char *, unsigned int)
 * - arg: void *
 * - fmt: const char *
 * - ap: struct __va_list_tag [1]
 * Return Type: PRUint32
 */
mrb_value
mrb_NSPR_PR_vsxprintf(mrb_state* mrb, mrb_value self) {
  mrb_value f;
  mrb_value arg;
  mrb_value fmt;
  mrb_value ap;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &f, &arg, &fmt, &ap);


  /* Type checking */
  TODO_type_check_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_const_char_PTR_COMMA_unsigned_int_RPAREN(f);
  TODO_type_check_void_PTR(arg);
  if (!mrb_obj_is_kind_of(mrb, fmt, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }
  TODO_type_check_struct___va_list_tag_[1](ap);


  /* Unbox parameters */
  int (*native_f)(void *, const char *, unsigned int) = TODO_mruby_unbox_int_LPAREN_PTR_RPAREN_LPAREN_void_PTR_COMMA_const_char_PTR_COMMA_unsigned_int_RPAREN(f);

  void * native_arg = TODO_mruby_unbox_void_PTR(arg);

  const char * native_fmt = mrb_string_value_cstr(mrb, &fmt);

  struct __va_list_tag [1] native_ap = TODO_mruby_unbox_struct___va_list_tag_[1](ap);

  /* Invocation */
  PRUint32 result = PR_vsxprintf(native_f, native_arg, native_fmt, native_ap);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_Wait_FUNCTION
#define PR_Wait_REQUIRED_ARGC 2
#define PR_Wait_OPTIONAL_ARGC 0
/* PR_Wait
 *
 * Parameters:
 * - mon: struct PRMonitor *
 * - ticks: unsigned int
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_Wait(mrb_state* mrb, mrb_value self) {
  mrb_value mon;
  mrb_value ticks;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &mon, &ticks);


  /* Type checking */
  TODO_type_check_struct_PRMonitor_PTR(mon);
  if (!mrb_obj_is_kind_of(mrb, ticks, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRMonitor * native_mon = TODO_mruby_unbox_struct_PRMonitor_PTR(mon);

  unsigned int native_ticks = mrb_fixnum(ticks);

  /* Invocation */
  PRStatus result = PR_Wait(native_mon, native_ticks);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_WaitCondVar_FUNCTION
#define PR_WaitCondVar_REQUIRED_ARGC 2
#define PR_WaitCondVar_OPTIONAL_ARGC 0
/* PR_WaitCondVar
 *
 * Parameters:
 * - cvar: struct PRCondVar *
 * - timeout: unsigned int
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_WaitCondVar(mrb_state* mrb, mrb_value self) {
  mrb_value cvar;
  mrb_value timeout;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &cvar, &timeout);


  /* Type checking */
  TODO_type_check_struct_PRCondVar_PTR(cvar);
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRCondVar * native_cvar = TODO_mruby_unbox_struct_PRCondVar_PTR(cvar);

  unsigned int native_timeout = mrb_fixnum(timeout);

  /* Invocation */
  PRStatus result = PR_WaitCondVar(native_cvar, native_timeout);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_WaitForPollableEvent_FUNCTION
#define PR_WaitForPollableEvent_REQUIRED_ARGC 1
#define PR_WaitForPollableEvent_OPTIONAL_ARGC 0
/* PR_WaitForPollableEvent
 *
 * Parameters:
 * - event: struct PRFileDesc *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_WaitForPollableEvent(mrb_state* mrb, mrb_value self) {
  mrb_value event;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &event);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(event);


  /* Unbox parameters */
  struct PRFileDesc * native_event = TODO_mruby_unbox_struct_PRFileDesc_PTR(event);

  /* Invocation */
  PRStatus result = PR_WaitForPollableEvent(native_event);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_WaitProcess_FUNCTION
#define PR_WaitProcess_REQUIRED_ARGC 2
#define PR_WaitProcess_OPTIONAL_ARGC 0
/* PR_WaitProcess
 *
 * Parameters:
 * - process: struct PRProcess *
 * - exitCode: int *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_WaitProcess(mrb_state* mrb, mrb_value self) {
  mrb_value process;
  mrb_value exitCode;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &process, &exitCode);


  /* Type checking */
  TODO_type_check_struct_PRProcess_PTR(process);
  TODO_type_check_int_PTR(exitCode);


  /* Unbox parameters */
  struct PRProcess * native_process = TODO_mruby_unbox_struct_PRProcess_PTR(process);

  int * native_exitCode = TODO_mruby_unbox_int_PTR(exitCode);

  /* Invocation */
  PRStatus result = PR_WaitProcess(native_process, native_exitCode);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_WaitRecvReady_FUNCTION
#define PR_WaitRecvReady_REQUIRED_ARGC 1
#define PR_WaitRecvReady_OPTIONAL_ARGC 0
/* PR_WaitRecvReady
 *
 * Parameters:
 * - group: struct PRWaitGroup *
 * Return Type: PRRecvWait *
 */
mrb_value
mrb_NSPR_PR_WaitRecvReady(mrb_state* mrb, mrb_value self) {
  mrb_value group;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &group);


  /* Type checking */
  TODO_type_check_struct_PRWaitGroup_PTR(group);


  /* Unbox parameters */
  struct PRWaitGroup * native_group = TODO_mruby_unbox_struct_PRWaitGroup_PTR(group);

  /* Invocation */
  PRRecvWait * result = PR_WaitRecvReady(native_group);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRRecvWait_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_WaitSemaphore_FUNCTION
#define PR_WaitSemaphore_REQUIRED_ARGC 1
#define PR_WaitSemaphore_OPTIONAL_ARGC 0
/* PR_WaitSemaphore
 *
 * Parameters:
 * - sem: struct PRSem *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PR_WaitSemaphore(mrb_state* mrb, mrb_value self) {
  mrb_value sem;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &sem);


  /* Type checking */
  TODO_type_check_struct_PRSem_PTR(sem);


  /* Unbox parameters */
  struct PRSem * native_sem = TODO_mruby_unbox_struct_PRSem_PTR(sem);

  /* Invocation */
  PRStatus result = PR_WaitSemaphore(native_sem);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PR_Write_FUNCTION
#define PR_Write_REQUIRED_ARGC 3
#define PR_Write_OPTIONAL_ARGC 0
/* PR_Write
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - buf: const void *
 * - amount: int
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_Write(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value buf;
  mrb_value amount;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &fd, &buf, &amount);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_const_void_PTR(buf);
  if (!mrb_obj_is_kind_of(mrb, amount, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  const void * native_buf = TODO_mruby_unbox_const_void_PTR(buf);

  int native_amount = mrb_fixnum(amount);

  /* Invocation */
  PRInt32 result = PR_Write(native_fd, native_buf, native_amount);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PR_Writev_FUNCTION
#define PR_Writev_REQUIRED_ARGC 4
#define PR_Writev_OPTIONAL_ARGC 0
/* PR_Writev
 *
 * Parameters:
 * - fd: struct PRFileDesc *
 * - iov: const struct PRIOVec *
 * - iov_size: int
 * - timeout: unsigned int
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_PR_Writev(mrb_state* mrb, mrb_value self) {
  mrb_value fd;
  mrb_value iov;
  mrb_value iov_size;
  mrb_value timeout;

  /* Fetch the args */
  mrb_get_args(mrb, "oooo", &fd, &iov, &iov_size, &timeout);


  /* Type checking */
  TODO_type_check_struct_PRFileDesc_PTR(fd);
  TODO_type_check_const_struct_PRIOVec_PTR(iov);
  if (!mrb_obj_is_kind_of(mrb, iov_size, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRFileDesc * native_fd = TODO_mruby_unbox_struct_PRFileDesc_PTR(fd);

  const struct PRIOVec * native_iov = TODO_mruby_unbox_const_struct_PRIOVec_PTR(iov);

  int native_iov_size = mrb_fixnum(iov_size);

  unsigned int native_timeout = mrb_fixnum(timeout);

  /* Invocation */
  PRInt32 result = PR_Writev(native_fd, native_iov, native_iov_size, native_timeout);

  /* Box the return value */
  if (result > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value return_value = mrb_fixnum_value(result);

  return return_value;
}
#endif

#if BIND_PRP_DestroyNakedCondVar_FUNCTION
#define PRP_DestroyNakedCondVar_REQUIRED_ARGC 1
#define PRP_DestroyNakedCondVar_OPTIONAL_ARGC 0
/* PRP_DestroyNakedCondVar
 *
 * Parameters:
 * - cvar: struct PRCondVar *
 * Return Type: void
 */
mrb_value
mrb_NSPR_PRP_DestroyNakedCondVar(mrb_state* mrb, mrb_value self) {
  mrb_value cvar;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &cvar);


  /* Type checking */
  TODO_type_check_struct_PRCondVar_PTR(cvar);


  /* Unbox parameters */
  struct PRCondVar * native_cvar = TODO_mruby_unbox_struct_PRCondVar_PTR(cvar);

  /* Invocation */
  PRP_DestroyNakedCondVar(native_cvar);

  return mrb_nil_value();
}
#endif

#if BIND_PRP_NakedBroadcast_FUNCTION
#define PRP_NakedBroadcast_REQUIRED_ARGC 1
#define PRP_NakedBroadcast_OPTIONAL_ARGC 0
/* PRP_NakedBroadcast
 *
 * Parameters:
 * - cvar: struct PRCondVar *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PRP_NakedBroadcast(mrb_state* mrb, mrb_value self) {
  mrb_value cvar;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &cvar);


  /* Type checking */
  TODO_type_check_struct_PRCondVar_PTR(cvar);


  /* Unbox parameters */
  struct PRCondVar * native_cvar = TODO_mruby_unbox_struct_PRCondVar_PTR(cvar);

  /* Invocation */
  PRStatus result = PRP_NakedBroadcast(native_cvar);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PRP_NakedNotify_FUNCTION
#define PRP_NakedNotify_REQUIRED_ARGC 1
#define PRP_NakedNotify_OPTIONAL_ARGC 0
/* PRP_NakedNotify
 *
 * Parameters:
 * - cvar: struct PRCondVar *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PRP_NakedNotify(mrb_state* mrb, mrb_value self) {
  mrb_value cvar;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &cvar);


  /* Type checking */
  TODO_type_check_struct_PRCondVar_PTR(cvar);


  /* Unbox parameters */
  struct PRCondVar * native_cvar = TODO_mruby_unbox_struct_PRCondVar_PTR(cvar);

  /* Invocation */
  PRStatus result = PRP_NakedNotify(native_cvar);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PRP_NakedWait_FUNCTION
#define PRP_NakedWait_REQUIRED_ARGC 3
#define PRP_NakedWait_OPTIONAL_ARGC 0
/* PRP_NakedWait
 *
 * Parameters:
 * - cvar: struct PRCondVar *
 * - lock: struct PRLock *
 * - timeout: unsigned int
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PRP_NakedWait(mrb_state* mrb, mrb_value self) {
  mrb_value cvar;
  mrb_value lock;
  mrb_value timeout;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &cvar, &lock, &timeout);


  /* Type checking */
  TODO_type_check_struct_PRCondVar_PTR(cvar);
  TODO_type_check_struct_PRLock_PTR(lock);
  if (!mrb_obj_is_kind_of(mrb, timeout, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }


  /* Unbox parameters */
  struct PRCondVar * native_cvar = TODO_mruby_unbox_struct_PRCondVar_PTR(cvar);

  struct PRLock * native_lock = TODO_mruby_unbox_struct_PRLock_PTR(lock);

  unsigned int native_timeout = mrb_fixnum(timeout);

  /* Invocation */
  PRStatus result = PRP_NakedWait(native_cvar, native_lock, native_timeout);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif

#if BIND_PRP_NewNakedCondVar_FUNCTION
#define PRP_NewNakedCondVar_REQUIRED_ARGC 0
#define PRP_NewNakedCondVar_OPTIONAL_ARGC 0
/* PRP_NewNakedCondVar
 *
 * Parameters: None
 * Return Type: PRCondVar *
 */
mrb_value
mrb_NSPR_PRP_NewNakedCondVar(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  PRCondVar * result = PRP_NewNakedCondVar();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRCondVar_PTR(mrb, result);

  return return_value;
}
#endif

#if BIND_PRP_TryLock_FUNCTION
#define PRP_TryLock_REQUIRED_ARGC 1
#define PRP_TryLock_OPTIONAL_ARGC 0
/* PRP_TryLock
 *
 * Parameters:
 * - lock: struct PRLock *
 * Return Type: PRStatus
 */
mrb_value
mrb_NSPR_PRP_TryLock(mrb_state* mrb, mrb_value self) {
  mrb_value lock;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &lock);


  /* Type checking */
  TODO_type_check_struct_PRLock_PTR(lock);


  /* Unbox parameters */
  struct PRLock * native_lock = TODO_mruby_unbox_struct_PRLock_PTR(lock);

  /* Invocation */
  PRStatus result = PRP_TryLock(native_lock);

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_PRStatus(mrb, result);

  return return_value;
}
#endif


void mrb_mruby_nspr_gem_init(mrb_state* mrb) {
  RClass* NSPR_module = mrb_define_module(mrb, "NSPR");
  mruby_NSPR_define_macro_constants(mrb);

  /*
   * Initialize class bindings
   */
#if BIND_Prversiondescription_TYPE
  mrb_NSPR_Prversiondescription_init(mrb);
#endif

  /*
   * Global Functions
   */
#if BIND_LL_MaxInt_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "LL_MaxInt", mrb_NSPR_LL_MaxInt, MRB_ARGS_ARG(LL_MaxInt_REQUIRED_ARGC, LL_MaxInt_OPTIONAL_ARGC));
#endif
#if BIND_LL_MaxUint_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "LL_MaxUint", mrb_NSPR_LL_MaxUint, MRB_ARGS_ARG(LL_MaxUint_REQUIRED_ARGC, LL_MaxUint_OPTIONAL_ARGC));
#endif
#if BIND_LL_MinInt_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "LL_MinInt", mrb_NSPR_LL_MinInt, MRB_ARGS_ARG(LL_MinInt_REQUIRED_ARGC, LL_MinInt_OPTIONAL_ARGC));
#endif
#if BIND_LL_Zero_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "LL_Zero", mrb_NSPR_LL_Zero, MRB_ARGS_ARG(LL_Zero_REQUIRED_ARGC, LL_Zero_OPTIONAL_ARGC));
#endif
#if BIND_nspr_InitializePRErrorTable_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "nspr_InitializePRErrorTable", mrb_NSPR_nspr_InitializePRErrorTable, MRB_ARGS_ARG(nspr_InitializePRErrorTable_REQUIRED_ARGC, nspr_InitializePRErrorTable_OPTIONAL_ARGC));
#endif
#if BIND_PL_Base64Decode_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_Base64Decode", mrb_NSPR_PL_Base64Decode, MRB_ARGS_ARG(PL_Base64Decode_REQUIRED_ARGC, PL_Base64Decode_OPTIONAL_ARGC));
#endif
#if BIND_PL_Base64Encode_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_Base64Encode", mrb_NSPR_PL_Base64Encode, MRB_ARGS_ARG(PL_Base64Encode_REQUIRED_ARGC, PL_Base64Encode_OPTIONAL_ARGC));
#endif
#if BIND_PL_CompareStrings_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_CompareStrings", mrb_NSPR_PL_CompareStrings, MRB_ARGS_ARG(PL_CompareStrings_REQUIRED_ARGC, PL_CompareStrings_OPTIONAL_ARGC));
#endif
#if BIND_PL_CompareValues_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_CompareValues", mrb_NSPR_PL_CompareValues, MRB_ARGS_ARG(PL_CompareValues_REQUIRED_ARGC, PL_CompareValues_OPTIONAL_ARGC));
#endif
#if BIND_PL_CreateLongOptState_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_CreateLongOptState", mrb_NSPR_PL_CreateLongOptState, MRB_ARGS_ARG(PL_CreateLongOptState_REQUIRED_ARGC, PL_CreateLongOptState_OPTIONAL_ARGC));
#endif
#if BIND_PL_CreateOptState_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_CreateOptState", mrb_NSPR_PL_CreateOptState, MRB_ARGS_ARG(PL_CreateOptState_REQUIRED_ARGC, PL_CreateOptState_OPTIONAL_ARGC));
#endif
#if BIND_PL_DestroyOptState_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_DestroyOptState", mrb_NSPR_PL_DestroyOptState, MRB_ARGS_ARG(PL_DestroyOptState_REQUIRED_ARGC, PL_DestroyOptState_OPTIONAL_ARGC));
#endif
#if BIND_PL_FPrintError_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_FPrintError", mrb_NSPR_PL_FPrintError, MRB_ARGS_ARG(PL_FPrintError_REQUIRED_ARGC, PL_FPrintError_OPTIONAL_ARGC));
#endif
#if BIND_PL_GetNextOpt_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_GetNextOpt", mrb_NSPR_PL_GetNextOpt, MRB_ARGS_ARG(PL_GetNextOpt_REQUIRED_ARGC, PL_GetNextOpt_OPTIONAL_ARGC));
#endif
#if BIND_PL_HashString_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_HashString", mrb_NSPR_PL_HashString, MRB_ARGS_ARG(PL_HashString_REQUIRED_ARGC, PL_HashString_OPTIONAL_ARGC));
#endif
#if BIND_PL_HashTableAdd_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_HashTableAdd", mrb_NSPR_PL_HashTableAdd, MRB_ARGS_ARG(PL_HashTableAdd_REQUIRED_ARGC, PL_HashTableAdd_OPTIONAL_ARGC));
#endif
#if BIND_PL_HashTableDestroy_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_HashTableDestroy", mrb_NSPR_PL_HashTableDestroy, MRB_ARGS_ARG(PL_HashTableDestroy_REQUIRED_ARGC, PL_HashTableDestroy_OPTIONAL_ARGC));
#endif
#if BIND_PL_HashTableDump_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_HashTableDump", mrb_NSPR_PL_HashTableDump, MRB_ARGS_ARG(PL_HashTableDump_REQUIRED_ARGC, PL_HashTableDump_OPTIONAL_ARGC));
#endif
#if BIND_PL_HashTableEnumerateEntries_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_HashTableEnumerateEntries", mrb_NSPR_PL_HashTableEnumerateEntries, MRB_ARGS_ARG(PL_HashTableEnumerateEntries_REQUIRED_ARGC, PL_HashTableEnumerateEntries_OPTIONAL_ARGC));
#endif
#if BIND_PL_HashTableLookup_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_HashTableLookup", mrb_NSPR_PL_HashTableLookup, MRB_ARGS_ARG(PL_HashTableLookup_REQUIRED_ARGC, PL_HashTableLookup_OPTIONAL_ARGC));
#endif
#if BIND_PL_HashTableLookupConst_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_HashTableLookupConst", mrb_NSPR_PL_HashTableLookupConst, MRB_ARGS_ARG(PL_HashTableLookupConst_REQUIRED_ARGC, PL_HashTableLookupConst_OPTIONAL_ARGC));
#endif
#if BIND_PL_HashTableRawAdd_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_HashTableRawAdd", mrb_NSPR_PL_HashTableRawAdd, MRB_ARGS_ARG(PL_HashTableRawAdd_REQUIRED_ARGC, PL_HashTableRawAdd_OPTIONAL_ARGC));
#endif
#if BIND_PL_HashTableRawLookup_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_HashTableRawLookup", mrb_NSPR_PL_HashTableRawLookup, MRB_ARGS_ARG(PL_HashTableRawLookup_REQUIRED_ARGC, PL_HashTableRawLookup_OPTIONAL_ARGC));
#endif
#if BIND_PL_HashTableRawLookupConst_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_HashTableRawLookupConst", mrb_NSPR_PL_HashTableRawLookupConst, MRB_ARGS_ARG(PL_HashTableRawLookupConst_REQUIRED_ARGC, PL_HashTableRawLookupConst_OPTIONAL_ARGC));
#endif
#if BIND_PL_HashTableRawRemove_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_HashTableRawRemove", mrb_NSPR_PL_HashTableRawRemove, MRB_ARGS_ARG(PL_HashTableRawRemove_REQUIRED_ARGC, PL_HashTableRawRemove_OPTIONAL_ARGC));
#endif
#if BIND_PL_HashTableRemove_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_HashTableRemove", mrb_NSPR_PL_HashTableRemove, MRB_ARGS_ARG(PL_HashTableRemove_REQUIRED_ARGC, PL_HashTableRemove_OPTIONAL_ARGC));
#endif
#if BIND_PL_NewHashTable_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_NewHashTable", mrb_NSPR_PL_NewHashTable, MRB_ARGS_ARG(PL_NewHashTable_REQUIRED_ARGC, PL_NewHashTable_OPTIONAL_ARGC));
#endif
#if BIND_PL_PrintError_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_PrintError", mrb_NSPR_PL_PrintError, MRB_ARGS_ARG(PL_PrintError_REQUIRED_ARGC, PL_PrintError_OPTIONAL_ARGC));
#endif
#if BIND_PL_strcasecmp_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strcasecmp", mrb_NSPR_PL_strcasecmp, MRB_ARGS_ARG(PL_strcasecmp_REQUIRED_ARGC, PL_strcasecmp_OPTIONAL_ARGC));
#endif
#if BIND_PL_strcaserstr_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strcaserstr", mrb_NSPR_PL_strcaserstr, MRB_ARGS_ARG(PL_strcaserstr_REQUIRED_ARGC, PL_strcaserstr_OPTIONAL_ARGC));
#endif
#if BIND_PL_strcasestr_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strcasestr", mrb_NSPR_PL_strcasestr, MRB_ARGS_ARG(PL_strcasestr_REQUIRED_ARGC, PL_strcasestr_OPTIONAL_ARGC));
#endif
#if BIND_PL_strcat_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strcat", mrb_NSPR_PL_strcat, MRB_ARGS_ARG(PL_strcat_REQUIRED_ARGC, PL_strcat_OPTIONAL_ARGC));
#endif
#if BIND_PL_strcatn_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strcatn", mrb_NSPR_PL_strcatn, MRB_ARGS_ARG(PL_strcatn_REQUIRED_ARGC, PL_strcatn_OPTIONAL_ARGC));
#endif
#if BIND_PL_strchr_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strchr", mrb_NSPR_PL_strchr, MRB_ARGS_ARG(PL_strchr_REQUIRED_ARGC, PL_strchr_OPTIONAL_ARGC));
#endif
#if BIND_PL_strcmp_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strcmp", mrb_NSPR_PL_strcmp, MRB_ARGS_ARG(PL_strcmp_REQUIRED_ARGC, PL_strcmp_OPTIONAL_ARGC));
#endif
#if BIND_PL_strcpy_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strcpy", mrb_NSPR_PL_strcpy, MRB_ARGS_ARG(PL_strcpy_REQUIRED_ARGC, PL_strcpy_OPTIONAL_ARGC));
#endif
#if BIND_PL_strdup_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strdup", mrb_NSPR_PL_strdup, MRB_ARGS_ARG(PL_strdup_REQUIRED_ARGC, PL_strdup_OPTIONAL_ARGC));
#endif
#if BIND_PL_strfree_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strfree", mrb_NSPR_PL_strfree, MRB_ARGS_ARG(PL_strfree_REQUIRED_ARGC, PL_strfree_OPTIONAL_ARGC));
#endif
#if BIND_PL_strlen_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strlen", mrb_NSPR_PL_strlen, MRB_ARGS_ARG(PL_strlen_REQUIRED_ARGC, PL_strlen_OPTIONAL_ARGC));
#endif
#if BIND_PL_strncasecmp_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strncasecmp", mrb_NSPR_PL_strncasecmp, MRB_ARGS_ARG(PL_strncasecmp_REQUIRED_ARGC, PL_strncasecmp_OPTIONAL_ARGC));
#endif
#if BIND_PL_strncaserstr_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strncaserstr", mrb_NSPR_PL_strncaserstr, MRB_ARGS_ARG(PL_strncaserstr_REQUIRED_ARGC, PL_strncaserstr_OPTIONAL_ARGC));
#endif
#if BIND_PL_strncasestr_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strncasestr", mrb_NSPR_PL_strncasestr, MRB_ARGS_ARG(PL_strncasestr_REQUIRED_ARGC, PL_strncasestr_OPTIONAL_ARGC));
#endif
#if BIND_PL_strncat_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strncat", mrb_NSPR_PL_strncat, MRB_ARGS_ARG(PL_strncat_REQUIRED_ARGC, PL_strncat_OPTIONAL_ARGC));
#endif
#if BIND_PL_strnchr_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strnchr", mrb_NSPR_PL_strnchr, MRB_ARGS_ARG(PL_strnchr_REQUIRED_ARGC, PL_strnchr_OPTIONAL_ARGC));
#endif
#if BIND_PL_strncmp_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strncmp", mrb_NSPR_PL_strncmp, MRB_ARGS_ARG(PL_strncmp_REQUIRED_ARGC, PL_strncmp_OPTIONAL_ARGC));
#endif
#if BIND_PL_strncpy_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strncpy", mrb_NSPR_PL_strncpy, MRB_ARGS_ARG(PL_strncpy_REQUIRED_ARGC, PL_strncpy_OPTIONAL_ARGC));
#endif
#if BIND_PL_strncpyz_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strncpyz", mrb_NSPR_PL_strncpyz, MRB_ARGS_ARG(PL_strncpyz_REQUIRED_ARGC, PL_strncpyz_OPTIONAL_ARGC));
#endif
#if BIND_PL_strndup_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strndup", mrb_NSPR_PL_strndup, MRB_ARGS_ARG(PL_strndup_REQUIRED_ARGC, PL_strndup_OPTIONAL_ARGC));
#endif
#if BIND_PL_strnlen_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strnlen", mrb_NSPR_PL_strnlen, MRB_ARGS_ARG(PL_strnlen_REQUIRED_ARGC, PL_strnlen_OPTIONAL_ARGC));
#endif
#if BIND_PL_strnpbrk_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strnpbrk", mrb_NSPR_PL_strnpbrk, MRB_ARGS_ARG(PL_strnpbrk_REQUIRED_ARGC, PL_strnpbrk_OPTIONAL_ARGC));
#endif
#if BIND_PL_strnprbrk_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strnprbrk", mrb_NSPR_PL_strnprbrk, MRB_ARGS_ARG(PL_strnprbrk_REQUIRED_ARGC, PL_strnprbrk_OPTIONAL_ARGC));
#endif
#if BIND_PL_strnrchr_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strnrchr", mrb_NSPR_PL_strnrchr, MRB_ARGS_ARG(PL_strnrchr_REQUIRED_ARGC, PL_strnrchr_OPTIONAL_ARGC));
#endif
#if BIND_PL_strnrstr_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strnrstr", mrb_NSPR_PL_strnrstr, MRB_ARGS_ARG(PL_strnrstr_REQUIRED_ARGC, PL_strnrstr_OPTIONAL_ARGC));
#endif
#if BIND_PL_strnstr_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strnstr", mrb_NSPR_PL_strnstr, MRB_ARGS_ARG(PL_strnstr_REQUIRED_ARGC, PL_strnstr_OPTIONAL_ARGC));
#endif
#if BIND_PL_strpbrk_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strpbrk", mrb_NSPR_PL_strpbrk, MRB_ARGS_ARG(PL_strpbrk_REQUIRED_ARGC, PL_strpbrk_OPTIONAL_ARGC));
#endif
#if BIND_PL_strprbrk_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strprbrk", mrb_NSPR_PL_strprbrk, MRB_ARGS_ARG(PL_strprbrk_REQUIRED_ARGC, PL_strprbrk_OPTIONAL_ARGC));
#endif
#if BIND_PL_strrchr_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strrchr", mrb_NSPR_PL_strrchr, MRB_ARGS_ARG(PL_strrchr_REQUIRED_ARGC, PL_strrchr_OPTIONAL_ARGC));
#endif
#if BIND_PL_strrstr_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strrstr", mrb_NSPR_PL_strrstr, MRB_ARGS_ARG(PL_strrstr_REQUIRED_ARGC, PL_strrstr_OPTIONAL_ARGC));
#endif
#if BIND_PL_strstr_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strstr", mrb_NSPR_PL_strstr, MRB_ARGS_ARG(PL_strstr_REQUIRED_ARGC, PL_strstr_OPTIONAL_ARGC));
#endif
#if BIND_PL_strtok_r_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PL_strtok_r", mrb_NSPR_PL_strtok_r, MRB_ARGS_ARG(PL_strtok_r_REQUIRED_ARGC, PL_strtok_r_OPTIONAL_ARGC));
#endif
#if BIND_PR_Abort_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Abort", mrb_NSPR_PR_Abort, MRB_ARGS_ARG(PR_Abort_REQUIRED_ARGC, PR_Abort_OPTIONAL_ARGC));
#endif
#if BIND_PR_Accept_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Accept", mrb_NSPR_PR_Accept, MRB_ARGS_ARG(PR_Accept_REQUIRED_ARGC, PR_Accept_OPTIONAL_ARGC));
#endif
#if BIND_PR_AcceptRead_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_AcceptRead", mrb_NSPR_PR_AcceptRead, MRB_ARGS_ARG(PR_AcceptRead_REQUIRED_ARGC, PR_AcceptRead_OPTIONAL_ARGC));
#endif
#if BIND_PR_Access_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Access", mrb_NSPR_PR_Access, MRB_ARGS_ARG(PR_Access_REQUIRED_ARGC, PR_Access_OPTIONAL_ARGC));
#endif
#if BIND_PR_AddToCounter_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_AddToCounter", mrb_NSPR_PR_AddToCounter, MRB_ARGS_ARG(PR_AddToCounter_REQUIRED_ARGC, PR_AddToCounter_OPTIONAL_ARGC));
#endif
#if BIND_PR_AddWaitFileDesc_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_AddWaitFileDesc", mrb_NSPR_PR_AddWaitFileDesc, MRB_ARGS_ARG(PR_AddWaitFileDesc_REQUIRED_ARGC, PR_AddWaitFileDesc_OPTIONAL_ARGC));
#endif
#if BIND_PR_Assert_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Assert", mrb_NSPR_PR_Assert, MRB_ARGS_ARG(PR_Assert_REQUIRED_ARGC, PR_Assert_OPTIONAL_ARGC));
#endif
#if BIND_PR_AssertCurrentThreadInMonitor_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_AssertCurrentThreadInMonitor", mrb_NSPR_PR_AssertCurrentThreadInMonitor, MRB_ARGS_ARG(PR_AssertCurrentThreadInMonitor_REQUIRED_ARGC, PR_AssertCurrentThreadInMonitor_OPTIONAL_ARGC));
#endif
#if BIND_PR_AssertCurrentThreadOwnsLock_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_AssertCurrentThreadOwnsLock", mrb_NSPR_PR_AssertCurrentThreadOwnsLock, MRB_ARGS_ARG(PR_AssertCurrentThreadOwnsLock_REQUIRED_ARGC, PR_AssertCurrentThreadOwnsLock_OPTIONAL_ARGC));
#endif
#if BIND_PR_AtomicAdd_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_AtomicAdd", mrb_NSPR_PR_AtomicAdd, MRB_ARGS_ARG(PR_AtomicAdd_REQUIRED_ARGC, PR_AtomicAdd_OPTIONAL_ARGC));
#endif
#if BIND_PR_AtomicDecrement_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_AtomicDecrement", mrb_NSPR_PR_AtomicDecrement, MRB_ARGS_ARG(PR_AtomicDecrement_REQUIRED_ARGC, PR_AtomicDecrement_OPTIONAL_ARGC));
#endif
#if BIND_PR_AtomicIncrement_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_AtomicIncrement", mrb_NSPR_PR_AtomicIncrement, MRB_ARGS_ARG(PR_AtomicIncrement_REQUIRED_ARGC, PR_AtomicIncrement_OPTIONAL_ARGC));
#endif
#if BIND_PR_AtomicSet_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_AtomicSet", mrb_NSPR_PR_AtomicSet, MRB_ARGS_ARG(PR_AtomicSet_REQUIRED_ARGC, PR_AtomicSet_OPTIONAL_ARGC));
#endif
#if BIND_PR_AttachSharedMemory_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_AttachSharedMemory", mrb_NSPR_PR_AttachSharedMemory, MRB_ARGS_ARG(PR_AttachSharedMemory_REQUIRED_ARGC, PR_AttachSharedMemory_OPTIONAL_ARGC));
#endif
#if BIND_PR_Available_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Available", mrb_NSPR_PR_Available, MRB_ARGS_ARG(PR_Available_REQUIRED_ARGC, PR_Available_OPTIONAL_ARGC));
#endif
#if BIND_PR_Available64_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Available64", mrb_NSPR_PR_Available64, MRB_ARGS_ARG(PR_Available64_REQUIRED_ARGC, PR_Available64_OPTIONAL_ARGC));
#endif
#if BIND_PR_Bind_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Bind", mrb_NSPR_PR_Bind, MRB_ARGS_ARG(PR_Bind_REQUIRED_ARGC, PR_Bind_OPTIONAL_ARGC));
#endif
#if BIND_PR_BlockClockInterrupts_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_BlockClockInterrupts", mrb_NSPR_PR_BlockClockInterrupts, MRB_ARGS_ARG(PR_BlockClockInterrupts_REQUIRED_ARGC, PR_BlockClockInterrupts_OPTIONAL_ARGC));
#endif
#if BIND_PR_BlockInterrupt_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_BlockInterrupt", mrb_NSPR_PR_BlockInterrupt, MRB_ARGS_ARG(PR_BlockInterrupt_REQUIRED_ARGC, PR_BlockInterrupt_OPTIONAL_ARGC));
#endif
#if BIND_PR_Calloc_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Calloc", mrb_NSPR_PR_Calloc, MRB_ARGS_ARG(PR_Calloc_REQUIRED_ARGC, PR_Calloc_OPTIONAL_ARGC));
#endif
#if BIND_PR_CallOnce_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CallOnce", mrb_NSPR_PR_CallOnce, MRB_ARGS_ARG(PR_CallOnce_REQUIRED_ARGC, PR_CallOnce_OPTIONAL_ARGC));
#endif
#if BIND_PR_CallOnceWithArg_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CallOnceWithArg", mrb_NSPR_PR_CallOnceWithArg, MRB_ARGS_ARG(PR_CallOnceWithArg_REQUIRED_ARGC, PR_CallOnceWithArg_OPTIONAL_ARGC));
#endif
#if BIND_PR_CancelJob_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CancelJob", mrb_NSPR_PR_CancelJob, MRB_ARGS_ARG(PR_CancelJob_REQUIRED_ARGC, PR_CancelJob_OPTIONAL_ARGC));
#endif
#if BIND_PR_CancelWaitFileDesc_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CancelWaitFileDesc", mrb_NSPR_PR_CancelWaitFileDesc, MRB_ARGS_ARG(PR_CancelWaitFileDesc_REQUIRED_ARGC, PR_CancelWaitFileDesc_OPTIONAL_ARGC));
#endif
#if BIND_PR_CancelWaitGroup_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CancelWaitGroup", mrb_NSPR_PR_CancelWaitGroup, MRB_ARGS_ARG(PR_CancelWaitGroup_REQUIRED_ARGC, PR_CancelWaitGroup_OPTIONAL_ARGC));
#endif
#if BIND_PR_CeilingLog2_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CeilingLog2", mrb_NSPR_PR_CeilingLog2, MRB_ARGS_ARG(PR_CeilingLog2_REQUIRED_ARGC, PR_CeilingLog2_OPTIONAL_ARGC));
#endif
#if BIND_PR_CEnterMonitor_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CEnterMonitor", mrb_NSPR_PR_CEnterMonitor, MRB_ARGS_ARG(PR_CEnterMonitor_REQUIRED_ARGC, PR_CEnterMonitor_OPTIONAL_ARGC));
#endif
#if BIND_PR_CExitMonitor_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CExitMonitor", mrb_NSPR_PR_CExitMonitor, MRB_ARGS_ARG(PR_CExitMonitor_REQUIRED_ARGC, PR_CExitMonitor_OPTIONAL_ARGC));
#endif
#if BIND_PR_Cleanup_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Cleanup", mrb_NSPR_PR_Cleanup, MRB_ARGS_ARG(PR_Cleanup_REQUIRED_ARGC, PR_Cleanup_OPTIONAL_ARGC));
#endif
#if BIND_PR_ClearInterrupt_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ClearInterrupt", mrb_NSPR_PR_ClearInterrupt, MRB_ARGS_ARG(PR_ClearInterrupt_REQUIRED_ARGC, PR_ClearInterrupt_OPTIONAL_ARGC));
#endif
#if BIND_PR_Close_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Close", mrb_NSPR_PR_Close, MRB_ARGS_ARG(PR_Close_REQUIRED_ARGC, PR_Close_OPTIONAL_ARGC));
#endif
#if BIND_PR_CloseDir_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CloseDir", mrb_NSPR_PR_CloseDir, MRB_ARGS_ARG(PR_CloseDir_REQUIRED_ARGC, PR_CloseDir_OPTIONAL_ARGC));
#endif
#if BIND_PR_CloseFileMap_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CloseFileMap", mrb_NSPR_PR_CloseFileMap, MRB_ARGS_ARG(PR_CloseFileMap_REQUIRED_ARGC, PR_CloseFileMap_OPTIONAL_ARGC));
#endif
#if BIND_PR_CloseSemaphore_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CloseSemaphore", mrb_NSPR_PR_CloseSemaphore, MRB_ARGS_ARG(PR_CloseSemaphore_REQUIRED_ARGC, PR_CloseSemaphore_OPTIONAL_ARGC));
#endif
#if BIND_PR_CloseSharedMemory_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CloseSharedMemory", mrb_NSPR_PR_CloseSharedMemory, MRB_ARGS_ARG(PR_CloseSharedMemory_REQUIRED_ARGC, PR_CloseSharedMemory_OPTIONAL_ARGC));
#endif
#if BIND_PR_CNotify_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CNotify", mrb_NSPR_PR_CNotify, MRB_ARGS_ARG(PR_CNotify_REQUIRED_ARGC, PR_CNotify_OPTIONAL_ARGC));
#endif
#if BIND_PR_CNotifyAll_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CNotifyAll", mrb_NSPR_PR_CNotifyAll, MRB_ARGS_ARG(PR_CNotifyAll_REQUIRED_ARGC, PR_CNotifyAll_OPTIONAL_ARGC));
#endif
#if BIND_PR_cnvtf_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_cnvtf", mrb_NSPR_PR_cnvtf, MRB_ARGS_ARG(PR_cnvtf_REQUIRED_ARGC, PR_cnvtf_OPTIONAL_ARGC));
#endif
#if BIND_PR_Connect_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Connect", mrb_NSPR_PR_Connect, MRB_ARGS_ARG(PR_Connect_REQUIRED_ARGC, PR_Connect_OPTIONAL_ARGC));
#endif
#if BIND_PR_ConnectContinue_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ConnectContinue", mrb_NSPR_PR_ConnectContinue, MRB_ARGS_ARG(PR_ConnectContinue_REQUIRED_ARGC, PR_ConnectContinue_OPTIONAL_ARGC));
#endif
#if BIND_PR_ConvertIPv4AddrToIPv6_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ConvertIPv4AddrToIPv6", mrb_NSPR_PR_ConvertIPv4AddrToIPv6, MRB_ARGS_ARG(PR_ConvertIPv4AddrToIPv6_REQUIRED_ARGC, PR_ConvertIPv4AddrToIPv6_OPTIONAL_ARGC));
#endif
#if BIND_PR_CreateCounter_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CreateCounter", mrb_NSPR_PR_CreateCounter, MRB_ARGS_ARG(PR_CreateCounter_REQUIRED_ARGC, PR_CreateCounter_OPTIONAL_ARGC));
#endif
#if BIND_PR_CreateFileMap_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CreateFileMap", mrb_NSPR_PR_CreateFileMap, MRB_ARGS_ARG(PR_CreateFileMap_REQUIRED_ARGC, PR_CreateFileMap_OPTIONAL_ARGC));
#endif
#if BIND_PR_CreateIOLayer_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CreateIOLayer", mrb_NSPR_PR_CreateIOLayer, MRB_ARGS_ARG(PR_CreateIOLayer_REQUIRED_ARGC, PR_CreateIOLayer_OPTIONAL_ARGC));
#endif
#if BIND_PR_CreateIOLayerStub_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CreateIOLayerStub", mrb_NSPR_PR_CreateIOLayerStub, MRB_ARGS_ARG(PR_CreateIOLayerStub_REQUIRED_ARGC, PR_CreateIOLayerStub_OPTIONAL_ARGC));
#endif
#if BIND_PR_CreateMWaitEnumerator_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CreateMWaitEnumerator", mrb_NSPR_PR_CreateMWaitEnumerator, MRB_ARGS_ARG(PR_CreateMWaitEnumerator_REQUIRED_ARGC, PR_CreateMWaitEnumerator_OPTIONAL_ARGC));
#endif
#if BIND_PR_CreateOrderedLock_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CreateOrderedLock", mrb_NSPR_PR_CreateOrderedLock, MRB_ARGS_ARG(PR_CreateOrderedLock_REQUIRED_ARGC, PR_CreateOrderedLock_OPTIONAL_ARGC));
#endif
#if BIND_PR_CreatePipe_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CreatePipe", mrb_NSPR_PR_CreatePipe, MRB_ARGS_ARG(PR_CreatePipe_REQUIRED_ARGC, PR_CreatePipe_OPTIONAL_ARGC));
#endif
#if BIND_PR_CreateProcess_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CreateProcess", mrb_NSPR_PR_CreateProcess, MRB_ARGS_ARG(PR_CreateProcess_REQUIRED_ARGC, PR_CreateProcess_OPTIONAL_ARGC));
#endif
#if BIND_PR_CreateProcessDetached_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CreateProcessDetached", mrb_NSPR_PR_CreateProcessDetached, MRB_ARGS_ARG(PR_CreateProcessDetached_REQUIRED_ARGC, PR_CreateProcessDetached_OPTIONAL_ARGC));
#endif
#if BIND_PR_CreateStack_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CreateStack", mrb_NSPR_PR_CreateStack, MRB_ARGS_ARG(PR_CreateStack_REQUIRED_ARGC, PR_CreateStack_OPTIONAL_ARGC));
#endif
#if BIND_PR_CreateThread_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CreateThread", mrb_NSPR_PR_CreateThread, MRB_ARGS_ARG(PR_CreateThread_REQUIRED_ARGC, PR_CreateThread_OPTIONAL_ARGC));
#endif
#if BIND_PR_CreateThreadPool_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CreateThreadPool", mrb_NSPR_PR_CreateThreadPool, MRB_ARGS_ARG(PR_CreateThreadPool_REQUIRED_ARGC, PR_CreateThreadPool_OPTIONAL_ARGC));
#endif
#if BIND_PR_CreateTrace_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CreateTrace", mrb_NSPR_PR_CreateTrace, MRB_ARGS_ARG(PR_CreateTrace_REQUIRED_ARGC, PR_CreateTrace_OPTIONAL_ARGC));
#endif
#if BIND_PR_CreateWaitGroup_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CreateWaitGroup", mrb_NSPR_PR_CreateWaitGroup, MRB_ARGS_ARG(PR_CreateWaitGroup_REQUIRED_ARGC, PR_CreateWaitGroup_OPTIONAL_ARGC));
#endif
#if BIND_PR_CSetOnMonitorRecycle_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CSetOnMonitorRecycle", mrb_NSPR_PR_CSetOnMonitorRecycle, MRB_ARGS_ARG(PR_CSetOnMonitorRecycle_REQUIRED_ARGC, PR_CSetOnMonitorRecycle_OPTIONAL_ARGC));
#endif
#if BIND_PR_CWait_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_CWait", mrb_NSPR_PR_CWait, MRB_ARGS_ARG(PR_CWait_REQUIRED_ARGC, PR_CWait_OPTIONAL_ARGC));
#endif
#if BIND_PR_DecrementCounter_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_DecrementCounter", mrb_NSPR_PR_DecrementCounter, MRB_ARGS_ARG(PR_DecrementCounter_REQUIRED_ARGC, PR_DecrementCounter_OPTIONAL_ARGC));
#endif
#if BIND_PR_Delete_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Delete", mrb_NSPR_PR_Delete, MRB_ARGS_ARG(PR_Delete_REQUIRED_ARGC, PR_Delete_OPTIONAL_ARGC));
#endif
#if BIND_PR_DeleteSemaphore_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_DeleteSemaphore", mrb_NSPR_PR_DeleteSemaphore, MRB_ARGS_ARG(PR_DeleteSemaphore_REQUIRED_ARGC, PR_DeleteSemaphore_OPTIONAL_ARGC));
#endif
#if BIND_PR_DeleteSharedMemory_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_DeleteSharedMemory", mrb_NSPR_PR_DeleteSharedMemory, MRB_ARGS_ARG(PR_DeleteSharedMemory_REQUIRED_ARGC, PR_DeleteSharedMemory_OPTIONAL_ARGC));
#endif
#if BIND_PR_DestroyCondVar_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_DestroyCondVar", mrb_NSPR_PR_DestroyCondVar, MRB_ARGS_ARG(PR_DestroyCondVar_REQUIRED_ARGC, PR_DestroyCondVar_OPTIONAL_ARGC));
#endif
#if BIND_PR_DestroyCounter_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_DestroyCounter", mrb_NSPR_PR_DestroyCounter, MRB_ARGS_ARG(PR_DestroyCounter_REQUIRED_ARGC, PR_DestroyCounter_OPTIONAL_ARGC));
#endif
#if BIND_PR_DestroyLock_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_DestroyLock", mrb_NSPR_PR_DestroyLock, MRB_ARGS_ARG(PR_DestroyLock_REQUIRED_ARGC, PR_DestroyLock_OPTIONAL_ARGC));
#endif
#if BIND_PR_DestroyMonitor_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_DestroyMonitor", mrb_NSPR_PR_DestroyMonitor, MRB_ARGS_ARG(PR_DestroyMonitor_REQUIRED_ARGC, PR_DestroyMonitor_OPTIONAL_ARGC));
#endif
#if BIND_PR_DestroyMWaitEnumerator_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_DestroyMWaitEnumerator", mrb_NSPR_PR_DestroyMWaitEnumerator, MRB_ARGS_ARG(PR_DestroyMWaitEnumerator_REQUIRED_ARGC, PR_DestroyMWaitEnumerator_OPTIONAL_ARGC));
#endif
#if BIND_PR_DestroyOrderedLock_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_DestroyOrderedLock", mrb_NSPR_PR_DestroyOrderedLock, MRB_ARGS_ARG(PR_DestroyOrderedLock_REQUIRED_ARGC, PR_DestroyOrderedLock_OPTIONAL_ARGC));
#endif
#if BIND_PR_DestroyPollableEvent_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_DestroyPollableEvent", mrb_NSPR_PR_DestroyPollableEvent, MRB_ARGS_ARG(PR_DestroyPollableEvent_REQUIRED_ARGC, PR_DestroyPollableEvent_OPTIONAL_ARGC));
#endif
#if BIND_PR_DestroyProcessAttr_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_DestroyProcessAttr", mrb_NSPR_PR_DestroyProcessAttr, MRB_ARGS_ARG(PR_DestroyProcessAttr_REQUIRED_ARGC, PR_DestroyProcessAttr_OPTIONAL_ARGC));
#endif
#if BIND_PR_DestroyRWLock_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_DestroyRWLock", mrb_NSPR_PR_DestroyRWLock, MRB_ARGS_ARG(PR_DestroyRWLock_REQUIRED_ARGC, PR_DestroyRWLock_OPTIONAL_ARGC));
#endif
#if BIND_PR_DestroyStack_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_DestroyStack", mrb_NSPR_PR_DestroyStack, MRB_ARGS_ARG(PR_DestroyStack_REQUIRED_ARGC, PR_DestroyStack_OPTIONAL_ARGC));
#endif
#if BIND_PR_DestroyTrace_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_DestroyTrace", mrb_NSPR_PR_DestroyTrace, MRB_ARGS_ARG(PR_DestroyTrace_REQUIRED_ARGC, PR_DestroyTrace_OPTIONAL_ARGC));
#endif
#if BIND_PR_DestroyWaitGroup_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_DestroyWaitGroup", mrb_NSPR_PR_DestroyWaitGroup, MRB_ARGS_ARG(PR_DestroyWaitGroup_REQUIRED_ARGC, PR_DestroyWaitGroup_OPTIONAL_ARGC));
#endif
#if BIND_PR_DetachProcess_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_DetachProcess", mrb_NSPR_PR_DetachProcess, MRB_ARGS_ARG(PR_DetachProcess_REQUIRED_ARGC, PR_DetachProcess_OPTIONAL_ARGC));
#endif
#if BIND_PR_DetachSharedMemory_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_DetachSharedMemory", mrb_NSPR_PR_DetachSharedMemory, MRB_ARGS_ARG(PR_DetachSharedMemory_REQUIRED_ARGC, PR_DetachSharedMemory_OPTIONAL_ARGC));
#endif
#if BIND_PR_DisableClockInterrupts_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_DisableClockInterrupts", mrb_NSPR_PR_DisableClockInterrupts, MRB_ARGS_ARG(PR_DisableClockInterrupts_REQUIRED_ARGC, PR_DisableClockInterrupts_OPTIONAL_ARGC));
#endif
#if BIND_PR_dtoa_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_dtoa", mrb_NSPR_PR_dtoa, MRB_ARGS_ARG(PR_dtoa_REQUIRED_ARGC, PR_dtoa_OPTIONAL_ARGC));
#endif
#if BIND_PR_EnableClockInterrupts_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_EnableClockInterrupts", mrb_NSPR_PR_EnableClockInterrupts, MRB_ARGS_ARG(PR_EnableClockInterrupts_REQUIRED_ARGC, PR_EnableClockInterrupts_OPTIONAL_ARGC));
#endif
#if BIND_PR_EnterMonitor_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_EnterMonitor", mrb_NSPR_PR_EnterMonitor, MRB_ARGS_ARG(PR_EnterMonitor_REQUIRED_ARGC, PR_EnterMonitor_OPTIONAL_ARGC));
#endif
#if BIND_PR_EnumerateAddrInfo_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_EnumerateAddrInfo", mrb_NSPR_PR_EnumerateAddrInfo, MRB_ARGS_ARG(PR_EnumerateAddrInfo_REQUIRED_ARGC, PR_EnumerateAddrInfo_OPTIONAL_ARGC));
#endif
#if BIND_PR_EnumerateHostEnt_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_EnumerateHostEnt", mrb_NSPR_PR_EnumerateHostEnt, MRB_ARGS_ARG(PR_EnumerateHostEnt_REQUIRED_ARGC, PR_EnumerateHostEnt_OPTIONAL_ARGC));
#endif
#if BIND_PR_EnumerateWaitGroup_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_EnumerateWaitGroup", mrb_NSPR_PR_EnumerateWaitGroup, MRB_ARGS_ARG(PR_EnumerateWaitGroup_REQUIRED_ARGC, PR_EnumerateWaitGroup_OPTIONAL_ARGC));
#endif
#if BIND_PR_ErrorInstallCallback_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ErrorInstallCallback", mrb_NSPR_PR_ErrorInstallCallback, MRB_ARGS_ARG(PR_ErrorInstallCallback_REQUIRED_ARGC, PR_ErrorInstallCallback_OPTIONAL_ARGC));
#endif
#if BIND_PR_ErrorInstallTable_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ErrorInstallTable", mrb_NSPR_PR_ErrorInstallTable, MRB_ARGS_ARG(PR_ErrorInstallTable_REQUIRED_ARGC, PR_ErrorInstallTable_OPTIONAL_ARGC));
#endif
#if BIND_PR_ErrorLanguages_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ErrorLanguages", mrb_NSPR_PR_ErrorLanguages, MRB_ARGS_ARG(PR_ErrorLanguages_REQUIRED_ARGC, PR_ErrorLanguages_OPTIONAL_ARGC));
#endif
#if BIND_PR_ErrorToName_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ErrorToName", mrb_NSPR_PR_ErrorToName, MRB_ARGS_ARG(PR_ErrorToName_REQUIRED_ARGC, PR_ErrorToName_OPTIONAL_ARGC));
#endif
#if BIND_PR_ErrorToString_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ErrorToString", mrb_NSPR_PR_ErrorToString, MRB_ARGS_ARG(PR_ErrorToString_REQUIRED_ARGC, PR_ErrorToString_OPTIONAL_ARGC));
#endif
#if BIND_PR_ExitMonitor_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ExitMonitor", mrb_NSPR_PR_ExitMonitor, MRB_ARGS_ARG(PR_ExitMonitor_REQUIRED_ARGC, PR_ExitMonitor_OPTIONAL_ARGC));
#endif
#if BIND_PR_ExplodeTime_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ExplodeTime", mrb_NSPR_PR_ExplodeTime, MRB_ARGS_ARG(PR_ExplodeTime_REQUIRED_ARGC, PR_ExplodeTime_OPTIONAL_ARGC));
#endif
#if BIND_PR_ExportFileMapAsString_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ExportFileMapAsString", mrb_NSPR_PR_ExportFileMapAsString, MRB_ARGS_ARG(PR_ExportFileMapAsString_REQUIRED_ARGC, PR_ExportFileMapAsString_OPTIONAL_ARGC));
#endif
#if BIND_PR_FindFunctionSymbol_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_FindFunctionSymbol", mrb_NSPR_PR_FindFunctionSymbol, MRB_ARGS_ARG(PR_FindFunctionSymbol_REQUIRED_ARGC, PR_FindFunctionSymbol_OPTIONAL_ARGC));
#endif
#if BIND_PR_FindFunctionSymbolAndLibrary_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_FindFunctionSymbolAndLibrary", mrb_NSPR_PR_FindFunctionSymbolAndLibrary, MRB_ARGS_ARG(PR_FindFunctionSymbolAndLibrary_REQUIRED_ARGC, PR_FindFunctionSymbolAndLibrary_OPTIONAL_ARGC));
#endif
#if BIND_PR_FindNextCounterQname_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_FindNextCounterQname", mrb_NSPR_PR_FindNextCounterQname, MRB_ARGS_ARG(PR_FindNextCounterQname_REQUIRED_ARGC, PR_FindNextCounterQname_OPTIONAL_ARGC));
#endif
#if BIND_PR_FindNextCounterRname_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_FindNextCounterRname", mrb_NSPR_PR_FindNextCounterRname, MRB_ARGS_ARG(PR_FindNextCounterRname_REQUIRED_ARGC, PR_FindNextCounterRname_OPTIONAL_ARGC));
#endif
#if BIND_PR_FindNextTraceQname_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_FindNextTraceQname", mrb_NSPR_PR_FindNextTraceQname, MRB_ARGS_ARG(PR_FindNextTraceQname_REQUIRED_ARGC, PR_FindNextTraceQname_OPTIONAL_ARGC));
#endif
#if BIND_PR_FindNextTraceRname_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_FindNextTraceRname", mrb_NSPR_PR_FindNextTraceRname, MRB_ARGS_ARG(PR_FindNextTraceRname_REQUIRED_ARGC, PR_FindNextTraceRname_OPTIONAL_ARGC));
#endif
#if BIND_PR_FindSymbol_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_FindSymbol", mrb_NSPR_PR_FindSymbol, MRB_ARGS_ARG(PR_FindSymbol_REQUIRED_ARGC, PR_FindSymbol_OPTIONAL_ARGC));
#endif
#if BIND_PR_FindSymbolAndLibrary_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_FindSymbolAndLibrary", mrb_NSPR_PR_FindSymbolAndLibrary, MRB_ARGS_ARG(PR_FindSymbolAndLibrary_REQUIRED_ARGC, PR_FindSymbolAndLibrary_OPTIONAL_ARGC));
#endif
#if BIND_PR_FloorLog2_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_FloorLog2", mrb_NSPR_PR_FloorLog2, MRB_ARGS_ARG(PR_FloorLog2_REQUIRED_ARGC, PR_FloorLog2_OPTIONAL_ARGC));
#endif
#if BIND_PR_FormatTime_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_FormatTime", mrb_NSPR_PR_FormatTime, MRB_ARGS_ARG(PR_FormatTime_REQUIRED_ARGC, PR_FormatTime_OPTIONAL_ARGC));
#endif
#if BIND_PR_FormatTimeUSEnglish_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_FormatTimeUSEnglish", mrb_NSPR_PR_FormatTimeUSEnglish, MRB_ARGS_ARG(PR_FormatTimeUSEnglish_REQUIRED_ARGC, PR_FormatTimeUSEnglish_OPTIONAL_ARGC));
#endif
#if BIND_PR_fprintf_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_fprintf", mrb_NSPR_PR_fprintf, MRB_ARGS_ARG(PR_fprintf_REQUIRED_ARGC, PR_fprintf_OPTIONAL_ARGC));
#endif
#if BIND_PR_Free_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Free", mrb_NSPR_PR_Free, MRB_ARGS_ARG(PR_Free_REQUIRED_ARGC, PR_Free_OPTIONAL_ARGC));
#endif
#if BIND_PR_FreeAddrInfo_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_FreeAddrInfo", mrb_NSPR_PR_FreeAddrInfo, MRB_ARGS_ARG(PR_FreeAddrInfo_REQUIRED_ARGC, PR_FreeAddrInfo_OPTIONAL_ARGC));
#endif
#if BIND_PR_FreeLibraryName_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_FreeLibraryName", mrb_NSPR_PR_FreeLibraryName, MRB_ARGS_ARG(PR_FreeLibraryName_REQUIRED_ARGC, PR_FreeLibraryName_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetAddrInfoByName_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetAddrInfoByName", mrb_NSPR_PR_GetAddrInfoByName, MRB_ARGS_ARG(PR_GetAddrInfoByName_REQUIRED_ARGC, PR_GetAddrInfoByName_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetCanonNameFromAddrInfo_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetCanonNameFromAddrInfo", mrb_NSPR_PR_GetCanonNameFromAddrInfo, MRB_ARGS_ARG(PR_GetCanonNameFromAddrInfo_REQUIRED_ARGC, PR_GetCanonNameFromAddrInfo_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetConnectStatus_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetConnectStatus", mrb_NSPR_PR_GetConnectStatus, MRB_ARGS_ARG(PR_GetConnectStatus_REQUIRED_ARGC, PR_GetConnectStatus_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetCounter_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetCounter", mrb_NSPR_PR_GetCounter, MRB_ARGS_ARG(PR_GetCounter_REQUIRED_ARGC, PR_GetCounter_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetCounterHandleFromName_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetCounterHandleFromName", mrb_NSPR_PR_GetCounterHandleFromName, MRB_ARGS_ARG(PR_GetCounterHandleFromName_REQUIRED_ARGC, PR_GetCounterHandleFromName_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetCounterNameFromHandle_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetCounterNameFromHandle", mrb_NSPR_PR_GetCounterNameFromHandle, MRB_ARGS_ARG(PR_GetCounterNameFromHandle_REQUIRED_ARGC, PR_GetCounterNameFromHandle_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetCurrentThread_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetCurrentThread", mrb_NSPR_PR_GetCurrentThread, MRB_ARGS_ARG(PR_GetCurrentThread_REQUIRED_ARGC, PR_GetCurrentThread_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetDefaultIOMethods_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetDefaultIOMethods", mrb_NSPR_PR_GetDefaultIOMethods, MRB_ARGS_ARG(PR_GetDefaultIOMethods_REQUIRED_ARGC, PR_GetDefaultIOMethods_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetDescType_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetDescType", mrb_NSPR_PR_GetDescType, MRB_ARGS_ARG(PR_GetDescType_REQUIRED_ARGC, PR_GetDescType_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetDirectorySeparator_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetDirectorySeparator", mrb_NSPR_PR_GetDirectorySeparator, MRB_ARGS_ARG(PR_GetDirectorySeparator_REQUIRED_ARGC, PR_GetDirectorySeparator_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetDirectorySepartor_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetDirectorySepartor", mrb_NSPR_PR_GetDirectorySepartor, MRB_ARGS_ARG(PR_GetDirectorySepartor_REQUIRED_ARGC, PR_GetDirectorySepartor_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetEnv_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetEnv", mrb_NSPR_PR_GetEnv, MRB_ARGS_ARG(PR_GetEnv_REQUIRED_ARGC, PR_GetEnv_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetError_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetError", mrb_NSPR_PR_GetError, MRB_ARGS_ARG(PR_GetError_REQUIRED_ARGC, PR_GetError_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetErrorText_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetErrorText", mrb_NSPR_PR_GetErrorText, MRB_ARGS_ARG(PR_GetErrorText_REQUIRED_ARGC, PR_GetErrorText_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetErrorTextLength_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetErrorTextLength", mrb_NSPR_PR_GetErrorTextLength, MRB_ARGS_ARG(PR_GetErrorTextLength_REQUIRED_ARGC, PR_GetErrorTextLength_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetFileInfo_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetFileInfo", mrb_NSPR_PR_GetFileInfo, MRB_ARGS_ARG(PR_GetFileInfo_REQUIRED_ARGC, PR_GetFileInfo_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetFileInfo64_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetFileInfo64", mrb_NSPR_PR_GetFileInfo64, MRB_ARGS_ARG(PR_GetFileInfo64_REQUIRED_ARGC, PR_GetFileInfo64_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetHostByAddr_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetHostByAddr", mrb_NSPR_PR_GetHostByAddr, MRB_ARGS_ARG(PR_GetHostByAddr_REQUIRED_ARGC, PR_GetHostByAddr_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetHostByName_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetHostByName", mrb_NSPR_PR_GetHostByName, MRB_ARGS_ARG(PR_GetHostByName_REQUIRED_ARGC, PR_GetHostByName_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetIdentitiesLayer_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetIdentitiesLayer", mrb_NSPR_PR_GetIdentitiesLayer, MRB_ARGS_ARG(PR_GetIdentitiesLayer_REQUIRED_ARGC, PR_GetIdentitiesLayer_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetInheritedFD_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetInheritedFD", mrb_NSPR_PR_GetInheritedFD, MRB_ARGS_ARG(PR_GetInheritedFD_REQUIRED_ARGC, PR_GetInheritedFD_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetInheritedFileMap_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetInheritedFileMap", mrb_NSPR_PR_GetInheritedFileMap, MRB_ARGS_ARG(PR_GetInheritedFileMap_REQUIRED_ARGC, PR_GetInheritedFileMap_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetIPNodeByName_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetIPNodeByName", mrb_NSPR_PR_GetIPNodeByName, MRB_ARGS_ARG(PR_GetIPNodeByName_REQUIRED_ARGC, PR_GetIPNodeByName_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetLayersIdentity_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetLayersIdentity", mrb_NSPR_PR_GetLayersIdentity, MRB_ARGS_ARG(PR_GetLayersIdentity_REQUIRED_ARGC, PR_GetLayersIdentity_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetLibraryFilePathname_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetLibraryFilePathname", mrb_NSPR_PR_GetLibraryFilePathname, MRB_ARGS_ARG(PR_GetLibraryFilePathname_REQUIRED_ARGC, PR_GetLibraryFilePathname_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetLibraryName_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetLibraryName", mrb_NSPR_PR_GetLibraryName, MRB_ARGS_ARG(PR_GetLibraryName_REQUIRED_ARGC, PR_GetLibraryName_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetLibraryPath_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetLibraryPath", mrb_NSPR_PR_GetLibraryPath, MRB_ARGS_ARG(PR_GetLibraryPath_REQUIRED_ARGC, PR_GetLibraryPath_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetMemMapAlignment_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetMemMapAlignment", mrb_NSPR_PR_GetMemMapAlignment, MRB_ARGS_ARG(PR_GetMemMapAlignment_REQUIRED_ARGC, PR_GetMemMapAlignment_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetNameForIdentity_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetNameForIdentity", mrb_NSPR_PR_GetNameForIdentity, MRB_ARGS_ARG(PR_GetNameForIdentity_REQUIRED_ARGC, PR_GetNameForIdentity_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetNumberOfProcessors_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetNumberOfProcessors", mrb_NSPR_PR_GetNumberOfProcessors, MRB_ARGS_ARG(PR_GetNumberOfProcessors_REQUIRED_ARGC, PR_GetNumberOfProcessors_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetOpenFileInfo_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetOpenFileInfo", mrb_NSPR_PR_GetOpenFileInfo, MRB_ARGS_ARG(PR_GetOpenFileInfo_REQUIRED_ARGC, PR_GetOpenFileInfo_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetOpenFileInfo64_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetOpenFileInfo64", mrb_NSPR_PR_GetOpenFileInfo64, MRB_ARGS_ARG(PR_GetOpenFileInfo64_REQUIRED_ARGC, PR_GetOpenFileInfo64_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetOSError_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetOSError", mrb_NSPR_PR_GetOSError, MRB_ARGS_ARG(PR_GetOSError_REQUIRED_ARGC, PR_GetOSError_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetPageShift_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetPageShift", mrb_NSPR_PR_GetPageShift, MRB_ARGS_ARG(PR_GetPageShift_REQUIRED_ARGC, PR_GetPageShift_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetPageSize_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetPageSize", mrb_NSPR_PR_GetPageSize, MRB_ARGS_ARG(PR_GetPageSize_REQUIRED_ARGC, PR_GetPageSize_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetPathSeparator_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetPathSeparator", mrb_NSPR_PR_GetPathSeparator, MRB_ARGS_ARG(PR_GetPathSeparator_REQUIRED_ARGC, PR_GetPathSeparator_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetPeerName_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetPeerName", mrb_NSPR_PR_GetPeerName, MRB_ARGS_ARG(PR_GetPeerName_REQUIRED_ARGC, PR_GetPeerName_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetPhysicalMemorySize_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetPhysicalMemorySize", mrb_NSPR_PR_GetPhysicalMemorySize, MRB_ARGS_ARG(PR_GetPhysicalMemorySize_REQUIRED_ARGC, PR_GetPhysicalMemorySize_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetProtoByName_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetProtoByName", mrb_NSPR_PR_GetProtoByName, MRB_ARGS_ARG(PR_GetProtoByName_REQUIRED_ARGC, PR_GetProtoByName_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetProtoByNumber_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetProtoByNumber", mrb_NSPR_PR_GetProtoByNumber, MRB_ARGS_ARG(PR_GetProtoByNumber_REQUIRED_ARGC, PR_GetProtoByNumber_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetRandomNoise_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetRandomNoise", mrb_NSPR_PR_GetRandomNoise, MRB_ARGS_ARG(PR_GetRandomNoise_REQUIRED_ARGC, PR_GetRandomNoise_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetSocketOption_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetSocketOption", mrb_NSPR_PR_GetSocketOption, MRB_ARGS_ARG(PR_GetSocketOption_REQUIRED_ARGC, PR_GetSocketOption_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetSockName_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetSockName", mrb_NSPR_PR_GetSockName, MRB_ARGS_ARG(PR_GetSockName_REQUIRED_ARGC, PR_GetSockName_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetSpecialFD_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetSpecialFD", mrb_NSPR_PR_GetSpecialFD, MRB_ARGS_ARG(PR_GetSpecialFD_REQUIRED_ARGC, PR_GetSpecialFD_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetSystemInfo_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetSystemInfo", mrb_NSPR_PR_GetSystemInfo, MRB_ARGS_ARG(PR_GetSystemInfo_REQUIRED_ARGC, PR_GetSystemInfo_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetThreadName_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetThreadName", mrb_NSPR_PR_GetThreadName, MRB_ARGS_ARG(PR_GetThreadName_REQUIRED_ARGC, PR_GetThreadName_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetThreadPriority_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetThreadPriority", mrb_NSPR_PR_GetThreadPriority, MRB_ARGS_ARG(PR_GetThreadPriority_REQUIRED_ARGC, PR_GetThreadPriority_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetThreadPrivate_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetThreadPrivate", mrb_NSPR_PR_GetThreadPrivate, MRB_ARGS_ARG(PR_GetThreadPrivate_REQUIRED_ARGC, PR_GetThreadPrivate_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetThreadScope_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetThreadScope", mrb_NSPR_PR_GetThreadScope, MRB_ARGS_ARG(PR_GetThreadScope_REQUIRED_ARGC, PR_GetThreadScope_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetThreadState_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetThreadState", mrb_NSPR_PR_GetThreadState, MRB_ARGS_ARG(PR_GetThreadState_REQUIRED_ARGC, PR_GetThreadState_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetThreadType_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetThreadType", mrb_NSPR_PR_GetThreadType, MRB_ARGS_ARG(PR_GetThreadType_REQUIRED_ARGC, PR_GetThreadType_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetTraceEntries_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetTraceEntries", mrb_NSPR_PR_GetTraceEntries, MRB_ARGS_ARG(PR_GetTraceEntries_REQUIRED_ARGC, PR_GetTraceEntries_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetTraceHandleFromName_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetTraceHandleFromName", mrb_NSPR_PR_GetTraceHandleFromName, MRB_ARGS_ARG(PR_GetTraceHandleFromName_REQUIRED_ARGC, PR_GetTraceHandleFromName_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetTraceNameFromHandle_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetTraceNameFromHandle", mrb_NSPR_PR_GetTraceNameFromHandle, MRB_ARGS_ARG(PR_GetTraceNameFromHandle_REQUIRED_ARGC, PR_GetTraceNameFromHandle_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetTraceOption_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetTraceOption", mrb_NSPR_PR_GetTraceOption, MRB_ARGS_ARG(PR_GetTraceOption_REQUIRED_ARGC, PR_GetTraceOption_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetUniqueIdentity_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetUniqueIdentity", mrb_NSPR_PR_GetUniqueIdentity, MRB_ARGS_ARG(PR_GetUniqueIdentity_REQUIRED_ARGC, PR_GetUniqueIdentity_OPTIONAL_ARGC));
#endif
#if BIND_PR_GetVersion_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GetVersion", mrb_NSPR_PR_GetVersion, MRB_ARGS_ARG(PR_GetVersion_REQUIRED_ARGC, PR_GetVersion_OPTIONAL_ARGC));
#endif
#if BIND_PR_GMTParameters_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_GMTParameters", mrb_NSPR_PR_GMTParameters, MRB_ARGS_ARG(PR_GMTParameters_REQUIRED_ARGC, PR_GMTParameters_OPTIONAL_ARGC));
#endif
#if BIND_PR_htonl_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_htonl", mrb_NSPR_PR_htonl, MRB_ARGS_ARG(PR_htonl_REQUIRED_ARGC, PR_htonl_OPTIONAL_ARGC));
#endif
#if BIND_PR_htonll_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_htonll", mrb_NSPR_PR_htonll, MRB_ARGS_ARG(PR_htonll_REQUIRED_ARGC, PR_htonll_OPTIONAL_ARGC));
#endif
#if BIND_PR_htons_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_htons", mrb_NSPR_PR_htons, MRB_ARGS_ARG(PR_htons_REQUIRED_ARGC, PR_htons_OPTIONAL_ARGC));
#endif
#if BIND_PR_ImplodeTime_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ImplodeTime", mrb_NSPR_PR_ImplodeTime, MRB_ARGS_ARG(PR_ImplodeTime_REQUIRED_ARGC, PR_ImplodeTime_OPTIONAL_ARGC));
#endif
#if BIND_PR_ImportFileMapFromString_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ImportFileMapFromString", mrb_NSPR_PR_ImportFileMapFromString, MRB_ARGS_ARG(PR_ImportFileMapFromString_REQUIRED_ARGC, PR_ImportFileMapFromString_OPTIONAL_ARGC));
#endif
#if BIND_PR_IncrementCounter_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_IncrementCounter", mrb_NSPR_PR_IncrementCounter, MRB_ARGS_ARG(PR_IncrementCounter_REQUIRED_ARGC, PR_IncrementCounter_OPTIONAL_ARGC));
#endif
#if BIND_PR_Init_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Init", mrb_NSPR_PR_Init, MRB_ARGS_ARG(PR_Init_REQUIRED_ARGC, PR_Init_OPTIONAL_ARGC));
#endif
#if BIND_PR_Initialize_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Initialize", mrb_NSPR_PR_Initialize, MRB_ARGS_ARG(PR_Initialize_REQUIRED_ARGC, PR_Initialize_OPTIONAL_ARGC));
#endif
#if BIND_PR_Initialized_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Initialized", mrb_NSPR_PR_Initialized, MRB_ARGS_ARG(PR_Initialized_REQUIRED_ARGC, PR_Initialized_OPTIONAL_ARGC));
#endif
#if BIND_PR_InitializeNetAddr_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_InitializeNetAddr", mrb_NSPR_PR_InitializeNetAddr, MRB_ARGS_ARG(PR_InitializeNetAddr_REQUIRED_ARGC, PR_InitializeNetAddr_OPTIONAL_ARGC));
#endif
#if BIND_PR_Interrupt_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Interrupt", mrb_NSPR_PR_Interrupt, MRB_ARGS_ARG(PR_Interrupt_REQUIRED_ARGC, PR_Interrupt_OPTIONAL_ARGC));
#endif
#if BIND_PR_IntervalNow_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_IntervalNow", mrb_NSPR_PR_IntervalNow, MRB_ARGS_ARG(PR_IntervalNow_REQUIRED_ARGC, PR_IntervalNow_OPTIONAL_ARGC));
#endif
#if BIND_PR_IntervalToMicroseconds_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_IntervalToMicroseconds", mrb_NSPR_PR_IntervalToMicroseconds, MRB_ARGS_ARG(PR_IntervalToMicroseconds_REQUIRED_ARGC, PR_IntervalToMicroseconds_OPTIONAL_ARGC));
#endif
#if BIND_PR_IntervalToMilliseconds_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_IntervalToMilliseconds", mrb_NSPR_PR_IntervalToMilliseconds, MRB_ARGS_ARG(PR_IntervalToMilliseconds_REQUIRED_ARGC, PR_IntervalToMilliseconds_OPTIONAL_ARGC));
#endif
#if BIND_PR_IntervalToSeconds_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_IntervalToSeconds", mrb_NSPR_PR_IntervalToSeconds, MRB_ARGS_ARG(PR_IntervalToSeconds_REQUIRED_ARGC, PR_IntervalToSeconds_OPTIONAL_ARGC));
#endif
#if BIND_PR_IsNetAddrType_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_IsNetAddrType", mrb_NSPR_PR_IsNetAddrType, MRB_ARGS_ARG(PR_IsNetAddrType_REQUIRED_ARGC, PR_IsNetAddrType_OPTIONAL_ARGC));
#endif
#if BIND_PR_JoinJob_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_JoinJob", mrb_NSPR_PR_JoinJob, MRB_ARGS_ARG(PR_JoinJob_REQUIRED_ARGC, PR_JoinJob_OPTIONAL_ARGC));
#endif
#if BIND_PR_JoinThread_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_JoinThread", mrb_NSPR_PR_JoinThread, MRB_ARGS_ARG(PR_JoinThread_REQUIRED_ARGC, PR_JoinThread_OPTIONAL_ARGC));
#endif
#if BIND_PR_JoinThreadPool_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_JoinThreadPool", mrb_NSPR_PR_JoinThreadPool, MRB_ARGS_ARG(PR_JoinThreadPool_REQUIRED_ARGC, PR_JoinThreadPool_OPTIONAL_ARGC));
#endif
#if BIND_PR_KillProcess_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_KillProcess", mrb_NSPR_PR_KillProcess, MRB_ARGS_ARG(PR_KillProcess_REQUIRED_ARGC, PR_KillProcess_OPTIONAL_ARGC));
#endif
#if BIND_PR_Listen_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Listen", mrb_NSPR_PR_Listen, MRB_ARGS_ARG(PR_Listen_REQUIRED_ARGC, PR_Listen_OPTIONAL_ARGC));
#endif
#if BIND_PR_LoadLibrary_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_LoadLibrary", mrb_NSPR_PR_LoadLibrary, MRB_ARGS_ARG(PR_LoadLibrary_REQUIRED_ARGC, PR_LoadLibrary_OPTIONAL_ARGC));
#endif
#if BIND_PR_LoadLibraryWithFlags_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_LoadLibraryWithFlags", mrb_NSPR_PR_LoadLibraryWithFlags, MRB_ARGS_ARG(PR_LoadLibraryWithFlags_REQUIRED_ARGC, PR_LoadLibraryWithFlags_OPTIONAL_ARGC));
#endif
#if BIND_PR_LoadStaticLibrary_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_LoadStaticLibrary", mrb_NSPR_PR_LoadStaticLibrary, MRB_ARGS_ARG(PR_LoadStaticLibrary_REQUIRED_ARGC, PR_LoadStaticLibrary_OPTIONAL_ARGC));
#endif
#if BIND_PR_LocalTimeParameters_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_LocalTimeParameters", mrb_NSPR_PR_LocalTimeParameters, MRB_ARGS_ARG(PR_LocalTimeParameters_REQUIRED_ARGC, PR_LocalTimeParameters_OPTIONAL_ARGC));
#endif
#if BIND_PR_Lock_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Lock", mrb_NSPR_PR_Lock, MRB_ARGS_ARG(PR_Lock_REQUIRED_ARGC, PR_Lock_OPTIONAL_ARGC));
#endif
#if BIND_PR_LockOrderedLock_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_LockOrderedLock", mrb_NSPR_PR_LockOrderedLock, MRB_ARGS_ARG(PR_LockOrderedLock_REQUIRED_ARGC, PR_LockOrderedLock_OPTIONAL_ARGC));
#endif
#if BIND_PR_LogFlush_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_LogFlush", mrb_NSPR_PR_LogFlush, MRB_ARGS_ARG(PR_LogFlush_REQUIRED_ARGC, PR_LogFlush_OPTIONAL_ARGC));
#endif
#if BIND_PR_LogPrint_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_LogPrint", mrb_NSPR_PR_LogPrint, MRB_ARGS_ARG(PR_LogPrint_REQUIRED_ARGC, PR_LogPrint_OPTIONAL_ARGC));
#endif
#if BIND_PR_MakeDir_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_MakeDir", mrb_NSPR_PR_MakeDir, MRB_ARGS_ARG(PR_MakeDir_REQUIRED_ARGC, PR_MakeDir_OPTIONAL_ARGC));
#endif
#if BIND_PR_Malloc_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Malloc", mrb_NSPR_PR_Malloc, MRB_ARGS_ARG(PR_Malloc_REQUIRED_ARGC, PR_Malloc_OPTIONAL_ARGC));
#endif
#if BIND_PR_MemMap_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_MemMap", mrb_NSPR_PR_MemMap, MRB_ARGS_ARG(PR_MemMap_REQUIRED_ARGC, PR_MemMap_OPTIONAL_ARGC));
#endif
#if BIND_PR_MemUnmap_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_MemUnmap", mrb_NSPR_PR_MemUnmap, MRB_ARGS_ARG(PR_MemUnmap_REQUIRED_ARGC, PR_MemUnmap_OPTIONAL_ARGC));
#endif
#if BIND_PR_MicrosecondsToInterval_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_MicrosecondsToInterval", mrb_NSPR_PR_MicrosecondsToInterval, MRB_ARGS_ARG(PR_MicrosecondsToInterval_REQUIRED_ARGC, PR_MicrosecondsToInterval_OPTIONAL_ARGC));
#endif
#if BIND_PR_MillisecondsToInterval_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_MillisecondsToInterval", mrb_NSPR_PR_MillisecondsToInterval, MRB_ARGS_ARG(PR_MillisecondsToInterval_REQUIRED_ARGC, PR_MillisecondsToInterval_OPTIONAL_ARGC));
#endif
#if BIND_PR_MkDir_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_MkDir", mrb_NSPR_PR_MkDir, MRB_ARGS_ARG(PR_MkDir_REQUIRED_ARGC, PR_MkDir_OPTIONAL_ARGC));
#endif
#if BIND_PR_NetAddrToString_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_NetAddrToString", mrb_NSPR_PR_NetAddrToString, MRB_ARGS_ARG(PR_NetAddrToString_REQUIRED_ARGC, PR_NetAddrToString_OPTIONAL_ARGC));
#endif
#if BIND_PR_NewCondVar_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_NewCondVar", mrb_NSPR_PR_NewCondVar, MRB_ARGS_ARG(PR_NewCondVar_REQUIRED_ARGC, PR_NewCondVar_OPTIONAL_ARGC));
#endif
#if BIND_PR_NewLock_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_NewLock", mrb_NSPR_PR_NewLock, MRB_ARGS_ARG(PR_NewLock_REQUIRED_ARGC, PR_NewLock_OPTIONAL_ARGC));
#endif
#if BIND_PR_NewLogModule_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_NewLogModule", mrb_NSPR_PR_NewLogModule, MRB_ARGS_ARG(PR_NewLogModule_REQUIRED_ARGC, PR_NewLogModule_OPTIONAL_ARGC));
#endif
#if BIND_PR_NewMonitor_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_NewMonitor", mrb_NSPR_PR_NewMonitor, MRB_ARGS_ARG(PR_NewMonitor_REQUIRED_ARGC, PR_NewMonitor_OPTIONAL_ARGC));
#endif
#if BIND_PR_NewPollableEvent_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_NewPollableEvent", mrb_NSPR_PR_NewPollableEvent, MRB_ARGS_ARG(PR_NewPollableEvent_REQUIRED_ARGC, PR_NewPollableEvent_OPTIONAL_ARGC));
#endif
#if BIND_PR_NewProcessAttr_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_NewProcessAttr", mrb_NSPR_PR_NewProcessAttr, MRB_ARGS_ARG(PR_NewProcessAttr_REQUIRED_ARGC, PR_NewProcessAttr_OPTIONAL_ARGC));
#endif
#if BIND_PR_NewRWLock_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_NewRWLock", mrb_NSPR_PR_NewRWLock, MRB_ARGS_ARG(PR_NewRWLock_REQUIRED_ARGC, PR_NewRWLock_OPTIONAL_ARGC));
#endif
#if BIND_PR_NewTCPSocket_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_NewTCPSocket", mrb_NSPR_PR_NewTCPSocket, MRB_ARGS_ARG(PR_NewTCPSocket_REQUIRED_ARGC, PR_NewTCPSocket_OPTIONAL_ARGC));
#endif
#if BIND_PR_NewTCPSocketPair_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_NewTCPSocketPair", mrb_NSPR_PR_NewTCPSocketPair, MRB_ARGS_ARG(PR_NewTCPSocketPair_REQUIRED_ARGC, PR_NewTCPSocketPair_OPTIONAL_ARGC));
#endif
#if BIND_PR_NewThreadPrivateIndex_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_NewThreadPrivateIndex", mrb_NSPR_PR_NewThreadPrivateIndex, MRB_ARGS_ARG(PR_NewThreadPrivateIndex_REQUIRED_ARGC, PR_NewThreadPrivateIndex_OPTIONAL_ARGC));
#endif
#if BIND_PR_NewUDPSocket_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_NewUDPSocket", mrb_NSPR_PR_NewUDPSocket, MRB_ARGS_ARG(PR_NewUDPSocket_REQUIRED_ARGC, PR_NewUDPSocket_OPTIONAL_ARGC));
#endif
#if BIND_PR_NormalizeTime_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_NormalizeTime", mrb_NSPR_PR_NormalizeTime, MRB_ARGS_ARG(PR_NormalizeTime_REQUIRED_ARGC, PR_NormalizeTime_OPTIONAL_ARGC));
#endif
#if BIND_PR_Notify_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Notify", mrb_NSPR_PR_Notify, MRB_ARGS_ARG(PR_Notify_REQUIRED_ARGC, PR_Notify_OPTIONAL_ARGC));
#endif
#if BIND_PR_NotifyAll_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_NotifyAll", mrb_NSPR_PR_NotifyAll, MRB_ARGS_ARG(PR_NotifyAll_REQUIRED_ARGC, PR_NotifyAll_OPTIONAL_ARGC));
#endif
#if BIND_PR_NotifyAllCondVar_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_NotifyAllCondVar", mrb_NSPR_PR_NotifyAllCondVar, MRB_ARGS_ARG(PR_NotifyAllCondVar_REQUIRED_ARGC, PR_NotifyAllCondVar_OPTIONAL_ARGC));
#endif
#if BIND_PR_NotifyCondVar_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_NotifyCondVar", mrb_NSPR_PR_NotifyCondVar, MRB_ARGS_ARG(PR_NotifyCondVar_REQUIRED_ARGC, PR_NotifyCondVar_OPTIONAL_ARGC));
#endif
#if BIND_PR_Now_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Now", mrb_NSPR_PR_Now, MRB_ARGS_ARG(PR_Now_REQUIRED_ARGC, PR_Now_OPTIONAL_ARGC));
#endif
#if BIND_PR_ntohl_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ntohl", mrb_NSPR_PR_ntohl, MRB_ARGS_ARG(PR_ntohl_REQUIRED_ARGC, PR_ntohl_OPTIONAL_ARGC));
#endif
#if BIND_PR_ntohll_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ntohll", mrb_NSPR_PR_ntohll, MRB_ARGS_ARG(PR_ntohll_REQUIRED_ARGC, PR_ntohll_OPTIONAL_ARGC));
#endif
#if BIND_PR_ntohs_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ntohs", mrb_NSPR_PR_ntohs, MRB_ARGS_ARG(PR_ntohs_REQUIRED_ARGC, PR_ntohs_OPTIONAL_ARGC));
#endif
#if BIND_PR_Open_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Open", mrb_NSPR_PR_Open, MRB_ARGS_ARG(PR_Open_REQUIRED_ARGC, PR_Open_OPTIONAL_ARGC));
#endif
#if BIND_PR_OpenAnonFileMap_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_OpenAnonFileMap", mrb_NSPR_PR_OpenAnonFileMap, MRB_ARGS_ARG(PR_OpenAnonFileMap_REQUIRED_ARGC, PR_OpenAnonFileMap_OPTIONAL_ARGC));
#endif
#if BIND_PR_OpenDir_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_OpenDir", mrb_NSPR_PR_OpenDir, MRB_ARGS_ARG(PR_OpenDir_REQUIRED_ARGC, PR_OpenDir_OPTIONAL_ARGC));
#endif
#if BIND_PR_OpenFile_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_OpenFile", mrb_NSPR_PR_OpenFile, MRB_ARGS_ARG(PR_OpenFile_REQUIRED_ARGC, PR_OpenFile_OPTIONAL_ARGC));
#endif
#if BIND_PR_OpenSemaphore_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_OpenSemaphore", mrb_NSPR_PR_OpenSemaphore, MRB_ARGS_ARG(PR_OpenSemaphore_REQUIRED_ARGC, PR_OpenSemaphore_OPTIONAL_ARGC));
#endif
#if BIND_PR_OpenSharedMemory_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_OpenSharedMemory", mrb_NSPR_PR_OpenSharedMemory, MRB_ARGS_ARG(PR_OpenSharedMemory_REQUIRED_ARGC, PR_OpenSharedMemory_OPTIONAL_ARGC));
#endif
#if BIND_PR_OpenTCPSocket_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_OpenTCPSocket", mrb_NSPR_PR_OpenTCPSocket, MRB_ARGS_ARG(PR_OpenTCPSocket_REQUIRED_ARGC, PR_OpenTCPSocket_OPTIONAL_ARGC));
#endif
#if BIND_PR_OpenUDPSocket_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_OpenUDPSocket", mrb_NSPR_PR_OpenUDPSocket, MRB_ARGS_ARG(PR_OpenUDPSocket_REQUIRED_ARGC, PR_OpenUDPSocket_OPTIONAL_ARGC));
#endif
#if BIND_PR_ParseTimeString_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ParseTimeString", mrb_NSPR_PR_ParseTimeString, MRB_ARGS_ARG(PR_ParseTimeString_REQUIRED_ARGC, PR_ParseTimeString_OPTIONAL_ARGC));
#endif
#if BIND_PR_ParseTimeStringToExplodedTime_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ParseTimeStringToExplodedTime", mrb_NSPR_PR_ParseTimeStringToExplodedTime, MRB_ARGS_ARG(PR_ParseTimeStringToExplodedTime_REQUIRED_ARGC, PR_ParseTimeStringToExplodedTime_OPTIONAL_ARGC));
#endif
#if BIND_PR_Poll_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Poll", mrb_NSPR_PR_Poll, MRB_ARGS_ARG(PR_Poll_REQUIRED_ARGC, PR_Poll_OPTIONAL_ARGC));
#endif
#if BIND_PR_PopIOLayer_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_PopIOLayer", mrb_NSPR_PR_PopIOLayer, MRB_ARGS_ARG(PR_PopIOLayer_REQUIRED_ARGC, PR_PopIOLayer_OPTIONAL_ARGC));
#endif
#if BIND_PR_PostSemaphore_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_PostSemaphore", mrb_NSPR_PR_PostSemaphore, MRB_ARGS_ARG(PR_PostSemaphore_REQUIRED_ARGC, PR_PostSemaphore_OPTIONAL_ARGC));
#endif
#if BIND_PR_ProcessAttrSetCurrentDirectory_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ProcessAttrSetCurrentDirectory", mrb_NSPR_PR_ProcessAttrSetCurrentDirectory, MRB_ARGS_ARG(PR_ProcessAttrSetCurrentDirectory_REQUIRED_ARGC, PR_ProcessAttrSetCurrentDirectory_OPTIONAL_ARGC));
#endif
#if BIND_PR_ProcessAttrSetInheritableFD_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ProcessAttrSetInheritableFD", mrb_NSPR_PR_ProcessAttrSetInheritableFD, MRB_ARGS_ARG(PR_ProcessAttrSetInheritableFD_REQUIRED_ARGC, PR_ProcessAttrSetInheritableFD_OPTIONAL_ARGC));
#endif
#if BIND_PR_ProcessAttrSetInheritableFileMap_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ProcessAttrSetInheritableFileMap", mrb_NSPR_PR_ProcessAttrSetInheritableFileMap, MRB_ARGS_ARG(PR_ProcessAttrSetInheritableFileMap_REQUIRED_ARGC, PR_ProcessAttrSetInheritableFileMap_OPTIONAL_ARGC));
#endif
#if BIND_PR_ProcessAttrSetStdioRedirect_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ProcessAttrSetStdioRedirect", mrb_NSPR_PR_ProcessAttrSetStdioRedirect, MRB_ARGS_ARG(PR_ProcessAttrSetStdioRedirect_REQUIRED_ARGC, PR_ProcessAttrSetStdioRedirect_OPTIONAL_ARGC));
#endif
#if BIND_PR_ProcessExit_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ProcessExit", mrb_NSPR_PR_ProcessExit, MRB_ARGS_ARG(PR_ProcessExit_REQUIRED_ARGC, PR_ProcessExit_OPTIONAL_ARGC));
#endif
#if BIND_PR_PushIOLayer_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_PushIOLayer", mrb_NSPR_PR_PushIOLayer, MRB_ARGS_ARG(PR_PushIOLayer_REQUIRED_ARGC, PR_PushIOLayer_OPTIONAL_ARGC));
#endif
#if BIND_PR_QueueJob_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_QueueJob", mrb_NSPR_PR_QueueJob, MRB_ARGS_ARG(PR_QueueJob_REQUIRED_ARGC, PR_QueueJob_OPTIONAL_ARGC));
#endif
#if BIND_PR_QueueJob_Accept_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_QueueJob_Accept", mrb_NSPR_PR_QueueJob_Accept, MRB_ARGS_ARG(PR_QueueJob_Accept_REQUIRED_ARGC, PR_QueueJob_Accept_OPTIONAL_ARGC));
#endif
#if BIND_PR_QueueJob_Connect_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_QueueJob_Connect", mrb_NSPR_PR_QueueJob_Connect, MRB_ARGS_ARG(PR_QueueJob_Connect_REQUIRED_ARGC, PR_QueueJob_Connect_OPTIONAL_ARGC));
#endif
#if BIND_PR_QueueJob_Read_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_QueueJob_Read", mrb_NSPR_PR_QueueJob_Read, MRB_ARGS_ARG(PR_QueueJob_Read_REQUIRED_ARGC, PR_QueueJob_Read_OPTIONAL_ARGC));
#endif
#if BIND_PR_QueueJob_Timer_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_QueueJob_Timer", mrb_NSPR_PR_QueueJob_Timer, MRB_ARGS_ARG(PR_QueueJob_Timer_REQUIRED_ARGC, PR_QueueJob_Timer_OPTIONAL_ARGC));
#endif
#if BIND_PR_QueueJob_Write_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_QueueJob_Write", mrb_NSPR_PR_QueueJob_Write, MRB_ARGS_ARG(PR_QueueJob_Write_REQUIRED_ARGC, PR_QueueJob_Write_OPTIONAL_ARGC));
#endif
#if BIND_PR_Read_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Read", mrb_NSPR_PR_Read, MRB_ARGS_ARG(PR_Read_REQUIRED_ARGC, PR_Read_OPTIONAL_ARGC));
#endif
#if BIND_PR_ReadDir_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ReadDir", mrb_NSPR_PR_ReadDir, MRB_ARGS_ARG(PR_ReadDir_REQUIRED_ARGC, PR_ReadDir_OPTIONAL_ARGC));
#endif
#if BIND_PR_Realloc_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Realloc", mrb_NSPR_PR_Realloc, MRB_ARGS_ARG(PR_Realloc_REQUIRED_ARGC, PR_Realloc_OPTIONAL_ARGC));
#endif
#if BIND_PR_RecordTraceEntries_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_RecordTraceEntries", mrb_NSPR_PR_RecordTraceEntries, MRB_ARGS_ARG(PR_RecordTraceEntries_REQUIRED_ARGC, PR_RecordTraceEntries_OPTIONAL_ARGC));
#endif
#if BIND_PR_Recv_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Recv", mrb_NSPR_PR_Recv, MRB_ARGS_ARG(PR_Recv_REQUIRED_ARGC, PR_Recv_OPTIONAL_ARGC));
#endif
#if BIND_PR_RecvFrom_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_RecvFrom", mrb_NSPR_PR_RecvFrom, MRB_ARGS_ARG(PR_RecvFrom_REQUIRED_ARGC, PR_RecvFrom_OPTIONAL_ARGC));
#endif
#if BIND_PR_Rename_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Rename", mrb_NSPR_PR_Rename, MRB_ARGS_ARG(PR_Rename_REQUIRED_ARGC, PR_Rename_OPTIONAL_ARGC));
#endif
#if BIND_PR_ResetProcessAttr_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ResetProcessAttr", mrb_NSPR_PR_ResetProcessAttr, MRB_ARGS_ARG(PR_ResetProcessAttr_REQUIRED_ARGC, PR_ResetProcessAttr_OPTIONAL_ARGC));
#endif
#if BIND_PR_RmDir_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_RmDir", mrb_NSPR_PR_RmDir, MRB_ARGS_ARG(PR_RmDir_REQUIRED_ARGC, PR_RmDir_OPTIONAL_ARGC));
#endif
#if BIND_PR_RWLock_Rlock_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_RWLock_Rlock", mrb_NSPR_PR_RWLock_Rlock, MRB_ARGS_ARG(PR_RWLock_Rlock_REQUIRED_ARGC, PR_RWLock_Rlock_OPTIONAL_ARGC));
#endif
#if BIND_PR_RWLock_Unlock_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_RWLock_Unlock", mrb_NSPR_PR_RWLock_Unlock, MRB_ARGS_ARG(PR_RWLock_Unlock_REQUIRED_ARGC, PR_RWLock_Unlock_OPTIONAL_ARGC));
#endif
#if BIND_PR_RWLock_Wlock_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_RWLock_Wlock", mrb_NSPR_PR_RWLock_Wlock, MRB_ARGS_ARG(PR_RWLock_Wlock_REQUIRED_ARGC, PR_RWLock_Wlock_OPTIONAL_ARGC));
#endif
#if BIND_PR_SecondsToInterval_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_SecondsToInterval", mrb_NSPR_PR_SecondsToInterval, MRB_ARGS_ARG(PR_SecondsToInterval_REQUIRED_ARGC, PR_SecondsToInterval_OPTIONAL_ARGC));
#endif
#if BIND_PR_Seek_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Seek", mrb_NSPR_PR_Seek, MRB_ARGS_ARG(PR_Seek_REQUIRED_ARGC, PR_Seek_OPTIONAL_ARGC));
#endif
#if BIND_PR_Seek64_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Seek64", mrb_NSPR_PR_Seek64, MRB_ARGS_ARG(PR_Seek64_REQUIRED_ARGC, PR_Seek64_OPTIONAL_ARGC));
#endif
#if BIND_PR_Send_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Send", mrb_NSPR_PR_Send, MRB_ARGS_ARG(PR_Send_REQUIRED_ARGC, PR_Send_OPTIONAL_ARGC));
#endif
#if BIND_PR_SendFile_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_SendFile", mrb_NSPR_PR_SendFile, MRB_ARGS_ARG(PR_SendFile_REQUIRED_ARGC, PR_SendFile_OPTIONAL_ARGC));
#endif
#if BIND_PR_SendTo_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_SendTo", mrb_NSPR_PR_SendTo, MRB_ARGS_ARG(PR_SendTo_REQUIRED_ARGC, PR_SendTo_OPTIONAL_ARGC));
#endif
#if BIND_PR_SetConcurrency_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_SetConcurrency", mrb_NSPR_PR_SetConcurrency, MRB_ARGS_ARG(PR_SetConcurrency_REQUIRED_ARGC, PR_SetConcurrency_OPTIONAL_ARGC));
#endif
#if BIND_PR_SetCounter_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_SetCounter", mrb_NSPR_PR_SetCounter, MRB_ARGS_ARG(PR_SetCounter_REQUIRED_ARGC, PR_SetCounter_OPTIONAL_ARGC));
#endif
#if BIND_PR_SetCurrentThreadName_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_SetCurrentThreadName", mrb_NSPR_PR_SetCurrentThreadName, MRB_ARGS_ARG(PR_SetCurrentThreadName_REQUIRED_ARGC, PR_SetCurrentThreadName_OPTIONAL_ARGC));
#endif
#if BIND_PR_SetEnv_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_SetEnv", mrb_NSPR_PR_SetEnv, MRB_ARGS_ARG(PR_SetEnv_REQUIRED_ARGC, PR_SetEnv_OPTIONAL_ARGC));
#endif
#if BIND_PR_SetError_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_SetError", mrb_NSPR_PR_SetError, MRB_ARGS_ARG(PR_SetError_REQUIRED_ARGC, PR_SetError_OPTIONAL_ARGC));
#endif
#if BIND_PR_SetErrorText_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_SetErrorText", mrb_NSPR_PR_SetErrorText, MRB_ARGS_ARG(PR_SetErrorText_REQUIRED_ARGC, PR_SetErrorText_OPTIONAL_ARGC));
#endif
#if BIND_PR_SetFDCacheSize_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_SetFDCacheSize", mrb_NSPR_PR_SetFDCacheSize, MRB_ARGS_ARG(PR_SetFDCacheSize_REQUIRED_ARGC, PR_SetFDCacheSize_OPTIONAL_ARGC));
#endif
#if BIND_PR_SetFDInheritable_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_SetFDInheritable", mrb_NSPR_PR_SetFDInheritable, MRB_ARGS_ARG(PR_SetFDInheritable_REQUIRED_ARGC, PR_SetFDInheritable_OPTIONAL_ARGC));
#endif
#if BIND_PR_SetLibraryPath_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_SetLibraryPath", mrb_NSPR_PR_SetLibraryPath, MRB_ARGS_ARG(PR_SetLibraryPath_REQUIRED_ARGC, PR_SetLibraryPath_OPTIONAL_ARGC));
#endif
#if BIND_PR_SetLogBuffering_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_SetLogBuffering", mrb_NSPR_PR_SetLogBuffering, MRB_ARGS_ARG(PR_SetLogBuffering_REQUIRED_ARGC, PR_SetLogBuffering_OPTIONAL_ARGC));
#endif
#if BIND_PR_SetLogFile_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_SetLogFile", mrb_NSPR_PR_SetLogFile, MRB_ARGS_ARG(PR_SetLogFile_REQUIRED_ARGC, PR_SetLogFile_OPTIONAL_ARGC));
#endif
#if BIND_PR_SetNetAddr_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_SetNetAddr", mrb_NSPR_PR_SetNetAddr, MRB_ARGS_ARG(PR_SetNetAddr_REQUIRED_ARGC, PR_SetNetAddr_OPTIONAL_ARGC));
#endif
#if BIND_PR_SetPollableEvent_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_SetPollableEvent", mrb_NSPR_PR_SetPollableEvent, MRB_ARGS_ARG(PR_SetPollableEvent_REQUIRED_ARGC, PR_SetPollableEvent_OPTIONAL_ARGC));
#endif
#if BIND_PR_SetSocketOption_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_SetSocketOption", mrb_NSPR_PR_SetSocketOption, MRB_ARGS_ARG(PR_SetSocketOption_REQUIRED_ARGC, PR_SetSocketOption_OPTIONAL_ARGC));
#endif
#if BIND_PR_SetStdioRedirect_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_SetStdioRedirect", mrb_NSPR_PR_SetStdioRedirect, MRB_ARGS_ARG(PR_SetStdioRedirect_REQUIRED_ARGC, PR_SetStdioRedirect_OPTIONAL_ARGC));
#endif
#if BIND_PR_SetThreadPriority_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_SetThreadPriority", mrb_NSPR_PR_SetThreadPriority, MRB_ARGS_ARG(PR_SetThreadPriority_REQUIRED_ARGC, PR_SetThreadPriority_OPTIONAL_ARGC));
#endif
#if BIND_PR_SetThreadPrivate_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_SetThreadPrivate", mrb_NSPR_PR_SetThreadPrivate, MRB_ARGS_ARG(PR_SetThreadPrivate_REQUIRED_ARGC, PR_SetThreadPrivate_OPTIONAL_ARGC));
#endif
#if BIND_PR_SetTraceOption_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_SetTraceOption", mrb_NSPR_PR_SetTraceOption, MRB_ARGS_ARG(PR_SetTraceOption_REQUIRED_ARGC, PR_SetTraceOption_OPTIONAL_ARGC));
#endif
#if BIND_PR_Shutdown_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Shutdown", mrb_NSPR_PR_Shutdown, MRB_ARGS_ARG(PR_Shutdown_REQUIRED_ARGC, PR_Shutdown_OPTIONAL_ARGC));
#endif
#if BIND_PR_ShutdownThreadPool_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_ShutdownThreadPool", mrb_NSPR_PR_ShutdownThreadPool, MRB_ARGS_ARG(PR_ShutdownThreadPool_REQUIRED_ARGC, PR_ShutdownThreadPool_OPTIONAL_ARGC));
#endif
#if BIND_PR_Sleep_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Sleep", mrb_NSPR_PR_Sleep, MRB_ARGS_ARG(PR_Sleep_REQUIRED_ARGC, PR_Sleep_OPTIONAL_ARGC));
#endif
#if BIND_PR_smprintf_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_smprintf", mrb_NSPR_PR_smprintf, MRB_ARGS_ARG(PR_smprintf_REQUIRED_ARGC, PR_smprintf_OPTIONAL_ARGC));
#endif
#if BIND_PR_smprintf_free_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_smprintf_free", mrb_NSPR_PR_smprintf_free, MRB_ARGS_ARG(PR_smprintf_free_REQUIRED_ARGC, PR_smprintf_free_OPTIONAL_ARGC));
#endif
#if BIND_PR_snprintf_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_snprintf", mrb_NSPR_PR_snprintf, MRB_ARGS_ARG(PR_snprintf_REQUIRED_ARGC, PR_snprintf_OPTIONAL_ARGC));
#endif
#if BIND_PR_sprintf_append_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_sprintf_append", mrb_NSPR_PR_sprintf_append, MRB_ARGS_ARG(PR_sprintf_append_REQUIRED_ARGC, PR_sprintf_append_OPTIONAL_ARGC));
#endif
#if BIND_PR_sscanf_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_sscanf", mrb_NSPR_PR_sscanf, MRB_ARGS_ARG(PR_sscanf_REQUIRED_ARGC, PR_sscanf_OPTIONAL_ARGC));
#endif
#if BIND_PR_StackPop_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_StackPop", mrb_NSPR_PR_StackPop, MRB_ARGS_ARG(PR_StackPop_REQUIRED_ARGC, PR_StackPop_OPTIONAL_ARGC));
#endif
#if BIND_PR_StackPush_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_StackPush", mrb_NSPR_PR_StackPush, MRB_ARGS_ARG(PR_StackPush_REQUIRED_ARGC, PR_StackPush_OPTIONAL_ARGC));
#endif
#if BIND_PR_StringToNetAddr_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_StringToNetAddr", mrb_NSPR_PR_StringToNetAddr, MRB_ARGS_ARG(PR_StringToNetAddr_REQUIRED_ARGC, PR_StringToNetAddr_OPTIONAL_ARGC));
#endif
#if BIND_PR_strtod_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_strtod", mrb_NSPR_PR_strtod, MRB_ARGS_ARG(PR_strtod_REQUIRED_ARGC, PR_strtod_OPTIONAL_ARGC));
#endif
#if BIND_PR_SubtractFromCounter_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_SubtractFromCounter", mrb_NSPR_PR_SubtractFromCounter, MRB_ARGS_ARG(PR_SubtractFromCounter_REQUIRED_ARGC, PR_SubtractFromCounter_OPTIONAL_ARGC));
#endif
#if BIND_PR_sxprintf_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_sxprintf", mrb_NSPR_PR_sxprintf, MRB_ARGS_ARG(PR_sxprintf_REQUIRED_ARGC, PR_sxprintf_OPTIONAL_ARGC));
#endif
#if BIND_PR_Sync_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Sync", mrb_NSPR_PR_Sync, MRB_ARGS_ARG(PR_Sync_REQUIRED_ARGC, PR_Sync_OPTIONAL_ARGC));
#endif
#if BIND_PR_SyncMemMap_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_SyncMemMap", mrb_NSPR_PR_SyncMemMap, MRB_ARGS_ARG(PR_SyncMemMap_REQUIRED_ARGC, PR_SyncMemMap_OPTIONAL_ARGC));
#endif
#if BIND_PR_TicksPerSecond_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_TicksPerSecond", mrb_NSPR_PR_TicksPerSecond, MRB_ARGS_ARG(PR_TicksPerSecond_REQUIRED_ARGC, PR_TicksPerSecond_OPTIONAL_ARGC));
#endif
#if BIND_PR_Trace_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Trace", mrb_NSPR_PR_Trace, MRB_ARGS_ARG(PR_Trace_REQUIRED_ARGC, PR_Trace_OPTIONAL_ARGC));
#endif
#if BIND_PR_TransmitFile_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_TransmitFile", mrb_NSPR_PR_TransmitFile, MRB_ARGS_ARG(PR_TransmitFile_REQUIRED_ARGC, PR_TransmitFile_OPTIONAL_ARGC));
#endif
#if BIND_PR_UnblockClockInterrupts_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_UnblockClockInterrupts", mrb_NSPR_PR_UnblockClockInterrupts, MRB_ARGS_ARG(PR_UnblockClockInterrupts_REQUIRED_ARGC, PR_UnblockClockInterrupts_OPTIONAL_ARGC));
#endif
#if BIND_PR_UnblockInterrupt_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_UnblockInterrupt", mrb_NSPR_PR_UnblockInterrupt, MRB_ARGS_ARG(PR_UnblockInterrupt_REQUIRED_ARGC, PR_UnblockInterrupt_OPTIONAL_ARGC));
#endif
#if BIND_PR_UnloadLibrary_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_UnloadLibrary", mrb_NSPR_PR_UnloadLibrary, MRB_ARGS_ARG(PR_UnloadLibrary_REQUIRED_ARGC, PR_UnloadLibrary_OPTIONAL_ARGC));
#endif
#if BIND_PR_Unlock_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Unlock", mrb_NSPR_PR_Unlock, MRB_ARGS_ARG(PR_Unlock_REQUIRED_ARGC, PR_Unlock_OPTIONAL_ARGC));
#endif
#if BIND_PR_UnlockOrderedLock_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_UnlockOrderedLock", mrb_NSPR_PR_UnlockOrderedLock, MRB_ARGS_ARG(PR_UnlockOrderedLock_REQUIRED_ARGC, PR_UnlockOrderedLock_OPTIONAL_ARGC));
#endif
#if BIND_PR_USPacificTimeParameters_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_USPacificTimeParameters", mrb_NSPR_PR_USPacificTimeParameters, MRB_ARGS_ARG(PR_USPacificTimeParameters_REQUIRED_ARGC, PR_USPacificTimeParameters_OPTIONAL_ARGC));
#endif
#if BIND_PR_VersionCheck_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_VersionCheck", mrb_NSPR_PR_VersionCheck, MRB_ARGS_ARG(PR_VersionCheck_REQUIRED_ARGC, PR_VersionCheck_OPTIONAL_ARGC));
#endif
#if BIND_PR_vfprintf_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_vfprintf", mrb_NSPR_PR_vfprintf, MRB_ARGS_ARG(PR_vfprintf_REQUIRED_ARGC, PR_vfprintf_OPTIONAL_ARGC));
#endif
#if BIND_PR_vsmprintf_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_vsmprintf", mrb_NSPR_PR_vsmprintf, MRB_ARGS_ARG(PR_vsmprintf_REQUIRED_ARGC, PR_vsmprintf_OPTIONAL_ARGC));
#endif
#if BIND_PR_vsnprintf_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_vsnprintf", mrb_NSPR_PR_vsnprintf, MRB_ARGS_ARG(PR_vsnprintf_REQUIRED_ARGC, PR_vsnprintf_OPTIONAL_ARGC));
#endif
#if BIND_PR_vsprintf_append_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_vsprintf_append", mrb_NSPR_PR_vsprintf_append, MRB_ARGS_ARG(PR_vsprintf_append_REQUIRED_ARGC, PR_vsprintf_append_OPTIONAL_ARGC));
#endif
#if BIND_PR_vsxprintf_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_vsxprintf", mrb_NSPR_PR_vsxprintf, MRB_ARGS_ARG(PR_vsxprintf_REQUIRED_ARGC, PR_vsxprintf_OPTIONAL_ARGC));
#endif
#if BIND_PR_Wait_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Wait", mrb_NSPR_PR_Wait, MRB_ARGS_ARG(PR_Wait_REQUIRED_ARGC, PR_Wait_OPTIONAL_ARGC));
#endif
#if BIND_PR_WaitCondVar_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_WaitCondVar", mrb_NSPR_PR_WaitCondVar, MRB_ARGS_ARG(PR_WaitCondVar_REQUIRED_ARGC, PR_WaitCondVar_OPTIONAL_ARGC));
#endif
#if BIND_PR_WaitForPollableEvent_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_WaitForPollableEvent", mrb_NSPR_PR_WaitForPollableEvent, MRB_ARGS_ARG(PR_WaitForPollableEvent_REQUIRED_ARGC, PR_WaitForPollableEvent_OPTIONAL_ARGC));
#endif
#if BIND_PR_WaitProcess_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_WaitProcess", mrb_NSPR_PR_WaitProcess, MRB_ARGS_ARG(PR_WaitProcess_REQUIRED_ARGC, PR_WaitProcess_OPTIONAL_ARGC));
#endif
#if BIND_PR_WaitRecvReady_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_WaitRecvReady", mrb_NSPR_PR_WaitRecvReady, MRB_ARGS_ARG(PR_WaitRecvReady_REQUIRED_ARGC, PR_WaitRecvReady_OPTIONAL_ARGC));
#endif
#if BIND_PR_WaitSemaphore_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_WaitSemaphore", mrb_NSPR_PR_WaitSemaphore, MRB_ARGS_ARG(PR_WaitSemaphore_REQUIRED_ARGC, PR_WaitSemaphore_OPTIONAL_ARGC));
#endif
#if BIND_PR_Write_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Write", mrb_NSPR_PR_Write, MRB_ARGS_ARG(PR_Write_REQUIRED_ARGC, PR_Write_OPTIONAL_ARGC));
#endif
#if BIND_PR_Writev_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PR_Writev", mrb_NSPR_PR_Writev, MRB_ARGS_ARG(PR_Writev_REQUIRED_ARGC, PR_Writev_OPTIONAL_ARGC));
#endif
#if BIND_PRP_DestroyNakedCondVar_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PRP_DestroyNakedCondVar", mrb_NSPR_PRP_DestroyNakedCondVar, MRB_ARGS_ARG(PRP_DestroyNakedCondVar_REQUIRED_ARGC, PRP_DestroyNakedCondVar_OPTIONAL_ARGC));
#endif
#if BIND_PRP_NakedBroadcast_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PRP_NakedBroadcast", mrb_NSPR_PRP_NakedBroadcast, MRB_ARGS_ARG(PRP_NakedBroadcast_REQUIRED_ARGC, PRP_NakedBroadcast_OPTIONAL_ARGC));
#endif
#if BIND_PRP_NakedNotify_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PRP_NakedNotify", mrb_NSPR_PRP_NakedNotify, MRB_ARGS_ARG(PRP_NakedNotify_REQUIRED_ARGC, PRP_NakedNotify_OPTIONAL_ARGC));
#endif
#if BIND_PRP_NakedWait_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PRP_NakedWait", mrb_NSPR_PRP_NakedWait, MRB_ARGS_ARG(PRP_NakedWait_REQUIRED_ARGC, PRP_NakedWait_OPTIONAL_ARGC));
#endif
#if BIND_PRP_NewNakedCondVar_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PRP_NewNakedCondVar", mrb_NSPR_PRP_NewNakedCondVar, MRB_ARGS_ARG(PRP_NewNakedCondVar_REQUIRED_ARGC, PRP_NewNakedCondVar_OPTIONAL_ARGC));
#endif
#if BIND_PRP_TryLock_FUNCTION
  mrb_define_class_method(mrb, NSPR_module, "PRP_TryLock", mrb_NSPR_PRP_TryLock, MRB_ARGS_ARG(PRP_TryLock_REQUIRED_ARGC, PRP_TryLock_OPTIONAL_ARGC));
#endif

}

void mrb_mruby_nspr_gem_final(mrb_state* mrb){

}

#ifdef __cplusplus
}
#endif
