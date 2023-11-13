#!/bin/bash
for i in $(ls automated_checker/tests/simple_shell_setenv_unsetenv/); do
    echo -e "\e[31m$i\e[0m"
    ./automated_checker/checker ./shell ./automated_checker/tests/simple_shell_setenv_unsetenv/$i
    echo
    echo "================================================================ ============================================================================================="
    echo "================================================================ ============================================================================================="
    echo "================================================================ ============================================================================================="
    echo "================================================================ ============================================================================================="
done
for i in $(ls automated_checker/tests/simple_shell_setenv_unsetenv/); do
    echo -e "\e[31m$i\e[0m"
    ./automated_checker/run ./shell ./automated_checker/checker ./automated_checker/tests/simple_shell_setenv_unsetenv/$i
    echo
done