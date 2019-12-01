# Project: helper thread prefetching competition

## Overview

In this project you will be working to implement a "helper thread" that pre-fetches data for the main thread. The basic idea behind helper thread is running another thread in addition to the main thread. In contrast to the conventional multithreading model that parallel threads simply partition the tasks from the main program, helper thread itself does not offload tasks from the main thread but running some lightweight computation that can accelerate the execution of the main thread. One example is to run a helper thread that prefetches the upcoming data that the main thread is using soon into caches. 

This project will require you to implement a helper thread for mcf, a network traversal benchmark application from SPEC2006. Unlike applications with strong localities on data, mcf's network data structure impedes conventional prefetching mechanisms from being effective. However, we envision that implementing a helper thread could potentially work better than conventional approach as the programmer can implement logic that is specific to mcf's memory access pattern. This is an individual project, no grouping is allowed.

As hints, you may find the following two papers useful.
1. Y. Solihin, Jaejin Lee and J. Torrellas. Using a user-level memory thread for correlation prefetching.  Proceedings 29th Annual International Symposium on Computer Architecture, Anchorage, AK, USA, 2002, pp. 171-182.
2. Chia-Lin Yang, Alvin R Lebeck, Hung-Wei Tseng, Chien-Hao Lee. Tolerating memory latency through push prefetching for pointer-intensive applications. ACM Transactions on Architecture and Code Optimization (TACO), 1, 4 (December 2004), 445-475. DOI: https://doi.org/10.1145/1044823.1044827

## How to start

You will be given the source code of mcf and a skeleton to support helper threads. You should clone this repo using git https://github.com/hungweitseng/CS203-Project. You should develop this project under a Linux machine. We will run your project on bolt.cs.ucr.edu. As a CSE student, you should have access to it. If not, please acquire an account from CSE's IT. Please don't contact us for account issues. 

Once you clone the repo, you will find a few directories in there. The project files you need to work on locate in the src/ directory. You may find another directory named baseline/, this is simply for you to compare the result. The build the executable file, you need to use "make" command in each directory. The repo also contains a data/ directory that provides the input data set while we also have a sample test script "run.sh".  

Your task will be to design and implement the helper thread located in the helper.c file. The effectiveness of your prefetcher will be tested against a baseline prefetcher. You will also compete against your fellow classmates for amazing awards and prizes! You will get full credit if you can speedup the main thread in our tests. If not, your grades will be the speedup_over_baseline * 100. You have the complete freedom to implement any mechanism that you think might help improve the main thread performance in the helper.c file. However, as you're only allowed to turnin helper.c, any modification you made in other files will be omitted. 

## Deliverables

You only need to turn your modified "helper.c" file and please put your name and student ID # as a comment in the first two lines of your code through iLearn. 

## Due 

11:59pm, 12/2/2019. No extension. No late submission accepted.

