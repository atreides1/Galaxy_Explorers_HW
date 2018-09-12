Homework 1: Galaxy Explorers

Note: the README.md looks terrible on Github! I suggest downloading the repo and reading it from your favorite text editor.

Note 1: The main files are this one and update_locations.c

###### Part 1 ###########

Trials:	

Object Count:		# of Iterations:		Mean Time:

2^8 (256)			100000					1.068261770429686
2^9 (512)			10000					1.175077976562466
2^10 (1024)			10000					1.1823225614257638
2^11 (2048)			10000					1.116253428710914
2^12 (4096)			10000					1.0927921264404283
2^13 (8192)			10000					1.1119768772460958
2^14 (16384)		1000					1.147477986938534
2^15 (32768)		1000					1.0636008092041043			
2^16 (65536)		100						1.339639813234572
2^17 (131072)		100						1.130279035797127
2^18 (262144)		100						1.0787893792724852
2^19 (524288)		100						1.0073558197212262
2^20 (1048576)		10						1.0165801866531856
2^21 (2097152)		10						0.9794268825054265
2^22 (4194304)		10						0.9936107108354406
2^23 (8338608)		10						0.9929963507578368
[could not run 2^24 - had a memory error]						

Questions:

a) Explain how many iterations you picked at different sizes and why.

	For the smaller sizes, I picked higher number of iterations and used those for larger sizes until it was unfeasible. For me, unfeasible meant unable to run a few tests within a couple of minutes. If a single test seemed to lag or take longer than 5 minutes, I reduced the iteration number by a magnitude of 10.

b) Explain how you picked a single number from repeated measurements and justify it.

	I would pick the median from the set of measurements I ran. I think this was a good way to get a good "fit," ensuring the value wasn't wildly far from the mean. 

c) Plot a line graph.
	Please see "part1_data.png"

###### Part 2 ###########

Trials: 
I decided to change the iteration count to higher values, because at lower values there wasn't enough precision (I'm using floats) and my readings were mostly 0.0000.	

Object Count:		# of Iterations:		Mean Time:

2^8 (256)			1000000					0.015625
2^9 (512)			1000000					0.019531
2^10 (1024)			1000000					0.009766
2^11 (2048)			1000000					0.014648	
2^12 (4096)			1000000					0.007568
2^13 (8192)			1000000					0.012207
2^14 (16384)		100000					0.010986
2^15 (32768)		100000					0.008850	
2^16 (65536)		10000					0.015259
2^17 (131072)		10000					0.012207
2^18 (262144)		100						0.005859
2^19 (524288)		100						0.012317
2^20 (1048576)		100						0.006104
2^21 (2097152)		100						0.007629
2^22 (4194304)		100						0.09537
2^23 (8338608)		100						0.00839
2^24 (16777216)		10						0.017881

Graph: see "Part2_data.png" - The graph got a bit wonky after I replotted it to fix a margin.

###### Part 3 ###########

Floats (original): Trials were in the range [0.004 - 0.02] 
Doubles: In order to test doubles, I had to decrease the magnitude of iterations from floats by 10. When I ran that, using a shell script (hw1.sh - much less typing!) I found the results to be comparable to Floats.

