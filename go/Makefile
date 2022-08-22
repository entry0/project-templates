BIN = hello

FLAGS = -buildmode=default
TAGS = static
LDFLAGS = -buildid "" -s -w

.PHONY: all
all:
	clear
	GOPATH="$(PWD)/src" GOOS=linux GOARCH=amd64 go build -o $(BIN) $(FLAGS) -tags '$(TAGS)' -ldflags '$(LDFLAGS)' ./src/
	strip -s -R '.comment' '$(BIN)'
	du -h $(BIN)
	echo

.PHONY: clean
clean:
	rm -f $(BIN)
