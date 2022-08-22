BIN = hello

.PHONY: all
all:
	@clear
	cargo build --release --bins
	@cp target/release/$(BIN) .
	@strip -s \
		-R '.comment' \
		-R '.note.ABI-tag' \
		-R '.note.gnu.build-id' \
		-R '.note.gnu.property' \
		-R '.gnu.hash' \
		$(BIN)
	@echo

.PHONY: clean
clean:
	rm -rf target/*
	rm -f $(BIN)
	rm -f Cargo.lock
