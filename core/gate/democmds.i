#ifdef SWIGJAVA
%insert("runtime") %{
#ifdef __ANDROID__
#define SWIG_JAVA_NO_DETACH_CURRENT_THREAD
#define SWIG_JAVA_ATTACH_CURRENT_THREAD_AS_DAEMON
#endif
%}
#endif

%module democmds
%{
#include <DemoCmds.h>
%}

%include <mgvector.h>
%template(Floats) mgvector<float>;
%template(Chars) mgvector<char>;

%include <DemoCmds.h>

#ifdef SWIGJAVA
%{
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* /*ajvm*/, void* /*reserved*/) {
    return JNI_VERSION_1_6;
}
%}
#endif
