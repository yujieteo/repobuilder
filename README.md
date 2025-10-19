# Repobuilder

Repobuilder is a C program for generating a structured project directory layout inspired by Stephen Wolfram's personal infrastructure and project organization. It supports **active projects**, **archives by year**, **templates**, and **Jupyter notebook placeholders**.

## Project Structure

After running, the default project layout (`project`) looks like this:

# Run program with default arguments
`make run`

# OR run manually with custom arguments:
`./repobuild <root_directory> <number_of_projects> <project_name1> <project_name2> ...`

# Example
`./repobuild diffeq 3 1d_poisson 1d_laplace 2d_poisson`

# Run Tests
`make test`

# Cleaning
`make clean`