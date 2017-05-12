/*
 * =====================================================================================
 *
 *       Filename:  jniutils.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年02月01日 17时32分43秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jun Xie (pright), pright.xj@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef JNI_UTILS_H
#define JNI_UTILS_H

#include "jni.h"

// for cpp only
#ifdef __cplusplus

#ifdef NELEM
#undef NELEM
#endif
#define NELEM(array) (sizeof(array)/sizeof((array)[0]))

#define CONCAT(arg1, arg2)  _CONCAT(arg1, arg2)
#define _CONCAT(arg1, arg2) arg1##arg2

#define STR(s) _STR(s)
#define _STR(s) #s

#define JNI_NEW_ARRAY_boolean NewBooleanArray 
#define JNI_NEW_ARRAY_byte    NewByteArray
#define JNI_NEW_ARRAY_char    NewCharArray 
#define JNI_NEW_ARRAY_short   NewShortArray 
#define JNI_NEW_ARRAY_int     NewIntArray 
#define JNI_NEW_ARRAY_long    NewLongArray 
#define JNI_NEW_ARRAY_float   NewFloatArray 
#define JNI_NEW_ARRAY_double  NewDoubleArray 

#define JNI_SET_ARRAY_boolean SetBooleanArrayRegion 
#define JNI_SET_ARRAY_byte    SetByteArrayRegion
#define JNI_SET_ARRAY_char    SetCharArrayRegion 
#define JNI_SET_ARRAY_short   SetShortArrayRegion 
#define JNI_SET_ARRAY_int     SetIntArrayRegion 
#define JNI_SET_ARRAY_long    SetLongArrayRegion 
#define JNI_SET_ARRAY_float   SetFloatArrayRegion 
#define JNI_SET_ARRAY_double  SetDoubleArrayRegion 

#define JNI_GET_ARRAY_boolean GetBooleanArrayElements 
#define JNI_GET_ARRAY_byte    GetByteArrayElements
#define JNI_GET_ARRAY_char    GetCharArrayElements 
#define JNI_GET_ARRAY_short   GetShortArrayElements 
#define JNI_GET_ARRAY_int     GetIntArrayElements 
#define JNI_GET_ARRAY_long    GetLongArrayElements 
#define JNI_GET_ARRAY_float   GetFloatArrayElements 
#define JNI_GET_ARRAY_double  GetDoubleArrayElements 

#define JNI_RELEASE_ARRAY_boolean ReleaseBooleanArrayElements 
#define JNI_RELEASE_ARRAY_byte    ReleaseByteArrayElements
#define JNI_RELEASE_ARRAY_char    ReleaseCharArrayElements 
#define JNI_RELEASE_ARRAY_short   ReleaseShortArrayElements 
#define JNI_RELEASE_ARRAY_int     ReleaseIntArrayElements 
#define JNI_RELEASE_ARRAY_long    ReleaseLongArrayElements 
#define JNI_RELEASE_ARRAY_float   ReleaseFloatArrayElements 
#define JNI_RELEASE_ARRAY_double  ReleaseDoubleArrayElements 

#define JNI_GET_SIG_boolean   Z  
#define JNI_GET_SIG_byte      B 
#define JNI_GET_SIG_char      C 
#define JNI_GET_SIG_short     S 
#define JNI_GET_SIG_int       I 
#define JNI_GET_SIG_long      J 
#define JNI_GET_SIG_float     F 
#define JNI_GET_SIG_double    D 
#define JNI_GET_SIG_string    Ljava/lang/String;

#define JNI_GET_SIG_ARRAY_boolean [Z
#define JNI_GET_SIG_ARRAY_byte    [B 
#define JNI_GET_SIG_ARRAY_char    [C 
#define JNI_GET_SIG_ARRAY_short   [S 
#define JNI_GET_SIG_ARRAY_int     [I 
#define JNI_GET_SIG_ARRAY_long    [J
#define JNI_GET_SIG_ARRAY_float   [F 
#define JNI_GET_SIG_ARRAY_double  [D 

#define JNI_SET_FIELD_boolean    SetBooleanField 
#define JNI_SET_FIELD_byte       SetByteField 
#define JNI_SET_FIELD_char       SetCharField
#define JNI_SET_FIELD_short      SetShortField  
#define JNI_SET_FIELD_int        SetIntField
#define JNI_SET_FIELD_long       SetLongField  
#define JNI_SET_FIELD_float      SetFloatField  
#define JNI_SET_FIELD_double     SetDoubleField 
#define JNI_SET_FIELD_string     SetObjectField  

#define JNI_GET_FIELD_boolean GetBooleanField 
#define JNI_GET_FIELD_byte    GetByteField 
#define JNI_GET_FIELD_char    GetCharField
#define JNI_GET_FIELD_short   GetShortField  
#define JNI_GET_FIELD_int     GetIntField
#define JNI_GET_FIELD_long    GetLongField  
#define JNI_GET_FIELD_float   GetFloatField  
#define JNI_GET_FIELD_double  GetDoubleField 
#define JNI_GET_FIELD_string  GetObjectField  

#define JNI_FREE_boolean(env, obj)
#define JNI_FREE_byte(env, obj)
#define JNI_FREE_char(env, obj)
#define JNI_FREE_short(env, obj)
#define JNI_FREE_int(env, obj)
#define JNI_FREE_long(env, obj)
#define JNI_FREE_float(env, obj)
#define JNI_FREE_double(env, obj)
#define JNI_FREE_string(env, obj) env->DeleteLocalRef(obj)

#define C_SET_FIELD_def(obj, field, value)     obj.field = value
#define C_SET_FIELD_boolean(obj, field, value) C_SET_FIELD_def(obj, field, value) 
#define C_SET_FIELD_byte(obj, field, value)    C_SET_FIELD_def(obj, field, value) 
#define C_SET_FIELD_char(obj, field, value)    C_SET_FIELD_def(obj, field, value) 
#define C_SET_FIELD_short(obj, field, value)   C_SET_FIELD_def(obj, field, value) 
#define C_SET_FIELD_int(obj, field, value)     C_SET_FIELD_def(obj, field, value) 
#define C_SET_FIELD_long(obj, field, value)    C_SET_FIELD_def(obj, field, value) 
#define C_SET_FIELD_float(obj, field, value)   C_SET_FIELD_def(obj, field, value) 
#define C_SET_FIELD_double(obj, field, value)  C_SET_FIELD_def(obj, field, value) 
#define C_SET_FIELD_string(obj, field, value)  convertJStrType(env, value, reinterpret_cast<char *>(obj.field))

#define C_GET_FIELD_def(obj, field)     (obj.field)
#define C_GET_FIELD_boolean(obj, field) C_GET_FIELD_def(obj, field) 
#define C_GET_FIELD_byte(obj, field)    C_GET_FIELD_def(obj, field) 
#define C_GET_FIELD_char(obj, field)    C_GET_FIELD_def(obj, field) 
#define C_GET_FIELD_short(obj, field)   C_GET_FIELD_def(obj, field) 
#define C_GET_FIELD_int(obj, field)     C_GET_FIELD_def(obj, field) 
#define C_GET_FIELD_long(obj, field)    C_GET_FIELD_def(obj, field) 
#define C_GET_FIELD_float(obj, field)   C_GET_FIELD_def(obj, field) 
#define C_GET_FIELD_double(obj, field)  C_GET_FIELD_def(obj, field) 
#define C_GET_FIELD_string(obj, field)  convertCStrType(env, reinterpret_cast<char *>(obj.field))

#define JNI_TYPE(type)             CONCAT(j, type)
#define JNI_ARRAY_TYPE(type)       CONCAT(JNI_TYPE(type), Array)
#define JNI_NEW_ARRAY(type)        CONCAT(JNI_NEW_ARRAY_, type)
#define JNI_SET_ARRAY(type)        CONCAT(JNI_SET_ARRAY_, type)
#define JNI_GET_ARRAY(type)        CONCAT(JNI_GET_ARRAY_, type)
#define JNI_RELEASE_ARRAY(type)    CONCAT(JNI_RELEASE_ARRAY_, type)
#define JNI_SET_FIELD(type)        CONCAT(JNI_SET_FIELD_, type)
#define JNI_GET_FIELD(type)        CONCAT(JNI_GET_FIELD_, type)
#define JNI_GET_SIG(type)          CONCAT(JNI_GET_SIG_, type)
#define JNI_GET_SIG_ARRAY(type)    CONCAT(JNI_GET_SIG_ARRAY_, type)
#define JNI_FREE(env, type, obj)   CONCAT(JNI_FREE_, type)(env, obj)

#define C_SET_FIELD(obj, field, type, value) CONCAT(C_SET_FIELD_, type)(obj, field, value)
#define C_GET_FIELD(obj, field, type)        CONCAT(C_GET_FIELD_, type)(obj, field)


#define INIT_CLASS(env, jobj, clzname, cobj, ctype, block...) ({ \
    jclass baseclz = env->FindClass(clzname); \
    jobject basejobj = jobj; \
    ctype *cptr = &cobj; \
    block \
    env->DeleteLocalRef(baseclz); })

#define NEW_CLASS(env, clzname, cobj, ctype, block...) ({ \
    jclass baseclz = env->FindClass(clzname); \
    jmethodID CONCAT(init_, field) = env->GetMethodID(baseclz, "<init>", "()V"); \
    jobject jobj = env->NewObject(baseclz, CONCAT(init_, field)); { \
    jobject basejobj = jobj; \
    ctype *cptr = &cobj; \
    block }\
    env->DeleteLocalRef(baseclz); \
    jobj; })

#define NEW_CLASS_EX(env, clz, cobj, ctype, block...) ({ \
    jclass baseclz =  clz; \
    jobject jobj = env->AllocObject(baseclz); { \
    jobject basejobj = jobj; \
    ctype *cptr = &cobj; \
    block }\
    jobj; })

#define INIT_ARRAY_CLASS(env, jobj, clzname, cobj, ctype, block...) ({ \
    jclass baseclz = env->FindClass(clzname); \
    jsize sz = env->GetArrayLength(jobj); \
    if (cobj == NULL) \
        cobj = new ctype[sz]; \
    for (jsize i=0; i<sz; ++i) { \
        jobject basejobj = env->GetObjectArrayElement(jobj, i); \
        ctype *cptr = &cobj[i]; \
        block \
        env->DeleteLocalRef(basejobj); } \
    env->DeleteLocalRef(baseclz); \
    sz; })

#define NEW_ARRAY_CLASS(env, clzname, cobj, ctype, num, block...) ({ \
    jclass baseclz = env->FindClass(clzname); \
    jsize sz = num; \
    jmethodID init_method = env->GetMethodID(baseclz, "<init>", "()V"); \
    jobjectArray jobj = env->NewObjectArray(sz, baseclz, NULL); \
    for (jsize i=0; i<sz; ++i) { \
        jobject basejobj = env->NewObject(baseclz, init_method); \
        ctype *cptr = &cobj[i]; \
        block \
        env->SetObjectArrayElement(jobj, i, basejobj); \
        env->DeleteLocalRef(basejobj); } \
    env->DeleteLocalRef(baseclz); \
    jobj; })

#define SET_FD(field, jtype) { \
    jfieldID CONCAT(f, field) = env->GetFieldID(baseclz, STR(field), STR(JNI_GET_SIG(jtype))); \
    JNI_TYPE(jtype) CONCAT(jobj_, jtype) = C_GET_FIELD((*cptr), field, jtype); \
    env->JNI_SET_FIELD(jtype)(basejobj, CONCAT(f, field), CONCAT(jobj_, jtype)); \
    JNI_FREE(env, jtype, CONCAT(jobj_, jtype)); }

#define SET_ARRAY_FD(field, jtype) { \
    jfieldID CONCAT(f, field) = env->GetFieldID(baseclz, STR(field), STR(JNI_GET_SIG_ARRAY(jtype))); \
    jsize CONCAT(sz_, field) = NELEM(C_GET_FIELD((*cptr), field, jtype)); \
    JNI_ARRAY_TYPE(jtype) CONCAT(array_, field) = env->JNI_NEW_ARRAY(jtype)(CONCAT(sz_, field)); \
    env->JNI_SET_ARRAY(jtype)(CONCAT(array_, field), 0, CONCAT(sz_, field), reinterpret_cast<JNI_TYPE(jtype) *>(C_GET_FIELD((*cptr), field, jtype))); \
    env->SetObjectField(basejobj, CONCAT(f, field), CONCAT(array_, field)); \
    env->DeleteLocalRef(CONCAT(array_, field)); }

#define SET_OBJ_FD(field, subclzname, cobj, ctype, block...) { \
    jclass subclz = env->FindClass(subclzname); \
    jmethodID CONCAT(init_, field) = env->GetMethodID(subclz, "<init>", "()V"); \
    jobject subjobj = env->NewObject(subclz, CONCAT(init_, field)); { \
        ctype *cptr = &cobj; \
        jclass baseclz = subclz; \
        jobject basejobj = subjobj; \
        block } \
    jfieldID CONCAT(f, field) = env->GetFieldID(baseclz, STR(field), "L"subclzname";"); \
    env->SetObjectField(basejobj, CONCAT(f, field), subjobj); \
    env->DeleteLocalRef(subjobj); \
    env->DeleteLocalRef(subclz); }

#define SET_OBJ_FD_EX(field, clz, subclzname, cobj, ctype, block...) { \
    jclass subclz = clz; \
    jmethodID CONCAT(init_, field) = env->GetMethodID(subclz, "<init>", "()V"); \
    jobject subjobj = env->NewObject(subclz, CONCAT(init_, field)); { \
        ctype *cptr = &cobj; \
        jclass baseclz = subclz; \
        jobject basejobj = subjobj; \
        block } \
    jfieldID CONCAT(f, field) = env->GetFieldID(baseclz, STR(field), "L"subclzname";"); \
    env->SetObjectField(basejobj, CONCAT(f, field), subjobj); \
    env->DeleteLocalRef(subjobj);}

#define SET_OBJ_ARRAY_FD(field, subclzname, cobj, ctype, block...) { \
    jclass subclz = env->FindClass(subclzname); \
    jmethodID CONCAT(init_, field) = env->GetMethodID(subclz, "<init>", "()V"); \
    jsize CONCAT(sz_, field) = NELEM(cobj); \
    jobjectArray subjobj = env->NewObjectArray(CONCAT(sz_, field), subclz, NULL); { \
        jclass baseclz = subclz; \
        for (jsize i=0; i<CONCAT(sz_, field); ++i) { \
            jobject jobj = env->AllocObject(subclz); \
            jobject basejobj = jobj; \
            ctype *cptr = &cobj[i]; \
            block \
            env->SetObjectArrayElement(subjobj, i, jobj); \
            env->DeleteLocalRef(jobj); }} \
    jfieldID CONCAT(f, field) = env->GetFieldID(baseclz, STR(field), "[L"subclzname";"); \
    env->SetObjectField(basejobj, CONCAT(f, field), subjobj); \
    env->DeleteLocalRef(subjobj); \
    env->DeleteLocalRef(subclz); }

#define SET_OBJ_ARRAY_FD_EX(field, clz, subclzname, cobj, ctype, block...) { \
    jclass subclz = clz; \
    jmethodID CONCAT(init_, field) = env->GetMethodID(subclz, "<init>", "()V"); \
    jsize CONCAT(sz_, field) = NELEM(cobj); \
    jobjectArray subjobj = env->NewObjectArray(CONCAT(sz_, field), subclz, NULL); { \
        jclass baseclz = subclz; \
        for (jsize i=0; i<CONCAT(sz_, field); ++i) { \
            jobject jobj = env->AllocObject(subclz); \
            jobject basejobj = jobj; \
            ctype *cptr = &cobj[i]; \
            block \
            env->SetObjectArrayElement(subjobj, i, jobj); \
            env->DeleteLocalRef(jobj); }} \
    jfieldID CONCAT(f, field) = env->GetFieldID(baseclz, STR(field), "[L"subclzname";"); \
    env->SetObjectField(basejobj, CONCAT(f, field), subjobj); \
    env->DeleteLocalRef(subjobj);}

#define GET_FD(field, jtype, ctype...) { \
    jfieldID CONCAT(f, field) = env->GetFieldID(baseclz, STR(field), STR(JNI_GET_SIG(jtype))); \
    C_SET_FIELD((*cptr), field, jtype, ctype static_cast<JNI_TYPE(jtype)>(env->JNI_GET_FIELD(jtype)(basejobj, CONCAT(f, field)))); } 

#define GET_ARRAY_FD(field, jtype) { \
    jfieldID CONCAT(f, field) = env->GetFieldID(baseclz, STR(field), STR(JNI_GET_SIG_ARRAY(jtype))); \
    JNI_ARRAY_TYPE(jtype) CONCAT(array_, field) = env->GetObjectField(basejobj, CONCAT(f, field)); \
    jsize CONCAT(sz_, field) = NELEM(C_GET_FIELD((*cptr), field, jtype)); \
    JNI_TYPE(jtype)* CONCAT(data_, field) = env->JNI_GET_ARRAY(jtype)(CONCAT(array_, field), 0); \
    memcpy(C_GET_FIELD((*cptr), field, jtype), CONCAT(data_, field), CONCAT(sz_, field)); \
    env->JNI_RELEASE_ARRAY(jtype)(CONCAT(array_, field), CONCAT(data_, field), 0); \
    env->DeleleteLocalRef(CONCAT(array_, field)); }

#define GET_OBJ_FD(field, subclzname, cobj, ctype, block...) { \
    jclass subclz = env->FindClass(subclzname); \
    jfieldID CONCAT(f, field) = env->GetFieldID(baseclz, STR(field), "L"subclzname";"); \
    jobject subjobj = env->GetObjectField(basejobj, CONCAT(f, field)); { \
        ctype *cptr = &cobj; \
        jclass baseclz = subclz; \
        jobject basejobj = subjobj; \
        block } \
    env->DeleteLocalRef(subjobj); \
    env->DeleteLocalRef(subclz); }

#define GET_OBJ_ARRAY_FD(field, subclzname, cobj, ctype, block...) { \
    jclass subclz = env->FindClass(subclzname); \
    jfieldID CONCAT(f, field) = env->GetFieldID(baseclz, STR(field), "[L"subclzname";"); \
    jobjectArray subjobj = static_cast<jobjectArray>(env->GetObjectField(basejobj, CONCAT(f, field))); { \
        jclass baseclz = subclz; \
        jsize CONCAT(sz_, field) = env->GetArrayLength(subjobj); \
        for (jsize i=0; i<CONCAT(sz_, field); ++i) { \
            jobject jobj = env->GetObjectArrayElement(subjobj, i); \
            jobject basejobj = jobj; \
            ctype *cptr = &cobj[i]; \
            block \
            env->DeleteLocalRef(jobj); }} \
    env->DeleteLocalRef(subjobj); \
    env->DeleteLocalRef(subclz); }

static inline jstring convertCStrType(JNIEnv *env, const char *cstr)
{
    jclass strClass = env->FindClass("java/lang/String");
    jmethodID ctorID = env->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
    jbyteArray bytes = env->NewByteArray(strlen(cstr));
    env->SetByteArrayRegion(bytes, 0, strlen(cstr), (jbyte*)cstr);
    jstring encoding = env->NewStringUTF("GB2312");
    jstring jstr = (jstring)env->NewObject(strClass, ctorID, bytes, encoding);
    env->DeleteLocalRef(bytes);
    env->DeleteLocalRef(encoding);
    env->DeleteLocalRef(strClass); 
    return jstr;
}

static inline void convertJStrType(JNIEnv *env, jstring jstr, char *cstr)
{
    const char *str = env->GetStringUTFChars(jstr, NULL);
    strcpy(cstr, str);
    env->ReleaseStringUTFChars(jstr, str);
}

#endif
#endif
