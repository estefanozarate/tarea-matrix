#!/usr/bin/env bash

project_name='prog3_unit1_tarea_introductoria_v2022_1'
source_code='
        PC1.h PC1.cpp
  '
rm -f ${project_name}.zip
zip -r -S ${project_name} ${source_code}