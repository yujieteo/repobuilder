#include "project_utils.h"
#include <stdio.h>
#include <stdlib.h>

/* Main program entry */
int main(int argc, char* argv[]) {
    const char* root_dir = "project";
    int num_projects = 1;
    const char* project_names[10];
    for (int i = 0; i < 10; i++) project_names[i] = "project";

    if (argc > 1) root_dir = argv[1];
    if (argc > 2) num_projects = atoi(argv[2]);
    if (num_projects > 10) num_projects = 10;
    for (int i = 0; i < num_projects && i+3 < argc; i++) {
        project_names[i] = argv[i+3];
    }

    mkdir_recursive(root_dir);

    char active_path[1024];
    snprintf(active_path, sizeof(active_path), "%s/active", root_dir);
    mkdir_recursive(active_path);

    for (int i = 0; i < num_projects; i++) {
        create_active_project(active_path, project_names[i]);
    }

    char archives_path[1024];
    snprintf(archives_path, sizeof(archives_path), "%s/archives", root_dir);
    mkdir_recursive(archives_path);

    for (int year = 2023; year <= 2025; year++) {
        char year_path[1024];
        snprintf(year_path, sizeof(year_path), "%s/%d", archives_path, year);
        mkdir_recursive(year_path);
    }

    char templates_path[1024];
    snprintf(templates_path, sizeof(templates_path), "%s/templates/project-template", root_dir);
    mkdir_recursive(templates_path);

    printf("Project directory structure created successfully under '%s'\n", root_dir);
    return 0;
}
