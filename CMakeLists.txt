cmake_minimum_required(VERSION 3.26)
project(SE_Project_Process_Scheduling C)

set(CMAKE_C_STANDARD 11)

add_executable(SE_Project_Process_Scheduling main.c
        "Queue/QueueManipulation.c"
        "CPU Scheduling Algorithms/FIFO/FIFO.c"
        "CPU Scheduling Algorithms/FIFO/FIFO.h"
        "CPU Scheduling Algorithms/RR/RR.h"
        "CPU Scheduling Algorithms/RR/RR.c"
        GanttChart/GanttChart.h
        GanttChart/GanttChart.c
        "CPU Scheduling Algorithms/SRT/SRT.h"
        "CPU Scheduling Algorithms/SRT/SRT.c"
        "CPU Scheduling Algorithms/Priority/Priority.h"
        "CPU Scheduling Algorithms/Priority/Priority.c"
        "CPU Scheduling Algorithms/Multilevel/MultiLevel.h"
        "CPU Scheduling Algorithms/Multilevel/MultiLevel.c")
