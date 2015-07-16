/*
 * PRVersionDescription
 * Defined in file prvrsion.h @ line 28
 */

/*
 * TODO: INCLUDES
 */

#include "mruby_NSPR.h"

#if BIND_Prversiondescription_TYPE

/*
 * Class Methods
 */

#if BIND_Prversiondescription_INITIALIZE
mrb_value
mrb_NSPR_Prversiondescription_initialize(mrb_state* mrb, mrb_value self) {
  PRVersionDescription* native_object = (PRVersionDescription*)malloc(sizeof(PRVersionDescription));
  mruby_gift_PRVersionDescription_data_ptr(self, native_object);
  return self;
}
#endif

mrb_value
mrb_NSPR_Prversiondescription_disown(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NSPR::Prversiondescription.disown only accepts objects of type NSPR::Prversiondescription");
    return mrb_nil_value();
  }

  ((mruby_to_native_ref*)(DATA_PTR(ruby_object)))->belongs_to_ruby = FALSE;

  return mrb_nil_value();
}

mrb_value
mrb_NSPR_Prversiondescription_belongs_to_ruby(mrb_state* mrb, mrb_value self) {
  mrb_value ruby_object;
  mrb_get_args(mrb, "o", &ruby_object);

  if (!mrb_obj_is_kind_of(mrb, ruby_object, mrb_class_ptr(self))) {
    mrb_raise(mrb, E_TYPE_ERROR, "NSPR::Prversiondescription.disown only accepts objects of type NSPR::Prversiondescription");
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

#if BIND_Prversiondescription_version_FIELD
/* get_version
 *
 * Return Type: PRInt32
 */
mrb_value
mrb_NSPR_Prversiondescription_get_version(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);

  PRInt32 native_field = native_self->version;

  if (native_field > MRB_INT_MAX) {
    mrb_raise(mrb, mrb->eStandardError_class, "MRuby cannot represent integers greater than MRB_INT_MAX");
    return mrb_nil_value();
  }
  mrb_value ruby_field = mrb_fixnum_value(native_field);

  return ruby_field;
}

/* set_version
 *
 * Parameters:
 * - value: PRInt32
 */
mrb_value
mrb_NSPR_Prversiondescription_set_version(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->fixnum_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "Fixnum expected");
    return mrb_nil_value();
  }

  int native_field = mrb_fixnum(ruby_field);

  native_self->version = native_field;

  return ruby_field;
}
#endif

#if BIND_Prversiondescription_buildTime_FIELD
/* get_buildTime
 *
 * Return Type: PRInt64
 */
mrb_value
mrb_NSPR_Prversiondescription_get_buildTime(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);

  PRInt64 native_field = native_self->buildTime;

  mrb_value ruby_field = TODO_mruby_box_long_long(mrb, native_field);

  return ruby_field;
}

/* set_buildTime
 *
 * Parameters:
 * - value: PRInt64
 */
mrb_value
mrb_NSPR_Prversiondescription_set_buildTime(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_long_long(ruby_field);

  long long native_field = TODO_mruby_unbox_long_long(ruby_field);

  native_self->buildTime = native_field;

  return ruby_field;
}
#endif

#if BIND_Prversiondescription_buildTimeString_FIELD
/* get_buildTimeString
 *
 * Return Type: char *
 */
mrb_value
mrb_NSPR_Prversiondescription_get_buildTimeString(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);

  char * native_field = native_self->buildTimeString;

  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);

  return ruby_field;
}

/* set_buildTimeString
 *
 * Parameters:
 * - value: char *
 */
mrb_value
mrb_NSPR_Prversiondescription_set_buildTimeString(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_field = strdup(mrb_string_value_cstr(mrb, &ruby_field));

  native_self->buildTimeString = native_field;

  return ruby_field;
}
#endif

#if BIND_Prversiondescription_vMajor_FIELD
/* get_vMajor
 *
 * Return Type: PRUint8
 */
mrb_value
mrb_NSPR_Prversiondescription_get_vMajor(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);

  PRUint8 native_field = native_self->vMajor;

  mrb_value ruby_field = TODO_mruby_box_PRUint8(mrb, native_field);

  return ruby_field;
}

/* set_vMajor
 *
 * Parameters:
 * - value: PRUint8
 */
mrb_value
mrb_NSPR_Prversiondescription_set_vMajor(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_PRUint8(ruby_field);

  PRUint8 native_field = TODO_mruby_unbox_PRUint8(ruby_field);

  native_self->vMajor = native_field;

  return ruby_field;
}
#endif

#if BIND_Prversiondescription_vMinor_FIELD
/* get_vMinor
 *
 * Return Type: PRUint8
 */
mrb_value
mrb_NSPR_Prversiondescription_get_vMinor(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);

  PRUint8 native_field = native_self->vMinor;

  mrb_value ruby_field = TODO_mruby_box_PRUint8(mrb, native_field);

  return ruby_field;
}

/* set_vMinor
 *
 * Parameters:
 * - value: PRUint8
 */
mrb_value
mrb_NSPR_Prversiondescription_set_vMinor(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_PRUint8(ruby_field);

  PRUint8 native_field = TODO_mruby_unbox_PRUint8(ruby_field);

  native_self->vMinor = native_field;

  return ruby_field;
}
#endif

#if BIND_Prversiondescription_vPatch_FIELD
/* get_vPatch
 *
 * Return Type: PRUint8
 */
mrb_value
mrb_NSPR_Prversiondescription_get_vPatch(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);

  PRUint8 native_field = native_self->vPatch;

  mrb_value ruby_field = TODO_mruby_box_PRUint8(mrb, native_field);

  return ruby_field;
}

/* set_vPatch
 *
 * Parameters:
 * - value: PRUint8
 */
mrb_value
mrb_NSPR_Prversiondescription_set_vPatch(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_PRUint8(ruby_field);

  PRUint8 native_field = TODO_mruby_unbox_PRUint8(ruby_field);

  native_self->vPatch = native_field;

  return ruby_field;
}
#endif

#if BIND_Prversiondescription_beta_FIELD
/* get_beta
 *
 * Return Type: PRBool
 */
mrb_value
mrb_NSPR_Prversiondescription_get_beta(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);

  PRBool native_field = native_self->beta;

  mrb_value ruby_field = TODO_mruby_box_PRBool(mrb, native_field);

  return ruby_field;
}

/* set_beta
 *
 * Parameters:
 * - value: PRBool
 */
mrb_value
mrb_NSPR_Prversiondescription_set_beta(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_PRBool(ruby_field);

  PRBool native_field = TODO_mruby_unbox_PRBool(ruby_field);

  native_self->beta = native_field;

  return ruby_field;
}
#endif

#if BIND_Prversiondescription_debug_FIELD
/* get_debug
 *
 * Return Type: PRBool
 */
mrb_value
mrb_NSPR_Prversiondescription_get_debug(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);

  PRBool native_field = native_self->debug;

  mrb_value ruby_field = TODO_mruby_box_PRBool(mrb, native_field);

  return ruby_field;
}

/* set_debug
 *
 * Parameters:
 * - value: PRBool
 */
mrb_value
mrb_NSPR_Prversiondescription_set_debug(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_PRBool(ruby_field);

  PRBool native_field = TODO_mruby_unbox_PRBool(ruby_field);

  native_self->debug = native_field;

  return ruby_field;
}
#endif

#if BIND_Prversiondescription_special_FIELD
/* get_special
 *
 * Return Type: PRBool
 */
mrb_value
mrb_NSPR_Prversiondescription_get_special(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);

  PRBool native_field = native_self->special;

  mrb_value ruby_field = TODO_mruby_box_PRBool(mrb, native_field);

  return ruby_field;
}

/* set_special
 *
 * Parameters:
 * - value: PRBool
 */
mrb_value
mrb_NSPR_Prversiondescription_set_special(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  TODO_type_check_PRBool(ruby_field);

  PRBool native_field = TODO_mruby_unbox_PRBool(ruby_field);

  native_self->special = native_field;

  return ruby_field;
}
#endif

#if BIND_Prversiondescription_filename_FIELD
/* get_filename
 *
 * Return Type: char *
 */
mrb_value
mrb_NSPR_Prversiondescription_get_filename(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);

  char * native_field = native_self->filename;

  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);

  return ruby_field;
}

/* set_filename
 *
 * Parameters:
 * - value: char *
 */
mrb_value
mrb_NSPR_Prversiondescription_set_filename(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_field = strdup(mrb_string_value_cstr(mrb, &ruby_field));

  native_self->filename = native_field;

  return ruby_field;
}
#endif

#if BIND_Prversiondescription_description_FIELD
/* get_description
 *
 * Return Type: char *
 */
mrb_value
mrb_NSPR_Prversiondescription_get_description(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);

  char * native_field = native_self->description;

  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);

  return ruby_field;
}

/* set_description
 *
 * Parameters:
 * - value: char *
 */
mrb_value
mrb_NSPR_Prversiondescription_set_description(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_field = strdup(mrb_string_value_cstr(mrb, &ruby_field));

  native_self->description = native_field;

  return ruby_field;
}
#endif

#if BIND_Prversiondescription_security_FIELD
/* get_security
 *
 * Return Type: char *
 */
mrb_value
mrb_NSPR_Prversiondescription_get_security(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);

  char * native_field = native_self->security;

  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);

  return ruby_field;
}

/* set_security
 *
 * Parameters:
 * - value: char *
 */
mrb_value
mrb_NSPR_Prversiondescription_set_security(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_field = strdup(mrb_string_value_cstr(mrb, &ruby_field));

  native_self->security = native_field;

  return ruby_field;
}
#endif

#if BIND_Prversiondescription_copyright_FIELD
/* get_copyright
 *
 * Return Type: char *
 */
mrb_value
mrb_NSPR_Prversiondescription_get_copyright(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);

  char * native_field = native_self->copyright;

  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);

  return ruby_field;
}

/* set_copyright
 *
 * Parameters:
 * - value: char *
 */
mrb_value
mrb_NSPR_Prversiondescription_set_copyright(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_field = strdup(mrb_string_value_cstr(mrb, &ruby_field));

  native_self->copyright = native_field;

  return ruby_field;
}
#endif

#if BIND_Prversiondescription_comment_FIELD
/* get_comment
 *
 * Return Type: char *
 */
mrb_value
mrb_NSPR_Prversiondescription_get_comment(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);

  char * native_field = native_self->comment;

  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);

  return ruby_field;
}

/* set_comment
 *
 * Parameters:
 * - value: char *
 */
mrb_value
mrb_NSPR_Prversiondescription_set_comment(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_field = strdup(mrb_string_value_cstr(mrb, &ruby_field));

  native_self->comment = native_field;

  return ruby_field;
}
#endif

#if BIND_Prversiondescription_specialString_FIELD
/* get_specialString
 *
 * Return Type: char *
 */
mrb_value
mrb_NSPR_Prversiondescription_get_specialString(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);

  char * native_field = native_self->specialString;

  mrb_value ruby_field = mrb_str_new_cstr(mrb, native_field);

  return ruby_field;
}

/* set_specialString
 *
 * Parameters:
 * - value: char *
 */
mrb_value
mrb_NSPR_Prversiondescription_set_specialString(mrb_state* mrb, mrb_value self) {
  PRVersionDescription * native_self = mruby_unbox_PRVersionDescription(self);
  mrb_value ruby_field;

  mrb_get_args(mrb, "o", &ruby_field);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, ruby_field, mrb->string_class)) {
    mrb_raise(mrb, E_TYPE_ERROR, "String expected");
    return mrb_nil_value();
  }

  /* WARNING: Allocating new memory to create 'char *' from 'const char *'.
   *          Please verify that this memory is cleaned up correctly.
   *
   *          Has this been verified? [No]
   */
  char * native_field = strdup(mrb_string_value_cstr(mrb, &ruby_field));

  native_self->specialString = native_field;

  return ruby_field;
}
#endif


void mrb_NSPR_Prversiondescription_init(mrb_state* mrb) {
  RClass* Prversiondescription_class = mrb_define_class_under(mrb, NSPR_module(mrb), "Prversiondescription", mrb->object_class);
  MRB_SET_INSTANCE_TT(Prversiondescription_class, MRB_TT_DATA);

#if BIND_Prversiondescription_INITIALIZE
  mrb_define_method(mrb, Prversiondescription_class, "initialize", mrb_NSPR_Prversiondescription_initialize, MRB_ARGS_NONE());
#endif
  mrb_define_class_method(mrb, Prversiondescription_class, "disown", mrb_NSPR_Prversiondescription_disown, MRB_ARGS_ARG(1, 0));
  mrb_define_class_method(mrb, Prversiondescription_class, "belongs_to_ruby?", mrb_NSPR_Prversiondescription_belongs_to_ruby, MRB_ARGS_ARG(1, 0));

  /*
   * Fields
   */
#if BIND_Prversiondescription_version_FIELD
  mrb_define_method(mrb, Prversiondescription_class, "version", mrb_NSPR_Prversiondescription_get_version, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, Prversiondescription_class, "version=", mrb_NSPR_Prversiondescription_set_version, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_Prversiondescription_buildTime_FIELD
  mrb_define_method(mrb, Prversiondescription_class, "buildTime", mrb_NSPR_Prversiondescription_get_buildTime, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, Prversiondescription_class, "buildTime=", mrb_NSPR_Prversiondescription_set_buildTime, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_Prversiondescription_buildTimeString_FIELD
  mrb_define_method(mrb, Prversiondescription_class, "buildTimeString", mrb_NSPR_Prversiondescription_get_buildTimeString, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, Prversiondescription_class, "buildTimeString=", mrb_NSPR_Prversiondescription_set_buildTimeString, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_Prversiondescription_vMajor_FIELD
  mrb_define_method(mrb, Prversiondescription_class, "vMajor", mrb_NSPR_Prversiondescription_get_vMajor, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, Prversiondescription_class, "vMajor=", mrb_NSPR_Prversiondescription_set_vMajor, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_Prversiondescription_vMinor_FIELD
  mrb_define_method(mrb, Prversiondescription_class, "vMinor", mrb_NSPR_Prversiondescription_get_vMinor, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, Prversiondescription_class, "vMinor=", mrb_NSPR_Prversiondescription_set_vMinor, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_Prversiondescription_vPatch_FIELD
  mrb_define_method(mrb, Prversiondescription_class, "vPatch", mrb_NSPR_Prversiondescription_get_vPatch, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, Prversiondescription_class, "vPatch=", mrb_NSPR_Prversiondescription_set_vPatch, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_Prversiondescription_beta_FIELD
  mrb_define_method(mrb, Prversiondescription_class, "beta", mrb_NSPR_Prversiondescription_get_beta, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, Prversiondescription_class, "beta=", mrb_NSPR_Prversiondescription_set_beta, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_Prversiondescription_debug_FIELD
  mrb_define_method(mrb, Prversiondescription_class, "debug", mrb_NSPR_Prversiondescription_get_debug, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, Prversiondescription_class, "debug=", mrb_NSPR_Prversiondescription_set_debug, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_Prversiondescription_special_FIELD
  mrb_define_method(mrb, Prversiondescription_class, "special", mrb_NSPR_Prversiondescription_get_special, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, Prversiondescription_class, "special=", mrb_NSPR_Prversiondescription_set_special, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_Prversiondescription_filename_FIELD
  mrb_define_method(mrb, Prversiondescription_class, "filename", mrb_NSPR_Prversiondescription_get_filename, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, Prversiondescription_class, "filename=", mrb_NSPR_Prversiondescription_set_filename, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_Prversiondescription_description_FIELD
  mrb_define_method(mrb, Prversiondescription_class, "description", mrb_NSPR_Prversiondescription_get_description, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, Prversiondescription_class, "description=", mrb_NSPR_Prversiondescription_set_description, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_Prversiondescription_security_FIELD
  mrb_define_method(mrb, Prversiondescription_class, "security", mrb_NSPR_Prversiondescription_get_security, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, Prversiondescription_class, "security=", mrb_NSPR_Prversiondescription_set_security, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_Prversiondescription_copyright_FIELD
  mrb_define_method(mrb, Prversiondescription_class, "copyright", mrb_NSPR_Prversiondescription_get_copyright, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, Prversiondescription_class, "copyright=", mrb_NSPR_Prversiondescription_set_copyright, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_Prversiondescription_comment_FIELD
  mrb_define_method(mrb, Prversiondescription_class, "comment", mrb_NSPR_Prversiondescription_get_comment, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, Prversiondescription_class, "comment=", mrb_NSPR_Prversiondescription_set_comment, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_Prversiondescription_specialString_FIELD
  mrb_define_method(mrb, Prversiondescription_class, "specialString", mrb_NSPR_Prversiondescription_get_specialString, MRB_ARGS_ARG(0, 0));
  mrb_define_method(mrb, Prversiondescription_class, "specialString=", mrb_NSPR_Prversiondescription_set_specialString, MRB_ARGS_ARG(1, 0));
#endif

}

#endif
