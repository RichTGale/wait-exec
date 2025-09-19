#!/bin/bash

printf "gcc -o mycutils.h timer_sec.h mycutils.c timer_sec.c wait_exec.c\n"
gcc -o mycutils.h timer_sec.h mycutils.c timer_sec.c wait_exec.c
