BIN = hello

.PHONY: all
all:
	@clear
	zig build -Drelease-small=true
	@cp zig-out/bin/$(BIN) .
	@strip -s \
		-R '.comment' \
		-R '.note.ABI-tag' \
		-R '.note.gnu.build-id' \
		-R '.note.gnu.property' \
		-R '.gnu.hash' \
		$(BIN)
	@wc -c $(BIN)
	@echo

.PHONY: clean
clean:
	rm -rf zig-cache/
	rm -rf zig-out/
	rm -f $(BIN)
