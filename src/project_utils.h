#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H

/* Recursively create a directory and all parent directories */
void mkdir_recursive(const char *path);

/* Create a standard project structure with notebooks, src, paper, viz */
void create_active_project(const char* active_path, const char* project_name);

#endif
