/*
 * TODO: Update includes
 */

#include "mruby_NN.h"

#if BIND_NnCmsghdr_TYPE
/*
 * Boxing implementation for nn_cmsghdr
 */

static void free_nn_cmsghdr(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    /* TODO: free is the default. Should be changed if a type-specific
     *       destructor is provided for this type.
     */
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
}

static const mrb_data_type nn_cmsghdr_data_type = {
   "nn_cmsghdr", free_nn_cmsghdr
};

mrb_value
mruby_box_nn_cmsghdr(mrb_state* mrb, nn_cmsghdr *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, NnCmsghdr_class(mrb), &nn_cmsghdr_data_type, box));
}

mrb_value
mruby_giftwrap_nn_cmsghdr(mrb_state* mrb, nn_cmsghdr *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, NnCmsghdr_class(mrb), &nn_cmsghdr_data_type, box));
}

void
mruby_set_nn_cmsghdr_data_ptr(mrb_value obj, nn_cmsghdr *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_cmsghdr_data_type);
}

void
mruby_gift_nn_cmsghdr_data_ptr(mrb_value obj, nn_cmsghdr *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_cmsghdr_data_type);
}

nn_cmsghdr *
mruby_unbox_nn_cmsghdr(mrb_value boxed) {
  return (nn_cmsghdr *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif

#if BIND_NnCp_TYPE
/*
 * Boxing implementation for nn_cp
 */

static void free_nn_cp(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    /* TODO: free is the default. Should be changed if a type-specific
     *       destructor is provided for this type.
     */
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
}

static const mrb_data_type nn_cp_data_type = {
   "nn_cp", free_nn_cp
};

mrb_value
mruby_box_nn_cp(mrb_state* mrb, nn_cp *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, NnCp_class(mrb), &nn_cp_data_type, box));
}

mrb_value
mruby_giftwrap_nn_cp(mrb_state* mrb, nn_cp *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, NnCp_class(mrb), &nn_cp_data_type, box));
}

void
mruby_set_nn_cp_data_ptr(mrb_value obj, nn_cp *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_cp_data_type);
}

void
mruby_gift_nn_cp_data_ptr(mrb_value obj, nn_cp *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_cp_data_type);
}

nn_cp *
mruby_unbox_nn_cp(mrb_value boxed) {
  return (nn_cp *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif

#if BIND_NnCtx_TYPE
/*
 * Boxing implementation for nn_ctx
 */

static void free_nn_ctx(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    /* TODO: free is the default. Should be changed if a type-specific
     *       destructor is provided for this type.
     */
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
}

static const mrb_data_type nn_ctx_data_type = {
   "nn_ctx", free_nn_ctx
};

mrb_value
mruby_box_nn_ctx(mrb_state* mrb, nn_ctx *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, NnCtx_class(mrb), &nn_ctx_data_type, box));
}

mrb_value
mruby_giftwrap_nn_ctx(mrb_state* mrb, nn_ctx *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, NnCtx_class(mrb), &nn_ctx_data_type, box));
}

void
mruby_set_nn_ctx_data_ptr(mrb_value obj, nn_ctx *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_ctx_data_type);
}

void
mruby_gift_nn_ctx_data_ptr(mrb_value obj, nn_ctx *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_ctx_data_type);
}

nn_ctx *
mruby_unbox_nn_ctx(mrb_value boxed) {
  return (nn_ctx *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif

#if BIND_NnEp_TYPE
/*
 * Boxing implementation for nn_ep
 */

static void free_nn_ep(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    /* TODO: free is the default. Should be changed if a type-specific
     *       destructor is provided for this type.
     */
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
}

static const mrb_data_type nn_ep_data_type = {
   "nn_ep", free_nn_ep
};

mrb_value
mruby_box_nn_ep(mrb_state* mrb, nn_ep *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, NnEp_class(mrb), &nn_ep_data_type, box));
}

mrb_value
mruby_giftwrap_nn_ep(mrb_state* mrb, nn_ep *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, NnEp_class(mrb), &nn_ep_data_type, box));
}

void
mruby_set_nn_ep_data_ptr(mrb_value obj, nn_ep *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_ep_data_type);
}

void
mruby_gift_nn_ep_data_ptr(mrb_value obj, nn_ep *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_ep_data_type);
}

nn_ep *
mruby_unbox_nn_ep(mrb_value boxed) {
  return (nn_ep *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif

#if BIND_NnEpOptions_TYPE
/*
 * Boxing implementation for nn_ep_options
 */

static void free_nn_ep_options(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    /* TODO: free is the default. Should be changed if a type-specific
     *       destructor is provided for this type.
     */
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
}

static const mrb_data_type nn_ep_options_data_type = {
   "nn_ep_options", free_nn_ep_options
};

mrb_value
mruby_box_nn_ep_options(mrb_state* mrb, nn_ep_options *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, NnEpOptions_class(mrb), &nn_ep_options_data_type, box));
}

mrb_value
mruby_giftwrap_nn_ep_options(mrb_state* mrb, nn_ep_options *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, NnEpOptions_class(mrb), &nn_ep_options_data_type, box));
}

void
mruby_set_nn_ep_options_data_ptr(mrb_value obj, nn_ep_options *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_ep_options_data_type);
}

void
mruby_gift_nn_ep_options_data_ptr(mrb_value obj, nn_ep_options *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_ep_options_data_type);
}

nn_ep_options *
mruby_unbox_nn_ep_options(mrb_value boxed) {
  return (nn_ep_options *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif

#if BIND_NnEpbase_TYPE
/*
 * Boxing implementation for nn_epbase
 */

static void free_nn_epbase(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    /* TODO: free is the default. Should be changed if a type-specific
     *       destructor is provided for this type.
     */
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
}

static const mrb_data_type nn_epbase_data_type = {
   "nn_epbase", free_nn_epbase
};

mrb_value
mruby_box_nn_epbase(mrb_state* mrb, nn_epbase *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, NnEpbase_class(mrb), &nn_epbase_data_type, box));
}

mrb_value
mruby_giftwrap_nn_epbase(mrb_state* mrb, nn_epbase *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, NnEpbase_class(mrb), &nn_epbase_data_type, box));
}

void
mruby_set_nn_epbase_data_ptr(mrb_value obj, nn_epbase *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_epbase_data_type);
}

void
mruby_gift_nn_epbase_data_ptr(mrb_value obj, nn_epbase *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_epbase_data_type);
}

nn_epbase *
mruby_unbox_nn_epbase(mrb_value boxed) {
  return (nn_epbase *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif

#if BIND_NnEpbaseVfptr_TYPE
/*
 * Boxing implementation for nn_epbase_vfptr
 */

static void free_nn_epbase_vfptr(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    /* TODO: free is the default. Should be changed if a type-specific
     *       destructor is provided for this type.
     */
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
}

static const mrb_data_type nn_epbase_vfptr_data_type = {
   "nn_epbase_vfptr", free_nn_epbase_vfptr
};

mrb_value
mruby_box_nn_epbase_vfptr(mrb_state* mrb, nn_epbase_vfptr *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, NnEpbaseVfptr_class(mrb), &nn_epbase_vfptr_data_type, box));
}

mrb_value
mruby_giftwrap_nn_epbase_vfptr(mrb_state* mrb, nn_epbase_vfptr *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, NnEpbaseVfptr_class(mrb), &nn_epbase_vfptr_data_type, box));
}

void
mruby_set_nn_epbase_vfptr_data_ptr(mrb_value obj, nn_epbase_vfptr *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_epbase_vfptr_data_type);
}

void
mruby_gift_nn_epbase_vfptr_data_ptr(mrb_value obj, nn_epbase_vfptr *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_epbase_vfptr_data_type);
}

nn_epbase_vfptr *
mruby_unbox_nn_epbase_vfptr(mrb_value boxed) {
  return (nn_epbase_vfptr *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif

#if BIND_NnIovec_TYPE
/*
 * Boxing implementation for nn_iovec
 */

static void free_nn_iovec(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    /* TODO: free is the default. Should be changed if a type-specific
     *       destructor is provided for this type.
     */
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
}

static const mrb_data_type nn_iovec_data_type = {
   "nn_iovec", free_nn_iovec
};

mrb_value
mruby_box_nn_iovec(mrb_state* mrb, nn_iovec *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, NnIovec_class(mrb), &nn_iovec_data_type, box));
}

mrb_value
mruby_giftwrap_nn_iovec(mrb_state* mrb, nn_iovec *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, NnIovec_class(mrb), &nn_iovec_data_type, box));
}

void
mruby_set_nn_iovec_data_ptr(mrb_value obj, nn_iovec *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_iovec_data_type);
}

void
mruby_gift_nn_iovec_data_ptr(mrb_value obj, nn_iovec *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_iovec_data_type);
}

nn_iovec *
mruby_unbox_nn_iovec(mrb_value boxed) {
  return (nn_iovec *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif

#if BIND_NnMsghdr_TYPE
/*
 * Boxing implementation for nn_msghdr
 */

static void free_nn_msghdr(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    /* TODO: free is the default. Should be changed if a type-specific
     *       destructor is provided for this type.
     */
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
}

static const mrb_data_type nn_msghdr_data_type = {
   "nn_msghdr", free_nn_msghdr
};

mrb_value
mruby_box_nn_msghdr(mrb_state* mrb, nn_msghdr *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, NnMsghdr_class(mrb), &nn_msghdr_data_type, box));
}

mrb_value
mruby_giftwrap_nn_msghdr(mrb_state* mrb, nn_msghdr *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, NnMsghdr_class(mrb), &nn_msghdr_data_type, box));
}

void
mruby_set_nn_msghdr_data_ptr(mrb_value obj, nn_msghdr *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_msghdr_data_type);
}

void
mruby_gift_nn_msghdr_data_ptr(mrb_value obj, nn_msghdr *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_msghdr_data_type);
}

nn_msghdr *
mruby_unbox_nn_msghdr(mrb_value boxed) {
  return (nn_msghdr *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif

#if BIND_NnOptset_TYPE
/*
 * Boxing implementation for nn_optset
 */

static void free_nn_optset(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    /* TODO: free is the default. Should be changed if a type-specific
     *       destructor is provided for this type.
     */
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
}

static const mrb_data_type nn_optset_data_type = {
   "nn_optset", free_nn_optset
};

mrb_value
mruby_box_nn_optset(mrb_state* mrb, nn_optset *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, NnOptset_class(mrb), &nn_optset_data_type, box));
}

mrb_value
mruby_giftwrap_nn_optset(mrb_state* mrb, nn_optset *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, NnOptset_class(mrb), &nn_optset_data_type, box));
}

void
mruby_set_nn_optset_data_ptr(mrb_value obj, nn_optset *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_optset_data_type);
}

void
mruby_gift_nn_optset_data_ptr(mrb_value obj, nn_optset *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_optset_data_type);
}

nn_optset *
mruby_unbox_nn_optset(mrb_value boxed) {
  return (nn_optset *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif

#if BIND_NnOptsetVfptr_TYPE
/*
 * Boxing implementation for nn_optset_vfptr
 */

static void free_nn_optset_vfptr(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    /* TODO: free is the default. Should be changed if a type-specific
     *       destructor is provided for this type.
     */
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
}

static const mrb_data_type nn_optset_vfptr_data_type = {
   "nn_optset_vfptr", free_nn_optset_vfptr
};

mrb_value
mruby_box_nn_optset_vfptr(mrb_state* mrb, nn_optset_vfptr *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, NnOptsetVfptr_class(mrb), &nn_optset_vfptr_data_type, box));
}

mrb_value
mruby_giftwrap_nn_optset_vfptr(mrb_state* mrb, nn_optset_vfptr *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, NnOptsetVfptr_class(mrb), &nn_optset_vfptr_data_type, box));
}

void
mruby_set_nn_optset_vfptr_data_ptr(mrb_value obj, nn_optset_vfptr *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_optset_vfptr_data_type);
}

void
mruby_gift_nn_optset_vfptr_data_ptr(mrb_value obj, nn_optset_vfptr *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_optset_vfptr_data_type);
}

nn_optset_vfptr *
mruby_unbox_nn_optset_vfptr(mrb_value boxed) {
  return (nn_optset_vfptr *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif

#if BIND_NnPipe_TYPE
/*
 * Boxing implementation for nn_pipe
 */

static void free_nn_pipe(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    /* TODO: free is the default. Should be changed if a type-specific
     *       destructor is provided for this type.
     */
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
}

static const mrb_data_type nn_pipe_data_type = {
   "nn_pipe", free_nn_pipe
};

mrb_value
mruby_box_nn_pipe(mrb_state* mrb, nn_pipe *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, NnPipe_class(mrb), &nn_pipe_data_type, box));
}

mrb_value
mruby_giftwrap_nn_pipe(mrb_state* mrb, nn_pipe *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, NnPipe_class(mrb), &nn_pipe_data_type, box));
}

void
mruby_set_nn_pipe_data_ptr(mrb_value obj, nn_pipe *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_pipe_data_type);
}

void
mruby_gift_nn_pipe_data_ptr(mrb_value obj, nn_pipe *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_pipe_data_type);
}

nn_pipe *
mruby_unbox_nn_pipe(mrb_value boxed) {
  return (nn_pipe *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif

#if BIND_NnPipebase_TYPE
/*
 * Boxing implementation for nn_pipebase
 */

static void free_nn_pipebase(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    /* TODO: free is the default. Should be changed if a type-specific
     *       destructor is provided for this type.
     */
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
}

static const mrb_data_type nn_pipebase_data_type = {
   "nn_pipebase", free_nn_pipebase
};

mrb_value
mruby_box_nn_pipebase(mrb_state* mrb, nn_pipebase *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, NnPipebase_class(mrb), &nn_pipebase_data_type, box));
}

mrb_value
mruby_giftwrap_nn_pipebase(mrb_state* mrb, nn_pipebase *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, NnPipebase_class(mrb), &nn_pipebase_data_type, box));
}

void
mruby_set_nn_pipebase_data_ptr(mrb_value obj, nn_pipebase *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_pipebase_data_type);
}

void
mruby_gift_nn_pipebase_data_ptr(mrb_value obj, nn_pipebase *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_pipebase_data_type);
}

nn_pipebase *
mruby_unbox_nn_pipebase(mrb_value boxed) {
  return (nn_pipebase *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif

#if BIND_NnPipebaseVfptr_TYPE
/*
 * Boxing implementation for nn_pipebase_vfptr
 */

static void free_nn_pipebase_vfptr(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    /* TODO: free is the default. Should be changed if a type-specific
     *       destructor is provided for this type.
     */
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
}

static const mrb_data_type nn_pipebase_vfptr_data_type = {
   "nn_pipebase_vfptr", free_nn_pipebase_vfptr
};

mrb_value
mruby_box_nn_pipebase_vfptr(mrb_state* mrb, nn_pipebase_vfptr *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, NnPipebaseVfptr_class(mrb), &nn_pipebase_vfptr_data_type, box));
}

mrb_value
mruby_giftwrap_nn_pipebase_vfptr(mrb_state* mrb, nn_pipebase_vfptr *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, NnPipebaseVfptr_class(mrb), &nn_pipebase_vfptr_data_type, box));
}

void
mruby_set_nn_pipebase_vfptr_data_ptr(mrb_value obj, nn_pipebase_vfptr *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_pipebase_vfptr_data_type);
}

void
mruby_gift_nn_pipebase_vfptr_data_ptr(mrb_value obj, nn_pipebase_vfptr *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_pipebase_vfptr_data_type);
}

nn_pipebase_vfptr *
mruby_unbox_nn_pipebase_vfptr(mrb_value boxed) {
  return (nn_pipebase_vfptr *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif

#if BIND_NnPollfd_TYPE
/*
 * Boxing implementation for nn_pollfd
 */

static void free_nn_pollfd(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    /* TODO: free is the default. Should be changed if a type-specific
     *       destructor is provided for this type.
     */
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
}

static const mrb_data_type nn_pollfd_data_type = {
   "nn_pollfd", free_nn_pollfd
};

mrb_value
mruby_box_nn_pollfd(mrb_state* mrb, nn_pollfd *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, NnPollfd_class(mrb), &nn_pollfd_data_type, box));
}

mrb_value
mruby_giftwrap_nn_pollfd(mrb_state* mrb, nn_pollfd *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, NnPollfd_class(mrb), &nn_pollfd_data_type, box));
}

void
mruby_set_nn_pollfd_data_ptr(mrb_value obj, nn_pollfd *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_pollfd_data_type);
}

void
mruby_gift_nn_pollfd_data_ptr(mrb_value obj, nn_pollfd *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_pollfd_data_type);
}

nn_pollfd *
mruby_unbox_nn_pollfd(mrb_value boxed) {
  return (nn_pollfd *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif

#if BIND_NnSock_TYPE
/*
 * Boxing implementation for nn_sock
 */

static void free_nn_sock(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    /* TODO: free is the default. Should be changed if a type-specific
     *       destructor is provided for this type.
     */
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
}

static const mrb_data_type nn_sock_data_type = {
   "nn_sock", free_nn_sock
};

mrb_value
mruby_box_nn_sock(mrb_state* mrb, nn_sock *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, NnSock_class(mrb), &nn_sock_data_type, box));
}

mrb_value
mruby_giftwrap_nn_sock(mrb_state* mrb, nn_sock *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, NnSock_class(mrb), &nn_sock_data_type, box));
}

void
mruby_set_nn_sock_data_ptr(mrb_value obj, nn_sock *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_sock_data_type);
}

void
mruby_gift_nn_sock_data_ptr(mrb_value obj, nn_sock *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_sock_data_type);
}

nn_sock *
mruby_unbox_nn_sock(mrb_value boxed) {
  return (nn_sock *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif

#if BIND_NnSockbase_TYPE
/*
 * Boxing implementation for nn_sockbase
 */

static void free_nn_sockbase(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    /* TODO: free is the default. Should be changed if a type-specific
     *       destructor is provided for this type.
     */
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
}

static const mrb_data_type nn_sockbase_data_type = {
   "nn_sockbase", free_nn_sockbase
};

mrb_value
mruby_box_nn_sockbase(mrb_state* mrb, nn_sockbase *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, NnSockbase_class(mrb), &nn_sockbase_data_type, box));
}

mrb_value
mruby_giftwrap_nn_sockbase(mrb_state* mrb, nn_sockbase *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, NnSockbase_class(mrb), &nn_sockbase_data_type, box));
}

void
mruby_set_nn_sockbase_data_ptr(mrb_value obj, nn_sockbase *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_sockbase_data_type);
}

void
mruby_gift_nn_sockbase_data_ptr(mrb_value obj, nn_sockbase *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_sockbase_data_type);
}

nn_sockbase *
mruby_unbox_nn_sockbase(mrb_value boxed) {
  return (nn_sockbase *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif

#if BIND_NnSockbaseVfptr_TYPE
/*
 * Boxing implementation for nn_sockbase_vfptr
 */

static void free_nn_sockbase_vfptr(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    /* TODO: free is the default. Should be changed if a type-specific
     *       destructor is provided for this type.
     */
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
}

static const mrb_data_type nn_sockbase_vfptr_data_type = {
   "nn_sockbase_vfptr", free_nn_sockbase_vfptr
};

mrb_value
mruby_box_nn_sockbase_vfptr(mrb_state* mrb, nn_sockbase_vfptr *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, NnSockbaseVfptr_class(mrb), &nn_sockbase_vfptr_data_type, box));
}

mrb_value
mruby_giftwrap_nn_sockbase_vfptr(mrb_state* mrb, nn_sockbase_vfptr *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, NnSockbaseVfptr_class(mrb), &nn_sockbase_vfptr_data_type, box));
}

void
mruby_set_nn_sockbase_vfptr_data_ptr(mrb_value obj, nn_sockbase_vfptr *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_sockbase_vfptr_data_type);
}

void
mruby_gift_nn_sockbase_vfptr_data_ptr(mrb_value obj, nn_sockbase_vfptr *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_sockbase_vfptr_data_type);
}

nn_sockbase_vfptr *
mruby_unbox_nn_sockbase_vfptr(mrb_value boxed) {
  return (nn_sockbase_vfptr *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif

#if BIND_NnSocktype_TYPE
/*
 * Boxing implementation for nn_socktype
 */

static void free_nn_socktype(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    /* TODO: free is the default. Should be changed if a type-specific
     *       destructor is provided for this type.
     */
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
}

static const mrb_data_type nn_socktype_data_type = {
   "nn_socktype", free_nn_socktype
};

mrb_value
mruby_box_nn_socktype(mrb_state* mrb, nn_socktype *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, NnSocktype_class(mrb), &nn_socktype_data_type, box));
}

mrb_value
mruby_giftwrap_nn_socktype(mrb_state* mrb, nn_socktype *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, NnSocktype_class(mrb), &nn_socktype_data_type, box));
}

void
mruby_set_nn_socktype_data_ptr(mrb_value obj, nn_socktype *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_socktype_data_type);
}

void
mruby_gift_nn_socktype_data_ptr(mrb_value obj, nn_socktype *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_socktype_data_type);
}

nn_socktype *
mruby_unbox_nn_socktype(mrb_value boxed) {
  return (nn_socktype *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif

#if BIND_NnSymbolProperties_TYPE
/*
 * Boxing implementation for nn_symbol_properties
 */

static void free_nn_symbol_properties(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    /* TODO: free is the default. Should be changed if a type-specific
     *       destructor is provided for this type.
     */
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
}

static const mrb_data_type nn_symbol_properties_data_type = {
   "nn_symbol_properties", free_nn_symbol_properties
};

mrb_value
mruby_box_nn_symbol_properties(mrb_state* mrb, nn_symbol_properties *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, NnSymbolProperties_class(mrb), &nn_symbol_properties_data_type, box));
}

mrb_value
mruby_giftwrap_nn_symbol_properties(mrb_state* mrb, nn_symbol_properties *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, NnSymbolProperties_class(mrb), &nn_symbol_properties_data_type, box));
}

void
mruby_set_nn_symbol_properties_data_ptr(mrb_value obj, nn_symbol_properties *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_symbol_properties_data_type);
}

void
mruby_gift_nn_symbol_properties_data_ptr(mrb_value obj, nn_symbol_properties *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_symbol_properties_data_type);
}

nn_symbol_properties *
mruby_unbox_nn_symbol_properties(mrb_value boxed) {
  return (nn_symbol_properties *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif

#if BIND_NnTransport_TYPE
/*
 * Boxing implementation for nn_transport
 */

static void free_nn_transport(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    /* TODO: free is the default. Should be changed if a type-specific
     *       destructor is provided for this type.
     */
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
}

static const mrb_data_type nn_transport_data_type = {
   "nn_transport", free_nn_transport
};

mrb_value
mruby_box_nn_transport(mrb_state* mrb, nn_transport *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, NnTransport_class(mrb), &nn_transport_data_type, box));
}

mrb_value
mruby_giftwrap_nn_transport(mrb_state* mrb, nn_transport *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, NnTransport_class(mrb), &nn_transport_data_type, box));
}

void
mruby_set_nn_transport_data_ptr(mrb_value obj, nn_transport *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_transport_data_type);
}

void
mruby_gift_nn_transport_data_ptr(mrb_value obj, nn_transport *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &nn_transport_data_type);
}

nn_transport *
mruby_unbox_nn_transport(mrb_value boxed) {
  return (nn_transport *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif

