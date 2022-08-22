package pop

import (
	"os"
	"fmt"
	"time"
	"runtime"
	"strconv"
)

const (
	ANSI_RESET  = "\x1B[0m"
	ANSI_ORANGE = "\x1B[38;5;202m"
	ANSI_GREEN = "\x1B[38;5;10m"
	ANSI_RED    = "\x1B[38;5;9m"
	ANSI_GRAY   = "\x1B[38;5;8m"
)

func LogInfo(s string) {
	fmt.Printf("[%v] [-] %v\n", time.Now().Format("03:04:05 PM"), s)
}

func LogSuccess(s string) {
	fmt.Printf("[%v] [%v*%v] %v\n", time.Now().Format("03:04:05 PM"), ANSI_GREEN, ANSI_RESET, s)
}

func LogWarning(s string) {
	fmt.Printf("[%v] [%v#%v] %v\n", time.Now().Format("03:04:05 PM"), ANSI_ORANGE, ANSI_RESET, s)
}

func LogError(s string) {
	fmt.Printf("[%v] [%v!%v] %v\n", time.Now().Format("03:04:05 PM"), ANSI_RED, ANSI_RESET, s)
}

func LogDebug(s string) {
	fmt.Printf("[%v] [%v?%v] %v\n", time.Now().Format("03:04:05 PM"), ANSI_GRAY, ANSI_RESET, s)
}

func LogFatal(s string) {
	LogError(s)
	os.Exit(1)
}

func IntToString(i int) string {
	return strconv.Itoa(i)
}

func Check(err error) {
	if err != nil {
		_, file, line, _ := runtime.Caller(1)
		LogFatal("Error in " + file + ":" + IntToString(line))
	}
}
