/*
 * TODO: Update includes
 */

#include "mruby_NSPR.h"


#if BIND_Prversiondescription_TYPE
/*
 * Boxing implementation for PRVersionDescription
 */

static void free_PRVersionDescription(mrb_state* mrb, void* ptr) {
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

static const mrb_data_type PRVersionDescription_data_type = {
   "PRVersionDescription", free_PRVersionDescription
};

mrb_value
mruby_box_PRVersionDescription(mrb_state* mrb, PRVersionDescription *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, Prversiondescription_class(mrb), &PRVersionDescription_data_type, box));
}

mrb_value
mruby_giftwrap_PRVersionDescription(mrb_state* mrb, PRVersionDescription *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, Prversiondescription_class(mrb), &PRVersionDescription_data_type, box));
}

void
mruby_set_PRVersionDescription_data_ptr(mrb_value obj, PRVersionDescription *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &PRVersionDescription_data_type);
}

void
mruby_gift_PRVersionDescription_data_ptr(mrb_value obj, PRVersionDescription *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &PRVersionDescription_data_type);
}

PRVersionDescription *
mruby_unbox_PRVersionDescription(mrb_value boxed) {
  return (PRVersionDescription *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif

