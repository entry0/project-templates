BIN = hello

.DEFAULT_GOAL := default
.PHONY: default
default:
	@clear
	@cd build && cmake -DCMAKE_BUILD_TYPE=Release .. && echo && make -s -j $(shell nproc) && mv $(BIN) ..
	@strip -s $(BIN)

.PHONY: debug
debug:
	@clear
	@cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && echo && make -s -j $(shell nproc) && mv $(BIN) ..

.PHONY: clean
clean:
	rm -rf build/*
	rm -f $(BIN)
