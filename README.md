# circuit-switch-table
This repo contains the work on circuit-switched network, including estimating # of slots, generating routing table for each switch.
## Source Files
### huyao_cs_table_v1.cc
* This file estimates # of slots and generates routing table for each switch.
* It supports 2-D mesh/torus as the host interconnection network (-a).
* It defaultly supports the update of slot # during slot ID allocation (add -d to deactivate the update).
* Compilation:
> g++ -c huyao_cs_table_v1.cc  
> g++ huyao_cs_table_v1.o -o huyao_cs_table_v1.out
* Usage: 
> // 16-switch mesh (see traffic pattern details in test.txt)  
> cat test.txt | ./huyao_cs_table_v1.out -a 4 -T 0 

> // 64-switch torus (see traffic pattern details in traffic_pattern_gen.cc)  
> cat ./traffic_pattern_gen.out -t 0 | ./huyao_cs_table_v1.out -a 8 -T 1
### test.txt
* This test file shows a simple src-dst traffic for 16-node mesh.
### traffic_pattern_gen.cc
* This file helps to generate various traditional traffic patterns, including uniform, matrix, reversal, hotspot, neighbor, shuffle, butterfly, complement, tornado, all-to-all.
* Compilation:
> g++ -c traffic_pattern_gen.cc  
> g++ traffic_pattern_gen.o -o traffic_pattern_gen.out
* Usage:
> // 16-node uniform (-n 0 uniform, 1 matrix, 2 reversal, 3 hotspot, 4 neighbor, 5 shuffle, 6 butterfly, 7 complement, 8 tornado, 9 all-to-all)  
> ./traffic_pattern_gen.out -t 0 -n 4
### mkpkt-huyao.h
* This file is the head file for traffic_pattern_gen.cc.