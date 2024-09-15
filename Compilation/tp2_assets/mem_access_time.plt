load "caches.cfg"

set term pdf size 16,12

# uncomment the following line to use a log y-axis
# set logscale y

set logscale x 2
set logscale y
set format x '2^{%L}'
set xlabel "List size (bytes)"
set ylabel "Processor cycles"

# L1
set arrow 1 from L1_SIZE,1 to L1_SIZE,10000 nohead

# L2
set arrow 2 from L2_SIZE,1 to L2_SIZE,10000 nohead

# L3
set arrow 3 from L3_SIZE,1 to L3_SIZE,10000 nohead

plot 'results.dat' title "mesures" #, 'results.dat' smooth bezier notitle
