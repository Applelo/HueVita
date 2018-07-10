
#include "Net.hpp"

void Net::init(){
    sceSysmoduleLoadModule(SCE_SYSMODULE_NET);
    SceNetInitParam netInitParam;
    int size = 4*1024*1024;
    netInitParam.memory = malloc(size);
    netInitParam.size = size;
    netInitParam.flags = 0;
    sceNetInit(&netInitParam);
    sceNetCtlInit();
    sceSysmoduleLoadModule(SCE_SYSMODULE_HTTP);
    sceHttpInit(4*1024*1024);
    curl_global_init(CURL_GLOBAL_ALL);
}
void Net::terminate(){
    curl_global_cleanup();
    sceHttpTerm();
    sceSysmoduleUnloadModule(SCE_SYSMODULE_HTTP);
    sceNetCtlTerm();
    sceNetTerm();
    sceSysmoduleUnloadModule(SCE_SYSMODULE_NET);
}