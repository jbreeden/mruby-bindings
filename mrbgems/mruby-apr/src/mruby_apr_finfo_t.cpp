/*
 * apr_finfo_t
 * Defined in file apr_file_info.h @ line 143
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_APR.h"

#if BIND_AprFinfoT_TYPE

/*
 * Class Methods
 */

#if BIND_AprFinfoT_INITIALIZE
mrb_value
mrb_APR_AprFinfoT_initialize(mrb_state* mrb, mrb_value self) {
  apr_finfo_t* native_object = (apr_finfo_t*)malloc(sizeof(apr_finfo_t));
  mruby_gift_apr_finfo_t_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_APR_AprFinfoT_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprFinfoT.disown only accepts objects of type APR::AprFinfoT");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_APR_AprFinfoT_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "APR::AprFinfoT.disown only accepts objects of type APR::AprFinfoT");
    return mrb_nil_value();
  }

  if ( ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby ) {
    return mrb_true_value();
  } else {
    return mrb_false_value();
  }
}

/*
 * Fields
 */

#if BIND_AprFinfoT_pool_FIELD
/* get_pool
 *
 * Return Type: apr_pool_t *
 */
mrb_value
mrb_APR_AprFinfoT_get_pool(mrb_state* mrb, mrb_value self) {
  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);

  apr_pool_t * native_field = native_self->pool;

  mrb_value ruby_field = (native_field == NULL ? mrb_nil_value() : mruby_box_apr_pool_t(mrb, native_field));
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@pool_box"), ruby_field);

  return ruby_field;
}

///* set_pool
// *
// * Parameters:
// * - value: apr_pool_t *
// */
//mrb_value
//mrb_APR_AprFinfoT_set_pool(mrb_state* mrb, mrb_value self) {
//  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
//  mrb_value ruby_field;
//
//  mrb_get_args(mrb, "o", &ruby_field);
//
//  /* type checking */
//  if (!mrb_obj_is_kind_of(mrb, ruby_field, AprPoolT_class(mrb))) {
//    mrb_raise(mrb, E_TYPE_ERROR, "AprPoolT expected");
//    return mrb_nil_value();
//  }
//
//  /* Store the ruby object to prevent garage collection of the underlying native object */
//  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@pool_box"), ruby_field);
//
//  apr_pool_t * native_field = (mrb_nil_p(ruby_field) ? NULL : mruby_unbox_apr_pool_t(ruby_field));
//
//  native_self->pool = native_field;
//
//  return ruby_field;
//}
#endif

#if BIND_AprFinfoT_valid_FIELD
/* get_valid
 *
 * Return Type: apr_int32_t
 */
mrb_value
mrb_APR_AprFinfoT_get_valid(mrb_state* mrb, mrb_value self) {
  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);

  apr_int32_t native_field = native_self->valid;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@valid_box"), ruby_field);

  return ruby_field;
}

///* set_valid
// *
// * Parameters:
// * - value: apr_int32_t
// */
//mrb_value
//mrb_APR_AprFinfoT_set_valid(mrb_state* mrb, mrb_value self) {
//  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
//  mrb_value ruby_field;
//
//  mrb_get_args(mrb, "o", &ruby_field);
//
//  /* type checking */
//  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
//    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
//    return mrb_nil_value();
//  }
//
//  /* Store the ruby object to prevent garage collection of the underlying native object */
//  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@valid_box"), ruby_field);
//
//  int native_field = mrb_fixnum(ruby_field);
//
//  native_self->valid = native_field;
//
//  return ruby_field;
//}
#endif

#if BIND_AprFinfoT_protection_FIELD
/* get_protection
 *
 * Return Type: apr_fileperms_t
 */
mrb_value
mrb_APR_AprFinfoT_get_protection(mrb_state* mrb, mrb_value self) {
  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
  apr_fileperms_t native_field = native_self->protection;
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  return ruby_field;
}

///* set_protection
// *
// * Parameters:
// * - value: apr_fileperms_t
// */
//mrb_value
//mrb_APR_AprFinfoT_set_protection(mrb_state* mrb, mrb_value self) {
//  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
//  mrb_value ruby_field;
//
//  mrb_get_args(mrb, "o", &ruby_field);
//
//  /* type checking */
//  TODO_type_check_apr_fileperms_t(ruby_field);
//
//  /* Store the ruby object to prevent garage collection of the underlying native object */
//  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@protection_box"), ruby_field);
//
//  apr_fileperms_t native_field = TODO_mruby_unbox_apr_fileperms_t(ruby_field);
//
//  native_self->protection = native_field;
//
//  return ruby_field;
//}
#endif

#if BIND_AprFinfoT_filetype_FIELD
/* get_filetype
 *
 * Return Type: apr_filetype_e
 */
mrb_value
mrb_APR_AprFinfoT_get_filetype(mrb_state* mrb, mrb_value self) {
  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
  apr_filetype_e native_field = native_self->filetype;
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  return ruby_field;
}

///* set_filetype
// *
// * Parameters:
// * - value: apr_filetype_e
// */
//mrb_value
//mrb_APR_AprFinfoT_set_filetype(mrb_state* mrb, mrb_value self) {
//  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
//  mrb_value ruby_field;
//
//  mrb_get_args(mrb, "o", &ruby_field);
//
//  /* type checking */
//  TODO_type_check_apr_filetype_e(ruby_field);
//
//  /* Store the ruby object to prevent garage collection of the underlying native object */
//  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@filetype_box"), ruby_field);
//
//  apr_filetype_e native_field = TODO_mruby_unbox_apr_filetype_e(ruby_field);
//
//  native_self->filetype = native_field;
//
//  return ruby_field;
//}
#endif

#if BIND_AprFinfoT_user_FIELD
/* get_user
 *
 * Return Type: apr_uid_t
 */
mrb_value
mrb_APR_AprFinfoT_get_user(mrb_state* mrb, mrb_value self) {
  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);

  apr_uid_t native_field = native_self->user;

  mrb_value ruby_field = TODO_mruby_box_apr_uid_t(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@user_box"), ruby_field);

  return ruby_field;
}

///* set_user
// *
// * Parameters:
// * - value: apr_uid_t
// */
//mrb_value
//mrb_APR_AprFinfoT_set_user(mrb_state* mrb, mrb_value self) {
//  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
//  mrb_value ruby_field;
//
//  mrb_get_args(mrb, "o", &ruby_field);
//
//  /* type checking */
//  TODO_type_check_apr_uid_t(ruby_field);
//
//  /* Store the ruby object to prevent garage collection of the underlying native object */
//  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@user_box"), ruby_field);
//
//  apr_uid_t native_field = TODO_mruby_unbox_apr_uid_t(ruby_field);
//
//  native_self->user = native_field;
//
//  return ruby_field;
//}
#endif

#if BIND_AprFinfoT_group_FIELD
/* get_group
 *
 * Return Type: apr_gid_t
 */
mrb_value
mrb_APR_AprFinfoT_get_group(mrb_state* mrb, mrb_value self) {
  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);

  apr_gid_t native_field = native_self->group;

  mrb_value ruby_field = TODO_mruby_box_apr_gid_t(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@group_box"), ruby_field);

  return ruby_field;
}

///* set_group
// *
// * Parameters:
// * - value: apr_gid_t
// */
//mrb_value
//mrb_APR_AprFinfoT_set_group(mrb_state* mrb, mrb_value self) {
//  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
//  mrb_value ruby_field;
//
//  mrb_get_args(mrb, "o", &ruby_field);
//
//  /* type checking */
//  TODO_type_check_apr_gid_t(ruby_field);
//
//  /* Store the ruby object to prevent garage collection of the underlying native object */
//  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@group_box"), ruby_field);
//
//  apr_gid_t native_field = TODO_mruby_unbox_apr_gid_t(ruby_field);
//
//  native_self->group = native_field;
//
//  return ruby_field;
//}
#endif

#if BIND_AprFinfoT_inode_FIELD
/* get_inode
 *
 * Return Type: apr_ino_t
 */
mrb_value
mrb_APR_AprFinfoT_get_inode(mrb_state* mrb, mrb_value self) {
  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);

  apr_ino_t native_field = native_self->inode;

  mrb_value ruby_field = TODO_mruby_box_apr_ino_t(mrb, native_field);
  /* Store the ruby object to prevent garage collection of the underlying native object */
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@inode_box"), ruby_field);

  return ruby_field;
}

///* set_inode
// *
// * Parameters:
// * - value: apr_ino_t
// */
//mrb_value
//mrb_APR_AprFinfoT_set_inode(mrb_state* mrb, mrb_value self) {
//  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
//  mrb_value ruby_field;
//
//  mrb_get_args(mrb, "o", &ruby_field);
//
//  /* type checking */
//  TODO_type_check_apr_ino_t(ruby_field);
//
//  /* Store the ruby object to prevent garage collection of the underlying native object */
//  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@inode_box"), ruby_field);
//
//  apr_ino_t native_field = TODO_mruby_unbox_apr_ino_t(ruby_field);
//
//  native_self->inode = native_field;
//
//  return ruby_field;
//}
#endif

#if BIND_AprFinfoT_device_FIELD
/* get_device
 *
 * Return Type: apr_dev_t
 */
mrb_value
mrb_APR_AprFinfoT_get_device(mrb_state* mrb, mrb_value self) {
  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
  apr_dev_t native_field = native_self->device;
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  return ruby_field;
}

///* set_device
// *
// * Parameters:
// * - value: apr_dev_t
// */
//mrb_value
//mrb_APR_AprFinfoT_set_device(mrb_state* mrb, mrb_value self) {
//  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
//  mrb_value ruby_field;
//
//  mrb_get_args(mrb, "o", &ruby_field);
//
//  /* type checking */
//  TODO_type_check_apr_dev_t(ruby_field);
//
//  /* Store the ruby object to prevent garage collection of the underlying native object */
//  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@device_box"), ruby_field);
//
//  apr_dev_t native_field = TODO_mruby_unbox_apr_dev_t(ruby_field);
//
//  native_self->device = native_field;
//
//  return ruby_field;
//}
#endif

#if BIND_AprFinfoT_nlink_FIELD
/* get_nlink
 *
 * Return Type: apr_int32_t
 */
mrb_value
mrb_APR_AprFinfoT_get_nlink(mrb_state* mrb, mrb_value self) {
  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
  apr_int32_t native_field = native_self->nlink;
  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  return ruby_field;
}

///* set_nlink
// *
// * Parameters:
// * - value: apr_int32_t
// */
//mrb_value
//mrb_APR_AprFinfoT_set_nlink(mrb_state* mrb, mrb_value self) {
//  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
//  mrb_value ruby_field;
//
//  mrb_get_args(mrb, "o", &ruby_field);
//
//  /* type checking */
//  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
//    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
//    return mrb_nil_value();
//  }
//
//  /* Store the ruby object to prevent garage collection of the underlying native object */
//  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@nlink_box"), ruby_field);
//
//  int native_field = mrb_fixnum(ruby_field);
//
//  native_self->nlink = native_field;
//
//  return ruby_field;
//}
#endif

#if BIND_AprFinfoT_size_FIELD
/* get_size
 *
 * Return Type: apr_off_t
 */
mrb_value
mrb_APR_AprFinfoT_get_size(mrb_state* mrb, mrb_value self) {
  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
  apr_off_t native_field = native_self->size;
  if (native_field > MRB_INT_MAX) {
     mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
     return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  return ruby_field;
}

///* set_size
// *
// * Parameters:
// * - value: apr_off_t
// */
//mrb_value
//mrb_APR_AprFinfoT_set_size(mrb_state* mrb, mrb_value self) {
//  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
//  mrb_value ruby_field;
//
//  mrb_get_args(mrb, "o", &ruby_field);
//
//  /* type checking */
//  TODO_type_check_long_long(ruby_field);
//
//  /* Store the ruby object to prevent garage collection of the underlying native object */
//  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@size_box"), ruby_field);
//
//  long long native_field = TODO_mruby_unbox_long_long(ruby_field);
//
//  native_self->size = native_field;
//
//  return ruby_field;
//}
#endif

#if BIND_AprFinfoT_csize_FIELD
/* get_csize
 *
 * Return Type: apr_off_t
 */
mrb_value
mrb_APR_AprFinfoT_get_csize(mrb_state* mrb, mrb_value self) {
  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
  apr_off_t native_field = native_self->csize;
  if (native_field > MRB_INT_MAX) {
     mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
     return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);
  return ruby_field;
}

///* set_csize
// *
// * Parameters:
// * - value: apr_off_t
// */
//mrb_value
//mrb_APR_AprFinfoT_set_csize(mrb_state* mrb, mrb_value self) {
//  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
//  mrb_value ruby_field;
//
//  mrb_get_args(mrb, "o", &ruby_field);
//
//  /* type checking */
//  TODO_type_check_long_long(ruby_field);
//
//  /* Store the ruby object to prevent garage collection of the underlying native object */
//  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@csize_box"), ruby_field);
//
//  long long native_field = TODO_mruby_unbox_long_long(ruby_field);
//
//  native_self->csize = native_field;
//
//  return ruby_field;
//}
#endif

#if BIND_AprFinfoT_atime_FIELD
/* get_atime
 *
 * Return Type: apr_time_t
 */
mrb_value
mrb_APR_AprFinfoT_get_atime(mrb_state* mrb, mrb_value self) {
  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
  apr_time_t native_field = native_self->atime;
  apr_time_t* new_atime = (apr_time_t*)malloc(sizeof(apr_time_t));
  memcpy(new_atime, &native_field, sizeof(apr_time_t));
  mrb_value ruby_field = mruby_giftwrap_apr_time_t(mrb, new_atime);
  return ruby_field;
}

/* set_atime
 *
 * Parameters:
 * - value: apr_time_t
 */
//mrb_value
//mrb_APR_AprFinfoT_set_atime(mrb_state* mrb, mrb_value self) {
//  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
//  mrb_value ruby_field;
//
//  mrb_get_args(mrb, "o", &ruby_field);
//
//  /* Store the ruby object to prevent garage collection of the underlying native object */
//  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@atime_box"), ruby_field);
//
//  apr_time_t native_field = TODO_mruby_unbox_apr_time_t(ruby_field);
//
//  native_self->atime = native_field;
//
//  return ruby_field;
//}
#endif

#if BIND_AprFinfoT_mtime_FIELD
/* get_mtime
 *
 * Return Type: apr_time_t
 */
mrb_value
mrb_APR_AprFinfoT_get_mtime(mrb_state* mrb, mrb_value self) {
  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
  apr_time_t native_field = native_self->mtime;
  apr_time_t* new_mtime = (apr_time_t*)malloc(sizeof(apr_time_t));
  memcpy(new_mtime, &native_field, sizeof(apr_time_t));
  mrb_value ruby_field = mruby_giftwrap_apr_time_t(mrb, new_mtime);
  return ruby_field;
}

///* set_mtime
// *
// * Parameters:
// * - value: apr_time_t
// */
//mrb_value
//mrb_APR_AprFinfoT_set_mtime(mrb_state* mrb, mrb_value self) {
//  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
//  mrb_value ruby_field;
//
//  mrb_get_args(mrb, "o", &ruby_field);
//
//  /* type checking */
//  TODO_type_check_apr_time_t(ruby_field);
//
//  /* Store the ruby object to prevent garage collection of the underlying native object */
//  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@mtime_box"), ruby_field);
//
//  apr_time_t native_field = TODO_mruby_unbox_apr_time_t(ruby_field);
//
//  native_self->mtime = native_field;
//
//  return ruby_field;
//}
#endif

#if BIND_AprFinfoT_ctime_FIELD
/* get_ctime
 *
 * Return Type: apr_time_t
 */
mrb_value
mrb_APR_AprFinfoT_get_ctime(mrb_state* mrb, mrb_value self) {
   apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
   apr_time_t native_field = native_self->ctime;
   apr_time_t* new_ctime = (apr_time_t*)malloc(sizeof(apr_time_t));
   memcpy(new_ctime, &native_field, sizeof(apr_time_t));
   mrb_value ruby_field = mruby_giftwrap_apr_time_t(mrb, new_ctime);
   return ruby_field;
}

///* set_ctime
// *
// * Parameters:
// * - value: apr_time_t
// */
//mrb_value
//mrb_APR_AprFinfoT_set_ctime(mrb_state* mrb, mrb_value self) {
//  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
//  mrb_value ruby_field;
//
//  mrb_get_args(mrb, "o", &ruby_field);
//
//  /* type checking */
//  TODO_type_check_apr_time_t(ruby_field);
//
//  /* Store the ruby object to prevent garage collection of the underlying native object */
//  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@ctime_box"), ruby_field);
//
//  apr_time_t native_field = TODO_mruby_unbox_apr_time_t(ruby_field);
//
//  native_self->ctime = native_field;
//
//  return ruby_field;
//}
#endif

#if BIND_AprFinfoT_fname_FIELD
/* get_fname
 *
 * Return Type: const char *
 */
mrb_value
mrb_APR_AprFinfoT_get_fname(mrb_state* mrb, mrb_value self) {
  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
  const char * native_field = native_self->fname;
  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);
  return ruby_field;
}

///* set_fname
// *
// * Parameters:
// * - value: const char *
// */
//mrb_value
//mrb_APR_AprFinfoT_set_fname(mrb_state* mrb, mrb_value self) {
//  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
//  mrb_value ruby_field;
//
//  mrb_get_args(mrb, "o", &ruby_field);
//
//  /* type checking */
//  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->string_class)) {
//    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
//    return mrb_nil_value();
//  }
//
//  /* Store the ruby object to prevent garage collection of the underlying native object */
//  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@fname_box"), ruby_field);
//
//  const char * native_field = mrb_string_value_cstr(mrb, &ruby_field);
//
//  native_self->fname = native_field;
//
//  return ruby_field;
//}
#endif

#if BIND_AprFinfoT_name_FIELD
/* get_name
 *
 * Return Type: const char *
 */
mrb_value
mrb_APR_AprFinfoT_get_name(mrb_state* mrb, mrb_value self) {
  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
  const char * native_field = native_self->name;
  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);
  return ruby_field;
}

///* set_name
// *
// * Parameters:
// * - value: const char *
// */
//mrb_value
//mrb_APR_AprFinfoT_set_name(mrb_state* mrb, mrb_value self) {
//  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
//  mrb_value ruby_field;
//
//  mrb_get_args(mrb, "o", &ruby_field);
//
//  /* type checking */
//  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->string_class)) {
//    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
//    return mrb_nil_value();
//  }
//
//  /* Store the ruby object to prevent garage collection of the underlying native object */
//  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@name_box"), ruby_field);
//
//  const char * native_field = mrb_string_value_cstr(mrb, &ruby_field);
//
//  native_self->name = native_field;
//
//  return ruby_field;
//}
#endif

#if BIND_AprFinfoT_filehand_FIELD
/* get_filehand
 *
 * Return Type: struct apr_file_t *
 */
mrb_value
mrb_APR_AprFinfoT_get_filehand(mrb_state* mrb, mrb_value self) {
  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
  struct apr_file_t * native_field = native_self->filehand;
  mrb_value ruby_field = (native_field == NULL ? mrb_nil_value() : mruby_box_apr_file_t(mrb, native_field));
  return ruby_field;
}

///* set_filehand
// *
// * Parameters:
// * - value: struct apr_file_t *
// */
//mrb_value
//mrb_APR_AprFinfoT_set_filehand(mrb_state* mrb, mrb_value self) {
//  apr_finfo_t * native_self = mruby_unbox_apr_finfo_t(self);
//  mrb_value ruby_field;
//
//  mrb_get_args(mrb, "o", &ruby_field);
//
//  /* type checking */
//  if (!mrb_obj_is_kind_of(mrb, ruby_field, AprFileT_class(mrb))) {
//    mrb_raise(mrb, E_TYPE_ERROR, "AprFileT expected");
//    return mrb_nil_value();
//  }
//
//  /* Store the ruby object to prevent garage collection of the underlying native object */
//  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@filehand_box"), ruby_field);
//
//  struct apr_file_t * native_field = (mrb_nil_p(ruby_field) ? NULL : mruby_unbox_apr_file_t(ruby_field));
//
//  native_self->filehand = native_field;
//
//  return ruby_field;
//}
#endif


void mrb_APR_AprFinfoT_init(mrb_state* mrb) {
  RClass* AprFinfoT_class = mrb_define_class_under(mrb, APR_module(mrb), "AprFinfoT", mrb->object_class);
  MRB_SET_INSTANCE_TT(AprFinfoT_class, MRB_TT_DATA);

#if BIND_AprFinfoT_INITIALIZE
  mrb_define_method(mrb, AprFinfoT_class, "initialize", mrb_APR_AprFinfoT_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, AprFinfoT_class, "disown", mrb_APR_AprFinfoT_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, AprFinfoT_class, "belongs_to_ruby?", mrb_APR_AprFinfoT_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_AprFinfoT_pool_FIELD
  mrb_define_method(mrb, AprFinfoT_class, "pool", mrb_APR_AprFinfoT_get_pool, MRB_ARGS_ARG(0, 0));
  //mrb_define_method(mrb, AprFinfoT_class, "pool=", mrb_APR_AprFinfoT_set_pool, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprFinfoT_valid_FIELD
  mrb_define_method(mrb, AprFinfoT_class, "valid", mrb_APR_AprFinfoT_get_valid, MRB_ARGS_ARG(0, 0));
  //mrb_define_method(mrb, AprFinfoT_class, "valid=", mrb_APR_AprFinfoT_set_valid, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprFinfoT_protection_FIELD
  mrb_define_method(mrb, AprFinfoT_class, "protection", mrb_APR_AprFinfoT_get_protection, MRB_ARGS_ARG(0, 0));
  //mrb_define_method(mrb, AprFinfoT_class, "protection=", mrb_APR_AprFinfoT_set_protection, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprFinfoT_filetype_FIELD
  mrb_define_method(mrb, AprFinfoT_class, "filetype", mrb_APR_AprFinfoT_get_filetype, MRB_ARGS_ARG(0, 0));
  //mrb_define_method(mrb, AprFinfoT_class, "filetype=", mrb_APR_AprFinfoT_set_filetype, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprFinfoT_user_FIELD
  mrb_define_method(mrb, AprFinfoT_class, "user", mrb_APR_AprFinfoT_get_user, MRB_ARGS_ARG(0, 0));
  //mrb_define_method(mrb, AprFinfoT_class, "user=", mrb_APR_AprFinfoT_set_user, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprFinfoT_group_FIELD
  mrb_define_method(mrb, AprFinfoT_class, "group", mrb_APR_AprFinfoT_get_group, MRB_ARGS_ARG(0, 0));
  //mrb_define_method(mrb, AprFinfoT_class, "group=", mrb_APR_AprFinfoT_set_group, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprFinfoT_inode_FIELD
  mrb_define_method(mrb, AprFinfoT_class, "inode", mrb_APR_AprFinfoT_get_inode, MRB_ARGS_ARG(0, 0));
  //mrb_define_method(mrb, AprFinfoT_class, "inode=", mrb_APR_AprFinfoT_set_inode, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprFinfoT_device_FIELD
  mrb_define_method(mrb, AprFinfoT_class, "device", mrb_APR_AprFinfoT_get_device, MRB_ARGS_ARG(0, 0));
  //mrb_define_method(mrb, AprFinfoT_class, "device=", mrb_APR_AprFinfoT_set_device, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprFinfoT_nlink_FIELD
  mrb_define_method(mrb, AprFinfoT_class, "nlink", mrb_APR_AprFinfoT_get_nlink, MRB_ARGS_ARG(0, 0));
  //mrb_define_method(mrb, AprFinfoT_class, "nlink=", mrb_APR_AprFinfoT_set_nlink, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprFinfoT_size_FIELD
  mrb_define_method(mrb, AprFinfoT_class, "size", mrb_APR_AprFinfoT_get_size, MRB_ARGS_ARG(0, 0));
  //mrb_define_method(mrb, AprFinfoT_class, "size=", mrb_APR_AprFinfoT_set_size, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprFinfoT_csize_FIELD
  mrb_define_method(mrb, AprFinfoT_class, "csize", mrb_APR_AprFinfoT_get_csize, MRB_ARGS_ARG(0, 0));
  //mrb_define_method(mrb, AprFinfoT_class, "csize=", mrb_APR_AprFinfoT_set_csize, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprFinfoT_atime_FIELD
  mrb_define_method(mrb, AprFinfoT_class, "atime", mrb_APR_AprFinfoT_get_atime, MRB_ARGS_ARG(0, 0));
  //mrb_define_method(mrb, AprFinfoT_class, "atime=", mrb_APR_AprFinfoT_set_atime, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprFinfoT_mtime_FIELD
  mrb_define_method(mrb, AprFinfoT_class, "mtime", mrb_APR_AprFinfoT_get_mtime, MRB_ARGS_ARG(0, 0));
  //mrb_define_method(mrb, AprFinfoT_class, "mtime=", mrb_APR_AprFinfoT_set_mtime, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprFinfoT_ctime_FIELD
  mrb_define_method(mrb, AprFinfoT_class, "ctime", mrb_APR_AprFinfoT_get_ctime, MRB_ARGS_ARG(0, 0));
  //mrb_define_method(mrb, AprFinfoT_class, "ctime=", mrb_APR_AprFinfoT_set_ctime, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprFinfoT_fname_FIELD
  mrb_define_method(mrb, AprFinfoT_class, "fname", mrb_APR_AprFinfoT_get_fname, MRB_ARGS_ARG(0, 0));
  //mrb_define_method(mrb, AprFinfoT_class, "fname=", mrb_APR_AprFinfoT_set_fname, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprFinfoT_name_FIELD
  mrb_define_method(mrb, AprFinfoT_class, "name", mrb_APR_AprFinfoT_get_name, MRB_ARGS_ARG(0, 0));
  //mrb_define_method(mrb, AprFinfoT_class, "name=", mrb_APR_AprFinfoT_set_name, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_AprFinfoT_filehand_FIELD
  mrb_define_method(mrb, AprFinfoT_class, "filehand", mrb_APR_AprFinfoT_get_filehand, MRB_ARGS_ARG(0, 0));
  //mrb_define_method(mrb, AprFinfoT_class, "filehand=", mrb_APR_AprFinfoT_set_filehand, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
