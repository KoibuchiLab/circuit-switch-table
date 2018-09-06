# circuit-switch-table
This repo contains the work on circuit-switched network, including estimating # of slots, generating routing table for each switch.
## Source Files
### circuit-switch-table-2d.cc
* This file estimates # of slots and generates routing table for each switch.
* It supports 2-D mesh/torus as the host interconnection network (-a).
* It defaultly supports the update of slot # during slot ID allocation (add -d to deactivate the update).
* The generated routing tables (output-port output-slot input-port input-slot) for corresponding switches are saved in output/, which is refreshed (NOT appended!) after each execution.
* Switch Port Number: East 0, West 1, South 2, North 3.

![result](https://raw.githubusercontent.com/KoibuchiLab/circuit-switch-table/master/fig/sw.png?token=ADxdf3SPO-P_p9ufh3P7CwIziQNqFATQks5bmgCTwA%3D%3D)

* Compilation:
> g++ -c circuit-switch-table-2d.cc  
> g++ circuit-switch-table-2d.o -o circuit-switch-table-2d.out
* Usage: 
> // for test in a 16-switch mesh (see traffic pattern details in test.txt)  
> cat test.txt | ./circuit-switch-table-2d.out -a 4 -T 0 

![result](https://raw.githubusercontent.com/KoibuchiLab/circuit-switch-table/master/examples/snip_20180902003648.png?token=ADxdf4ZJN5dOcQYGcf0X3smPrV0uSEUJks5bk_anwA%3D%3D)

![result](https://raw.githubusercontent.com/KoibuchiLab/circuit-switch-table/master/examples/snip_20180902003826.png?token=ADxdf8WBAz82CeqXK61UMMz2gu_IpUkIks5bk_cvwA%3D%3D)

> // 64-switch torus (see traffic pattern details in traffic-pattern-generator.cc below)  
> cat ./traffic-pattern-generator.out -t 0 | ./circuit-switch-table-2d.out -a 8 -T 1
### test.txt
* This test file shows a simple src-dst traffic for 16-node mesh.
### traffic-pattern-generator.cc
* This file helps to generate various traditional traffic patterns, including uniform, matrix, reversal, hotspot, neighbor, shuffle, butterfly, complement, tornado, all-to-all.
* Compilation:
> g++ -c traffic-pattern-generator.cc  
> g++ traffic-pattern-generator.o -o traffic-pattern-generator.out
* Usage:
> // 16-node uniform (-t 0 uniform, 1 matrix, 2 reversal, 3 hotspot, 4 neighbor, 5 shuffle, 6 butterfly, 7 complement, 8 tornado, 9 all-to-all)  
> ./traffic-pattern-generator.out -t 0 -n 4  

![result](https://raw.githubusercontent.com/KoibuchiLab/circuit-switch-table/master/examples/snip_20180902002828.png?token=ADxdf68kxk6IoTq_PYrlZERTx0Z08YNUks5bk_Y1wA%3D%3D)
### traffic-pattern-generator.h
* This file is the head file for traffic-pattern-generator.cc.