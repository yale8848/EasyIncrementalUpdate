#include <jni.h>

extern int bspatch_main(int argc,char * argv[]);

JNIEXPORT jboolean JNICALL
Java_ren_yale_android_intremetalupdate_EasyIncrementalUpdate_patch(JNIEnv *env, jclass type,
                                                                   jstring oldFilePath_,
                                                                   jstring newFilePath_,
                                                                   jstring patchPath_) {

    char *ch[5]={0};
    ch[0] ="bspatch";
    ch[1] = (*env)->GetStringUTFChars(env, oldFilePath_, 0);
    ch[2] = (*env)->GetStringUTFChars(env, newFilePath_, 0);
    ch[3] = (*env)->GetStringUTFChars(env, patchPath_, 0);
    // TODO

    int ret = bspatch_main(4,ch);

    (*env)->ReleaseStringUTFChars(env, oldFilePath_, oldFilePath_);
    (*env)->ReleaseStringUTFChars(env, newFilePath_, newFilePath_);
    (*env)->ReleaseStringUTFChars(env, patchPath_, patchPath_);

    return !ret;
}