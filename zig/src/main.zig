// main.zig - Entrypoint for project.

const std = @import("std");
const stdout = std.io.getStdOut();

pub fn main() !void {
    try stdout.writeAll("Hello world!\n");
}
