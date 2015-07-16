#include "mruby_NSPR.h"

void
mruby_NSPR_define_macro_constants(mrb_state* mrb) {
  /* WARNING
   * Code generator does it's best to determine the type of the macro
   * expansions, but mistakes will be made (as macros are just text,
   * and may contain other macros). So, you'll need to verify the
   * conversions used here are of the correct type.
   */

#ifdef __PRUNICHAR__
  /* Ignoring macro with no expansion: __PRUNICHAR__ */
#endif
#ifdef _plbase64_h
  /* Ignoring macro with no expansion: _plbase64_h */
#endif
#ifdef _plstr_h
  /* Ignoring macro with no expansion: _plstr_h */
#endif
#ifdef _PR_NAKED_CV_LOCK
  /* _PR_NAKED_CV_LOCK assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "_PR_NAKED_CV_LOCK", mrb_fixnum_value(_PR_NAKED_CV_LOCK));
#endif
#ifdef _PRMWAIT_H
  /* Ignoring macro with no expansion: _PRMWAIT_H */
#endif
#ifdef _PRVERSION_H
  /* Ignoring macro with no expansion: _PRVERSION_H */
#endif
#ifdef ALIGN_OF_DOUBLE
  /* ALIGN_OF_DOUBLE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "ALIGN_OF_DOUBLE", mrb_fixnum_value(ALIGN_OF_DOUBLE));
#endif
#ifdef ALIGN_OF_FLOAT
  /* ALIGN_OF_FLOAT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "ALIGN_OF_FLOAT", mrb_fixnum_value(ALIGN_OF_FLOAT));
#endif
#ifdef ALIGN_OF_INT
  /* ALIGN_OF_INT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "ALIGN_OF_INT", mrb_fixnum_value(ALIGN_OF_INT));
#endif
#ifdef ALIGN_OF_INT64
  /* ALIGN_OF_INT64 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "ALIGN_OF_INT64", mrb_fixnum_value(ALIGN_OF_INT64));
#endif
#ifdef ALIGN_OF_LONG
  /* ALIGN_OF_LONG assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "ALIGN_OF_LONG", mrb_fixnum_value(ALIGN_OF_LONG));
#endif
#ifdef ALIGN_OF_POINTER
  /* ALIGN_OF_POINTER assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "ALIGN_OF_POINTER", mrb_fixnum_value(ALIGN_OF_POINTER));
#endif
#ifdef ALIGN_OF_SHORT
  /* ALIGN_OF_SHORT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "ALIGN_OF_SHORT", mrb_fixnum_value(ALIGN_OF_SHORT));
#endif
#ifdef ALIGN_OF_WORD
  /* ALIGN_OF_WORD assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "ALIGN_OF_WORD", mrb_fixnum_value(ALIGN_OF_WORD));
#endif
#ifdef BITS_PER_BYTE
  /* BITS_PER_BYTE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BITS_PER_BYTE", mrb_fixnum_value(BITS_PER_BYTE));
#endif
#ifdef BITS_PER_BYTE_LOG2
  /* BITS_PER_BYTE_LOG2 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BITS_PER_BYTE_LOG2", mrb_fixnum_value(BITS_PER_BYTE_LOG2));
#endif
#ifdef BITS_PER_DOUBLE
  /* BITS_PER_DOUBLE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BITS_PER_DOUBLE", mrb_fixnum_value(BITS_PER_DOUBLE));
#endif
#ifdef BITS_PER_DOUBLE_LOG2
  /* BITS_PER_DOUBLE_LOG2 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BITS_PER_DOUBLE_LOG2", mrb_fixnum_value(BITS_PER_DOUBLE_LOG2));
#endif
#ifdef BITS_PER_FLOAT
  /* BITS_PER_FLOAT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BITS_PER_FLOAT", mrb_fixnum_value(BITS_PER_FLOAT));
#endif
#ifdef BITS_PER_FLOAT_LOG2
  /* BITS_PER_FLOAT_LOG2 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BITS_PER_FLOAT_LOG2", mrb_fixnum_value(BITS_PER_FLOAT_LOG2));
#endif
#ifdef BITS_PER_INT
  /* BITS_PER_INT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BITS_PER_INT", mrb_fixnum_value(BITS_PER_INT));
#endif
#ifdef BITS_PER_INT64
  /* BITS_PER_INT64 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BITS_PER_INT64", mrb_fixnum_value(BITS_PER_INT64));
#endif
#ifdef BITS_PER_INT64_LOG2
  /* BITS_PER_INT64_LOG2 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BITS_PER_INT64_LOG2", mrb_fixnum_value(BITS_PER_INT64_LOG2));
#endif
#ifdef BITS_PER_INT_LOG2
  /* BITS_PER_INT_LOG2 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BITS_PER_INT_LOG2", mrb_fixnum_value(BITS_PER_INT_LOG2));
#endif
#ifdef BITS_PER_LONG
  /* BITS_PER_LONG assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BITS_PER_LONG", mrb_fixnum_value(BITS_PER_LONG));
#endif
#ifdef BITS_PER_LONG_LOG2
  /* BITS_PER_LONG_LOG2 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BITS_PER_LONG_LOG2", mrb_fixnum_value(BITS_PER_LONG_LOG2));
#endif
#ifdef BITS_PER_SHORT
  /* BITS_PER_SHORT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BITS_PER_SHORT", mrb_fixnum_value(BITS_PER_SHORT));
#endif
#ifdef BITS_PER_SHORT_LOG2
  /* BITS_PER_SHORT_LOG2 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BITS_PER_SHORT_LOG2", mrb_fixnum_value(BITS_PER_SHORT_LOG2));
#endif
#ifdef BITS_PER_WORD
  /* BITS_PER_WORD assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BITS_PER_WORD", mrb_fixnum_value(BITS_PER_WORD));
#endif
#ifdef BITS_PER_WORD_LOG2
  /* BITS_PER_WORD_LOG2 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BITS_PER_WORD_LOG2", mrb_fixnum_value(BITS_PER_WORD_LOG2));
#endif
#ifdef BYTES_PER_BYTE
  /* BYTES_PER_BYTE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BYTES_PER_BYTE", mrb_fixnum_value(BYTES_PER_BYTE));
#endif
#ifdef BYTES_PER_DOUBLE
  /* BYTES_PER_DOUBLE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BYTES_PER_DOUBLE", mrb_fixnum_value(BYTES_PER_DOUBLE));
#endif
#ifdef BYTES_PER_DWORD
  /* BYTES_PER_DWORD assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BYTES_PER_DWORD", mrb_fixnum_value(BYTES_PER_DWORD));
#endif
#ifdef BYTES_PER_DWORD_LOG2
  /* BYTES_PER_DWORD_LOG2 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BYTES_PER_DWORD_LOG2", mrb_fixnum_value(BYTES_PER_DWORD_LOG2));
#endif
#ifdef BYTES_PER_FLOAT
  /* BYTES_PER_FLOAT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BYTES_PER_FLOAT", mrb_fixnum_value(BYTES_PER_FLOAT));
#endif
#ifdef BYTES_PER_INT
  /* BYTES_PER_INT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BYTES_PER_INT", mrb_fixnum_value(BYTES_PER_INT));
#endif
#ifdef BYTES_PER_INT64
  /* BYTES_PER_INT64 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BYTES_PER_INT64", mrb_fixnum_value(BYTES_PER_INT64));
#endif
#ifdef BYTES_PER_LONG
  /* BYTES_PER_LONG assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BYTES_PER_LONG", mrb_fixnum_value(BYTES_PER_LONG));
#endif
#ifdef BYTES_PER_SHORT
  /* BYTES_PER_SHORT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BYTES_PER_SHORT", mrb_fixnum_value(BYTES_PER_SHORT));
#endif
#ifdef BYTES_PER_WORD
  /* BYTES_PER_WORD assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BYTES_PER_WORD", mrb_fixnum_value(BYTES_PER_WORD));
#endif
#ifdef BYTES_PER_WORD_LOG2
  /* BYTES_PER_WORD_LOG2 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "BYTES_PER_WORD_LOG2", mrb_fixnum_value(BYTES_PER_WORD_LOG2));
#endif
#ifdef ERROR_TABLE_BASE_nspr
  /* ERROR_TABLE_BASE_nspr assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "ERROR_TABLE_BASE_nspr", mrb_fixnum_value(ERROR_TABLE_BASE_nspr));
#endif
#ifdef HAVE_ALIGNED_LONGLONGS
  /* HAVE_ALIGNED_LONGLONGS assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "HAVE_ALIGNED_LONGLONGS", mrb_fixnum_value(HAVE_ALIGNED_LONGLONGS));
#endif
#ifdef HAVE_LONG_LONG
  /* Ignoring macro with no expansion: HAVE_LONG_LONG */
#endif
#ifdef HT_ENUMERATE_NEXT
  /* HT_ENUMERATE_NEXT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "HT_ENUMERATE_NEXT", mrb_fixnum_value(HT_ENUMERATE_NEXT));
#endif
#ifdef HT_ENUMERATE_REMOVE
  /* HT_ENUMERATE_REMOVE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "HT_ENUMERATE_REMOVE", mrb_fixnum_value(HT_ENUMERATE_REMOVE));
#endif
#ifdef HT_ENUMERATE_STOP
  /* HT_ENUMERATE_STOP assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "HT_ENUMERATE_STOP", mrb_fixnum_value(HT_ENUMERATE_STOP));
#endif
#ifdef HT_ENUMERATE_UNHASH
  /* HT_ENUMERATE_UNHASH assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "HT_ENUMERATE_UNHASH", mrb_fixnum_value(HT_ENUMERATE_UNHASH));
#endif
#ifdef HT_FREE_ENTRY
  /* HT_FREE_ENTRY assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "HT_FREE_ENTRY", mrb_fixnum_value(HT_FREE_ENTRY));
#endif
#ifdef HT_FREE_VALUE
  /* HT_FREE_VALUE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "HT_FREE_VALUE", mrb_fixnum_value(HT_FREE_VALUE));
#endif
#ifdef IS_64
  /* Ignoring macro with no expansion: IS_64 */
#endif
#ifdef IS_LITTLE_ENDIAN
  /* IS_LITTLE_ENDIAN assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "IS_LITTLE_ENDIAN", mrb_fixnum_value(IS_LITTLE_ENDIAN));
#endif
#ifdef LL_ADD
  /* Ignoring function-like macro: LL_ADD(r, a, b) */
#endif
#ifdef LL_AND
  /* Ignoring function-like macro: LL_AND(r, a, b) */
#endif
#ifdef LL_CMP
  /* Ignoring function-like macro: LL_CMP(a, op, b) */
#endif
#ifdef LL_D2L
  /* Ignoring function-like macro: LL_D2L(l, d) */
#endif
#ifdef LL_DIV
  /* Ignoring function-like macro: LL_DIV(r, a, b) */
#endif
#ifdef LL_EQ
  /* Ignoring function-like macro: LL_EQ(a, b) */
#endif
#ifdef LL_F2L
  /* Ignoring function-like macro: LL_F2L(l, f) */
#endif
#ifdef LL_GE_ZERO
  /* Ignoring function-like macro: LL_GE_ZERO(a) */
#endif
#ifdef LL_I2L
  /* Ignoring function-like macro: LL_I2L(l, i) */
#endif
#ifdef LL_INIT
  /* Ignoring function-like macro: LL_INIT(hi, lo) */
#endif
#ifdef LL_IS_ZERO
  /* Ignoring function-like macro: LL_IS_ZERO(a) */
#endif
#ifdef LL_ISHL
  /* Ignoring function-like macro: LL_ISHL(r, a, b) */
#endif
#ifdef LL_L2D
  /* Ignoring function-like macro: LL_L2D(d, l) */
#endif
#ifdef LL_L2F
  /* Ignoring function-like macro: LL_L2F(f, l) */
#endif
#ifdef LL_L2I
  /* Ignoring function-like macro: LL_L2I(i, l) */
#endif
#ifdef LL_L2UI
  /* Ignoring function-like macro: LL_L2UI(ui, l) */
#endif
#ifdef LL_MAXINT
  /* LL_MAXINT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "LL_MAXINT", mrb_fixnum_value(LL_MAXINT));
#endif
#ifdef LL_MAXUINT
  /* LL_MAXUINT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "LL_MAXUINT", mrb_fixnum_value(LL_MAXUINT));
#endif
#ifdef LL_MININT
  /* LL_MININT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "LL_MININT", mrb_fixnum_value(LL_MININT));
#endif
#ifdef LL_MOD
  /* Ignoring function-like macro: LL_MOD(r, a, b) */
#endif
#ifdef LL_MUL
  /* Ignoring function-like macro: LL_MUL(r, a, b) */
#endif
#ifdef LL_NE
  /* Ignoring function-like macro: LL_NE(a, b) */
#endif
#ifdef LL_NEG
  /* Ignoring function-like macro: LL_NEG(r, a) */
#endif
#ifdef LL_NOT
  /* Ignoring function-like macro: LL_NOT(r, a) */
#endif
#ifdef LL_OR
  /* Ignoring function-like macro: LL_OR(r, a, b) */
#endif
#ifdef LL_OR2
  /* Ignoring function-like macro: LL_OR2(r, a) */
#endif
#ifdef LL_SHL
  /* Ignoring function-like macro: LL_SHL(r, a, b) */
#endif
#ifdef LL_SHR
  /* Ignoring function-like macro: LL_SHR(r, a, b) */
#endif
#ifdef LL_SUB
  /* Ignoring function-like macro: LL_SUB(r, a, b) */
#endif
#ifdef LL_UCMP
  /* Ignoring function-like macro: LL_UCMP(a, op, b) */
#endif
#ifdef LL_UDIVMOD
  /* Ignoring function-like macro: LL_UDIVMOD(qp, rp, a, b) */
#endif
#ifdef LL_UI2L
  /* Ignoring function-like macro: LL_UI2L(l, ui) */
#endif
#ifdef LL_USHR
  /* Ignoring function-like macro: LL_USHR(r, a, b) */
#endif
#ifdef LL_XOR
  /* Ignoring function-like macro: LL_XOR(r, a, b) */
#endif
#ifdef LL_ZERO
  /* LL_ZERO assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "LL_ZERO", mrb_fixnum_value(LL_ZERO));
#endif
#ifdef NSPR_API
  /* Ignoring function-like macro: NSPR_API(__type) */
#endif
#ifdef NSPR_BEGIN_EXTERN_C
  /* Ignoring macro with no expansion: NSPR_BEGIN_EXTERN_C */
#endif
#ifdef NSPR_BEGIN_MACRO
  /* NSPR_BEGIN_MACRO assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "NSPR_BEGIN_MACRO", mrb_fixnum_value(NSPR_BEGIN_MACRO));
#endif
#ifdef nspr_cpucfg___
  /* Ignoring macro with no expansion: nspr_cpucfg___ */
#endif
#ifdef NSPR_DATA_API
  /* Ignoring function-like macro: NSPR_DATA_API(__type) */
#endif
#ifdef NSPR_END_EXTERN_C
  /* Ignoring macro with no expansion: NSPR_END_EXTERN_C */
#endif
#ifdef NSPR_END_MACRO
  /* NSPR_END_MACRO assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "NSPR_END_MACRO", mrb_fixnum_value(NSPR_END_MACRO));
#endif
#ifdef nspr_h___
  /* Ignoring macro with no expansion: nspr_h___ */
#endif
#ifdef PL_ARENA_ALIGN
  /* Ignoring function-like macro: PL_ARENA_ALIGN(pool, n) */
#endif
#ifdef PL_ARENA_ALLOCATE
  /* Ignoring function-like macro: PL_ARENA_ALLOCATE(p, pool, nb) */
#endif
#ifdef PL_ARENA_DESTROY
  /* Ignoring function-like macro: PL_ARENA_DESTROY(pool, a, pnext) */
#endif
#ifdef PL_ARENA_GROW
  /* Ignoring function-like macro: PL_ARENA_GROW(p, pool, size, incr) */
#endif
#ifdef PL_ARENA_MARK
  /* Ignoring function-like macro: PL_ARENA_MARK(pool) */
#endif
#ifdef PL_ARENA_RELEASE
  /* Ignoring function-like macro: PL_ARENA_RELEASE(pool, mark) */
#endif
#ifdef PL_ArenaCountAllocation
  /* Ignoring function-like macro: PL_ArenaCountAllocation(ap, nb) */
#endif
#ifdef PL_ArenaCountGrowth
  /* Ignoring function-like macro: PL_ArenaCountGrowth(ap, size, incr) */
#endif
#ifdef PL_ArenaCountInplaceGrowth
  /* Ignoring function-like macro: PL_ArenaCountInplaceGrowth(ap, size, incr) */
#endif
#ifdef PL_ArenaCountRelease
  /* Ignoring function-like macro: PL_ArenaCountRelease(ap, mark) */
#endif
#ifdef PL_ArenaCountRetract
  /* Ignoring function-like macro: PL_ArenaCountRetract(ap, mark) */
#endif
#ifdef PL_CLEAR_ARENA
  /* Ignoring macro with no expansion: PL_CLEAR_ARENA */
#endif
#ifdef PL_CLEAR_UNUSED
  /* Ignoring macro with no expansion: PL_CLEAR_UNUSED */
#endif
#ifdef PL_CLEAR_UNUSED_PATTERN
  /* Ignoring function-like macro: PL_CLEAR_UNUSED_PATTERN(a, pattern) */
#endif
#ifdef PL_COUNT_ARENA
  /* Ignoring macro with no expansion: PL_COUNT_ARENA */
#endif
#ifdef PL_HASH_BITS
  /* PL_HASH_BITS assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PL_HASH_BITS", mrb_fixnum_value(PL_HASH_BITS));
#endif
#ifdef PL_MAKE_MEM_DEFINED
  /* Ignoring function-like macro: PL_MAKE_MEM_DEFINED(addr, size) */
#endif
#ifdef PL_MAKE_MEM_NOACCESS
  /* Ignoring function-like macro: PL_MAKE_MEM_NOACCESS(addr, size) */
#endif
#ifdef PL_MAKE_MEM_UNDEFINED
  /* Ignoring function-like macro: PL_MAKE_MEM_UNDEFINED(addr, size) */
#endif
#ifdef plarena_h___
  /* Ignoring macro with no expansion: plarena_h___ */
#endif
#ifdef PLARENAS_H
  /* Ignoring macro with no expansion: PLARENAS_H */
#endif
#ifdef PLERROR_H
  /* Ignoring macro with no expansion: PLERROR_H */
#endif
#ifdef PLGETOPT_H_
  /* Ignoring macro with no expansion: PLGETOPT_H_ */
#endif
#ifdef plhash_h___
  /* Ignoring macro with no expansion: plhash_h___ */
#endif
#ifdef PR_ABS
  /* Ignoring function-like macro: PR_ABS(x) */
#endif
#ifdef PR_ACCEPT_READ_BUF_OVERHEAD
  /* PR_ACCEPT_READ_BUF_OVERHEAD assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_ACCEPT_READ_BUF_OVERHEAD", mrb_fixnum_value(PR_ACCEPT_READ_BUF_OVERHEAD));
#endif
#ifdef PR_ACCESS_FAULT_ERROR
  /* PR_ACCESS_FAULT_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_ACCESS_FAULT_ERROR", mrb_fixnum_value(PR_ACCESS_FAULT_ERROR));
#endif
#ifdef PR_ADD_TO_COUNTER
  /* Ignoring macro with no expansion: PR_ADD_TO_COUNTER */
#endif
#ifdef PR_ADDRESS_IN_USE_ERROR
  /* PR_ADDRESS_IN_USE_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_ADDRESS_IN_USE_ERROR", mrb_fixnum_value(PR_ADDRESS_IN_USE_ERROR));
#endif
#ifdef PR_ADDRESS_NOT_AVAILABLE_ERROR
  /* PR_ADDRESS_NOT_AVAILABLE_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_ADDRESS_NOT_AVAILABLE_ERROR", mrb_fixnum_value(PR_ADDRESS_NOT_AVAILABLE_ERROR));
#endif
#ifdef PR_ADDRESS_NOT_SUPPORTED_ERROR
  /* PR_ADDRESS_NOT_SUPPORTED_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_ADDRESS_NOT_SUPPORTED_ERROR", mrb_fixnum_value(PR_ADDRESS_NOT_SUPPORTED_ERROR));
#endif
#ifdef PR_AF_INET
  /* PR_AF_INET assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_AF_INET", mrb_fixnum_value(PR_AF_INET));
#endif
#ifdef PR_AF_INET6
  /* PR_AF_INET6 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_AF_INET6", mrb_fixnum_value(PR_AF_INET6));
#endif
#ifdef PR_AF_INET6_SDP
  /* PR_AF_INET6_SDP assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_AF_INET6_SDP", mrb_fixnum_value(PR_AF_INET6_SDP));
#endif
#ifdef PR_AF_INET_SDP
  /* PR_AF_INET_SDP assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_AF_INET_SDP", mrb_fixnum_value(PR_AF_INET_SDP));
#endif
#ifdef PR_AF_LOCAL
  /* PR_AF_LOCAL assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_AF_LOCAL", mrb_fixnum_value(PR_AF_LOCAL));
#endif
#ifdef PR_AF_UNSPEC
  /* PR_AF_UNSPEC assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_AF_UNSPEC", mrb_fixnum_value(PR_AF_UNSPEC));
#endif
#ifdef PR_AI_ADDRCONFIG
  /* PR_AI_ADDRCONFIG assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_AI_ADDRCONFIG", mrb_fixnum_value(PR_AI_ADDRCONFIG));
#endif
#ifdef PR_AI_ALL
  /* PR_AI_ALL assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_AI_ALL", mrb_fixnum_value(PR_AI_ALL));
#endif
#ifdef PR_AI_DEFAULT
  /* PR_AI_DEFAULT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_AI_DEFAULT", mrb_fixnum_value(PR_AI_DEFAULT));
#endif
#ifdef PR_AI_NOCANONNAME
  /* PR_AI_NOCANONNAME assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_AI_NOCANONNAME", mrb_fixnum_value(PR_AI_NOCANONNAME));
#endif
#ifdef PR_AI_V4MAPPED
  /* PR_AI_V4MAPPED assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_AI_V4MAPPED", mrb_fixnum_value(PR_AI_V4MAPPED));
#endif
#ifdef PR_ALIGN_OF_DOUBLE
  /* PR_ALIGN_OF_DOUBLE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_ALIGN_OF_DOUBLE", mrb_fixnum_value(PR_ALIGN_OF_DOUBLE));
#endif
#ifdef PR_ALIGN_OF_DWORD
  /* PR_ALIGN_OF_DWORD assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_ALIGN_OF_DWORD", mrb_fixnum_value(PR_ALIGN_OF_DWORD));
#endif
#ifdef PR_ALIGN_OF_FLOAT
  /* PR_ALIGN_OF_FLOAT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_ALIGN_OF_FLOAT", mrb_fixnum_value(PR_ALIGN_OF_FLOAT));
#endif
#ifdef PR_ALIGN_OF_INT
  /* PR_ALIGN_OF_INT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_ALIGN_OF_INT", mrb_fixnum_value(PR_ALIGN_OF_INT));
#endif
#ifdef PR_ALIGN_OF_INT64
  /* PR_ALIGN_OF_INT64 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_ALIGN_OF_INT64", mrb_fixnum_value(PR_ALIGN_OF_INT64));
#endif
#ifdef PR_ALIGN_OF_LONG
  /* PR_ALIGN_OF_LONG assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_ALIGN_OF_LONG", mrb_fixnum_value(PR_ALIGN_OF_LONG));
#endif
#ifdef PR_ALIGN_OF_POINTER
  /* PR_ALIGN_OF_POINTER assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_ALIGN_OF_POINTER", mrb_fixnum_value(PR_ALIGN_OF_POINTER));
#endif
#ifdef PR_ALIGN_OF_SHORT
  /* PR_ALIGN_OF_SHORT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_ALIGN_OF_SHORT", mrb_fixnum_value(PR_ALIGN_OF_SHORT));
#endif
#ifdef PR_ALIGN_OF_WORD
  /* PR_ALIGN_OF_WORD assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_ALIGN_OF_WORD", mrb_fixnum_value(PR_ALIGN_OF_WORD));
#endif
#ifdef PR_ALREADY_INITIATED_ERROR
  /* PR_ALREADY_INITIATED_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_ALREADY_INITIATED_ERROR", mrb_fixnum_value(PR_ALREADY_INITIATED_ERROR));
#endif
#ifdef PR_ALTERNATE_INT64_TYPEDEF
  /* Ignoring macro with no expansion: PR_ALTERNATE_INT64_TYPEDEF */
#endif
#ifdef PR_APPEND
  /* PR_APPEND assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_APPEND", mrb_fixnum_value(PR_APPEND));
#endif
#ifdef PR_APPEND_LINK
  /* Ignoring function-like macro: PR_APPEND_LINK(_e, _l) */
#endif
#ifdef PR_ARRAY_SIZE
  /* Ignoring function-like macro: PR_ARRAY_SIZE(a) */
#endif
#ifdef PR_ASSERT
  /* Ignoring function-like macro: PR_ASSERT(expr) */
#endif
#ifdef PR_ASSERT_CURRENT_THREAD_IN_MONITOR
  /* Ignoring function-like macro: PR_ASSERT_CURRENT_THREAD_IN_MONITOR(/* PRMonitor* */ mon) */
#endif
#ifdef PR_ASSERT_CURRENT_THREAD_OWNS_LOCK
  /* Ignoring function-like macro: PR_ASSERT_CURRENT_THREAD_OWNS_LOCK(/* PrLock* */ lock) */
#endif
#ifdef PR_ATOMIC_ADD
  /* Ignoring function-like macro: PR_ATOMIC_ADD(ptr, val) */
#endif
#ifdef PR_ATOMIC_DECREMENT
  /* Ignoring function-like macro: PR_ATOMIC_DECREMENT(val) */
#endif
#ifdef PR_ATOMIC_INCREMENT
  /* Ignoring function-like macro: PR_ATOMIC_INCREMENT(val) */
#endif
#ifdef PR_ATOMIC_SET
  /* Ignoring function-like macro: PR_ATOMIC_SET(val, newval) */
#endif
#ifdef PR_BAD_ADDRESS_ERROR
  /* PR_BAD_ADDRESS_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BAD_ADDRESS_ERROR", mrb_fixnum_value(PR_BAD_ADDRESS_ERROR));
#endif
#ifdef PR_BAD_DESCRIPTOR_ERROR
  /* PR_BAD_DESCRIPTOR_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BAD_DESCRIPTOR_ERROR", mrb_fixnum_value(PR_BAD_DESCRIPTOR_ERROR));
#endif
#ifdef PR_BEGIN_EXTERN_C
  /* Ignoring macro with no expansion: PR_BEGIN_EXTERN_C */
#endif
#ifdef PR_BEGIN_MACRO
  /* PR_BEGIN_MACRO assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BEGIN_MACRO", mrb_fixnum_value(PR_BEGIN_MACRO));
#endif
#ifdef PR_BETA
  /* PR_BETA assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BETA", mrb_fixnum_value(PR_BETA));
#endif
#ifdef PR_BIT
  /* Ignoring function-like macro: PR_BIT(n) */
#endif
#ifdef PR_BITMASK
  /* Ignoring function-like macro: PR_BITMASK(n) */
#endif
#ifdef PR_BITS_PER_BYTE
  /* PR_BITS_PER_BYTE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BITS_PER_BYTE", mrb_fixnum_value(PR_BITS_PER_BYTE));
#endif
#ifdef PR_BITS_PER_BYTE_LOG2
  /* PR_BITS_PER_BYTE_LOG2 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BITS_PER_BYTE_LOG2", mrb_fixnum_value(PR_BITS_PER_BYTE_LOG2));
#endif
#ifdef PR_BITS_PER_DOUBLE
  /* PR_BITS_PER_DOUBLE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BITS_PER_DOUBLE", mrb_fixnum_value(PR_BITS_PER_DOUBLE));
#endif
#ifdef PR_BITS_PER_DOUBLE_LOG2
  /* PR_BITS_PER_DOUBLE_LOG2 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BITS_PER_DOUBLE_LOG2", mrb_fixnum_value(PR_BITS_PER_DOUBLE_LOG2));
#endif
#ifdef PR_BITS_PER_DWORD
  /* PR_BITS_PER_DWORD assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BITS_PER_DWORD", mrb_fixnum_value(PR_BITS_PER_DWORD));
#endif
#ifdef PR_BITS_PER_DWORD_LOG2
  /* PR_BITS_PER_DWORD_LOG2 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BITS_PER_DWORD_LOG2", mrb_fixnum_value(PR_BITS_PER_DWORD_LOG2));
#endif
#ifdef PR_BITS_PER_FLOAT
  /* PR_BITS_PER_FLOAT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BITS_PER_FLOAT", mrb_fixnum_value(PR_BITS_PER_FLOAT));
#endif
#ifdef PR_BITS_PER_FLOAT_LOG2
  /* PR_BITS_PER_FLOAT_LOG2 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BITS_PER_FLOAT_LOG2", mrb_fixnum_value(PR_BITS_PER_FLOAT_LOG2));
#endif
#ifdef PR_BITS_PER_INT
  /* PR_BITS_PER_INT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BITS_PER_INT", mrb_fixnum_value(PR_BITS_PER_INT));
#endif
#ifdef PR_BITS_PER_INT64
  /* PR_BITS_PER_INT64 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BITS_PER_INT64", mrb_fixnum_value(PR_BITS_PER_INT64));
#endif
#ifdef PR_BITS_PER_INT64_LOG2
  /* PR_BITS_PER_INT64_LOG2 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BITS_PER_INT64_LOG2", mrb_fixnum_value(PR_BITS_PER_INT64_LOG2));
#endif
#ifdef PR_BITS_PER_INT_LOG2
  /* PR_BITS_PER_INT_LOG2 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BITS_PER_INT_LOG2", mrb_fixnum_value(PR_BITS_PER_INT_LOG2));
#endif
#ifdef PR_BITS_PER_LONG
  /* PR_BITS_PER_LONG assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BITS_PER_LONG", mrb_fixnum_value(PR_BITS_PER_LONG));
#endif
#ifdef PR_BITS_PER_LONG_LOG2
  /* PR_BITS_PER_LONG_LOG2 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BITS_PER_LONG_LOG2", mrb_fixnum_value(PR_BITS_PER_LONG_LOG2));
#endif
#ifdef PR_BITS_PER_SHORT
  /* PR_BITS_PER_SHORT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BITS_PER_SHORT", mrb_fixnum_value(PR_BITS_PER_SHORT));
#endif
#ifdef PR_BITS_PER_SHORT_LOG2
  /* PR_BITS_PER_SHORT_LOG2 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BITS_PER_SHORT_LOG2", mrb_fixnum_value(PR_BITS_PER_SHORT_LOG2));
#endif
#ifdef PR_BITS_PER_WORD
  /* PR_BITS_PER_WORD assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BITS_PER_WORD", mrb_fixnum_value(PR_BITS_PER_WORD));
#endif
#ifdef PR_BITS_PER_WORD_LOG2
  /* PR_BITS_PER_WORD_LOG2 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BITS_PER_WORD_LOG2", mrb_fixnum_value(PR_BITS_PER_WORD_LOG2));
#endif
#ifdef pr_bitscan_clz32
  /* Ignoring function-like macro: pr_bitscan_clz32(val) */
#endif
#ifdef pr_bitscan_ctz32
  /* Ignoring function-like macro: pr_bitscan_ctz32(val) */
#endif
#ifdef PR_BUFFER_OVERFLOW_ERROR
  /* PR_BUFFER_OVERFLOW_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BUFFER_OVERFLOW_ERROR", mrb_fixnum_value(PR_BUFFER_OVERFLOW_ERROR));
#endif
#ifdef PR_BYTES_PER_BYTE
  /* PR_BYTES_PER_BYTE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BYTES_PER_BYTE", mrb_fixnum_value(PR_BYTES_PER_BYTE));
#endif
#ifdef PR_BYTES_PER_DOUBLE
  /* PR_BYTES_PER_DOUBLE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BYTES_PER_DOUBLE", mrb_fixnum_value(PR_BYTES_PER_DOUBLE));
#endif
#ifdef PR_BYTES_PER_DWORD
  /* PR_BYTES_PER_DWORD assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BYTES_PER_DWORD", mrb_fixnum_value(PR_BYTES_PER_DWORD));
#endif
#ifdef PR_BYTES_PER_FLOAT
  /* PR_BYTES_PER_FLOAT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BYTES_PER_FLOAT", mrb_fixnum_value(PR_BYTES_PER_FLOAT));
#endif
#ifdef PR_BYTES_PER_INT
  /* PR_BYTES_PER_INT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BYTES_PER_INT", mrb_fixnum_value(PR_BYTES_PER_INT));
#endif
#ifdef PR_BYTES_PER_INT64
  /* PR_BYTES_PER_INT64 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BYTES_PER_INT64", mrb_fixnum_value(PR_BYTES_PER_INT64));
#endif
#ifdef PR_BYTES_PER_LONG
  /* PR_BYTES_PER_LONG assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BYTES_PER_LONG", mrb_fixnum_value(PR_BYTES_PER_LONG));
#endif
#ifdef PR_BYTES_PER_SHORT
  /* PR_BYTES_PER_SHORT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BYTES_PER_SHORT", mrb_fixnum_value(PR_BYTES_PER_SHORT));
#endif
#ifdef PR_BYTES_PER_WORD
  /* PR_BYTES_PER_WORD assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_BYTES_PER_WORD", mrb_fixnum_value(PR_BYTES_PER_WORD));
#endif
#ifdef PR_CALL_ONCE_ERROR
  /* PR_CALL_ONCE_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_CALL_ONCE_ERROR", mrb_fixnum_value(PR_CALL_ONCE_ERROR));
#endif
#ifdef PR_CALLBACK
  /* Ignoring macro with no expansion: PR_CALLBACK */
#endif
#ifdef PR_CALLBACK_DECL
  /* Ignoring macro with no expansion: PR_CALLBACK_DECL */
#endif
#ifdef PR_CALLOC
  /* Ignoring function-like macro: PR_CALLOC(_size) */
#endif
#ifdef PR_CEILING_LOG2
  /* Ignoring function-like macro: PR_CEILING_LOG2(_log2, _n) */
#endif
#ifdef PR_CLEAR_BIT
  /* Ignoring function-like macro: PR_CLEAR_BIT(_map, _bit) */
#endif
#ifdef PR_CLIST_IS_EMPTY
  /* Ignoring function-like macro: PR_CLIST_IS_EMPTY(_l) */
#endif
#ifdef PR_CONNECT_ABORTED_ERROR
  /* PR_CONNECT_ABORTED_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_CONNECT_ABORTED_ERROR", mrb_fixnum_value(PR_CONNECT_ABORTED_ERROR));
#endif
#ifdef PR_CONNECT_REFUSED_ERROR
  /* PR_CONNECT_REFUSED_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_CONNECT_REFUSED_ERROR", mrb_fixnum_value(PR_CONNECT_REFUSED_ERROR));
#endif
#ifdef PR_CONNECT_RESET_ERROR
  /* PR_CONNECT_RESET_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_CONNECT_RESET_ERROR", mrb_fixnum_value(PR_CONNECT_RESET_ERROR));
#endif
#ifdef PR_CONNECT_TIMEOUT_ERROR
  /* PR_CONNECT_TIMEOUT_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_CONNECT_TIMEOUT_ERROR", mrb_fixnum_value(PR_CONNECT_TIMEOUT_ERROR));
#endif
#ifdef PR_CREATE_COUNTER
  /* Ignoring macro with no expansion: PR_CREATE_COUNTER */
#endif
#ifdef PR_CREATE_FILE
  /* PR_CREATE_FILE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_CREATE_FILE", mrb_fixnum_value(PR_CREATE_FILE));
#endif
#ifdef PR_CREATE_ORDERED_LOCK
  /* Ignoring function-like macro: PR_CREATE_ORDERED_LOCK(order) */
#endif
#ifdef PR_CREATE_TRACE
  /* Ignoring macro with no expansion: PR_CREATE_TRACE */
#endif
#ifdef PR_CurrentThread
  /* Ignoring function-like macro: PR_CurrentThread() */
#endif
#ifdef PR_DEADLOCK_ERROR
  /* PR_DEADLOCK_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_DEADLOCK_ERROR", mrb_fixnum_value(PR_DEADLOCK_ERROR));
#endif
#ifdef PR_DECREMENT_COUNTER
  /* Ignoring macro with no expansion: PR_DECREMENT_COUNTER */
#endif
#ifdef PR_DEFINE_COUNTER
  /* Ignoring function-like macro: PR_DEFINE_COUNTER(name) */
#endif
#ifdef PR_DEFINE_TRACE
  /* Ignoring function-like macro: PR_DEFINE_TRACE(name) */
#endif
#ifdef PR_DELETE
  /* Ignoring function-like macro: PR_DELETE(_ptr) */
#endif
#ifdef PR_DESTROY_COUNTER
  /* Ignoring macro with no expansion: PR_DESTROY_COUNTER */
#endif
#ifdef PR_DESTROY_ORDERED_LOCK
  /* Ignoring function-like macro: PR_DESTROY_ORDERED_LOCK(lock) */
#endif
#ifdef PR_DESTROY_TRACE
  /* Ignoring macro with no expansion: PR_DESTROY_TRACE */
#endif
#ifdef PR_DEVICE_IS_LOCKED_ERROR
  /* PR_DEVICE_IS_LOCKED_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_DEVICE_IS_LOCKED_ERROR", mrb_fixnum_value(PR_DEVICE_IS_LOCKED_ERROR));
#endif
#ifdef PR_DIRECTORY_CORRUPTED_ERROR
  /* PR_DIRECTORY_CORRUPTED_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_DIRECTORY_CORRUPTED_ERROR", mrb_fixnum_value(PR_DIRECTORY_CORRUPTED_ERROR));
#endif
#ifdef PR_DIRECTORY_LOOKUP_ERROR
  /* PR_DIRECTORY_LOOKUP_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_DIRECTORY_LOOKUP_ERROR", mrb_fixnum_value(PR_DIRECTORY_LOOKUP_ERROR));
#endif
#ifdef PR_DIRECTORY_NOT_EMPTY_ERROR
  /* PR_DIRECTORY_NOT_EMPTY_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_DIRECTORY_NOT_EMPTY_ERROR", mrb_fixnum_value(PR_DIRECTORY_NOT_EMPTY_ERROR));
#endif
#ifdef PR_DIRECTORY_OPEN_ERROR
  /* PR_DIRECTORY_OPEN_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_DIRECTORY_OPEN_ERROR", mrb_fixnum_value(PR_DIRECTORY_OPEN_ERROR));
#endif
#ifdef PR_DirName
  /* Ignoring function-like macro: PR_DirName(dirEntry) */
#endif
#ifdef PR_END_EXTERN_C
  /* Ignoring macro with no expansion: PR_END_EXTERN_C */
#endif
#ifdef PR_END_MACRO
  /* PR_END_MACRO assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_END_MACRO", mrb_fixnum_value(PR_END_MACRO));
#endif
#ifdef PR_END_OF_FILE_ERROR
  /* PR_END_OF_FILE_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_END_OF_FILE_ERROR", mrb_fixnum_value(PR_END_OF_FILE_ERROR));
#endif
#ifdef PR_EXCL
  /* PR_EXCL assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_EXCL", mrb_fixnum_value(PR_EXCL));
#endif
#ifdef PR_EXPORT
  /* Ignoring function-like macro: PR_EXPORT(__type) */
#endif
#ifdef PR_EXPORT_DATA
  /* Ignoring function-like macro: PR_EXPORT_DATA(__type) */
#endif
#ifdef PR_EXTERN
  /* Ignoring function-like macro: PR_EXTERN(__type) */
#endif
#ifdef PR_EXTERN_DATA
  /* Ignoring function-like macro: PR_EXTERN_DATA(__type) */
#endif
#ifdef PR_FALSE
  /* PR_FALSE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_FALSE", mrb_fixnum_value(PR_FALSE));
#endif
#ifdef PR_FILE_EXISTS_ERROR
  /* PR_FILE_EXISTS_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_FILE_EXISTS_ERROR", mrb_fixnum_value(PR_FILE_EXISTS_ERROR));
#endif
#ifdef PR_FILE_IS_BUSY_ERROR
  /* PR_FILE_IS_BUSY_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_FILE_IS_BUSY_ERROR", mrb_fixnum_value(PR_FILE_IS_BUSY_ERROR));
#endif
#ifdef PR_FILE_IS_LOCKED_ERROR
  /* PR_FILE_IS_LOCKED_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_FILE_IS_LOCKED_ERROR", mrb_fixnum_value(PR_FILE_IS_LOCKED_ERROR));
#endif
#ifdef PR_FILE_NOT_FOUND_ERROR
  /* PR_FILE_NOT_FOUND_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_FILE_NOT_FOUND_ERROR", mrb_fixnum_value(PR_FILE_NOT_FOUND_ERROR));
#endif
#ifdef PR_FILE_SEEK_ERROR
  /* PR_FILE_SEEK_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_FILE_SEEK_ERROR", mrb_fixnum_value(PR_FILE_SEEK_ERROR));
#endif
#ifdef PR_FILE_TOO_BIG_ERROR
  /* PR_FILE_TOO_BIG_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_FILE_TOO_BIG_ERROR", mrb_fixnum_value(PR_FILE_TOO_BIG_ERROR));
#endif
#ifdef PR_FILEMAP_STRING_BUFSIZE
  /* PR_FILEMAP_STRING_BUFSIZE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_FILEMAP_STRING_BUFSIZE", mrb_fixnum_value(PR_FILEMAP_STRING_BUFSIZE));
#endif
#ifdef PR_FILESYSTEM_MOUNTED_ERROR
  /* PR_FILESYSTEM_MOUNTED_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_FILESYSTEM_MOUNTED_ERROR", mrb_fixnum_value(PR_FILESYSTEM_MOUNTED_ERROR));
#endif
#ifdef PR_FIND_NEXT_COUNTER_QNAME
  /* Ignoring function-like macro: PR_FIND_NEXT_COUNTER_QNAME(next, handle) */
#endif
#ifdef PR_FIND_NEXT_COUNTER_RNAME
  /* Ignoring macro with no expansion: PR_FIND_NEXT_COUNTER_RNAME */
#endif
#ifdef PR_FIND_NEXT_TRACE_QNAME
  /* Ignoring macro with no expansion: PR_FIND_NEXT_TRACE_QNAME */
#endif
#ifdef PR_FIND_NEXT_TRACE_RNAME
  /* Ignoring macro with no expansion: PR_FIND_NEXT_TRACE_RNAME */
#endif
#ifdef PR_FIND_SYMBOL_ERROR
  /* PR_FIND_SYMBOL_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_FIND_SYMBOL_ERROR", mrb_fixnum_value(PR_FIND_SYMBOL_ERROR));
#endif
#ifdef PR_FLOOR_LOG2
  /* Ignoring function-like macro: PR_FLOOR_LOG2(_log2, _n) */
#endif
#ifdef PR_FREEIF
  /* Ignoring function-like macro: PR_FREEIF(_ptr) */
#endif
#ifdef PR_GET_COUNTER
  /* Ignoring function-like macro: PR_GET_COUNTER(counter, handle) */
#endif
#ifdef PR_GET_COUNTER_HANDLE_FROM_NAME
  /* Ignoring macro with no expansion: PR_GET_COUNTER_HANDLE_FROM_NAME */
#endif
#ifdef PR_GET_COUNTER_NAME_FROM_HANDLE
  /* Ignoring function-like macro: PR_GET_COUNTER_NAME_FROM_HANDLE(handle, qName, rName, description) */
#endif
#ifdef PR_GET_TRACE_ENTRIES
  /* Ignoring macro with no expansion: PR_GET_TRACE_ENTRIES */
#endif
#ifdef PR_GET_TRACE_HANDLE_FROM_NAME
  /* Ignoring macro with no expansion: PR_GET_TRACE_HANDLE_FROM_NAME */
#endif
#ifdef PR_GET_TRACE_NAME_FROM_HANDLE
  /* Ignoring macro with no expansion: PR_GET_TRACE_NAME_FROM_HANDLE */
#endif
#ifdef PR_GET_TRACE_OPTION
  /* Ignoring macro with no expansion: PR_GET_TRACE_OPTION */
#endif
#ifdef PR_GROUP_EMPTY_ERROR
  /* PR_GROUP_EMPTY_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_GROUP_EMPTY_ERROR", mrb_fixnum_value(PR_GROUP_EMPTY_ERROR));
#endif
#ifdef PR_HAVE_BUILTIN_BITSCAN32
  /* Ignoring macro with no expansion: PR_HAVE_BUILTIN_BITSCAN32 */
#endif
#ifdef PR_HOST_UNREACHABLE_ERROR
  /* PR_HOST_UNREACHABLE_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_HOST_UNREACHABLE_ERROR", mrb_fixnum_value(PR_HOST_UNREACHABLE_ERROR));
#endif
#ifdef PR_ILLEGAL_ACCESS_ERROR
  /* PR_ILLEGAL_ACCESS_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_ILLEGAL_ACCESS_ERROR", mrb_fixnum_value(PR_ILLEGAL_ACCESS_ERROR));
#endif
#ifdef PR_IMPLEMENT
  /* Ignoring function-like macro: PR_IMPLEMENT(__type) */
#endif
#ifdef PR_IMPLEMENT_DATA
  /* Ignoring function-like macro: PR_IMPLEMENT_DATA(__type) */
#endif
#ifdef PR_IMPORT
  /* Ignoring function-like macro: PR_IMPORT(__type) */
#endif
#ifdef PR_IMPORT_DATA
  /* Ignoring function-like macro: PR_IMPORT_DATA(__type) */
#endif
#ifdef PR_IN_PROGRESS_ERROR
  /* PR_IN_PROGRESS_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_IN_PROGRESS_ERROR", mrb_fixnum_value(PR_IN_PROGRESS_ERROR));
#endif
#ifdef PR_INADDR_ANY
  /* PR_INADDR_ANY assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_INADDR_ANY", mrb_fixnum_value(PR_INADDR_ANY));
#endif
#ifdef PR_INADDR_BROADCAST
  /* PR_INADDR_BROADCAST assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_INADDR_BROADCAST", mrb_fixnum_value(PR_INADDR_BROADCAST));
#endif
#ifdef PR_INADDR_LOOPBACK
  /* PR_INADDR_LOOPBACK assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_INADDR_LOOPBACK", mrb_fixnum_value(PR_INADDR_LOOPBACK));
#endif
#ifdef PR_INCREMENT_COUNTER
  /* Ignoring macro with no expansion: PR_INCREMENT_COUNTER */
#endif
#ifdef PR_INIT_CLIST
  /* Ignoring function-like macro: PR_INIT_CLIST(_l) */
#endif
#ifdef PR_INIT_COUNTER_HANDLE
  /* Ignoring macro with no expansion: PR_INIT_COUNTER_HANDLE */
#endif
#ifdef PR_INIT_STATIC_CLIST
  /* Ignoring function-like macro: PR_INIT_STATIC_CLIST(_l) */
#endif
#ifdef PR_INIT_TRACE_HANDLE
  /* Ignoring macro with no expansion: PR_INIT_TRACE_HANDLE */
#endif
#ifdef PR_INSERT_AFTER
  /* Ignoring function-like macro: PR_INSERT_AFTER(_e, _l) */
#endif
#ifdef PR_INSERT_BEFORE
  /* Ignoring function-like macro: PR_INSERT_BEFORE(_e, _l) */
#endif
#ifdef PR_INSERT_LINK
  /* Ignoring function-like macro: PR_INSERT_LINK(_e, _l) */
#endif
#ifdef PR_INSUFFICIENT_RESOURCES_ERROR
  /* PR_INSUFFICIENT_RESOURCES_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_INSUFFICIENT_RESOURCES_ERROR", mrb_fixnum_value(PR_INSUFFICIENT_RESOURCES_ERROR));
#endif
#ifdef PR_INT16_MAX
  /* PR_INT16_MAX assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_INT16_MAX", mrb_fixnum_value(PR_INT16_MAX));
#endif
#ifdef PR_INT16_MIN
  /* PR_INT16_MIN assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_INT16_MIN", mrb_fixnum_value(PR_INT16_MIN));
#endif
#ifdef PR_INT32
  /* Ignoring function-like macro: PR_INT32(x) */
#endif
#ifdef PR_INT32_MAX
  /* PR_INT32_MAX assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_INT32_MAX", mrb_fixnum_value(PR_INT32_MAX));
#endif
#ifdef PR_INT32_MIN
  /* PR_INT32_MIN assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_INT32_MIN", mrb_fixnum_value(PR_INT32_MIN));
#endif
#ifdef PR_INT64
  /* Ignoring function-like macro: PR_INT64(x) */
#endif
#ifdef PR_INT64_MAX
  /* PR_INT64_MAX assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_INT64_MAX", mrb_fixnum_value(PR_INT64_MAX));
#endif
#ifdef PR_INT64_MIN
  /* PR_INT64_MIN assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_INT64_MIN", mrb_fixnum_value(PR_INT64_MIN));
#endif
#ifdef PR_INT8_MAX
  /* PR_INT8_MAX assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_INT8_MAX", mrb_fixnum_value(PR_INT8_MAX));
#endif
#ifdef PR_INT8_MIN
  /* PR_INT8_MIN assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_INT8_MIN", mrb_fixnum_value(PR_INT8_MIN));
#endif
#ifdef PR_INTERVAL_MAX
  /* PR_INTERVAL_MAX assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_INTERVAL_MAX", mrb_fixnum_value(PR_INTERVAL_MAX));
#endif
#ifdef PR_INTERVAL_MIN
  /* PR_INTERVAL_MIN assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_INTERVAL_MIN", mrb_fixnum_value(PR_INTERVAL_MIN));
#endif
#ifdef PR_INTERVAL_NO_TIMEOUT
  /* PR_INTERVAL_NO_TIMEOUT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_INTERVAL_NO_TIMEOUT", mrb_fixnum_value(PR_INTERVAL_NO_TIMEOUT));
#endif
#ifdef PR_INTERVAL_NO_WAIT
  /* PR_INTERVAL_NO_WAIT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_INTERVAL_NO_WAIT", mrb_fixnum_value(PR_INTERVAL_NO_WAIT));
#endif
#ifdef PR_INVALID_ARGUMENT_ERROR
  /* PR_INVALID_ARGUMENT_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_INVALID_ARGUMENT_ERROR", mrb_fixnum_value(PR_INVALID_ARGUMENT_ERROR));
#endif
#ifdef PR_INVALID_DEVICE_STATE_ERROR
  /* PR_INVALID_DEVICE_STATE_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_INVALID_DEVICE_STATE_ERROR", mrb_fixnum_value(PR_INVALID_DEVICE_STATE_ERROR));
#endif
#ifdef PR_INVALID_IO_LAYER
  /* PR_INVALID_IO_LAYER assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_INVALID_IO_LAYER", mrb_fixnum_value(PR_INVALID_IO_LAYER));
#endif
#ifdef PR_INVALID_METHOD_ERROR
  /* PR_INVALID_METHOD_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_INVALID_METHOD_ERROR", mrb_fixnum_value(PR_INVALID_METHOD_ERROR));
#endif
#ifdef PR_INVALID_STATE_ERROR
  /* PR_INVALID_STATE_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_INVALID_STATE_ERROR", mrb_fixnum_value(PR_INVALID_STATE_ERROR));
#endif
#ifdef PR_IO_ERROR
  /* PR_IO_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_IO_ERROR", mrb_fixnum_value(PR_IO_ERROR));
#endif
#ifdef PR_IO_LAYER_HEAD
  /* PR_IO_LAYER_HEAD assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_IO_LAYER_HEAD", mrb_fixnum_value(PR_IO_LAYER_HEAD));
#endif
#ifdef PR_IO_PENDING_ERROR
  /* PR_IO_PENDING_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_IO_PENDING_ERROR", mrb_fixnum_value(PR_IO_PENDING_ERROR));
#endif
#ifdef PR_IO_TIMEOUT_ERROR
  /* PR_IO_TIMEOUT_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_IO_TIMEOUT_ERROR", mrb_fixnum_value(PR_IO_TIMEOUT_ERROR));
#endif
#ifdef PR_IRGRP
  /* PR_IRGRP assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_IRGRP", mrb_fixnum_value(PR_IRGRP));
#endif
#ifdef PR_IROTH
  /* PR_IROTH assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_IROTH", mrb_fixnum_value(PR_IROTH));
#endif
#ifdef PR_IRUSR
  /* PR_IRUSR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_IRUSR", mrb_fixnum_value(PR_IRUSR));
#endif
#ifdef PR_IRWXG
  /* PR_IRWXG assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_IRWXG", mrb_fixnum_value(PR_IRWXG));
#endif
#ifdef PR_IRWXO
  /* PR_IRWXO assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_IRWXO", mrb_fixnum_value(PR_IRWXO));
#endif
#ifdef PR_IRWXU
  /* PR_IRWXU assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_IRWXU", mrb_fixnum_value(PR_IRWXU));
#endif
#ifdef PR_IS_CONNECTED_ERROR
  /* PR_IS_CONNECTED_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_IS_CONNECTED_ERROR", mrb_fixnum_value(PR_IS_CONNECTED_ERROR));
#endif
#ifdef PR_IS_DIRECTORY_ERROR
  /* PR_IS_DIRECTORY_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_IS_DIRECTORY_ERROR", mrb_fixnum_value(PR_IS_DIRECTORY_ERROR));
#endif
#ifdef PR_IWGRP
  /* PR_IWGRP assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_IWGRP", mrb_fixnum_value(PR_IWGRP));
#endif
#ifdef PR_IWOTH
  /* PR_IWOTH assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_IWOTH", mrb_fixnum_value(PR_IWOTH));
#endif
#ifdef PR_IWUSR
  /* PR_IWUSR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_IWUSR", mrb_fixnum_value(PR_IWUSR));
#endif
#ifdef PR_IXGRP
  /* PR_IXGRP assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_IXGRP", mrb_fixnum_value(PR_IXGRP));
#endif
#ifdef PR_IXOTH
  /* PR_IXOTH assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_IXOTH", mrb_fixnum_value(PR_IXOTH));
#endif
#ifdef PR_IXUSR
  /* PR_IXUSR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_IXUSR", mrb_fixnum_value(PR_IXUSR));
#endif
#ifdef PR_LANGUAGE_EN
  /* PR_LANGUAGE_EN assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_LANGUAGE_EN", mrb_fixnum_value(PR_LANGUAGE_EN));
#endif
#ifdef PR_LANGUAGE_I_DEFAULT
  /* PR_LANGUAGE_I_DEFAULT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_LANGUAGE_I_DEFAULT", mrb_fixnum_value(PR_LANGUAGE_I_DEFAULT));
#endif
#ifdef PR_LD_ALT_SEARCH_PATH
  /* PR_LD_ALT_SEARCH_PATH assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_LD_ALT_SEARCH_PATH", mrb_fixnum_value(PR_LD_ALT_SEARCH_PATH));
#endif
#ifdef PR_LD_GLOBAL
  /* PR_LD_GLOBAL assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_LD_GLOBAL", mrb_fixnum_value(PR_LD_GLOBAL));
#endif
#ifdef PR_LD_LAZY
  /* PR_LD_LAZY assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_LD_LAZY", mrb_fixnum_value(PR_LD_LAZY));
#endif
#ifdef PR_LD_LOCAL
  /* PR_LD_LOCAL assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_LD_LOCAL", mrb_fixnum_value(PR_LD_LOCAL));
#endif
#ifdef PR_LD_NOW
  /* PR_LD_NOW assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_LD_NOW", mrb_fixnum_value(PR_LD_NOW));
#endif
#ifdef PR_LIBRARY_NOT_LOADED_ERROR
  /* PR_LIBRARY_NOT_LOADED_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_LIBRARY_NOT_LOADED_ERROR", mrb_fixnum_value(PR_LIBRARY_NOT_LOADED_ERROR));
#endif
#ifdef PR_LIST_HEAD
  /* Ignoring function-like macro: PR_LIST_HEAD(_l) */
#endif
#ifdef PR_LIST_TAIL
  /* Ignoring function-like macro: PR_LIST_TAIL(_l) */
#endif
#ifdef PR_LOAD_LIBRARY_ERROR
  /* PR_LOAD_LIBRARY_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_LOAD_LIBRARY_ERROR", mrb_fixnum_value(PR_LOAD_LIBRARY_ERROR));
#endif
#ifdef PR_LOCK_ORDERED_LOCK
  /* Ignoring function-like macro: PR_LOCK_ORDERED_LOCK(lock) */
#endif
#ifdef PR_LOG
  /* Ignoring macro with no expansion: PR_LOG */
#endif
#ifdef PR_LOG_BEGIN
  /* Ignoring macro with no expansion: PR_LOG_BEGIN */
#endif
#ifdef PR_LOG_DEFINE
  /* Ignoring function-like macro: PR_LOG_DEFINE(_name) */
#endif
#ifdef PR_LOG_END
  /* Ignoring macro with no expansion: PR_LOG_END */
#endif
#ifdef PR_LOG_TEST
  /* Ignoring function-like macro: PR_LOG_TEST(module, level) */
#endif
#ifdef PR_LOOP_ERROR
  /* PR_LOOP_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_LOOP_ERROR", mrb_fixnum_value(PR_LOOP_ERROR));
#endif
#ifdef PR_MALLOC
  /* Ignoring function-like macro: PR_MALLOC(_bytes) */
#endif
#ifdef PR_MAX
  /* Ignoring function-like macro: PR_MAX(x, y) */
#endif
#ifdef PR_MAX_DIRECTORY_ENTRIES_ERROR
  /* PR_MAX_DIRECTORY_ENTRIES_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_MAX_DIRECTORY_ENTRIES_ERROR", mrb_fixnum_value(PR_MAX_DIRECTORY_ENTRIES_ERROR));
#endif
#ifdef PR_MAX_ERROR
  /* PR_MAX_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_MAX_ERROR", mrb_fixnum_value(PR_MAX_ERROR));
#endif
#ifdef PR_MAX_IOVECTOR_SIZE
  /* PR_MAX_IOVECTOR_SIZE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_MAX_IOVECTOR_SIZE", mrb_fixnum_value(PR_MAX_IOVECTOR_SIZE));
#endif
#ifdef PR_MIN
  /* Ignoring function-like macro: PR_MIN(x, y) */
#endif
#ifdef PR_MSEC_PER_SEC
  /* PR_MSEC_PER_SEC assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_MSEC_PER_SEC", mrb_fixnum_value(PR_MSEC_PER_SEC));
#endif
#ifdef PR_MSG_PEEK
  /* PR_MSG_PEEK assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_MSG_PEEK", mrb_fixnum_value(PR_MSG_PEEK));
#endif
#ifdef PR_NAME
  /* PR_NAME appears to be a string */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_NAME", mrb_str_new_cstr(mrb, PR_NAME));
#endif
#ifdef PR_NAME_TOO_LONG_ERROR
  /* PR_NAME_TOO_LONG_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_NAME_TOO_LONG_ERROR", mrb_fixnum_value(PR_NAME_TOO_LONG_ERROR));
#endif
#ifdef PR_NetAddrFamily
  /* Ignoring function-like macro: PR_NetAddrFamily(addr) */
#endif
#ifdef PR_NetAddrInetPort
  /* Ignoring function-like macro: PR_NetAddrInetPort(addr) */
#endif
#ifdef PR_NETDB_BUF_SIZE
  /* PR_NETDB_BUF_SIZE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_NETDB_BUF_SIZE", mrb_fixnum_value(PR_NETDB_BUF_SIZE));
#endif
#ifdef PR_NETWORK_DOWN_ERROR
  /* PR_NETWORK_DOWN_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_NETWORK_DOWN_ERROR", mrb_fixnum_value(PR_NETWORK_DOWN_ERROR));
#endif
#ifdef PR_NETWORK_UNREACHABLE_ERROR
  /* PR_NETWORK_UNREACHABLE_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_NETWORK_UNREACHABLE_ERROR", mrb_fixnum_value(PR_NETWORK_UNREACHABLE_ERROR));
#endif
#ifdef PR_NEW
  /* Ignoring function-like macro: PR_NEW(_struct) */
#endif
#ifdef PR_NEWZAP
  /* Ignoring function-like macro: PR_NEWZAP(_struct) */
#endif
#ifdef PR_NEXT_LINK
  /* Ignoring function-like macro: PR_NEXT_LINK(_e) */
#endif
#ifdef PR_NO_ACCESS_RIGHTS_ERROR
  /* PR_NO_ACCESS_RIGHTS_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_NO_ACCESS_RIGHTS_ERROR", mrb_fixnum_value(PR_NO_ACCESS_RIGHTS_ERROR));
#endif
#ifdef PR_NO_DEVICE_SPACE_ERROR
  /* PR_NO_DEVICE_SPACE_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_NO_DEVICE_SPACE_ERROR", mrb_fixnum_value(PR_NO_DEVICE_SPACE_ERROR));
#endif
#ifdef PR_NO_MORE_FILES_ERROR
  /* PR_NO_MORE_FILES_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_NO_MORE_FILES_ERROR", mrb_fixnum_value(PR_NO_MORE_FILES_ERROR));
#endif
#ifdef PR_NO_SEEK_DEVICE_ERROR
  /* PR_NO_SEEK_DEVICE_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_NO_SEEK_DEVICE_ERROR", mrb_fixnum_value(PR_NO_SEEK_DEVICE_ERROR));
#endif
#ifdef PR_NOT_CONNECTED_ERROR
  /* PR_NOT_CONNECTED_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_NOT_CONNECTED_ERROR", mrb_fixnum_value(PR_NOT_CONNECTED_ERROR));
#endif
#ifdef PR_NOT_DIRECTORY_ERROR
  /* PR_NOT_DIRECTORY_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_NOT_DIRECTORY_ERROR", mrb_fixnum_value(PR_NOT_DIRECTORY_ERROR));
#endif
#ifdef PR_NOT_IMPLEMENTED_ERROR
  /* PR_NOT_IMPLEMENTED_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_NOT_IMPLEMENTED_ERROR", mrb_fixnum_value(PR_NOT_IMPLEMENTED_ERROR));
#endif
#ifdef PR_NOT_REACHED
  /* Ignoring macro with no expansion: PR_NOT_REACHED */
#endif
#ifdef PR_NOT_SAME_DEVICE_ERROR
  /* PR_NOT_SAME_DEVICE_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_NOT_SAME_DEVICE_ERROR", mrb_fixnum_value(PR_NOT_SAME_DEVICE_ERROR));
#endif
#ifdef PR_NOT_SOCKET_ERROR
  /* PR_NOT_SOCKET_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_NOT_SOCKET_ERROR", mrb_fixnum_value(PR_NOT_SOCKET_ERROR));
#endif
#ifdef PR_NOT_TCP_SOCKET_ERROR
  /* PR_NOT_TCP_SOCKET_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_NOT_TCP_SOCKET_ERROR", mrb_fixnum_value(PR_NOT_TCP_SOCKET_ERROR));
#endif
#ifdef PR_NSEC_PER_MSEC
  /* PR_NSEC_PER_MSEC assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_NSEC_PER_MSEC", mrb_fixnum_value(PR_NSEC_PER_MSEC));
#endif
#ifdef PR_NSEC_PER_SEC
  /* PR_NSEC_PER_SEC assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_NSEC_PER_SEC", mrb_fixnum_value(PR_NSEC_PER_SEC));
#endif
#ifdef PR_NSPR_ERROR_BASE
  /* PR_NSPR_ERROR_BASE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_NSPR_ERROR_BASE", mrb_fixnum_value(PR_NSPR_ERROR_BASE));
#endif
#ifdef PR_NSPR_IO_LAYER
  /* PR_NSPR_IO_LAYER assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_NSPR_IO_LAYER", mrb_fixnum_value(PR_NSPR_IO_LAYER));
#endif
#ifdef PR_OPERATION_ABORTED_ERROR
  /* PR_OPERATION_ABORTED_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_OPERATION_ABORTED_ERROR", mrb_fixnum_value(PR_OPERATION_ABORTED_ERROR));
#endif
#ifdef PR_OPERATION_NOT_SUPPORTED_ERROR
  /* PR_OPERATION_NOT_SUPPORTED_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_OPERATION_NOT_SUPPORTED_ERROR", mrb_fixnum_value(PR_OPERATION_NOT_SUPPORTED_ERROR));
#endif
#ifdef PR_OUT_OF_MEMORY_ERROR
  /* PR_OUT_OF_MEMORY_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_OUT_OF_MEMORY_ERROR", mrb_fixnum_value(PR_OUT_OF_MEMORY_ERROR));
#endif
#ifdef PR_PENDING_INTERRUPT_ERROR
  /* PR_PENDING_INTERRUPT_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_PENDING_INTERRUPT_ERROR", mrb_fixnum_value(PR_PENDING_INTERRUPT_ERROR));
#endif
#ifdef PR_PIPE_ERROR
  /* PR_PIPE_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_PIPE_ERROR", mrb_fixnum_value(PR_PIPE_ERROR));
#endif
#ifdef PR_POLL_ERR
  /* PR_POLL_ERR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_POLL_ERR", mrb_fixnum_value(PR_POLL_ERR));
#endif
#ifdef PR_POLL_EXCEPT
  /* PR_POLL_EXCEPT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_POLL_EXCEPT", mrb_fixnum_value(PR_POLL_EXCEPT));
#endif
#ifdef PR_POLL_HUP
  /* PR_POLL_HUP assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_POLL_HUP", mrb_fixnum_value(PR_POLL_HUP));
#endif
#ifdef PR_POLL_NVAL
  /* PR_POLL_NVAL assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_POLL_NVAL", mrb_fixnum_value(PR_POLL_NVAL));
#endif
#ifdef PR_POLL_READ
  /* PR_POLL_READ assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_POLL_READ", mrb_fixnum_value(PR_POLL_READ));
#endif
#ifdef PR_POLL_WRITE
  /* PR_POLL_WRITE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_POLL_WRITE", mrb_fixnum_value(PR_POLL_WRITE));
#endif
#ifdef PR_PREV_LINK
  /* Ignoring function-like macro: PR_PREV_LINK(_e) */
#endif
#ifdef PR_PROC_DESC_TABLE_FULL_ERROR
  /* PR_PROC_DESC_TABLE_FULL_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_PROC_DESC_TABLE_FULL_ERROR", mrb_fixnum_value(PR_PROC_DESC_TABLE_FULL_ERROR));
#endif
#ifdef PR_PROTOCOL_NOT_SUPPORTED_ERROR
  /* PR_PROTOCOL_NOT_SUPPORTED_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_PROTOCOL_NOT_SUPPORTED_ERROR", mrb_fixnum_value(PR_PROTOCOL_NOT_SUPPORTED_ERROR));
#endif
#ifdef PR_PUBLIC_API
  /* PR_PUBLIC_API assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_PUBLIC_API", mrb_fixnum_value(PR_PUBLIC_API));
#endif
#ifdef PR_RANGE_ERROR
  /* PR_RANGE_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_RANGE_ERROR", mrb_fixnum_value(PR_RANGE_ERROR));
#endif
#ifdef PR_RDONLY
  /* PR_RDONLY assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_RDONLY", mrb_fixnum_value(PR_RDONLY));
#endif
#ifdef PR_RDWR
  /* PR_RDWR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_RDWR", mrb_fixnum_value(PR_RDWR));
#endif
#ifdef PR_READ_ONLY_FILESYSTEM_ERROR
  /* PR_READ_ONLY_FILESYSTEM_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_READ_ONLY_FILESYSTEM_ERROR", mrb_fixnum_value(PR_READ_ONLY_FILESYSTEM_ERROR));
#endif
#ifdef PR_REALLOC
  /* Ignoring function-like macro: PR_REALLOC(_ptr, _size) */
#endif
#ifdef PR_RECORD_TRACE_ENTRIES
  /* Ignoring macro with no expansion: PR_RECORD_TRACE_ENTRIES */
#endif
#ifdef PR_REMOTE_FILE_ERROR
  /* PR_REMOTE_FILE_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_REMOTE_FILE_ERROR", mrb_fixnum_value(PR_REMOTE_FILE_ERROR));
#endif
#ifdef PR_REMOVE_AND_INIT_LINK
  /* Ignoring function-like macro: PR_REMOVE_AND_INIT_LINK(_e) */
#endif
#ifdef PR_REMOVE_LINK
  /* Ignoring function-like macro: PR_REMOVE_LINK(_e) */
#endif
#ifdef PR_ROTATE_LEFT32
  /* Ignoring function-like macro: PR_ROTATE_LEFT32(a, bits) */
#endif
#ifdef PR_ROTATE_RIGHT32
  /* Ignoring function-like macro: PR_ROTATE_RIGHT32(a, bits) */
#endif
#ifdef PR_ROUNDUP
  /* Ignoring function-like macro: PR_ROUNDUP(x, y) */
#endif
#ifdef PR_RWLOCK_RANK_NONE
  /* PR_RWLOCK_RANK_NONE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_RWLOCK_RANK_NONE", mrb_fixnum_value(PR_RWLOCK_RANK_NONE));
#endif
#ifdef pr_s6_addr
  /* pr_s6_addr appears to be a floating point number */
  mrb_define_const(mrb, NSPR_module(mrb), "pr_s6_addr", mrb_float_value(mrb, pr_s6_addr));
#endif
#ifdef pr_s6_addr16
  /* pr_s6_addr16 appears to be a floating point number */
  mrb_define_const(mrb, NSPR_module(mrb), "pr_s6_addr16", mrb_float_value(mrb, pr_s6_addr16));
#endif
#ifdef pr_s6_addr32
  /* pr_s6_addr32 appears to be a floating point number */
  mrb_define_const(mrb, NSPR_module(mrb), "pr_s6_addr32", mrb_float_value(mrb, pr_s6_addr32));
#endif
#ifdef pr_s6_addr64
  /* pr_s6_addr64 appears to be a floating point number */
  mrb_define_const(mrb, NSPR_module(mrb), "pr_s6_addr64", mrb_float_value(mrb, pr_s6_addr64));
#endif
#ifdef PR_SEM_CREATE
  /* PR_SEM_CREATE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_SEM_CREATE", mrb_fixnum_value(PR_SEM_CREATE));
#endif
#ifdef PR_SEM_EXCL
  /* PR_SEM_EXCL assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_SEM_EXCL", mrb_fixnum_value(PR_SEM_EXCL));
#endif
#ifdef PR_SET_BIT
  /* Ignoring function-like macro: PR_SET_BIT(_map, _bit) */
#endif
#ifdef PR_SET_COUNTER
  /* Ignoring macro with no expansion: PR_SET_COUNTER */
#endif
#ifdef PR_SET_TRACE_OPTION
  /* Ignoring macro with no expansion: PR_SET_TRACE_OPTION */
#endif
#ifdef PR_SHM_CREATE
  /* PR_SHM_CREATE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_SHM_CREATE", mrb_fixnum_value(PR_SHM_CREATE));
#endif
#ifdef PR_SHM_EXCL
  /* PR_SHM_EXCL assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_SHM_EXCL", mrb_fixnum_value(PR_SHM_EXCL));
#endif
#ifdef PR_SHM_READONLY
  /* PR_SHM_READONLY assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_SHM_READONLY", mrb_fixnum_value(PR_SHM_READONLY));
#endif
#ifdef PR_SOCKET_ADDRESS_IS_BOUND_ERROR
  /* PR_SOCKET_ADDRESS_IS_BOUND_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_SOCKET_ADDRESS_IS_BOUND_ERROR", mrb_fixnum_value(PR_SOCKET_ADDRESS_IS_BOUND_ERROR));
#endif
#ifdef PR_SOCKET_SHUTDOWN_ERROR
  /* PR_SOCKET_SHUTDOWN_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_SOCKET_SHUTDOWN_ERROR", mrb_fixnum_value(PR_SOCKET_SHUTDOWN_ERROR));
#endif
#ifdef PR_STATIC_ASSERT
  /* Ignoring function-like macro: PR_STATIC_ASSERT(condition) */
#endif
#ifdef PR_STATIC_CALLBACK
  /* Ignoring function-like macro: PR_STATIC_CALLBACK(__x) */
#endif
#ifdef PR_STDERR
  /* PR_STDERR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_STDERR", mrb_fixnum_value(PR_STDERR));
#endif
#ifdef PR_STDIN
  /* PR_STDIN assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_STDIN", mrb_fixnum_value(PR_STDIN));
#endif
#ifdef PR_STDIO_INIT
  /* Ignoring macro with no expansion: PR_STDIO_INIT */
#endif
#ifdef PR_STDOUT
  /* PR_STDOUT assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_STDOUT", mrb_fixnum_value(PR_STDOUT));
#endif
#ifdef PR_SUBTRACT_FROM_COUNTER
  /* Ignoring macro with no expansion: PR_SUBTRACT_FROM_COUNTER */
#endif
#ifdef PR_SYNC
  /* PR_SYNC assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_SYNC", mrb_fixnum_value(PR_SYNC));
#endif
#ifdef PR_SYS_DESC_TABLE_FULL_ERROR
  /* PR_SYS_DESC_TABLE_FULL_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_SYS_DESC_TABLE_FULL_ERROR", mrb_fixnum_value(PR_SYS_DESC_TABLE_FULL_ERROR));
#endif
#ifdef PR_TEST_BIT
  /* Ignoring function-like macro: PR_TEST_BIT(_map, _bit) */
#endif
#ifdef PR_TOP_IO_LAYER
  /* PR_TOP_IO_LAYER assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_TOP_IO_LAYER", mrb_fixnum_value(PR_TOP_IO_LAYER));
#endif
#ifdef PR_TPD_RANGE_ERROR
  /* PR_TPD_RANGE_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_TPD_RANGE_ERROR", mrb_fixnum_value(PR_TPD_RANGE_ERROR));
#endif
#ifdef PR_TRACE
  /* Ignoring macro with no expansion: PR_TRACE */
#endif
#ifdef PR_TRUE
  /* PR_TRUE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_TRUE", mrb_fixnum_value(PR_TRUE));
#endif
#ifdef PR_TRUNCATE
  /* PR_TRUNCATE assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_TRUNCATE", mrb_fixnum_value(PR_TRUNCATE));
#endif
#ifdef PR_UINT16_MAX
  /* PR_UINT16_MAX assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_UINT16_MAX", mrb_fixnum_value(PR_UINT16_MAX));
#endif
#ifdef PR_UINT32
  /* Ignoring function-like macro: PR_UINT32(x) */
#endif
#ifdef PR_UINT32_MAX
  /* PR_UINT32_MAX assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_UINT32_MAX", mrb_fixnum_value(PR_UINT32_MAX));
#endif
#ifdef PR_UINT64
  /* Ignoring function-like macro: PR_UINT64(x) */
#endif
#ifdef PR_UINT64_MAX
  /* PR_UINT64_MAX assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_UINT64_MAX", mrb_fixnum_value(PR_UINT64_MAX));
#endif
#ifdef PR_UINT8_MAX
  /* PR_UINT8_MAX assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_UINT8_MAX", mrb_fixnum_value(PR_UINT8_MAX));
#endif
#ifdef PR_UNKNOWN_ERROR
  /* PR_UNKNOWN_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_UNKNOWN_ERROR", mrb_fixnum_value(PR_UNKNOWN_ERROR));
#endif
#ifdef PR_UNLOAD_LIBRARY_ERROR
  /* PR_UNLOAD_LIBRARY_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_UNLOAD_LIBRARY_ERROR", mrb_fixnum_value(PR_UNLOAD_LIBRARY_ERROR));
#endif
#ifdef PR_UNLOCK_ORDERED_LOCK
  /* Ignoring function-like macro: PR_UNLOCK_ORDERED_LOCK(lock) */
#endif
#ifdef PR_UPTRDIFF
  /* Ignoring function-like macro: PR_UPTRDIFF(p, q) */
#endif
#ifdef PR_USEC_PER_MSEC
  /* PR_USEC_PER_MSEC assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_USEC_PER_MSEC", mrb_fixnum_value(PR_USEC_PER_MSEC));
#endif
#ifdef PR_USEC_PER_SEC
  /* PR_USEC_PER_SEC assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_USEC_PER_SEC", mrb_fixnum_value(PR_USEC_PER_SEC));
#endif
#ifdef PR_VERSION
  /* PR_VERSION appears to be a string */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_VERSION", mrb_str_new_cstr(mrb, PR_VERSION));
#endif
#ifdef PR_VISIBILITY_DEFAULT
  /* PR_VISIBILITY_DEFAULT appears to be a string */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_VISIBILITY_DEFAULT", mrb_str_new_cstr(mrb, PR_VISIBILITY_DEFAULT));
#endif
#ifdef PR_VMAJOR
  /* PR_VMAJOR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_VMAJOR", mrb_fixnum_value(PR_VMAJOR));
#endif
#ifdef PR_VMINOR
  /* PR_VMINOR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_VMINOR", mrb_fixnum_value(PR_VMINOR));
#endif
#ifdef PR_VPATCH
  /* PR_VPATCH assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_VPATCH", mrb_fixnum_value(PR_VPATCH));
#endif
#ifdef PR_WOULD_BLOCK_ERROR
  /* PR_WOULD_BLOCK_ERROR assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_WOULD_BLOCK_ERROR", mrb_fixnum_value(PR_WOULD_BLOCK_ERROR));
#endif
#ifdef PR_WRONLY
  /* PR_WRONLY assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PR_WRONLY", mrb_fixnum_value(PR_WRONLY));
#endif
#ifdef pratom_h___
  /* Ignoring macro with no expansion: pratom_h___ */
#endif
#ifdef prbit_h___
  /* Ignoring macro with no expansion: prbit_h___ */
#endif
#ifdef prclist_h___
  /* Ignoring macro with no expansion: prclist_h___ */
#endif
#ifdef prcmon_h___
  /* Ignoring macro with no expansion: prcmon_h___ */
#endif
#ifdef PRCOUNTER_DESC_MAX
  /* PRCOUNTER_DESC_MAX assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PRCOUNTER_DESC_MAX", mrb_fixnum_value(PRCOUNTER_DESC_MAX));
#endif
#ifdef PRCOUNTER_NAME_MAX
  /* PRCOUNTER_NAME_MAX assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PRCOUNTER_NAME_MAX", mrb_fixnum_value(PRCOUNTER_NAME_MAX));
#endif
#ifdef prcountr_h___
  /* Ignoring macro with no expansion: prcountr_h___ */
#endif
#ifdef prcvar_h___
  /* Ignoring macro with no expansion: prcvar_h___ */
#endif
#ifdef prdtoa_h___
  /* Ignoring macro with no expansion: prdtoa_h___ */
#endif
#ifdef prenv_h___
  /* Ignoring macro with no expansion: prenv_h___ */
#endif
#ifdef prerr_h___
  /* Ignoring macro with no expansion: prerr_h___ */
#endif
#ifdef prerror_h___
  /* Ignoring macro with no expansion: prerror_h___ */
#endif
#ifdef prinet_h__
  /* Ignoring macro with no expansion: prinet_h__ */
#endif
#ifdef prinit_h___
  /* Ignoring macro with no expansion: prinit_h___ */
#endif
#ifdef prinrval_h
  /* Ignoring macro with no expansion: prinrval_h */
#endif
#ifdef prio_h___
  /* Ignoring macro with no expansion: prio_h___ */
#endif
#ifdef pripcsem_h___
  /* Ignoring macro with no expansion: pripcsem_h___ */
#endif
#ifdef prlink_h___
  /* Ignoring macro with no expansion: prlink_h___ */
#endif
#ifdef prlock_h___
  /* Ignoring macro with no expansion: prlock_h___ */
#endif
#ifdef prlog_h___
  /* Ignoring macro with no expansion: prlog_h___ */
#endif
#ifdef prlong_h___
  /* Ignoring macro with no expansion: prlong_h___ */
#endif
#ifdef prmem_h___
  /* Ignoring macro with no expansion: prmem_h___ */
#endif
#ifdef prmon_h___
  /* Ignoring macro with no expansion: prmon_h___ */
#endif
#ifdef prnetdb_h___
  /* Ignoring macro with no expansion: prnetdb_h___ */
#endif
#ifdef prolock_h___
  /* Ignoring macro with no expansion: prolock_h___ */
#endif
#ifdef PRPDCE_H
  /* Ignoring macro with no expansion: PRPDCE_H */
#endif
#ifdef prprf_h___
  /* Ignoring macro with no expansion: prprf_h___ */
#endif
#ifdef prproces_h___
  /* Ignoring macro with no expansion: prproces_h___ */
#endif
#ifdef prrng_h___
  /* Ignoring macro with no expansion: prrng_h___ */
#endif
#ifdef prrwlock_h___
  /* Ignoring macro with no expansion: prrwlock_h___ */
#endif
#ifdef prshm_h___
  /* Ignoring macro with no expansion: prshm_h___ */
#endif
#ifdef prshma_h___
  /* Ignoring macro with no expansion: prshma_h___ */
#endif
#ifdef prsystem_h___
  /* Ignoring macro with no expansion: prsystem_h___ */
#endif
#ifdef prthread_h___
  /* Ignoring macro with no expansion: prthread_h___ */
#endif
#ifdef prtime_h___
  /* Ignoring macro with no expansion: prtime_h___ */
#endif
#ifdef prtpool_h___
  /* Ignoring macro with no expansion: prtpool_h___ */
#endif
#ifdef PRTRACE_DESC_MAX
  /* PRTRACE_DESC_MAX assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PRTRACE_DESC_MAX", mrb_fixnum_value(PRTRACE_DESC_MAX));
#endif
#ifdef prtrace_h___
  /* Ignoring macro with no expansion: prtrace_h___ */
#endif
#ifdef PRTRACE_NAME_MAX
  /* PRTRACE_NAME_MAX assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "PRTRACE_NAME_MAX", mrb_fixnum_value(PRTRACE_NAME_MAX));
#endif
#ifdef prtypes_h___
  /* Ignoring macro with no expansion: prtypes_h___ */
#endif
#ifdef prwin16_h___
  /* Ignoring macro with no expansion: prwin16_h___ */
#endif
#ifdef SYS_INFO_BUFFER_LENGTH
  /* SYS_INFO_BUFFER_LENGTH assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "SYS_INFO_BUFFER_LENGTH", mrb_fixnum_value(SYS_INFO_BUFFER_LENGTH));
#endif
#ifdef WORDS_PER_DWORD_LOG2
  /* WORDS_PER_DWORD_LOG2 assumed to be an integer value */
  mrb_define_const(mrb, NSPR_module(mrb), "WORDS_PER_DWORD_LOG2", mrb_fixnum_value(WORDS_PER_DWORD_LOG2));
#endif
#ifdef XP_UNIX
  /* Ignoring macro with no expansion: XP_UNIX */
#endif
}
