# AGENTS.md

## Overview
This repo contains C++ solutions to LeetCode problems.
Each file in `src/` contains:
- a `class Solution` implementation
- a `main()` with basic tests for standalone compilation

## Layout
- `src/` — one `.cpp` per problem, named `lc_<id>_<slug>.cpp`

## Build / Run
Compile a single file directly, e.g.:
- `clang++ -std=c++17 -O2 -Wall -Wextra -pedantic src/lc_1_two_sum.cpp -o /tmp/a.out`
- `/tmp/a.out`

## Conventions
- Keep solutions self-contained per file.
- Use standard headers only.
- Tests in `main()` should be minimal and runnable.

## New Files
When adding a solution:
- name as `lc_<id>_<slug>.cpp`
- include `class Solution` and a `main()` with tests
