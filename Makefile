run: obj_dir/Vour
	obj_dir/Vour

obj_dir/Vour: our.v sim_main.cpp
	verilator -Wall --cc our.v --exe --trace  sim_main.cpp
	make -C obj_dir -j -f Vour.mk Vour
