#include <pxit.h>
#include <stdio.h>

FILE* g_logfile = nullptr;

void OnApplicationInit(int argc, char** argv)
{
    g_logfile = fopen("D:\\GitHub\\wincon\\build\\log.txt", "a");
    fprintf(g_logfile, "The application is about to init...\n");
}

void OnApplicationQuit()
{
    fprintf(g_logfile, "The application is about to quit...\n");
    fclose(g_logfile);
}

void OnApplicationTick(float t, float dt)
{
    fprintf(g_logfile, "The application is ticking...\n");
    printf("The application is ticking...\n");

    if (!pxitGetKeyValue(PxitKey_E)) return;
    if (!pxitGetKeyValue(PxitKey_S)) return;
    if (!pxitGetKeyValue(PxitKey_C)) return;

    pxitCloseApplication();
}

int main(int argc, char** argv)
{
    // 1) configure a new 'Pxit' application
    PxitApplicationCreateInfo app_info;
    app_info.OnInit = OnApplicationInit;
    app_info.OnQuit = OnApplicationQuit;
    app_info.OnTick = OnApplicationTick;

    // 2) Run the 'Pxit' application entry point
    if (!pxitApplicationEntryPoint(&app_info, argc, argv))
    {
        printf("FATAL: The application encountered a error...\n");
        return -1;
    }

    return 0;
}