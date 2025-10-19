#include "project_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#ifdef _WIN32
#include <direct.h>
#define MKDIR(path) _mkdir(path)
#else
#include <sys/stat.h>
#include <sys/types.h>
#define MKDIR(path) mkdir(path, 0755)
#endif

/* Recursively create directories */
void mkdir_recursive(const char *path) {
    char tmp[1024];
    char *p = NULL;
    size_t len;

    snprintf(tmp, sizeof(tmp), "%s", path);
    len = strlen(tmp);

    if (tmp[len - 1] == '/' || tmp[len - 1] == '\\') tmp[len - 1] = 0;

    for (p = tmp + 1; *p; p++) {
        if (*p == '/' || *p == '\\') {
            *p = 0;
            if (MKDIR(tmp) != 0 && errno != EEXIST) {
                perror(tmp);
            }
            *p = '/';
        }
    }

    if (MKDIR(tmp) != 0 && errno != EEXIST) {
        perror(tmp);
    }
}

/* Create project structure and notebook templates */
void create_active_project(const char* active_path, const char* project_name) {
    char path[1024];
    const char* folders[] = {"nb", "src", "paper", "viz"};
    int n = sizeof(folders)/sizeof(folders[0]);

    for (int i = 0; i < n; i++) {
        snprintf(path, sizeof(path), "%s/%s/%s", active_path, project_name, folders[i]);
        mkdir_recursive(path);
    }

    char nb_template[1024];
    for (int i = 1; i <= 3; i++) {
        snprintf(nb_template, sizeof(nb_template), "%s/%s/nb/XX-%02d.ipynb", active_path, project_name, i);
        FILE* f = fopen(nb_template, "w");
        if (f) {
            fprintf(f, "{\n \"cells\": [],\n \"metadata\": {},\n \"nbformat\": 4,\n \"nbformat_minor\": 5\n}");
            fclose(f);
        } else {
            perror(nb_template);
        }
    }
}
