#!/bin/bash

printf "gcc -o mycutils/mycutils.h clocks/timer_sec/timer_sec.h mycutils/mycutils.c clocks/timer_sec/timer_sec.c wait_exec.c\n"
gcc -o mycutils/mycutils.h clocks/timer_sec/timer_sec.h mycutils/mycutils.c clocks/timer_sec/timer_sec.c wait_exec.c
