#include "project_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Check if path exists */
int exists(const char* path) {
    return access(path, F_OK) == 0;
}

/* Cleanup directory recursively (cross-platform) */
void cleanup(const char* path) {
#ifdef _WIN32
    char cmd[1024];
    snprintf(cmd, sizeof(cmd), "rmdir /S /Q \"%s\"", path);
    system(cmd);
#else
    char cmd[1024];
    snprintf(cmd, sizeof(cmd), "rm -rf \"%s\"", path);
    system(cmd);
#endif
}

int main() {
    const char* test_root = "test_project";
    const char* active_path = "test_project/active";
    const char* project_name = "Alpha";

    cleanup(test_root);

    mkdir_recursive(test_root);
    if (!exists(test_root)) { printf("Root missing\n"); return 1; }

    mkdir_recursive(active_path);
    create_active_project(active_path, project_name);

    char path[1024];
    snprintf(path, sizeof(path), "%s/%s/nb", active_path, project_name);
    if (!exists(path)) { printf("nb missing\n"); return 1; }

    snprintf(path, sizeof(path), "%s/%s/src", active_path, project_name);
    if (!exists(path)) { printf("src missing\n"); return 1; }

    snprintf(path, sizeof(path), "%s/%s/paper", active_path, project_name);
    if (!exists(path)) { printf("paper missing\n"); return 1; }

    snprintf(path, sizeof(path), "%s/%s/viz", active_path, project_name);
    if (!exists(path)) { printf("viz missing\n"); return 1; }

    snprintf(path, sizeof(path), "%s/%s/nb/XX-01.ipynb", active_path, project_name);
    if (!exists(path)) { printf("XX-01.ipynb missing\n"); return 1; }

    snprintf(path, sizeof(path), "%s/%s/nb/XX-02.ipynb", active_path, project_name);
    if (!exists(path)) { printf("XX-02.ipynb missing\n"); return 1; }

    snprintf(path, sizeof(path), "%s/%s/nb/XX-03.ipynb", active_path, project_name);
    if (!exists(path)) { printf("XX-03.ipynb missing\n"); return 1; }

    printf("All tests passed!\n");
    cleanup(test_root);
    return 0;
}
